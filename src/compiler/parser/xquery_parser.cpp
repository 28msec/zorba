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
#line 88 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"


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
#line 69 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 908 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1039 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 99 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 185 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 906 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2783 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2792 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2801 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2810 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 659: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2819 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 660: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2828 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 661: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2837 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 133 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2934 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1057 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1061 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1065 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1073 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1079 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1083 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1098 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1106 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1112 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1123 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1128 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1143 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1159 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1174 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1190 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1201 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1206 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1220 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1232 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1242 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1249 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1256 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1291 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1296 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1304 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1320 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1325 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1333 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1338 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1346 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1351 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1359 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1364 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1369 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1374 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1387 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1402 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1418 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1429 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1436 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1447 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1460 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1467 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1474 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1483 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1496 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1504 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1511 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1521 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1528 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1535 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1564 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1573 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1580 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1590 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1599 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1601 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1602 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1605 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1606 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1607 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1608 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1638 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1653 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1660 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1665 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1673 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1681 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1695 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1709 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1726 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1731 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1739 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1747 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1758 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1763 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1772 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1777 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1784 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1789 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1799 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1804 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1813 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1819 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1832 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1837 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1845 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1856 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1871 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1883 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1898 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1903 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1908 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1939 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1944 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1954 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1963 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1972 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1981 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1993 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1997 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2003 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2007 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2017 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2027 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2040 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2046 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2055 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2060 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2067 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2074 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2086 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2096 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2106 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2117 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2133 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2153 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2157 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2161 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2173 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2177 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2185 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2190 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2202 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2209 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2219 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2251 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2256 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2264 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2281 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2289 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2297 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2304 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2311 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2322 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2331 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2340 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2349 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2362 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2370 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2378 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2386 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2401 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2406 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2414 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2428 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2445 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2470 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2478 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2485 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2496 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2506 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2511 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2524 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2571 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2585 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2593 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2598 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2606 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2611 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2616 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2624 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2633 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2645 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2655 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2668 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2692 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2699 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2709 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2715 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2724 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2734 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2741 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2749 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2761 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2771 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2781 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2791 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2801 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2811 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2821 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2831 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2842 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2851 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2861 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2871 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2887 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2896 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2919 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2939 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2949 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2957 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2969 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2975 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2992 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3000 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3004 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3013 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3017 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3021 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3031 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3039 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3046 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3062 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3066 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3070 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3078 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3086 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3094 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3106 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3114 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3120 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3130 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3136 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3146 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3150 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3160 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3166 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3172 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3178 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3187 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3196 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3205 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3218 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3222 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3230 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3236 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3246 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3254 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3263 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3276 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3283 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3295 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3299 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3311 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3318 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3324 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3333 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3340 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3346 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3357 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3364 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3379 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3388 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3395 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3406 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3425 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3431 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3443 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3449 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3460 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3466 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3477 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3483 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3494 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3500 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3511 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3520 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3524 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3537 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3559 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3566 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3575 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3584 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3589 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3598 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3607 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3616 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3629 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3633 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3645 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3649 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3656 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3667 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3671 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3680 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3684 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3688 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3696 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3700 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3712 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3718 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3728 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3732 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3736 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3744 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3748 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3768 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3778 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3796 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3806 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3810 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3820 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3824 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3833 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3837 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3845 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3849 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3853 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3857 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3867 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3871 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3875 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3882 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3895 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3899 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3903 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3907 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3911 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3915 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3927 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3939 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3947 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3962 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3968 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3978 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3984 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3994 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3998 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4002 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4040 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4044 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4054 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4065 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4078 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4087 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4097 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4101 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4110 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4115 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4124 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4130 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4138 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4144 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4156 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4162 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4172 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4176 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4180 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4184 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4188 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4194 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4200 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4208 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4212 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4220 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4224 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4235 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4239 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4243 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4249 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4253 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4267 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4271 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4279 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4283 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4293 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4297 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4301 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4305 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4314 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4318 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4322 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4326 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4334 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4340 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4350 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4358 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4362 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4366 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4370 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4374 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4378 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4382 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4386 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4390 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4394 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4399 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4403 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4407 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4411 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4426 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4430 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4445 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4452 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4463 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4471 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4475 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4483 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4491 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4499 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4553 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4557 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4579 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4585 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4591 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4597 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4607 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4611 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4619 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4627 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4639 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4643 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4651 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4655 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4659 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4667 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4675 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4692 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4700 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4719 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4738 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4760 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4766 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4777 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4783 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4794 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4809 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4814 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4823 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4827 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4834 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4840 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4846 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4853 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4864 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4868 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4875 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4881 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4887 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4894 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4909 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4917 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4955 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4959 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4963 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4971 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4976 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4984 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4989 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4997 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5005 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5010 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5015 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5025 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5030 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5041 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5049 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5053 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5070 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5074 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5082 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5090 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5102 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5110 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5122 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5130 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5134 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5138 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5173 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5179 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5185 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5195 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5199 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5215 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5219 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5226 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5232 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5242 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5250 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5258 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5262 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5266 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5270 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5274 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5278 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5282 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5286 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5290 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5294 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5302 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5326 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5333 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5341 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5349 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5353 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5369 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5385 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5395 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5403 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5407 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5413 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 5422 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 5431 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5437 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5443 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5453 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5470 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5477 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5492 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5519 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5523 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5531 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5539 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5543 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5554 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5571 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5577 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5597 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5603 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5623 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5635 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5752 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5777 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5785 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5791 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5809 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5828 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5841 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5845 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5852 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5863 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5874 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5878 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 5899 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5903 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5910 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5914 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5922 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 5938 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5949 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5953 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5961 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 5972 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5976 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 5996 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6002 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6011 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6015 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6023 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6027 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6031 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6038 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6042 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6049 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6053 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6061 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6065 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6069 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6073 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6077 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6085 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6093 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6105 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6117 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6121 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6125 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6133 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6139 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6149 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6153 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6157 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6161 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6165 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6169 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6173 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6177 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6185 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6189 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6193 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6197 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6205 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6211 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6221 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6231 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6235 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6243 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6253 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6264 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6271 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6275 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6282 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6286 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6293 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6298 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6307 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6316 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6320 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6327 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6331 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6339 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6348 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6355 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6365 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6369 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6376 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6382 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6391 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6395 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6402 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6407 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6419 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6427 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6439 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6447 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6451 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6459 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6463 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6467 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6475 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6483 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6487 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6491 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6495 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6503 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6511 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6523 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6527 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6535 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6549 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6553 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6560 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6565 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6573 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6578 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6587 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6595 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6601 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6611 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6617 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6627 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6634 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6641 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6666 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6694 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6722 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6726 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6730 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6737 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6744 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6751 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6768 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 6781 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6782 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6783 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6784 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6785 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6786 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6787 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6788 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6789 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6790 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6791 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6792 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6793 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6794 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6795 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6796 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6801 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6802 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6803 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6804 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6805 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6807 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6808 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6809 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6810 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6811 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6812 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6813 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6814 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6815 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6816 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6817 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6818 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6819 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6820 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6821 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6822 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6823 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6824 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6825 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6826 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6827 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6828 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6829 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6830 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6831 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6832 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6833 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6834 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6835 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6836 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6837 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6840 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6841 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6842 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6843 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6844 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6845 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6847 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6848 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6849 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6850 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6851 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6852 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6853 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6854 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6855 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6857 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6858 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6859 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6860 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6861 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 6979 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 6980 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 6983 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 6984 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 6985 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 6986 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 6987 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 6988 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 6989 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 6990 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 6991 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 6992 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 6993 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 6994 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 6995 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 6996 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 6997 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 6998 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 6999 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 7000 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 7001 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 7002 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 7003 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 7004 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1027:

/* Line 690 of lalr1.cc  */
#line 7005 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1028:

