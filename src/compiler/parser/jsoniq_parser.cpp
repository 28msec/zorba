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
#line 88 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"


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
#line 69 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 916 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1052 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"

#include "compiler/parser/jsoniq_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 99 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 185 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 914 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 946 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 946 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 946 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 946 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 424: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "NotExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 531: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 569: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 946 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 591: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 599: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 601: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 609: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 619: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 623: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 631: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 641: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 653: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 661: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 662: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2783 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
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
#line 133 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2880 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 1070 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1074 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1078 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1086 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1096 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1105 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1111 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1119 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1125 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1141 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1145 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl(
        LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1159 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1173 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1189 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1197 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1205 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1224 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1229 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1236 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1243 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1255 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1265 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 1272 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 1279 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1314 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1319 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1327 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1335 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1343 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1348 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1356 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1361 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1369 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1374 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1382 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1387 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1392 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1420 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1425 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1433 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1441 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1459 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1470 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1475 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1483 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1490 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1497 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1506 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1519 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1527 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1534 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1544 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 1551 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1581 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1587 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1596 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1613 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1623 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1624 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1625 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1626 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1627 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1628 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1629 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1631 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1637 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1653 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1661 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1668 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1676 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1683 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1688 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1696 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1704 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1718 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1732 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1749 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1754 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1762 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1770 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1781 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1786 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1795 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1800 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1807 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1812 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1822 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1827 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1836 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1842 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1855 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1860 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1868 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1879 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1894 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1906 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1921 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1926 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1936 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1951 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1962 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1967 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1977 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1986 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1995 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2004 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2016 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2020 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2026 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2030 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2040 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2050 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2063 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2069 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2078 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2083 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2090 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2097 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2109 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2119 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2129 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2140 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2156 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2176 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2180 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2184 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2192 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2196 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2200 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2208 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2213 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2225 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 2232 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 2242 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 189:

/* Line 690 of lalr1.cc  */
#line 2275 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2283 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));
      if ((yysemantic_stack_[(3) - (2)].expr) == NULL || (block != NULL && block->isEmpty()))
      {        
        (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)));
      }
      else if (block == NULL)
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
#line 2305 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2313 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2321 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2328 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 2335 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2346 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2355 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2364 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2373 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2386 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2394 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2402 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2410 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2425 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2430 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2438 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2452 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2469 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2494 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2502 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2509 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2520 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2529 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2536 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2541 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 216:

/* Line 690 of lalr1.cc  */
#line 2554 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 235:

/* Line 690 of lalr1.cc  */
#line 2601 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 236:

/* Line 690 of lalr1.cc  */
#line 2615 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2623 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2628 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2636 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2641 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2646 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2654 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 243:

/* Line 690 of lalr1.cc  */
#line 2663 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 244:

/* Line 690 of lalr1.cc  */
#line 2675 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 245:

/* Line 690 of lalr1.cc  */
#line 2685 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 246:

/* Line 690 of lalr1.cc  */
#line 2698 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2722 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2729 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2739 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2745 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2754 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2764 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      // this adds on shift-reduce conflict (probably with FTRange expression)
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2772 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2779 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2787 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2799 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 266:

/* Line 690 of lalr1.cc  */
#line 2809 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 267:

/* Line 690 of lalr1.cc  */
#line 2819 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 268:

/* Line 690 of lalr1.cc  */
#line 2829 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 269:

/* Line 690 of lalr1.cc  */
#line 2839 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 270:

/* Line 690 of lalr1.cc  */
#line 2849 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 271:

/* Line 690 of lalr1.cc  */
#line 2859 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 272:

/* Line 690 of lalr1.cc  */
#line 2869 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 273:

/* Line 690 of lalr1.cc  */
#line 2880 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2889 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 275:

/* Line 690 of lalr1.cc  */
#line 2899 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 276:

/* Line 690 of lalr1.cc  */
#line 2909 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 277:

/* Line 690 of lalr1.cc  */
#line 2925 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2943 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2951 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2957 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2969 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2977 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2987 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2995 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3007 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3013 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3026 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3030 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3038 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3042 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3051 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3055 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3059 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3069 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3077 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3084 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3090 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3100 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3104 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3108 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3116 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3124 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3132 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3144 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3152 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3158 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3168 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3174 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3184 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3188 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3198 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3204 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3210 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3216 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3225 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3234 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3243 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3256 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3260 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3268 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3274 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3284 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3292 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3301 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3314 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3321 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3333 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3337 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3349 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3356 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3362 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3371 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3378 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3384 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3395 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3402 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3408 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3417 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3426 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3433 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3444 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3451 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3463 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3469 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3481 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3487 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3498 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3504 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3515 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3521 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3532 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3538 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3558 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3562 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3571 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3575 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3582 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3586 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new ComparisonExpr(
              LOC((yyloc)),
              new ValueComp( LOC((yyloc)), ParseConstants::op_val_not ),
              (yysemantic_stack_[(2) - (2)].expr),
              NULL
          );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3599 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3603 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 365:

/* Line 690 of lalr1.cc  */
#line 3613 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3620 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3629 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3638 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3643 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3652 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3661 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3670 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3683 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3687 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3699 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3703 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3710 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3714 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3721 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3725 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3734 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3738 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3742 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3750 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3760 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3766 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3772 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3786 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3790 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3802 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3808 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3818 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3822 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3832 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3836 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3846 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3850 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3860 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3864 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3874 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3878 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3891 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3899 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3903 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3907 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3911 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3921 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3925 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3929 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3936 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3941 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3949 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3953 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3957 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3961 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3965 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3969 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3977 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3981 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3985 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3993 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3997 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4001 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4005 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4016 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4022 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4032 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4038 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4048 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4052 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4056 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4119 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4141 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 438:

/* Line 690 of lalr1.cc  */
#line 4169 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4333 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4337 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4347 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4351 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4355 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4359 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4368 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4372 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4376 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4380 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4384 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4389 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4393 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4397 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4401 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4410 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4416 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4426 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4434 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4442 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4446 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4450 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4454 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4458 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4462 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4466 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4470 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4475 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4479 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4483 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4487 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4495 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4499 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4503 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4507 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4515 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4522 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4529 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4539 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4543 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4551 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4559 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4563 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4571 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4579 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4587 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4641 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4645 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 488:

/* Line 690 of lalr1.cc  */
#line 4667 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4673 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4679 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4685 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4695 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4699 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4707 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4715 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4727 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4731 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4739 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4743 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4747 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4755 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4763 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 503:

/* Line 690 of lalr1.cc  */
#line 4780 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4788 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 505:

/* Line 690 of lalr1.cc  */
#line 4807 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 506:

/* Line 690 of lalr1.cc  */
#line 4826 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 507:

/* Line 690 of lalr1.cc  */
#line 4848 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4854 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4865 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4871 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4882 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4897 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4902 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4911 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4915 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4922 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4928 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4934 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4941 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4952 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4956 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4963 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4969 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4975 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4982 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4993 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4997 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 5005 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 5009 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 5017 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 5021 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 5025 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 5030 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 5039 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 5043 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 5051 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 5059 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 5064 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 5072 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 5077 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 5085 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 5093 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 5103 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 5108 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 5113 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 5118 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 5129 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 5137 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 5141 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 5158 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 5162 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 5170 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5178 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5186 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5190 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5198 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5202 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5210 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5218 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5222 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5226 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5231 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5266 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5272 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5278 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5288 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5292 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5296 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5301 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5305 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5322 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5329 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5335 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5345 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5353 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5361 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5369 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5373 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5377 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5385 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5389 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5393 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5397 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5405 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5413 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5417 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5421 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5429 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5436 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5444 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5452 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5456 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5460 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5468 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5472 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5478 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5484 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5488 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5498 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5506 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5510 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5516 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5525 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5534 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5540 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5546 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5556 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5573 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5580 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5595 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5622 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5626 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5634 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5646 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5657 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5674 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5686 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5700 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5706 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5716 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5726 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5732 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5738 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5755 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5760 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5774 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5784 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5806 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5815 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5821 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5834 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5848 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5855 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5861 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5871 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5880 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5888 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5894 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5912 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5920 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5924 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5931 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5936 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5948 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5955 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5959 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5966 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5970 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5977 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5981 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5990 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 6002 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 6006 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6013 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6017 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 6025 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6033 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6041 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6045 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6052 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6056 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6064 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6075 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6079 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6087 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6099 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6105 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6114 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6118 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6126 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6130 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6134 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6141 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6145 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6152 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6156 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6164 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6168 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6172 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6176 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6180 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6188 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6196 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6208 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6220 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6224 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6228 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6236 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6242 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6252 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6256 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6260 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6264 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6268 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6272 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6276 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6280 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6288 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6292 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6296 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6300 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6308 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6314 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6324 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6334 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6338 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6346 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 726:

/* Line 690 of lalr1.cc  */
#line 6356 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 727:

/* Line 690 of lalr1.cc  */
#line 6367 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6374 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6378 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6385 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6389 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6396 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6401 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6410 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6419 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6423 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6430 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6434 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6442 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6451 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6458 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6468 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6472 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6479 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6485 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6494 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6498 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6505 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6510 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6522 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6530 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6542 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6550 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6554 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6562 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6566 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6570 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6578 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6586 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6590 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6594 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6598 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6606 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6614 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6626 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6630 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6638 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6652 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6656 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6663 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6668 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6676 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6681 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6690 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6698 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6705 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6711 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6718 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6729 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6735 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 781:

