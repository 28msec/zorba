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
#line 908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1039 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"

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
#line 906 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 905 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 340: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 341: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 342: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 343: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 344: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 371: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 391: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 406: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 407: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 424: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 426: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 431: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 434: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 467: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 473: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 479: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 514: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 522: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 523: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 524: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 531: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 573: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 576: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 577: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 592: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 604: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 607: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 608: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 609: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 610: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 627: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 628: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 631: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 632: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 633: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 641: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 653: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1057 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1061 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1065 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1079 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1083 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1098 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1106 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1112 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1123 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1128 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1143 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1159 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1174 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1190 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1201 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1206 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1220 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1232 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1242 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1249 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1256 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1291 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1296 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1304 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1320 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1333 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1338 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1346 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1351 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1359 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1364 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1369 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1374 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1387 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1402 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1418 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1429 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1436 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1447 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1460 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1467 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1474 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1483 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1496 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1504 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1511 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1521 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1528 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1535 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1564 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1573 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1580 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1590 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1599 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1601 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1602 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1605 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1606 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1607 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1608 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1638 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1653 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1660 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1665 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1673 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1681 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1695 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1709 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1726 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1731 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1739 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1747 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1758 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1763 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1772 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1777 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1784 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1789 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1799 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1804 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1813 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1819 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1832 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1837 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1845 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1856 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1871 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1883 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1898 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1903 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1921 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1944 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1954 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1963 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1972 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1981 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 1993 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1997 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2003 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2007 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2017 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2027 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2040 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2055 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2060 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2067 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2074 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2086 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2096 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2106 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2117 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2133 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2153 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2157 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2161 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2173 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2177 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2185 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2190 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2202 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2209 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2219 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2251 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2256 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2264 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2281 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2289 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2297 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2304 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2311 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2322 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2331 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2340 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2349 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2362 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2370 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2378 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2386 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2401 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2406 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2414 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2428 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2445 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2470 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2478 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2485 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2496 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2506 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2511 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2524 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2571 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2585 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2593 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2598 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2606 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2611 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2616 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2624 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2633 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2645 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2655 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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
#line 2668 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2692 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2699 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2709 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2714 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2720 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2729 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2739 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2746 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 260:

/* Line 690 of lalr1.cc  */
#line 2754 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2766 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 262:

/* Line 690 of lalr1.cc  */
#line 2776 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 263:

/* Line 690 of lalr1.cc  */
#line 2786 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 264:

/* Line 690 of lalr1.cc  */
#line 2796 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 265:

/* Line 690 of lalr1.cc  */
#line 2806 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 266:

/* Line 690 of lalr1.cc  */
#line 2816 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 267:

/* Line 690 of lalr1.cc  */
#line 2826 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 268:

/* Line 690 of lalr1.cc  */
#line 2836 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 269:

/* Line 690 of lalr1.cc  */
#line 2847 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2856 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 271:

/* Line 690 of lalr1.cc  */
#line 2866 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 272:

/* Line 690 of lalr1.cc  */
#line 2876 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 273:

/* Line 690 of lalr1.cc  */
#line 2892 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2901 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2910 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2918 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2924 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2944 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2954 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2962 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2974 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2980 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2993 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2997 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3005 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 3009 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3018 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3022 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3026 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3036 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3044 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3057 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3067 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3071 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3075 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3083 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3091 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3099 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3111 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3119 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3125 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3135 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3141 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3151 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3155 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3165 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3171 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3177 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3183 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3192 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3201 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3210 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3223 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3227 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3235 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3241 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3251 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3259 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3268 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3281 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3288 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3300 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3304 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3316 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3323 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3329 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3338 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3345 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3351 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3362 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3369 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3375 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3384 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3393 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3400 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3411 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3418 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3430 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3436 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3448 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3454 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3465 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3471 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3482 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3488 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3499 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3505 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3516 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3525 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3529 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3538 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3542 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3550 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3554 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 359:

/* Line 690 of lalr1.cc  */
#line 3564 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3571 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3580 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3589 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3594 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3603 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3612 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3621 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3634 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3638 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3650 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3654 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3661 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3665 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3672 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3676 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3685 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3689 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3693 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3701 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3705 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3711 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3717 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3723 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3733 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3737 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3741 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3749 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3753 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3759 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3769 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3773 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3783 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3787 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3797 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3801 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3811 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3815 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3825 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3829 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3838 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3842 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3850 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3854 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3858 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3862 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3872 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3876 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3880 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3892 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3900 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3912 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3916 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3932 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3944 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3948 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3952 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3956 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3967 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3973 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3983 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3989 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3999 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4003 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4007 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4070 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4092 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 432:

/* Line 690 of lalr1.cc  */
#line 4120 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4284 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4288 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4298 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4302 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4306 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4310 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4319 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4323 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4327 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4331 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4339 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4345 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4355 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4363 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4367 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4371 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4375 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4379 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4383 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4387 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4391 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4395 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4399 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4404 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4408 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4412 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4416 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4420 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
          ArgList *al = new ArgList( LOC((yyloc)) );
          al->push_back(sl);
          (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), al); 
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4431 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4435 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4443 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4450 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4457 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4468 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4476 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4480 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4488 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4496 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4504 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4558 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4562 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                            dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4572 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4578 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4588 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4592 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4600 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4604 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4608 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4616 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4624 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 483:

/* Line 690 of lalr1.cc  */
#line 4641 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4649 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 485:

/* Line 690 of lalr1.cc  */
#line 4668 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 486:

/* Line 690 of lalr1.cc  */
#line 4687 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 487:

/* Line 690 of lalr1.cc  */
#line 4709 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4715 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4726 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4732 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4743 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4758 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4763 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4772 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4776 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4783 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4789 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4795 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4802 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4813 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4817 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4824 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4830 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4836 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4843 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4854 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4858 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4866 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4870 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4878 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4882 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4886 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4891 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4900 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4912 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4925 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4946 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4954 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4959 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4964 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4969 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4974 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4979 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4990 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4998 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 5002 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 5019 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 5023 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 5031 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 5039 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 5047 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 5051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 5059 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 5063 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 5071 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 5079 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 5083 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 5087 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 5122 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 5128 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 5134 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 5144 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 5148 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 5152 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 5156 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 5160 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 5164 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 5168 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 5175 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5181 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5191 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5199 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5215 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5219 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5223 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5227 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5231 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5235 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5239 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5243 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5251 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5259 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5263 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5267 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5275 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5282 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5290 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5298 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5302 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5306 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5314 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5324 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5330 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5334 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5344 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5352 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5356 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5362 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5371 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5380 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5386 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5392 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5402 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5419 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5426 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5441 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5477 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5481 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5489 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5497 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5509 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5513 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5521 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5529 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5533 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5544 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5561 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5567 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5573 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5583 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5587 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5593 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5599 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5603 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5609 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5613 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5625 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5632 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5647 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5655 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5661 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5693 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5702 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5721 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5742 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5748 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5767 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5775 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5781 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5807 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5811 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5818 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5823 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5831 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5835 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5842 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5846 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5853 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5857 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5864 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5868 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5877 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5889 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5893 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5900 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5912 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5932 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5962 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5966 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5974 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5986 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5992 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 6001 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 6005 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 6013 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 6017 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 6021 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6028 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6032 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 6039 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6043 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6051 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6055 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6059 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6063 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6067 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6075 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6083 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6095 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6107 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6111 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6115 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6123 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6129 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6139 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6143 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6147 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6151 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6155 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
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
#line 6175 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6179 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6183 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6187 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6195 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6201 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6211 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6221 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6225 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6233 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 707:

/* Line 690 of lalr1.cc  */
#line 6243 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 708:

/* Line 690 of lalr1.cc  */
#line 6254 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6261 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6265 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6272 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6276 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6283 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6288 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6297 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6306 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6310 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6317 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6321 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6329 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6338 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6345 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6355 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6359 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6366 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6372 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6381 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6385 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6392 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6397 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6409 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6417 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6429 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6437 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6441 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6449 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6453 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6457 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6465 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6473 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6477 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6481 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6485 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6493 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6501 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6513 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6517 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6525 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6539 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6543 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6550 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6555 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6563 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6568 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6577 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6585 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6591 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6601 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6607 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 760:

/* Line 690 of lalr1.cc  */
#line 6617 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6624 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6631 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 763:

/* Line 690 of lalr1.cc  */
#line 6656 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 764:

/* Line 690 of lalr1.cc  */
#line 6684 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 765:

/* Line 690 of lalr1.cc  */
#line 6712 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6716 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6720 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6728 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6735 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6742 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6759 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
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

  case 775:

