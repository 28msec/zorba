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
#line 915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1054 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"

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
#line 913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 945 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 945 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 945 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 945 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 426: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 431: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 434: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 467: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 473: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "NotExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 569: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 945 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 601: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 608: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 619: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 641: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 661: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2783 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
#line 2880 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 1072 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1076 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1080 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1088 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1094 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1098 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1107 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1113 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1121 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1127 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1138 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1143 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1147 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1152 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl(
        LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1161 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1168 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1175 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1184 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1191 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1199 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1207 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1215 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1226 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1231 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1238 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1245 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1257 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1267 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 1274 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 1281 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1316 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1321 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1329 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1337 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1345 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1350 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1358 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1363 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1371 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1376 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1384 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1389 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1394 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1399 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1412 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1422 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1427 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1435 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1443 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1454 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1461 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1472 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1477 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1485 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1492 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1499 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1508 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1521 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1529 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1536 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1546 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 1553 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1560 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1583 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1589 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1598 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1605 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1615 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1624 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1625 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1626 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1627 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1628 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1629 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1631 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1632 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1633 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1639 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1647 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1655 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1663 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1670 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1678 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1685 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1690 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1698 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1706 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1720 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1734 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1751 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1756 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1764 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1772 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1783 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1788 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1797 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1802 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1809 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1814 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1824 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1829 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1838 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1844 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1857 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1862 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1870 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1881 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1896 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1946 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1953 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1964 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1969 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1979 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1997 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2006 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2018 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2022 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2028 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2032 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2042 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2052 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2065 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2071 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2080 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2085 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2092 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2099 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2111 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2121 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2131 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2142 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2158 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2178 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2182 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2186 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2194 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2198 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2202 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2210 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2215 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2227 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 2234 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 2244 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2276 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 2281 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2289 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2306 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2314 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2322 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2329 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 2336 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2347 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2356 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2365 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2374 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2387 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2395 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2403 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2411 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2426 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2431 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2439 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2453 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2470 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2495 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2503 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2510 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2521 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2531 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2536 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2549 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2596 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2610 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2618 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2623 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2631 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2636 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2641 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2649 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2658 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2670 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2680 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2693 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2717 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2724 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2734 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2740 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2749 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2759 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      // this adds on shift-reduce conflict (probably with FTRange expression)
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2767 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2774 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2782 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2794 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2804 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2814 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2824 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2834 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2844 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2854 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2864 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2875 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2884 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2894 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2946 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2952 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2964 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2972 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2982 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2990 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3002 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3008 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 3021 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3025 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3033 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3037 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3050 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3054 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3064 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3072 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3079 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3085 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3095 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3099 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3103 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3111 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3119 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3127 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3139 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3147 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3153 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3163 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3169 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3179 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3183 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3193 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3199 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3205 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3211 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3220 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3229 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3238 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3251 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3255 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3263 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3269 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3279 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3287 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3296 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3309 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3316 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3328 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3332 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3344 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3351 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3357 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3366 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3373 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3379 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3390 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3397 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3403 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3412 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3421 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3428 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3439 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3446 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 3458 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3464 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3476 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3482 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3493 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3499 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3510 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3516 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3527 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3544 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
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
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3566 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3570 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3577 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3581 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new ComparisonExpr(
              LOC((yyloc)),
              new ValueComp( LOC((yyloc)), ParseConstants::op_val_not ),
              (yysemantic_stack_[(2) - (2)].expr),
              NULL
          );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3594 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3598 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 364:

/* Line 690 of lalr1.cc  */
#line 3608 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3615 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3624 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3633 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3638 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3647 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3656 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3665 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3678 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3682 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3694 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3698 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3705 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3709 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3716 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3720 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3729 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3733 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3737 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3745 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3749 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3755 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3761 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3767 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3777 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3781 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3785 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3793 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3797 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3803 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3813 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3817 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3827 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3831 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3841 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3845 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3855 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3859 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3869 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3873 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3882 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3886 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3894 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3898 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3902 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3906 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3916 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3924 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3944 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3948 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3952 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3956 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3960 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3964 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3972 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3976 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3980 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3992 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3996 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4000 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4011 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4017 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4027 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4033 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4043 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4047 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4114 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4136 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 4164 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4328 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4332 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4342 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4346 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4350 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4354 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4363 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4367 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4371 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4375 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4379 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4384 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4388 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4392 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4396 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4405 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4411 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4421 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4429 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4433 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4437 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4441 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4445 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4449 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4453 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4457 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4461 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4465 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4470 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4474 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4478 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4482 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4490 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4494 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4498 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4502 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4510 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4517 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4524 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4534 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4538 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4546 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4554 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4558 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4566 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4574 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4582 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4636 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4640 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 487:

/* Line 690 of lalr1.cc  */
#line 4662 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4668 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4674 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4680 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4690 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4694 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4702 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4710 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4722 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4726 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4734 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4738 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4742 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4750 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4758 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 502:

/* Line 690 of lalr1.cc  */
#line 4775 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4783 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 504:

/* Line 690 of lalr1.cc  */
#line 4802 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 505:

/* Line 690 of lalr1.cc  */
#line 4821 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 506:

/* Line 690 of lalr1.cc  */
#line 4843 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4849 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4860 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4866 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4877 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4892 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4897 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4906 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4910 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4917 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4947 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4958 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4964 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4970 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4977 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4992 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 5000 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 5004 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 5012 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 5016 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 5020 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 5025 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 5034 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 5038 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 5042 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 5046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 5054 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 5059 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 5067 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 5072 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 5080 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 5088 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 5093 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 5103 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 5108 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 5113 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 5124 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 5132 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 5136 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 5153 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 5157 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 5165 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 5173 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5181 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5185 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5193 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5197 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5205 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5213 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5217 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5221 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5226 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5261 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5267 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5273 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5283 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5287 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5291 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5296 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5300 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5305 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5309 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5313 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5317 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5324 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5330 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5340 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5348 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5356 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5360 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5364 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5368 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5372 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5376 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5380 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5384 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5388 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5392 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5400 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5408 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5412 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5416 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5424 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5431 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5439 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5447 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5451 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5455 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5463 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5467 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5473 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5479 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5483 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5493 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5501 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5505 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5511 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5520 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5529 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5535 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5541 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5551 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5568 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5575 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5590 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5617 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5621 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5637 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5641 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5652 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5669 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5675 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5701 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5707 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5711 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5717 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5733 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5740 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5763 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5769 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5779 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5810 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5829 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5843 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5850 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5856 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5866 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5875 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5883 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5889 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5919 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5950 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5954 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5961 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5965 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5972 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5976 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5985 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5997 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 6001 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 6008 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6012 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6020 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 6028 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6036 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6040 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6047 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6059 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6070 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6074 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6082 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6094 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6100 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6109 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6113 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6121 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6125 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6129 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6136 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6140 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6147 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6151 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6159 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6163 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6167 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6171 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6175 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6183 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6191 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6203 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6215 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6219 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6223 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6231 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6237 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6247 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6251 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6255 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6259 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6263 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6267 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6271 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6275 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6283 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6287 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6291 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6295 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6303 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6309 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6319 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6329 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6333 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6341 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 725:

/* Line 690 of lalr1.cc  */
#line 6351 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 726:

/* Line 690 of lalr1.cc  */
#line 6362 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6369 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6373 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6380 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6384 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6391 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6396 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6405 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6414 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6418 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6425 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6429 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6437 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6446 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6453 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6463 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6467 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6474 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6480 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6489 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6493 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6500 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6505 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6517 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6525 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6537 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6545 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6549 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6557 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6561 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6565 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6573 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6581 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6585 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6589 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6593 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6601 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6609 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6621 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6625 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6633 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6647 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6651 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6658 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6663 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6671 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6676 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6685 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6693 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6700 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6706 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6713 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6724 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6730 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 780:

/* Line 690 of lalr1.cc  */
#line 6740 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6745 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(4) - (2)].expr),
                                        (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6751 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(4) - (2)].node));
          (yyval.expr) = new JSONObjectInsertExpr(
              LOC((yyloc)),
              new JSONDirectObjectConstructor(
                  LOC((yyloc)),
                  jpl),
              (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6761 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6768 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6772 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6779 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 787:

/* Line 690 of lalr1.cc  */
#line 6801 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(2) - (2)].expr));

          if (lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(2) - (2)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(2) - (2)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          (yyval.expr) = new JSONDeleteExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0));
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6826 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 789:

/* Line 690 of lalr1.cc  */
#line 6851 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(4) - (2)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(4) - (2)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(4) - (4)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(4) - (2)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(4) - (4)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONRenameExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 791:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation =
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(6) - (4)].expr));

          if(lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(6) - (2)]), "An object invocation is expected. A filter was found instead.");
            delete (yysemantic_stack_[(6) - (6)].expr);
            YYERROR;
          }

          if (lDynamicFunctionInvocation->getArgList()->size() != 1)
          {
            error((yylocation_stack_[(6) - (2)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            delete (yysemantic_stack_[(6) - (6)].expr);
            YYERROR;
          }

          (yyval.expr) = new JSONReplaceExpr(
                LOC((yyloc)),
                lDynamicFunctionInvocation->getPrimaryExpr(),
                lDynamicFunctionInvocation->getArgList()->operator[](0),
                (yysemantic_stack_[(6) - (6)].expr));
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6993 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 805:

/* Line 690 of lalr1.cc  */
#line 7006 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 7007 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 7008 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 7009 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 7010 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 7012 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 7013 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 7014 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 7015 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 7016 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 7017 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 7018 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 7019 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 7020 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 7021 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 7026 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 7027 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 7028 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 7029 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 7030 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 7031 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 7032 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 7033 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 7034 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 7035 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 7036 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 7037 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 7038 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 7039 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 7040 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 7041 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 7042 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 7043 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 7044 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 7045 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 7046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 7047 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 7048 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 7049 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 7050 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 7051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 7052 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 7053 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 7054 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 7055 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 7056 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 7057 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 7058 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 7059 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 7060 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 7061 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 7062 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 7063 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 7064 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 7065 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 7066 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 7067 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 7068 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 7069 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 7070 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 7071 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 7072 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 7073 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 7074 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 7075 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 7076 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 7077 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 7078 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 7079 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 7080 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 7081 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 7082 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 7083 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 7084 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 7085 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 7086 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 7087 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 7088 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 7089 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 7090 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 7091 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 7092 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 7093 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 7094 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 7095 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 7096 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 7097 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 7098 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 7099 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 7100 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 7101 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 7102 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 7103 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 7104 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 7105 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 7106 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 7107 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 7108 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 7109 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 7110 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 7111 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 7112 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 7113 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 7114 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 7115 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 7116 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 7117 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 7118 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 7119 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 7120 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 7121 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 7122 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 7123 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 7124 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 7125 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 7126 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 7127 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 7128 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 7129 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 7130 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 7131 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 7132 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 7133 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 7134 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 7135 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 7136 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 7137 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 7138 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 7139 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 7140 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 7141 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 7142 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 7143 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 7144 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 7145 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 7146 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 7147 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 7148 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 7149 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 7150 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 7151 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 7152 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 7154 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 7155 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 7157 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 7158 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 7159 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 7160 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 7161 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 7163 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 7165 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 7166 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 7167 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 7168 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 7169 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 7170 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 7171 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 7172 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 7173 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 7174 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 7175 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 7176 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 7177 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 7178 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 7179 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 7180 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 7181 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 7182 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 7183 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 7184 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 7185 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 7186 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 7187 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 7188 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 7189 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 7190 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 7191 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 7192 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 7193 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 7194 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 7195 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 7196 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 7197 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 7198 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 7199 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 7200 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 7201 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 7202 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 7203 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 7204 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7205 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 7206 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 7207 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 7208 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 7209 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 7210 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 7211 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 7212 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 7213 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 7214 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 7215 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 7216 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 7217 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 7218 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 7219 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 7220 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 7221 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 7222 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 7223 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 7226 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 7235 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12246 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1481;
  const short int
  jsoniq_parser::yypact_[] =
  {
      4438,  8672,  8672,  8672,  8672, -1481, -1481,    71,   297, -1481,
     815,    37, -1481, -1481, -1481,   490, -1481, -1481, -1481,   505,
   -1481,   525,    60,   594,   601,   410, -1481,    10, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481,   610, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481,   682, -1481,   669, -1481,   672,   694, -1481,
     355, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481,   745, -1481, -1481, -1481, -1481, -1481, -1481, -1481,   755,
   -1481, -1481, -1481, -1481, -1481, 18836, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481,   805, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481,  5054, 10786, 11088, 18836, -1481, -1481,
     793, -1481, -1481, -1481, -1481,   799, -1481, -1481, -1481,  6864,
   -1481,  7162, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481,   813, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481,    76,   769,   775, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, 14712, -1481,  5660, -1481,
   15014,   400, -1481, -1481, -1481, -1481, -1481, -1481,   854, -1481,
     750,   768,   774, -1481, -1481,   871,   878, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,   762,
   -1481, 14410, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   11390, 11692, 11994, -1481,  4746,  7464,  1036, -1481,  8974, -1481,
   -1481,   810,   101, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481,   107, -1481, -1481,
   -1481, -1481, -1481, -1481,   580, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481,  8672, -1481, -1481, -1481, -1481,   282, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481,   251, -1481,   851,
   -1481, -1481, -1481,   604, -1481,   603, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481,   884,   962, -1481, -1481,  1129,   818,   959,
     508,   635,   237,   572, -1481,  1018,   876,   977,   979, 13504,
   -1481,   886, -1481, -1481,    27, -1481, -1481, -1481, -1481,   650,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481,   938,   930, -1481, -1481, -1481, -1481, -1481,
     905, -1481,  8672,   906,   907,   908,  8672,    64,    64,  1059,
      14,   481,   703, 19127, 18836,    22,  1048, 18836,   943,   981,
     652,  6864,   811,   847, 18836, 18836,   792,   733,    53, -1481,
   -1481, -1481,  6864,  8672,  8672, 12900,    33,   948, 12900,  1104,
     254,   132, 18836,   986,   963,  1001, -1481, 12900, 18836,  8672,
   12900, 12900, 18836,  8672,   956,   960, 12900, 18836, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481,   969, -1481, 18836, -1481,
   -1481,   928,  7766,   994,   361,   996,   938,   965,   967,   968,
   18836,  5357, -1481,   972,   188, -1481,   644, -1481,    91,  1084,
   12900, 12900,    92, -1481, -1481, -1481,  1111, 12900,   914, -1481,
    1102,  1103, 12900, 13202, 15316,   650, 12900, 13202,  5963,    -4,
       7, 12900, 15316,   630, 12900,   894,   898, 18836,   944,   947,
   12900, 12900,  8068,   895, -1481, -1481,    62, -1481,    57, 12900,
     910,  7464, -1481, -1481, -1481, -1481, -1481,   815,   410,   114,
     130,  1142,  9276,  2877,  9578,  3196,   755, -1481, -1481,   312,
     755, -1481, 12900,  3828, -1481,  1027, -1481,    10,   980,   982,
     983,  8672, 12900, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, 18836, -1481,   861,   869, 18836,  1033, 13806, 13806,
   14108, -1481, 14108, 14108, -1481, 14108, -1481, 14108, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, 14108, 14108,  1086, 14108, 14108,
   14108, 14108, 14108, 14108, 14108, 14108, 14108, 14108, 14108, 14108,
     923,  1065,  1066,  1068, -1481, -1481, -1481, 15316, 12296, -1481,
    6264, 12900,  9880,  1009, -1481,  1015, 10182, -1481, -1481, -1481,
   -1481,   327, -1481,   360, -1481, -1481, -1481, -1481, -1481, -1481,
    1058,  1060,   594,  1138, -1481, -1481, 19127,  1262,   646, 18836,
    1010,  1011,  1262,  1059,  1050,  1043, -1481, -1481, -1481,   128,
     931,  1088,   875, 18836,  1038, 12900,  1067, 18836, 18836, -1481,
    1051,  1000,  1005,   261, 18836,  1096,   395, -1481,  8672, -1481,
     111, -1481,  6864,  1097,  1148,  6864,  1059,  1098,   640, 18836,
   12900,    10,   274,   299, -1481,    79,  1013,   125,   134,  1042,
   -1481,  1014,  8672,  8672,   356,   715, 12900,   322, -1481, -1481,
   12900,  5963, -1481, 12900, 12900, 12900, 12900, -1481, 12900, -1481,
   12900, -1481, 18836,  1084, -1481,   310,   377,   386, -1481, -1481,
   -1481,   388, -1481,    32,   276, -1481, -1481,   650,   389,   405,
      17,   290, 12900, 12900,  1106,   803, 12900,   966, 15618,   973,
     277, -1481,  1062, -1481, -1481,  1022,   149,  7766,   393,  4136,
     895, -1481, -1481, -1481,   976, 12900, -1481,   810,   786,  1183,
     187, -1481, -1481,   157, -1481, -1481, -1481,   159, -1481,    41,
   -1481, -1481, -1481, -1481, -1481,  3512, -1481, -1481, -1481, 18836,
    1046, 12900,  1099, -1481, -1481, -1481,  1112, -1481,    74, -1481,
   -1481,  1112, 18836,    21,   962, -1481, -1481, -1481, -1481, -1481,
   14108, -1481, -1481, -1481,   483, -1481,   635,   635,   656,   237,
     237,   237,   237,   572,   572, -1481, -1481, 17377, 17377, 18836,
   18836, -1481, -1481,   394, -1481, -1481, -1481, -1481, -1481,   215,
   -1481, -1481, -1481,   466, -1481, -1481, -1481,   472,    64, -1481,
   -1481,   731,   764,   434, -1481,   594, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481,  1262, -1481,  1089, 17670,
    1076, 12900, -1481, -1481, -1481,  1128,  1059,  1059,  1262, -1481,
     870,  1059,   720, 18836,   298,   684,  1195, -1481, -1481,   936,
      80, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481,   128,    42,   997,   613, 12900, -1481, 18836,  1133,
     927,  1059, -1481, -1481,  1079,  1128, 17377,  1116,  1141,  1053,
    1044,  1108,  1059,  1083,  1113,  1151,  1059, 17377, 12900,    29,
   -1481, -1481, -1481,  1091,  1130, 12900, 12900,  1107, -1481,  1150,
    1153,  8672, -1481,  1071,  1072,  1109, 12900,  1118,  1061, 12900,
   -1481,  1143,  1146, -1481,   158,   167,   193,  1229, -1481,   344,
   -1481,   664,  1115, -1481, -1481,  1245, -1481,  1246, -1481,   814,
   12900, 12900, 12900,   819, 12900, 12900, 12900, 12900, 12900,  1179,
   -1481, 12900, 12900, -1481, 12900, 12900,   441, 15316,  1159, 12900,
   12900, -1481, 10484,   162,  1029, -1481, -1481, -1481, -1481, -1481,
   -1481,   487, -1481, -1481, 12900, -1481,   160,   110,    41,  9578,
    3196,  9578,  1200, -1481, -1481, 12900,   863,  1175, -1481, 18836,
    1176, -1481, 18545,  1158,  1169, 12900,   265,  1145,    47,   536,
    1030, -1481, -1481,   749,    21, -1481, 12900,   483,   919,   267,
   -1481,  1004,   103,  1028,  1031, -1481, -1481,   847, -1481,  1023,
     527,  1140,  1147,  1149,  1156,  1162,  1163,  1164,  1166,  1167,
    1168,  1170, 16205,  1171,  1172,  1173,  1174,  1182,  1184, -1481,
      31, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481,  1154, -1481, -1481, -1481, -1481, 12598,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,   808,
   -1481,  1269, 17670,   873, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481,  1012, -1481, -1481,  1273, -1481, -1481, -1481,
   -1481, -1481,   592,  1276, -1481,   821, -1481, -1481, -1481,  1140,
    1147,  1149,  1162,  1163,  1164,  1166,  1167,  1168,  1172, -1481,
      31,    31, 15316,  1016,   999, -1481,  1128,    42,  1075,  1135,
    8672, -1481, -1481, -1481, 17377, -1481,  8672,  1059,  1232, -1481,
   -1481, -1481,  1059,  1232, -1481, -1481, 12900,  1210,  8672, 18836,
   -1481, -1481, 12900, 12900,    95, -1481,    25,   535, -1481, 16498,
     629, -1481,   837, -1481,  1177, -1481, -1481,  8672, -1481, 12900,
   -1481, -1481, 12900, 12900,  1155,  1150,  1254, -1481,  1223, -1481,
     817, -1481, -1481,  1352, -1481, -1481,  8672, 18836, -1481,   840,
   -1481, -1481, -1481,  8672,  1178,  1181,  1121,  1122, -1481, -1481,
   -1481,  1123,  1125, -1481, -1481, -1481,  1267, -1481,  1045, -1481,
   -1481, -1481,  1126, 12900,   514, 18836,  1180, -1481,  1208,  1213,
    1216,  1220, -1481,   851,   678,  4136,  1029, -1481,  8370,  4136,
   -1481, -1481,  1183,   469, -1481, -1481, -1481,  1175, -1481,  1059,
   -1481,   916, -1481,   330,  1268, -1481, 12900,   772,  1099, 18836,
   -1481,    83, 18836, -1481, 12900,  1228, 12900,  1249, 12900,   271,
    1230, 12900,  1231, -1481,  1261,  1263, 12900, 18836,   958,  1303,
   -1481, -1481, -1481,   402,  1197, -1481,   483,  1131, -1481, -1481,
     190, -1481,   708,   144,  1132,   483,   708, 14108, -1481,   203,
   -1481, -1481, -1481, -1481, -1481, -1481,   483,  1235,  1105,   931,
     144, -1481, -1481,  1100,  1309, -1481, -1481, -1481,  1201,    93,
   17963, 15912,  1202,  6564, 18836, 18836,  1205, 18254,  1206, -1481,
    1207,  1209,  1212,  1214,  1215,  1217,  1218, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
    1369,   289,  1372,   289,  1134,  1299, -1481, -1481,  1237, 18836,
    1152, -1481, -1481, 15316, -1481,  1227, -1481,  1286,  1290,  1321,
    1059,  1232, -1481, 12900,  1234, -1481, -1481, -1481,  1233, -1481,
      72, 12900,  8672,  1236,   253, -1481, 18836,    -8, -1481, 16791,
     363, -1481, 17084,  1238, -1481, -1481,  1239, -1481, -1481, -1481,
   12900,   860,  1229, 18836,   903, -1481,  1241,  1229, 18836, -1481,
    1242, -1481, -1481, 12900, 12900, 12900, 12900,  1110, 12900, 12900,
   -1481, 12900, -1481, 12900, 12900, 12900, 12900, 10484,   499, -1481,
   -1481, -1481, -1481, -1481,  1268, -1481, -1481, -1481,  1059, 12900,
   -1481,  1278, -1481, -1481, 12900,  1274, -1481, -1481, 12900, -1481,
     565, -1481, 12900,  1281, 12900, -1481, 12900, 18836, 18836, -1481,
     778, -1481, 12900, -1481, -1481, -1481,  1247, 14108, -1481, -1481,
   -1481, -1481, -1481,   564, 14108, 14108,   -90, -1481,  1028, -1481,
     486, -1481,  1031,   483,  1279, -1481, -1481,  1157, -1481, -1481,
   -1481, -1481, -1481, -1481,  1248,  1250, -1481,   478,   492,  1335,
    1251, -1481,   493, -1481,  1252, -1481,  1253,  1255,  1256, -1481,
   -1481,   539,   543, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481,    81,    81, -1481,   289, -1481, -1481,   548, -1481,
    1405,    15,  1338,  1257, 15316,   -23,  1160,  1275, -1481, 10484,
   12900,  1059, -1481, -1481, -1481, 12900, 12900, -1481, -1481, -1481,
   10484, 10484,  1353,  8672, 17377, 18836,    -1, 18836, 12900, 18836,
     268, 10484, -1481,   504,    51,  1229, 18836, -1481,  1259,  1229,
   -1481, -1481, -1481, -1481, -1481, 12900, -1481, -1481, -1481, -1481,
     216,   230,   236, 12900, -1481, -1481, -1481,  1340, 12900, -1481,
   12900, -1481, 12900,  1301, -1481, 12900, -1481, -1481, -1481,  1396,
   -1481, -1481, -1481,   237, 14108, 14108,   656,   737, -1481, -1481,
   -1481, -1481, -1481, -1481, 12900, -1481, -1481, -1481, 18836, -1481,
   18836, -1481, 17377, -1481, 17377,  1356, -1481, -1481, -1481, -1481,
   18836, -1481, 18836, -1481, -1481, -1481, -1481,  1424, -1481, -1481,
   -1481,  1185,  1346, -1481, -1481,  1350, -1481,   882, 18836,  1341,
    1240, 18836, 15316, -1481, -1481,  1232, -1481, -1481, 17377, -1481,
   -1481, -1481,  1364, 12900,  1277, -1481,  1367, 10484, -1481, 18836,
     485,   674, -1481,  1265,  1229, -1481,  1270, -1481,  1272,  1150,
    1153,   417, -1481,  1340, -1481, -1481, 12900, -1481,  1347,   656,
     656, 14108,   425,  1284,  1285,  1322,  1288,  1292, -1481, -1481,
   17377,  1293,  1294, -1481, -1481,  1338, 15316, -1481,  1268,  1186,
   18836,  1355,  1258,  1350,   627, 17377,  8672, 17377,  1282, -1481,
   -1481,  1384,   618, -1481, -1481, -1481, -1481,  1300,   710, -1481,
   -1481, -1481,  1287, -1481, 10484,   868, -1481, -1481, -1481, 18836,
     656, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481, 12900,  1187, 18836,  1368,  8672,   690, -1481,
   -1481,   746, 12900, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
    1370, -1481, -1481,  1188,  1190, 18836, -1481, -1481, 12900, 10484,
   18836,  1192, 12900,  1193,  1296, 15316, -1481, 15316, 10484, -1481,
    1298,  1198, 18836,  1264,  1382, 18836,  1194, 15316, -1481
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   170,   170,   170,     0,   821,  1016,   122,   124,   619,
     913,   922,   862,   826,   824,   806,   914,   917,   869,   830,
     807,   809,   259,   923,   810,   920,   891,   871,   846,   808,
     866,   867,   918,   915,   865,   812,   921,   813,   814,   958,
     970,   957,   863,   882,   876,   815,   864,   817,   816,   959,
     900,   901,   868,   843,   980,   981,   982,   983,   984,   985,
     986,   987,   988,   989,   990,  1004,  1011,   890,   886,   877,
     857,   805,   885,   893,   902,  1005,   881,   474,   858,   859,
     916,  1006,  1012,   878,   895,     0,   482,   476,   888,   823,
     879,   880,   909,   883,   899,   908,  1010,  1013,   829,   870,
     911,   475,   898,   904,     0,     0,     0,     0,   407,   896,
     907,   912,   910,   889,   875,   960,   873,   874,  1007,     0,
     406,     0,  1008,  1014,   905,   860,   884,  1009,   906,   887,
     894,   903,   897,   961,   851,   856,   855,   854,   853,   852,
     818,   872,     0,   822,     0,   919,   844,   473,   477,   478,
     951,   950,   952,   828,   827,   847,     0,   811,     0,   954,
       0,     0,   850,   892,   949,   956,   955,   948,   848,   953,
     965,   966,   963,   964,   962,   819,   967,   968,   969,   939,
     938,   925,   842,   835,   932,   928,   845,   841,   940,   260,
     831,   832,   825,   834,   937,   936,   933,   929,   946,   947,
     945,   935,   931,   924,   833,   944,   943,   837,   839,   838,
     930,   934,   926,   840,   927,   836,   942,   991,   992,   993,
     994,   995,   996,   972,   973,   971,   977,   978,   979,   974,
     975,   976,   849,   997,   998,   999,  1000,  1001,  1002,  1003,
       0,     0,     0,  1015,   167,   167,     0,     2,   167,     9,
      11,    25,     0,    30,    33,    38,    39,    40,    41,    42,
      43,    44,    34,    60,    61,    35,    36,     0,    78,    81,
      82,    37,    83,    84,     0,   120,    85,    86,    87,    88,
      20,   164,   165,   166,   173,   176,   465,   177,     0,   178,
     179,   180,   181,   182,   183,   184,   187,     0,   213,   221,
     216,   248,   254,     0,   246,     0,   247,   223,   217,   186,
     218,   185,   219,   222,   356,   358,   360,   362,   372,   374,
     378,   380,   383,   388,   391,   394,   396,   398,   400,     0,
     404,   411,   410,   412,     0,   430,   413,   435,   436,   437,
     444,   456,   470,   472,   457,   458,   459,   462,   463,   460,
     464,   491,   492,   461,   495,   497,   498,   499,   496,   544,
     545,   546,   547,   548,   549,   550,   471,    45,   224,   225,
     227,   226,   228,   220,   467,   468,   469,   466,   230,   233,
     229,   231,   232,     0,   804,   820,   913,   922,   920,   822,
       0,   168,   169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
     130,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   279,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   194,   806,
     830,   809,   861,   923,   810,   871,   812,   882,   815,   817,
     816,   900,   805,   859,   883,   907,   960,   961,   848,   965,
     966,   963,   819,   967,   941,   832,   479,   804,     0,   802,
     189,     0,     0,   213,     0,     0,   803,   810,   817,   816,
       0,   170,   767,   967,     0,   221,     0,   480,     0,   511,
       0,     0,     0,   803,   433,   434,     0,     0,     0,   540,
       0,     0,   811,   954,     0,   787,   811,   954,     0,     0,
       0,   811,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   361,   769,     0,   771,     0,     0,
       0,   167,     3,     4,     1,    10,    12,     0,     0,     0,
       0,     6,   167,     0,   167,     0,     0,   121,   174,     0,
       0,   192,     0,     0,   201,     0,   259,     0,     0,     0,
       0,     0,     0,   260,   206,   234,   253,   249,   255,   250,
     252,   251,     0,   258,     0,     0,     0,     0,     0,     0,
       0,   423,     0,     0,   421,     0,   367,     0,   422,   415,
     420,   419,   418,   417,   416,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   409,   408,   405,     0,     0,   431,
       0,     0,     0,   445,   453,     0,     0,   552,   554,   558,
     560,     0,   126,     0,   801,    49,    46,    47,    50,    51,
       0,     0,     0,     0,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   626,   627,   628,     0,
     105,   144,     0,     0,   114,     0,     0,     0,     0,   129,
       0,     0,     0,     0,     0,   136,     0,   140,   170,   494,
       0,    62,     0,    71,     0,     0,     0,    63,     0,     0,
       0,     0,     0,     0,   327,     0,     0,     0,     0,     0,
     617,     0,     0,     0,     0,   196,     0,     0,   190,   188,
       0,     0,   773,     0,     0,     0,     0,   479,     0,   768,
       0,   481,   512,   511,   508,     0,     0,     0,   542,   541,
     432,     0,   539,     0,     0,   639,   640,   786,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   645,     0,   204,   205,     0,     0,     0,     0,     0,
     209,   210,   770,   772,     0,     0,     5,    26,     0,    27,
       0,     7,    31,     0,    17,     8,    32,     0,    21,   913,
      79,    18,    80,    22,   195,     0,   193,   214,   215,     0,
       0,     0,     0,   207,   235,   296,   257,   261,     0,   236,
     237,   256,     0,     0,   357,   359,   365,   371,   370,   369,
       0,   366,   363,   364,     0,   375,   382,   381,   379,   385,
     386,   387,   384,   389,   390,   393,   392,     0,     0,     0,
       0,   414,   428,     0,   452,   450,   449,   451,   448,     0,
     487,   446,   489,     0,   454,   493,   485,     0,     0,   123,
     125,     0,     0,     0,   104,     0,    94,    96,    97,    98,
      99,   101,   102,   103,    95,   100,    90,    91,     0,     0,
     110,     0,   106,   108,   109,   116,     0,     0,    89,    48,
       0,     0,     0,     0,     0,     0,     0,   717,   722,     0,
       0,   718,   752,   705,   707,   708,   709,   711,   713,   712,
     710,   714,     0,     0,     0,     0,     0,   113,     0,   146,
       0,     0,   557,   551,     0,   142,     0,     0,   137,     0,
       0,     0,     0,     0,     0,    64,     0,     0,     0,     0,
     277,   283,   280,     0,     0,     0,     0,     0,   556,     0,
       0,     0,   424,     0,     0,     0,     0,   197,     0,     0,
     775,     0,     0,   774,     0,     0,     0,   511,   509,     0,
     500,     0,     0,   483,   484,     0,    13,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   781,
     782,     0,     0,   789,     0,   811,     0,     0,     0,     0,
       0,   202,     0,     0,     0,   441,   442,   443,   440,   653,
     439,     0,   438,   211,     0,   785,     0,     0,     0,   167,
       0,   167,     0,   175,   245,     0,   311,   307,   309,     0,
     297,   298,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   238,   239,     0,   244,   368,     0,     0,     0,     0,
     683,   376,   656,   660,   662,   664,   666,   669,   676,   677,
     685,   806,   807,   809,   923,   808,   812,   813,   814,   815,
     805,   573,     0,   818,   811,   798,   800,   796,   575,   395,
     563,   570,   571,   592,   583,   591,   590,   589,   588,   585,
     587,   584,   586,   576,   620,   621,   577,   578,   792,   793,
     794,   581,   397,   399,   402,   582,   401,   429,   455,     0,
     447,   486,   127,    58,    59,    56,    57,   133,   132,     0,
      92,     0,     0,     0,   111,   112,   117,    76,    77,    54,
      55,    75,   723,     0,   726,   753,     0,   716,   715,   720,
     719,   751,     0,     0,   728,     0,   724,   727,   706,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
     148,   150,     0,     0,     0,   115,   118,     0,     0,     0,
     170,   143,   138,   141,     0,   191,     0,     0,    73,    67,
      70,    69,     0,    65,   562,   281,     0,     0,   170,     0,
     325,   329,     0,     0,     0,   332,     0,     0,   338,     0,
       0,   345,     0,   349,     0,   426,   425,   170,   198,     0,
     200,   326,     0,     0,     0,     0,     0,   512,     0,   502,
       0,   535,   532,     0,   536,   537,     0,     0,   531,     0,
     506,   534,   533,     0,     0,     0,     0,     0,   632,   633,
     629,     0,     0,   637,   638,   634,   778,   779,     0,   643,
     788,   641,     0,     0,     0,     0,     0,   647,   810,   817,
     816,   967,   203,     0,     0,     0,   648,   649,     0,     0,
     212,   784,    28,     0,    19,    23,    24,   308,   320,     0,
     321,     0,   312,   313,   314,   315,     0,   300,     0,     0,
     263,     0,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,     0,     0,     0,     0,   290,     0,
     287,   292,   243,     0,     0,   667,   680,     0,   373,   377,
       0,   699,     0,     0,     0,     0,     0,     0,   655,   657,
     658,   694,   695,   696,   698,   697,     0,     0,   671,   670,
       0,   674,   678,   692,   690,   689,   682,   686,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   566,
       0,     0,     0,     0,     0,     0,     0,   567,   569,   568,
     564,   403,   488,   490,   135,   134,    93,   107,   740,   721,
       0,   745,     0,   745,   734,   729,   149,   151,     0,     0,
       0,   119,   147,     0,    29,     0,   139,     0,     0,    72,
       0,    66,   282,     0,     0,   328,   330,   335,     0,   333,
       0,     0,     0,     0,     0,   339,     0,     0,   353,     0,
       0,   346,     0,     0,   350,   427,     0,   199,   776,   777,
       0,     0,   511,     0,     0,   543,     0,   511,     0,   507,
       0,    14,    16,     0,     0,     0,     0,     0,     0,     0,
     791,     0,   646,     0,     0,     0,     0,     0,     0,   650,
     654,   324,   322,   323,   316,   317,   318,   310,     0,     0,
     305,     0,   299,   262,     0,     0,   276,   268,     0,   272,
       0,   266,     0,     0,     0,   285,     0,     0,     0,   242,
     288,   291,     0,   684,   675,   681,     0,     0,   754,   755,
     765,   764,   763,     0,     0,     0,     0,   756,   661,   762,
       0,   659,   663,     0,     0,   668,   672,     0,   693,   688,
     691,   687,   599,   594,     0,     0,   609,     0,     0,     0,
       0,   579,     0,   597,     0,   600,     0,     0,     0,   598,
     603,     0,     0,   572,   625,   565,   593,   797,   799,   795,
     574,   741,     0,     0,   739,   746,   747,   743,     0,   738,
       0,   736,     0,     0,     0,     0,     0,     0,   553,     0,
       0,     0,    68,   284,   559,     0,     0,   336,   340,   334,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   555,     0,     0,   511,     0,   538,     0,   511,
     561,   630,   631,   635,   636,     0,   783,   642,   790,   644,
       0,     0,     0,     0,   651,   319,   306,   301,     0,   265,
       0,   274,     0,     0,   270,     0,   273,   286,   294,   295,
     289,   241,   679,   766,     0,     0,   758,     0,   704,   703,
     702,   701,   700,   665,     0,   757,   595,   596,     0,   613,
       0,   610,     0,   622,     0,     0,   602,   601,   608,   616,
       0,   606,     0,   604,   750,   749,   748,     0,   742,   735,
     733,     0,   730,   731,   725,   152,   154,   156,     0,     0,
       0,     0,     0,   208,   355,    74,   331,   337,     0,   351,
     347,   354,     0,     0,     0,   341,     0,     0,   343,     0,
     521,   515,   510,     0,   511,   501,     0,   780,     0,     0,
       0,     0,   304,   302,   269,   267,     0,   275,     0,   760,
     759,     0,     0,     0,     0,   617,     0,     0,   623,   580,
       0,     0,     0,   744,   737,     0,     0,   158,   157,     0,
       0,     0,     0,   153,     0,     0,     0,     0,     0,   529,
     523,     0,   522,   524,   530,   527,   517,     0,   516,   518,
     528,   503,     0,   504,     0,     0,   652,   303,   271,     0,
     761,   673,   614,   615,   618,   611,   612,   624,   607,   605,
     732,   155,   159,     0,     0,     0,     0,     0,     0,   344,
     342,     0,     0,   514,   525,   526,   513,   519,   520,   505,
       0,   293,   160,     0,     0,     0,   352,   348,     0,     0,
       0,     0,     0,     0,     0,     0,   162,     0,     0,   161,
       0,     0,     0,     0,     0,     0,     0,     0,   163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1481, -1481,  -191,  -178, -1481,  1266,  1280, -1481,  1271,  -467,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
    -912, -1481, -1481, -1481, -1481,  -209,  -514, -1481,   845,  -685,
   -1481, -1481, -1481, -1481, -1481,   387,   632, -1481, -1481,     9,
    -164,  1117, -1481,  1095, -1481, -1481,  -561, -1481,   582, -1481,
     349, -1481,  -165,  -216, -1481,  -498, -1481,    20,    28,    34,
    -268,  -166, -1481,  -784, -1481, -1481,   431, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481,   751,    38,  1101,
       0, -1481, -1481, -1481, -1481,   480, -1481, -1481,  -291, -1481,
       5, -1481, -1481,   937,  -960,  -783,  -775, -1481, -1481,   824,
   -1481, -1481,    36,   219, -1481, -1481, -1481,   241, -1480, -1481,
     506,   244, -1481, -1481,   249, -1224, -1481,  1055,   345, -1481,
   -1481,   341,  -933, -1481, -1481,   339, -1481, -1481, -1170, -1174,
   -1481,   335, -1357, -1481, -1481,   950,  -157, -1481, -1481,  -472,
     932, -1481, -1481,  -600,   454,  -562,   450,   453, -1481, -1481,
   -1481,   699, -1481, -1481,  1219, -1481, -1481, -1481, -1481, -1481,
    -731,  -314,  -614, -1481, -1481,   273, -1481,  -142, -1481,   911,
   -1481,  -370, -1481, -1481,   913,   915, -1481, -1481, -1481, -1481,
     917, -1481, -1481, -1481, -1481,  -901, -1481,   326, -1481,   816,
    -662, -1481, -1481, -1481, -1481, -1481,  -211,  -200, -1139,  -945,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481,  -666,  -790,   -85,  -781, -1481, -1481, -1481,  -840, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481,   205,   206,  -664,
     -94,  -585, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
   -1481, -1481, -1481,   302, -1481, -1481,   292, -1481,   294,  -983,
   -1481, -1481, -1481,   235,   227,    54,   522, -1481, -1481, -1481,
   -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481, -1481,
     242, -1481, -1481, -1481,    63,   515,   663, -1481, -1481, -1481,
   -1481, -1481,   432, -1481, -1481, -1467, -1481, -1481, -1481,  -466,
   -1481,   195, -1481,    24, -1481, -1481, -1481, -1481, -1263, -1481,
     250, -1481, -1481, -1481, -1481, -1481,  -114, -1481, -1481, -1481,
   -1481, -1481,  -830, -1481, -1481, -1481,  -356,  -102,   211,   479,
   -1481
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   246,   563,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
    1178,   696,   264,   265,   266,   267,   268,   269,   876,   877,
     878,   270,   271,   272,   882,   883,   884,   273,   417,   274,
     275,   641,   276,   419,   420,   421,   427,   686,   687,   277,
    1159,   278,  1675,  1676,   279,   280,   281,   481,   282,   283,
     284,   285,   286,   689,   287,   288,   448,   289,   290,   291,
     292,   293,   294,   574,   295,   296,   770,   771,   297,   298,
     495,   300,   575,   587,  1043,  1044,   301,   576,   302,   578,
     496,   304,   305,   806,   807,  1308,   434,   306,   435,   436,
     813,  1309,  1310,  1311,   579,   580,  1030,  1031,  1470,   581,
    1027,  1028,  1282,  1283,  1284,  1285,   307,   703,   704,   308,
    1194,  1195,  1410,   309,  1197,  1198,   310,   311,  1200,  1201,
    1202,  1203,  1417,   312,   313,   314,   315,   316,   820,   317,
     318,  1318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,  1103,   328,   329,   330,   331,   605,   606,   332,   333,
     334,   335,   336,   337,   338,  1009,  1010,   339,   633,   634,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     853,   350,   351,   352,   353,   354,   355,  1229,   733,   734,
     735,  1702,  1757,  1758,  1751,  1752,  1759,  1753,  1230,  1231,
     356,   357,  1232,   358,   359,   360,   361,   362,   363,   364,
     365,   939,  1418,  1370,  1080,  1532,  1081,  1104,  1082,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,   709,
    1724,   366,  1093,  1094,  1095,  1096,   367,   368,   369,   370,
     371,   372,   760,   761,   373,  1266,  1267,  1614,  1011,  1051,
    1328,  1329,  1052,  1053,  1054,  1055,  1056,  1338,  1515,  1516,
    1057,  1341,  1058,  1496,  1059,  1060,  1346,  1347,  1521,  1519,
    1330,  1331,  1332,  1333,  1641,   670,   903,   904,   905,   906,
     907,   908,  1146,  1563,  1672,  1147,  1561,  1670,   909,  1383,
    1558,  1554,  1555,  1556,   910,   911,  1334,  1342,  1506,  1335,
    1502,  1319,   374,   375,   376,   377,   484,   378,   379,   380,
     381,   382,  1097,  1098,  1099,  1100,  1179,   485,   383,   384,
     385
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -942;
  const short int
  jsoniq_parser::yytable_[] =
  {
       299,   299,   299,   299,   299,   303,   303,   303,   303,   303,
     533,   828,   577,   841,   515,   558,  1196,   502,   523,   418,
     629,   390,   393,   394,  1183,  1036,  1421,   642,   642,   391,
     391,   391,   395,  1037,   534,   392,   392,   392,   396,   947,
     790,   792,   550,   645,   520,   847,  1431,  1079,  1102,   957,
     829,   830,   831,   832,   784,   788,   791,   793,   551,  1465,
    1466,   553,  1586,   551,  1314,  1590,   542,   543,     7,     8,
    1228,   969,  1290,  1160,   693,   697,   555,  1517,  1040,  1118,
       7,     8,  1149,  1161,  1297,   782,   786,  1150,  1151,   403,
    1439,   863,   551,  1049,     9,  1673,  1152,  1678,  1123,   404,
     738,   403,   551,  1153,   299,  1154,  1155,   508,   551,   303,
     557,  1033,   551,  1503,  1156,   551,   721,   406,   816,   720,
     817,   818,   407,   819,   558,   821,   551,  1411,   558,   406,
     432,   551,   391,   822,   823,   551,  1172,  1712,   482,  1151,
     720,  1157,  1038,   494,   498,  1034,  1700,  1184,   399,   400,
     551,   401,   402,   684,   408,   409,  1022,  1155,   551,   551,
     551,   551,   644,   551,  1187,   975,   562,   676,   551,   405,
     937,   562,  1034,  1186,  1411,   937,    77,  1367,  1143,  1380,
    1583,  1034,   628,  -861,   892,  1638,   893,  1693,   785,   551,
      87,  1120,  1639,   654,   551,  1144,  1298,  1193,   646,   422,
     562,  1320,  1640,  1120,  1584,   577,   121,  -861,  1679,  1368,
    1408,  1584,   647,  1412,   558,   101,   551,   551,  -861,  1126,
     562,  1018,   685,  1035,   976,  1273,   655,  1369,   946,   397,
     894,   551,  1474,  1767,   562,   752,  1701,   551,  1145,  1382,
    1615,  1041,  1503,   562,   299,   299,   753,   694,   299,   303,
     303,  -171,   551,   303,   557,  1299,   987,  1421,   562,  1171,
    1576,  1295,   551,  1300,  1414,   790,   792,   562,  1780,   739,
    1401,   562,   411,  1158,  1321,   551,   562,  1504,   536,   538,
     731,  1042,  1523,   299,   644,   147,   148,   149,   303,   433,
    1680,  1360,   509,   552,   695,  1439,   476,   562,  1671,   554,
     930,  1320,   562,   803,  1119,  1218,   777,   889,   433,   665,
     782,   786,  -172,   551,   949,   486,  1049,  1049,   499,  1228,
     680,   559,   779,   950,   562,   562,   433,  1160,  1228,  1473,
     503,  1744,   506,  1495,   414,  1375,   412,  1161,  1002,   562,
     935,  1360,   415,   783,   787,   562,   677,  1214,  1045,  1019,
     416,  1021,  1272,   433,   678,  1411,  1215,   551,   778,   780,
     562,  1322,  1323,   776,  1324,  1075,  1076,  1077,   795,   486,
     562,  1325,   747,  1302,  1321,   729,   773,   413,   551,   772,
     755,  1326,  1216,   562,  1396,   895,   998,   551,  1788,   551,
    1791,   560,   299,  1327,   551,   551,   299,   303,   896,   721,
     897,   303,  1108,   551,   751,  1708,  1504,  1505,   944,   977,
    1498,   898,   899,   900,  1294,   901,   692,   902,   551,  1709,
    1482,   562,  1316,   299,   299,  1710,   551,  1552,   303,   303,
     559,   944,   815,   442,   559,   429,   858,  -171,  1279,   299,
     616,  1581,   970,   299,   303,   430,   121,   924,   303,   617,
    1499,   681,   682,  1737,  1050,   398,  1697,   396,   396,  1281,
     943,  1322,  1323,   683,  1324,   562,   690,   706,   978,   858,
     721,   711,   431,   396,   561,   702,  1219,   396,   707,   708,
    1584,  1326,   299,  1587,   714,   979,   562,   303,  1112,   945,
    1749,   299,  1553,  1327,  1221,   562,   303,   562,  -172,   558,
    1391,   983,   562,   562,   927,   790,   792,   790,  1475,   971,
     443,   562,   959,     9,  1782,   660,   859,   661,   999,   391,
     559,  1274,  1275,  1276,  1483,   392,   562,  1023,   848,   988,
    1127,  1128,   299,  1228,   562,  1131,  1376,   303,   736,   737,
    1765,   299,   955,  1220,   433,   741,   303,   722,  1388,   860,
     433,  1588,   299,   299,   299,   299,   418,   303,   303,   303,
     303,  1531,   630,   972,   477,  1169,   767,  1137,  1016,   766,
     768,   299,   973,  1117,   974,  1109,   303,   663,  1138,  1004,
    1107,  1109,   444,   445,   928,  1049,   477,  1648,  1493,   688,
     931,  1421,  1020,   934,  1049,    77,   780,   631,   477,   632,
     477,  1650,  1654,  1766,   582,  1049,   583,     7,     8,    87,
    1224,  1771,  1225,   980,   981,   653,   996,  1634,   657,   962,
    1750,  1471,   503,  1749,  1699,   671,   672,  1221,   982,   984,
     985,   524,   937,   503,   101,   630,   525,  1193,  1046,   664,
    1226,  1047,  1268,   698,   986,   423,   609,   565,  1660,   705,
    1413,   566,  1662,   710,  1613,  1110,   567,  1667,   715,  1685,
     424,  1111,   121,  1034,   610,   648,   843,  1649,   609,   849,
     631,   584,   632,  1221,  1222,   568,   585,  1050,  1050,   649,
     425,  1651,  1655,  1221,  1253,  1301,   610,   565,   299,   705,
    1380,   566,  1588,   303,   556,  1635,   567,  1623,   660,  1269,
     661,   727,   486,  1755,   147,   148,   149,  1381,   929,   611,
     618,  1269,   299,   299,  1622,   568,   391,   303,   303,  1221,
     526,   565,   392,   586,   619,   566,   756,  1510,  1661,   486,
     567,  1419,  1663,   662,  1262,   629,   937,  1668,   762,  1755,
     953,   954,   879,  1224,  1420,  1225,   396,   396,  1048,   568,
    1382,   630,   426,  1794,   612,  1754,  1760,  1451,   790,   428,
     663,  1638,   964,   965,   966,   437,   768,   299,  1639,  1223,
    1594,   630,   303,  1226,   569,  1598,  1414,   570,  1640,  1567,
    1343,  1344,  1049,   613,   938,   880,   631,   785,   632,  1224,
     881,  1225,   571,   808,  1691,   299,   614,   808,   418,  1224,
     303,  1225,   438,  1345,  1304,  1003,   631,  1754,   632,  1305,
    1756,   937,   795,  1760,   569,  1787,   609,   570,   572,  1226,
    1017,  1399,   664,   107,   439,   780,  1221,  1222,  1306,  1226,
     440,   615,   730,  1304,   610,  1224,   548,  1225,  1305,  1584,
     119,   503,     7,     8,   547,  1270,  1797,  1034,   569,  1221,
    1222,   570,   441,   399,   400,  1254,   401,   402,   572,   956,
     548,  1227,  1728,   403,  1729,  1226,  1457,   573,   937,  1307,
     885,   650,   674,   404,   405,   447,  1034,   675,  1808,   142,
    1468,  1113,   652,   477,   915,  -941,   477,   651,   919,   920,
     477,   406,   572,   477,   477,   925,   407,   609,  1114,   992,
     446,   477,  1584,   503,  1636,  1637,   503,   573,  1397,  -941,
     940,   477,  1221,  1222,  1115,   610,  1469,   477,  1163,  1143,
    -941,   477,  1223,  1461,   630,   478,   477,  1164,   408,   409,
     410,  1116,   486,  1703,  1809,  1633,  1144,  1706,  1721,  1422,
    1777,   573,  1224,   967,  1225,  1223,  1050,  1374,   500,     9,
    1677,   299,  1423,  1139,   501,  1050,   303,   477,  1584,   631,
    1278,   632,  1419,   688,  1140,  1224,  1050,  1225,   507,   477,
    1419,  1279,  1226,   577,   527,  1593,   107,   411,   937,  1204,
    1012,  1280,  1500,  1800,  1723,   396,  1726,   794,   510,  1501,
    1279,   796,  1281,   119,   511,  1226,  1731,   528,  1732,   107,
    1129,  1130,  1263,  1132,  1133,  1134,   477,  1264,  1223,  1135,
    1024,  1738,   880,  1304,  1433,   529,   119,   881,  1305,   299,
     299,   299,   530,  1039,   303,   303,   303,   418,  1224,   531,
    1225,    77,   142,   532,  1719,  1720,   544,  1438,   666,   667,
     668,   412,  1762,   564,  1572,    87,  1462,  1463,  1101,  1101,
    1105,  1105,  1236,   588,  1237,   142,   589,  1241,  1226,  1242,
     608,   477,   107,   826,   827,   477,   833,   834,  1677,   620,
     101,   835,   836,   607,  1046,  1386,  1387,  1047,   621,   119,
     622,   627,   413,   623,  1313,   635,  1664,  1665,   636,   644,
    1101,   637,   638,   639,   640,   533,   656,   658,   121,   669,
    1596,   659,   673,   688,  1136,   691,   699,   700,   414,   477,
     701,   712,  1616,   716,   718,   713,   415,   720,   142,   723,
     732,  1770,  1677,   724,   416,   725,   726,   728,   740,  1166,
     742,   758,   743,   744,   759,   865,   763,  1101,   477,   764,
     147,   148,   149,  1050,  1578,   781,   769,   799,  1101,   775,
     800,   809,   477,   812,   801,   802,   477,   477,   824,   810,
     837,   838,   839,   477,   840,   631,   855,   861,   864,   862,
     299,   477,   886,   887,   477,   303,   299,   891,   477,   890,
     914,   303,   916,   912,   913,   921,   922,   918,   299,   803,
    1395,   923,   926,   303,   933,   932,   936,   951,   391,   948,
     952,  1819,   991,  1820,   392,   483,  1000,   299,  1404,   994,
     997,   477,   303,  1828,  1001,  1014,   391,  1018,  1025,  1029,
     881,  1032,   392,  1121,   937,  1141,   299,  1426,  1142,  1167,
    1162,   303,  1168,   299,  1170,   391,   684,  1174,   303,  1175,
    1287,   392,  1177,   808,  1176,  1180,  1188,  1181,   477,  1182,
    1189,  1536,  1193,  1210,  1436,  1199,  1192,  1205,  1206,   519,
     396,  1440,  1209,   590,  1207,  1217,  1212,   396,  1263,  1213,
    1233,   591,   592,  1264,   593,  1234,  1235,  1248,   477,  1255,
    1265,   662,   594,  1101,  1286,  1288,   595,  1291,   596,  1292,
    1303,   477,  1336,   597,  1296,  1317,  1340,  1337,  1348,     9,
    1371,  1683,   767,  1379,  1378,  1349,  1384,  1350,  1393,  1389,
     598,  1390,  1687,  1578,  1351,  1689,   477,   477,   477,   477,
    1352,  1353,  1354,  1698,  1355,  1356,  1357,  1394,  1358,  1361,
    1362,  1363,  1364,  1101,   599,   600,   601,   602,   603,   604,
    1365,  1400,  1366,   540,   866,   867,   868,   869,   870,   871,
     872,   873,   874,   875,  1403,  1430,  1419,  1432,   477,  1435,
    1443,  1444,  1445,  1425,  1446,  1447,  1454,  1448,  1453,  1449,
    1441,  1455,   477,  1442,  1456,  1268,  1279,  1478,  1480,  1484,
    1486,  1487,  1492,  1488,  1513,  1101,  1494,  1497,  1507,  1520,
    1522,  1533,  1518,  1514,  1539,  1543,  1544,   477,  1545,  1551,
     705,  1546,  1557,  1547,  1548,   477,  1549,  1550,  1562,  1564,
    1101,  1560,   299,  1568,  1569,  1566,   477,   303,  1570,  1571,
    1574,  1575,  1618,  1620,  1580,  1592,  1591,  1597,  1600,  1689,
    1625,  1652,  1605,  1632,  1644,  1669,  1143,  1646,  1437,  1647,
    1653,  1656,  1657,  1645,  1658,  1659,  1674,  1682,  1468,  1688,
    1716,  1718,  1730,  1681,  1733,  1735,  1734,  1263,  1705,  1736,
    1745,  1740,  1264,  1747,  1761,  1746,   762,  1769,  1774,  1763,
    1792,  1741,  1764,  1772,  1773,  1785,  1012,  1775,  1789,  1793,
    1012,  1776,  1778,  1779,  1818,  1796,  1799,  1811,  1805,  1786,
    1810,  1822,  1610,  1611,  1612,  1824,  1397,  1783,  1803,  1821,
     808,  1812,  1825,  1476,  1815,  1817,  1827,   888,   477,  1173,
    1377,   477,  1124,   679,   545,   643,  1392,  1743,  1490,  1806,
    1781,  1013,   549,   811,  1312,   942,  1630,  1491,   546,  1472,
    1467,  1277,  1464,   717,  1405,  1409,  1415,  1424,   814,  1106,
     825,  1806,  1460,   845,   854,   846,  1434,  1798,   626,   968,
    1789,   477,  1795,   857,  1524,  1525,  1727,  1452,  1459,  1458,
    1508,  1528,  1101,  1512,   503,  1537,  1538,  1643,  1542,  1263,
    1315,  1511,  1339,  1642,  1264,  1148,  1509,  1385,  1559,  1666,
    1263,  1263,     0,   299,     0,  1264,  1264,     0,   303,     0,
       0,  1263,   483,     0,     0,     0,  1264,     0,     0,     0,
    1565,   477,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   745,   746,     0,     0,   748,   749,   750,
       0,     0,   754,     0,     0,   757,     0,  1582,     0,     0,
    1101,   765,     0,  1101,     0,     0,     0,     0,     0,     0,
     774,     0,     0,     0,  1595,     0,     0,     0,     0,  1599,
       0,  1711,     0,   477,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   797,   798,     0,     0,     0,   477,     0,
       0,     0,   804,   805,     0,     0,     0,     0,   477,     0,
       0,     0,  1722,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1263,  1628,  1629,
       0,     0,  1264,     0,     0,     0,   477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   852,   477,     0,     0,   852,     0,     0,
       0,     0,     0,     0,   477,     0,   299,     0,   477,     0,
       0,   303,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1263,     0,     0,     0,   477,  1264,
       0,   477,     0,     0,     0,     0,   917,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   477,   299,     0,     0,
       0,     0,   303,     0,     0,  1101,  1692,     0,  1694,     0,
    1696,   941,     0,     0,     0,     0,     0,  1704,     0,  1263,
       0,     0,     0,     0,  1264,     0,     0,   958,  1263,     0,
       0,   960,   961,  1264,   963,     0,     0,     0,     0,   477,
     477,   804,   477,   477,   477,     0,   477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   989,   990,     0,     0,   993,     0,  1725,
       0,  1725,     0,  1101,     0,  1101,     0,     0,   477,     0,
       0,   710,     0,   710,     0,     0,  1015,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1739,
       0,     0,  1742,     0,     0,   477,   798,     0,   477,  1101,
       0,   477,  1026,     0,     0,     0,     0,     0,     0,     0,
    1748,     0,   477,     0,     0,     0,     0,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1784,     0,     0,     0,     0,  1101,     0,  1101,     0,
       0,     0,     0,     0,     0,     0,   477,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1801,     0,  1125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1804,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1813,  1165,     0,     0,
       0,  1814,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1823,     0,     0,  1826,     0,     0,  1185,
       0,     0,     0,     0,     0,     0,  1190,  1191,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1208,     0,     0,
    1211,     0,     0,   477,   477,     0,   477,     0,   477,     0,
       0,     0,     0,     0,     0,   477,     0,     0,     0,     0,
       0,  1238,  1239,  1240,     0,  1243,  1244,  1245,  1246,  1247,
       0,     0,  1249,  1250,     0,  1251,  1252,     0,     0,     0,
    1256,  1257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1026,   477,     0,   477,
       0,   477,     0,   477,     0,     0,  1293,     0,     0,   477,
       0,   477,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   477,     0,     0,
     477,     0,     0,     0,     0,     0,     0,   477,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   477,
    1373,     0,     0,     0,     0,     0,     0,     0,     0,   477,
       0,     0,     0,     0,   477,     0,   477,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   477,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   477,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1398,     0,     0,
       0,     0,     0,     0,   477,     0,     0,  1402,     0,   477,
       0,     0,     0,  1406,  1407,     0,     0,     0,     0,     0,
       0,   477,     0,     0,   477,     0,     0,     0,     0,     0,
    1427,     0,     0,  1428,  1429,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1450,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1026,     0,     0,
       0,     0,     0,     0,     0,  1477,     0,  1479,     0,  1481,
       0,     0,  1485,     0,     0,     0,     0,  1489,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1573,     0,     0,     0,     0,     0,
       0,     0,  1577,  1579,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1398,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1601,  1602,  1603,  1604,     0,  1606,
    1607,     0,  1608,     0,  1609,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1617,     0,     0,     0,     0,  1619,     0,     0,     0,  1621,
       0,     0,     0,  1624,     0,  1626,     0,  1627,     0,     0,
       0,     0,     0,  1631,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1684,     0,     0,     0,     0,  1686,  1579,     0,     0,
       0,     0,     0,     0,  1690,     0,     0,     0,     0,  1695,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1707,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1713,
       0,  1714,     0,  1715,     0,     0,  1717,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1690,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1768,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1790,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -167,   785,     0,
       0,     0,     0,     0,  1802,     0,     0,     0,  1807,     0,
       0,     0,     0,  1790,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,  1807,
       0,    10,   387,  1816,    12,    13,    14,    15,    16,    17,
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
     103,     0,   104,   105,     0,   106,   107,   108,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,     0,   120,   121,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
       0,     0,     0,     0,     0,   128,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
     140,   141,   142,     0,   389,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,  -167,   785,   242,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     789,   387,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   388,    26,    27,    28,
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
       0,   104,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   389,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   785,   241,     0,     0,   242,   243,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   386,   387,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   388,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   389,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   785,
     241,     0,     0,   242,   243,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   386,   387,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   487,   388,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   488,   489,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   463,    80,    81,    82,    83,    84,   490,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   491,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   389,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   469,   470,   471,   173,   174,   472,   493,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,  1005,  1006,   242,
     243,     0,     0,     0,     0,     0,  1007,     0,     0,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     0,
     386,   387,     0,    12,    13,    14,   449,    16,    17,    18,
     450,    20,   451,   452,   453,   454,   388,    26,   455,    28,
      29,    30,     0,    31,    32,    33,    34,   456,    36,    37,
      38,    39,    40,    41,    42,   457,     0,    44,   458,    46,
     459,   460,    49,   461,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,   462,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     463,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   464,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,   109,   465,     0,
       0,     0,     0,   111,   112,   113,   114,   466,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,  1008,     0,   128,     0,   129,   130,   131,   132,
     467,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,     0,     0,   389,     0,   145,   146,     0,     0,     0,
     150,   151,   152,   153,   154,   155,     0,   157,     0,   159,
       0,     0,   162,   163,   164,   165,   166,   167,   468,   169,
     469,   470,   471,   173,   174,   472,   473,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   474,
       0,   190,   475,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     0,     0,     0,     0,   243,     1,
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
     102,   103,     0,   104,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,   242,
     243,     0,     0,     0,     0,   244,   245,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
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
       0,   104,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,   242,   243,     0,
     479,     0,     0,     0,   541,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   386,   387,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   388,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   104,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
     480,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   389,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,   479,     0,   242,   243,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   386,   387,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   388,    26,    27,
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
     103,     0,   104,   105,     0,   106,   107,   108,   109,   110,
       0,     0,     0,     0,   111,   112,   113,   114,   115,   116,
     117,   118,     0,   119,     0,   120,   121,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
       0,     0,     0,     0,     0,   128,     0,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,     0,     0,
     140,   141,   142,     0,   389,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,     0,   190,   191,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,   241,   479,     0,   242,   243,
       0,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   386,   387,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   487,
     388,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   488,   489,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   463,    80,    81,    82,    83,    84,
     490,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   491,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   389,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   516,   158,   517,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   469,   470,   471,   173,   174,   472,
     493,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,   479,
     518,   242,   243,     0,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   386,   387,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   487,   388,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   488,   489,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   463,    80,    81,
      82,    83,    84,   490,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,     0,   491,   105,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,     0,     0,     0,     0,
       0,   128,     0,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,     0,     0,   140,   141,   142,     0,
     389,     0,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   469,   470,   471,
     173,   174,   472,   493,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,     0,   190,   191,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     479,   241,     0,     0,   242,   243,     0,     0,     0,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   386,   387,
       0,    12,    13,    14,   449,    16,    17,    18,   450,    20,
     451,   452,   453,   454,   388,    26,   455,    28,    29,    30,
       0,    31,    32,    33,    34,   456,    36,    37,    38,    39,
      40,    41,    42,   457,     0,    44,   458,    46,   459,   460,
      49,   461,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   462,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   463,    80,
      81,    82,    83,    84,   490,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   464,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,     0,     0,
       0,     0,   106,     0,     0,   109,   465,     0,     0,     0,
       0,   111,   112,   113,   114,   466,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
     844,     0,   128,     0,   129,   130,   131,   132,   467,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,     0,
       0,   389,     0,   145,   146,     0,     0,     0,   150,   151,
     152,   153,   154,   155,     0,   157,     0,   159,     0,     0,
     162,   163,   164,   165,   166,   167,   468,   169,   469,   470,
     471,   173,   174,   472,   473,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   474,     0,   190,
     475,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     479,     0,     0,     0,     0,     0,   243,     0,     0,     5,
       6,     0,     0,     0,  1534,     0,     0,     0,   386,   387,
       0,    12,    13,    14,   449,    16,    17,    18,   450,    20,
     451,   452,   453,   454,   388,    26,   455,    28,    29,    30,
       0,    31,    32,    33,    34,   456,    36,    37,    38,    39,
      40,    41,    42,   457,     0,    44,   458,    46,   459,   460,
      49,   461,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   462,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   463,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   464,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   109,   465,     0,     0,     0,
       0,   111,   112,   113,   114,   466,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,  1535,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   467,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,     0,
       0,   389,     0,   145,   146,     0,     0,     0,   150,   151,
     152,   153,   154,   155,     0,   157,     0,   159,     0,     0,
     162,   163,   164,   165,   166,   167,   468,   169,   469,   470,
     471,   173,   174,   472,   473,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   474,     0,   190,
     475,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     479,     0,     0,     0,     0,     0,   243,     0,     0,     5,
       6,     0,     0,     0,     0,     0,     0,     0,   386,   387,
       0,    12,    13,    14,   449,    16,    17,    18,   450,    20,
     451,   452,   453,   454,   388,    26,   455,    28,    29,    30,
       0,    31,    32,    33,    34,   456,    36,    37,    38,    39,
      40,    41,    42,   457,     0,    44,   458,    46,   459,   460,
      49,   461,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   462,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   463,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   464,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   109,   465,     0,     0,     0,
       0,   111,   112,   113,   114,   466,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   467,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,     0,
       0,   389,     0,   145,   146,     0,     0,     0,   150,   151,
     152,   153,   154,   155,     0,   157,     0,   159,     0,     0,
     162,   163,   164,   165,   166,   167,   468,   169,   469,   470,
     471,   173,   174,   472,   473,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   474,     0,   190,
     475,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     504,   505,     0,     0,     0,     0,   243,     5,     6,     0,
       0,     0,     0,     0,     0,     0,   386,   387,     0,    12,
      13,    14,   449,    16,    17,    18,   450,    20,   451,   452,
     453,   454,   388,    26,   455,    28,    29,    30,     0,    31,
      32,    33,    34,   456,    36,    37,    38,    39,    40,    41,
      42,   457,     0,    44,   458,    46,   459,   460,    49,   461,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,   462,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   463,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   464,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   109,   465,     0,     0,     0,     0,   111,
     112,   113,   114,   466,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   467,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,     0,     0,   389,
       0,   145,   146,     0,     0,     0,   150,   151,   152,   153,
     154,   155,     0,   157,     0,   159,     0,     0,   162,   163,
     164,   165,   166,   167,   468,   169,   469,   470,   471,   173,
     174,   472,   473,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   474,     0,   190,   475,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       0,     0,     0,     0,   243,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   104,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,     0,   242,   243,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     386,   387,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   388,    26,    27,    28,
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
       0,   104,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,   719,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   389,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,   242,   243,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   386,   387,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   388,    26,
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
     102,   103,     0,   104,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,   480,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   389,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,   242,
     243,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   386,   387,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,  1258,
     388,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,  1259,  1260,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   104,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,   480,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   389,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
    1261,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,   242,   243,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   386,   387,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   388,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   389,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,     0,   242,   243,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   104,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   389,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,     0,   242,   243,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
      10,   387,     0,    12,    13,    14,    15,    16,    17,    18,
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
       0,   104,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   389,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,   242,   243,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   789,   387,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   388,    26,
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
     102,   103,     0,   104,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   389,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,   242,
     243,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   386,   387,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   487,
     388,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   488,   489,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   463,    80,    81,    82,    83,    84,
     490,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,   850,     0,    98,    99,
     100,   101,   102,   103,     0,   491,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,   851,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   389,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   469,   470,   471,   173,   174,   472,
     493,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,   242,   243,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   386,   387,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   487,   388,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   488,   489,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   463,    80,    81,    82,
      83,    84,   490,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,   850,     0,
      98,    99,   100,   101,   102,   103,     0,   491,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,   856,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   389,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   469,   470,   471,   173,
     174,   472,   493,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,     0,   242,   243,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   386,   387,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,  1258,   388,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,  1259,  1260,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   104,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   389,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,  1261,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,     0,   242,   243,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     386,   387,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   487,   388,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     488,   489,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     463,    80,    81,    82,    83,    84,   490,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   491,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,   492,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   389,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     469,   470,   471,   173,   174,   472,   493,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,   242,   243,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   386,   387,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   487,   388,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   488,   489,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   463,    80,    81,    82,    83,    84,   490,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   491,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,   497,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   389,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   469,   470,   471,   173,   174,   472,   493,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,   242,
     243,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   386,   387,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   487,
     388,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   488,   489,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   463,    80,    81,    82,    83,    84,
     490,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   491,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   389,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   469,   470,   471,   173,   174,   472,
     493,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   535,   241,     0,
       0,   242,   243,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   386,   387,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   487,   388,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   488,   489,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   463,    80,    81,    82,
      83,    84,   490,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   491,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   389,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   469,   470,   471,   173,
     174,   472,   493,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,   537,     0,   242,   243,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   386,   387,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   487,   388,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   488,   489,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   463,    80,
      81,    82,    83,    84,   490,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   491,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   389,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   469,   470,
     471,   173,   174,   472,   493,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   539,   242,   243,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     386,   387,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   487,   388,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     488,   489,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     463,    80,    81,    82,    83,    84,   490,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   491,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,   842,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   389,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     469,   470,   471,   173,   174,   472,   493,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,   242,   243,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   386,   387,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   487,   388,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   488,   489,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   463,    80,    81,    82,    83,    84,   490,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,  1372,     0,    98,    99,   100,   101,
     102,   103,     0,   491,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   389,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   469,   470,   471,   173,   174,   472,   493,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,   242,
     243,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   386,   387,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   487,
     388,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   488,   489,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   463,    80,    81,    82,    83,    84,
     490,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   491,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   389,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   469,   470,   471,   173,   174,   472,
     493,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,   242,   243,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   386,   387,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   487,   388,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   488,   489,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   463,    80,    81,    82,
      83,    84,   490,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   491,   105,     0,
       0,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   389,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   469,   470,   471,   173,
     174,   472,   493,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,     0,   242,   243,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   386,   387,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   452,    23,   454,   388,    26,   455,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   457,     0,    44,    45,    46,   459,   460,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   463,    80,
      81,    82,    83,    84,   490,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   464,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   491,
     105,     0,   106,   107,   624,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   625,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   389,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     0,   157,     0,   159,     0,     0,
     162,   163,   164,   165,   166,   167,   468,   169,   469,   470,
     471,   173,   174,   472,   473,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   474,     0,   190,
     475,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,     0,     0,   243,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     386,   387,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   452,    23,   454,   388,    26,   455,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   457,     0,    44,    45,    46,
     459,   460,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     463,    80,    81,    82,    83,    84,   490,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   464,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   491,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   389,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     0,   157,     0,   159,
       0,     0,   162,   163,   164,   165,   166,   167,   468,   169,
     469,   470,   471,   173,   174,   472,   473,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   474,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,     0,   243,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   386,   387,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   452,    23,   454,   388,    26,
     455,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   457,     0,    44,
      45,    46,   459,   460,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   463,    80,    81,    82,    83,    84,   490,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   464,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   491,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   389,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     0,   157,
       0,   159,     0,     0,   162,   163,   164,   165,   166,   167,
     468,   169,   469,   470,   471,   173,   174,   472,   473,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   474,     0,   190,   475,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,     0,     0,
     243,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   386,   387,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   452,    23,   454,
     388,    26,   455,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   457,
       0,    44,    45,    46,   459,   460,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   463,    80,    81,    82,    83,    84,
     490,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   464,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   491,   105,     0,     0,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   389,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
       0,   157,     0,   159,     0,     0,   162,   163,   164,   165,
     166,   167,   468,   169,   469,   470,   471,   173,   174,   472,
     473,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   474,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
       0,     0,   243,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   386,   387,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   452,
      23,   454,   388,    26,   455,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   457,     0,    44,    45,    46,   459,   460,    49,   461,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   463,    80,    81,    82,
      83,    84,   490,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   464,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   491,   105,     0,
     106,   107,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   389,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,     0,   512,     0,   513,     0,     0,   162,   163,
     164,   165,   166,   167,   468,   169,   469,   470,   471,   173,
     174,   472,   473,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   474,     0,   190,   475,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   514,     0,   243,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   386,   387,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   452,    23,   454,   388,    26,   455,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   457,     0,    44,    45,    46,   459,   460,
      49,   461,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   463,    80,
      81,    82,    83,    84,   490,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   464,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   491,
     105,     0,   106,   107,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   389,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,     0,   521,     0,   159,     0,     0,
     162,   163,   164,   165,   166,   167,   468,   169,   469,   470,
     471,   173,   174,   472,   473,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   474,     0,   190,
     475,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   522,     0,   243,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     386,   387,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   452,    23,   454,   388,    26,   455,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   457,     0,    44,    45,    46,
     459,   460,    49,   461,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     463,    80,    81,    82,    83,    84,   490,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   464,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   491,   105,     0,   106,   107,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,     0,     0,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   389,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,     0,   157,     0,   159,
       0,     0,   162,   163,   164,   165,   166,   167,   468,   169,
     469,   470,   471,   173,   174,   472,   473,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   474,
       0,   190,   475,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,     0,     0,   243,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   386,   387,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   452,    23,   454,   388,    26,
     455,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   457,     0,    44,
      45,    46,   459,   460,    49,   461,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   463,    80,    81,    82,    83,    84,   490,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   464,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   491,   105,     0,   106,   107,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,     0,     0,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   389,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,     0,   995,
       0,   159,     0,     0,   162,   163,   164,   165,   166,   167,
     468,   169,   469,   470,   471,   173,   174,   472,   473,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   474,     0,   190,   475,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     5,     6,     0,
     243,     0,     0,     0,     0,     0,   386,   387,     0,    12,
      13,    14,  1061,    16,    17,    18,   450,  1062,  1063,   452,
    1064,   454,   388,    26,   455,    28,  1065,    30,     0,    31,
      32,    33,    34,  1066,    36,  1067,  1068,    39,    40,    41,
      42,   457,     0,    44,  1069,    46,   459,   460,    49,   461,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,  1070,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   463,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   464,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,  1071,     0,     0,     0,
    1072,     0,     0,   109,   465,     0,     0,     0,     0,   111,
     112,   113,   114,   466,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,  1529,   126,   127,     0,     0,     0,     0,  1530,     0,
     128,     0,   129,   130,   131,   132,   467,   134,   135,   136,
     137,   138,   139,     0,     0,  1073,   141,     0,     0,   389,
       0,   145,   146,     0,     0,     0,   150,   151,   152,   153,
     154,   155,     0,  1074,     0,   159,     0,     0,   162,   163,
     164,   165,   166,   167,   468,   169,   469,   470,   471,   173,
     174,   472,   473,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   474,     0,   190,   475,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       5,     6,     0,     0,   243,  1075,  1076,  1077,  1078,   386,
     387,     0,    12,    13,    14,  1061,    16,    17,    18,   450,
    1062,  1063,   452,  1064,   454,   388,    26,   455,    28,  1065,
      30,     0,    31,    32,    33,    34,  1066,    36,  1067,  1068,
      39,    40,    41,    42,   457,     0,    44,  1069,    46,   459,
     460,    49,   461,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,  1070,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   463,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   464,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,  1071,
       0,     0,     0,  1122,     0,     0,   109,   465,     0,     0,
       0,     0,   111,   112,   113,   114,   466,   116,   117,   118,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
       0,     0,     0,   125,  1359,   126,   127,     0,     0,     0,
       0,     0,     0,   128,     0,   129,   130,   131,   132,   467,
     134,   135,   136,   137,   138,   139,     0,     0,   140,   141,
       0,     0,   389,     0,   145,   146,     0,     0,     0,   150,
     151,   152,   153,   154,   155,     0,  1074,     0,   159,     0,
       0,   162,   163,   164,   165,   166,   167,   468,   169,   469,
     470,   471,   173,   174,   472,   473,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   474,     0,
     190,   475,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,     5,     6,     0,     0,   243,  1075,  1076,
    1077,  1078,   386,   387,     0,    12,    13,    14,  1061,    16,
      17,    18,   450,  1062,  1063,   452,  1064,   454,   388,    26,
     455,    28,  1065,    30,     0,    31,    32,    33,    34,  1066,
      36,  1067,  1068,    39,    40,    41,    42,   457,     0,    44,
    1069,    46,   459,   460,    49,   461,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1070,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   463,    80,    81,    82,    83,    84,  1416,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   464,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,  1071,     0,     0,     0,  1072,     0,     0,   109,
     465,     0,     0,     0,     0,   111,   112,   113,   114,   466,
     116,   117,   118,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   467,   134,   135,   136,   137,   138,   139,     0,
       0,  1073,   141,     0,     0,   389,     0,   145,   146,     0,
       0,     0,   150,   151,   152,   153,   154,   155,     0,  1074,
       0,   159,     0,     0,   162,   163,   164,   165,   166,   167,
     468,   169,   469,   470,   471,   173,   174,   472,   473,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   474,     0,   190,   475,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     5,     6,     0,     0,
     243,  1075,  1076,  1077,  1078,   386,   387,     0,    12,    13,
      14,  1061,    16,    17,    18,   450,  1062,  1063,   452,  1064,
     454,   388,    26,   455,    28,  1065,    30,     0,    31,    32,
      33,    34,  1066,    36,  1067,  1068,    39,    40,    41,    42,
     457,     0,    44,  1069,    46,   459,   460,    49,   461,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
    1070,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   463,    80,    81,    82,    83,
      84,  1585,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   464,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,  1071,     0,     0,     0,  1072,
       0,     0,   109,   465,     0,     0,     0,     0,   111,   112,
     113,   114,   466,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,     0,     0,     0,     0,     0,   128,
       0,   129,   130,   131,   132,   467,   134,   135,   136,   137,
     138,   139,     0,     0,  1073,   141,     0,     0,   389,     0,
     145,   146,     0,     0,     0,   150,   151,   152,   153,   154,
     155,     0,  1074,     0,   159,     0,     0,   162,   163,   164,
     165,   166,   167,   468,   169,   469,   470,   471,   173,   174,
     472,   473,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   474,     0,   190,   475,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     0,     0,     5,
       6,     0,     0,   243,  1075,  1076,  1077,  1078,   386,   387,
       0,    12,    13,    14,  1061,    16,    17,    18,   450,  1062,
    1063,   452,  1064,   454,   388,    26,   455,    28,  1065,    30,
       0,    31,    32,    33,    34,  1066,    36,  1067,  1068,    39,
      40,    41,    42,   457,     0,    44,  1069,    46,   459,   460,
      49,   461,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,  1070,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   463,    80,
      81,    82,    83,    84,  1589,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   464,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,  1071,     0,
       0,     0,  1072,     0,     0,   109,   465,     0,     0,     0,
       0,   111,   112,   113,   114,   466,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   467,   134,
     135,   136,   137,   138,   139,     0,     0,  1073,   141,     0,
       0,   389,     0,   145,   146,     0,     0,     0,   150,   151,
     152,   153,   154,   155,     0,  1074,     0,   159,     0,     0,
     162,   163,   164,   165,   166,   167,   468,   169,   469,   470,
     471,   173,   174,   472,   473,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   474,     0,   190,
     475,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     5,     6,     0,     0,   243,  1075,  1076,  1077,
    1078,   386,   387,     0,    12,    13,    14,  1061,    16,    17,
      18,   450,  1062,  1063,   452,  1064,   454,   388,    26,   455,
      28,  1065,    30,     0,    31,    32,    33,    34,  1066,    36,
    1067,  1068,    39,    40,    41,    42,   457,     0,    44,  1069,
      46,   459,   460,    49,   461,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,  1070,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   463,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   464,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,  1071,     0,     0,     0,  1072,     0,     0,   109,   465,
       0,     0,     0,     0,   111,   112,   113,   114,   466,   116,
     117,   118,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
       0,     0,     0,     0,     0,   128,     0,   129,   130,   131,
     132,   467,   134,   135,   136,   137,   138,   139,     0,     0,
    1073,   141,     0,     0,   389,     0,   145,   146,     0,     0,
       0,   150,   151,   152,   153,   154,   155,     0,  1074,     0,
     159,     0,     0,   162,   163,   164,   165,   166,   167,   468,
     169,   469,   470,   471,   173,   174,   472,   473,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     474,     0,   190,   475,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     5,     6,     0,     0,   243,
    1075,  1076,  1077,  1078,   386,   387,     0,    12,    13,    14,
    1061,    16,    17,    18,   450,  1062,  1063,   452,  1064,   454,
     388,    26,   455,    28,  1065,    30,     0,    31,    32,    33,
      34,  1066,    36,  1067,  1068,    39,    40,    41,    42,   457,
       0,    44,  1069,    46,   459,   460,    49,   461,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,  1070,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   463,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   464,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,  1071,     0,     0,     0,  1122,     0,
       0,   109,   465,     0,     0,     0,     0,   111,   112,   113,
     114,   466,   116,   117,   118,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   467,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,     0,     0,   389,     0,   145,
     146,     0,     0,     0,   150,   151,   152,   153,   154,   155,
       0,  1074,     0,   159,     0,     0,   162,   163,   164,   165,
     166,   167,   468,   169,   469,   470,   471,   173,   174,   472,
     473,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   474,     0,   190,   475,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     5,     6,
       0,     0,   243,  1075,  1076,  1077,  1078,   386,   387,     0,
      12,    13,    14,   449,    16,    17,    18,   450,    20,   451,
     452,   453,   454,   388,    26,   455,    28,    29,    30,     0,
      31,    32,    33,    34,   456,    36,    37,    38,    39,    40,
      41,    42,   457,     0,    44,   458,    46,   459,   460,    49,
     461,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,   462,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   463,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     464,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   109,   465,     0,     0,     0,     0,
     111,   112,   113,   114,   466,   116,   117,   118,     0,     0,
       0,     0,     0,     0,     0,   122,   123,   124,     0,     0,
       0,   125,  1526,   126,   127,     0,     0,     0,     0,  1527,
       0,   128,     0,   129,   130,   131,   132,   467,   134,   135,
     136,   137,   138,   139,     0,     0,   140,   141,     0,     0,
     389,     0,   145,   146,     0,     0,     0,   150,   151,   152,
     153,   154,   155,     0,   157,     0,   159,     0,     0,   162,
     163,   164,   165,   166,   167,   468,   169,   469,   470,   471,
     173,   174,   472,   473,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   474,     0,   190,   475,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     5,
       6,     0,     0,     0,     0,   243,     0,     0,   386,   387,
       0,    12,    13,    14,   449,    16,    17,    18,   450,    20,
     451,   452,   453,   454,   388,    26,   455,    28,    29,    30,
       0,    31,    32,    33,    34,   456,    36,    37,    38,    39,
      40,    41,    42,   457,     0,    44,   458,    46,   459,   460,
      49,   461,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   462,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   463,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   464,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   109,   465,     0,     0,     0,
       0,   111,   112,   113,   114,   466,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,  1540,   126,   127,     0,     0,     0,     0,
    1541,     0,   128,     0,   129,   130,   131,   132,   467,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,     0,
       0,   389,     0,   145,   146,     0,     0,     0,   150,   151,
     152,   153,   154,   155,     0,   157,     0,   159,     0,     0,
     162,   163,   164,   165,   166,   167,   468,   169,   469,   470,
     471,   173,   174,   472,   473,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   474,     0,   190,
     475,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       5,     6,     0,     0,     0,     0,   243,     0,     0,   386,
     387,     0,    12,    13,    14,   449,    16,    17,    18,   450,
      20,   451,   452,   453,   454,   388,    26,   455,    28,    29,
      30,     0,    31,    32,    33,    34,   456,    36,    37,    38,
      39,    40,    41,    42,   457,     0,    44,   458,    46,   459,
     460,    49,   461,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,   462,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   463,
      80,    81,    82,    83,    84,  1289,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   464,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   109,   465,     0,     0,
       0,     0,   111,   112,   113,   114,   466,   116,   117,   118,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,     0,     0,
       0,     0,     0,   128,     0,   129,   130,   131,   132,   467,
     134,   135,   136,   137,   138,   139,     0,     0,   140,   141,
       0,     0,   389,     0,   145,   146,     0,     0,     0,   150,
     151,   152,   153,   154,   155,     0,   157,     0,   159,     0,
       0,   162,   163,   164,   165,   166,   167,   468,   169,   469,
     470,   471,   173,   174,   472,   473,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   474,     0,
     190,   475,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     5,     6,     0,     0,     0,     0,   243,     0,     0,
     386,   387,     0,    12,    13,    14,   449,    16,    17,    18,
     450,    20,   451,   452,   453,   454,   388,    26,   455,    28,
      29,    30,     0,    31,    32,    33,    34,   456,    36,    37,
      38,    39,    40,    41,    42,   457,     0,    44,   458,    46,
     459,   460,    49,   461,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,   462,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     463,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   464,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,   109,   465,     0,
       0,     0,     0,   111,   112,   113,   114,   466,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     467,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,     0,     0,   389,     0,   145,   146,     0,     0,     0,
     150,   151,   152,   153,   154,   155,     0,   157,     0,   159,
       0,     0,   162,   163,   164,   165,   166,   167,   468,   169,
     469,   470,   471,   173,   174,   472,   473,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   474,
       0,   190,   475,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     5,     6,     0,     0,     0,     0,   243,     0,
       0,   386,   387,     0,    12,    13,    14,     0,    16,    17,
      18,   450,     0,     0,   452,   453,     0,   388,    26,   455,
      28,     0,    30,     0,    31,    32,    33,    34,     0,    36,
       0,     0,    39,    40,    41,    42,   457,     0,    44,     0,
      46,     0,     0,    49,   461,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,     0,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   463,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   464,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,     0,     0,     0,     0,     0,     0,     0,   109,   465,
       0,     0,     0,     0,   111,   112,   113,   114,   466,   116,
     117,   118,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
       0,     0,     0,     0,     0,   128,     0,   129,   130,   131,
     132,   467,   134,   135,   136,   137,   138,   139,     0,     0,
       0,   141,     0,     0,   389,     0,   145,   146,     0,     0,
       0,   150,   151,   152,   153,   154,   155,     0,     0,     0,
     159,     0,     0,   162,   163,   164,   165,   166,   167,   468,
     169,   469,   470,   471,   173,   174,     0,   473,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     474,     0,   190,   475,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     0,     0,     0,     0,   243
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     176,   611,   303,   627,   156,   283,   949,   119,   160,    10,
     334,     1,     2,     3,   936,   808,  1200,   397,   398,     1,
       2,     3,     4,   808,   191,     1,     2,     3,     4,   705,
     554,   555,   251,   399,   158,   630,  1216,   837,   838,   715,
     612,   613,   614,   615,   552,   553,   554,   555,     1,  1283,
    1284,   252,  1419,     1,  1047,  1422,   244,   245,    27,    28,
     971,   733,  1032,   913,   430,   431,   267,  1340,    57,   863,
      27,    28,    40,   913,    37,   552,   553,    45,    46,    48,
    1229,   652,     1,   824,    30,  1562,    54,   120,   879,    58,
       8,    48,     1,    61,   104,    63,    64,    31,     1,   104,
     274,    37,     1,    98,    72,     1,   109,    76,   590,   123,
     592,   593,    81,   595,   392,   597,     1,   102,   396,    76,
     120,     1,   104,   605,   606,     1,   926,  1617,   104,    46,
     123,    99,   808,   105,   106,    98,    95,   937,    38,    39,
       1,    41,    42,   120,   113,   114,   115,    64,     1,     1,
       1,     1,    30,     1,   939,   133,   109,   114,     1,    59,
      96,   109,    98,   144,   102,    96,   112,   146,    98,    98,
     188,    98,   155,   123,    56,   275,    58,   188,     1,     1,
     126,   876,   282,   171,     1,   115,   149,   102,   184,   162,
     109,    98,   292,   888,   212,   496,   179,   147,   231,   178,
     115,   212,   198,   188,   482,   151,     1,     1,   158,   885,
     109,    34,   189,   149,   192,   115,   204,   196,   149,   158,
     102,     1,   149,  1713,   109,   239,   185,     1,   158,   158,
    1464,   220,    98,   109,   244,   245,   239,   115,   248,   244,
     245,     0,     1,   248,   418,  1038,   239,  1431,   109,   925,
     188,  1036,     1,  1038,  1197,   779,   780,   109,  1735,   177,
    1182,   109,   162,   231,   171,     1,   109,   262,   240,   241,
     189,   260,   189,   283,    30,   221,   222,   223,   283,   279,
     313,  1072,   216,   192,   162,  1434,    85,   109,  1561,   192,
     189,    98,   109,   571,   865,   967,   192,   663,   279,   411,
     777,   778,     0,     1,   189,   104,  1047,  1048,   107,  1220,
     422,   283,   192,   189,   109,   109,   279,  1167,  1229,  1289,
     119,  1688,   121,  1316,   293,  1119,   226,  1167,   189,   109,
     696,  1122,   301,   552,   553,   109,   293,   189,   820,   192,
     309,   192,   192,   279,   301,   102,   189,     1,   549,   550,
     109,   258,   259,   541,   261,   323,   324,   325,   559,   158,
     109,   268,   514,  1039,   171,   187,   319,   267,     1,   317,
     522,   278,   189,   109,  1174,   257,   109,     1,  1745,     1,
    1747,   109,   392,   290,     1,     1,   396,   392,   270,   109,
     272,   396,   187,     1,   518,   189,   262,   263,   109,   133,
     220,   283,   284,   285,   149,   287,   162,   289,     1,   189,
     149,   109,   155,   423,   424,   189,     1,   138,   423,   424,
     392,   109,   589,    78,   396,    25,   109,   186,   108,   439,
     203,   188,   132,   443,   439,    35,   179,   186,   443,   212,
     260,   423,   424,  1677,   824,   158,   188,   423,   424,   129,
     186,   258,   259,   425,   261,   109,   428,   439,   192,   109,
     109,   443,    62,   439,   192,   437,   132,   443,   440,   441,
     212,   278,   482,   120,   446,    96,   109,   482,   858,   190,
       5,   491,   203,   290,     9,   109,   491,   109,   186,   767,
    1166,    96,   109,   109,   109,  1019,  1020,  1021,  1291,   199,
     155,   109,   190,    30,  1738,    46,   189,    48,   241,   491,
     482,  1019,  1020,  1021,  1299,   491,   109,   795,   630,   239,
     886,   887,   532,  1434,   109,   891,  1121,   532,   500,   501,
    1710,   541,   186,   199,   279,   507,   541,   186,  1162,   189,
     279,   188,   552,   553,   554,   555,   547,   552,   553,   554,
     555,  1351,   121,   186,    85,   921,   532,   269,   777,   531,
     532,   571,   186,   139,   186,   109,   571,   108,   280,   186,
     186,   109,   227,   228,   189,  1316,   107,   109,   186,   155,
     692,  1765,   783,   695,  1325,   112,   787,   156,   119,   158,
     121,   109,   109,   186,     1,  1336,     3,    27,    28,   126,
     125,   186,   127,   224,   225,   404,   758,    53,   407,   721,
     135,  1287,   411,     5,   120,   414,   415,     9,   239,   224,
     225,   231,    96,   422,   151,   121,   236,   102,   155,   170,
     155,   158,   155,   432,   239,   155,   160,    43,   109,   438,
     115,    47,   109,   442,   155,   189,    52,   109,   447,  1571,
     155,   189,   179,    98,   178,   184,   628,   189,   160,   631,
     156,    68,   158,     9,    10,    71,    73,  1047,  1048,   198,
     155,   189,   189,     9,   243,   149,   178,    43,   688,   478,
      98,    47,   188,   688,   114,   131,    52,  1480,    46,   212,
      48,   490,   491,    29,   221,   222,   223,   115,   688,   201,
     138,   212,   712,   713,   149,    71,   688,   712,   713,     9,
     320,    43,   688,   120,   152,    47,    96,  1327,   189,   518,
      52,   102,   189,    81,  1002,  1049,    96,   189,   527,    29,
     712,   713,    96,   125,   115,   127,   712,   713,   265,    71,
     158,   121,   158,   135,   119,  1700,  1701,   243,  1272,   158,
     108,   275,   724,   725,   726,   155,   728,   767,   282,   105,
    1432,   121,   767,   155,   170,  1437,  1709,   173,   292,  1393,
     253,   254,  1513,   148,   144,   139,   156,     1,   158,   125,
     144,   127,   188,   582,  1584,   795,   161,   586,   789,   125,
     795,   127,   120,   276,    55,   767,   156,  1752,   158,    60,
     136,    96,  1003,  1758,   170,   188,   160,   173,   214,   155,
      34,  1177,   170,   159,   155,  1016,     9,    10,    79,   155,
     158,   196,   188,    55,   178,   125,    50,   127,    60,   212,
     176,   630,    27,    28,    34,  1011,   136,    98,   170,     9,
      10,   173,   158,    38,    39,   997,    41,    42,   214,   144,
      50,   197,  1652,    48,  1654,   155,   188,   263,    96,   120,
     659,   168,   139,    58,    59,   120,    98,   144,   188,   215,
     108,   150,   403,   404,   673,   123,   407,   184,   677,   678,
     411,    76,   214,   414,   415,   684,    81,   160,   167,    96,
     155,   422,   212,   692,  1504,  1505,   695,   263,  1176,   147,
     699,   432,     9,    10,   150,   178,   144,   438,   305,    98,
     158,   442,   105,  1279,   121,   120,   447,   314,   113,   114,
     115,   167,   721,  1595,   188,  1497,   115,  1599,   201,   102,
    1730,   263,   125,   732,   127,   105,  1316,   139,   155,    30,
    1564,   951,   115,   269,   155,  1325,   951,   478,   212,   156,
      97,   158,   102,   155,   280,   125,  1336,   127,   155,   490,
     102,   108,   155,  1264,   120,   115,   159,   162,    96,   951,
     769,   118,   274,   115,  1648,   951,  1650,   556,   219,   281,
     108,   560,   129,   176,   219,   155,  1660,   247,  1662,   159,
     130,   131,  1002,   283,   284,   285,   527,  1002,   105,   289,
     799,  1677,   139,    55,   197,   247,   176,   144,    60,  1019,
    1020,  1021,   248,   812,  1019,  1020,  1021,  1018,   125,   158,
     127,   112,   215,   155,  1634,  1635,     0,   197,   227,   228,
     229,   226,  1704,   192,  1400,   126,   130,   131,   837,   838,
     839,   840,   238,   169,   240,   215,    94,   238,   155,   240,
     101,   582,   159,   609,   610,   586,   616,   617,  1682,    51,
     151,   618,   619,   255,   155,  1160,  1161,   158,   202,   176,
     103,   195,   267,   104,  1046,   147,  1552,  1553,   158,    30,
     879,   186,   186,   186,   186,  1261,    48,   154,   179,   252,
     197,   120,   310,   155,   893,     1,   120,   144,   293,   630,
     109,   155,  1468,   144,   186,   155,   301,   123,   215,   123,
      36,  1721,  1736,   158,   309,   158,   158,   155,    17,   918,
     216,   237,    30,    30,   236,   656,   192,   926,   659,   192,
     221,   222,   223,  1513,  1412,     3,   251,   120,   937,   239,
     170,   290,   673,   120,   172,   172,   677,   678,    72,   290,
     237,    96,    96,   684,    96,   156,   151,   109,    30,   109,
    1170,   692,   162,   162,   695,  1170,  1176,   134,   699,   129,
     305,  1176,   144,   252,    96,   134,   186,   120,  1188,  1457,
    1170,   186,    96,  1188,    46,    98,    98,   155,  1170,   186,
     186,  1815,    96,  1817,  1170,   104,   144,  1207,  1188,   243,
     237,   732,  1207,  1827,   192,   239,  1188,    34,   172,   120,
     144,   109,  1188,   134,    96,    30,  1226,  1207,   292,    96,
     233,  1226,   305,  1233,   155,  1207,   120,    96,  1233,   186,
    1029,  1207,   134,  1032,   200,   162,   155,   134,   769,    98,
     120,  1353,   102,   192,  1226,   102,   149,   186,   186,   158,
    1226,  1233,   144,   134,   155,    36,   123,  1233,  1268,   123,
     155,   142,   143,  1268,   145,    30,    30,    98,   799,   120,
     251,    81,   153,  1072,   109,   109,   157,   129,   159,   120,
     260,   812,   264,   164,   149,   291,   273,   266,   158,    30,
     146,  1569,  1268,    30,   292,   158,    30,   158,   233,   293,
     181,   312,  1580,  1581,   158,  1583,   837,   838,   839,   840,
     158,   158,   158,  1591,   158,   158,   158,   192,   158,   158,
     158,   158,   158,  1122,   205,   206,   207,   208,   209,   210,
     158,   109,   158,   242,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   144,   200,   102,   134,   879,     7,
     239,   239,   239,   186,   239,    98,   158,   322,   188,   243,
     192,   158,   893,   192,   158,   155,   108,   149,   129,   149,
     149,   120,    79,   120,   149,  1174,   189,   256,   256,    80,
     189,   189,   292,   288,   189,   189,   189,   918,   189,    30,
    1189,   189,    30,   189,   189,   926,   189,   189,   109,   172,
    1199,   277,  1412,   186,   128,   263,   937,  1412,   128,    98,
     186,   188,   144,   149,   188,   186,   188,   186,   186,  1697,
     149,    96,   322,   186,   155,    30,    98,   189,  1227,   189,
     189,   189,   189,   286,   189,   189,   189,   172,   108,    96,
     149,    55,    96,   293,    30,   109,   271,  1457,   199,   109,
      96,   120,  1457,    96,   199,   188,  1255,   120,   146,   199,
     188,   231,   200,   189,   189,   120,  1265,   189,  1746,    95,
    1269,   189,   189,   189,   188,   185,   199,   299,   120,   231,
     120,   293,  1454,  1455,  1456,   231,  1764,   311,   311,   201,
    1289,   311,   120,  1292,   312,   312,   312,   662,  1029,   927,
    1123,  1032,   880,   418,   248,   398,  1167,  1682,  1307,  1787,
    1736,   770,   251,   586,  1044,   701,  1490,  1308,   248,  1288,
    1286,  1025,  1283,   478,  1189,  1194,  1197,  1202,   588,   840,
     608,  1809,  1269,   630,   633,   630,  1220,  1758,   329,   733,
    1818,  1072,  1752,   636,  1349,  1349,  1650,  1255,  1266,  1265,
    1325,  1350,  1351,  1336,  1353,  1354,  1355,  1513,  1357,  1569,
    1048,  1329,  1057,  1510,  1569,   912,  1326,  1145,  1383,  1555,
    1580,  1581,    -1,  1583,    -1,  1580,  1581,    -1,  1583,    -1,
      -1,  1591,   491,    -1,    -1,    -1,  1591,    -1,    -1,    -1,
    1389,  1122,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   512,   513,    -1,    -1,   516,   517,   518,
      -1,    -1,   521,    -1,    -1,   524,    -1,  1416,    -1,    -1,
    1419,   530,    -1,  1422,    -1,    -1,    -1,    -1,    -1,    -1,
     539,    -1,    -1,    -1,  1433,    -1,    -1,    -1,    -1,  1438,
      -1,  1613,    -1,  1174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   562,   563,    -1,    -1,    -1,  1189,    -1,
      -1,    -1,   571,   572,    -1,    -1,    -1,    -1,  1199,    -1,
      -1,    -1,  1644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1697,  1487,  1488,
      -1,    -1,  1697,    -1,    -1,    -1,  1227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   632,  1255,    -1,    -1,   636,    -1,    -1,
      -1,    -1,    -1,    -1,  1265,    -1,  1746,    -1,  1269,    -1,
      -1,  1746,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1764,    -1,    -1,    -1,  1289,  1764,
      -1,  1292,    -1,    -1,    -1,    -1,   675,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1307,  1787,    -1,    -1,
      -1,    -1,  1787,    -1,    -1,  1584,  1585,    -1,  1587,    -1,
    1589,   700,    -1,    -1,    -1,    -1,    -1,  1596,    -1,  1809,
      -1,    -1,    -1,    -1,  1809,    -1,    -1,   716,  1818,    -1,
      -1,   720,   721,  1818,   723,    -1,    -1,    -1,    -1,  1350,
    1351,   730,  1353,  1354,  1355,    -1,  1357,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   752,   753,    -1,    -1,   756,    -1,  1648,
      -1,  1650,    -1,  1652,    -1,  1654,    -1,    -1,  1389,    -1,
      -1,  1660,    -1,  1662,    -1,    -1,   775,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1678,
      -1,    -1,  1681,    -1,    -1,  1416,   795,    -1,  1419,  1688,
      -1,  1422,   801,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1699,    -1,  1433,    -1,    -1,    -1,    -1,  1438,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1730,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1740,    -1,    -1,    -1,    -1,  1745,    -1,  1747,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1487,  1488,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1769,    -1,   881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1785,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1805,   916,    -1,    -1,
      -1,  1810,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1822,    -1,    -1,  1825,    -1,    -1,   938,
      -1,    -1,    -1,    -1,    -1,    -1,   945,   946,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   956,    -1,    -1,
     959,    -1,    -1,  1584,  1585,    -1,  1587,    -1,  1589,    -1,
      -1,    -1,    -1,    -1,    -1,  1596,    -1,    -1,    -1,    -1,
      -1,   980,   981,   982,    -1,   984,   985,   986,   987,   988,
      -1,    -1,   991,   992,    -1,   994,   995,    -1,    -1,    -1,
     999,  1000,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1014,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1025,  1648,    -1,  1650,
      -1,  1652,    -1,  1654,    -1,    -1,  1035,    -1,    -1,  1660,
      -1,  1662,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1678,    -1,    -1,
    1681,    -1,    -1,    -1,    -1,    -1,    -1,  1688,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1699,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1730,
    1109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1740,
      -1,    -1,    -1,    -1,  1745,    -1,  1747,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1769,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1785,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1176,    -1,    -1,
      -1,    -1,    -1,    -1,  1805,    -1,    -1,  1186,    -1,  1810,
      -1,    -1,    -1,  1192,  1193,    -1,    -1,    -1,    -1,    -1,
      -1,  1822,    -1,    -1,  1825,    -1,    -1,    -1,    -1,    -1,
    1209,    -1,    -1,  1212,  1213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1253,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1286,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1294,    -1,  1296,    -1,  1298,
      -1,    -1,  1301,    -1,    -1,    -1,    -1,  1306,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1403,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1411,  1412,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1443,  1444,  1445,  1446,    -1,  1448,
    1449,    -1,  1451,    -1,  1453,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1469,    -1,    -1,    -1,    -1,  1474,    -1,    -1,    -1,  1478,
      -1,    -1,    -1,  1482,    -1,  1484,    -1,  1486,    -1,    -1,
      -1,    -1,    -1,  1492,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1570,    -1,    -1,    -1,    -1,  1575,  1576,    -1,    -1,
      -1,    -1,    -1,    -1,  1583,    -1,    -1,    -1,    -1,  1588,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1605,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1618,
      -1,  1620,    -1,  1622,    -1,    -1,  1625,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1693,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1716,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1746,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,    -1,    -1,    -1,  1783,    -1,    -1,    -1,  1787,    -1,
      -1,    -1,    -1,  1792,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,  1808,
      -1,    34,    35,  1812,    37,    38,    39,    40,    41,    42,
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
     153,    -1,   155,   156,    -1,   158,   159,   160,   161,   162,
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
     313,   314,   315,   316,    -1,   318,     0,     1,   321,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
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
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,     1,   318,    -1,    -1,   321,   322,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,     1,
     318,    -1,    -1,   321,   322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
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
     312,   313,   314,   315,   316,    -1,   318,    11,    12,   321,
     322,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,
     224,   225,   226,   227,   228,   229,    -1,   231,    -1,   233,
      -1,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    -1,    -1,    -1,    -1,   322,    21,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
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
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,    -1,   321,
     322,    -1,    -1,    -1,    -1,   327,   328,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
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
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    -1,
      16,    -1,    -1,    -1,   328,    21,    22,    23,    24,    25,
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
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
     186,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
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
     316,    -1,   318,    16,    -1,   321,   322,    -1,    21,    22,
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
     153,    -1,   155,   156,    -1,   158,   159,   160,   161,   162,
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
     313,   314,   315,   316,    -1,   318,    16,    -1,   321,   322,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
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
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    16,
     320,   321,   322,    -1,    21,    22,    23,    24,    25,    26,
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
      -1,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
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
      16,   318,    -1,    -1,   321,   322,    -1,    -1,    -1,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
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
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      16,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    25,
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
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      16,    -1,    -1,    -1,    -1,    -1,   322,    -1,    -1,    25,
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
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      18,    19,    -1,    -1,    -1,    -1,   322,    25,    26,    -1,
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
     148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
      -1,   219,   220,    -1,    -1,    -1,   224,   225,   226,   227,
     228,   229,    -1,   231,    -1,   233,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,    -1,
      -1,    -1,    -1,    -1,   322,    21,    22,    23,    24,    25,
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
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
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
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,   321,   322,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
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
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,   186,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    21,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,   186,    -1,   188,    -1,   190,   191,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,    -1,   321,
     322,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,   186,    -1,   188,    -1,
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
      -1,   321,   322,    21,    22,    23,    24,    25,    26,    27,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,   321,   322,    21,    22,    23,    24,    25,
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
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
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
     316,    -1,   318,    -1,    -1,   321,   322,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
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
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    21,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,    -1,   321,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     140,   141,    -1,    -1,    -1,    -1,   146,    -1,   148,   149,
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,
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
      -1,   321,   322,    21,    22,    23,    24,    25,    26,    -1,
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
     138,   139,   140,   141,    -1,    -1,    -1,    -1,   146,    -1,
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,   321,   322,    21,    22,    23,    24,    25,
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
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
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
     316,    -1,   318,    -1,    -1,   321,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
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
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,   187,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,   189,   190,   191,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,    -1,   321,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
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
     310,   311,   312,   313,   314,   315,   316,   317,   318,    -1,
      -1,   321,   322,    21,    22,    23,    24,    25,    26,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,   319,    -1,   321,   322,    21,    22,    23,    24,    25,
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
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
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
     316,    -1,   318,    -1,   320,   321,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
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
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,   186,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
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
      -1,    -1,    -1,    -1,   146,    -1,   148,   149,   150,   151,
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,    -1,   321,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
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
      -1,   321,   322,    21,    22,    23,    24,    25,    26,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
      -1,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,   321,   322,    21,    22,    23,    24,    25,
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
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,    -1,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
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
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,    -1,   231,    -1,   233,
      -1,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,    -1,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,    -1,   231,
      -1,   233,    -1,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,    -1,    -1,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,    -1,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
      -1,   231,    -1,   233,    -1,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
      -1,    -1,   322,    21,    22,    23,    24,    25,    26,    -1,
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
     148,   149,   150,   151,   152,   153,    -1,   155,   156,    -1,
     158,   159,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,    -1,   231,    -1,   233,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,    -1,   322,    21,    22,    23,    24,    25,
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
      -1,    -1,   148,   149,   150,   151,   152,   153,    -1,   155,
     156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,   320,    -1,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
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
      -1,   155,   156,    -1,   158,   159,    -1,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,    -1,    -1,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,    -1,   231,    -1,   233,
      -1,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,    -1,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
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
     152,   153,    -1,   155,   156,    -1,   158,   159,    -1,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,   213,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,    -1,   231,
      -1,   233,    -1,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    25,    26,    -1,
     322,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
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
     158,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,
      -1,   219,   220,    -1,    -1,    -1,   224,   225,   226,   227,
     228,   229,    -1,   231,    -1,   233,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,    -1,
      25,    26,    -1,    -1,   322,   323,   324,   325,   326,    34,
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
      -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
      -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,
     225,   226,   227,   228,   229,    -1,   231,    -1,   233,    -1,
      -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,    -1,    25,    26,    -1,    -1,   322,   323,   324,
     325,   326,    34,    35,    -1,    37,    38,    39,    40,    41,
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
      -1,   213,   214,    -1,    -1,   217,    -1,   219,   220,    -1,
      -1,    -1,   224,   225,   226,   227,   228,   229,    -1,   231,
      -1,   233,    -1,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    25,    26,    -1,    -1,
     322,   323,   324,   325,   326,    34,    35,    -1,    37,    38,
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
     209,   210,    -1,    -1,   213,   214,    -1,    -1,   217,    -1,
     219,   220,    -1,    -1,    -1,   224,   225,   226,   227,   228,
     229,    -1,   231,    -1,   233,    -1,    -1,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,    -1,    25,
      26,    -1,    -1,   322,   323,   324,   325,   326,    34,    35,
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
      -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    25,    26,    -1,    -1,   322,   323,   324,   325,
     326,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
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
     213,   214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,
      -1,   224,   225,   226,   227,   228,   229,    -1,   231,    -1,
     233,    -1,    -1,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,    -1,    25,    26,    -1,    -1,   322,
     323,   324,   325,   326,    34,    35,    -1,    37,    38,    39,
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
     210,    -1,    -1,   213,   214,    -1,    -1,   217,    -1,   219,
     220,    -1,    -1,    -1,   224,   225,   226,   227,   228,   229,
      -1,   231,    -1,   233,    -1,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,    -1,    25,    26,
      -1,    -1,   322,   323,   324,   325,   326,    34,    35,    -1,
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
      -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,   196,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,   213,   214,    -1,    -1,
     217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,   226,
     227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    25,
      26,    -1,    -1,    -1,    -1,   322,    -1,    -1,    34,    35,
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
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
     196,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,   213,   214,    -1,
      -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      25,    26,    -1,    -1,    -1,    -1,   322,    -1,    -1,    34,
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
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,   213,   214,
      -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,
     225,   226,   227,   228,   229,    -1,   231,    -1,   233,    -1,
      -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    25,    26,    -1,    -1,    -1,    -1,   322,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,   213,
     214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,
     224,   225,   226,   227,   228,   229,    -1,   231,    -1,   233,
      -1,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    25,    26,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    -1,    41,    42,
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
      -1,   214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,
      -1,   224,   225,   226,   227,   228,   229,    -1,    -1,    -1,
     233,    -1,    -1,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,    -1,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,    -1,   265,   266,   267,    -1,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,    -1,    -1,    -1,    -1,    -1,    -1,   322
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
     150,   151,   152,   153,   155,   156,   158,   159,   160,   161,
     162,   167,   168,   169,   170,   171,   172,   173,   174,   176,
     178,   179,   182,   183,   184,   188,   190,   191,   198,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     213,   214,   215,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     265,   266,   267,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   318,   321,   322,   327,   328,   342,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   363,   364,   365,   366,   367,   368,
     372,   373,   374,   378,   380,   381,   383,   390,   392,   395,
     396,   397,   399,   400,   401,   402,   403,   405,   406,   408,
     409,   410,   411,   412,   413,   415,   416,   419,   420,   421,
     422,   427,   429,   431,   432,   433,   438,   457,   460,   464,
     467,   468,   474,   475,   476,   477,   478,   480,   481,   483,
     484,   485,   486,   487,   488,   489,   490,   491,   493,   494,
     495,   496,   499,   500,   501,   502,   503,   504,   505,   508,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     522,   523,   524,   525,   526,   527,   541,   542,   544,   545,
     546,   547,   548,   549,   550,   551,   572,   577,   578,   579,
     580,   581,   582,   585,   643,   644,   645,   646,   648,   649,
     650,   651,   652,   659,   660,   661,    34,    35,    50,   217,
     398,   399,   400,   398,   398,   399,   400,   158,   158,    38,
      39,    41,    42,    48,    58,    59,    76,    81,   113,   114,
     115,   162,   226,   267,   293,   301,   309,   379,   380,   384,
     385,   386,   162,   155,   155,   155,   158,   387,   158,    25,
      35,    62,   120,   279,   437,   439,   440,   155,   120,   155,
     158,   158,    78,   155,   227,   228,   155,   120,   407,    40,
      44,    46,    47,    48,    49,    52,    61,    69,    72,    74,
      75,    77,    99,   114,   137,   162,   171,   204,   242,   244,
     245,   246,   249,   250,   263,   266,   659,   660,   120,    16,
     186,   398,   400,   420,   647,   658,   659,    49,    74,    75,
     120,   155,   187,   250,   419,   421,   431,   189,   419,   659,
     155,   155,   658,   659,    18,    19,   659,   155,    31,   216,
     219,   219,   231,   233,   320,   508,   231,   233,   320,   420,
     647,   231,   320,   508,   231,   236,   320,   120,   247,   247,
     248,   158,   155,   402,   477,   317,   419,   319,   419,   320,
     420,   328,   344,   344,     0,   346,   347,    34,    50,   349,
     366,     1,   192,   343,   192,   343,   114,   381,   401,   419,
     109,   192,   109,   343,   192,    43,    47,    52,    71,   170,
     173,   188,   214,   263,   414,   423,   428,   429,   430,   445,
     446,   450,     1,     3,    68,    73,   120,   424,   169,    94,
     134,   142,   143,   145,   153,   157,   159,   164,   181,   205,
     206,   207,   208,   209,   210,   497,   498,   255,   101,   160,
     178,   201,   119,   148,   161,   196,   203,   212,   138,   152,
      51,   202,   103,   104,   160,   178,   495,   195,   155,   502,
     121,   156,   158,   509,   510,   147,   158,   186,   186,   186,
     186,   382,   512,   382,    30,   657,   184,   198,   184,   198,
     168,   184,   660,   659,   171,   204,    48,   659,   154,   120,
      46,    48,    81,   108,   170,   658,   227,   228,   229,   252,
     616,   659,   659,   310,   139,   144,   114,   293,   301,   384,
     658,   399,   399,   419,   120,   189,   388,   389,   155,   404,
     419,     1,   162,   657,   115,   162,   362,   657,   659,   120,
     144,   109,   419,   458,   459,   659,   399,   419,   419,   570,
     659,   399,   155,   155,   419,   659,   144,   458,   186,   186,
     123,   109,   186,   123,   158,   158,   158,   659,   155,   187,
     188,   189,    36,   529,   530,   531,   419,   419,     8,   177,
      17,   419,   216,    30,    30,   420,   420,   508,   420,   420,
     420,   647,   239,   239,   420,   508,    96,   420,   237,   236,
     583,   584,   659,   192,   192,   420,   419,   400,   419,   251,
     417,   418,   317,   319,   420,   239,   344,   192,   343,   192,
     343,     3,   350,   366,   396,     1,   350,   366,   396,    34,
     367,   396,   367,   396,   407,   343,   407,   420,   420,   120,
     170,   172,   172,   401,   420,   420,   434,   435,   659,   290,
     290,   434,   120,   441,   476,   477,   480,   480,   480,   480,
     479,   480,   480,   480,    72,   481,   485,   485,   484,   486,
     486,   486,   486,   487,   487,   488,   488,   237,    96,    96,
      96,   503,   186,   419,   196,   515,   516,   572,   658,   419,
     146,   189,   420,   521,   510,   151,   189,   521,   109,   189,
     189,   109,   109,   387,    30,   660,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   369,   370,   371,    96,
     139,   144,   375,   376,   377,   659,   162,   162,   369,   657,
     129,   134,    56,    58,   102,   257,   270,   272,   283,   284,
     285,   287,   289,   617,   618,   619,   620,   621,   622,   629,
     635,   636,   252,    96,   305,   659,   144,   420,   120,   659,
     659,   134,   186,   186,   186,   659,    96,   109,   189,   398,
     189,   658,    98,    46,   658,   657,    98,    96,   144,   552,
     659,   420,   440,   186,   109,   190,   149,   552,   186,   189,
     189,   155,   186,   399,   399,   186,   144,   552,   420,   190,
     420,   420,   658,   420,   419,   419,   419,   659,   530,   531,
     132,   199,   186,   186,   186,   133,   192,   133,   192,    96,
     224,   225,   239,    96,   224,   225,   239,   239,   239,   420,
     420,    96,    96,   420,   243,   231,   508,   237,   109,   241,
     144,   192,   189,   419,   186,    11,    12,    20,   196,   506,
     507,   589,   659,   418,   239,   420,   366,    34,    34,   192,
     343,   192,   115,   401,   659,   172,   420,   451,   452,   120,
     447,   448,   109,    37,    98,   149,   436,   437,   552,   659,
      57,   220,   260,   425,   426,   480,   155,   158,   265,   501,
     512,   590,   593,   594,   595,   596,   597,   601,   603,   605,
     606,    40,    45,    46,    48,    54,    61,    63,    64,    72,
      99,   154,   158,   213,   231,   323,   324,   325,   326,   553,
     555,   557,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   573,   574,   575,   576,   653,   654,   655,
     656,   659,   553,   492,   558,   659,   492,   186,   187,   109,
     189,   189,   512,   150,   167,   150,   167,   139,   404,   387,
     370,   134,   158,   555,   377,   420,   552,   657,   657,   130,
     131,   657,   283,   284,   285,   289,   659,   269,   280,   269,
     280,    30,   292,    98,   115,   158,   623,   626,   617,    40,
      45,    46,    54,    61,    63,    64,    72,    99,   231,   391,
     559,   653,   233,   305,   314,   420,   659,    96,   305,   657,
     155,   552,   553,   389,    96,   186,   200,   134,   361,   657,
     162,   134,    98,   361,   553,   420,   144,   437,   155,   120,
     420,   420,   149,   102,   461,   462,   463,   465,   466,   102,
     469,   470,   471,   472,   399,   186,   186,   155,   420,   144,
     192,   420,   123,   123,   189,   189,   189,    36,   531,   132,
     199,     9,    10,   105,   125,   127,   155,   197,   526,   528,
     539,   540,   543,   155,    30,    30,   238,   240,   420,   420,
     420,   238,   240,   420,   420,   420,   420,   420,    98,   420,
     420,   420,   420,   243,   508,   120,   420,   420,    49,    74,
      75,   250,   401,   421,   431,   251,   586,   587,   155,   212,
     402,   420,   192,   115,   396,   396,   396,   451,    97,   108,
     118,   129,   453,   454,   455,   456,   109,   659,   109,   120,
     435,   129,   120,   420,   149,   437,   149,    37,   149,   436,
     437,   149,   552,   260,    55,    60,    79,   120,   436,   442,
     443,   444,   426,   419,   590,   597,   155,   291,   482,   642,
      98,   171,   258,   259,   261,   268,   278,   290,   591,   592,
     611,   612,   613,   614,   637,   640,   264,   266,   598,   616,
     273,   602,   638,   253,   254,   276,   607,   608,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   189,
     555,   158,   158,   158,   158,   158,   158,   146,   178,   196,
     554,   146,   146,   420,   139,   404,   572,   376,   292,    30,
      98,   115,   158,   630,    30,   623,   554,   554,   503,   293,
     312,   552,   391,   233,   192,   398,   553,   401,   420,   657,
     109,   361,   420,   144,   398,   459,   420,   420,   115,   462,
     463,   102,   188,   115,   463,   466,   120,   473,   553,   102,
     115,   470,   102,   115,   472,   186,   398,   420,   420,   420,
     200,   469,   134,   197,   528,     7,   399,   659,   197,   539,
     399,   192,   192,   239,   239,   239,   239,    98,   322,   243,
     420,   243,   584,   188,   158,   158,   158,   188,   589,   587,
     506,   657,   130,   131,   455,   456,   456,   452,   108,   144,
     449,   552,   448,   435,   149,   436,   659,   420,   149,   420,
     129,   420,   149,   437,   149,   420,   149,   120,   120,   420,
     659,   444,    79,   186,   189,   590,   604,   256,   220,   260,
     274,   281,   641,    98,   262,   263,   639,   256,   594,   641,
     484,   611,   595,   149,   288,   599,   600,   639,   292,   610,
      80,   609,   189,   189,   568,   569,   189,   196,   659,   189,
     196,   553,   556,   189,    30,   189,   658,   659,   659,   189,
     189,   196,   659,   189,   189,   189,   189,   189,   189,   189,
     189,    30,   138,   203,   632,   633,   634,    30,   631,   632,
     277,   627,   109,   624,   172,   659,   263,   503,   186,   128,
     128,    98,   657,   420,   186,   188,   188,   420,   401,   420,
     188,   188,   659,   188,   212,   120,   473,   120,   188,   120,
     473,   188,   186,   115,   531,   659,   197,   186,   531,   659,
     186,   420,   420,   420,   420,   322,   420,   420,   420,   420,
     419,   419,   419,   155,   588,   456,   657,   420,   144,   420,
     149,   420,   149,   436,   420,   149,   420,   420,   659,   659,
     443,   420,   186,   486,    53,   131,   484,   484,   275,   282,
     292,   615,   615,   596,   155,   286,   189,   189,   109,   189,
     109,   189,    96,   189,   109,   189,   189,   189,   189,   189,
     109,   189,   109,   189,   630,   630,   634,   109,   189,    30,
     628,   639,   625,   626,   189,   393,   394,   503,   120,   231,
     313,   293,   172,   401,   420,   361,   420,   401,    96,   401,
     420,   553,   659,   188,   659,   420,   659,   188,   401,   120,
      95,   185,   532,   531,   659,   199,   531,   420,   189,   189,
     189,   419,   449,   420,   420,   420,   149,   420,    55,   484,
     484,   201,   419,   570,   571,   659,   570,   571,   553,   553,
      96,   570,   570,    30,   271,   109,   109,   456,   552,   659,
     120,   231,   659,   393,   473,    96,   188,    96,   659,     5,
     135,   535,   536,   538,   540,    29,   136,   533,   534,   537,
     540,   199,   531,   199,   200,   469,   186,   449,   420,   120,
     484,   186,   189,   189,   146,   189,   189,   553,   189,   189,
     626,   394,   456,   311,   659,   120,   231,   188,   473,   401,
     420,   473,   188,    95,   135,   538,   185,   136,   537,   199,
     115,   659,   420,   311,   659,   120,   401,   420,   188,   188,
     120,   299,   311,   659,   659,   312,   420,   312,   188,   503,
     503,   201,   293,   659,   231,   120,   659,   312,   503
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
     477,   477,   478,   478,   478,   478,   478,   479,   478,   478,
     478,   478,   480,   480,   481,   481,   482,   482,   483,   483,
     484,   484,   484,   485,   485,   485,   485,   485,   486,   486,
     486,   487,   487,   487,   488,   488,   489,   489,   490,   490,
     491,   491,   492,   492,   493,   493,   494,   494,   494,   494,
     495,   495,   495,   496,   496,   497,   497,   497,   497,   497,
     497,   498,   498,   498,   499,   499,   499,   499,   500,   500,
     501,   501,   502,   502,   502,   503,   504,   505,   506,   506,
     507,   507,   507,   507,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   509,   509,   510,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     512,   512,   512,   512,   513,   513,   513,   514,   514,   515,
     516,   516,   517,   518,   519,   520,   520,   521,   521,   521,
     521,   522,   522,   523,   524,   525,   525,   526,   526,   526,
     527,   527,   527,   527,   527,   527,   528,   528,   529,   529,
     530,   531,   531,   532,   532,   533,   533,   534,   534,   534,
     534,   535,   535,   536,   536,   536,   536,   537,   537,   538,
     538,   539,   539,   539,   539,   540,   540,   540,   540,   541,
     541,   542,   542,   543,   544,   544,   544,   544,   544,   544,
     544,   545,   546,   546,   547,   547,   548,   549,   550,   550,
     551,   551,   552,   553,   553,   553,   553,   554,   554,   554,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   556,
     556,   557,   558,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   560,   561,   561,   561,   562,   563,   564,
     565,   565,   565,   566,   566,   566,   566,   566,   567,   568,
     568,   568,   568,   568,   568,   568,   569,   570,   571,   572,
     573,   573,   574,   575,   575,   576,   577,   577,   577,   578,
     578,   578,   578,   578,   578,   578,   578,   578,   578,   579,
     579,   580,   580,   581,   582,   583,   583,   584,   585,   586,
     586,   587,   588,   589,   589,   590,   591,   591,   592,   592,
     593,   593,   594,   594,   595,   595,   596,   596,   597,   598,
     598,   599,   599,   600,   601,   601,   601,   602,   602,   603,
     604,   604,   605,   606,   606,   607,   607,   608,   608,   608,
     609,   609,   610,   610,   611,   611,   611,   611,   611,   612,
     613,   614,   615,   615,   615,   616,   616,   617,   617,   617,
     617,   617,   617,   617,   617,   618,   618,   618,   618,   619,
     619,   620,   621,   621,   622,   622,   622,   623,   623,   624,
     624,   625,   625,   626,   627,   627,   628,   628,   629,   629,
     629,   630,   630,   631,   631,   632,   632,   633,   633,   634,
     634,   635,   636,   636,   637,   637,   637,   638,   639,   639,
     639,   639,   640,   640,   641,   641,   642,   643,   643,   644,
     644,   645,   645,   646,   647,   647,   647,   647,   648,   648,
     648,   648,   648,   648,   649,   649,   650,   650,   651,   651,
     652,   652,   653,   653,   653,   654,   654,   655,   655,   656,
     656,   657,   658,   658,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
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
     660,   660,   660,   660,   660,   660,   661
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
       1,     2,     1,     3,     3,     3,     3,     0,     4,     3,
       3,     3,     1,     5,     1,     3,     0,     1,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     4,
       1,     4,     1,     2,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     3,     4,
       1,     2,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     3,     3,
       3,     3,     3,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     4,     4,     3,     4,     1,     3,     1,
       3,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       4,     8,     5,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     7,     3,     7,     4,     4,     3,     7,
       3,     7,     2,     1,     2,     3,     2,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     4,     3,     3,     3,
       3,     4,     4,     3,     4,     6,     4,     6,     4,     3,
       4,     6,     6,     4,     6,     6,     4,     1,     2,     1,
       1,     1,     4,     5,     6,     3,     3,     3,     3,     5,
       7,     7,     5,     5,     5,     7,     7,     5,     5,     3,
       3,     5,     7,     5,     7,     1,     4,     3,     5,     1,
       2,     3,     3,     1,     3,     2,     0,     1,     1,     2,
       1,     3,     1,     3,     1,     4,     1,     2,     3,     0,
       1,     0,     1,     4,     2,     3,     1,     0,     1,     4,
       0,     1,     2,     1,     3,     0,     1,     2,     2,     1,
       0,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     2,
       2,     3,     1,     2,     2,     5,     2,     1,     1,     0,
       2,     1,     3,     4,     0,     2,     0,     2,     4,     4,
       3,     2,     3,     1,     3,     0,     1,     1,     2,     2,
       2,     2,     1,     2,     2,     2,     2,     3,     2,     3,
       3,     4,     2,     2,     1,     1,     3,     2,     3,     2,
       3,     2,     3,     3,     3,     3,     5,     5,     5,     5,
       8,     4,     4,     7,     5,     4,     3,     2,     5,     4,
       7,     6,     1,     1,     1,     3,     1,     3,     1,     3,
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
  "OrExpr", "AndExpr", "NotExpr", "ComparisonExpr", "$@1",
  "FTContainsExpr", "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr",
  "AdditiveExpr", "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
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
     162,   658,   134,   657,   192,    -1,   350,    -1,   349,   192,
     350,    -1,   349,   343,   350,    -1,   351,    -1,   359,    -1,
     364,    -1,   365,    -1,   373,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   358,    -1,
     577,    -1,    34,    39,   184,    -1,    34,    39,   198,    -1,
      34,   115,   108,   657,    -1,    34,    38,   657,    -1,    34,
      41,   184,    -1,    34,    41,   198,    -1,    34,    59,   171,
      -1,    34,    59,   204,    -1,    34,   115,   170,   129,   130,
      -1,    34,   115,   170,   129,   131,    -1,    34,    42,   184,
     109,   150,    -1,    34,    42,   184,   109,   167,    -1,    34,
      42,   168,   109,   150,    -1,    34,    42,   168,   109,   167,
      -1,   360,    -1,   363,    -1,    50,    25,     1,    -1,    50,
      62,   657,    -1,    50,    62,   362,   657,    -1,    50,    62,
     657,    98,   361,    -1,    50,    62,   362,   657,    98,   361,
      -1,   657,    -1,   361,   109,   657,    -1,   162,   658,   134,
      -1,   115,    46,   162,    -1,    50,    35,   657,    -1,    50,
      35,   162,   658,   134,   657,    -1,    50,    35,   657,    98,
     361,    -1,    50,    35,   162,   658,   134,   657,    98,   361,
      -1,    34,   162,   658,   134,   657,    -1,    34,   115,    46,
     162,   657,    -1,    34,   115,    48,   162,   657,    -1,   367,
      -1,   366,   192,   367,    -1,   366,   343,   367,    -1,   368,
      -1,   372,    -1,   374,    -1,   378,    -1,   383,    -1,   390,
      -1,   392,    -1,   395,    -1,    34,   115,    81,   369,    -1,
      34,    81,   659,   369,    -1,   370,    -1,   369,   370,    -1,
     371,   134,   572,    -1,    82,    -1,    90,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    91,    -1,    87,    -1,
      88,    -1,    89,    -1,    34,    58,   659,    30,    -1,    34,
     267,   616,    -1,    34,   113,   154,   375,    -1,    96,   555,
     376,    -1,   376,    -1,   377,    -1,   139,    -1,   139,   377,
      -1,   144,   420,    -1,    34,   379,   144,   420,    -1,    34,
     379,   139,    -1,    34,   379,   139,   144,   420,    -1,   114,
     120,   659,    -1,   114,   120,   659,   552,    -1,   380,   114,
     120,   659,    -1,   380,   114,   120,   659,   552,    -1,   381,
      -1,   380,   381,    -1,    27,    -1,    27,   158,   382,   189,
      -1,    28,    -1,    28,   158,   382,   189,    -1,   512,    -1,
     382,   109,   512,    -1,    34,   384,    -1,    34,   380,   384,
      -1,   385,    -1,   386,    -1,    48,   660,   387,   404,    -1,
      48,   660,   387,   139,    -1,    76,    48,   660,   387,   404,
      -1,    76,    48,   660,   387,   139,    -1,   158,   189,    -1,
     158,   388,   189,    -1,   158,   189,    96,   553,    -1,   158,
     388,   189,    96,   553,    -1,   389,    -1,   388,   109,   389,
      -1,   120,   659,    -1,   120,   659,   552,    -1,    34,   293,
     659,    -1,    34,   293,   659,    96,   391,    -1,    34,   380,
     293,   659,    -1,    34,   380,   293,   659,    96,   391,    -1,
     559,    -1,   559,   554,    -1,   653,    -1,   653,   554,    -1,
      34,   301,   659,   305,   233,   503,   172,   393,    -1,    34,
     380,   301,   659,   305,   233,   503,   172,   393,    -1,   394,
      -1,   393,   109,   394,    -1,   503,    -1,   503,   552,    -1,
     503,   456,    -1,   503,   552,   456,    -1,    34,   309,   310,
     659,   305,   293,   659,   120,   659,   311,   420,    -1,    34,
     309,   310,   659,   305,   293,   659,   231,   120,   659,   311,
     299,   312,   503,    -1,    34,   309,   310,   659,   305,   293,
     659,   313,   231,   120,   659,   311,   420,    -1,    34,   309,
     310,   659,   314,   312,   263,   293,   659,   231,   120,   659,
     312,   503,   201,   293,   659,   231,   120,   659,   312,   503,
      -1,   397,    -1,   399,    -1,   400,    -1,    -1,   399,    -1,
     400,    -1,    -1,   419,    -1,   400,   419,    -1,   401,    -1,
     400,   401,    -1,   400,   419,   343,   401,    -1,   402,    -1,
     405,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   413,    -1,   415,    -1,   468,    -1,   464,    -1,
     416,    -1,   155,   400,   186,    -1,   155,   186,    -1,   155,
     398,   186,    -1,   155,   398,   186,    -1,   406,   192,    -1,
     406,   109,   407,    -1,   114,   407,    -1,   380,   114,   407,
      -1,   120,   659,    -1,   120,   659,   552,    -1,   120,   659,
     144,   420,    -1,   120,   659,   552,   144,   420,    -1,   120,
     659,   144,   420,   192,    -1,   421,   192,    -1,   246,   248,
     420,   192,    -1,   249,   158,   419,   189,   401,    -1,   244,
     247,   192,    -1,   245,   247,   192,    -1,   431,   414,    -1,
     188,   401,    -1,    49,   158,   419,   189,   200,   401,   128,
     401,    -1,   250,   402,   417,    -1,   418,    -1,   417,   418,
      -1,   251,   589,   402,    -1,   420,    -1,   419,   109,   420,
      -1,   419,   343,   420,    -1,   422,    -1,   460,    -1,   467,
      -1,   474,    -1,   585,    -1,   421,    -1,   475,    -1,   457,
      -1,   578,    -1,   579,    -1,   581,    -1,   580,    -1,   582,
      -1,   650,    -1,   648,    -1,   651,    -1,   652,    -1,   649,
      -1,   431,   423,    -1,   188,   420,    -1,    68,   290,    -1,
      73,   290,    -1,   220,    -1,   260,    -1,    57,   260,    -1,
     425,   442,    79,   420,    -1,   425,    79,   420,    -1,   433,
     424,   441,   426,   426,    -1,   433,   424,   441,   426,    -1,
      43,   120,   659,    -1,   432,    -1,   438,    -1,   427,    -1,
     429,    -1,   445,    -1,   450,    -1,   446,    -1,   428,    -1,
     429,    -1,   431,   430,    -1,   433,   120,   434,    -1,   433,
       1,   434,    -1,   433,     3,    -1,    47,    -1,   263,    -1,
     435,    -1,   434,   109,   120,   435,    -1,   434,   109,   435,
      -1,   659,   149,   420,    -1,   659,    37,   129,   149,   420,
      -1,   659,   552,   149,   420,    -1,   659,   552,    37,   129,
     149,   420,    -1,   659,   436,   149,   420,    -1,   659,    37,
     129,   436,   149,   420,    -1,   659,   552,   436,   149,   420,
      -1,   659,   552,    37,   129,   436,   149,   420,    -1,   659,
     437,   149,   420,    -1,   659,   552,   437,   149,   420,    -1,
     659,   436,   437,   149,   420,    -1,   659,   552,   436,   437,
     149,   420,    -1,    98,   120,   659,    -1,   279,   120,   659,
      -1,    52,   439,    -1,   440,    -1,   439,   109,   440,    -1,
     120,   659,   144,   420,    -1,   120,   659,   552,   144,   420,
      -1,   437,   144,   420,    -1,   120,   659,   552,   437,   144,
     420,    -1,   120,   659,   149,   420,    -1,   120,   659,   552,
     149,   420,    -1,   443,    -1,   120,   659,    -1,   120,   659,
     443,    -1,   436,    -1,   436,   444,    -1,   444,    -1,    60,
     120,   659,    55,   120,   659,    -1,    55,   120,   659,    -1,
      60,   120,   659,    -1,   214,   420,    -1,   173,   172,   447,
      -1,   448,    -1,   447,   109,   448,    -1,   120,   659,    -1,
     120,   659,   144,   420,    -1,   120,   659,   552,   144,   420,
      -1,   120,   659,   552,   144,   420,   449,    -1,   120,   659,
     144,   420,   449,    -1,   120,   659,   449,    -1,   108,   657,
      -1,   170,   172,   451,    -1,    71,   170,   172,   451,    -1,
     452,    -1,   451,   109,   452,    -1,   420,    -1,   420,   453,
      -1,   454,    -1,   455,    -1,   456,    -1,   454,   455,    -1,
     454,   456,    -1,   455,   456,    -1,   454,   455,   456,    -1,
      97,    -1,   118,    -1,   129,   130,    -1,   129,   131,    -1,
     108,   657,    -1,    69,   120,   458,   190,   420,    -1,   137,
     120,   458,   190,   420,    -1,   459,    -1,   458,   109,   120,
     459,    -1,   659,   149,   420,    -1,   659,   552,   149,   420,
      -1,    74,   158,   419,   189,   461,   115,   188,   420,    -1,
     462,    -1,   461,   462,    -1,   463,   188,   420,    -1,   102,
     420,    -1,   463,   102,   420,    -1,    74,   158,   419,   189,
     465,   115,   188,   401,    -1,   466,    -1,   465,   466,    -1,
     463,   188,   401,    -1,    75,   158,   419,   189,   469,   115,
     188,   420,    -1,    75,   158,   419,   189,   469,   115,   120,
     659,   188,   420,    -1,    75,   158,   419,   189,   471,   115,
     188,   401,    -1,    75,   158,   419,   189,   469,   115,   120,
     659,   188,   401,    -1,   470,    -1,   469,   470,    -1,   102,
     473,   188,   420,    -1,   102,   120,   659,    96,   473,   188,
     420,    -1,   472,    -1,   471,   472,    -1,   102,   473,   188,
     401,    -1,   102,   120,   659,    96,   473,   188,   401,    -1,
     553,    -1,   473,   212,   553,    -1,    49,   158,   419,   189,
     200,   420,   128,   420,    -1,   476,    -1,   475,   169,   476,
      -1,   477,    -1,   476,    94,   477,    -1,   478,    -1,   266,
     477,    -1,   480,    -1,   480,   497,   480,    -1,   480,   498,
     480,    -1,   480,   134,   480,    -1,   480,   164,   480,    -1,
      -1,   480,   159,   479,   480,    -1,   480,   157,   480,    -1,
     480,   145,   480,    -1,   480,   143,   480,    -1,   481,    -1,
     481,   255,    72,   590,   482,    -1,   483,    -1,   483,   101,
     481,    -1,    -1,   642,    -1,   484,    -1,   484,   201,   484,
      -1,   485,    -1,   484,   178,   485,    -1,   484,   160,   485,
      -1,   486,    -1,   485,   196,   486,    -1,   485,   119,   486,
      -1,   485,   148,   486,    -1,   485,   161,   486,    -1,   487,
      -1,   486,   203,   487,    -1,   486,   212,   487,    -1,   488,
      -1,   487,   152,   488,    -1,   487,   138,   488,    -1,   489,
      -1,   489,    51,   237,   553,    -1,   490,    -1,   490,   202,
      96,   553,    -1,   491,    -1,   491,   103,    96,   492,    -1,
     493,    -1,   493,   104,    96,   492,    -1,   558,    -1,   558,
     146,    -1,   495,    -1,   494,   495,    -1,   178,    -1,   160,
      -1,   494,   178,    -1,   494,   160,    -1,   499,    -1,   496,
      -1,   500,    -1,   503,    -1,   496,   195,   503,    -1,   205,
      -1,   210,    -1,   209,    -1,   208,    -1,   207,    -1,   206,
      -1,   153,    -1,   181,    -1,   142,    -1,    77,   155,   399,
     186,    -1,    77,   228,   155,   399,   186,    -1,    77,   227,
     155,   399,   186,    -1,    77,    78,   570,   155,   399,   186,
      -1,   501,   155,   186,    -1,   501,   155,   419,   186,    -1,
     502,    -1,   501,   502,    -1,   179,   659,    17,    -1,   179,
      18,    -1,   179,    19,    -1,   504,    -1,   505,    -1,   508,
      -1,   659,    -1,   507,    -1,   196,    -1,    11,    -1,    12,
      -1,    20,    -1,   511,    -1,   508,   509,    -1,   508,   158,
     189,    -1,   508,   158,   521,   189,    -1,   508,   121,   658,
      -1,   508,   121,   516,    -1,   508,   121,   515,    -1,   508,
     121,   572,    -1,   508,   121,   196,    -1,   510,    -1,   509,
     510,    -1,   156,   419,   187,    -1,   512,    -1,   515,    -1,
     516,    -1,   517,    -1,   520,    -1,   525,    -1,   518,    -1,
     519,    -1,   522,    -1,   403,    -1,   646,    -1,   643,    -1,
     644,    -1,   645,    -1,   513,    -1,   572,    -1,   514,    -1,
     221,    -1,   112,    -1,   151,    -1,   126,    -1,   222,    -1,
     223,    -1,   120,   659,    -1,   158,   189,    -1,   158,   419,
     189,    -1,   121,    -1,   171,   155,   419,   186,    -1,   204,
     155,   419,   186,    -1,   660,   158,   189,    -1,   660,   158,
     521,   189,    -1,   146,    -1,   521,   109,   146,    -1,   420,
      -1,   521,   109,   420,    -1,   523,    -1,   524,    -1,   659,
     147,   151,    -1,    48,   387,   404,    -1,   526,    -1,   544,
      -1,   527,    -1,   541,    -1,   542,    -1,   159,   659,   531,
     132,    -1,   159,   659,   531,   199,   197,   659,   531,   199,
      -1,   159,   659,   529,   531,   132,    -1,   159,   659,   529,
     531,   199,   197,   659,   531,   199,    -1,   159,   659,   531,
     199,   528,   197,   659,   531,   199,    -1,   159,   659,   529,
     531,   199,   528,   197,   659,   531,   199,    -1,   539,    -1,
     528,   539,    -1,   530,    -1,   529,   530,    -1,    36,   659,
     531,   134,   531,   532,    -1,    -1,    36,    -1,   185,   533,
     185,    -1,    95,   535,    95,    -1,    -1,   534,    -1,   136,
      -1,   537,    -1,   534,   136,    -1,   534,   537,    -1,    -1,
     536,    -1,   135,    -1,   538,    -1,   536,   135,    -1,   536,
     538,    -1,    29,    -1,   540,    -1,     5,    -1,   540,    -1,
     526,    -1,    10,    -1,   543,    -1,   540,    -1,     9,    -1,
     125,    -1,   127,    -1,   155,   399,   186,    -1,   215,    31,
     216,    -1,   215,   216,    -1,   176,   658,   177,    -1,   176,
     658,     8,    -1,   105,     7,    -1,   545,    -1,   546,    -1,
     547,    -1,   548,    -1,   549,    -1,   550,    -1,   551,    -1,
      44,   155,   399,   186,    -1,    21,   398,   186,    -1,    46,
     155,   419,   186,   155,   398,   186,    -1,    22,   398,   186,
      -1,    99,   155,   419,   186,   155,   398,   186,    -1,    72,
     155,   399,   186,    -1,    40,   155,   399,   186,    -1,    23,
     398,   186,    -1,    61,   155,   419,   186,   155,   398,   186,
      -1,    24,   399,   186,    -1,   162,   155,   419,   186,   155,
     399,   186,    -1,    96,   553,    -1,   555,    -1,   555,   554,
      -1,   213,   158,   189,    -1,   158,   189,    -1,   146,    -1,
     196,    -1,   178,    -1,   557,    -1,   559,    -1,   154,   158,
     189,    -1,   154,    -1,   326,   158,   189,    -1,   326,    -1,
     573,    -1,   576,    -1,   653,    -1,   553,    -1,   556,   109,
     553,    -1,   659,    -1,   659,    -1,   561,    -1,   568,    -1,
     566,    -1,   569,    -1,   567,    -1,   565,    -1,   564,    -1,
     563,    -1,   562,    -1,   560,    -1,   231,   158,   189,    -1,
      45,   158,   189,    -1,    45,   158,   568,   189,    -1,    45,
     158,   569,   189,    -1,    54,   158,   189,    -1,    72,   158,
     189,    -1,    40,   158,   189,    -1,    61,   158,   189,    -1,
      61,   158,   658,   189,    -1,    61,   158,    30,   189,    -1,
      99,   158,   189,    -1,    99,   158,   659,   189,    -1,    99,
     158,   659,   109,   570,   189,    -1,    99,   158,   196,   189,
      -1,    99,   158,   196,   109,   570,   189,    -1,    63,   158,
     659,   189,    -1,    46,   158,   189,    -1,    46,   158,   659,
     189,    -1,    46,   158,   659,   109,   570,   189,    -1,    46,
     158,   659,   109,   571,   189,    -1,    46,   158,   196,   189,
      -1,    46,   158,   196,   109,   570,   189,    -1,    46,   158,
     196,   109,   571,   189,    -1,    64,   158,   659,   189,    -1,
     659,    -1,   659,   146,    -1,    30,    -1,   574,    -1,   575,
      -1,    48,   158,   196,   189,    -1,    48,   158,   189,    96,
     553,    -1,    48,   158,   556,   189,    96,   553,    -1,   158,
     555,   189,    -1,    34,   226,   227,    -1,    34,   226,   228,
      -1,    34,   226,   229,    -1,   232,   231,   420,   239,   420,
      -1,   232,   231,   420,    96,   238,   239,   420,    -1,   232,
     231,   420,    96,   240,   239,   420,    -1,   232,   231,   420,
     224,   420,    -1,   232,   231,   420,   225,   420,    -1,   232,
     233,   420,   239,   420,    -1,   232,   233,   420,    96,   238,
     239,   420,    -1,   232,   233,   420,    96,   240,   239,   420,
      -1,   232,   233,   420,   224,   420,    -1,   232,   233,   420,
     225,   420,    -1,   230,   231,   420,    -1,   230,   233,   420,
      -1,   235,   231,   420,   243,   420,    -1,   235,   236,   237,
     231,   420,   243,   420,    -1,   234,   231,   420,    96,   420,
      -1,   242,   120,   583,   241,   420,   188,   420,    -1,   584,
      -1,   583,   109,   120,   584,    -1,   659,   144,   420,    -1,
     250,   155,   419,   186,   586,    -1,   587,    -1,   586,   587,
      -1,   251,   589,   588,    -1,   155,   419,   186,    -1,   506,
      -1,   589,   212,   506,    -1,   593,   591,    -1,    -1,   592,
      -1,   611,    -1,   592,   611,    -1,   594,    -1,   593,   268,
     594,    -1,   595,    -1,   594,   264,   595,    -1,   596,    -1,
     595,   266,   149,   596,    -1,   597,    -1,   265,   597,    -1,
     601,   598,   599,    -1,    -1,   616,    -1,    -1,   600,    -1,
     288,   155,   419,   186,    -1,   605,   602,    -1,   158,   590,
     189,    -1,   603,    -1,    -1,   638,    -1,   501,   155,   604,
     186,    -1,    -1,   590,    -1,   606,   607,    -1,   512,    -1,
     155,   419,   186,    -1,    -1,   608,    -1,   254,   609,    -1,
     253,   610,    -1,   276,    -1,    -1,    80,    -1,    -1,   292,
      -1,   612,    -1,   613,    -1,   614,    -1,   640,    -1,   637,
      -1,   171,    -1,   290,   484,   615,    -1,   259,   639,   615,
      -1,   292,    -1,   282,    -1,   275,    -1,   252,   617,    -1,
     616,   252,   617,    -1,   618,    -1,   619,    -1,   620,    -1,
     635,    -1,   621,    -1,   629,    -1,   622,    -1,   636,    -1,
     102,   280,    -1,   102,   269,    -1,   272,    -1,   287,    -1,
     257,   280,    -1,   257,   269,    -1,    58,   659,    30,    -1,
     283,    -1,    56,   283,    -1,   285,   623,    -1,   285,   158,
     623,   624,   189,    -1,    56,   285,    -1,   626,    -1,   115,
      -1,    -1,   109,   625,    -1,   626,    -1,   625,   109,   626,
      -1,    98,    30,   627,   628,    -1,    -1,   277,    30,    -1,
      -1,   639,   271,    -1,   284,   292,   630,   632,    -1,   284,
     292,   115,   632,    -1,    56,   284,   292,    -1,    98,    30,
      -1,   158,   631,   189,    -1,    30,    -1,   631,   109,    30,
      -1,    -1,   633,    -1,   634,    -1,   633,   634,    -1,   203,
     630,    -1,   138,   630,    -1,   270,    30,    -1,   289,    -1,
      56,   289,    -1,    98,   220,    -1,    98,   260,    -1,   261,
     256,    -1,   273,   639,   286,    -1,   262,   484,    -1,    98,
     131,   484,    -1,    98,    53,   484,    -1,   263,   484,   201,
     484,    -1,   278,   641,    -1,   258,   641,    -1,   281,    -1,
     274,    -1,   291,   256,   486,    -1,   156,   187,    -1,   156,
     419,   187,    -1,   316,   317,    -1,   316,   419,   317,    -1,
     318,   319,    -1,   318,   419,   319,    -1,   155,   647,   186,
      -1,   658,   123,   420,    -1,   420,   123,   420,    -1,   647,
     109,   420,   123,   420,    -1,   647,   109,   658,   123,   420,
      -1,   232,   320,   420,   239,   420,    -1,   232,   320,   647,
     239,   420,    -1,   232,   320,   420,   239,   420,    98,   322,
     420,    -1,   232,   420,   239,   420,    -1,   232,   647,   239,
     420,    -1,   232,   420,   239,   420,    98,   322,   420,    -1,
     321,   320,   420,   239,   420,    -1,   321,   420,   239,   420,
      -1,   230,   320,   508,    -1,   230,   508,    -1,   234,   320,
     508,    96,   420,    -1,   234,   508,    96,   420,    -1,   235,
     320,   236,   237,   508,   243,   420,    -1,   235,   236,   237,
     508,   243,   420,    -1,   654,    -1,   655,    -1,   656,    -1,
     325,   158,   189,    -1,   325,    -1,   323,   158,   189,    -1,
     323,    -1,   324,   158,   189,    -1,   324,    -1,    30,    -1,
      16,    -1,   659,    -1,   660,    -1,    99,    -1,    40,    -1,
      45,    -1,    54,    -1,    46,    -1,    49,    -1,   231,    -1,
      61,    -1,    63,    -1,    64,    -1,    72,    -1,    75,    -1,
      74,    -1,   213,    -1,   249,    -1,   661,    -1,    25,    -1,
     217,    -1,   129,    -1,    39,    -1,   267,    -1,    38,    -1,
     228,    -1,   227,    -1,   148,    -1,    44,    -1,   265,    -1,
     266,    -1,   280,    -1,   269,    -1,   257,    -1,   291,    -1,
     283,    -1,   285,    -1,   284,    -1,   289,    -1,   261,    -1,
     256,    -1,    80,    -1,   220,    -1,   260,    -1,    53,    -1,
     229,    -1,   242,    -1,   308,    -1,   236,    -1,   205,    -1,
     210,    -1,   209,    -1,   208,    -1,   207,    -1,   206,    -1,
      98,    -1,   113,    -1,   114,    -1,   188,    -1,    47,    -1,
      37,    -1,    68,    -1,    73,    -1,    60,    -1,    55,    -1,
      57,    -1,    79,    -1,    43,    -1,   149,    -1,    52,    -1,
     214,    -1,   172,    -1,   173,    -1,   170,    -1,    71,    -1,
      97,    -1,   118,    -1,   130,    -1,   131,    -1,   108,    -1,
      69,    -1,   137,    -1,   190,    -1,   102,    -1,    96,    -1,
     200,    -1,   128,    -1,   169,    -1,    94,    -1,    51,    -1,
     237,    -1,   103,    -1,   201,    -1,   119,    -1,   161,    -1,
     203,    -1,   152,    -1,   138,    -1,    77,    -1,    78,    -1,
     104,    -1,   202,    -1,   153,    -1,   184,    -1,   198,    -1,
     162,    -1,   139,    -1,   133,    -1,   168,    -1,   150,    -1,
     167,    -1,    34,    -1,    41,    -1,    59,    -1,   115,    -1,
      42,    -1,    58,    -1,   219,    -1,    50,    -1,    62,    -1,
      35,    -1,    48,    -1,   279,    -1,   255,    -1,   288,    -1,
     290,    -1,   259,    -1,   273,    -1,   286,    -1,   278,    -1,
     258,    -1,   272,    -1,   287,    -1,   277,    -1,   271,    -1,
     270,    -1,   254,    -1,   253,    -1,   262,    -1,   263,    -1,
     292,    -1,   282,    -1,   281,    -1,   276,    -1,   274,    -1,
     275,    -1,   241,    -1,   238,    -1,   225,    -1,   224,    -1,
     226,    -1,   243,    -1,   233,    -1,   240,    -1,   239,    -1,
      67,    -1,    65,    -1,    76,    -1,   171,    -1,   204,    -1,
     248,    -1,   246,    -1,   247,    -1,   244,    -1,   245,    -1,
     250,    -1,   251,    -1,   252,    -1,    66,    -1,   301,    -1,
     299,    -1,   300,    -1,   305,    -1,   306,    -1,   307,    -1,
     302,    -1,   303,    -1,   304,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    89,    -1,    90,    -1,    91,    -1,   293,    -1,
     294,    -1,   295,    -1,   296,    -1,   297,    -1,   298,    -1,
     309,    -1,   310,    -1,   311,    -1,   312,    -1,   313,    -1,
     314,    -1,   315,    -1,    92,    -1,   107,    -1,   116,    -1,
     174,    -1,   182,    -1,   191,    -1,   140,    -1,    93,    -1,
     117,    -1,   141,    -1,   183,    -1,   322,    -1,    26,    -1
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
    1377,  1379,  1382,  1384,  1388,  1392,  1396,  1400,  1401,  1406,
    1410,  1414,  1418,  1420,  1426,  1428,  1432,  1433,  1435,  1437,
    1441,  1443,  1447,  1451,  1453,  1457,  1461,  1465,  1469,  1471,
    1475,  1479,  1481,  1485,  1489,  1491,  1496,  1498,  1503,  1505,
    1510,  1512,  1517,  1519,  1522,  1524,  1527,  1529,  1531,  1534,
    1537,  1539,  1541,  1543,  1545,  1549,  1551,  1553,  1555,  1557,
    1559,  1561,  1563,  1565,  1567,  1572,  1578,  1584,  1591,  1595,
    1600,  1602,  1605,  1609,  1612,  1615,  1617,  1619,  1621,  1623,
    1625,  1627,  1629,  1631,  1633,  1635,  1638,  1642,  1647,  1651,
    1655,  1659,  1663,  1667,  1669,  1672,  1676,  1678,  1680,  1682,
    1684,  1686,  1688,  1690,  1692,  1694,  1696,  1698,  1700,  1702,
    1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1720,  1722,
    1725,  1728,  1732,  1734,  1739,  1744,  1748,  1753,  1755,  1759,
    1761,  1765,  1767,  1769,  1773,  1777,  1779,  1781,  1783,  1785,
    1787,  1792,  1801,  1807,  1817,  1827,  1838,  1840,  1843,  1845,
    1848,  1855,  1856,  1858,  1862,  1866,  1867,  1869,  1871,  1873,
    1876,  1879,  1880,  1882,  1884,  1886,  1889,  1892,  1894,  1896,
    1898,  1900,  1902,  1904,  1906,  1908,  1910,  1912,  1914,  1918,
    1922,  1925,  1929,  1933,  1936,  1938,  1940,  1942,  1944,  1946,
    1948,  1950,  1955,  1959,  1967,  1971,  1979,  1984,  1989,  1993,
    2001,  2005,  2013,  2016,  2018,  2021,  2025,  2028,  2030,  2032,
    2034,  2036,  2038,  2042,  2044,  2048,  2050,  2052,  2054,  2056,
    2058,  2062,  2064,  2066,  2068,  2070,  2072,  2074,  2076,  2078,
    2080,  2082,  2084,  2086,  2090,  2094,  2099,  2104,  2108,  2112,
    2116,  2120,  2125,  2130,  2134,  2139,  2146,  2151,  2158,  2163,
    2167,  2172,  2179,  2186,  2191,  2198,  2205,  2210,  2212,  2215,
    2217,  2219,  2221,  2226,  2232,  2239,  2243,  2247,  2251,  2255,
    2261,  2269,  2277,  2283,  2289,  2295,  2303,  2311,  2317,  2323,
    2327,  2331,  2337,  2345,  2351,  2359,  2361,  2366,  2370,  2376,
    2378,  2381,  2385,  2389,  2391,  2395,  2398,  2399,  2401,  2403,
    2406,  2408,  2412,  2414,  2418,  2420,  2425,  2427,  2430,  2434,
    2435,  2437,  2438,  2440,  2445,  2448,  2452,  2454,  2455,  2457,
    2462,  2463,  2465,  2468,  2470,  2474,  2475,  2477,  2480,  2483,
    2485,  2486,  2488,  2489,  2491,  2493,  2495,  2497,  2499,  2501,
    2503,  2507,  2511,  2513,  2515,  2517,  2520,  2524,  2526,  2528,
    2530,  2532,  2534,  2536,  2538,  2540,  2543,  2546,  2548,  2550,
    2553,  2556,  2560,  2562,  2565,  2568,  2574,  2577,  2579,  2581,
    2582,  2585,  2587,  2591,  2596,  2597,  2600,  2601,  2604,  2609,
    2614,  2618,  2621,  2625,  2627,  2631,  2632,  2634,  2636,  2639,
    2642,  2645,  2648,  2650,  2653,  2656,  2659,  2662,  2666,  2669,
    2673,  2677,  2682,  2685,  2688,  2690,  2692,  2696,  2699,  2703,
    2706,  2710,  2713,  2717,  2721,  2725,  2729,  2735,  2741,  2747,
    2753,  2762,  2767,  2772,  2780,  2786,  2791,  2795,  2798,  2804,
    2809,  2817,  2824,  2826,  2828,  2830,  2834,  2836,  2840,  2842,
    2846,  2848,  2850,  2852,  2854,  2856,  2858,  2860,  2862,  2864,
    2866,  2868,  2870,  2872,  2874,  2876,  2878,  2880,  2882,  2884,
    2886,  2888,  2890,  2892,  2894,  2896,  2898,  2900,  2902,  2904,
    2906,  2908,  2910,  2912,  2914,  2916,  2918,  2920,  2922,  2924,
    2926,  2928,  2930,  2932,  2934,  2936,  2938,  2940,  2942,  2944,
    2946,  2948,  2950,  2952,  2954,  2956,  2958,  2960,  2962,  2964,
    2966,  2968,  2970,  2972,  2974,  2976,  2978,  2980,  2982,  2984,
    2986,  2988,  2990,  2992,  2994,  2996,  2998,  3000,  3002,  3004,
    3006,  3008,  3010,  3012,  3014,  3016,  3018,  3020,  3022,  3024,
    3026,  3028,  3030,  3032,  3034,  3036,  3038,  3040,  3042,  3044,
    3046,  3048,  3050,  3052,  3054,  3056,  3058,  3060,  3062,  3064,
    3066,  3068,  3070,  3072,  3074,  3076,  3078,  3080,  3082,  3084,
    3086,  3088,  3090,  3092,  3094,  3096,  3098,  3100,  3102,  3104,
    3106,  3108,  3110,  3112,  3114,  3116,  3118,  3120,  3122,  3124,
    3126,  3128,  3130,  3132,  3134,  3136,  3138,  3140,  3142,  3144,
    3146,  3148,  3150,  3152,  3154,  3156,  3158,  3160,  3162,  3164,
    3166,  3168,  3170,  3172,  3174,  3176,  3178,  3180,  3182,  3184,
    3186,  3188,  3190,  3192,  3194,  3196,  3198,  3200,  3202,  3204,
    3206,  3208,  3210,  3212,  3214,  3216,  3218,  3220,  3222,  3224,
    3226,  3228,  3230,  3232,  3234,  3236,  3238,  3240,  3242,  3244,
    3246,  3248,  3250,  3252,  3254,  3256,  3258,  3260,  3262,  3264,
    3266,  3268,  3270,  3272,  3274,  3276,  3278
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,  1070,  1070,  1071,  1075,  1079,  1087,  1093,  1097,  1106,
    1112,  1120,  1126,  1137,  1142,  1146,  1151,  1160,  1167,  1174,
    1183,  1190,  1198,  1206,  1214,  1225,  1230,  1237,  1244,  1256,
    1266,  1273,  1280,  1292,  1293,  1294,  1295,  1296,  1301,  1302,
    1303,  1304,  1305,  1306,  1307,  1310,  1315,  1320,  1328,  1336,
    1344,  1349,  1357,  1362,  1370,  1375,  1383,  1388,  1393,  1398,
    1406,  1408,  1411,  1421,  1426,  1434,  1442,  1453,  1460,  1471,
    1476,  1484,  1491,  1498,  1507,  1520,  1528,  1535,  1545,  1552,
    1559,  1570,  1571,  1572,  1573,  1574,  1575,  1576,  1577,  1582,
    1588,  1597,  1604,  1614,  1624,  1625,  1626,  1627,  1628,  1629,
    1630,  1631,  1632,  1633,  1638,  1646,  1654,  1662,  1669,  1677,
    1684,  1689,  1697,  1705,  1719,  1733,  1750,  1755,  1763,  1771,
    1782,  1787,  1796,  1801,  1808,  1813,  1823,  1828,  1837,  1843,
    1856,  1861,  1869,  1880,  1895,  1907,  1922,  1927,  1932,  1937,
    1945,  1952,  1963,  1968,  1978,  1987,  1996,  2005,  2017,  2021,
    2027,  2031,  2041,  2051,  2064,  2070,  2079,  2084,  2091,  2098,
    2109,  2119,  2129,  2139,  2157,  2177,  2181,  2186,  2193,  2197,
    2202,  2209,  2214,  2226,  2233,  2243,  2258,  2259,  2260,  2261,
    2262,  2263,  2264,  2266,  2267,  2268,  2269,  2270,  2275,  2280,
    2288,  2305,  2313,  2321,  2328,  2335,  2346,  2355,  2364,  2373,
    2386,  2394,  2402,  2410,  2425,  2430,  2438,  2452,  2469,  2494,
    2502,  2509,  2520,  2530,  2535,  2548,  2565,  2566,  2567,  2568,
    2569,  2570,  2575,  2576,  2579,  2580,  2581,  2582,  2583,  2586,
    2587,  2588,  2589,  2590,  2595,  2609,  2617,  2622,  2630,  2635,
    2640,  2648,  2657,  2669,  2679,  2692,  2700,  2701,  2702,  2707,
    2708,  2709,  2710,  2711,  2716,  2723,  2733,  2739,  2748,  2757,
    2758,  2766,  2773,  2781,  2793,  2803,  2813,  2823,  2833,  2843,
    2853,  2863,  2874,  2883,  2893,  2903,  2919,  2928,  2937,  2945,
    2951,  2963,  2971,  2981,  2989,  3001,  3007,  3018,  3020,  3024,
    3032,  3036,  3041,  3045,  3049,  3053,  3063,  3071,  3078,  3084,
    3094,  3098,  3102,  3110,  3118,  3126,  3138,  3146,  3152,  3162,
    3168,  3178,  3182,  3192,  3198,  3204,  3210,  3219,  3228,  3237,
    3250,  3254,  3262,  3268,  3278,  3286,  3295,  3308,  3315,  3327,
    3331,  3343,  3350,  3356,  3365,  3372,  3378,  3389,  3396,  3402,
    3411,  3420,  3427,  3438,  3445,  3457,  3463,  3475,  3481,  3492,
    3498,  3509,  3515,  3526,  3532,  3543,  3552,  3556,  3565,  3569,
    3576,  3580,  3593,  3597,  3607,  3614,  3623,  3633,  3632,  3646,
    3655,  3664,  3677,  3681,  3693,  3697,  3705,  3708,  3715,  3719,
    3728,  3732,  3736,  3744,  3748,  3754,  3760,  3766,  3776,  3780,
    3784,  3792,  3796,  3802,  3812,  3816,  3826,  3830,  3840,  3844,
    3854,  3858,  3868,  3872,  3881,  3885,  3893,  3897,  3901,  3905,
    3915,  3919,  3923,  3930,  3935,  3943,  3947,  3951,  3955,  3959,
    3963,  3971,  3975,  3979,  3987,  3991,  3995,  3999,  4010,  4016,
    4026,  4032,  4042,  4046,  4050,  4113,  4135,  4163,  4327,  4331,
    4341,  4345,  4349,  4353,  4362,  4366,  4370,  4374,  4378,  4383,
    4387,  4391,  4395,  4404,  4410,  4420,  4428,  4432,  4436,  4440,
    4444,  4448,  4452,  4456,  4460,  4464,  4469,  4473,  4477,  4481,
    4489,  4493,  4497,  4501,  4509,  4516,  4523,  4533,  4537,  4545,
    4553,  4557,  4565,  4573,  4581,  4635,  4639,  4661,  4667,  4673,
    4679,  4689,  4693,  4701,  4709,  4721,  4725,  4733,  4737,  4741,
    4749,  4757,  4774,  4782,  4799,  4818,  4842,  4848,  4859,  4865,
    4876,  4885,  4887,  4891,  4896,  4906,  4909,  4916,  4922,  4928,
    4935,  4947,  4950,  4957,  4963,  4969,  4976,  4987,  4991,  4999,
    5003,  5011,  5015,  5019,  5024,  5033,  5037,  5041,  5045,  5053,
    5058,  5066,  5071,  5079,  5087,  5092,  5097,  5102,  5107,  5112,
    5117,  5123,  5131,  5135,  5152,  5156,  5164,  5172,  5180,  5184,
    5192,  5196,  5204,  5212,  5216,  5220,  5225,  5260,  5266,  5272,
    5282,  5286,  5290,  5295,  5299,  5304,  5308,  5312,  5316,  5323,
    5329,  5339,  5347,  5355,  5359,  5363,  5367,  5371,  5375,  5379,
    5383,  5387,  5391,  5399,  5407,  5411,  5415,  5423,  5430,  5438,
    5446,  5450,  5454,  5462,  5466,  5472,  5478,  5482,  5492,  5500,
    5504,  5510,  5519,  5528,  5534,  5540,  5550,  5567,  5574,  5589,
    5616,  5620,  5628,  5636,  5640,  5651,  5668,  5674,  5680,  5690,
    5694,  5700,  5706,  5710,  5716,  5720,  5726,  5732,  5739,  5749,
    5754,  5762,  5768,  5778,  5800,  5809,  5815,  5828,  5842,  5849,
    5855,  5865,  5874,  5882,  5888,  5906,  5914,  5918,  5925,  5930,
    5938,  5942,  5949,  5953,  5960,  5964,  5971,  5975,  5984,  5997,
    6000,  6008,  6011,  6019,  6027,  6035,  6039,  6047,  6050,  6058,
    6070,  6073,  6081,  6093,  6099,  6109,  6112,  6120,  6124,  6128,
    6136,  6139,  6147,  6150,  6158,  6162,  6166,  6170,  6174,  6182,
    6190,  6202,  6214,  6218,  6222,  6230,  6236,  6246,  6250,  6254,
    6258,  6262,  6266,  6270,  6274,  6282,  6286,  6290,  6294,  6302,
    6308,  6318,  6328,  6332,  6340,  6350,  6361,  6368,  6372,  6380,
    6383,  6390,  6395,  6404,  6414,  6417,  6424,  6428,  6436,  6445,
    6452,  6462,  6466,  6473,  6479,  6489,  6492,  6499,  6504,  6516,
    6524,  6536,  6544,  6548,  6556,  6560,  6564,  6572,  6580,  6584,
    6588,  6592,  6600,  6608,  6620,  6624,  6632,  6646,  6650,  6657,
    6662,  6670,  6675,  6684,  6692,  6699,  6705,  6712,  6723,  6729,
    6739,  6744,  6750,  6760,  6767,  6771,  6778,  6800,  6825,  6850,
    6878,  6903,  6931,  6935,  6939,  6946,  6951,  6958,  6963,  6970,
    6975,  6987,  6991,  6992,  7005,  7006,  7007,  7008,  7009,  7010,
    7012,  7013,  7014,  7015,  7016,  7017,  7018,  7019,  7020,  7021,
    7025,  7026,  7027,  7028,  7029,  7030,  7031,  7032,  7033,  7034,
    7035,  7036,  7037,  7038,  7039,  7040,  7041,  7042,  7043,  7044,
    7045,  7046,  7047,  7048,  7049,  7050,  7051,  7052,  7053,  7054,
    7055,  7056,  7057,  7058,  7059,  7060,  7061,  7062,  7063,  7064,
    7065,  7066,  7067,  7068,  7069,  7070,  7071,  7072,  7073,  7074,
    7075,  7076,  7077,  7078,  7079,  7080,  7081,  7082,  7083,  7084,
    7085,  7086,  7087,  7088,  7089,  7090,  7091,  7092,  7093,  7094,
    7095,  7096,  7097,  7098,  7099,  7100,  7101,  7102,  7103,  7104,
    7105,  7106,  7107,  7108,  7109,  7110,  7111,  7112,  7113,  7114,
    7115,  7116,  7117,  7118,  7119,  7120,  7121,  7122,  7123,  7124,
    7125,  7126,  7127,  7128,  7129,  7130,  7131,  7132,  7133,  7134,
    7135,  7136,  7137,  7138,  7139,  7140,  7141,  7142,  7143,  7144,
    7145,  7146,  7147,  7148,  7149,  7150,  7151,  7152,  7154,  7155,
    7157,  7158,  7159,  7160,  7161,  7163,  7165,  7166,  7167,  7168,
    7169,  7170,  7171,  7172,  7173,  7174,  7175,  7176,  7177,  7178,
    7179,  7180,  7181,  7182,  7183,  7184,  7185,  7186,  7187,  7188,
    7189,  7190,  7191,  7192,  7193,  7194,  7195,  7196,  7197,  7198,
    7199,  7200,  7201,  7202,  7203,  7204,  7205,  7206,  7207,  7208,
    7209,  7210,  7211,  7212,  7213,  7214,  7215,  7216,  7217,  7218,
    7219,  7220,  7221,  7222,  7223,  7226,  7235
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
  const int jsoniq_parser::yylast_ = 19449;
  const int jsoniq_parser::yynnts_ = 321;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 544;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 341;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 595;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 18186 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7239 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"


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

