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
#line 917 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1053 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"

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
#line 915 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 127: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 914 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 152: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 913 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 371: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 391: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 406: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 419: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 424: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 425: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 431: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 434: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 466: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 472: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "NotExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 569: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 601: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 608: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 619: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 641: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 661: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
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
#line 2871 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"

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
#line 1071 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1075 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1079 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1087 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1093 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1097 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1106 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1112 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1120 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1126 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1137 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1142 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1146 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1151 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl(
        LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1160 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1167 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1174 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1183 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1190 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1198 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1206 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1214 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1225 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1230 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1237 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1244 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1256 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1266 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 1273 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 1280 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1315 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1320 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1328 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1336 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1344 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1349 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1357 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1362 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1370 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1375 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1383 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1388 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1393 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1398 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1411 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1421 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1426 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1434 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1442 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1453 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1460 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1471 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1476 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1484 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1491 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1498 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1507 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1520 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1528 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1535 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1545 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 1552 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1559 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1582 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1588 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1597 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1623 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1624 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1625 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1626 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1627 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1628 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1629 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1631 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1632 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1638 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1646 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1654 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1662 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1669 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1677 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1684 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1689 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1697 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1705 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1719 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1733 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1750 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1755 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1763 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1771 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1782 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1787 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1796 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1801 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1808 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1813 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1823 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1828 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1837 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1843 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1856 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1861 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1869 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1880 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1895 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1907 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1922 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1927 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1945 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1952 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1963 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1968 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1978 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1987 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 1996 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2005 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2017 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2021 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2027 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2031 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2041 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2051 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2064 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2070 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2079 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2084 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2091 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2098 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2110 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2120 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2130 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2141 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2157 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2177 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2181 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2185 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2193 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2197 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2201 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2209 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2214 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2226 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 2233 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 2243 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2276 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2284 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2301 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2309 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2317 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2324 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 2331 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2342 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2351 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2360 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2369 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2382 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2390 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2398 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2406 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2421 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2426 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2434 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2448 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2465 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2490 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2498 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2505 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2516 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2525 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2532 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2537 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2550 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2597 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2611 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2619 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2624 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2632 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2637 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2642 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2650 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2659 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2671 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2681 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2694 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2718 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2725 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2735 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2741 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2750 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2760 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      // this adds on shift-reduce conflict (probably with FTRange expression)
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2768 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2775 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2783 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2795 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2805 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2815 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2825 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2835 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2845 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2855 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2865 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2876 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2885 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2895 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2905 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2921 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2930 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2939 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2947 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2953 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2965 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2973 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2983 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 2991 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3003 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3009 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3022 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3026 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3034 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3038 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3047 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3051 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3055 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3065 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3073 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3080 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3086 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3096 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3100 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3104 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3112 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3120 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3128 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3140 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3148 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3154 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3164 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3170 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3180 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3184 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3194 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3200 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3206 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3212 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3221 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3230 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3239 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3252 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3256 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3264 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3270 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3280 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3288 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3297 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3310 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3317 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3329 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3333 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3345 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3352 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3358 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3367 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3374 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3380 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3391 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3398 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3404 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3422 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3429 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3440 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3447 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3459 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3465 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3477 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3483 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3494 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3500 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3511 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3517 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3528 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3534 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3554 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3558 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3567 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3571 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3578 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3582 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3595 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3599 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 3679 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3683 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3695 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3699 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3710 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3717 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3721 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3730 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3734 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3738 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3746 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3750 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3756 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3762 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3768 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3778 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3786 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3794 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3804 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3814 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3818 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3828 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3832 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3842 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3846 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3856 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3860 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3870 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3874 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3883 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3895 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3899 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3903 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3907 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3917 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3921 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3925 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3945 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3949 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3953 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3957 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3961 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3965 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3989 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3993 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3997 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 4001 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 4012 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 4018 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 4028 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 4034 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 4044 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 4048 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 4052 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 4115 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 4137 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 427:

/* Line 690 of lalr1.cc  */
#line 4165 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4329 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4333 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4343 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4347 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4351 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4355 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4364 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4368 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4372 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4376 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4380 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4385 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4389 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4393 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4402 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4408 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4418 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4426 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4430 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4434 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4442 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4446 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4450 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4454 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4458 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4462 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4467 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4471 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4475 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4479 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4487 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4491 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4495 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4499 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4507 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4514 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4521 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4531 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4535 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4543 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4551 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4555 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4563 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4567 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4575 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4583 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4637 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4641 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 477:

/* Line 690 of lalr1.cc  */
#line 4663 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4669 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4675 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4681 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4691 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4695 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4703 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4711 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4723 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4727 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4735 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4739 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4743 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4751 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 4759 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 4776 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 4784 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 4803 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 4822 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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
#line 4844 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4850 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4861 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4867 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4878 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4893 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4898 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4907 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4911 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4918 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4924 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4930 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4948 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4952 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4959 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4965 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4971 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4978 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4989 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4993 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 5001 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 5005 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 5013 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 5017 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 5021 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 5026 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 5035 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 5039 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 5043 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 5055 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 5060 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 5068 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 5073 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 5081 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 5089 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 5094 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 5099 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 5104 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 5109 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 5125 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 5133 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 5137 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 5154 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 5158 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 5166 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 5174 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 5182 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 5186 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 5194 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 5198 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 5206 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 5214 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 5218 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 5222 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 5227 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 5262 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5268 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5274 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5284 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5288 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5292 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5297 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5301 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5306 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5325 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5331 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5341 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5349 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5357 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5361 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5365 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5369 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5373 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5377 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5381 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5385 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5389 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5393 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5401 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5409 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5413 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5417 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5425 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5432 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5440 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5448 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5452 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5456 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5464 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5468 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5474 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5480 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5484 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5494 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5502 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5506 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5512 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5521 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5530 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5536 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5542 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5552 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5569 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5576 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5618 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5622 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5638 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5653 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5670 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5682 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5692 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5696 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5712 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5728 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5734 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5751 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5756 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5770 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5802 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5811 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5817 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5830 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5844 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5857 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5867 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5876 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5884 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5890 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5908 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5916 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5920 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5927 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5932 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5940 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5944 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5955 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5962 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5966 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5973 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5977 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5986 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5998 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 6002 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 6009 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 6013 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 6021 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 6029 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 6037 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 6041 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 6048 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 6052 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 6060 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 6071 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 6075 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6083 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6095 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 6101 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6110 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6114 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6122 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6126 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6130 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6137 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6141 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6148 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6152 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6160 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6164 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6168 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6172 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6176 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6184 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6192 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6204 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6216 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6220 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6224 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6232 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6238 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6248 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6252 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6256 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6260 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6264 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6268 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6272 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6276 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6284 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6288 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6292 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6296 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6304 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6310 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6320 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6330 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6334 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6342 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 715:

/* Line 690 of lalr1.cc  */
#line 6352 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
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

  case 716:

/* Line 690 of lalr1.cc  */
#line 6363 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6370 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6374 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6381 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6385 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6392 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6397 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6406 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6415 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6419 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6426 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6430 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6438 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6447 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6454 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6464 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6468 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6475 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6481 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6490 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6494 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6501 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6506 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6518 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6526 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6538 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6546 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6550 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6558 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6562 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6566 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6574 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6582 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6586 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6590 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6594 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6602 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6610 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6622 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6626 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6634 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6648 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6652 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6659 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6664 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6672 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6677 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6686 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6691 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)));
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6698 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6705 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6711 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 768:

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

  case 769:

/* Line 690 of lalr1.cc  */
#line 6729 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 770:

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

  case 771:

/* Line 690 of lalr1.cc  */
#line 6745 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6750 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(4) - (2)].expr),
                                        (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 773:

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

  case 774:

/* Line 690 of lalr1.cc  */
#line 6766 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6773 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6777 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 777:

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

  case 778:

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

  case 779:

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

  case 780:

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

  case 781:

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

  case 782:

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

  case 783:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 794:

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

  case 796:

/* Line 690 of lalr1.cc  */
#line 7011 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 7012 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 7013 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 7014 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 7015 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 7017 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 7018 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 7019 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 7020 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 7021 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 7022 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 7023 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 7024 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 7025 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 7026 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 7031 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 7032 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 7033 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 7034 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 7035 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 7036 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 7037 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 7038 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 7039 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 7040 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 7041 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 7042 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 7043 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 7044 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 7045 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 7046 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 7047 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 7048 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 7049 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 7050 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 7051 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 7052 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 7053 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 7054 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 7055 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 7056 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 7057 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 7058 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 7059 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 7060 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 7061 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 7062 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 7063 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 7064 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 7065 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 7066 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 7067 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 7068 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 7069 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 7070 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 7071 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 7072 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 7073 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 7074 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 7075 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 7076 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 7077 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 7078 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 7079 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 7080 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 7081 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 7082 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 7083 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 7084 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 7085 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 7086 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 7087 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 7088 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 7089 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 7090 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 7091 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 7092 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 7093 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 7094 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 7095 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 7096 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 7097 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 7098 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 7099 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 7100 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 7101 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 7102 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 7103 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 7104 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 7105 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 7106 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 7107 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 7108 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 7109 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 7110 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 7111 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 7112 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 7113 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 7114 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 7115 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 7116 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 7117 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 7118 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 7119 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 7120 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 7121 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 7122 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 7123 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 7124 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 7125 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 7126 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 7127 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 7128 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 7129 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 7130 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 7131 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 7132 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 7133 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 7134 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 7135 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 7136 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 7137 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 7138 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 7139 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 7140 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 7141 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 7142 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 7143 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 7144 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 7145 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 7146 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 7147 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 7148 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 7149 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 7150 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 7151 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 7152 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 7153 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 7154 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 7155 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 7156 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 7157 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 7159 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 7160 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 7162 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 7163 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 7164 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 7165 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 7166 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 7168 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 7170 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 7171 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 7172 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 7173 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 7174 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 7175 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 7176 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 7177 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 7178 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 7179 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 7180 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 7181 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 7182 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 7183 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 7184 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 7185 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 7186 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 7187 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 7188 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 7189 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 7190 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 7191 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 7192 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 7193 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 7194 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 7195 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 7196 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 7197 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 7198 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 7199 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 7200 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 7201 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 7202 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 7203 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 7204 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 7205 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 7206 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 7207 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 7208 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 7209 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 7210 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 7211 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 7212 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 7213 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 7214 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 7215 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 7216 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 7217 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 7218 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7219 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 7220 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 7221 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 7222 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 7223 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 7224 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 7225 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 7226 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 7227 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 7228 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 7231 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 7240 "/home/colea/xquery_bzr/feature-empty_object/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12113 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"
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
      5092,  8430,  8430,  8430,  8430, -1487, -1487,   322,   413, -1487,
     577,   432, -1487, -1487, -1487,   476, -1487, -1487, -1487,   494,
   -1487,   501,   719,   535,   541,   857, -1487,    76, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,   567, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487,    52, -1487,   612, -1487,   616,   655, -1487,
      11, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487,   688, -1487, -1487, -1487, -1487, -1487, -1487, -1487,   629,
   -1487, -1487, -1487, -1487, -1487, 18628, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487,   743, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,  5710, 10551, 10854, 18628, -1487,
   -1487,   750, -1487, -1487, -1487, -1487,   758, -1487, -1487, -1487,
    7222, -1487,  7521, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,   772, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487,    88,   763,   773, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, 14490, -1487,
    6014, -1487, 14793,   266, -1487, -1487, -1487, -1487, -1487, -1487,
     877, -1487,   713,   751,   752, -1487, -1487,   844,   851, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487,   741, -1487, 14187, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, 11157, 11460, 11763, -1487,  5401,  7824,  1015, -1487,
    8733, -1487, -1487,   721,    87, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,    89,
   -1487, -1487, -1487, -1487, -1487, -1487,   520, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487,  8430, -1487, -1487, -1487, -1487,
       8, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
     164, -1487,   859, -1487, -1487, -1487,   191, -1487,   115, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487,   880,   959, -1487, -1487,
     826,   798,   954,   659,   305,   746,    39, -1487,  1005,   856,
     957,   958, 13278, -1487,   865, -1487, -1487,    13, -1487, -1487,
   -1487, -1487,   670, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487,   915,   905, -1487, -1487,
   -1487, -1487, -1487,   878, -1487,  8430,   881,   882,   883,  8430,
     353,   353,  1037,   726,   727,   593, 18920, 18628,   -14,  1023,
   18628,   917,   953,   702,  7222,   813,   821, 18628, 18628,   769,
     841,    38, -1487, -1487, -1487,  7222,  8430,  8430, 12672,   258,
     926, 12672,  1083,   192,   351, 18628,   965,   941,   978, -1487,
   12672, 18628,  8430, 12672, 12672, 18628,  8430,   943,   945, 12672,
   18628, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,   960,
   -1487, 18628, -1487, -1487,   916,  8127,   980,    34,   982,   915,
     948,   949,   950, 18628,  5710, -1487,   946,   201, -1487,   457,
   -1487,   121,  1074, 12672, 12672,   168, -1487, -1487, -1487,  1095,
   12672,   896, -1487,  1084,  1087, 12672, 12975, 15096,   670, 12672,
   12975,  6318,    25,     4, 12672, 15096,   314, 12672,   884,   888,
   18628,   925,   930, 12672, 12672,  8430,   867, -1487, -1487,    53,
   -1487,    46, 12672,   887,  7824, -1487, -1487, -1487, -1487, -1487,
     577,   857,    91,    93,  1123,  9036,  3526,  9339,  3846,   629,
   -1487, -1487,   270,   629, -1487, 12672,  4480, -1487,  1008, -1487,
      76,   962,   956,   963,  8430, 12672, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, 18628, -1487,   840,   843, 18628,
    1012, 13581, 13581, -1487, -1487, -1487, -1487, -1487, -1487, 13884,
    1063, 13884, 13884, 13884, 13884, 13884, 13884, 13884, 13884, 13884,
   13884, 13884, 13884,   899,  1045,  1046,  1047, -1487, -1487, -1487,
   15096, 12066, -1487,  6620, 12672,  9945,   987, -1487,   993, 10248,
   -1487, -1487, -1487, -1487,   293, -1487,   294, -1487, -1487, -1487,
   -1487, -1487, -1487,  1038,  1039,   535,  1116, -1487, -1487, 18920,
    1007,   694, 18628,   986,   988,  1007,  1037,  1026,  1018, -1487,
   -1487, -1487,   538,   904,  1062,   855, 18628,  1017, 12672,  1044,
   18628, 18628, -1487,  1031,   981,   983,   110, 18628,  1071,   320,
   -1487,  8430, -1487,   123, -1487,  7222,  1073,  1127,  7222,  1037,
    1077,   356, 18628, 12672,    76,   209,    16, -1487,    48,   991,
     136,   139,  1024, -1487,   992,  8430,  8430,   232,   506, 12672,
      24, -1487, -1487, 12672,  6318, -1487, 12672, 12672, 12672, 12672,
   -1487, 12672, -1487, 12672, -1487, 18628,  1074, -1487,   452,   241,
     302, -1487, -1487, -1487,   363, -1487,    12,   514, -1487, -1487,
     670,   372,   374,   299,   283, 12672, 12672,  1085,   662, 12672,
     938, 15399,   947,   273, -1487,  1041, -1487, -1487,   990,   144,
    8127,   397,  4789,   867, -1487, -1487, -1487,   944, 12672, -1487,
     721,   847,  1154,   180, -1487, -1487,    94, -1487, -1487, -1487,
     105, -1487,   103, -1487, -1487, -1487, -1487, -1487,  4163, -1487,
   -1487, -1487, 18628,  1016, 12672,  1070, -1487, -1487, -1487,  1086,
   -1487,    36, -1487, -1487,  1086, 18628,    45,   959, -1487, -1487,
     211, -1487,   305,   305,    -5,   746,   746,   746,   746,    39,
      39, -1487, -1487, 17164, 17164, 18628, 18628, -1487, -1487,   416,
   -1487, -1487, -1487, -1487,   230, -1487, -1487, -1487,   483, -1487,
   -1487, -1487,   529,   353, -1487, -1487,   528,   689,   647, -1487,
     535, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487,  1007, -1487,  1057, 17458,  1048, 12672, -1487, -1487, -1487,
    1101,  1037,  1037,  1007, -1487,   886,  1037,   710, 18628,   588,
     709,  1168, -1487, -1487,   907,   597, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,   538,    96,   968,
     676, 12672, -1487, 18628,  1107,   898,  1037, -1487, -1487,  1050,
    1101, 17164,  1088,  1111,  1022,  1011,  1079,  1037,  1053,  1090,
    1120,  1037, 17164, 12672,    67, -1487, -1487, -1487,  1064,  1099,
   12672, 12672,  1076, -1487,  1119,  1121,  8430, -1487,  1040,  1042,
    1072, 12672,  1089,  1043, 12672, -1487,  1106,  1109, -1487,   152,
     179,   198,  1195, -1487,   543, -1487,    98,  1081, -1487, -1487,
    1205, -1487,  1208, -1487,   -68, 12672, 12672, 12672,   325, 12672,
   12672, 12672, 12672, 12672,  1141, -1487, 12672, 12672, -1487, 12672,
   12672,   486, 15096,  1122, 12672, 12672, -1487,  9642,   111,   989,
   -1487, -1487, -1487, -1487, -1487, -1487,   251, -1487, -1487, 12672,
   -1487,   108,    62,   103,  9339,  3846,  9339,  1159, -1487, -1487,
   12672,   812,  1135, -1487, 18628,  1136, -1487, 18336,  1117,  1126,
   12672,   -57,  1098,    37,    58,   994, -1487, -1487,   770,    45,
   12672,   211,   461,   282, -1487,   964,   472,   995,   984, -1487,
   -1487,   821, -1487,   979,   661,  1100,  1102,  1103,  1104,  1105,
    1112,  1113,  1114,  1115,  1118,  1124, 15988,  1125,  1128,  1129,
    1130,  1131,  1132, -1487,   634, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,  1133, -1487,
   -1487, -1487, -1487, 12369, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487,   768, -1487,  1224, 17458,   868, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,   972, -1487, -1487,
    1228, -1487, -1487, -1487, -1487, -1487,   674,  1238, -1487,   762,
   -1487, -1487, -1487,  1100,  1102,  1103,  1105,  1112,  1113,  1114,
    1115,  1118,  1128, -1487,   634,   634, 15096,   976,   966, -1487,
    1101,    96,  1060,  1082,  8430, -1487, -1487, -1487, 17164, -1487,
    8430,  1037,  1167, -1487, -1487, -1487,  1037,  1167, -1487, -1487,
   12672,  1137,  8430, 18628, -1487, -1487, 12672, 12672,   849, -1487,
     347,   852, -1487, 16282,   863, -1487,   869, -1487,  1091, -1487,
   -1487,  8430, -1487, 12672, -1487, -1487, 12672, 12672,  1096,  1119,
    1194, -1487,  1163, -1487,   757, -1487, -1487,  1292, -1487, -1487,
    8430, 18628, -1487,   842, -1487, -1487, -1487,  8430,  1108,  1134,
    1066,  1067, -1487, -1487, -1487,  1069,  1075, -1487, -1487, -1487,
    1202, -1487,   996, -1487, -1487, -1487,  1058, 12672,   542, 18628,
    1139, -1487,  1145,  1151,  1152,  1157, -1487,   859,   590,  4789,
     989, -1487,  9642,  4789, -1487, -1487,  1154,   430, -1487, -1487,
   -1487,  1135, -1487,  1037, -1487,   891, -1487,    55,  1206, -1487,
   12672,   608,  1070, 18628, -1487,   343, 18628, -1487, 12672,  1166,
   12672,  1187, 12672,   237,  1170, 12672,  1171, -1487,  1198,  1203,
   12672, 18628,   961,  1243, -1487, -1487, -1487,   442,  1140, -1487,
     211,  1068, -1487, -1487,   -55, -1487,   162,    -7,  1078,   211,
     162, 13884, -1487,   556, -1487, -1487, -1487, -1487, -1487, -1487,
     211,  1174,  1049,   904,    -7, -1487, -1487,  1033,  1249, -1487,
   -1487, -1487,  1142,   330, 17752, 15694,  1143,  6921, 18628, 18628,
    1144, 18044,  1146, -1487,  1147,  1149,  1150,  1156,  1158,  1160,
    1161, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487,  1301,   -10,  1311,   -10,  1092,  1233,
   -1487, -1487,  1176, 18628,  1093, -1487, -1487, 15096, -1487,  1165,
   -1487,  1218,  1225,  1255,  1037,  1167, -1487, 12672,  1169, -1487,
   -1487, -1487,  1172, -1487,   354, 12672,  8430,  1173,   479, -1487,
   18628,   269, -1487, 16576,   471, -1487, 16870,  1175, -1487, -1487,
    1178, -1487, -1487, -1487, 12672,   873,  1195, 18628,   923, -1487,
    1179,  1195, 18628, -1487,  1180, -1487, -1487, 12672, 12672, 12672,
   12672,  1032, 12672, 12672, -1487, 12672, -1487, 12672, 12672, 12672,
   12672,  9642,   274, -1487, -1487, -1487, -1487, -1487,  1206, -1487,
   -1487, -1487,  1037, 12672, -1487,  1214, -1487, -1487, 12672,  1210,
   -1487, -1487, 12672, -1487,   480, -1487, 12672,  1213, 12672, -1487,
   12672, 18628, 18628, -1487,   804, -1487, 12672, -1487, -1487, -1487,
    1181, 13884, -1487, -1487, -1487, -1487, -1487,   421, 13884, 13884,
     663, -1487,   995, -1487,   519, -1487,   984,   211,  1215, -1487,
   -1487,  1094, -1487, -1487, -1487, -1487, -1487, -1487,  1182,  1183,
   -1487,   530,   546,  1273,  1184, -1487,   554, -1487,  1185, -1487,
    1186,  1188,  1189, -1487, -1487,   562,   569, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487,   523,   523, -1487,   -10,
   -1487, -1487,   579, -1487,  1347,    28,  1282,  1192, 15096,   -35,
    1097,  1211, -1487,  9642, 12672,  1037, -1487, -1487, -1487, 12672,
   12672, -1487, -1487, -1487,  9642,  9642,  1287,  8430, 17164, 18628,
     657, 18628, 12672, 18628,   683,  9642, -1487,   536,   306,  1195,
   18628, -1487,  1190,  1195, -1487, -1487, -1487, -1487, -1487, 12672,
   -1487, -1487, -1487, -1487,   203,   226,   235, 12672, -1487, -1487,
   -1487,  1277, 12672, -1487, 12672, -1487, 12672,  1236, -1487, 12672,
   -1487, -1487, -1487,  1332, -1487, -1487, -1487,   746, 13884, 13884,
      -5,   705, -1487, -1487, -1487, -1487, -1487, -1487, 12672, -1487,
   -1487, -1487, 18628, -1487, 18628, -1487, 17164, -1487, 17164,  1293,
   -1487, -1487, -1487, -1487, 18628, -1487, 18628, -1487, -1487, -1487,
   -1487,  1358, -1487, -1487, -1487,  1148,  1283, -1487, -1487,  1284,
   -1487,    74, 18628,  1274,  1191, 18628, 15096, -1487, -1487,  1167,
   -1487, -1487, 17164, -1487, -1487, -1487,  1299, 12672,  1209, -1487,
    1303,  9642, -1487, 18628,   601,   598, -1487,  1197,  1195, -1487,
    1200, -1487,  1201,  1119,  1121,   460, -1487,  1277, -1487, -1487,
   12672, -1487,  1285,    -5,    -5, 13884,   462,  1216,  1217,  1256,
    1221,  1222, -1487, -1487, 17164,  1223,  1226, -1487, -1487,  1282,
   15096, -1487,  1206,  1110, 18628,  1288,  1196,  1284,   685, 17164,
    8430, 17164,  1229, -1487, -1487,  1309,   765, -1487, -1487, -1487,
   -1487,  1231,   680, -1487, -1487, -1487,  1219, -1487,  9642,   874,
   -1487, -1487, -1487, 18628,    -5, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, 12672,  1138, 18628,
    1294,  8430,   697, -1487, -1487,   714, 12672, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487,  1295, -1487, -1487,  1153,  1155, 18628,
   -1487, -1487, 12672,  9642, 18628,  1164, 12672,  1177,  1232, 15096,
   -1487, 15096,  9642, -1487,  1227,  1162, 18628,  1199,  1304, 18628,
    1193, 15096, -1487
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   170,   170,   170,     0,   812,  1007,   122,   124,   609,
     904,   913,   853,   817,   815,   797,   905,   908,   860,   821,
     798,   800,   260,   914,   801,   911,   882,   862,   837,   799,
     857,   858,   909,   906,   856,   803,   912,   804,   805,   949,
     961,   948,   854,   873,   867,   806,   855,   808,   807,   950,
     891,   892,   859,   834,   971,   972,   973,   974,   975,   976,
     977,   978,   979,   980,   981,   995,  1002,   881,   877,   868,
     848,   796,   876,   884,   893,   996,   872,   463,   849,   850,
     907,   997,  1003,   869,   886,     0,   472,   471,   465,   879,
     814,   870,   871,   900,   874,   890,   899,  1001,  1004,   820,
     861,   902,   464,   889,   895,     0,     0,     0,     0,   400,
     887,   898,   903,   901,   880,   866,   951,   864,   865,   998,
       0,   399,     0,   999,  1005,   896,   851,   875,  1000,   213,
     897,   878,   885,   894,   888,   952,   842,   847,   846,   845,
     844,   843,   809,   863,     0,   813,     0,   910,   835,   462,
     466,   467,   942,   941,   943,   819,   818,   838,     0,   802,
       0,   945,     0,     0,   841,   883,   940,   947,   946,   939,
     839,   944,   956,   957,   954,   955,   953,   810,   958,   959,
     960,   930,   929,   916,   833,   826,   923,   919,   836,   832,
     931,   261,   822,   823,   816,   825,   928,   927,   924,   920,
     937,   938,   936,   926,   922,   915,   824,   935,   934,   828,
     830,   829,   921,   925,   917,   831,   918,   827,   933,   982,
     983,   984,   985,   986,   987,   963,   964,   962,   968,   969,
     970,   965,   966,   967,   840,   988,   989,   990,   991,   992,
     993,   994,     0,     0,     0,  1006,   167,   167,     0,     2,
     167,     9,    11,    25,     0,    30,    33,    38,    39,    40,
      41,    42,    43,    44,    34,    60,    61,    35,    36,     0,
      78,    81,    82,    37,    83,    84,     0,   120,    85,    86,
      87,    88,    20,   164,   165,   166,   173,   176,   454,   177,
       0,   178,   179,   180,   181,   182,   183,   184,   187,   188,
       0,   214,   222,   217,   249,   255,     0,   247,     0,   248,
     224,   218,   186,   219,   185,   220,   223,   357,   359,   361,
     363,   365,   367,   371,   373,   376,   381,   384,   387,   389,
     391,   393,     0,   397,   404,   403,   405,     0,   420,   406,
     425,   426,   427,   434,   445,   459,   461,   446,   447,   448,
     451,   452,   449,   453,   481,   482,   450,   485,   487,   488,
     489,   486,   534,   535,   536,   537,   538,   539,   540,   460,
      45,   225,   226,   228,   227,   229,   221,   456,   457,   458,
     455,   231,   234,   230,   232,   233,     0,   795,   811,   904,
     913,   911,   813,     0,   168,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,   130,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,   280,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   194,   797,   821,   800,   852,   914,   801,   862,   803,
     873,   806,   808,   807,   891,   796,   850,   874,   898,   951,
     952,   839,   956,   957,   954,   810,   958,   932,   823,   468,
     795,     0,   793,   764,     0,     0,   214,     0,     0,   794,
     801,   808,   807,     0,     0,   757,   958,     0,   222,     0,
     469,     0,   501,     0,     0,     0,   794,   423,   424,     0,
       0,     0,   530,     0,     0,   802,   945,     0,   778,   802,
     945,     0,     0,     0,   802,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   362,   759,     0,
     761,     0,     0,     0,   167,     3,     4,     1,    10,    12,
       0,     0,     0,     0,     6,   167,     0,   167,     0,     0,
     121,   174,     0,     0,   192,     0,     0,   201,     0,   260,
       0,     0,     0,     0,     0,     0,   261,   206,   235,   254,
     250,   256,   251,   253,   252,     0,   259,     0,     0,     0,
       0,     0,     0,   408,   413,   412,   411,   410,   409,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   402,   401,   398,
       0,     0,   421,     0,     0,     0,   435,   442,     0,     0,
     542,   544,   548,   550,     0,   126,     0,   792,    49,    46,
      47,    50,    51,     0,     0,     0,     0,    52,    53,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
     617,   618,     0,   105,   144,     0,     0,   114,     0,     0,
       0,     0,   129,     0,     0,     0,     0,     0,   136,     0,
     140,   170,   484,     0,    62,     0,    71,     0,     0,     0,
      63,     0,     0,     0,     0,     0,     0,   328,     0,     0,
       0,     0,     0,   607,     0,     0,     0,     0,   196,     0,
       0,   190,   189,     0,     0,   763,     0,     0,     0,     0,
     468,     0,   758,     0,   470,   502,   501,   498,     0,     0,
       0,   532,   531,   422,     0,   529,     0,     0,   629,   630,
     777,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   635,     0,   204,   205,     0,     0,
       0,     0,     0,   209,   210,   760,   762,     0,     0,     5,
      26,     0,    27,     0,     7,    31,     0,    17,     8,    32,
       0,    21,   904,    79,    18,    80,    22,   195,     0,   193,
     215,   216,     0,     0,     0,     0,   207,   236,   297,   258,
     262,     0,   237,   238,   257,     0,     0,   358,   360,   364,
       0,   368,   375,   374,   372,   378,   379,   380,   377,   382,
     383,   386,   385,     0,     0,     0,     0,   407,   418,     0,
     440,   439,   441,   438,     0,   477,   436,   479,     0,   443,
     483,   475,     0,     0,   123,   125,     0,     0,     0,   104,
       0,    94,    96,    97,    98,    99,   101,   102,   103,    95,
     100,    90,    91,     0,     0,   110,     0,   106,   108,   109,
     116,     0,     0,    89,    48,     0,     0,     0,     0,     0,
       0,     0,   707,   712,     0,     0,   708,   742,   695,   697,
     698,   699,   701,   703,   702,   700,   704,     0,     0,     0,
       0,     0,   113,     0,   146,     0,     0,   547,   541,     0,
     142,     0,     0,   137,     0,     0,     0,     0,     0,     0,
      64,     0,     0,     0,     0,   278,   284,   281,     0,     0,
       0,     0,     0,   546,     0,     0,     0,   414,     0,     0,
       0,     0,   197,     0,     0,   766,     0,     0,   765,     0,
       0,     0,   501,   499,     0,   490,     0,     0,   473,   474,
       0,    13,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   772,   773,     0,     0,   780,     0,
     802,     0,     0,     0,     0,     0,   202,     0,     0,     0,
     431,   432,   433,   430,   643,   429,     0,   428,   211,     0,
     776,     0,     0,     0,   167,     0,   167,     0,   175,   246,
       0,   312,   308,   310,     0,   298,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,     0,   245,
       0,     0,     0,     0,   673,   369,   646,   650,   652,   654,
     656,   659,   666,   667,   675,   797,   798,   800,   914,   799,
     803,   804,   805,   806,   796,   563,     0,   809,   802,   789,
     791,   787,   565,   388,   553,   560,   561,   582,   573,   581,
     580,   579,   578,   575,   577,   574,   576,   566,   610,   611,
     567,   568,   783,   784,   785,   571,   390,   392,   395,   572,
     394,   419,   444,     0,   437,   476,   127,    58,    59,    56,
      57,   133,   132,     0,    92,     0,     0,     0,   111,   112,
     117,    76,    77,    54,    55,    75,   713,     0,   716,   743,
       0,   706,   705,   710,   709,   741,     0,     0,   718,     0,
     714,   717,   696,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   145,   148,   150,     0,     0,     0,   115,
     118,     0,     0,     0,   170,   143,   138,   141,     0,   191,
       0,     0,    73,    67,    70,    69,     0,    65,   552,   282,
       0,     0,   170,     0,   326,   330,     0,     0,     0,   333,
       0,     0,   339,     0,     0,   346,     0,   350,     0,   416,
     415,   170,   198,     0,   200,   327,     0,     0,     0,     0,
       0,   502,     0,   492,     0,   525,   522,     0,   526,   527,
       0,     0,   521,     0,   496,   524,   523,     0,     0,     0,
       0,     0,   622,   623,   619,     0,     0,   627,   628,   624,
     769,   770,     0,   633,   779,   631,     0,     0,     0,     0,
       0,   637,   801,   808,   807,   958,   203,     0,     0,     0,
     638,   639,     0,     0,   212,   775,    28,     0,    19,    23,
      24,   309,   321,     0,   322,     0,   313,   314,   315,   316,
       0,   301,     0,     0,   264,     0,     0,   265,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,     0,     0,
       0,     0,   291,     0,   288,   293,   244,     0,     0,   657,
     670,     0,   366,   370,     0,   689,     0,     0,     0,     0,
       0,     0,   645,   647,   648,   684,   685,   686,   688,   687,
       0,     0,   661,   660,     0,   664,   668,   682,   680,   679,
     672,   676,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   556,     0,     0,     0,     0,     0,     0,
       0,   557,   559,   558,   554,   396,   478,   480,   135,   134,
      93,   107,   730,   711,     0,   735,     0,   735,   724,   719,
     149,   151,     0,     0,     0,   119,   147,     0,    29,     0,
     139,     0,     0,    72,     0,    66,   283,     0,     0,   329,
     331,   336,     0,   334,     0,     0,     0,     0,     0,   340,
       0,     0,   354,     0,     0,   347,     0,     0,   351,   417,
       0,   199,   767,   768,     0,     0,   501,     0,     0,   533,
       0,   501,     0,   497,     0,    14,    16,     0,     0,     0,
       0,     0,     0,     0,   782,     0,   636,     0,     0,     0,
       0,     0,     0,   640,   644,   325,   323,   324,   317,   318,
     319,   311,     0,     0,   306,     0,   300,   263,     0,     0,
     277,   269,     0,   273,     0,   267,     0,     0,     0,   286,
       0,     0,     0,   243,   289,   292,     0,   674,   665,   671,
       0,     0,   744,   745,   755,   754,   753,     0,     0,     0,
       0,   746,   651,   752,     0,   649,   653,     0,     0,   658,
     662,     0,   683,   678,   681,   677,   589,   584,     0,     0,
     599,     0,     0,     0,     0,   569,     0,   587,     0,   590,
       0,     0,     0,   588,   593,     0,     0,   562,   615,   555,
     583,   788,   790,   786,   564,   731,     0,     0,   729,   736,
     737,   733,     0,   728,     0,   726,     0,     0,     0,     0,
       0,     0,   543,     0,     0,     0,    68,   285,   549,     0,
       0,   337,   341,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   545,     0,     0,   501,
       0,   528,     0,   501,   551,   620,   621,   625,   626,     0,
     774,   632,   781,   634,     0,     0,     0,     0,   641,   320,
     307,   302,     0,   266,     0,   275,     0,     0,   271,     0,
     274,   287,   295,   296,   290,   242,   669,   756,     0,     0,
     748,     0,   694,   693,   692,   691,   690,   655,     0,   747,
     585,   586,     0,   603,     0,   600,     0,   612,     0,     0,
     592,   591,   598,   606,     0,   596,     0,   594,   740,   739,
     738,     0,   732,   725,   723,     0,   720,   721,   715,   152,
     154,   156,     0,     0,     0,     0,     0,   208,   356,    74,
     332,   338,     0,   352,   348,   355,     0,     0,     0,   342,
       0,     0,   344,     0,   511,   505,   500,     0,   501,   491,
       0,   771,     0,     0,     0,     0,   305,   303,   270,   268,
       0,   276,     0,   750,   749,     0,     0,     0,     0,   607,
       0,     0,   613,   570,     0,     0,     0,   734,   727,     0,
       0,   158,   157,     0,     0,     0,     0,   153,     0,     0,
       0,     0,     0,   519,   513,     0,   512,   514,   520,   517,
     507,     0,   506,   508,   518,   493,     0,   494,     0,     0,
     642,   304,   272,     0,   751,   663,   604,   605,   608,   601,
     602,   614,   597,   595,   722,   155,   159,     0,     0,     0,
       0,     0,     0,   345,   343,     0,     0,   504,   515,   516,
     503,   509,   510,   495,     0,   294,   160,     0,     0,     0,
     353,   349,     0,     0,     0,     0,     0,     0,     0,     0,
     162,     0,     0,   161,     0,     0,     0,     0,     0,     0,
       0,     0,   163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1487, -1487,  -194,  -183, -1487,  1204,  1207, -1487,  1220,  -476,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
    -888, -1487, -1487, -1487, -1487,  -203,  -509, -1487,   771,    84,
   -1487, -1487, -1487, -1487, -1487,   323,   568, -1487, -1487,     9,
     -48,  1051, -1487,  1006, -1487, -1487,  -569, -1487,   522, -1487,
     281, -1487,  -228,  -281, -1487,  -474, -1487,    22,    95,    33,
    -272,  -164, -1487,  -781, -1487, -1487,   390, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487,   679, -1487,   -95,
    1766,     0, -1487, -1487, -1487, -1487,   414, -1487, -1487,  -290,
   -1487,     5, -1487, -1487,   860,  -958,  -756,  -749, -1487, -1487,
     766, -1487, -1487,   -29,   159, -1487, -1487, -1487,   187, -1486,
   -1487,   451,   194, -1487, -1487,   195, -1211, -1487,   985,   295,
   -1487, -1487,   291,  -913, -1487, -1487,   289, -1487, -1487, -1161,
   -1156, -1487,   286, -1345, -1487, -1487,   890,  -147, -1487,   875,
     885, -1487, -1487,  -594,   424,  -576,   420,   427, -1487, -1487,
   -1487,   652, -1487, -1487,  1212, -1487, -1487, -1487, -1487,  -755,
    -311,  -600, -1487, -1487,   229, -1487,  -140, -1487,   853, -1487,
    -357, -1487, -1487,   861,   862, -1487, -1487, -1487, -1487,   854,
   -1487, -1487, -1487, -1487,  -905, -1487,   284, -1487,   761,  -703,
   -1487, -1487, -1487, -1487, -1487,  -253,  -244, -1135,  -886, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
    -681,  -783,   -99,  -787, -1487, -1487, -1487,  -830, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487,   160,   161,  -672,  -139,
    -581, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,
   -1487, -1487,   257, -1487, -1487,   247, -1487,   249,  -969, -1487,
   -1487, -1487,   199,   183,     3,   475, -1487, -1487, -1487, -1487,
   -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487, -1487,   196,
   -1487, -1487, -1487,    10,   469,   615, -1487, -1487, -1487, -1487,
   -1487,   384, -1487, -1487, -1459, -1487, -1487, -1487,  -489, -1487,
     147, -1487,   -24, -1487, -1487, -1487, -1487, -1252, -1487,   206,
   -1487, -1487, -1487, -1487, -1487,  -107, -1487, -1487, -1487, -1487,
   -1487,  -827, -1487, -1487, -1487,  -364,  -105,   252,  1030, -1487
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   248,   566,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
    1162,   689,   266,   267,   268,   269,   270,   271,   861,   862,
     863,   272,   273,   274,   867,   868,   869,   275,   420,   276,
     277,   634,   278,   422,   423,   424,   430,   679,   680,   279,
    1143,   280,  1659,  1660,   281,   282,   283,   393,   284,   285,
     286,   287,   288,   682,   289,   290,   451,   291,   292,   293,
     294,   295,   296,   577,   297,   298,   763,   764,   299,   300,
     301,   498,   303,   578,   590,  1028,  1029,   304,   579,   305,
     581,   499,   307,   308,   799,   800,  1292,   437,   309,   438,
     439,   806,  1293,  1294,  1295,   582,   583,  1015,  1016,  1454,
     584,  1012,  1013,  1266,  1267,  1268,  1269,   310,   696,   697,
     311,  1178,  1179,  1394,   312,  1181,  1182,   313,   314,  1184,
    1185,  1186,  1187,  1401,   315,   316,   317,   318,   319,   320,
     321,  1302,   322,   323,   324,   325,   326,   327,   328,   329,
     330,  1087,   331,   332,   333,   334,   599,   335,   336,   337,
     338,   339,   340,   341,   994,   995,   342,   626,   627,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   838,
     353,   354,   355,   356,   357,   358,  1213,   726,   727,   728,
    1686,  1741,  1742,  1735,  1736,  1743,  1737,  1214,  1215,   359,
     360,  1216,   361,   362,   363,   364,   365,   366,   367,   368,
     924,  1402,  1354,  1064,  1516,  1065,  1088,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,   702,  1708,
     369,  1077,  1078,  1079,  1080,   370,   371,   372,   373,   374,
     375,   753,   754,   376,  1250,  1251,  1598,   996,  1035,  1312,
    1313,  1036,  1037,  1038,  1039,  1040,  1322,  1499,  1500,  1041,
    1325,  1042,  1480,  1043,  1044,  1330,  1331,  1505,  1503,  1314,
    1315,  1316,  1317,  1625,   663,   888,   889,   890,   891,   892,
     893,  1130,  1547,  1656,  1131,  1545,  1654,   894,  1367,  1542,
    1538,  1539,  1540,   895,   896,  1318,  1326,  1490,  1319,  1486,
    1303,   377,   378,   379,   380,   487,   381,   382,   383,   384,
     385,  1081,  1082,  1083,  1084,  1163,   488,   386,   387,   388
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -933;
  const short int
  jsoniq_parser::yytable_[] =
  {
       302,   302,   302,   302,   302,   306,   306,   306,   306,   306,
     814,   497,   501,   561,   536,   505,   580,   932,   518,   421,
     827,  1180,   526,   954,   396,   397,   622,   942,  1405,   815,
     816,   817,   818,  1167,   395,   395,   395,   399,   638,  1415,
    1063,  1086,   832,   635,   635,  1021,   537,   554,   783,   785,
     553,  1212,  1022,   523,   554,  1033,  1449,  1450,  1570,  1274,
     556,  1574,  1298,   545,   546,     7,     8,  1102,  1144,   686,
     690,  1145,  1501,  1018,  1281,   558,   848,  1107,  1423,   775,
     779,   777,   781,   784,   786,  1662,   406,  1657,   554,   445,
     554,  1487,   554,  1278,   554,   554,   394,   394,   394,   398,
     402,   403,  1025,   404,   405,   302,   554,  1205,  1206,   554,
     306,   554,   554,   714,   409,  1696,   585,   563,   586,   511,
    1023,   408,   554,   561,   554,   929,  1487,   561,  1156,  1536,
       7,     8,   922,   929,  1019,  1019,  1133,   554,   485,  1168,
     554,  1134,  1135,   714,   922,   554,   960,   539,   541,   713,
    1136,   406,   669,   554,   922,   565,   602,  1137,   647,  1138,
    1139,   407,   565,  1263,  -171,   554,  1482,   446,  1140,   621,
     922,  1220,   441,  1221,   603,  1171,   731,  1257,   611,   409,
     554,   778,  1263,   587,   410,  1265,  1020,  1282,   588,  1110,
     562,   648,   612,   122,  1537,  1141,   435,  1663,   931,   554,
     484,   564,   554,  1207,   554,   961,  1483,   930,  1285,   580,
     554,  1751,  1170,   561,  1003,   944,   411,   412,  1007,   565,
     565,   715,   637,   436,  1208,   414,  1209,   554,   560,  1155,
     565,   554,   565,   554,   568,   589,   554,  1599,   569,   447,
     448,     9,   554,   570,   746,   565,   302,   302,   565,  1202,
     302,   306,   306,   565,  1210,   306,  1488,  1489,   108,  1405,
    1764,   565,   571,   783,   785,   745,  1026,  1283,  1398,  1344,
    -172,   554,  1279,   565,  1284,   120,  1033,  1033,  1385,  1664,
     555,  1103,   557,  1423,   770,   302,   772,  1004,   565,   415,
     306,  1488,   874,  1655,   775,   779,  1211,   909,  1006,  1212,
     562,  1256,   796,   554,   562,   512,  1027,   565,  1212,   658,
     565,   724,   565,   915,   144,  1457,   436,   436,   565,  1344,
     673,  1144,  1359,    77,  1145,   920,   934,  1728,  1142,   935,
     416,  1479,   670,   676,   987,   565,   683,   479,    88,   565,
     671,   565,  1198,  1286,   565,   695,   732,   436,   700,   701,
     565,  -171,   776,   780,   707,   685,   436,   489,   771,   773,
     502,   769,   572,   102,   554,   573,   766,  1030,   788,  1199,
    1031,   765,   506,   560,   509,  1380,  1135,   740,   677,   565,
     574,   637,   983,     9,  1772,   748,  1775,  1466,  1200,   722,
     562,   122,   714,  1692,  1139,   302,   928,   417,   554,   302,
     306,  1684,   843,   843,   306,   418,   575,  1252,   729,   730,
     749,   565,   489,   419,   744,   734,  1693,   554,  1092,   940,
    1059,  1060,  1061,   713,   605,  1694,   302,   302,   957,   912,
    1597,   306,   306,   149,   150,   151,   623,  1484,  1300,   759,
     761,  1019,   302,   554,  1485,   808,   302,   306,   678,  1395,
    1721,   306,   922,  1034,   606,   576,  1395,  -172,  1567,   399,
     399,   554,   122,   554,  1253,    77,   687,   607,   964,  1375,
     968,   624,   565,   625,  1618,   399,   653,  1032,   654,   399,
      88,   400,  1568,   844,   845,   302,  1096,  1253,   561,   958,
     306,     9,  1685,  1458,   302,   783,   785,   783,   527,   306,
     568,   923,   608,   528,   569,   102,   565,  1111,  1112,   570,
     913,  1766,  1115,  1212,   688,   984,  1008,   436,   833,  1459,
    1507,   674,   675,   973,  1360,   565,   829,   399,   571,   834,
    1258,  1259,  1260,  1749,  1467,   302,  1396,   699,   656,   972,
     306,   704,  1153,  1560,   302,  1033,  1372,     7,     8,   306,
     959,   565,  1515,  1619,  1033,   302,   302,   302,   302,   421,
     306,   306,   306,   306,  1225,  1033,  1226,  1001,   760,   565,
    1304,   565,   401,    77,   302,   149,   150,   151,  1019,   306,
     916,  1395,  1005,   919,   989,   955,   773,   529,    88,   484,
    1455,  1571,  1093,  1405,   877,   425,   878,   965,   966,   969,
     970,   657,   922,  1091,     7,     8,  1733,  1205,   623,   947,
    1205,   981,   967,   102,   971,   402,   403,  1030,   404,   405,
    1031,  1364,   949,   950,   951,   406,   761,  1739,   572,  1477,
    1606,   573,   426,   568,   559,   407,   408,   569,  1093,  1632,
     879,   122,   570,   624,  1305,   625,   723,  1750,   962,  1755,
     427,   941,   956,   409,  1304,  1634,  1683,   428,   410,   646,
    1572,   571,   650,  1638,   623,   988,   506,  1669,  1565,   664,
     665,  1644,   575,  1094,  1034,  1034,  1203,   506,  1646,  1097,
     602,   302,  1366,   149,   150,   151,   306,   691,  1651,  1205,
     411,   412,   413,   698,   429,  1127,  1098,   703,   603,   624,
     431,   625,   708,   914,   922,   302,   302,   963,  1607,  1739,
     306,   306,  1128,  1578,   395,  1246,  1452,  1494,  1582,  1095,
    1633,   576,   622,   440,  1208,  1572,  1209,  1208,  1305,  1209,
    1237,  1306,  1307,   698,  1308,  1740,  1635,  1734,   399,   399,
     414,  1309,  1033,  1204,  1639,   720,   489,   783,   653,   450,
     654,  1310,  1645,  1453,  1210,   550,  1129,  1210,   977,  1647,
     302,   572,   643,  1311,   573,   306,  1205,  1206,   442,  1652,
    1733,   551,  1364,   489,  1205,   443,   394,  1551,   644,  1441,
    1398,  1351,   755,   655,   623,  1675,  1435,  1101,   302,  1365,
     864,   421,   623,   306,   788,  1622,   880,  1383,  1738,  1744,
     938,   939,  1623,   681,   415,   575,  1208,   773,  1209,   881,
     656,   882,  1624,  1352,   444,  1306,  1307,  1781,  1308,   624,
     602,   625,   883,   884,   885,  1288,   886,   624,   887,   625,
    1289,  1353,  1254,  1366,   865,  1310,  1210,   801,   603,   866,
    1099,   801,  1238,  -852,   449,   416,  1677,  1311,   778,  1290,
    1738,  1205,  1206,  1712,   576,  1713,  1744,  1100,  1121,  1288,
    1127,   604,  1207,   481,  1289,  -932,   602,  -852,  1019,  1122,
    1568,   417,  1681,   657,  1771,   506,  1687,  1128,  -852,   418,
    1690,  1002,   432,  1208,   603,  1209,  1792,   419,  1381,  -932,
    1291,  1208,   433,  1209,  1620,  1621,  1568,   551,  1568,  1445,
    -932,  1778,  1019,  1793,   870,  1617,   503,  1705,  1358,  1262,
    1568,   639,   641,  1210,   504,  1327,  1328,   108,   900,   434,
    1263,  1210,   904,   905,   681,   640,   642,  1568,   510,   910,
    1264,  1761,  1205,  1206,   120,  1297,   302,   506,  1329,  1622,
     506,   306,  1265,  1034,   925,  1104,  1623,  1207,  1661,   787,
     609,  1177,  1034,   789,  1177,  1417,  1624,  1104,   580,   610,
    1707,   531,  1710,  1034,  1392,  1403,   489,  1397,  1208,   399,
    1209,  1406,  1715,   144,  1716,  1403,  1403,   952,  1404,  1123,
    1722,   667,  1147,   513,  1407,  1746,   668,  1247,  1577,  1784,
    1124,  1148,  1248,   514,  1116,  1117,  1118,   530,  1210,   532,
    1119,   533,   108,   534,   302,   302,   302,   535,   865,   306,
     306,   306,   421,   866,   997,   547,  1288,  1113,  1114,   120,
    1556,  1289,  1446,  1447,  1703,  1704,   812,   813,  1207,   819,
     820,  1188,   593,   594,   595,   596,   597,   598,   821,   822,
    1422,   659,   660,   661,  1009,  1370,  1371,  1648,  1649,  1208,
     591,  1209,   567,   592,   600,   601,   613,  1024,   144,   614,
     615,   620,   616,   628,   629,   630,  1661,   637,   631,   632,
     633,   649,   651,   652,   662,  1085,  1085,  1089,  1089,  1210,
     666,   536,   681,   108,   684,   692,   693,   694,  1600,   851,
     852,   853,   854,   855,   856,   857,   858,   859,   860,   705,
     120,   706,   721,   711,   713,   709,   716,   717,   718,   719,
     725,  1754,   733,   735,   736,   480,  1085,   737,   756,   762,
    1661,  1580,   751,   757,  1562,   752,   774,   768,   792,   794,
    1120,   802,   805,   793,   803,   810,   795,   823,   480,   144,
    1034,   824,   825,   826,   624,   840,   849,   846,   847,   871,
     480,   872,   480,   876,   302,  1150,   875,   897,   898,   306,
     302,   899,   901,  1085,   903,   306,   906,   911,   907,   796,
     908,   917,   302,   918,  1085,   921,  1379,   306,   933,   937,
     936,   976,   979,   986,   999,   982,   985,   395,  1003,  1010,
    1014,   302,  1105,   866,  1388,  1017,   306,   922,  1125,  1803,
    1126,  1804,  1146,  1151,  1152,   395,  1154,  1158,   677,  1159,
     302,  1812,  1160,  1410,  1161,   306,  1164,   302,  1166,  1173,
    1172,  1177,   306,  1183,   395,  1165,  1176,  1189,  1191,  1190,
    1196,  1201,  1520,  1197,  1193,  1218,  1194,  1217,  1219,  1232,
     655,  1249,  1239,   399,  1270,  1272,  1276,  1275,  1280,   394,
     399,  1321,  1247,  1324,     9,  1287,  1301,  1248,  1363,  1332,
    1320,  1333,  1334,  1335,  1336,  1362,  1271,   394,  1368,   801,
    1373,  1337,  1338,  1339,  1340,  1378,  1384,  1341,  1409,  1374,
    1355,  1667,  1387,  1342,  1345,   760,   394,  1346,  1347,  1348,
    1349,  1350,  1671,  1562,  1377,  1673,  1403,  1414,  1416,  1419,
    1431,  1425,  1433,  1682,  1438,  1420,  1427,  1428,  1085,  1429,
    1439,  1440,  1424,  1252,  1263,  1430,  1462,  1464,  1471,  1432,
    1468,  1470,  1476,  1472,  1497,  1481,  1502,  1426,  1437,  1504,
    1478,  1535,  1506,  1517,  1523,  1491,  1527,  1528,  1498,  1529,
    1530,  1541,  1546,  1594,  1595,  1596,  1531,  1553,  1532,  1548,
    1533,  1534,  1552,  1555,  1554,  1589,  1558,  1550,  1085,  1602,
    1604,  1559,  1564,  1609,  1575,  1576,  1581,  1584,  1616,  1636,
    1544,  1628,  1630,  1631,  1637,  1640,  1641,  1653,  1642,  1643,
    1127,  1629,  1658,  1672,  1666,  1452,  1700,  1702,  1717,  1714,
    1689,  1665,  1719,  1720,  1724,  1729,   302,  1745,  1730,  1731,
    1747,   306,  1748,  1758,  1777,  1753,  1756,  1757,  1769,  1673,
    1085,  1759,  1760,  1762,  1789,  1794,  1763,  1780,  1776,  1783,
    1718,  1802,  1767,  1725,  1809,   698,   873,   672,  1770,  1805,
    1361,  1808,  1376,  1108,  1157,  1085,   645,   480,  1727,  1765,
     480,  1247,   998,  1296,   480,  1614,  1248,   480,   480,   804,
    1787,  1475,   636,  1795,   548,   480,  1806,   549,  1773,  1456,
     927,  1261,  1448,  1421,  1451,   480,   710,  1796,  1389,  1393,
    1399,   480,  1408,   552,   809,   480,  1381,  1799,  1090,   839,
     480,   807,  1444,   842,   830,   831,   811,   953,  1418,  1782,
    1801,   755,  1779,  1508,  1509,  1711,  1436,  1443,  1442,  1790,
    1627,   997,  1695,  1496,  1626,   997,  1811,  1299,  1492,  1495,
    1323,   480,  1132,  1369,  1543,  1650,  1493,     0,     0,     0,
       0,  1790,     0,   480,     0,   801,     0,     0,  1460,     0,
    1773,     0,     0,  1706,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1474,   619,     0,     0,     0,     0,     0,
       0,     0,     0,  1247,     0,     0,     0,     0,  1248,     0,
     480,     0,     0,     0,  1247,  1247,     0,   302,     0,  1248,
    1248,     0,   306,     0,     0,  1247,     0,     0,     0,     0,
    1248,     0,     0,     0,     0,     0,  1512,  1085,     0,   506,
    1521,  1522,     0,  1526,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   480,     0,     0,     0,   480,
       0,     0,     0,     0,     0,  1549,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1566,   480,     0,  1085,     0,     0,  1085,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1579,
       0,     0,     0,     0,  1583,     0,     0,     0,     0,   850,
       0,  1247,   480,     0,     0,     0,  1248,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   480,     0,     0,     0,
     480,   480,     0,     0,     0,     0,     0,   480,     0,     0,
       0,     0,     0,     0,     0,   480,     0,     0,   480,     0,
       0,     0,   480,  1612,  1613,     0,     0,     0,     0,     0,
     302,     0,     0,     0,     0,   306,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1247,     0,
       0,     0,     0,  1248,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   302,     0,     0,     0,     0,   306,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,  1247,     0,     0,     0,     0,  1248,     0,
       0,     0,  1247,     0,     0,     0,     0,  1248,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1085,  1676,   480,  1678,     0,  1680,     0,     0,     0,     0,
       0,     0,  1688,     0,     0,   480,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,   480,   480,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   486,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1709,     0,  1709,     0,  1085,     0,
    1085,     0,     0,     0,   480,     0,   703,     0,   703,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,  1723,     0,     0,  1726,     0,     0,
       0,     0,     0,     0,  1085,     0,   522,     0,     0,     0,
       0,     0,     0,   480,     0,  1732,     0,     0,     0,     0,
       0,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1085,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1768,     0,     0,     0,
       0,  1085,     0,  1085,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1785,     0,     0,     0,     0,
     543,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1788,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1797,     0,     0,   480,     0,  1798,   480,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1807,     0,
       0,  1810,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   480,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     486,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,   738,   739,   480,     0,   741,   742,   743,     0,     0,
     747,     0,     0,   750,     0,     0,     0,     0,     0,   758,
       0,     0,     0,   480,     0,     0,   480,     0,   767,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   790,   791,     0,     0,     0,     0,     0,     0,     0,
     797,   798,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   480,   480,     0,   480,   480,   480,
       0,   480,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   837,     0,     0,     0,   837,     0,     0,     0,     0,
       0,     0,     0,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     480,     0,     0,   480,   902,     0,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   480,     0,     0,
       0,     0,   480,     0,     0,     0,     0,     0,     0,   926,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   943,     0,     0,     0,   945,
     946,     0,   948,     0,     0,     0,     0,     0,     0,   797,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   480,   480,     0,     0,     0,     0,     0,     0,     0,
       0,   974,   975,     0,     0,   978,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1000,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   791,     0,     0,     0,     0,     0,
    1011,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   480,   480,
       0,   480,     0,   480,     0,     0,     0,     0,     0,     0,
     480,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   480,     0,   480,     0,   480,  1149,   480,     0,
       0,     0,     0,     0,   480,     0,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1169,
       0,     0,   480,     0,     0,   480,  1174,  1175,     0,     0,
       0,     0,   480,     0,     0,     0,     0,  1192,     0,     0,
    1195,     0,     0,   480,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1222,  1223,  1224,     0,  1227,  1228,  1229,  1230,  1231,
       0,     0,  1233,  1234,   480,  1235,  1236,     0,     0,     0,
    1240,  1241,     0,     0,   480,     0,     0,     0,     0,   480,
       0,   480,     0,     0,     0,  1255,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1011,     0,     0,     0,
       0,     0,     0,   480,     0,     0,  1277,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   480,
       0,     0,     0,     0,   480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   480,     0,     0,   480,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1357,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1382,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1386,     0,     0,     0,
       0,     0,  1390,  1391,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1411,
       0,     0,  1412,  1413,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1434,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1011,     0,     0,     0,
       0,     0,     0,     0,  1461,     0,  1463,     0,  1465,     0,
       0,  1469,     0,     0,     0,     0,  1473,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1557,     0,     0,     0,     0,     0,     0,
       0,  1561,  1563,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1382,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1585,  1586,  1587,  1588,     0,  1590,  1591,
       0,  1592,     0,  1593,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1601,
       0,     0,     0,     0,  1603,     0,     0,     0,  1605,     0,
       0,     0,  1608,     0,  1610,     0,  1611,     0,     0,     0,
       0,     0,  1615,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1668,     0,     0,     0,     0,  1670,  1563,     0,     0,     0,
       0,     0,     0,  1674,     0,     0,     0,     0,  1679,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1691,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1697,     0,
    1698,     0,  1699,     0,     0,  1701,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1674,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1752,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1774,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -167,   778,     0,     0,
       0,     0,     0,  1786,     0,     0,     0,  1791,     0,     0,
       0,     0,  1774,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,  1791,     0,
      10,   390,  1800,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   105,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,   129,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   392,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,   243,  -167,   778,   244,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     782,   390,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   391,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   105,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,   129,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   392,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   778,   243,     0,     0,   244,   245,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,   389,   390,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   391,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,   105,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,   129,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   392,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   778,   243,     0,     0,   244,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   389,   390,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   490,
     391,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   491,   492,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   466,    80,    81,    82,    83,    84,
     493,    86,    87,     0,     0,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,     0,   494,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   392,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   472,   473,   474,   175,   176,
     475,   496,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,   243,
     990,   991,   244,   245,     0,     0,     0,     0,     0,   992,
       0,     0,     0,     0,     5,     6,     0,     0,     0,     0,
       0,     0,     0,   389,   390,     0,    12,    13,    14,   452,
      16,    17,    18,   453,    20,   454,   455,   456,   457,   391,
      26,   458,    28,    29,    30,     0,    31,    32,    33,    34,
     459,    36,    37,    38,    39,    40,    41,    42,   460,     0,
      44,   461,    46,   462,   463,    49,   464,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,   465,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   466,    80,    81,    82,    83,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   467,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,     0,   103,   104,     0,     0,     0,     0,     0,     0,
       0,   110,   468,     0,     0,     0,     0,   112,   113,   114,
     115,   469,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,   993,     0,   130,     0,
     131,   132,   133,   134,   470,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,     0,     0,   392,     0,   147,
     148,     0,     0,     0,   152,   153,   154,   155,   156,   157,
       0,   159,     0,   161,     0,     0,   164,   165,   166,   167,
     168,   169,   471,   171,   472,   473,   474,   175,   176,   475,
     476,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   477,     0,   192,   478,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,     0,     0,     0,
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
      83,    84,    85,    86,    87,     0,     0,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,   105,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,   129,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,   243,     0,     0,   244,   245,     0,     0,     0,     0,
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
      84,    85,    86,    87,     0,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,   105,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,   129,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     243,     0,     0,   244,   245,     0,   482,     0,     0,     0,
     544,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   389,   390,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     391,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,     0,   105,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,   483,     0,   126,
       0,   127,   128,   129,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   392,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,   243,
     482,     0,   244,   245,     0,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   389,   390,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   490,   391,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   491,   492,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   466,    80,
      81,    82,    83,    84,   493,    86,    87,     0,     0,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,     0,
     494,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   392,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   519,   160,   520,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   472,
     473,   474,   175,   176,   475,   496,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,   243,   482,   521,   244,   245,     0,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   389,   390,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   490,   391,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   491,   492,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   466,    80,    81,    82,    83,    84,   493,    86,
      87,     0,     0,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     0,   494,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   392,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   472,   473,   474,   175,   176,   475,   496,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   482,   243,     0,     0,
     244,   245,     0,     0,     0,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   389,   390,     0,    12,    13,    14,
     452,    16,    17,    18,   453,    20,   454,   455,   456,   457,
     391,    26,   458,    28,    29,    30,     0,    31,    32,    33,
      34,   459,    36,    37,    38,    39,    40,    41,    42,   460,
       0,    44,   461,    46,   462,   463,    49,   464,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   465,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   466,    80,    81,    82,    83,    84,
     493,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   467,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,   103,   104,     0,     0,     0,     0,   107,
       0,     0,   110,   468,     0,     0,     0,     0,   112,   113,
     114,   115,   469,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   470,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,     0,     0,   392,     0,
     147,   148,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,   159,     0,   161,     0,     0,   164,   165,   166,
     167,   168,   169,   471,   171,   472,   473,   474,   175,   176,
     475,   476,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   477,     0,   192,   478,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   482,     0,     0,
       0,     0,     0,   245,     0,     0,     5,     6,     0,     0,
       0,  1518,     0,     0,     0,   389,   390,     0,    12,    13,
      14,   452,    16,    17,    18,   453,    20,   454,   455,   456,
     457,   391,    26,   458,    28,    29,    30,     0,    31,    32,
      33,    34,   459,    36,    37,    38,    39,    40,    41,    42,
     460,     0,    44,   461,    46,   462,   463,    49,   464,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
     465,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   466,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   467,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,     0,     0,     0,     0,
       0,     0,     0,   110,   468,     0,     0,     0,     0,   112,
     113,   114,   115,   469,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,  1519,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   470,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   392,
       0,   147,   148,     0,     0,     0,   152,   153,   154,   155,
     156,   157,     0,   159,     0,   161,     0,     0,   164,   165,
     166,   167,   168,   169,   471,   171,   472,   473,   474,   175,
     176,   475,   476,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   477,     0,   192,   478,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   482,     0,
       0,     0,     0,     0,   245,     0,     0,     5,     6,     0,
       0,     0,     0,     0,     0,     0,   389,   390,     0,    12,
      13,    14,   452,    16,    17,    18,   453,    20,   454,   455,
     456,   457,   391,    26,   458,    28,    29,    30,     0,    31,
      32,    33,    34,   459,    36,    37,    38,    39,    40,    41,
      42,   460,     0,    44,   461,    46,   462,   463,    49,   464,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,   465,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   466,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
     467,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,     0,   103,   104,     0,     0,     0,
       0,     0,     0,     0,   110,   468,     0,     0,     0,     0,
     112,   113,   114,   115,   469,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   470,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,     0,     0,
     392,     0,   147,   148,     0,     0,     0,   152,   153,   154,
     155,   156,   157,     0,   159,     0,   161,     0,     0,   164,
     165,   166,   167,   168,   169,   471,   171,   472,   473,   474,
     175,   176,   475,   476,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   477,     0,   192,   478,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   507,
     508,     0,     0,     0,     0,   245,     5,     6,     0,     0,
       0,     0,     0,     0,     0,   389,   390,     0,    12,    13,
      14,   452,    16,    17,    18,   453,    20,   454,   455,   456,
     457,   391,    26,   458,    28,    29,    30,     0,    31,    32,
      33,    34,   459,    36,    37,    38,    39,    40,    41,    42,
     460,     0,    44,   461,    46,   462,   463,    49,   464,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
     465,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   466,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   467,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,     0,   103,   104,     0,     0,     0,     0,
       0,     0,     0,   110,   468,     0,     0,     0,     0,   112,
     113,   114,   115,   469,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   470,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,     0,     0,   392,
       0,   147,   148,     0,     0,     0,   152,   153,   154,   155,
     156,   157,     0,   159,     0,   161,     0,     0,   164,   165,
     166,   167,   168,   169,   471,   171,   472,   473,   474,   175,
     176,   475,   476,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   477,     0,   192,   478,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,     0,
       0,     0,     0,     0,   245,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,    10,    11,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,     0,     0,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,     0,
     105,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,   129,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,   243,     0,     0,   244,   245,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   391,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
       0,     0,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,     0,   105,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,   712,     0,   126,     0,   127,   128,
     129,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   392,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,     0,     0,   244,
     245,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   389,   390,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     391,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,     0,     0,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,     0,   105,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,   129,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   392,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,   243,
       0,     0,   244,   245,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,     0,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,   105,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,   129,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   392,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,   243,     0,     0,   244,   245,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
      10,   390,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,     0,
       0,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   105,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,   129,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   392,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,   243,     0,     0,   244,   245,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,   782,   390,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   391,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,     0,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     0,   105,   106,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,   129,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   392,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,   243,     0,
       0,   244,   245,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,  1242,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,  1243,  1244,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,     0,     0,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,   105,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,   129,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     392,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,  1245,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,   243,     0,     0,   244,   245,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   389,
     390,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   490,   391,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   491,
     492,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   466,
      80,    81,    82,    83,    84,   493,    86,    87,     0,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,   835,     0,    99,   100,   101,   102,   103,   104,
       0,   494,   106,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,   836,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   392,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     472,   473,   474,   175,   176,   475,   496,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,     0,     0,   244,   245,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   389,   390,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   490,   391,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   491,   492,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   466,    80,    81,    82,    83,    84,   493,    86,
      87,     0,     0,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,    94,    95,    96,    97,
      98,     0,     0,     0,     0,   835,     0,    99,   100,   101,
     102,   103,   104,     0,   494,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,   841,   127,
     128,     0,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   392,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   472,   473,   474,   175,   176,   475,   496,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,   243,     0,     0,
     244,   245,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   389,   390,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     490,   391,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,   491,   492,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   466,    80,    81,    82,    83,
      84,   493,    86,    87,     0,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,    94,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,   494,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,   495,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   392,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   472,   473,   474,   175,
     176,   475,   496,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     243,     0,     0,   244,   245,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   389,   390,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   490,   391,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   491,   492,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   466,    80,
      81,    82,    83,    84,   493,    86,    87,     0,     0,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,    94,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,     0,
     494,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,   500,   127,   128,     0,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   392,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   472,
     473,   474,   175,   176,   475,   496,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,   243,     0,     0,   244,   245,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   490,   391,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   491,   492,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   466,    80,    81,    82,    83,    84,   493,    86,    87,
       0,     0,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,    94,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,     0,   494,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   392,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   472,   473,   474,   175,   176,   475,   496,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   538,   243,     0,     0,   244,
     245,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   389,   390,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   490,
     391,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   491,   492,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   466,    80,    81,    82,    83,    84,
     493,    86,    87,     0,     0,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,    94,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,     0,   494,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   392,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   472,   473,   474,   175,   176,
     475,   496,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,   243,
     540,     0,   244,   245,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   389,   390,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   490,   391,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   491,   492,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   466,    80,    81,
      82,    83,    84,   493,    86,    87,     0,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,    94,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,   494,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   392,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   472,   473,
     474,   175,   176,   475,   496,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,   243,     0,   542,   244,   245,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     389,   390,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   490,   391,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     491,   492,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     466,    80,    81,    82,    83,    84,   493,    86,    87,     0,
       0,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,    94,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   494,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,   828,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   392,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   472,   473,   474,   175,   176,   475,   496,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,   243,     0,     0,   244,   245,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   389,   390,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   490,   391,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,   491,   492,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   466,    80,    81,    82,    83,    84,   493,
      86,    87,     0,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,    94,    95,    96,
      97,    98,     0,     0,     0,     0,  1356,     0,    99,   100,
     101,   102,   103,   104,     0,   494,   106,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   392,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   472,   473,   474,   175,   176,   475,
     496,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,   243,     0,
       0,   244,   245,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   389,   390,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   490,   391,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   491,   492,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   466,    80,    81,    82,
      83,    84,   493,    86,    87,     0,     0,     0,     0,    88,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,   102,   103,   104,     0,   494,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   121,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,   144,     0,
     392,     0,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   472,   473,   474,
     175,   176,   475,   496,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,   243,     0,     0,   244,   245,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   389,
     390,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   490,   391,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   491,
     492,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   466,
      80,    81,    82,    83,    84,   493,    86,    87,     0,     0,
       0,     0,    88,     0,    89,    90,    91,    92,     0,    93,
       0,     0,     0,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,    99,   100,   101,   102,   103,   104,
       0,   494,   106,     0,     0,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   392,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     472,   473,   474,   175,   176,   475,   496,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,     0,     0,   244,   245,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   389,   390,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   455,    23,   457,   391,    26,
     458,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   460,     0,    44,
      45,    46,   462,   463,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   466,    80,    81,    82,    83,    84,   493,    86,
      87,     0,     0,     0,     0,    88,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   467,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
     102,   103,   104,     0,   494,   106,     0,   107,   108,   617,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   618,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   392,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,     0,
     159,     0,   161,     0,     0,   164,   165,   166,   167,   168,
     169,   471,   171,   472,   473,   474,   175,   176,   475,   476,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   477,     0,   192,   478,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,   243,     0,     0,
       0,   245,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   389,   390,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,   455,    23,
     457,   391,    26,   458,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     460,     0,    44,    45,    46,   462,   463,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   466,    80,    81,    82,    83,
      84,   493,    86,    87,     0,     0,     0,     0,    88,     0,
      89,    90,    91,    92,     0,    93,     0,     0,     0,   467,
      95,    96,    97,    98,     0,     0,     0,     0,     0,     0,
      99,   100,   101,   102,   103,   104,     0,   494,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   392,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,     0,   159,     0,   161,     0,     0,   164,   165,
     166,   167,   168,   169,   471,   171,   472,   473,   474,   175,
     176,   475,   476,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   477,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     243,     0,     0,     0,   245,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   389,   390,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   455,    23,   457,   391,    26,   458,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   460,     0,    44,    45,    46,   462,   463,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   466,    80,
      81,    82,    83,    84,   493,    86,    87,     0,     0,     0,
       0,    88,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   467,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,   102,   103,   104,     0,
     494,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   392,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,   159,     0,   161,     0,
       0,   164,   165,   166,   167,   168,   169,   471,   171,   472,
     473,   474,   175,   176,   475,   476,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   477,     0,
     192,   478,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,   243,     0,     0,     0,   245,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   389,   390,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   455,    23,   457,   391,    26,   458,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   460,     0,    44,    45,
      46,   462,   463,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   466,    80,    81,    82,    83,    84,   493,    86,    87,
       0,     0,     0,     0,    88,     0,    89,    90,    91,    92,
       0,    93,     0,     0,     0,   467,    95,    96,    97,    98,
       0,     0,     0,     0,     0,     0,    99,   100,   101,   102,
     103,   104,     0,   494,   106,     0,     0,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   392,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,   159,
       0,   161,     0,     0,   164,   165,   166,   167,   168,   169,
     471,   171,   472,   473,   474,   175,   176,   475,   476,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   477,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,     0,     0,     0,
     245,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   389,   390,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   455,    23,   457,
     391,    26,   458,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   460,
       0,    44,    45,    46,   462,   463,    49,   464,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   466,    80,    81,    82,    83,    84,
     493,    86,    87,     0,     0,     0,     0,    88,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   467,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,   102,   103,   104,     0,   494,   106,     0,   107,
     108,     0,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,   144,     0,   392,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,     0,   515,     0,   516,     0,     0,   164,   165,   166,
     167,   168,   169,   471,   171,   472,   473,   474,   175,   176,
     475,   476,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   477,     0,   192,   478,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,   243,
       0,   517,     0,   245,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   389,   390,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     455,    23,   457,   391,    26,   458,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   460,     0,    44,    45,    46,   462,   463,    49,
     464,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   466,    80,    81,
      82,    83,    84,   493,    86,    87,     0,     0,     0,     0,
      88,     0,    89,    90,    91,    92,     0,    93,     0,     0,
       0,   467,    95,    96,    97,    98,     0,     0,     0,     0,
       0,     0,    99,   100,   101,   102,   103,   104,     0,   494,
     106,     0,   107,   108,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   392,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,   524,     0,   161,     0,     0,
     164,   165,   166,   167,   168,   169,   471,   171,   472,   473,
     474,   175,   176,   475,   476,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   477,     0,   192,
     478,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,   243,     0,   525,     0,   245,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     389,   390,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   455,    23,   457,   391,    26,   458,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   460,     0,    44,    45,    46,
     462,   463,    49,   464,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     466,    80,    81,    82,    83,    84,   493,    86,    87,     0,
       0,     0,     0,    88,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   467,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,   102,   103,
     104,     0,   494,   106,     0,   107,   108,     0,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,   144,     0,   392,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,   159,     0,
     161,     0,     0,   164,   165,   166,   167,   168,   169,   471,
     171,   472,   473,   474,   175,   176,   475,   476,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     477,     0,   192,   478,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,   243,     0,     0,     0,   245,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   389,   390,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   455,    23,   457,   391,
      26,   458,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   460,     0,
      44,    45,    46,   462,   463,    49,   464,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   466,    80,    81,    82,    83,    84,   493,
      86,    87,     0,     0,     0,     0,    88,     0,    89,    90,
      91,    92,     0,    93,     0,     0,     0,   467,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,    99,   100,
     101,   102,   103,   104,     0,   494,   106,     0,   107,   108,
       0,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   392,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
       0,   980,     0,   161,     0,     0,   164,   165,   166,   167,
     168,   169,   471,   171,   472,   473,   474,   175,   176,   475,
     476,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   477,     0,   192,   478,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,   243,     5,
       6,     0,   245,     0,     0,     0,     0,     0,   389,   390,
       0,    12,    13,    14,  1045,    16,    17,    18,   453,  1046,
    1047,   455,  1048,   457,   391,    26,   458,    28,  1049,    30,
       0,    31,    32,    33,    34,  1050,    36,  1051,  1052,    39,
      40,    41,    42,   460,     0,    44,  1053,    46,   462,   463,
      49,   464,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,  1054,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   466,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   467,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,  1055,
       0,     0,     0,  1056,     0,     0,   110,   468,     0,     0,
       0,     0,   112,   113,   114,   115,   469,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,  1513,   127,   128,     0,     0,     0,
       0,  1514,     0,   130,     0,   131,   132,   133,   134,   470,
     136,   137,   138,   139,   140,   141,     0,     0,  1057,   143,
       0,     0,   392,     0,   147,   148,     0,     0,     0,   152,
     153,   154,   155,   156,   157,     0,  1058,     0,   161,     0,
       0,   164,   165,   166,   167,   168,   169,   471,   171,   472,
     473,   474,   175,   176,   475,   476,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   477,     0,
     192,   478,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,     0,     5,     6,     0,     0,   245,  1059,  1060,
    1061,  1062,   389,   390,     0,    12,    13,    14,  1045,    16,
      17,    18,   453,  1046,  1047,   455,  1048,   457,   391,    26,
     458,    28,  1049,    30,     0,    31,    32,    33,    34,  1050,
      36,  1051,  1052,    39,    40,    41,    42,   460,     0,    44,
    1053,    46,   462,   463,    49,   464,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1054,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   466,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   467,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,   103,   104,  1055,     0,     0,     0,  1106,     0,     0,
     110,   468,     0,     0,     0,     0,   112,   113,   114,   115,
     469,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,  1343,   127,
     128,     0,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   470,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,     0,     0,   392,     0,   147,   148,
       0,     0,     0,   152,   153,   154,   155,   156,   157,     0,
    1058,     0,   161,     0,     0,   164,   165,   166,   167,   168,
     169,   471,   171,   472,   473,   474,   175,   176,   475,   476,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   477,     0,   192,   478,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,     0,     5,     6,     0,
       0,   245,  1059,  1060,  1061,  1062,   389,   390,     0,    12,
      13,    14,  1045,    16,    17,    18,   453,  1046,  1047,   455,
    1048,   457,   391,    26,   458,    28,  1049,    30,     0,    31,
      32,    33,    34,  1050,    36,  1051,  1052,    39,    40,    41,
      42,   460,     0,    44,  1053,    46,   462,   463,    49,   464,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,  1054,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   466,    80,    81,    82,
      83,    84,  1400,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
     467,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,     0,   103,   104,  1055,     0,     0,
       0,  1056,     0,     0,   110,   468,     0,     0,     0,     0,
     112,   113,   114,   115,   469,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   470,   136,   137,
     138,   139,   140,   141,     0,     0,  1057,   143,     0,     0,
     392,     0,   147,   148,     0,     0,     0,   152,   153,   154,
     155,   156,   157,     0,  1058,     0,   161,     0,     0,   164,
     165,   166,   167,   168,   169,   471,   171,   472,   473,   474,
     175,   176,   475,   476,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   477,     0,   192,   478,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
       0,     5,     6,     0,     0,   245,  1059,  1060,  1061,  1062,
     389,   390,     0,    12,    13,    14,  1045,    16,    17,    18,
     453,  1046,  1047,   455,  1048,   457,   391,    26,   458,    28,
    1049,    30,     0,    31,    32,    33,    34,  1050,    36,  1051,
    1052,    39,    40,    41,    42,   460,     0,    44,  1053,    46,
     462,   463,    49,   464,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,  1054,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     466,    80,    81,    82,    83,    84,  1569,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   467,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,  1055,     0,     0,     0,  1056,     0,     0,   110,   468,
       0,     0,     0,     0,   112,   113,   114,   115,   469,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   470,   136,   137,   138,   139,   140,   141,     0,     0,
    1057,   143,     0,     0,   392,     0,   147,   148,     0,     0,
       0,   152,   153,   154,   155,   156,   157,     0,  1058,     0,
     161,     0,     0,   164,   165,   166,   167,   168,   169,   471,
     171,   472,   473,   474,   175,   176,   475,   476,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     477,     0,   192,   478,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,     0,     5,     6,     0,     0,   245,
    1059,  1060,  1061,  1062,   389,   390,     0,    12,    13,    14,
    1045,    16,    17,    18,   453,  1046,  1047,   455,  1048,   457,
     391,    26,   458,    28,  1049,    30,     0,    31,    32,    33,
      34,  1050,    36,  1051,  1052,    39,    40,    41,    42,   460,
       0,    44,  1053,    46,   462,   463,    49,   464,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,  1054,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   466,    80,    81,    82,    83,    84,
    1573,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   467,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,   103,   104,  1055,     0,     0,     0,  1056,
       0,     0,   110,   468,     0,     0,     0,     0,   112,   113,
     114,   115,   469,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   470,   136,   137,   138,   139,
     140,   141,     0,     0,  1057,   143,     0,     0,   392,     0,
     147,   148,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,  1058,     0,   161,     0,     0,   164,   165,   166,
     167,   168,   169,   471,   171,   472,   473,   474,   175,   176,
     475,   476,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   477,     0,   192,   478,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,     0,     5,
       6,     0,     0,   245,  1059,  1060,  1061,  1062,   389,   390,
       0,    12,    13,    14,  1045,    16,    17,    18,   453,  1046,
    1047,   455,  1048,   457,   391,    26,   458,    28,  1049,    30,
       0,    31,    32,    33,    34,  1050,    36,  1051,  1052,    39,
      40,    41,    42,   460,     0,    44,  1053,    46,   462,   463,
      49,   464,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,  1054,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   466,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   467,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,  1055,
       0,     0,     0,  1056,     0,     0,   110,   468,     0,     0,
       0,     0,   112,   113,   114,   115,   469,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   470,
     136,   137,   138,   139,   140,   141,     0,     0,  1057,   143,
       0,     0,   392,     0,   147,   148,     0,     0,     0,   152,
     153,   154,   155,   156,   157,     0,  1058,     0,   161,     0,
       0,   164,   165,   166,   167,   168,   169,   471,   171,   472,
     473,   474,   175,   176,   475,   476,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   477,     0,
     192,   478,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,     0,     5,     6,     0,     0,   245,  1059,  1060,
    1061,  1062,   389,   390,     0,    12,    13,    14,  1045,    16,
      17,    18,   453,  1046,  1047,   455,  1048,   457,   391,    26,
     458,    28,  1049,    30,     0,    31,    32,    33,    34,  1050,
      36,  1051,  1052,    39,    40,    41,    42,   460,     0,    44,
    1053,    46,   462,   463,    49,   464,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1054,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   466,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   467,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,   103,   104,  1055,     0,     0,     0,  1106,     0,     0,
     110,   468,     0,     0,     0,     0,   112,   113,   114,   115,
     469,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   470,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,     0,     0,   392,     0,   147,   148,
       0,     0,     0,   152,   153,   154,   155,   156,   157,     0,
    1058,     0,   161,     0,     0,   164,   165,   166,   167,   168,
     169,   471,   171,   472,   473,   474,   175,   176,   475,   476,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   477,     0,   192,   478,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,     0,     5,     6,     0,
       0,   245,  1059,  1060,  1061,  1062,   389,   390,     0,    12,
      13,    14,   452,    16,    17,    18,   453,    20,   454,   455,
     456,   457,   391,    26,   458,    28,    29,    30,     0,    31,
      32,    33,    34,   459,    36,    37,    38,    39,    40,    41,
      42,   460,     0,    44,   461,    46,   462,   463,    49,   464,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,   465,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   466,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,     0,    93,     0,     0,     0,
     467,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,    99,   100,   101,     0,   103,   104,     0,     0,     0,
       0,     0,     0,     0,   110,   468,     0,     0,     0,     0,
     112,   113,   114,   115,   469,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,  1510,   127,   128,     0,     0,     0,     0,  1511,
       0,   130,     0,   131,   132,   133,   134,   470,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,     0,     0,
     392,     0,   147,   148,     0,     0,     0,   152,   153,   154,
     155,   156,   157,     0,   159,     0,   161,     0,     0,   164,
     165,   166,   167,   168,   169,   471,   171,   472,   473,   474,
     175,   176,   475,   476,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   477,     0,   192,   478,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     5,
       6,     0,     0,     0,     0,   245,     0,     0,   389,   390,
       0,    12,    13,    14,   452,    16,    17,    18,   453,    20,
     454,   455,   456,   457,   391,    26,   458,    28,    29,    30,
       0,    31,    32,    33,    34,   459,    36,    37,    38,    39,
      40,    41,    42,   460,     0,    44,   461,    46,   462,   463,
      49,   464,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   465,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   466,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,     0,    93,     0,
       0,     0,   467,    95,    96,    97,    98,     0,     0,     0,
       0,     0,     0,    99,   100,   101,     0,   103,   104,     0,
       0,     0,     0,     0,     0,     0,   110,   468,     0,     0,
       0,     0,   112,   113,   114,   115,   469,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,  1524,   127,   128,     0,     0,     0,
       0,  1525,     0,   130,     0,   131,   132,   133,   134,   470,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
       0,     0,   392,     0,   147,   148,     0,     0,     0,   152,
     153,   154,   155,   156,   157,     0,   159,     0,   161,     0,
       0,   164,   165,   166,   167,   168,   169,   471,   171,   472,
     473,   474,   175,   176,   475,   476,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   477,     0,
     192,   478,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     5,     6,     0,     0,     0,     0,   245,     0,     0,
     389,   390,     0,    12,    13,    14,   452,    16,    17,    18,
     453,    20,   454,   455,   456,   457,   391,    26,   458,    28,
      29,    30,     0,    31,    32,    33,    34,   459,    36,    37,
      38,    39,    40,    41,    42,   460,     0,    44,   461,    46,
     462,   463,    49,   464,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,   465,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     466,    80,    81,    82,    83,    84,  1273,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,     0,
      93,     0,     0,     0,   467,    95,    96,    97,    98,     0,
       0,     0,     0,     0,     0,    99,   100,   101,     0,   103,
     104,     0,     0,     0,     0,     0,     0,     0,   110,   468,
       0,     0,     0,     0,   112,   113,   114,   115,   469,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   130,     0,   131,   132,   133,
     134,   470,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   392,     0,   147,   148,     0,     0,
       0,   152,   153,   154,   155,   156,   157,     0,   159,     0,
     161,     0,     0,   164,   165,   166,   167,   168,   169,   471,
     171,   472,   473,   474,   175,   176,   475,   476,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     477,     0,   192,   478,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     5,     6,     0,     0,     0,     0,   245,
       0,     0,   389,   390,     0,    12,    13,    14,   452,    16,
      17,    18,   453,    20,   454,   455,   456,   457,   391,    26,
     458,    28,    29,    30,     0,    31,    32,    33,    34,   459,
      36,    37,    38,    39,    40,    41,    42,   460,     0,    44,
     461,    46,   462,   463,    49,   464,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,   465,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   466,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,     0,    93,     0,     0,     0,   467,    95,    96,    97,
      98,     0,     0,     0,     0,     0,     0,    99,   100,   101,
       0,   103,   104,     0,     0,     0,     0,     0,     0,     0,
     110,   468,     0,     0,     0,     0,   112,   113,   114,   115,
     469,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   470,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,     0,     0,   392,     0,   147,   148,
       0,     0,     0,   152,   153,   154,   155,   156,   157,     0,
     159,     0,   161,     0,     0,   164,   165,   166,   167,   168,
     169,   471,   171,   472,   473,   474,   175,   176,   475,   476,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   477,     0,   192,   478,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     5,     6,     0,     0,     0,
       0,   245,     0,     0,   389,   390,     0,    12,    13,    14,
       0,    16,    17,    18,   453,     0,     0,   455,   456,     0,
     391,    26,   458,    28,     0,    30,     0,    31,    32,    33,
      34,     0,    36,     0,     0,    39,    40,    41,    42,   460,
       0,    44,     0,    46,     0,     0,    49,   464,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,     0,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   466,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    89,
      90,    91,    92,     0,    93,     0,     0,     0,   467,    95,
      96,    97,    98,     0,     0,     0,     0,     0,     0,    99,
     100,   101,     0,   103,   104,     0,     0,     0,     0,     0,
       0,     0,   110,   468,     0,     0,     0,     0,   112,   113,
     114,   115,   469,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   470,   136,   137,   138,   139,
     140,   141,     0,     0,     0,   143,     0,     0,   392,     0,
     147,   148,     0,     0,     0,   152,   153,   154,   155,   156,
     157,     0,     0,     0,   161,     0,     0,   164,   165,   166,
     167,   168,   169,   471,   171,   472,   473,   474,   175,   176,
       0,   476,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   477,     0,   192,   478,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,     0,     0,
       0,     0,     0,   245
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     604,   106,   107,   285,   178,   120,   306,   698,   158,    10,
     620,   934,   162,   726,     2,     3,   337,   708,  1184,   605,
     606,   607,   608,   921,     1,     2,     3,     4,   402,  1200,
     823,   824,   623,   400,   401,   801,   193,     1,   557,   558,
     253,   956,   801,   160,     1,   810,  1267,  1268,  1403,  1017,
     254,  1406,  1031,   246,   247,    27,    28,   848,   898,   433,
     434,   898,  1324,    37,    37,   269,   645,   864,  1213,   555,
     556,   555,   556,   557,   558,   120,    48,  1546,     1,    78,
       1,    98,     1,   150,     1,     1,     1,     2,     3,     4,
      38,    39,    57,    41,    42,   105,     1,     9,    10,     1,
     105,     1,     1,   109,    76,  1601,     1,   109,     3,    31,
     801,    59,     1,   395,     1,   109,    98,   399,   911,   139,
      27,    28,    96,   109,    98,    98,    40,     1,   105,   922,
       1,    45,    46,   109,    96,     1,   134,   242,   243,   124,
      54,    48,   114,     1,    96,   109,   161,    61,   172,    63,
      64,    58,   109,   108,     0,     1,   221,   156,    72,   156,
      96,   239,   120,   241,   179,   924,     8,   115,   139,    76,
       1,     1,   108,    68,    81,   130,   150,   150,    73,   870,
     285,   205,   153,   180,   204,    99,   120,   232,   150,     1,
     105,   193,     1,   105,     1,   193,   261,   191,   150,   499,
       1,  1697,   145,   485,    34,   191,   113,   114,   115,   109,
     109,   187,    30,   280,   126,   163,   128,     1,   276,   910,
     109,     1,   109,     1,    43,   120,     1,  1448,    47,   228,
     229,    30,     1,    52,   240,   109,   246,   247,   109,   952,
     250,   246,   247,   109,   156,   250,   263,   264,   160,  1415,
    1719,   109,    71,   772,   773,   240,   221,  1023,  1181,  1056,
       0,     1,  1021,   109,  1023,   177,  1031,  1032,  1166,   314,
     193,   850,   193,  1418,   193,   285,   193,   193,   109,   227,
     285,   263,   656,  1545,   770,   771,   198,   187,   193,  1204,
     395,   193,   574,     1,   399,   217,   261,   109,  1213,   414,
     109,   190,   109,   190,   216,  1273,   280,   280,   109,  1106,
     425,  1151,  1103,   112,  1151,   689,   190,  1672,   232,   190,
     268,  1300,   294,   428,   190,   109,   431,    85,   127,   109,
     302,   109,   190,  1024,   109,   440,   178,   280,   443,   444,
     109,   187,   555,   556,   449,   163,   280,   105,   552,   553,
     108,   544,   171,   152,     1,   174,   320,   156,   562,   190,
     159,   318,   120,   421,   122,  1158,    46,   517,   120,   109,
     189,    30,   109,    30,  1729,   525,  1731,   150,   190,   188,
     485,   180,   109,   190,    64,   395,   187,   294,     1,   399,
     395,    95,   109,   109,   399,   302,   215,   156,   503,   504,
      96,   109,   160,   310,   521,   510,   190,     1,   188,   187,
     324,   325,   326,   124,   119,   190,   426,   427,   187,   109,
     156,   426,   427,   222,   223,   224,   122,   275,   156,   534,
     535,    98,   442,     1,   282,   592,   446,   442,   190,   102,
    1661,   446,    96,   810,   149,   264,   102,   187,   189,   426,
     427,     1,   180,     1,   213,   112,   115,   162,    96,  1150,
      96,   157,   109,   159,    53,   442,    46,   266,    48,   446,
     127,   159,   213,   190,   190,   485,   843,   213,   760,   187,
     485,    30,   186,   150,   494,  1004,  1005,  1006,   232,   494,
      43,   145,   197,   237,    47,   152,   109,   871,   872,    52,
     190,  1722,   876,  1418,   163,   242,   788,   280,   623,  1275,
     190,   426,   427,   240,  1105,   109,   621,   494,    71,   624,
    1004,  1005,  1006,  1694,  1283,   535,   189,   442,   108,   240,
     535,   446,   906,   189,   544,  1300,  1146,    27,    28,   544,
     187,   109,  1335,   132,  1309,   555,   556,   557,   558,   550,
     555,   556,   557,   558,   239,  1320,   241,   770,   535,   109,
      98,   109,   159,   112,   574,   222,   223,   224,    98,   574,
     685,   102,   776,   688,   187,   133,   780,   321,   127,   494,
    1271,   120,   109,  1749,    56,   163,    58,   225,   226,   225,
     226,   171,    96,   187,    27,    28,     5,     9,   122,   714,
       9,   751,   240,   152,   240,    38,    39,   156,    41,    42,
     159,    98,   717,   718,   719,    48,   721,    29,   171,   187,
     150,   174,   156,    43,   114,    58,    59,    47,   109,   109,
     102,   180,    52,   157,   172,   159,   189,   187,   134,   187,
     156,   145,   200,    76,    98,   109,   120,   156,    81,   407,
     189,    71,   410,   109,   122,   760,   414,  1555,   189,   417,
     418,   109,   215,   190,  1031,  1032,   133,   425,   109,   151,
     161,   681,   159,   222,   223,   224,   681,   435,   109,     9,
     113,   114,   115,   441,   159,    98,   168,   445,   179,   157,
     159,   159,   450,   681,    96,   705,   706,   193,  1464,    29,
     705,   706,   115,  1416,   681,   987,   108,  1311,  1421,   190,
     190,   264,  1033,   156,   126,   189,   128,   126,   172,   128,
     244,   259,   260,   481,   262,   137,   190,   136,   705,   706,
     163,   269,  1497,   200,   190,   493,   494,  1256,    46,   120,
      48,   279,   190,   145,   156,    34,   159,   156,    96,   190,
     760,   171,   169,   291,   174,   760,     9,    10,   156,   190,
       5,    50,    98,   521,     9,   159,   681,  1377,   185,   189,
    1693,   147,   530,    81,   122,  1568,   244,   140,   788,   115,
      96,   782,   122,   788,   988,   276,   258,  1161,  1684,  1685,
     705,   706,   283,   156,   227,   215,   126,  1001,   128,   271,
     108,   273,   293,   179,   159,   259,   260,   137,   262,   157,
     161,   159,   284,   285,   286,    55,   288,   157,   290,   159,
      60,   197,   996,   159,   140,   279,   156,   585,   179,   145,
     151,   589,   982,   124,   156,   268,   189,   291,     1,    79,
    1736,     9,    10,  1636,   264,  1638,  1742,   168,   270,    55,
      98,   202,   105,   120,    60,   124,   161,   148,    98,   281,
     213,   294,   189,   171,   189,   623,  1579,   115,   159,   302,
    1583,    34,    25,   126,   179,   128,   189,   310,  1160,   148,
     120,   126,    35,   128,  1488,  1489,   213,    50,   213,  1263,
     159,   136,    98,   189,   652,  1481,   156,   202,   140,    97,
     213,   185,   185,   156,   156,   254,   255,   160,   666,    62,
     108,   156,   670,   671,   156,   199,   199,   213,   156,   677,
     118,  1714,     9,    10,   177,  1030,   936,   685,   277,   276,
     688,   936,   130,  1300,   692,   861,   283,   105,  1548,   559,
     204,   102,  1309,   563,   102,   198,   293,   873,  1248,   213,
    1632,   248,  1634,  1320,   115,   102,   714,   115,   126,   936,
     128,   102,  1644,   216,  1646,   102,   102,   725,   115,   270,
    1661,   140,   306,   220,   115,  1688,   145,   987,   115,   115,
     281,   315,   987,   220,   284,   285,   286,   120,   156,   248,
     290,   249,   160,   159,  1004,  1005,  1006,   156,   140,  1004,
    1005,  1006,  1003,   145,   762,     0,    55,   131,   132,   177,
    1384,    60,   131,   132,  1618,  1619,   602,   603,   105,   609,
     610,   936,   206,   207,   208,   209,   210,   211,   611,   612,
     198,   228,   229,   230,   792,  1144,  1145,  1536,  1537,   126,
     170,   128,   193,    94,   256,   101,    51,   805,   216,   203,
     103,   196,   104,   148,   159,   187,  1666,    30,   187,   187,
     187,    48,   155,   120,   253,   823,   824,   825,   826,   156,
     311,  1245,   156,   160,     1,   120,   145,   109,  1452,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   156,
     177,   156,   156,   187,   124,   145,   124,   159,   159,   159,
      36,  1705,    17,   217,    30,    85,   864,    30,   193,   252,
    1720,   198,   238,   193,  1396,   237,     3,   240,   120,   173,
     878,   291,   120,   171,   291,    72,   173,   238,   108,   216,
    1497,    96,    96,    96,   157,   152,    30,   109,   109,   163,
     120,   163,   122,   135,  1154,   903,   130,   253,    96,  1154,
    1160,   306,   145,   911,   120,  1160,   135,    96,   187,  1441,
     187,    98,  1172,    46,   922,    98,  1154,  1172,   187,   187,
     156,    96,   244,   193,   240,   238,   145,  1154,    34,   173,
     120,  1191,   135,   145,  1172,   109,  1191,    96,    30,  1799,
     293,  1801,   234,    96,   306,  1172,   156,    96,   120,   187,
    1210,  1811,   201,  1191,   135,  1210,   163,  1217,    98,   120,
     156,   102,  1217,   102,  1191,   135,   150,   187,   156,   187,
     124,    36,  1337,   124,   145,    30,   193,   156,    30,    98,
      81,   252,   120,  1210,   109,   109,   120,   130,   150,  1154,
    1217,   267,  1252,   274,    30,   261,   292,  1252,    30,   159,
     265,   159,   159,   159,   159,   293,  1014,  1172,    30,  1017,
     294,   159,   159,   159,   159,   193,   109,   159,   187,   313,
     147,  1553,   145,   159,   159,  1252,  1191,   159,   159,   159,
     159,   159,  1564,  1565,   234,  1567,   102,   201,   135,     7,
      98,   193,   244,  1575,   159,  1210,   240,   240,  1056,   240,
     159,   159,  1217,   156,   108,   240,   150,   130,   120,   323,
     150,   150,    79,   120,   150,   257,   293,   193,   189,    80,
     190,    30,   190,   190,   190,   257,   190,   190,   289,   190,
     190,    30,   109,  1438,  1439,  1440,   190,   129,   190,   173,
     190,   190,   187,    98,   129,   323,   187,   264,  1106,   145,
     150,   189,   189,   150,   189,   187,   187,   187,   187,    96,
     278,   156,   190,   190,   190,   190,   190,    30,   190,   190,
      98,   287,   190,    96,   173,   108,   150,    55,    30,    96,
     200,   294,   109,   109,   120,    96,  1396,   200,   189,    96,
     200,  1396,   201,   147,    95,   120,   190,   190,   120,  1681,
    1158,   190,   190,   190,   120,   120,   190,   186,   189,   200,
     272,   189,   312,   232,   120,  1173,   655,   421,   232,   202,
    1107,   232,  1151,   865,   912,  1183,   406,   407,  1666,  1720,
     410,  1441,   763,  1029,   414,  1474,  1441,   417,   418,   589,
     312,  1292,   401,   300,   250,   425,   294,   250,  1730,  1272,
     694,  1010,  1267,  1211,  1270,   435,   481,   312,  1173,  1178,
    1181,   441,  1186,   253,   599,   445,  1748,   313,   826,   626,
     450,   591,  1253,   629,   623,   623,   601,   726,  1204,  1742,
     313,  1239,  1736,  1333,  1333,  1634,  1239,  1250,  1249,  1771,
    1497,  1249,  1597,  1320,  1494,  1253,   313,  1032,  1309,  1313,
    1041,   481,   897,  1129,  1367,  1539,  1310,    -1,    -1,    -1,
      -1,  1793,    -1,   493,    -1,  1273,    -1,    -1,  1276,    -1,
    1802,    -1,    -1,  1628,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1291,   332,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1553,    -1,    -1,    -1,    -1,  1553,    -1,
     530,    -1,    -1,    -1,  1564,  1565,    -1,  1567,    -1,  1564,
    1565,    -1,  1567,    -1,    -1,  1575,    -1,    -1,    -1,    -1,
    1575,    -1,    -1,    -1,    -1,    -1,  1334,  1335,    -1,  1337,
    1338,  1339,    -1,  1341,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   585,    -1,    -1,    -1,   589,
      -1,    -1,    -1,    -1,    -1,  1373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1400,   623,    -1,  1403,    -1,    -1,  1406,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,
      -1,    -1,    -1,    -1,  1422,    -1,    -1,    -1,    -1,   649,
      -1,  1681,   652,    -1,    -1,    -1,  1681,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   666,    -1,    -1,    -1,
     670,   671,    -1,    -1,    -1,    -1,    -1,   677,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   685,    -1,    -1,   688,    -1,
      -1,    -1,   692,  1471,  1472,    -1,    -1,    -1,    -1,    -1,
    1730,    -1,    -1,    -1,    -1,  1730,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1748,    -1,
      -1,    -1,    -1,  1748,    -1,   725,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1771,    -1,    -1,    -1,    -1,  1771,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   762,  1793,    -1,    -1,    -1,    -1,  1793,    -1,
      -1,    -1,  1802,    -1,    -1,    -1,    -1,  1802,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1568,  1569,   792,  1571,    -1,  1573,    -1,    -1,    -1,    -1,
      -1,    -1,  1580,    -1,    -1,   805,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   823,   824,   825,   826,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1632,    -1,  1634,    -1,  1636,    -1,
    1638,    -1,    -1,    -1,   864,    -1,  1644,    -1,  1646,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   878,    -1,
      -1,    -1,    -1,    -1,  1662,    -1,    -1,  1665,    -1,    -1,
      -1,    -1,    -1,    -1,  1672,    -1,   160,    -1,    -1,    -1,
      -1,    -1,    -1,   903,    -1,  1683,    -1,    -1,    -1,    -1,
      -1,   911,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   922,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1714,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1724,    -1,    -1,    -1,
      -1,  1729,    -1,  1731,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1753,    -1,    -1,    -1,    -1,
     244,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1769,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1789,    -1,    -1,  1014,    -1,  1794,  1017,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1806,    -1,
      -1,  1809,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1056,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1106,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1173,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1183,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1211,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     494,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1249,
      -1,   515,   516,  1253,    -1,   519,   520,   521,    -1,    -1,
     524,    -1,    -1,   527,    -1,    -1,    -1,    -1,    -1,   533,
      -1,    -1,    -1,  1273,    -1,    -1,  1276,    -1,   542,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   565,   566,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     574,   575,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1334,  1335,    -1,  1337,  1338,  1339,
      -1,  1341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   625,    -1,    -1,    -1,   629,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1400,    -1,    -1,  1403,   668,    -1,  1406,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1417,    -1,    -1,
      -1,    -1,  1422,    -1,    -1,    -1,    -1,    -1,    -1,   693,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   709,    -1,    -1,    -1,   713,
     714,    -1,   716,    -1,    -1,    -1,    -1,    -1,    -1,   723,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1471,  1472,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   745,   746,    -1,    -1,   749,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   768,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   788,    -1,    -1,    -1,    -1,    -1,
     794,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1568,  1569,
      -1,  1571,    -1,  1573,    -1,    -1,    -1,    -1,    -1,    -1,
    1580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   866,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1632,    -1,  1634,    -1,  1636,   901,  1638,    -1,
      -1,    -1,    -1,    -1,  1644,    -1,  1646,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   923,
      -1,    -1,  1662,    -1,    -1,  1665,   930,   931,    -1,    -1,
      -1,    -1,  1672,    -1,    -1,    -1,    -1,   941,    -1,    -1,
     944,    -1,    -1,  1683,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   965,   966,   967,    -1,   969,   970,   971,   972,   973,
      -1,    -1,   976,   977,  1714,   979,   980,    -1,    -1,    -1,
     984,   985,    -1,    -1,  1724,    -1,    -1,    -1,    -1,  1729,
      -1,  1731,    -1,    -1,    -1,   999,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1010,    -1,    -1,    -1,
      -1,    -1,    -1,  1753,    -1,    -1,  1020,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1769,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1789,
      -1,    -1,    -1,    -1,  1794,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1806,    -1,    -1,  1809,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1093,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1160,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1170,    -1,    -1,    -1,
      -1,    -1,  1176,  1177,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1193,
      -1,    -1,  1196,  1197,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1237,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1270,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1278,    -1,  1280,    -1,  1282,    -1,
      -1,  1285,    -1,    -1,    -1,    -1,  1290,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1387,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1395,  1396,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1414,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1427,  1428,  1429,  1430,    -1,  1432,  1433,
      -1,  1435,    -1,  1437,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1453,
      -1,    -1,    -1,    -1,  1458,    -1,    -1,    -1,  1462,    -1,
      -1,    -1,  1466,    -1,  1468,    -1,  1470,    -1,    -1,    -1,
      -1,    -1,  1476,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1554,    -1,    -1,    -1,    -1,  1559,  1560,    -1,    -1,    -1,
      -1,    -1,    -1,  1567,    -1,    -1,    -1,    -1,  1572,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1589,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1602,    -1,
    1604,    -1,  1606,    -1,    -1,  1609,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1677,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1700,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1730,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,
      -1,    -1,    -1,  1767,    -1,    -1,    -1,  1771,    -1,    -1,
      -1,    -1,  1776,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,  1792,    -1,
      34,    35,  1796,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,
     184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,   193,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,   216,    -1,   218,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,    -1,   319,     0,     1,   322,   323,
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
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,
     184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,   193,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,   216,    -1,   218,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,     1,   319,    -1,    -1,   322,   323,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,    -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
     177,    -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,
      -1,    -1,   189,    -1,   191,   192,   193,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,   214,   215,   216,
      -1,   218,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,     1,   319,    -1,    -1,   322,   323,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,   177,    -1,   179,
     180,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,
      -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    -1,   319,
      11,    12,   322,   323,    -1,    -1,    -1,    -1,    -1,    20,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,    -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,
     191,   192,    -1,    -1,    -1,    -1,   197,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,    -1,    -1,   218,    -1,   220,
     221,    -1,    -1,    -1,   225,   226,   227,   228,   229,   230,
      -1,   232,    -1,   234,    -1,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,    -1,    -1,    -1,    -1,
      -1,    -1,   323,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,   177,
      -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,
      -1,   189,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,   214,   215,   216,    -1,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,    -1,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
      -1,   319,    -1,    -1,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,   177,    -1,
     179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,
     189,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,   216,    -1,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
     319,    -1,    -1,   322,   323,    -1,    16,    -1,    -1,    -1,
     329,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,   177,    -1,   179,
     180,    -1,    -1,   183,   184,   185,    -1,   187,    -1,   189,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    -1,   319,
      16,    -1,   322,   323,    -1,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
     216,    -1,   218,    -1,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,   319,    16,   321,   322,   323,    -1,    21,
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
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,   177,    -1,   179,   180,    -1,
      -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,    16,   319,    -1,    -1,
     322,   323,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,   159,
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,
      -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,   214,   215,    -1,    -1,   218,    -1,
     220,   221,    -1,    -1,    -1,   225,   226,   227,   228,   229,
     230,    -1,   232,    -1,   234,    -1,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    16,    -1,    -1,
      -1,    -1,    -1,   323,    -1,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,
     189,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,    -1,    -1,   218,
      -1,   220,   221,    -1,    -1,    -1,   225,   226,   227,   228,
     229,   230,    -1,   232,    -1,   234,    -1,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    16,    -1,
      -1,    -1,    -1,    -1,   323,    -1,    -1,    25,    26,    -1,
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
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,    -1,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,   184,   185,    -1,    -1,
      -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,   214,   215,    -1,    -1,
     218,    -1,   220,   221,    -1,    -1,    -1,   225,   226,   227,
     228,   229,   230,    -1,   232,    -1,   234,    -1,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,    -1,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    18,
      19,    -1,    -1,    -1,    -1,   323,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,
     189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,    -1,    -1,   218,
      -1,   220,   221,    -1,    -1,    -1,   225,   226,   227,   228,
     229,   230,    -1,   232,    -1,   234,    -1,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,    -1,    -1,
      -1,    -1,    -1,    -1,   323,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,    -1,   191,   192,   193,    -1,    -1,
      -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
     216,    -1,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,   319,    -1,    -1,   322,   323,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,
      -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,
     183,   184,   185,    -1,   187,    -1,   189,    -1,   191,   192,
     193,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,   214,   215,   216,    -1,   218,    -1,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,    -1,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,    -1,   319,    -1,    -1,   322,
     323,    21,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,   177,    -1,   179,
     180,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,
      -1,   191,   192,   193,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    -1,   319,
      -1,    -1,   322,   323,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,    -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
     177,    -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,
      -1,    -1,   189,    -1,   191,   192,   193,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,   214,   215,   216,
      -1,   218,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,    -1,   319,    -1,    -1,   322,   323,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,
     184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,   193,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,   216,    -1,   218,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,    -1,   319,    -1,    -1,   322,   323,
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
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,   177,    -1,   179,   180,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,
     191,   192,   193,    -1,    -1,    -1,    -1,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,   319,    -1,
      -1,   322,   323,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,   177,
      -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,
      -1,   189,    -1,   191,   192,   193,    -1,    -1,    -1,    -1,
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,   214,   215,   216,    -1,
     218,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,    -1,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
      -1,   319,    -1,    -1,   322,   323,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,   147,    -1,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,    -1,   159,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,   214,
     215,   216,    -1,   218,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,    -1,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    -1,   319,    -1,    -1,   322,   323,    21,
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
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,   147,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,   177,    -1,   179,   180,    -1,
      -1,   183,   184,   185,    -1,    -1,    -1,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,    -1,   319,    -1,    -1,
     322,   323,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,   177,    -1,
     179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,   188,
     189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,   216,    -1,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
     319,    -1,    -1,   322,   323,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
     216,    -1,   218,    -1,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,   319,    -1,    -1,   322,   323,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,
      -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,
     183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,   214,   215,   216,    -1,   218,    -1,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,    -1,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,    -1,    -1,   322,
     323,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,   177,    -1,   179,
     180,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,
      -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    -1,   319,
     320,    -1,   322,   323,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,    -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
     177,    -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,
      -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,   214,   215,   216,
      -1,   218,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,    -1,   319,    -1,   321,   322,   323,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,
     184,   185,    -1,   187,    -1,   189,    -1,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,   216,    -1,   218,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,    -1,   319,    -1,    -1,   322,   323,
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
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
     161,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,   177,    -1,   179,   180,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,   319,    -1,
      -1,   322,   323,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,   177,
      -1,   179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,
      -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,   214,   215,   216,    -1,
     218,    -1,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,    -1,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
      -1,   319,    -1,    -1,   322,   323,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,
      35,    -1,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    96,    97,    98,    99,    -1,    -1,   102,   103,   104,
      -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,    -1,    -1,   160,   161,   162,   163,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,   174,
     175,    -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,
     185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,   214,
     215,   216,    -1,   218,    -1,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      -1,   266,   267,   268,    -1,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,    -1,   319,    -1,    -1,   322,   323,    21,
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
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,   177,    -1,   179,   180,    -1,
      -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,    -1,
     232,    -1,   234,    -1,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,    -1,   319,    -1,    -1,
      -1,   323,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,    -1,   168,
     169,   170,   171,   172,   173,   174,   175,    -1,   177,    -1,
     179,   180,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,
     189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,
     199,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,   214,   215,   216,    -1,   218,
      -1,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,    -1,   232,    -1,   234,    -1,    -1,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,    -1,   266,   267,   268,
      -1,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,    -1,
     319,    -1,    -1,    -1,   323,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,   161,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,   177,    -1,   179,   180,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
     216,    -1,   218,    -1,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,    -1,   232,    -1,   234,    -1,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,    -1,   319,    -1,    -1,    -1,   323,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,
      -1,    34,    35,    -1,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,
      -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,    -1,   160,   161,   162,
     163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,   174,   175,    -1,   177,    -1,   179,   180,    -1,    -1,
     183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,
      -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,   214,   215,   216,    -1,   218,    -1,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,    -1,   232,
      -1,   234,    -1,    -1,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,    -1,   266,   267,   268,    -1,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,    -1,   319,    -1,    -1,    -1,
     323,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,   177,    -1,    -1,
      -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,
      -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,    -1,   232,    -1,   234,    -1,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,    -1,   319,
      -1,   321,    -1,   323,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    -1,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    96,
      97,    98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,
     107,   108,    -1,    -1,    -1,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,
     127,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,    -1,   159,   160,    -1,   162,   163,    -1,    -1,    -1,
      -1,   168,   169,   170,   171,   172,   173,   174,   175,    -1,
     177,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,    -1,
      -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,
      -1,    -1,   199,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,   214,   215,   216,
      -1,   218,    -1,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,    -1,   232,    -1,   234,    -1,    -1,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,    -1,   266,
     267,   268,    -1,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,    -1,   319,    -1,   321,    -1,   323,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,    -1,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,   177,    -1,    -1,    -1,    -1,    -1,   183,
     184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,   216,    -1,   218,    -1,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,    -1,   232,    -1,
     234,    -1,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,    -1,   319,    -1,    -1,    -1,   323,
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
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
      -1,   162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,   174,   175,    -1,   177,    -1,    -1,    -1,
      -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,
     191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,   214,   215,   216,    -1,   218,    -1,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
      -1,   232,    -1,   234,    -1,    -1,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,    -1,   266,   267,   268,    -1,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,    -1,   319,    25,
      26,    -1,   323,    -1,    -1,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,   155,
      -1,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
      -1,    -1,   218,    -1,   220,   221,    -1,    -1,    -1,   225,
     226,   227,   228,   229,   230,    -1,   232,    -1,   234,    -1,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,    -1,    25,    26,    -1,    -1,   323,   324,   325,
     326,   327,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
      -1,   153,   154,   155,    -1,    -1,    -1,   159,    -1,    -1,
     162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   183,   184,   185,    -1,    -1,    -1,   189,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,   214,   215,    -1,    -1,   218,    -1,   220,   221,
      -1,    -1,    -1,   225,   226,   227,   228,   229,   230,    -1,
     232,    -1,   234,    -1,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,    -1,    25,    26,    -1,
      -1,   323,   324,   325,   326,   327,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,    -1,   153,   154,   155,    -1,    -1,
      -1,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,   184,   185,    -1,    -1,
      -1,   189,    -1,   191,   192,    -1,    -1,    -1,    -1,    -1,
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,   214,   215,    -1,    -1,
     218,    -1,   220,   221,    -1,    -1,    -1,   225,   226,   227,
     228,   229,   230,    -1,   232,    -1,   234,    -1,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,    -1,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
      -1,    25,    26,    -1,    -1,   323,   324,   325,   326,   327,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,   155,    -1,    -1,    -1,   159,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,
     184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,    -1,    -1,   218,    -1,   220,   221,    -1,    -1,
      -1,   225,   226,   227,   228,   229,   230,    -1,   232,    -1,
     234,    -1,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,    -1,    25,    26,    -1,    -1,   323,
     324,   325,   326,   327,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,    -1,   153,   154,   155,    -1,    -1,    -1,   159,
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,
      -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,   214,   215,    -1,    -1,   218,    -1,
     220,   221,    -1,    -1,    -1,   225,   226,   227,   228,   229,
     230,    -1,   232,    -1,   234,    -1,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,    -1,    25,
      26,    -1,    -1,   323,   324,   325,   326,   327,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,   155,
      -1,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,    -1,   191,   192,    -1,    -1,    -1,
      -1,    -1,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
      -1,    -1,   218,    -1,   220,   221,    -1,    -1,    -1,   225,
     226,   227,   228,   229,   230,    -1,   232,    -1,   234,    -1,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,    -1,    25,    26,    -1,    -1,   323,   324,   325,
     326,   327,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
      -1,   153,   154,   155,    -1,    -1,    -1,   159,    -1,    -1,
     162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,   214,   215,    -1,    -1,   218,    -1,   220,   221,
      -1,    -1,    -1,   225,   226,   227,   228,   229,   230,    -1,
     232,    -1,   234,    -1,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,    -1,    25,    26,    -1,
      -1,   323,   324,   325,   326,   327,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,    -1,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,    -1,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,   174,   175,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   183,   184,   185,    -1,    -1,
      -1,   189,   190,   191,   192,    -1,    -1,    -1,    -1,   197,
      -1,   199,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,   214,   215,    -1,    -1,
     218,    -1,   220,   221,    -1,    -1,    -1,   225,   226,   227,
     228,   229,   230,    -1,   232,    -1,   234,    -1,    -1,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,    -1,   266,   267,
     268,    -1,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    25,
      26,    -1,    -1,    -1,    -1,   323,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,    -1,   113,   114,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,   174,   175,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,   184,   185,
      -1,    -1,    -1,   189,   190,   191,   192,    -1,    -1,    -1,
      -1,   197,    -1,   199,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   214,   215,
      -1,    -1,   218,    -1,   220,   221,    -1,    -1,    -1,   225,
     226,   227,   228,   229,   230,    -1,   232,    -1,   234,    -1,
      -1,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,    -1,
     266,   267,   268,    -1,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    25,    26,    -1,    -1,    -1,    -1,   323,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,    -1,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
     174,   175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,
     184,   185,    -1,    -1,    -1,   189,    -1,   191,   192,    -1,
      -1,    -1,    -1,    -1,    -1,   199,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
     214,   215,    -1,    -1,   218,    -1,   220,   221,    -1,    -1,
      -1,   225,   226,   227,   228,   229,   230,    -1,   232,    -1,
     234,    -1,    -1,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,    -1,   266,   267,   268,    -1,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    25,    26,    -1,    -1,    -1,    -1,   323,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
      -1,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,   163,    -1,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   174,   175,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   183,   184,   185,    -1,    -1,    -1,   189,    -1,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,   199,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,   214,   215,    -1,    -1,   218,    -1,   220,   221,
      -1,    -1,    -1,   225,   226,   227,   228,   229,   230,    -1,
     232,    -1,   234,    -1,    -1,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,   266,   267,   268,    -1,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    25,    26,    -1,    -1,    -1,
      -1,   323,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      -1,    41,    42,    43,    44,    -1,    -1,    47,    48,    -1,
      50,    51,    52,    53,    -1,    55,    -1,    57,    58,    59,
      60,    -1,    62,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    -1,    73,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    -1,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,    -1,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   162,   163,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,   174,   175,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   183,   184,   185,    -1,    -1,    -1,   189,
      -1,   191,   192,    -1,    -1,    -1,    -1,    -1,    -1,   199,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,    -1,   215,    -1,    -1,   218,    -1,
     220,   221,    -1,    -1,    -1,   225,   226,   227,   228,   229,
     230,    -1,    -1,    -1,   234,    -1,    -1,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
      -1,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,    -1,   266,   267,   268,    -1,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,    -1,    -1,
      -1,    -1,    -1,   323
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
     115,   116,   117,   118,   119,   120,   121,   122,   127,   129,
     130,   131,   132,   134,   138,   139,   140,   141,   142,   149,
     150,   151,   152,   153,   154,   156,   157,   159,   160,   161,
     162,   163,   168,   169,   170,   171,   172,   173,   174,   175,
     177,   179,   180,   183,   184,   185,   189,   191,   192,   193,
     199,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   214,   215,   216,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   266,   267,   268,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   319,   322,   323,   328,   329,   343,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   364,   365,   366,   367,
     368,   369,   373,   374,   375,   379,   381,   382,   384,   391,
     393,   396,   397,   398,   400,   401,   402,   403,   404,   406,
     407,   409,   410,   411,   412,   413,   414,   416,   417,   420,
     421,   422,   423,   424,   429,   431,   433,   434,   435,   440,
     459,   462,   466,   469,   470,   476,   477,   478,   479,   480,
     481,   482,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   494,   495,   496,   497,   499,   500,   501,   502,   503,
     504,   505,   508,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   522,   523,   524,   525,   526,   527,   541,
     542,   544,   545,   546,   547,   548,   549,   550,   551,   572,
     577,   578,   579,   580,   581,   582,   585,   643,   644,   645,
     646,   648,   649,   650,   651,   652,   659,   660,   661,    34,
      35,    50,   218,   399,   400,   401,   399,   399,   400,   401,
     159,   159,    38,    39,    41,    42,    48,    58,    59,    76,
      81,   113,   114,   115,   163,   227,   268,   294,   302,   310,
     380,   381,   385,   386,   387,   163,   156,   156,   156,   159,
     388,   159,    25,    35,    62,   120,   280,   439,   441,   442,
     156,   120,   156,   159,   159,    78,   156,   228,   229,   156,
     120,   408,    40,    44,    46,    47,    48,    49,    52,    61,
      69,    72,    74,    75,    77,    99,   114,   138,   163,   172,
     205,   243,   245,   246,   247,   250,   251,   264,   267,   659,
     660,   120,    16,   187,   400,   401,   422,   647,   658,   659,
      49,    74,    75,   120,   156,   188,   251,   421,   423,   433,
     190,   421,   659,   156,   156,   658,   659,    18,    19,   659,
     156,    31,   217,   220,   220,   232,   234,   321,   508,   232,
     234,   321,   422,   647,   232,   321,   508,   232,   237,   321,
     120,   248,   248,   249,   159,   156,   403,   479,   318,   421,
     320,   421,   321,   422,   329,   345,   345,     0,   347,   348,
      34,    50,   350,   367,     1,   193,   344,   193,   344,   114,
     382,   402,   421,   109,   193,   109,   344,   193,    43,    47,
      52,    71,   171,   174,   189,   215,   264,   415,   425,   430,
     431,   432,   447,   448,   452,     1,     3,    68,    73,   120,
     426,   170,    94,   206,   207,   208,   209,   210,   211,   498,
     256,   101,   161,   179,   202,   119,   149,   162,   197,   204,
     213,   139,   153,    51,   203,   103,   104,   161,   179,   496,
     196,   156,   502,   122,   157,   159,   509,   510,   148,   159,
     187,   187,   187,   187,   383,   512,   383,    30,   657,   185,
     199,   185,   199,   169,   185,   660,   659,   172,   205,    48,
     659,   155,   120,    46,    48,    81,   108,   171,   658,   228,
     229,   230,   253,   616,   659,   659,   311,   140,   145,   114,
     294,   302,   385,   658,   400,   400,   421,   120,   190,   389,
     390,   156,   405,   421,     1,   163,   657,   115,   163,   363,
     657,   659,   120,   145,   109,   421,   460,   461,   659,   400,
     421,   421,   570,   659,   400,   156,   156,   421,   659,   145,
     460,   187,   187,   124,   109,   187,   124,   159,   159,   159,
     659,   156,   188,   189,   190,    36,   529,   530,   531,   421,
     421,     8,   178,    17,   421,   217,    30,    30,   422,   422,
     508,   422,   422,   422,   647,   240,   240,   422,   508,    96,
     422,   238,   237,   583,   584,   659,   193,   193,   422,   421,
     401,   421,   252,   418,   419,   318,   320,   422,   240,   345,
     193,   344,   193,   344,     3,   351,   367,   397,     1,   351,
     367,   397,    34,   368,   397,   368,   397,   408,   344,   408,
     422,   422,   120,   171,   173,   173,   402,   422,   422,   436,
     437,   659,   291,   291,   436,   120,   443,   478,   479,   481,
      72,   482,   486,   486,   485,   487,   487,   487,   487,   488,
     488,   489,   489,   238,    96,    96,    96,   503,   187,   421,
     515,   516,   572,   658,   421,   147,   190,   422,   521,   510,
     152,   190,   521,   109,   190,   190,   109,   109,   388,    30,
     660,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   370,   371,   372,    96,   140,   145,   376,   377,   378,
     659,   163,   163,   370,   657,   130,   135,    56,    58,   102,
     258,   271,   273,   284,   285,   286,   288,   290,   617,   618,
     619,   620,   621,   622,   629,   635,   636,   253,    96,   306,
     659,   145,   422,   120,   659,   659,   135,   187,   187,   187,
     659,    96,   109,   190,   399,   190,   658,    98,    46,   658,
     657,    98,    96,   145,   552,   659,   422,   442,   187,   109,
     191,   150,   552,   187,   190,   190,   156,   187,   400,   400,
     187,   145,   552,   422,   191,   422,   422,   658,   422,   421,
     421,   421,   659,   530,   531,   133,   200,   187,   187,   187,
     134,   193,   134,   193,    96,   225,   226,   240,    96,   225,
     226,   240,   240,   240,   422,   422,    96,    96,   422,   244,
     232,   508,   238,   109,   242,   145,   193,   190,   421,   187,
      11,    12,    20,   197,   506,   507,   589,   659,   419,   240,
     422,   367,    34,    34,   193,   344,   193,   115,   402,   659,
     173,   422,   453,   454,   120,   449,   450,   109,    37,    98,
     150,   438,   439,   552,   659,    57,   221,   261,   427,   428,
     156,   159,   266,   501,   512,   590,   593,   594,   595,   596,
     597,   601,   603,   605,   606,    40,    45,    46,    48,    54,
      61,    63,    64,    72,    99,   155,   159,   214,   232,   324,
     325,   326,   327,   553,   555,   557,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   573,   574,   575,
     576,   653,   654,   655,   656,   659,   553,   493,   558,   659,
     493,   187,   188,   109,   190,   190,   512,   151,   168,   151,
     168,   140,   405,   388,   371,   135,   159,   555,   378,   422,
     552,   657,   657,   131,   132,   657,   284,   285,   286,   290,
     659,   270,   281,   270,   281,    30,   293,    98,   115,   159,
     623,   626,   617,    40,    45,    46,    54,    61,    63,    64,
      72,    99,   232,   392,   559,   653,   234,   306,   315,   422,
     659,    96,   306,   657,   156,   552,   553,   390,    96,   187,
     201,   135,   362,   657,   163,   135,    98,   362,   553,   422,
     145,   439,   156,   120,   422,   422,   150,   102,   463,   464,
     465,   467,   468,   102,   471,   472,   473,   474,   400,   187,
     187,   156,   422,   145,   193,   422,   124,   124,   190,   190,
     190,    36,   531,   133,   200,     9,    10,   105,   126,   128,
     156,   198,   526,   528,   539,   540,   543,   156,    30,    30,
     239,   241,   422,   422,   422,   239,   241,   422,   422,   422,
     422,   422,    98,   422,   422,   422,   422,   244,   508,   120,
     422,   422,    49,    74,    75,   251,   402,   423,   433,   252,
     586,   587,   156,   213,   403,   422,   193,   115,   397,   397,
     397,   453,    97,   108,   118,   130,   455,   456,   457,   458,
     109,   659,   109,   120,   437,   130,   120,   422,   150,   439,
     150,    37,   150,   438,   439,   150,   552,   261,    55,    60,
      79,   120,   438,   444,   445,   446,   428,   421,   590,   597,
     156,   292,   483,   642,    98,   172,   259,   260,   262,   269,
     279,   291,   591,   592,   611,   612,   613,   614,   637,   640,
     265,   267,   598,   616,   274,   602,   638,   254,   255,   277,
     607,   608,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   190,   555,   159,   159,   159,   159,   159,
     159,   147,   179,   197,   554,   147,   147,   422,   140,   405,
     572,   377,   293,    30,    98,   115,   159,   630,    30,   623,
     554,   554,   503,   294,   313,   552,   392,   234,   193,   399,
     553,   402,   422,   657,   109,   362,   422,   145,   399,   461,
     422,   422,   115,   464,   465,   102,   189,   115,   465,   468,
     120,   475,   553,   102,   115,   472,   102,   115,   474,   187,
     399,   422,   422,   422,   201,   471,   135,   198,   528,     7,
     400,   659,   198,   539,   400,   193,   193,   240,   240,   240,
     240,    98,   323,   244,   422,   244,   584,   189,   159,   159,
     159,   189,   589,   587,   506,   657,   131,   132,   457,   458,
     458,   454,   108,   145,   451,   552,   450,   437,   150,   438,
     659,   422,   150,   422,   130,   422,   150,   439,   150,   422,
     150,   120,   120,   422,   659,   446,    79,   187,   190,   590,
     604,   257,   221,   261,   275,   282,   641,    98,   263,   264,
     639,   257,   594,   641,   485,   611,   595,   150,   289,   599,
     600,   639,   293,   610,    80,   609,   190,   190,   568,   569,
     190,   197,   659,   190,   197,   553,   556,   190,    30,   190,
     658,   659,   659,   190,   190,   197,   659,   190,   190,   190,
     190,   190,   190,   190,   190,    30,   139,   204,   632,   633,
     634,    30,   631,   632,   278,   627,   109,   624,   173,   659,
     264,   503,   187,   129,   129,    98,   657,   422,   187,   189,
     189,   422,   402,   422,   189,   189,   659,   189,   213,   120,
     475,   120,   189,   120,   475,   189,   187,   115,   531,   659,
     198,   187,   531,   659,   187,   422,   422,   422,   422,   323,
     422,   422,   422,   422,   421,   421,   421,   156,   588,   458,
     657,   422,   145,   422,   150,   422,   150,   438,   422,   150,
     422,   422,   659,   659,   445,   422,   187,   487,    53,   132,
     485,   485,   276,   283,   293,   615,   615,   596,   156,   287,
     190,   190,   109,   190,   109,   190,    96,   190,   109,   190,
     190,   190,   190,   190,   109,   190,   109,   190,   630,   630,
     634,   109,   190,    30,   628,   639,   625,   626,   190,   394,
     395,   503,   120,   232,   314,   294,   173,   402,   422,   362,
     422,   402,    96,   402,   422,   553,   659,   189,   659,   422,
     659,   189,   402,   120,    95,   186,   532,   531,   659,   200,
     531,   422,   190,   190,   190,   421,   451,   422,   422,   422,
     150,   422,    55,   485,   485,   202,   421,   570,   571,   659,
     570,   571,   553,   553,    96,   570,   570,    30,   272,   109,
     109,   458,   552,   659,   120,   232,   659,   394,   475,    96,
     189,    96,   659,     5,   136,   535,   536,   538,   540,    29,
     137,   533,   534,   537,   540,   200,   531,   200,   201,   471,
     187,   451,   422,   120,   485,   187,   190,   190,   147,   190,
     190,   553,   190,   190,   626,   395,   458,   312,   659,   120,
     232,   189,   475,   402,   422,   475,   189,    95,   136,   538,
     186,   137,   537,   200,   115,   659,   422,   312,   659,   120,
     402,   422,   189,   189,   120,   300,   312,   659,   659,   313,
     422,   313,   189,   503,   503,   202,   294,   659,   232,   120,
     659,   313,   503
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
     595,   596
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  jsoniq_parser::yyr1_[] =
  {
         0,   342,   343,   343,   343,   343,   344,   344,   344,   345,
     345,   345,   345,   346,   346,   346,   346,   347,   347,   347,
     347,   347,   347,   347,   347,   348,   348,   348,   348,   349,
     350,   350,   350,   351,   351,   351,   351,   351,   352,   352,
     352,   352,   352,   352,   352,   352,   353,   353,   354,   355,
     356,   356,   357,   357,   358,   358,   359,   359,   359,   359,
     360,   360,   360,   361,   361,   361,   361,   362,   362,   363,
     363,   364,   364,   364,   364,   365,   366,   366,   367,   367,
     367,   368,   368,   368,   368,   368,   368,   368,   368,   369,
     369,   370,   370,   371,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   373,   374,   375,   376,   376,   377,
     377,   377,   378,   379,   379,   379,   380,   380,   380,   380,
     381,   381,   382,   382,   382,   382,   383,   383,   384,   384,
     385,   385,   386,   386,   387,   387,   388,   388,   388,   388,
     389,   389,   390,   390,   391,   391,   391,   391,   392,   392,
     392,   392,   393,   393,   394,   394,   395,   395,   395,   395,
     396,   396,   396,   396,   397,   398,   398,   398,   399,   399,
     399,   400,   400,   401,   401,   401,   402,   402,   402,   402,
     402,   402,   402,   402,   402,   402,   402,   402,   402,   403,
     404,   405,   406,   407,   407,   407,   408,   408,   408,   408,
     409,   410,   411,   412,   413,   413,   414,   415,   416,   417,
     418,   418,   419,   420,   421,   421,   421,   422,   422,   422,
     422,   422,   422,   423,   423,   423,   423,   423,   423,   423,
     423,   423,   423,   423,   423,   424,   425,   426,   426,   427,
     427,   427,   428,   428,   429,   429,   430,   431,   431,   431,
     432,   432,   432,   432,   432,   433,   433,   434,   434,   434,
     435,   435,   436,   436,   436,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   438,   439,   440,
     441,   441,   442,   442,   442,   442,   443,   443,   444,   444,
     444,   445,   445,   445,   446,   446,   446,   447,   448,   449,
     449,   450,   450,   450,   450,   450,   450,   451,   452,   452,
     453,   453,   454,   454,   455,   455,   455,   455,   455,   455,
     455,   456,   456,   457,   457,   458,   459,   459,   460,   460,
     461,   461,   462,   463,   463,   464,   465,   465,   466,   467,
     467,   468,   469,   469,   470,   470,   471,   471,   472,   472,
     473,   473,   474,   474,   475,   475,   476,   477,   477,   478,
     478,   479,   479,   480,   480,   481,   481,   482,   482,   483,
     483,   484,   484,   485,   485,   485,   486,   486,   486,   486,
     486,   487,   487,   487,   488,   488,   488,   489,   489,   490,
     490,   491,   491,   492,   492,   493,   493,   494,   494,   495,
     495,   495,   495,   496,   496,   496,   497,   497,   498,   498,
     498,   498,   498,   498,   499,   499,   499,   499,   500,   500,
     501,   501,   502,   502,   502,   503,   504,   505,   506,   506,
     507,   507,   507,   507,   508,   508,   508,   508,   508,   508,
     508,   508,   509,   509,   510,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   512,
     512,   512,   512,   513,   513,   513,   514,   514,   515,   516,
     516,   517,   517,   518,   519,   520,   520,   521,   521,   521,
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
     644,   645,   645,   646,   646,   647,   647,   647,   647,   648,
     648,   648,   648,   648,   648,   649,   649,   650,   650,   651,
     651,   652,   652,   653,   653,   653,   654,   654,   655,   655,
     656,   656,   657,   658,   658,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   660,   660,   660,   660,   660,   660,   660,   660,   660,
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
     660,   660,   660,   660,   660,   660,   660,   661
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
       3,     1,     2,     1,     3,     1,     5,     1,     3,     0,
       1,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     4,     1,
       4,     1,     4,     1,     4,     1,     2,     1,     2,     1,
       1,     2,     2,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     4,     5,     5,     6,     3,     4,
       1,     2,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     3,     3,
       3,     3,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     1,     4,     4,     3,     4,     1,     3,     1,
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
       3,     2,     3,     3,     2,     3,     3,     5,     5,     5,
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
  "\"'descending'\"", "\"'div'\"", "\"'$'\"", "\"'$_'\"", "\"'.'\"",
  "\"'..'\"", "\"':'\"", "\"'::'\"", "\"'{{'\"", "\"'DOUBLE'\"",
  "\"'<double {>'\"", "\"'else'\"", "\"'empty'\"", "\"'greatest'\"",
  "\"'least'\"", "\"'/>'\"", "\"'encoding'\"", "\"'='\"", "\"''''\"",
  "\"'\\\"\\\"'\"", "\"'every'\"", "\"'except'\"", "\"'external'\"",
  "\"'following'\"", "\"'following-sibling'\"", "\"'follows'\"",
  "\"'>='\"", "\"':='\"", "\"'>'\"", "\"'?'\"", "\"'#'\"", "\"'idiv'\"",
  "\"'in'\"", "\"'inherit'\"", "\"'INTEGER'\"", "\"'intersect'\"",
  "\"'is'\"", "\"'item'\"", "\"'{'\"", "\"'['\"", "\"'<='\"", "\"'('\"",
  "\"'<'\"", "\"'-'\"", "\"'mod'\"", "\"'namespace'\"", "\"'nan'\"",
  "\"'!='\"", "\"'nodecomp'\"", "\"'?""?'\"", "\"'<no inherit>'\"",
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
  "OrExpr", "AndExpr", "NotExpr", "ComparisonExpr", "FTContainsExpr",
  "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "SingleType",
  "UnaryExpr", "SignList", "ValueExpr", "SimpleMapExpr", "ValueComp",
  "ValidateExpr", "ExtensionExpr", "Pragma_list", "Pragma", "PathExpr",
  "RelativePathExpr", "StepExpr", "NameTest", "Wildcard", "FilterExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "BooleanLiteral", "VarRef", "ParenthesizedExpr", "ContextItemExpr",
  "OrderedExpr", "UnorderedExpr", "FunctionCall", "ArgList",
  "FunctionItemExpr", "LiteralFunctionItem", "InlineFunction",
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
       343,     0,    -1,   345,    -1,   328,   345,    -1,   329,   345,
      -1,   328,   329,   345,    -1,     1,    -1,     1,     3,    -1,
     344,     1,    -1,   347,    -1,   346,   347,    -1,   348,    -1,
     346,   348,    -1,   218,   220,    30,   193,    -1,   218,   220,
      30,   134,    30,   193,    -1,   219,   220,    30,   193,    -1,
     219,   220,    30,   134,    30,   193,    -1,   350,   193,   397,
      -1,   367,   193,   397,    -1,   350,   193,   367,   193,   397,
      -1,   397,    -1,   350,   344,   397,    -1,   367,   344,   397,
      -1,   350,   193,   367,   344,   397,    -1,   350,   344,   367,
     193,   397,    -1,   349,    -1,   349,   350,   193,    -1,   349,
     367,   193,    -1,   349,   350,   193,   367,   193,    -1,    35,
     163,   658,   135,   657,   193,    -1,   351,    -1,   350,   193,
     351,    -1,   350,   344,   351,    -1,   352,    -1,   360,    -1,
     365,    -1,   366,    -1,   374,    -1,   353,    -1,   354,    -1,
     355,    -1,   356,    -1,   357,    -1,   358,    -1,   359,    -1,
     577,    -1,    34,    39,   185,    -1,    34,    39,   199,    -1,
      34,   115,   108,   657,    -1,    34,    38,   657,    -1,    34,
      41,   185,    -1,    34,    41,   199,    -1,    34,    59,   172,
      -1,    34,    59,   205,    -1,    34,   115,   171,   130,   131,
      -1,    34,   115,   171,   130,   132,    -1,    34,    42,   185,
     109,   151,    -1,    34,    42,   185,   109,   168,    -1,    34,
      42,   169,   109,   151,    -1,    34,    42,   169,   109,   168,
      -1,   361,    -1,   364,    -1,    50,    25,     1,    -1,    50,
      62,   657,    -1,    50,    62,   363,   657,    -1,    50,    62,
     657,    98,   362,    -1,    50,    62,   363,   657,    98,   362,
      -1,   657,    -1,   362,   109,   657,    -1,   163,   658,   135,
      -1,   115,    46,   163,    -1,    50,    35,   657,    -1,    50,
      35,   163,   658,   135,   657,    -1,    50,    35,   657,    98,
     362,    -1,    50,    35,   163,   658,   135,   657,    98,   362,
      -1,    34,   163,   658,   135,   657,    -1,    34,   115,    46,
     163,   657,    -1,    34,   115,    48,   163,   657,    -1,   368,
      -1,   367,   193,   368,    -1,   367,   344,   368,    -1,   369,
      -1,   373,    -1,   375,    -1,   379,    -1,   384,    -1,   391,
      -1,   393,    -1,   396,    -1,    34,   115,    81,   370,    -1,
      34,    81,   659,   370,    -1,   371,    -1,   370,   371,    -1,
     372,   135,   572,    -1,    82,    -1,    90,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    91,    -1,    87,    -1,
      88,    -1,    89,    -1,    34,    58,   659,    30,    -1,    34,
     268,   616,    -1,    34,   113,   155,   376,    -1,    96,   555,
     377,    -1,   377,    -1,   378,    -1,   140,    -1,   140,   378,
      -1,   145,   422,    -1,    34,   380,   145,   422,    -1,    34,
     380,   140,    -1,    34,   380,   140,   145,   422,    -1,   114,
     120,   659,    -1,   114,   120,   659,   552,    -1,   381,   114,
     120,   659,    -1,   381,   114,   120,   659,   552,    -1,   382,
      -1,   381,   382,    -1,    27,    -1,    27,   159,   383,   190,
      -1,    28,    -1,    28,   159,   383,   190,    -1,   512,    -1,
     383,   109,   512,    -1,    34,   385,    -1,    34,   381,   385,
      -1,   386,    -1,   387,    -1,    48,   660,   388,   405,    -1,
      48,   660,   388,   140,    -1,    76,    48,   660,   388,   405,
      -1,    76,    48,   660,   388,   140,    -1,   159,   190,    -1,
     159,   389,   190,    -1,   159,   190,    96,   553,    -1,   159,
     389,   190,    96,   553,    -1,   390,    -1,   389,   109,   390,
      -1,   120,   659,    -1,   120,   659,   552,    -1,    34,   294,
     659,    -1,    34,   294,   659,    96,   392,    -1,    34,   381,
     294,   659,    -1,    34,   381,   294,   659,    96,   392,    -1,
     559,    -1,   559,   554,    -1,   653,    -1,   653,   554,    -1,
      34,   302,   659,   306,   234,   503,   173,   394,    -1,    34,
     381,   302,   659,   306,   234,   503,   173,   394,    -1,   395,
      -1,   394,   109,   395,    -1,   503,    -1,   503,   552,    -1,
     503,   458,    -1,   503,   552,   458,    -1,    34,   310,   311,
     659,   306,   294,   659,   120,   659,   312,   422,    -1,    34,
     310,   311,   659,   306,   294,   659,   232,   120,   659,   312,
     300,   313,   503,    -1,    34,   310,   311,   659,   306,   294,
     659,   314,   232,   120,   659,   312,   422,    -1,    34,   310,
     311,   659,   315,   313,   264,   294,   659,   232,   120,   659,
     313,   503,   202,   294,   659,   232,   120,   659,   313,   503,
      -1,   398,    -1,   400,    -1,   401,    -1,    -1,   400,    -1,
     401,    -1,    -1,   421,    -1,   401,   421,    -1,   402,    -1,
     401,   402,    -1,   401,   421,   344,   402,    -1,   403,    -1,
     406,    -1,   409,    -1,   410,    -1,   411,    -1,   412,    -1,
     413,    -1,   414,    -1,   416,    -1,   470,    -1,   466,    -1,
     417,    -1,   420,    -1,   156,   401,   187,    -1,   156,   400,
     187,    -1,   156,   399,   187,    -1,   407,   193,    -1,   407,
     109,   408,    -1,   114,   408,    -1,   381,   114,   408,    -1,
     120,   659,    -1,   120,   659,   552,    -1,   120,   659,   145,
     422,    -1,   120,   659,   552,   145,   422,    -1,   120,   659,
     145,   422,   193,    -1,   423,   193,    -1,   247,   249,   422,
     193,    -1,   250,   159,   421,   190,   402,    -1,   245,   248,
     193,    -1,   246,   248,   193,    -1,   433,   415,    -1,   189,
     402,    -1,    49,   159,   421,   190,   201,   402,   129,   402,
      -1,   251,   403,   418,    -1,   419,    -1,   418,   419,    -1,
     252,   589,   403,    -1,   193,    -1,   422,    -1,   421,   109,
     422,    -1,   421,   344,   422,    -1,   424,    -1,   462,    -1,
     469,    -1,   476,    -1,   585,    -1,   423,    -1,   477,    -1,
     459,    -1,   578,    -1,   579,    -1,   581,    -1,   580,    -1,
     582,    -1,   650,    -1,   648,    -1,   651,    -1,   652,    -1,
     649,    -1,   433,   425,    -1,   189,   422,    -1,    68,   291,
      -1,    73,   291,    -1,   221,    -1,   261,    -1,    57,   261,
      -1,   427,   444,    79,   422,    -1,   427,    79,   422,    -1,
     435,   426,   443,   428,   428,    -1,   435,   426,   443,   428,
      -1,    43,   120,   659,    -1,   434,    -1,   440,    -1,   429,
      -1,   431,    -1,   447,    -1,   452,    -1,   448,    -1,   430,
      -1,   431,    -1,   433,   432,    -1,   435,   120,   436,    -1,
     435,     1,   436,    -1,   435,     3,    -1,    47,    -1,   264,
      -1,   437,    -1,   436,   109,   120,   437,    -1,   436,   109,
     437,    -1,   659,   150,   422,    -1,   659,    37,   130,   150,
     422,    -1,   659,   552,   150,   422,    -1,   659,   552,    37,
     130,   150,   422,    -1,   659,   438,   150,   422,    -1,   659,
      37,   130,   438,   150,   422,    -1,   659,   552,   438,   150,
     422,    -1,   659,   552,    37,   130,   438,   150,   422,    -1,
     659,   439,   150,   422,    -1,   659,   552,   439,   150,   422,
      -1,   659,   438,   439,   150,   422,    -1,   659,   552,   438,
     439,   150,   422,    -1,    98,   120,   659,    -1,   280,   120,
     659,    -1,    52,   441,    -1,   442,    -1,   441,   109,   442,
      -1,   120,   659,   145,   422,    -1,   120,   659,   552,   145,
     422,    -1,   439,   145,   422,    -1,   120,   659,   552,   439,
     145,   422,    -1,   120,   659,   150,   422,    -1,   120,   659,
     552,   150,   422,    -1,   445,    -1,   120,   659,    -1,   120,
     659,   445,    -1,   438,    -1,   438,   446,    -1,   446,    -1,
      60,   120,   659,    55,   120,   659,    -1,    55,   120,   659,
      -1,    60,   120,   659,    -1,   215,   422,    -1,   174,   173,
     449,    -1,   450,    -1,   449,   109,   450,    -1,   120,   659,
      -1,   120,   659,   145,   422,    -1,   120,   659,   552,   145,
     422,    -1,   120,   659,   552,   145,   422,   451,    -1,   120,
     659,   145,   422,   451,    -1,   120,   659,   451,    -1,   108,
     657,    -1,   171,   173,   453,    -1,    71,   171,   173,   453,
      -1,   454,    -1,   453,   109,   454,    -1,   422,    -1,   422,
     455,    -1,   456,    -1,   457,    -1,   458,    -1,   456,   457,
      -1,   456,   458,    -1,   457,   458,    -1,   456,   457,   458,
      -1,    97,    -1,   118,    -1,   130,   131,    -1,   130,   132,
      -1,   108,   657,    -1,    69,   120,   460,   191,   422,    -1,
     138,   120,   460,   191,   422,    -1,   461,    -1,   460,   109,
     120,   461,    -1,   659,   150,   422,    -1,   659,   552,   150,
     422,    -1,    74,   159,   421,   190,   463,   115,   189,   422,
      -1,   464,    -1,   463,   464,    -1,   465,   189,   422,    -1,
     102,   422,    -1,   465,   102,   422,    -1,    74,   159,   421,
     190,   467,   115,   189,   402,    -1,   468,    -1,   467,   468,
      -1,   465,   189,   402,    -1,    75,   159,   421,   190,   471,
     115,   189,   422,    -1,    75,   159,   421,   190,   471,   115,
     120,   659,   189,   422,    -1,    75,   159,   421,   190,   473,
     115,   189,   402,    -1,    75,   159,   421,   190,   471,   115,
     120,   659,   189,   402,    -1,   472,    -1,   471,   472,    -1,
     102,   475,   189,   422,    -1,   102,   120,   659,    96,   475,
     189,   422,    -1,   474,    -1,   473,   474,    -1,   102,   475,
     189,   402,    -1,   102,   120,   659,    96,   475,   189,   402,
      -1,   553,    -1,   475,   213,   553,    -1,    49,   159,   421,
     190,   201,   422,   129,   422,    -1,   478,    -1,   477,   170,
     478,    -1,   479,    -1,   478,    94,   479,    -1,   480,    -1,
     267,   479,    -1,   481,    -1,   481,   498,   481,    -1,   482,
      -1,   482,   256,    72,   590,   483,    -1,   484,    -1,   484,
     101,   482,    -1,    -1,   642,    -1,   485,    -1,   485,   202,
     485,    -1,   486,    -1,   485,   179,   486,    -1,   485,   161,
     486,    -1,   487,    -1,   486,   197,   487,    -1,   486,   119,
     487,    -1,   486,   149,   487,    -1,   486,   162,   487,    -1,
     488,    -1,   487,   204,   488,    -1,   487,   213,   488,    -1,
     489,    -1,   488,   153,   489,    -1,   488,   139,   489,    -1,
     490,    -1,   490,    51,   238,   553,    -1,   491,    -1,   491,
     203,    96,   553,    -1,   492,    -1,   492,   103,    96,   493,
      -1,   494,    -1,   494,   104,    96,   493,    -1,   558,    -1,
     558,   147,    -1,   496,    -1,   495,   496,    -1,   179,    -1,
     161,    -1,   495,   179,    -1,   495,   161,    -1,   499,    -1,
     497,    -1,   500,    -1,   503,    -1,   497,   196,   503,    -1,
     206,    -1,   211,    -1,   210,    -1,   209,    -1,   208,    -1,
     207,    -1,    77,   156,   400,   187,    -1,    77,   229,   156,
     400,   187,    -1,    77,   228,   156,   400,   187,    -1,    77,
      78,   570,   156,   400,   187,    -1,   501,   156,   187,    -1,
     501,   156,   421,   187,    -1,   502,    -1,   501,   502,    -1,
     180,   659,    17,    -1,   180,    18,    -1,   180,    19,    -1,
     504,    -1,   505,    -1,   508,    -1,   659,    -1,   507,    -1,
     197,    -1,    11,    -1,    12,    -1,    20,    -1,   511,    -1,
     508,   509,    -1,   508,   159,   190,    -1,   508,   159,   521,
     190,    -1,   508,   122,   658,    -1,   508,   122,   516,    -1,
     508,   122,   515,    -1,   508,   122,   572,    -1,   510,    -1,
     509,   510,    -1,   157,   421,   188,    -1,   512,    -1,   515,
      -1,   516,    -1,   517,    -1,   520,    -1,   525,    -1,   518,
      -1,   519,    -1,   522,    -1,   404,    -1,   646,    -1,   643,
      -1,   644,    -1,   645,    -1,   513,    -1,   572,    -1,   514,
      -1,   222,    -1,   112,    -1,   152,    -1,   127,    -1,   223,
      -1,   224,    -1,   120,   659,    -1,   159,   190,    -1,   159,
     421,   190,    -1,   122,    -1,   121,    -1,   172,   156,   421,
     187,    -1,   205,   156,   421,   187,    -1,   660,   159,   190,
      -1,   660,   159,   521,   190,    -1,   147,    -1,   521,   109,
     147,    -1,   422,    -1,   521,   109,   422,    -1,   523,    -1,
     524,    -1,   659,   148,   152,    -1,    48,   388,   405,    -1,
     526,    -1,   544,    -1,   527,    -1,   541,    -1,   542,    -1,
     160,   659,   531,   133,    -1,   160,   659,   531,   200,   198,
     659,   531,   200,    -1,   160,   659,   529,   531,   133,    -1,
     160,   659,   529,   531,   200,   198,   659,   531,   200,    -1,
     160,   659,   531,   200,   528,   198,   659,   531,   200,    -1,
     160,   659,   529,   531,   200,   528,   198,   659,   531,   200,
      -1,   539,    -1,   528,   539,    -1,   530,    -1,   529,   530,
      -1,    36,   659,   531,   135,   531,   532,    -1,    -1,    36,
      -1,   186,   533,   186,    -1,    95,   535,    95,    -1,    -1,
     534,    -1,   137,    -1,   537,    -1,   534,   137,    -1,   534,
     537,    -1,    -1,   536,    -1,   136,    -1,   538,    -1,   536,
     136,    -1,   536,   538,    -1,    29,    -1,   540,    -1,     5,
      -1,   540,    -1,   526,    -1,    10,    -1,   543,    -1,   540,
      -1,     9,    -1,   126,    -1,   128,    -1,   156,   400,   187,
      -1,   216,    31,   217,    -1,   216,   217,    -1,   177,   658,
     178,    -1,   177,   658,     8,    -1,   105,     7,    -1,   545,
      -1,   546,    -1,   547,    -1,   548,    -1,   549,    -1,   550,
      -1,   551,    -1,    44,   156,   400,   187,    -1,    21,   399,
     187,    -1,    46,   156,   421,   187,   156,   399,   187,    -1,
      22,   399,   187,    -1,    99,   156,   421,   187,   156,   399,
     187,    -1,    72,   156,   400,   187,    -1,    40,   156,   400,
     187,    -1,    23,   399,   187,    -1,    61,   156,   421,   187,
     156,   399,   187,    -1,    24,   400,   187,    -1,   163,   156,
     421,   187,   156,   400,   187,    -1,    96,   553,    -1,   555,
      -1,   555,   554,    -1,   214,   159,   190,    -1,   159,   190,
      -1,   147,    -1,   197,    -1,   179,    -1,   557,    -1,   559,
      -1,   155,   159,   190,    -1,   155,    -1,   327,   159,   190,
      -1,   327,    -1,   573,    -1,   576,    -1,   653,    -1,   553,
      -1,   556,   109,   553,    -1,   659,    -1,   659,    -1,   561,
      -1,   568,    -1,   566,    -1,   569,    -1,   567,    -1,   565,
      -1,   564,    -1,   563,    -1,   562,    -1,   560,    -1,   232,
     159,   190,    -1,    45,   159,   190,    -1,    45,   159,   568,
     190,    -1,    45,   159,   569,   190,    -1,    54,   159,   190,
      -1,    72,   159,   190,    -1,    40,   159,   190,    -1,    61,
     159,   190,    -1,    61,   159,   658,   190,    -1,    61,   159,
      30,   190,    -1,    99,   159,   190,    -1,    99,   159,   659,
     190,    -1,    99,   159,   659,   109,   570,   190,    -1,    99,
     159,   197,   190,    -1,    99,   159,   197,   109,   570,   190,
      -1,    63,   159,   659,   190,    -1,    46,   159,   190,    -1,
      46,   159,   659,   190,    -1,    46,   159,   659,   109,   570,
     190,    -1,    46,   159,   659,   109,   571,   190,    -1,    46,
     159,   197,   190,    -1,    46,   159,   197,   109,   570,   190,
      -1,    46,   159,   197,   109,   571,   190,    -1,    64,   159,
     659,   190,    -1,   659,    -1,   659,   147,    -1,    30,    -1,
     574,    -1,   575,    -1,    48,   159,   197,   190,    -1,    48,
     159,   190,    96,   553,    -1,    48,   159,   556,   190,    96,
     553,    -1,   159,   555,   190,    -1,    34,   227,   228,    -1,
      34,   227,   229,    -1,    34,   227,   230,    -1,   233,   232,
     422,   240,   422,    -1,   233,   232,   422,    96,   239,   240,
     422,    -1,   233,   232,   422,    96,   241,   240,   422,    -1,
     233,   232,   422,   225,   422,    -1,   233,   232,   422,   226,
     422,    -1,   233,   234,   422,   240,   422,    -1,   233,   234,
     422,    96,   239,   240,   422,    -1,   233,   234,   422,    96,
     241,   240,   422,    -1,   233,   234,   422,   225,   422,    -1,
     233,   234,   422,   226,   422,    -1,   231,   232,   422,    -1,
     231,   234,   422,    -1,   236,   232,   422,   244,   422,    -1,
     236,   237,   238,   232,   422,   244,   422,    -1,   235,   232,
     422,    96,   422,    -1,   243,   120,   583,   242,   422,   189,
     422,    -1,   584,    -1,   583,   109,   120,   584,    -1,   659,
     145,   422,    -1,   251,   156,   421,   187,   586,    -1,   587,
      -1,   586,   587,    -1,   252,   589,   588,    -1,   156,   421,
     187,    -1,   506,    -1,   589,   213,   506,    -1,   593,   591,
      -1,    -1,   592,    -1,   611,    -1,   592,   611,    -1,   594,
      -1,   593,   269,   594,    -1,   595,    -1,   594,   265,   595,
      -1,   596,    -1,   595,   267,   150,   596,    -1,   597,    -1,
     266,   597,    -1,   601,   598,   599,    -1,    -1,   616,    -1,
      -1,   600,    -1,   289,   156,   421,   187,    -1,   605,   602,
      -1,   159,   590,   190,    -1,   603,    -1,    -1,   638,    -1,
     501,   156,   604,   187,    -1,    -1,   590,    -1,   606,   607,
      -1,   512,    -1,   156,   421,   187,    -1,    -1,   608,    -1,
     255,   609,    -1,   254,   610,    -1,   277,    -1,    -1,    80,
      -1,    -1,   293,    -1,   612,    -1,   613,    -1,   614,    -1,
     640,    -1,   637,    -1,   172,    -1,   291,   485,   615,    -1,
     260,   639,   615,    -1,   293,    -1,   283,    -1,   276,    -1,
     253,   617,    -1,   616,   253,   617,    -1,   618,    -1,   619,
      -1,   620,    -1,   635,    -1,   621,    -1,   629,    -1,   622,
      -1,   636,    -1,   102,   281,    -1,   102,   270,    -1,   273,
      -1,   288,    -1,   258,   281,    -1,   258,   270,    -1,    58,
     659,    30,    -1,   284,    -1,    56,   284,    -1,   286,   623,
      -1,   286,   159,   623,   624,   190,    -1,    56,   286,    -1,
     626,    -1,   115,    -1,    -1,   109,   625,    -1,   626,    -1,
     625,   109,   626,    -1,    98,    30,   627,   628,    -1,    -1,
     278,    30,    -1,    -1,   639,   272,    -1,   285,   293,   630,
     632,    -1,   285,   293,   115,   632,    -1,    56,   285,   293,
      -1,    98,    30,    -1,   159,   631,   190,    -1,    30,    -1,
     631,   109,    30,    -1,    -1,   633,    -1,   634,    -1,   633,
     634,    -1,   204,   630,    -1,   139,   630,    -1,   271,    30,
      -1,   290,    -1,    56,   290,    -1,    98,   221,    -1,    98,
     261,    -1,   262,   257,    -1,   274,   639,   287,    -1,   263,
     485,    -1,    98,   132,   485,    -1,    98,    53,   485,    -1,
     264,   485,   202,   485,    -1,   279,   641,    -1,   259,   641,
      -1,   282,    -1,   275,    -1,   292,   257,   487,    -1,   157,
     188,    -1,   157,   421,   188,    -1,   317,   318,    -1,   317,
     421,   318,    -1,   319,   320,    -1,   319,   421,   320,    -1,
     156,   647,   187,    -1,   156,   187,    -1,   658,   124,   422,
      -1,   422,   124,   422,    -1,   647,   109,   422,   124,   422,
      -1,   647,   109,   658,   124,   422,    -1,   233,   321,   422,
     240,   422,    -1,   233,   321,   647,   240,   422,    -1,   233,
     321,   422,   240,   422,    98,   323,   422,    -1,   233,   422,
     240,   422,    -1,   233,   647,   240,   422,    -1,   233,   422,
     240,   422,    98,   323,   422,    -1,   322,   321,   422,   240,
     422,    -1,   322,   422,   240,   422,    -1,   231,   321,   508,
      -1,   231,   508,    -1,   235,   321,   508,    96,   422,    -1,
     235,   508,    96,   422,    -1,   236,   321,   237,   238,   508,
     244,   422,    -1,   236,   237,   238,   508,   244,   422,    -1,
     654,    -1,   655,    -1,   656,    -1,   326,   159,   190,    -1,
     326,    -1,   324,   159,   190,    -1,   324,    -1,   325,   159,
     190,    -1,   325,    -1,    30,    -1,    16,    -1,   659,    -1,
     660,    -1,    99,    -1,    40,    -1,    45,    -1,    54,    -1,
      46,    -1,    49,    -1,   232,    -1,    61,    -1,    63,    -1,
      64,    -1,    72,    -1,    75,    -1,    74,    -1,   214,    -1,
     250,    -1,   661,    -1,    25,    -1,   218,    -1,   130,    -1,
      39,    -1,   268,    -1,    38,    -1,   229,    -1,   228,    -1,
     149,    -1,    44,    -1,   266,    -1,   267,    -1,   281,    -1,
     270,    -1,   258,    -1,   292,    -1,   284,    -1,   286,    -1,
     285,    -1,   290,    -1,   262,    -1,   257,    -1,    80,    -1,
     221,    -1,   261,    -1,    53,    -1,   230,    -1,   243,    -1,
     309,    -1,   237,    -1,   206,    -1,   211,    -1,   210,    -1,
     209,    -1,   208,    -1,   207,    -1,    98,    -1,   113,    -1,
     114,    -1,   189,    -1,    47,    -1,    37,    -1,    68,    -1,
      73,    -1,    60,    -1,    55,    -1,    57,    -1,    79,    -1,
      43,    -1,   150,    -1,    52,    -1,   215,    -1,   173,    -1,
     174,    -1,   171,    -1,    71,    -1,    97,    -1,   118,    -1,
     131,    -1,   132,    -1,   108,    -1,    69,    -1,   138,    -1,
     191,    -1,   102,    -1,    96,    -1,   201,    -1,   129,    -1,
     170,    -1,    94,    -1,    51,    -1,   238,    -1,   103,    -1,
     202,    -1,   119,    -1,   162,    -1,   204,    -1,   153,    -1,
     139,    -1,    77,    -1,    78,    -1,   104,    -1,   203,    -1,
     154,    -1,   185,    -1,   199,    -1,   163,    -1,   140,    -1,
     134,    -1,   169,    -1,   151,    -1,   168,    -1,    34,    -1,
      41,    -1,    59,    -1,   115,    -1,    42,    -1,    58,    -1,
     220,    -1,    50,    -1,    62,    -1,    35,    -1,    48,    -1,
     280,    -1,   256,    -1,   289,    -1,   291,    -1,   260,    -1,
     274,    -1,   287,    -1,   279,    -1,   259,    -1,   273,    -1,
     288,    -1,   278,    -1,   272,    -1,   271,    -1,   255,    -1,
     254,    -1,   263,    -1,   264,    -1,   293,    -1,   283,    -1,
     282,    -1,   277,    -1,   275,    -1,   276,    -1,   242,    -1,
     239,    -1,   226,    -1,   225,    -1,   227,    -1,   244,    -1,
     234,    -1,   241,    -1,   240,    -1,    67,    -1,    65,    -1,
      76,    -1,   172,    -1,   205,    -1,   249,    -1,   247,    -1,
     248,    -1,   245,    -1,   246,    -1,   251,    -1,   252,    -1,
     253,    -1,    66,    -1,   302,    -1,   300,    -1,   301,    -1,
     306,    -1,   307,    -1,   308,    -1,   303,    -1,   304,    -1,
     305,    -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,
      90,    -1,    91,    -1,   294,    -1,   295,    -1,   296,    -1,
     297,    -1,   298,    -1,   299,    -1,   310,    -1,   311,    -1,
     312,    -1,   313,    -1,   314,    -1,   315,    -1,   316,    -1,
      92,    -1,   107,    -1,   116,    -1,   175,    -1,   183,    -1,
     192,    -1,   141,    -1,    93,    -1,   117,    -1,   142,    -1,
     184,    -1,   323,    -1,    26,    -1
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
    1374,  1378,  1380,  1383,  1385,  1389,  1391,  1397,  1399,  1403,
    1404,  1406,  1408,  1412,  1414,  1418,  1422,  1424,  1428,  1432,
    1436,  1440,  1442,  1446,  1450,  1452,  1456,  1460,  1462,  1467,
    1469,  1474,  1476,  1481,  1483,  1488,  1490,  1493,  1495,  1498,
    1500,  1502,  1505,  1508,  1510,  1512,  1514,  1516,  1520,  1522,
    1524,  1526,  1528,  1530,  1532,  1537,  1543,  1549,  1556,  1560,
    1565,  1567,  1570,  1574,  1577,  1580,  1582,  1584,  1586,  1588,
    1590,  1592,  1594,  1596,  1598,  1600,  1603,  1607,  1612,  1616,
    1620,  1624,  1628,  1630,  1633,  1637,  1639,  1641,  1643,  1645,
    1647,  1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,  1665,
    1667,  1669,  1671,  1673,  1675,  1677,  1679,  1681,  1683,  1686,
    1689,  1693,  1695,  1697,  1702,  1707,  1711,  1716,  1718,  1722,
    1724,  1728,  1730,  1732,  1736,  1740,  1742,  1744,  1746,  1748,
    1750,  1755,  1764,  1770,  1780,  1790,  1801,  1803,  1806,  1808,
    1811,  1818,  1819,  1821,  1825,  1829,  1830,  1832,  1834,  1836,
    1839,  1842,  1843,  1845,  1847,  1849,  1852,  1855,  1857,  1859,
    1861,  1863,  1865,  1867,  1869,  1871,  1873,  1875,  1877,  1881,
    1885,  1888,  1892,  1896,  1899,  1901,  1903,  1905,  1907,  1909,
    1911,  1913,  1918,  1922,  1930,  1934,  1942,  1947,  1952,  1956,
    1964,  1968,  1976,  1979,  1981,  1984,  1988,  1991,  1993,  1995,
    1997,  1999,  2001,  2005,  2007,  2011,  2013,  2015,  2017,  2019,
    2021,  2025,  2027,  2029,  2031,  2033,  2035,  2037,  2039,  2041,
    2043,  2045,  2047,  2049,  2053,  2057,  2062,  2067,  2071,  2075,
    2079,  2083,  2088,  2093,  2097,  2102,  2109,  2114,  2121,  2126,
    2130,  2135,  2142,  2149,  2154,  2161,  2168,  2173,  2175,  2178,
    2180,  2182,  2184,  2189,  2195,  2202,  2206,  2210,  2214,  2218,
    2224,  2232,  2240,  2246,  2252,  2258,  2266,  2274,  2280,  2286,
    2290,  2294,  2300,  2308,  2314,  2322,  2324,  2329,  2333,  2339,
    2341,  2344,  2348,  2352,  2354,  2358,  2361,  2362,  2364,  2366,
    2369,  2371,  2375,  2377,  2381,  2383,  2388,  2390,  2393,  2397,
    2398,  2400,  2401,  2403,  2408,  2411,  2415,  2417,  2418,  2420,
    2425,  2426,  2428,  2431,  2433,  2437,  2438,  2440,  2443,  2446,
    2448,  2449,  2451,  2452,  2454,  2456,  2458,  2460,  2462,  2464,
    2466,  2470,  2474,  2476,  2478,  2480,  2483,  2487,  2489,  2491,
    2493,  2495,  2497,  2499,  2501,  2503,  2506,  2509,  2511,  2513,
    2516,  2519,  2523,  2525,  2528,  2531,  2537,  2540,  2542,  2544,
    2545,  2548,  2550,  2554,  2559,  2560,  2563,  2564,  2567,  2572,
    2577,  2581,  2584,  2588,  2590,  2594,  2595,  2597,  2599,  2602,
    2605,  2608,  2611,  2613,  2616,  2619,  2622,  2625,  2629,  2632,
    2636,  2640,  2645,  2648,  2651,  2653,  2655,  2659,  2662,  2666,
    2669,  2673,  2676,  2680,  2684,  2687,  2691,  2695,  2701,  2707,
    2713,  2719,  2728,  2733,  2738,  2746,  2752,  2757,  2761,  2764,
    2770,  2775,  2783,  2790,  2792,  2794,  2796,  2800,  2802,  2806,
    2808,  2812,  2814,  2816,  2818,  2820,  2822,  2824,  2826,  2828,
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
    3210,  3212,  3214,  3216,  3218,  3220,  3222,  3224,  3226,  3228,
    3230,  3232,  3234,  3236,  3238,  3240,  3242,  3244
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,  1069,  1069,  1070,  1074,  1078,  1086,  1092,  1096,  1105,
    1111,  1119,  1125,  1136,  1141,  1145,  1150,  1159,  1166,  1173,
    1182,  1189,  1197,  1205,  1213,  1224,  1229,  1236,  1243,  1255,
    1265,  1272,  1279,  1291,  1292,  1293,  1294,  1295,  1300,  1301,
    1302,  1303,  1304,  1305,  1306,  1309,  1314,  1319,  1327,  1335,
    1343,  1348,  1356,  1361,  1369,  1374,  1382,  1387,  1392,  1397,
    1405,  1407,  1410,  1420,  1425,  1433,  1441,  1452,  1459,  1470,
    1475,  1483,  1490,  1497,  1506,  1519,  1527,  1534,  1544,  1551,
    1558,  1569,  1570,  1571,  1572,  1573,  1574,  1575,  1576,  1581,
    1587,  1596,  1603,  1613,  1623,  1624,  1625,  1626,  1627,  1628,
    1629,  1630,  1631,  1632,  1637,  1645,  1653,  1661,  1668,  1676,
    1683,  1688,  1696,  1704,  1718,  1732,  1749,  1754,  1762,  1770,
    1781,  1786,  1795,  1800,  1807,  1812,  1822,  1827,  1836,  1842,
    1855,  1860,  1868,  1879,  1894,  1906,  1921,  1926,  1931,  1936,
    1944,  1951,  1962,  1967,  1977,  1986,  1995,  2004,  2016,  2020,
    2026,  2030,  2040,  2050,  2063,  2069,  2078,  2083,  2090,  2097,
    2108,  2118,  2128,  2138,  2156,  2176,  2180,  2185,  2192,  2196,
    2201,  2208,  2213,  2225,  2232,  2242,  2257,  2258,  2259,  2260,
    2261,  2262,  2263,  2265,  2266,  2267,  2268,  2269,  2270,  2275,
    2283,  2300,  2308,  2316,  2323,  2330,  2341,  2350,  2359,  2368,
    2381,  2389,  2397,  2405,  2420,  2425,  2433,  2447,  2464,  2489,
    2497,  2504,  2515,  2524,  2531,  2536,  2549,  2566,  2567,  2568,
    2569,  2570,  2571,  2576,  2577,  2580,  2581,  2582,  2583,  2584,
    2587,  2588,  2589,  2590,  2591,  2596,  2610,  2618,  2623,  2631,
    2636,  2641,  2649,  2658,  2670,  2680,  2693,  2701,  2702,  2703,
    2708,  2709,  2710,  2711,  2712,  2717,  2724,  2734,  2740,  2749,
    2758,  2759,  2767,  2774,  2782,  2794,  2804,  2814,  2824,  2834,
    2844,  2854,  2864,  2875,  2884,  2894,  2904,  2920,  2929,  2938,
    2946,  2952,  2964,  2972,  2982,  2990,  3002,  3008,  3019,  3021,
    3025,  3033,  3037,  3042,  3046,  3050,  3054,  3064,  3072,  3079,
    3085,  3095,  3099,  3103,  3111,  3119,  3127,  3139,  3147,  3153,
    3163,  3169,  3179,  3183,  3193,  3199,  3205,  3211,  3220,  3229,
    3238,  3251,  3255,  3263,  3269,  3279,  3287,  3296,  3309,  3316,
    3328,  3332,  3344,  3351,  3357,  3366,  3373,  3379,  3390,  3397,
    3403,  3412,  3421,  3428,  3439,  3446,  3458,  3464,  3476,  3482,
    3493,  3499,  3510,  3516,  3527,  3533,  3544,  3553,  3557,  3566,
    3570,  3577,  3581,  3594,  3598,  3678,  3682,  3694,  3698,  3706,
    3709,  3716,  3720,  3729,  3733,  3737,  3745,  3749,  3755,  3761,
    3767,  3777,  3781,  3785,  3793,  3797,  3803,  3813,  3817,  3827,
    3831,  3841,  3845,  3855,  3859,  3869,  3873,  3882,  3886,  3894,
    3898,  3902,  3906,  3916,  3920,  3924,  3931,  3936,  3944,  3948,
    3952,  3956,  3960,  3964,  3988,  3992,  3996,  4000,  4011,  4017,
    4027,  4033,  4043,  4047,  4051,  4114,  4136,  4164,  4328,  4332,
    4342,  4346,  4350,  4354,  4363,  4367,  4371,  4375,  4379,  4384,
    4388,  4392,  4401,  4407,  4417,  4425,  4429,  4433,  4437,  4441,
    4445,  4449,  4453,  4457,  4461,  4466,  4470,  4474,  4478,  4486,
    4490,  4494,  4498,  4506,  4513,  4520,  4530,  4534,  4542,  4550,
    4554,  4562,  4566,  4574,  4582,  4636,  4640,  4662,  4668,  4674,
    4680,  4690,  4694,  4702,  4710,  4722,  4726,  4734,  4738,  4742,
    4750,  4758,  4775,  4783,  4800,  4819,  4843,  4849,  4860,  4866,
    4877,  4886,  4888,  4892,  4897,  4907,  4910,  4917,  4923,  4929,
    4936,  4948,  4951,  4958,  4964,  4970,  4977,  4988,  4992,  5000,
    5004,  5012,  5016,  5020,  5025,  5034,  5038,  5042,  5046,  5054,
    5059,  5067,  5072,  5080,  5088,  5093,  5098,  5103,  5108,  5113,
    5118,  5124,  5132,  5136,  5153,  5157,  5165,  5173,  5181,  5185,
    5193,  5197,  5205,  5213,  5217,  5221,  5226,  5261,  5267,  5273,
    5283,  5287,  5291,  5296,  5300,  5305,  5309,  5313,  5317,  5324,
    5330,  5340,  5348,  5356,  5360,  5364,  5368,  5372,  5376,  5380,
    5384,  5388,  5392,  5400,  5408,  5412,  5416,  5424,  5431,  5439,
    5447,  5451,  5455,  5463,  5467,  5473,  5479,  5483,  5493,  5501,
    5505,  5511,  5520,  5529,  5535,  5541,  5551,  5568,  5575,  5590,
    5617,  5621,  5629,  5637,  5641,  5652,  5669,  5675,  5681,  5691,
    5695,  5701,  5707,  5711,  5717,  5721,  5727,  5733,  5740,  5750,
    5755,  5763,  5769,  5779,  5801,  5810,  5816,  5829,  5843,  5850,
    5856,  5866,  5875,  5883,  5889,  5907,  5915,  5919,  5926,  5931,
    5939,  5943,  5950,  5954,  5961,  5965,  5972,  5976,  5985,  5998,
    6001,  6009,  6012,  6020,  6028,  6036,  6040,  6048,  6051,  6059,
    6071,  6074,  6082,  6094,  6100,  6110,  6113,  6121,  6125,  6129,
    6137,  6140,  6148,  6151,  6159,  6163,  6167,  6171,  6175,  6183,
    6191,  6203,  6215,  6219,  6223,  6231,  6237,  6247,  6251,  6255,
    6259,  6263,  6267,  6271,  6275,  6283,  6287,  6291,  6295,  6303,
    6309,  6319,  6329,  6333,  6341,  6351,  6362,  6369,  6373,  6381,
    6384,  6391,  6396,  6405,  6415,  6418,  6425,  6429,  6437,  6446,
    6453,  6463,  6467,  6474,  6480,  6490,  6493,  6500,  6505,  6517,
    6525,  6537,  6545,  6549,  6557,  6561,  6565,  6573,  6581,  6585,
    6589,  6593,  6601,  6609,  6621,  6625,  6633,  6647,  6651,  6658,
    6663,  6671,  6676,  6685,  6690,  6697,  6704,  6710,  6717,  6728,
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
     335,   336,   337,   338,   339,   340,   341
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int jsoniq_parser::yyeof_ = 0;
  const int jsoniq_parser::yylast_ = 19243;
  const int jsoniq_parser::yynnts_ = 320;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 547;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 342;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 596;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 18001 "/home/colea/xquery_bzr/feature-empty_object/build/src/compiler/parser/jsoniq_parser.cpp"


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