/* Line 690 of lalr1.cc  */
#line 6772 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6773 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6774 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6775 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6776 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6777 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6778 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6779 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6780 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6781 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6782 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6783 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6784 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6785 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6786 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6787 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6792 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6793 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6794 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6795 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6796 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6797 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6798 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6799 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6800 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6801 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6802 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6803 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6804 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6805 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6807 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6808 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6809 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6810 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6811 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6812 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6813 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6814 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6815 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6816 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6817 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6818 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6819 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6820 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6821 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6822 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6823 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6824 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6825 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6826 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6827 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6828 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6829 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6830 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6831 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6832 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6833 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6834 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6835 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6836 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6837 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6840 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6841 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6842 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6843 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6844 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6845 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6847 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6848 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6849 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6850 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6851 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6852 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6853 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6854 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6855 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6857 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6858 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6859 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6860 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6861 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6979 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6980 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6983 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6984 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6985 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6986 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6987 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6989 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6990 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 6991 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 6992 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 6994 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 6995 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 6996 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7001 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 11951 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1427;
  const short int
  jsoniq_parser::yypact_[] =
  {
      5613,  7127,  7127,  7127,  7127, -1427, -1427,   -19,   222, -1427,
     795,   240, -1427, -1427, -1427,   254, -1427, -1427, -1427,   277,
   -1427,   331,   661,   431,   480,   747, -1427,   -14, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427,   594, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427,   700, -1427,   705, -1427,   741,   764, -1427,
     457, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427,   770, -1427, -1427, -1427, -1427, -1427, -1427, -1427,   821,
   -1427, -1427, -1427, -1427, -1427, 14858, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427,   824, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427,  6221,  8939,  9241, 14858, -1427,
   -1427,   804, -1427, -1427, -1427, -1427,   811, -1427, -1427, -1427,
    5006, -1427,  5311, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427,   831, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427,    51,   756, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427,   -79, -1427,   140, -1427,   -96,  -109, -1427,
   -1427, -1427, -1427, -1427, -1427,   874, -1427,   754,   778,   785,
   -1427, -1427,   864,   875, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427,   912, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427,  9543,  9845, -1427,
     717, -1427, -1427, -1427, -1427,  5917,  7429,  1036, -1427,  7731,
   -1427, -1427,   566,    67, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,    80, -1427,
   -1427, -1427, -1427, -1427, -1427,   110, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427,  7127, -1427, -1427, -1427, -1427,    17,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,   182, -1427,
     847, -1427, -1427, -1427,   159, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427,   872,   948, -1427,   904,   792,   943,   650,
     565,   739,     8, -1427,   994,   846,   947,   949, 11053, -1427,
     856, -1427, -1427,   207, -1427, -1427, -1427, -1427,   546,   931,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427,   907,   897, -1427, -1427, -1427, -1427, -1427,   870, -1427,
    7127,   873,   876,   878,  7127,   628,   628,  1035,   512,   637,
     498, 15147, 14858,    -6,  1018, 14858,   913,   950,   657,  5006,
     765,   823, 14858, 14858,   763,   603,    31, -1427, -1427, -1427,
    5006,  7127,  7127, 11355, 14858, -1427,   786,   787, 14858,   955,
       7,   921, 11355,  1076,    79,   308, 14858,   958,   935,   971,
   -1427, 11355, 14858,  7127, 11355, 11355, 14858,  7127,   926,   928,
   11355, 14858, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427,   938, -1427, 14858, -1427,   900,  6523,
     964,   289,   932,   933,   936, 14858,  7127, -1427,   934,    77,
   -1427,   397, -1427,   127,  1057, 11355, 11355, -1427,   103, -1427,
   -1427, -1427,  1079, 11355,   881, -1427,  1068, 11355, 11355, 11959,
   11355, 11355, 11355, 11355, 11959, 11355,   882,   871, 14858,   915,
     924, 11355, 11355,  6221,   858, 14858, -1427,    32, -1427,    25,
   11355,  7429, -1427, -1427, -1427, -1427, -1427,   795,   747,    83,
      86,  1114,  8033,  3151,  8335,  3474,   821, -1427, -1427,   226,
     821, -1427, 11355,  4098, -1427,   998,   685,   -14,   962,   961,
     963,  7127, 11355,   912, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, 11657, 11657, 11657, -1427, 11657, 11657, -1427, 11657,
   -1427, 11657, -1427, -1427, -1427, -1427, -1427, -1427, -1427, 11657,
   11657,  1047, 11657, 11657, 11657, 11657, 11657, 11657, 11657, 11657,
   11657, 11657, 11657, 11657,   887,  1038,  1041,  1042, -1427, -1427,
   -1427, 11959, 10147, -1427, 11355, 10449,   980, -1427,  5006,   988,
   10751, -1427, -1427, -1427, -1427,    34, -1427,   301, -1427, -1427,
   -1427, -1427, -1427, -1427,  1031,  1032,   431,  1112, -1427, -1427,
   15147,  1040,   647, 14858,   981,   982,  1040,  1035,  1016,  1013,
   -1427, -1427, -1427,   108,   901,  1052,   849, 14858,  1008, 11355,
    1033, 14858, 14858, -1427,  1020,   969,   970,   124,  1049, -1427,
      55, -1427, -1427,  1049, 14858,    13, 14858,  1063,   304, -1427,
    7127, -1427,   167, -1427,  5006,  1062,  1115,  5006,  1035,  1064,
     564, 14858, 11355,   -14,   294,   249, -1427,    48,   977,   168,
     193,  1009, -1427,   979,  7127,  7127,   350,   578, 11355,   287,
   -1427, -1427, 11355, 11355, -1427, 11355, 11355, 11355, -1427, 11355,
   -1427, 11355, -1427, 14858,  1057, -1427,   303,   363,   365, -1427,
   -1427, -1427,   391, -1427,   485, -1427, -1427,   546,   409,   432,
     -10,    61,  1070,   551,   929,   944,   937,     6, -1427,  1028,
   -1427, -1427,   983,   218,  6523,   428,  4410,   858, -1427,  1049,
   -1427, -1427,   939, -1427,   566,   528,  1139,   678, -1427, -1427,
      94, -1427, -1427, -1427,    95, -1427,    66, -1427, -1427, -1427,
   -1427, -1427,  3786, -1427, -1427, -1427, 14858,  1004, 11355,  1058,
   -1427, -1427, -1427,   948, -1427, -1427, -1427, -1427, -1427, 11657,
   -1427, -1427, -1427,    50, -1427,   565,   565,   590,   739,   739,
     739,   739,     8,     8, -1427, -1427, 13413, 13413, 14858, 14858,
   -1427, -1427,   436,   154, -1427, -1427,   321, -1427, -1427, -1427,
   -1427,   386,   628, -1427, -1427,   474,   645,   660, -1427,   431,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
    1040, -1427,  1046, 13702,  1037, 11355, -1427, -1427, -1427,  1087,
    1035,  1035,  1040, -1427,   710,  1035,   699, 14858,   -91,   648,
    1154, -1427, -1427,   898,   539, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427,   108,    58,   956,   659,
   11355, -1427, 14858,  1091,   888,  1035, -1427, -1427,  1039, 14569,
    1061, 13413,  1071, 11355,    69,  1043,    38,   501,   940, -1427,
   -1427,   673,    13,  1087, 13413,  1075,  1101,  1012,  1001,  1069,
    1035,  1044,  1074,  1104,  1035, 11355,   -36, -1427, -1427, -1427,
    1050,  1084, 11355, 11355,  1060, -1427,  1108,  1109,  7127, -1427,
    1027,  1029,  1066, 11355,  1078,  1034, 11355, -1427,  1096,   227,
     230,   239,  1187, -1427,   469, -1427,   530,  1081, -1427, -1427,
    1199, -1427,   627, 11355, 11355, 11355,   749, 11355, 11355, 11355,
   11355, 11355, 11355, 11355, 11355, 11355, 11959,  1111, 11355, 11355,
   -1427,  8637,   341,   987, -1427, -1427, -1427, -1427, -1427, -1427,
     545, -1427, -1427, 11355,   100,   175,    66,  8335,  3474,  8335,
    1157, -1427, -1427, 11355,   810,  1131, -1427, 14858,  1133, -1427,
   -1427, 11355,    50,   514,   352, -1427,   959,   160,   985,   986,
   -1427, -1427,   823, -1427,   978,   -72,  1092,  1094,  1095,  1097,
    1098,  1102,  1105,  1107,  1110,  1113,  1116, 13702,  1118,  1120,
    1121,  1122, -1427,  1123, -1427,   600, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,  1103,
   -1427, -1427, -1427, -1427, 11355, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427,   734, -1427,  1224,   753, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427,   974, -1427, -1427,
    1229, -1427, -1427, -1427, -1427, -1427,   572,  1237, -1427,   744,
   -1427, -1427, -1427,  1092,  1094,  1095,  1098,  1102,  1105,  1107,
    1110,  1113,  1120,  1121,  1122, -1427,   600,   600, 11959,   984,
     975, -1427,  1087,    58,  1053,  1080,  7127, 14858, -1427,   471,
   -1427, 14858, -1427, 11355,  1135, 11355,  1141, 11355,   204,  1136,
   11355,  1137, -1427,  1167,  1168, 11355, 14858,   927,  1210, -1427,
   -1427, -1427, -1427, -1427, -1427, 13413, -1427,  7127,  1035,  1181,
   -1427, -1427, -1427,  1035,  1181, -1427, 11355,  1147,  7127, 14858,
   -1427, -1427, 11355, 11355,   791, -1427,   270,   799, -1427, 12546,
     819, -1427,   841, -1427,  1106, -1427, -1427,  7127, -1427, 11355,
   -1427, -1427, 11355,  1093,  1108,  1194, -1427,  1163, -1427,   689,
   -1427, -1427,  1291, -1427, -1427,  7127, 14858, -1427,   757, -1427,
   -1427, -1427,  7127,  1117,  1065,  1072, -1427, -1427, -1427,  1073,
    1082, -1427, -1427, -1427,  1201, -1427, -1427, -1427, -1427,  1067,
     424, 14858,  1125, -1427,  1145,  1146,  1153,  1150, -1427,   847,
     435,  4410,   987, -1427,  6825,  4410, -1427, -1427,  1139,   416,
   -1427, -1427, -1427,  1131, -1427,  1035, -1427,   869, -1427,   312,
    1206, -1427, 11355,   667,  1058,   456,  1126, -1427,    50,  1077,
   -1427, -1427,   -65, -1427,   -82,   101,  1083,    50,   -82, 11657,
   -1427,   333, -1427, -1427, -1427, -1427, -1427, -1427,    50,  1169,
    1048,   901,   101, -1427, -1427,  1045,  1236, -1427, -1427, -1427,
    1132,   157, 13991, 12257,  1134,  4708, 14858, 14858,  1138, 14280,
    1142,  1148,  1149,  1151,  1152,  1158,  1160, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,  1290,
     412,  1292,   412,  1051,  1216, -1427, -1427,  1156, 14858,  1099,
   -1427, -1427, 11959, -1427,  1140, -1427, 11355,  1190, -1427, -1427,
   11355, -1427,   529, -1427, 11355,  1193, 11355, -1427, 11355, 14858,
   14858, -1427,   758, -1427, 11355, -1427,  1202,  1208,  1248,  1035,
    1181, -1427, 11355,  1165, -1427, -1427, -1427,  1164, -1427,   273,
   11355,  7127,  1166,   281, -1427, 14858,   -39, -1427, 12835,   265,
   -1427, 13124,  1172, -1427, -1427,  1175, -1427, -1427, 11355,   843,
    1187, 14858,   822, -1427,  1176,  1187, 14858, -1427,  1178, -1427,
   11355, 11355, 11355, 11355,  1055, 11355, 11355, -1427, 11355, 11355,
   11355, 11355,  8637,   561, -1427, -1427, -1427, -1427, -1427,  1206,
   -1427, -1427, -1427,  1035, 11355, -1427,  1209, -1427, -1427, -1427,
   -1427,  1179, 11657, -1427, -1427, -1427, -1427, -1427,   372, 11657,
   11657,   658, -1427,   985, -1427,   453, -1427,   986,    50,  1200,
   -1427, -1427,  1086, -1427, -1427, -1427, -1427, -1427, -1427,  1177,
    1180, -1427,   405,   439,  1274,  1182, -1427,   470, -1427,  1185,
   -1427,  1186,  1188,  1189, -1427, -1427,   484,   486, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427,   313,   313, -1427,   412,
   -1427, -1427,   487, -1427,  1346,    54,  1281,  1191, 11959,   -43,
    1100,  1211, -1427, -1427, 11355, -1427, 11355,  1232, -1427, 11355,
   -1427, -1427, -1427,  1327, -1427, -1427,  8637, 11355,  1035, -1427,
   -1427, -1427, 11355, 11355, -1427, -1427, -1427,  8637,  8637,  1288,
    7127, 13413, 14858,   568, 14858, 11355, 14858,   595,  8637, -1427,
     285,    37,  1187, 14858, -1427,  1192,  1187, -1427, -1427, -1427,
   -1427, -1427, 11355, -1427, -1427, -1427,   256,   292,   299, 11355,
   -1427, -1427, -1427,  1277, 11355, -1427,   739, 11657, 11657,   590,
     679, -1427, -1427, -1427, -1427, -1427, -1427, 11355, -1427, -1427,
   -1427, 14858, -1427, 14858, -1427, 13413, -1427, 13413,  1294, -1427,
   -1427, -1427, -1427, 14858, -1427, 14858, -1427, -1427, -1427, -1427,
    1357, -1427, -1427, -1427,  1127,  1279, -1427, -1427,  1283, -1427,
     759, 14858,  1273,  1170, 14858, 11959, -1427, -1427, 11355, -1427,
    1275, -1427, -1427,  1181, -1427, -1427, 13413, -1427, -1427, -1427,
    1302, 11355,  1212, -1427,  1303,  8637, -1427, 14858,   750,   662,
   -1427,  1203,  1187, -1427,  1204, -1427,  1205,  1108,  1109,   465,
   -1427,  1277,   590,   590, 11657,   475,  1215,  1218,  1262,  1220,
    1221, -1427, -1427, 13413,  1222,  1223, -1427, -1427,  1281, 11959,
   -1427,  1206,  1119, 14858,  1293,  1195,  1283, -1427, 14858,   618,
   13413,  7127, 13413,  1226, -1427, -1427,  1320,   840, -1427, -1427,
   -1427, -1427,  1231,   837, -1427, -1427, -1427,  1219, -1427,  8637,
     853, -1427, -1427,   590, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, 11355,  1124, 14858,  1297,
   -1427,  7127,   684, -1427, -1427,   691, 11355, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427,  1299, -1427,  1129,  1128, 14858, -1427,
   -1427, 11355,  8637, 14858,  1130, 11355,  1144,  1233, 11959, -1427,
   11959,  8637, -1427,  1227,  1143, 14858,  1198,  1300, 14858,  1155,
   11959, -1427
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       165,   168,   168,   168,     0,   792,   996,   120,   122,   597,
     884,   893,   833,   797,   795,   776,   885,   888,   840,   801,
     777,   779,     0,   894,   781,   891,   862,   842,   817,   778,
     837,   838,   889,   886,   836,   783,   892,   784,   785,   933,
     945,   932,   834,   853,   847,   786,   835,   788,   787,   934,
     871,   872,   839,   814,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   979,   986,   861,   857,   848,
     828,   775,   856,   864,   873,   980,   852,   463,   829,   830,
     887,   981,   987,   849,   866,     0,   469,   465,   859,   794,
     850,   851,   880,   854,   870,   879,   985,   988,   800,   841,
     882,   464,   869,   875,   780,     0,     0,     0,     0,   402,
     867,   878,   883,   881,   860,   846,   935,   844,   845,   982,
       0,   401,     0,   983,   989,   876,   831,   855,   984,   877,
     858,   865,   874,   868,   936,   822,   827,   826,   825,   824,
     823,   789,   843,     0,   793,   890,   815,   924,   923,   925,
     799,   798,   818,   930,   782,   922,   927,   928,   919,   821,
     863,   921,   931,   929,   920,   819,   926,   940,   941,   938,
     939,   937,   790,   942,   943,   944,   910,   909,   896,   813,
     806,   903,   899,   816,   812,   911,   912,   802,   803,   796,
     805,   908,   907,   904,   900,   917,   918,   916,   906,   902,
     895,   804,   915,   914,   808,   810,   809,   901,   905,   897,
     811,   898,   807,   913,   966,   967,   968,   969,   970,   971,
     947,   948,   946,   952,   953,   954,   949,   950,   951,   820,
     972,   973,   974,   975,   976,   977,   978,     0,     0,   990,
     991,   992,   994,   993,   995,   165,   165,     0,     2,   165,
       9,    11,    23,     0,    28,    31,    36,    37,    38,    39,
      40,    41,    42,    32,    58,    59,    33,    34,     0,    76,
      79,    80,    35,    81,    82,     0,   118,    83,    84,    85,
      86,    18,   162,   163,   164,   171,   174,   455,   175,     0,
     176,   177,   178,   179,   180,   181,   182,   185,     0,   211,
     219,   214,   246,   252,     0,   244,   245,   221,   215,   184,
     216,   183,   217,   220,   353,   355,   357,   367,   369,   373,
     375,   378,   383,   386,   389,   391,   393,   395,     0,   399,
     406,   405,   407,     0,   425,   408,   430,   431,   432,   439,
     446,   461,   447,   448,   449,   452,   453,   450,   451,   476,
     478,   479,   480,   477,   525,   526,   527,   528,   529,   530,
     531,   462,   454,   598,   599,    43,   222,   223,   225,   224,
     226,   218,   457,   458,   459,   456,   228,   231,   227,   229,
     230,     0,   774,   791,   884,   893,   891,   793,     0,   166,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   128,   129,
       0,     0,     0,     0,     0,   257,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   275,
     276,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   192,   776,   801,   779,   832,   894,   781,   842,
     783,   853,   786,   788,   787,   871,   775,   830,   854,   878,
     935,   936,   930,   922,   928,   919,   819,   940,   941,   938,
     790,   942,   912,   991,   466,   774,     0,   187,     0,     0,
     211,     0,   781,   788,   787,     0,   168,   749,   942,     0,
     219,     0,   467,     0,   492,     0,     0,   772,     0,   773,
     428,   429,     0,     0,     0,   521,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   751,     0,   753,     0,
       0,   165,     3,     4,     1,    10,    12,     0,     0,     0,
       0,     6,   165,     0,   165,     0,     0,   119,   172,     0,
       0,   190,     0,     0,   199,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   204,   232,   251,   247,   253,   248,
     250,   249,     0,     0,     0,   418,     0,     0,   416,     0,
     362,     0,   417,   410,   415,   414,   413,   412,   411,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   404,   403,
     400,     0,     0,   426,     0,     0,   440,   443,     0,     0,
       0,   533,   535,   539,   541,     0,   124,     0,   771,    47,
      44,    45,    48,    49,     0,     0,     0,     0,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     608,   609,   610,     0,   103,   142,     0,     0,   112,     0,
       0,     0,     0,   127,     0,     0,     0,     0,   256,   258,
       0,   234,   235,   254,     0,     0,     0,   134,     0,   138,
     168,   601,     0,    60,     0,    69,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,   324,     0,     0,     0,
       0,     0,   595,     0,     0,     0,     0,   194,     0,     0,
     188,   186,     0,     0,   755,     0,     0,     0,   466,     0,
     750,     0,   468,   493,   492,   489,     0,     0,     0,   523,
     522,   427,     0,   520,     0,   621,   622,   762,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   627,     0,
     202,   203,     0,     0,     0,     0,     0,   207,   208,   255,
     752,   754,     0,     5,    24,     0,    25,     0,     7,    29,
       0,    15,     8,    30,     0,    19,   884,    77,    16,    78,
      20,   193,     0,   191,   212,   213,     0,     0,     0,     0,
     205,   233,   293,   354,   356,   360,   366,   365,   364,     0,
     361,   358,   359,     0,   370,   377,   376,   374,   380,   381,
     382,   379,   384,   385,   388,   387,     0,     0,     0,     0,
     409,   423,     0,     0,   441,   474,     0,   444,   460,   600,
     472,     0,     0,   121,   123,     0,     0,     0,   102,     0,
      92,    94,    95,    96,    97,    99,   100,   101,    93,    98,
      88,    89,     0,     0,   108,     0,   104,   106,   107,   114,
       0,     0,    87,    46,     0,     0,     0,     0,     0,     0,
       0,   699,   704,     0,     0,   700,   734,   687,   689,   690,
     691,   693,   695,   694,   692,   696,     0,     0,     0,     0,
       0,   111,     0,   144,     0,     0,   538,   532,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     237,     0,   242,   140,     0,     0,   135,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,   274,   280,   277,
       0,     0,     0,     0,     0,   537,     0,     0,     0,   419,
       0,     0,     0,     0,   195,     0,     0,   756,     0,     0,
       0,     0,   492,   490,     0,   481,     0,     0,   470,   471,
       0,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,     0,     0,     0,   436,   437,   438,   435,   635,   434,
       0,   433,   209,     0,     0,     0,     0,   165,     0,   165,
       0,   173,   243,     0,   308,   304,   306,     0,   294,   295,
     363,     0,     0,     0,     0,   665,   371,   638,   642,   644,
     646,   648,   651,   658,   659,   667,   776,   777,   779,   894,
     778,   783,   784,   785,   786,   775,   780,     0,   789,   782,
     994,   993,   768,   995,   390,   544,   550,   551,   570,   561,
     569,   568,   567,   566,   563,   565,   562,   564,   554,   602,
     603,   555,   556,   765,   766,   767,   559,   392,   394,   397,
     560,   396,   424,   445,     0,   442,   473,   125,    56,    57,
      54,    55,   131,   130,     0,    90,     0,     0,   109,   110,
     115,    74,    75,    52,    53,    73,   705,     0,   708,   735,
       0,   698,   697,   702,   701,   733,     0,     0,   710,     0,
     706,   709,   688,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   146,   148,     0,     0,
       0,   113,   116,     0,     0,     0,   168,     0,   260,     0,
     543,     0,   261,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   238,     0,     0,     0,     0,   287,     0,   284,
     289,   241,   141,   136,   139,     0,   189,     0,     0,    71,
      65,    68,    67,     0,    63,   278,     0,     0,   168,     0,
     322,   326,     0,     0,     0,   329,     0,     0,   335,     0,
       0,   342,     0,   346,     0,   421,   420,   168,   196,     0,
     198,   323,     0,     0,     0,     0,   493,     0,   483,     0,
     516,   513,     0,   517,   518,     0,     0,   512,     0,   487,
     515,   514,     0,     0,     0,     0,   614,   615,   611,     0,
       0,   619,   620,   616,   758,   759,   625,   763,   623,     0,
       0,     0,     0,   629,   781,   788,   787,   942,   201,     0,
       0,     0,   630,   631,     0,     0,   210,   761,    26,     0,
      17,    21,    22,   305,   317,     0,   318,     0,   309,   310,
     311,   312,     0,   297,     0,     0,     0,   649,   662,     0,
     368,   372,     0,   681,     0,     0,     0,     0,     0,     0,
     637,   639,   640,   676,   677,   678,   680,   679,     0,     0,
     653,   652,     0,   656,   660,   674,   672,   671,   664,   668,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   547,   549,   548,
     545,   398,   475,   133,   132,    91,   105,   722,   703,     0,
     727,     0,   727,   716,   711,   147,   149,     0,     0,     0,
     117,   145,     0,    27,     0,   259,     0,     0,   273,   265,
       0,   269,     0,   263,     0,     0,     0,   282,     0,     0,
       0,   240,   285,   288,     0,   137,     0,     0,    70,     0,
      64,   279,     0,     0,   325,   327,   332,     0,   330,     0,
       0,     0,     0,     0,   336,     0,     0,   350,     0,     0,
     343,     0,     0,   347,   422,     0,   197,   757,     0,     0,
     492,     0,     0,   524,     0,   492,     0,   488,     0,    14,
       0,     0,     0,     0,     0,     0,     0,   628,     0,     0,
       0,     0,     0,     0,   632,   636,   321,   319,   320,   313,
     314,   315,   307,     0,     0,   302,     0,   296,   666,   657,
     663,     0,     0,   736,   737,   747,   746,   745,     0,     0,
       0,     0,   738,   643,   744,     0,   641,   645,     0,     0,
     650,   654,     0,   675,   670,   673,   669,   577,   572,     0,
       0,   587,     0,     0,     0,     0,   557,     0,   575,     0,
     578,     0,     0,     0,   576,   581,     0,     0,   552,   607,
     546,   571,   769,   770,   553,   723,     0,     0,   721,   728,
     729,   725,     0,   720,     0,   718,     0,     0,     0,     0,
       0,     0,   534,   262,     0,   271,     0,     0,   267,     0,
     270,   283,   291,   292,   286,   239,     0,     0,     0,    66,
     281,   540,     0,     0,   333,   337,   331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   536,
       0,     0,   492,     0,   519,     0,   492,   542,   612,   613,
     617,   618,     0,   624,   764,   626,     0,     0,     0,     0,
     633,   316,   303,   298,     0,   661,   748,     0,     0,   740,
       0,   686,   685,   684,   683,   682,   647,     0,   739,   573,
     574,     0,   591,     0,   588,     0,   604,     0,     0,   580,
     579,   586,   594,     0,   584,     0,   582,   732,   731,   730,
       0,   724,   717,   715,     0,   712,   713,   707,   150,   152,
     154,     0,     0,     0,     0,     0,   266,   264,     0,   272,
       0,   206,   352,    72,   328,   334,     0,   348,   344,   351,
       0,     0,     0,   338,     0,     0,   340,     0,   502,   496,
     491,     0,   492,   482,     0,   760,     0,     0,     0,     0,
     301,   299,   742,   741,     0,     0,     0,     0,   595,     0,
       0,   605,   558,     0,     0,     0,   726,   719,     0,     0,
     156,   155,     0,     0,     0,     0,   151,   268,     0,     0,
       0,     0,     0,     0,   510,   504,     0,   503,   505,   511,
     508,   498,     0,   497,   499,   509,   484,     0,   485,     0,
       0,   634,   300,   743,   655,   592,   593,   596,   589,   590,
     606,   585,   583,   714,   153,   157,     0,     0,     0,     0,
     290,     0,     0,   341,   339,     0,     0,   495,   506,   507,
     494,   500,   501,   486,     0,   158,     0,     0,     0,   349,
     345,     0,     0,     0,     0,     0,     0,     0,     0,   160,
       0,     0,   159,     0,     0,     0,     0,     0,     0,     0,
       0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1427, -1427,  -216,  -191, -1427,  1184,  1196, -1427,  1207,  -453,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
    -912, -1427, -1427, -1427, -1427,  -227,  -524, -1427,   771,    18,
   -1427, -1427, -1427, -1427, -1427,   332,   570, -1427, -1427,    14,
    -146,  1059, -1427,  1014, -1427, -1427,  -570, -1427,   511, -1427,
     296, -1427,  -208,  -259, -1427,  -489, -1427,    11,    87,    70,
    -201,  -162, -1427,  -780, -1427, -1427,   359, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427,   674,    10,  1412,
       0, -1427, -1427, -1427, -1427,   522, -1427, -1427,  -289, -1427,
       5, -1427,  -293,  -848,  -651,  -633, -1427, -1427,   743, -1427,
   -1427,    71,   290, -1427, -1427, -1427,   170, -1426, -1427,   443,
     178, -1427, -1427,   186, -1234, -1427,   989,   272, -1427, -1427,
     275,  -929, -1427, -1427,   269, -1427, -1427, -1181, -1157, -1427,
     268, -1358, -1427, -1427,   885,   889, -1427,  -428,   877, -1427,
   -1427,  -582,   398,  -567,   393,   415, -1427, -1427, -1427,   642,
   -1427, -1427,  1161, -1427, -1427, -1427, -1427, -1427,  -716,  -313,
    -611, -1427, -1427,   208, -1427,  -475, -1427,   848, -1427,  -377,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427,   850, -1427,  -910,
   -1427,   257, -1427,   751,  -702, -1427, -1427, -1427, -1427, -1427,
    -246,  -239, -1166,  -865, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427,  -679,  -791,  -131,  -723, -1427,
   -1427, -1427,  -846, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427,   162,   163,  -673,  -132,   392, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427, -1427,
     241, -1427, -1427,   228, -1427,   232,  -965, -1427, -1427, -1427,
     194,   187,    16,   473, -1427, -1427, -1427, -1427, -1427, -1427,
   -1427, -1427, -1427, -1427, -1427, -1427, -1427,   196, -1427, -1427,
   -1427,    23,   468,   606, -1427, -1427, -1427, -1427, -1427,   384,
   -1427, -1427, -1424, -1427, -1427, -1427,  -506, -1427,   152, -1427,
     -13, -1427, -1427, -1427, -1427, -1252, -1427,   209, -1427, -1427,
   -1427, -1427, -1427,   991, -1427, -1427, -1427, -1427, -1427,  -828,
   -1427, -1427, -1427,  -349,  -393,   815,   197, -1427
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   247,   563,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
    1179,   698,   265,   266,   267,   268,   269,   270,   860,   861,
     862,   271,   272,   273,   866,   867,   868,   274,   415,   275,
     276,   635,   277,   417,   418,   419,   431,   688,   689,   278,
    1135,   279,  1638,  1639,   280,   281,   282,   488,   283,   284,
     285,   286,   287,   691,   288,   289,   452,   290,   291,   292,
     293,   294,   295,   574,   296,   297,   767,   768,   298,   299,
     500,   301,   575,   429,   921,   922,   302,   576,   303,   578,
     501,   305,   678,   679,  1167,   438,   306,   439,   440,   685,
    1168,  1169,  1170,   579,   580,  1018,  1019,  1455,   581,  1015,
    1016,  1278,  1279,  1280,  1281,   307,   705,   706,   308,  1194,
    1195,  1399,   309,  1197,  1198,   310,   311,  1200,  1201,  1202,
    1203,  1406,   312,   313,   314,   315,   809,   316,   317,  1290,
     318,   319,   320,   321,   322,   323,   324,   325,   326,  1078,
     327,   328,   329,   330,   599,   600,   331,   332,   333,   334,
     335,   336,   337,   998,   999,   338,   626,   627,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   836,   348,   349,
     350,  1228,   734,   735,   736,  1670,  1722,  1723,  1716,  1717,
    1724,  1718,  1229,  1230,   351,   352,  1231,   353,   354,   355,
     356,   357,   358,   359,   360,   916,  1407,  1340,  1055,  1497,
    1056,  1079,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1064,
    1065,  1066,  1067,   711,  1687,   361,   362,   363,   364,  1068,
    1069,  1070,  1071,   365,   366,   367,   368,   369,   370,   757,
     758,   371,  1262,  1263,  1590,  1000,  1026,  1300,  1301,  1027,
    1028,  1029,  1030,  1031,  1310,  1480,  1481,  1032,  1313,  1033,
    1461,  1034,  1035,  1318,  1319,  1486,  1484,  1302,  1303,  1304,
    1305,  1604,   664,   887,   888,   889,   890,   891,   892,  1120,
    1527,  1635,  1121,  1525,  1633,   893,  1352,  1522,  1518,  1519,
    1520,   894,   895,  1306,  1314,  1471,  1307,  1467,  1291,   372,
     373,   374,   375,   491,   376,   377,   378,   379,   380,  1072,
    1073,  1074,  1075,  1180,   508,   381,   382,   383
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -833;
  const short int
  jsoniq_parser::yytable_[] =
  {
       300,   300,   300,   300,   300,   304,   304,   304,   304,   304,
     830,   534,   388,   391,   392,   577,   659,  1196,   636,   636,
     623,   936,  1184,   817,   416,   550,   551,   674,   944,   914,
     787,   789,   964,   551,  1419,  1054,  1077,   553,   954,   818,
     819,   820,   821,  1410,   747,  1450,  1451,   915,   639,   753,
    1563,  1136,   555,  1567,   542,   543,  1227,  1286,     7,     8,
    1482,  1148,  1427,   781,   785,   788,   790,  1093,   551,  1137,
     918,   390,   390,   390,   394,  1156,   847,  1641,   551,   401,
       9,   551,   514,   558,   551,   695,   699,   551,   389,   389,
     389,   393,   910,     7,     8,   551,   551,  1024,  1123,   779,
     783,   551,  1636,  1124,  1125,   300,   436,   404,  1186,   638,
     304,   739,  1126,   722,   401,   987,   499,   503,   525,  1127,
    1150,  1128,  1129,   526,   402,   551,   560,   686,   551,   557,
    1130,   523,  1668,  1173,   562,   683,   912,     7,     8,   395,
    1097,   562,   404,   842,   911,   670,   612,   405,   517,  1560,
     518,   911,  1468,   912,  1463,   551,   805,  1131,   806,   807,
     613,   808,    77,   810,   876,   648,   877,  1680,   551,   551,
     723,   811,   812,  1561,  1111,   489,    87,  1315,  1316,   406,
     407,  1010,  -169,   551,  1642,  1112,   562,  1157,  1465,   558,
    1100,  1464,   389,   558,   551,  1466,   687,   943,   649,  1468,
    1317,   101,   565,  1125,   913,  1021,   566,   527,  1022,   561,
     878,   567,   577,   397,   398,  1591,   399,   400,  1153,   551,
     524,  1129,  1669,   843,   556,   980,  -170,   551,   551,   122,
     568,   551,   919,   562,   403,   838,   562,   519,  1161,   437,
     551,   694,   769,   988,  1172,   300,   300,   537,   539,   300,
     304,   304,   787,   789,   304,  1732,  1427,   551,  1292,   552,
    1217,   437,  1410,   562,   730,  1158,  1643,   515,  1403,   920,
     557,  1390,   554,  1634,  1743,   774,   562,   562,   776,  1094,
     740,  1154,   485,  1159,   300,  1132,  1007,  1009,   558,   304,
    1269,   562,  1268,   551,   559,   551,   981,  1136,  1709,  1365,
     551,   929,   562,  1187,   932,   485,  1024,  1024,   873,  1227,
     908,  1023,  1469,   437,  1344,  1137,   732,   485,  1227,   485,
     671,   779,   783,  1460,  1331,   780,   784,   562,   672,   569,
     437,  1293,   570,   775,   777,   562,   562,   409,   638,   562,
     771,  1083,   551,   792,   437,   770,  1488,   571,   562,   933,
     773,   551,  1752,  1374,  1755,   412,   928,   946,   941,  1469,
    1470,   879,   622,   413,   551,   562,   551,   520,  -169,   521,
     800,   414,  1400,   572,   880,  1400,   881,  1133,  1134,  1052,
     396,  1020,   947,  1400,  1385,  1564,   122,   882,   883,   884,
     300,   885,   551,   886,   300,   304,   941,   410,   723,   304,
     559,   562,   420,   562,   559,  1667,  1700,   991,   562,   421,
     842,  1349,  -170,   925,  1294,  1295,  1213,  1296,   573,  1214,
    1275,   300,   300,   696,  1297,  1597,   304,   304,  1215,   551,
    1084,  1292,   422,   677,  1298,   965,  1025,   551,   411,   942,
     565,  1277,   692,   300,   566,  1676,  1299,   300,   304,   567,
     562,   704,   304,  1565,   709,   710,   522,   551,  1401,   562,
     716,  1553,   654,  1360,   655,  1087,   551,  1745,   568,  1558,
     697,  1351,   562,  1565,   562,   724,   551,   956,   565,   437,
     940,  1677,   566,   787,   789,   787,   423,   567,  1678,   300,
     844,   394,   394,   926,   304,  1084,   300,  1730,  1367,   559,
     562,   304,   966,  1598,  1293,   972,   568,  1288,   675,   676,
    1085,  1250,  1227,   394,  1611,   737,   738,   394,  1270,  1271,
    1272,  1101,  1102,   742,   657,  1375,  1105,  1357,   976,   782,
     708,   122,  1496,   300,   713,   446,   952,   562,   304,  1220,
    1221,   300,   763,   765,     9,   562,   304,  1004,  1613,   967,
    1516,   968,   300,   300,   300,   300,  1145,   304,   304,   304,
     304,   416,  1005,   558,  1008,   562,   390,   569,   777,   912,
     570,   300,  1024,  1410,   562,  1086,   304,   969,   548,  1617,
     624,  1024,   625,   389,   562,   731,   658,  1294,  1295,   430,
    1296,  1011,  1024,  1623,  1612,  1625,  1630,   911,   646,   485,
     547,  1218,   485,   764,  1456,   569,   485,  1298,   570,   485,
     485,   572,   447,   603,   993,  1517,   548,   485,   970,  1299,
    1366,   485,  1082,  1442,  1088,   485,    77,   912,  1614,   973,
     974,   604,   832,   485,   833,  1222,  1653,  1117,   432,   485,
      87,  1089,  1458,   485,   975,  1025,  1025,   983,   485,   572,
    1160,  1731,   977,   978,  1118,  1223,   573,  1224,     9,  1618,
     911,  1734,   424,  1436,   425,   101,   644,   979,  1219,  1021,
    1349,  1220,  1022,  1624,   911,  1626,  1631,   971,  1536,   782,
     448,   449,   645,   485,   606,  1225,   424,  1350,   425,   108,
     300,  1720,   485,   122,   573,   304,   640,  1119,  1220,  1221,
    1264,   927,   624,   654,   625,   655,   120,   624,   935,   625,
     641,   623,  1006,   607,   300,   300,  1589,  1475,  1571,   304,
     304,  1537,   953,  1575,  1601,   485,   608,  1226,  1163,   426,
    1351,  1602,   485,  1164,   427,   959,   960,   961,   656,   765,
      77,  1603,   668,   863,   787,   143,  1337,   669,  1403,   441,
     603,  1531,  1165,   426,    87,  1714,  1661,  1265,   427,  1220,
     390,   609,  1024,   911,   300,   657,  1220,  1221,   604,   304,
    1659,   912,   433,  1265,   992,  1453,   792,   389,  1338,   101,
    1561,   428,   434,  1665,   394,   394,   864,  1223,   777,  1224,
    1258,   865,   300,  1166,  1222,  1090,  1339,   304,  1721,  1092,
     416,   950,   951,  1719,  1725,   428,  1751,  1561,  -832,   435,
     603,  1454,  1091,  1163,  1223,   690,  1224,  1225,  1164,  -832,
     442,   642,     7,     8,  1691,   485,  1692,   658,   604,  1388,
    1561,  1220,  1221,   397,   398,   643,   399,   400,  1266,   603,
    1103,  1104,  1117,   401,  1225,  1714,  1220,   849,   108,  1220,
     485,   605,  1719,   402,   403,   911,   912,   604,  1725,  1118,
     443,  1234,  1222,  1235,   485,   120,  1720,  1275,   485,   485,
    1671,   404,  1771,  1343,  1674,  1223,   405,  1224,  1095,  1772,
    1684,   485,  1223,   485,  1224,  1715,  1421,  1599,  1600,   690,
    1095,   485,   864,  1193,   485,  1596,  1561,   865,   485,   444,
     484,  1193,  1740,  1561,   143,  1225,  1397,  1274,   406,   407,
     408,  1025,  1225,  1113,  1402,   791,   108,  1640,  1275,   793,
    1025,  1408,   445,   504,  1114,   450,  1446,  1222,  1276,  1601,
     485,  1025,  1501,   120,  1409,   509,  1602,   512,  1686,  1277,
    1689,   451,   610,  1411,   486,  1408,  1603,  1223,   300,  1224,
    1694,   611,  1695,   304,  1426,  1408,  1412,   409,  1570,   505,
    1139,  1701,  1223,   485,  1224,  1223,   506,  1224,  1764,  1140,
    1727,   577,   143,  1761,   516,  1758,  1386,  1225,  1106,  1107,
    1108,   108,  1163,  1239,  1109,  1240,   513,  1164,   660,   661,
     662,  1259,  1225,   485,   528,  1225,  1260,   529,   120,  1447,
    1448,   815,   816,   822,   823,  1355,  1356,   300,   300,   300,
    1627,  1628,   304,   304,   304,  1682,  1683,   410,   394,  1573,
     416,   530,   532,   485,   485,   485,   485,   824,   825,   531,
     533,  1285,   535,   540,  1640,  1204,   544,   143,   584,   564,
    1549,   582,   583,   601,   602,   614,   585,   586,   615,   587,
     616,   621,   628,   617,   629,   630,   631,   588,   411,   632,
     485,   589,   633,   590,   634,   638,   650,   652,   591,   667,
     653,   663,   681,   682,   485,   684,   690,   693,   701,   702,
     703,   714,   718,   715,   412,   592,   720,   722,  1640,   729,
     725,   726,   413,   733,   727,   534,   741,   743,   744,   485,
     414,  1025,  1733,   756,  1592,   766,   485,   760,   485,   593,
     594,   595,   596,   597,   598,   755,   761,   778,   796,   813,
     826,   485,   850,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   797,   798,   827,   799,   624,   828,   829,   839,
     845,   846,   848,   870,   871,   874,   300,   875,   897,   896,
     898,   304,   900,   902,   905,   906,   907,  1364,   909,   924,
     930,   931,   934,   945,   948,   949,   982,  1782,   984,  1783,
     986,   985,   989,  1006,  1003,   990,  1013,   300,  1017,  1791,
    1096,   865,   304,   911,  1115,  1138,  1116,  1143,   300,  1144,
    1149,  1151,  1155,   304,  1146,   686,  1162,  1175,  1176,  1393,
    1555,  1177,  1183,  1178,  1189,  1188,  1181,   300,  1182,  1192,
    1193,  1199,   304,  1205,   485,  1206,   390,   647,  1415,  1212,
     651,  1207,  1209,  1216,   509,   300,  1210,   665,   666,  1233,
     304,  1251,   300,   389,  1261,   509,  1232,   304,   656,   680,
    1282,   800,  1284,   680,   485,  1308,  1289,  1312,  1309,  1341,
    1320,   700,  1321,  1322,     9,  1323,  1324,   707,   390,  1348,
    1325,   712,  1347,  1326,  1259,  1327,   717,  1353,  1328,  1260,
    1372,  1329,  1363,  1358,  1330,   389,  1332,   390,  1333,  1334,
    1335,  1336,  1362,  1359,  1370,  1376,  1378,  1379,  1380,  1384,
    1389,  1392,  1414,  1418,   389,   394,  1408,  1420,  1423,  1434,
    1430,   707,   394,  1439,  1440,  1264,  1435,  1431,  1432,  1429,
     728,  1441,  1424,  1438,  1275,  1459,  1485,  1433,  1478,  1428,
    1515,  1487,  1521,  1498,  1524,  1526,  1532,  1504,  1528,  1462,
    1546,  1508,  1479,  1483,   764,  1472,  1547,  1509,  1510,  1534,
    1511,  1512,  1539,   759,   485,  1651,  1548,  1513,   485,  1514,
     680,  1551,  1552,  1594,  1557,  1607,  1655,  1555,  1530,  1657,
    1568,  1569,  1574,   485,  1577,  1595,  1609,  1666,  1608,  1610,
    1615,  1616,   485,  1582,  1619,  1620,  1632,  1621,  1622,  1117,
    1637,  1648,  1650,  1645,  1656,  1453,   485,  1696,  1698,  1644,
    1693,  1673,  1699,  1703,  1697,  1708,   485,  1704,  1710,  1712,
    1711,   300,  1726,  1728,  1735,  1729,   304,  1736,  1737,  1738,
    1739,  1741,  1742,  1748,  1756,  1757,  1760,  1768,  1763,  1773,
    1788,  1781,  1749,   485,  1774,  1787,  1746,   872,  1784,  1346,
     673,  1766,  1785,   545,  1098,  1775,  1174,  1706,  1778,  1361,
    1744,  1002,  1259,   509,  1171,   546,   939,  1260,   485,  1586,
    1587,  1588,  1780,  1544,  1457,   637,  1273,  1383,   485,   549,
    1452,  1394,   485,  1790,  1657,  1449,  1404,   803,   869,  1398,
    1413,  1081,   804,  1445,   837,   719,  1422,  1762,  1759,   814,
     841,  1690,   899,  1489,  1490,   963,   903,   904,  1345,   620,
    1444,  1473,  1437,  1443,  1606,  1477,  1287,  1476,  1605,   917,
    1311,   923,  1122,  1354,  1523,     0,  1629,  1474,     0,   509,
    1753,     0,   509,   751,     0,     0,   937,   490,     0,   485,
     485,     0,   485,   485,   485,     0,   485,     0,  1386,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1259,     0,   962,     0,
    1769,  1260,     0,     0,     0,   485,     0,  1259,  1259,     0,
     300,     0,  1260,  1260,     0,   304,     0,     0,  1259,     0,
       0,  1769,     0,  1260,     0,     0,   485,   485,     0,     0,
    1753,  1001,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1679,
       0,     0,   485,     0,     0,   485,     0,     0,   485,     0,
       0,  1012,     0,     0,     0,     0,     0,  1685,   485,     0,
       0,     0,     0,   485,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1076,  1076,  1080,  1080,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1259,     0,     0,     0,     0,
    1260,     0,     0,     0,     0,     0,     0,     0,  1076,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   300,     0,     0,     0,     0,   304,  1142,     0,     0,
       0,     0,     0,     0,   680,     0,  1076,     0,     0,  1259,
       0,     0,     0,     0,  1260,     0,     0,     0,     0,  1076,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   300,     0,     0,     0,     0,   304,     0,   485,   485,
       0,   485,     0,   485,     0,     0,     0,     0,     0,     0,
     485,     0,  1259,     0,     0,     0,     0,  1260,     0,     0,
       0,  1259,     0,     0,     0,     0,  1260,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   485,     0,
     485,     0,   485,     0,   485,     0,     0,     0,     0,     0,
     485,     0,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1283,     0,     0,     0,     0,     0,   485,     0,
       0,   485,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   485,     0,     0,     0,     0,     0,     0,
       0,     0,  1076,     0,   485,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     485,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     485,     0,     0,     0,     0,   485,     0,   485,   490,   485,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   745,
     746,     0,   748,   749,   750,   752,     0,   754,     0,     0,
       0,     0,     0,   762,     0,   485,     0,     0,     0,     0,
       0,     0,   772,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   680,     0,     0,   485,  1368,     0,     0,     0,
     485,     0,     0,     0,   794,   795,     0,     0,     0,     0,
       0,  1382,   485,   801,   802,   485,     0,     0,     0,     0,
    1076,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   707,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1076,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   835,     0,     0,
       0,  1425,   835,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   759,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1001,     0,     0,     0,
    1001,   901,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   938,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     955,     0,     0,     0,   957,   958,     0,  1493,  1076,     0,
     509,  1502,  1503,   801,  1507,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1529,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1542,  1543,     0,     0,     0,     0,
       0,     0,     0,     0,   795,     0,     0,     0,     0,     0,
    1014,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1559,     0,     0,  1076,     0,     0,  1076,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1572,     0,     0,     0,
       0,  1576,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1099,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1152,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1185,     0,     0,
       0,     0,     0,     0,  1190,  1191,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1208,     0,     0,  1211,     0,
       0,     0,     0,     0,     0,     0,  1076,  1660,     0,  1662,
       0,  1664,     0,     0,     0,  1236,  1237,  1238,  1672,  1241,
    1242,  1243,  1244,  1245,  1246,  1247,  1248,  1249,     0,     0,
    1252,  1253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1014,  1688,     0,  1688,     0,
    1076,     0,  1076,     0,     0,     0,     0,     0,   712,     0,
     712,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1702,     0,     0,  1705,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1076,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1713,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1342,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1076,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1747,     0,
       0,     0,     0,  1750,     0,  1076,     0,  1076,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1767,     0,  1369,     0,  1371,     0,  1373,
       0,     0,  1377,     0,     0,     0,     0,  1381,     0,     0,
       0,     0,     0,  1776,     0,     0,     0,     0,  1777,  1387,
       0,     0,     0,     0,     0,     0,     0,     0,  1391,     0,
    1786,     0,     0,  1789,  1395,  1396,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1416,     0,     0,  1417,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1014,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1533,     0,
       0,     0,  1535,     0,     0,     0,  1538,     0,  1540,     0,
    1541,     0,     0,     0,     0,     0,  1545,     0,     0,     0,
       0,     0,     0,     0,  1550,     0,     0,     0,     0,     0,
       0,     0,  1554,  1556,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1387,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1578,  1579,  1580,  1581,     0,  1583,  1584,     0,
    1585,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1646,     0,  1647,     0,
       0,  1649,     0,     0,     0,     0,     0,     0,     0,  1652,
       0,     0,     0,     0,  1654,  1556,     0,     0,     0,     0,
       0,     0,  1658,     0,     0,     0,     0,  1663,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1675,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1681,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1707,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1658,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1754,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -165,   782,     0,     0,     0,     0,     0,  1765,     0,
       0,     0,     0,  1770,     0,     0,     0,     0,  1754,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,  1770,     0,    10,   385,  1779,    12,    13,
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
     139,   140,     0,     0,   141,   142,   143,     0,   387,   145,
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
     242,   243,     0,   244,  -165,   782,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,   786,   385,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,   386,    26,    27,    28,    29,    30,
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
       0,   387,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   782,   238,     0,
     239,   240,   241,   242,   243,     0,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     384,   385,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   386,    26,    27,    28,
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
     142,   143,     0,   387,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   782,
     238,     0,   239,   240,   241,   242,   243,     0,   244,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   384,   385,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   492,   386,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   493,   494,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   467,    80,    81,    82,    83,    84,   495,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   496,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,   143,     0,   387,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   477,   478,
     479,   170,   171,   480,   498,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,     0,   238,     0,   239,   240,   241,   242,   243,     0,
     244,   994,   995,     0,     0,     0,     0,     0,     0,     0,
     996,     0,     0,     0,     0,     5,     6,     0,     0,     0,
       0,     0,     0,     0,   384,   385,     0,    12,    13,    14,
     453,    16,    17,    18,   454,    20,   455,   456,   457,   458,
     386,    26,   459,    28,    29,    30,     0,    31,    32,    33,
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
     127,   128,     0,     0,     0,     0,   997,     0,   129,     0,
     130,   131,   132,   133,   471,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   387,   145,   146,
     147,   148,   149,   150,   151,   152,   472,   154,   473,   156,
     474,   475,   159,   160,   161,   162,   163,   164,   476,   166,
     477,   478,   479,   170,   171,   480,   481,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   482,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,   507,     0,   239,   483,   241,   242,
     243,     0,   244,     5,     6,     0,     0,     0,  1499,     0,
       0,     0,   384,   385,     0,    12,    13,    14,   453,    16,
      17,    18,   454,    20,   455,   456,   457,   458,   386,    26,
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
     123,   124,   125,     0,     0,     0,   126,  1500,   127,   128,
       0,     0,     0,     0,     0,     0,   129,     0,   130,   131,
     132,   133,   471,   135,   136,   137,   138,   139,   140,     0,
       0,   141,   142,     0,     0,   387,   145,   146,   147,   148,
     149,   150,   151,   152,   472,   154,   473,   156,   474,   475,
     159,   160,   161,   162,   163,   164,   476,   166,   477,   478,
     479,   170,   171,   480,   481,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   482,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,     0,   507,     0,   239,   483,   241,   242,   243,     0,
     244,     5,     6,     0,     0,     0,     0,     0,     0,     0,
     384,   385,     0,    12,    13,    14,   453,    16,    17,    18,
     454,    20,   455,   456,   457,   458,   386,    26,   459,    28,
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
     142,     0,     0,   387,   145,   146,   147,   148,   149,   150,
     151,   152,   472,   154,   473,   156,   474,   475,   159,   160,
     161,   162,   163,   164,   476,   166,   477,   478,   479,   170,
     171,   480,   481,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   482,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     0,     0,
       0,     0,   239,   483,   241,   242,   243,     0,   244,   510,
     511,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     0,     0,     0,     0,   384,   385,     0,    12,    13,
      14,   453,    16,    17,    18,   454,    20,   455,   456,   457,
     458,   386,    26,   459,    28,    29,    30,     0,    31,    32,
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
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   471,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   387,   145,
     146,   147,   148,   149,   150,   151,   152,   472,   154,   473,
     156,   474,   475,   159,   160,   161,   162,   163,   164,   476,
     166,   477,   478,   479,   170,   171,   480,   481,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     482,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     0,     0,   239,   483,   241,
     242,   243,     0,   244,     1,     2,     3,     4,     5,     6,
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
     240,   241,   242,   243,     0,   244,   245,   246,     1,     2,
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
       0,   238,     0,   239,   240,   241,   242,   243,     0,   244,
       0,   541,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,   384,   385,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   386,    26,    27,    28,    29,    30,     0,    31,    32,
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
     122,     0,     0,   123,   124,   125,     0,   487,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   387,   145,
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
     242,   243,     0,   244,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,   384,   385,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   386,    26,    27,    28,    29,    30,     0,
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
       0,   121,   122,     0,     0,   123,   124,   125,     0,   721,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     387,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,     0,   239,
     240,   241,   242,   243,     0,   244,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   384,
     385,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,  1254,   386,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,  1255,
    1256,    49,    50,    51,    52,    53,    54,    55,    56,    57,
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
     143,     0,   387,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,  1257,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
       0,   239,   240,   241,   242,   243,     0,   244,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   384,   385,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   386,    26,    27,
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
     141,   142,   143,     0,   387,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,   239,   240,   241,   242,   243,     0,   244,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,    10,    11,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
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
       0,     0,   141,   142,   143,     0,   144,   145,   146,   147,
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
       0,   244,     1,     2,     3,     4,     5,     6,     7,     8,
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
     139,   140,     0,     0,   141,   142,   143,     0,   387,   145,
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
     242,   243,     0,   244,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,    10,   385,     0,
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
     387,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,     0,   239,
     240,   241,   242,   243,     0,   244,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,     0,     0,   786,
     385,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   386,    26,    27,    28,    29,
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
     143,     0,   387,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
       0,   239,   240,   241,   242,   243,     0,   244,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   384,   385,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,  1254,   386,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,  1255,  1256,    49,    50,    51,    52,    53,    54,    55,
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
     141,   142,   143,     0,   387,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,  1257,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,   239,   240,   241,   242,   243,     0,   244,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   384,   385,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   492,   386,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,   493,   494,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   467,    80,    81,    82,    83,    84,   495,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   496,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,   497,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   387,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   477,
     478,   479,   170,   171,   480,   498,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,   238,     0,   239,   240,   241,   242,   243,
       0,   244,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   384,   385,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     492,   386,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,   493,   494,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   467,    80,    81,    82,    83,
      84,   495,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   496,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
     502,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   387,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   477,   478,   479,   170,   171,   480,   498,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,   238,     0,   239,   240,   241,
     242,   243,     0,   244,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   384,   385,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   492,   386,    26,    27,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,     0,    44,    45,    46,   493,   494,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   467,    80,    81,
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
     387,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   477,   478,   479,   170,   171,   480,   498,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   536,   238,     0,   239,
     240,   241,   242,   243,     0,   244,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   384,
     385,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   492,   386,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   493,
     494,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   467,
      80,    81,    82,    83,    84,   495,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     496,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   387,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   477,   478,   479,   170,   171,
     480,   498,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
     538,   239,   240,   241,   242,   243,     0,   244,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   384,   385,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   492,   386,    26,    27,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,    44,    45,
      46,   493,   494,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   467,    80,    81,    82,    83,    84,   495,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,    93,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   496,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,   831,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   387,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   477,   478,   479,
     170,   171,   480,   498,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,   239,   240,   241,   242,   243,     0,   244,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   384,   385,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   492,   386,
      26,    27,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,     0,
      44,    45,    46,   493,   494,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   467,    80,    81,    82,    83,    84,   495,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,    93,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   496,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,   121,   122,     0,
       0,   123,   124,   125,     0,     0,     0,   126,   834,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   387,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   477,
     478,   479,   170,   171,   480,   498,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,   238,     0,   239,   240,   241,   242,   243,
       0,   244,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   384,   385,     0,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     492,   386,    26,    27,    28,    29,    30,     0,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,    44,    45,    46,   493,   494,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
      71,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,    77,    78,   467,    80,    81,    82,    83,
      84,   495,    86,     0,     0,     0,     0,    87,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,    93,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   104,   496,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,   112,   113,
     114,   115,   116,   117,   118,   119,     0,   120,     0,   121,
     122,     0,     0,   123,   124,   125,     0,     0,     0,   126,
     840,   127,   128,     0,     0,     0,     0,     0,     0,   129,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,   143,     0,   387,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   477,   478,   479,   170,   171,   480,   498,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,     0,   238,     0,   239,   240,   241,
     242,   243,     0,   244,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   384,   385,     0,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
     456,    23,   458,   386,    26,   459,    28,    29,    30,     0,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   461,     0,    44,    45,    46,   463,   464,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,    71,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,    77,    78,   467,    80,    81,
      82,    83,    84,   495,    86,     0,     0,     0,     0,    87,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     468,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   496,   106,
       0,   107,   108,   618,   110,   111,     0,     0,     0,     0,
     112,   113,   114,   115,   116,   117,   118,   119,     0,   120,
       0,   619,   122,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,     0,     0,   141,   142,   143,     0,
     387,   145,   146,   147,   148,   149,   150,   151,   152,   472,
     154,   473,   156,   474,   475,   159,   160,   161,   162,   163,
     164,   476,   166,   477,   478,   479,   170,   171,   480,   481,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   482,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,     0,   238,     0,   239,
     483,   241,   242,   243,     0,   244,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   384,
     385,     0,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   492,   386,    26,    27,    28,    29,
      30,     0,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,    44,    45,    46,   493,
     494,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,    71,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,    77,    78,   467,
      80,    81,    82,    83,    84,   495,    86,     0,     0,     0,
       0,    87,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,    93,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,   101,   102,   103,   104,
     496,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,   112,   113,   114,   115,   116,   117,   118,   119,
       0,   120,     0,   121,   122,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,     0,     0,   141,   142,
     143,     0,   387,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   477,   478,   479,   170,   171,
     480,   498,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,     0,   238,
       0,   239,   240,   241,   242,   243,     0,   244,     1,     2,
       3,     4,     5,     6,     0,     0,     0,     9,     0,     0,
       0,   384,   385,     0,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,   456,    23,   458,   386,    26,   459,
      28,    29,    30,     0,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,   461,     0,    44,    45,
      46,   463,   464,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,    71,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,    77,
      78,   467,    80,    81,    82,    83,    84,   495,    86,     0,
       0,     0,     0,    87,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   468,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,   101,   102,
     103,   104,   496,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,   112,   113,   114,   115,   116,   117,
     118,   119,     0,   120,     0,   121,   122,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,     0,     0,
     141,   142,   143,     0,   387,   145,   146,   147,   148,   149,
     150,   151,   152,   472,   154,   473,   156,   474,   475,   159,
     160,   161,   162,   163,   164,   476,   166,   477,   478,   479,
     170,   171,   480,   481,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   482,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
       0,   238,     0,   239,   483,   241,   242,   243,     0,   244,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     9,
       0,     0,     0,   384,   385,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   456,    23,   458,   386,
      26,   459,    28,    29,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,   461,     0,
      44,    45,    46,   463,   464,    49,   465,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,    71,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,    77,    78,   467,    80,    81,    82,    83,    84,   495,
      86,     0,     0,     0,     0,    87,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   468,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,   104,   496,   106,     0,   107,   108,     0,
     110,   111,     0,     0,     0,     0,   112,   113,   114,   115,
     116,   117,   118,   119,     0,   120,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,   143,     0,   387,   145,   146,   147,
     148,   149,   150,   151,   152,   472,   154,   473,   156,   474,
     475,   159,   160,   161,   162,   163,   164,   476,   166,   477,
     478,   479,   170,   171,   480,   481,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   482,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,     0,   238,     0,   239,   483,   241,   242,   243,
       0,   244,     5,     6,     0,     0,     0,     0,     0,     0,
       0,   384,   385,     0,    12,    13,    14,  1036,    16,    17,
      18,   454,  1037,  1038,   456,  1039,   458,   386,    26,   459,
      28,  1040,    30,     0,    31,    32,    33,    34,  1041,    36,
    1042,  1043,    39,    40,    41,    42,   461,     0,    44,  1044,
      46,   463,   464,    49,   465,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,  1045,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   467,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   468,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,  1046,     0,     0,     0,  1047,     0,     0,   110,   469,
       0,     0,     0,     0,   112,   113,   114,   115,   470,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,  1494,   127,   128,     0,
       0,     0,     0,  1495,     0,   129,     0,   130,   131,   132,
     133,   471,   135,   136,   137,   138,   139,   140,     0,     0,
    1048,   142,     0,     0,   387,   145,   146,   147,   148,   149,
     150,   151,   152,   472,  1049,   473,   156,   474,   475,   159,
     160,   161,   162,   163,   164,   476,   166,   477,   478,   479,
     170,   171,   480,   481,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   482,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     5,     6,   239,   483,   241,  1050,  1051,  1052,  1053,
     384,   385,     0,    12,    13,    14,  1036,    16,    17,    18,
     454,  1037,  1038,   456,  1039,   458,   386,    26,   459,    28,
    1040,    30,     0,    31,    32,    33,    34,  1041,    36,  1042,
    1043,    39,    40,    41,    42,   461,     0,    44,  1044,    46,
     463,   464,    49,   465,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,  1045,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     467,    80,    81,    82,    83,    84,  1405,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   468,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
    1046,     0,     0,     0,  1047,     0,     0,   110,   469,     0,
       0,     0,     0,   112,   113,   114,   115,   470,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   129,     0,   130,   131,   132,   133,
     471,   135,   136,   137,   138,   139,   140,     0,     0,  1048,
     142,     0,     0,   387,   145,   146,   147,   148,   149,   150,
     151,   152,   472,  1049,   473,   156,   474,   475,   159,   160,
     161,   162,   163,   164,   476,   166,   477,   478,   479,   170,
     171,   480,   481,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   482,     0,   187,   188,   189,
       0,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     0,     0,
       5,     6,   239,   483,   241,  1050,  1051,  1052,  1053,   384,
     385,     0,    12,    13,    14,  1036,    16,    17,    18,   454,
    1037,  1038,   456,  1039,   458,   386,    26,   459,    28,  1040,
      30,     0,    31,    32,    33,    34,  1041,    36,  1042,  1043,
      39,    40,    41,    42,   461,     0,    44,  1044,    46,   463,
     464,    49,   465,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,  1045,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   467,
      80,    81,    82,    83,    84,  1562,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   468,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,  1046,
       0,     0,     0,  1047,     0,     0,   110,   469,     0,     0,
       0,     0,   112,   113,   114,   115,   470,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   129,     0,   130,   131,   132,   133,   471,
     135,   136,   137,   138,   139,   140,     0,     0,  1048,   142,
       0,     0,   387,   145,   146,   147,   148,   149,   150,   151,
     152,   472,  1049,   473,   156,   474,   475,   159,   160,   161,
     162,   163,   164,   476,   166,   477,   478,   479,   170,   171,
     480,   481,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   482,     0,   187,   188,   189,     0,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,     0,     5,
       6,   239,   483,   241,  1050,  1051,  1052,  1053,   384,   385,
       0,    12,    13,    14,  1036,    16,    17,    18,   454,  1037,
    1038,   456,  1039,   458,   386,    26,   459,    28,  1040,    30,
       0,    31,    32,    33,    34,  1041,    36,  1042,  1043,    39,
      40,    41,    42,   461,     0,    44,  1044,    46,   463,   464,
      49,   465,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,  1045,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   467,    80,
      81,    82,    83,    84,  1566,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   468,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,  1046,     0,
       0,     0,  1047,     0,     0,   110,   469,     0,     0,     0,
       0,   112,   113,   114,   115,   470,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   129,     0,   130,   131,   132,   133,   471,   135,
     136,   137,   138,   139,   140,     0,     0,  1048,   142,     0,
       0,   387,   145,   146,   147,   148,   149,   150,   151,   152,
     472,  1049,   473,   156,   474,   475,   159,   160,   161,   162,
     163,   164,   476,   166,   477,   478,   479,   170,   171,   480,
     481,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   482,     0,   187,   188,   189,     0,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     0,     0,     5,     6,
     239,   483,   241,  1050,  1051,  1052,  1053,   384,   385,     0,
      12,    13,    14,  1036,    16,    17,    18,   454,  1037,  1038,
     456,  1039,   458,   386,    26,   459,    28,  1040,    30,     0,
      31,    32,    33,    34,  1041,    36,  1042,  1043,    39,    40,
      41,    42,   461,     0,    44,  1044,    46,   463,   464,    49,
     465,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,  1045,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   467,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     468,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,  1046,     0,     0,
       0,  1047,     0,     0,   110,   469,     0,     0,     0,     0,
     112,   113,   114,   115,   470,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   129,     0,   130,   131,   132,   133,   471,   135,   136,
     137,   138,   139,   140,     0,     0,  1048,   142,     0,     0,
     387,   145,   146,   147,   148,   149,   150,   151,   152,   472,
    1049,   473,   156,   474,   475,   159,   160,   161,   162,   163,
     164,   476,   166,   477,   478,   479,   170,   171,   480,   481,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   482,     0,   187,   188,   189,     0,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,     0,     5,     6,   239,
     483,   241,  1050,  1051,  1052,  1053,   384,   385,     0,    12,
      13,    14,  1036,    16,    17,    18,   454,  1037,  1038,   456,
    1039,   458,   386,    26,   459,    28,  1040,    30,     0,    31,
      32,    33,    34,  1041,    36,  1042,  1043,    39,    40,    41,
      42,   461,     0,    44,  1044,    46,   463,   464,    49,   465,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,  1045,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   467,    80,    81,    82,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   468,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,  1046,     0,     0,     0,
    1047,     0,     0,   110,   469,     0,     0,     0,     0,   112,
     113,   114,   115,   470,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     129,     0,   130,   131,   132,   133,   471,   135,   136,   137,
     138,   139,   140,     0,     0,   141,   142,     0,     0,   387,
     145,   146,   147,   148,   149,   150,   151,   152,   472,  1049,
     473,   156,   474,   475,   159,   160,   161,   162,   163,   164,
     476,   166,   477,   478,   479,   170,   171,   480,   481,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   482,     0,   187,   188,   189,     0,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,     0,     0,     5,     6,   239,   483,
     241,  1050,  1051,  1052,  1053,   384,   385,     0,    12,    13,
      14,   453,    16,    17,    18,   454,    20,   455,   456,   457,
     458,   386,    26,   459,    28,    29,    30,     0,    31,    32,
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
    1491,   127,   128,     0,     0,     0,     0,  1492,     0,   129,
       0,   130,   131,   132,   133,   471,   135,   136,   137,   138,
     139,   140,     0,     0,   141,   142,     0,     0,   387,   145,
     146,   147,   148,   149,   150,   151,   152,   472,   154,   473,
     156,   474,   475,   159,   160,   161,   162,   163,   164,   476,
     166,   477,   478,   479,   170,   171,   480,   481,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     482,     0,   187,   188,   189,     0,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,     0,     5,     6,   239,   483,   241,
     242,   243,     0,   244,   384,   385,     0,    12,    13,    14,
     453,    16,    17,    18,   454,    20,   455,   456,   457,   458,
     386,    26,   459,    28,    29,    30,     0,    31,    32,    33,
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
       0,     0,   123,   124,   125,     0,     0,     0,   126,  1505,
     127,   128,     0,     0,     0,     0,  1506,     0,   129,     0,
     130,   131,   132,   133,   471,   135,   136,   137,   138,   139,
     140,     0,     0,   141,   142,     0,     0,   387,   145,   146,
     147,   148,   149,   150,   151,   152,   472,   154,   473,   156,
     474,   475,   159,   160,   161,   162,   163,   164,   476,   166,
     477,   478,   479,   170,   171,   480,   481,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   482,
       0,   187,   188,   189,     0,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,     0,     0,     5,     6,   239,   483,   241,   242,
     243,     0,   244,   384,   385,     0,    12,    13,    14,   453,
      16,    17,    18,   454,    20,   455,   456,   457,   458,   386,
      26,   459,    28,    29,    30,     0,    31,    32,    33,    34,
     460,    36,    37,    38,    39,    40,    41,    42,   461,     0,
      44,   462,    46,   463,   464,    49,   465,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,   466,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   467,    80,    81,    82,    83,    84,  1147,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   468,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,   104,     0,     0,     0,     0,     0,     0,
     110,   469,     0,     0,     0,     0,   112,   113,   114,   115,
     470,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   129,     0,   130,
     131,   132,   133,   471,   135,   136,   137,   138,   139,   140,
       0,     0,   141,   142,     0,     0,   387,   145,   146,   147,
     148,   149,   150,   151,   152,   472,   154,   473,   156,   474,
     475,   159,   160,   161,   162,   163,   164,   476,   166,   477,
     478,   479,   170,   171,   480,   481,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   482,     0,
     187,   188,   189,     0,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,     0,     5,     6,   239,   483,   241,   242,   243,
       0,   244,   384,   385,     0,    12,    13,    14,   453,    16,
      17,    18,   454,    20,   455,   456,   457,   458,   386,    26,
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
       0,   141,   142,     0,     0,   387,   145,   146,   147,   148,
     149,   150,   151,   152,   472,   154,   473,   156,   474,   475,
     159,   160,   161,   162,   163,   164,   476,   166,   477,   478,
     479,   170,   171,   480,   481,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   482,     0,   187,
     188,   189,     0,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,     0,     5,     6,   239,   483,   241,   242,   243,     0,
     244,   384,   385,     0,    12,    13,    14,     0,    16,    17,
      18,   454,     0,     0,   456,   457,     0,   386,    26,   459,
      28,     0,    30,     0,    31,    32,    33,    34,     0,    36,
       0,     0,    39,    40,    41,    42,   461,     0,    44,     0,
      46,     0,     0,    49,   465,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,     0,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   467,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   468,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,     0,     0,     0,     0,     0,     0,     0,   110,   469,
       0,     0,     0,     0,   112,   113,   114,   115,   470,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,     0,   127,   128,     0,
       0,     0,     0,     0,     0,   129,     0,   130,   131,   132,
     133,   471,   135,   136,   137,   138,   139,   140,     0,     0,
       0,   142,     0,     0,   387,   145,   146,   147,   148,   149,
     150,   151,   152,   472,     0,   473,   156,   474,   475,   159,
     160,   161,   162,   163,   164,   476,   166,   477,   478,   479,
     170,   171,     0,   481,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   482,     0,   187,   188,
     189,     0,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
       0,     0,     0,   239,   483,   241,   242,   243,     0,   244
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     621,   173,     1,     2,     3,   304,   409,   946,   395,   396,
     333,   700,   934,   605,    10,   252,     1,   420,   707,   680,
     554,   555,   734,     1,  1215,   826,   827,   253,   717,   606,
     607,   608,   609,  1200,   519,  1279,  1280,   680,   397,   524,
    1408,   897,   268,  1411,   245,   246,   966,  1022,    27,    28,
    1312,   909,  1228,   552,   553,   554,   555,   847,     1,   897,
      57,     1,     2,     3,     4,    37,   646,   120,     1,    48,
      30,     1,    31,   284,     1,   434,   435,     1,     1,     2,
       3,     4,    37,    27,    28,     1,     1,   813,    40,   552,
     553,     1,  1526,    45,    46,   105,   120,    76,   144,    30,
     105,     8,    54,   123,    48,   109,   106,   107,   227,    61,
     911,    63,    64,   232,    58,     1,   109,   120,     1,   275,
      72,   227,    95,   924,   109,   428,    98,    27,    28,   158,
     863,   109,    76,   109,    96,   114,   138,    81,   227,   188,
     229,    96,    98,    98,   219,     1,   584,    99,   586,   587,
     152,   589,   112,   591,    56,   171,    58,  1593,     1,     1,
     109,   599,   600,   212,   265,   105,   126,   249,   250,   113,
     114,   115,     0,     1,   227,   276,   109,   149,   270,   390,
     869,   256,   105,   394,     1,   277,   189,   149,   204,    98,
     272,   151,    43,    46,   149,   155,    47,   316,   158,   192,
     102,    52,   501,    38,    39,  1449,    41,    42,   149,     1,
     316,    64,   185,   189,   114,   235,     0,     1,     1,   179,
      71,     1,   219,   109,    59,   628,   109,   316,   917,   275,
       1,   162,   535,   237,   923,   245,   246,   237,   238,   249,
     245,   246,   776,   777,   249,  1681,  1422,     1,    98,   192,
     962,   275,  1419,   109,   187,   916,   309,   216,  1197,   256,
     416,  1183,   192,  1525,  1698,   192,   109,   109,   192,   849,
     177,   914,    85,   916,   284,   227,   192,   192,   489,   284,
     115,   109,   192,     1,   284,     1,   235,  1143,  1656,  1147,
       1,   694,   109,   936,   697,   108,  1022,  1023,   657,  1219,
     186,   261,   258,   275,  1094,  1143,   189,   120,  1228,   122,
     289,   774,   775,  1288,  1047,   552,   553,   109,   297,   170,
     275,   171,   173,   549,   550,   109,   109,   162,    30,   109,
     315,   187,     1,   559,   275,   313,   189,   188,   109,   698,
     541,     1,  1710,   149,  1712,   289,   189,   189,   109,   258,
     259,   253,   155,   297,     1,   109,     1,   227,   186,   229,
     571,   305,   102,   214,   266,   102,   268,   319,   320,   321,
     158,   809,   189,   102,  1175,   120,   179,   279,   280,   281,
     390,   283,     1,   285,   394,   390,   109,   222,   109,   394,
     390,   109,   162,   109,   394,   120,  1640,   189,   109,   155,
     109,    98,   186,   109,   254,   255,   189,   257,   259,   189,
     108,   421,   422,   115,   264,    53,   421,   422,   189,     1,
     109,    98,   155,   423,   274,   132,   813,     1,   263,   190,
      43,   129,   432,   443,    47,   189,   286,   447,   443,    52,
     109,   441,   447,   188,   444,   445,   316,     1,   188,   109,
     450,   188,    46,  1142,    48,   842,     1,  1701,    71,   188,
     162,   158,   109,   188,   109,   186,     1,   190,    43,   275,
     186,   189,    47,  1007,  1008,  1009,   155,    52,   189,   489,
     189,   421,   422,   189,   489,   109,   496,  1678,  1149,   489,
     109,   496,   199,   131,   171,    96,    71,   155,   421,   422,
     189,   986,  1422,   443,   109,   505,   506,   447,  1007,  1008,
    1009,   870,   871,   513,   108,  1158,   875,  1138,    96,     1,
     443,   179,  1323,   533,   447,    78,   186,   109,   533,     9,
      10,   541,   532,   533,    30,   109,   541,   774,   109,   186,
     138,   186,   552,   553,   554,   555,   905,   552,   553,   554,
     555,   547,    34,   764,   780,   109,   496,   170,   784,    98,
     173,   571,  1288,  1730,   109,   189,   571,   186,    50,   109,
     156,  1297,   158,   496,   109,   188,   170,   254,   255,   158,
     257,   792,  1308,   109,   189,   109,   109,    96,   401,   402,
      34,   132,   405,   533,  1283,   170,   409,   274,   173,   412,
     413,   214,   155,   160,   186,   203,    50,   420,   133,   286,
     149,   424,   186,   188,   150,   428,   112,    98,   189,   220,
     221,   178,   622,   436,   624,   105,  1548,    98,   158,   442,
     126,   167,   186,   446,   235,  1022,  1023,    96,   451,   214,
     149,   186,   220,   221,   115,   125,   259,   127,    30,   189,
      96,   186,     1,   239,     3,   151,   168,   235,   199,   155,
      98,     9,   158,   189,    96,   189,   189,   192,   149,     1,
     223,   224,   184,   486,   119,   155,     1,   115,     3,   159,
     690,    29,   495,   179,   259,   690,   184,   158,     9,    10,
     155,   690,   156,    46,   158,    48,   176,   156,   144,   158,
     198,  1024,    34,   148,   714,   715,   155,  1299,  1420,   714,
     715,  1372,   144,  1425,   271,   528,   161,   197,    55,    68,
     158,   278,   535,    60,    73,   725,   726,   727,    81,   729,
     112,   288,   139,    96,  1268,   215,   146,   144,  1677,   155,
     160,  1362,    79,    68,   126,     5,   188,   212,    73,     9,
     690,   196,  1478,    96,   764,   108,     9,    10,   178,   764,
    1561,    98,    25,   212,   764,   108,   992,   690,   178,   151,
     212,   120,    35,   188,   714,   715,   139,   125,  1004,   127,
     991,   144,   792,   120,   105,   150,   196,   792,   136,   139,
     786,   714,   715,  1668,  1669,   120,   188,   212,   147,    62,
     160,   144,   167,    55,   125,   155,   127,   155,    60,   158,
     120,   184,    27,    28,  1615,   628,  1617,   170,   178,  1178,
     212,     9,    10,    38,    39,   198,    41,    42,  1000,   160,
     130,   131,    98,    48,   155,     5,     9,   650,   159,     9,
     653,   201,  1717,    58,    59,    96,    98,   178,  1723,   115,
     155,   234,   105,   236,   667,   176,    29,   108,   671,   672,
    1572,    76,   188,   139,  1576,   125,    81,   127,   860,   188,
     201,   684,   125,   686,   127,   135,   197,  1469,  1470,   155,
     872,   694,   139,   102,   697,  1462,   212,   144,   701,   158,
      85,   102,  1693,   212,   215,   155,   115,    97,   113,   114,
     115,  1288,   155,   265,   115,   556,   159,  1528,   108,   560,
    1297,   102,   158,   108,   276,   155,  1275,   105,   118,   271,
     733,  1308,  1325,   176,   115,   120,   278,   122,  1611,   129,
    1613,   120,   203,   102,   120,   102,   288,   125,   948,   127,
    1623,   212,  1625,   948,   197,   102,   115,   162,   115,   155,
     301,  1640,   125,   766,   127,   125,   155,   127,   115,   310,
    1672,  1260,   215,   136,   218,   135,  1177,   155,   279,   280,
     281,   159,    55,   234,   285,   236,   155,    60,   223,   224,
     225,   991,   155,   796,   120,   155,   991,   243,   176,   130,
     131,   603,   604,   610,   611,  1136,  1137,  1007,  1008,  1009,
    1516,  1517,  1007,  1008,  1009,  1597,  1598,   222,   948,   197,
    1006,   243,   158,   826,   827,   828,   829,   612,   613,   244,
     155,  1021,   120,   316,  1645,   948,     0,   215,   134,   192,
    1389,   169,    94,   251,   101,    51,   142,   143,   202,   145,
     103,   195,   121,   104,   147,   158,   186,   153,   263,   186,
     863,   157,   186,   159,   186,    30,    48,   154,   164,   306,
     120,   248,   286,   286,   877,   120,   155,     1,   120,   144,
     109,   155,   144,   155,   289,   181,   186,   123,  1699,   155,
     158,   158,   297,    36,   158,  1257,    17,   216,    30,   902,
     305,  1478,  1684,   232,  1453,   247,   909,   192,   911,   205,
     206,   207,   208,   209,   210,   233,   192,     3,   120,    72,
     233,   924,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,   170,   172,    96,   172,   156,    96,    96,   151,
     109,   109,    30,   162,   162,   129,  1146,   134,    96,   248,
     301,  1146,   144,   120,   134,   186,   186,  1146,   109,    96,
      98,    46,    98,   186,   155,   186,    96,  1778,   239,  1780,
     233,   227,   144,    34,   235,   192,   172,  1177,   120,  1790,
     134,   144,  1177,    96,    30,   229,   288,    96,  1188,   301,
     129,   120,   149,  1188,   155,   120,   256,    96,   186,  1188,
    1401,   200,    98,   134,   120,   155,   162,  1207,   134,   149,
     102,   102,  1207,   186,  1017,   186,  1146,   402,  1207,   123,
     405,   155,   144,    36,   409,  1225,   192,   412,   413,    30,
    1225,   120,  1232,  1146,   247,   420,   155,  1232,    81,   424,
     109,  1442,   109,   428,  1047,   260,   287,   269,   262,   146,
     158,   436,   158,   158,    30,   158,   158,   442,  1188,    30,
     158,   446,   288,   158,  1264,   158,   451,    30,   158,  1264,
     129,   158,   192,   289,   158,  1188,   158,  1207,   158,   158,
     158,   158,   229,   308,   149,   149,   149,   120,   120,    79,
     109,   144,   186,   200,  1207,  1225,   102,   134,     7,    98,
     235,   486,  1232,   158,   158,   155,   239,   235,   235,   192,
     495,   158,  1225,   188,   108,   189,    80,   235,   149,  1232,
      30,   189,    30,   189,   273,   109,   186,   189,   172,   252,
     128,   189,   284,   288,  1264,   252,   128,   189,   189,   149,
     189,   189,   149,   528,  1147,  1546,    98,   189,  1151,   189,
     535,   186,   188,   144,   188,   155,  1557,  1558,   259,  1560,
     188,   186,   186,  1166,   186,   186,   189,  1568,   282,   189,
      96,   189,  1175,   318,   189,   189,    30,   189,   189,    98,
     189,   149,    55,   172,    96,   108,  1189,    30,   109,   289,
      96,   199,   109,   120,   267,   120,  1199,   227,    96,    96,
     188,  1401,   199,   199,   189,   200,  1401,   189,   146,   189,
     189,   189,   189,   120,   188,    95,   185,   120,   199,   120,
     120,   188,   227,  1226,   295,   227,   307,   656,   201,  1097,
     416,   307,   289,   249,   864,   307,   925,  1645,   308,  1143,
    1699,   767,  1442,   628,   922,   249,   703,  1442,  1251,  1439,
    1440,  1441,   308,  1382,  1284,   396,  1013,  1167,  1261,   252,
    1282,  1189,  1265,   308,  1665,  1279,  1197,   582,   653,  1194,
    1202,   829,   583,  1265,   626,   486,  1219,  1723,  1717,   602,
     630,  1613,   667,  1321,  1321,   734,   671,   672,  1096,   328,
    1262,  1297,  1251,  1261,  1478,  1308,  1023,  1301,  1475,   684,
    1032,   686,   896,  1119,  1352,    -1,  1519,  1298,    -1,   694,
    1711,    -1,   697,   522,    -1,    -1,   701,   105,    -1,  1322,
    1323,    -1,  1325,  1326,  1327,    -1,  1329,    -1,  1729,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1546,    -1,   733,    -1,
    1751,  1546,    -1,    -1,    -1,  1358,    -1,  1557,  1558,    -1,
    1560,    -1,  1557,  1558,    -1,  1560,    -1,    -1,  1568,    -1,
      -1,  1772,    -1,  1568,    -1,    -1,  1379,  1380,    -1,    -1,
    1781,   766,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1589,
      -1,    -1,  1405,    -1,    -1,  1408,    -1,    -1,  1411,    -1,
      -1,   796,    -1,    -1,    -1,    -1,    -1,  1607,  1421,    -1,
      -1,    -1,    -1,  1426,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   826,   827,   828,   829,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1665,    -1,    -1,    -1,    -1,
    1665,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   863,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   877,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1711,    -1,    -1,    -1,    -1,  1711,   902,    -1,    -1,
      -1,    -1,    -1,    -1,   909,    -1,   911,    -1,    -1,  1729,
      -1,    -1,    -1,    -1,  1729,    -1,    -1,    -1,    -1,   924,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1751,    -1,    -1,    -1,    -1,  1751,    -1,  1561,  1562,
      -1,  1564,    -1,  1566,    -1,    -1,    -1,    -1,    -1,    -1,
    1573,    -1,  1772,    -1,    -1,    -1,    -1,  1772,    -1,    -1,
      -1,  1781,    -1,    -1,    -1,    -1,  1781,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1611,    -1,
    1613,    -1,  1615,    -1,  1617,    -1,    -1,    -1,    -1,    -1,
    1623,    -1,  1625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1017,    -1,    -1,    -1,    -1,    -1,  1641,    -1,
      -1,  1644,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1656,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1047,    -1,  1667,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1693,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1703,    -1,    -1,    -1,    -1,  1708,    -1,  1710,   496,  1712,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   517,
     518,    -1,   520,   521,   522,   523,    -1,   525,    -1,    -1,
      -1,    -1,    -1,   531,    -1,  1748,    -1,    -1,    -1,    -1,
      -1,    -1,   540,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1147,    -1,    -1,  1768,  1151,    -1,    -1,    -1,
    1773,    -1,    -1,    -1,   562,   563,    -1,    -1,    -1,    -1,
      -1,  1166,  1785,   571,   572,  1788,    -1,    -1,    -1,    -1,
    1175,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1189,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1199,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   625,    -1,    -1,
      -1,  1226,   630,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1251,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1261,    -1,    -1,    -1,
    1265,   669,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   702,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     718,    -1,    -1,    -1,   722,   723,    -1,  1322,  1323,    -1,
    1325,  1326,  1327,   731,  1329,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1358,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1379,  1380,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   792,    -1,    -1,    -1,    -1,    -1,
     798,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1405,    -1,    -1,  1408,    -1,    -1,  1411,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1421,    -1,    -1,    -1,
      -1,  1426,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   865,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   900,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   913,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   935,    -1,    -1,
      -1,    -1,    -1,    -1,   942,   943,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   953,    -1,    -1,   956,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1561,  1562,    -1,  1564,
      -1,  1566,    -1,    -1,    -1,   973,   974,   975,  1573,   977,
     978,   979,   980,   981,   982,   983,   984,   985,    -1,    -1,
     988,   989,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1003,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1013,  1611,    -1,  1613,    -1,
    1615,    -1,  1617,    -1,    -1,    -1,    -1,    -1,  1623,    -1,
    1625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1641,    -1,    -1,  1644,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1667,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1084,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1693,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1703,    -1,
      -1,    -1,    -1,  1708,    -1,  1710,    -1,  1712,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1748,    -1,  1153,    -1,  1155,    -1,  1157,
      -1,    -1,  1160,    -1,    -1,    -1,    -1,  1165,    -1,    -1,
      -1,    -1,    -1,  1768,    -1,    -1,    -1,    -1,  1773,  1177,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1186,    -1,
    1785,    -1,    -1,  1788,  1192,  1193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1209,    -1,    -1,  1212,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1282,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1366,    -1,
      -1,    -1,  1370,    -1,    -1,    -1,  1374,    -1,  1376,    -1,
    1378,    -1,    -1,    -1,    -1,    -1,  1384,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1392,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1400,  1401,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1418,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1430,  1431,  1432,  1433,    -1,  1435,  1436,    -1,
    1438,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1454,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1534,    -1,  1536,    -1,
      -1,  1539,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1547,
      -1,    -1,    -1,    -1,  1552,  1553,    -1,    -1,    -1,    -1,
      -1,    -1,  1560,    -1,    -1,    -1,    -1,  1565,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1582,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1594,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1648,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1661,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1711,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     0,     1,    -1,    -1,    -1,    -1,    -1,  1746,    -1,
      -1,    -1,    -1,  1751,    -1,    -1,    -1,    -1,  1756,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,  1771,    -1,    34,    35,  1775,    37,    38,
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
     319,   320,    -1,   322,     0,     1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     256,   257,   258,   259,    -1,   261,   262,   263,    -1,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,     1,   314,    -1,
     316,   317,   318,   319,   320,    -1,   322,    -1,    -1,    -1,
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
     254,   255,   256,   257,   258,   259,    -1,   261,   262,   263,
      -1,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,     1,
     314,    -1,   316,   317,   318,   319,   320,    -1,   322,    -1,
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
     312,    -1,   314,    -1,   316,   317,   318,   319,   320,    -1,
     322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
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
     310,   311,    -1,    -1,    16,    -1,   316,   317,   318,   319,
     320,    -1,   322,    25,    26,    -1,    -1,    -1,    30,    -1,
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
      -1,    -1,    16,    -1,   316,   317,   318,   319,   320,    -1,
     322,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   316,   317,   318,   319,   320,    -1,   322,    18,
      19,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
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
     309,   310,   311,    -1,    -1,    -1,    -1,   316,   317,   318,
     319,   320,    -1,   322,    21,    22,    23,    24,    25,    26,
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
     317,   318,   319,   320,    -1,   322,   323,   324,    21,    22,
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
      -1,   314,    -1,   316,   317,   318,   319,   320,    -1,   322,
      -1,   324,    21,    22,    23,    24,    25,    26,    27,    28,
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
     319,   320,    -1,   322,    21,    22,    23,    24,    25,    26,
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
     317,   318,   319,   320,    -1,   322,    21,    22,    23,    24,
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
      -1,   316,   317,   318,   319,   320,    -1,   322,    21,    22,
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
      -1,   314,    -1,   316,   317,   318,   319,   320,    -1,   322,
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
      -1,   322,    21,    22,    23,    24,    25,    26,    27,    28,
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
     319,   320,    -1,   322,    21,    22,    23,    24,    25,    26,
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
     317,   318,   319,   320,    -1,   322,    21,    22,    23,    24,
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
      -1,   316,   317,   318,   319,   320,    -1,   322,    21,    22,
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
      -1,   314,    -1,   316,   317,   318,   319,   320,    -1,   322,
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
      -1,   182,   183,   184,    -1,    -1,   187,   188,    -1,   190,
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
      -1,   322,    21,    22,    23,    24,    25,    26,    -1,    -1,
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
     319,   320,    -1,   322,    21,    22,    23,    24,    25,    26,
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
     307,   308,   309,   310,   311,   312,   313,   314,    -1,   316,
     317,   318,   319,   320,    -1,   322,    21,    22,    23,    24,
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
     255,   256,   257,   258,   259,    -1,   261,   262,   263,    -1,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,    -1,   322,    21,    22,
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
     253,   254,   255,   256,   257,   258,   259,    -1,   261,   262,
     263,    -1,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      -1,   314,    -1,   316,   317,   318,   319,   320,    -1,   322,
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
      -1,   322,    21,    22,    23,    24,    25,    26,    -1,    -1,
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
     319,   320,    -1,   322,    21,    22,    23,    24,    25,    26,
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
     317,   318,   319,   320,    -1,   322,    21,    22,    23,    24,
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
     255,   256,   257,   258,   259,    -1,   261,   262,   263,    -1,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    -1,   314,
      -1,   316,   317,   318,   319,   320,    -1,   322,    21,    22,
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
     253,   254,   255,   256,   257,   258,   259,    -1,   261,   262,
     263,    -1,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
      -1,   314,    -1,   316,   317,   318,   319,   320,    -1,   322,
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
      -1,   322,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
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
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     319,   320,    -1,   322,    34,    35,    -1,    37,    38,    39,
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
     320,    -1,   322,    34,    35,    -1,    37,    38,    39,    40,
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
      -1,   322,    34,    35,    -1,    37,    38,    39,    40,    41,
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
      -1,    -1,    25,    26,   316,   317,   318,   319,   320,    -1,
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
      -1,    -1,    -1,   316,   317,   318,   319,   320,    -1,   322
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
     317,   318,   319,   320,   322,   323,   324,   337,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   358,   359,   360,   361,   362,
     363,   367,   368,   369,   373,   375,   376,   378,   385,   387,
     390,   391,   392,   394,   395,   396,   397,   398,   400,   401,
     403,   404,   405,   406,   407,   408,   410,   411,   414,   415,
     416,   417,   422,   424,   426,   427,   432,   451,   454,   458,
     461,   462,   468,   469,   470,   471,   473,   474,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   486,   487,   488,
     489,   492,   493,   494,   495,   496,   497,   498,   501,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   514,   515,
     516,   530,   531,   533,   534,   535,   536,   537,   538,   539,
     540,   561,   562,   563,   564,   569,   570,   571,   572,   573,
     574,   577,   635,   636,   637,   638,   640,   641,   642,   643,
     644,   651,   652,   653,    34,    35,    50,   217,   393,   394,
     395,   393,   393,   394,   395,   158,   158,    38,    39,    41,
      42,    48,    58,    59,    76,    81,   113,   114,   115,   162,
     222,   263,   289,   297,   305,   374,   375,   379,   380,   381,
     162,   155,   155,   155,     1,     3,    68,    73,   120,   419,
     158,   382,   158,    25,    35,    62,   120,   275,   431,   433,
     434,   155,   120,   155,   158,   158,    78,   155,   223,   224,
     155,   120,   402,    40,    44,    46,    47,    48,    49,    52,
      61,    69,    72,    74,    75,    77,    99,   114,   137,   162,
     171,   204,   226,   228,   230,   231,   238,   240,   241,   242,
     245,   246,   259,   317,   651,   652,   120,   186,   393,   395,
     415,   639,    49,    74,    75,   120,   155,   187,   246,   414,
     416,   426,   189,   414,   651,   155,   155,    16,   650,   651,
      18,    19,   651,   155,    31,   216,   218,   227,   229,   316,
     227,   229,   316,   227,   316,   227,   232,   316,   120,   243,
     243,   244,   158,   155,   397,   120,   313,   414,   315,   414,
     316,   324,   339,   339,     0,   341,   342,    34,    50,   344,
     361,     1,   192,   338,   192,   338,   114,   376,   396,   414,
     109,   192,   109,   338,   192,    43,    47,    52,    71,   170,
     173,   188,   214,   259,   409,   418,   423,   424,   425,   439,
     440,   444,   169,    94,   134,   142,   143,   145,   153,   157,
     159,   164,   181,   205,   206,   207,   208,   209,   210,   490,
     491,   251,   101,   160,   178,   201,   119,   148,   161,   196,
     203,   212,   138,   152,    51,   202,   103,   104,   160,   178,
     488,   195,   155,   495,   156,   158,   502,   503,   121,   147,
     158,   186,   186,   186,   186,   377,   505,   377,    30,   649,
     184,   198,   184,   198,   168,   184,   652,   651,   171,   204,
      48,   651,   154,   120,    46,    48,    81,   108,   170,   650,
     223,   224,   225,   248,   608,   651,   651,   306,   139,   144,
     114,   289,   297,   379,   650,   394,   394,   414,   428,   429,
     651,   286,   286,   428,   120,   435,   120,   189,   383,   384,
     155,   399,   414,     1,   162,   649,   115,   162,   357,   649,
     651,   120,   144,   109,   414,   452,   453,   651,   394,   414,
     414,   559,   651,   394,   155,   155,   414,   651,   144,   452,
     186,   186,   123,   109,   186,   158,   158,   158,   651,   155,
     187,   188,   189,    36,   518,   519,   520,   414,   414,     8,
     177,    17,   414,   216,    30,   415,   415,   501,   415,   415,
     415,   639,   415,   501,   415,   233,   232,   575,   576,   651,
     192,   192,   415,   414,   395,   414,   247,   412,   413,   428,
     313,   315,   415,   339,   192,   338,   192,   338,     3,   345,
     361,   391,     1,   345,   361,   391,    34,   362,   391,   362,
     391,   402,   338,   402,   415,   415,   120,   170,   172,   172,
     396,   415,   415,   470,   471,   473,   473,   473,   473,   472,
     473,   473,   473,    72,   474,   478,   478,   477,   479,   479,
     479,   479,   480,   480,   481,   481,   233,    96,    96,    96,
     496,   186,   414,   414,   189,   415,   513,   503,   650,   151,
     189,   513,   109,   189,   189,   109,   109,   382,    30,   652,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
     364,   365,   366,    96,   139,   144,   370,   371,   372,   651,
     162,   162,   364,   649,   129,   134,    56,    58,   102,   253,
     266,   268,   279,   280,   281,   283,   285,   609,   610,   611,
     612,   613,   614,   621,   627,   628,   248,    96,   301,   651,
     144,   415,   120,   651,   651,   134,   186,   186,   186,   109,
      37,    96,    98,   149,   430,   431,   541,   651,    57,   219,
     256,   420,   421,   651,    96,   109,   189,   393,   189,   650,
      98,    46,   650,   649,    98,   144,   541,   651,   415,   434,
     186,   109,   190,   149,   541,   186,   189,   189,   155,   186,
     394,   394,   186,   144,   541,   415,   190,   415,   415,   414,
     414,   414,   651,   519,   520,   132,   199,   186,   186,   186,
     133,   192,    96,   220,   221,   235,    96,   220,   221,   235,
     235,   235,    96,    96,   239,   227,   233,   109,   237,   144,
     192,   189,   414,   186,    11,    12,    20,   196,   499,   500,
     581,   651,   413,   235,   361,    34,    34,   192,   338,   192,
     115,   396,   651,   172,   415,   445,   446,   120,   441,   442,
     473,   155,   158,   261,   494,   505,   582,   585,   586,   587,
     588,   589,   593,   595,   597,   598,    40,    45,    46,    48,
      54,    61,    63,    64,    72,    99,   154,   158,   213,   227,
     319,   320,   321,   322,   542,   544,   546,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   557,   558,   565,   566,
     567,   568,   645,   646,   647,   648,   651,   542,   485,   547,
     651,   485,   186,   187,   109,   189,   189,   505,   150,   167,
     150,   167,   139,   399,   382,   365,   134,   544,   372,   415,
     541,   649,   649,   130,   131,   649,   279,   280,   281,   285,
     651,   265,   276,   265,   276,    30,   288,    98,   115,   158,
     615,   618,   609,    40,    45,    46,    54,    61,    63,    64,
      72,    99,   227,   319,   320,   386,   548,   645,   229,   301,
     310,   415,   651,    96,   301,   649,   155,   120,   429,   129,
     542,   120,   415,   149,   431,   149,    37,   149,   430,   431,
     149,   541,   256,    55,    60,    79,   120,   430,   436,   437,
     438,   421,   541,   542,   384,    96,   186,   200,   134,   356,
     649,   162,   134,    98,   356,   415,   144,   431,   155,   120,
     415,   415,   149,   102,   455,   456,   457,   459,   460,   102,
     463,   464,   465,   466,   394,   186,   186,   155,   415,   144,
     192,   415,   123,   189,   189,   189,    36,   520,   132,   199,
       9,    10,   105,   125,   127,   155,   197,   515,   517,   528,
     529,   532,   155,    30,   234,   236,   415,   415,   415,   234,
     236,   415,   415,   415,   415,   415,   415,   415,   415,   415,
     501,   120,   415,   415,    49,    74,    75,   246,   396,   416,
     426,   247,   578,   579,   155,   212,   397,   415,   192,   115,
     391,   391,   391,   445,    97,   108,   118,   129,   447,   448,
     449,   450,   109,   651,   109,   414,   582,   589,   155,   287,
     475,   634,    98,   171,   254,   255,   257,   264,   274,   286,
     583,   584,   603,   604,   605,   606,   629,   632,   260,   262,
     590,   608,   269,   594,   630,   249,   250,   272,   599,   600,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   544,   158,   158,   158,   158,   158,   146,   178,   196,
     543,   146,   415,   139,   399,   561,   371,   288,    30,    98,
     115,   158,   622,    30,   615,   543,   543,   496,   289,   308,
     541,   386,   229,   192,   393,   429,   149,   430,   651,   415,
     149,   415,   129,   415,   149,   431,   149,   415,   149,   120,
     120,   415,   651,   438,    79,   542,   396,   415,   649,   109,
     356,   415,   144,   393,   453,   415,   415,   115,   456,   457,
     102,   188,   115,   457,   460,   120,   467,   542,   102,   115,
     464,   102,   115,   466,   186,   393,   415,   415,   200,   463,
     134,   197,   517,     7,   394,   651,   197,   528,   394,   192,
     235,   235,   235,   235,    98,   239,   239,   576,   188,   158,
     158,   158,   188,   581,   579,   499,   649,   130,   131,   449,
     450,   450,   446,   108,   144,   443,   541,   442,   186,   189,
     582,   596,   252,   219,   256,   270,   277,   633,    98,   258,
     259,   631,   252,   586,   633,   477,   603,   587,   149,   284,
     591,   592,   631,   288,   602,    80,   601,   189,   189,   557,
     558,   189,   196,   651,   189,   196,   542,   545,   189,    30,
     189,   650,   651,   651,   189,   189,   196,   651,   189,   189,
     189,   189,   189,   189,   189,    30,   138,   203,   624,   625,
     626,    30,   623,   624,   273,   619,   109,   616,   172,   651,
     259,   496,   186,   415,   149,   415,   149,   430,   415,   149,
     415,   415,   651,   651,   437,   415,   128,   128,    98,   649,
     415,   186,   188,   188,   415,   396,   415,   188,   188,   651,
     188,   212,   120,   467,   120,   188,   120,   467,   188,   186,
     115,   520,   651,   197,   186,   520,   651,   186,   415,   415,
     415,   415,   318,   415,   415,   415,   414,   414,   414,   155,
     580,   450,   649,   415,   144,   186,   479,    53,   131,   477,
     477,   271,   278,   288,   607,   607,   588,   155,   282,   189,
     189,   109,   189,   109,   189,    96,   189,   109,   189,   189,
     189,   189,   189,   109,   189,   109,   189,   622,   622,   626,
     109,   189,    30,   620,   631,   617,   618,   189,   388,   389,
     496,   120,   227,   309,   289,   172,   415,   415,   149,   415,
      55,   396,   415,   356,   415,   396,    96,   396,   415,   542,
     651,   188,   651,   415,   651,   188,   396,   120,    95,   185,
     521,   520,   651,   199,   520,   415,   189,   189,   189,   414,
     443,   415,   477,   477,   201,   414,   559,   560,   651,   559,
     560,   542,   542,    96,   559,   559,    30,   267,   109,   109,
     450,   541,   651,   120,   227,   651,   388,   415,   120,   467,
      96,   188,    96,   651,     5,   135,   524,   525,   527,   529,
      29,   136,   522,   523,   526,   529,   199,   520,   199,   200,
     463,   186,   443,   477,   186,   189,   189,   146,   189,   189,
     542,   189,   189,   618,   389,   450,   307,   651,   120,   227,
     651,   188,   467,   396,   415,   467,   188,    95,   135,   527,
     185,   136,   526,   199,   115,   415,   307,   651,   120,   396,
     415,   188,   188,   120,   295,   307,   651,   651,   308,   415,
     308,   188,   496,   496,   201,   289,   651,   227,   120,   651,
     308,   496
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
     425,   425,   426,   426,   427,   427,   427,   427,   428,   428,
     428,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   430,   431,   432,   433,   433,   434,   434,
     434,   434,   435,   435,   436,   436,   436,   437,   437,   437,
     438,   438,   438,   439,   440,   441,   441,   442,   442,   442,
     442,   442,   442,   443,   444,   444,   445,   445,   446,   446,
     447,   447,   447,   447,   447,   447,   447,   448,   448,   449,
     449,   450,   451,   451,   452,   452,   453,   453,   454,   455,
     455,   456,   457,   457,   458,   459,   459,   460,   461,   461,
     462,   462,   463,   463,   464,   464,   465,   465,   466,   466,
     467,   467,   468,   469,   469,   470,   470,   471,   471,   471,
     471,   471,   472,   471,   471,   471,   471,   473,   473,   474,
     474,   475,   475,   476,   476,   477,   477,   477,   478,   478,
     478,   478,   478,   479,   479,   479,   480,   480,   480,   481,
     481,   482,   482,   483,   483,   484,   484,   485,   485,   486,
     486,   487,   487,   487,   487,   488,   488,   488,   489,   489,
     490,   490,   490,   490,   490,   490,   491,   491,   491,   492,
     492,   492,   492,   493,   493,   494,   494,   495,   495,   495,
     496,   497,   498,   499,   499,   500,   500,   500,   500,   501,
     501,   501,   501,   502,   502,   503,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   505,   505,   506,   506,   506,   507,   508,   508,   509,
     510,   511,   512,   512,   513,   513,   514,   514,   515,   515,
     515,   516,   516,   516,   516,   516,   516,   517,   517,   518,
     518,   519,   520,   520,   521,   521,   522,   522,   523,   523,
     523,   523,   524,   524,   525,   525,   525,   525,   526,   526,
     527,   527,   528,   528,   528,   528,   529,   529,   529,   529,
     530,   530,   531,   531,   532,   533,   533,   533,   533,   533,
     533,   533,   534,   535,   535,   536,   536,   537,   538,   539,
     539,   540,   540,   541,   542,   542,   542,   543,   543,   543,
     544,   544,   544,   544,   544,   544,   544,   545,   545,   546,
     547,   548,   548,   548,   548,   548,   548,   548,   548,   548,
     548,   549,   550,   550,   550,   551,   552,   553,   554,   554,
     554,   555,   555,   555,   555,   555,   556,   557,   557,   557,
     557,   557,   557,   557,   558,   559,   560,   561,   562,   562,
     563,   564,   565,   565,   566,   567,   567,   568,   569,   569,
     569,   570,   570,   570,   570,   570,   570,   570,   570,   570,
     570,   571,   571,   572,   572,   573,   574,   575,   575,   576,
     577,   578,   578,   579,   580,   581,   581,   582,   583,   583,
     584,   584,   585,   585,   586,   586,   587,   587,   588,   588,
     589,   590,   590,   591,   591,   592,   593,   593,   593,   594,
     594,   595,   596,   596,   597,   598,   598,   599,   599,   600,
     600,   600,   601,   601,   602,   602,   603,   603,   603,   603,
     603,   604,   605,   606,   607,   607,   607,   608,   608,   609,
     609,   609,   609,   609,   609,   609,   609,   610,   610,   610,
     610,   611,   611,   612,   613,   613,   614,   614,   614,   615,
     615,   616,   616,   617,   617,   618,   619,   619,   620,   620,
     621,   621,   621,   622,   622,   623,   623,   624,   624,   625,
     625,   626,   626,   627,   628,   628,   629,   629,   629,   630,
     631,   631,   631,   631,   632,   632,   633,   633,   634,   635,
     635,   636,   636,   637,   637,   638,   639,   639,   640,   640,
     640,   641,   642,   643,   644,   645,   645,   645,   646,   647,
     648,   649,   650,   650,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   652,   652,   652,   652,   652,   652,   652,   652,   652,
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
     652,   652,   652,   652,   652,   652,   653
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
       1,     1,     1,     2,     3,     3,     3,     2,     1,     4,
       3,     3,     5,     4,     6,     4,     6,     5,     7,     4,
       5,     5,     6,     3,     3,     2,     1,     3,     4,     5,
       3,     6,     4,     5,     1,     2,     3,     1,     2,     1,
       6,     3,     3,     2,     3,     1,     3,     2,     4,     5,
       6,     5,     3,     2,     3,     4,     1,     3,     1,     2,
       1,     1,     1,     2,     2,     2,     3,     1,     1,     2,
       2,     2,     5,     5,     1,     4,     3,     4,     8,     1,
       2,     3,     2,     3,     8,     1,     2,     3,     8,    10,
       8,    10,     1,     2,     4,     7,     1,     2,     4,     7,
       1,     3,     8,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     0,     4,     3,     3,     3,     1,     5,     1,
       3,     0,     1,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       4,     1,     4,     1,     4,     1,     4,     1,     2,     1,
       2,     1,     1,     2,     2,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       5,     5,     6,     3,     4,     1,     2,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     4,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     2,     2,     3,     1,
       4,     4,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     4,     8,     5,     9,     9,    10,     1,     2,     1,
       2,     6,     0,     1,     3,     3,     0,     1,     1,     1,
       2,     2,     0,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     2,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     7,     3,     7,     4,     4,     3,
       7,     3,     7,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     4,     3,     3,     3,     3,     4,
       4,     3,     4,     6,     4,     6,     4,     3,     4,     6,
       6,     4,     6,     6,     4,     1,     2,     1,     1,     1,
       3,     3,     1,     1,     4,     5,     6,     3,     3,     3,
       3,     5,     7,     7,     5,     5,     5,     7,     7,     5,
       5,     3,     3,     5,     7,     5,     7,     1,     4,     3,
       5,     1,     2,     3,     3,     1,     3,     2,     0,     1,
       1,     2,     1,     3,     1,     3,     1,     4,     1,     2,
       3,     0,     1,     0,     1,     4,     2,     3,     1,     0,
       1,     4,     0,     1,     2,     1,     3,     0,     1,     2,
       2,     1,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     2,     2,     3,     1,     2,     2,     5,     2,     1,
       1,     0,     2,     1,     3,     4,     0,     2,     0,     2,
       4,     4,     3,     2,     3,     1,     3,     0,     1,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     3,
       2,     3,     3,     4,     2,     2,     1,     1,     3,     2,
       3,     2,     3,     2,     3,     3,     3,     5,     5,     5,
       8,     5,     3,     5,     7,     1,     1,     1,     1,     3,
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
  "FunctionCall", "ArgList", "Constructor", "DirectConstructor",
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
     561,    -1,    82,    -1,    90,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    91,    -1,    87,    -1,    88,    -1,
      89,    -1,    34,    58,   651,    30,    -1,    34,   263,   608,
      -1,    34,   113,   154,   370,    -1,    96,   544,   371,    -1,
     371,    -1,   372,    -1,   139,    -1,   139,   372,    -1,   144,
     415,    -1,    34,   374,   144,   415,    -1,    34,   374,   139,
      -1,    34,   374,   139,   144,   415,    -1,   114,   120,   651,
      -1,   114,   120,   651,   541,    -1,   375,   114,   120,   651,
      -1,   375,   114,   120,   651,   541,    -1,   376,    -1,   375,
     376,    -1,    27,    -1,    27,   158,   377,   189,    -1,    28,
      -1,    28,   158,   377,   189,    -1,   505,    -1,   377,   109,
     505,    -1,    34,   379,    -1,    34,   375,   379,    -1,   380,
      -1,   381,    -1,    48,   652,   382,   399,    -1,    48,   652,
     382,   139,    -1,    76,    48,   652,   382,   399,    -1,    76,
      48,   652,   382,   139,    -1,   158,   189,    -1,   158,   383,
     189,    -1,   158,   189,    96,   542,    -1,   158,   383,   189,
      96,   542,    -1,   384,    -1,   383,   109,   384,    -1,   120,
     651,    -1,   120,   651,   541,    -1,    34,   289,   651,    -1,
      34,   289,   651,    96,   386,    -1,    34,   375,   289,   651,
      -1,    34,   375,   289,   651,    96,   386,    -1,   548,    -1,
     548,   543,    -1,   645,    -1,   645,   543,    -1,    34,   297,
     651,   301,   229,   496,   172,   388,    -1,    34,   375,   297,
     651,   301,   229,   496,   172,   388,    -1,   389,    -1,   388,
     109,   389,    -1,   496,    -1,   496,   541,    -1,   496,   450,
      -1,   496,   541,   450,    -1,    34,   305,   306,   651,   301,
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
     651,    -1,   120,   651,   541,    -1,   120,   651,   144,   415,
      -1,   120,   651,   541,   144,   415,    -1,   120,   651,   144,
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
     426,   425,    -1,    47,   120,   428,    -1,   259,   120,   428,
      -1,    47,     1,   428,    -1,    47,     3,    -1,   429,    -1,
     428,   109,   120,   429,    -1,   428,   109,   429,    -1,   651,
     149,   415,    -1,   651,    37,   129,   149,   415,    -1,   651,
     541,   149,   415,    -1,   651,   541,    37,   129,   149,   415,
      -1,   651,   430,   149,   415,    -1,   651,    37,   129,   430,
     149,   415,    -1,   651,   541,   430,   149,   415,    -1,   651,
     541,    37,   129,   430,   149,   415,    -1,   651,   431,   149,
     415,    -1,   651,   541,   431,   149,   415,    -1,   651,   430,
     431,   149,   415,    -1,   651,   541,   430,   431,   149,   415,
      -1,    98,   120,   651,    -1,   275,   120,   651,    -1,    52,
     433,    -1,   434,    -1,   433,   109,   434,    -1,   120,   651,
     144,   415,    -1,   120,   651,   541,   144,   415,    -1,   431,
     144,   415,    -1,   120,   651,   541,   431,   144,   415,    -1,
     120,   651,   149,   415,    -1,   120,   651,   541,   149,   415,
      -1,   437,    -1,   120,   651,    -1,   120,   651,   437,    -1,
     430,    -1,   430,   438,    -1,   438,    -1,    60,   120,   651,
      55,   120,   651,    -1,    55,   120,   651,    -1,    60,   120,
     651,    -1,   214,   415,    -1,   173,   172,   441,    -1,   442,
      -1,   441,   109,   442,    -1,   120,   651,    -1,   120,   651,
     144,   415,    -1,   120,   651,   541,   144,   415,    -1,   120,
     651,   541,   144,   415,   443,    -1,   120,   651,   144,   415,
     443,    -1,   120,   651,   443,    -1,   108,   649,    -1,   170,
     172,   445,    -1,    71,   170,   172,   445,    -1,   446,    -1,
     445,   109,   446,    -1,   415,    -1,   415,   447,    -1,   448,
      -1,   449,    -1,   450,    -1,   448,   449,    -1,   448,   450,
      -1,   449,   450,    -1,   448,   449,   450,    -1,    97,    -1,
     118,    -1,   129,   130,    -1,   129,   131,    -1,   108,   649,
      -1,    69,   120,   452,   190,   415,    -1,   137,   120,   452,
     190,   415,    -1,   453,    -1,   452,   109,   120,   453,    -1,
     651,   149,   415,    -1,   651,   541,   149,   415,    -1,    74,
     158,   414,   189,   455,   115,   188,   415,    -1,   456,    -1,
     455,   456,    -1,   457,   188,   415,    -1,   102,   415,    -1,
     457,   102,   415,    -1,    74,   158,   414,   189,   459,   115,
     188,   396,    -1,   460,    -1,   459,   460,    -1,   457,   188,
     396,    -1,    75,   158,   414,   189,   463,   115,   188,   415,
      -1,    75,   158,   414,   189,   463,   115,   120,   651,   188,
     415,    -1,    75,   158,   414,   189,   465,   115,   188,   396,
      -1,    75,   158,   414,   189,   463,   115,   120,   651,   188,
     396,    -1,   464,    -1,   463,   464,    -1,   102,   467,   188,
     415,    -1,   102,   120,   651,    96,   467,   188,   415,    -1,
     466,    -1,   465,   466,    -1,   102,   467,   188,   396,    -1,
     102,   120,   651,    96,   467,   188,   396,    -1,   542,    -1,
     467,   212,   542,    -1,    49,   158,   414,   189,   200,   415,
     128,   415,    -1,   470,    -1,   469,   169,   470,    -1,   471,
      -1,   470,    94,   471,    -1,   473,    -1,   473,   490,   473,
      -1,   473,   491,   473,    -1,   473,   134,   473,    -1,   473,
     164,   473,    -1,    -1,   473,   159,   472,   473,    -1,   473,
     157,   473,    -1,   473,   145,   473,    -1,   473,   143,   473,
      -1,   474,    -1,   474,   251,    72,   582,   475,    -1,   476,
      -1,   476,   101,   474,    -1,    -1,   634,    -1,   477,    -1,
     477,   201,   477,    -1,   478,    -1,   477,   178,   478,    -1,
     477,   160,   478,    -1,   479,    -1,   478,   196,   479,    -1,
     478,   119,   479,    -1,   478,   148,   479,    -1,   478,   161,
     479,    -1,   480,    -1,   479,   203,   480,    -1,   479,   212,
     480,    -1,   481,    -1,   480,   152,   481,    -1,   480,   138,
     481,    -1,   482,    -1,   482,    51,   233,   542,    -1,   483,
      -1,   483,   202,    96,   542,    -1,   484,    -1,   484,   103,
      96,   485,    -1,   486,    -1,   486,   104,    96,   485,    -1,
     547,    -1,   547,   146,    -1,   488,    -1,   487,   488,    -1,
     178,    -1,   160,    -1,   487,   178,    -1,   487,   160,    -1,
     492,    -1,   489,    -1,   493,    -1,   496,    -1,   489,   195,
     496,    -1,   205,    -1,   210,    -1,   209,    -1,   208,    -1,
     207,    -1,   206,    -1,   153,    -1,   181,    -1,   142,    -1,
      77,   155,   394,   186,    -1,    77,   224,   155,   394,   186,
      -1,    77,   223,   155,   394,   186,    -1,    77,    78,   559,
     155,   394,   186,    -1,   494,   155,   186,    -1,   494,   155,
     414,   186,    -1,   495,    -1,   494,   495,    -1,   179,   651,
      17,    -1,   179,    18,    -1,   179,    19,    -1,   497,    -1,
     498,    -1,   501,    -1,   651,    -1,   500,    -1,   196,    -1,
      11,    -1,    12,    -1,    20,    -1,   504,    -1,   501,   502,
      -1,   501,   158,   189,    -1,   501,   158,   513,   189,    -1,
     503,    -1,   502,   503,    -1,   156,   414,   187,    -1,   505,
      -1,   507,    -1,   508,    -1,   509,    -1,   512,    -1,   514,
      -1,   510,    -1,   511,    -1,   562,    -1,   398,    -1,   638,
      -1,   635,    -1,   636,    -1,   637,    -1,   504,   121,   650,
      -1,   506,    -1,   561,    -1,   112,    -1,   151,    -1,   126,
      -1,   120,   651,    -1,   158,   189,    -1,   158,   414,   189,
      -1,   121,    -1,   171,   155,   414,   186,    -1,   204,   155,
     414,   186,    -1,   652,   158,   189,    -1,   652,   158,   513,
     189,    -1,   415,    -1,   513,   109,   415,    -1,   515,    -1,
     533,    -1,   516,    -1,   530,    -1,   531,    -1,   159,   651,
     520,   132,    -1,   159,   651,   520,   199,   197,   651,   520,
     199,    -1,   159,   651,   518,   520,   132,    -1,   159,   651,
     518,   520,   199,   197,   651,   520,   199,    -1,   159,   651,
     520,   199,   517,   197,   651,   520,   199,    -1,   159,   651,
     518,   520,   199,   517,   197,   651,   520,   199,    -1,   528,
      -1,   517,   528,    -1,   519,    -1,   518,   519,    -1,    36,
     651,   520,   134,   520,   521,    -1,    -1,    36,    -1,   185,
     522,   185,    -1,    95,   524,    95,    -1,    -1,   523,    -1,
     136,    -1,   526,    -1,   523,   136,    -1,   523,   526,    -1,
      -1,   525,    -1,   135,    -1,   527,    -1,   525,   135,    -1,
     525,   527,    -1,    29,    -1,   529,    -1,     5,    -1,   529,
      -1,   515,    -1,    10,    -1,   532,    -1,   529,    -1,     9,
      -1,   125,    -1,   127,    -1,   155,   394,   186,    -1,   215,
      31,   216,    -1,   215,   216,    -1,   176,   650,   177,    -1,
     176,   650,     8,    -1,   105,     7,    -1,   534,    -1,   535,
      -1,   536,    -1,   537,    -1,   538,    -1,   539,    -1,   540,
      -1,    44,   155,   394,   186,    -1,    21,   393,   186,    -1,
      46,   155,   414,   186,   155,   393,   186,    -1,    22,   393,
     186,    -1,    99,   155,   414,   186,   155,   393,   186,    -1,
      72,   155,   394,   186,    -1,    40,   155,   394,   186,    -1,
      23,   393,   186,    -1,    61,   155,   414,   186,   155,   393,
     186,    -1,    24,   394,   186,    -1,   162,   155,   414,   186,
     155,   394,   186,    -1,    96,   542,    -1,   544,    -1,   544,
     543,    -1,   213,   158,   189,    -1,   146,    -1,   196,    -1,
     178,    -1,   546,    -1,   548,    -1,   154,   158,   189,    -1,
     322,   158,   189,    -1,   565,    -1,   568,    -1,   645,    -1,
     542,    -1,   545,   109,   542,    -1,   651,    -1,   651,    -1,
     550,    -1,   557,    -1,   555,    -1,   558,    -1,   556,    -1,
     554,    -1,   553,    -1,   552,    -1,   551,    -1,   549,    -1,
     227,   158,   189,    -1,    45,   158,   189,    -1,    45,   158,
     557,   189,    -1,    45,   158,   558,   189,    -1,    54,   158,
     189,    -1,    72,   158,   189,    -1,    40,   158,   189,    -1,
      61,   158,   189,    -1,    61,   158,   650,   189,    -1,    61,
     158,    30,   189,    -1,    99,   158,   189,    -1,    99,   158,
     651,   189,    -1,    99,   158,   651,   109,   559,   189,    -1,
      99,   158,   196,   189,    -1,    99,   158,   196,   109,   559,
     189,    -1,    63,   158,   651,   189,    -1,    46,   158,   189,
      -1,    46,   158,   651,   189,    -1,    46,   158,   651,   109,
     559,   189,    -1,    46,   158,   651,   109,   560,   189,    -1,
      46,   158,   196,   189,    -1,    46,   158,   196,   109,   559,
     189,    -1,    46,   158,   196,   109,   560,   189,    -1,    64,
     158,   651,   189,    -1,   651,    -1,   651,   146,    -1,    30,
      -1,   563,    -1,   564,    -1,   651,   147,   151,    -1,    48,
     382,   399,    -1,   566,    -1,   567,    -1,    48,   158,   196,
     189,    -1,    48,   158,   189,    96,   542,    -1,    48,   158,
     545,   189,    96,   542,    -1,   158,   544,   189,    -1,    34,
     222,   223,    -1,    34,   222,   224,    -1,    34,   222,   225,
      -1,   228,   227,   415,   235,   415,    -1,   228,   227,   415,
      96,   234,   235,   415,    -1,   228,   227,   415,    96,   236,
     235,   415,    -1,   228,   227,   415,   220,   415,    -1,   228,
     227,   415,   221,   415,    -1,   228,   229,   415,   235,   415,
      -1,   228,   229,   415,    96,   234,   235,   415,    -1,   228,
     229,   415,    96,   236,   235,   415,    -1,   228,   229,   415,
     220,   415,    -1,   228,   229,   415,   221,   415,    -1,   226,
     227,   415,    -1,   226,   229,   415,    -1,   231,   227,   415,
     239,   415,    -1,   231,   232,   233,   227,   415,   239,   415,
      -1,   230,   227,   415,    96,   415,    -1,   238,   120,   575,
     237,   415,   188,   415,    -1,   576,    -1,   575,   109,   120,
     576,    -1,   651,   144,   415,    -1,   246,   155,   414,   186,
     578,    -1,   579,    -1,   578,   579,    -1,   247,   581,   580,
      -1,   155,   414,   186,    -1,   499,    -1,   581,   212,   499,
      -1,   585,   583,    -1,    -1,   584,    -1,   603,    -1,   584,
     603,    -1,   586,    -1,   585,   264,   586,    -1,   587,    -1,
     586,   260,   587,    -1,   588,    -1,   587,   262,   149,   588,
      -1,   589,    -1,   261,   589,    -1,   593,   590,   591,    -1,
      -1,   608,    -1,    -1,   592,    -1,   284,   155,   414,   186,
      -1,   597,   594,    -1,   158,   582,   189,    -1,   595,    -1,
      -1,   630,    -1,   494,   155,   596,   186,    -1,    -1,   582,
      -1,   598,   599,    -1,   505,    -1,   155,   414,   186,    -1,
      -1,   600,    -1,   250,   601,    -1,   249,   602,    -1,   272,
      -1,    -1,    80,    -1,    -1,   288,    -1,   604,    -1,   605,
      -1,   606,    -1,   632,    -1,   629,    -1,   171,    -1,   286,
     477,   607,    -1,   255,   631,   607,    -1,   288,    -1,   278,
      -1,   271,    -1,   248,   609,    -1,   608,   248,   609,    -1,
     610,    -1,   611,    -1,   612,    -1,   627,    -1,   613,    -1,
     621,    -1,   614,    -1,   628,    -1,   102,   276,    -1,   102,
     265,    -1,   268,    -1,   283,    -1,   253,   276,    -1,   253,
     265,    -1,    58,   651,    30,    -1,   279,    -1,    56,   279,
      -1,   281,   615,    -1,   281,   158,   615,   616,   189,    -1,
      56,   281,    -1,   618,    -1,   115,    -1,    -1,   109,   617,
      -1,   618,    -1,   617,   109,   618,    -1,    98,    30,   619,
     620,    -1,    -1,   273,    30,    -1,    -1,   631,   267,    -1,
     280,   288,   622,   624,    -1,   280,   288,   115,   624,    -1,
      56,   280,   288,    -1,    98,    30,    -1,   158,   623,   189,
      -1,    30,    -1,   623,   109,    30,    -1,    -1,   625,    -1,
     626,    -1,   625,   626,    -1,   203,   622,    -1,   138,   622,
      -1,   266,    30,    -1,   285,    -1,    56,   285,    -1,    98,
     219,    -1,    98,   256,    -1,   257,   252,    -1,   269,   631,
     282,    -1,   258,   477,    -1,    98,   131,   477,    -1,    98,
      53,   477,    -1,   259,   477,   201,   477,    -1,   274,   633,
      -1,   254,   633,    -1,   277,    -1,   270,    -1,   287,   252,
     479,    -1,   156,   187,    -1,   156,   414,   187,    -1,   312,
     313,    -1,   312,   414,   313,    -1,   314,   315,    -1,   314,
     414,   315,    -1,   155,   639,   186,    -1,   415,   123,   415,
      -1,   639,   109,   415,   123,   415,    -1,   228,   316,   415,
     235,   415,    -1,   228,   316,   639,   235,   415,    -1,   228,
     316,   415,   235,   415,    98,   318,   415,    -1,   317,   316,
     415,   235,   415,    -1,   226,   316,   501,    -1,   230,   316,
     501,    96,   415,    -1,   231,   316,   232,   233,   501,   239,
     415,    -1,   646,    -1,   647,    -1,   648,    -1,   321,    -1,
     319,   158,   189,    -1,   320,   158,   189,    -1,    30,    -1,
      16,    -1,   651,    -1,   652,    -1,    99,    -1,    40,    -1,
      45,    -1,    54,    -1,    46,    -1,   154,    -1,    49,    -1,
     227,    -1,    61,    -1,    63,    -1,    64,    -1,    72,    -1,
      75,    -1,    74,    -1,   213,    -1,   245,    -1,   653,    -1,
      25,    -1,   217,    -1,   129,    -1,    39,    -1,   263,    -1,
      38,    -1,   224,    -1,   223,    -1,   148,    -1,    44,    -1,
     261,    -1,   262,    -1,   276,    -1,   265,    -1,   253,    -1,
     287,    -1,   279,    -1,   281,    -1,   280,    -1,   285,    -1,
     257,    -1,   252,    -1,    80,    -1,   219,    -1,   256,    -1,
      53,    -1,   225,    -1,   238,    -1,   304,    -1,   232,    -1,
     205,    -1,   210,    -1,   209,    -1,   208,    -1,   207,    -1,
     206,    -1,    98,    -1,   113,    -1,   114,    -1,   188,    -1,
      47,    -1,    37,    -1,    68,    -1,    73,    -1,    60,    -1,
      55,    -1,    57,    -1,    79,    -1,    43,    -1,   149,    -1,
      52,    -1,   214,    -1,   172,    -1,   173,    -1,   170,    -1,
      71,    -1,    97,    -1,   118,    -1,   130,    -1,   131,    -1,
     108,    -1,    69,    -1,   137,    -1,   190,    -1,   102,    -1,
      96,    -1,   200,    -1,   128,    -1,   169,    -1,    94,    -1,
      51,    -1,   233,    -1,   103,    -1,   201,    -1,   119,    -1,
     161,    -1,   203,    -1,   152,    -1,   138,    -1,    77,    -1,
      78,    -1,   104,    -1,   202,    -1,   153,    -1,   184,    -1,
     198,    -1,   162,    -1,   139,    -1,   133,    -1,   168,    -1,
     150,    -1,   167,    -1,    34,    -1,    41,    -1,    59,    -1,
     115,    -1,    42,    -1,    58,    -1,   218,    -1,    50,    -1,
      62,    -1,    35,    -1,    48,    -1,   275,    -1,   251,    -1,
     284,    -1,   286,    -1,   255,    -1,   269,    -1,   282,    -1,
     274,    -1,   254,    -1,   268,    -1,   283,    -1,   273,    -1,
     267,    -1,   266,    -1,   250,    -1,   249,    -1,   258,    -1,
     259,    -1,   288,    -1,   278,    -1,   277,    -1,   272,    -1,
     270,    -1,   271,    -1,   231,    -1,   237,    -1,   234,    -1,
     228,    -1,   221,    -1,   220,    -1,   222,    -1,   239,    -1,
     229,    -1,   230,    -1,   236,    -1,   226,    -1,   235,    -1,
      67,    -1,    65,    -1,    76,    -1,   171,    -1,   204,    -1,
     244,    -1,   242,    -1,   243,    -1,   240,    -1,   241,    -1,
     246,    -1,   247,    -1,   248,    -1,    66,    -1,   297,    -1,
     295,    -1,   296,    -1,   301,    -1,   302,    -1,   303,    -1,
     298,    -1,   299,    -1,   300,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,
      88,    -1,    89,    -1,    90,    -1,    91,    -1,   289,    -1,
     290,    -1,   291,    -1,   292,    -1,   293,    -1,   294,    -1,
     305,    -1,   306,    -1,   307,    -1,   308,    -1,   309,    -1,
     310,    -1,   311,    -1,    92,    -1,   107,    -1,   116,    -1,
     174,    -1,   182,    -1,   191,    -1,   140,    -1,    93,    -1,
     117,    -1,   141,    -1,   183,    -1,   316,    -1,   317,    -1,
     318,    -1,   320,    -1,   319,    -1,   322,    -1,    26,    -1
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
     904,   906,   908,   910,   913,   917,   921,   925,   928,   930,
     935,   939,   943,   949,   954,   961,   966,   973,   979,   987,
     992,   998,  1004,  1011,  1015,  1019,  1022,  1024,  1028,  1033,
    1039,  1043,  1050,  1055,  1061,  1063,  1066,  1070,  1072,  1075,
    1077,  1084,  1088,  1092,  1095,  1099,  1101,  1105,  1108,  1113,
    1119,  1126,  1132,  1136,  1139,  1143,  1148,  1150,  1154,  1156,
    1159,  1161,  1163,  1165,  1168,  1171,  1174,  1178,  1180,  1182,
    1185,  1188,  1191,  1197,  1203,  1205,  1210,  1214,  1219,  1228,
    1230,  1233,  1237,  1240,  1244,  1253,  1255,  1258,  1262,  1271,
    1282,  1291,  1302,  1304,  1307,  1312,  1320,  1322,  1325,  1330,
    1338,  1340,  1344,  1353,  1355,  1359,  1361,  1365,  1367,  1371,
    1375,  1379,  1383,  1384,  1389,  1393,  1397,  1401,  1403,  1409,
    1411,  1415,  1416,  1418,  1420,  1424,  1426,  1430,  1434,  1436,
    1440,  1444,  1448,  1452,  1454,  1458,  1462,  1464,  1468,  1472,
    1474,  1479,  1481,  1486,  1488,  1493,  1495,  1500,  1502,  1505,
    1507,  1510,  1512,  1514,  1517,  1520,  1522,  1524,  1526,  1528,
    1532,  1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,
    1555,  1561,  1567,  1574,  1578,  1583,  1585,  1588,  1592,  1595,
    1598,  1600,  1602,  1604,  1606,  1608,  1610,  1612,  1614,  1616,
    1618,  1621,  1625,  1630,  1632,  1635,  1639,  1641,  1643,  1645,
    1647,  1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,  1665,
    1667,  1671,  1673,  1675,  1677,  1679,  1681,  1684,  1687,  1691,
    1693,  1698,  1703,  1707,  1712,  1714,  1718,  1720,  1722,  1724,
    1726,  1728,  1733,  1742,  1748,  1758,  1768,  1779,  1781,  1784,
    1786,  1789,  1796,  1797,  1799,  1803,  1807,  1808,  1810,  1812,
    1814,  1817,  1820,  1821,  1823,  1825,  1827,  1830,  1833,  1835,
    1837,  1839,  1841,  1843,  1845,  1847,  1849,  1851,  1853,  1855,
    1859,  1863,  1866,  1870,  1874,  1877,  1879,  1881,  1883,  1885,
    1887,  1889,  1891,  1896,  1900,  1908,  1912,  1920,  1925,  1930,
    1934,  1942,  1946,  1954,  1957,  1959,  1962,  1966,  1968,  1970,
    1972,  1974,  1976,  1980,  1984,  1986,  1988,  1990,  1992,  1996,
    1998,  2000,  2002,  2004,  2006,  2008,  2010,  2012,  2014,  2016,
    2018,  2020,  2024,  2028,  2033,  2038,  2042,  2046,  2050,  2054,
    2059,  2064,  2068,  2073,  2080,  2085,  2092,  2097,  2101,  2106,
    2113,  2120,  2125,  2132,  2139,  2144,  2146,  2149,  2151,  2153,
    2155,  2159,  2163,  2165,  2167,  2172,  2178,  2185,  2189,  2193,
    2197,  2201,  2207,  2215,  2223,  2229,  2235,  2241,  2249,  2257,
    2263,  2269,  2273,  2277,  2283,  2291,  2297,  2305,  2307,  2312,
    2316,  2322,  2324,  2327,  2331,  2335,  2337,  2341,  2344,  2345,
    2347,  2349,  2352,  2354,  2358,  2360,  2364,  2366,  2371,  2373,
    2376,  2380,  2381,  2383,  2384,  2386,  2391,  2394,  2398,  2400,
    2401,  2403,  2408,  2409,  2411,  2414,  2416,  2420,  2421,  2423,
    2426,  2429,  2431,  2432,  2434,  2435,  2437,  2439,  2441,  2443,
    2445,  2447,  2449,  2453,  2457,  2459,  2461,  2463,  2466,  2470,
    2472,  2474,  2476,  2478,  2480,  2482,  2484,  2486,  2489,  2492,
    2494,  2496,  2499,  2502,  2506,  2508,  2511,  2514,  2520,  2523,
    2525,  2527,  2528,  2531,  2533,  2537,  2542,  2543,  2546,  2547,
    2550,  2555,  2560,  2564,  2567,  2571,  2573,  2577,  2578,  2580,
    2582,  2585,  2588,  2591,  2594,  2596,  2599,  2602,  2605,  2608,
    2612,  2615,  2619,  2623,  2628,  2631,  2634,  2636,  2638,  2642,
    2645,  2649,  2652,  2656,  2659,  2663,  2667,  2671,  2677,  2683,
    2689,  2698,  2704,  2708,  2714,  2722,  2724,  2726,  2728,  2730,
    2734,  2738,  2740,  2742,  2744,  2746,  2748,  2750,  2752,  2754,
    2756,  2758,  2760,  2762,  2764,  2766,  2768,  2770,  2772,  2774,
    2776,  2778,  2780,  2782,  2784,  2786,  2788,  2790,  2792,  2794,
    2796,  2798,  2800,  2802,  2804,  2806,  2808,  2810,  2812,  2814,
    2816,  2818,  2820,  2822,  2824,  2826,  2828,  2830,  2832,  2834,
    2836,  2838,  2840,  2842,  2844,  2846,  2848,  2850,  2852,  2854,
    2856,  2858,  2860,  2862,  2864,  2866,  2868,  2870,  2872,  2874,
    2876,  2878,  2880,  2882,  2884,  2886,  2888,  2890,  2892,  2894,
    2896,  2898,  2900,  2902,  2904,  2906,  2908,  2910,  2912,  2914,
    2916,  2918,  2920,  2922,  2924,  2926,  2928,  2930,  2932,  2934,
    2936,  2938,  2940,  2942,  2944,  2946,  2948,  2950,  2952,  2954,
    2956,  2958,  2960,  2962,  2964,  2966,  2968,  2970,  2972,  2974,
    2976,  2978,  2980,  2982,  2984,  2986,  2988,  2990,  2992,  2994,
    2996,  2998,  3000,  3002,  3004,  3006,  3008,  3010,  3012,  3014,
    3016,  3018,  3020,  3022,  3024,  3026,  3028,  3030,  3032,  3034,
    3036,  3038,  3040,  3042,  3044,  3046,  3048,  3050,  3052,  3054,
    3056,  3058,  3060,  3062,  3064,  3066,  3068,  3070,  3072,  3074,
    3076,  3078,  3080,  3082,  3084,  3086,  3088,  3090,  3092,  3094,
    3096,  3098,  3100,  3102,  3104,  3106,  3108,  3110,  3112,  3114,
    3116,  3118,  3120,  3122,  3124,  3126,  3128,  3130,  3132,  3134,
    3136,  3138,  3140,  3142,  3144,  3146,  3148,  3150,  3152,  3154,
    3156,  3158,  3160,  3162,  3164,  3166,  3168,  3170,  3172,  3174,
    3176,  3178,  3180,  3182,  3184,  3186,  3188
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
    2685,  2686,  2691,  2698,  2708,  2713,  2719,  2728,  2738,  2745,
    2753,  2765,  2775,  2785,  2795,  2805,  2815,  2825,  2835,  2846,
    2855,  2865,  2875,  2891,  2900,  2909,  2917,  2923,  2935,  2943,
    2953,  2961,  2973,  2979,  2990,  2992,  2996,  3004,  3008,  3013,
    3017,  3021,  3025,  3035,  3043,  3050,  3056,  3066,  3070,  3074,
    3082,  3090,  3098,  3110,  3118,  3124,  3134,  3140,  3150,  3154,
    3164,  3170,  3176,  3182,  3191,  3200,  3209,  3222,  3226,  3234,
    3240,  3250,  3258,  3267,  3280,  3287,  3299,  3303,  3315,  3322,
    3328,  3337,  3344,  3350,  3361,  3368,  3374,  3383,  3392,  3399,
    3410,  3417,  3429,  3435,  3447,  3453,  3464,  3470,  3481,  3487,
    3498,  3504,  3515,  3524,  3528,  3537,  3541,  3549,  3553,  3563,
    3570,  3579,  3589,  3588,  3602,  3611,  3620,  3633,  3637,  3649,
    3653,  3661,  3664,  3671,  3675,  3684,  3688,  3692,  3700,  3704,
    3710,  3716,  3722,  3732,  3736,  3740,  3748,  3752,  3758,  3768,
    3772,  3782,  3786,  3796,  3800,  3810,  3814,  3824,  3828,  3837,
    3841,  3849,  3853,  3857,  3861,  3871,  3875,  3879,  3886,  3891,
    3899,  3903,  3907,  3911,  3915,  3919,  3927,  3931,  3935,  3943,
    3947,  3951,  3955,  3966,  3972,  3982,  3988,  3998,  4002,  4006,
    4069,  4091,  4119,  4283,  4287,  4297,  4301,  4305,  4309,  4318,
    4322,  4326,  4330,  4338,  4344,  4354,  4362,  4366,  4370,  4374,
    4378,  4382,  4386,  4390,  4394,  4398,  4403,  4407,  4411,  4415,
    4419,  4430,  4434,  4442,  4449,  4456,  4467,  4475,  4479,  4487,
    4495,  4503,  4557,  4561,  4571,  4577,  4587,  4591,  4599,  4603,
    4607,  4615,  4623,  4640,  4648,  4665,  4684,  4708,  4714,  4725,
    4731,  4742,  4751,  4753,  4757,  4762,  4772,  4775,  4782,  4788,
    4794,  4801,  4813,  4816,  4823,  4829,  4835,  4842,  4853,  4857,
    4865,  4869,  4877,  4881,  4885,  4890,  4899,  4903,  4907,  4911,
    4919,  4924,  4932,  4937,  4945,  4953,  4958,  4963,  4968,  4973,
    4978,  4983,  4989,  4997,  5001,  5018,  5022,  5030,  5038,  5046,
    5050,  5058,  5062,  5070,  5078,  5082,  5086,  5121,  5127,  5133,
    5143,  5147,  5151,  5155,  5159,  5163,  5167,  5174,  5180,  5190,
    5198,  5206,  5210,  5214,  5218,  5222,  5226,  5230,  5234,  5238,
    5242,  5250,  5258,  5262,  5266,  5274,  5281,  5289,  5297,  5301,
    5305,  5313,  5317,  5323,  5329,  5333,  5343,  5351,  5355,  5361,
    5370,  5379,  5385,  5391,  5401,  5418,  5425,  5440,  5476,  5480,
    5488,  5496,  5508,  5512,  5520,  5528,  5532,  5543,  5560,  5566,
    5572,  5582,  5586,  5592,  5598,  5602,  5608,  5612,  5618,  5624,
    5631,  5641,  5646,  5654,  5660,  5670,  5692,  5701,  5707,  5720,
    5734,  5741,  5747,  5757,  5766,  5774,  5780,  5798,  5806,  5810,
    5817,  5822,  5830,  5834,  5841,  5845,  5852,  5856,  5863,  5867,
    5876,  5889,  5892,  5900,  5903,  5911,  5919,  5927,  5931,  5939,
    5942,  5950,  5962,  5965,  5973,  5985,  5991,  6001,  6004,  6012,
    6016,  6020,  6028,  6031,  6039,  6042,  6050,  6054,  6058,  6062,
    6066,  6074,  6082,  6094,  6106,  6110,  6114,  6122,  6128,  6138,
    6142,  6146,  6150,  6154,  6158,  6162,  6166,  6174,  6178,  6182,
    6186,  6194,  6200,  6210,  6220,  6224,  6232,  6242,  6253,  6260,
    6264,  6272,  6275,  6282,  6287,  6296,  6306,  6309,  6316,  6320,
    6328,  6337,  6344,  6354,  6358,  6365,  6371,  6381,  6384,  6391,
    6396,  6408,  6416,  6428,  6436,  6440,  6448,  6452,  6456,  6464,
    6472,  6476,  6480,  6484,  6492,  6500,  6512,  6516,  6524,  6538,
    6542,  6549,  6554,  6562,  6567,  6576,  6584,  6590,  6600,  6606,
    6616,  6623,  6630,  6655,  6683,  6711,  6715,  6719,  6727,  6734,
    6741,  6753,  6757,  6758,  6771,  6772,  6773,  6774,  6775,  6776,
    6777,  6778,  6779,  6780,  6781,  6782,  6783,  6784,  6785,  6786,
    6787,  6791,  6792,  6793,  6794,  6795,  6796,  6797,  6798,  6799,
    6800,  6801,  6802,  6803,  6804,  6805,  6806,  6807,  6808,  6809,
    6810,  6811,  6812,  6813,  6814,  6815,  6816,  6817,  6818,  6819,
    6820,  6821,  6822,  6823,  6824,  6825,  6826,  6827,  6828,  6829,
    6830,  6831,  6832,  6833,  6834,  6835,  6836,  6837,  6838,  6839,
    6840,  6841,  6842,  6843,  6844,  6845,  6846,  6847,  6848,  6849,
    6850,  6851,  6852,  6853,  6854,  6855,  6856,  6857,  6858,  6859,
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
    6990,  6991,  6992,  6994,  6995,  6996,  7001
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
  const int jsoniq_parser::yylast_ = 15469;
  const int jsoniq_parser::yynnts_ = 318;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 544;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 336;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 590;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17067 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7005 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/jsoniq_parser.y"


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