/* Line 690 of lalr1.cc  */
#line 7010 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12352 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1532;
  const short int
  xquery_parser::yypact_[] =
  {
      4919, -1532, -1532, -1532,  6483,  6483,  6483,  6483, -1532, -1532,
     208,   323, -1532,   879,   410, -1532, -1532, -1532,    50, -1532,
   -1532, -1532,   368,   534,   817,  4637,   647,   657,   765, -1532,
     -32, -1532,   699, -1532, -1532, -1532, -1532, -1532,   842, -1532,
     783,   845, -1532, -1532, -1532, -1532,   691, -1532,   852, -1532,
     850,   854, -1532,   327, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,   463,   780,
   -1532, -1532, -1532, -1532,   740, 12723, -1532, -1532, -1532,   799,
   -1532, -1532, -1532,   896, -1532,   894,   910, -1532, -1532, 17128,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,   915, -1532,
   -1532,   913,   916, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
    5547,  8979,  9291, 17128, -1532, -1532,   884, -1532, -1532, -1532,
   -1532,   887, -1532, -1532,   919, 13622, -1532, 13927,   931,   932,
   -1532, -1532, -1532,   933, -1532, 12099, -1532, -1532, -1532, -1532,
   -1532, -1532,   903, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532,   140,   848, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532,   -69,   902,   262, -1532,  -105,   285, -1532, -1532, -1532,
   -1532, -1532, -1532,   941, -1532,   819,   822,   823, -1532, -1532,
     911,   918, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532,  9603,  9915, -1532,   754, -1532,
   -1532, -1532, -1532, -1532,  5233,  6795,  1068, -1532,  7107, -1532,
   -1532,   725,   102, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532,   103, -1532, -1532,
   -1532, -1532, -1532, -1532,   552, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532,  6483, -1532, -1532, -1532, -1532,    43, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532,   370, -1532,   882,
   -1532, -1532, -1532,   559, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532,   906,   977, -1532,   943,   825,   978,    14,   438,
     764,    57, -1532,  1027,   878,   979,   980, 10851, -1532,   886,
   -1532, -1532,    15, -1532, -1532, 12411, -1532,   467, -1532,   934,
   12723, -1532,   934, 12723, -1532, -1532, -1532,   815, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532,   942,   935, -1532, -1532, -1532, -1532, -1532,   905, -1532,
    6483,   908,   909,   912,  6483,   543,   543,  1067,   746,   752,
     745, 17417, 17128,   587,  1056, 17128,   951,   986,   598, 13622,
     756,   861, 17128, 17128,   804,   271,    63, -1532, -1532, -1532,
   13622,  6483,   923,  6483,   120, 11163, 14816, 17128, -1532,   827,
     828, 17128,   996,   243,   962, 11163,  1117,    89,   429, 17128,
     999,   976,  1016, -1532,   937, 11163, 13324, 17128, 17128, 17128,
    6483,   938, 11163, 11163, 17128,  6483,   973,   974, -1532, -1532,
   -1532, 11163, 15105,   972, -1532,   975, -1532, -1532, -1532, -1532,
     981, -1532,   982, -1532, -1532, -1532, -1532, -1532,   983, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, 17128, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532,   987, 17128, -1532, -1532, -1532,   949,  5859,  1013,
     314,   985,   989,   998, 17128,  6483, -1532,  1004,   101, -1532,
     629, -1532,   154,  1101, 11163, 11163, -1532, -1532,    85, -1532,
   -1532, -1532,  1143, -1532, -1532, -1532, -1532, 11163,   945, -1532,
    1136, 11163, 11163, 14229,   984, 11163, 11163, 11163, 11163, 14229,
   11163,   936,   939, 17128,   988,   990, 11163, 11163,  5547,   927,
   -1532,    64, -1532,    59, 11163,  6795, -1532, -1532, -1532, -1532,
   -1532,   879,   765,   108,   133,  1167,  7419,  3367,  7731,  3690,
     896, -1532, -1532,   418,   896, -1532, 11163,  4314, -1532,  1055,
     694,   -32,  1008,  1007,  1009,  6483, 11163, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, 11475, 11475, 11475, -1532, 11475,
   11475, -1532, 11475, -1532, 11475, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, 11475, 11475,  1111, 11475, 11475, 11475, 11475, 11475,
   11475, 11475, 11475, 11475, 11475, 11475, 11475,   952,  1090,  1091,
    1092, -1532, -1532, -1532, 11787, 10227, -1532, -1532, 12099, 12099,
   11163,   934, -1532, -1532,   934, -1532,  8043,   934,  1038,  8355,
   -1532, -1532, -1532, -1532,    53, -1532,   278, -1532, -1532, -1532,
   -1532, -1532, -1532,  1081,  1082,   647,  1162, -1532, -1532, 17417,
     963,   733, 17128,  1031,  1032,   963,  1067,  1066,  1063, -1532,
   -1532, -1532,   472,   950,  1103,   899, 17128,  1058, 11163,  1084,
   17128, 17128, -1532,  1069,  1019, -1532,  1020,   975,   845, -1532,
    1018,  1022,   197, -1532,   294,   298,  1100, -1532,    42, -1532,
   -1532,  1100, 17128,    30, 17128,  1116,   346, -1532,  6483, -1532,
     164, -1532, 13622,  1115,  1168, 13622,  1067,  1118,   622, 17128,
   11163,   -32, -1532,   231,  1028, -1532,  1029,  1030,  1033,    33,
   -1532,   377,  1034, -1532,   166,   206,  1070, -1532,  1035,  6483,
    6483,   258, -1532,   363,   395,   637, 11163,   183, -1532, -1532,
   11163, 11163, -1532, 11163, 11163, 11163, -1532, 11163, -1532, 11163,
   -1532, 17128,  1101, -1532,   270,   348,   361, -1532, -1532, -1532,
     390, -1532,   450, -1532, -1532,  1071,  1072,  1073,  1074,  1075,
     815,   942, -1532,   286,   397,     2,   -11,  1127,   500,   992,
     997,  1000,    27, -1532,  1088, -1532, -1532,  1042,   220,  5859,
     427, 13026,   927, -1532, -1532, -1532,  1001, -1532,   725,   646,
    1201,   803, -1532, -1532,   134, -1532, -1532, -1532,   136, -1532,
      99, -1532, -1532, -1532, -1532, -1532,  4002, -1532, -1532, -1532,
   17128,  1065, 11163,  1121, -1532, -1532, -1532,   977, -1532, -1532,
   -1532, -1532, -1532, 11475, -1532, -1532, -1532,    71, -1532,   438,
     438,   620,   764,   764,   764,   764,    57,    57, -1532, -1532,
   16261, 16261, 17128, 17128, -1532, -1532,   433, -1532, -1532,   111,
   -1532, -1532, -1532, -1532,   468, -1532, -1532,   498,   543, -1532,
   -1532,   711,   738,   785, -1532,   647, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532,   963, -1532,  1104, 16550,
    1098, 11163, -1532, -1532, -1532,  1147,  1067,  1067,   963, -1532,
     856,  1067,   710, 17128,   -75,   389,  1215, -1532, -1532,   958,
     588, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532,   472,    60,  1023,   667, 11163, -1532, 17128,  1151,
     947,  1067, -1532, -1532, -1532, -1532,  1099, 17128, -1532, 17128,
   -1532, 16839,  1128, 16261,  1138, 11163,    -3,  1107,    55,   566,
    1003, -1532, -1532,   796,    30,  1147, 16261,  1140,  1165,  1077,
    1064,  1131,  1067,  1105,  1132,  1171,  1067, 11163,   -36, -1532,
   -1532, -1532,  1122, -1532, -1532, -1532, -1532,  1150, 11163, 11163,
    1123, -1532,  1169,  1174,  6483, -1532,  1087,  1093,  1125, 17128,
   -1532, 17128, -1532, 11163,  1134,  1089, 11163, -1532,  1159,   233,
     237,   252,  1248, -1532,   339, -1532,   178,  1130, -1532, -1532,
    1257, -1532,   775, 11163, 11163, 11163,   779, 11163, 11163, 11163,
   11163, 11163, 11163, 11163, 11163, 11163, 14229,  1170, 11163, 11163,
   -1532,  8667,   116,  1041, -1532,   310, -1532, 11163,   149,   189,
      99,  7731,  3690,  7731,  1208, -1532, -1532, 11163,   814,  1183,
   -1532, 17128,  1185, -1532, -1532, 11163,    71,   605,    38, -1532,
    1010,   176,  1036,  1037, -1532, -1532,   861, -1532,  1026,   653,
    1142,  1144, 16550,  1146,  1148,  1149,  1153,  1154, -1532,   596,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532,  1172, -1532, -1532, -1532, -1532, 10539, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,   787, -1532,
    1278,   610, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532,  1025, -1532, -1532,  1284, -1532, -1532, -1532, -1532, -1532,
     621,  1285, -1532,    87, -1532, -1532, -1532,   972,   534,   699,
     981,   783,   982,   983,   902,  1148,  1149,  1153, -1532,   596,
     596, 11787,  1040,  1011, -1532,  1147,    60,  1094,  1124,  6483,
    1133,  1135,  1180,  1145,  1152, 17128, -1532,   555, -1532, 17128,
   -1532, 11163,  1178, 11163,  1188, 11163,    37,  1182, 11163,  1184,
   -1532,  1200,  1216, 11163, 17128,   810,  1256, -1532, -1532, -1532,
   -1532, -1532, -1532, 16261, -1532,  6483,  1067,  1228, -1532, -1532,
   -1532,  1067,  1228, -1532, 11163,  1195,  6483, 17128, -1532, -1532,
   11163, 11163,   416, -1532,    28,   732, -1532, 15394,   843, -1532,
     844, -1532,  1156, -1532, -1532,  6483,  1155,  1157, -1532, 11163,
   -1532, -1532, 11163,  1158,  1169,  1241, -1532,  1211, -1532,   287,
   -1532, -1532,  1340, -1532, -1532,  6483, 17128, -1532,   755, -1532,
   -1532, -1532,  6483,  1160,  1119,  1126, -1532, -1532, -1532,  1137,
    1139, -1532, -1532, -1532,  1252, -1532, -1532, -1532, -1532,  1112,
     302, 17128,  1177, -1532,  1198,  1199,  1204,  1213, -1532,   882,
     698, 13026,  1041, -1532,  6171, 13026, -1532, -1532,  1201,   591,
   -1532, -1532, -1532,  1183, -1532,  1067, -1532,   892, -1532,   614,
    1245, -1532, 11163,   686,  1121,   434,  1181, -1532,    71,  1114,
   -1532, -1532,   -56, -1532,   414,    80,  1129,    71,   414, 11475,
   -1532,   338, -1532, -1532, -1532, -1532, -1532, -1532,    71,  1210,
    1095,   950,    80, -1532, -1532,  1085,  1291, -1532, -1532, -1532,
   14527,  1186,  1189,  1193,  1194,  1196,  1197,  1206, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532,  1347,   311,  1358,   311,  1120,  1280, -1532, -1532,  1218,
   17128,  1141, -1532, -1532, 11787, -1532,  1212, -1532, -1532, -1532,
   -1532, -1532, -1532, 11163,  1247, -1532, -1532, 11163, -1532,   585,
   -1532, 11163,  1254, 11163, -1532, 11163, 17128, 17128, -1532,   781,
   -1532, 11163, -1532,  1269,  1273,  1306,  1067,  1228, -1532, 11163,
    1219, -1532, -1532, -1532,  1220, -1532,    77, 11163,  6483,  1221,
     325, -1532, 17128,   662, -1532, 15683,   132, -1532, 15972,  1222,
   -1532, -1532,  1225, -1532, -1532, -1532, -1532, 11163,   847,  1248,
   17128,   829, -1532,  1226,  1248, 17128, -1532,  1227, -1532, 11163,
   11163, 11163, 11163,  1096, 11163, 11163, -1532, 11163, 11163, 11163,
   11163,  8667,   343, -1532, -1532, -1532, -1532, -1532,  1245, -1532,
   -1532, -1532,  1067, 11163, -1532,  1262, -1532, -1532, -1532, -1532,
    1229, 11475, -1532, -1532, -1532, -1532, -1532,    88, 11475, 11475,
     -89, -1532,  1036, -1532,   261, -1532,  1037,    71,  1261, -1532,
   -1532,  1163, -1532, -1532, -1532, -1532,  1311,  1230, -1532,   516,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,    83,    83,
   -1532,   311, -1532, -1532,   531, -1532,  1387,    80,  1320,  1231,
   11787,   -24,  1161,  1249, -1532, -1532, 11163, -1532, 11163,  1274,
   -1532, 11163, -1532, -1532, -1532,  1367, -1532, -1532,  8667, 11163,
    1067, -1532, -1532, -1532, 11163, 11163, -1532, -1532, -1532,  8667,
    8667,  1328,  6483, 16261, 17128,   671, 17128, 11163, 17128,   678,
    8667, -1532,   490,    48,  1248, 17128, -1532,  1232,  1248, -1532,
   -1532, -1532, -1532, -1532, 11163, -1532, -1532, -1532,   256,   267,
     275, 11163, -1532, -1532, -1532,  1317, 11163, -1532,   764, 11475,
   11475,   620,   680, -1532, -1532, -1532, -1532, -1532, -1532, 11163,
   -1532, 16261, -1532, 16261,  1330, -1532, -1532, -1532,  1397, -1532,
   -1532, -1532,  1173,  1319, -1532, -1532,  1321, -1532,   855, 17128,
    1309,  1205, 17128, 11787, -1532, -1532, 11163, -1532,  1314, -1532,
   -1532,  1228, -1532, -1532, 16261, -1532, -1532, -1532,  1339, 11163,
    1250, -1532,  1341,  8667, -1532, 17128,   668,   439, -1532,  1240,
    1248, -1532,  1253, -1532,  1244,  1169,  1174,   436, -1532,  1317,
     620,   620, 11475,   437, -1532, -1532, 16261, -1532, -1532,  1320,
   11787, -1532,  1245,  1164, 17128,  1326,  1224,  1321, -1532, 17128,
     679, 16261,  6483, 16261,  1259, -1532, -1532,  1353,   693, -1532,
   -1532, -1532, -1532,  1264,   661, -1532, -1532, -1532,  1255, -1532,
    8667,   851, -1532, -1532,   620, -1532, -1532, -1532, -1532, -1532,
   11163,  1166, 17128,  1333, -1532,  6483,   685, -1532, -1532,   688,
   11163, -1532, -1532, -1532, -1532, -1532, -1532, -1532,  1335, -1532,
    1175,  1176, 17128, -1532, -1532, 11163,  8667, 17128,  1179, 11163,
    1187,  1268, 11787, -1532, 11787,  8667, -1532,  1258,  1190, 17128,
    1233,  1337, 17128,  1191, 11787, -1532
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
     969,   821,   973,  1022,   453,   463,   805,   445,     0,   192,
     446,   449,   807,   808,   810,   809,   814,   815,   816,   817,
     806,   813,   495,     0,   451,   450,   187,     0,     0,   211,
       0,   812,   819,   818,     0,   168,   780,   973,     0,   219,
       0,   496,     0,   527,     0,     0,   456,   803,     0,   804,
     427,   428,     0,   459,   458,   448,   431,     0,     0,   556,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     782,     0,   784,     0,     0,   165,     3,     4,     1,    10,
      12,     0,     0,     0,     0,     6,   165,     0,   165,     0,
       0,   119,   172,     0,     0,   190,     0,     0,   199,     0,
       0,     0,     0,     0,     0,     0,     0,   204,   232,   251,
     247,   253,   248,   250,   249,     0,     0,     0,   417,     0,
       0,   415,     0,   361,     0,   416,   409,   414,   413,   412,
     411,   410,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   403,   402,   399,     0,     0,   425,   430,     0,     0,
       0,   440,   473,   443,   442,   454,     0,   470,     0,     0,
     568,   570,   574,   576,     0,   124,     0,   802,    47,    44,
      45,    48,    49,     0,     0,     0,     0,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   639,
     640,   641,     0,   103,   142,     0,     0,   112,     0,     0,
       0,     0,   127,     0,     0,   612,     0,     0,     0,   607,
       0,     0,     0,   622,     0,     0,   255,   257,     0,   234,
     235,   254,     0,     0,     0,   134,     0,   138,   168,   510,
       0,    60,     0,    69,     0,     0,     0,    61,     0,     0,
       0,     0,   610,     0,     0,   613,     0,     0,     0,     0,
     323,     0,     0,   611,     0,     0,     0,   630,     0,     0,
       0,     0,   616,     0,     0,   194,     0,     0,   188,   186,
       0,     0,   786,     0,     0,     0,   495,     0,   781,     0,
     497,   528,   527,   524,     0,     0,     0,   558,   557,   426,
       0,   555,     0,   652,   653,   807,   810,   814,   817,   806,
     793,     0,   606,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   658,     0,   202,   203,     0,     0,     0,
       0,     0,   207,   208,   783,   785,     0,     5,    24,     0,
      25,     0,     7,    29,     0,    15,     8,    30,     0,    19,
     915,    77,    16,    78,    20,   193,     0,   191,   212,   213,
       0,     0,     0,     0,   205,   233,   292,   353,   355,   359,
     365,   364,   363,     0,   360,   357,   358,     0,   369,   376,
     375,   373,   379,   380,   381,   378,   383,   384,   387,   386,
       0,     0,     0,     0,   408,   422,     0,   435,   436,     0,
     474,   503,   471,   505,     0,   509,   501,     0,     0,   121,
     123,     0,     0,     0,   102,     0,    92,    94,    95,    96,
      97,    99,   100,   101,    93,    98,    88,    89,     0,     0,
     108,     0,   104,   106,   107,   114,     0,     0,    87,    46,
       0,     0,     0,     0,     0,     0,     0,   730,   735,     0,
       0,   731,   765,   718,   720,   721,   722,   724,   726,   725,
     723,   727,     0,     0,     0,     0,     0,   111,     0,   144,
       0,     0,   573,   567,   608,   609,     0,     0,   626,     0,
     623,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   237,     0,   242,   140,     0,     0,   135,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,   273,
     279,   276,     0,   615,   614,   621,   629,     0,     0,     0,
       0,   572,     0,     0,     0,   418,     0,     0,     0,     0,
     619,     0,   617,     0,   195,     0,     0,   787,     0,     0,
       0,     0,   527,   525,     0,   516,     0,     0,   499,   500,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,     0,     0,   666,     0,   209,     0,     0,     0,
       0,   165,     0,   165,     0,   173,   243,     0,   307,   303,
     305,     0,   293,   294,   362,     0,     0,     0,     0,   696,
     370,   669,   673,   675,   677,   679,   682,   689,   690,   698,
     925,   811,     0,   820,  1026,  1025,  1024,  1027,   389,   579,
     585,   586,   589,   633,   634,   590,   591,   796,   797,   798,
     594,   391,   393,   396,   595,   395,   423,   475,     0,   472,
     502,   125,    56,    57,    54,    55,   131,   130,     0,    90,
       0,     0,   109,   110,   115,    74,    75,    52,    53,    73,
     736,     0,   739,   766,     0,   729,   728,   733,   732,   764,
       0,     0,   741,     0,   737,   740,   719,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   146,
     148,     0,     0,     0,   113,   116,     0,     0,     0,   168,
       0,     0,   630,     0,     0,     0,   259,     0,   578,     0,
     260,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     238,     0,     0,     0,     0,   286,     0,   283,   288,   241,
     141,   136,   139,     0,   189,     0,     0,    71,    65,    68,
      67,     0,    63,   277,     0,     0,   168,     0,   321,   325,
       0,     0,     0,   328,     0,     0,   334,     0,     0,   341,
       0,   345,     0,   420,   419,   168,     0,     0,   196,     0,
     198,   322,     0,     0,     0,     0,   528,     0,   518,     0,
     551,   548,     0,   552,   553,     0,     0,   547,     0,   522,
     550,   549,     0,     0,     0,     0,   645,   646,   642,     0,
       0,   650,   651,   647,   789,   790,   656,   794,   654,     0,
       0,     0,     0,   660,   812,   819,   818,   973,   201,     0,
       0,     0,   661,   662,     0,     0,   210,   792,    26,     0,
      17,    21,    22,   304,   316,     0,   317,     0,   308,   309,
     310,   311,     0,   296,     0,     0,     0,   680,   693,     0,
     367,   371,     0,   712,     0,     0,     0,     0,     0,     0,
     668,   670,   671,   707,   708,   709,   711,   710,     0,     0,
     684,   683,     0,   687,   691,   705,   703,   702,   695,   699,
       0,     0,     0,     0,     0,     0,     0,     0,   582,   584,
     583,   580,   397,   504,   506,   133,   132,    91,   105,   753,
     734,     0,   758,     0,   758,   747,   742,   147,   149,     0,
       0,     0,   117,   145,     0,    27,     0,   627,   628,   631,
     624,   625,   258,     0,     0,   272,   264,     0,   268,     0,
     262,     0,     0,     0,   281,     0,     0,     0,   240,   284,
     287,     0,   137,     0,     0,    70,     0,    64,   278,     0,
       0,   324,   326,   331,     0,   329,     0,     0,     0,     0,
       0,   335,     0,     0,   349,     0,     0,   342,     0,     0,
     346,   421,     0,   620,   618,   197,   788,     0,     0,   527,
       0,     0,   559,     0,   527,     0,   523,     0,    14,     0,
       0,     0,     0,     0,     0,     0,   659,     0,     0,     0,
       0,     0,     0,   663,   667,   320,   318,   319,   312,   313,
     314,   306,     0,     0,   301,     0,   295,   697,   688,   694,
       0,     0,   767,   768,   778,   777,   776,     0,     0,     0,
       0,   769,   674,   775,     0,   672,   676,     0,     0,   681,
     685,     0,   706,   701,   704,   700,     0,     0,   592,     0,
     587,   638,   581,   800,   801,   799,   588,   754,     0,     0,
     752,   759,   760,   756,     0,   751,     0,   749,     0,     0,
       0,     0,     0,     0,   569,   261,     0,   270,     0,     0,
     266,     0,   269,   282,   290,   291,   285,   239,     0,     0,
       0,    66,   280,   575,     0,     0,   332,   336,   330,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   571,     0,     0,   527,     0,   554,     0,   527,   577,
     643,   644,   648,   649,     0,   655,   795,   657,     0,     0,
       0,     0,   664,   315,   302,   297,     0,   692,   779,     0,
       0,   771,     0,   717,   716,   715,   714,   713,   678,     0,
     770,     0,   635,     0,     0,   763,   762,   761,     0,   755,
     748,   746,     0,   743,   744,   738,   150,   152,   154,     0,
       0,     0,     0,     0,   265,   263,     0,   271,     0,   206,
     351,    72,   327,   333,     0,   347,   343,   350,     0,     0,
       0,   337,     0,     0,   339,     0,   537,   531,   526,     0,
     527,   517,     0,   791,     0,     0,     0,     0,   300,   298,
     773,   772,     0,     0,   636,   593,     0,   757,   750,     0,
       0,   156,   155,     0,     0,     0,     0,   151,   267,     0,
       0,     0,     0,     0,     0,   545,   539,     0,   538,   540,
     546,   543,   533,     0,   532,   534,   544,   519,     0,   520,
       0,     0,   665,   299,   774,   686,   637,   745,   153,   157,
       0,     0,     0,     0,   289,     0,     0,   340,   338,     0,
       0,   530,   541,   542,   529,   535,   536,   521,     0,   158,
       0,     0,     0,   348,   344,     0,     0,     0,     0,     0,
       0,     0,     0,   160,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1532, -1532,  -225,  -186, -1532,  1203,  1207, -1532,  1202,  -543,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1025, -1532, -1532, -1532, -1532,  -237,  -562, -1532,   723,    -9,
   -1532, -1532, -1532, -1532, -1532,   273,   492, -1532, -1532,    -5,
    -185,  1043, -1532,  1021, -1532, -1532,  -631, -1532,   431, -1532,
     230, -1532,  -241,  -286, -1532,  -552, -1532,     5,    44,    35,
    -248,  -180, -1532,  -880, -1532, -1532,   114, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532,   603,   -97,  1571,
       0, -1532, -1532, -1532, -1532,   442, -1532, -1532,  -301, -1532,
      23, -1532,  1017,  -943,  -746,  -737, -1532, -1532,   689, -1532,
   -1532,     3,   219, -1532, -1532, -1532,   104, -1531, -1532,   359,
     107, -1532, -1532,   112, -1308, -1532,   940,   203, -1532, -1532,
     200, -1024, -1532, -1532,   199, -1532, -1532, -1271, -1251, -1532,
     201, -1423, -1532, -1532,   849,   841, -1532,  -544,   831, -1532,
   -1532,  -660,   352,  -646,   264,   345, -1532, -1532, -1532,   567,
   -1532, -1532,  1209, -1532, -1532, -1532, -1532, -1532,  -892,  -326,
    -677, -1532,  -109, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
     -19,  -828, -1532,  -538,   649,   295, -1532,  -423, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532,   793, -1532, -1532, -1532, -1532,
   -1029, -1532,   184, -1532,   675,  -812, -1532, -1532, -1532, -1532,
   -1532,  -276,  -269, -1242,  -929, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532,  -769,  -867,  -205,  -808,
   -1532, -1532, -1532,  -872, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532,  1057,  1059,  -282,   491,   322, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,   165, -1532,
   -1532,   155, -1532,   159, -1074, -1532, -1532, -1532,   126,   119,
     -49,   393, -1532, -1532, -1532, -1532, -1532, -1532, -1532, -1532,
   -1532, -1532, -1532, -1532, -1532,   130, -1532, -1532, -1532,   -42,
     388,   533, -1532, -1532, -1532, -1532, -1532,   324, -1532, -1532,
   -1513, -1532, -1532, -1532,  -566, -1532,    92, -1532,   -63, -1532,
   -1532, -1532, -1532, -1323, -1532,   145, -1532, -1532, -1532, -1532,
   -1532,   948, -1532, -1532, -1532, -1532, -1532,  -923, -1532, -1532,
   -1532,  -414,  -369,   232,  1083, -1532
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   256,   637,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
    1277,   786,   274,   275,   276,   277,   278,   279,   966,   967,
     968,   280,   281,   282,   972,   973,   974,   283,   445,   284,
     285,   714,   286,   447,   448,   449,   464,   776,   777,   287,
    1228,   288,  1706,  1707,   289,   290,   291,   557,   292,   293,
     294,   295,   296,   779,   297,   298,   539,   299,   300,   301,
     302,   303,   304,   647,   305,   306,   872,   873,   307,   308,
     569,   310,   648,   462,  1033,  1034,   311,   649,   312,   651,
     570,   314,   766,   767,  1265,   471,   315,   472,   473,   773,
    1266,  1267,  1268,   652,   653,  1132,  1133,  1554,   654,  1129,
    1130,  1378,  1379,  1380,  1381,   316,   799,   800,   317,  1292,
    1293,  1496,   318,  1295,  1296,   319,   320,  1298,  1299,  1300,
    1301,  1503,   321,   322,   323,   324,   913,   325,   326,  1390,
     327,   328,   329,   330,   331,   332,   333,   334,   335,  1172,
     336,   337,   338,   339,   672,   673,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   707,   702,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   944,   367,   368,   369,   370,
     371,   372,  1328,   832,   833,   834,  1738,  1783,  1784,  1777,
    1778,  1785,  1779,  1329,  1330,   373,   374,  1331,   375,   376,
     377,   378,   379,   380,   381,   382,  1028,  1504,  1431,  1159,
    1589,  1160,  1173,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   806,  1241,   394,  1162,  1163,  1164,
    1165,   395,   396,   397,   398,   399,   400,   862,   863,   401,
    1362,  1363,  1672,  1115,  1140,  1400,  1401,  1141,  1142,  1143,
    1144,  1145,  1410,  1579,  1580,  1146,  1413,  1147,  1560,  1148,
    1149,  1418,  1419,  1585,  1583,  1402,  1403,  1404,  1405,  1686,
     743,   993,   994,   995,   996,   997,   998,  1214,  1609,  1703,
    1215,  1607,  1701,   999,  1444,  1604,  1600,  1601,  1602,  1000,
    1001,  1406,  1414,  1570,  1407,  1566,  1391,   402,   403,   404,
     405,   560,   406,   407,   408,   409,   410,  1166,  1167,  1168,
    1169,  1278,   578,   411,   412,   413
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -864;
  const short int
  xquery_parser::yytable_[] =
  {
       309,   609,   715,   715,   309,   309,   309,   309,   446,   418,
     421,   422,   650,   718,   568,   572,   696,   934,   921,  1048,
    1084,  1282,  1026,   313,   624,  1138,   586,   313,   313,   313,
     313,  1027,  1060,   922,   923,   924,   925,   627,  1294,   420,
     420,   420,   424,  1114,  1518,   632,  1074,  1507,   419,   419,
     419,   423,   629,   783,   787,   850,   534,  1327,  1161,  1161,
     625,   858,  1386,  1158,  1171,   625,   891,   893,   616,   617,
     738,  1549,  1550,  1187,   885,   889,   892,   894,  1246,  1022,
    1230,   753,  1645,   883,   887,  1649,  1526,  1030,   469,  1581,
      10,    11,  1254,   837,   953,  1704,  1709,  1161,   821,   631,
    1217,    12,   625,   625,   625,  1218,   757,   796,  1284,   625,
     309,   431,   625,   909,  1219,   910,   911,   625,   912,   717,
     914,  1220,   598,  1221,   758,   820,    10,    11,   915,   916,
    1497,  1229,  1222,   313,   625,   625,  1107,   625,  1023,   434,
    1024,  1679,  1057,  1736,  1748,   558,  1251,   431,   611,   613,
     625,  1161,   634,  1024,   419,   625,  1248,   432,   591,  1223,
     592,  1191,   948,  1562,  1161,   625,   757,   625,   636,  1271,
     695,   588,   632,   636,   676,   434,   632,   749,  1567,  1497,
     435,  1441,  1683,    81,   758,  1211,  1471,  1320,  1321,  1684,
    1205,  1025,   677,  1388,   127,   685,   633,    92,   625,  1685,
    1563,  1206,  1212,  1710,  1255,   451,  1194,   625,   452,   686,
     636,   599,   436,   437,  1124,   678,  1498,   127,  1793,  1680,
     636,   625,   106,  1058,  1101,   636,  1135,   427,   428,  1136,
     429,   430,   625,  1737,   625,   635,   697,  1100,   625,   470,
    1673,  1443,   949,   470,  1138,  1138,  1797,   593,   433,  1031,
     127,   782,  1646,   625,   309,   309,  1487,   625,   309,   625,
    1259,   631,   838,   636,  1108,  1635,  1270,  1507,   625,   650,
    1317,  1500,   470,   636,  1392,   636,   625,   313,   313,  1526,
    1161,   313,  1256,  1322,  1702,  1711,  1032,  1224,   828,  1252,
    1327,  1257,  1057,   309,   626,   628,  1320,  1321,  1177,  1327,
     878,  1770,  1462,  1323,  1369,  1324,   636,   535,  1436,   759,
     632,  1285,   470,  1230,  1559,   636,   313,   470,   891,   893,
    1647,   552,   979,   633,  1188,   880,  1121,   633,  1123,   636,
     470,   703,  1137,  1325,   705,   883,   887,   113,  1568,  1569,
     636,  1368,   636,   830,  1422,   573,   636,  1393,  1806,   625,
    1809,   439,   750,  1040,   125,  1062,   589,   579,   762,   582,
     751,   636,   625,   774,  1229,   636,   425,   636,   780,  1134,
    -169,   625,  1045,  1076,   875,  1326,   636,   874,   793,  1225,
    1226,  1227,  1092,  1016,   636,   804,   805,   948,   442,   884,
     888,   625,  1322,   151,   811,  1063,   443,   904,   879,   881,
    1761,  1161,  1085,  1017,   444,   484,  1482,  1019,   896,  1111,
     747,   440,  1323,  1041,  1324,   748,  1044,  1052,  -170,   625,
     309,   676,  1313,   821,   309,  1161,  1314,  1497,   625,   877,
    1394,  1395,   775,  1396,   625,   625,  1392,   625,   625,   677,
    1397,  1315,  1325,   313,  1068,  1744,   113,   313,  1320,  1598,
    1398,   309,   441,   309,  1799,  1037,  1745,   636,   700,   717,
     706,   633,  1399,   125,  1746,  1364,  1452,   950,  1781,  1086,
     636,  1318,  1069,  1023,   313,  1791,   313,   835,   836,   636,
     309,   426,   485,  1018,  1520,   309,   424,  1020,   424,   595,
     840,   596,  1327,  1096,  1139,   754,  1138,   756,  1671,   636,
     822,  1464,   151,   313,  1071,  1138,  1093,  1094,   313,  1393,
     868,   870,   600,  1640,  1599,   424,  1138,   601,  1291,  1472,
     424,  1095,  1365,   453,   802,  1181,  1059,   636,   982,   808,
     983,  1494,  1683,  1114,  1087,  1038,   636,  1544,  1319,  1684,
    1507,  1535,   636,   636,   784,   636,   636,  1088,  1161,  1685,
     486,   487,  1070,  1588,  1449,  1365,  -169,   679,   309,   891,
     893,   891,  1195,  1196,  1323,   309,  1324,  1199,  1350,  1370,
    1371,  1372,   450,    12,   984,  1782,  1089,  1178,   597,    10,
      11,   313,   535,  1090,  1072,   535,   680,   488,   313,   937,
     938,   785,  1394,  1395,  1325,  1396,  1103,  1238,   936,   681,
     420,   602,   639,   939,  -170,  1721,   640,  1178,   309,   419,
    1735,   641,  1398,  1113,  1555,   309,   446,  1097,  1098,  1176,
    1557,   632,  1792,  1795,  1399,  1693,   309,   309,   309,   309,
     642,   313,  1099,  1161,   682,    12,  1161,   733,   313,   734,
    1698,  1118,  1091,   869,   733,   309,   734,   886,  1125,   313,
     313,   313,   313,  1024,  1207,    81,   700,  1179,   706,  1122,
     698,   699,  1023,   881,   726,  1208,   630,   730,   313,    92,
    1320,   579,   639,  1775,   744,   745,   640,  1320,  1647,   735,
    1119,   641,   579,  1024,  1564,  1138,  1211,  1180,   765,   768,
    1781,  1565,   454,   768,   106,   457,   622,   458,  1775,   736,
     642,   788,  1320,  1212,  1463,  1694,   736,  1653,   579,   797,
     798,   801,  1657,  1139,  1139,  1258,   807,    81,  1023,  1441,
    1699,  1500,  1375,  1619,   814,   985,  1079,  1080,  1081,   643,
     870,    92,   644,  1023,  1618,  1240,  1442,  1243,   986,  1574,
     987,   639,  1428,  1377,   895,   640,  1213,   645,   897,   970,
     641,   988,   989,   990,   971,   991,   106,   992,   727,   621,
    1135,   737,   459,  1136,  1320,  1321,  1047,   460,   737,   642,
     815,  1161,  1112,   646,  1429,   622,  1727,  1613,   309,  1443,
     676,  1073,  1023,  1039,   127,   801,  1323,  1306,  1324,  1307,
     466,   728,  1430,  1323,  1552,  1324,   826,  1815,   677,   643,
     467,   313,   644,  1776,   886,   463,   891,  1780,  1786,   309,
     309,   479,   696,   420,   461,   465,  1325,   829,  1323,  1161,
    1324,  1161,   419,  1325,  1754,   851,  1755,   468,  1812,   969,
    1553,   851,   313,   313,  1291,   864,  1261,  1120,  1320,  1321,
     676,  1262,  1739,   646,   424,   424,  1742,  1499,  1325,  1780,
    1642,  1261,  1161,  1066,  1067,  1786,  1262,   474,   677,  1729,
    1322,  1182,  1485,  1358,   490,  1261,  1733,  1805,   643,   309,
    1262,   644,   970,  1825,  1643,  1263,  1826,   971,  1183,  1024,
    1323,  1752,  1324,  1643,  1161,   446,  1541,   896,  1184,  1796,
    1643,  1643,   313,   881,  1024,   491,   309,  1643,   492,  1161,
    1643,  1161,  1415,  1416,   489,  1185,    10,    11,  1681,  1682,
    1325,  1374,   646,   723,   113,  1678,  1264,   427,   428,   313,
     429,   430,  1375,   537,  1186,  1417,  1435,   431,  1788,   724,
     719,   125,  1376,  1708,  1322,  1366,   721,   432,   433,  1762,
     778,   477,   778,  1377,   720,  1505,  1508,   926,   927,  1505,
     722,  1023,  1525,  1505,  1323,   434,  1324,  1189,  1506,  1509,
     435,  1545,  1652,  1375,   975,  1139,  1818,   683,  1232,  1189,
     151,   700,   455,   706,  1139,   456,   684,  1233,  1005,   739,
     740,   741,  1009,  1010,  1325,  1139,  1197,  1198,   113,  1200,
    1201,  1202,   436,   437,   438,  1203,   940,   475,   701,   940,
     476,   704,   940,   478,  1029,   125,  1035,   480,   482,  1334,
     481,  1335,   483,  1339,   579,  1340,   538,   579,   540,  1750,
    1751,  1049,  1546,  1547,  1447,  1448,  1655,  1483,   919,   920,
     928,   929,  1695,  1696,   541,   553,  1708,   554,  1385,   574,
     555,   439,   575,   576,   151,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   583,   584,   585,   587,   650,
     594,   603,   604,  1082,   309,   605,   590,   606,   618,   607,
     614,   656,  1631,   608,   638,   655,   674,   657,   687,   675,
     688,   694,   689,  1708,   690,   658,   659,   313,   660,   708,
     700,   710,  1794,   709,   711,   712,   661,   717,   713,   424,
     662,   440,   663,   535,   729,   731,   732,   664,  1302,   742,
     746,  1359,   755,   769,   770,   446,   772,   778,   781,   789,
     790,   309,   309,   309,   665,   791,   792,   803,   809,   810,
     452,   816,  1126,   456,  1360,   818,   820,   831,  1674,   476,
     481,   492,   441,   823,   313,   313,   313,   824,   666,   667,
     668,   669,   670,   671,  1139,  1836,   825,  1837,   536,   827,
     839,   841,  1170,  1170,  1174,  1174,   842,  1845,   442,   860,
     882,   861,   536,   852,   871,   900,   443,   609,   901,   902,
     865,   903,   866,   917,   444,   930,   931,   932,   933,   945,
     951,   952,   954,   976,   977,   980,   536,   981,  1002,  1003,
    1004,  1170,  1006,  1011,  1008,  1012,  1013,  1014,   536,  1021,
     536,  1015,  1036,  1042,  1043,  1204,  1046,  1053,  1054,  1055,
    1061,  1065,  1056,  1102,  1105,  1064,   451,   455,   475,   480,
     491,  1104,  1109,  1106,  1110,  1120,  1117,  1127,  1190,   309,
    1235,  1131,   971,  1023,  1456,  1209,  1210,  1236,  1237,  1242,
    1637,  1242,  1231,   768,  1239,  1170,  1253,  1247,  1249,  1260,
     774,  1273,   313,  1274,  1275,  1276,  1280,  1279,  1170,  1281,
    1287,  1291,  1290,  1303,   420,   309,  1297,  1286,  1309,  1304,
    1305,  1310,  1312,   419,  1316,  1332,   309,  1333,  1361,   735,
    1351,  1490,  1382,   904,  1384,  1412,  1408,  1389,   313,  1409,
    1420,   807,  1421,   807,  1423,   309,  1424,  1425,    12,   313,
    1512,  1426,  1427,  1439,  1440,  1445,  1455,  1469,  1432,  1451,
    1476,   420,  1457,  1454,  1458,   309,  1459,  1467,   313,  1450,
     419,  1473,   309,  1475,  1460,  1481,  1477,  1486,   851,  1489,
     420,  1461,  1511,  1505,  1513,  1519,  1514,  1522,   313,   419,
    1533,  1534,  1528,  1375,  1529,   313,  1538,  1539,  1517,  1577,
     424,  1530,  1540,  1383,  1359,  1537,  1561,   424,  1364,  1523,
    1558,  1584,  1531,  1582,  1532,  1590,  1527,  1597,  1591,  1578,
    1719,  1571,  1592,  1593,  1170,  1594,  1595,  1360,  1603,  1608,
    1610,  1723,  1637,  1606,  1725,  1596,  1616,  1628,  1614,   869,
    1612,  1629,  1734,  1621,  1630,  1633,  1676,  1691,  1634,  1639,
    1650,  1651,  1656,  1659,  1664,  1677,  1689,  1700,  1211,  1692,
    1705,  1713,  1718,  1716,  1724,  1552,  1756,  1757,  1759,  1764,
    1760,  1741,  1765,   536,  1769,  1771,   536,  1773,  1772,  1787,
    1758,  1668,  1669,  1670,  1790,  1690,  1802,  1810,  1811,  1814,
    1712,  1803,  1789,  1822,  1817,  1827,  1835,  1842,   978,  1838,
    1841,   619,  1192,   623,  1438,   620,  1453,   752,  1272,   716,
    1828,  1800,  1767,  1820,  1798,  1116,  1269,   768,   771,  1839,
    1051,  1465,  1626,  1829,  1480,  1725,  1373,  1832,  1556,  1551,
    1491,  1548,  1495,   817,  1501,  1834,  1479,   908,   309,  1844,
    1175,  1510,   947,  1521,   907,  1170,   918,  1083,  1816,  1813,
    1244,   760,  1437,   761,   725,   536,  1536,  1543,   536,   801,
    1542,   313,   536,  1572,  1807,   536,   536,  1576,  1688,  1170,
    1387,  1575,  1687,   536,  1411,  1216,  1605,  1446,  1697,   536,
     536,  1359,  1483,  1573,   536,   856,   693,     0,     0,     0,
       0,     0,   536,     0,     0,     0,     0,  1823,  1524,   536,
     536,   536,   536,     0,  1360,     0,     0,   536,     0,     0,
       0,     0,     0,     0,  1747,   536,     0,     0,  1823,     0,
       0,     0,     0,   864,     0,     0,     0,  1807,     0,     0,
       0,     0,  1753,   535,     0,     0,     0,   535,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,     0,     0,     0,     0,     0,     0,  1359,     0,
       0,     0,     0,     0,     0,     0,   536,     0,     0,  1359,
    1359,     0,   309,     0,     0,     0,     0,   536,     0,     0,
    1359,  1360,  1170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1360,  1360,     0,   313,     0,     0,     0,     0,
       0,     0,     0,  1360,     0,     0,     0,     0,     0,     0,
       0,   559,  1611,     0,     0,     0,   536,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1624,  1625,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1359,  1641,     0,     0,  1170,     0,     0,
    1170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1654,     0,     0,     0,  1360,  1658,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   309,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1359,     0,     0,     0,     0,   313,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   309,     0,     0,     0,     0,
       0,     0,   955,  1360,     0,   536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1359,     0,   313,   536,
       0,     0,     0,   536,   536,  1359,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1360,
       0,     0,     0,     0,     0,   536,     0,   536,  1360,     0,
       0,     0,     0,     0,     0,   536,     0,     0,   536,     0,
       0,     0,   536,     0,     0,  1170,  1728,     0,  1730,     0,
    1732,     0,     0,     0,     0,     0,     0,  1740,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,     0,     0,     0,     0,     0,
       0,     0,     0,  1170,     0,  1170,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1763,     0,     0,  1766,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,     0,  1170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1774,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   536,     0,     0,     0,     0,  1170,     0,
       0,     0,     0,     0,     0,     0,  1801,     0,     0,     0,
       0,  1804,     0,  1170,     0,  1170,     0,     0,     0,     0,
       0,     0,     0,   536,   536,   536,   536,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1821,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   536,     0,  1830,     0,     0,     0,     0,  1831,
       0,     0,     0,     0,     0,     0,   536,     0,     0,     0,
       0,  1840,     0,     0,  1843,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,     0,     0,     0,     0,     0,     0,     0,     0,
     536,     0,   536,     0,   536,     0,   536,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   559,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   536,     0,   536,     0,     0,     0,     0,     0,
       0,     0,   843,   844,     0,     0,   853,   854,   855,   857,
       0,   859,     0,     0,     0,     0,     0,   867,     0,     0,
       0,     0,     0,     0,     0,   876,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   898,   899,     0,
       0,     0,     0,     0,   536,     0,   905,   906,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   943,     0,     0,
     943,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1007,
       0,     0,     0,     0,     0,     0,     0,     0,   536,     0,
       0,     0,   536,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   536,     0,     0,
       0,     0,     0,     0,     0,     0,   536,     0,     0,     0,
       0,  1050,     0,     0,     0,     0,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,  1075,     0,     0,
       0,  1077,  1078,     0,     0,     0,     0,     0,     0,     0,
     905,     0,     0,     0,     0,     0,     0,     0,     0,   536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,     0,     0,     0,   536,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   899,     0,     0,
       0,     0,     0,  1128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   536,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   536,     0,     0,     0,     0,     0,     0,
       0,     0,  1193,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   536,
     536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1234,     0,     0,
       0,     0,     0,     0,     0,   536,     0,     0,   536,     0,
       0,   536,     0,     0,     0,     0,  1250,     0,     0,     0,
       0,     0,     0,   536,     0,     0,     0,     0,   536,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1283,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1288,
    1289,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1308,     0,     0,  1311,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1336,  1337,  1338,     0,  1341,  1342,
    1343,  1344,  1345,  1346,  1347,  1348,  1349,     0,     0,  1352,
    1353,     0,     0,     0,     0,     0,     0,     0,  1367,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   536,   536,     0,   536,
       0,   536,     0,     0,     0,     0,     0,     0,   536,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1434,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,     0,   536,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   536,     0,     0,   536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   536,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   536,     0,
       0,     0,  1466,     0,  1468,     0,  1470,     0,     0,  1474,
       0,     0,     0,     0,  1478,     0,     0,     0,     0,   536,
       0,     0,     0,     0,     0,     0,  1484,   536,     0,     0,
       0,     0,   536,     0,   536,  1488,   536,     0,     0,     0,
       0,  1492,  1493,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1515,     0,     0,  1516,     0,   536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   536,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   536,     0,     0,   536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1615,     0,     0,     0,  1617,     0,
       0,     0,  1620,     0,  1622,     0,  1623,     0,     0,     0,
       0,     0,  1627,     0,     0,     0,     0,     0,     0,     0,
    1632,     0,     0,     0,     0,     0,     0,     0,  1636,  1638,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1660,  1661,  1662,  1663,     0,  1665,  1666,     0,  1667,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1675,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1714,     0,  1715,
       0,     0,  1717,     0,     0,     0,     0,     0,     0,     0,
    1720,     0,     0,     0,     0,  1722,  1638,     0,     0,     0,
       0,     0,     0,  1726,     0,     0,     0,     0,  1731,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1743,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1749,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1768,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1726,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1808,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -165,   886,     0,
       0,  1819,     0,     0,     0,     0,  1824,     0,     1,     2,
       0,  1808,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,  1824,    12,     0,     0,
    1833,    13,   415,     0,    15,    16,    17,    18,    19,    20,
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
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
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
    -165,   886,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,    11,     0,
      12,     0,     0,     0,   890,   415,     0,    15,    16,    17,
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
     243,   244,   245,   886,   246,     0,   247,   248,   249,   250,
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
     241,   242,   243,   244,   245,   886,   246,     0,   247,   248,
     249,   250,   251,   252,   253,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,     0,     0,     0,    12,     0,     0,     0,   414,   415,
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   561,   416,    29,    30,    31,    32,    33,
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,     0,    47,    48,    49,   562,   563,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
      71,    72,    73,    74,    75,     0,    76,    77,    78,     0,
       0,    79,    80,     0,     0,     0,    81,    82,   510,    84,
      85,    86,    87,    88,   564,    90,    91,     0,     0,     0,
      92,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,    98,    99,   100,   101,   102,     0,     0,     0,     0,
       0,     0,   103,   104,   105,   106,   107,   108,   109,   565,
     111,     0,   112,   113,   114,   115,   116,     0,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   124,     0,
     125,     0,   126,   127,     0,     0,   128,   129,   130,     0,
       0,     0,   131,     0,   132,   133,     0,   134,   135,     0,
     136,     0,   137,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,     0,     0,   149,   150,   151,
       0,   417,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   528,   529,   530,   178,   179,   531,
     567,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,     0,   246,     0,
     247,   248,   249,   250,   251,   252,   253,  -863,   457,     0,
     458,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -863,     0,     0,     0,  -863,     0,     0,     0,  -863,  -863,
       0,     0,     0,     0,  -863,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   459,     0,     0,  -863,     0,
     460,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -863,     0,  -863,  -863,  -863,     0,     0,  -863,  -863,
    -863,  -863,     0,     0,     0,  -863,  -863,     0,     0,     0,
       0,     0,  -863,     0,     0,  -863,  -863,   461,     0,     0,
    -863,     0,     0,     0,     0,  -863,  -863,     0,     0,     0,
       0,  -863,     0,     0,     0,  -863,     0,     0,     0,  -863,
    -863,     0,  -863,     0,  -863,  -863,     0,     0,     0,  -863,
    -863,     0,     0,  -863,  -863,  -863,  -863,  -863,  -863,     0,
       0,  -863,     0,     0,     0,     0,  -863,  -863,     0,     0,
    -863,     0,     0,     0,     0,  -863,     0,     0,  -863,     0,
       0,     0,     0,  -863,  -863,  -863,  -863,  -863,     0,  -863,
    -863,  -863,  -863,  -863,     0,     0,     0,     0,  -863,  -863,
    -863,     0,  -863,  -863,  -863,  -863,  -863,  -863,     0,  -863,
       0,  -863,     0,     0,     0,     0,  -863,  -863,  -863,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -863,     0,  -863,     0,  -863,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -863,     0,
       0,     0,     0,  -863,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
    -863,     0,  -863,    13,    14,     0,    15,    16,    17,    18,
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
     115,   116,     0,     0,     0,     0,   117,   118,   119,   120,
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
     252,   253,   254,   255,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    12,     0,     0,     0,    13,    14,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,     0,
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
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,   246,     0,   247,
     248,   249,   250,   251,   252,   253,     0,   615,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,     0,     0,
       0,   414,   415,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,   416,    29,    30,
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
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,   126,   127,     0,     0,   128,
     129,   130,     0,   556,     0,   131,     0,   132,   133,     0,
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
       0,     0,     0,   414,   415,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   416,
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
     115,   116,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,   819,     0,   131,     0,   132,
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
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    12,     0,     0,     0,   414,   415,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    1354,   416,    29,    30,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,    47,    48,    49,  1355,  1356,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,     0,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,    92,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,    98,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
     113,   114,   115,   116,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,   126,
     127,     0,     0,   128,   129,   130,     0,   556,     0,   131,
       0,   132,   133,     0,   134,   135,     0,   136,     0,   137,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,   149,   150,   151,     0,   417,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,  1357,   182,   183,
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
     240,   241,   242,   243,   244,   245,     0,   246,     0,   247,
     248,   249,   250,   251,   252,   253,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    12,     0,     0,     0,    13,
      14,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
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
     151,     0,   152,   153,   154,   155,   156,   157,   158,   159,
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
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
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
     115,   116,     0,     0,     0,     0,   117,   118,   119,   120,
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
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    12,     0,     0,     0,   890,   415,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   416,    29,    30,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,     0,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     0,     0,     0,    92,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,    98,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,   112,
     113,   114,   115,   116,     0,     0,     0,     0,   117,   118,
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
     242,   243,   244,   245,     0,   246,     0,   247,   248,   249,
     250,   251,   252,   253,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
       0,     0,     0,    12,     0,     0,     0,   414,   415,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   561,   416,    29,    30,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,    47,    48,    49,   562,   563,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,     0,     0,
      79,    80,     0,     0,     0,    81,    82,   510,    84,    85,
      86,    87,    88,   564,    90,    91,     0,     0,     0,    92,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
      98,    99,   100,   101,   102,     0,     0,     0,     0,   941,
       0,   103,   104,   105,   106,   107,   108,   109,   565,   111,
       0,   112,   113,   114,   115,   116,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,     0,
       0,   131,   942,   132,   133,     0,   134,   135,     0,   136,
       0,   137,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,   151,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   528,   529,   530,   178,   179,   531,   567,
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
      23,    24,    25,    26,   561,   416,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,    47,    48,    49,   562,
     563,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    81,    82,   510,
      84,    85,    86,    87,    88,   564,    90,    91,     0,     0,
       0,    92,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,    98,    99,   100,   101,   102,     0,     0,     0,
       0,   941,     0,   103,   104,   105,   106,   107,   108,   109,
     565,   111,     0,   112,   113,   114,   115,   116,     0,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,   126,   127,     0,     0,   128,   129,   130,
       0,     0,     0,   131,   946,   132,   133,     0,   134,   135,
       0,   136,     0,   137,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,     0,   149,   150,
     151,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   528,   529,   530,   178,   179,
     531,   567,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,   246,
       0,   247,   248,   249,   250,   251,   252,   253,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,    11,     0,    12,     0,     0,
       0,   414,   415,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,  1354,   416,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    47,    48,
      49,  1355,  1356,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,     0,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,     0,    92,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,   126,   127,     0,     0,   128,
     129,   130,     0,     0,     0,   131,     0,   132,   133,     0,
     134,   135,     0,   136,     0,   137,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,     0,
     149,   150,   151,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,  1357,   182,   183,   184,   185,   186,   187,
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
      19,    20,    21,    22,    23,    24,    25,    26,   561,   416,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
      47,    48,    49,   562,   563,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,    75,
       0,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,    81,    82,   510,    84,    85,    86,    87,    88,   564,
      90,    91,     0,     0,     0,    92,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,    98,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   565,   111,     0,   112,   113,   114,
     115,   116,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,   566,   131,     0,   132,
     133,     0,   134,   135,     0,   136,     0,   137,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,   149,   150,   151,     0,   417,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   528,
     529,   530,   178,   179,   531,   567,   182,   183,   184,   185,
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
     561,   416,    29,    30,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,     0,    47,    48,    49,   562,   563,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,     0,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,    81,    82,   510,    84,    85,    86,    87,
      88,   564,    90,    91,     0,     0,     0,    92,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,    98,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   565,   111,     0,   112,
     113,   114,   115,   116,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,   126,
     127,     0,     0,   128,   129,   130,     0,     0,     0,   131,
     571,   132,   133,     0,   134,   135,     0,   136,     0,   137,
       0,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,     0,     0,   149,   150,   151,     0,   417,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   528,   529,   530,   178,   179,   531,   567,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,     0,   246,     0,   247,   248,   249,
     250,   251,   252,   253,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
       0,     0,     0,    12,     0,     0,     0,   414,   415,     0,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   561,   416,    29,    30,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,    47,    48,    49,   562,   563,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,     0,     0,
      79,    80,     0,     0,     0,    81,    82,   510,    84,    85,
      86,    87,    88,   564,    90,    91,     0,     0,     0,    92,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   565,   111,
       0,   112,   113,   114,   115,   116,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,     0,
       0,   131,     0,   132,   133,     0,   134,   135,     0,   136,
       0,   137,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,   151,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   528,   529,   530,   178,   179,   531,   567,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   610,   246,     0,   247,
     248,   249,   250,   251,   252,   253,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,     0,     0,     0,    12,     0,     0,     0,   414,
     415,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,   561,   416,    29,    30,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,     0,    47,    48,    49,   562,
     563,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    81,    82,   510,
      84,    85,    86,    87,    88,   564,    90,    91,     0,     0,
       0,    92,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     565,   111,     0,   112,   113,   114,   115,   116,     0,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,   126,   127,     0,     0,   128,   129,   130,
       0,     0,     0,   131,     0,   132,   133,     0,   134,   135,
       0,   136,     0,   137,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,     0,   149,   150,
     151,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   528,   529,   530,   178,   179,
     531,   567,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,   246,
     612,   247,   248,   249,   250,   251,   252,   253,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,    12,     0,     0,
       0,   414,   415,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   561,   416,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    47,    48,
      49,   562,   563,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,     0,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,    81,
      82,   510,    84,    85,    86,    87,    88,   564,    90,    91,
       0,     0,     0,    92,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,    98,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   565,   111,     0,   112,   113,   114,   115,   116,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,   126,   127,     0,     0,   128,
     129,   130,     0,   935,     0,   131,     0,   132,   133,     0,
     134,   135,     0,   136,     0,   137,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,     0,
     149,   150,   151,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   528,   529,   530,
     178,   179,   531,   567,   182,   183,   184,   185,   186,   187,
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
      19,    20,    21,    22,    23,    24,    25,    26,   561,   416,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
      47,    48,    49,   562,   563,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,    75,
       0,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,    81,    82,   510,    84,    85,    86,    87,    88,   564,
      90,    91,     0,     0,     0,    92,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,    98,    99,   100,   101,
     102,     0,     0,     0,     0,  1433,     0,   103,   104,   105,
     106,   107,   108,   109,   565,   111,     0,   112,   113,   114,
     115,   116,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,   134,   135,     0,   136,     0,   137,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,   149,   150,   151,     0,   417,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   528,
     529,   530,   178,   179,   531,   567,   182,   183,   184,   185,
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
      17,    18,    19,    20,    21,    22,    23,    24,   496,    26,
     498,   416,    29,   499,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     501,     0,    47,    48,    49,   503,   504,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,     0,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,    81,    82,   510,    84,    85,    86,    87,
      88,   564,    90,    91,     0,     0,     0,    92,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,   513,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   565,   111,     0,   112,
     113,   691,   115,   116,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,   692,
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
      25,    26,   561,   416,    29,    30,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,     0,    47,    48,    49,   562,   563,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,     0,     0,
      79,    80,     0,     0,     0,    81,    82,   510,    84,    85,
      86,    87,    88,   564,    90,    91,     0,     0,     0,    92,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
      98,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   565,   111,
       0,   112,   113,   114,   115,   116,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,   126,   127,     0,     0,   128,   129,   130,     0,     0,
       0,   131,     0,   132,   133,     0,   134,   135,     0,   136,
       0,   137,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,   151,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   528,   529,   530,   178,   179,   531,   567,
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
      23,    24,   496,    26,   498,   416,    29,   499,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,   501,     0,    47,    48,    49,   503,
     504,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    81,    82,   510,
      84,    85,    86,    87,    88,   564,    90,    91,     0,     0,
       0,    92,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,   513,    99,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,   107,   108,   109,
     565,   111,     0,   112,   113,   114,   115,   116,     0,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,   126,   127,     0,     0,   128,   129,   130,
       0,     0,     0,   131,     0,   132,   133,     0,   134,   135,
       0,   136,     0,   137,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,     0,   149,   150,
     151,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   523,   162,   524,   164,   525,   526,   167,   168,   169,
     170,   171,   172,   527,   174,   528,   529,   530,   178,   179,
     531,   532,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,     0,   246,
       0,   247,   533,   249,   250,   251,   252,   253,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,     0,     0,     0,    12,     0,     0,
       0,   414,   415,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   496,    26,   498,   416,    29,   499,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,   501,     0,    47,    48,
      49,   503,   504,    52,   505,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,    71,    72,    73,    74,    75,     0,    76,
      77,    78,     0,     0,    79,    80,     0,     0,     0,    81,
      82,   510,    84,    85,    86,    87,    88,   564,    90,    91,
       0,     0,     0,    92,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,   513,    99,   100,   101,   102,     0,
       0,     0,     0,     0,     0,   103,   104,   105,   106,   107,
     108,   109,   565,   111,     0,   112,   113,     0,   115,   116,
       0,     0,     0,     0,   117,   118,   119,   120,   121,   122,
     123,   124,     0,   125,     0,     0,     0,     0,     0,   128,
     129,   130,     0,     0,     0,   131,     0,   132,   133,     0,
     134,   135,     0,   136,     0,   137,     0,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,     0,     0,
     149,   150,   151,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   523,   162,   524,   164,   525,   526,   167,
     168,   169,   170,   171,   172,   527,   174,   528,   529,   530,
     178,   179,   531,   532,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
       0,   246,     0,   247,   533,   249,   250,   251,   252,   253,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    12,
       0,     0,     0,   414,   415,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   496,    26,   498,   416,
      29,   499,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,   501,     0,
      47,    48,    49,   503,   504,    52,   505,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,    75,
       0,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,    81,    82,   510,    84,    85,    86,    87,    88,   564,
      90,    91,     0,     0,     0,    92,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,   513,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   565,   111,     0,   112,   113,     0,
     115,   116,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,     0,     0,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,     0,     0,     0,   136,     0,   137,     0,   138,
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
      17,    18,    19,    20,    21,    22,    23,    24,   496,    26,
     498,   416,    29,   499,    31,    32,    33,     0,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
     501,     0,    47,    48,    49,   503,   504,    52,   505,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,    71,    72,    73,
      74,    75,     0,    76,    77,    78,     0,     0,    79,    80,
       0,     0,     0,    81,    82,   510,    84,    85,    86,    87,
      88,   564,    90,    91,     0,     0,     0,    92,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,   513,     0,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,     0,   108,   109,   565,   111,     0,   112,
     113,     0,   115,   116,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,     0,
       0,     0,     0,   128,   129,   130,     0,     0,     0,   131,
       0,   132,   133,     0,     0,     0,     0,   136,     0,   137,
       0,   138,     0,   140,     0,   142,   143,   144,   145,   146,
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
       0,     0,     0,     3,     0,     0,     0,     0,     8,     9,
       0,     0,     0,     0,     0,     0,     0,   414,   415,     0,
      15,    16,    17,   493,    19,    20,    21,   494,    23,   495,
     496,   497,   498,   416,    29,   499,    31,    32,    33,     0,
      34,    35,    36,    37,   500,    39,    40,    41,    42,    43,
      44,    45,   501,     0,    47,   502,    49,   503,   504,    52,
     505,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   506,   507,    70,     0,    71,
      72,    73,   508,     0,     0,    76,    77,    78,     0,     0,
     509,    80,     0,     0,     0,     0,    82,   510,    84,   511,
     512,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
     513,    99,   100,   514,   515,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     0,   107,   108,   109,     0,     0,
       0,     0,     0,     0,   115,   516,     0,     0,     0,     0,
     117,   118,   119,   120,   517,   122,   123,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,     0,   132,   521,     0,     0,     0,     0,   136,
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
     240,   241,   242,   243,   244,     0,     0,     1,     2,   247,
     533,   249,   250,   251,   252,   253,     3,     0,     0,     0,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
     414,   415,     0,    15,    16,    17,   542,    19,    20,    21,
     494,   543,   544,   496,   497,   498,   416,    29,   499,    31,
     545,    33,     0,    34,    35,    36,    37,   546,    39,   547,
     548,    42,    43,    44,    45,   501,     0,    47,   549,    49,
     503,   504,    52,   505,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   506,   507,
      70,     0,    71,    72,    73,   550,     0,     0,    76,    77,
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
     159,   160,   523,   551,   524,   164,   525,   526,   167,   168,
     169,   170,   171,   172,   527,   174,   528,   529,   530,   178,
     179,   531,   532,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,     0,
     577,     0,   247,   533,   249,   250,   251,   252,   253,     8,
       9,     0,     0,     0,   794,     0,     0,     0,   414,   415,
       0,    15,    16,    17,   542,    19,    20,    21,   494,   543,
     544,   496,   497,   498,   416,    29,   499,    31,   545,    33,
       0,    34,    35,    36,    37,   546,    39,   547,   548,    42,
      43,    44,    45,   501,     0,    47,   549,    49,   503,   504,
      52,   505,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,   506,   507,    70,     0,
      71,    72,    73,   550,     0,     0,    76,    77,    78,     0,
       0,   509,    80,     0,     0,     0,     0,    82,   510,    84,
     511,   512,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,   513,    99,   100,   514,   515,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,   107,   108,   109,     0,
       0,     0,     0,     0,     0,   115,   516,     0,     0,     0,
       0,   117,   118,   119,   120,   517,   122,   123,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   130,     0,
       0,     0,   131,   795,   132,   521,     0,     0,     0,     0,
       0,     0,   137,     0,   138,   139,   140,   141,   522,   143,
     144,   145,   146,   147,   148,     0,     0,   149,   150,     0,
       0,   417,   153,   154,   155,   156,   157,   158,   159,   160,
     523,   551,   524,   164,   525,   526,   167,   168,   169,   170,
     171,   172,   527,   174,   528,   529,   530,   178,   179,   531,
     532,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,     0,   195,   196,   197,     0,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,     0,     0,   577,     0,
     247,   533,   249,   250,   251,   252,   253,     8,     9,     0,
       0,     0,     0,     0,     0,     0,   414,   415,     0,    15,
      16,    17,   542,    19,    20,    21,   494,   543,   544,   496,
     497,   498,   416,    29,   499,    31,   545,    33,     0,    34,
      35,    36,    37,   546,    39,   547,   548,    42,    43,    44,
      45,   501,     0,    47,   549,    49,   503,   504,    52,   505,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,   506,   507,    70,     0,    71,    72,
      73,   550,     0,     0,    76,    77,    78,     0,     0,   509,
      80,     0,     0,     0,     0,    82,   510,    84,   511,   512,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,   513,
      99,   100,   514,   515,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,   107,   108,   109,     0,     0,     0,
       0,     0,     0,   115,   516,     0,     0,     0,     0,   117,
     118,   119,   120,   517,   122,   123,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   130,     0,     0,     0,
     131,     0,   132,   521,     0,     0,     0,     0,     0,     0,
     137,     0,   138,   139,   140,   141,   522,   143,   144,   145,
     146,   147,   148,     0,     0,   149,   150,     0,     0,   417,
     153,   154,   155,   156,   157,   158,   159,   160,   523,   551,
     524,   164,   525,   526,   167,   168,   169,   170,   171,   172,
     527,   174,   528,   529,   530,   178,   179,   531,   532,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,     0,     0,     0,   247,   533,
     249,   250,   251,   252,   253,   580,   581,     0,     0,     0,
       0,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,   414,   415,     0,    15,    16,    17,   542,    19,    20,
      21,   494,   543,   544,   496,   497,   498,   416,    29,   499,
      31,   545,    33,     0,    34,    35,    36,    37,   546,    39,
     547,   548,    42,    43,    44,    45,   501,     0,    47,   549,
      49,   503,   504,    52,   505,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   506,
     507,    70,     0,    71,    72,    73,   550,     0,     0,    76,
      77,    78,     0,     0,   509,    80,     0,     0,     0,     0,
      82,   510,    84,   511,   512,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,   513,    99,   100,   514,   515,     0,
       0,     0,     0,     0,     0,   103,   104,   105,     0,   107,
     108,   109,     0,     0,     0,     0,     0,     0,   115,   516,
       0,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,     0,     0,   137,     0,   138,   139,   140,
     141,   522,   143,   144,   145,   146,   147,   148,     0,     0,
     149,   150,     0,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   523,   551,   524,   164,   525,   526,   167,
     168,   169,   170,   171,   172,   527,   174,   528,   529,   530,
     178,   179,   531,   532,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
       0,     0,     0,   247,   533,   249,   250,   251,   252,   253,
       4,     5,     6,     7,     8,     9,     0,     0,     0,    12,
       0,     0,     0,   414,   415,     0,    15,    16,    17,   845,
      19,    20,    21,    22,   543,   846,   496,    26,   498,   416,
      29,   499,    31,   545,    33,     0,    34,    35,    36,    37,
     847,    39,   547,   548,    42,    43,    44,    45,   501,     0,
      47,   848,    49,   503,   504,    52,   505,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   506,   507,    70,     0,    71,    72,    73,   849,     0,
       0,    76,    77,    78,     0,     0,   509,    80,     0,     0,
       0,    81,    82,   510,    84,   511,   512,    87,    88,   564,
      90,     0,     0,     0,     0,    92,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,   513,    99,   100,   514,
     515,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   565,   111,     0,   112,   113,     0,
     115,   116,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   518,     0,   125,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,     0,   132,
     521,     0,     0,     0,     0,     0,     0,   137,     0,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
       0,     0,   149,   150,   151,     0,   417,   153,   154,   155,
     156,   157,   158,   159,   160,   523,   551,   524,   164,   525,
     526,   167,   168,   169,   170,   171,   172,   527,   174,   528,
     529,   530,   178,   179,   531,   532,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,     0,   246,     0,   247,   533,   249,   250,   251,
     252,   253,     8,     9,     0,     0,     0,     0,     0,     0,
       0,   414,   415,     0,    15,    16,    17,   493,    19,    20,
      21,   494,    23,   495,   496,  1150,   498,   416,    29,   499,
      31,    32,    33,     0,    34,    35,    36,    37,   500,    39,
      40,    41,    42,    43,    44,    45,   501,     0,    47,   502,
      49,   503,   504,    52,   505,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   506,
     507,    70,     0,    71,    72,    73,   508,     0,     0,    76,
      77,    78,     0,     0,   509,    80,     0,     0,     0,     0,
      82,   510,    84,   511,   512,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,   513,    99,   100,   514,   515,     0,
       0,     0,     0,     0,     0,   103,   104,   105,     0,   107,
     108,  1151,     0,     0,     0,  1152,     0,     0,   115,   516,
       0,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,  1586,   132,   521,     0,
       0,     0,     0,  1587,     0,   137,     0,   138,   139,   140,
     141,   522,   143,   144,   145,   146,   147,   148,     0,     0,
    1153,   150,     0,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   523,   162,   524,   164,   525,   526,   167,
     168,   169,   170,   171,   172,   527,   174,   528,   529,   530,
     178,   179,   531,   532,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
       0,     8,     9,   247,   533,   249,  1154,  1155,  1156,  1157,
     414,   415,     0,    15,    16,    17,   542,    19,    20,    21,
     494,   543,   544,   496,   497,   498,   416,    29,   499,    31,
     545,    33,     0,    34,    35,    36,    37,   546,    39,   547,
     548,    42,    43,    44,    45,   501,     0,    47,   549,    49,
     503,   504,    52,   505,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   506,   507,
      70,     0,    71,    72,    73,   550,     0,     0,    76,    77,
      78,     0,     0,   509,    80,     0,     0,     0,     0,    82,
     510,    84,   511,   512,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,     0,    97,
       0,     0,     0,   513,    99,   100,   514,   515,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,   107,   108,
     109,     0,     0,     0,     0,     0,     0,   115,   516,     0,
       0,     0,     0,   117,   118,   119,   120,   517,   122,   123,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     130,     0,     0,     0,   131,   763,   132,   521,     0,     0,
       0,     0,   764,     0,   137,     0,   138,   139,   140,   141,
     522,   143,   144,   145,   146,   147,   148,     0,     0,   149,
     150,     0,     0,   417,   153,   154,   155,   156,   157,   158,
     159,   160,   523,   551,   524,   164,   525,   526,   167,   168,
     169,   170,   171,   172,   527,   174,   528,   529,   530,   178,
     179,   531,   532,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,     0,
       8,     9,   247,   533,   249,   250,   251,   252,   253,   414,
     415,     0,    15,    16,    17,   542,    19,    20,    21,   494,
     543,   544,   496,   497,   498,   416,    29,   499,    31,   545,
      33,     0,    34,    35,    36,    37,   546,    39,   547,   548,
      42,    43,    44,    45,   501,     0,    47,   549,    49,   503,
     504,    52,   505,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   506,   507,    70,
       0,    71,    72,    73,   550,     0,     0,    76,    77,    78,
       0,     0,   509,    80,     0,     0,     0,     0,    82,   510,
      84,   511,   512,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,   513,    99,   100,   514,   515,     0,     0,     0,
       0,     0,     0,   103,   104,   105,     0,   107,   108,   109,
       0,     0,     0,     0,     0,     0,   115,   516,     0,     0,
       0,     0,   117,   118,   119,   120,   517,   122,   123,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   130,
       0,     0,     0,   131,   812,   132,   521,     0,     0,     0,
       0,   813,     0,   137,     0,   138,   139,   140,   141,   522,
     143,   144,   145,   146,   147,   148,     0,     0,   149,   150,
       0,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   523,   551,   524,   164,   525,   526,   167,   168,   169,
     170,   171,   172,   527,   174,   528,   529,   530,   178,   179,
     531,   532,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,     0,     8,
       9,   247,   533,   249,   250,   251,   252,   253,   414,   415,
       0,    15,    16,    17,   493,    19,    20,    21,   494,    23,
     495,   496,  1150,   498,   416,    29,   499,    31,    32,    33,
       0,    34,    35,    36,    37,   500,    39,    40,    41,    42,
      43,    44,    45,   501,     0,    47,   502,    49,   503,   504,
      52,   505,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,   506,   507,    70,     0,
      71,    72,    73,   508,     0,     0,    76,    77,    78,     0,
       0,   509,    80,     0,     0,     0,     0,    82,   510,    84,
     511,   512,    87,    88,  1502,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,   513,    99,   100,   514,   515,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,   107,   108,  1151,     0,
       0,     0,  1152,     0,     0,   115,   516,     0,     0,     0,
       0,   117,   118,   119,   120,   517,   122,   123,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   130,     0,
       0,     0,   131,     0,   132,   521,     0,     0,     0,     0,
       0,     0,   137,     0,   138,   139,   140,   141,   522,   143,
     144,   145,   146,   147,   148,     0,     0,  1153,   150,     0,
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
     247,   533,   249,  1154,  1155,  1156,  1157,   414,   415,     0,
      15,    16,    17,   493,    19,    20,    21,   494,    23,   495,
     496,  1150,   498,   416,    29,   499,    31,    32,    33,     0,
      34,    35,    36,    37,   500,    39,    40,    41,    42,    43,
      44,    45,   501,     0,    47,   502,    49,   503,   504,    52,
     505,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   506,   507,    70,     0,    71,
      72,    73,   508,     0,     0,    76,    77,    78,     0,     0,
     509,    80,     0,     0,     0,     0,    82,   510,    84,   511,
     512,    87,    88,  1644,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
     513,    99,   100,   514,   515,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     0,   107,   108,  1151,     0,     0,
       0,  1152,     0,     0,   115,   516,     0,     0,     0,     0,
     117,   118,   119,   120,   517,   122,   123,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,     0,   132,   521,     0,     0,     0,     0,     0,
       0,   137,     0,   138,   139,   140,   141,   522,   143,   144,
     145,   146,   147,   148,     0,     0,  1153,   150,     0,     0,
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
     533,   249,  1154,  1155,  1156,  1157,   414,   415,     0,    15,
      16,    17,   493,    19,    20,    21,   494,    23,   495,   496,
    1150,   498,   416,    29,   499,    31,    32,    33,     0,    34,
      35,    36,    37,   500,    39,    40,    41,    42,    43,    44,
      45,   501,     0,    47,   502,    49,   503,   504,    52,   505,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,   506,   507,    70,     0,    71,    72,
      73,   508,     0,     0,    76,    77,    78,     0,     0,   509,
      80,     0,     0,     0,     0,    82,   510,    84,   511,   512,
      87,    88,  1648,     0,     0,     0,     0,     0,     0,     0,
      93,    94,    95,    96,     0,    97,     0,     0,     0,   513,
      99,   100,   514,   515,     0,     0,     0,     0,     0,     0,
     103,   104,   105,     0,   107,   108,  1151,     0,     0,     0,
    1152,     0,     0,   115,   516,     0,     0,     0,     0,   117,
     118,   119,   120,   517,   122,   123,   518,     0,     0,     0,
       0,     0,     0,     0,   519,   520,   130,     0,     0,     0,
     131,     0,   132,   521,     0,     0,     0,     0,     0,     0,
     137,     0,   138,   139,   140,   141,   522,   143,   144,   145,
     146,   147,   148,     0,     0,  1153,   150,     0,     0,   417,
     153,   154,   155,   156,   157,   158,   159,   160,   523,   162,
     524,   164,   525,   526,   167,   168,   169,   170,   171,   172,
     527,   174,   528,   529,   530,   178,   179,   531,   532,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,     0,   195,   196,   197,     0,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,     0,     0,     8,     9,   247,   533,
     249,  1154,  1155,  1156,  1157,   414,   415,     0,    15,    16,
      17,   493,    19,    20,    21,   494,    23,   495,   496,  1150,
     498,   416,    29,   499,    31,    32,    33,     0,    34,    35,
      36,    37,   500,    39,    40,    41,    42,    43,    44,    45,
     501,     0,    47,   502,    49,   503,   504,    52,   505,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,   506,   507,    70,     0,    71,    72,    73,
     508,     0,     0,    76,    77,    78,     0,     0,   509,    80,
       0,     0,     0,     0,    82,   510,    84,   511,   512,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,   513,    99,
     100,   514,   515,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,   107,   108,  1151,     0,     0,     0,  1152,
       0,     0,   115,   516,     0,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
       0,   132,   521,     0,     0,     0,     0,     0,     0,   137,
       0,   138,   139,   140,   141,   522,   143,   144,   145,   146,
     147,   148,     0,     0,  1153,   150,     0,     0,   417,   153,
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
    1154,  1155,  1156,  1157,   414,   415,     0,    15,    16,    17,
     493,    19,    20,    21,   494,    23,   495,   496,  1150,   498,
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
     105,     0,   107,   108,  1151,     0,     0,     0,  1152,     0,
       0,   115,   516,     0,     0,     0,     0,   117,   118,   119,
     120,   517,   122,   123,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   130,     0,     0,     0,   131,     0,
     132,   521,     0,     0,     0,     0,     0,     0,   137,     0,
     138,   139,   140,   141,   522,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,     0,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   523,   162,   524,   164,
     525,   526,   167,   168,   169,   170,   171,   172,   527,   174,
     528,   529,   530,   178,   179,   531,   532,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,     0,     8,     9,   247,   533,   249,  1154,
    1155,  1156,  1157,   414,   415,     0,    15,    16,    17,   542,
      19,    20,    21,   494,   543,   544,   496,   497,   498,   416,
      29,   499,    31,   545,    33,     0,    34,    35,    36,    37,
     546,    39,   547,   548,    42,    43,    44,    45,   501,     0,
      47,   549,    49,   503,   504,    52,   505,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   506,   507,    70,     0,    71,    72,    73,   550,     0,
       0,    76,    77,    78,     0,     0,   509,    80,     0,     0,
       0,     0,    82,   510,    84,   511,   512,    87,    88,  1245,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,   513,    99,   100,   514,
     515,     0,     0,     0,     0,     0,     0,   103,   104,   105,
       0,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     115,   516,     0,     0,     0,     0,   117,   118,   119,   120,
     517,   122,   123,   518,     0,     0,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,     0,   132,
     521,     0,     0,     0,     0,     0,     0,   137,     0,   138,
     139,   140,   141,   522,   143,   144,   145,   146,   147,   148,
       0,     0,   149,   150,     0,     0,   417,   153,   154,   155,
     156,   157,   158,   159,   160,   523,   551,   524,   164,   525,
     526,   167,   168,   169,   170,   171,   172,   527,   174,   528,
     529,   530,   178,   179,   531,   532,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,     0,
     195,   196,   197,     0,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,     0,     0,     8,     9,   247,   533,   249,   250,   251,
     252,   253,   414,   415,     0,    15,    16,    17,   542,    19,
      20,    21,   494,   543,   544,   496,   497,   498,   416,    29,
     499,    31,   545,    33,     0,    34,    35,    36,    37,   546,
      39,   547,   548,    42,    43,    44,    45,   501,     0,    47,
     549,    49,   503,   504,    52,   505,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
     506,   507,    70,     0,    71,    72,    73,   550,     0,     0,
      76,    77,    78,     0,     0,   509,    80,     0,     0,     0,
       0,    82,   510,    84,   511,   512,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,    93,    94,    95,    96,
       0,    97,     0,     0,     0,   513,    99,   100,   514,   515,
       0,     0,     0,     0,     0,     0,   103,   104,   105,     0,
     107,   108,   109,     0,     0,     0,     0,     0,     0,   115,
     516,     0,     0,     0,     0,   117,   118,   119,   120,   517,
     122,   123,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   130,     0,     0,     0,   131,     0,   132,   521,
       0,     0,     0,     0,     0,     0,   137,     0,   138,   139,
     140,   141,   522,   143,   144,   145,   146,   147,   148,     0,
       0,   149,   150,     0,     0,   417,   153,   154,   155,   156,
     157,   158,   159,   160,   523,   551,   524,   164,   525,   526,
     167,   168,   169,   170,   171,   172,   527,   174,   528,   529,
     530,   178,   179,   531,   532,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     0,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
       0,     0,     8,     9,   247,   533,   249,   250,   251,   252,
     253,   414,   415,     0,    15,    16,    17,     0,    19,    20,
      21,   494,     0,     0,   496,   497,     0,   416,    29,   499,
      31,     0,    33,     0,    34,    35,    36,    37,     0,    39,
       0,     0,    42,    43,    44,    45,   501,     0,    47,     0,
      49,     0,     0,    52,   505,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   506,
     507,    70,     0,    71,    72,    73,     0,     0,     0,    76,
      77,    78,     0,     0,   509,    80,     0,     0,     0,     0,
      82,   510,    84,   511,   512,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,   513,    99,   100,   514,   515,     0,
       0,     0,     0,     0,     0,   103,   104,   105,     0,   107,
     108,     0,     0,     0,     0,     0,     0,     0,   115,   516,
       0,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,     0,     0,   137,     0,   138,   139,   140,
     141,   522,   143,   144,   145,   146,   147,   148,     0,     0,
       0,   150,     0,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   523,     0,   524,   164,   525,   526,   167,
     168,   169,   170,   171,   172,   527,   174,   528,   529,   530,
     178,   179,     0,   532,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
       0,     0,     0,   247,   533,   249,   250,   251,   252,   253
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   181,   425,   426,     4,     5,     6,     7,    13,     4,
       5,     6,   313,   427,   111,   112,   342,   694,   678,   788,
     832,  1046,   768,     0,   261,   917,   135,     4,     5,     6,
       7,   768,   801,   679,   680,   681,   682,   262,  1062,     4,
       5,     6,     7,   871,  1315,   293,   815,  1298,     4,     5,
       6,     7,   277,   467,   468,   593,    75,  1086,   930,   931,
       1,   599,  1136,   930,   931,     1,   628,   629,   254,   255,
     439,  1379,  1380,   953,   626,   627,   628,   629,  1021,    37,
    1003,   450,  1505,   626,   627,  1508,  1328,    57,   120,  1412,
      27,    28,    37,     8,   725,  1608,   120,   969,   109,   284,
      40,    30,     1,     1,     1,    45,    46,   476,   144,     1,
     110,    48,     1,   657,    54,   659,   660,     1,   662,    30,
     664,    61,   227,    63,    64,   123,    27,    28,   672,   673,
     102,  1003,    72,   110,     1,     1,   109,     1,    96,    76,
      98,    53,   109,    95,  1675,   110,   149,    48,   245,   246,
       1,  1023,   109,    98,   110,     1,  1023,    58,   227,    99,
     229,   969,   109,   219,  1036,     1,    46,     1,   109,  1036,
     155,    31,   420,   109,   160,    76,   424,   114,    98,   102,
      81,    98,   271,   112,    64,    98,   149,     9,    10,   278,
     265,   149,   178,   155,   179,   138,   293,   126,     1,   288,
     256,   276,   115,   227,   149,   155,   975,     1,   158,   152,
     109,   316,   113,   114,   115,   201,   188,   179,  1749,   131,
     109,     1,   151,   190,   235,   109,   155,    38,    39,   158,
      41,    42,     1,   185,     1,   192,   345,   235,     1,   275,
    1548,   158,   189,   275,  1136,  1137,  1759,   316,    59,   219,
     179,   162,   120,     1,   254,   255,  1281,     1,   258,     1,
    1029,   446,   177,   109,   237,   188,  1035,  1518,     1,   570,
    1082,  1295,   275,   109,    98,   109,     1,   254,   255,  1521,
    1152,   258,  1028,   105,  1607,   309,   256,   227,   187,  1026,
    1319,  1028,   109,   293,   192,   192,     9,    10,   187,  1328,
     192,  1724,  1245,   125,   115,   127,   109,    75,  1188,   189,
     558,  1048,   275,  1236,  1388,   109,   293,   275,   880,   881,
     188,    89,   736,   420,   955,   192,   192,   424,   192,   109,
     275,   350,   261,   155,   353,   878,   879,   159,   258,   259,
     109,   192,   109,   189,  1152,   113,   109,   171,  1771,     1,
    1773,   162,   289,   189,   176,   189,   216,   125,   455,   127,
     297,   109,     1,   120,  1236,   109,   158,   109,   465,   913,
       0,     1,   786,   190,   315,   197,   109,   313,   475,   319,
     320,   321,    96,   186,   109,   482,   483,   109,   289,   626,
     627,     1,   105,   215,   491,   189,   297,   645,   623,   624,
    1708,  1273,   132,   109,   305,    78,  1273,   109,   633,   189,
     139,   222,   125,   782,   127,   144,   785,   186,     0,     1,
     420,   160,   189,   109,   424,  1297,   189,   102,     1,   615,
     254,   255,   189,   257,     1,     1,    98,     1,     1,   178,
     264,   189,   155,   420,   186,   189,   159,   424,     9,   138,
     274,   451,   263,   453,  1762,   109,   189,   109,   156,    30,
     158,   558,   286,   176,   189,   155,  1235,   189,    29,   199,
     109,   132,   109,    96,   451,  1746,   453,   574,   575,   109,
     480,   158,   155,   189,   197,   485,   451,   189,   453,   227,
     587,   229,  1521,    96,   917,   451,  1388,   453,   155,   109,
     186,  1247,   215,   480,   109,  1397,   220,   221,   485,   171,
     607,   608,   227,   188,   203,   480,  1408,   232,   102,  1256,
     485,   235,   212,   155,   480,   948,   149,   109,    56,   485,
      58,   115,   271,  1361,   186,   189,   109,  1365,   199,   278,
    1791,   239,   109,   109,   115,   109,   109,   186,  1420,   288,
     223,   224,   189,  1420,  1231,   212,   186,   119,   558,  1121,
    1122,  1123,   976,   977,   125,   565,   127,   981,  1106,  1121,
    1122,  1123,   162,    30,   102,   136,   186,   109,   316,    27,
      28,   558,   350,   133,   189,   353,   148,   124,   565,   698,
     699,   162,   254,   255,   155,   257,    96,  1011,   695,   161,
     565,   316,    43,   700,   186,  1630,    47,   109,   608,   565,
     120,    52,   274,   186,  1383,   615,   621,   220,   221,   186,
     186,   869,   186,   186,   286,   109,   626,   627,   628,   629,
      71,   608,   235,  1505,   196,    30,  1508,    46,   615,    48,
     109,   878,   192,   608,    46,   645,    48,     1,   896,   626,
     627,   628,   629,    98,   265,   112,   156,   189,   158,   884,
     193,   194,    96,   888,   432,   276,   114,   435,   645,   126,
       9,   439,    43,     5,   442,   443,    47,     9,   188,    81,
      34,    52,   450,    98,   270,  1577,    98,   189,   456,   457,
      29,   277,   158,   461,   151,     1,    50,     3,     5,   108,
      71,   469,     9,   115,   149,   189,   108,  1519,   476,   477,
     478,   479,  1524,  1136,  1137,   149,   484,   112,    96,    98,
     189,  1745,   108,  1469,   492,   253,   823,   824,   825,   170,
     827,   126,   173,    96,   149,  1017,   115,  1019,   266,  1399,
     268,    43,   146,   129,   630,    47,   158,   188,   634,   139,
      52,   279,   280,   281,   144,   283,   151,   285,   171,    34,
     155,   170,    68,   158,     9,    10,   144,    73,   170,    71,
     538,  1643,   869,   214,   178,    50,  1643,  1454,   778,   158,
     160,   144,    96,   778,   179,   553,   125,  1069,   127,  1071,
      25,   204,   196,   125,   108,   127,   564,   136,   178,   170,
      35,   778,   173,   135,     1,   158,  1368,  1736,  1737,   809,
     810,   120,  1138,   778,   120,   158,   155,   188,   125,  1691,
     127,  1693,   778,   155,  1691,   593,  1693,    62,   135,    96,
     144,   599,   809,   810,   102,   603,    55,    34,     9,    10,
     160,    60,  1654,   214,   809,   810,  1658,   115,   155,  1778,
     188,    55,  1724,   809,   810,  1784,    60,   158,   178,   188,
     105,   150,  1276,  1111,   124,    55,   188,   188,   170,   869,
      60,   173,   139,   188,   212,    79,   188,   144,   167,    98,
     125,   201,   127,   212,  1756,   890,   188,  1112,   150,  1756,
     212,   212,   869,  1118,    98,   155,   896,   212,   158,  1771,
     212,  1773,   249,   250,   124,   167,    27,    28,  1568,  1569,
     155,    97,   214,   168,   159,  1561,   120,    38,    39,   896,
      41,    42,   108,   124,   139,   272,   139,    48,  1740,   184,
     184,   176,   118,  1610,   105,  1115,   184,    58,    59,  1708,
     155,   158,   155,   129,   198,   102,   102,   683,   684,   102,
     198,    96,   197,   102,   125,    76,   127,   966,   115,   115,
      81,  1375,   115,   108,   732,  1388,   115,   203,   301,   978,
     215,   156,   155,   158,  1397,   158,   212,   310,   746,   223,
     224,   225,   750,   751,   155,  1408,   130,   131,   159,   279,
     280,   281,   113,   114,   115,   285,   701,   155,   349,   704,
     158,   352,   707,   158,   772,   176,   774,   155,   158,   234,
     158,   236,   158,   234,   782,   236,   120,   785,   124,  1679,
    1680,   789,   130,   131,  1229,  1230,   197,  1275,   676,   677,
     685,   686,  1598,  1599,   124,   120,  1713,   124,  1135,   155,
     124,   162,   155,   124,   215,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   124,   124,   124,   155,  1360,
     158,   120,   243,   831,  1064,   243,   218,   244,     0,   158,
     316,    94,  1486,   155,   192,   169,   251,   134,    51,   101,
     202,   195,   103,  1760,   104,   142,   143,  1064,   145,   147,
     156,   186,  1752,   158,   186,   186,   153,    30,   186,  1064,
     157,   222,   159,   871,    48,   154,   120,   164,  1064,   248,
     306,  1111,   189,   286,   286,  1120,   120,   155,     1,   120,
     144,  1121,  1122,  1123,   181,   109,   189,   189,   155,   155,
     158,   144,   900,   158,  1111,   186,   123,    36,  1552,   158,
     158,   158,   263,   158,  1121,  1122,  1123,   158,   205,   206,
     207,   208,   209,   210,  1577,  1832,   158,  1834,    75,   155,
      17,   216,   930,   931,   932,   933,    30,  1844,   289,   233,
       3,   232,    89,   189,   247,   120,   297,  1357,   170,   172,
     192,   172,   192,    72,   305,   233,    96,    96,    96,   151,
     109,   109,    30,   162,   162,   129,   113,   134,   248,    96,
     301,   969,   144,   134,   120,   186,   186,   189,   125,   109,
     127,   189,    96,    98,    46,   983,    98,   189,   189,   189,
     186,   186,   189,    96,   227,   155,   155,   155,   155,   155,
     155,   239,   144,   233,   192,    34,   235,   172,   134,  1239,
    1008,   120,   144,    96,  1239,    30,   288,    96,   301,  1017,
    1498,  1019,   229,  1021,   155,  1023,   149,   129,   120,   256,
     120,    96,  1239,   186,   200,   134,   134,   162,  1036,    98,
     120,   102,   149,   186,  1239,  1275,   102,   155,   144,   186,
     155,   192,   123,  1239,    36,   155,  1286,    30,   247,    81,
     120,  1286,   109,  1541,   109,   269,   260,   287,  1275,   262,
     158,  1069,   158,  1071,   158,  1305,   158,   158,    30,  1286,
    1305,   158,   158,   288,    30,    30,   192,   129,   146,   308,
     120,  1286,   189,   229,   189,  1325,   146,   149,  1305,   289,
    1286,   149,  1332,   149,   189,    79,   120,   109,  1106,   144,
    1305,   189,   186,   102,   189,   134,   189,     7,  1325,  1305,
      98,   239,   192,   108,   235,  1332,   158,   158,   200,   149,
    1325,   235,   158,  1131,  1364,   188,   252,  1332,   155,  1325,
     189,    80,   235,   288,   235,   189,  1332,    30,   189,   284,
    1628,   252,   189,   189,  1152,   189,   189,  1364,    30,   109,
     172,  1639,  1640,   273,  1642,   189,   149,   128,   186,  1364,
     259,   128,  1650,   149,    98,   186,   144,    96,   188,   188,
     188,   186,   186,   186,   318,   186,   155,    30,    98,   189,
     189,   172,    55,   149,    96,   108,    96,    30,   109,   120,
     109,   199,   227,   350,   120,    96,   353,    96,   188,   199,
     267,  1538,  1539,  1540,   200,   282,   120,   188,    95,   185,
     289,   227,   199,   120,   199,   120,   188,   120,   735,   201,
     227,   258,   970,   261,  1191,   258,  1236,   446,  1037,   426,
     295,   307,  1713,   307,  1760,   872,  1034,  1245,   461,   289,
     791,  1249,  1479,   307,  1265,  1733,  1127,   308,  1384,  1382,
    1287,  1379,  1292,   553,  1295,   308,  1264,   656,  1498,   308,
     933,  1300,   709,  1319,   655,  1273,   675,   832,  1784,  1778,
    1019,   454,  1190,   454,   431,   432,  1351,  1362,   435,  1287,
    1361,  1498,   439,  1397,  1772,   442,   443,  1408,  1577,  1297,
    1137,  1401,  1574,   450,  1146,  1002,  1444,  1213,  1601,   456,
     457,  1541,  1790,  1398,   461,   597,   337,    -1,    -1,    -1,
      -1,    -1,   469,    -1,    -1,    -1,    -1,  1805,  1326,   476,
     477,   478,   479,    -1,  1541,    -1,    -1,   484,    -1,    -1,
      -1,    -1,    -1,    -1,  1671,   492,    -1,    -1,  1826,    -1,
      -1,    -1,    -1,  1351,    -1,    -1,    -1,  1835,    -1,    -1,
      -1,    -1,  1689,  1361,    -1,    -1,    -1,  1365,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   538,    -1,    -1,    -1,    -1,    -1,    -1,  1628,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   553,    -1,    -1,  1639,
    1640,    -1,  1642,    -1,    -1,    -1,    -1,   564,    -1,    -1,
    1650,  1628,  1420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1639,  1640,    -1,  1642,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1650,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   110,  1450,    -1,    -1,    -1,   603,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1476,  1477,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1733,  1502,    -1,    -1,  1505,    -1,    -1,
    1508,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1520,    -1,    -1,    -1,  1733,  1525,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1772,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1790,    -1,    -1,    -1,    -1,  1772,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1805,    -1,    -1,    -1,    -1,
      -1,    -1,   729,  1790,    -1,   732,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1826,    -1,  1805,   746,
      -1,    -1,    -1,   750,   751,  1835,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1826,
      -1,    -1,    -1,    -1,    -1,   772,    -1,   774,  1835,    -1,
      -1,    -1,    -1,    -1,    -1,   782,    -1,    -1,   785,    -1,
      -1,    -1,   789,    -1,    -1,  1643,  1644,    -1,  1646,    -1,
    1648,    -1,    -1,    -1,    -1,    -1,    -1,  1655,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   831,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1691,    -1,  1693,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1709,    -1,    -1,  1712,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   871,    -1,  1724,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1735,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   900,    -1,    -1,    -1,    -1,  1756,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1764,    -1,    -1,    -1,
      -1,  1769,    -1,  1771,    -1,  1773,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   930,   931,   932,   933,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1802,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   969,    -1,  1822,    -1,    -1,    -1,    -1,  1827,
      -1,    -1,    -1,    -1,    -1,    -1,   983,    -1,    -1,    -1,
      -1,  1839,    -1,    -1,  1842,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1008,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1017,    -1,  1019,    -1,  1021,    -1,  1023,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1036,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   565,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1069,    -1,  1071,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   591,   592,    -1,    -1,   595,   596,   597,   598,
      -1,   600,    -1,    -1,    -1,    -1,    -1,   606,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   614,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   636,   637,    -1,
      -1,    -1,    -1,    -1,  1131,    -1,   645,   646,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1152,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   706,    -1,    -1,
     709,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   748,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1245,    -1,
      -1,    -1,  1249,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1264,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1273,    -1,    -1,    -1,
      -1,   790,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1297,    -1,    -1,    -1,    -1,    -1,    -1,   816,    -1,    -1,
      -1,   820,   821,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     829,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1326,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1351,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1361,    -1,    -1,    -1,  1365,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   896,    -1,    -1,
      -1,    -1,    -1,   902,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1420,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1450,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   971,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1476,
    1477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1006,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1502,    -1,    -1,  1505,    -1,
      -1,  1508,    -1,    -1,    -1,    -1,  1025,    -1,    -1,    -1,
      -1,    -1,    -1,  1520,    -1,    -1,    -1,    -1,  1525,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1047,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1058,
    1059,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1073,    -1,    -1,  1076,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1093,  1094,  1095,    -1,  1097,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,    -1,    -1,  1108,
    1109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1127,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1643,  1644,    -1,  1646,
      -1,  1648,    -1,    -1,    -1,    -1,    -1,    -1,  1655,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1178,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1691,    -1,  1693,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1709,    -1,    -1,  1712,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1724,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1735,    -1,
      -1,    -1,  1251,    -1,  1253,    -1,  1255,    -1,    -1,  1258,
      -1,    -1,    -1,    -1,  1263,    -1,    -1,    -1,    -1,  1756,
      -1,    -1,    -1,    -1,    -1,    -1,  1275,  1764,    -1,    -1,
      -1,    -1,  1769,    -1,  1771,  1284,  1773,    -1,    -1,    -1,
      -1,  1290,  1291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1309,    -1,    -1,  1312,    -1,  1802,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1822,    -1,    -1,    -1,    -1,
    1827,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1839,    -1,    -1,  1842,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1382,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1463,    -1,    -1,    -1,  1467,    -1,
      -1,    -1,  1471,    -1,  1473,    -1,  1475,    -1,    -1,    -1,
      -1,    -1,  1481,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1497,  1498,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1517,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1529,  1530,  1531,  1532,    -1,  1534,  1535,    -1,  1537,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1553,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1616,    -1,  1618,
      -1,    -1,  1621,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1629,    -1,    -1,    -1,    -1,  1634,  1635,    -1,    -1,    -1,
      -1,    -1,    -1,  1642,    -1,    -1,    -1,    -1,  1647,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1664,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1716,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1729,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1772,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,  1800,    -1,    -1,    -1,    -1,  1805,    -1,    11,    12,
      -1,  1810,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    28,  1825,    30,    -1,    -1,
    1829,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
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
       0,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     310,   311,   312,     1,   314,    -1,   316,   317,   318,   319,
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
     308,   309,   310,   311,   312,     1,   314,    -1,   316,   317,
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
     316,   317,   318,   319,   320,   321,   322,     0,     1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    -1,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,
      73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    94,    -1,    96,    97,    98,    -1,    -1,   101,   102,
     103,   104,    -1,    -1,    -1,   108,   109,    -1,    -1,    -1,
      -1,    -1,   115,    -1,    -1,   118,   119,   120,    -1,    -1,
     123,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
      -1,   134,    -1,    -1,    -1,   138,    -1,    -1,    -1,   142,
     143,    -1,   145,    -1,   147,   148,    -1,    -1,    -1,   152,
     153,    -1,    -1,   156,   157,   158,   159,   160,   161,    -1,
      -1,   164,    -1,    -1,    -1,    -1,   169,   170,    -1,    -1,
     173,    -1,    -1,    -1,    -1,   178,    -1,    -1,   181,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,   190,    -1,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,   201,   202,
     203,    -1,   205,   206,   207,   208,   209,   210,    -1,   212,
      -1,   214,    -1,    -1,    -1,    -1,   219,   220,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   235,    -1,   237,    -1,   239,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,
      -1,    -1,    -1,   256,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
     313,    -1,   315,    34,    35,    -1,    37,    38,    39,    40,
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
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,
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
     321,   322,   323,   324,    11,    12,    -1,    -1,    -1,    -1,
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
     307,   308,   309,   310,   311,   312,    -1,   314,    -1,   316,
     317,   318,   319,   320,   321,   322,    -1,   324,    11,    12,
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
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,
     183,   184,    -1,   186,    -1,   188,    -1,   190,   191,    -1,
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
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,   186,    -1,   188,    -1,   190,
     191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,
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
     321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
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
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,   186,    -1,   188,
      -1,   190,   191,    -1,   193,   194,    -1,   196,    -1,   198,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,
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
     307,   308,   309,   310,   311,   312,    -1,   314,    -1,   316,
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
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
      -1,   316,   317,   318,   319,   320,   321,   322,    11,    12,
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
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,
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
     321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
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
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,   193,   194,    -1,   196,    -1,   198,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,
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
     137,   138,   139,   140,   141,    -1,    -1,    -1,    -1,   146,
      -1,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,   189,   190,   191,    -1,   193,   194,    -1,   196,
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
     317,   318,   319,   320,   321,   322,    11,    12,    -1,    -1,
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
      -1,   146,    -1,   148,   149,   150,   151,   152,   153,   154,
     155,   156,    -1,   158,   159,   160,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,   189,   190,   191,    -1,   193,   194,
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
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
      -1,   316,   317,   318,   319,   320,   321,   322,    11,    12,
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
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,   187,   188,    -1,   190,
     191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,
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
     321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
     189,   190,   191,    -1,   193,   194,    -1,   196,    -1,   198,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,
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
     307,   308,   309,   310,   311,   312,   313,   314,    -1,   316,
     317,   318,   319,   320,   321,   322,    11,    12,    -1,    -1,
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
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,   321,   322,    11,    12,
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
     183,   184,    -1,   186,    -1,   188,    -1,   190,   191,    -1,
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
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,    -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,
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
     321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
     159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,   193,   194,    -1,   196,    -1,   198,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,
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
     307,   308,   309,   310,   311,   312,    -1,   314,    -1,   316,
     317,   318,   319,   320,   321,   322,    11,    12,    -1,    -1,
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
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
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
     153,   154,   155,   156,    -1,   158,   159,    -1,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,   182,
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
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
     151,   152,   153,   154,   155,   156,    -1,   158,   159,    -1,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,
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
     321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
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
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,    -1,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,   151,    -1,   153,   154,   155,   156,    -1,   158,
     159,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
      -1,   200,    -1,   202,    -1,   204,   205,   206,   207,   208,
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
     319,   320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    25,    26,
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
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,   196,
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
     307,   308,   309,   310,   311,    -1,    -1,    11,    12,   316,
     317,   318,   319,   320,   321,   322,    20,    -1,    -1,    -1,
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
      16,    -1,   316,   317,   318,   319,   320,   321,   322,    25,
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
     308,   309,   310,   311,    -1,    -1,    -1,    -1,   316,   317,
     318,   319,   320,   321,   322,    18,    19,    -1,    -1,    -1,
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
      -1,    -1,    -1,   316,   317,   318,   319,   320,   321,   322,
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
     151,   152,   153,   154,   155,   156,    -1,   158,   159,    -1,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,    -1,    -1,    -1,
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
     321,   322,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
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
     153,   154,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,   189,   190,   191,    -1,
      -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,   202,
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
     154,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,
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
      25,    26,   316,   317,   318,   319,   320,   321,   322,    34,
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
     149,   150,    -1,   152,   153,   154,    -1,    -1,    -1,   158,
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
      -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
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
     322,    34,    35,    -1,    37,    38,    39,    -1,    41,    42,
      43,    44,    -1,    -1,    47,    48,    -1,    50,    51,    52,
      53,    -1,    55,    -1,    57,    58,    59,    60,    -1,    62,
      -1,    -1,    65,    66,    67,    68,    69,    -1,    71,    -1,
      73,    -1,    -1,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    -1,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,   131,    -1,
     133,    -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,   148,   149,   150,    -1,   152,
     153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,   214,    -1,    -1,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,    -1,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,    -1,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,    -1,   261,   262,
     263,    -1,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
      -1,    -1,    -1,   316,   317,   318,   319,   320,   321,   322
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
     242,   245,   246,   317,   506,   659,   660,   124,   120,   402,
     124,   124,    40,    45,    46,    54,    61,    63,    64,    72,
      99,   227,   659,   120,   124,   124,   186,   393,   395,   415,
     647,    49,    74,    75,   120,   155,   187,   246,   414,   416,
     426,   189,   414,   659,   155,   155,   124,    16,   658,   659,
      18,    19,   659,   124,   124,   124,   498,   155,    31,   216,
     218,   227,   229,   316,   158,   227,   229,   316,   227,   316,
     227,   232,   316,   120,   243,   243,   244,   158,   155,   397,
     313,   414,   315,   414,   316,   324,   339,   339,     0,   341,
     342,    34,    50,   344,   361,     1,   192,   338,   192,   338,
     114,   376,   396,   414,   109,   192,   109,   338,   192,    43,
      47,    52,    71,   170,   173,   188,   214,   409,   418,   423,
     424,   425,   439,   440,   444,   169,    94,   134,   142,   143,
     145,   153,   157,   159,   164,   181,   205,   206,   207,   208,
     209,   210,   490,   491,   251,   101,   160,   178,   201,   119,
     148,   161,   196,   203,   212,   138,   152,    51,   202,   103,
     104,   160,   178,   488,   195,   155,   495,   498,   193,   194,
     156,   510,   511,   506,   510,   506,   158,   510,   147,   158,
     186,   186,   186,   186,   377,   513,   377,    30,   657,   184,
     198,   184,   198,   168,   184,   660,   659,   171,   204,    48,
     659,   154,   120,    46,    48,    81,   108,   170,   658,   223,
     224,   225,   248,   616,   659,   659,   306,   139,   144,   114,
     289,   297,   379,   658,   394,   189,   394,    46,    64,   189,
     568,   569,   414,   189,   196,   659,   428,   429,   659,   286,
     286,   428,   120,   435,   120,   189,   383,   384,   155,   399,
     414,     1,   162,   657,   115,   162,   357,   657,   659,   120,
     144,   109,   189,   414,    30,   189,   658,   659,   659,   452,
     453,   659,   394,   189,   414,   414,   570,   659,   394,   155,
     155,   414,   189,   196,   659,   659,   144,   452,   186,   186,
     123,   109,   186,   158,   158,   158,   659,   155,   187,   188,
     189,    36,   529,   530,   531,   414,   414,     8,   177,    17,
     414,   216,    30,   415,   415,    40,    46,    61,    72,    99,
     509,   659,   189,   415,   415,   415,   647,   415,   509,   415,
     233,   232,   583,   584,   659,   192,   192,   415,   414,   395,
     414,   247,   412,   413,   313,   315,   415,   339,   192,   338,
     192,   338,     3,   345,   361,   391,     1,   345,   361,   391,
      34,   362,   391,   362,   391,   402,   338,   402,   415,   415,
     120,   170,   172,   172,   396,   415,   415,   470,   471,   473,
     473,   473,   473,   472,   473,   473,   473,    72,   474,   478,
     478,   477,   479,   479,   479,   479,   480,   480,   481,   481,
     233,    96,    96,    96,   496,   186,   414,   498,   498,   414,
     511,   146,   189,   415,   521,   151,   189,   521,   109,   189,
     189,   109,   109,   382,    30,   660,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   364,   365,   366,    96,
     139,   144,   370,   371,   372,   659,   162,   162,   364,   657,
     129,   134,    56,    58,   102,   253,   266,   268,   279,   280,
     281,   283,   285,   617,   618,   619,   620,   621,   622,   629,
     635,   636,   248,    96,   301,   659,   144,   415,   120,   659,
     659,   134,   186,   186,   189,   189,   186,   109,   189,   109,
     189,   109,    37,    96,    98,   149,   430,   431,   552,   659,
      57,   219,   256,   420,   421,   659,    96,   109,   189,   393,
     189,   658,    98,    46,   658,   657,    98,   144,   552,   659,
     415,   434,   186,   189,   189,   189,   189,   109,   190,   149,
     552,   186,   189,   189,   155,   186,   394,   394,   186,   109,
     189,   109,   189,   144,   552,   415,   190,   415,   415,   414,
     414,   414,   659,   530,   531,   132,   199,   186,   186,   186,
     133,   192,    96,   220,   221,   235,    96,   220,   221,   235,
     235,   235,    96,    96,   239,   227,   233,   109,   237,   144,
     192,   189,   414,   186,   507,   589,   413,   235,   361,    34,
      34,   192,   338,   192,   115,   396,   659,   172,   415,   445,
     446,   120,   441,   442,   473,   155,   158,   261,   494,   513,
     590,   593,   594,   595,   596,   597,   601,   603,   605,   606,
      48,   154,   158,   213,   319,   320,   321,   322,   553,   555,
     557,   559,   573,   574,   575,   576,   653,   654,   655,   656,
     659,   553,   485,   558,   659,   485,   186,   187,   109,   189,
     189,   513,   150,   167,   150,   167,   139,   399,   382,   365,
     134,   555,   372,   415,   552,   657,   657,   130,   131,   657,
     279,   280,   281,   285,   659,   265,   276,   265,   276,    30,
     288,    98,   115,   158,   623,   626,   617,    40,    45,    54,
      61,    63,    72,    99,   227,   319,   320,   321,   386,   559,
     653,   229,   301,   310,   415,   659,    96,   301,   657,   155,
     570,   571,   659,   570,   571,   120,   429,   129,   553,   120,
     415,   149,   431,   149,    37,   149,   430,   431,   149,   552,
     256,    55,    60,    79,   120,   430,   436,   437,   438,   421,
     552,   553,   384,    96,   186,   200,   134,   356,   657,   162,
     134,    98,   356,   415,   144,   431,   155,   120,   415,   415,
     149,   102,   455,   456,   457,   459,   460,   102,   463,   464,
     465,   466,   394,   186,   186,   155,   570,   570,   415,   144,
     192,   415,   123,   189,   189,   189,    36,   531,   132,   199,
       9,    10,   105,   125,   127,   155,   197,   526,   528,   539,
     540,   543,   155,    30,   234,   236,   415,   415,   415,   234,
     236,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     509,   120,   415,   415,    49,    74,    75,   246,   396,   416,
     426,   247,   586,   587,   155,   212,   397,   415,   192,   115,
     391,   391,   391,   445,    97,   108,   118,   129,   447,   448,
     449,   450,   109,   659,   109,   414,   590,   597,   155,   287,
     475,   642,    98,   171,   254,   255,   257,   264,   274,   286,
     591,   592,   611,   612,   613,   614,   637,   640,   260,   262,
     598,   616,   269,   602,   638,   249,   250,   272,   607,   608,
     158,   158,   555,   158,   158,   158,   158,   158,   146,   178,
     196,   554,   146,   146,   415,   139,   399,   572,   371,   288,
      30,    98,   115,   158,   630,    30,   623,   554,   554,   496,
     289,   308,   552,   386,   229,   192,   393,   189,   189,   146,
     189,   189,   429,   149,   430,   659,   415,   149,   415,   129,
     415,   149,   431,   149,   415,   149,   120,   120,   415,   659,
     438,    79,   553,   396,   415,   657,   109,   356,   415,   144,
     393,   453,   415,   415,   115,   456,   457,   102,   188,   115,
     457,   460,   120,   467,   553,   102,   115,   464,   102,   115,
     466,   186,   393,   189,   189,   415,   415,   200,   463,   134,
     197,   528,     7,   394,   659,   197,   539,   394,   192,   235,
     235,   235,   235,    98,   239,   239,   584,   188,   158,   158,
     158,   188,   589,   587,   507,   657,   130,   131,   449,   450,
     450,   446,   108,   144,   443,   552,   442,   186,   189,   590,
     604,   252,   219,   256,   270,   277,   641,    98,   258,   259,
     639,   252,   594,   641,   477,   611,   595,   149,   284,   599,
     600,   639,   288,   610,    80,   609,   189,   196,   553,   556,
     189,   189,   189,   189,   189,   189,   189,    30,   138,   203,
     632,   633,   634,    30,   631,   632,   273,   627,   109,   624,
     172,   659,   259,   496,   186,   415,   149,   415,   149,   430,
     415,   149,   415,   415,   659,   659,   437,   415,   128,   128,
      98,   657,   415,   186,   188,   188,   415,   396,   415,   188,
     188,   659,   188,   212,   120,   467,   120,   188,   120,   467,
     188,   186,   115,   531,   659,   197,   186,   531,   659,   186,
     415,   415,   415,   415,   318,   415,   415,   415,   414,   414,
     414,   155,   588,   450,   657,   415,   144,   186,   479,    53,
     131,   477,   477,   271,   278,   288,   615,   615,   596,   155,
     282,    96,   189,   109,   189,   630,   630,   634,   109,   189,
      30,   628,   639,   625,   626,   189,   388,   389,   496,   120,
     227,   309,   289,   172,   415,   415,   149,   415,    55,   396,
     415,   356,   415,   396,    96,   396,   415,   553,   659,   188,
     659,   415,   659,   188,   396,   120,    95,   185,   532,   531,
     659,   199,   531,   415,   189,   189,   189,   414,   443,   415,
     477,   477,   201,   414,   553,   553,    96,    30,   267,   109,
     109,   450,   552,   659,   120,   227,   659,   388,   415,   120,
     467,    96,   188,    96,   659,     5,   135,   535,   536,   538,
     540,    29,   136,   533,   534,   537,   540,   199,   531,   199,
     200,   463,   186,   443,   477,   186,   553,   626,   389,   450,
     307,   659,   120,   227,   659,   188,   467,   396,   415,   467,
     188,    95,   135,   538,   185,   136,   537,   199,   115,   415,
     307,   659,   120,   396,   415,   188,   188,   120,   295,   307,
     659,   659,   308,   415,   308,   188,   496,   496,   201,   289,
     659,   227,   120,   659,   308,   496
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
      -1,   523,    -1,   524,    -1,   659,   147,   151,    -1,    48,
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
  const int xquery_parser::yylast_ = 17739;
  const int xquery_parser::yynnts_ = 326;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 618;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 336;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 590;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17961 "/home/mbrantner/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7014 "/home/mbrantner/zorba/sandbox/src/compiler/parser/xquery_parser.y"


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

