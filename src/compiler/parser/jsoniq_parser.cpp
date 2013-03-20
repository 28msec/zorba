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
#line 88 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"


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
#line 69 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1051 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"

#include "compiler/parser/jsoniq_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 99 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 185 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 911 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 910 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 909 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 344: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 371: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 391: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 407: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 425: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 426: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 431: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 434: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 466: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 467: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 472: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 473: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 523: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 531: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 591: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 601: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 609: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 619: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 624: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 632: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 633: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 641: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 657: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 658: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
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
#line 133 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2871 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 1069 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1073 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1077 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1085 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1091 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1095 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1104 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1110 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1118 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1124 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1135 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1140 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1148 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1155 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1162 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1171 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1178 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1186 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1194 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1202 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1218 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1225 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1232 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1244 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1254 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1261 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1268 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1303 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1308 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1316 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1324 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1332 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1337 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1345 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1350 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1358 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1363 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1371 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1376 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1381 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1386 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1399 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1409 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1414 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1422 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1430 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1441 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1448 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1459 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1464 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1472 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1479 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1486 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1495 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1508 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1516 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1523 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1533 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1540 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1547 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1570 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1576 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1585 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1592 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1602 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1611 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1612 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1613 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1615 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1616 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1617 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1618 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1619 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1620 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1626 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1634 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1642 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1650 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1657 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1665 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1672 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1677 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1685 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1693 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1707 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1721 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1738 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1743 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1751 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1759 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1770 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1775 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1784 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1789 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1796 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1801 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1811 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1816 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1825 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1831 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1844 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1849 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1857 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1868 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1883 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1895 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1910 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1915 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1925 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1956 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1966 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1975 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1984 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1993 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2005 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 2009 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2015 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2019 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2029 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2039 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2058 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2067 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2072 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2079 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2086 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2098 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2108 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2118 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2129 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2145 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2165 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2173 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2181 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2185 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2189 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2197 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2202 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2214 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2221 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2231 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2263 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2268 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2276 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2293 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2301 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2309 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2316 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2323 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2334 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2343 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2352 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2361 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2374 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2382 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2390 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2398 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2413 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2418 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2426 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2440 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2457 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2482 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2490 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2497 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2508 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2518 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2523 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2536 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2583 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2597 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2605 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2610 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2618 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2623 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2628 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2636 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2645 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2657 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2667 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2680 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2704 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2711 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2721 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2727 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2736 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2744 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      // this adds on shift-reduce conflict (probably with FTRange expression)
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2752 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2759 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2767 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2779 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2789 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2799 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2809 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2819 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2829 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2839 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2849 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2860 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2869 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2879 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2889 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2914 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2949 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2957 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2967 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2975 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2987 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2993 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3006 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3010 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 3018 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3022 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3031 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3035 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3039 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3049 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3057 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3064 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3070 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3080 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3084 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3088 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3096 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3104 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3112 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3124 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3132 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3138 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3148 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3154 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3164 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3168 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3178 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3184 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3190 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3196 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3205 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3214 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3223 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3236 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3240 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3248 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3254 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3264 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3272 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3281 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3294 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3301 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3313 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3317 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3329 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3336 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3342 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3351 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3358 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3364 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3375 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3382 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3388 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3397 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3406 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3424 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3431 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3443 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3449 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3461 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3467 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3478 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3484 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3495 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3501 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3512 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3518 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3529 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3538 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3542 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3551 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3555 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3563 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3567 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3577 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3584 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3593 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3602 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3607 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3616 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3625 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3634 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3647 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3651 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3663 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3667 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3674 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3678 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3685 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3689 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3698 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3702 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3714 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3718 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3724 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3730 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3736 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3746 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3750 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3762 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3766 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3772 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3786 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3796 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3800 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3810 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3814 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3824 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3828 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3838 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3842 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3851 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3855 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3863 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3867 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3871 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3875 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3885 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3889 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3893 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3900 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3917 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3925 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3941 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3949 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3957 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3961 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3965 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3969 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3980 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3986 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3996 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4002 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4012 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4016 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4020 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4083 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4105 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 4133 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4297 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4301 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4311 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4315 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4319 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4323 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4332 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4336 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4340 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4344 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4348 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4353 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4357 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4361 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4365 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4374 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4380 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4390 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4398 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4402 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4406 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4410 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4414 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4418 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4422 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4426 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4430 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4434 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4439 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4443 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4447 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4451 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4459 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4463 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4467 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4471 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4479 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4486 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4493 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4503 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4507 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4515 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4523 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4527 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4535 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4543 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4551 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4605 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4609 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                            dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4619 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4625 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4635 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4639 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4647 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4651 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4655 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4663 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 4671 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 4688 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 4696 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 4715 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 4734 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 4756 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4762 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4773 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4779 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4790 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4805 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4810 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4819 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4823 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4830 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4836 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4842 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4849 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4860 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4864 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4871 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4877 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4883 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4890 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4901 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4917 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4925 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4938 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4947 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4955 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4959 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4967 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4972 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4980 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4985 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4993 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 5001 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 5006 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 5011 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 5016 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 5021 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 5026 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 5037 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 5045 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 5049 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 5066 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 5070 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 5078 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 5086 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 5094 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 5106 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 5110 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 5118 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 5126 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 5130 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 5134 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 5169 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 5175 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5181 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5191 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5195 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5199 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5215 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5222 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5228 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5238 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5246 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5254 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5258 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5262 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5266 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5270 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5274 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5278 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5282 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5286 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5290 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5298 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5306 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5322 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5329 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5337 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5345 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5349 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5353 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5361 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5371 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5377 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5391 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5399 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5403 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5409 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 5418 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 5427 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5433 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5439 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5449 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5466 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5473 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5488 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5524 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5528 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5536 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5544 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 5556 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5560 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5568 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5576 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5580 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5614 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5620 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5634 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5640 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5646 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5650 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5656 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5660 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5666 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5672 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5679 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5689 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5740 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5789 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5795 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5814 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5822 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5846 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5854 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5858 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5865 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5870 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5878 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5882 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5889 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5893 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5900 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5904 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5911 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5915 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5924 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 5936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5947 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5959 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5967 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 5975 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5979 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5986 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5990 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5998 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6009 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6013 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6021 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6033 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6039 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6048 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6060 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6064 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6068 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6075 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6079 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6086 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6090 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6098 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6102 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6106 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6110 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6114 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6122 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6130 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6142 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6154 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6158 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6162 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6170 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6176 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6186 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6190 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6194 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6198 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6202 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6206 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6210 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6214 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6222 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6226 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6230 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6234 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6242 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6248 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6258 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6268 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6272 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6280 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6290 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6301 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6308 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6312 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6319 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6323 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6330 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6335 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6344 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6353 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6357 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6364 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6368 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6376 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6385 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6392 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6402 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6406 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6413 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6419 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6428 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6432 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6439 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6444 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6456 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6464 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6476 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6484 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6488 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6496 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6500 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6504 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6512 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6520 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6524 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6528 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6532 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6540 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6548 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6560 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6564 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6572 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6586 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6590 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6597 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6602 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6610 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6615 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6624 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6632 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6639 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6645 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6652 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6663 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6669 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6679 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6686 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6693 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6718 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6746 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6774 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6778 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6782 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6789 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6796 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6803 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6820 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6833 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6834 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6835 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6836 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6837 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6840 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6841 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6842 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6843 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6844 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6845 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6847 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6848 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6853 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6854 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6855 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6857 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6858 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6859 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6860 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6861 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6979 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6980 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6983 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6984 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6985 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6986 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6987 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6988 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6989 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6990 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6991 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6992 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6993 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6994 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6995 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6996 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6997 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6998 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6999 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 7000 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 7001 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 7002 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 7003 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 7004 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 7005 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 7006 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 7007 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 7008 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 7009 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 7010 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 7011 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 7012 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 7013 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 7014 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 7015 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 7016 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 7017 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 7018 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 7019 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 7020 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 7021 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 7022 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 7023 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 7024 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 7025 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 7026 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 7027 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 7028 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 7029 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 7030 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 7031 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 7032 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 7033 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 7034 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 7035 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 7036 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 7037 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 7038 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 7039 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 7040 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 7041 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 7042 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 7043 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 7044 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 7045 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7046 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 7047 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 7048 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 7049 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 7050 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 7051 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 7052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 7053 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 7054 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 7055 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 7056 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 7057 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 7062 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12053 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1487;
  const short int
  jsoniq_parser::yypact_[] =
  {
      6601,  8130,  8130,  8130,  8130, -1487, -1487,   256,   282, -1487,
     740,   395, -1487, -1487, -1487,   306, -1487, -1487, -1487,   333,
   -1487,   478,   476,   496,   668,   121, -1487,   -22, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,   642, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487,   606, -1487,   763, -1487,   721,   801, -1487,
      39, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487,   818, -1487, -1487, -1487, -1487, -1487, -1487, -1487,   762,
   -1487, -1487, -1487, -1487, -1487, 15939, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487,   855, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,  4464,  9960, 10265, 15939, -1487,
   -1487,   831, -1487, -1487, -1487, -1487,   835, -1487, -1487, -1487,
    5988, -1487,  6296, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487,   838, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487,    57,   764, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487,  -102, -1487,   199, -1487,
     -80,   254, -1487, -1487, -1487, -1487, -1487, -1487,   890, -1487,
     773,   785,   786, -1487, -1487,   879,   884, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,   689,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   10570, 10875, -1487,   722, -1487, -1487, -1487, -1487, -1487,  6908,
    8435,  1044, -1487,  8740, -1487, -1487,   324,    76, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487,    83, -1487, -1487, -1487, -1487, -1487, -1487,   569,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,  8130, -1487,
   -1487, -1487, -1487,   299, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487,   353, -1487,   857, -1487, -1487, -1487,   479, -1487,
     736, -1487, -1487, -1487, -1487, -1487, -1487, -1487,   878,   956,
   -1487,   945,   798,   954,   684,   614,   758,   600, -1487,  1009,
     859,   959,   962, 12095, -1487,   873, -1487, -1487,   -19, -1487,
   -1487, -1487, -1487,   571, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,   923,   913, -1487,
   -1487, -1487, -1487, -1487,   886, -1487,  8130,   889,   891,   894,
    8130,   159,   159,  1046,   724,   742,     3, 16231, 15939,   451,
    1033, 15939,   929,   966,   317,  5988,   730,   842, 15939, 15939,
     788,   833,    47, -1487, -1487, -1487,  5988,  8130,  8130, 12400,
      34,   934, 12400,  1094,   158,   365, 15939,   979,   957,   991,
   -1487, 12400, 15939,  8130, 12400, 12400, 15939,  8130,   948,   950,
   12400, 15939, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487,   963, -1487, 15939, -1487, -1487,   920,
    7215,   989,    23,   993,   923,   960,   964,   969, 15939,  4774,
   -1487,   965,    89, -1487,   619, -1487,   136,  1078, 12400, 12400,
      85, -1487, -1487, -1487,  1100, 12400,   905, -1487,  1098, 12400,
   12400, 13010, 12400, 12400,  5084, 12400, 13010, 12400,   888,   896,
   15939,   937,   940, 12400, 12400,  7520,   883, -1487,    33, -1487,
      38, 12400,  8435, -1487, -1487, -1487, -1487, -1487,   740,   121,
      88,    95,  1131,  9045,  2883,  9350,  3209,   762, -1487, -1487,
     383,   762, -1487, 12400,  3839, -1487,  1015, -1487,   -22,   967,
     971,   972,  8130, 12400, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, 15939, -1487,   847,   849, 15939,  1019, 12705,
   12705, 12705, -1487, 12705, 12705, -1487, 12705, -1487, 12705, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, 12705, 12705,  1069, 12705,
   12705, 12705, 12705, 12705, 12705, 12705, 12705, 12705, 12705, 12705,
   12705,   909,  1050,  1051,  1052, -1487, -1487, -1487, 13010, 11180,
   -1487,  5386, 12400, 11485,  1002, -1487,   998, 11790, -1487, -1487,
   -1487, -1487,    13, -1487,    48, -1487, -1487, -1487, -1487, -1487,
   -1487,  1053,  1054,   496,  1129, -1487, -1487, 16231,  1151,   662,
   15939,   999,  1005,  1151,  1046,  1035,  1036, -1487, -1487, -1487,
     182,   918,  1077,   871, 15939,  1030, 12400,  1056, 15939, 15939,
   -1487,  1043,   994,   995,   326, 15939,  1083,   280, -1487,  8130,
   -1487,   137, -1487,  5988,  1084,  1139,  5988,  1046,  1088,    62,
   15939, 12400,   -22,   351,    44, -1487,   375,  1001,   142,   202,
    1037, -1487,  1008,  8130,  8130,   389,   271, 12400,    77, -1487,
   -1487, 12400,  5084, -1487, 12400, 12400, 12400, 12400, -1487, 12400,
   -1487, 12400, -1487, 15939,  1078, -1487,    32,   406,   420, -1487,
   -1487, -1487,   440, -1487,   238, -1487, -1487,   571,   259,   371,
     -23,     9,  1092,   574,   953,   968,   970,   -12, -1487,  1055,
   -1487, -1487,  1004,   203,  7215,   453,  4154,   883, -1487, -1487,
   -1487,   973, -1487,   324,   631,  1166,   673, -1487, -1487,   100,
   -1487, -1487, -1487,   103, -1487,    86, -1487, -1487, -1487, -1487,
   -1487,  3524, -1487, -1487, -1487, 15939,  1032, 12400,  1093, -1487,
   -1487, -1487,  1099, -1487,    35, -1487, -1487,  1099, 15939,    45,
     956, -1487, -1487, -1487, -1487, -1487, 12705, -1487, -1487, -1487,
      69, -1487,   614,   614,   633,   758,   758,   758,   758,   600,
     600, -1487, -1487, 15063, 15063, 15939, 15939, -1487, -1487,   454,
   -1487, -1487, -1487, -1487, -1487,   307, -1487, -1487,   376, -1487,
   -1487, -1487,   419,   159, -1487, -1487,   296,   710,   676, -1487,
     496, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487,  1151, -1487,  1081, 15355,  1068, 12400, -1487, -1487, -1487,
    1121,  1046,  1046,  1151, -1487,   870,  1046,   697, 15939,   589,
     666,  1188, -1487, -1487,   928,   530, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,   182,    22,   988,
     639, 12400, -1487, 15939,  1128,   921,  1046, -1487, -1487,  1067,
    1121, 15063,  1106,  1133,  1057,  1047,  1110,  1046,  1086,  1112,
    1152,  1046, 15063, 12400,   -52, -1487, -1487, -1487,  1096,  1132,
   12400, 12400,  1104, -1487,  1147,  1154,  8130, -1487,  1071,  1073,
    1107, 12400,  1117,  1062, 12400, -1487,  1140,  1141, -1487,   215,
     220,   221,  1230, -1487,   287, -1487,   209,  1113, -1487, -1487,
    1237, -1487,   -63, 12400, 12400, 12400,   760, 12400, 12400, 12400,
   12400, 12400, 12400, 12400, 12400, 12400, 13010,  1149, 12400, 12400,
   -1487,  9655,   402,  1020, -1487, -1487, -1487, -1487, -1487, -1487,
     436, -1487, -1487, 12400,   114,   110,    86,  9350,  3209,  9350,
    1190, -1487, -1487, 12400,   647,  1163, -1487, 15939,  1164, -1487,
   15647,  1145,  1155, 12400,   179,  1127,    41,   523,  1018, -1487,
   -1487,   767,    45, -1487, 12400,    69,   837,   521, -1487,   990,
     807,  1016,  1013, -1487, -1487,   842, -1487,  1010,   663,  1123,
    1136,  1142,  1146,  1153,  1156,  1157,  1158,  1159,  1161,  1168,
   15355,  1171,  1172,  1173,  1174,  1175,  1176, -1487,   565, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487,  1144, -1487, -1487, -1487, -1487, 12400, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,   749, -1487,  1255,
     845, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
    1006, -1487, -1487,  1256, -1487, -1487, -1487, -1487, -1487,   570,
    1268, -1487,   780, -1487, -1487, -1487,  1123,  1136,  1142,  1153,
    1156,  1157,  1158,  1159,  1161,  1172,  1173,  1174,  1175, -1487,
     565,   565, 13010,  1007,   992, -1487,  1121,    22,  1090,  1143,
    8130, -1487, -1487, -1487, 15063, -1487,  8130,  1046,  1200, -1487,
   -1487, -1487,  1046,  1200, -1487, -1487, 12400,  1169,  8130, 15939,
   -1487, -1487, 12400, 12400,    70, -1487,    17,   595, -1487, 13603,
     601, -1487,   805, -1487,  1138, -1487, -1487,  8130, -1487, 12400,
   -1487, -1487, 12400, 12400,  1137,  1147,  1234, -1487,  1204, -1487,
     715, -1487, -1487,  1332, -1487, -1487,  8130, 15939, -1487,   828,
   -1487, -1487, -1487,  8130,  1148,  1103,  1105, -1487, -1487, -1487,
    1108,  1109, -1487, -1487, -1487,  1244, -1487, -1487, -1487, -1487,
    1102,   278, 15939,  1160, -1487,  1187,  1191,  1192,  1196, -1487,
     857,   644,  4154,  1020, -1487,  7825,  4154, -1487, -1487,  1166,
     538, -1487, -1487, -1487,  1163, -1487,  1046, -1487,   872, -1487,
      51,  1245, -1487, 12400,   727,  1093, 15939, -1487,   325, 15939,
   -1487, 12400,  1205, 12400,  1227, 12400,   201,  1208, 12400,  1210,
   -1487,  1241,  1242, 12400, 15939,   122,  1284, -1487, -1487, -1487,
     455,  1177, -1487,    69,  1116, -1487, -1487,   -84, -1487,   696,
      99,  1118,    69,   696, 12705, -1487,   834, -1487, -1487, -1487,
   -1487, -1487, -1487,    69,  1215,  1080,   918,    99, -1487, -1487,
    1074,  1288, -1487, -1487, -1487,  1183,   109, 13895, 13311,  1186,
    5687, 15939, 15939,  1189, 14187,  1193,  1194,  1195,  1197,  1198,
    1201,  1202,  1203, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,  1346,   275,  1347,   275,  1119,
    1270, -1487, -1487,  1209, 15939,  1134, -1487, -1487, 13010, -1487,
    1199, -1487,  1252,  1261,  1296,  1046,  1200, -1487, 12400,  1212,
   -1487, -1487, -1487,  1211, -1487,   320, 12400,  8130,  1213,   337,
   -1487, 15939,   568, -1487, 14479,   356, -1487, 14771,  1216, -1487,
   -1487,  1214, -1487, -1487, -1487, 12400,   826,  1230, 15939,   839,
   -1487,  1217,  1230, 15939, -1487,  1219, -1487, 12400, 12400, 12400,
   12400,  1085, 12400, 12400, -1487, 12400, 12400, 12400, 12400,  9655,
     438, -1487, -1487, -1487, -1487, -1487,  1245, -1487, -1487, -1487,
    1046, 12400, -1487,  1264, -1487, -1487, 12400,  1260, -1487, -1487,
   12400, -1487,   515, -1487, 12400,  1262, 12400, -1487, 12400, 15939,
   15939, -1487,   753, -1487, 12400, -1487, -1487, -1487,  1224, 12705,
   -1487, -1487, -1487, -1487, -1487,   295, 12705, 12705,   640, -1487,
    1016, -1487,   336, -1487,  1013,    69,  1257, -1487, -1487,  1130,
   -1487, -1487, -1487, -1487, -1487, -1487,  1225,  1228, -1487,   467,
     474,  1317,  1229, -1487,   480, -1487,  1235, -1487,  1236,  1238,
    1239, -1487, -1487,   489,   493, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487,   284,   284, -1487,   275, -1487, -1487,
     509, -1487,  1386,    99,  1321,  1240, 13010,   -38,  1150,  1258,
   -1487,  9655, 12400,  1046, -1487, -1487, -1487, 12400, 12400, -1487,
   -1487, -1487,  9655,  9655,  1335,  8130, 15063, 15939,   578, 15939,
   12400, 15939,   657,  9655, -1487,   487,     8,  1230, 15939, -1487,
    1233,  1230, -1487, -1487, -1487, -1487, -1487, 12400, -1487, -1487,
   -1487,   228,   229,   231, 12400, -1487, -1487, -1487,  1326, 12400,
   -1487, 12400, -1487, 12400,  1287, -1487, 12400, -1487, -1487, -1487,
    1382, -1487, -1487, -1487,   758, 12705, 12705,   633,   716, -1487,
   -1487, -1487, -1487, -1487, -1487, 12400, -1487, -1487, -1487, 15939,
   -1487, 15939, -1487, 15063, -1487, 15063,  1342, -1487, -1487, -1487,
   -1487, 15939, -1487, 15939, -1487, -1487, -1487, -1487,  1410, -1487,
   -1487, -1487,  1178,  1334, -1487, -1487,  1336, -1487,   652, 15939,
    1327,  1220, 15939, 13010, -1487, -1487,  1200, -1487, -1487, 15063,
   -1487, -1487, -1487,  1345, 12400,  1263, -1487,  1350,  9655, -1487,
   15939,   596,   725, -1487,  1250,  1230, -1487,  1253, -1487,  1254,
    1147,  1154,   457, -1487,  1326, -1487, -1487, 12400, -1487,  1333,
     633,   633, 12705,   472,  1266,  1267,  1311,  1269,  1275, -1487,
   -1487, 15063,  1277,  1278, -1487, -1487,  1321, 13010, -1487,  1245,
    1165, 15939,  1339,  1243,  1336,   678, 15063,  8130, 15063,  1280,
   -1487, -1487,  1374,   615, -1487, -1487, -1487, -1487,  1285,   748,
   -1487, -1487, -1487,  1272, -1487,  9655,   827, -1487, -1487, -1487,
   15939,   633, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, 12400,  1167, 15939,  1354,  8130,   698,
   -1487, -1487,   701, 12400, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487,  1356, -1487, -1487,  1180,  1170, 15939, -1487, -1487, 12400,
    9655, 15939,  1181, 12400,  1182,  1291, 13010, -1487, 13010,  9655,
   -1487,  1281,  1206, 15939,  1251,  1363, 15939,  1184, 13010, -1487
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       165,   168,   168,   168,     0,   803,  1008,   120,   122,   606,
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
       0,     0,  1001,  1002,  1003,  1006,  1005,  1004,  1007,   165,
     165,     0,     2,   165,     9,    11,    23,     0,    28,    31,
      36,    37,    38,    39,    40,    41,    42,    32,    58,    59,
      33,    34,     0,    76,    79,    80,    35,    81,    82,     0,
     118,    83,    84,    85,    86,    18,   162,   163,   164,   171,
     174,   461,   175,     0,   176,   177,   178,   179,   180,   181,
     182,   185,     0,   211,   219,   214,   246,   252,     0,   244,
       0,   245,   221,   215,   184,   216,   183,   217,   220,   354,
     356,   358,   368,   370,   374,   376,   379,   384,   387,   390,
     392,   394,   396,     0,   400,   407,   406,   408,     0,   426,
     409,   431,   432,   433,   440,   452,   466,   468,   453,   454,
     455,   458,   459,   456,   457,   485,   487,   488,   489,   486,
     534,   535,   536,   537,   538,   539,   540,   467,   460,   607,
     608,    43,   222,   223,   225,   224,   226,   218,   463,   464,
     465,   462,   228,   231,   227,   229,   230,     0,   785,   802,
     895,   904,   902,   804,     0,   166,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   276,
     277,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,   787,   812,   790,   843,   905,   792,   853,
     794,   864,   797,   799,   798,   882,   786,   841,   865,   889,
     946,   947,   941,   933,   939,   930,   830,   951,   952,   949,
     801,   953,   923,  1002,   475,   785,     0,   783,   187,     0,
       0,   211,     0,     0,   784,   792,   799,   798,     0,   168,
     758,   953,     0,   219,     0,   476,     0,   501,     0,     0,
       0,   784,   429,   430,     0,     0,     0,   530,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   760,     0,   762,
       0,     0,   165,     3,     4,     1,    10,    12,     0,     0,
       0,     0,     6,   165,     0,   165,     0,     0,   119,   172,
       0,     0,   190,     0,     0,   199,     0,   257,     0,     0,
       0,     0,     0,     0,   258,   204,   232,   251,   247,   253,
     248,   250,   249,     0,   256,     0,     0,     0,     0,     0,
       0,     0,   419,     0,     0,   417,     0,   363,     0,   418,
     411,   416,   415,   414,   413,   412,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   405,   404,   401,     0,     0,
     427,     0,     0,     0,   441,   449,     0,     0,   542,   544,
     548,   550,     0,   124,     0,   782,    47,    44,    45,    48,
      49,     0,     0,     0,     0,    50,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   617,   618,   619,
       0,   103,   142,     0,     0,   112,     0,     0,     0,     0,
     127,     0,     0,     0,     0,     0,   134,     0,   138,   168,
     610,     0,    60,     0,    69,     0,     0,     0,    61,     0,
       0,     0,     0,     0,     0,   325,     0,     0,     0,     0,
       0,   604,     0,     0,     0,     0,   194,     0,     0,   188,
     186,     0,     0,   764,     0,     0,     0,     0,   475,     0,
     759,     0,   477,   502,   501,   498,     0,     0,     0,   532,
     531,   428,     0,   529,     0,   630,   631,   773,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   636,     0,
     202,   203,     0,     0,     0,     0,     0,   207,   208,   761,
     763,     0,     5,    24,     0,    25,     0,     7,    29,     0,
      15,     8,    30,     0,    19,   895,    77,    16,    78,    20,
     193,     0,   191,   212,   213,     0,     0,     0,     0,   205,
     233,   294,   255,   259,     0,   234,   235,   254,     0,     0,
     355,   357,   361,   367,   366,   365,     0,   362,   359,   360,
       0,   371,   378,   377,   375,   381,   382,   383,   380,   385,
     386,   389,   388,     0,     0,     0,     0,   410,   424,     0,
     448,   446,   445,   447,   444,     0,   442,   483,     0,   450,
     609,   481,     0,     0,   121,   123,     0,     0,     0,   102,
       0,    92,    94,    95,    96,    97,    99,   100,   101,    93,
      98,    88,    89,     0,     0,   108,     0,   104,   106,   107,
     114,     0,     0,    87,    46,     0,     0,     0,     0,     0,
       0,     0,   708,   713,     0,     0,   709,   743,   696,   698,
     699,   700,   702,   704,   703,   701,   705,     0,     0,     0,
       0,     0,   111,     0,   144,     0,     0,   547,   541,     0,
     140,     0,     0,   135,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,     0,   275,   281,   278,     0,     0,
       0,     0,     0,   546,     0,     0,     0,   420,     0,     0,
       0,     0,   195,     0,     0,   766,     0,     0,   765,     0,
       0,     0,   501,   499,     0,   490,     0,     0,   479,   480,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,     0,     0,   437,   438,   439,   436,   644,   435,
       0,   434,   209,     0,     0,     0,     0,   165,     0,   165,
       0,   173,   243,     0,   309,   305,   307,     0,   295,   296,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     237,     0,   242,   364,     0,     0,     0,     0,   674,   372,
     647,   651,   653,   655,   657,   660,   667,   668,   676,   787,
     788,   790,   905,   789,   794,   795,   796,   797,   786,   791,
       0,   800,   793,  1006,  1005,  1004,  1007,   391,   553,   559,
     560,   579,   570,   578,   577,   576,   575,   572,   574,   571,
     573,   563,   611,   612,   564,   565,   776,   777,   778,   568,
     393,   395,   398,   569,   397,   425,   451,     0,   443,   482,
     125,    56,    57,    54,    55,   131,   130,     0,    90,     0,
       0,   109,   110,   115,    74,    75,    52,    53,    73,   714,
       0,   717,   744,     0,   707,   706,   711,   710,   742,     0,
       0,   719,     0,   715,   718,   697,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     146,   148,     0,     0,     0,   113,   116,     0,     0,     0,
     168,   141,   136,   139,     0,   189,     0,     0,    71,    65,
      68,    67,     0,    63,   552,   279,     0,     0,   168,     0,
     323,   327,     0,     0,     0,   330,     0,     0,   336,     0,
       0,   343,     0,   347,     0,   422,   421,   168,   196,     0,
     198,   324,     0,     0,     0,     0,     0,   502,     0,   492,
       0,   525,   522,     0,   526,   527,     0,     0,   521,     0,
     496,   524,   523,     0,     0,     0,     0,   623,   624,   620,
       0,     0,   628,   629,   625,   769,   770,   634,   774,   632,
       0,     0,     0,     0,   638,   792,   799,   798,   953,   201,
       0,     0,     0,   639,   640,     0,     0,   210,   772,    26,
       0,    17,    21,    22,   306,   318,     0,   319,     0,   310,
     311,   312,   313,     0,   298,     0,     0,   261,     0,     0,
     262,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,     0,     0,   288,     0,   285,   290,   241,
       0,     0,   658,   671,     0,   369,   373,     0,   690,     0,
       0,     0,     0,     0,     0,   646,   648,   649,   685,   686,
     687,   689,   688,     0,     0,   662,   661,     0,   665,   669,
     683,   681,   680,   673,   677,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   556,   558,   557,   554,   399,   484,   133,
     132,    91,   105,   731,   712,     0,   736,     0,   736,   725,
     720,   147,   149,     0,     0,     0,   117,   145,     0,    27,
       0,   137,     0,     0,    70,     0,    64,   280,     0,     0,
     326,   328,   333,     0,   331,     0,     0,     0,     0,     0,
     337,     0,     0,   351,     0,     0,   344,     0,     0,   348,
     423,     0,   197,   767,   768,     0,     0,   501,     0,     0,
     533,     0,   501,     0,   497,     0,    14,     0,     0,     0,
       0,     0,     0,     0,   637,     0,     0,     0,     0,     0,
       0,   641,   645,   322,   320,   321,   314,   315,   316,   308,
       0,     0,   303,     0,   297,   260,     0,     0,   274,   266,
       0,   270,     0,   264,     0,     0,     0,   283,     0,     0,
       0,   240,   286,   289,     0,   675,   666,   672,     0,     0,
     745,   746,   756,   755,   754,     0,     0,     0,     0,   747,
     652,   753,     0,   650,   654,     0,     0,   659,   663,     0,
     684,   679,   682,   678,   586,   581,     0,     0,   596,     0,
       0,     0,     0,   566,     0,   584,     0,   587,     0,     0,
       0,   585,   590,     0,     0,   561,   616,   555,   580,   780,
     781,   779,   562,   732,     0,     0,   730,   737,   738,   734,
       0,   729,     0,   727,     0,     0,     0,     0,     0,     0,
     543,     0,     0,     0,    66,   282,   549,     0,     0,   334,
     338,   332,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   545,     0,     0,   501,     0,   528,
       0,   501,   551,   621,   622,   626,   627,     0,   633,   775,
     635,     0,     0,     0,     0,   642,   317,   304,   299,     0,
     263,     0,   272,     0,     0,   268,     0,   271,   284,   292,
     293,   287,   239,   670,   757,     0,     0,   749,     0,   695,
     694,   693,   692,   691,   656,     0,   748,   582,   583,     0,
     600,     0,   597,     0,   613,     0,     0,   589,   588,   595,
     603,     0,   593,     0,   591,   741,   740,   739,     0,   733,
     726,   724,     0,   721,   722,   716,   150,   152,   154,     0,
       0,     0,     0,     0,   206,   353,    72,   329,   335,     0,
     349,   345,   352,     0,     0,     0,   339,     0,     0,   341,
       0,   511,   505,   500,     0,   501,   491,     0,   771,     0,
       0,     0,     0,   302,   300,   267,   265,     0,   273,     0,
     751,   750,     0,     0,     0,     0,   604,     0,     0,   614,
     567,     0,     0,     0,   735,   728,     0,     0,   156,   155,
       0,     0,     0,     0,   151,     0,     0,     0,     0,     0,
     519,   513,     0,   512,   514,   520,   517,   507,     0,   506,
     508,   518,   493,     0,   494,     0,     0,   643,   301,   269,
       0,   752,   664,   601,   602,   605,   598,   599,   615,   594,
     592,   723,   153,   157,     0,     0,     0,     0,     0,     0,
     342,   340,     0,     0,   504,   515,   516,   503,   509,   510,
     495,     0,   291,   158,     0,     0,     0,   350,   346,     0,
       0,     0,     0,     0,     0,     0,     0,   160,     0,     0,
     159,     0,     0,     0,     0,     0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1487, -1487,  -209,  -185, -1487,  1231,  1232, -1487,  1246,  -473,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
    -911, -1487, -1487, -1487, -1487,  -232,  -506, -1487,   823,    54,
   -1487, -1487, -1487, -1487, -1487,   377,   613, -1487, -1487,    20,
    -163,  1087, -1487,  1072, -1487, -1487,  -566, -1487,   575, -1487,
     334, -1487,  -167,  -218, -1487,  -429, -1487,    12,   105,   210,
    -255,  -166, -1487,  -821, -1487, -1487,    74, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,   733,   171,  1126,
       0, -1487, -1487, -1487, -1487,   471, -1487, -1487,  -297, -1487,
       5, -1487, -1487,   917,  -973,  -785,  -743, -1487, -1487,   803,
   -1487, -1487,    36,   211, -1487, -1487, -1487,   232, -1486, -1487,
     497,   236, -1487, -1487,   241, -1213, -1487,  1026,   335, -1487,
   -1487,   332,  -927, -1487, -1487,   338, -1487, -1487, -1178, -1159,
   -1487,   327, -1353, -1487, -1487,   932,   933, -1487,  -428,   915,
   -1487, -1487,  -594,   218,  -570,   400,   404, -1487, -1487, -1487,
     690, -1487, -1487,  1221, -1487, -1487, -1487, -1487, -1487,  -793,
    -315,  -607, -1487, -1487,   272, -1487,  -486, -1487,   893, -1487,
    -376, -1487, -1487,   899,   900, -1487, -1487, -1487, -1487,   895,
   -1487,  -914, -1487,   323, -1487,   800,  -718, -1487, -1487, -1487,
   -1487, -1487,  -203,  -196, -1140,  -909, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,  -684,  -792,  -123,
    -763, -1487, -1487, -1487,  -855, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487,   205,   206,  -681,   -93,  -602, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487,   297, -1487, -1487,   290, -1487,   293,  -980, -1487,
   -1487, -1487,   234,   224,    55,   513, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,   237,
   -1487, -1487, -1487,    60,   510,   650, -1487, -1487, -1487, -1487,
   -1487,   426, -1487, -1487, -1453, -1487, -1487, -1487,  -505, -1487,
     192, -1487,    24, -1487, -1487, -1487, -1487, -1261, -1487,   251,
   -1487, -1487, -1487, -1487, -1487,  1042, -1487, -1487, -1487, -1487,
   -1487,  -848, -1487, -1487, -1487,  -365,  -108,   -49,   627, -1487
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   251,   564,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
    1168,   697,   269,   270,   271,   272,   273,   274,   871,   872,
     873,   275,   276,   277,   877,   878,   879,   278,   421,   279,
     280,   642,   281,   423,   424,   425,   431,   687,   688,   282,
    1149,   283,  1656,  1657,   284,   285,   286,   489,   287,   288,
     289,   290,   291,   690,   292,   293,   452,   294,   295,   296,
     297,   298,   299,   575,   300,   301,   767,   768,   302,   303,
     503,   305,   576,   588,  1031,  1032,   306,   577,   307,   579,
     504,   309,   310,   802,   803,  1295,   438,   311,   439,   440,
     809,  1296,  1297,  1298,   580,   581,  1018,  1019,  1452,   582,
    1015,  1016,  1269,  1270,  1271,  1272,   312,   704,   705,   313,
    1184,  1185,  1395,   314,  1187,  1188,   315,   316,  1190,  1191,
    1192,  1193,  1402,   317,   318,   319,   320,   816,   321,   322,
    1305,   323,   324,   325,   326,   327,   328,   329,   330,   331,
    1091,   332,   333,   334,   335,   606,   607,   336,   337,   338,
     339,   340,   341,   342,   998,   999,   343,   634,   635,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   848,
     354,   355,   356,  1219,   734,   735,   736,  1683,  1738,  1739,
    1732,  1733,  1740,  1734,  1220,  1221,   357,   358,  1222,   359,
     360,   361,   362,   363,   364,   365,   366,   934,  1403,  1356,
    1068,  1514,  1069,  1092,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,   710,  1705,   367,   368,   369,
     370,  1081,  1082,  1083,  1084,   371,   372,   373,   374,   375,
     376,   757,   758,   377,  1253,  1254,  1595,  1000,  1039,  1315,
    1316,  1040,  1041,  1042,  1043,  1044,  1325,  1497,  1498,  1045,
    1328,  1046,  1478,  1047,  1048,  1333,  1334,  1503,  1501,  1317,
    1318,  1319,  1320,  1622,   671,   898,   899,   900,   901,   902,
     903,  1133,  1545,  1653,  1134,  1543,  1651,   904,  1368,  1540,
    1536,  1537,  1538,   905,   906,  1321,  1329,  1488,  1322,  1484,
    1306,   378,   379,   380,   381,   492,   382,   383,   384,   385,
     386,  1085,  1086,  1087,  1088,  1169,   493,   387,   388,   389
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -924;
  const short int
  jsoniq_parser::yytable_[] =
  {
       304,   304,   304,   304,   304,   308,   308,   308,   308,   308,
     536,   578,   510,   394,   397,   398,   964,  1186,   824,  1024,
    1173,   837,   942,   630,   551,   643,   643,  1037,  1416,   843,
     422,  1406,   952,   559,   552,   747,   484,  1106,   646,   552,
     753,  1067,  1090,   825,   826,   827,   828,  1277,   554,   786,
     788,  1568,  1218,  1150,  1572,  1301,   494,  1447,  1448,   507,
    1151,  1025,  1136,   556,   543,   544,  1499,  1137,  1138,   694,
     698,   511,  1021,   514,     7,     8,  1139,   552,  1284,  1424,
     778,   782,  1659,  1140,   552,  1141,  1142,   858,   516,   552,
     552,  1654,  1176,   739,  1143,   407,   552,   987,   436,     9,
     721,   552,  1028,  1681,   552,   304,   395,   395,   395,   399,
     308,  1110,  1693,     7,     8,   552,   558,   446,   722,  1396,
    1026,  1144,   853,   410,   780,   784,   787,   789,   519,  1162,
     520,   932,   722,  1022,   407,  1480,   629,   552,   552,  1022,
    1174,   559,   563,   552,   408,   559,   433,   563,   403,   404,
     525,   405,   406,   939,   685,  1138,   434,   853,   932,  1266,
     122,   677,   410,   812,   965,   813,   814,   411,   815,   409,
     817,   651,  1183,  1142,  1225,  1481,  1226,  1291,   818,   819,
    1268,    77,  1292,   435,  1023,  1393,   939,   652,   645,     9,
    1285,  1177,  1660,  1682,   447,    87,  1113,  1485,   563,   412,
     413,  1010,   854,   552,   552,  1397,   933,   578,  1748,   723,
     395,   396,   396,   396,   400,   980,   552,   521,  1211,  1212,
     101,   552,   552,   686,  1034,  1260,   437,  1035,   988,   552,
     552,   966,   552,  1596,   940,   559,  1161,   855,   887,   526,
     888,  1286,  1037,  1037,  1208,   563,   563,   981,   122,   304,
     304,   563,  1145,   304,   308,   308,   437,  1406,   308,   558,
    1399,  1386,   740,  1761,  1029,   448,   449,   954,   553,   786,
     788,    77,   415,   517,  1661,   555,   730,   502,   506,  1424,
     773,  1282,  1652,  1287,   889,    87,  1360,   775,   304,   147,
     148,   149,  1007,   308,  1107,  1009,  1218,  1346,  1505,   884,
     778,   782,  1150,  1455,  1030,  1218,  1259,   666,   552,  1151,
     101,   563,   563,   437,  1213,   490,  1725,   799,   681,   437,
     693,   779,   783,  1477,   563,   732,   925,   552,  1281,   563,
     563,   944,   930,  1036,  1214,   416,  1215,   563,   563,   678,
     563,   774,   776,  1289,  1146,  1147,  1148,   679,  1615,   769,
    1464,   791,   552,  -169,   552,   972,   770,   772,   548,   654,
    1486,  1487,   658,   661,  1216,   662,   511,   932,   108,   672,
     673,   970,  1381,  1769,   549,  1772,   417,   511,   418,   147,
     148,   149,  1365,  -170,   552,   120,   419,   699,  1033,   922,
     552,   945,   991,   706,   420,   645,   304,   711,   663,   631,
     304,   308,   716,   552,  1204,   308,  1217,   552,   561,  1205,
    1206,   538,   540,  1534,   401,   951,   563,  1689,  1690,  1209,
    1691,   552,  1396,  1022,   143,   664,  1616,   304,   304,   522,
     971,   523,   308,   308,   632,   563,   633,   706,   890,  1396,
     402,   552,  1367,   304,  1038,  1718,  1101,   304,   308,   728,
     494,   891,   308,   892,   552,   552,   552,   437,   552,   560,
     563,   427,   563,  1102,   893,   894,   895,   976,   896,   923,
     897,   932,  1376,   552,  1456,   494,  1569,  1100,  1535,   437,
     695,   759,   973,   974,   527,  1097,  1210,   665,   428,   528,
     304,   562,   563,  1457,  1096,   308,   610,   975,   563,   304,
    1241,   786,   788,   786,   308,  1218,  1763,  1361,  1558,   559,
    1037,   563,   919,  1746,   611,   563,  1114,  1115,   524,  1037,
    1433,  1118,   566,   844,   941,  1563,   567,   696,  1097,   563,
    1037,   568,   682,   683,   804,   304,  1011,   938,   804,  -169,
     308,  1004,   304,  1465,  1570,  1373,  1513,   308,   707,   563,
     569,  1159,   712,   304,   304,   304,   304,   426,   308,   308,
     308,   308,   563,   563,   563,  1098,   563,   560,   422,  -170,
    1008,   560,   304,   529,   776,   950,  1629,   308,  1261,  1262,
    1263,   563,   511,  1631,   661,   926,   662,  1406,   929,  1635,
    1453,  1255,   967,  1594,   977,   978,     7,     8,  1641,  -843,
     684,  1730,  1643,   691,   395,  1211,   968,  1680,  1099,   979,
    1619,   880,   703,  1022,   957,   708,   709,  1620,  1648,   932,
    1730,   715,   655,  -843,  1211,   910,   969,  1621,  1130,   914,
     915,   790,   781,   429,  -843,   792,   920,   400,   400,   993,
    1095,  1475,  1666,  1747,   511,  1131,   664,   511,  1256,   570,
    1256,   935,   571,   400,   430,   656,  1630,   400,  1752,  1038,
    1038,   560,   566,  1632,  1603,  1005,   567,   572,  1365,  1636,
     983,   568,  1288,   494,   781,  1570,  1303,  1604,  1642,   737,
     738,   549,  1644,   557,   962,  1366,   742,   566,  1132,   304,
     569,   567,   631,   573,   308,   631,   568,  1183,  1649,  1576,
     122,   924,  1037,  1404,  1580,   763,   765,  1006,   665,   396,
    1398,  1353,   485,   304,   304,   569,  1405,  1001,   308,   308,
    1492,  1214,   630,  1215,  1211,  1212,   442,   632,  1367,   633,
     632,  1731,   633,   613,  1211,   485,  1249,   583,   619,   584,
    1214,   574,  1215,  1354,  1265,   764,  1012,   485,   932,   485,
    1775,  1216,   620,   786,  1736,  1266,  1565,  1211,   874,  1027,
    1266,  1355,   614,  1399,   304,  1267,  1674,     7,     8,   308,
    1216,  1549,  1735,  1741,  1672,   615,  1268,  1736,   403,   404,
    1566,   405,   406,   791,  1089,  1089,  1093,  1093,   407,   570,
    1566,   304,   571,   610,   395,   776,   308,   441,   408,   409,
     839,   875,  1384,   845,   585,   422,   876,   731,  1291,   586,
     616,   611,  -923,  1292,   570,  1105,   410,   571,   948,   949,
    1213,   411,  1291,   932,  1735,  1089,   432,  1292,   822,   823,
    1741,   689,  1439,   573,  1257,  1450,  -923,  1211,  1212,  1123,
    1214,  1709,  1215,  1710,   610,  1678,  1293,  -923,  1211,  1212,
    1214,  1022,  1215,   412,   413,   414,   587,  1124,   573,  1684,
    1103,  1737,   611,  1687,  1156,  1022,  1768,     9,  1125,  1566,
    1216,  1451,  1089,  1214,   108,  1215,   610,  1104,  1130,   444,
    1216,   574,   451,  1089,  1778,   612,  1789,  1294,  1359,  1790,
    1566,   120,  1617,  1618,   611,  1131,   959,   960,   961,   396,
     765,  1443,   415,  1216,   689,  1307,   574,  1407,   647,  1614,
    1566,  1382,  1418,  1566,  1619,  1330,  1331,  1702,   443,  1758,
    1408,  1620,   648,   400,   400,  1108,   649,  1038,  1404,  1404,
     143,  1621,  1307,  1213,  1126,   992,  1038,  1108,  1332,  1658,
     650,  1575,  1781,  1153,  1213,  1127,   304,  1038,  1704,    77,
    1707,   308,  1154,  1214,   578,  1215,   667,   668,   669,   445,
    1712,   617,  1713,    87,  1214,   416,  1215,  1743,  1274,  1482,
     618,   804,   675,   450,  1719,   486,  1483,   676,  1308,  1119,
    1120,  1121,   518,  1216,   875,  1122,   508,   108,   101,   876,
     509,  1250,  1034,   515,  1216,  1035,  1251,  1230,   108,  1231,
    1116,  1117,  1444,  1445,   120,  1308,   417,   304,   304,   304,
     530,  1089,   308,   308,   308,   120,   122,   829,   830,   531,
    1554,  1700,  1701,   831,   832,  1423,   422,  1371,  1372,  1645,
    1646,   532,   418,   533,   653,   485,  1578,   534,   485,   535,
     419,   541,   485,   143,   545,   485,   485,   589,   420,   565,
     590,  1194,   608,   485,   143,   609,  1658,   147,   148,   149,
     621,   622,   623,   485,  1309,  1310,   624,  1311,   628,   485,
     636,   637,   638,   485,  1312,   639,   645,   640,   485,   591,
     641,   657,   536,   659,  1313,  1597,   660,   592,   593,   689,
     594,  1309,  1310,   670,  1311,   692,  1314,   674,   595,   700,
     702,   701,   596,   713,   597,   714,   719,   717,  1751,   598,
    1658,  1313,   721,   485,   733,  1089,   724,   741,   725,  1038,
     729,   743,   726,  1314,   755,   485,   599,   727,   744,   760,
     706,   756,   761,   766,   777,   795,   805,   796,   806,   808,
    1089,   820,  1560,   797,   798,   833,   834,   835,   836,   850,
     600,   601,   602,   603,   604,   605,   400,   485,   632,   859,
     304,   881,   856,   857,   885,   308,   304,   882,  1422,   907,
     886,   308,  1380,   908,   911,   909,   913,   916,   304,   921,
     917,   918,   927,   308,   799,   928,   931,   943,   982,  1800,
    1389,  1801,   946,   759,   947,   984,   990,   304,   985,   989,
    1006,  1809,   308,  1001,  1013,  1300,   986,  1001,  1020,  1411,
     485,  1003,   876,  1017,   485,  1109,   304,   932,  1128,  1129,
    1152,   308,  1160,   304,  1157,  1158,   685,   804,   308,  1164,
    1458,   491,  1518,   861,   862,   863,   864,   865,   866,   867,
     868,   869,   870,  1165,  1167,  1472,  1171,  1166,  1170,  1183,
    1172,  1178,  1179,  1182,  1200,  1250,  1189,  1195,   485,  1196,
    1251,  1199,  1197,  1202,  1203,   395,  1207,  1224,  1223,  1242,
    1252,   663,  1273,  1275,  1278,  1279,  1283,  1290,  1324,  1323,
    1304,  1335,  1327,   395,   860,     9,  1364,   485,  1510,  1089,
    1357,   511,  1519,  1520,  1336,  1524,  1664,  1363,  1369,  1374,
    1337,   485,   395,  1375,  1338,   485,   485,  1668,  1560,  1385,
    1670,  1339,   485,  1388,  1340,  1341,  1342,  1343,  1679,  1344,
     485,  1421,  1378,   485,  1410,  1547,  1345,   485,  1425,  1347,
    1348,  1349,  1350,  1351,  1352,  1379,  1404,  1415,  1417,  1420,
    1426,  1427,  1431,  1428,  1432,  1436,  1429,  1430,  1435,  1437,
    1438,  1255,  1564,  1266,  1460,  1089,  1462,  1466,  1089,  1468,
     485,  1469,  1470,  1474,  1495,  1500,  1476,  1496,  1502,  1577,
     396,  1479,  1504,  1489,  1581,  1515,  1533,  1539,  1521,  1544,
    1551,  1546,  1525,  1526,  1527,  1550,  1528,  1529,   396,  1552,
    1530,  1531,  1532,   485,  1553,  1542,  1548,   304,  1556,  1557,
    1574,  1562,   308,  1579,  1573,  1582,  1587,   396,  1599,  1601,
    1613,  1606,  1625,  1633,  1627,  1626,  1650,  1628,  1634,  1130,
    1609,  1610,   485,  1670,  1637,  1638,   400,  1639,  1640,  1655,
    1663,  1669,  1686,   400,  1450,   485,  1697,  1699,  1711,  1250,
    1714,  1726,  1662,  1716,  1251,  1717,  1728,  1721,  1715,  1742,
    1722,  1727,  1744,  1750,  1745,  1753,  1754,  1755,  1756,  1766,
     485,   485,   485,   485,  1757,   764,  1759,  1760,  1773,  1774,
    1777,  1780,  1770,  1767,  1786,  1764,  1791,  1784,  1792,  1799,
    1793,  1805,  1802,  1806,   546,   547,   883,  1362,  1111,   644,
    1382,  1377,  1796,  1798,   680,  1808,  1724,  1163,  1803,  1762,
    1002,   485,   550,  1299,   807,   937,  1473,  1454,  1611,  1449,
    1264,  1446,   718,  1787,  1390,   485,  1394,  1089,  1673,  1409,
    1675,   810,  1677,   811,   821,  1400,  1094,   849,  1442,  1685,
     841,   842,   852,  1419,   963,  1787,  1779,  1776,  1708,  1434,
     485,  1506,  1507,  1441,  1770,  1440,  1490,  1494,   485,  1302,
    1624,  1250,  1623,  1493,   627,  1326,  1251,  1135,  1370,   485,
    1541,  1647,  1250,  1250,  1491,   304,   751,  1251,  1251,     0,
     308,     0,     0,  1250,     0,     0,     0,     0,  1251,     0,
    1706,     0,  1706,     0,  1089,     0,  1089,     0,     0,     0,
       0,     0,   711,     0,   711,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1591,  1592,  1593,
    1720,     0,     0,  1723,     0,     0,     0,     0,     0,     0,
    1089,     0,     0,     0,     0,   491,     0,     0,     0,     0,
       0,  1729,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,   745,   746,   485,   748,   749,
     750,   752,     0,   754,     0,     0,     0,     0,     0,   762,
       0,     0,  1089,     0,     0,     0,     0,   771,     0,     0,
       0,     0,  1765,     0,     0,     0,     0,  1089,  1250,  1089,
       0,     0,     0,  1251,     0,     0,     0,   485,     0,   793,
     794,     0,     0,     0,     0,     0,     0,     0,   800,   801,
       0,  1782,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1785,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   304,     0,     0,
       0,     0,   308,     0,     0,     0,     0,  1794,     0,     0,
       0,     0,  1795,     0,     0,  1250,     0,     0,     0,     0,
    1251,     0,     0,     0,  1804,     0,     0,  1807,     0,   847,
       0,     0,     0,   847,     0,  1692,     0,     0,   304,     0,
       0,     0,     0,   308,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1250,   485,     0,     0,     0,  1251,  1703,     0,     0,  1250,
       0,     0,   912,     0,  1251,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   936,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   953,   485,     0,     0,   955,   956,     0,
     958,     0,     0,     0,     0,     0,     0,   800,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   485,
       0,     0,     0,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   794,     0,     0,
       0,   485,     0,  1014,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   485,   485,     0,   485,   485,   485,
       0,   485,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   485,  1112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,     0,
       0,   485,     0,     0,   485,     0,     0,  1155,     0,     0,
       0,     0,     0,     0,     0,   485,     0,     0,     0,     0,
     485,     0,     0,     0,     0,     0,     0,     0,     0,  1175,
       0,     0,     0,     0,     0,     0,  1180,  1181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1198,     0,     0,
    1201,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   485,   485,     0,  1227,
    1228,  1229,     0,  1232,  1233,  1234,  1235,  1236,  1237,  1238,
    1239,  1240,     0,     0,  1243,  1244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1258,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1014,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1280,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,   485,     0,   485,     0,   485,     0,
       0,     0,     0,     0,     0,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1358,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   485,     0,   485,     0,
     485,     0,   485,     0,     0,     0,     0,     0,   485,     0,
     485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   485,     0,     0,   485,
       0,     0,  1383,     0,     0,     0,   485,     0,     0,     0,
       0,     0,  1387,     0,     0,     0,     0,   485,  1391,  1392,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1412,     0,     0,  1413,  1414,
       0,     0,     0,     0,     0,     0,     0,     0,   485,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,     0,
       0,     0,     0,   485,     0,   485,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   485,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,     0,     0,     0,  1014,
       0,     0,     0,     0,     0,     0,     0,  1459,     0,  1461,
       0,  1463,     0,   485,  1467,     0,     0,     0,   485,  1471,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     485,     0,     0,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1555,     0,     0,     0,     0,     0,
       0,     0,  1559,  1561,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1383,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1583,  1584,  1585,  1586,     0,  1588,  1589,
       0,  1590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1598,     0,     0,
       0,     0,  1600,     0,     0,     0,  1602,     0,     0,     0,
    1605,     0,  1607,     0,  1608,     0,     0,     0,     0,     0,
    1612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1665,     0,
       0,     0,     0,  1667,  1561,     0,     0,     0,     0,     0,
       0,  1671,     0,     0,     0,     0,  1676,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1688,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1694,     0,  1695,     0,  1696,
       0,     0,  1698,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1671,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1749,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1771,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -165,   781,     0,     0,     0,     0,     0,
    1783,     0,     0,     0,  1788,     0,     0,     0,     0,  1771,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,  1788,     0,    10,   391,  1797,
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
     393,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   242,   243,   244,   245,   246,   247,   248,  -165,
     781,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,   785,   391,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   392,
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
       0,     0,   141,   142,   143,     0,   393,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   781,   241,     0,   242,   243,
     244,   245,   246,   247,   248,     0,     0,     0,     0,     0,
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
       0,   393,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     781,   241,     0,   242,   243,   244,   245,   246,   247,   248,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,   141,   142,   143,     0,   393,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   477,   478,   479,   173,   174,   480,   501,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,   242,   243,
     244,   245,   246,   247,   248,   994,   995,     0,     0,     0,
       0,     0,     0,     0,   996,     0,     0,     0,     0,     5,
       6,     0,     0,     0,     0,     0,     0,     0,   390,   391,
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
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
     997,     0,   129,     0,   130,   131,   132,   133,   471,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   393,   145,   146,     0,     0,     0,   150,   151,   152,
     153,   154,   155,   472,   157,   473,   159,   474,   475,   162,
     163,   164,   165,   166,   167,   476,   169,   477,   478,   479,
     173,   174,   480,   481,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   482,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,     0,     0,   242,   483,   244,   245,   246,   247,   248,
     487,     0,     0,     0,     0,     1,     2,     3,     4,     5,
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
     488,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   393,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,   241,     0,   242,   243,   244,   245,   246,   247,   248,
     487,     0,     0,     0,     0,     1,     2,     3,     4,     5,
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
       0,   393,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,   241,     0,   242,   243,   244,   245,   246,   247,   248,
     487,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   390,   391,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   495,   392,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   496,   497,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   467,    80,
      81,    82,    83,    84,   498,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   499,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   393,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   477,   478,   479,
     173,   174,   480,   501,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,   241,   487,   242,   243,   244,   245,   246,   247,   248,
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
       0,     0,   840,     0,   129,     0,   130,   131,   132,   133,
     471,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   393,   145,   146,     0,     0,     0,   150,
     151,   152,   153,   154,   155,   472,   157,   473,   159,   474,
     475,   162,   163,   164,   165,   166,   167,   476,   169,   477,
     478,   479,   173,   174,   480,   481,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   482,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,   487,     0,   242,   483,   244,   245,   246,
     247,   248,     5,     6,     0,     0,     0,  1516,     0,     0,
       0,   390,   391,     0,    12,    13,    14,   453,    16,    17,
      18,   454,    20,   455,   456,   457,   458,   392,    26,   459,
      28,    29,    30,     0,    31,    32,    33,    34,   460,    36,
      37,    38,    39,    40,    41,    42,   461,     0,    44,   462,
      46,   463,   464,    49,   465,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,   466,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   467,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   468,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,   104,     0,     0,     0,     0,     0,     0,   110,   469,
       0,     0,     0,     0,   112,   113,   114,   115,   470,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,  1517,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   471,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   393,   145,   146,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   472,   157,   473,   159,
     474,   475,   162,   163,   164,   165,   166,   167,   476,   169,
     477,   478,   479,   173,   174,   480,   481,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   482,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,   487,     0,   242,   483,   244,   245,
     246,   247,   248,     5,     6,     0,     0,     0,     0,     0,
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
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   471,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   393,   145,   146,     0,     0,
       0,   150,   151,   152,   153,   154,   155,   472,   157,   473,
     159,   474,   475,   162,   163,   164,   165,   166,   167,   476,
     169,   477,   478,   479,   173,   174,   480,   481,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     482,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     0,     0,   242,   483,   244,
     245,   246,   247,   248,   512,   513,     0,     0,     0,     0,
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
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     471,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   393,   145,   146,     0,     0,     0,   150,
     151,   152,   153,   154,   155,   472,   157,   473,   159,   474,
     475,   162,   163,   164,   165,   166,   167,   476,   169,   477,
     478,   479,   173,   174,   480,   481,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   482,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,     0,     0,   242,   483,   244,   245,   246,
     247,   248,     1,     2,     3,     4,     5,     6,     7,     8,
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
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
     242,   243,   244,   245,   246,   247,   248,   249,   250,     1,
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
     245,   246,   247,   248,     0,   542,     1,     2,     3,     4,
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
       0,   720,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   393,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,   245,   246,   247,
     248,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   390,   391,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     392,    26,    27,    28,    29,    30,     0,    31,    32,    33,
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
       0,     0,   123,   124,   125,     0,   488,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   393,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,   242,
     243,   244,   245,   246,   247,   248,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   390,
     391,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,  1245,   392,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,  1246,
    1247,    49,    50,    51,    52,    53,    54,    55,    56,    57,
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
     143,     0,   393,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,  1248,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,   245,   246,   247,
     248,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   390,   391,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     392,    26,    27,    28,    29,    30,     0,    31,    32,    33,
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
     140,     0,     0,   141,   142,   143,     0,   393,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,   242,
     243,   244,   245,   246,   247,   248,     1,     2,     3,     4,
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
     240,     0,   241,     0,   242,   243,   244,   245,   246,   247,
     248,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,    10,    11,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,     0,    31,    32,    33,
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
     140,     0,     0,   141,   142,   143,     0,   393,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,   242,
     243,   244,   245,   246,   247,   248,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,    10,
     391,     0,    12,    13,    14,    15,    16,    17,    18,    19,
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
     143,     0,   393,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,   245,   246,   247,
     248,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   785,   391,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     392,    26,    27,    28,    29,    30,     0,    31,    32,    33,
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
     140,     0,     0,   141,   142,   143,     0,   393,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,   242,
     243,   244,   245,   246,   247,   248,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   390,
     391,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,  1245,   392,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,  1246,
    1247,    49,    50,    51,    52,    53,    54,    55,    56,    57,
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
     143,     0,   393,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,  1248,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,   245,   246,   247,
     248,     1,     2,     3,     4,     5,     6,     0,     0,     0,
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
       0,     0,   123,   124,   125,     0,     0,   500,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   393,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   477,   478,   479,   173,   174,   480,   501,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,   242,
     243,   244,   245,   246,   247,   248,     1,     2,     3,     4,
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
       0,     0,     0,   126,   505,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   393,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   477,   478,
     479,   173,   174,   480,   501,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,   245,   246,   247,
     248,     1,     2,     3,     4,     5,     6,     0,     0,     0,
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
     140,     0,     0,   141,   142,   143,     0,   393,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   477,   478,   479,   173,   174,   480,   501,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   537,   241,     0,   242,
     243,   244,   245,   246,   247,   248,     1,     2,     3,     4,
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
     143,     0,   393,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   477,   478,
     479,   173,   174,   480,   501,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,   539,   242,   243,   244,   245,   246,   247,
     248,     1,     2,     3,     4,     5,     6,     0,     0,     0,
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
       0,     0,   123,   124,   125,     0,   838,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   393,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   477,   478,   479,   173,   174,   480,   501,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,   242,
     243,   244,   245,   246,   247,   248,     1,     2,     3,     4,
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
       0,     0,     0,   126,   846,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   393,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   477,   478,
     479,   173,   174,   480,   501,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,   245,   246,   247,
     248,     1,     2,     3,     4,     5,     6,     0,     0,     0,
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
       0,     0,   123,   124,   125,     0,     0,     0,   126,   851,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   393,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   477,   478,   479,   173,   174,   480,   501,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,   242,
     243,   244,   245,   246,   247,   248,     1,     2,     3,     4,
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
     499,   106,     0,   107,   108,   625,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   626,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   393,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   472,   157,   473,   159,   474,   475,
     162,   163,   164,   165,   166,   167,   476,   169,   477,   478,
     479,   173,   174,   480,   481,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   482,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   483,   244,   245,   246,   247,
     248,     1,     2,     3,     4,     5,     6,     0,     0,     0,
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
     140,     0,     0,   141,   142,   143,     0,   393,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   477,   478,   479,   173,   174,   480,   501,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,   242,
     243,   244,   245,   246,   247,   248,     1,     2,     3,     4,
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
     143,     0,   393,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   472,   157,   473,   159,   474,   475,
     162,   163,   164,   165,   166,   167,   476,   169,   477,   478,
     479,   173,   174,   480,   481,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   482,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   483,   244,   245,   246,   247,
     248,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   390,   391,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   456,    23,   458,
     392,    26,   459,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   461,
       0,    44,    45,    46,   463,   464,    49,   465,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   467,    80,    81,    82,    83,    84,
     498,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   468,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   499,   106,     0,   107,   108,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   393,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   472,
     157,   473,   159,   474,   475,   162,   163,   164,   165,   166,
     167,   476,   169,   477,   478,   479,   173,   174,   480,   481,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   482,     0,   190,   191,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,   241,     0,   242,
     483,   244,   245,   246,   247,   248,     5,     6,     0,     0,
       0,     0,     0,     0,     0,   390,   391,     0,    12,    13,
      14,  1049,    16,    17,    18,   454,  1050,  1051,   456,  1052,
     458,   392,    26,   459,    28,  1053,    30,     0,    31,    32,
      33,    34,  1054,    36,  1055,  1056,    39,    40,    41,    42,
     461,     0,    44,  1057,    46,   463,   464,    49,   465,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
    1058,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   467,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   468,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,  1059,     0,     0,     0,  1060,
       0,     0,   110,   469,     0,     0,     0,     0,   112,   113,
     114,   115,   470,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
    1511,   127,   128,     0,     0,     0,     0,  1512,     0,   129,
       0,   130,   131,   132,   133,   471,   135,   136,   137,   138,
     139,   140,     0,     0,  1061,   142,     0,     0,   393,   145,
     146,     0,     0,     0,   150,   151,   152,   153,   154,   155,
     472,  1062,   473,   159,   474,   475,   162,   163,   164,   165,
     166,   167,   476,   169,   477,   478,   479,   173,   174,   480,
     481,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   482,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     5,     6,
     242,   483,   244,  1063,  1064,  1065,  1066,   390,   391,     0,
      12,    13,    14,  1049,    16,    17,    18,   454,  1050,  1051,
     456,  1052,   458,   392,    26,   459,    28,  1053,    30,     0,
      31,    32,    33,    34,  1054,    36,  1055,  1056,    39,    40,
      41,    42,   461,     0,    44,  1057,    46,   463,   464,    49,
     465,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,  1058,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   467,    80,    81,
      82,    83,    84,  1401,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     468,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,  1059,     0,     0,
       0,  1060,     0,     0,   110,   469,     0,     0,     0,     0,
     112,   113,   114,   115,   470,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   471,   135,   136,
     137,   138,   139,   140,     0,     0,  1061,   142,     0,     0,
     393,   145,   146,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   472,  1062,   473,   159,   474,   475,   162,   163,
     164,   165,   166,   167,   476,   169,   477,   478,   479,   173,
     174,   480,   481,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   482,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       5,     6,   242,   483,   244,  1063,  1064,  1065,  1066,   390,
     391,     0,    12,    13,    14,   453,    16,    17,    18,   454,
      20,   455,   456,   457,   458,   392,    26,   459,    28,    29,
      30,     0,    31,    32,    33,    34,   460,    36,    37,    38,
      39,    40,    41,    42,   461,     0,    44,   462,    46,   463,
     464,    49,   465,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,   466,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   467,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   468,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,   104,
       0,     0,     0,     0,     0,     0,   110,   469,     0,     0,
       0,     0,   112,   113,   114,   115,   470,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,  1508,   127,   128,     0,     0,     0,
       0,  1509,     0,   129,     0,   130,   131,   132,   133,   471,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   393,   145,   146,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   472,   157,   473,   159,   474,   475,
     162,   163,   164,   165,   166,   167,   476,   169,   477,   478,
     479,   173,   174,   480,   481,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   482,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     5,     6,   242,   483,   244,   245,   246,   247,
     248,   390,   391,     0,    12,    13,    14,   453,    16,    17,
      18,   454,    20,   455,   456,   457,   458,   392,    26,   459,
      28,    29,    30,     0,    31,    32,    33,    34,   460,    36,
      37,    38,    39,    40,    41,    42,   461,     0,    44,   462,
      46,   463,   464,    49,   465,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,   466,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   467,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   468,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,   104,     0,     0,     0,     0,     0,     0,   110,   469,
       0,     0,     0,     0,   112,   113,   114,   115,   470,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,  1522,   127,   128,     0,
       0,     0,     0,  1523,     0,   129,     0,   130,   131,   132,
     133,   471,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   393,   145,   146,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   472,   157,   473,   159,
     474,   475,   162,   163,   164,   165,   166,   167,   476,   169,
     477,   478,   479,   173,   174,   480,   481,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   482,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     5,     6,   242,   483,   244,   245,
     246,   247,   248,   390,   391,     0,    12,    13,    14,  1049,
      16,    17,    18,   454,  1050,  1051,   456,  1052,   458,   392,
      26,   459,    28,  1053,    30,     0,    31,    32,    33,    34,
    1054,    36,  1055,  1056,    39,    40,    41,    42,   461,     0,
      44,  1057,    46,   463,   464,    49,   465,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,  1058,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   467,    80,    81,    82,    83,    84,  1567,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   468,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,  1059,     0,     0,     0,  1060,     0,     0,
     110,   469,     0,     0,     0,     0,   112,   113,   114,   115,
     470,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   471,   135,   136,   137,   138,   139,   140,
       0,     0,  1061,   142,     0,     0,   393,   145,   146,     0,
       0,     0,   150,   151,   152,   153,   154,   155,   472,  1062,
     473,   159,   474,   475,   162,   163,   164,   165,   166,   167,
     476,   169,   477,   478,   479,   173,   174,   480,   481,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   482,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     5,     6,   242,   483,
     244,  1063,  1064,  1065,  1066,   390,   391,     0,    12,    13,
      14,  1049,    16,    17,    18,   454,  1050,  1051,   456,  1052,
     458,   392,    26,   459,    28,  1053,    30,     0,    31,    32,
      33,    34,  1054,    36,  1055,  1056,    39,    40,    41,    42,
     461,     0,    44,  1057,    46,   463,   464,    49,   465,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
    1058,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   467,    80,    81,    82,    83,
      84,  1571,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   468,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,  1059,     0,     0,     0,  1060,
       0,     0,   110,   469,     0,     0,     0,     0,   112,   113,
     114,   115,   470,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   471,   135,   136,   137,   138,
     139,   140,     0,     0,  1061,   142,     0,     0,   393,   145,
     146,     0,     0,     0,   150,   151,   152,   153,   154,   155,
     472,  1062,   473,   159,   474,   475,   162,   163,   164,   165,
     166,   167,   476,   169,   477,   478,   479,   173,   174,   480,
     481,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   482,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     5,     6,
     242,   483,   244,  1063,  1064,  1065,  1066,   390,   391,     0,
      12,    13,    14,  1049,    16,    17,    18,   454,  1050,  1051,
     456,  1052,   458,   392,    26,   459,    28,  1053,    30,     0,
      31,    32,    33,    34,  1054,    36,  1055,  1056,    39,    40,
      41,    42,   461,     0,    44,  1057,    46,   463,   464,    49,
     465,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,  1058,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   467,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     468,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,  1059,     0,     0,
       0,  1060,     0,     0,   110,   469,     0,     0,     0,     0,
     112,   113,   114,   115,   470,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   471,   135,   136,
     137,   138,   139,   140,     0,     0,  1061,   142,     0,     0,
     393,   145,   146,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   472,  1062,   473,   159,   474,   475,   162,   163,
     164,   165,   166,   167,   476,   169,   477,   478,   479,   173,
     174,   480,   481,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   482,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       5,     6,   242,   483,   244,  1063,  1064,  1065,  1066,   390,
     391,     0,    12,    13,    14,  1049,    16,    17,    18,   454,
    1050,  1051,   456,  1052,   458,   392,    26,   459,    28,  1053,
      30,     0,    31,    32,    33,    34,  1054,    36,  1055,  1056,
      39,    40,    41,    42,   461,     0,    44,  1057,    46,   463,
     464,    49,   465,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,  1058,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   467,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   468,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,  1059,
       0,     0,     0,  1060,     0,     0,   110,   469,     0,     0,
       0,     0,   112,   113,   114,   115,   470,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   471,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
       0,     0,   393,   145,   146,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   472,  1062,   473,   159,   474,   475,
     162,   163,   164,   165,   166,   167,   476,   169,   477,   478,
     479,   173,   174,   480,   481,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   482,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     5,     6,   242,   483,   244,  1063,  1064,  1065,
    1066,   390,   391,     0,    12,    13,    14,   453,    16,    17,
      18,   454,    20,   455,   456,   457,   458,   392,    26,   459,
      28,    29,    30,     0,    31,    32,    33,    34,   460,    36,
      37,    38,    39,    40,    41,    42,   461,     0,    44,   462,
      46,   463,   464,    49,   465,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,   466,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   467,    80,    81,    82,    83,    84,  1276,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   468,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,   104,     0,     0,     0,     0,     0,     0,   110,   469,
       0,     0,     0,     0,   112,   113,   114,   115,   470,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   471,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,     0,     0,   393,   145,   146,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   472,   157,   473,   159,
     474,   475,   162,   163,   164,   165,   166,   167,   476,   169,
     477,   478,   479,   173,   174,   480,   481,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   482,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     5,     6,   242,   483,   244,   245,
     246,   247,   248,   390,   391,     0,    12,    13,    14,   453,
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
       0,     0,   141,   142,     0,     0,   393,   145,   146,     0,
       0,     0,   150,   151,   152,   153,   154,   155,   472,   157,
     473,   159,   474,   475,   162,   163,   164,   165,   166,   167,
     476,   169,   477,   478,   479,   173,   174,   480,   481,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   482,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     5,     6,   242,   483,
     244,   245,   246,   247,   248,   390,   391,     0,    12,    13,
      14,     0,    16,    17,    18,   454,     0,     0,   456,   457,
       0,   392,    26,   459,    28,     0,    30,     0,    31,    32,
      33,    34,     0,    36,     0,     0,    39,    40,    41,    42,
     461,     0,    44,     0,    46,     0,     0,    49,   465,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
       0,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   467,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   468,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   110,   469,     0,     0,     0,     0,   112,   113,
     114,   115,   470,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   471,   135,   136,   137,   138,
     139,   140,     0,     0,     0,   142,     0,     0,   393,   145,
     146,     0,     0,     0,   150,   151,   152,   153,   154,   155,
     472,     0,   473,   159,   474,   475,   162,   163,   164,   165,
     166,   167,   476,   169,   477,   478,   479,   173,   174,     0,
     481,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   482,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     0,     0,
     242,   483,   244,   245,   246,   247,   248
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     176,   308,   120,     1,     2,     3,   734,   944,   612,   804,
     931,   628,   706,   338,   256,   401,   402,   820,  1206,   631,
      10,  1190,   716,   288,     1,   521,    85,   858,   403,     1,
     526,   833,   834,   613,   614,   615,   616,  1020,   257,   555,
     556,  1404,   966,   908,  1407,  1035,   105,  1270,  1271,   108,
     908,   804,    40,   272,   249,   250,  1327,    45,    46,   434,
     435,   120,    37,   122,    27,    28,    54,     1,    37,  1219,
     553,   554,   120,    61,     1,    63,    64,   653,    31,     1,
       1,  1544,   144,     8,    72,    48,     1,   109,   120,    30,
     123,     1,    57,    95,     1,   105,     1,     2,     3,     4,
     105,   874,  1598,    27,    28,     1,   279,    78,   109,   102,
     804,    99,   109,    76,   553,   554,   555,   556,   230,   921,
     232,    96,   109,    98,    48,   219,   155,     1,     1,    98,
     932,   396,   109,     1,    58,   400,    25,   109,    38,    39,
     230,    41,    42,   109,   120,    46,    35,   109,    96,   108,
     179,   114,    76,   591,   132,   593,   594,    81,   596,    59,
     598,   168,   102,    64,   237,   259,   239,    55,   606,   607,
     129,   112,    60,    62,   149,   115,   109,   184,    30,    30,
     149,   934,   230,   185,   155,   126,   880,    98,   109,   113,
     114,   115,   189,     1,     1,   188,   144,   504,  1694,   186,
     105,     1,     2,     3,     4,   238,     1,   319,     9,    10,
     151,     1,     1,   189,   155,   115,   278,   158,   240,     1,
       1,   199,     1,  1446,   190,   490,   920,   189,    56,   319,
      58,  1026,  1035,  1036,   962,   109,   109,   238,   179,   249,
     250,   109,   230,   253,   249,   250,   278,  1416,   253,   422,
    1187,  1172,   177,  1716,   219,   226,   227,   190,   192,   775,
     776,   112,   162,   216,   312,   192,   187,   106,   107,  1419,
     192,  1024,  1543,  1026,   102,   126,  1107,   192,   288,   220,
     221,   222,   192,   288,   860,   192,  1210,  1060,   189,   664,
     773,   774,  1157,  1276,   259,  1219,   192,   415,     1,  1157,
     151,   109,   109,   278,   105,   105,  1669,   572,   426,   278,
     162,   553,   554,  1303,   109,   189,   189,     1,   149,   109,
     109,   189,   697,   264,   125,   225,   127,   109,   109,   292,
     109,   550,   551,  1027,   322,   323,   324,   300,    53,   316,
     149,   560,     1,     0,     1,    96,   318,   542,    34,   408,
     261,   262,   411,    46,   155,    48,   415,    96,   159,   418,
     419,   133,  1164,  1726,    50,  1728,   266,   426,   292,   220,
     221,   222,    98,     0,     1,   176,   300,   436,   816,   109,
       1,   189,   189,   442,   308,    30,   396,   446,    81,   121,
     400,   396,   451,     1,   189,   400,   197,     1,   109,   189,
     189,   240,   241,   138,   158,   144,   109,   189,   189,   132,
     189,     1,   102,    98,   215,   108,   131,   427,   428,   230,
     192,   232,   427,   428,   156,   109,   158,   486,   256,   102,
     158,     1,   158,   443,   820,  1658,   150,   447,   443,   498,
     499,   269,   447,   271,     1,     1,     1,   278,     1,   288,
     109,   155,   109,   167,   282,   283,   284,    96,   286,   189,
     288,    96,  1156,     1,   149,   524,   120,   853,   203,   278,
     115,   530,   223,   224,   230,   109,   199,   170,   155,   235,
     490,   192,   109,  1278,   187,   490,   160,   238,   109,   499,
     986,  1007,  1008,  1009,   499,  1419,  1719,  1109,   188,   764,
    1303,   109,   186,  1691,   178,   109,   881,   882,   319,  1312,
     242,   886,    43,   631,   149,   188,    47,   162,   109,   109,
    1323,    52,   427,   428,   583,   535,   791,   186,   587,   186,
     535,   773,   542,  1286,   188,  1152,  1338,   542,   443,   109,
      71,   916,   447,   553,   554,   555,   556,   162,   553,   554,
     555,   556,   109,   109,   109,   189,   109,   396,   548,   186,
     779,   400,   572,   319,   783,   186,   109,   572,  1007,  1008,
    1009,   109,   631,   109,    46,   693,    48,  1746,   696,   109,
    1274,   155,   186,   155,   223,   224,    27,    28,   109,   123,
     429,     5,   109,   432,   499,     9,   186,   120,   189,   238,
     274,   660,   441,    98,   722,   444,   445,   281,   109,    96,
       5,   450,   171,   147,     9,   674,   186,   291,    98,   678,
     679,   557,     1,   155,   158,   561,   685,   427,   428,   186,
     186,   186,  1553,   186,   693,   115,   108,   696,   212,   170,
     212,   700,   173,   443,   158,   204,   189,   447,   186,  1035,
    1036,   490,    43,   189,   149,    34,    47,   188,    98,   189,
      96,    52,   149,   722,     1,   188,   155,  1462,   189,   508,
     509,    50,   189,   114,   733,   115,   515,    43,   158,   689,
      71,    47,   121,   214,   689,   121,    52,   102,   189,  1417,
     179,   689,  1495,   102,  1422,   534,   535,    34,   170,   499,
     115,   146,    85,   713,   714,    71,   115,   766,   713,   714,
    1314,   125,  1037,   127,     9,    10,   120,   156,   158,   158,
     156,   135,   158,   119,     9,   108,   991,     1,   138,     3,
     125,   262,   127,   178,    97,   535,   795,   120,    96,   122,
     135,   155,   152,  1259,    29,   108,   188,     9,    96,   808,
     108,   196,   148,  1690,   764,   118,   188,    27,    28,   764,
     155,  1378,  1681,  1682,  1566,   161,   129,    29,    38,    39,
     212,    41,    42,   992,   833,   834,   835,   836,    48,   170,
     212,   791,   173,   160,   689,  1004,   791,   155,    58,    59,
     629,   139,  1167,   632,    68,   785,   144,   188,    55,    73,
     196,   178,   123,    60,   170,   139,    76,   173,   713,   714,
     105,    81,    55,    96,  1733,   874,   158,    60,   610,   611,
    1739,   155,   188,   214,  1000,   108,   147,     9,    10,   888,
     125,  1633,   127,  1635,   160,   188,    79,   158,     9,    10,
     125,    98,   127,   113,   114,   115,   120,   268,   214,  1577,
     150,   136,   178,  1581,   913,    98,   188,    30,   279,   212,
     155,   144,   921,   125,   159,   127,   160,   167,    98,   158,
     155,   262,   120,   932,   136,   201,   188,   120,   139,   188,
     212,   176,  1486,  1487,   178,   115,   725,   726,   727,   689,
     729,  1266,   162,   155,   155,    98,   262,   102,   184,  1479,
     212,  1166,   197,   212,   274,   252,   253,   201,   155,  1711,
     115,   281,   198,   713,   714,   871,   184,  1303,   102,   102,
     215,   291,    98,   105,   268,   764,  1312,   883,   275,  1546,
     198,   115,   115,   304,   105,   279,   946,  1323,  1629,   112,
    1631,   946,   313,   125,  1251,   127,   226,   227,   228,   158,
    1641,   203,  1643,   126,   125,   225,   127,  1685,  1017,   273,
     212,  1020,   139,   155,  1658,   120,   280,   144,   171,   282,
     283,   284,   218,   155,   139,   288,   155,   159,   151,   144,
     155,   991,   155,   155,   155,   158,   991,   237,   159,   239,
     130,   131,   130,   131,   176,   171,   266,  1007,  1008,  1009,
     120,  1060,  1007,  1008,  1009,   176,   179,   617,   618,   246,
    1385,  1615,  1616,   619,   620,   197,  1006,  1150,  1151,  1534,
    1535,   246,   292,   247,   407,   408,   197,   158,   411,   155,
     300,   319,   415,   215,     0,   418,   419,   169,   308,   192,
      94,   946,   254,   426,   215,   101,  1663,   220,   221,   222,
      51,   202,   103,   436,   257,   258,   104,   260,   195,   442,
     147,   158,   186,   446,   267,   186,    30,   186,   451,   134,
     186,    48,  1248,   154,   277,  1450,   120,   142,   143,   155,
     145,   257,   258,   251,   260,     1,   289,   309,   153,   120,
     109,   144,   157,   155,   159,   155,   186,   144,  1702,   164,
    1717,   277,   123,   486,    36,  1164,   123,    17,   158,  1495,
     155,   216,   158,   289,   236,   498,   181,   158,    30,   192,
    1179,   235,   192,   250,     3,   120,   289,   170,   289,   120,
    1189,    72,  1397,   172,   172,   236,    96,    96,    96,   151,
     205,   206,   207,   208,   209,   210,   946,   530,   156,    30,
    1160,   162,   109,   109,   129,  1160,  1166,   162,  1217,   251,
     134,  1166,  1160,    96,   144,   304,   120,   134,  1178,    96,
     186,   186,    98,  1178,  1439,    46,    98,   186,    96,  1796,
    1178,  1798,   155,  1242,   186,   242,   192,  1197,   230,   144,
      34,  1808,  1197,  1252,   172,  1034,   236,  1256,   109,  1197,
     583,   238,   144,   120,   587,   134,  1216,    96,    30,   291,
     232,  1216,   155,  1223,    96,   304,   120,  1276,  1223,    96,
    1279,   105,  1340,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   186,   134,  1294,   134,   200,   162,   102,
      98,   155,   120,   149,   192,  1255,   102,   186,   631,   186,
    1255,   144,   155,   123,   123,  1160,    36,    30,   155,   120,
     250,    81,   109,   109,   129,   120,   149,   259,   265,   263,
     290,   158,   272,  1178,   657,    30,    30,   660,  1337,  1338,
     146,  1340,  1341,  1342,   158,  1344,  1551,   291,    30,   292,
     158,   674,  1197,   311,   158,   678,   679,  1562,  1563,   109,
    1565,   158,   685,   144,   158,   158,   158,   158,  1573,   158,
     693,  1216,   232,   696,   186,  1374,   158,   700,  1223,   158,
     158,   158,   158,   158,   158,   192,   102,   200,   134,     7,
     192,   238,    98,   238,   242,   158,   238,   238,   188,   158,
     158,   155,  1401,   108,   149,  1404,   129,   149,  1407,   149,
     733,   120,   120,    79,   149,   291,   189,   287,    80,  1418,
    1160,   255,   189,   255,  1423,   189,    30,    30,   189,   109,
     128,   172,   189,   189,   189,   186,   189,   189,  1178,   128,
     189,   189,   189,   766,    98,   276,   262,  1397,   186,   188,
     186,   188,  1397,   186,   188,   186,   321,  1197,   144,   149,
     186,   149,   155,    96,   189,   285,    30,   189,   189,    98,
    1469,  1470,   795,  1678,   189,   189,  1216,   189,   189,   189,
     172,    96,   199,  1223,   108,   808,   149,    55,    96,  1439,
      30,    96,   292,   109,  1439,   109,    96,   120,   270,   199,
     230,   188,   199,   120,   200,   189,   189,   146,   189,   120,
     833,   834,   835,   836,   189,  1255,   189,   189,   188,    95,
     185,   199,  1727,   230,   120,   310,   120,   310,   298,   188,
     310,   230,   201,   120,   253,   253,   663,  1110,   875,   402,
    1745,  1157,   311,   311,   422,   311,  1663,   922,   292,  1717,
     767,   874,   256,  1032,   587,   702,  1295,  1275,  1472,  1273,
    1013,  1270,   486,  1768,  1179,   888,  1184,  1566,  1567,  1192,
    1569,   589,  1571,   590,   609,  1187,   836,   634,  1256,  1578,
     631,   631,   637,  1210,   734,  1790,  1739,  1733,  1631,  1242,
     913,  1336,  1336,  1253,  1799,  1252,  1312,  1323,   921,  1036,
    1495,  1551,  1492,  1316,   333,  1045,  1551,   907,  1132,   932,
    1368,  1537,  1562,  1563,  1313,  1565,   524,  1562,  1563,    -1,
    1565,    -1,    -1,  1573,    -1,    -1,    -1,    -1,  1573,    -1,
    1629,    -1,  1631,    -1,  1633,    -1,  1635,    -1,    -1,    -1,
      -1,    -1,  1641,    -1,  1643,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1436,  1437,  1438,
    1659,    -1,    -1,  1662,    -1,    -1,    -1,    -1,    -1,    -1,
    1669,    -1,    -1,    -1,    -1,   499,    -1,    -1,    -1,    -1,
      -1,  1680,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1017,   519,   520,  1020,   522,   523,
     524,   525,    -1,   527,    -1,    -1,    -1,    -1,    -1,   533,
      -1,    -1,  1711,    -1,    -1,    -1,    -1,   541,    -1,    -1,
      -1,    -1,  1721,    -1,    -1,    -1,    -1,  1726,  1678,  1728,
      -1,    -1,    -1,  1678,    -1,    -1,    -1,  1060,    -1,   563,
     564,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   572,   573,
      -1,  1750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1766,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1727,    -1,    -1,
      -1,    -1,  1727,    -1,    -1,    -1,    -1,  1786,    -1,    -1,
      -1,    -1,  1791,    -1,    -1,  1745,    -1,    -1,    -1,    -1,
    1745,    -1,    -1,    -1,  1803,    -1,    -1,  1806,    -1,   633,
      -1,    -1,    -1,   637,    -1,  1594,    -1,    -1,  1768,    -1,
      -1,    -1,    -1,  1768,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1790,  1164,    -1,    -1,    -1,  1790,  1625,    -1,    -1,  1799,
      -1,    -1,   676,    -1,  1799,    -1,  1179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   701,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   717,  1217,    -1,    -1,   721,   722,    -1,
     724,    -1,    -1,    -1,    -1,    -1,    -1,   731,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1252,
      -1,    -1,    -1,  1256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1276,    -1,    -1,  1279,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   791,    -1,    -1,
      -1,  1294,    -1,   797,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1337,  1338,    -1,  1340,  1341,  1342,
      -1,  1344,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1374,   876,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1401,    -1,
      -1,  1404,    -1,    -1,  1407,    -1,    -1,   911,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1418,    -1,    -1,    -1,    -1,
    1423,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   933,
      -1,    -1,    -1,    -1,    -1,    -1,   940,   941,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   951,    -1,    -1,
     954,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1469,  1470,    -1,   973,
     974,   975,    -1,   977,   978,   979,   980,   981,   982,   983,
     984,   985,    -1,    -1,   988,   989,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1003,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1013,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1023,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1566,  1567,    -1,  1569,    -1,  1571,    -1,
      -1,    -1,    -1,    -1,    -1,  1578,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1097,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1629,    -1,  1631,    -1,
    1633,    -1,  1635,    -1,    -1,    -1,    -1,    -1,  1641,    -1,
    1643,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1659,    -1,    -1,  1662,
      -1,    -1,  1166,    -1,    -1,    -1,  1669,    -1,    -1,    -1,
      -1,    -1,  1176,    -1,    -1,    -1,    -1,  1680,  1182,  1183,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1199,    -1,    -1,  1202,  1203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1711,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1721,    -1,
      -1,    -1,    -1,  1726,    -1,  1728,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1750,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1766,    -1,    -1,    -1,    -1,    -1,  1273,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1281,    -1,  1283,
      -1,  1285,    -1,  1786,  1288,    -1,    -1,    -1,  1791,  1293,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1803,    -1,    -1,  1806,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1388,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1396,  1397,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1415,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1427,  1428,  1429,  1430,    -1,  1432,  1433,
      -1,  1435,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1451,    -1,    -1,
      -1,    -1,  1456,    -1,    -1,    -1,  1460,    -1,    -1,    -1,
    1464,    -1,  1466,    -1,  1468,    -1,    -1,    -1,    -1,    -1,
    1474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1552,    -1,
      -1,    -1,    -1,  1557,  1558,    -1,    -1,    -1,    -1,    -1,
      -1,  1565,    -1,    -1,    -1,    -1,  1570,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1587,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1599,    -1,  1601,    -1,  1603,
      -1,    -1,  1606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1674,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1697,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1727,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,    -1,    -1,    -1,    -1,
    1764,    -1,    -1,    -1,  1768,    -1,    -1,    -1,    -1,  1773,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,  1789,    -1,    34,    35,  1793,
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
     317,    -1,   319,   320,   321,   322,   323,   324,   325,     0,
       1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,     1,   317,    -1,   319,   320,
     321,   322,   323,   324,   325,    -1,    -1,    -1,    -1,    -1,
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
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
       1,   317,    -1,   319,   320,   321,   322,   323,   324,   325,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,   317,    -1,   319,   320,
     321,   322,   323,   324,   325,    11,    12,    -1,    -1,    -1,
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
      -1,    -1,    -1,   319,   320,   321,   322,   323,   324,   325,
      16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
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
     186,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,   317,    -1,   319,   320,   321,   322,   323,   324,   325,
      16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
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
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,   317,    -1,   319,   320,   321,   322,   323,   324,   325,
      16,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
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
      -1,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,    -1,   264,   265,
     266,    -1,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,   317,    16,   319,   320,   321,   322,   323,   324,   325,
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
     314,    -1,    -1,    16,    -1,   319,   320,   321,   322,   323,
     324,   325,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
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
     313,   314,    -1,    -1,    16,    -1,   319,   320,   321,   322,
     323,   324,   325,    25,    26,    -1,    -1,    -1,    -1,    -1,
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
     312,   313,   314,    -1,    -1,    -1,    -1,   319,   320,   321,
     322,   323,   324,   325,    18,    19,    -1,    -1,    -1,    -1,
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
     314,    -1,    -1,    -1,    -1,   319,   320,   321,   322,   323,
     324,   325,    21,    22,    23,    24,    25,    26,    27,    28,
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
     309,   310,   311,   312,   313,   314,   315,    -1,   317,    -1,
     319,   320,   321,   322,   323,   324,   325,   326,   327,    21,
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
     322,   323,   324,   325,    -1,   327,    21,    22,    23,    24,
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
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,   324,
     325,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
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
      -1,    -1,   182,   183,   184,    -1,   186,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
     320,   321,   322,   323,   324,   325,    21,    22,    23,    24,
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
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,   324,
     325,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
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
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
     320,   321,   322,   323,   324,   325,    21,    22,    23,    24,
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
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,   324,
     325,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
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
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
     320,   321,   322,   323,   324,   325,    21,    22,    23,    24,
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
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,   324,
     325,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
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
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
     320,   321,   322,   323,   324,   325,    21,    22,    23,    24,
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
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,   324,
     325,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
      -1,    -1,   182,   183,   184,    -1,    -1,   187,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
     320,   321,   322,   323,   324,   325,    21,    22,    23,    24,
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
      -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,
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
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,   324,
     325,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    -1,   319,
     320,   321,   322,   323,   324,   325,    21,    22,    23,    24,
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
     315,    -1,   317,   318,   319,   320,   321,   322,   323,   324,
     325,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
      -1,    -1,   182,   183,   184,    -1,   186,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
     320,   321,   322,   323,   324,   325,    21,    22,    23,    24,
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
      -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,
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
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,   324,
     325,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
     320,   321,   322,   323,   324,   325,    21,    22,    23,    24,
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
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,   324,
     325,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
     320,   321,   322,   323,   324,   325,    21,    22,    23,    24,
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
     315,    -1,   317,    -1,   319,   320,   321,   322,   323,   324,
     325,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,    -1,   264,   265,   266,    -1,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,   317,    -1,   319,
     320,   321,   322,   323,   324,   325,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
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
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,
     219,    -1,    -1,    -1,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,    -1,    -1,    25,    26,
     319,   320,   321,   322,   323,   324,   325,    34,    35,    -1,
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
      25,    26,   319,   320,   321,   322,   323,   324,   325,    34,
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
      -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,    -1,   200,   201,   202,   203,   204,
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
      -1,    -1,    25,    26,   319,   320,   321,   322,   323,   324,
     325,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
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
     313,   314,    -1,    -1,    25,    26,   319,   320,   321,   322,
     323,   324,   325,    34,    35,    -1,    37,    38,    39,    40,
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
      -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,    -1,
      -1,    -1,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,    -1,    -1,    25,    26,   319,   320,
     321,   322,   323,   324,   325,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,   218,
     219,    -1,    -1,    -1,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,    -1,    -1,    25,    26,
     319,   320,   321,   322,   323,   324,   325,    34,    35,    -1,
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
      25,    26,   319,   320,   321,   322,   323,   324,   325,    34,
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
      -1,    -1,    25,    26,   319,   320,   321,   322,   323,   324,
     325,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
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
     313,   314,    -1,    -1,    25,    26,   319,   320,   321,   322,
     323,   324,   325,    34,    35,    -1,    37,    38,    39,    40,
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
      -1,    -1,   213,   214,    -1,    -1,   217,   218,   219,    -1,
      -1,    -1,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,    -1,   264,   265,   266,    -1,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,    -1,    -1,    25,    26,   319,   320,
     321,   322,   323,   324,   325,    34,    35,    -1,    37,    38,
      39,    -1,    41,    42,    43,    44,    -1,    -1,    47,    48,
      -1,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    -1,    62,    -1,    -1,    65,    66,    67,    68,
      69,    -1,    71,    -1,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      -1,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,   214,    -1,    -1,   217,   218,
     219,    -1,    -1,    -1,   223,   224,   225,   226,   227,   228,
     229,    -1,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    -1,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,    -1,   264,   265,   266,    -1,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,    -1,    -1,    -1,    -1,
     319,   320,   321,   322,   323,   324,   325
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
     315,   317,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   341,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   362,
     363,   364,   365,   366,   367,   371,   372,   373,   377,   379,
     380,   382,   389,   391,   394,   395,   396,   398,   399,   400,
     401,   402,   404,   405,   407,   408,   409,   410,   411,   412,
     414,   415,   418,   419,   420,   421,   426,   428,   430,   431,
     432,   437,   456,   459,   463,   466,   467,   473,   474,   475,
     476,   478,   479,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   491,   492,   493,   494,   497,   498,   499,   500,
     501,   502,   503,   506,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   520,   521,   522,   536,   537,   539,
     540,   541,   542,   543,   544,   545,   546,   567,   568,   569,
     570,   575,   576,   577,   578,   579,   580,   583,   641,   642,
     643,   644,   646,   647,   648,   649,   650,   657,   658,   659,
      34,    35,    50,   217,   397,   398,   399,   397,   397,   398,
     399,   158,   158,    38,    39,    41,    42,    48,    58,    59,
      76,    81,   113,   114,   115,   162,   225,   266,   292,   300,
     308,   378,   379,   383,   384,   385,   162,   155,   155,   155,
     158,   386,   158,    25,    35,    62,   120,   278,   436,   438,
     439,   155,   120,   155,   158,   158,    78,   155,   226,   227,
     155,   120,   406,    40,    44,    46,    47,    48,    49,    52,
      61,    69,    72,    74,    75,    77,    99,   114,   137,   162,
     171,   204,   229,   231,   233,   234,   241,   243,   244,   245,
     248,   249,   262,   320,   657,   658,   120,    16,   186,   397,
     399,   419,   645,   656,   657,    49,    74,    75,   120,   155,
     187,   249,   418,   420,   430,   189,   418,   657,   155,   155,
     656,   657,    18,    19,   657,   155,    31,   216,   218,   230,
     232,   319,   230,   232,   319,   230,   319,   230,   235,   319,
     120,   246,   246,   247,   158,   155,   401,   316,   418,   318,
     418,   319,   327,   343,   343,     0,   345,   346,    34,    50,
     348,   365,     1,   192,   342,   192,   342,   114,   380,   400,
     418,   109,   192,   109,   342,   192,    43,    47,    52,    71,
     170,   173,   188,   214,   262,   413,   422,   427,   428,   429,
     444,   445,   449,     1,     3,    68,    73,   120,   423,   169,
      94,   134,   142,   143,   145,   153,   157,   159,   164,   181,
     205,   206,   207,   208,   209,   210,   495,   496,   254,   101,
     160,   178,   201,   119,   148,   161,   196,   203,   212,   138,
     152,    51,   202,   103,   104,   160,   178,   493,   195,   155,
     500,   121,   156,   158,   507,   508,   147,   158,   186,   186,
     186,   186,   381,   510,   381,    30,   655,   184,   198,   184,
     198,   168,   184,   658,   657,   171,   204,    48,   657,   154,
     120,    46,    48,    81,   108,   170,   656,   226,   227,   228,
     251,   614,   657,   657,   309,   139,   144,   114,   292,   300,
     383,   656,   398,   398,   418,   120,   189,   387,   388,   155,
     403,   418,     1,   162,   655,   115,   162,   361,   655,   657,
     120,   144,   109,   418,   457,   458,   657,   398,   418,   418,
     565,   657,   398,   155,   155,   418,   657,   144,   457,   186,
     186,   123,   109,   186,   123,   158,   158,   158,   657,   155,
     187,   188,   189,    36,   524,   525,   526,   418,   418,     8,
     177,    17,   418,   216,    30,   419,   419,   506,   419,   419,
     419,   645,   419,   506,   419,   236,   235,   581,   582,   657,
     192,   192,   419,   418,   399,   418,   250,   416,   417,   316,
     318,   419,   343,   192,   342,   192,   342,     3,   349,   365,
     395,     1,   349,   365,   395,    34,   366,   395,   366,   395,
     406,   342,   406,   419,   419,   120,   170,   172,   172,   400,
     419,   419,   433,   434,   657,   289,   289,   433,   120,   440,
     475,   476,   478,   478,   478,   478,   477,   478,   478,   478,
      72,   479,   483,   483,   482,   484,   484,   484,   484,   485,
     485,   486,   486,   236,    96,    96,    96,   501,   186,   418,
     196,   513,   514,   567,   656,   418,   189,   419,   519,   508,
     151,   189,   519,   109,   189,   189,   109,   109,   386,    30,
     658,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   368,   369,   370,    96,   139,   144,   374,   375,   376,
     657,   162,   162,   368,   655,   129,   134,    56,    58,   102,
     256,   269,   271,   282,   283,   284,   286,   288,   615,   616,
     617,   618,   619,   620,   627,   633,   634,   251,    96,   304,
     657,   144,   419,   120,   657,   657,   134,   186,   186,   186,
     657,    96,   109,   189,   397,   189,   656,    98,    46,   656,
     655,    98,    96,   144,   547,   657,   419,   439,   186,   109,
     190,   149,   547,   186,   189,   189,   155,   186,   398,   398,
     186,   144,   547,   419,   190,   419,   419,   656,   419,   418,
     418,   418,   657,   525,   526,   132,   199,   186,   186,   186,
     133,   192,    96,   223,   224,   238,    96,   223,   224,   238,
     238,   238,    96,    96,   242,   230,   236,   109,   240,   144,
     192,   189,   418,   186,    11,    12,    20,   196,   504,   505,
     587,   657,   417,   238,   365,    34,    34,   192,   342,   192,
     115,   400,   657,   172,   419,   450,   451,   120,   446,   447,
     109,    37,    98,   149,   435,   436,   547,   657,    57,   219,
     259,   424,   425,   478,   155,   158,   264,   499,   510,   588,
     591,   592,   593,   594,   595,   599,   601,   603,   604,    40,
      45,    46,    48,    54,    61,    63,    64,    72,    99,   154,
     158,   213,   230,   322,   323,   324,   325,   548,   550,   552,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
     564,   571,   572,   573,   574,   651,   652,   653,   654,   657,
     548,   490,   553,   657,   490,   186,   187,   109,   189,   189,
     510,   150,   167,   150,   167,   139,   403,   386,   369,   134,
     550,   376,   419,   547,   655,   655,   130,   131,   655,   282,
     283,   284,   288,   657,   268,   279,   268,   279,    30,   291,
      98,   115,   158,   621,   624,   615,    40,    45,    46,    54,
      61,    63,    64,    72,    99,   230,   322,   323,   324,   390,
     554,   651,   232,   304,   313,   419,   657,    96,   304,   655,
     155,   547,   548,   388,    96,   186,   200,   134,   360,   655,
     162,   134,    98,   360,   548,   419,   144,   436,   155,   120,
     419,   419,   149,   102,   460,   461,   462,   464,   465,   102,
     468,   469,   470,   471,   398,   186,   186,   155,   419,   144,
     192,   419,   123,   123,   189,   189,   189,    36,   526,   132,
     199,     9,    10,   105,   125,   127,   155,   197,   521,   523,
     534,   535,   538,   155,    30,   237,   239,   419,   419,   419,
     237,   239,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   506,   120,   419,   419,    49,    74,    75,   249,   400,
     420,   430,   250,   584,   585,   155,   212,   401,   419,   192,
     115,   395,   395,   395,   450,    97,   108,   118,   129,   452,
     453,   454,   455,   109,   657,   109,   120,   434,   129,   120,
     419,   149,   436,   149,    37,   149,   435,   436,   149,   547,
     259,    55,    60,    79,   120,   435,   441,   442,   443,   425,
     418,   588,   595,   155,   290,   480,   640,    98,   171,   257,
     258,   260,   267,   277,   289,   589,   590,   609,   610,   611,
     612,   635,   638,   263,   265,   596,   614,   272,   600,   636,
     252,   253,   275,   605,   606,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   550,   158,   158,   158,
     158,   158,   158,   146,   178,   196,   549,   146,   419,   139,
     403,   567,   375,   291,    30,    98,   115,   158,   628,    30,
     621,   549,   549,   501,   292,   311,   547,   390,   232,   192,
     397,   548,   400,   419,   655,   109,   360,   419,   144,   397,
     458,   419,   419,   115,   461,   462,   102,   188,   115,   462,
     465,   120,   472,   548,   102,   115,   469,   102,   115,   471,
     186,   397,   419,   419,   419,   200,   468,   134,   197,   523,
       7,   398,   657,   197,   534,   398,   192,   238,   238,   238,
     238,    98,   242,   242,   582,   188,   158,   158,   158,   188,
     587,   585,   504,   655,   130,   131,   454,   455,   455,   451,
     108,   144,   448,   547,   447,   434,   149,   435,   657,   419,
     149,   419,   129,   419,   149,   436,   149,   419,   149,   120,
     120,   419,   657,   443,    79,   186,   189,   588,   602,   255,
     219,   259,   273,   280,   639,    98,   261,   262,   637,   255,
     592,   639,   482,   609,   593,   149,   287,   597,   598,   637,
     291,   608,    80,   607,   189,   189,   563,   564,   189,   196,
     657,   189,   196,   548,   551,   189,    30,   189,   656,   657,
     657,   189,   189,   196,   657,   189,   189,   189,   189,   189,
     189,   189,   189,    30,   138,   203,   630,   631,   632,    30,
     629,   630,   276,   625,   109,   622,   172,   657,   262,   501,
     186,   128,   128,    98,   655,   419,   186,   188,   188,   419,
     400,   419,   188,   188,   657,   188,   212,   120,   472,   120,
     188,   120,   472,   188,   186,   115,   526,   657,   197,   186,
     526,   657,   186,   419,   419,   419,   419,   321,   419,   419,
     419,   418,   418,   418,   155,   586,   455,   655,   419,   144,
     419,   149,   419,   149,   435,   419,   149,   419,   419,   657,
     657,   442,   419,   186,   484,    53,   131,   482,   482,   274,
     281,   291,   613,   613,   594,   155,   285,   189,   189,   109,
     189,   109,   189,    96,   189,   109,   189,   189,   189,   189,
     189,   109,   189,   109,   189,   628,   628,   632,   109,   189,
      30,   626,   637,   623,   624,   189,   392,   393,   501,   120,
     230,   312,   292,   172,   400,   419,   360,   419,   400,    96,
     400,   419,   548,   657,   188,   657,   419,   657,   188,   400,
     120,    95,   185,   527,   526,   657,   199,   526,   419,   189,
     189,   189,   418,   448,   419,   419,   419,   149,   419,    55,
     482,   482,   201,   418,   565,   566,   657,   565,   566,   548,
     548,    96,   565,   565,    30,   270,   109,   109,   455,   547,
     657,   120,   230,   657,   392,   472,    96,   188,    96,   657,
       5,   135,   530,   531,   533,   535,    29,   136,   528,   529,
     532,   535,   199,   526,   199,   200,   468,   186,   448,   419,
     120,   482,   186,   189,   189,   146,   189,   189,   548,   189,
     189,   624,   393,   455,   310,   657,   120,   230,   188,   472,
     400,   419,   472,   188,    95,   135,   533,   185,   136,   532,
     199,   115,   657,   419,   310,   657,   120,   400,   419,   188,
     188,   120,   298,   310,   657,   657,   311,   419,   311,   188,
     501,   501,   201,   292,   657,   230,   120,   657,   311,   501
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
     658,   658,   658,   658,   658,   658,   658,   658,   659
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
     654,    -1,   324,   158,   189,    -1,   322,   158,   189,    -1,
     323,   158,   189,    -1,    30,    -1,    16,    -1,   657,    -1,
     658,    -1,    99,    -1,    40,    -1,    45,    -1,    54,    -1,
      46,    -1,   154,    -1,    49,    -1,   230,    -1,    61,    -1,
      63,    -1,    64,    -1,    72,    -1,    75,    -1,    74,    -1,
     213,    -1,   248,    -1,   659,    -1,    25,    -1,   217,    -1,
     129,    -1,    39,    -1,   266,    -1,    38,    -1,   227,    -1,
     226,    -1,   148,    -1,    44,    -1,   264,    -1,   265,    -1,
     279,    -1,   268,    -1,   256,    -1,   290,    -1,   282,    -1,
     284,    -1,   283,    -1,   288,    -1,   260,    -1,   255,    -1,
      80,    -1,   219,    -1,   259,    -1,    53,    -1,   228,    -1,
     241,    -1,   307,    -1,   235,    -1,   205,    -1,   210,    -1,
     209,    -1,   208,    -1,   207,    -1,   206,    -1,    98,    -1,
     113,    -1,   114,    -1,   188,    -1,    47,    -1,    37,    -1,
      68,    -1,    73,    -1,    60,    -1,    55,    -1,    57,    -1,
      79,    -1,    43,    -1,   149,    -1,    52,    -1,   214,    -1,
     172,    -1,   173,    -1,   170,    -1,    71,    -1,    97,    -1,
     118,    -1,   130,    -1,   131,    -1,   108,    -1,    69,    -1,
     137,    -1,   190,    -1,   102,    -1,    96,    -1,   200,    -1,
     128,    -1,   169,    -1,    94,    -1,    51,    -1,   236,    -1,
     103,    -1,   201,    -1,   119,    -1,   161,    -1,   203,    -1,
     152,    -1,   138,    -1,    77,    -1,    78,    -1,   104,    -1,
     202,    -1,   153,    -1,   184,    -1,   198,    -1,   162,    -1,
     139,    -1,   133,    -1,   168,    -1,   150,    -1,   167,    -1,
      34,    -1,    41,    -1,    59,    -1,   115,    -1,    42,    -1,
      58,    -1,   218,    -1,    50,    -1,    62,    -1,    35,    -1,
      48,    -1,   278,    -1,   254,    -1,   287,    -1,   289,    -1,
     258,    -1,   272,    -1,   285,    -1,   277,    -1,   257,    -1,
     271,    -1,   286,    -1,   276,    -1,   270,    -1,   269,    -1,
     253,    -1,   252,    -1,   261,    -1,   262,    -1,   291,    -1,
     281,    -1,   280,    -1,   275,    -1,   273,    -1,   274,    -1,
     234,    -1,   240,    -1,   237,    -1,   231,    -1,   224,    -1,
     223,    -1,   225,    -1,   242,    -1,   232,    -1,   233,    -1,
     239,    -1,   229,    -1,   238,    -1,    67,    -1,    65,    -1,
      76,    -1,   171,    -1,   204,    -1,   247,    -1,   245,    -1,
     246,    -1,   243,    -1,   244,    -1,   249,    -1,   250,    -1,
     251,    -1,    66,    -1,   300,    -1,   298,    -1,   299,    -1,
     304,    -1,   305,    -1,   306,    -1,   301,    -1,   302,    -1,
     303,    -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,
      90,    -1,    91,    -1,   292,    -1,   293,    -1,   294,    -1,
     295,    -1,   296,    -1,   297,    -1,   308,    -1,   309,    -1,
     310,    -1,   311,    -1,   312,    -1,   313,    -1,   314,    -1,
      92,    -1,   107,    -1,   116,    -1,   174,    -1,   182,    -1,
     191,    -1,   140,    -1,    93,    -1,   117,    -1,   141,    -1,
     183,    -1,   319,    -1,   320,    -1,   321,    -1,   324,    -1,
     323,    -1,   322,    -1,   325,    -1,    26,    -1
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
    2766,  2770,  2774,  2776,  2778,  2780,  2782,  2784,  2786,  2788,
    2790,  2792,  2794,  2796,  2798,  2800,  2802,  2804,  2806,  2808,
    2810,  2812,  2814,  2816,  2818,  2820,  2822,  2824,  2826,  2828,
    2830,  2832,  2834,  2836,  2838,  2840,  2842,  2844,  2846,  2848,
    2850,  2852,  2854,  2856,  2858,  2860,  2862,  2864,  2866,  2868,
    2870,  2872,  2874,  2876,  2878,  2880,  2882,  2884,  2886,  2888,
    2890,  2892,  2894,  2896,  2898,  2900,  2902,  2904,  2906,  2908,
    2910,  2912,  2914,  2916,  2918,  2920,  2922,  2924,  2926,  2928,
    2930,  2932,  2934,  2936,  2938,  2940,  2942,  2944,  2946,  2948,
    2950,  2952,  2954,  2956,  2958,  2960,  2962,  2964,  2966,  2968,
    2970,  2972,  2974,  2976,  2978,  2980,  2982,  2984,  2986,  2988,
    2990,  2992,  2994,  2996,  2998,  3000,  3002,  3004,  3006,  3008,
    3010,  3012,  3014,  3016,  3018,  3020,  3022,  3024,  3026,  3028,
    3030,  3032,  3034,  3036,  3038,  3040,  3042,  3044,  3046,  3048,
    3050,  3052,  3054,  3056,  3058,  3060,  3062,  3064,  3066,  3068,
    3070,  3072,  3074,  3076,  3078,  3080,  3082,  3084,  3086,  3088,
    3090,  3092,  3094,  3096,  3098,  3100,  3102,  3104,  3106,  3108,
    3110,  3112,  3114,  3116,  3118,  3120,  3122,  3124,  3126,  3128,
    3130,  3132,  3134,  3136,  3138,  3140,  3142,  3144,  3146,  3148,
    3150,  3152,  3154,  3156,  3158,  3160,  3162,  3164,  3166,  3168,
    3170,  3172,  3174,  3176,  3178,  3180,  3182,  3184,  3186,  3188,
    3190,  3192,  3194,  3196,  3198,  3200,  3202,  3204,  3206,  3208,
    3210,  3212,  3214,  3216,  3218,  3220,  3222,  3224,  3226
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
    2697,  2698,  2703,  2710,  2720,  2726,  2735,  2743,  2743,  2751,
    2758,  2766,  2778,  2788,  2798,  2808,  2818,  2828,  2838,  2848,
    2859,  2868,  2878,  2888,  2904,  2913,  2922,  2930,  2936,  2948,
    2956,  2966,  2974,  2986,  2992,  3003,  3005,  3009,  3017,  3021,
    3026,  3030,  3034,  3038,  3048,  3056,  3063,  3069,  3079,  3083,
    3087,  3095,  3103,  3111,  3123,  3131,  3137,  3147,  3153,  3163,
    3167,  3177,  3183,  3189,  3195,  3204,  3213,  3222,  3235,  3239,
    3247,  3253,  3263,  3271,  3280,  3293,  3300,  3312,  3316,  3328,
    3335,  3341,  3350,  3357,  3363,  3374,  3381,  3387,  3396,  3405,
    3412,  3423,  3430,  3442,  3448,  3460,  3466,  3477,  3483,  3494,
    3500,  3511,  3517,  3528,  3537,  3541,  3550,  3554,  3562,  3566,
    3576,  3583,  3592,  3602,  3601,  3615,  3624,  3633,  3646,  3650,
    3662,  3666,  3674,  3677,  3684,  3688,  3697,  3701,  3705,  3713,
    3717,  3723,  3729,  3735,  3745,  3749,  3753,  3761,  3765,  3771,
    3781,  3785,  3795,  3799,  3809,  3813,  3823,  3827,  3837,  3841,
    3850,  3854,  3862,  3866,  3870,  3874,  3884,  3888,  3892,  3899,
    3904,  3912,  3916,  3920,  3924,  3928,  3932,  3940,  3944,  3948,
    3956,  3960,  3964,  3968,  3979,  3985,  3995,  4001,  4011,  4015,
    4019,  4082,  4104,  4132,  4296,  4300,  4310,  4314,  4318,  4322,
    4331,  4335,  4339,  4343,  4347,  4352,  4356,  4360,  4364,  4373,
    4379,  4389,  4397,  4401,  4405,  4409,  4413,  4417,  4421,  4425,
    4429,  4433,  4438,  4442,  4446,  4450,  4458,  4462,  4466,  4470,
    4478,  4485,  4492,  4502,  4506,  4514,  4522,  4526,  4534,  4542,
    4550,  4604,  4608,  4618,  4624,  4634,  4638,  4646,  4650,  4654,
    4662,  4670,  4687,  4695,  4712,  4731,  4755,  4761,  4772,  4778,
    4789,  4798,  4800,  4804,  4809,  4819,  4822,  4829,  4835,  4841,
    4848,  4860,  4863,  4870,  4876,  4882,  4889,  4900,  4904,  4912,
    4916,  4924,  4928,  4932,  4937,  4946,  4950,  4954,  4958,  4966,
    4971,  4979,  4984,  4992,  5000,  5005,  5010,  5015,  5020,  5025,
    5030,  5036,  5044,  5048,  5065,  5069,  5077,  5085,  5093,  5097,
    5105,  5109,  5117,  5125,  5129,  5133,  5168,  5174,  5180,  5190,
    5194,  5198,  5202,  5206,  5210,  5214,  5221,  5227,  5237,  5245,
    5253,  5257,  5261,  5265,  5269,  5273,  5277,  5281,  5285,  5289,
    5297,  5305,  5309,  5313,  5321,  5328,  5336,  5344,  5348,  5352,
    5360,  5364,  5370,  5376,  5380,  5390,  5398,  5402,  5408,  5417,
    5426,  5432,  5438,  5448,  5465,  5472,  5487,  5523,  5527,  5535,
    5543,  5555,  5559,  5567,  5575,  5579,  5590,  5607,  5613,  5619,
    5629,  5633,  5639,  5645,  5649,  5655,  5659,  5665,  5671,  5678,
    5688,  5693,  5701,  5707,  5717,  5739,  5748,  5754,  5767,  5781,
    5788,  5794,  5804,  5813,  5821,  5827,  5845,  5853,  5857,  5864,
    5869,  5877,  5881,  5888,  5892,  5899,  5903,  5910,  5914,  5923,
    5936,  5939,  5947,  5950,  5958,  5966,  5974,  5978,  5986,  5989,
    5997,  6009,  6012,  6020,  6032,  6038,  6048,  6051,  6059,  6063,
    6067,  6075,  6078,  6086,  6089,  6097,  6101,  6105,  6109,  6113,
    6121,  6129,  6141,  6153,  6157,  6161,  6169,  6175,  6185,  6189,
    6193,  6197,  6201,  6205,  6209,  6213,  6221,  6225,  6229,  6233,
    6241,  6247,  6257,  6267,  6271,  6279,  6289,  6300,  6307,  6311,
    6319,  6322,  6329,  6334,  6343,  6353,  6356,  6363,  6367,  6375,
    6384,  6391,  6401,  6405,  6412,  6418,  6428,  6431,  6438,  6443,
    6455,  6463,  6475,  6483,  6487,  6495,  6499,  6503,  6511,  6519,
    6523,  6527,  6531,  6539,  6547,  6559,  6563,  6571,  6585,  6589,
    6596,  6601,  6609,  6614,  6623,  6631,  6638,  6644,  6651,  6662,
    6668,  6678,  6685,  6692,  6717,  6745,  6773,  6777,  6781,  6788,
    6795,  6802,  6814,  6818,  6819,  6832,  6833,  6834,  6835,  6836,
    6837,  6838,  6839,  6840,  6841,  6842,  6843,  6844,  6845,  6846,
    6847,  6848,  6852,  6853,  6854,  6855,  6856,  6857,  6858,  6859,
    6860,  6861,  6862,  6863,  6864,  6865,  6866,  6867,  6868,  6869,
    6870,  6871,  6872,  6873,  6874,  6875,  6876,  6877,  6878,  6879,
    6880,  6881,  6882,  6883,  6884,  6885,  6886,  6887,  6888,  6889,
    6890,  6891,  6892,  6893,  6894,  6895,  6896,  6897,  6898,  6899,
    6900,  6901,  6902,  6903,  6904,  6905,  6906,  6907,  6908,  6909,
    6910,  6911,  6912,  6913,  6914,  6915,  6916,  6917,  6918,  6919,
    6920,  6921,  6922,  6923,  6924,  6925,  6926,  6927,  6928,  6929,
    6930,  6931,  6932,  6933,  6934,  6935,  6936,  6937,  6938,  6939,
    6940,  6941,  6942,  6943,  6944,  6945,  6946,  6947,  6948,  6949,
    6950,  6951,  6952,  6953,  6954,  6955,  6956,  6957,  6958,  6959,
    6960,  6961,  6962,  6963,  6964,  6965,  6966,  6967,  6968,  6969,
    6970,  6971,  6972,  6973,  6974,  6975,  6976,  6977,  6978,  6979,
    6980,  6981,  6982,  6983,  6984,  6985,  6986,  6987,  6988,  6989,
    6990,  6991,  6992,  6993,  6994,  6995,  6996,  6997,  6998,  6999,
    7000,  7001,  7002,  7003,  7004,  7005,  7006,  7007,  7008,  7009,
    7010,  7011,  7012,  7013,  7014,  7015,  7016,  7017,  7018,  7019,
    7020,  7021,  7022,  7023,  7024,  7025,  7026,  7027,  7028,  7029,
    7030,  7031,  7032,  7033,  7034,  7035,  7036,  7037,  7038,  7039,
    7040,  7041,  7042,  7043,  7044,  7045,  7046,  7047,  7048,  7049,
    7050,  7051,  7052,  7053,  7054,  7055,  7056,  7057,  7062
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
  const int jsoniq_parser::yylast_ = 16556;
  const int jsoniq_parser::yynnts_ = 320;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 545;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 340;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 594;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17398 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7066 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"


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

