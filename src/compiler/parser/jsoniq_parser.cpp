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
#line 5222 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5257 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5263 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5269 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5279 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
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
#line 5288 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5292 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5296 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5300 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5304 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5311 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5317 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5327 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5335 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5343 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5347 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5351 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5355 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5359 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5363 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5367 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5371 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5379 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5387 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5395 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5399 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5403 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5411 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5418 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5426 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5434 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5438 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5442 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5450 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5454 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5460 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5466 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5470 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5480 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5488 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5492 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5498 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5507 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5516 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5522 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5528 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5538 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5555 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5562 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5577 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5604 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5616 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5624 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5628 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5639 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5656 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5662 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5668 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5678 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5688 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5694 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5698 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5714 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5727 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5737 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5766 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5788 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5797 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5803 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5816 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5830 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5837 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5843 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5853 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5862 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5870 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5876 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5894 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5902 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5906 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5918 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5937 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5941 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5948 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5952 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5959 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5963 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5972 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5995 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5999 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 6007 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 6015 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6023 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6027 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 6034 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6038 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6057 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6061 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6069 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6081 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6087 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6096 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6100 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6108 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6112 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6116 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6123 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6127 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6134 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6138 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6146 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6150 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6154 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6158 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6162 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6170 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6178 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6190 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6202 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6206 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6210 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6218 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6224 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6234 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6238 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6242 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6246 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6250 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6254 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6258 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6262 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6270 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6274 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6278 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6282 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6290 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6296 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6306 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6316 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6320 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6328 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 722:

/* Line 690 of lalr1.cc  */
#line 6338 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 723:

/* Line 690 of lalr1.cc  */
#line 6349 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6356 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6360 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6367 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6371 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6378 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6383 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6392 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6401 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6405 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6412 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6416 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6424 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6433 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6440 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6450 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6454 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6461 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6467 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6476 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6480 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6487 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6492 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6504 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6512 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6524 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6532 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6536 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6544 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6548 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6552 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6560 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6568 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6572 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6576 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6580 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6588 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6596 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6608 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6612 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6620 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6634 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6638 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6645 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6650 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6658 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6663 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6672 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6680 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6687 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6693 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6700 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6711 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6717 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 777:

/* Line 690 of lalr1.cc  */
#line 6727 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6734 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6741 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 780:

/* Line 690 of lalr1.cc  */
#line 6766 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 781:

/* Line 690 of lalr1.cc  */
#line 6794 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 782:

/* Line 690 of lalr1.cc  */
#line 6822 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6826 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6830 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6854 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 792:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6979 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6980 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6983 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6984 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6985 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6986 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6987 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6989 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6990 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6991 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6992 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6993 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6994 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6995 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6996 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6997 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6998 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6999 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 7000 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 7001 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 7002 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 7003 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 7004 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 7005 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 7006 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 7007 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 7008 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 7009 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 7010 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 7011 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 7012 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 7013 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 7014 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 7015 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 7016 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 7017 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 7018 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 7019 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 7020 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 7021 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 7022 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 7023 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 7024 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 7025 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 7026 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 7027 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 7028 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 7029 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 7030 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 7031 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 7032 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 7033 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 7034 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 7035 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 7036 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 7037 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 7038 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 7039 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 7040 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 7041 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 7042 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 7043 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 7044 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 7045 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 7046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 7047 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 7048 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 7049 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 7050 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 7051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 7052 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 7053 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 7054 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 7055 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 7056 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 7057 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 7058 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 7059 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 7060 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 7061 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 7062 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 7063 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 7064 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 7065 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 7066 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 7067 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 7068 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 7069 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 7070 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 7071 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 7072 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 7073 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 7074 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 7075 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 7076 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 7077 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 7078 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 7079 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 7080 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 7081 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 7082 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 7083 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 7084 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 7085 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 7086 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 7087 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 7088 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 7089 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 7090 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 7091 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7092 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 7093 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 7094 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 7095 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 7096 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 7097 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 7098 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 7099 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 7100 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 7101 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 7102 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 7103 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 7104 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 7108 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 7113 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12110 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1450;
  const short int
  jsoniq_parser::yypact_[] =
  {
      6936,  8776,  8776,  8776,  8776, -1450, -1450,    35,   244, -1450,
     114,    21, -1450, -1450, -1450,   302, -1450, -1450, -1450,   341,
   -1450,   493,    42,   600,   649,   790, -1450,   -15, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450,   527, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450,   774, -1450,   681, -1450,   768,   779, -1450,
     361, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450,   691, -1450, -1450, -1450, -1450, -1450, -1450, -1450,   797,
   -1450, -1450, -1450, -1450, -1450, 17512, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450,   866, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450,  4811, 10918, 11224, 17512, -1450, -1450,
     834, -1450, -1450, -1450, -1450,   844, -1450, -1450, -1450,  6332,
   -1450,  6630, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450,   867, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450,   130,   813,   822, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450,   262, -1450,   418, -1450,
     113,   156, -1450, -1450, -1450, -1450, -1450, -1450,   929, -1450,
     815,   817,   820, -1450, -1450,   905,   912, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,   783,
   -1450, 13978, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   11530, 11836, -1450,   749, -1450, -1450,  7244,  7552,  1070, -1450,
    9082, -1450, -1450,   592,    96, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,    99,
   -1450, -1450, -1450, -1450, -1450, -1450,   112, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450,  8776, -1450, -1450, -1450, -1450,
      25, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,   163,
   -1450,   879, -1450, -1450, -1450,   436, -1450,   745, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450,   903,   979, -1450, -1450,   893,
     823,   974,   726,   635,   161,   676, -1450,  1025,   875,   988,
     989, 12754, -1450,   897, -1450, -1450,   680, -1450, -1450, -1450,
   -1450,   762, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450,   947,   937, -1450, -1450, -1450,
   -1450, -1450,   910, -1450,  8776,   911,   920,   922,  8776,   424,
     424,  1079,   741,   748,   658, 17805, 17512,   512,  1062, 17512,
     957,   993,   687,  6332,   816,   863, 17512, 17512,   804,   819,
      67, -1450, -1450, -1450,  6332,  8776,  8776, 13060,   381,   961,
   13060,  1116,    73,    63, 17512,   999,   976,  1009, -1450, 13060,
   17512,  8776, 13060, 13060, 17512,  8776,   966,   969, 13060, 17512,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450,   981, -1450, 17512, -1450, -1450,   940,  7858,
    1004,   291,  1005,   947,   971,   972,   973, 17512,  5118, -1450,
     978,   129, -1450,   564, -1450,    97,  1098, 13060, 13060,    93,
   -1450, -1450, -1450,  1118, 13060,   924, -1450,  1106,  1107, 13060,
   13060, 14284, 13060, 13060,  5425, 13060, 14284, 13060,   901,   906,
   17512,   949,   951, 13060, 13060,  8164,   888, -1450, -1450,    58,
   -1450,    57, 13060,  7552, -1450, -1450, -1450, -1450, -1450,   114,
     790,   105,   109,  1141,  9388,  3237,  9694,  3560,   797, -1450,
   -1450,   168,   797, -1450, 13060,  4192, -1450,  1026, -1450,   -15,
     975,   977,   980,  8776, 13060, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, 17512, -1450,   857,   858, 17512,  1030,
   13366, 13366, 13672, -1450, 13672, 13672, -1450, 13672, -1450, 13672,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, 13672, 13672,  1081,
   13672, 13672, 13672, 13672, 13672, 13672, 13672, 13672, 13672, 13672,
   13672, 13672,   914,  1058,  1059,  1060, -1450, -1450, -1450, 14284,
   12142, -1450,  5728, 13060, 10000,  1001, -1450,  1007, 10306, -1450,
   -1450, -1450, -1450,    15, -1450,   328, -1450, -1450, -1450, -1450,
   -1450, -1450,  1050,  1051,   600,  1131, -1450, -1450, 17805,   998,
     725, 17512,  1002,  1008,   998,  1079,  1034,  1032, -1450, -1450,
   -1450,   330,   919,  1073,   869, 17512,  1031, 13060,  1056, 17512,
   17512, -1450,  1043,   992,   995,   148, 17512,  1086,   339, -1450,
    8776, -1450,    98, -1450,  6332,  1085,  1142,  6332,  1079,  1089,
     612, 17512, 13060,   -15,   169,   226, -1450,   640,  1006,   121,
     128,  1036, -1450,  1012,  8776,  8776,   292,   633, 13060,   284,
   -1450, -1450, 13060,  5425, -1450, 13060, 13060, 13060, 13060, -1450,
   13060, -1450, 13060, -1450, 17512,  1098, -1450,   497,   366,   388,
   -1450, -1450, -1450,   405, -1450,   500,   558, -1450, -1450,   762,
     430,   578,    -7,     4,  1097,   683,   952,   963,   964,    -1,
   -1450,  1061, -1450, -1450,  1010,   147,  7858,   458,  4504,   888,
   -1450, -1450, -1450,   967, -1450,   592,   821,  1166,   697, -1450,
   -1450,   110, -1450, -1450, -1450,   120, -1450,    44, -1450, -1450,
   -1450, -1450, -1450,  3876, -1450, -1450, -1450, 17512,  1039, 13060,
    1083, -1450, -1450, -1450,  1099, -1450,    49, -1450, -1450,  1099,
   17512,    39,   979, -1450, -1450, -1450, -1450, -1450, 13672, -1450,
   -1450, -1450,   259, -1450,   635,   635,   589,   161,   161,   161,
     161,   676,   676, -1450, -1450, 16047, 16047, 17512, 17512, -1450,
   -1450,   470, -1450, -1450, -1450, -1450, -1450,   136, -1450, -1450,
   -1450,   352, -1450, -1450, -1450,   353,   424, -1450, -1450,   255,
     786,   759, -1450,   600, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450,   998, -1450,  1078, 16340,  1071, 13060,
   -1450, -1450, -1450,  1121,  1079,  1079,   998, -1450,   917,  1079,
     720, 17512,   372,   398,  1184, -1450, -1450,   927,   582, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
     330,    72,   987,   688, 13060, -1450, 17512,  1125,   926,  1079,
   -1450, -1450,  1067,  1121, 16047,  1104,  1133,  1041,  1033,  1100,
    1079,  1074,  1103,  1134,  1079, 16047, 13060,   -37, -1450, -1450,
   -1450,  1084,  1120, 13060, 13060,  1093, -1450,  1136,  1144,  8776,
   -1450,  1057,  1063,  1092, 13060,  1110,  1052, 13060, -1450,  1127,
    1128, -1450,   159,   191,   215,  1212, -1450,   504, -1450,   513,
    1101, -1450, -1450,  1225, -1450,  1227, -1450,   791, 13060, 13060,
   13060,   799, 13060, 13060, 13060, 13060, 13060, 13060, 13060, 13060,
   13060, 14284,  1139, 13060, 13060, -1450, 10612,   358,  1011, -1450,
   -1450, -1450, -1450, -1450, -1450,    -9, -1450, -1450, 13060,   127,
     146,    44,  9694,  3560,  9694,  1179, -1450, -1450, 13060,   711,
    1152, -1450, 17512,  1155, -1450, 17219,  1137,  1145, 13060,    53,
    1122,    52,   648,  1013, -1450, -1450,   793,    39, -1450, 13060,
     259,   744,   682, -1450,   983,   150,  1003,  1014, -1450, -1450,
     863, -1450,   996,   -57,  1112,  1117,  1119,  1123,  1124,  1129,
    1130,  1132,  1135,  1138, -1450, 14875,  1140, -1450, -1450, -1450,
    1143, -1450,   609, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450,  1146, -1450, -1450, -1450,
   -1450, 12448, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450,   805, -1450,  1246, 16340,   871, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450,   986, -1450, -1450,  1249, -1450,
   -1450, -1450, -1450, -1450,   732,  1255, -1450,   840, -1450, -1450,
   -1450,  1112,  1117,  1119,  1124,  1129,  1130,  1132,  1135,  1138,
    1140, -1450,   609,   609, 14284,  1015,   985, -1450,  1121,    72,
    1066,  1108,  8776, -1450, -1450, -1450, 16047, -1450,  8776,  1079,
    1180, -1450, -1450, -1450,  1079,  1180, -1450, -1450, 13060,  1147,
    8776, 17512, -1450, -1450, 13060, 13060,   846, -1450,    78,   862,
   -1450, 15168,   873, -1450,   877, -1450,  1109, -1450, -1450,  8776,
   -1450, 13060, -1450, -1450, 13060, 13060,  1105,  1136,  1201, -1450,
    1170, -1450,   554, -1450, -1450,  1299, -1450, -1450,  8776, 17512,
   -1450,   753, -1450, -1450, -1450,  8776,  1115,  1126,  1072,  1075,
   -1450, -1450, -1450,  1076,  1077, -1450, -1450, -1450,  1211, -1450,
   -1450, -1450, -1450,  1069,   308, 17512,  1148, -1450,  1159,  1161,
    1162,  1158, -1450,   879,   587,  4504,  1011, -1450,  8470,  4504,
   -1450, -1450,  1166,   535, -1450, -1450, -1450,  1152, -1450,  1079,
   -1450,   923, -1450,    83,  1202, -1450, 13060,   716,  1083, 17512,
   -1450,   314, 17512, -1450, 13060,  1172, 13060,  1193, 13060,   111,
    1174, 13060,  1175, -1450,  1205,  1208, 13060, 17512,   956,  1250,
   -1450, -1450, -1450,   484,  1150, -1450,   259,  1087, -1450, -1450,
     433, -1450,   713,    88,  1088,   259,   713, 13672, -1450,   533,
   -1450, -1450, -1450, -1450, -1450, -1450,   259,  1182,  1044,   919,
      88, -1450, -1450,  1048,  1253, -1450, -1450, -1450,  1153,   172,
   16633, 14582,  1157,  6030, 17512, 17512,  1160, 16926, -1450,  1163,
    1164,  1167, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450,  1305,    41,  1311,    41,  1080,
    1238, -1450, -1450,  1176, 17512,  1095, -1450, -1450, 14284, -1450,
    1165, -1450,  1222,  1231,  1262,  1079,  1180, -1450, 13060,  1177,
   -1450, -1450, -1450,  1178, -1450,   268, 13060,  8776,  1183,   277,
   -1450, 17512,   663, -1450, 15461,    34, -1450, 15754,  1187, -1450,
   -1450,  1181, -1450, -1450, -1450, 13060,   880,  1212, 17512,   776,
   -1450,  1190,  1212, 17512, -1450,  1191, -1450, -1450, 13060, 13060,
   13060, 13060,  1040, 13060, 13060, -1450, 13060, 13060, 13060, 13060,
   10612,   208, -1450, -1450, -1450, -1450, -1450,  1202, -1450, -1450,
   -1450,  1079, 13060, -1450,  1220, -1450, -1450, 13060,  1219, -1450,
   -1450, 13060, -1450,   522, -1450, 13060,  1229, 13060, -1450, 13060,
   17512, 17512, -1450,   778, -1450, 13060, -1450, -1450, -1450,  1194,
   13672, -1450, -1450, -1450, -1450, -1450,   494, 13672, 13672,   665,
   -1450,  1003, -1450,   524, -1450,  1014,   259,  1226, -1450, -1450,
    1096, -1450, -1450, -1450, -1450, -1450, -1450,  1195,  1196, -1450,
     364,   377,  1287,  1197, -1450,   396, -1450,  1198, -1450,  1199,
    1200,  1203, -1450, -1450,   410,   477, -1450, -1450, -1450, -1450,
     422,   422, -1450,    41, -1450, -1450,   499, -1450,  1360,    76,
    1293,  1204, 14284,   -32,  1102,  1224, -1450, 10612, 13060,  1079,
   -1450, -1450, -1450, 13060, 13060, -1450, -1450, -1450, 10612, 10612,
    1298,  8776, 16047, 17512,   704, 17512, 13060, 17512,   712, 10612,
   -1450,   327,    56,  1212, 17512, -1450,  1206,  1212, -1450, -1450,
   -1450, -1450, -1450, 13060, -1450, -1450, -1450,   230,   232,   238,
   13060, -1450, -1450, -1450,  1290, 13060, -1450, 13060, -1450, 13060,
    1251, -1450, 13060, -1450, -1450, -1450,  1346, -1450, -1450, -1450,
     161, 13672, 13672,   589,   727, -1450, -1450, -1450, -1450, -1450,
   -1450, 13060, -1450, -1450, -1450, 17512, -1450, 17512, -1450, 16047,
   -1450, 16047,  1307, -1450, -1450, -1450, -1450, 17512, -1450, 17512,
   -1450, -1450, -1450, -1450,  1374, -1450, -1450, -1450,  1149,  1300,
   -1450, -1450,  1301, -1450,    86, 17512,  1288,  1185, 17512, 14284,
   -1450, -1450,  1180, -1450, -1450, 16047, -1450, -1450, -1450,  1315,
   13060,  1233, -1450,  1316, 10612, -1450, 17512,   618,   718, -1450,
    1214,  1212, -1450,  1215, -1450,  1217,  1136,  1144,   489, -1450,
    1290, -1450, -1450, 13060, -1450,  1295,   589,   589, 13672,   501,
    1230,  1234,  1276,  1235,  1236, -1450, -1450, 16047,  1237,  1239,
   -1450, -1450,  1293, 14284, -1450,  1202,  1151, 17512,  1309,  1207,
    1301,   721, 16047,  8776, 16047,  1242, -1450, -1450,  1332,   655,
   -1450, -1450, -1450, -1450,  1247,   752, -1450, -1450, -1450,  1232,
   -1450, 10612,   882, -1450, -1450, -1450, 17512,   589, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   13060,  1154, 17512,  1314,  8776,   731, -1450, -1450,   733, 13060,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450,  1317, -1450, -1450,
    1156,  1168, 17512, -1450, -1450, 13060, 10612, 17512,  1169, 13060,
    1171,  1248, 14284, -1450, 14284, 10612, -1450,  1240,  1189, 17512,
    1213,  1319, 17512,  1186, 14284, -1450
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   170,   170,   170,     0,   808,  1010,   122,   124,   616,
     900,   909,   849,   813,   811,   793,   901,   904,   856,   817,
     794,   796,   259,   910,   797,   907,   878,   858,   833,   795,
     853,   854,   905,   902,   852,   799,   908,   800,   801,   949,
     961,   948,   850,   869,   863,   802,   851,   804,   803,   950,
     887,   888,   855,   830,   971,   972,   973,   974,   975,   976,
     977,   978,   979,   980,   981,   995,  1002,   877,   873,   864,
     844,   792,   872,   880,   889,   996,   868,   474,   845,   846,
     903,   997,  1003,   865,   882,     0,   482,   476,   875,   810,
     866,   867,   896,   870,   886,   895,  1001,  1004,   816,   857,
     898,   475,   885,   891,     0,     0,     0,     0,   407,   883,
     894,   899,   897,   876,   862,   951,   860,   861,   998,     0,
     406,     0,   999,  1005,   892,   847,   871,  1000,   893,   874,
     881,   890,   884,   952,   838,   843,   842,   841,   840,   839,
     805,   859,     0,   809,     0,   906,   831,   473,   477,   478,
     940,   939,   941,   815,   814,   834,   946,   798,   938,   943,
     944,   935,   837,   879,   937,   947,   945,   936,   835,   942,
     956,   957,   954,   955,   953,   806,   958,   959,   960,   926,
     925,   912,   829,   822,   919,   915,   832,   828,   927,   260,
     818,   819,   812,   821,   924,   923,   920,   916,   933,   934,
     932,   922,   918,   911,   820,   931,   930,   824,   826,   825,
     917,   921,   913,   827,   914,   823,   929,   982,   983,   984,
     985,   986,   987,   963,   964,   962,   968,   969,   970,   965,
     966,   967,   836,   988,   989,   990,   991,   992,   993,   994,
       0,     0,  1006,  1007,  1008,  1009,   167,   167,     0,     2,
     167,     9,    11,    25,     0,    30,    33,    38,    39,    40,
      41,    42,    43,    44,    34,    60,    61,    35,    36,     0,
      78,    81,    82,    37,    83,    84,     0,   120,    85,    86,
      87,    88,    20,   164,   165,   166,   173,   176,   465,   177,
       0,   178,   179,   180,   181,   182,   183,   184,   187,     0,
     213,   221,   216,   248,   254,     0,   246,     0,   247,   223,
     217,   186,   218,   185,   219,   222,   356,   358,   360,   362,
     372,   374,   378,   380,   383,   388,   391,   394,   396,   398,
     400,     0,   404,   411,   410,   412,     0,   430,   413,   435,
     436,   437,   444,   456,   470,   472,   457,   458,   459,   462,
     463,   460,   464,   491,   492,   461,   495,   497,   498,   499,
     496,   544,   545,   546,   547,   548,   549,   550,   471,    45,
     224,   225,   227,   226,   228,   220,   467,   468,   469,   466,
     230,   233,   229,   231,   232,     0,   791,   807,   900,   909,
     907,   809,     0,   168,   169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   278,   279,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   793,   817,   796,   848,   910,   797,   858,   799,   869,
     802,   804,   803,   887,   792,   846,   870,   894,   951,   952,
     946,   938,   944,   935,   835,   956,   957,   954,   806,   958,
     928,   819,  1007,   479,   791,     0,   789,   189,     0,     0,
     213,     0,     0,   790,   797,   804,   803,     0,   170,   764,
     958,     0,   221,     0,   480,     0,   511,     0,     0,     0,
     790,   433,   434,     0,     0,     0,   540,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   361,   766,     0,
     768,     0,     0,   167,     3,     4,     1,    10,    12,     0,
       0,     0,     0,     6,   167,     0,   167,     0,     0,   121,
     174,     0,     0,   192,     0,     0,   201,     0,   259,     0,
       0,     0,     0,     0,     0,   260,   206,   234,   253,   249,
     255,   250,   252,   251,     0,   258,     0,     0,     0,     0,
       0,     0,     0,   423,     0,     0,   421,     0,   367,     0,
     422,   415,   420,   419,   418,   417,   416,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   409,   408,   405,     0,
       0,   431,     0,     0,     0,   445,   453,     0,     0,   552,
     554,   558,   560,     0,   126,     0,   788,    49,    46,    47,
      50,    51,     0,     0,     0,     0,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   623,   624,
     625,     0,   105,   144,     0,     0,   114,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,   136,     0,   140,
     170,   494,     0,    62,     0,    71,     0,     0,     0,    63,
       0,     0,     0,     0,     0,     0,   327,     0,     0,     0,
       0,     0,   614,     0,     0,     0,     0,   196,     0,     0,
     190,   188,     0,     0,   770,     0,     0,     0,     0,   479,
       0,   765,     0,   481,   512,   511,   508,     0,     0,     0,
     542,   541,   432,     0,   539,     0,     0,   636,   637,   779,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     642,     0,   204,   205,     0,     0,     0,     0,     0,   209,
     210,   767,   769,     0,     5,    26,     0,    27,     0,     7,
      31,     0,    17,     8,    32,     0,    21,   900,    79,    18,
      80,    22,   195,     0,   193,   214,   215,     0,     0,     0,
       0,   207,   235,   296,   257,   261,     0,   236,   237,   256,
       0,     0,   357,   359,   365,   371,   370,   369,     0,   366,
     363,   364,     0,   375,   382,   381,   379,   385,   386,   387,
     384,   389,   390,   393,   392,     0,     0,     0,     0,   414,
     428,     0,   452,   450,   449,   451,   448,     0,   487,   446,
     489,     0,   454,   493,   485,     0,     0,   123,   125,     0,
       0,     0,   104,     0,    94,    96,    97,    98,    99,   101,
     102,   103,    95,   100,    90,    91,     0,     0,   110,     0,
     106,   108,   109,   116,     0,     0,    89,    48,     0,     0,
       0,     0,     0,     0,     0,   714,   719,     0,     0,   715,
     749,   702,   704,   705,   706,   708,   710,   709,   707,   711,
       0,     0,     0,     0,     0,   113,     0,   146,     0,     0,
     557,   551,     0,   142,     0,     0,   137,     0,     0,     0,
       0,     0,     0,    64,     0,     0,     0,     0,   277,   283,
     280,     0,     0,     0,     0,     0,   556,     0,     0,     0,
     424,     0,     0,     0,     0,   197,     0,     0,   772,     0,
       0,   771,     0,     0,     0,   511,   509,     0,   500,     0,
       0,   483,   484,     0,    13,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   202,     0,     0,     0,   441,
     442,   443,   440,   650,   439,     0,   438,   211,     0,     0,
       0,     0,   167,     0,   167,     0,   175,   245,     0,   311,
     307,   309,     0,   297,   298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,   239,     0,   244,   368,     0,
       0,     0,     0,   680,   376,   653,   657,   659,   661,   663,
     666,   673,   674,   682,   793,   794,   796,   910,   795,   799,
     800,   801,   802,   792,   571,     0,   798,   786,   787,   785,
    1009,   395,   563,   569,   570,   589,   580,   588,   587,   586,
     585,   582,   584,   581,   583,   573,   617,   618,   574,   575,
     782,   783,   784,   578,   397,   399,   402,   579,   401,   429,
     455,     0,   447,   486,   127,    58,    59,    56,    57,   133,
     132,     0,    92,     0,     0,     0,   111,   112,   117,    76,
      77,    54,    55,    75,   720,     0,   723,   750,     0,   713,
     712,   717,   716,   748,     0,     0,   725,     0,   721,   724,
     703,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   145,   148,   150,     0,     0,     0,   115,   118,     0,
       0,     0,   170,   143,   138,   141,     0,   191,     0,     0,
      73,    67,    70,    69,     0,    65,   562,   281,     0,     0,
     170,     0,   325,   329,     0,     0,     0,   332,     0,     0,
     338,     0,     0,   345,     0,   349,     0,   426,   425,   170,
     198,     0,   200,   326,     0,     0,     0,     0,     0,   512,
       0,   502,     0,   535,   532,     0,   536,   537,     0,     0,
     531,     0,   506,   534,   533,     0,     0,     0,     0,     0,
     629,   630,   626,     0,     0,   634,   635,   631,   775,   776,
     640,   780,   638,     0,     0,     0,     0,   644,   797,   804,
     803,   958,   203,     0,     0,     0,   645,   646,     0,     0,
     212,   778,    28,     0,    19,    23,    24,   308,   320,     0,
     321,     0,   312,   313,   314,   315,     0,   300,     0,     0,
     263,     0,     0,   264,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   240,     0,     0,     0,     0,   290,     0,
     287,   292,   243,     0,     0,   664,   677,     0,   373,   377,
       0,   696,     0,     0,     0,     0,     0,     0,   652,   654,
     655,   691,   692,   693,   695,   694,     0,     0,   668,   667,
       0,   671,   675,   689,   687,   686,   679,   683,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   565,     0,
       0,     0,   566,   568,   567,   564,   403,   488,   490,   135,
     134,    93,   107,   737,   718,     0,   742,     0,   742,   731,
     726,   149,   151,     0,     0,     0,   119,   147,     0,    29,
       0,   139,     0,     0,    72,     0,    66,   282,     0,     0,
     328,   330,   335,     0,   333,     0,     0,     0,     0,     0,
     339,     0,     0,   353,     0,     0,   346,     0,     0,   350,
     427,     0,   199,   773,   774,     0,     0,   511,     0,     0,
     543,     0,   511,     0,   507,     0,    14,    16,     0,     0,
       0,     0,     0,     0,     0,   643,     0,     0,     0,     0,
       0,     0,   647,   651,   324,   322,   323,   316,   317,   318,
     310,     0,     0,   305,     0,   299,   262,     0,     0,   276,
     268,     0,   272,     0,   266,     0,     0,     0,   285,     0,
       0,     0,   242,   288,   291,     0,   681,   672,   678,     0,
       0,   751,   752,   762,   761,   760,     0,     0,     0,     0,
     753,   658,   759,     0,   656,   660,     0,     0,   665,   669,
       0,   690,   685,   688,   684,   596,   591,     0,     0,   606,
       0,     0,     0,     0,   576,     0,   594,     0,   597,     0,
       0,     0,   595,   600,     0,     0,   622,   590,   572,   738,
       0,     0,   736,   743,   744,   740,     0,   735,     0,   733,
       0,     0,     0,     0,     0,     0,   553,     0,     0,     0,
      68,   284,   559,     0,     0,   336,   340,   334,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     555,     0,     0,   511,     0,   538,     0,   511,   561,   627,
     628,   632,   633,     0,   639,   781,   641,     0,     0,     0,
       0,   648,   319,   306,   301,     0,   265,     0,   274,     0,
       0,   270,     0,   273,   286,   294,   295,   289,   241,   676,
     763,     0,     0,   755,     0,   701,   700,   699,   698,   697,
     662,     0,   754,   592,   593,     0,   610,     0,   607,     0,
     619,     0,     0,   599,   598,   605,   613,     0,   603,     0,
     601,   747,   746,   745,     0,   739,   732,   730,     0,   727,
     728,   722,   152,   154,   156,     0,     0,     0,     0,     0,
     208,   355,    74,   331,   337,     0,   351,   347,   354,     0,
       0,     0,   341,     0,     0,   343,     0,   521,   515,   510,
       0,   511,   501,     0,   777,     0,     0,     0,     0,   304,
     302,   269,   267,     0,   275,     0,   757,   756,     0,     0,
       0,     0,   614,     0,     0,   620,   577,     0,     0,     0,
     741,   734,     0,     0,   158,   157,     0,     0,     0,     0,
     153,     0,     0,     0,     0,     0,   529,   523,     0,   522,
     524,   530,   527,   517,     0,   516,   518,   528,   503,     0,
     504,     0,     0,   649,   303,   271,     0,   758,   670,   611,
     612,   615,   608,   609,   621,   604,   602,   729,   155,   159,
       0,     0,     0,     0,     0,     0,   344,   342,     0,     0,
     514,   525,   526,   513,   519,   520,   505,     0,   293,   160,
       0,     0,     0,   352,   348,     0,     0,     0,     0,     0,
       0,     0,     0,   162,     0,     0,   161,     0,     0,     0,
       0,     0,     0,     0,     0,   163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1450, -1450,  -209,  -177, -1450,  1192,  1209, -1450,  1210,  -471,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
    -892, -1450, -1450, -1450, -1450,  -198,  -503, -1450,   771,   104,
   -1450, -1450, -1450, -1450, -1450,   331,   571, -1450, -1450,    22,
    -186,  1053, -1450,  1037, -1450, -1450,  -569, -1450,   525, -1450,
     293, -1450,  -205,  -257, -1450,  -481, -1450,    17,    27,    10,
    -275,  -161, -1450,  -793, -1450, -1450,   472, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450,   689,   -65,  1484,
       0, -1450, -1450, -1450, -1450,   423, -1450, -1450,  -282, -1450,
       5, -1450, -1450,   876,  -959,  -769,  -760, -1450, -1450,   758,
   -1450, -1450,    -5,   171, -1450, -1450, -1450,   193, -1203, -1450,
     454,   197, -1450, -1450,   201, -1194, -1450,   990,   295, -1450,
   -1450,   294,  -922, -1450, -1450,   288, -1450, -1450, -1181, -1158,
   -1450,   290, -1340, -1450, -1450,   896,  -147, -1450, -1450,  -384,
     868, -1450, -1450,  -591,   444,  -565,   389,   102, -1450, -1450,
   -1450,   650, -1450, -1450,  1173, -1450, -1450, -1450, -1450, -1450,
    -757,  -310,  -608, -1450, -1450,   228, -1450,  -464, -1450,   855,
   -1450,  -364, -1450, -1450,   859,   860, -1450, -1450, -1450, -1450,
     856, -1450, -1450, -1450, -1450,  -906, -1450,   281, -1450,   760,
    -711, -1450, -1450, -1450, -1450, -1450,  -239,  -232, -1140, -1139,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450,  -674,  -797,   -94,  -800, -1450, -1450, -1450,  -833, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450,   160,   162,  -656,
    -127,  -576, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
   -1450, -1450, -1450,   257, -1450, -1450,   247, -1450,   251,  -979,
   -1450, -1450, -1450,   192,   182,    14,   471, -1450, -1450, -1450,
   -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450, -1450,
     194, -1450, -1450, -1450,    23,   464,   605, -1450, -1450, -1450,
   -1450, -1450,   380, -1450, -1450, -1449, -1450, -1450, -1450,  -470,
   -1450,   151, -1450,   -12, -1450, -1450, -1450, -1450, -1243, -1450,
     202, -1450, -1450, -1450, -1450, -1450,  1000, -1450, -1450, -1450,
   -1450, -1450,  -829, -1450, -1450, -1450,  -385,  -102,   188,   921,
   -1450
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   248,   565,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
    1170,   698,   266,   267,   268,   269,   270,   271,   874,   875,
     876,   272,   273,   274,   880,   881,   882,   275,   419,   276,
     277,   643,   278,   421,   422,   423,   429,   688,   689,   279,
    1151,   280,  1652,  1653,   281,   282,   283,   488,   284,   285,
     286,   287,   288,   691,   289,   290,   450,   291,   292,   293,
     294,   295,   296,   576,   297,   298,   769,   770,   299,   300,
     502,   302,   577,   589,  1036,  1037,   303,   578,   304,   580,
     503,   306,   307,   804,   805,  1298,   436,   308,   437,   438,
     811,  1299,  1300,  1301,   581,   582,  1023,  1024,  1453,   583,
    1020,  1021,  1272,  1273,  1274,  1275,   309,   705,   706,   310,
    1186,  1187,  1395,   311,  1189,  1190,   312,   313,  1192,  1193,
    1194,  1195,  1402,   314,   315,   316,   317,   318,   818,   319,
     320,  1308,   321,   322,   323,   324,   325,   326,   327,   328,
     329,  1095,   330,   331,   332,   333,   607,   608,   334,   335,
     336,   337,   338,   339,   340,  1003,  1004,   341,   635,   636,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     851,   352,   353,   354,   355,   356,   357,  1221,   735,   736,
     737,  1679,  1734,  1735,  1728,  1729,  1736,  1730,  1222,  1223,
     358,   359,  1224,   360,   361,   362,   363,   364,   365,   366,
     367,   937,  1403,  1355,  1072,  1515,  1073,  1096,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,   711,
    1701,   368,  1085,  1086,  1087,  1088,   369,   370,   371,   372,
     373,   374,   759,   760,   375,  1256,  1257,  1591,  1005,  1044,
    1318,  1319,  1045,  1046,  1047,  1048,  1049,  1328,  1498,  1499,
    1050,  1331,  1051,  1479,  1052,  1053,  1336,  1337,  1504,  1502,
    1320,  1321,  1322,  1323,  1618,   672,   901,   902,   903,   904,
     905,   906,  1138,  1541,  1649,  1139,  1539,  1647,   907,  1368,
    1536,  1532,  1533,  1534,   908,   909,  1324,  1332,  1489,  1325,
    1485,  1309,   376,   377,   378,   379,   491,   380,   381,   382,
     383,   384,  1089,  1090,  1091,  1092,  1171,   492,   385,   386,
     387
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -929;
  const short int
  jsoniq_parser::yytable_[] =
  {
       301,   301,   301,   301,   301,   305,   305,   305,   305,   305,
     560,   394,   394,   394,   398,   536,   647,   509,   392,   395,
     396,   839,   826,   579,   967,  1188,   631,  1416,   393,   393,
     393,   397,   420,   945,  1406,   644,   644,  1029,  1071,  1094,
     501,   505,  1175,   955,   537,   555,  1030,   695,   699,   827,
     828,   829,   830,   788,   790,   552,   845,   749,   553,   553,
     557,  1304,   755,  1220,  1564,  1042,  1280,  1568,  1110,   544,
     545,     7,     8,   782,   786,   789,   791,  1115,  1152,  1448,
    1449,  1424,  1153,   780,   784,   861,  1026,  1500,  1655,  1287,
     559,  1650,   405,   646,     7,     8,  1033,   553,   553,   553,
     553,   740,   406,   646,   301,   434,   553,  1178,   992,   305,
     553,   553,  1141,   723,   489,   405,   722,  1142,  1143,   560,
     408,   553,   553,   560,   856,   409,  1144,  1164,   553,   553,
     553,   393,  1031,  1145,   562,  1146,  1147,   553,  1176,     7,
       8,     7,     8,   408,  1148,   935,  1258,  1027,   553,   553,
    1027,  1677,   401,   402,  1565,   403,   404,   410,   411,  1015,
     553,   515,   405,  -171,   553,  -848,   564,   564,  -172,   553,
     553,  1149,   406,   407,  1486,   539,   541,  1179,   696,  1530,
    1396,   678,   935,   424,   401,   402,  1486,   403,   404,  -848,
     408,  1269,   553,   399,  1269,   409,  1333,  1334,  1028,  1656,
    -848,  1288,  1284,  1259,   857,   407,   564,   564,   814,  1118,
     815,   816,  1271,   817,   560,   819,   553,   563,  1143,  1335,
     561,   579,  1566,   820,   821,   697,   558,   410,   411,   412,
     564,   553,   985,   553,   559,   694,  1147,   564,   564,   553,
     993,  1678,   435,   986,  1531,   564,   301,   301,  1310,  1163,
     301,   305,   305,  1592,  1210,   305,   564,   564,  1406,  1034,
    1465,  1263,  1289,  1757,   435,  1349,  1397,  1399,   564,  1285,
     741,  1290,   564,   483,   788,   790,   413,   564,   564,  1424,
     887,  1657,  1386,  1042,  1042,   301,   733,   928,   554,     9,
     305,   556,   493,   553,  1111,   506,  1648,   775,   801,  1035,
     564,   777,  1012,  1150,   780,   784,  1220,   510,   413,   513,
     947,   667,  1014,   933,  1349,  1220,   731,   948,  1360,  1262,
    1456,  1311,   682,  1100,   564,  1721,  1152,  1478,   435,   561,
    1153,   435,   435,   561,   922,   942,   996,   416,  1487,   564,
     414,   564,   776,   778,   525,   417,   516,   564,  1206,  -171,
    1487,  1488,   793,   418,  -172,   941,   781,   785,  1292,   553,
     679,  1506,   685,  1590,   618,   692,   774,   553,   680,  1381,
    1396,    77,   414,   619,   704,   771,   772,   709,   710,  1396,
    1207,   415,  1765,   716,  1768,    87,   890,   527,   891,   553,
     435,  1689,   528,   942,   301,  1067,  1068,  1069,   301,   305,
     723,   564,   400,   305,  1208,  1105,   553,   416,  1312,  1313,
     101,  1314,  1027,   415,  1039,   417,   943,  1040,  1315,  1685,
    1259,  1686,  1106,   418,   561,   301,   301,  1687,  1316,   632,
     305,   305,   892,   526,  1038,   398,   398,   856,   121,   444,
    1317,   301,   738,   739,   813,   301,   305,  1676,   925,   743,
     305,   398,   683,   684,     9,   398,  1554,   425,  1043,   553,
    1714,  1101,  1101,  1457,   633,  1559,   634,   564,   708,   765,
     767,   553,   713,  1625,   957,   564,   529,   724,   953,   567,
     147,   148,   149,   568,  1376,   553,  1627,  1744,   569,   301,
     553,   560,  1104,   519,   305,   520,   426,   564,   301,  1119,
    1120,   686,   553,   305,  1123,  1631,  1742,   570,   394,   788,
     790,   788,  1458,  1220,   564,  1566,   445,   858,  1016,  1637,
    1365,  1759,  1213,  1214,  1041,   393,   977,  1244,   926,  1466,
     846,  1264,  1265,  1266,  1161,   301,    77,  1361,  1731,  1737,
     305,  1102,  1103,   301,  1514,   766,  1373,  1611,   305,  1042,
      87,  1434,   970,  1626,   301,   301,   301,   301,  1042,   305,
     305,   305,   305,  1213,  1214,   841,  1628,   564,   847,  1042,
     687,   420,  1013,   301,   971,   101,   778,  1009,   305,   564,
    1367,   662,   521,   663,  1406,  1632,  1639,   893,   446,   447,
    1731,   972,   929,   564,   655,   932,  1737,   659,   564,  1638,
     894,   510,   895,  1454,   673,   674,   571,   567,  1644,   572,
     564,   568,   510,   896,   897,   898,   569,   899,  1215,   900,
    1027,   960,   700,  1726,   573,  1612,   549,  1213,   707,   968,
     567,  1310,   712,   973,   568,   570,  1211,   717,  1216,   569,
    1217,  1129,   550,   665,   998,   147,   148,   149,   427,   522,
     574,   523,  1130,  1481,   978,   979,  1099,  1662,   570,  1215,
    1726,   962,   963,   964,  1213,   767,  1640,  1131,  1218,   980,
    1476,  1599,   107,   707,   981,  1743,  1043,  1043,  1132,  1216,
    1135,  1217,   439,   656,   611,   729,   493,  1748,  1645,   119,
     301,   975,   974,  1482,  1600,   305,   969,  1136,   783,   575,
     394,   997,   612,  1212,  1311,   666,  1572,   927,   935,  1218,
    1219,  1576,   493,   107,   301,   301,   657,   393,   761,   305,
     305,  1252,   833,   834,   398,   398,  1493,  1213,   142,   935,
     119,  1011,   631,   662,   571,   663,   935,   572,   524,  1042,
    1137,   951,   952,  1216,   935,  1217,   584,  1732,   585,   611,
     976,  1418,   732,  1727,   614,  1352,   936,   571,   428,   788,
     572,  1213,  1213,  1214,  1399,  1668,   301,   612,   664,   142,
    1545,   305,   806,  1218,     9,  1440,   806,   954,   574,   988,
    1216,  1732,  1217,   615,  1384,  1213,  1214,  1353,   793,   944,
    1771,  1312,  1313,   301,  1314,   665,   616,  1291,   305,  1615,
     778,   574,   982,   983,   632,  1354,  1616,   430,  1268,   420,
    1218,  1316,   935,   586,   620,   431,  1617,   984,   587,  1269,
     510,   877,   783,  1317,  1451,   432,   652,   575,   621,  1270,
    1365,   617,  1705,  1294,  1706,   630,   441,  1306,  1295,   633,
    1271,   634,   653,  1216,  1260,  1217,   448,  1366,  1294,   883,
     575,  1561,   433,  1295,  1733,  1010,    77,   666,  1215,   121,
    1452,   121,  1680,   913,   878,   588,  1683,   917,   918,   879,
      87,   550,  1296,  1218,   923,  1562,  1027,  1216,  1216,  1217,
    1217,  1215,   510,   632,  1444,   510,   611,   611,  1774,   938,
    1367,  1027,  1670,  1382,   440,   101,  1613,  1614,  1109,  1039,
    1674,  1216,  1040,  1217,   612,   612,  -928,  1218,  1218,  1764,
    1754,   493,   107,  1297,   690,  1610,  1562,   449,   633,  1785,
     634,  1786,   965,   121,  1562,   648,   442,   613,  1698,   119,
    -928,  1218,   650,  1562,  1654,   107,  1107,   443,  1135,   649,
    1615,  -928,  1043,  1562,  1359,  1562,   651,  1616,  1185,   301,
    1423,  1043,   119,  1108,   305,  1136,  1006,  1617,   676,   398,
     690,  1393,  1043,   677,  1185,   147,   148,   149,   142,  1700,
    1739,  1703,   579,  1574,  1303,  1404,  1196,  1398,  1112,  1407,
    1715,  1708,  1404,  1709,  1404,  1017,   485,  1483,  1405,   507,
    1112,   142,  1408,  1155,  1484,  1571,  1253,  1777,  1032,   508,
    1550,  1254,  1156,  1124,  1125,  1126,   484,   831,   832,  1127,
     878,  1294,   301,   301,   301,   879,  1295,   305,   305,   305,
    1696,  1697,   514,  1093,  1093,  1097,  1097,   592,   484,  1228,
     792,  1229,   517,   420,   794,   593,   594,  1233,   595,  1234,
     484,   518,   484,   668,   669,   670,   596,  1121,  1122,   530,
     597,  1654,   598,  1445,  1446,   824,   825,   599,  1371,  1372,
    1641,  1642,   531,   534,   532,  1093,  1593,   535,   533,   542,
     546,   566,   590,   591,   600,   610,   622,   623,   609,  1128,
     864,   865,   866,   867,   868,   869,   870,   871,   872,   873,
     536,   624,   629,   625,   637,   638,   639,   640,   601,   602,
     603,   604,   605,   606,  1158,  1654,   641,  1747,   642,   646,
     658,   660,  1093,   661,   675,   671,   690,   693,   703,   701,
     702,   714,  1556,  1093,   715,   718,   720,   722,   725,   726,
     727,   728,  1043,   730,   734,   742,   745,   746,   757,   768,
     744,   762,   758,   763,   779,   798,   797,   807,   808,   799,
     810,   835,   800,   822,   836,   837,   838,   633,   853,   859,
     860,   862,   301,   888,   884,   801,   889,   305,   301,   911,
     885,   910,   394,   305,   912,   914,   916,   919,   920,  1380,
     301,   921,   924,   930,  1796,   305,  1797,   934,   931,   393,
     394,   949,   946,   987,   990,   989,  1805,  1389,   950,   301,
    1011,   991,   995,  1022,   305,   994,  1008,   393,  1025,   394,
    1277,  1018,  1113,   806,  1133,   879,  1411,   935,   301,  1134,
    1154,  1159,  1162,   305,   686,   301,   393,  1167,   398,  1166,
     305,  1160,  1174,  1168,  1169,   398,  1172,  1173,  1185,  1180,
    1181,  1519,  1184,  1197,  1202,  1421,  1191,  1199,  1209,  1198,
    1204,  1205,  1425,  1093,  1201,  1226,  1225,  1227,  1253,  1245,
     664,  1276,  1255,  1254,  1278,  1282,  1281,  1326,   766,  1330,
    1338,  1286,  1660,  1293,  1307,  1339,     9,  1340,  1363,  1364,
    1327,  1341,  1342,  1664,  1556,  1369,  1666,  1343,  1344,  1385,
    1345,  1388,  1356,  1346,  1675,  1410,  1347,  1375,  1350,  1378,
    1379,  1351,  1093,  1404,  1417,  1415,  1420,  1426,  1374,  1432,
    1269,  1428,  1433,  1258,  1429,  1430,  1431,  1437,  1427,  1438,
    1439,  1461,  1463,  1467,  1469,  1470,   654,   484,  1471,  1475,
     484,  1496,  1497,  1503,   484,  1529,  1436,   484,   484,  1477,
    1501,  1535,  1505,  1480,  1490,   484,  1516,  1540,  1542,  1522,
    1547,  1546,  1526,  1527,  1093,   484,  1528,  1538,  1544,  1548,
    1549,   484,  1583,  1552,  1595,   484,  1553,  1570,  1597,   707,
     484,  1558,  1587,  1588,  1589,  1569,  1575,  1578,  1602,  1093,
    1609,  1621,  1622,  1629,  1623,  1624,  1630,  1633,  1634,  1635,
    1646,  1135,  1636,  1651,  1665,  1658,  1659,   301,  1451,  1666,
    1693,  1695,   305,  1707,  1710,  1682,   484,  1422,  1717,  1712,
    1713,  1722,  1724,  1738,  1740,  1746,  1718,  1741,   484,  1749,
    1711,  1723,  1751,  1750,  1752,  1753,  1755,  1770,  1756,  1762,
    1769,  1776,  1773,   761,  1782,   886,  1795,  1787,  1763,  1802,
    1253,  1798,   547,  1006,  1801,  1254,  1362,  1006,  1766,  1116,
    1165,   484,  1377,   645,  1720,  1788,  1758,   681,  1007,   548,
    1302,   940,  1760,   551,   809,  1780,  1382,   806,  1607,  1474,
    1459,  1455,  1267,  1450,  1447,   719,  1390,  1400,   823,  1789,
    1394,  1792,  1799,  1794,  1409,  1473,   812,  1443,  1098,  1783,
     852,   843,   844,  1419,   855,   966,  1775,  1772,  1804,  1507,
    1704,  1508,  1435,  1442,   628,   484,  1441,  1491,  1495,   484,
    1620,  1783,  1305,  1494,  1329,  1140,  1619,  1370,  1492,  1537,
    1766,  1643,     0,     0,   753,  1688,     0,     0,  1511,  1093,
       0,   510,  1520,  1521,     0,  1525,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1253,     0,     0,
       0,     0,  1254,   484,     0,     0,  1699,     0,  1253,  1253,
       0,   301,  1543,  1254,  1254,     0,   305,     0,     0,  1253,
       0,     0,     0,     0,  1254,     0,     0,     0,     0,   863,
       0,     0,   484,     0,     0,     0,     0,     0,   490,  1560,
       0,     0,  1093,     0,     0,  1093,   484,     0,     0,     0,
     484,   484,     0,     0,     0,     0,  1573,   484,     0,     0,
       0,  1577,     0,     0,     0,   484,     0,     0,   484,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,  1605,  1606,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1253,     0,     0,     0,     0,  1254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   484,     0,
       0,     0,     0,   301,     0,     0,     0,     0,   305,     0,
       0,   484,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1253,     0,     0,     0,     0,  1254,     0,     0,     0,
    1093,  1669,     0,  1671,     0,  1673,   484,   484,   484,   484,
       0,     0,  1681,     0,   301,     0,     0,     0,     0,   305,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1253,     0,     0,     0,
       0,  1254,     0,     0,     0,  1253,     0,     0,   484,     0,
    1254,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,  1702,     0,  1702,     0,  1093,     0,  1093,
       0,     0,     0,     0,     0,   712,     0,   712,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,  1716,     0,   484,  1719,     0,     0,     0,
       0,     0,     0,  1093,     0,     0,   484,     0,     0,     0,
       0,     0,     0,     0,  1725,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1093,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1761,     0,     0,     0,     0,
    1093,     0,  1093,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1778,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,   484,     0,     0,     0,
    1781,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1790,     0,     0,     0,     0,  1791,     0,     0,     0,     0,
       0,     0,   490,     0,     0,     0,   484,  1800,     0,     0,
    1803,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   747,   748,     0,   750,   751,   752,   754,
       0,   756,     0,     0,     0,     0,     0,   764,     0,     0,
       0,     0,     0,     0,     0,     0,   773,     0,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   795,   796,
       0,     0,     0,     0,     0,     0,     0,   802,   803,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,     0,     0,     0,     0,     0,   850,     0,
       0,     0,   850,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   915,     0,     0,     0,     0,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,     0,     0,     0,
     484,     0,     0,     0,     0,     0,   939,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,   956,   484,     0,     0,   958,   959,     0,   961,
       0,     0,     0,     0,     0,     0,   802,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   484,   484,     0,   484,   484,   484,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,   796,     0,     0,
       0,     0,     0,  1019,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   484,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   484,     0,     0,   484,     0,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   484,
       0,     0,     0,     0,   484,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1117,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   484,   484,     0,     0,     0,     0,     0,  1157,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1177,     0,     0,     0,     0,     0,     0,  1182,  1183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1200,     0,
       0,  1203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1230,  1231,  1232,     0,  1235,  1236,  1237,  1238,
    1239,  1240,  1241,  1242,  1243,     0,     0,  1246,  1247,     0,
       0,     0,     0,   484,   484,     0,   484,     0,   484,     0,
       0,     0,  1261,     0,     0,   484,     0,     0,     0,     0,
       0,     0,  1019,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1283,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,     0,   484,     0,
     484,     0,   484,     0,     0,     0,     0,     0,   484,     0,
     484,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   484,     0,     0,   484,
       0,     0,     0,     0,     0,  1358,   484,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   484,     0,
       0,     0,     0,   484,     0,   484,     0,     0,     0,     0,
       0,     0,  1383,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1387,     0,     0,     0,     0,   484,  1391,  1392,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,  1412,     0,     0,  1413,  1414,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   484,     0,     0,     0,     0,   484,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     484,     0,     0,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1019,     0,     0,     0,     0,     0,     0,     0,  1460,     0,
    1462,     0,  1464,     0,     0,  1468,     0,     0,     0,     0,
    1472,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1551,     0,     0,     0,     0,     0,     0,     0,
    1555,  1557,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1383,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1579,  1580,  1581,  1582,     0,  1584,  1585,     0,
    1586,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1594,     0,     0,     0,
       0,  1596,     0,     0,     0,  1598,     0,     0,     0,  1601,
       0,  1603,     0,  1604,     0,     0,     0,     0,     0,  1608,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1661,     0,     0,     0,     0,  1663,  1557,     0,
       0,     0,     0,     0,     0,  1667,     0,     0,     0,     0,
    1672,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1684,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1690,
       0,  1691,     0,  1692,     0,     0,  1694,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1667,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1745,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1767,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -167,   783,     0,
       0,     0,     0,     0,  1779,     0,     0,     0,  1784,     0,
       0,     0,     0,  1767,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,  1784,
       0,    10,   389,  1793,    12,    13,    14,    15,    16,    17,
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
     140,   141,   142,     0,   391,     0,   145,   146,   147,   148,
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
    -167,   783,     0,   245,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   787,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
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
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   391,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   783,   241,     0,
     242,   243,   244,     0,     0,     0,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   390,    26,    27,    28,
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
     141,   142,     0,   391,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   783,   241,     0,   242,   243,   244,     0,
       0,     0,   245,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   494,   390,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   495,   496,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   497,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   498,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   391,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   475,   476,   477,   173,
     174,   478,   500,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   242,   243,   244,   999,  1000,     0,   245,     0,
       0,     0,     0,     0,  1001,     0,     0,     0,     0,     5,
       6,     0,     0,     0,     0,     0,     0,     0,   388,   389,
       0,    12,    13,    14,   451,    16,    17,    18,   452,    20,
     453,   454,   455,   456,   390,    26,   457,    28,    29,    30,
       0,    31,    32,    33,    34,   458,    36,    37,    38,    39,
      40,    41,    42,   459,     0,    44,   460,    46,   461,   462,
      49,   463,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   464,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   465,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,     0,     0,
       0,     0,     0,     0,     0,   109,   467,     0,     0,     0,
       0,   111,   112,   113,   114,   468,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
    1002,     0,   128,     0,   129,   130,   131,   132,   469,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,     0,
       0,   391,     0,   145,   146,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   470,   157,   471,   159,   472,   473,
     162,   163,   164,   165,   166,   167,   474,   169,   475,   476,
     477,   173,   174,   478,   479,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   480,     0,   190,
     481,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     0,     0,   242,   482,   244,   486,     0,     0,
     245,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,   388,   389,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   390,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,     0,   104,   105,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,   487,     0,   125,
       0,   126,   127,     0,     0,     0,     0,     0,     0,   128,
       0,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,     0,     0,   140,   141,   142,     0,   391,     0,
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
       0,   242,   243,   244,   486,     0,     0,   245,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   390,    26,
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
       0,   140,   141,   142,     0,   391,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,   242,   243,
     244,   486,     0,     0,   245,     0,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   388,
     389,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   494,   390,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   495,
     496,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   465,
      80,    81,    82,    83,    84,   497,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,     0,
     498,   105,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,     0,     0,
       0,     0,     0,   128,     0,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,     0,     0,   140,   141,
     142,     0,   391,     0,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   475,
     476,   477,   173,   174,   478,   500,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,   241,   486,   242,   243,   244,     0,     0,
       0,   245,     0,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,   451,    16,
      17,    18,   452,    20,   453,   454,   455,   456,   390,    26,
     457,    28,    29,    30,     0,    31,    32,    33,    34,   458,
      36,    37,    38,    39,    40,    41,    42,   459,     0,    44,
     460,    46,   461,   462,    49,   463,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,   464,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   465,    80,    81,    82,    83,    84,   497,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   466,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,     0,     0,     0,     0,   106,     0,     0,   109,
     467,     0,     0,     0,     0,   111,   112,   113,   114,   468,
     116,   117,   118,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,   842,     0,   128,     0,   129,   130,
     131,   132,   469,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,     0,     0,   391,     0,   145,   146,     0,
       0,     0,   150,   151,   152,   153,   154,   155,   470,   157,
     471,   159,   472,   473,   162,   163,   164,   165,   166,   167,
     474,   169,   475,   476,   477,   173,   174,   478,   479,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   480,     0,   190,   481,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,   486,     0,   242,   482,
     244,     0,     0,     0,   245,     5,     6,     0,     0,     0,
    1517,     0,     0,     0,   388,   389,     0,    12,    13,    14,
     451,    16,    17,    18,   452,    20,   453,   454,   455,   456,
     390,    26,   457,    28,    29,    30,     0,    31,    32,    33,
      34,   458,    36,    37,    38,    39,    40,    41,    42,   459,
       0,    44,   460,    46,   461,   462,    49,   463,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   464,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   465,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   466,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,     0,     0,     0,     0,     0,     0,
       0,   109,   467,     0,     0,     0,     0,   111,   112,   113,
     114,   468,   116,   117,   118,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,     0,     0,     0,   125,  1518,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   469,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,     0,     0,   391,     0,   145,
     146,     0,     0,     0,   150,   151,   152,   153,   154,   155,
     470,   157,   471,   159,   472,   473,   162,   163,   164,   165,
     166,   167,   474,   169,   475,   476,   477,   173,   174,   478,
     479,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   480,     0,   190,   481,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,   486,     0,
     242,   482,   244,     0,     0,     0,   245,     5,     6,     0,
       0,     0,     0,     0,     0,     0,   388,   389,     0,    12,
      13,    14,   451,    16,    17,    18,   452,    20,   453,   454,
     455,   456,   390,    26,   457,    28,    29,    30,     0,    31,
      32,    33,    34,   458,    36,    37,    38,    39,    40,    41,
      42,   459,     0,    44,   460,    46,   461,   462,    49,   463,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,   464,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   465,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   109,   467,     0,     0,     0,     0,   111,
     112,   113,   114,   468,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   469,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,     0,     0,   391,
       0,   145,   146,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   470,   157,   471,   159,   472,   473,   162,   163,
     164,   165,   166,   167,   474,   169,   475,   476,   477,   173,
     174,   478,   479,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   480,     0,   190,   481,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   511,   512,
       0,     0,   242,   482,   244,     5,     6,     0,   245,     0,
       0,     0,     0,     0,   388,   389,     0,    12,    13,    14,
     451,    16,    17,    18,   452,    20,   453,   454,   455,   456,
     390,    26,   457,    28,    29,    30,     0,    31,    32,    33,
      34,   458,    36,    37,    38,    39,    40,    41,    42,   459,
       0,    44,   460,    46,   461,   462,    49,   463,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   464,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   465,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   466,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,     0,     0,     0,     0,     0,     0,
       0,   109,   467,     0,     0,     0,     0,   111,   112,   113,
     114,   468,   116,   117,   118,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   469,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,     0,     0,   391,     0,   145,
     146,     0,     0,     0,   150,   151,   152,   153,   154,   155,
     470,   157,   471,   159,   472,   473,   162,   163,   164,   165,
     166,   167,   474,   169,   475,   476,   477,   173,   174,   478,
     479,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   480,     0,   190,   481,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     0,     0,
     242,   482,   244,     0,     0,     0,   245,     1,     2,     3,
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
     238,   239,   240,     0,   241,     0,   242,   243,   244,     0,
       0,     0,   245,   246,   247,     1,     2,     3,     4,     5,
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
     240,     0,   241,     0,   242,   243,   244,     0,     0,     0,
     245,     0,   543,     1,     2,     3,     4,     5,     6,     7,
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
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   242,   243,   244,     0,     0,     0,   245,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   390,    26,
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
     122,   123,   124,     0,   721,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   391,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,   242,   243,
     244,     0,     0,     0,   245,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   390,    26,    27,    28,    29,    30,
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
     487,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   391,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,     0,     0,     0,
     245,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,  1248,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,  1249,  1250,    49,    50,    51,    52,
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
       0,     0,   122,   123,   124,     0,   487,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   391,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
    1251,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
     242,   243,   244,     0,     0,     0,   245,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   390,    26,    27,    28,
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
     141,   142,     0,   391,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   243,   244,     0,
       0,     0,   245,     1,     2,     3,     4,     5,     6,     7,
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
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   391,
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
     241,     0,   242,   243,   244,     0,     0,     0,   245,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,    10,   389,     0,    12,    13,    14,    15,    16,
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
       0,   140,   141,   142,     0,   391,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,   242,   243,
     244,     0,     0,     0,   245,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   787,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   390,    26,    27,    28,    29,    30,
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
       0,   391,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,     0,     0,     0,
     245,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   494,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   495,   496,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     497,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,   848,     0,    98,    99,
     100,   101,   102,   103,     0,   498,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,   849,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   391,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   475,   476,   477,   173,   174,   478,
     500,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
     242,   243,   244,     0,     0,     0,   245,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   494,   390,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     495,   496,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     465,    80,    81,    82,    83,    84,   497,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,   848,     0,    98,    99,   100,   101,   102,   103,
       0,   498,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,   854,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   391,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     475,   476,   477,   173,   174,   478,   500,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   243,   244,     0,
       0,     0,   245,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,  1248,   390,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,  1249,  1250,    49,    50,
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
     137,   138,   139,     0,     0,   140,   141,   142,     0,   391,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,  1251,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   242,   243,   244,     0,     0,     0,   245,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   494,   390,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   495,   496,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   465,    80,    81,    82,    83,    84,   497,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   498,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,   499,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   391,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   475,   476,   477,   173,   174,   478,   500,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,   242,   243,
     244,     0,     0,     0,   245,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   494,   390,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   495,   496,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   497,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   498,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,   504,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   391,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   475,   476,
     477,   173,   174,   478,   500,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   243,   244,     0,     0,     0,
     245,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   494,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   495,   496,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     497,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   498,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   391,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   475,   476,   477,   173,   174,   478,
     500,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   538,   241,     0,
     242,   243,   244,     0,     0,     0,   245,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   494,   390,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     495,   496,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     465,    80,    81,    82,    83,    84,   497,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   498,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   391,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     475,   476,   477,   173,   174,   478,   500,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,   540,   242,   243,   244,     0,
       0,     0,   245,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   494,   390,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   495,   496,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   497,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   498,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,   840,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   391,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   475,   476,   477,   173,
     174,   478,   500,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,     0,   190,   191,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   242,   243,   244,     0,     0,     0,   245,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   494,   390,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   495,   496,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   465,    80,    81,    82,    83,    84,   497,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,  1357,     0,    98,    99,   100,   101,
     102,   103,     0,   498,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   391,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   475,   476,   477,   173,   174,   478,   500,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,   242,   243,
     244,     0,     0,     0,   245,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   454,    23,   456,   390,    26,   457,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   459,     0,    44,    45,    46,   461,   462,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   497,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   498,
     105,     0,   106,   107,   626,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   627,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   391,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   470,   157,   471,   159,   472,   473,
     162,   163,   164,   165,   166,   167,   474,   169,   475,   476,
     477,   173,   174,   478,   479,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   480,     0,   190,
     481,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   482,   244,     0,     0,     0,
     245,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   494,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   495,   496,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     497,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   498,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,   142,     0,   391,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   475,   476,   477,   173,   174,   478,
     500,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,     0,   190,   191,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,   241,     0,
     242,   243,   244,     0,     0,     0,   245,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   454,    23,   456,   390,    26,   457,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   459,     0,    44,    45,    46,
     461,   462,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     465,    80,    81,    82,    83,    84,   497,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   466,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   498,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   128,     0,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,   142,     0,   391,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   470,   157,   471,   159,
     472,   473,   162,   163,   164,   165,   166,   167,   474,   169,
     475,   476,   477,   173,   174,   478,   479,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   480,
       0,   190,   191,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,     0,   241,     0,   242,   482,   244,     0,
       0,     0,   245,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   454,
      23,   456,   390,    26,   457,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   459,     0,    44,    45,    46,   461,   462,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   497,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   498,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,   142,     0,   391,
       0,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   470,   157,   471,   159,   472,   473,   162,   163,
     164,   165,   166,   167,   474,   169,   475,   476,   477,   173,
     174,   478,   479,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   480,     0,   190,   481,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
     241,     0,   242,   482,   244,     0,     0,     0,   245,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   454,    23,   456,   390,    26,
     457,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   459,     0,    44,
      45,    46,   461,   462,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   465,    80,    81,    82,    83,    84,   497,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   466,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   498,   105,     0,     0,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,   142,     0,   391,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   470,   157,
     471,   159,   472,   473,   162,   163,   164,   165,   166,   167,
     474,   169,   475,   476,   477,   173,   174,   478,   479,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   480,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,   241,     0,   242,   482,
     244,     0,     0,     0,   245,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   454,    23,   456,   390,    26,   457,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   459,     0,    44,    45,    46,   461,   462,
      49,   463,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   497,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   498,
     105,     0,   106,   107,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,   142,
       0,   391,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   470,   157,   471,   159,   472,   473,
     162,   163,   164,   165,   166,   167,   474,   169,   475,   476,
     477,   173,   174,   478,   479,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   480,     0,   190,
     481,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,   241,     0,   242,   482,   244,     5,     6,     0,
     245,     0,     0,     0,     0,     0,   388,   389,     0,    12,
      13,    14,  1054,    16,    17,    18,   452,  1055,  1056,   454,
    1057,   456,   390,    26,   457,    28,  1058,    30,     0,    31,
      32,    33,    34,  1059,    36,  1060,  1061,    39,    40,    41,
      42,   459,     0,    44,  1062,    46,   461,   462,    49,   463,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,  1063,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   465,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,  1064,     0,     0,     0,
    1065,     0,     0,   109,   467,     0,     0,     0,     0,   111,
     112,   113,   114,   468,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,  1512,   126,   127,     0,     0,     0,     0,  1513,     0,
     128,     0,   129,   130,   131,   132,   469,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,     0,     0,   391,
       0,   145,   146,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   470,  1066,   471,   159,   472,   473,   162,   163,
     164,   165,   166,   167,   474,   169,   475,   476,   477,   173,
     174,   478,   479,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   480,     0,   190,   481,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       5,     6,   242,   482,   244,  1067,  1068,  1069,  1070,   388,
     389,     0,    12,    13,    14,  1054,    16,    17,    18,   452,
    1055,  1056,   454,  1057,   456,   390,    26,   457,    28,  1058,
      30,     0,    31,    32,    33,    34,  1059,    36,  1060,  1061,
      39,    40,    41,    42,   459,     0,    44,  1062,    46,   461,
     462,    49,   463,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,  1063,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   465,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   466,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,  1064,
       0,     0,     0,  1114,     0,     0,   109,   467,     0,     0,
       0,     0,   111,   112,   113,   114,   468,   116,   117,   118,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
       0,     0,     0,   125,  1348,   126,   127,     0,     0,     0,
       0,     0,     0,   128,     0,   129,   130,   131,   132,   469,
     134,   135,   136,   137,   138,   139,     0,     0,   140,   141,
       0,     0,   391,     0,   145,   146,     0,     0,     0,   150,
     151,   152,   153,   154,   155,   470,  1066,   471,   159,   472,
     473,   162,   163,   164,   165,   166,   167,   474,   169,   475,
     476,   477,   173,   174,   478,   479,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   480,     0,
     190,   481,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,     5,     6,   242,   482,   244,  1067,  1068,
    1069,  1070,   388,   389,     0,    12,    13,    14,  1054,    16,
      17,    18,   452,  1055,  1056,   454,  1057,   456,   390,    26,
     457,    28,  1058,    30,     0,    31,    32,    33,    34,  1059,
      36,  1060,  1061,    39,    40,    41,    42,   459,     0,    44,
    1062,    46,   461,   462,    49,   463,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1063,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   465,    80,    81,    82,    83,    84,  1401,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   466,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,  1064,     0,     0,     0,  1065,     0,     0,   109,
     467,     0,     0,     0,     0,   111,   112,   113,   114,   468,
     116,   117,   118,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   128,     0,   129,   130,
     131,   132,   469,   134,   135,   136,   137,   138,   139,     0,
       0,   140,   141,     0,     0,   391,     0,   145,   146,     0,
       0,     0,   150,   151,   152,   153,   154,   155,   470,  1066,
     471,   159,   472,   473,   162,   163,   164,   165,   166,   167,
     474,   169,   475,   476,   477,   173,   174,   478,   479,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   480,     0,   190,   481,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,     0,     0,     5,     6,   242,   482,
     244,  1067,  1068,  1069,  1070,   388,   389,     0,    12,    13,
      14,  1054,    16,    17,    18,   452,  1055,  1056,   454,  1057,
     456,   390,    26,   457,    28,  1058,    30,     0,    31,    32,
      33,    34,  1059,    36,  1060,  1061,    39,    40,    41,    42,
     459,     0,    44,  1062,    46,   461,   462,    49,   463,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
    1063,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   465,    80,    81,    82,    83,
      84,  1563,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   466,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,  1064,     0,     0,     0,  1065,
       0,     0,   109,   467,     0,     0,     0,     0,   111,   112,
     113,   114,   468,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,     0,     0,     0,     0,     0,   128,
       0,   129,   130,   131,   132,   469,   134,   135,   136,   137,
     138,   139,     0,     0,   140,   141,     0,     0,   391,     0,
     145,   146,     0,     0,     0,   150,   151,   152,   153,   154,
     155,   470,  1066,   471,   159,   472,   473,   162,   163,   164,
     165,   166,   167,   474,   169,   475,   476,   477,   173,   174,
     478,   479,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   480,     0,   190,   481,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,     0,     0,     5,
       6,   242,   482,   244,  1067,  1068,  1069,  1070,   388,   389,
       0,    12,    13,    14,  1054,    16,    17,    18,   452,  1055,
    1056,   454,  1057,   456,   390,    26,   457,    28,  1058,    30,
       0,    31,    32,    33,    34,  1059,    36,  1060,  1061,    39,
      40,    41,    42,   459,     0,    44,  1062,    46,   461,   462,
      49,   463,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,  1063,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   465,    80,
      81,    82,    83,    84,  1567,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,  1064,     0,
       0,     0,  1065,     0,     0,   109,   467,     0,     0,     0,
       0,   111,   112,   113,   114,   468,   116,   117,   118,     0,
       0,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   128,     0,   129,   130,   131,   132,   469,   134,
     135,   136,   137,   138,   139,     0,     0,   140,   141,     0,
       0,   391,     0,   145,   146,     0,     0,     0,   150,   151,
     152,   153,   154,   155,   470,  1066,   471,   159,   472,   473,
     162,   163,   164,   165,   166,   167,   474,   169,   475,   476,
     477,   173,   174,   478,   479,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   480,     0,   190,
     481,   192,     0,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
       0,     0,     5,     6,   242,   482,   244,  1067,  1068,  1069,
    1070,   388,   389,     0,    12,    13,    14,  1054,    16,    17,
      18,   452,  1055,  1056,   454,  1057,   456,   390,    26,   457,
      28,  1058,    30,     0,    31,    32,    33,    34,  1059,    36,
    1060,  1061,    39,    40,    41,    42,   459,     0,    44,  1062,
      46,   461,   462,    49,   463,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,  1063,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   465,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   466,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,  1064,     0,     0,     0,  1065,     0,     0,   109,   467,
       0,     0,     0,     0,   111,   112,   113,   114,   468,   116,
     117,   118,     0,     0,     0,     0,     0,     0,     0,   122,
     123,   124,     0,     0,     0,   125,     0,   126,   127,     0,
       0,     0,     0,     0,     0,   128,     0,   129,   130,   131,
     132,   469,   134,   135,   136,   137,   138,   139,     0,     0,
     140,   141,     0,     0,   391,     0,   145,   146,     0,     0,
       0,   150,   151,   152,   153,   154,   155,   470,  1066,   471,
     159,   472,   473,   162,   163,   164,   165,   166,   167,   474,
     169,   475,   476,   477,   173,   174,   478,   479,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     480,     0,   190,   481,   192,     0,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,     0,     0,     5,     6,   242,   482,   244,
    1067,  1068,  1069,  1070,   388,   389,     0,    12,    13,    14,
    1054,    16,    17,    18,   452,  1055,  1056,   454,  1057,   456,
     390,    26,   457,    28,  1058,    30,     0,    31,    32,    33,
      34,  1059,    36,  1060,  1061,    39,    40,    41,    42,   459,
       0,    44,  1062,    46,   461,   462,    49,   463,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,  1063,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   465,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   466,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,  1064,     0,     0,     0,  1114,     0,
       0,   109,   467,     0,     0,     0,     0,   111,   112,   113,
     114,   468,   116,   117,   118,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   128,     0,
     129,   130,   131,   132,   469,   134,   135,   136,   137,   138,
     139,     0,     0,   140,   141,     0,     0,   391,     0,   145,
     146,     0,     0,     0,   150,   151,   152,   153,   154,   155,
     470,  1066,   471,   159,   472,   473,   162,   163,   164,   165,
     166,   167,   474,   169,   475,   476,   477,   173,   174,   478,
     479,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   480,     0,   190,   481,   192,     0,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,     0,     0,     5,     6,
     242,   482,   244,  1067,  1068,  1069,  1070,   388,   389,     0,
      12,    13,    14,   451,    16,    17,    18,   452,    20,   453,
     454,   455,   456,   390,    26,   457,    28,    29,    30,     0,
      31,    32,    33,    34,   458,    36,    37,    38,    39,    40,
      41,    42,   459,     0,    44,   460,    46,   461,   462,    49,
     463,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,   464,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   465,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     466,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   109,   467,     0,     0,     0,     0,
     111,   112,   113,   114,   468,   116,   117,   118,     0,     0,
       0,     0,     0,     0,     0,   122,   123,   124,     0,     0,
       0,   125,  1509,   126,   127,     0,     0,     0,     0,  1510,
       0,   128,     0,   129,   130,   131,   132,   469,   134,   135,
     136,   137,   138,   139,     0,     0,   140,   141,     0,     0,
     391,     0,   145,   146,     0,     0,     0,   150,   151,   152,
     153,   154,   155,   470,   157,   471,   159,   472,   473,   162,
     163,   164,   165,   166,   167,   474,   169,   475,   476,   477,
     173,   174,   478,   479,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   480,     0,   190,   481,
     192,     0,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,     0,
       0,     5,     6,   242,   482,   244,     0,     0,     0,   245,
     388,   389,     0,    12,    13,    14,   451,    16,    17,    18,
     452,    20,   453,   454,   455,   456,   390,    26,   457,    28,
      29,    30,     0,    31,    32,    33,    34,   458,    36,    37,
      38,    39,    40,    41,    42,   459,     0,    44,   460,    46,
     461,   462,    49,   463,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,   464,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     465,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   466,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,   109,   467,     0,
       0,     0,     0,   111,   112,   113,   114,   468,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     124,     0,     0,     0,   125,  1523,   126,   127,     0,     0,
       0,     0,  1524,     0,   128,     0,   129,   130,   131,   132,
     469,   134,   135,   136,   137,   138,   139,     0,     0,   140,
     141,     0,     0,   391,     0,   145,   146,     0,     0,     0,
     150,   151,   152,   153,   154,   155,   470,   157,   471,   159,
     472,   473,   162,   163,   164,   165,   166,   167,   474,   169,
     475,   476,   477,   173,   174,   478,   479,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   480,
       0,   190,   481,   192,     0,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,     0,     0,     5,     6,   242,   482,   244,     0,
       0,     0,   245,   388,   389,     0,    12,    13,    14,   451,
      16,    17,    18,   452,    20,   453,   454,   455,   456,   390,
      26,   457,    28,    29,    30,     0,    31,    32,    33,    34,
     458,    36,    37,    38,    39,    40,    41,    42,   459,     0,
      44,   460,    46,   461,   462,    49,   463,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,   464,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   465,    80,    81,    82,    83,    84,  1279,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   466,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,     0,     0,     0,     0,     0,     0,     0,
     109,   467,     0,     0,     0,     0,   111,   112,   113,   114,
     468,   116,   117,   118,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,     0,     0,     0,     0,     0,   128,     0,   129,
     130,   131,   132,   469,   134,   135,   136,   137,   138,   139,
       0,     0,   140,   141,     0,     0,   391,     0,   145,   146,
       0,     0,     0,   150,   151,   152,   153,   154,   155,   470,
     157,   471,   159,   472,   473,   162,   163,   164,   165,   166,
     167,   474,   169,   475,   476,   477,   173,   174,   478,   479,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   480,     0,   190,   481,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,     0,     0,     5,     6,   242,
     482,   244,     0,     0,     0,   245,   388,   389,     0,    12,
      13,    14,   451,    16,    17,    18,   452,    20,   453,   454,
     455,   456,   390,    26,   457,    28,    29,    30,     0,    31,
      32,    33,    34,   458,    36,    37,    38,    39,    40,    41,
      42,   459,     0,    44,   460,    46,   461,   462,    49,   463,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,   464,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   465,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,     0,     0,     0,     0,
       0,     0,     0,   109,   467,     0,     0,     0,     0,   111,
     112,   113,   114,   468,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     128,     0,   129,   130,   131,   132,   469,   134,   135,   136,
     137,   138,   139,     0,     0,   140,   141,     0,     0,   391,
       0,   145,   146,     0,     0,     0,   150,   151,   152,   153,
     154,   155,   470,   157,   471,   159,   472,   473,   162,   163,
     164,   165,   166,   167,   474,   169,   475,   476,   477,   173,
     174,   478,   479,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   480,     0,   190,   481,   192,
       0,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,     0,     0,
       5,     6,   242,   482,   244,     0,     0,     0,   245,   388,
     389,     0,    12,    13,    14,     0,    16,    17,    18,   452,
       0,     0,   454,   455,     0,   390,    26,   457,    28,     0,
      30,     0,    31,    32,    33,    34,     0,    36,     0,     0,
      39,    40,    41,    42,   459,     0,    44,     0,    46,     0,
       0,    49,   463,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,     0,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   465,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   466,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,     0,
       0,     0,     0,     0,     0,     0,   109,   467,     0,     0,
       0,     0,   111,   112,   113,   114,   468,   116,   117,   118,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,     0,     0,
       0,     0,     0,   128,     0,   129,   130,   131,   132,   469,
     134,   135,   136,   137,   138,   139,     0,     0,     0,   141,
       0,     0,   391,     0,   145,   146,     0,     0,     0,   150,
     151,   152,   153,   154,   155,   470,     0,   471,   159,   472,
     473,   162,   163,   164,   165,   166,   167,   474,   169,   475,
     476,   477,   173,   174,     0,   479,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   480,     0,
     190,   481,   192,     0,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,     0,     0,     0,     0,   242,   482,   244,     0,     0,
       0,   245
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     285,     1,     2,     3,     4,   176,   401,   119,     1,     2,
       3,   629,   613,   305,   735,   947,   336,  1208,     1,     2,
       3,     4,    10,   707,  1192,   399,   400,   806,   835,   836,
     105,   106,   934,   717,   191,   254,   806,   432,   433,   614,
     615,   616,   617,   556,   557,   253,   632,   521,     1,     1,
     269,  1040,   526,   969,  1404,   822,  1025,  1407,   861,   246,
     247,    27,    28,   554,   555,   556,   557,   877,   911,  1273,
    1274,  1221,   911,   554,   555,   654,    37,  1330,   120,    37,
     276,  1540,    48,    30,    27,    28,    57,     1,     1,     1,
       1,     8,    58,    30,   104,   120,     1,   144,   109,   104,
       1,     1,    40,   109,   104,    48,   123,    45,    46,   394,
      76,     1,     1,   398,   109,    81,    54,   924,     1,     1,
       1,   104,   806,    61,   109,    63,    64,     1,   935,    27,
      28,    27,    28,    76,    72,    96,   155,    98,     1,     1,
      98,    95,    38,    39,   120,    41,    42,   113,   114,   115,
       1,    31,    48,     0,     1,   123,   109,   109,     0,     1,
       1,    99,    58,    59,    98,   240,   241,   937,   115,   138,
     102,   114,    96,   162,    38,    39,    98,    41,    42,   147,
      76,   108,     1,   158,   108,    81,   253,   254,   149,   231,
     158,   149,   149,   212,   189,    59,   109,   109,   592,   883,
     594,   595,   129,   597,   489,   599,     1,   192,    46,   276,
     285,   503,   188,   607,   608,   162,   114,   113,   114,   115,
     109,     1,   239,     1,   420,   162,    64,   109,   109,     1,
     241,   185,   279,   239,   203,   109,   246,   247,    98,   923,
     250,   246,   247,  1447,   965,   250,   109,   109,  1416,   220,
     149,   115,  1031,  1712,   279,  1065,   188,  1189,   109,  1029,
     177,  1031,   109,    85,   777,   778,   162,   109,   109,  1419,
     665,   313,  1174,  1040,  1041,   285,   189,   189,   192,    30,
     285,   192,   104,     1,   863,   107,  1539,   192,   573,   260,
     109,   192,   192,   231,   775,   776,  1212,   119,   162,   121,
     189,   413,   192,   698,  1114,  1221,   187,   189,  1111,   192,
    1279,   171,   424,   187,   109,  1665,  1159,  1306,   279,   394,
    1159,   279,   279,   398,   186,   109,   189,   293,   262,   109,
     226,   109,   551,   552,   231,   301,   216,   109,   189,   186,
     262,   263,   561,   309,   186,   186,   554,   555,  1032,     1,
     293,   189,   427,   155,   203,   430,   543,     1,   301,  1166,
     102,   112,   226,   212,   439,   317,   319,   442,   443,   102,
     189,   267,  1722,   448,  1724,   126,    56,   231,    58,     1,
     279,  1594,   236,   109,   394,   323,   324,   325,   398,   394,
     109,   109,   158,   398,   189,   150,     1,   293,   258,   259,
     151,   261,    98,   267,   155,   301,   190,   158,   268,   189,
     212,   189,   167,   309,   489,   425,   426,   189,   278,   121,
     425,   426,   102,   320,   818,   425,   426,   109,   179,    78,
     290,   441,   507,   508,   591,   445,   441,   120,   109,   514,
     445,   441,   425,   426,    30,   445,   188,   155,   822,     1,
    1654,   109,   109,   149,   156,   188,   158,   109,   441,   534,
     535,     1,   445,   109,   190,   109,   320,   186,   186,    43,
     221,   222,   223,    47,  1158,     1,   109,  1690,    52,   489,
       1,   766,   856,   231,   489,   233,   155,   109,   498,   884,
     885,   120,     1,   498,   889,   109,  1687,    71,   498,  1012,
    1013,  1014,  1281,  1419,   109,   188,   155,   189,   793,   109,
      98,  1715,     9,    10,   265,   498,    96,   991,   189,  1289,
     632,  1012,  1013,  1014,   919,   535,   112,  1113,  1677,  1678,
     535,   189,   189,   543,  1341,   535,  1154,    53,   543,  1306,
     126,   243,   186,   189,   554,   555,   556,   557,  1315,   554,
     555,   556,   557,     9,    10,   630,   189,   109,   633,  1326,
     189,   549,   781,   573,   186,   151,   785,   775,   573,   109,
     158,    46,   320,    48,  1742,   189,   109,   257,   227,   228,
    1729,   186,   694,   109,   406,   697,  1735,   409,   109,   189,
     270,   413,   272,  1277,   416,   417,   170,    43,   109,   173,
     109,    47,   424,   283,   284,   285,    52,   287,   105,   289,
      98,   723,   434,     5,   188,   131,    34,     9,   440,   132,
      43,    98,   444,   133,    47,    71,   132,   449,   125,    52,
     127,   269,    50,   108,   186,   221,   222,   223,   155,   231,
     214,   233,   280,   220,   224,   225,   186,  1549,    71,   105,
       5,   726,   727,   728,     9,   730,   189,   269,   155,   239,
     186,   149,   159,   485,    96,   186,  1040,  1041,   280,   125,
      98,   127,   155,   171,   160,   497,   498,   186,   189,   176,
     690,   133,   192,   260,  1463,   690,   199,   115,     1,   263,
     690,   766,   178,   199,   171,   170,  1417,   690,    96,   155,
     197,  1422,   524,   159,   714,   715,   204,   690,   530,   714,
     715,   996,   620,   621,   714,   715,  1317,     9,   215,    96,
     176,    34,  1042,    46,   170,    48,    96,   173,   320,  1496,
     158,   714,   715,   125,    96,   127,     1,    29,     3,   160,
     192,   197,   188,   135,   119,   146,   144,   170,   158,  1262,
     173,     9,     9,    10,  1686,  1562,   766,   178,    81,   215,
    1378,   766,   584,   155,    30,   188,   588,   144,   214,    96,
     125,    29,   127,   148,  1169,     9,    10,   178,   997,   149,
     135,   258,   259,   793,   261,   108,   161,   149,   793,   275,
    1009,   214,   224,   225,   121,   196,   282,   158,    97,   787,
     155,   278,    96,    68,   138,    25,   292,   239,    73,   108,
     632,    96,     1,   290,   108,    35,   168,   263,   152,   118,
      98,   196,  1629,    55,  1631,   155,   155,   155,    60,   156,
     129,   158,   184,   125,  1005,   127,   155,   115,    55,   661,
     263,   188,    62,    60,   136,    34,   112,   170,   105,   179,
     144,   179,  1573,   675,   139,   120,  1577,   679,   680,   144,
     126,    50,    79,   155,   686,   212,    98,   125,   125,   127,
     127,   105,   694,   121,  1269,   697,   160,   160,   136,   701,
     158,    98,   188,  1168,   120,   151,  1487,  1488,   139,   155,
     188,   125,   158,   127,   178,   178,   123,   155,   155,   188,
    1707,   723,   159,   120,   155,  1480,   212,   120,   156,   188,
     158,   188,   734,   179,   212,   184,   158,   201,   201,   176,
     147,   155,   184,   212,  1542,   159,   150,   158,    98,   198,
     275,   158,  1306,   212,   139,   212,   198,   282,   102,   949,
     197,  1315,   176,   167,   949,   115,   768,   292,   139,   949,
     155,   115,  1326,   144,   102,   221,   222,   223,   215,  1625,
    1681,  1627,  1254,   197,  1039,   102,   949,   115,   874,   102,
    1654,  1637,   102,  1639,   102,   797,   120,   274,   115,   155,
     886,   215,   115,   305,   281,   115,   996,   115,   810,   155,
    1385,   996,   314,   283,   284,   285,    85,   618,   619,   289,
     139,    55,  1012,  1013,  1014,   144,    60,  1012,  1013,  1014,
    1611,  1612,   155,   835,   836,   837,   838,   134,   107,   238,
     558,   240,   219,  1011,   562,   142,   143,   238,   145,   240,
     119,   219,   121,   227,   228,   229,   153,   130,   131,   120,
     157,  1659,   159,   130,   131,   611,   612,   164,  1152,  1153,
    1530,  1531,   247,   158,   247,   877,  1451,   155,   248,   320,
       0,   192,   169,    94,   181,   101,    51,   202,   255,   891,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    1251,   103,   195,   104,   147,   158,   186,   186,   205,   206,
     207,   208,   209,   210,   916,  1713,   186,  1698,   186,    30,
      48,   154,   924,   120,   310,   252,   155,     1,   109,   120,
     144,   155,  1397,   935,   155,   144,   186,   123,   123,   158,
     158,   158,  1496,   155,    36,    17,    30,    30,   237,   251,
     216,   192,   236,   192,     3,   170,   120,   290,   290,   172,
     120,   237,   172,    72,    96,    96,    96,   156,   151,   109,
     109,    30,  1162,   129,   162,  1440,   134,  1162,  1168,    96,
     162,   252,  1162,  1168,   305,   144,   120,   134,   186,  1162,
    1180,   186,    96,    98,  1792,  1180,  1794,    98,    46,  1162,
    1180,   155,   186,    96,   231,   243,  1804,  1180,   186,  1199,
      34,   237,   192,   120,  1199,   144,   239,  1180,   109,  1199,
    1022,   172,   134,  1025,    30,   144,  1199,    96,  1218,   292,
     233,    96,   155,  1218,   120,  1225,  1199,   186,  1218,    96,
    1225,   305,    98,   200,   134,  1225,   162,   134,   102,   155,
     120,  1343,   149,   186,   192,  1218,   102,   155,    36,   186,
     123,   123,  1225,  1065,   144,    30,   155,    30,  1258,   120,
      81,   109,   251,  1258,   109,   120,   129,   264,  1258,   273,
     158,   149,  1547,   260,   291,   158,    30,   158,   292,    30,
     266,   158,   158,  1558,  1559,    30,  1561,   158,   158,   109,
     158,   144,   146,   158,  1569,   186,   158,   312,   158,   233,
     192,   158,  1114,   102,   134,   200,     7,   192,   293,    98,
     108,   239,   243,   155,   239,   239,   239,   158,   192,   158,
     158,   149,   129,   149,   149,   120,   405,   406,   120,    79,
     409,   149,   288,    80,   413,    30,   188,   416,   417,   189,
     292,    30,   189,   256,   256,   424,   189,   109,   172,   189,
     128,   186,   189,   189,  1166,   434,   189,   277,   263,   128,
      98,   440,   322,   186,   144,   444,   188,   186,   149,  1181,
     449,   188,  1437,  1438,  1439,   188,   186,   186,   149,  1191,
     186,   155,   286,    96,   189,   189,   189,   189,   189,   189,
      30,    98,   189,   189,    96,   293,   172,  1397,   108,  1674,
     149,    55,  1397,    96,    30,   199,   485,  1219,   120,   109,
     109,    96,    96,   199,   199,   120,   231,   200,   497,   189,
     271,   188,   146,   189,   189,   189,   189,    95,   189,   120,
     188,   199,   185,  1245,   120,   664,   188,   120,   231,   120,
    1440,   201,   250,  1255,   231,  1440,  1115,  1259,  1723,   878,
     925,   530,  1159,   400,  1659,   299,  1713,   420,   769,   250,
    1037,   703,   311,   253,   588,   311,  1741,  1279,  1473,  1298,
    1282,  1278,  1018,  1276,  1273,   485,  1181,  1189,   610,   311,
    1186,   312,   293,   312,  1194,  1297,   590,  1259,   838,  1764,
     635,   632,   632,  1212,   638,   735,  1735,  1729,   312,  1339,
    1627,  1339,  1245,  1256,   331,   584,  1255,  1315,  1326,   588,
    1496,  1786,  1041,  1319,  1050,   910,  1493,  1137,  1316,  1368,
    1795,  1533,    -1,    -1,   524,  1590,    -1,    -1,  1340,  1341,
      -1,  1343,  1344,  1345,    -1,  1347,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1547,    -1,    -1,
      -1,    -1,  1547,   632,    -1,    -1,  1621,    -1,  1558,  1559,
      -1,  1561,  1374,  1558,  1559,    -1,  1561,    -1,    -1,  1569,
      -1,    -1,    -1,    -1,  1569,    -1,    -1,    -1,    -1,   658,
      -1,    -1,   661,    -1,    -1,    -1,    -1,    -1,   104,  1401,
      -1,    -1,  1404,    -1,    -1,  1407,   675,    -1,    -1,    -1,
     679,   680,    -1,    -1,    -1,    -1,  1418,   686,    -1,    -1,
      -1,  1423,    -1,    -1,    -1,   694,    -1,    -1,   697,    -1,
      -1,    -1,   701,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   734,    -1,    -1,  1470,  1471,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1674,    -1,    -1,    -1,    -1,  1674,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   768,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   797,    -1,
      -1,    -1,    -1,  1723,    -1,    -1,    -1,    -1,  1723,    -1,
      -1,   810,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1741,    -1,    -1,    -1,    -1,  1741,    -1,    -1,    -1,
    1562,  1563,    -1,  1565,    -1,  1567,   835,   836,   837,   838,
      -1,    -1,  1574,    -1,  1764,    -1,    -1,    -1,    -1,  1764,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1786,    -1,    -1,    -1,
      -1,  1786,    -1,    -1,    -1,  1795,    -1,    -1,   877,    -1,
    1795,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   891,  1625,    -1,  1627,    -1,  1629,    -1,  1631,
      -1,    -1,    -1,    -1,    -1,  1637,    -1,  1639,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   916,    -1,    -1,
      -1,    -1,    -1,  1655,    -1,   924,  1658,    -1,    -1,    -1,
      -1,    -1,    -1,  1665,    -1,    -1,   935,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1676,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1707,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1717,    -1,    -1,    -1,    -1,
    1722,    -1,  1724,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1746,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1022,    -1,    -1,  1025,    -1,    -1,    -1,
    1762,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1782,    -1,    -1,    -1,    -1,  1787,    -1,    -1,    -1,    -1,
      -1,    -1,   498,    -1,    -1,    -1,  1065,  1799,    -1,    -1,
    1802,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   519,   520,    -1,   522,   523,   524,   525,
      -1,   527,    -1,    -1,    -1,    -1,    -1,   533,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   542,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   564,   565,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   573,   574,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1166,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1191,    -1,    -1,    -1,    -1,    -1,   634,    -1,
      -1,    -1,   638,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   677,    -1,    -1,    -1,    -1,  1245,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1255,    -1,    -1,    -1,
    1259,    -1,    -1,    -1,    -1,    -1,   702,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1279,    -1,   718,  1282,    -1,    -1,   722,   723,    -1,   725,
      -1,    -1,    -1,    -1,    -1,    -1,   732,    -1,  1297,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1340,  1341,    -1,  1343,  1344,  1345,    -1,  1347,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   793,    -1,    -1,
      -1,    -1,    -1,   799,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1374,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1401,    -1,    -1,  1404,    -1,    -1,  1407,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1418,
      -1,    -1,    -1,    -1,  1423,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   879,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1470,  1471,    -1,    -1,    -1,    -1,    -1,   914,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     936,    -1,    -1,    -1,    -1,    -1,    -1,   943,   944,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   954,    -1,
      -1,   957,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   978,   979,   980,    -1,   982,   983,   984,   985,
     986,   987,   988,   989,   990,    -1,    -1,   993,   994,    -1,
      -1,    -1,    -1,  1562,  1563,    -1,  1565,    -1,  1567,    -1,
      -1,    -1,  1008,    -1,    -1,  1574,    -1,    -1,    -1,    -1,
      -1,    -1,  1018,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1028,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1625,    -1,  1627,    -1,
    1629,    -1,  1631,    -1,    -1,    -1,    -1,    -1,  1637,    -1,
    1639,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1655,    -1,    -1,  1658,
      -1,    -1,    -1,    -1,    -1,  1101,  1665,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1676,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1707,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1717,    -1,
      -1,    -1,    -1,  1722,    -1,  1724,    -1,    -1,    -1,    -1,
      -1,    -1,  1168,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1178,    -1,    -1,    -1,    -1,  1746,  1184,  1185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1762,    -1,  1201,    -1,    -1,  1204,  1205,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1782,    -1,    -1,    -1,    -1,  1787,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1799,    -1,    -1,  1802,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1284,    -1,
    1286,    -1,  1288,    -1,    -1,  1291,    -1,    -1,    -1,    -1,
    1296,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1396,  1397,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1415,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1428,  1429,  1430,  1431,    -1,  1433,  1434,    -1,
    1436,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1452,    -1,    -1,    -1,
      -1,  1457,    -1,    -1,    -1,  1461,    -1,    -1,    -1,  1465,
      -1,  1467,    -1,  1469,    -1,    -1,    -1,    -1,    -1,  1475,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1548,    -1,    -1,    -1,    -1,  1553,  1554,    -1,
      -1,    -1,    -1,    -1,    -1,  1561,    -1,    -1,    -1,    -1,
    1566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1583,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1595,
      -1,  1597,    -1,  1599,    -1,    -1,  1602,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1670,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1693,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1723,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,
      -1,    -1,    -1,    -1,  1760,    -1,    -1,    -1,  1764,    -1,
      -1,    -1,    -1,  1769,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,  1785,
      -1,    34,    35,  1789,    37,    38,    39,    40,    41,    42,
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
     313,   314,   315,   316,    -1,   318,    -1,   320,   321,   322,
       0,     1,    -1,   326,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     310,   311,   312,   313,   314,   315,   316,     1,   318,    -1,
     320,   321,   322,    -1,    -1,    -1,   326,    -1,    -1,    -1,
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
     314,   315,   316,     1,   318,    -1,   320,   321,   322,    -1,
      -1,    -1,   326,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     318,    -1,   320,   321,   322,    11,    12,    -1,   326,    -1,
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
      -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,   320,   321,   322,    16,    -1,    -1,
     326,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
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
     149,   150,   151,   152,   153,    -1,   155,   156,    -1,   158,
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
      -1,   320,   321,   322,    16,    -1,    -1,   326,    -1,    21,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,    16,    -1,    -1,   326,    -1,    21,    22,    23,    24,
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
      -1,    -1,    -1,   148,   149,   150,   151,   152,   153,    -1,
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
     315,   316,    -1,   318,    16,   320,   321,   322,    -1,    -1,
      -1,   326,    -1,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
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
     152,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,   201,
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
     322,    -1,    -1,    -1,   326,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
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
     150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,
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
     310,   311,   312,   313,   314,   315,    -1,    -1,    16,    -1,
     320,   321,   322,    -1,    -1,    -1,   326,    25,    26,    -1,
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
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    18,    19,
      -1,    -1,   320,   321,   322,    25,    26,    -1,   326,    -1,
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
     150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,
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
     320,   321,   322,    -1,    -1,    -1,   326,    21,    22,    23,
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
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,    -1,
      -1,    -1,   326,   327,   328,    21,    22,    23,    24,    25,
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
     316,    -1,   318,    -1,   320,   321,   322,    -1,    -1,    -1,
     326,    -1,   328,    21,    22,    23,    24,    25,    26,    27,
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
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,    -1,    -1,    -1,   326,    21,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,    -1,    -1,    -1,   326,    21,    22,    23,    24,    25,
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
     316,    -1,   318,    -1,   320,   321,   322,    -1,    -1,    -1,
     326,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
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
     320,   321,   322,    -1,    -1,    -1,   326,    21,    22,    23,
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
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,    -1,
      -1,    -1,   326,    21,    22,    23,    24,    25,    26,    27,
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
     318,    -1,   320,   321,   322,    -1,    -1,    -1,   326,    21,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,    -1,    -1,    -1,   326,    21,    22,    23,    24,    25,
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
     316,    -1,   318,    -1,   320,   321,   322,    -1,    -1,    -1,
     326,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     320,   321,   322,    -1,    -1,    -1,   326,    21,    22,    23,
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
      -1,    -1,   146,    -1,   148,   149,   150,   151,   152,   153,
      -1,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,
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
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,    -1,
      -1,    -1,   326,    21,    22,    23,    24,    25,    26,    27,
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
     318,    -1,   320,   321,   322,    -1,    -1,    -1,   326,    21,
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
     182,   183,   184,    -1,    -1,   187,   188,    -1,   190,   191,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,    -1,    -1,    -1,   326,    21,    22,    23,    24,    25,
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
      -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,
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
     316,    -1,   318,    -1,   320,   321,   322,    -1,    -1,    -1,
     326,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     320,   321,   322,    -1,    -1,    -1,   326,    21,    22,    23,
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
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,   319,   320,   321,   322,    -1,
      -1,    -1,   326,    21,    22,    23,    24,    25,    26,    -1,
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
     178,   179,    -1,    -1,   182,   183,   184,    -1,   186,    -1,
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
     318,    -1,   320,   321,   322,    -1,    -1,    -1,   326,    21,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,    -1,    -1,    -1,   326,    21,    22,    23,    24,    25,
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
     316,    -1,   318,    -1,   320,   321,   322,    -1,    -1,    -1,
     326,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     320,   321,   322,    -1,    -1,    -1,   326,    21,    22,    23,
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
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,    -1,
      -1,    -1,   326,    21,    22,    23,    24,    25,    26,    -1,
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
     318,    -1,   320,   321,   322,    -1,    -1,    -1,   326,    21,
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
     152,   153,    -1,   155,   156,    -1,    -1,   159,   160,   161,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,    -1,    -1,    -1,   326,    21,    22,    23,    24,    25,
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
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,   320,   321,   322,    25,    26,    -1,
     326,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,
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
      -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,    -1,
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
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,    -1,   265,   266,   267,    -1,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,    -1,    -1,    25,
      26,   320,   321,   322,   323,   324,   325,   326,    34,    35,
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
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
      -1,    -1,    25,    26,   320,   321,   322,   323,   324,   325,
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
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,    -1,    -1,    25,    26,
     320,   321,   322,   323,   324,   325,   326,    34,    35,    -1,
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
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,    -1,   265,   266,
     267,    -1,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
      -1,    25,    26,   320,   321,   322,    -1,    -1,    -1,   326,
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
     184,    -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,
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
     314,   315,    -1,    -1,    25,    26,   320,   321,   322,    -1,
      -1,    -1,   326,    34,    35,    -1,    37,    38,    39,    40,
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
      -1,   152,   153,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     321,   322,    -1,    -1,    -1,   326,    34,    35,    -1,    37,
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
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,    -1,    -1,
      25,    26,   320,   321,   322,    -1,    -1,    -1,   326,    34,
      35,    -1,    37,    38,    39,    -1,    41,    42,    43,    44,
      -1,    -1,    47,    48,    -1,    50,    51,    52,    53,    -1,
      55,    -1,    57,    58,    59,    60,    -1,    62,    -1,    -1,
      65,    66,    67,    68,    69,    -1,    71,    -1,    73,    -1,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    -1,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,
     115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,   131,    -1,   133,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,    -1,   152,   153,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,   214,
      -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,   224,
     225,   226,   227,   228,   229,   230,    -1,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,    -1,    -1,    -1,   320,   321,   322,    -1,    -1,
      -1,   326
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
     316,   318,   320,   321,   322,   326,   327,   328,   342,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   363,   364,   365,   366,
     367,   368,   372,   373,   374,   378,   380,   381,   383,   390,
     392,   395,   396,   397,   399,   400,   401,   402,   403,   405,
     406,   408,   409,   410,   411,   412,   413,   415,   416,   419,
     420,   421,   422,   427,   429,   431,   432,   433,   438,   457,
     460,   464,   467,   468,   474,   475,   476,   477,   478,   480,
     481,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     493,   494,   495,   496,   499,   500,   501,   502,   503,   504,
     505,   508,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   522,   523,   524,   525,   526,   527,   541,   542,
     544,   545,   546,   547,   548,   549,   550,   551,   572,   577,
     578,   579,   580,   581,   582,   585,   643,   644,   645,   646,
     648,   649,   650,   651,   652,   659,   660,   661,    34,    35,
      50,   217,   398,   399,   400,   398,   398,   399,   400,   158,
     158,    38,    39,    41,    42,    48,    58,    59,    76,    81,
     113,   114,   115,   162,   226,   267,   293,   301,   309,   379,
     380,   384,   385,   386,   162,   155,   155,   155,   158,   387,
     158,    25,    35,    62,   120,   279,   437,   439,   440,   155,
     120,   155,   158,   158,    78,   155,   227,   228,   155,   120,
     407,    40,    44,    46,    47,    48,    49,    52,    61,    69,
      72,    74,    75,    77,    99,   114,   137,   162,   171,   204,
     230,   232,   234,   235,   242,   244,   245,   246,   249,   250,
     263,   266,   321,   659,   660,   120,    16,   186,   398,   400,
     420,   647,   658,   659,    49,    74,    75,   120,   155,   187,
     250,   419,   421,   431,   189,   419,   659,   155,   155,   658,
     659,    18,    19,   659,   155,    31,   216,   219,   219,   231,
     233,   320,   231,   233,   320,   231,   320,   231,   236,   320,
     120,   247,   247,   248,   158,   155,   402,   477,   317,   419,
     319,   419,   320,   328,   344,   344,     0,   346,   347,    34,
      50,   349,   366,     1,   192,   343,   192,   343,   114,   381,
     401,   419,   109,   192,   109,   343,   192,    43,    47,    52,
      71,   170,   173,   188,   214,   263,   414,   423,   428,   429,
     430,   445,   446,   450,     1,     3,    68,    73,   120,   424,
     169,    94,   134,   142,   143,   145,   153,   157,   159,   164,
     181,   205,   206,   207,   208,   209,   210,   497,   498,   255,
     101,   160,   178,   201,   119,   148,   161,   196,   203,   212,
     138,   152,    51,   202,   103,   104,   160,   178,   495,   195,
     155,   502,   121,   156,   158,   509,   510,   147,   158,   186,
     186,   186,   186,   382,   512,   382,    30,   657,   184,   198,
     184,   198,   168,   184,   660,   659,   171,   204,    48,   659,
     154,   120,    46,    48,    81,   108,   170,   658,   227,   228,
     229,   252,   616,   659,   659,   310,   139,   144,   114,   293,
     301,   384,   658,   399,   399,   419,   120,   189,   388,   389,
     155,   404,   419,     1,   162,   657,   115,   162,   362,   657,
     659,   120,   144,   109,   419,   458,   459,   659,   399,   419,
     419,   570,   659,   399,   155,   155,   419,   659,   144,   458,
     186,   186,   123,   109,   186,   123,   158,   158,   158,   659,
     155,   187,   188,   189,    36,   529,   530,   531,   419,   419,
       8,   177,    17,   419,   216,    30,    30,   420,   420,   508,
     420,   420,   420,   647,   420,   508,   420,   237,   236,   583,
     584,   659,   192,   192,   420,   419,   400,   419,   251,   417,
     418,   317,   319,   420,   344,   192,   343,   192,   343,     3,
     350,   366,   396,     1,   350,   366,   396,    34,   367,   396,
     367,   396,   407,   343,   407,   420,   420,   120,   170,   172,
     172,   401,   420,   420,   434,   435,   659,   290,   290,   434,
     120,   441,   476,   477,   480,   480,   480,   480,   479,   480,
     480,   480,    72,   481,   485,   485,   484,   486,   486,   486,
     486,   487,   487,   488,   488,   237,    96,    96,    96,   503,
     186,   419,   196,   515,   516,   572,   658,   419,   146,   189,
     420,   521,   510,   151,   189,   521,   109,   189,   189,   109,
     109,   387,    30,   660,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   369,   370,   371,    96,   139,   144,
     375,   376,   377,   659,   162,   162,   369,   657,   129,   134,
      56,    58,   102,   257,   270,   272,   283,   284,   285,   287,
     289,   617,   618,   619,   620,   621,   622,   629,   635,   636,
     252,    96,   305,   659,   144,   420,   120,   659,   659,   134,
     186,   186,   186,   659,    96,   109,   189,   398,   189,   658,
      98,    46,   658,   657,    98,    96,   144,   552,   659,   420,
     440,   186,   109,   190,   149,   552,   186,   189,   189,   155,
     186,   399,   399,   186,   144,   552,   420,   190,   420,   420,
     658,   420,   419,   419,   419,   659,   530,   531,   132,   199,
     186,   186,   186,   133,   192,   133,   192,    96,   224,   225,
     239,    96,   224,   225,   239,   239,   239,    96,    96,   243,
     231,   237,   109,   241,   144,   192,   189,   419,   186,    11,
      12,    20,   196,   506,   507,   589,   659,   418,   239,   366,
      34,    34,   192,   343,   192,   115,   401,   659,   172,   420,
     451,   452,   120,   447,   448,   109,    37,    98,   149,   436,
     437,   552,   659,    57,   220,   260,   425,   426,   480,   155,
     158,   265,   501,   512,   590,   593,   594,   595,   596,   597,
     601,   603,   605,   606,    40,    45,    46,    48,    54,    61,
      63,    64,    72,    99,   154,   158,   231,   323,   324,   325,
     326,   553,   555,   557,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   573,   574,   575,   576,   653,
     654,   655,   656,   659,   553,   492,   558,   659,   492,   186,
     187,   109,   189,   189,   512,   150,   167,   150,   167,   139,
     404,   387,   370,   134,   158,   555,   377,   420,   552,   657,
     657,   130,   131,   657,   283,   284,   285,   289,   659,   269,
     280,   269,   280,    30,   292,    98,   115,   158,   623,   626,
     617,    40,    45,    46,    54,    61,    63,    64,    72,    99,
     231,   391,   559,   653,   233,   305,   314,   420,   659,    96,
     305,   657,   155,   552,   553,   389,    96,   186,   200,   134,
     361,   657,   162,   134,    98,   361,   553,   420,   144,   437,
     155,   120,   420,   420,   149,   102,   461,   462,   463,   465,
     466,   102,   469,   470,   471,   472,   399,   186,   186,   155,
     420,   144,   192,   420,   123,   123,   189,   189,   189,    36,
     531,   132,   199,     9,    10,   105,   125,   127,   155,   197,
     526,   528,   539,   540,   543,   155,    30,    30,   238,   240,
     420,   420,   420,   238,   240,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   508,   120,   420,   420,    49,    74,
      75,   250,   401,   421,   431,   251,   586,   587,   155,   212,
     402,   420,   192,   115,   396,   396,   396,   451,    97,   108,
     118,   129,   453,   454,   455,   456,   109,   659,   109,   120,
     435,   129,   120,   420,   149,   437,   149,    37,   149,   436,
     437,   149,   552,   260,    55,    60,    79,   120,   436,   442,
     443,   444,   426,   419,   590,   597,   155,   291,   482,   642,
      98,   171,   258,   259,   261,   268,   278,   290,   591,   592,
     611,   612,   613,   614,   637,   640,   264,   266,   598,   616,
     273,   602,   638,   253,   254,   276,   607,   608,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   189,   555,
     158,   158,   146,   178,   196,   554,   146,   146,   420,   139,
     404,   572,   376,   292,    30,    98,   115,   158,   630,    30,
     623,   554,   554,   503,   293,   312,   552,   391,   233,   192,
     398,   553,   401,   420,   657,   109,   361,   420,   144,   398,
     459,   420,   420,   115,   462,   463,   102,   188,   115,   463,
     466,   120,   473,   553,   102,   115,   470,   102,   115,   472,
     186,   398,   420,   420,   420,   200,   469,   134,   197,   528,
       7,   399,   659,   197,   539,   399,   192,   192,   239,   239,
     239,   239,    98,   243,   243,   584,   188,   158,   158,   158,
     188,   589,   587,   506,   657,   130,   131,   455,   456,   456,
     452,   108,   144,   449,   552,   448,   435,   149,   436,   659,
     420,   149,   420,   129,   420,   149,   437,   149,   420,   149,
     120,   120,   420,   659,   444,    79,   186,   189,   590,   604,
     256,   220,   260,   274,   281,   641,    98,   262,   263,   639,
     256,   594,   641,   484,   611,   595,   149,   288,   599,   600,
     639,   292,   610,    80,   609,   189,   189,   568,   569,   189,
     196,   659,   189,   196,   553,   556,   189,    30,   189,   658,
     659,   659,   189,   189,   196,   659,   189,   189,   189,    30,
     138,   203,   632,   633,   634,    30,   631,   632,   277,   627,
     109,   624,   172,   659,   263,   503,   186,   128,   128,    98,
     657,   420,   186,   188,   188,   420,   401,   420,   188,   188,
     659,   188,   212,   120,   473,   120,   188,   120,   473,   188,
     186,   115,   531,   659,   197,   186,   531,   659,   186,   420,
     420,   420,   420,   322,   420,   420,   420,   419,   419,   419,
     155,   588,   456,   657,   420,   144,   420,   149,   420,   149,
     436,   420,   149,   420,   420,   659,   659,   443,   420,   186,
     486,    53,   131,   484,   484,   275,   282,   292,   615,   615,
     596,   155,   286,   189,   189,   109,   189,   109,   189,    96,
     189,   109,   189,   189,   189,   189,   189,   109,   189,   109,
     189,   630,   630,   634,   109,   189,    30,   628,   639,   625,
     626,   189,   393,   394,   503,   120,   231,   313,   293,   172,
     401,   420,   361,   420,   401,    96,   401,   420,   553,   659,
     188,   659,   420,   659,   188,   401,   120,    95,   185,   532,
     531,   659,   199,   531,   420,   189,   189,   189,   419,   449,
     420,   420,   420,   149,   420,    55,   484,   484,   201,   419,
     570,   571,   659,   570,   571,   553,   553,    96,   570,   570,
      30,   271,   109,   109,   456,   552,   659,   120,   231,   659,
     393,   473,    96,   188,    96,   659,     5,   135,   535,   536,
     538,   540,    29,   136,   533,   534,   537,   540,   199,   531,
     199,   200,   469,   186,   449,   420,   120,   484,   186,   189,
     189,   146,   189,   189,   553,   189,   189,   626,   394,   456,
     311,   659,   120,   231,   188,   473,   401,   420,   473,   188,
      95,   135,   538,   185,   136,   537,   199,   115,   659,   420,
     311,   659,   120,   401,   420,   188,   188,   120,   299,   311,
     659,   659,   312,   420,   312,   188,   503,   503,   201,   293,
     659,   231,   120,   659,   312,   503
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
     551,   551,   552,   553,   553,   553,   554,   554,   554,   555,
     555,   555,   555,   555,   555,   555,   556,   556,   557,   558,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     560,   561,   561,   561,   562,   563,   564,   565,   565,   565,
     566,   566,   566,   566,   566,   567,   568,   568,   568,   568,
     568,   568,   568,   569,   570,   571,   572,   573,   573,   574,
     575,   575,   576,   577,   577,   577,   578,   578,   578,   578,
     578,   578,   578,   578,   578,   578,   579,   579,   580,   580,
     581,   582,   583,   583,   584,   585,   586,   586,   587,   588,
     589,   589,   590,   591,   591,   592,   592,   593,   593,   594,
     594,   595,   595,   596,   596,   597,   598,   598,   599,   599,
     600,   601,   601,   601,   602,   602,   603,   604,   604,   605,
     606,   606,   607,   607,   608,   608,   608,   609,   609,   610,
     610,   611,   611,   611,   611,   611,   612,   613,   614,   615,
     615,   615,   616,   616,   617,   617,   617,   617,   617,   617,
     617,   617,   618,   618,   618,   618,   619,   619,   620,   621,
     621,   622,   622,   622,   623,   623,   624,   624,   625,   625,
     626,   627,   627,   628,   628,   629,   629,   629,   630,   630,
     631,   631,   632,   632,   633,   633,   634,   634,   635,   636,
     636,   637,   637,   637,   638,   639,   639,   639,   639,   640,
     640,   641,   641,   642,   643,   643,   644,   644,   645,   645,
     646,   647,   647,   647,   647,   648,   648,   648,   649,   650,
     651,   652,   653,   653,   653,   654,   655,   656,   657,   658,
     658,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   660,   660,   660,
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
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     661
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
       3,     7,     2,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     4,     3,     3,     3,     3,     4,     4,
       3,     4,     6,     4,     6,     4,     3,     4,     6,     6,
       4,     6,     6,     4,     1,     2,     1,     1,     1,     4,
       5,     6,     3,     3,     3,     3,     5,     7,     7,     5,
       5,     5,     7,     7,     5,     5,     3,     3,     5,     7,
       5,     7,     1,     4,     3,     5,     1,     2,     3,     3,
       1,     3,     2,     0,     1,     1,     2,     1,     3,     1,
       3,     1,     4,     1,     2,     3,     0,     1,     0,     1,
       4,     2,     3,     1,     0,     1,     4,     0,     1,     2,
       1,     3,     0,     1,     2,     2,     1,     0,     1,     0,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     2,     2,     3,     1,
       2,     2,     5,     2,     1,     1,     0,     2,     1,     3,
       4,     0,     2,     0,     2,     4,     4,     3,     2,     3,
       1,     3,     0,     1,     1,     2,     2,     2,     2,     1,
       2,     2,     2,     2,     3,     2,     3,     3,     4,     2,
       2,     1,     1,     3,     2,     3,     2,     3,     2,     3,
       3,     3,     3,     5,     5,     5,     5,     8,     5,     3,
       5,     7,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1
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
      -1,   158,   189,    -1,   146,    -1,   196,    -1,   178,    -1,
     557,    -1,   559,    -1,   154,    -1,   326,   158,   189,    -1,
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
     420,    -1,   321,   320,   420,   239,   420,    -1,   230,   320,
     508,    -1,   234,   320,   508,    96,   420,    -1,   235,   320,
     236,   237,   508,   243,   420,    -1,   654,    -1,   655,    -1,
     656,    -1,   325,    -1,   323,    -1,   324,    -1,    30,    -1,
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
     275,    -1,   235,    -1,   241,    -1,   238,    -1,   232,    -1,
     225,    -1,   224,    -1,   226,    -1,   243,    -1,   233,    -1,
     234,    -1,   240,    -1,   230,    -1,   239,    -1,    67,    -1,
      65,    -1,    76,    -1,   171,    -1,   204,    -1,   248,    -1,
     246,    -1,   247,    -1,   244,    -1,   245,    -1,   250,    -1,
     251,    -1,   252,    -1,    66,    -1,   301,    -1,   299,    -1,
     300,    -1,   305,    -1,   306,    -1,   307,    -1,   302,    -1,
     303,    -1,   304,    -1,    81,    -1,    82,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,    -1,
      89,    -1,    90,    -1,    91,    -1,   293,    -1,   294,    -1,
     295,    -1,   296,    -1,   297,    -1,   298,    -1,   309,    -1,
     310,    -1,   311,    -1,   312,    -1,   313,    -1,   314,    -1,
     315,    -1,    92,    -1,   107,    -1,   116,    -1,   174,    -1,
     182,    -1,   191,    -1,   140,    -1,    93,    -1,   117,    -1,
     141,    -1,   183,    -1,   320,    -1,   321,    -1,   322,    -1,
     326,    -1,    26,    -1
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
    2001,  2005,  2013,  2016,  2018,  2021,  2024,  2026,  2028,  2030,
    2032,  2034,  2036,  2040,  2042,  2044,  2046,  2048,  2052,  2054,
    2056,  2058,  2060,  2062,  2064,  2066,  2068,  2070,  2072,  2074,
    2076,  2080,  2084,  2089,  2094,  2098,  2102,  2106,  2110,  2115,
    2120,  2124,  2129,  2136,  2141,  2148,  2153,  2157,  2162,  2169,
    2176,  2181,  2188,  2195,  2200,  2202,  2205,  2207,  2209,  2211,
    2216,  2222,  2229,  2233,  2237,  2241,  2245,  2251,  2259,  2267,
    2273,  2279,  2285,  2293,  2301,  2307,  2313,  2317,  2321,  2327,
    2335,  2341,  2349,  2351,  2356,  2360,  2366,  2368,  2371,  2375,
    2379,  2381,  2385,  2388,  2389,  2391,  2393,  2396,  2398,  2402,
    2404,  2408,  2410,  2415,  2417,  2420,  2424,  2425,  2427,  2428,
    2430,  2435,  2438,  2442,  2444,  2445,  2447,  2452,  2453,  2455,
    2458,  2460,  2464,  2465,  2467,  2470,  2473,  2475,  2476,  2478,
    2479,  2481,  2483,  2485,  2487,  2489,  2491,  2493,  2497,  2501,
    2503,  2505,  2507,  2510,  2514,  2516,  2518,  2520,  2522,  2524,
    2526,  2528,  2530,  2533,  2536,  2538,  2540,  2543,  2546,  2550,
    2552,  2555,  2558,  2564,  2567,  2569,  2571,  2572,  2575,  2577,
    2581,  2586,  2587,  2590,  2591,  2594,  2599,  2604,  2608,  2611,
    2615,  2617,  2621,  2622,  2624,  2626,  2629,  2632,  2635,  2638,
    2640,  2643,  2646,  2649,  2652,  2656,  2659,  2663,  2667,  2672,
    2675,  2678,  2680,  2682,  2686,  2689,  2693,  2696,  2700,  2703,
    2707,  2711,  2715,  2719,  2725,  2731,  2737,  2743,  2752,  2758,
    2762,  2768,  2776,  2778,  2780,  2782,  2784,  2786,  2788,  2790,
    2792,  2794,  2796,  2798,  2800,  2802,  2804,  2806,  2808,  2810,
    2812,  2814,  2816,  2818,  2820,  2822,  2824,  2826,  2828,  2830,
    2832,  2834,  2836,  2838,  2840,  2842,  2844,  2846,  2848,  2850,
    2852,  2854,  2856,  2858,  2860,  2862,  2864,  2866,  2868,  2870,
    2872,  2874,  2876,  2878,  2880,  2882,  2884,  2886,  2888,  2890,
    2892,  2894,  2896,  2898,  2900,  2902,  2904,  2906,  2908,  2910,
    2912,  2914,  2916,  2918,  2920,  2922,  2924,  2926,  2928,  2930,
    2932,  2934,  2936,  2938,  2940,  2942,  2944,  2946,  2948,  2950,
    2952,  2954,  2956,  2958,  2960,  2962,  2964,  2966,  2968,  2970,
    2972,  2974,  2976,  2978,  2980,  2982,  2984,  2986,  2988,  2990,
    2992,  2994,  2996,  2998,  3000,  3002,  3004,  3006,  3008,  3010,
    3012,  3014,  3016,  3018,  3020,  3022,  3024,  3026,  3028,  3030,
    3032,  3034,  3036,  3038,  3040,  3042,  3044,  3046,  3048,  3050,
    3052,  3054,  3056,  3058,  3060,  3062,  3064,  3066,  3068,  3070,
    3072,  3074,  3076,  3078,  3080,  3082,  3084,  3086,  3088,  3090,
    3092,  3094,  3096,  3098,  3100,  3102,  3104,  3106,  3108,  3110,
    3112,  3114,  3116,  3118,  3120,  3122,  3124,  3126,  3128,  3130,
    3132,  3134,  3136,  3138,  3140,  3142,  3144,  3146,  3148,  3150,
    3152,  3154,  3156,  3158,  3160,  3162,  3164,  3166,  3168,  3170,
    3172,  3174,  3176,  3178,  3180,  3182,  3184,  3186,  3188,  3190,
    3192,  3194,  3196,  3198,  3200,  3202,  3204,  3206,  3208,  3210,
    3212,  3214,  3216,  3218,  3220,  3222,  3224,  3226,  3228,  3230,
    3232
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
    5192,  5196,  5204,  5212,  5216,  5221,  5256,  5262,  5268,  5278,
    5282,  5287,  5291,  5295,  5299,  5303,  5310,  5316,  5326,  5334,
    5342,  5346,  5350,  5354,  5358,  5362,  5366,  5370,  5374,  5378,
    5386,  5394,  5398,  5402,  5410,  5417,  5425,  5433,  5437,  5441,
    5449,  5453,  5459,  5465,  5469,  5479,  5487,  5491,  5497,  5506,
    5515,  5521,  5527,  5537,  5554,  5561,  5576,  5603,  5607,  5615,
    5623,  5627,  5638,  5655,  5661,  5667,  5677,  5681,  5687,  5693,
    5697,  5703,  5707,  5713,  5719,  5726,  5736,  5741,  5749,  5755,
    5765,  5787,  5796,  5802,  5815,  5829,  5836,  5842,  5852,  5861,
    5869,  5875,  5893,  5901,  5905,  5912,  5917,  5925,  5929,  5936,
    5940,  5947,  5951,  5958,  5962,  5971,  5984,  5987,  5995,  5998,
    6006,  6014,  6022,  6026,  6034,  6037,  6045,  6057,  6060,  6068,
    6080,  6086,  6096,  6099,  6107,  6111,  6115,  6123,  6126,  6134,
    6137,  6145,  6149,  6153,  6157,  6161,  6169,  6177,  6189,  6201,
    6205,  6209,  6217,  6223,  6233,  6237,  6241,  6245,  6249,  6253,
    6257,  6261,  6269,  6273,  6277,  6281,  6289,  6295,  6305,  6315,
    6319,  6327,  6337,  6348,  6355,  6359,  6367,  6370,  6377,  6382,
    6391,  6401,  6404,  6411,  6415,  6423,  6432,  6439,  6449,  6453,
    6460,  6466,  6476,  6479,  6486,  6491,  6503,  6511,  6523,  6531,
    6535,  6543,  6547,  6551,  6559,  6567,  6571,  6575,  6579,  6587,
    6595,  6607,  6611,  6619,  6633,  6637,  6644,  6649,  6657,  6662,
    6671,  6679,  6686,  6692,  6699,  6710,  6716,  6726,  6733,  6740,
    6765,  6793,  6821,  6825,  6829,  6837,  6845,  6853,  6865,  6869,
    6870,  6883,  6884,  6885,  6886,  6887,  6888,  6890,  6891,  6892,
    6893,  6894,  6895,  6896,  6897,  6898,  6899,  6903,  6904,  6905,
    6906,  6907,  6908,  6909,  6910,  6911,  6912,  6913,  6914,  6915,
    6916,  6917,  6918,  6919,  6920,  6921,  6922,  6923,  6924,  6925,
    6926,  6927,  6928,  6929,  6930,  6931,  6932,  6933,  6934,  6935,
    6936,  6937,  6938,  6939,  6940,  6941,  6942,  6943,  6944,  6945,
    6946,  6947,  6948,  6949,  6950,  6951,  6952,  6953,  6954,  6955,
    6956,  6957,  6958,  6959,  6960,  6961,  6962,  6963,  6964,  6965,
    6966,  6967,  6968,  6969,  6970,  6971,  6972,  6973,  6974,  6975,
    6976,  6977,  6978,  6979,  6980,  6981,  6982,  6983,  6984,  6985,
    6986,  6987,  6988,  6989,  6990,  6991,  6992,  6993,  6994,  6995,
    6996,  6997,  6998,  6999,  7000,  7001,  7002,  7003,  7004,  7005,
    7006,  7007,  7008,  7009,  7010,  7011,  7012,  7013,  7014,  7015,
    7016,  7017,  7018,  7019,  7020,  7021,  7022,  7023,  7024,  7025,
    7026,  7027,  7028,  7029,  7030,  7031,  7032,  7033,  7034,  7035,
    7036,  7037,  7038,  7039,  7040,  7041,  7042,  7043,  7044,  7045,
    7046,  7047,  7048,  7049,  7050,  7051,  7052,  7053,  7054,  7055,
    7056,  7057,  7058,  7059,  7060,  7061,  7062,  7063,  7064,  7065,
    7066,  7067,  7068,  7069,  7070,  7071,  7072,  7073,  7074,  7075,
    7076,  7077,  7078,  7079,  7080,  7081,  7082,  7083,  7084,  7085,
    7086,  7087,  7088,  7089,  7090,  7091,  7092,  7093,  7094,  7095,
    7096,  7097,  7098,  7099,  7100,  7101,  7102,  7103,  7104,  7108,
    7113
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
  const int jsoniq_parser::yylast_ = 18131;
  const int jsoniq_parser::yynnts_ = 321;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 546;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 341;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 595;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17778 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7117 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"


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