/* Line 690 of lalr1.cc  */
#line 6745 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6750 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(4) - (2)].expr),
                                        (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6756 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 784:

/* Line 690 of lalr1.cc  */
#line 6766 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6773 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6777 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6784 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 788:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 789:

/* Line 690 of lalr1.cc  */
#line 6831 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 790:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 791:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 792:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 793:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6998 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 7011 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 7012 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 7013 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 7014 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 7015 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 7017 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 7018 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 7019 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 7020 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 7021 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 7022 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 7023 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 7024 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 7025 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 7026 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 7031 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 7032 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 7033 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 7034 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 7035 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 7036 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 7037 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 7038 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 7039 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 7040 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 7041 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 7042 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 7043 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 7044 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 7045 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 7046 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 7047 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 7048 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 7049 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 7050 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 7051 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 7052 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 7053 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 7054 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 7055 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 7056 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 7057 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 7058 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 7059 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 7060 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 7061 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 7062 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 7063 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 7064 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 7065 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 7066 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 7067 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 7068 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 7069 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 7070 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 7071 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 7072 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 7073 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 7074 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 7075 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 7076 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 7077 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 7078 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 7079 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 7080 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 7081 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 7082 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 7083 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 7084 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 7085 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 7086 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 7087 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 7088 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 7089 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 7090 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 7091 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 7092 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 7093 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 7094 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 7095 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 7096 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 7097 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 7098 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 7099 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 7100 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 7101 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 7102 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 7103 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 7104 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 7105 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 7106 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 7107 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 7108 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 7109 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 7110 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 7111 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 7112 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 7113 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 7114 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 7115 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 7116 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 7117 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 7118 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 7119 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 7120 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 7121 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 7122 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 7123 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 7124 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 7125 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 7126 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 7127 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 7128 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 7129 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 7130 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 7131 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 7132 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 7133 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 7134 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 7135 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 7136 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 7137 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 7138 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 7139 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 7140 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 7141 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 7142 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 7143 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 7144 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 7145 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 7146 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 7147 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 7148 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 7149 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 7150 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 7151 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 7152 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 7153 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 7154 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 7155 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 7156 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 7157 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 7159 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 7160 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 7162 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 7163 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 7164 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 7165 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 7166 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 7168 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 7170 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 7171 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 7172 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 7173 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 7174 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 7175 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 7176 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 7177 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 7178 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 7179 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 7180 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 7181 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 7182 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 7183 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 7184 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 7185 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 7186 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 7187 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 7188 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 7189 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 7190 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 7191 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 7192 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 7193 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 7194 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 7195 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 7196 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 7197 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 7198 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 7199 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 7200 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 7201 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 7202 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 7203 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 7204 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 7205 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 7206 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 7207 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 7208 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7209 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 7210 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 7211 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 7212 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 7213 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 7214 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 7215 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 7216 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 7217 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 7218 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 7219 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 7220 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 7221 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 7222 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 7223 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 7224 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 7225 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 7226 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 7227 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 7228 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 7231 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 7240 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12251 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1476;
  const short int
  jsoniq_parser::yypact_[] =
  {
      4693,  8020,  8020,  8020,  8020, -1476, -1476,   271,   293, -1476,
     991,   411, -1476, -1476, -1476,   444, -1476, -1476, -1476,   552,
   -1476,   575,   700,   438,   523,   170, -1476,    82, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476,   583, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476,   704, -1476,   614, -1476,   752,   804, -1476,
     524, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476,   751, -1476, -1476, -1476, -1476, -1476, -1476, -1476,   836,
   -1476, -1476, -1476, -1476, -1476, 18184, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476,   872, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476,  5309, 10134, 10436, 18184, -1476, -1476,
     839, -1476, -1476, -1476, -1476,   843, -1476, -1476, -1476,  6816,
   -1476,  7114, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476,   855, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476,    74,   812,   824, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, 14060, -1476,  5612,
   -1476, 14362,   408, -1476, -1476, -1476, -1476, -1476, -1476,   927,
   -1476,   801,   806,   807, -1476, -1476,   896,   913, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
     754, -1476, 13758, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, 10738, 11040, 11342, -1476,  5001,  7416,  1069, -1476,  8322,
   -1476, -1476,   153,    99, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,   100, -1476,
   -1476, -1476, -1476, -1476, -1476,   673, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476,  8020, -1476, -1476, -1476, -1476,    55,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,   155,
   -1476,   879, -1476, -1476, -1476,    43, -1476,   702, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476,   904,   980, -1476, -1476,  1122,
     820,   976,    10,   722,   788,   764, -1476,  1025,   876,   977,
     978, 12852, -1476,   884, -1476, -1476,    28, -1476, -1476, -1476,
   -1476,   769, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476,   934,   925, -1476, -1476, -1476,
   -1476, -1476,   898, -1476,  8020,   899,   900,   901,  8020,   242,
     242,  1058,    25,   528,   785, 18475, 18184,   266,  1041, 18184,
     936,   971,   628,  6816,   778,   840, 18184, 18184,   783,    73,
      46, -1476, -1476, -1476,  6816,  8020,  8020, 12248,   504,   939,
   12248,  1095,   109,   137, 18184,   979,   953,   992, -1476, 12248,
   18184,  8020, 12248, 12248, 18184,  8020,   945,   952, 12248, 18184,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,   964, -1476,
   18184, -1476,   923,  7718,   987,   348,   988,   934,   955,   959,
     960, 18184,  5309, -1476,   965,   173, -1476,   551, -1476,    92,
    1086, 12248, 12248,   192, -1476, -1476, -1476,  1107, 12248,   909,
   -1476,  1098,  1099, 12248, 12550, 14664,   769, 12248, 12550,  5915,
     282,    19, 12248, 14664,   635, 12248,   893,   895, 18184,   940,
     941, 12248, 12248,  8020,   885, -1476, -1476,    60, -1476,    66,
   12248,   902,  7416, -1476, -1476, -1476, -1476, -1476,   991,   170,
     102,   106,  1132,  8624,  3132,  8926,  3451,   836, -1476, -1476,
     432,   836, -1476, 12248,  4083, -1476,  1018, -1476,    82,   969,
     968,   970,  8020, 12248, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, 18184, -1476,   853,   856, 18184,  1027, 13154,
   13154, 13456, -1476, 13456, 13456, -1476, 13456, -1476, 13456, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, 13456, 13456,  1073, 13456,
   13456, 13456, 13456, 13456, 13456, 13456, 13456, 13456, 13456, 13456,
   13456,   911,  1053,  1055,  1059, -1476, -1476, -1476, 14664, 11644,
   -1476,  6216, 12248,  9530,  1000, -1476,  1006,  9832, -1476, -1476,
   -1476, -1476,   291, -1476,   351, -1476, -1476, -1476, -1476, -1476,
   -1476,  1049,  1051,   438,  1131, -1476, -1476, 18475,   975,   747,
   18184,  1001,  1002,   975,  1058,  1033,  1032, -1476, -1476, -1476,
     134,   915,  1072,   864, 18184,  1026, 12248,  1052, 18184, 18184,
   -1476,  1039,   989,   993,   131, 18184,  1078,   375, -1476,  8020,
   -1476,   119, -1476,  6816,  1080,  1134,  6816,  1058,  1083,   589,
   18184, 12248,    82,   236,    32, -1476,   515,   997,   133,   144,
    1030, -1476,  1005,  8020,  8020,   261,   638, 12248,   318, -1476,
   -1476, 12248,  5915, -1476, 12248, 12248, 12248, 12248, -1476, 12248,
   -1476, 12248, -1476, 18184,  1086, -1476,   303,   366,   380, -1476,
   -1476, -1476,   409, -1476,    29,    33, -1476, -1476,   769,   430,
     472,   288,   265, 12248, 12248,  1090,   738, 12248,   944, 14966,
     951,   329, -1476,  1048, -1476, -1476,  1003,   223,  7718,   415,
    4391,   885, -1476, -1476, -1476,   954, 12248, -1476,   153,   744,
    1162,   817, -1476, -1476,   124, -1476, -1476, -1476,   129, -1476,
      71, -1476, -1476, -1476, -1476, -1476,  3767, -1476, -1476, -1476,
   18184,  1028, 12248,  1077, -1476, -1476, -1476,  1094, -1476,    65,
   -1476, -1476,  1094, 18184,    40,   980, -1476, -1476, -1476, -1476,
   -1476, 13456, -1476, -1476, -1476,   108, -1476,   722,   722,    20,
     788,   788,   788,   788,   764,   764, -1476, -1476, 16725, 16725,
   18184, 18184, -1476, -1476,   466, -1476, -1476, -1476, -1476, -1476,
     292, -1476, -1476, -1476,   416, -1476, -1476, -1476,   519,   242,
   -1476, -1476,   772,   798,   742, -1476,   438, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476,   975, -1476,  1065,
   17018,  1060, 12248, -1476, -1476, -1476,  1109,  1058,  1058,   975,
   -1476,   343,  1058,   753, 18184,   510,   721,  1181, -1476, -1476,
     920,    61, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476,   134,    72,   981,   688, 12248, -1476, 18184,
    1119,   914,  1058, -1476, -1476,  1063,  1109, 16725,  1100,  1126,
    1037,  1024,  1092,  1058,  1066,  1096,  1138,  1058, 16725, 12248,
     -38, -1476, -1476, -1476,  1074,  1117, 12248, 12248,  1091, -1476,
    1139,  1140,  8020, -1476,  1061,  1062,  1097, 12248,  1102,  1067,
   12248, -1476,  1127,  1128, -1476,   269,   382,   385,  1217, -1476,
     511, -1476,   502,  1105, -1476, -1476,  1225, -1476,  1227, -1476,
     757, 12248, 12248, 12248,   771, 12248, 12248, 12248, 12248, 12248,
    1164, -1476, 12248, 12248, -1476, 12248, 12248,    -5, 14664,  1146,
   12248, 12248, -1476,  9228,   120,  1017, -1476, -1476, -1476, -1476,
   -1476, -1476,    18, -1476, -1476, 12248, -1476,   156,   140,    71,
    8926,  3451,  8926,  1190, -1476, -1476, 12248,   818,  1163, -1476,
   18184,  1167, -1476, 17893,  1144,  1157, 12248,    84,  1129,    44,
     541,  1020, -1476, -1476,   737,    40, -1476, 12248,   108,   425,
     665, -1476,   994,   392,  1019,  1016, -1476, -1476,   840, -1476,
    1014,   679,  1130,  1133,  1136,  1137,  1143,  1148,  1149,  1150,
    1151,  1152,  1153, 15553,  1154,  1155,  1156,  1158,  1159,  1160,
   -1476,   696, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476,  1169, -1476, -1476, -1476, -1476,
   11946, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
     827, -1476,  1259, 17018,   327, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476,   998, -1476, -1476,  1266, -1476, -1476,
   -1476, -1476, -1476,   750,  1268, -1476,   852, -1476, -1476, -1476,
    1130,  1133,  1136,  1143,  1148,  1149,  1150,  1151,  1152,  1155,
   -1476,   696,   696, 14664,  1009,  1007, -1476,  1109,    72,  1071,
    1145,  8020, -1476, -1476, -1476, 16725, -1476,  8020,  1058,  1211,
   -1476, -1476, -1476,  1058,  1211, -1476, -1476, 12248,  1177,  8020,
   18184, -1476, -1476, 12248, 12248,   633, -1476,   290,   849, -1476,
   15846,   866, -1476,   868, -1476,  1161, -1476, -1476,  8020, -1476,
   12248, -1476, -1476, 12248, 12248,  1123,  1139,  1222, -1476,  1191,
   -1476,   649, -1476, -1476,  1319, -1476, -1476,  8020, 18184, -1476,
     656, -1476, -1476, -1476,  8020,  1147,  1165,  1101,  1103, -1476,
   -1476, -1476,  1104,  1106, -1476, -1476, -1476,  1237, -1476,  1031,
   -1476, -1476, -1476,  1111, 12248,   602, 18184,  1168, -1476,  1180,
    1188,  1192,  1193, -1476,   879,   574,  4391,  1017, -1476,  9228,
    4391, -1476, -1476,  1162,   718, -1476, -1476, -1476,  1163, -1476,
    1058, -1476,   811, -1476,    89,  1241, -1476, 12248,   770,  1077,
   18184, -1476,   338, 18184, -1476, 12248,  1203, 12248,  1226, 12248,
     226,  1209, 12248,  1210, -1476,  1240,  1245, 12248, 18184,   729,
    1282, -1476, -1476, -1476,   500,  1179, -1476,   108,  1113, -1476,
   -1476,   -52, -1476,   195,   181,  1115,   108,   195, 13456, -1476,
      98, -1476, -1476, -1476, -1476, -1476, -1476,   108,  1223,  1085,
     915,   181, -1476, -1476,  1082,  1295, -1476, -1476, -1476,  1189,
     449, 17311, 15260,  1194,  6516, 18184, 18184,  1196, 17602,  1197,
   -1476,  1198,  1201,  1202,  1204,  1205,  1207,  1208, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476,  1347,   296,  1349,   296,  1121,  1271, -1476, -1476,  1220,
   18184,  1118, -1476, -1476, 14664, -1476,  1213, -1476,  1254,  1272,
    1303,  1058,  1211, -1476, 12248,  1216, -1476, -1476, -1476,  1219,
   -1476,   312, 12248,  8020,  1221,   489, -1476, 18184,   651, -1476,
   16139,    38, -1476, 16432,  1224, -1476, -1476,  1228, -1476, -1476,
   -1476, 12248,   869,  1217, 18184,   762, -1476,  1229,  1217, 18184,
   -1476,  1230, -1476, -1476, 12248, 12248, 12248, 12248,  1089, 12248,
   12248, -1476, 12248, -1476, 12248, 12248, 12248, 12248,  9228,   476,
   -1476, -1476, -1476, -1476, -1476,  1241, -1476, -1476, -1476,  1058,
   12248, -1476,  1261, -1476, -1476, 12248,  1270, -1476, -1476, 12248,
   -1476,   361, -1476, 12248,  1273, 12248, -1476, 12248, 18184, 18184,
   -1476,   117, -1476, 12248, -1476, -1476, -1476,  1231, 13456, -1476,
   -1476, -1476, -1476, -1476,   367, 13456, 13456,   653, -1476,  1019,
   -1476,   211, -1476,  1016,   108,  1253, -1476, -1476,  1135, -1476,
   -1476, -1476, -1476, -1476, -1476,  1234,  1235, -1476,   526,   531,
    1324,  1236, -1476,   540, -1476,  1238, -1476,  1239,  1242,  1244,
   -1476, -1476,   554,   564, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476,   483,   483, -1476,   296, -1476, -1476,   597,
   -1476,  1396,   -14,  1331,  1246, 14664,   -37,  1141,  1258, -1476,
    9228, 12248,  1058, -1476, -1476, -1476, 12248, 12248, -1476, -1476,
   -1476,  9228,  9228,  1340,  8020, 16725, 18184,   712, 18184, 12248,
   18184,   719,  9228, -1476,   308,    42,  1217, 18184, -1476,  1248,
    1217, -1476, -1476, -1476, -1476, -1476, 12248, -1476, -1476, -1476,
   -1476,   423,   441,   453, 12248, -1476, -1476, -1476,  1329, 12248,
   -1476, 12248, -1476, 12248,  1289, -1476, 12248, -1476, -1476, -1476,
    1384, -1476, -1476, -1476,   788, 13456, 13456,    20,   733, -1476,
   -1476, -1476, -1476, -1476, -1476, 12248, -1476, -1476, -1476, 18184,
   -1476, 18184, -1476, 16725, -1476, 16725,  1344, -1476, -1476, -1476,
   -1476, 18184, -1476, 18184, -1476, -1476, -1476, -1476,  1411, -1476,
   -1476, -1476,  1173,  1336, -1476, -1476,  1339, -1476,   878, 18184,
    1332,  1218, 18184, 14664, -1476, -1476,  1211, -1476, -1476, 16725,
   -1476, -1476, -1476,  1357, 12248,  1263, -1476,  1358,  9228, -1476,
   18184,   675,   713, -1476,  1256,  1217, -1476,  1257, -1476,  1260,
    1139,  1140,   505, -1476,  1329, -1476, -1476, 12248, -1476,  1337,
      20,    20, 13456,   506,  1275,  1276,  1315,  1278,  1279, -1476,
   -1476, 16725,  1281,  1283, -1476, -1476,  1331, 14664, -1476,  1241,
    1166, 18184,  1342,  1243,  1339,   725, 16725,  8020, 16725,  1285,
   -1476, -1476,  1376,   678, -1476, -1476, -1476, -1476,  1290,   748,
   -1476, -1476, -1476,  1277, -1476,  9228,   870, -1476, -1476, -1476,
   18184,    20, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, 12248,  1170, 18184,  1359,  8020,   731,
   -1476, -1476,   732, 12248, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476,  1362, -1476, -1476,  1184,  1174, 18184, -1476, -1476, 12248,
    9228, 18184,  1175, 12248,  1176,  1298, 14664, -1476, 14664,  9228,
   -1476,  1288,  1185, 18184,  1262,  1370, 18184,  1182, 14664, -1476
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   170,   170,   170,     0,   822,  1017,   122,   124,   620,
     914,   923,   863,   827,   825,   807,   915,   918,   870,   831,
     808,   810,   260,   924,   811,   921,   892,   872,   847,   809,
     867,   868,   919,   916,   866,   813,   922,   814,   815,   959,
     971,   958,   864,   883,   877,   816,   865,   818,   817,   960,
     901,   902,   869,   844,   981,   982,   983,   984,   985,   986,
     987,   988,   989,   990,   991,  1005,  1012,   891,   887,   878,
     858,   806,   886,   894,   903,  1006,   882,   475,   859,   860,
     917,  1007,  1013,   879,   896,     0,   483,   477,   889,   824,
     880,   881,   910,   884,   900,   909,  1011,  1014,   830,   871,
     912,   476,   899,   905,   170,     0,     0,     0,   408,   897,
     908,   913,   911,   890,   876,   961,   874,   875,  1008,     0,
     407,     0,  1009,  1015,   906,   861,   885,  1010,   213,   907,
     888,   895,   904,   898,   962,   852,   857,   856,   855,   854,
     853,   819,   873,     0,   823,     0,   920,   845,   474,   478,
     479,   952,   951,   953,   829,   828,   848,     0,   812,     0,
     955,     0,     0,   851,   893,   950,   957,   956,   949,   849,
     954,   966,   967,   964,   965,   963,   820,   968,   969,   970,
     940,   939,   926,   843,   836,   933,   929,   846,   842,   941,
     261,   832,   833,   826,   835,   938,   937,   934,   930,   947,
     948,   946,   936,   932,   925,   834,   945,   944,   838,   840,
     839,   931,   935,   927,   841,   928,   837,   943,   992,   993,
     994,   995,   996,   997,   973,   974,   972,   978,   979,   980,
     975,   976,   977,   850,   998,   999,  1000,  1001,  1002,  1003,
    1004,     0,     0,     0,  1016,   167,   167,     0,     2,   167,
       9,    11,    25,     0,    30,    33,    38,    39,    40,    41,
      42,    43,    44,    34,    60,    61,    35,    36,     0,    78,
      81,    82,    37,    83,    84,     0,   120,    85,    86,    87,
      88,    20,   164,   165,   166,   173,   176,   466,   177,     0,
     178,   179,   180,   181,   182,   183,   184,   187,   188,     0,
     214,   222,   217,   249,   255,     0,   247,     0,   248,   224,
     218,   186,   219,   185,   220,   223,   357,   359,   361,   363,
     373,   375,   379,   381,   384,   389,   392,   395,   397,   399,
     401,     0,   405,   412,   411,   413,     0,   431,   414,   436,
     437,   438,   445,   457,   471,   473,   458,   459,   460,   463,
     464,   461,   465,   492,   493,   462,   496,   498,   499,   500,
     497,   545,   546,   547,   548,   549,   550,   551,   472,    45,
     225,   226,   228,   227,   229,   221,   468,   469,   470,   467,
     231,   234,   230,   232,   233,     0,   805,   821,   914,   923,
     921,   823,     0,   168,   169,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,   130,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   279,   280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     194,   807,   831,   810,   862,   924,   811,   872,   813,   883,
     816,   818,   817,   901,   806,   860,   884,   908,   961,   962,
     849,   966,   967,   964,   820,   968,   942,   833,   480,   805,
       0,   803,     0,     0,   214,     0,     0,   804,   811,   818,
     817,     0,   170,   768,   968,     0,   222,     0,   481,     0,
     512,     0,     0,     0,   804,   434,   435,     0,     0,     0,
     541,     0,     0,   812,   955,     0,   788,   812,   955,     0,
       0,     0,   812,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,   770,     0,   772,     0,
       0,     0,   167,     3,     4,     1,    10,    12,     0,     0,
       0,     0,     6,   167,     0,   167,     0,     0,   121,   174,
       0,     0,   192,     0,     0,   201,     0,   260,     0,     0,
       0,     0,     0,     0,   261,   206,   235,   254,   250,   256,
     251,   253,   252,     0,   259,     0,     0,     0,     0,     0,
       0,     0,   424,     0,     0,   422,     0,   368,     0,   423,
     416,   421,   420,   419,   418,   417,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   410,   409,   406,     0,     0,
     432,     0,     0,     0,   446,   454,     0,     0,   553,   555,
     559,   561,     0,   126,     0,   802,    49,    46,    47,    50,
      51,     0,     0,     0,     0,    52,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   627,   628,   629,
       0,   105,   144,     0,     0,   114,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,   136,     0,   140,   170,
     495,     0,    62,     0,    71,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,   328,     0,     0,     0,     0,
       0,   618,     0,     0,     0,     0,   196,     0,     0,   190,
     189,     0,     0,   774,     0,     0,     0,     0,   480,     0,
     769,     0,   482,   513,   512,   509,     0,     0,     0,   543,
     542,   433,     0,   540,     0,     0,   640,   641,   787,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   646,     0,   204,   205,     0,     0,     0,     0,
       0,   209,   210,   771,   773,     0,     0,     5,    26,     0,
      27,     0,     7,    31,     0,    17,     8,    32,     0,    21,
     914,    79,    18,    80,    22,   195,     0,   193,   215,   216,
       0,     0,     0,     0,   207,   236,   297,   258,   262,     0,
     237,   238,   257,     0,     0,   358,   360,   366,   372,   371,
     370,     0,   367,   364,   365,     0,   376,   383,   382,   380,
     386,   387,   388,   385,   390,   391,   394,   393,     0,     0,
       0,     0,   415,   429,     0,   453,   451,   450,   452,   449,
       0,   488,   447,   490,     0,   455,   494,   486,     0,     0,
     123,   125,     0,     0,     0,   104,     0,    94,    96,    97,
      98,    99,   101,   102,   103,    95,   100,    90,    91,     0,
       0,   110,     0,   106,   108,   109,   116,     0,     0,    89,
      48,     0,     0,     0,     0,     0,     0,     0,   718,   723,
       0,     0,   719,   753,   706,   708,   709,   710,   712,   714,
     713,   711,   715,     0,     0,     0,     0,     0,   113,     0,
     146,     0,     0,   558,   552,     0,   142,     0,     0,   137,
       0,     0,     0,     0,     0,     0,    64,     0,     0,     0,
       0,   278,   284,   281,     0,     0,     0,     0,     0,   557,
       0,     0,     0,   425,     0,     0,     0,     0,   197,     0,
       0,   776,     0,     0,   775,     0,     0,     0,   512,   510,
       0,   501,     0,     0,   484,   485,     0,    13,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     782,   783,     0,     0,   790,     0,   812,     0,     0,     0,
       0,     0,   202,     0,     0,     0,   442,   443,   444,   441,
     654,   440,     0,   439,   211,     0,   786,     0,     0,     0,
     167,     0,   167,     0,   175,   246,     0,   312,   308,   310,
       0,   298,   299,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   240,     0,   245,   369,     0,     0,     0,
       0,   684,   377,   657,   661,   663,   665,   667,   670,   677,
     678,   686,   807,   808,   810,   924,   809,   813,   814,   815,
     816,   806,   574,     0,   819,   812,   799,   801,   797,   576,
     396,   564,   571,   572,   593,   584,   592,   591,   590,   589,
     586,   588,   585,   587,   577,   621,   622,   578,   579,   793,
     794,   795,   582,   398,   400,   403,   583,   402,   430,   456,
       0,   448,   487,   127,    58,    59,    56,    57,   133,   132,
       0,    92,     0,     0,     0,   111,   112,   117,    76,    77,
      54,    55,    75,   724,     0,   727,   754,     0,   717,   716,
     721,   720,   752,     0,     0,   729,     0,   725,   728,   707,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,   148,   150,     0,     0,     0,   115,   118,     0,     0,
       0,   170,   143,   138,   141,     0,   191,     0,     0,    73,
      67,    70,    69,     0,    65,   563,   282,     0,     0,   170,
       0,   326,   330,     0,     0,     0,   333,     0,     0,   339,
       0,     0,   346,     0,   350,     0,   427,   426,   170,   198,
       0,   200,   327,     0,     0,     0,     0,     0,   513,     0,
     503,     0,   536,   533,     0,   537,   538,     0,     0,   532,
       0,   507,   535,   534,     0,     0,     0,     0,     0,   633,
     634,   630,     0,     0,   638,   639,   635,   779,   780,     0,
     644,   789,   642,     0,     0,     0,     0,     0,   648,   811,
     818,   817,   968,   203,     0,     0,     0,   649,   650,     0,
       0,   212,   785,    28,     0,    19,    23,    24,   309,   321,
       0,   322,     0,   313,   314,   315,   316,     0,   301,     0,
       0,   264,     0,     0,   265,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   241,     0,     0,     0,     0,   291,
       0,   288,   293,   244,     0,     0,   668,   681,     0,   374,
     378,     0,   700,     0,     0,     0,     0,     0,     0,   656,
     658,   659,   695,   696,   697,   699,   698,     0,     0,   672,
     671,     0,   675,   679,   693,   691,   690,   683,   687,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     567,     0,     0,     0,     0,     0,     0,     0,   568,   570,
     569,   565,   404,   489,   491,   135,   134,    93,   107,   741,
     722,     0,   746,     0,   746,   735,   730,   149,   151,     0,
       0,     0,   119,   147,     0,    29,     0,   139,     0,     0,
      72,     0,    66,   283,     0,     0,   329,   331,   336,     0,
     334,     0,     0,     0,     0,     0,   340,     0,     0,   354,
       0,     0,   347,     0,     0,   351,   428,     0,   199,   777,
     778,     0,     0,   512,     0,     0,   544,     0,   512,     0,
     508,     0,    14,    16,     0,     0,     0,     0,     0,     0,
       0,   792,     0,   647,     0,     0,     0,     0,     0,     0,
     651,   655,   325,   323,   324,   317,   318,   319,   311,     0,
       0,   306,     0,   300,   263,     0,     0,   277,   269,     0,
     273,     0,   267,     0,     0,     0,   286,     0,     0,     0,
     243,   289,   292,     0,   685,   676,   682,     0,     0,   755,
     756,   766,   765,   764,     0,     0,     0,     0,   757,   662,
     763,     0,   660,   664,     0,     0,   669,   673,     0,   694,
     689,   692,   688,   600,   595,     0,     0,   610,     0,     0,
       0,     0,   580,     0,   598,     0,   601,     0,     0,     0,
     599,   604,     0,     0,   573,   626,   566,   594,   798,   800,
     796,   575,   742,     0,     0,   740,   747,   748,   744,     0,
     739,     0,   737,     0,     0,     0,     0,     0,     0,   554,
       0,     0,     0,    68,   285,   560,     0,     0,   337,   341,
     335,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   556,     0,     0,   512,     0,   539,     0,
     512,   562,   631,   632,   636,   637,     0,   784,   643,   791,
     645,     0,     0,     0,     0,   652,   320,   307,   302,     0,
     266,     0,   275,     0,     0,   271,     0,   274,   287,   295,
     296,   290,   242,   680,   767,     0,     0,   759,     0,   705,
     704,   703,   702,   701,   666,     0,   758,   596,   597,     0,
     614,     0,   611,     0,   623,     0,     0,   603,   602,   609,
     617,     0,   607,     0,   605,   751,   750,   749,     0,   743,
     736,   734,     0,   731,   732,   726,   152,   154,   156,     0,
       0,     0,     0,     0,   208,   356,    74,   332,   338,     0,
     352,   348,   355,     0,     0,     0,   342,     0,     0,   344,
       0,   522,   516,   511,     0,   512,   502,     0,   781,     0,
       0,     0,     0,   305,   303,   270,   268,     0,   276,     0,
     761,   760,     0,     0,     0,     0,   618,     0,     0,   624,
     581,     0,     0,     0,   745,   738,     0,     0,   158,   157,
       0,     0,     0,     0,   153,     0,     0,     0,     0,     0,
     530,   524,     0,   523,   525,   531,   528,   518,     0,   517,
     519,   529,   504,     0,   505,     0,     0,   653,   304,   272,
       0,   762,   674,   615,   616,   619,   612,   613,   625,   608,
     606,   733,   155,   159,     0,     0,     0,     0,     0,     0,
     345,   343,     0,     0,   515,   526,   527,   514,   520,   521,
     506,     0,   294,   160,     0,     0,     0,   353,   349,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,     0,
     161,     0,     0,     0,     0,     0,     0,     0,     0,   163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1476, -1476,  -198,  -177, -1476,  1247,  1249, -1476,  1250,  -466,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
    -910, -1476, -1476, -1476, -1476,  -211,  -506, -1476,   828,   110,
   -1476, -1476, -1476, -1476, -1476,   368,   616, -1476, -1476,     9,
     -69,  1108, -1476,  1075, -1476, -1476,  -589, -1476,   572, -1476,
     333, -1476,  -180,  -233, -1476,  -476, -1476,    13,    27,    36,
    -248,  -160, -1476,  -793, -1476, -1476,   299, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476,   734, -1476,   -93,
    1355,     0, -1476, -1476, -1476, -1476,   461, -1476, -1476,  -287,
   -1476,     5, -1476, -1476,   922,  -976,  -783,  -751, -1476, -1476,
     805, -1476, -1476,    21,   202, -1476, -1476, -1476,   224, -1475,
   -1476,   490,   228, -1476, -1476,   234, -1222, -1476,  1040,   332,
   -1476, -1476,   324,  -930, -1476, -1476,   326, -1476, -1476, -1182,
   -1147, -1476,   322, -1364, -1476, -1476,   937,  -141, -1476, -1476,
    -483,   924, -1476, -1476,  -601,   402,  -568,   406,   421, -1476,
   -1476, -1476,   694, -1476, -1476,  1206, -1476, -1476, -1476, -1476,
   -1476,  -729,  -304,  -585, -1476, -1476,   259, -1476,  -136, -1476,
     905, -1476,  -377, -1476, -1476,   907,   910, -1476, -1476, -1476,
   -1476,   906, -1476, -1476, -1476, -1476,  -912, -1476,   315, -1476,
     808,  -701, -1476, -1476, -1476, -1476, -1476,  -215,  -208, -1139,
    -874, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476,  -682,  -773,  -116,  -795, -1476, -1476, -1476,  -842,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,   196,   197,
    -688,   -98,  -579, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476, -1476, -1476, -1476,   298, -1476, -1476,   289, -1476,   294,
   -1006, -1476, -1476, -1476,   229,   220,    45,   509, -1476, -1476,
   -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476, -1476,
   -1476,   231, -1476, -1476, -1476,    52,   507,   654, -1476, -1476,
   -1476, -1476, -1476,   418, -1476, -1476, -1471, -1476, -1476, -1476,
    -502, -1476,   184, -1476,    16, -1476, -1476, -1476, -1476, -1252,
   -1476,   246, -1476, -1476, -1476, -1476, -1476,  -106, -1476, -1476,
   -1476, -1476, -1476,  -832, -1476, -1476, -1476,  -357,  -109,   176,
     710, -1476
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   247,   564,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
    1179,   697,   265,   266,   267,   268,   269,   270,   877,   878,
     879,   271,   272,   273,   883,   884,   885,   274,   419,   275,
     276,   642,   277,   421,   422,   423,   429,   687,   688,   278,
    1160,   279,  1676,  1677,   280,   281,   282,   482,   283,   284,
     285,   286,   287,   690,   288,   289,   450,   290,   291,   292,
     293,   294,   295,   575,   296,   297,   771,   772,   298,   299,
     300,   496,   302,   576,   588,  1044,  1045,   303,   577,   304,
     579,   497,   306,   307,   807,   808,  1309,   436,   308,   437,
     438,   814,  1310,  1311,  1312,   580,   581,  1031,  1032,  1471,
     582,  1028,  1029,  1283,  1284,  1285,  1286,   309,   704,   705,
     310,  1195,  1196,  1411,   311,  1198,  1199,   312,   313,  1201,
    1202,  1203,  1204,  1418,   314,   315,   316,   317,   318,   821,
     319,   320,  1319,   321,   322,   323,   324,   325,   326,   327,
     328,   329,  1104,   330,   331,   332,   333,   606,   607,   334,
     335,   336,   337,   338,   339,   340,  1010,  1011,   341,   634,
     635,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   854,   352,   353,   354,   355,   356,   357,  1230,   734,
     735,   736,  1703,  1758,  1759,  1752,  1753,  1760,  1754,  1231,
    1232,   358,   359,  1233,   360,   361,   362,   363,   364,   365,
     366,   367,   940,  1419,  1371,  1081,  1533,  1082,  1105,  1083,
    1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
     710,  1725,   368,  1094,  1095,  1096,  1097,   369,   370,   371,
     372,   373,   374,   761,   762,   375,  1267,  1268,  1615,  1012,
    1052,  1329,  1330,  1053,  1054,  1055,  1056,  1057,  1339,  1516,
    1517,  1058,  1342,  1059,  1497,  1060,  1061,  1347,  1348,  1522,
    1520,  1331,  1332,  1333,  1334,  1642,   671,   904,   905,   906,
     907,   908,   909,  1147,  1564,  1673,  1148,  1562,  1671,   910,
    1384,  1559,  1555,  1556,  1557,   911,   912,  1335,  1343,  1507,
    1336,  1503,  1320,   376,   377,   378,   379,   485,   380,   381,
     382,   383,   384,  1098,  1099,  1100,  1101,  1180,   486,   385,
     386,   387
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -943;
  const short int
  jsoniq_parser::yytable_[] =
  {
       301,   301,   301,   301,   301,   305,   305,   305,   305,   305,
     503,   829,   495,   499,   392,   395,   396,   534,   578,   420,
    1197,   516,   643,   643,   948,   524,  1037,  1184,   393,   393,
     393,   397,   630,   970,   958,  1432,   559,   394,   394,   394,
     398,   551,  1315,   842,   646,   830,   831,   832,   833,   791,
     793,   535,   848,   521,  1422,   554,  1587,  1291,  1038,  1591,
    1229,   552,  1466,  1467,   864,  1080,  1103,   552,   543,   544,
     556,  1119,  1161,     7,     8,   694,   698,   785,   789,   792,
     794,  1298,  1162,  1679,  1504,  1124,   566,   783,   787,  1518,
     567,  1440,  1674,   552,   405,   568,  1050,  1041,     7,     8,
     552,   552,  1034,   552,   301,   509,  1187,   552,   817,   305,
     818,   819,  1150,   820,   569,   822,   631,  1151,  1152,   405,
     552,   552,   408,   823,   824,   552,  1153,  1039,   722,   406,
     552,   393,   552,  1154,   552,  1155,  1156,  1701,     9,   645,
     483,   945,  1035,  1713,  1157,   552,   559,   408,   537,   539,
     559,   632,   409,   633,  1173,  -171,   552,   552,  1588,  1144,
     677,   938,   976,  1035,   561,  1185,   978,   645,  1499,   563,
     610,  1158,  1305,  1269,   552,   563,  1145,  1306,   401,   402,
     610,   403,   404,   629,   410,   411,  1023,   548,   611,  1188,
     893,   560,   894,  1299,  1680,   431,  1321,  1280,   611,   407,
     739,   563,   434,   549,  1127,   432,   558,   121,  1500,   647,
     578,   612,   675,   570,  1036,  1035,   571,   676,  1282,  1146,
      77,   977,   946,   648,   552,   979,  1589,  1702,   563,   563,
    1270,   572,   433,  1295,    87,   559,   895,   552,  1254,  1768,
     563,   435,   563,  1616,  1172,   301,   301,   562,  1505,   301,
     305,   305,   695,   563,   305,  1274,  1300,   573,   754,   101,
    1042,   478,   552,  1047,   563,  1781,  1048,  1219,  1415,  1322,
     552,   693,     9,  1402,   791,   793,  1681,  1120,  1361,  1504,
     487,   732,   563,   500,   301,  1422,  1296,   121,  1301,   305,
     510,   553,   555,   552,   778,   504,  1440,   507,   780,   696,
    1043,   560,   413,  1159,   666,   560,   574,   890,   931,  1229,
    1672,  1496,   783,   787,  1474,   681,  1020,   925,  1229,  1050,
    1050,  1022,   950,   435,   804,  1745,  1161,  1376,  1361,   148,
     149,   150,   563,   951,   684,   487,  1162,   691,  1046,   678,
     936,  -171,   784,   788,   435,   563,   703,   679,  1273,   708,
     709,   558,   779,   781,    77,   715,  1323,  1324,  1303,  1325,
     730,   435,   796,   435,   416,   777,   414,   552,    87,   740,
     563,   610,   417,  1049,   722,  1483,  1327,   773,   563,   748,
     418,   552,  1789,   552,  1792,   774,   552,   756,  1328,   611,
     560,   896,  1412,   101,   301,  1076,  1077,  1078,   301,   305,
     859,   563,  1397,   305,   897,   721,   898,   415,   737,   738,
     552,   721,  1003,   752,  1412,   742,   552,   899,   900,   901,
    1635,   902,   944,   903,   552,   301,   301,   945,  1700,   399,
     305,   305,  -172,   552,  1553,   971,  1035,   655,   999,   767,
     769,   301,   552,  1505,  1506,   301,   305,   956,  1051,   816,
     305,   400,   682,   683,   552,     9,  1738,   722,  1215,  1035,
     859,   398,   398,   148,   149,   150,   881,   552,   707,  1501,
     656,   882,   712,  1130,  1131,   563,  1502,   398,  1413,  1109,
     860,   398,  1113,   301,   928,  1392,  1639,  1475,   305,   563,
    1321,   563,   301,  1640,   563,  1152,  1589,   305,  1636,  1554,
    1577,   552,   972,  1641,   989,   435,   552,   552,   960,  1476,
    1623,  1222,  1223,  1156,   791,   793,   791,  1783,   563,   393,
     559,   753,   849,  1229,   563,  1110,   980,   988,   394,  1766,
    1128,  1129,   563,   301,   723,  1132,   844,    77,   305,   850,
     861,   563,   301,  1377,  1275,  1276,  1277,   305,  1024,  1484,
     563,    87,   973,   301,   301,   301,   301,   420,   305,   305,
     305,   305,   563,  1322,   929,  1170,   974,  1017,   984,   768,
    1000,  1216,   301,   424,  1217,   563,   101,   305,  1389,  1532,
    1047,  1381,   654,  1048,   932,   658,  1021,   935,  1050,   504,
     781,  1412,   672,   673,   566,   975,   428,  1050,   567,   425,
     504,  1005,   444,   568,   121,  1111,  1472,  1224,  1050,   563,
     699,   938,  1709,   963,   563,   563,   706,   566,  -172,  1422,
     711,   567,   569,   997,   685,   716,   568,  1225,  1110,  1226,
    1710,  1614,   965,   966,   967,  1649,   769,   938,  1524,   525,
    1651,  1383,  1711,  1220,   526,   569,   148,   149,   150,  1655,
    1323,  1324,  1108,  1325,   981,   982,   706,  1227,  1222,  1223,
    1326,   107,  1686,  1661,   947,  1222,  1223,   728,   487,   983,
    1327,  1051,  1051,  1663,   661,  1004,   662,  1582,   119,   445,
    1750,   430,  1328,  1750,  1222,   938,  1494,  1222,  1270,   301,
    1302,  1767,  1772,   686,   305,   487,   985,   986,  1624,  1228,
       7,     8,   930,   583,   763,   584,  1668,   426,  1112,   663,
    1221,   987,   649,   301,   301,  1650,   393,   143,   305,   305,
    1652,   570,  1222,   631,   571,   394,   650,  1511,   527,  1656,
     427,   757,  1595,   939,   938,  1194,   664,  1599,   439,   731,
     954,   955,  1756,  1662,   570,   786,   630,   571,  1409,   398,
     398,   446,   447,  1664,  1224,  1263,   631,  1222,   632,   809,
     633,  1224,  1458,   809,   661,   573,   662,   791,   301,   441,
     585,  1222,  1223,   305,  1225,   586,  1226,  1756,  1018,  1138,
    1415,  1225,   957,  1226,  1305,  1050,  1669,   557,   573,  1306,
    1139,   632,  1305,   633,   549,   479,   301,  1306,   665,   420,
    1225,   305,  1226,  1225,  1227,  1226,   796,   504,   107,  1568,
    1751,  1227,  1692,  1795,   574,   107,  1307,   479,   786,   781,
    1317,  1400,   587,  -862,   440,   119,   664,  1755,  1761,   479,
    1227,   479,   119,  1227,   993,  1035,   886,   574,  1225,  1584,
    1226,   613,  1368,   880,   121,  1452,  1434,  -862,  1381,  1757,
     916,  1019,  1271,  1439,   920,   921,   795,  1308,  -862,   631,
     797,   926,  1255,  1585,   143,  1382,   938,  1224,  1227,   504,
     614,   143,   504,  1225,  1369,  1226,   941,  -942,  1469,  1755,
    1729,  1118,  1730,   615,  1798,  1761,   881,  1225,   665,  1226,
     631,   882,  1370,   610,   632,  1704,   633,   689,   487,  1707,
    1694,  -942,   619,  1227,  1637,  1638,   448,  1698,  1383,   968,
     442,   611,  -942,  1788,  1470,  1279,   620,  1227,   616,  1809,
    1810,   107,  1114,  1462,  1585,   632,  1280,   633,  1639,  1398,
    1634,  1585,  1344,  1345,  1722,  1640,  1281,  1585,   119,  1115,
    1051,  1463,  1464,  1585,  1585,  1641,  1013,  1282,  1116,  1051,
    1144,  1194,   301,   651,  1314,  1346,   449,   305,  1778,  1597,
    1051,  1724,   443,  1727,  1414,  1117,  1375,  1145,  1420,   652,
    1423,  1420,  1420,  1732,   938,  1733,  1025,   143,   578,  1205,
    1678,  1421,   689,  1424,  1594,  1801,  1280,  1121,   398,  1040,
    1140,   617,   480,  1164,   501,  1237,  1739,  1238,   502,  1121,
     618,  1141,  1165,  1264,  1763,   667,   668,   669,  1265,  1242,
     508,  1243,   827,   828,  1102,  1102,  1106,  1106,     7,     8,
     301,   301,   301,   834,   835,   305,   305,   305,   420,   401,
     402,   511,   403,   404,  1720,  1721,  1133,  1134,  1135,   405,
     836,   837,  1136,   512,  1573,  1387,  1388,   528,   529,   406,
     407,  1665,  1666,   530,   532,   531,  1102,   867,   868,   869,
     870,   871,   872,   873,   874,   875,   876,   408,   533,   545,
    1137,   565,   409,   589,   590,   608,   621,   609,   622,   628,
     623,   636,   624,   637,   638,   639,   640,   641,   645,   657,
     659,   660,   670,   674,   689,  1167,   692,   701,  1678,   700,
     713,   702,   534,  1102,   410,   411,   412,   714,   717,   719,
     721,   724,  1617,   725,  1102,   653,   479,   726,   727,   479,
     729,  1771,   733,   479,   741,   743,   479,   479,   744,   745,
     759,   760,   764,   765,   479,   782,   770,  1051,   800,   801,
     802,   776,   803,   810,   479,   825,   811,   813,   838,   839,
     479,   840,  1678,   413,   479,   841,   632,   856,   862,   479,
     863,   865,   891,   887,   888,  1579,   892,   913,   914,   915,
     917,   301,   919,   922,   927,   923,   305,   301,   933,   924,
     934,   937,   305,   949,  1396,   952,   992,   995,   998,   301,
     479,   953,  1001,  1015,   305,  1002,  1019,  1030,   393,  1122,
    1026,   479,  1405,  1033,   882,   938,  1288,   394,   301,   809,
     804,  1142,  1143,   305,  1163,  1168,   393,   414,  1171,  1169,
     685,  1427,  1175,  1176,  1177,   394,  1178,   301,  1181,  1189,
    1182,  1820,   305,  1821,   301,   393,  1183,  1190,   479,   305,
    1193,  1194,  1200,  1829,   394,  1537,  1210,  1206,  1207,  1102,
    1213,  1214,  1208,  1218,  1437,  1235,   591,  1236,   415,  1211,
    1234,  1441,  1249,   398,   592,   593,  1256,   594,  1266,  1264,
     398,   663,  1287,  1292,  1265,   595,  1289,  1293,  1297,   596,
    1304,   597,  1338,  1337,   416,  1318,   598,  1341,  1349,     9,
    1379,  1350,   417,   479,  1351,  1352,  1380,   479,  1385,  1102,
     418,  1353,  1390,   599,  1394,   768,  1354,  1355,  1356,  1357,
    1358,  1359,  1362,  1363,  1364,  1372,  1365,  1366,  1367,  1391,
    1401,  1404,  1684,  1431,  1420,  1433,  1436,   600,   601,   602,
     603,   604,   605,  1688,  1579,  1448,  1690,  1395,  1455,  1442,
    1444,   479,  1445,  1446,  1699,  1447,  1456,  1426,  1269,  1280,
    1457,  1102,  1479,  1449,  1450,  1481,  1454,  1443,  1485,  1487,
    1488,  1493,  1611,  1612,  1613,  1489,   706,   866,  1495,  1498,
     479,  1508,  1514,  1515,  1519,  1521,  1102,  1552,  1523,  1558,
    1563,  1567,  1570,  1534,   479,  1540,  1544,  1545,   479,   479,
    1546,  1547,  1565,  1548,  1549,   479,  1550,  1551,  1561,  1569,
    1571,  1572,  1575,   479,  1438,  1619,   479,  1576,  1645,  1581,
     479,  1606,  1592,   301,  1593,  1598,  1601,  1633,   305,  1621,
    1653,  1646,  1626,  1647,  1648,  1654,  1670,  1657,  1658,  1144,
    1683,  1659,   763,  1660,  1682,  1675,  1689,  1469,  1717,  1719,
    1731,  1734,  1013,   479,  1735,  1736,  1013,  1706,  1737,  1742,
    1690,  1747,  1741,  1746,  1748,  1762,  1764,  1770,  1264,   484,
    1765,  1775,  1786,  1265,  1773,  1774,   809,  1776,  1777,  1477,
    1779,  1794,  1780,  1793,  1787,  1797,  1800,  1784,  1823,  1806,
     479,  1804,  1811,  1812,  1491,  1813,  1819,  1816,  1818,  1822,
    1826,   889,  1378,  1825,  1828,   680,   546,  1125,   547,  1790,
    1174,  1393,   550,  1744,  1782,  1014,  1313,   943,   644,   812,
     479,  1492,  1631,  1473,   520,  1468,  1278,  1398,  1465,  1410,
     718,  1712,  1406,   479,  1416,  1425,   815,  1529,  1102,  1461,
     504,  1538,  1539,   826,  1543,  1107,  1435,   627,   846,   855,
    1807,   847,   969,   858,  1799,  1796,  1525,  1526,   479,   479,
     479,   479,  1723,  1728,  1453,  1509,  1460,  1513,  1316,  1644,
    1459,  1512,  1807,  1643,  1386,  1340,  1566,  1149,  1560,     0,
    1264,  1790,  1667,  1510,     0,  1265,     0,     0,     0,     0,
       0,  1264,  1264,     0,   301,     0,  1265,  1265,     0,   305,
     479,     0,  1264,  1583,     0,     0,  1102,  1265,   541,  1102,
       0,     0,     0,     0,   479,     0,     0,     0,     0,     0,
    1596,     0,     0,     0,     0,  1600,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   479,
       0,     0,     0,     0,     0,     0,     0,   479,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1629,  1630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1264,     0,
       0,     0,     0,  1265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,   479,     0,     0,     0,   301,     0,     0,
       0,     0,   305,     0,     0,     0,     0,     0,     0,     0,
       0,  1102,  1693,     0,  1695,  1264,  1697,     0,     0,     0,
    1265,     0,     0,  1705,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   479,     0,     0,     0,     0,   301,     0,
       0,     0,     0,   305,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1264,     0,     0,     0,     0,  1265,     0,     0,     0,  1264,
       0,     0,     0,     0,  1265,  1726,     0,  1726,     0,  1102,
       0,  1102,     0,   479,     0,     0,     0,   711,     0,   711,
       0,     0,     0,     0,     0,     0,     0,   484,     0,     0,
       0,     0,     0,     0,     0,  1740,     0,     0,  1743,     0,
       0,     0,     0,     0,     0,  1102,     0,     0,   746,   747,
       0,     0,   749,   750,   751,     0,  1749,   755,     0,     0,
     758,     0,     0,     0,     0,   479,   766,     0,     0,     0,
       0,     0,     0,     0,     0,   775,     0,     0,     0,     0,
     479,     0,     0,     0,     0,     0,     0,  1102,     0,     0,
     479,     0,     0,     0,     0,     0,     0,  1785,   798,   799,
       0,     0,  1102,     0,  1102,     0,     0,   805,   806,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   479,     0,
       0,     0,     0,     0,     0,     0,  1802,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1805,     0,     0,     0,   479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,     0,     0,     0,
     479,     0,  1814,     0,     0,     0,     0,  1815,   853,     0,
       0,     0,   853,     0,     0,     0,     0,     0,     0,  1824,
     479,     0,  1827,   479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   918,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   942,     0,     0,     0,
       0,   479,   479,     0,   479,   479,   479,     0,   479,     0,
       0,     0,   959,     0,     0,     0,   961,   962,     0,   964,
       0,     0,     0,     0,     0,     0,   805,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,     0,     0,     0,     0,     0,   990,   991,
       0,     0,   994,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   479,     0,     0,
     479,  1016,     0,   479,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   479,     0,     0,     0,     0,   479,
       0,   799,     0,     0,     0,     0,     0,  1027,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   479,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1186,   479,   479,     0,   479,     0,
     479,  1191,  1192,     0,     0,     0,     0,   479,     0,     0,
       0,     0,  1209,     0,     0,  1212,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1239,  1240,  1241,     0,
    1244,  1245,  1246,  1247,  1248,     0,     0,  1250,  1251,     0,
    1252,  1253,     0,     0,     0,  1257,  1258,     0,     0,   479,
       0,   479,     0,   479,     0,   479,     0,     0,     0,     0,
    1272,   479,     0,   479,     0,     0,     0,     0,     0,     0,
       0,  1027,     0,     0,     0,     0,     0,     0,     0,   479,
       0,  1294,   479,     0,     0,     0,     0,     0,     0,   479,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,     0,     0,   479,     0,   479,     0,
       0,     0,     0,     0,     0,  1374,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,     0,     0,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1399,   479,     0,     0,   479,     0,     0,     0,
       0,     0,  1403,     0,     0,     0,     0,     0,  1407,  1408,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1428,     0,     0,  1429,  1430,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1451,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1027,     0,     0,     0,     0,     0,     0,     0,
    1478,     0,  1480,     0,  1482,     0,     0,  1486,     0,     0,
       0,     0,  1490,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1574,
       0,     0,     0,     0,     0,     0,     0,  1578,  1580,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1602,
    1603,  1604,  1605,     0,  1607,  1608,     0,  1609,     0,  1610,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1618,     0,     0,     0,     0,
    1620,     0,     0,     0,  1622,     0,     0,     0,  1625,     0,
    1627,     0,  1628,     0,     0,     0,     0,     0,  1632,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1685,     0,     0,     0,
       0,  1687,  1580,     0,     0,     0,     0,     0,     0,  1691,
       0,     0,     0,     0,  1696,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1708,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1714,     0,  1715,     0,  1716,     0,
       0,  1718,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1691,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1769,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1791,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -167,   786,     0,     0,     0,     0,     0,  1803,
       0,     0,     0,  1808,     0,     0,     0,     0,  1791,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,  1808,     0,    10,   389,  1817,    12,
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
     125,     0,   126,   127,   128,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,  -167,   786,   243,   244,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,   790,   389,     0,    12,    13,
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
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,   128,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   391,     0,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,     0,   191,   192,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   786,   242,
       0,     0,   243,   244,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   388,   389,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   390,    26,    27,
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
     123,   124,     0,     0,     0,   125,     0,   126,   127,   128,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   391,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,     0,   191,   192,   193,     0,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   786,   242,     0,     0,   243,   244,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   388,   389,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   488,   390,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   489,   490,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   465,    80,    81,
      82,    83,    84,   491,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
      93,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,     0,   492,   105,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     391,     0,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   471,   472,   473,
     174,   175,   474,   494,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,     0,   191,   192,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,   242,  1006,  1007,   243,   244,     0,     0,     0,     0,
       0,  1008,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     0,     0,     0,     0,   388,   389,     0,    12,    13,
      14,   451,    16,    17,    18,   452,    20,   453,   454,   455,
     456,   390,    26,   457,    28,    29,    30,     0,    31,    32,
      33,    34,   458,    36,    37,    38,    39,    40,    41,    42,
     459,     0,    44,   460,    46,   461,   462,    49,   463,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
     464,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   465,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   466,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   109,   467,     0,     0,     0,     0,   111,   112,
     113,   114,   468,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,     0,     0,     0,     0,  1009,     0,   129,
       0,   130,   131,   132,   133,   469,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   391,     0,
     146,   147,     0,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   158,     0,   160,     0,     0,   163,   164,   165,
     166,   167,   168,   470,   170,   471,   472,   473,   174,   175,
     474,   475,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   476,     0,   191,   477,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     0,     0,     0,
       0,     0,     0,   244,     1,     2,     3,     4,     5,     6,
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
       0,    98,    99,   100,   101,   102,   103,     0,   104,   105,
       0,   106,   107,   108,   109,   110,     0,     0,     0,     0,
     111,   112,   113,   114,   115,   116,   117,   118,     0,   119,
       0,   120,   121,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,   128,     0,     0,     0,     0,
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
       0,   242,     0,     0,   243,   244,     0,     0,     0,     0,
     245,   246,     1,     2,     3,     4,     5,     6,     7,     8,
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
      99,   100,   101,   102,   103,     0,   104,   105,     0,   106,
     107,   108,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,   115,   116,   117,   118,     0,   119,     0,   120,
     121,     0,     0,   122,   123,   124,     0,     0,     0,   125,
       0,   126,   127,   128,     0,     0,     0,     0,     0,   129,
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
       0,     0,   243,   244,     0,   481,     0,     0,     0,   542,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,   388,   389,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   390,
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
     101,   102,   103,     0,   104,   105,     0,   106,   107,   108,
     109,   110,     0,     0,     0,     0,   111,   112,   113,   114,
     115,   116,   117,   118,     0,   119,     0,   120,   121,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,   128,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   391,     0,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,     0,   191,   192,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,   242,   481,     0,
     243,   244,     0,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   488,   390,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   489,   490,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   491,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   492,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   517,   159,   518,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   471,   472,   473,   174,
     175,   474,   494,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,   481,   519,   243,   244,     0,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   388,
     389,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   488,   390,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   489,
     490,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   465,
      80,    81,    82,    83,    84,   491,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,     0,
     492,   105,     0,   106,   107,   108,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   115,   116,   117,   118,
       0,   119,     0,   120,   121,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   391,     0,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   471,
     472,   473,   174,   175,   474,   494,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,     0,
     191,   192,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   481,   242,     0,     0,   243,   244,     0,     0,
       0,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,   451,    16,    17,    18,
     452,    20,   453,   454,   455,   456,   390,    26,   457,    28,
      29,    30,     0,    31,    32,    33,    34,   458,    36,    37,
      38,    39,    40,    41,    42,   459,     0,    44,   460,    46,
     461,   462,    49,   463,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,   464,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     465,    80,    81,    82,    83,    84,   491,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   466,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
       0,     0,     0,     0,   106,     0,     0,   109,   467,     0,
       0,     0,     0,   111,   112,   113,   114,   468,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,   845,     0,   129,     0,   130,   131,   132,   133,
     469,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   391,     0,   146,   147,     0,     0,     0,
     151,   152,   153,   154,   155,   156,     0,   158,     0,   160,
       0,     0,   163,   164,   165,   166,   167,   168,   470,   170,
     471,   472,   473,   174,   175,   474,   475,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   476,
       0,   191,   477,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   481,     0,     0,     0,     0,     0,   244,     0,
       0,     5,     6,     0,     0,     0,  1535,     0,     0,     0,
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
     124,     0,     0,     0,   125,  1536,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     469,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   391,     0,   146,   147,     0,     0,     0,
     151,   152,   153,   154,   155,   156,     0,   158,     0,   160,
       0,     0,   163,   164,   165,   166,   167,   168,   470,   170,
     471,   472,   473,   174,   175,   474,   475,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   476,
       0,   191,   477,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   481,     0,     0,     0,     0,     0,   244,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     0,
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
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     469,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,     0,     0,   391,     0,   146,   147,     0,     0,     0,
     151,   152,   153,   154,   155,   156,     0,   158,     0,   160,
       0,     0,   163,   164,   165,   166,   167,   168,   470,   170,
     471,   472,   473,   174,   175,   474,   475,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   476,
       0,   191,   477,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   505,   506,     0,     0,     0,     0,   244,     5,
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
       0,     0,   129,     0,   130,   131,   132,   133,   469,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   391,     0,   146,   147,     0,     0,     0,   151,   152,
     153,   154,   155,   156,     0,   158,     0,   160,     0,     0,
     163,   164,   165,   166,   167,   168,   470,   170,   471,   472,
     473,   174,   175,   474,   475,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   476,     0,   191,
     477,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       0,     0,     0,     0,     0,     0,   244,     1,     2,     3,
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
     124,     0,     0,     0,   125,     0,   126,   127,   128,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     0,     0,   243,   244,     1,
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
     122,   123,   124,     0,   720,     0,   125,     0,   126,   127,
     128,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   391,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,   242,     0,     0,   243,
     244,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
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
     126,   127,   128,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,     0,
       0,   243,   244,     1,     2,     3,     4,     5,     6,     7,
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
     125,     0,   126,   127,   128,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,     0,     0,   243,   244,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,    10,   389,
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
       0,     0,   125,     0,   126,   127,   128,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   391,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,     0,   243,   244,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     790,   389,     0,    12,    13,    14,    15,    16,    17,    18,
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
     124,     0,     0,     0,   125,     0,   126,   127,   128,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   391,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     0,     0,   243,   244,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,  1259,   390,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,  1260,  1261,    49,    50,    51,    52,    53,    54,
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
     128,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   391,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,  1262,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,   242,     0,     0,   243,
     244,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   488,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   489,   490,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     491,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,   851,     0,    98,    99,
     100,   101,   102,   103,     0,   492,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,   852,
     126,   127,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   471,   472,   473,   174,   175,   474,
     494,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,     0,
       0,   243,   244,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   488,   390,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   489,   490,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   491,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,   851,     0,
      98,    99,   100,   101,   102,   103,     0,   492,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,   857,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   471,   472,   473,   174,
     175,   474,   494,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,     0,     0,   243,   244,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   488,   390,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   489,   490,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   491,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   492,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,   493,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   391,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   471,   472,
     473,   174,   175,   474,   494,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,     0,   243,   244,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   488,   390,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     489,   490,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     465,    80,    81,    82,    83,    84,   491,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   492,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,   498,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   391,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     471,   472,   473,   174,   175,   474,   494,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     0,     0,   243,   244,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   488,   390,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   489,   490,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   465,    80,    81,    82,    83,    84,   491,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   492,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   391,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   471,   472,   473,   174,   175,   474,   494,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   536,   242,     0,     0,   243,
     244,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   488,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   489,   490,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     491,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   492,   105,     0,   106,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   471,   472,   473,   174,   175,   474,
     494,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,   538,
       0,   243,   244,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   488,   390,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   489,   490,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   491,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   492,   105,     0,
     106,   107,   108,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     120,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   471,   472,   473,   174,
     175,   474,   494,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,     0,   191,   192,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,     0,   540,   243,   244,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   488,   390,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   489,   490,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   491,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   492,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
     843,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   391,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   471,   472,
     473,   174,   175,   474,   494,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,     0,   243,   244,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   488,   390,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     489,   490,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     465,    80,    81,    82,    83,    84,   491,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,  1373,     0,    98,    99,   100,   101,   102,   103,
       0,   492,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   391,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     471,   472,   473,   174,   175,   474,   494,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
       0,   191,   192,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     0,     0,   243,   244,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   488,   390,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   489,   490,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   465,    80,    81,    82,    83,    84,   491,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   492,   105,     0,   106,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   391,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   471,   472,   473,   174,   175,   474,   494,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,   242,     0,     0,   243,
     244,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   488,
     390,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   489,   490,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     491,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   492,   105,     0,     0,   107,
     108,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,   120,   121,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   471,   472,   473,   174,   175,   474,
     494,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,     0,   191,   192,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,     0,
       0,   243,   244,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   454,
      23,   456,   390,    26,   457,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   459,     0,    44,    45,    46,   461,   462,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   491,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   492,   105,     0,
     106,   107,   625,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
     626,   121,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,     0,   158,     0,   160,     0,     0,   163,   164,
     165,   166,   167,   168,   470,   170,   471,   472,   473,   174,
     175,   474,   475,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   476,     0,   191,   477,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,     0,     0,     0,   244,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   454,    23,   456,   390,    26,   457,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   459,     0,    44,    45,    46,   461,   462,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   491,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   492,
     105,     0,   106,   107,   108,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,   120,   121,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   391,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   158,     0,   160,     0,     0,
     163,   164,   165,   166,   167,   168,   470,   170,   471,   472,
     473,   174,   175,   474,   475,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   476,     0,   191,
     192,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,     0,     0,   244,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   454,    23,   456,   390,    26,   457,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   459,     0,    44,    45,    46,
     461,   462,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     465,    80,    81,    82,    83,    84,   491,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   466,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   492,   105,     0,   106,   107,   108,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,   120,   121,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   391,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,   158,     0,   160,
       0,     0,   163,   164,   165,   166,   167,   168,   470,   170,
     471,   472,   473,   174,   175,   474,   475,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   476,
       0,   191,   477,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     0,     0,     0,   244,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   388,   389,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   454,    23,   456,   390,    26,
     457,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   459,     0,    44,
      45,    46,   461,   462,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   465,    80,    81,    82,    83,    84,   491,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   466,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,   492,   105,     0,     0,   107,   108,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,   115,
     116,   117,   118,     0,   119,     0,   120,   121,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   391,     0,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,     0,   158,
       0,   160,     0,     0,   163,   164,   165,   166,   167,   168,
     470,   170,   471,   472,   473,   174,   175,   474,   475,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   476,     0,   191,   192,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,   242,     0,     0,     0,
     244,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   388,   389,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   454,    23,   456,
     390,    26,   457,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   459,
       0,    44,    45,    46,   461,   462,    49,   463,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   465,    80,    81,    82,    83,    84,
     491,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   466,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,     0,   492,   105,     0,   106,   107,
       0,   109,   110,     0,     0,     0,     0,   111,   112,   113,
     114,   115,   116,   117,   118,     0,   119,     0,     0,     0,
       0,     0,   122,   123,   124,     0,     0,     0,   125,     0,
     126,   127,     0,     0,     0,     0,     0,     0,   129,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,   143,     0,   391,     0,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
       0,   513,     0,   514,     0,     0,   163,   164,   165,   166,
     167,   168,   470,   170,   471,   472,   473,   174,   175,   474,
     475,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   476,     0,   191,   477,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,   242,     0,
     515,     0,   244,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   388,   389,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   454,
      23,   456,   390,    26,   457,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,   459,     0,    44,    45,    46,   461,   462,    49,   463,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   465,    80,    81,    82,
      83,    84,   491,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,     0,   492,   105,     0,
     106,   107,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,   115,   116,   117,   118,     0,   119,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,   143,     0,   391,
       0,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,     0,   522,     0,   160,     0,     0,   163,   164,
     165,   166,   167,   168,   470,   170,   471,   472,   473,   174,
     175,   474,   475,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   476,     0,   191,   477,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
     242,     0,   523,     0,   244,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   388,   389,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   454,    23,   456,   390,    26,   457,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   459,     0,    44,    45,    46,   461,   462,
      49,   463,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   465,    80,
      81,    82,    83,    84,   491,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   466,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,     0,   492,
     105,     0,   106,   107,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,   115,   116,   117,   118,     0,
     119,     0,     0,     0,     0,     0,   122,   123,   124,     0,
       0,     0,   125,     0,   126,   127,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,   143,
       0,   391,     0,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,     0,   158,     0,   160,     0,     0,
     163,   164,   165,   166,   167,   168,   470,   170,   471,   472,
     473,   174,   175,   474,   475,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   476,     0,   191,
     477,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,   242,     0,     0,     0,   244,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     388,   389,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   454,    23,   456,   390,    26,   457,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   459,     0,    44,    45,    46,
     461,   462,    49,   463,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     465,    80,    81,    82,    83,    84,   491,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   466,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
       0,   492,   105,     0,   106,   107,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,   115,   116,   117,
     118,     0,   119,     0,     0,     0,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,     0,     0,   141,
     142,   143,     0,   391,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,     0,   996,     0,   160,
       0,     0,   163,   164,   165,   166,   167,   168,   470,   170,
     471,   472,   473,   174,   175,   474,   475,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   476,
       0,   191,   477,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,   242,     5,     6,     0,   244,     0,
       0,     0,     0,     0,   388,   389,     0,    12,    13,    14,
    1062,    16,    17,    18,   452,  1063,  1064,   454,  1065,   456,
     390,    26,   457,    28,  1066,    30,     0,    31,    32,    33,
      34,  1067,    36,  1068,  1069,    39,    40,    41,    42,   459,
       0,    44,  1070,    46,   461,   462,    49,   463,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,  1071,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   465,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   466,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,  1072,     0,     0,     0,  1073,     0,
       0,   109,   467,     0,     0,     0,     0,   111,   112,   113,
     114,   468,   116,   117,   118,     0,     0,     0,     0,     0,
       0,     0,   122,   123,   124,     0,     0,     0,   125,  1530,
     126,   127,     0,     0,     0,     0,  1531,     0,   129,     0,
     130,   131,   132,   133,   469,   135,   136,   137,   138,   139,
     140,     0,     0,  1074,   142,     0,     0,   391,     0,   146,
     147,     0,     0,     0,   151,   152,   153,   154,   155,   156,
       0,  1075,     0,   160,     0,     0,   163,   164,   165,   166,
     167,   168,   470,   170,   471,   472,   473,   174,   175,   474,
     475,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   476,     0,   191,   477,   193,     0,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,     0,     0,     5,     6,
       0,     0,   244,  1076,  1077,  1078,  1079,   388,   389,     0,
      12,    13,    14,  1062,    16,    17,    18,   452,  1063,  1064,
     454,  1065,   456,   390,    26,   457,    28,  1066,    30,     0,
      31,    32,    33,    34,  1067,    36,  1068,  1069,    39,    40,
      41,    42,   459,     0,    44,  1070,    46,   461,   462,    49,
     463,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,  1071,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   465,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     466,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,  1072,     0,     0,
       0,  1123,     0,     0,   109,   467,     0,     0,     0,     0,
     111,   112,   113,   114,   468,   116,   117,   118,     0,     0,
       0,     0,     0,     0,     0,   122,   123,   124,     0,     0,
       0,   125,  1360,   126,   127,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   469,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     391,     0,   146,   147,     0,     0,     0,   151,   152,   153,
     154,   155,   156,     0,  1075,     0,   160,     0,     0,   163,
     164,   165,   166,   167,   168,   470,   170,   471,   472,   473,
     174,   175,   474,   475,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   476,     0,   191,   477,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     0,
       0,     5,     6,     0,     0,   244,  1076,  1077,  1078,  1079,
     388,   389,     0,    12,    13,    14,  1062,    16,    17,    18,
     452,  1063,  1064,   454,  1065,   456,   390,    26,   457,    28,
    1066,    30,     0,    31,    32,    33,    34,  1067,    36,  1068,
    1069,    39,    40,    41,    42,   459,     0,    44,  1070,    46,
     461,   462,    49,   463,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,  1071,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     465,    80,    81,    82,    83,    84,  1417,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   466,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
    1072,     0,     0,     0,  1073,     0,     0,   109,   467,     0,
       0,     0,     0,   111,   112,   113,   114,   468,   116,   117,
     118,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     124,     0,     0,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     469,   135,   136,   137,   138,   139,   140,     0,     0,  1074,
     142,     0,     0,   391,     0,   146,   147,     0,     0,     0,
     151,   152,   153,   154,   155,   156,     0,  1075,     0,   160,
       0,     0,   163,   164,   165,   166,   167,   168,   470,   170,
     471,   472,   473,   174,   175,   474,   475,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   476,
       0,   191,   477,   193,     0,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,     0,     0,     5,     6,     0,     0,   244,  1076,
    1077,  1078,  1079,   388,   389,     0,    12,    13,    14,  1062,
      16,    17,    18,   452,  1063,  1064,   454,  1065,   456,   390,
      26,   457,    28,  1066,    30,     0,    31,    32,    33,    34,
    1067,    36,  1068,  1069,    39,    40,    41,    42,   459,     0,
      44,  1070,    46,   461,   462,    49,   463,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,  1071,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   465,    80,    81,    82,    83,    84,  1586,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   466,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,  1072,     0,     0,     0,  1073,     0,     0,
     109,   467,     0,     0,     0,     0,   111,   112,   113,   114,
     468,   116,   117,   118,     0,     0,     0,     0,     0,     0,
       0,   122,   123,   124,     0,     0,     0,   125,     0,   126,
     127,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   469,   135,   136,   137,   138,   139,   140,
       0,     0,  1074,   142,     0,     0,   391,     0,   146,   147,
       0,     0,     0,   151,   152,   153,   154,   155,   156,     0,
    1075,     0,   160,     0,     0,   163,   164,   165,   166,   167,
     168,   470,   170,   471,   472,   473,   174,   175,   474,   475,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   476,     0,   191,   477,   193,     0,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,     0,     0,     5,     6,     0,
       0,   244,  1076,  1077,  1078,  1079,   388,   389,     0,    12,
      13,    14,  1062,    16,    17,    18,   452,  1063,  1064,   454,
    1065,   456,   390,    26,   457,    28,  1066,    30,     0,    31,
      32,    33,    34,  1067,    36,  1068,  1069,    39,    40,    41,
      42,   459,     0,    44,  1070,    46,   461,   462,    49,   463,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,  1071,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   465,    80,    81,    82,
      83,    84,  1590,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   466,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,  1072,     0,     0,     0,
    1073,     0,     0,   109,   467,     0,     0,     0,     0,   111,
     112,   113,   114,   468,   116,   117,   118,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,     0,     0,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   469,   135,   136,   137,
     138,   139,   140,     0,     0,  1074,   142,     0,     0,   391,
       0,   146,   147,     0,     0,     0,   151,   152,   153,   154,
     155,   156,     0,  1075,     0,   160,     0,     0,   163,   164,
     165,   166,   167,   168,   470,   170,   471,   472,   473,   174,
     175,   474,   475,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   476,     0,   191,   477,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     0,     0,
       5,     6,     0,     0,   244,  1076,  1077,  1078,  1079,   388,
     389,     0,    12,    13,    14,  1062,    16,    17,    18,   452,
    1063,  1064,   454,  1065,   456,   390,    26,   457,    28,  1066,
      30,     0,    31,    32,    33,    34,  1067,    36,  1068,  1069,
      39,    40,    41,    42,   459,     0,    44,  1070,    46,   461,
     462,    49,   463,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,  1071,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   465,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   466,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,  1072,
       0,     0,     0,  1073,     0,     0,   109,   467,     0,     0,
       0,     0,   111,   112,   113,   114,   468,   116,   117,   118,
       0,     0,     0,     0,     0,     0,     0,   122,   123,   124,
       0,     0,     0,   125,     0,   126,   127,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   469,
     135,   136,   137,   138,   139,   140,     0,     0,  1074,   142,
       0,     0,   391,     0,   146,   147,     0,     0,     0,   151,
     152,   153,   154,   155,   156,     0,  1075,     0,   160,     0,
       0,   163,   164,   165,   166,   167,   168,   470,   170,   471,
     472,   473,   174,   175,   474,   475,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   476,     0,
     191,   477,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     5,     6,     0,     0,   244,  1076,  1077,
    1078,  1079,   388,   389,     0,    12,    13,    14,  1062,    16,
      17,    18,   452,  1063,  1064,   454,  1065,   456,   390,    26,
     457,    28,  1066,    30,     0,    31,    32,    33,    34,  1067,
      36,  1068,  1069,    39,    40,    41,    42,   459,     0,    44,
    1070,    46,   461,   462,    49,   463,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1071,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   465,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   466,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,  1072,     0,     0,     0,  1123,     0,     0,   109,
     467,     0,     0,     0,     0,   111,   112,   113,   114,   468,
     116,   117,   118,     0,     0,     0,     0,     0,     0,     0,
     122,   123,   124,     0,     0,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   469,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   391,     0,   146,   147,     0,
       0,     0,   151,   152,   153,   154,   155,   156,     0,  1075,
       0,   160,     0,     0,   163,   164,   165,   166,   167,   168,
     470,   170,   471,   472,   473,   174,   175,   474,   475,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   476,     0,   191,   477,   193,     0,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,     0,     0,     5,     6,     0,     0,
     244,  1076,  1077,  1078,  1079,   388,   389,     0,    12,    13,
      14,   451,    16,    17,    18,   452,    20,   453,   454,   455,
     456,   390,    26,   457,    28,    29,    30,     0,    31,    32,
      33,    34,   458,    36,    37,    38,    39,    40,    41,    42,
     459,     0,    44,   460,    46,   461,   462,    49,   463,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
     464,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   465,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   466,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,     0,     0,     0,     0,     0,
       0,     0,   109,   467,     0,     0,     0,     0,   111,   112,
     113,   114,   468,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,   122,   123,   124,     0,     0,     0,   125,
    1527,   126,   127,     0,     0,     0,     0,  1528,     0,   129,
       0,   130,   131,   132,   133,   469,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   391,     0,
     146,   147,     0,     0,     0,   151,   152,   153,   154,   155,
     156,     0,   158,     0,   160,     0,     0,   163,   164,   165,
     166,   167,   168,   470,   170,   471,   472,   473,   174,   175,
     474,   475,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   476,     0,   191,   477,   193,     0,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,     5,     6,     0,
       0,     0,     0,   244,     0,     0,   388,   389,     0,    12,
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
     125,  1541,   126,   127,     0,     0,     0,     0,  1542,     0,
     129,     0,   130,   131,   132,   133,   469,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   391,
       0,   146,   147,     0,     0,     0,   151,   152,   153,   154,
     155,   156,     0,   158,     0,   160,     0,     0,   163,   164,
     165,   166,   167,   168,   470,   170,   471,   472,   473,   174,
     175,   474,   475,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   476,     0,   191,   477,   193,
       0,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,     5,     6,
       0,     0,     0,     0,   244,     0,     0,   388,   389,     0,
      12,    13,    14,   451,    16,    17,    18,   452,    20,   453,
     454,   455,   456,   390,    26,   457,    28,    29,    30,     0,
      31,    32,    33,    34,   458,    36,    37,    38,    39,    40,
      41,    42,   459,     0,    44,   460,    46,   461,   462,    49,
     463,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,   464,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   465,    80,    81,
      82,    83,    84,  1290,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     466,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,     0,     0,     0,
       0,     0,     0,     0,   109,   467,     0,     0,     0,     0,
     111,   112,   113,   114,   468,   116,   117,   118,     0,     0,
       0,     0,     0,     0,     0,   122,   123,   124,     0,     0,
       0,   125,     0,   126,   127,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   469,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,     0,     0,
     391,     0,   146,   147,     0,     0,     0,   151,   152,   153,
     154,   155,   156,     0,   158,     0,   160,     0,     0,   163,
     164,   165,   166,   167,   168,   470,   170,   471,   472,   473,
     174,   175,   474,   475,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   476,     0,   191,   477,
     193,     0,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,     5,
       6,     0,     0,     0,     0,   244,     0,     0,   388,   389,
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
       0,     0,   129,     0,   130,   131,   132,   133,   469,   135,
     136,   137,   138,   139,   140,     0,     0,   141,   142,     0,
       0,   391,     0,   146,   147,     0,     0,     0,   151,   152,
     153,   154,   155,   156,     0,   158,     0,   160,     0,     0,
     163,   164,   165,   166,   167,   168,   470,   170,   471,   472,
     473,   174,   175,   474,   475,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   476,     0,   191,
     477,   193,     0,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
       5,     6,     0,     0,     0,     0,   244,     0,     0,   388,
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
       0,     0,     0,   129,     0,   130,   131,   132,   133,   469,
     135,   136,   137,   138,   139,   140,     0,     0,     0,   142,
       0,     0,   391,     0,   146,   147,     0,     0,     0,   151,
     152,   153,   154,   155,   156,     0,     0,     0,   160,     0,
       0,   163,   164,   165,   166,   167,   168,   470,   170,   471,
     472,   473,   174,   175,     0,   475,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   476,     0,
     191,   477,   193,     0,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,     0,     0,     0,     0,     0,     0,   244
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     119,   612,   105,   106,     1,     2,     3,   177,   305,    10,
     950,   157,   399,   400,   706,   161,   809,   937,     1,     2,
       3,     4,   336,   734,   716,  1217,   284,     1,     2,     3,
       4,   252,  1048,   628,   401,   613,   614,   615,   616,   555,
     556,   192,   631,   159,  1201,   253,  1420,  1033,   809,  1423,
     972,     1,  1284,  1285,   653,   838,   839,     1,   245,   246,
     268,   864,   914,    27,    28,   432,   433,   553,   554,   555,
     556,    37,   914,   120,    98,   880,    43,   553,   554,  1341,
      47,  1230,  1563,     1,    48,    52,   825,    57,    27,    28,
       1,     1,    37,     1,   104,    31,   144,     1,   591,   104,
     593,   594,    40,   596,    71,   598,   121,    45,    46,    48,
       1,     1,    76,   606,   607,     1,    54,   809,   109,    58,
       1,   104,     1,    61,     1,    63,    64,    95,    30,    30,
     104,   109,    98,  1618,    72,     1,   394,    76,   241,   242,
     398,   156,    81,   158,   927,     0,     1,     1,   120,    98,
     114,    96,   133,    98,   109,   938,   133,    30,   220,   109,
     160,    99,    55,   155,     1,   109,   115,    60,    38,    39,
     160,    41,    42,   155,   113,   114,   115,    34,   178,   940,
      56,   284,    58,   149,   231,    25,    98,   108,   178,    59,
       8,   109,   120,    50,   886,    35,   275,   179,   260,   184,
     497,   201,   139,   170,   149,    98,   173,   144,   129,   158,
     112,   192,   190,   198,     1,   192,   188,   185,   109,   109,
     212,   188,    62,   149,   126,   483,   102,     1,   243,  1714,
     109,   279,   109,  1465,   926,   245,   246,   192,   262,   249,
     245,   246,   115,   109,   249,   115,  1039,   214,   239,   151,
     220,    85,     1,   155,   109,  1736,   158,   968,  1198,   171,
       1,   162,    30,  1183,   780,   781,   313,   866,  1073,    98,
     104,   189,   109,   107,   284,  1432,  1037,   179,  1039,   284,
     216,   192,   192,     1,   192,   119,  1435,   121,   192,   162,
     260,   394,   162,   231,   413,   398,   263,   664,   189,  1221,
    1562,  1317,   778,   779,  1290,   424,   192,   186,  1230,  1048,
    1049,   192,   189,   279,   572,  1689,  1168,  1120,  1123,   221,
     222,   223,   109,   189,   427,   159,  1168,   430,   821,   293,
     697,   186,   553,   554,   279,   109,   439,   301,   192,   442,
     443,   420,   550,   551,   112,   448,   258,   259,  1040,   261,
     187,   279,   560,   279,   293,   542,   226,     1,   126,   177,
     109,   160,   301,   265,   109,   149,   278,   317,   109,   515,
     309,     1,  1746,     1,  1748,   319,     1,   523,   290,   178,
     483,   257,   102,   151,   394,   323,   324,   325,   398,   394,
     109,   109,  1175,   398,   270,   123,   272,   267,   501,   502,
       1,   123,   189,   519,   102,   508,     1,   283,   284,   285,
      53,   287,   186,   289,     1,   425,   426,   109,   120,   158,
     425,   426,     0,     1,   138,   132,    98,   171,   109,   532,
     533,   441,     1,   262,   263,   445,   441,   186,   825,   590,
     445,   158,   425,   426,     1,    30,  1678,   109,   189,    98,
     109,   425,   426,   221,   222,   223,   139,     1,   441,   274,
     204,   144,   445,   130,   131,   109,   281,   441,   188,   187,
     189,   445,   859,   483,   109,  1167,   275,   149,   483,   109,
      98,   109,   492,   282,   109,    46,   188,   492,   131,   203,
     188,     1,   199,   292,   239,   279,     1,     1,   190,  1292,
     149,     9,    10,    64,  1020,  1021,  1022,  1739,   109,   492,
     768,   239,   631,  1435,   109,   109,    96,   239,   492,  1711,
     887,   888,   109,   533,   186,   892,   629,   112,   533,   632,
     189,   109,   542,  1122,  1020,  1021,  1022,   542,   796,  1300,
     109,   126,   186,   553,   554,   555,   556,   548,   553,   554,
     555,   556,   109,   171,   189,   922,   186,   778,    96,   533,
     241,   189,   572,   162,   189,   109,   151,   572,  1163,  1352,
     155,    98,   406,   158,   693,   409,   784,   696,  1317,   413,
     788,   102,   416,   417,    43,   186,   158,  1326,    47,   155,
     424,   186,    78,    52,   179,   189,  1288,   105,  1337,   109,
     434,    96,   189,   722,   109,   109,   440,    43,   186,  1766,
     444,    47,    71,   759,   120,   449,    52,   125,   109,   127,
     189,   155,   725,   726,   727,   109,   729,    96,   189,   231,
     109,   158,   189,   132,   236,    71,   221,   222,   223,   109,
     258,   259,   186,   261,   224,   225,   480,   155,     9,    10,
     268,   159,  1572,   109,   149,     9,    10,   491,   492,   239,
     278,  1048,  1049,   109,    46,   768,    48,   188,   176,   155,
       5,   158,   290,     5,     9,    96,   186,     9,   212,   689,
     149,   186,   186,   189,   689,   519,   224,   225,  1481,   197,
      27,    28,   689,     1,   528,     3,   109,   155,   189,    81,
     199,   239,   184,   713,   714,   189,   689,   215,   713,   714,
     189,   170,     9,   121,   173,   689,   198,  1328,   320,   189,
     155,    96,  1433,   144,    96,   102,   108,  1438,   155,   188,
     713,   714,    29,   189,   170,     1,  1050,   173,   115,   713,
     714,   227,   228,   189,   105,  1003,   121,     9,   156,   583,
     158,   105,   188,   587,    46,   214,    48,  1273,   768,   155,
      68,     9,    10,   768,   125,    73,   127,    29,    34,   269,
    1710,   125,   144,   127,    55,  1514,   189,   114,   214,    60,
     280,   156,    55,   158,    50,    85,   796,    60,   170,   790,
     125,   796,   127,   125,   155,   127,  1004,   631,   159,  1394,
     135,   155,  1585,   135,   263,   159,    79,   107,     1,  1017,
     155,  1178,   120,   123,   120,   176,   108,  1701,  1702,   119,
     155,   121,   176,   155,    96,    98,   660,   263,   125,   188,
     127,   119,   146,    96,   179,   243,   197,   147,    98,   136,
     674,    34,  1012,   197,   678,   679,   557,   120,   158,   121,
     561,   685,   998,   212,   215,   115,    96,   105,   155,   693,
     148,   215,   696,   125,   178,   127,   700,   123,   108,  1753,
    1653,   139,  1655,   161,   136,  1759,   139,   125,   170,   127,
     121,   144,   196,   160,   156,  1596,   158,   155,   722,  1600,
     188,   147,   138,   155,  1505,  1506,   155,   188,   158,   733,
     158,   178,   158,   188,   144,    97,   152,   155,   196,   188,
     188,   159,   150,  1280,   212,   156,   108,   158,   275,  1177,
    1498,   212,   253,   254,   201,   282,   118,   212,   176,   167,
    1317,   130,   131,   212,   212,   292,   770,   129,   150,  1326,
      98,   102,   952,   168,  1047,   276,   120,   952,  1731,   197,
    1337,  1649,   158,  1651,   115,   167,   139,   115,   102,   184,
     102,   102,   102,  1661,    96,  1663,   800,   215,  1265,   952,
    1565,   115,   155,   115,   115,   115,   108,   877,   952,   813,
     269,   203,   120,   305,   155,   238,  1678,   240,   155,   889,
     212,   280,   314,  1003,  1705,   227,   228,   229,  1003,   238,
     155,   240,   610,   611,   838,   839,   840,   841,    27,    28,
    1020,  1021,  1022,   617,   618,  1020,  1021,  1022,  1019,    38,
      39,   219,    41,    42,  1635,  1636,   283,   284,   285,    48,
     619,   620,   289,   219,  1401,  1161,  1162,   120,   247,    58,
      59,  1553,  1554,   247,   158,   248,   880,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    76,   155,     0,
     894,   192,    81,   169,    94,   255,    51,   101,   202,   195,
     103,   147,   104,   158,   186,   186,   186,   186,    30,    48,
     154,   120,   252,   310,   155,   919,     1,   144,  1683,   120,
     155,   109,  1262,   927,   113,   114,   115,   155,   144,   186,
     123,   123,  1469,   158,   938,   405,   406,   158,   158,   409,
     155,  1722,    36,   413,    17,   216,   416,   417,    30,    30,
     237,   236,   192,   192,   424,     3,   251,  1514,   120,   170,
     172,   239,   172,   290,   434,    72,   290,   120,   237,    96,
     440,    96,  1737,   162,   444,    96,   156,   151,   109,   449,
     109,    30,   129,   162,   162,  1413,   134,   252,    96,   305,
     144,  1171,   120,   134,    96,   186,  1171,  1177,    98,   186,
      46,    98,  1177,   186,  1171,   155,    96,   243,   237,  1189,
     480,   186,   144,   239,  1189,   192,    34,   120,  1171,   134,
     172,   491,  1189,   109,   144,    96,  1030,  1171,  1208,  1033,
    1458,    30,   292,  1208,   233,    96,  1189,   226,   155,   305,
     120,  1208,    96,   186,   200,  1189,   134,  1227,   162,   155,
     134,  1816,  1227,  1818,  1234,  1208,    98,   120,   528,  1234,
     149,   102,   102,  1828,  1208,  1354,   144,   186,   186,  1073,
     123,   123,   155,    36,  1227,    30,   134,    30,   267,   192,
     155,  1234,    98,  1227,   142,   143,   120,   145,   251,  1269,
    1234,    81,   109,   129,  1269,   153,   109,   120,   149,   157,
     260,   159,   266,   264,   293,   291,   164,   273,   158,    30,
     292,   158,   301,   583,   158,   158,    30,   587,    30,  1123,
     309,   158,   293,   181,   233,  1269,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   146,   158,   158,   158,   312,
     109,   144,  1570,   200,   102,   134,     7,   205,   206,   207,
     208,   209,   210,  1581,  1582,    98,  1584,   192,   158,   192,
     239,   631,   239,   239,  1592,   239,   158,   186,   155,   108,
     158,  1175,   149,   322,   243,   129,   188,   192,   149,   149,
     120,    79,  1455,  1456,  1457,   120,  1190,   657,   189,   256,
     660,   256,   149,   288,   292,    80,  1200,    30,   189,    30,
     109,   263,   128,   189,   674,   189,   189,   189,   678,   679,
     189,   189,   172,   189,   189,   685,   189,   189,   277,   186,
     128,    98,   186,   693,  1228,   144,   696,   188,   155,   188,
     700,   322,   188,  1413,   186,   186,   186,   186,  1413,   149,
      96,   286,   149,   189,   189,   189,    30,   189,   189,    98,
     172,   189,  1256,   189,   293,   189,    96,   108,   149,    55,
      96,    30,  1266,   733,   271,   109,  1270,   199,   109,   231,
    1698,   188,   120,    96,    96,   199,   199,   120,  1458,   104,
     200,   146,   120,  1458,   189,   189,  1290,   189,   189,  1293,
     189,    95,   189,   188,   231,   185,   199,   311,   293,   120,
     770,   311,   120,   299,  1308,   311,   188,   312,   312,   201,
     120,   663,  1124,   231,   312,   420,   249,   881,   249,  1747,
     928,  1168,   252,  1683,  1737,   771,  1045,   702,   400,   587,
     800,  1309,  1491,  1289,   159,  1287,  1026,  1765,  1284,  1195,
     480,  1614,  1190,   813,  1198,  1203,   589,  1351,  1352,  1270,
    1354,  1355,  1356,   609,  1358,   841,  1221,   331,   631,   634,
    1788,   631,   734,   637,  1759,  1753,  1350,  1350,   838,   839,
     840,   841,  1645,  1651,  1256,  1326,  1267,  1337,  1049,  1514,
    1266,  1330,  1810,  1511,  1146,  1058,  1390,   913,  1384,    -1,
    1570,  1819,  1556,  1327,    -1,  1570,    -1,    -1,    -1,    -1,
      -1,  1581,  1582,    -1,  1584,    -1,  1581,  1582,    -1,  1584,
     880,    -1,  1592,  1417,    -1,    -1,  1420,  1592,   243,  1423,
      -1,    -1,    -1,    -1,   894,    -1,    -1,    -1,    -1,    -1,
    1434,    -1,    -1,    -1,    -1,  1439,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   919,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   927,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   938,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1488,  1489,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1698,    -1,
      -1,    -1,    -1,  1698,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1030,    -1,    -1,  1033,    -1,    -1,    -1,  1747,    -1,    -1,
      -1,    -1,  1747,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1585,  1586,    -1,  1588,  1765,  1590,    -1,    -1,    -1,
    1765,    -1,    -1,  1597,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1073,    -1,    -1,    -1,    -1,  1788,    -1,
      -1,    -1,    -1,  1788,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1810,    -1,    -1,    -1,    -1,  1810,    -1,    -1,    -1,  1819,
      -1,    -1,    -1,    -1,  1819,  1649,    -1,  1651,    -1,  1653,
      -1,  1655,    -1,  1123,    -1,    -1,    -1,  1661,    -1,  1663,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   492,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1679,    -1,    -1,  1682,    -1,
      -1,    -1,    -1,    -1,    -1,  1689,    -1,    -1,   513,   514,
      -1,    -1,   517,   518,   519,    -1,  1700,   522,    -1,    -1,
     525,    -1,    -1,    -1,    -1,  1175,   531,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   540,    -1,    -1,    -1,    -1,
    1190,    -1,    -1,    -1,    -1,    -1,    -1,  1731,    -1,    -1,
    1200,    -1,    -1,    -1,    -1,    -1,    -1,  1741,   563,   564,
      -1,    -1,  1746,    -1,  1748,    -1,    -1,   572,   573,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1228,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1770,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1786,    -1,    -1,    -1,  1256,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1266,    -1,    -1,    -1,
    1270,    -1,  1806,    -1,    -1,    -1,    -1,  1811,   633,    -1,
      -1,    -1,   637,    -1,    -1,    -1,    -1,    -1,    -1,  1823,
    1290,    -1,  1826,  1293,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1308,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   676,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   701,    -1,    -1,    -1,
      -1,  1351,  1352,    -1,  1354,  1355,  1356,    -1,  1358,    -1,
      -1,    -1,   717,    -1,    -1,    -1,   721,   722,    -1,   724,
      -1,    -1,    -1,    -1,    -1,    -1,   731,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   753,   754,
      -1,    -1,   757,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,    -1,    -1,
    1420,   776,    -1,  1423,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1434,    -1,    -1,    -1,    -1,  1439,
      -1,   796,    -1,    -1,    -1,    -1,    -1,   802,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1488,  1489,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   882,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   917,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   939,  1585,  1586,    -1,  1588,    -1,
    1590,   946,   947,    -1,    -1,    -1,    -1,  1597,    -1,    -1,
      -1,    -1,   957,    -1,    -1,   960,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   981,   982,   983,    -1,
     985,   986,   987,   988,   989,    -1,    -1,   992,   993,    -1,
     995,   996,    -1,    -1,    -1,  1000,  1001,    -1,    -1,  1649,
      -1,  1651,    -1,  1653,    -1,  1655,    -1,    -1,    -1,    -1,
    1015,  1661,    -1,  1663,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1026,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1679,
      -1,  1036,  1682,    -1,    -1,    -1,    -1,    -1,    -1,  1689,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1700,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1731,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1741,    -1,    -1,    -1,    -1,  1746,    -1,  1748,    -1,
      -1,    -1,    -1,    -1,    -1,  1110,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1770,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1786,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1806,    -1,    -1,    -1,
      -1,  1811,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1177,  1823,    -1,    -1,  1826,    -1,    -1,    -1,
      -1,    -1,  1187,    -1,    -1,    -1,    -1,    -1,  1193,  1194,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1210,    -1,    -1,  1213,  1214,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1254,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1295,    -1,  1297,    -1,  1299,    -1,    -1,  1302,    -1,    -1,
      -1,    -1,  1307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1404,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1412,  1413,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1431,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1444,
    1445,  1446,  1447,    -1,  1449,  1450,    -1,  1452,    -1,  1454,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1470,    -1,    -1,    -1,    -1,
    1475,    -1,    -1,    -1,  1479,    -1,    -1,    -1,  1483,    -1,
    1485,    -1,  1487,    -1,    -1,    -1,    -1,    -1,  1493,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1571,    -1,    -1,    -1,
      -1,  1576,  1577,    -1,    -1,    -1,    -1,    -1,    -1,  1584,
      -1,    -1,    -1,    -1,  1589,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1606,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1619,    -1,  1621,    -1,  1623,    -1,
      -1,  1626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1694,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1717,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1747,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,    -1,    -1,    -1,  1784,
      -1,    -1,    -1,  1788,    -1,    -1,    -1,    -1,  1793,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,  1809,    -1,    34,    35,  1813,    37,
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
     188,    -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
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
     318,     0,     1,   321,   322,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
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
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
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
     309,   310,   311,   312,   313,   314,   315,   316,     1,   318,
      -1,    -1,   321,   322,    -1,    -1,    -1,    -1,    -1,    -1,
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
     153,    -1,   155,   156,    -1,   158,   159,   160,   161,   162,
      -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,   192,
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
     313,   314,   315,   316,     1,   318,    -1,    -1,   321,   322,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
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
      -1,   318,    11,    12,   321,   322,    -1,    -1,    -1,    -1,
      -1,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
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
     149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
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
     309,   310,   311,   312,   313,   314,   315,    -1,    -1,    -1,
      -1,    -1,    -1,   322,    21,    22,    23,    24,    25,    26,
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
      -1,   148,   149,   150,   151,   152,   153,    -1,   155,   156,
      -1,   158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,   192,    -1,    -1,    -1,    -1,
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
      -1,   318,    -1,    -1,   321,   322,    -1,    -1,    -1,    -1,
     327,   328,    21,    22,    23,    24,    25,    26,    27,    28,
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
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
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
      -1,    -1,   321,   322,    -1,    16,    -1,    -1,    -1,   328,
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
     151,   152,   153,    -1,   155,   156,    -1,   158,   159,   160,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,   176,    -1,   178,   179,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,
     191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,
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
     311,   312,   313,   314,   315,   316,    -1,   318,    16,    -1,
     321,   322,    -1,    21,    22,    23,    24,    25,    26,    -1,
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
     318,    16,   320,   321,   322,    -1,    21,    22,    23,    24,
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
     315,   316,    16,   318,    -1,    -1,   321,   322,    -1,    -1,
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
      -1,    -1,    -1,    -1,   158,    -1,    -1,   161,   162,    -1,
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
     314,   315,    16,    -1,    -1,    -1,    -1,    -1,   322,    -1,
      -1,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
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
     314,   315,    16,    -1,    -1,    -1,    -1,    -1,   322,    -1,
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
     314,   315,    18,    19,    -1,    -1,    -1,    -1,   322,    25,
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
      -1,    -1,    -1,    -1,    -1,    -1,   322,    21,    22,    23,
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
     184,    -1,    -1,    -1,   188,    -1,   190,   191,   192,    -1,
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
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
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
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
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
     188,    -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   188,    -1,   190,   191,   192,    -1,    -1,    -1,
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
     184,    -1,    -1,    -1,   188,    -1,   190,   191,   192,    -1,
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
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
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
      -1,   187,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
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
     312,   313,   314,   315,   316,   317,   318,    -1,    -1,   321,
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
     310,   311,   312,   313,   314,   315,   316,    -1,   318,   319,
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
     318,    -1,   320,   321,   322,    21,    22,    23,    24,    25,
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
      -1,    -1,   146,    -1,   148,   149,   150,   151,   152,   153,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,    -1,   159,
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
     158,   159,   160,   161,   162,    -1,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
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
     318,    -1,    -1,    -1,   322,    21,    22,    23,    24,    25,
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
     152,   153,    -1,   155,   156,    -1,    -1,   159,   160,   161,
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
     150,   151,   152,   153,    -1,   155,   156,    -1,   158,   159,
      -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,    -1,    -1,
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
     320,    -1,   322,    21,    22,    23,    24,    25,    26,    -1,
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
     314,   315,   316,    -1,   318,    25,    26,    -1,   322,    -1,
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
      -1,   148,   149,   150,    -1,   152,   153,   154,    -1,    -1,
      -1,   158,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,
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
     307,   308,   309,   310,   311,   312,   313,   314,   315,    -1,
      -1,    25,    26,    -1,    -1,   322,   323,   324,   325,   326,
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
     224,   225,   226,   227,   228,   229,    -1,   231,    -1,   233,
      -1,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    25,    26,    -1,    -1,   322,   323,
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
      -1,    -1,    -1,   224,   225,   226,   227,   228,   229,    -1,
     231,    -1,   233,    -1,    -1,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,    -1,   265,   266,   267,    -1,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,    -1,    -1,    25,    26,    -1,
      -1,   322,   323,   324,   325,   326,    34,    35,    -1,    37,
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
     315,    -1,    -1,    25,    26,    -1,    -1,   322,   323,   324,
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
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,   130,   131,    -1,   133,    -1,    -1,    -1,   137,   138,
     139,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,   148,
     149,   150,    -1,   152,   153,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
     189,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
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
     309,   310,   311,   312,   313,   314,   315,    25,    26,    -1,
      -1,    -1,    -1,   322,    -1,    -1,    34,    35,    -1,    37,
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
     308,   309,   310,   311,   312,   313,   314,   315,    25,    26,
      -1,    -1,    -1,    -1,   322,    -1,    -1,    34,    35,    -1,
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
      -1,   148,   149,   150,    -1,   152,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
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
      25,    26,    -1,    -1,    -1,    -1,   322,    -1,    -1,    34,
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
     225,   226,   227,   228,   229,    -1,    -1,    -1,   233,    -1,
      -1,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,    -1,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,    -1,
     265,   266,   267,    -1,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    -1,    -1,    -1,    -1,    -1,    -1,   322
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
     178,   179,   182,   183,   184,   188,   190,   191,   192,   198,
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
     315,   316,   318,   321,   322,   327,   328,   342,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   363,   364,   365,   366,   367,
     368,   372,   373,   374,   378,   380,   381,   383,   390,   392,
     395,   396,   397,   399,   400,   401,   402,   403,   405,   406,
     408,   409,   410,   411,   412,   413,   415,   416,   419,   420,
     421,   422,   423,   428,   430,   432,   433,   434,   439,   458,
     461,   465,   468,   469,   475,   476,   477,   478,   479,   481,
     482,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     494,   495,   496,   497,   500,   501,   502,   503,   504,   505,
     506,   509,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   523,   524,   525,   526,   527,   528,   542,   543,
     545,   546,   547,   548,   549,   550,   551,   552,   573,   578,
     579,   580,   581,   582,   583,   586,   644,   645,   646,   647,
     649,   650,   651,   652,   653,   660,   661,   662,    34,    35,
      50,   217,   398,   399,   400,   398,   398,   399,   400,   158,
     158,    38,    39,    41,    42,    48,    58,    59,    76,    81,
     113,   114,   115,   162,   226,   267,   293,   301,   309,   379,
     380,   384,   385,   386,   162,   155,   155,   155,   158,   387,
     158,    25,    35,    62,   120,   279,   438,   440,   441,   155,
     120,   155,   158,   158,    78,   155,   227,   228,   155,   120,
     407,    40,    44,    46,    47,    48,    49,    52,    61,    69,
      72,    74,    75,    77,    99,   114,   137,   162,   171,   204,
     242,   244,   245,   246,   249,   250,   263,   266,   660,   661,
     120,    16,   398,   400,   421,   648,   659,   660,    49,    74,
      75,   120,   155,   187,   250,   420,   422,   432,   189,   420,
     660,   155,   155,   659,   660,    18,    19,   660,   155,    31,
     216,   219,   219,   231,   233,   320,   509,   231,   233,   320,
     421,   648,   231,   320,   509,   231,   236,   320,   120,   247,
     247,   248,   158,   155,   402,   478,   317,   420,   319,   420,
     320,   421,   328,   344,   344,     0,   346,   347,    34,    50,
     349,   366,     1,   192,   343,   192,   343,   114,   381,   401,
     420,   109,   192,   109,   343,   192,    43,    47,    52,    71,
     170,   173,   188,   214,   263,   414,   424,   429,   430,   431,
     446,   447,   451,     1,     3,    68,    73,   120,   425,   169,
      94,   134,   142,   143,   145,   153,   157,   159,   164,   181,
     205,   206,   207,   208,   209,   210,   498,   499,   255,   101,
     160,   178,   201,   119,   148,   161,   196,   203,   212,   138,
     152,    51,   202,   103,   104,   160,   178,   496,   195,   155,
     503,   121,   156,   158,   510,   511,   147,   158,   186,   186,
     186,   186,   382,   513,   382,    30,   658,   184,   198,   184,
     198,   168,   184,   661,   660,   171,   204,    48,   660,   154,
     120,    46,    48,    81,   108,   170,   659,   227,   228,   229,
     252,   617,   660,   660,   310,   139,   144,   114,   293,   301,
     384,   659,   399,   399,   420,   120,   189,   388,   389,   155,
     404,   420,     1,   162,   658,   115,   162,   362,   658,   660,
     120,   144,   109,   420,   459,   460,   660,   399,   420,   420,
     571,   660,   399,   155,   155,   420,   660,   144,   459,   186,
     186,   123,   109,   186,   123,   158,   158,   158,   660,   155,
     187,   188,   189,    36,   530,   531,   532,   420,   420,     8,
     177,    17,   420,   216,    30,    30,   421,   421,   509,   421,
     421,   421,   648,   239,   239,   421,   509,    96,   421,   237,
     236,   584,   585,   660,   192,   192,   421,   420,   400,   420,
     251,   417,   418,   317,   319,   421,   239,   344,   192,   343,
     192,   343,     3,   350,   366,   396,     1,   350,   366,   396,
      34,   367,   396,   367,   396,   407,   343,   407,   421,   421,
     120,   170,   172,   172,   401,   421,   421,   435,   436,   660,
     290,   290,   435,   120,   442,   477,   478,   481,   481,   481,
     481,   480,   481,   481,   481,    72,   482,   486,   486,   485,
     487,   487,   487,   487,   488,   488,   489,   489,   237,    96,
      96,    96,   504,   186,   420,   196,   516,   517,   573,   659,
     420,   146,   189,   421,   522,   511,   151,   189,   522,   109,
     189,   189,   109,   109,   387,    30,   661,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,   369,   370,   371,
      96,   139,   144,   375,   376,   377,   660,   162,   162,   369,
     658,   129,   134,    56,    58,   102,   257,   270,   272,   283,
     284,   285,   287,   289,   618,   619,   620,   621,   622,   623,
     630,   636,   637,   252,    96,   305,   660,   144,   421,   120,
     660,   660,   134,   186,   186,   186,   660,    96,   109,   189,
     398,   189,   659,    98,    46,   659,   658,    98,    96,   144,
     553,   660,   421,   441,   186,   109,   190,   149,   553,   186,
     189,   189,   155,   186,   399,   399,   186,   144,   553,   421,
     190,   421,   421,   659,   421,   420,   420,   420,   660,   531,
     532,   132,   199,   186,   186,   186,   133,   192,   133,   192,
      96,   224,   225,   239,    96,   224,   225,   239,   239,   239,
     421,   421,    96,    96,   421,   243,   231,   509,   237,   109,
     241,   144,   192,   189,   420,   186,    11,    12,    20,   196,
     507,   508,   590,   660,   418,   239,   421,   366,    34,    34,
     192,   343,   192,   115,   401,   660,   172,   421,   452,   453,
     120,   448,   449,   109,    37,    98,   149,   437,   438,   553,
     660,    57,   220,   260,   426,   427,   481,   155,   158,   265,
     502,   513,   591,   594,   595,   596,   597,   598,   602,   604,
     606,   607,    40,    45,    46,    48,    54,    61,    63,    64,
      72,    99,   154,   158,   213,   231,   323,   324,   325,   326,
     554,   556,   558,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   574,   575,   576,   577,   654,   655,
     656,   657,   660,   554,   493,   559,   660,   493,   186,   187,
     109,   189,   189,   513,   150,   167,   150,   167,   139,   404,
     387,   370,   134,   158,   556,   377,   421,   553,   658,   658,
     130,   131,   658,   283,   284,   285,   289,   660,   269,   280,
     269,   280,    30,   292,    98,   115,   158,   624,   627,   618,
      40,    45,    46,    54,    61,    63,    64,    72,    99,   231,
     391,   560,   654,   233,   305,   314,   421,   660,    96,   305,
     658,   155,   553,   554,   389,    96,   186,   200,   134,   361,
     658,   162,   134,    98,   361,   554,   421,   144,   438,   155,
     120,   421,   421,   149,   102,   462,   463,   464,   466,   467,
     102,   470,   471,   472,   473,   399,   186,   186,   155,   421,
     144,   192,   421,   123,   123,   189,   189,   189,    36,   532,
     132,   199,     9,    10,   105,   125,   127,   155,   197,   527,
     529,   540,   541,   544,   155,    30,    30,   238,   240,   421,
     421,   421,   238,   240,   421,   421,   421,   421,   421,    98,
     421,   421,   421,   421,   243,   509,   120,   421,   421,    49,
      74,    75,   250,   401,   422,   432,   251,   587,   588,   155,
     212,   402,   421,   192,   115,   396,   396,   396,   452,    97,
     108,   118,   129,   454,   455,   456,   457,   109,   660,   109,
     120,   436,   129,   120,   421,   149,   438,   149,    37,   149,
     437,   438,   149,   553,   260,    55,    60,    79,   120,   437,
     443,   444,   445,   427,   420,   591,   598,   155,   291,   483,
     643,    98,   171,   258,   259,   261,   268,   278,   290,   592,
     593,   612,   613,   614,   615,   638,   641,   264,   266,   599,
     617,   273,   603,   639,   253,   254,   276,   608,   609,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     189,   556,   158,   158,   158,   158,   158,   158,   146,   178,
     196,   555,   146,   146,   421,   139,   404,   573,   376,   292,
      30,    98,   115,   158,   631,    30,   624,   555,   555,   504,
     293,   312,   553,   391,   233,   192,   398,   554,   401,   421,
     658,   109,   361,   421,   144,   398,   460,   421,   421,   115,
     463,   464,   102,   188,   115,   464,   467,   120,   474,   554,
     102,   115,   471,   102,   115,   473,   186,   398,   421,   421,
     421,   200,   470,   134,   197,   529,     7,   399,   660,   197,
     540,   399,   192,   192,   239,   239,   239,   239,    98,   322,
     243,   421,   243,   585,   188,   158,   158,   158,   188,   590,
     588,   507,   658,   130,   131,   456,   457,   457,   453,   108,
     144,   450,   553,   449,   436,   149,   437,   660,   421,   149,
     421,   129,   421,   149,   438,   149,   421,   149,   120,   120,
     421,   660,   445,    79,   186,   189,   591,   605,   256,   220,
     260,   274,   281,   642,    98,   262,   263,   640,   256,   595,
     642,   485,   612,   596,   149,   288,   600,   601,   640,   292,
     611,    80,   610,   189,   189,   569,   570,   189,   196,   660,
     189,   196,   554,   557,   189,    30,   189,   659,   660,   660,
     189,   189,   196,   660,   189,   189,   189,   189,   189,   189,
     189,   189,    30,   138,   203,   633,   634,   635,    30,   632,
     633,   277,   628,   109,   625,   172,   660,   263,   504,   186,
     128,   128,    98,   658,   421,   186,   188,   188,   421,   401,
     421,   188,   188,   660,   188,   212,   120,   474,   120,   188,
     120,   474,   188,   186,   115,   532,   660,   197,   186,   532,
     660,   186,   421,   421,   421,   421,   322,   421,   421,   421,
     421,   420,   420,   420,   155,   589,   457,   658,   421,   144,
     421,   149,   421,   149,   437,   421,   149,   421,   421,   660,
     660,   444,   421,   186,   487,    53,   131,   485,   485,   275,
     282,   292,   616,   616,   597,   155,   286,   189,   189,   109,
     189,   109,   189,    96,   189,   109,   189,   189,   189,   189,
     189,   109,   189,   109,   189,   631,   631,   635,   109,   189,
      30,   629,   640,   626,   627,   189,   393,   394,   504,   120,
     231,   313,   293,   172,   401,   421,   361,   421,   401,    96,
     401,   421,   554,   660,   188,   660,   421,   660,   188,   401,
     120,    95,   185,   533,   532,   660,   199,   532,   421,   189,
     189,   189,   420,   450,   421,   421,   421,   149,   421,    55,
     485,   485,   201,   420,   571,   572,   660,   571,   572,   554,
     554,    96,   571,   571,    30,   271,   109,   109,   457,   553,
     660,   120,   231,   660,   393,   474,    96,   188,    96,   660,
       5,   135,   536,   537,   539,   541,    29,   136,   534,   535,
     538,   541,   199,   532,   199,   200,   470,   186,   450,   421,
     120,   485,   186,   189,   189,   146,   189,   189,   554,   189,
     189,   627,   394,   457,   311,   660,   120,   231,   188,   474,
     401,   421,   474,   188,    95,   135,   539,   185,   136,   538,
     199,   115,   660,   421,   311,   660,   120,   401,   421,   188,
     188,   120,   299,   311,   660,   660,   312,   421,   312,   188,
     504,   504,   201,   293,   660,   231,   120,   660,   312,   504
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
     401,   401,   401,   401,   401,   401,   401,   401,   401,   402,
     403,   404,   405,   406,   406,   406,   407,   407,   407,   407,
     408,   409,   410,   411,   412,   412,   413,   414,   415,   416,
     417,   417,   418,   419,   420,   420,   420,   421,   421,   421,
     421,   421,   421,   422,   422,   422,   422,   422,   422,   422,
     422,   422,   422,   422,   422,   423,   424,   425,   425,   426,
     426,   426,   427,   427,   428,   428,   429,   430,   430,   430,
     431,   431,   431,   431,   431,   432,   432,   433,   433,   433,
     434,   434,   435,   435,   435,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   437,   438,   439,
     440,   440,   441,   441,   441,   441,   442,   442,   443,   443,
     443,   444,   444,   444,   445,   445,   445,   446,   447,   448,
     448,   449,   449,   449,   449,   449,   449,   450,   451,   451,
     452,   452,   453,   453,   454,   454,   454,   454,   454,   454,
     454,   455,   455,   456,   456,   457,   458,   458,   459,   459,
     460,   460,   461,   462,   462,   463,   464,   464,   465,   466,
     466,   467,   468,   468,   469,   469,   470,   470,   471,   471,
     472,   472,   473,   473,   474,   474,   475,   476,   476,   477,
     477,   478,   478,   479,   479,   479,   479,   479,   480,   479,
     479,   479,   479,   481,   481,   482,   482,   483,   483,   484,
     484,   485,   485,   485,   486,   486,   486,   486,   486,   487,
     487,   487,   488,   488,   488,   489,   489,   490,   490,   491,
     491,   492,   492,   493,   493,   494,   494,   495,   495,   495,
     495,   496,   496,   496,   497,   497,   498,   498,   498,   498,
     498,   498,   499,   499,   499,   500,   500,   500,   500,   501,
     501,   502,   502,   503,   503,   503,   504,   505,   506,   507,
     507,   508,   508,   508,   508,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   510,   510,   511,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     512,   513,   513,   513,   513,   514,   514,   514,   515,   515,
     516,   517,   517,   518,   519,   520,   521,   521,   522,   522,
     522,   522,   523,   523,   524,   525,   526,   526,   527,   527,
     527,   528,   528,   528,   528,   528,   528,   529,   529,   530,
     530,   531,   532,   532,   533,   533,   534,   534,   535,   535,
     535,   535,   536,   536,   537,   537,   537,   537,   538,   538,
     539,   539,   540,   540,   540,   540,   541,   541,   541,   541,
     542,   542,   543,   543,   544,   545,   545,   545,   545,   545,
     545,   545,   546,   547,   547,   548,   548,   549,   550,   551,
     551,   552,   552,   553,   554,   554,   554,   554,   555,   555,
     555,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     557,   557,   558,   559,   560,   560,   560,   560,   560,   560,
     560,   560,   560,   560,   561,   562,   562,   562,   563,   564,
     565,   566,   566,   566,   567,   567,   567,   567,   567,   568,
     569,   569,   569,   569,   569,   569,   569,   570,   571,   572,
     573,   574,   574,   575,   576,   576,   577,   578,   578,   578,
     579,   579,   579,   579,   579,   579,   579,   579,   579,   579,
     580,   580,   581,   581,   582,   583,   584,   584,   585,   586,
     587,   587,   588,   589,   590,   590,   591,   592,   592,   593,
     593,   594,   594,   595,   595,   596,   596,   597,   597,   598,
     599,   599,   600,   600,   601,   602,   602,   602,   603,   603,
     604,   605,   605,   606,   607,   607,   608,   608,   609,   609,
     609,   610,   610,   611,   611,   612,   612,   612,   612,   612,
     613,   614,   615,   616,   616,   616,   617,   617,   618,   618,
     618,   618,   618,   618,   618,   618,   619,   619,   619,   619,
     620,   620,   621,   622,   622,   623,   623,   623,   624,   624,
     625,   625,   626,   626,   627,   628,   628,   629,   629,   630,
     630,   630,   631,   631,   632,   632,   633,   633,   634,   634,
     635,   635,   636,   637,   637,   638,   638,   638,   639,   640,
     640,   640,   640,   641,   641,   642,   642,   643,   644,   644,
     645,   645,   646,   646,   647,   648,   648,   648,   648,   649,
     649,   649,   649,   649,   649,   650,   650,   651,   651,   652,
     652,   653,   653,   654,   654,   654,   655,   655,   656,   656,
     657,   657,   658,   659,   659,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   661,   661,   661,
     661,   661,   661,   661,   661,   661,   661,   662
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     2,     3,     2,     3,     2,     3,     4,     5,
       5,     2,     4,     5,     3,     3,     2,     2,     8,     3,
       1,     2,     3,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       1,     2,     4,     3,     5,     4,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     2,
       1,     1,     1,     4,     3,     3,     5,     4,     6,     4,
       6,     5,     7,     4,     5,     5,     6,     3,     3,     2,
       1,     3,     4,     5,     3,     6,     4,     5,     1,     2,
       3,     1,     2,     1,     6,     3,     3,     2,     3,     1,
       3,     2,     4,     5,     6,     5,     3,     2,     3,     4,
       1,     3,     1,     2,     1,     1,     1,     2,     2,     2,
       3,     1,     1,     2,     2,     2,     5,     5,     1,     4,
       3,     4,     8,     1,     2,     3,     2,     3,     8,     1,
       2,     3,     8,    10,     8,    10,     1,     2,     4,     7,
       1,     2,     4,     7,     1,     3,     8,     1,     3,     1,
       3,     1,     2,     1,     3,     3,     3,     3,     0,     4,
       3,     3,     3,     1,     5,     1,     3,     0,     1,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     4,     1,     4,     1,
       4,     1,     4,     1,     2,     1,     2,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     5,     5,     6,     3,
       4,     1,     2,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     3,
       3,     3,     3,     3,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     1,     4,     4,     3,     4,     1,     3,
       1,     3,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     4,     8,     5,     9,     9,    10,     1,     2,     1,
       2,     6,     0,     1,     3,     3,     0,     1,     1,     1,
       2,     2,     0,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     2,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     7,     3,     7,     4,     4,     3,
       7,     3,     7,     2,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     4,     4,     3,     3,
       3,     3,     4,     4,     3,     4,     6,     4,     6,     4,
       3,     4,     6,     6,     4,     6,     6,     4,     1,     2,
       1,     1,     1,     4,     5,     6,     3,     3,     3,     3,
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
       5,     8,     4,     4,     7,     5,     4,     3,     2,     5,
       4,     7,     6,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
  "CatchStatement", "VoidStatement", "Expr", "ExprSingle", "ExprSimple",
  "FLWORExpr", "ReturnExpr", "WindowType", "FLWORWinCondType",
  "FLWORWinCond", "WindowClause", "CountClause", "ForLetWinClause",
  "FLWORClause", "FLWORClauseList", "ForClause", "ForOrFrom",
  "VarInDeclList", "VarInDecl", "PositionalVar", "FTScoreVar", "LetClause",
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
     162,   659,   134,   658,   192,    -1,   350,    -1,   349,   192,
     350,    -1,   349,   343,   350,    -1,   351,    -1,   359,    -1,
     364,    -1,   365,    -1,   373,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   358,    -1,
     578,    -1,    34,    39,   184,    -1,    34,    39,   198,    -1,
      34,   115,   108,   658,    -1,    34,    38,   658,    -1,    34,
      41,   184,    -1,    34,    41,   198,    -1,    34,    59,   171,
      -1,    34,    59,   204,    -1,    34,   115,   170,   129,   130,
      -1,    34,   115,   170,   129,   131,    -1,    34,    42,   184,
     109,   150,    -1,    34,    42,   184,   109,   167,    -1,    34,
      42,   168,   109,   150,    -1,    34,    42,   168,   109,   167,
      -1,   360,    -1,   363,    -1,    50,    25,     1,    -1,    50,
      62,   658,    -1,    50,    62,   362,   658,    -1,    50,    62,
     658,    98,   361,    -1,    50,    62,   362,   658,    98,   361,
      -1,   658,    -1,   361,   109,   658,    -1,   162,   659,   134,
      -1,   115,    46,   162,    -1,    50,    35,   658,    -1,    50,
      35,   162,   659,   134,   658,    -1,    50,    35,   658,    98,
     361,    -1,    50,    35,   162,   659,   134,   658,    98,   361,
      -1,    34,   162,   659,   134,   658,    -1,    34,   115,    46,
     162,   658,    -1,    34,   115,    48,   162,   658,    -1,   367,
      -1,   366,   192,   367,    -1,   366,   343,   367,    -1,   368,
      -1,   372,    -1,   374,    -1,   378,    -1,   383,    -1,   390,
      -1,   392,    -1,   395,    -1,    34,   115,    81,   369,    -1,
      34,    81,   660,   369,    -1,   370,    -1,   369,   370,    -1,
     371,   134,   573,    -1,    82,    -1,    90,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    91,    -1,    87,    -1,
      88,    -1,    89,    -1,    34,    58,   660,    30,    -1,    34,
     267,   617,    -1,    34,   113,   154,   375,    -1,    96,   556,
     376,    -1,   376,    -1,   377,    -1,   139,    -1,   139,   377,
      -1,   144,   421,    -1,    34,   379,   144,   421,    -1,    34,
     379,   139,    -1,    34,   379,   139,   144,   421,    -1,   114,
     120,   660,    -1,   114,   120,   660,   553,    -1,   380,   114,
     120,   660,    -1,   380,   114,   120,   660,   553,    -1,   381,
      -1,   380,   381,    -1,    27,    -1,    27,   158,   382,   189,
      -1,    28,    -1,    28,   158,   382,   189,    -1,   513,    -1,
     382,   109,   513,    -1,    34,   384,    -1,    34,   380,   384,
      -1,   385,    -1,   386,    -1,    48,   661,   387,   404,    -1,
      48,   661,   387,   139,    -1,    76,    48,   661,   387,   404,
      -1,    76,    48,   661,   387,   139,    -1,   158,   189,    -1,
     158,   388,   189,    -1,   158,   189,    96,   554,    -1,   158,
     388,   189,    96,   554,    -1,   389,    -1,   388,   109,   389,
      -1,   120,   660,    -1,   120,   660,   553,    -1,    34,   293,
     660,    -1,    34,   293,   660,    96,   391,    -1,    34,   380,
     293,   660,    -1,    34,   380,   293,   660,    96,   391,    -1,
     560,    -1,   560,   555,    -1,   654,    -1,   654,   555,    -1,
      34,   301,   660,   305,   233,   504,   172,   393,    -1,    34,
     380,   301,   660,   305,   233,   504,   172,   393,    -1,   394,
      -1,   393,   109,   394,    -1,   504,    -1,   504,   553,    -1,
     504,   457,    -1,   504,   553,   457,    -1,    34,   309,   310,
     660,   305,   293,   660,   120,   660,   311,   421,    -1,    34,
     309,   310,   660,   305,   293,   660,   231,   120,   660,   311,
     299,   312,   504,    -1,    34,   309,   310,   660,   305,   293,
     660,   313,   231,   120,   660,   311,   421,    -1,    34,   309,
     310,   660,   314,   312,   263,   293,   660,   231,   120,   660,
     312,   504,   201,   293,   660,   231,   120,   660,   312,   504,
      -1,   397,    -1,   399,    -1,   400,    -1,    -1,   399,    -1,
     400,    -1,    -1,   420,    -1,   400,   420,    -1,   401,    -1,
     400,   401,    -1,   400,   420,   343,   401,    -1,   402,    -1,
     405,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   413,    -1,   415,    -1,   469,    -1,   465,    -1,
     416,    -1,   419,    -1,   155,   400,   186,    -1,   155,   398,
     186,    -1,   155,   398,   186,    -1,   406,   192,    -1,   406,
     109,   407,    -1,   114,   407,    -1,   380,   114,   407,    -1,
     120,   660,    -1,   120,   660,   553,    -1,   120,   660,   144,
     421,    -1,   120,   660,   553,   144,   421,    -1,   120,   660,
     144,   421,   192,    -1,   422,   192,    -1,   246,   248,   421,
     192,    -1,   249,   158,   420,   189,   401,    -1,   244,   247,
     192,    -1,   245,   247,   192,    -1,   432,   414,    -1,   188,
     401,    -1,    49,   158,   420,   189,   200,   401,   128,   401,
      -1,   250,   402,   417,    -1,   418,    -1,   417,   418,    -1,
     251,   590,   402,    -1,   192,    -1,   421,    -1,   420,   109,
     421,    -1,   420,   343,   421,    -1,   423,    -1,   461,    -1,
     468,    -1,   475,    -1,   586,    -1,   422,    -1,   476,    -1,
     458,    -1,   579,    -1,   580,    -1,   582,    -1,   581,    -1,
     583,    -1,   651,    -1,   649,    -1,   652,    -1,   653,    -1,
     650,    -1,   432,   424,    -1,   188,   421,    -1,    68,   290,
      -1,    73,   290,    -1,   220,    -1,   260,    -1,    57,   260,
      -1,   426,   443,    79,   421,    -1,   426,    79,   421,    -1,
     434,   425,   442,   427,   427,    -1,   434,   425,   442,   427,
      -1,    43,   120,   660,    -1,   433,    -1,   439,    -1,   428,
      -1,   430,    -1,   446,    -1,   451,    -1,   447,    -1,   429,
      -1,   430,    -1,   432,   431,    -1,   434,   120,   435,    -1,
     434,     1,   435,    -1,   434,     3,    -1,    47,    -1,   263,
      -1,   436,    -1,   435,   109,   120,   436,    -1,   435,   109,
     436,    -1,   660,   149,   421,    -1,   660,    37,   129,   149,
     421,    -1,   660,   553,   149,   421,    -1,   660,   553,    37,
     129,   149,   421,    -1,   660,   437,   149,   421,    -1,   660,
      37,   129,   437,   149,   421,    -1,   660,   553,   437,   149,
     421,    -1,   660,   553,    37,   129,   437,   149,   421,    -1,
     660,   438,   149,   421,    -1,   660,   553,   438,   149,   421,
      -1,   660,   437,   438,   149,   421,    -1,   660,   553,   437,
     438,   149,   421,    -1,    98,   120,   660,    -1,   279,   120,
     660,    -1,    52,   440,    -1,   441,    -1,   440,   109,   441,
      -1,   120,   660,   144,   421,    -1,   120,   660,   553,   144,
     421,    -1,   438,   144,   421,    -1,   120,   660,   553,   438,
     144,   421,    -1,   120,   660,   149,   421,    -1,   120,   660,
     553,   149,   421,    -1,   444,    -1,   120,   660,    -1,   120,
     660,   444,    -1,   437,    -1,   437,   445,    -1,   445,    -1,
      60,   120,   660,    55,   120,   660,    -1,    55,   120,   660,
      -1,    60,   120,   660,    -1,   214,   421,    -1,   173,   172,
     448,    -1,   449,    -1,   448,   109,   449,    -1,   120,   660,
      -1,   120,   660,   144,   421,    -1,   120,   660,   553,   144,
     421,    -1,   120,   660,   553,   144,   421,   450,    -1,   120,
     660,   144,   421,   450,    -1,   120,   660,   450,    -1,   108,
     658,    -1,   170,   172,   452,    -1,    71,   170,   172,   452,
      -1,   453,    -1,   452,   109,   453,    -1,   421,    -1,   421,
     454,    -1,   455,    -1,   456,    -1,   457,    -1,   455,   456,
      -1,   455,   457,    -1,   456,   457,    -1,   455,   456,   457,
      -1,    97,    -1,   118,    -1,   129,   130,    -1,   129,   131,
      -1,   108,   658,    -1,    69,   120,   459,   190,   421,    -1,
     137,   120,   459,   190,   421,    -1,   460,    -1,   459,   109,
     120,   460,    -1,   660,   149,   421,    -1,   660,   553,   149,
     421,    -1,    74,   158,   420,   189,   462,   115,   188,   421,
      -1,   463,    -1,   462,   463,    -1,   464,   188,   421,    -1,
     102,   421,    -1,   464,   102,   421,    -1,    74,   158,   420,
     189,   466,   115,   188,   401,    -1,   467,    -1,   466,   467,
      -1,   464,   188,   401,    -1,    75,   158,   420,   189,   470,
     115,   188,   421,    -1,    75,   158,   420,   189,   470,   115,
     120,   660,   188,   421,    -1,    75,   158,   420,   189,   472,
     115,   188,   401,    -1,    75,   158,   420,   189,   470,   115,
     120,   660,   188,   401,    -1,   471,    -1,   470,   471,    -1,
     102,   474,   188,   421,    -1,   102,   120,   660,    96,   474,
     188,   421,    -1,   473,    -1,   472,   473,    -1,   102,   474,
     188,   401,    -1,   102,   120,   660,    96,   474,   188,   401,
      -1,   554,    -1,   474,   212,   554,    -1,    49,   158,   420,
     189,   200,   421,   128,   421,    -1,   477,    -1,   476,   169,
     477,    -1,   478,    -1,   477,    94,   478,    -1,   479,    -1,
     266,   478,    -1,   481,    -1,   481,   498,   481,    -1,   481,
     499,   481,    -1,   481,   134,   481,    -1,   481,   164,   481,
      -1,    -1,   481,   159,   480,   481,    -1,   481,   157,   481,
      -1,   481,   145,   481,    -1,   481,   143,   481,    -1,   482,
      -1,   482,   255,    72,   591,   483,    -1,   484,    -1,   484,
     101,   482,    -1,    -1,   643,    -1,   485,    -1,   485,   201,
     485,    -1,   486,    -1,   485,   178,   486,    -1,   485,   160,
     486,    -1,   487,    -1,   486,   196,   487,    -1,   486,   119,
     487,    -1,   486,   148,   487,    -1,   486,   161,   487,    -1,
     488,    -1,   487,   203,   488,    -1,   487,   212,   488,    -1,
     489,    -1,   488,   152,   489,    -1,   488,   138,   489,    -1,
     490,    -1,   490,    51,   237,   554,    -1,   491,    -1,   491,
     202,    96,   554,    -1,   492,    -1,   492,   103,    96,   493,
      -1,   494,    -1,   494,   104,    96,   493,    -1,   559,    -1,
     559,   146,    -1,   496,    -1,   495,   496,    -1,   178,    -1,
     160,    -1,   495,   178,    -1,   495,   160,    -1,   500,    -1,
     497,    -1,   501,    -1,   504,    -1,   497,   195,   504,    -1,
     205,    -1,   210,    -1,   209,    -1,   208,    -1,   207,    -1,
     206,    -1,   153,    -1,   181,    -1,   142,    -1,    77,   155,
     399,   186,    -1,    77,   228,   155,   399,   186,    -1,    77,
     227,   155,   399,   186,    -1,    77,    78,   571,   155,   399,
     186,    -1,   502,   155,   186,    -1,   502,   155,   420,   186,
      -1,   503,    -1,   502,   503,    -1,   179,   660,    17,    -1,
     179,    18,    -1,   179,    19,    -1,   505,    -1,   506,    -1,
     509,    -1,   660,    -1,   508,    -1,   196,    -1,    11,    -1,
      12,    -1,    20,    -1,   512,    -1,   509,   510,    -1,   509,
     158,   189,    -1,   509,   158,   522,   189,    -1,   509,   121,
     659,    -1,   509,   121,   517,    -1,   509,   121,   516,    -1,
     509,   121,   573,    -1,   509,   121,   196,    -1,   511,    -1,
     510,   511,    -1,   156,   420,   187,    -1,   513,    -1,   516,
      -1,   517,    -1,   518,    -1,   521,    -1,   526,    -1,   519,
      -1,   520,    -1,   523,    -1,   403,    -1,   647,    -1,   644,
      -1,   645,    -1,   646,    -1,   514,    -1,   573,    -1,   515,
      -1,   221,    -1,   112,    -1,   151,    -1,   126,    -1,   222,
      -1,   223,    -1,   120,   660,    -1,   158,   189,    -1,   158,
     420,   189,    -1,   121,    -1,   171,   155,   420,   186,    -1,
     204,   155,   420,   186,    -1,   661,   158,   189,    -1,   661,
     158,   522,   189,    -1,   146,    -1,   522,   109,   146,    -1,
     421,    -1,   522,   109,   421,    -1,   524,    -1,   525,    -1,
     660,   147,   151,    -1,    48,   387,   404,    -1,   527,    -1,
     545,    -1,   528,    -1,   542,    -1,   543,    -1,   159,   660,
     532,   132,    -1,   159,   660,   532,   199,   197,   660,   532,
     199,    -1,   159,   660,   530,   532,   132,    -1,   159,   660,
     530,   532,   199,   197,   660,   532,   199,    -1,   159,   660,
     532,   199,   529,   197,   660,   532,   199,    -1,   159,   660,
     530,   532,   199,   529,   197,   660,   532,   199,    -1,   540,
      -1,   529,   540,    -1,   531,    -1,   530,   531,    -1,    36,
     660,   532,   134,   532,   533,    -1,    -1,    36,    -1,   185,
     534,   185,    -1,    95,   536,    95,    -1,    -1,   535,    -1,
     136,    -1,   538,    -1,   535,   136,    -1,   535,   538,    -1,
      -1,   537,    -1,   135,    -1,   539,    -1,   537,   135,    -1,
     537,   539,    -1,    29,    -1,   541,    -1,     5,    -1,   541,
      -1,   527,    -1,    10,    -1,   544,    -1,   541,    -1,     9,
      -1,   125,    -1,   127,    -1,   155,   399,   186,    -1,   215,
      31,   216,    -1,   215,   216,    -1,   176,   659,   177,    -1,
     176,   659,     8,    -1,   105,     7,    -1,   546,    -1,   547,
      -1,   548,    -1,   549,    -1,   550,    -1,   551,    -1,   552,
      -1,    44,   155,   399,   186,    -1,    21,   398,   186,    -1,
      46,   155,   420,   186,   155,   398,   186,    -1,    22,   398,
     186,    -1,    99,   155,   420,   186,   155,   398,   186,    -1,
      72,   155,   399,   186,    -1,    40,   155,   399,   186,    -1,
      23,   398,   186,    -1,    61,   155,   420,   186,   155,   398,
     186,    -1,    24,   399,   186,    -1,   162,   155,   420,   186,
     155,   399,   186,    -1,    96,   554,    -1,   556,    -1,   556,
     555,    -1,   213,   158,   189,    -1,   158,   189,    -1,   146,
      -1,   196,    -1,   178,    -1,   558,    -1,   560,    -1,   154,
     158,   189,    -1,   154,    -1,   326,   158,   189,    -1,   326,
      -1,   574,    -1,   577,    -1,   654,    -1,   554,    -1,   557,
     109,   554,    -1,   660,    -1,   660,    -1,   562,    -1,   569,
      -1,   567,    -1,   570,    -1,   568,    -1,   566,    -1,   565,
      -1,   564,    -1,   563,    -1,   561,    -1,   231,   158,   189,
      -1,    45,   158,   189,    -1,    45,   158,   569,   189,    -1,
      45,   158,   570,   189,    -1,    54,   158,   189,    -1,    72,
     158,   189,    -1,    40,   158,   189,    -1,    61,   158,   189,
      -1,    61,   158,   659,   189,    -1,    61,   158,    30,   189,
      -1,    99,   158,   189,    -1,    99,   158,   660,   189,    -1,
      99,   158,   660,   109,   571,   189,    -1,    99,   158,   196,
     189,    -1,    99,   158,   196,   109,   571,   189,    -1,    63,
     158,   660,   189,    -1,    46,   158,   189,    -1,    46,   158,
     660,   189,    -1,    46,   158,   660,   109,   571,   189,    -1,
      46,   158,   660,   109,   572,   189,    -1,    46,   158,   196,
     189,    -1,    46,   158,   196,   109,   571,   189,    -1,    46,
     158,   196,   109,   572,   189,    -1,    64,   158,   660,   189,
      -1,   660,    -1,   660,   146,    -1,    30,    -1,   575,    -1,
     576,    -1,    48,   158,   196,   189,    -1,    48,   158,   189,
      96,   554,    -1,    48,   158,   557,   189,    96,   554,    -1,
     158,   556,   189,    -1,    34,   226,   227,    -1,    34,   226,
     228,    -1,    34,   226,   229,    -1,   232,   231,   421,   239,
     421,    -1,   232,   231,   421,    96,   238,   239,   421,    -1,
     232,   231,   421,    96,   240,   239,   421,    -1,   232,   231,
     421,   224,   421,    -1,   232,   231,   421,   225,   421,    -1,
     232,   233,   421,   239,   421,    -1,   232,   233,   421,    96,
     238,   239,   421,    -1,   232,   233,   421,    96,   240,   239,
     421,    -1,   232,   233,   421,   224,   421,    -1,   232,   233,
     421,   225,   421,    -1,   230,   231,   421,    -1,   230,   233,
     421,    -1,   235,   231,   421,   243,   421,    -1,   235,   236,
     237,   231,   421,   243,   421,    -1,   234,   231,   421,    96,
     421,    -1,   242,   120,   584,   241,   421,   188,   421,    -1,
     585,    -1,   584,   109,   120,   585,    -1,   660,   144,   421,
      -1,   250,   155,   420,   186,   587,    -1,   588,    -1,   587,
     588,    -1,   251,   590,   589,    -1,   155,   420,   186,    -1,
     507,    -1,   590,   212,   507,    -1,   594,   592,    -1,    -1,
     593,    -1,   612,    -1,   593,   612,    -1,   595,    -1,   594,
     268,   595,    -1,   596,    -1,   595,   264,   596,    -1,   597,
      -1,   596,   266,   149,   597,    -1,   598,    -1,   265,   598,
      -1,   602,   599,   600,    -1,    -1,   617,    -1,    -1,   601,
      -1,   288,   155,   420,   186,    -1,   606,   603,    -1,   158,
     591,   189,    -1,   604,    -1,    -1,   639,    -1,   502,   155,
     605,   186,    -1,    -1,   591,    -1,   607,   608,    -1,   513,
      -1,   155,   420,   186,    -1,    -1,   609,    -1,   254,   610,
      -1,   253,   611,    -1,   276,    -1,    -1,    80,    -1,    -1,
     292,    -1,   613,    -1,   614,    -1,   615,    -1,   641,    -1,
     638,    -1,   171,    -1,   290,   485,   616,    -1,   259,   640,
     616,    -1,   292,    -1,   282,    -1,   275,    -1,   252,   618,
      -1,   617,   252,   618,    -1,   619,    -1,   620,    -1,   621,
      -1,   636,    -1,   622,    -1,   630,    -1,   623,    -1,   637,
      -1,   102,   280,    -1,   102,   269,    -1,   272,    -1,   287,
      -1,   257,   280,    -1,   257,   269,    -1,    58,   660,    30,
      -1,   283,    -1,    56,   283,    -1,   285,   624,    -1,   285,
     158,   624,   625,   189,    -1,    56,   285,    -1,   627,    -1,
     115,    -1,    -1,   109,   626,    -1,   627,    -1,   626,   109,
     627,    -1,    98,    30,   628,   629,    -1,    -1,   277,    30,
      -1,    -1,   640,   271,    -1,   284,   292,   631,   633,    -1,
     284,   292,   115,   633,    -1,    56,   284,   292,    -1,    98,
      30,    -1,   158,   632,   189,    -1,    30,    -1,   632,   109,
      30,    -1,    -1,   634,    -1,   635,    -1,   634,   635,    -1,
     203,   631,    -1,   138,   631,    -1,   270,    30,    -1,   289,
      -1,    56,   289,    -1,    98,   220,    -1,    98,   260,    -1,
     261,   256,    -1,   273,   640,   286,    -1,   262,   485,    -1,
      98,   131,   485,    -1,    98,    53,   485,    -1,   263,   485,
     201,   485,    -1,   278,   642,    -1,   258,   642,    -1,   281,
      -1,   274,    -1,   291,   256,   487,    -1,   156,   187,    -1,
     156,   420,   187,    -1,   316,   317,    -1,   316,   420,   317,
      -1,   318,   319,    -1,   318,   420,   319,    -1,   155,   648,
     186,    -1,   659,   123,   421,    -1,   421,   123,   421,    -1,
     648,   109,   421,   123,   421,    -1,   648,   109,   659,   123,
     421,    -1,   232,   320,   421,   239,   421,    -1,   232,   320,
     648,   239,   421,    -1,   232,   320,   421,   239,   421,    98,
     322,   421,    -1,   232,   421,   239,   421,    -1,   232,   648,
     239,   421,    -1,   232,   421,   239,   421,    98,   322,   421,
      -1,   321,   320,   421,   239,   421,    -1,   321,   421,   239,
     421,    -1,   230,   320,   509,    -1,   230,   509,    -1,   234,
     320,   509,    96,   421,    -1,   234,   509,    96,   421,    -1,
     235,   320,   236,   237,   509,   243,   421,    -1,   235,   236,
     237,   509,   243,   421,    -1,   655,    -1,   656,    -1,   657,
      -1,   325,   158,   189,    -1,   325,    -1,   323,   158,   189,
      -1,   323,    -1,   324,   158,   189,    -1,   324,    -1,    30,
      -1,    16,    -1,   660,    -1,   661,    -1,    99,    -1,    40,
      -1,    45,    -1,    54,    -1,    46,    -1,    49,    -1,   231,
      -1,    61,    -1,    63,    -1,    64,    -1,    72,    -1,    75,
      -1,    74,    -1,   213,    -1,   249,    -1,   662,    -1,    25,
      -1,   217,    -1,   129,    -1,    39,    -1,   267,    -1,    38,
      -1,   228,    -1,   227,    -1,   148,    -1,    44,    -1,   265,
      -1,   266,    -1,   280,    -1,   269,    -1,   257,    -1,   291,
      -1,   283,    -1,   285,    -1,   284,    -1,   289,    -1,   261,
      -1,   256,    -1,    80,    -1,   220,    -1,   260,    -1,    53,
      -1,   229,    -1,   242,    -1,   308,    -1,   236,    -1,   205,
      -1,   210,    -1,   209,    -1,   208,    -1,   207,    -1,   206,
      -1,    98,    -1,   113,    -1,   114,    -1,   188,    -1,    47,
      -1,    37,    -1,    68,    -1,    73,    -1,    60,    -1,    55,
      -1,    57,    -1,    79,    -1,    43,    -1,   149,    -1,    52,
      -1,   214,    -1,   172,    -1,   173,    -1,   170,    -1,    71,
      -1,    97,    -1,   118,    -1,   130,    -1,   131,    -1,   108,
      -1,    69,    -1,   137,    -1,   190,    -1,   102,    -1,    96,
      -1,   200,    -1,   128,    -1,   169,    -1,    94,    -1,    51,
      -1,   237,    -1,   103,    -1,   201,    -1,   119,    -1,   161,
      -1,   203,    -1,   152,    -1,   138,    -1,    77,    -1,    78,
      -1,   104,    -1,   202,    -1,   153,    -1,   184,    -1,   198,
      -1,   162,    -1,   139,    -1,   133,    -1,   168,    -1,   150,
      -1,   167,    -1,    34,    -1,    41,    -1,    59,    -1,   115,
      -1,    42,    -1,    58,    -1,   219,    -1,    50,    -1,    62,
      -1,    35,    -1,    48,    -1,   279,    -1,   255,    -1,   288,
      -1,   290,    -1,   259,    -1,   273,    -1,   286,    -1,   278,
      -1,   258,    -1,   272,    -1,   287,    -1,   277,    -1,   271,
      -1,   270,    -1,   254,    -1,   253,    -1,   262,    -1,   263,
      -1,   292,    -1,   282,    -1,   281,    -1,   276,    -1,   274,
      -1,   275,    -1,   241,    -1,   238,    -1,   225,    -1,   224,
      -1,   226,    -1,   243,    -1,   233,    -1,   240,    -1,   239,
      -1,    67,    -1,    65,    -1,    76,    -1,   171,    -1,   204,
      -1,   248,    -1,   246,    -1,   247,    -1,   244,    -1,   245,
      -1,   250,    -1,   251,    -1,   252,    -1,    66,    -1,   301,
      -1,   299,    -1,   300,    -1,   305,    -1,   306,    -1,   307,
      -1,   302,    -1,   303,    -1,   304,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    -1,    89,    -1,    90,    -1,    91,    -1,   293,
      -1,   294,    -1,   295,    -1,   296,    -1,   297,    -1,   298,
      -1,   309,    -1,   310,    -1,   311,    -1,   312,    -1,   313,
      -1,   314,    -1,   315,    -1,    92,    -1,   107,    -1,   116,
      -1,   174,    -1,   182,    -1,   191,    -1,   140,    -1,    93,
      -1,   117,    -1,   141,    -1,   183,    -1,   322,    -1,    26,
      -1
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
     696,   698,   700,   702,   704,   706,   708,   710,   712,   714,
     718,   722,   726,   729,   733,   736,   740,   743,   747,   752,
     758,   764,   767,   772,   778,   782,   786,   789,   792,   801,
     805,   807,   810,   814,   816,   818,   822,   826,   828,   830,
     832,   834,   836,   838,   840,   842,   844,   846,   848,   850,
     852,   854,   856,   858,   860,   862,   865,   868,   871,   874,
     876,   878,   881,   886,   890,   896,   901,   905,   907,   909,
     911,   913,   915,   917,   919,   921,   923,   926,   930,   934,
     937,   939,   941,   943,   948,   952,   956,   962,   967,   974,
     979,   986,   992,  1000,  1005,  1011,  1017,  1024,  1028,  1032,
    1035,  1037,  1041,  1046,  1052,  1056,  1063,  1068,  1074,  1076,
    1079,  1083,  1085,  1088,  1090,  1097,  1101,  1105,  1108,  1112,
    1114,  1118,  1121,  1126,  1132,  1139,  1145,  1149,  1152,  1156,
    1161,  1163,  1167,  1169,  1172,  1174,  1176,  1178,  1181,  1184,
    1187,  1191,  1193,  1195,  1198,  1201,  1204,  1210,  1216,  1218,
    1223,  1227,  1232,  1241,  1243,  1246,  1250,  1253,  1257,  1266,
    1268,  1271,  1275,  1284,  1295,  1304,  1315,  1317,  1320,  1325,
    1333,  1335,  1338,  1343,  1351,  1353,  1357,  1366,  1368,  1372,
    1374,  1378,  1380,  1383,  1385,  1389,  1393,  1397,  1401,  1402,
    1407,  1411,  1415,  1419,  1421,  1427,  1429,  1433,  1434,  1436,
    1438,  1442,  1444,  1448,  1452,  1454,  1458,  1462,  1466,  1470,
    1472,  1476,  1480,  1482,  1486,  1490,  1492,  1497,  1499,  1504,
    1506,  1511,  1513,  1518,  1520,  1523,  1525,  1528,  1530,  1532,
    1535,  1538,  1540,  1542,  1544,  1546,  1550,  1552,  1554,  1556,
    1558,  1560,  1562,  1564,  1566,  1568,  1573,  1579,  1585,  1592,
    1596,  1601,  1603,  1606,  1610,  1613,  1616,  1618,  1620,  1622,
    1624,  1626,  1628,  1630,  1632,  1634,  1636,  1639,  1643,  1648,
    1652,  1656,  1660,  1664,  1668,  1670,  1673,  1677,  1679,  1681,
    1683,  1685,  1687,  1689,  1691,  1693,  1695,  1697,  1699,  1701,
    1703,  1705,  1707,  1709,  1711,  1713,  1715,  1717,  1719,  1721,
    1723,  1726,  1729,  1733,  1735,  1740,  1745,  1749,  1754,  1756,
    1760,  1762,  1766,  1768,  1770,  1774,  1778,  1780,  1782,  1784,
    1786,  1788,  1793,  1802,  1808,  1818,  1828,  1839,  1841,  1844,
    1846,  1849,  1856,  1857,  1859,  1863,  1867,  1868,  1870,  1872,
    1874,  1877,  1880,  1881,  1883,  1885,  1887,  1890,  1893,  1895,
    1897,  1899,  1901,  1903,  1905,  1907,  1909,  1911,  1913,  1915,
    1919,  1923,  1926,  1930,  1934,  1937,  1939,  1941,  1943,  1945,
    1947,  1949,  1951,  1956,  1960,  1968,  1972,  1980,  1985,  1990,
    1994,  2002,  2006,  2014,  2017,  2019,  2022,  2026,  2029,  2031,
    2033,  2035,  2037,  2039,  2043,  2045,  2049,  2051,  2053,  2055,
    2057,  2059,  2063,  2065,  2067,  2069,  2071,  2073,  2075,  2077,
    2079,  2081,  2083,  2085,  2087,  2091,  2095,  2100,  2105,  2109,
    2113,  2117,  2121,  2126,  2131,  2135,  2140,  2147,  2152,  2159,
    2164,  2168,  2173,  2180,  2187,  2192,  2199,  2206,  2211,  2213,
    2216,  2218,  2220,  2222,  2227,  2233,  2240,  2244,  2248,  2252,
    2256,  2262,  2270,  2278,  2284,  2290,  2296,  2304,  2312,  2318,
    2324,  2328,  2332,  2338,  2346,  2352,  2360,  2362,  2367,  2371,
    2377,  2379,  2382,  2386,  2390,  2392,  2396,  2399,  2400,  2402,
    2404,  2407,  2409,  2413,  2415,  2419,  2421,  2426,  2428,  2431,
    2435,  2436,  2438,  2439,  2441,  2446,  2449,  2453,  2455,  2456,
    2458,  2463,  2464,  2466,  2469,  2471,  2475,  2476,  2478,  2481,
    2484,  2486,  2487,  2489,  2490,  2492,  2494,  2496,  2498,  2500,
    2502,  2504,  2508,  2512,  2514,  2516,  2518,  2521,  2525,  2527,
    2529,  2531,  2533,  2535,  2537,  2539,  2541,  2544,  2547,  2549,
    2551,  2554,  2557,  2561,  2563,  2566,  2569,  2575,  2578,  2580,
    2582,  2583,  2586,  2588,  2592,  2597,  2598,  2601,  2602,  2605,
    2610,  2615,  2619,  2622,  2626,  2628,  2632,  2633,  2635,  2637,
    2640,  2643,  2646,  2649,  2651,  2654,  2657,  2660,  2663,  2667,
    2670,  2674,  2678,  2683,  2686,  2689,  2691,  2693,  2697,  2700,
    2704,  2707,  2711,  2714,  2718,  2722,  2726,  2730,  2736,  2742,
    2748,  2754,  2763,  2768,  2773,  2781,  2787,  2792,  2796,  2799,
    2805,  2810,  2818,  2825,  2827,  2829,  2831,  2835,  2837,  2841,
    2843,  2847,  2849,  2851,  2853,  2855,  2857,  2859,  2861,  2863,
    2865,  2867,  2869,  2871,  2873,  2875,  2877,  2879,  2881,  2883,
    2885,  2887,  2889,  2891,  2893,  2895,  2897,  2899,  2901,  2903,
    2905,  2907,  2909,  2911,  2913,  2915,  2917,  2919,  2921,  2923,
    2925,  2927,  2929,  2931,  2933,  2935,  2937,  2939,  2941,  2943,
    2945,  2947,  2949,  2951,  2953,  2955,  2957,  2959,  2961,  2963,
    2965,  2967,  2969,  2971,  2973,  2975,  2977,  2979,  2981,  2983,
    2985,  2987,  2989,  2991,  2993,  2995,  2997,  2999,  3001,  3003,
    3005,  3007,  3009,  3011,  3013,  3015,  3017,  3019,  3021,  3023,
    3025,  3027,  3029,  3031,  3033,  3035,  3037,  3039,  3041,  3043,
    3045,  3047,  3049,  3051,  3053,  3055,  3057,  3059,  3061,  3063,
    3065,  3067,  3069,  3071,  3073,  3075,  3077,  3079,  3081,  3083,
    3085,  3087,  3089,  3091,  3093,  3095,  3097,  3099,  3101,  3103,
    3105,  3107,  3109,  3111,  3113,  3115,  3117,  3119,  3121,  3123,
    3125,  3127,  3129,  3131,  3133,  3135,  3137,  3139,  3141,  3143,
    3145,  3147,  3149,  3151,  3153,  3155,  3157,  3159,  3161,  3163,
    3165,  3167,  3169,  3171,  3173,  3175,  3177,  3179,  3181,  3183,
    3185,  3187,  3189,  3191,  3193,  3195,  3197,  3199,  3201,  3203,
    3205,  3207,  3209,  3211,  3213,  3215,  3217,  3219,  3221,  3223,
    3225,  3227,  3229,  3231,  3233,  3235,  3237,  3239,  3241,  3243,
    3245,  3247,  3249,  3251,  3253,  3255,  3257,  3259,  3261,  3263,
    3265,  3267,  3269,  3271,  3273,  3275,  3277,  3279
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
    2260,  2261,  2262,  2264,  2265,  2266,  2267,  2268,  2269,  2274,
    2282,  2304,  2312,  2320,  2327,  2334,  2345,  2354,  2363,  2372,
    2385,  2393,  2401,  2409,  2424,  2429,  2437,  2451,  2468,  2493,
    2501,  2508,  2519,  2528,  2535,  2540,  2553,  2570,  2571,  2572,
    2573,  2574,  2575,  2580,  2581,  2584,  2585,  2586,  2587,  2588,
    2591,  2592,  2593,  2594,  2595,  2600,  2614,  2622,  2627,  2635,
    2640,  2645,  2653,  2662,  2674,  2684,  2697,  2705,  2706,  2707,
    2712,  2713,  2714,  2715,  2716,  2721,  2728,  2738,  2744,  2753,
    2762,  2763,  2771,  2778,  2786,  2798,  2808,  2818,  2828,  2838,
    2848,  2858,  2868,  2879,  2888,  2898,  2908,  2924,  2933,  2942,
    2950,  2956,  2968,  2976,  2986,  2994,  3006,  3012,  3023,  3025,
    3029,  3037,  3041,  3046,  3050,  3054,  3058,  3068,  3076,  3083,
    3089,  3099,  3103,  3107,  3115,  3123,  3131,  3143,  3151,  3157,
    3167,  3173,  3183,  3187,  3197,  3203,  3209,  3215,  3224,  3233,
    3242,  3255,  3259,  3267,  3273,  3283,  3291,  3300,  3313,  3320,
    3332,  3336,  3348,  3355,  3361,  3370,  3377,  3383,  3394,  3401,
    3407,  3416,  3425,  3432,  3443,  3450,  3462,  3468,  3480,  3486,
    3497,  3503,  3514,  3520,  3531,  3537,  3548,  3557,  3561,  3570,
    3574,  3581,  3585,  3598,  3602,  3612,  3619,  3628,  3638,  3637,
    3651,  3660,  3669,  3682,  3686,  3698,  3702,  3710,  3713,  3720,
    3724,  3733,  3737,  3741,  3749,  3753,  3759,  3765,  3771,  3781,
    3785,  3789,  3797,  3801,  3807,  3817,  3821,  3831,  3835,  3845,
    3849,  3859,  3863,  3873,  3877,  3886,  3890,  3898,  3902,  3906,
    3910,  3920,  3924,  3928,  3935,  3940,  3948,  3952,  3956,  3960,
    3964,  3968,  3976,  3980,  3984,  3992,  3996,  4000,  4004,  4015,
    4021,  4031,  4037,  4047,  4051,  4055,  4118,  4140,  4168,  4332,
    4336,  4346,  4350,  4354,  4358,  4367,  4371,  4375,  4379,  4383,
    4388,  4392,  4396,  4400,  4409,  4415,  4425,  4433,  4437,  4441,
    4445,  4449,  4453,  4457,  4461,  4465,  4469,  4474,  4478,  4482,
    4486,  4494,  4498,  4502,  4506,  4514,  4521,  4528,  4538,  4542,
    4550,  4558,  4562,  4570,  4578,  4586,  4640,  4644,  4666,  4672,
    4678,  4684,  4694,  4698,  4706,  4714,  4726,  4730,  4738,  4742,
    4746,  4754,  4762,  4779,  4787,  4804,  4823,  4847,  4853,  4864,
    4870,  4881,  4890,  4892,  4896,  4901,  4911,  4914,  4921,  4927,
    4933,  4940,  4952,  4955,  4962,  4968,  4974,  4981,  4992,  4996,
    5004,  5008,  5016,  5020,  5024,  5029,  5038,  5042,  5046,  5050,
    5058,  5063,  5071,  5076,  5084,  5092,  5097,  5102,  5107,  5112,
    5117,  5122,  5128,  5136,  5140,  5157,  5161,  5169,  5177,  5185,
    5189,  5197,  5201,  5209,  5217,  5221,  5225,  5230,  5265,  5271,
    5277,  5287,  5291,  5295,  5300,  5304,  5309,  5313,  5317,  5321,
    5328,  5334,  5344,  5352,  5360,  5364,  5368,  5372,  5376,  5380,
    5384,  5388,  5392,  5396,  5404,  5412,  5416,  5420,  5428,  5435,
    5443,  5451,  5455,  5459,  5467,  5471,  5477,  5483,  5487,  5497,
    5505,  5509,  5515,  5524,  5533,  5539,  5545,  5555,  5572,  5579,
    5594,  5621,  5625,  5633,  5641,  5645,  5656,  5673,  5679,  5685,
    5695,  5699,  5705,  5711,  5715,  5721,  5725,  5731,  5737,  5744,
    5754,  5759,  5767,  5773,  5783,  5805,  5814,  5820,  5833,  5847,
    5854,  5860,  5870,  5879,  5887,  5893,  5911,  5919,  5923,  5930,
    5935,  5943,  5947,  5954,  5958,  5965,  5969,  5976,  5980,  5989,
    6002,  6005,  6013,  6016,  6024,  6032,  6040,  6044,  6052,  6055,
    6063,  6075,  6078,  6086,  6098,  6104,  6114,  6117,  6125,  6129,
    6133,  6141,  6144,  6152,  6155,  6163,  6167,  6171,  6175,  6179,
    6187,  6195,  6207,  6219,  6223,  6227,  6235,  6241,  6251,  6255,
    6259,  6263,  6267,  6271,  6275,  6279,  6287,  6291,  6295,  6299,
    6307,  6313,  6323,  6333,  6337,  6345,  6355,  6366,  6373,  6377,
    6385,  6388,  6395,  6400,  6409,  6419,  6422,  6429,  6433,  6441,
    6450,  6457,  6467,  6471,  6478,  6484,  6494,  6497,  6504,  6509,
    6521,  6529,  6541,  6549,  6553,  6561,  6565,  6569,  6577,  6585,
    6589,  6593,  6597,  6605,  6613,  6625,  6629,  6637,  6651,  6655,
    6662,  6667,  6675,  6680,  6689,  6697,  6704,  6710,  6717,  6728,
    6734,  6744,  6749,  6755,  6765,  6772,  6776,  6783,  6805,  6830,
    6855,  6883,  6908,  6936,  6940,  6944,  6951,  6956,  6963,  6968,
    6975,  6980,  6992,  6996,  6997,  7010,  7011,  7012,  7013,  7014,
    7015,  7017,  7018,  7019,  7020,  7021,  7022,  7023,  7024,  7025,
    7026,  7030,  7031,  7032,  7033,  7034,  7035,  7036,  7037,  7038,
    7039,  7040,  7041,  7042,  7043,  7044,  7045,  7046,  7047,  7048,
    7049,  7050,  7051,  7052,  7053,  7054,  7055,  7056,  7057,  7058,
    7059,  7060,  7061,  7062,  7063,  7064,  7065,  7066,  7067,  7068,
    7069,  7070,  7071,  7072,  7073,  7074,  7075,  7076,  7077,  7078,
    7079,  7080,  7081,  7082,  7083,  7084,  7085,  7086,  7087,  7088,
    7089,  7090,  7091,  7092,  7093,  7094,  7095,  7096,  7097,  7098,
    7099,  7100,  7101,  7102,  7103,  7104,  7105,  7106,  7107,  7108,
    7109,  7110,  7111,  7112,  7113,  7114,  7115,  7116,  7117,  7118,
    7119,  7120,  7121,  7122,  7123,  7124,  7125,  7126,  7127,  7128,
    7129,  7130,  7131,  7132,  7133,  7134,  7135,  7136,  7137,  7138,
    7139,  7140,  7141,  7142,  7143,  7144,  7145,  7146,  7147,  7148,
    7149,  7150,  7151,  7152,  7153,  7154,  7155,  7156,  7157,  7159,
    7160,  7162,  7163,  7164,  7165,  7166,  7168,  7170,  7171,  7172,
    7173,  7174,  7175,  7176,  7177,  7178,  7179,  7180,  7181,  7182,
    7183,  7184,  7185,  7186,  7187,  7188,  7189,  7190,  7191,  7192,
    7193,  7194,  7195,  7196,  7197,  7198,  7199,  7200,  7201,  7202,
    7203,  7204,  7205,  7206,  7207,  7208,  7209,  7210,  7211,  7212,
    7213,  7214,  7215,  7216,  7217,  7218,  7219,  7220,  7221,  7222,
    7223,  7224,  7225,  7226,  7227,  7228,  7231,  7240
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
  const int jsoniq_parser::yylast_ = 18797;
  const int jsoniq_parser::yynnts_ = 322;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 545;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 341;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 595;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 18062 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7244 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"


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

