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
#line 88 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"


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
#line 69 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1039 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 99 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 185 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 906 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 905 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 567: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 618: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 619: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 622: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 648: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2774 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 649: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2783 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2792 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2801 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2810 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 659: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2819 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 660: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2828 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 661: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2837 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
#line 133 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2934 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1057 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1061 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1065 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1079 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1083 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1092 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1098 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1106 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1112 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1123 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1128 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1143 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1150 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1159 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1166 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1174 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1182 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1190 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1201 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1206 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1213 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1220 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1232 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1242 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1249 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1256 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1291 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1296 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1304 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1312 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1320 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1333 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1338 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1346 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1351 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1359 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1364 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1369 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1374 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1387 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1402 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1410 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1418 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1429 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1436 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1447 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1452 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1460 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1467 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1474 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1483 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1496 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1504 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1511 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1521 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1528 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1535 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1558 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1564 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1573 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1580 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1590 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1599 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1601 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1602 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1605 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1606 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1607 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1608 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1622 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1638 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1645 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1653 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1660 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1665 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1673 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1681 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1695 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1709 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1726 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1731 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1739 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1747 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1758 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1763 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1772 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1777 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1784 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1789 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1799 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1804 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1813 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1819 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1832 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1837 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1845 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1856 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1871 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1883 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1898 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1903 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1921 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1944 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1954 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1963 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1972 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1981 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 1993 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1997 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2003 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2007 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2017 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2027 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2040 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2055 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2060 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2067 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2074 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2086 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2096 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2106 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2117 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2133 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2153 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2157 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2161 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2173 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2177 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2185 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2190 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2202 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2209 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2219 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2251 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2256 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2264 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2281 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2289 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2297 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2304 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2311 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2322 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2331 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2340 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2349 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2362 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2370 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2378 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2386 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2401 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2406 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2414 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2428 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2445 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2470 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2478 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2485 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2496 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2506 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2511 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2524 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2571 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2585 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2593 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2598 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2606 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2611 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2616 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2624 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2633 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2645 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2655 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2668 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2692 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2699 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2709 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2715 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2724 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2734 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2741 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2749 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2761 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2771 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2781 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2791 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2801 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2811 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2821 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2831 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2842 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2851 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2861 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2871 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2887 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2896 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2905 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2919 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2949 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2957 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 2969 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2975 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2992 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 3000 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3004 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3013 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3017 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3021 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3031 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3039 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3052 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3062 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3066 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3070 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3078 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3086 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3094 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3106 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3114 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3120 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3130 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3136 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3146 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3150 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3160 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3166 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3172 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3178 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3187 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3196 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3205 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3218 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3222 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3230 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3236 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3246 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3254 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3263 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3276 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3283 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3295 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3299 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3311 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3318 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3324 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3333 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3340 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3346 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3357 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3364 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3370 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3379 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3388 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3395 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3406 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3425 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3431 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3443 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3449 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3460 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3466 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3477 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3483 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3494 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3500 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3511 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3520 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3524 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3533 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3537 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3549 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3559 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3566 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3575 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3584 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3589 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3598 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3607 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3616 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3629 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3633 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 3645 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3649 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3656 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3660 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3667 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3671 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3680 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3684 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3688 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3696 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3700 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3706 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3712 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3718 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3728 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3732 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3736 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3744 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3748 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3754 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3764 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3768 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3778 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3792 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3796 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3806 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3810 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3820 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3824 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3833 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3837 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3845 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3849 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3853 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3857 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3867 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3871 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3875 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3882 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3895 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3899 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3903 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3911 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3927 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3947 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3962 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3968 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3978 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3984 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3994 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3998 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4002 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4040 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4044 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4054 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4064 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4077 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4086 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4096 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4100 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4109 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4114 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4123 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4129 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4137 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4143 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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
#line 4155 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4161 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4171 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4175 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4179 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4183 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4187 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4193 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4199 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4207 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4211 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4219 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4223 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4234 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4238 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4242 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4248 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4252 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4266 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4270 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4278 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4282 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4292 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4296 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4300 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4304 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4313 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4317 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4321 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4325 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4333 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4339 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4349 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4357 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4361 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4365 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4369 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4373 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4377 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4381 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4385 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4389 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4393 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4398 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4402 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4406 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4410 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4418 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4422 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4430 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4437 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4444 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4455 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4463 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4467 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4475 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4483 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4491 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4545 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4549 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FunctionCall(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                            dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4559 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4565 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4575 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4579 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4587 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4591 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4595 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4603 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4611 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 512:

/* Line 690 of lalr1.cc  */
#line 4628 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4636 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 514:

/* Line 690 of lalr1.cc  */
#line 4655 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 515:

/* Line 690 of lalr1.cc  */
#line 4674 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 516:

/* Line 690 of lalr1.cc  */
#line 4696 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4702 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4713 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4719 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4730 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4745 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4750 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4759 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4763 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4770 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4776 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4782 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4789 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4800 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4804 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4811 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4817 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4823 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4830 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4841 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4845 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4853 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4857 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4865 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4869 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4873 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4878 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4887 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4891 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4895 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4899 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4912 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4925 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4941 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4946 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4956 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4961 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4966 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4977 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4985 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4989 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5006 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5010 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5018 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5026 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5034 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5038 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5050 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5058 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5066 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5070 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5074 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5109 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5115 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5121 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5131 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5135 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5139 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5143 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5147 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5151 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5155 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5162 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5168 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5178 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5186 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5194 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5198 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5202 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5206 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5210 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5214 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5218 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5222 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5226 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5230 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5238 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5246 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5250 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5254 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5262 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5269 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5277 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5285 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5289 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5293 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5301 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5305 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5311 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5317 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5321 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5331 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5339 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5343 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5349 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5358 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5367 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5373 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5379 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5389 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5406 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5413 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5428 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5464 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5468 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5476 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5484 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5496 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5500 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5508 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5516 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5520 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5531 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5548 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5554 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5560 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5570 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5574 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5580 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5586 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5590 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5596 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5600 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5606 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5612 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5619 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5629 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5634 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5642 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5648 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5658 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5680 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5689 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5695 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5708 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5722 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5729 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5735 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5745 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5754 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5762 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5768 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5798 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5805 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5810 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5818 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5822 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5829 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5833 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5840 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5844 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5855 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5864 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5876 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5880 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5891 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5899 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5919 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5949 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5953 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5961 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5973 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5979 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5988 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5992 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6000 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6004 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6008 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6015 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6019 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6026 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6030 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6038 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6042 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6046 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6050 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6054 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6062 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6070 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6082 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6094 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6098 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6102 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6110 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6116 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6126 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6130 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6134 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6138 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6142 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6146 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6150 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6154 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6162 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6166 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6170 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6174 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6182 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6188 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6198 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6208 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6212 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6220 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 736:

/* Line 690 of lalr1.cc  */
#line 6230 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 737:

/* Line 690 of lalr1.cc  */
#line 6241 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6248 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6252 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6259 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6263 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6270 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6275 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6284 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6293 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6297 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6304 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6308 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6316 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6325 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6332 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6342 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6346 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6353 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6359 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6368 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6372 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6379 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6384 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6396 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6404 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6416 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6424 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6428 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6436 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6440 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6444 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6452 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6460 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6464 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6468 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6472 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6480 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6488 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6500 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6504 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6512 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6526 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6530 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6537 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6542 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6550 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6555 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6564 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6572 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6578 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6588 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 788:

/* Line 690 of lalr1.cc  */
#line 6594 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 789:

/* Line 690 of lalr1.cc  */
#line 6604 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6611 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6618 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 792:

/* Line 690 of lalr1.cc  */
#line 6643 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 793:

/* Line 690 of lalr1.cc  */
#line 6671 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 794:

/* Line 690 of lalr1.cc  */
#line 6699 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6703 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6707 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6714 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6721 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6728 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6745 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
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

  case 804:

/* Line 690 of lalr1.cc  */
#line 6758 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6759 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6760 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6761 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6762 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6763 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6764 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6765 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6766 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6767 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6768 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6769 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6770 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6771 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6772 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6773 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6778 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6779 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6780 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6781 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6782 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6783 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6784 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6785 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6786 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6787 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6788 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6789 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6790 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6791 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6792 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6793 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6794 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6795 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6796 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6797 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6798 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6799 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6800 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6801 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6802 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6803 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6804 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6805 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6807 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6808 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6809 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6810 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6811 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6812 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6813 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6814 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6815 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6816 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6817 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6818 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6819 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6820 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6821 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6822 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6823 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6824 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6825 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6826 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6827 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6828 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6829 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6830 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6831 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6832 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6833 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6834 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6835 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6836 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6837 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6840 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6841 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6842 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6843 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6844 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6845 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6847 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6848 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6849 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6850 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6851 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6852 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6853 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6854 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6855 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6857 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6858 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6859 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6860 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6861 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1021:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1022:

/* Line 690 of lalr1.cc  */
#line 6979 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1023:

/* Line 690 of lalr1.cc  */
#line 6980 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1024:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1025:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1026:

/* Line 690 of lalr1.cc  */
#line 6987 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12318 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1495;
  const short int
  xquery_parser::yypact_[] =
  {
      4805, -1495, -1495, -1495,  6369,  6369,  6369,  6369, -1495, -1495,
     -11,    28, -1495,    81,    43, -1495, -1495, -1495,   833, -1495,
   -1495, -1495,   278,   517,   844,  4523,   527,   588,   156, -1495,
      55, -1495,   662, -1495, -1495, -1495, -1495, -1495,   849, -1495,
     716,   731, -1495, -1495, -1495, -1495,   377, -1495,   858, -1495,
     752,   822, -1495,   347, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   400,   590,
   -1495, -1495, -1495, -1495,   733, 12297, -1495, -1495, -1495,   660,
   -1495, -1495, -1495,   762, -1495,   879,   885, -1495, -1495, 16702,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   903, -1495,
   -1495,   891,   909, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
    5433,  8241,  8553, 16702, -1495, -1495,   881, -1495, -1495, -1495,
   -1495,   884, -1495, -1495,   927, 13196, -1495, 13501,   931,   941,
   -1495, -1495, -1495,   943, -1495, 11673, -1495, -1495, -1495, -1495,
   -1495, -1495,   913, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495,    63,   852, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495,   -81,   911,   280, -1495,   -92,   185, -1495, -1495, -1495,
   -1495, -1495, -1495,   952, -1495,   830,   831,   834, -1495, -1495,
     917,   922, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,  8865,  9177, -1495,   763, -1495,
   -1495, -1495, -1495, -1495,  5119,  6681,  1080, -1495,  6993, -1495,
   -1495,   818,    83, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495,    88, -1495, -1495,
   -1495, -1495, -1495, -1495,   526, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495,  6369, -1495, -1495, -1495, -1495,    17, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495,   173, -1495,   889,
   -1495, -1495, -1495,   554, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495,   914,   988, -1495,   895,   836,   984,   705,   561,
     409,   643, -1495,  1037,   887,   987,   990, 10425, -1495,   904,
   -1495, -1495,    34, -1495, -1495, 11985, -1495,   824, -1495,   936,
   12297, -1495,   936, 12297, -1495, -1495, -1495,   464, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495,   948,   940, -1495, -1495, -1495, -1495, -1495,   920, -1495,
    6369,   921,   925,   928,  6369,   497,   497,  1078,   746,   753,
     703, 16991, 16702,    -5,  1064, 16702,   959,   995,   471, 13196,
     797,   868, 16702, 16702,   812,   263,    58, -1495, -1495, -1495,
   13196,  6369,   930,  6369,    52, 10737, 14390, 16702, -1495,   837,
     839, 16702,   997,   289,   969, 10737,  1125,    85,   364, 16702,
    1007,   985,  1019, -1495,   945, 10737, 12898, 16702, 16702, 16702,
    6369,   946, 10737, 10737, 16702,  6369,   975,   977, -1495, -1495,
   -1495, 10737, 14679,   978, -1495,   979, -1495, -1495, -1495, -1495,
     981, -1495,   983, -1495, -1495, -1495, -1495, -1495,   989, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, 16702, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495,   998, 16702, -1495, -1495, -1495,   960,  5745,  1025,
     460,   991,   993,   994, 16702,  6369, -1495,   999,   127, -1495,
     612, -1495,   101,  1117, 10737, 10737, -1495, -1495,   180, -1495,
   -1495, -1495,  1138, -1495, -1495, -1495, -1495, 10737,   955, -1495,
    1126, 10737, 10737, 13803,   968, 10737, 10737, 10737, 10737, 13803,
   10737,   939,   942, 16702,   986,   992, 10737, 10737,  5433,   932,
   -1495,    54, -1495,    50, 10737,  6681, -1495, -1495, -1495, -1495,
   -1495,    81,   156,    94,    99,  1170,  7305,  3253,  7617,  3576,
     762, -1495, -1495,   197,   762, -1495, 10737,  4200, -1495,  1055,
     761,    55,  1010,  1005,  1009,  6369, 10737, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, 11049, 11049, 11049, -1495, 11049,
   11049, -1495, 11049, -1495, 11049, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, 11049, 11049,  1110, 11049, 11049, 11049, 11049, 11049,
   11049, 11049, 11049, 11049, 11049, 11049, 11049,   950,  1089,  1090,
    1091, -1495, -1495, -1495, 11361,  9489, -1495, -1495, 11673, 11673,
   10737,   936, -1495, -1495,   936, -1495,  9801,   936,  1038, 10113,
   -1495, -1495, -1495, -1495,    59, -1495,   307, -1495, -1495, -1495,
   -1495, -1495, -1495,  1085,  1086,   527,  1158, -1495, -1495, 16991,
    1079,   617, 16702,  1034,  1035,  1079,  1078,  1069,  1065, -1495,
   -1495, -1495,   408,   953,  1104,   901, 16702,  1059, 10737,  1084,
   16702, 16702, -1495,  1071,  1020, -1495,  1021,   979,   731, -1495,
    1022,  1023,   255, -1495,   339,   340,  1099, -1495,    53, -1495,
   -1495,  1099, 16702,    42, 16702,  1113,   354, -1495,  6369, -1495,
     106, -1495, 13196,  1112,  1167, 13196,  1078,  1116,   619, 16702,
   10737,    55, -1495,   268,  1026, -1495,  1027,  1028,  1029,    21,
   -1495,   326,  1033, -1495,   123,   136,  1066, -1495,  1036,  6369,
    6369,   287, -1495,   383,   397,   639, 10737,   270, -1495, -1495,
   10737, 10737, -1495, 10737, 10737, 10737, -1495, 10737, -1495, 10737,
   -1495, 16702,  1117, -1495,    38,   319,   336, -1495, -1495, -1495,
     337, -1495,    47, -1495, -1495,  1068,  1070,  1072,  1074,  1075,
     464,   948, -1495,   341,   343,    -2,   116,  1124,   585,   996,
    1004,  1000,   164, -1495,  1082, -1495, -1495,  1032,   143,  5745,
     353, 12600,   932, -1495, -1495, -1495,  1001, -1495,   818,   788,
    1198,   769, -1495, -1495,   100, -1495, -1495, -1495,   110, -1495,
      69, -1495, -1495, -1495, -1495, -1495,  3888, -1495, -1495, -1495,
   16702,  1062, 10737,  1119, -1495, -1495, -1495,   988, -1495, -1495,
   -1495, -1495, -1495, 11049, -1495, -1495, -1495,    95, -1495,   561,
     561,   439,   409,   409,   409,   409,   643,   643, -1495, -1495,
   15835, 15835, 16702, 16702, -1495, -1495,   359, -1495, -1495,   304,
   -1495, -1495, -1495,   402, -1495, -1495,   465,   497, -1495, -1495,
     544,   706,   784, -1495,   527, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,  1079, -1495,  1103, 16124,  1096,
   10737, -1495, -1495, -1495,  1145,  1078,  1078,  1079, -1495,   897,
    1078,   697, 16702,   699,   708,  1213, -1495, -1495,   956,   562,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495,   408,   115,  1016,   631, 10737, -1495, 16702,  1151,   947,
    1078, -1495, -1495, -1495, -1495,  1094, 16702, -1495, 16702, -1495,
   16413,  1121, 15835,  1131, 10737,   177,  1106,    44,   609,  1002,
   -1495, -1495,   668,    42,  1145, 15835,  1132,  1157,  1073,  1056,
    1123,  1078,  1098,  1128,  1165,  1078, 10737,   -13, -1495, -1495,
   -1495,  1109, -1495, -1495, -1495, -1495,  1146, 10737, 10737,  1120,
   -1495,  1163,  1166,  6369, -1495,  1087,  1093,  1115, 16702, -1495,
   16702, -1495, 10737,  1133,  1083, 10737, -1495,  1149,   163,   225,
     241,  1245, -1495,   448, -1495,   739,  1129, -1495, -1495,  1253,
   -1495,   556, 10737, 10737, 10737,   738, 10737, 10737, 10737, 10737,
   10737, 10737, 10737, 10737, 10737, 13803,  1168, 10737, 10737, -1495,
    7929,   135,  1039, -1495,   238, -1495, 10737,   112,   181,    69,
    7617,  3576,  7617,  1208, -1495, -1495, 10737,   804,  1182, -1495,
   16702,  1183, -1495, -1495, 10737,    95,   614,   244, -1495,  1011,
     379,  1040,  1041, -1495, -1495,   868, -1495,  1030,   525,  1136,
    1144, 16124,  1147,  1152,  1153,  1155,  1156, -1495,   659, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495,  1150, -1495, -1495, -1495, -1495, 10737, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495,   792, -1495,  1277,
     850, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
    1031, -1495, -1495,  1279, -1495, -1495, -1495, -1495, -1495,   704,
    1285, -1495,   811, -1495, -1495, -1495,   978,   517,   662,   981,
     716,   983,   989,   911,  1152,  1153,  1155, -1495,   659,   659,
   11361,  1044,  1008, -1495,  1145,   115,  1088,  1130,  6369,  1134,
    1137,  1175,  1140,  1154, 16702, -1495,   559, -1495, 16702, -1495,
   10737,  1176, 10737,  1205, 10737,   220,  1186, 10737,  1187, -1495,
    1218,  1220, 10737, 16702,   926,  1262, -1495, -1495, -1495, -1495,
   -1495, -1495, 15835, -1495,  6369,  1078,  1233, -1495, -1495, -1495,
    1078,  1233, -1495, 10737,  1200,  6369, 16702, -1495, -1495, 10737,
   10737,    75, -1495,    39,   418, -1495, 14968,   847, -1495,   851,
   -1495,  1159, -1495, -1495,  6369,  1161,  1162, -1495, 10737, -1495,
   -1495, 10737,  1148,  1163,  1244, -1495,  1219, -1495,   745, -1495,
   -1495,  1345, -1495, -1495,  6369, 16702, -1495,   770, -1495, -1495,
   -1495,  6369,  1164,  1127,  1135, -1495, -1495, -1495,  1139,  1142,
   -1495, -1495, -1495,  1257, -1495, -1495, -1495, -1495,  1122,   282,
   16702,  1171, -1495,  1202,  1209,  1215,  1203, -1495,   889,   626,
   12600,  1039, -1495,  6057, 12600, -1495, -1495,  1198,   486, -1495,
   -1495, -1495,  1182, -1495,  1078, -1495,   900, -1495,   474,  1258,
   -1495, 10737,   663,  1119,   360,  1189, -1495,    95,  1143, -1495,
   -1495,   165, -1495,   678,   133,  1160,    95,   678, 11049, -1495,
      67, -1495, -1495, -1495, -1495, -1495, -1495,    95,  1226,  1097,
     953,   133, -1495, -1495,  1095,  1302, -1495, -1495, -1495, 14101,
    1195,  1196,  1199,  1207,  1210,  1211,  1212, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,  1359,
     455,  1361,   455,  1169,  1283, -1495, -1495,  1225, 16702,  1172,
   -1495, -1495, 11361, -1495,  1216, -1495, -1495, -1495, -1495, -1495,
   -1495, 10737,  1254, -1495, -1495, 10737, -1495,   602, -1495, 10737,
    1255, 10737, -1495, 10737, 16702, 16702, -1495,   652, -1495, 10737,
   -1495,  1280,  1281,  1307,  1078,  1233, -1495, 10737,  1221, -1495,
   -1495, -1495,  1222, -1495,   279, 10737,  6369,  1229,   324, -1495,
   16702,   579, -1495, 15257,   436, -1495, 15546,  1230, -1495, -1495,
    1234, -1495, -1495, -1495, -1495, 10737,   854,  1245, 16702,   838,
   -1495,  1236,  1245, 16702, -1495,  1237, -1495, 10737, 10737, 10737,
   10737,  1101, 10737, 10737, -1495, 10737, 10737, 10737, 10737,  7929,
     459, -1495, -1495, -1495, -1495, -1495,  1258, -1495, -1495, -1495,
    1078, 10737, -1495,  1282, -1495, -1495, -1495, -1495,  1238, 11049,
   -1495, -1495, -1495, -1495, -1495,    61, 11049, 11049,   657, -1495,
    1040, -1495,   312, -1495,  1041,    95,  1270, -1495, -1495,  1173,
   -1495, -1495, -1495, -1495,  1331,  1239, -1495,   478, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495,   477,   477, -1495,   455,
   -1495, -1495,   483, -1495,  1400,   133,  1334,  1246, 11361,   -15,
    1174,  1261, -1495, -1495, 10737, -1495, 10737,  1288, -1495, 10737,
   -1495, -1495, -1495,  1379, -1495, -1495,  7929, 10737,  1078, -1495,
   -1495, -1495, 10737, 10737, -1495, -1495, -1495,  7929,  7929,  1342,
    6369, 15835, 16702,   616, 16702, 10737, 16702,   627,  7929, -1495,
     475,   285,  1245, 16702, -1495,  1240,  1245, -1495, -1495, -1495,
   -1495, -1495, 10737, -1495, -1495, -1495,   267,   309,   310, 10737,
   -1495, -1495, -1495,  1332, 10737, -1495,   409, 11049, 11049,   439,
     707, -1495, -1495, -1495, -1495, -1495, -1495, 10737, -1495, 15835,
   -1495, 15835,  1350, -1495, -1495, -1495,  1411, -1495, -1495, -1495,
    1184,  1340, -1495, -1495,  1343, -1495,   842, 16702,  1333,  1227,
   16702, 11361, -1495, -1495, 10737, -1495,  1336, -1495, -1495,  1233,
   -1495, -1495, 15835, -1495, -1495, -1495,  1363, 10737,  1269, -1495,
    1364,  7929, -1495, 16702,   422,   724, -1495,  1263,  1245, -1495,
    1265, -1495,  1266,  1163,  1166,   362, -1495,  1332,   439,   439,
   11049,   374, -1495, -1495, 15835, -1495, -1495,  1334, 11361, -1495,
    1258,  1177, 16702,  1341,  1241,  1343, -1495, 16702,   642, 15835,
    6369, 15835,  1284, -1495, -1495,  1370,   681, -1495, -1495, -1495,
   -1495,  1286,   832, -1495, -1495, -1495,  1268, -1495,  7929,   856,
   -1495, -1495,   439, -1495, -1495, -1495, -1495, -1495, 10737,  1178,
   16702,  1349, -1495,  6369,   690, -1495, -1495,   715, 10737, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495,  1353, -1495,  1179,  1180,
   16702, -1495, -1495, 10737,  7929, 16702,  1181, 10737,  1185,  1289,
   11361, -1495, 11361,  7929, -1495,  1275,  1190, 16702,  1243,  1358,
   16702,  1191, 11361, -1495
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   466,   467,   468,   168,   168,   168,     0,   821,  1026,
     120,   122,   626,   913,   922,   862,   826,   824,   805,   914,
     917,   869,   830,   806,   808,     0,   923,   810,   920,   891,
     871,   846,   807,   866,   867,   918,   915,   865,   812,   921,
     813,   814,   962,   974,   961,   863,   882,   876,   815,   864,
     817,   816,   963,   900,   901,   868,   843,   984,   985,   986,
     987,   988,   989,   990,   991,   992,   993,   994,  1008,  1015,
     890,   886,   877,   857,   804,     0,   885,   893,   902,  1009,
     881,   492,   858,   859,   916,  1010,  1016,   878,   895,     0,
     498,   455,   494,   888,   823,   879,   880,   909,   883,   899,
     908,  1014,  1017,   829,   870,   911,   493,   898,   904,   809,
       0,     0,     0,     0,   401,   896,   907,   912,   910,   889,
     875,   964,   873,   874,  1011,     0,   400,     0,  1012,  1018,
     905,   860,   884,  1013,   433,     0,   465,   906,   887,   894,
     903,   897,   965,   851,   856,   855,   854,   853,   852,   818,
     872,     0,   822,   919,   844,   953,   952,   954,   828,   827,
     847,   959,   811,   951,   956,   957,   948,   850,   892,   950,
     960,   958,   949,   848,   955,   969,   970,   967,   968,   966,
     819,   971,   972,   973,   939,   938,   925,   842,   835,   932,
     928,   845,   841,   940,   941,   831,   832,   825,   834,   937,
     936,   933,   929,   946,   947,   945,   935,   931,   924,   833,
     944,   943,   837,   839,   838,   930,   934,   926,   840,   927,
     836,   942,   995,   996,   997,   998,   999,  1000,   976,   977,
     975,   981,   982,   983,   978,   979,   980,   849,  1001,  1002,
    1003,  1004,  1005,  1006,  1007,     0,     0,  1019,  1020,  1021,
    1024,  1023,  1022,  1025,   165,   165,     0,     2,   165,     9,
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
     490,   477,   478,   479,   482,   483,   480,   481,   505,   507,
     508,   509,   506,   554,   555,   556,   557,   558,   559,   560,
     461,   599,   590,   598,   597,   596,   595,   592,   594,   591,
     593,   491,   484,   627,   628,    43,   222,   223,   225,   224,
     226,   218,   487,   488,   489,   486,   228,   231,   227,   229,
     230,   463,   803,   820,   913,   922,   920,   822,     0,   166,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   128,   129,
       0,     0,     0,     0,     0,     0,     0,     0,   256,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   274,   275,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   457,   460,
     447,     0,     0,   805,   830,   808,   861,   923,   810,   871,
     812,   882,   815,   817,   816,   900,  1008,  1015,   804,  1009,
     859,  1010,  1016,   883,  1014,  1017,   907,   964,  1011,  1012,
    1018,  1013,   965,   959,   951,   957,   948,   848,   969,   970,
     967,   819,   971,  1020,   453,   463,   803,   445,     0,   192,
     446,   449,   805,   806,   808,   807,   812,   813,   814,   815,
     804,   811,   495,     0,   451,   450,   187,     0,     0,   211,
       0,   810,   817,   816,     0,   168,   778,   971,     0,   219,
       0,   496,     0,   521,     0,     0,   456,   801,     0,   802,
     427,   428,     0,   459,   458,   448,   431,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     780,     0,   782,     0,     0,   165,     3,     4,     1,    10,
      12,     0,     0,     0,     0,     6,   165,     0,   165,     0,
       0,   119,   172,     0,     0,   190,     0,     0,   199,     0,
       0,     0,     0,     0,     0,     0,     0,   204,   232,   251,
     247,   253,   248,   250,   249,     0,     0,     0,   417,     0,
       0,   415,     0,   361,     0,   416,   409,   414,   413,   412,
     411,   410,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   403,   402,   399,     0,     0,   425,   430,     0,     0,
       0,   440,   473,   443,   442,   454,     0,   470,     0,     0,
     562,   564,   568,   570,     0,   124,     0,   800,    47,    44,
      45,    48,    49,     0,     0,     0,     0,    50,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   637,
     638,   639,     0,   103,   142,     0,     0,   112,     0,     0,
       0,     0,   127,     0,     0,   606,     0,     0,     0,   601,
       0,     0,     0,   616,     0,     0,   255,   257,     0,   234,
     235,   254,     0,     0,     0,   134,     0,   138,   168,   630,
       0,    60,     0,    69,     0,     0,     0,    61,     0,     0,
       0,     0,   604,     0,     0,   607,     0,     0,     0,     0,
     323,     0,     0,   605,     0,     0,     0,   624,     0,     0,
       0,     0,   610,     0,     0,   194,     0,     0,   188,   186,
       0,     0,   784,     0,     0,     0,   495,     0,   779,     0,
     497,   522,   521,   518,     0,     0,     0,   552,   551,   426,
       0,   549,     0,   650,   651,   805,   808,   812,   815,   804,
     791,     0,   600,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   656,     0,   202,   203,     0,     0,     0,
       0,     0,   207,   208,   781,   783,     0,     5,    24,     0,
      25,     0,     7,    29,     0,    15,     8,    30,     0,    19,
     913,    77,    16,    78,    20,   193,     0,   191,   212,   213,
       0,     0,     0,     0,   205,   233,   292,   353,   355,   359,
     365,   364,   363,     0,   360,   357,   358,     0,   369,   376,
     375,   373,   379,   380,   381,   378,   383,   384,   387,   386,
       0,     0,     0,     0,   408,   422,     0,   435,   436,     0,
     474,   471,   503,     0,   629,   501,     0,     0,   121,   123,
       0,     0,     0,   102,     0,    92,    94,    95,    96,    97,
      99,   100,   101,    93,    98,    88,    89,     0,     0,   108,
       0,   104,   106,   107,   114,     0,     0,    87,    46,     0,
       0,     0,     0,     0,     0,     0,   728,   733,     0,     0,
     729,   763,   716,   718,   719,   720,   722,   724,   723,   721,
     725,     0,     0,     0,     0,     0,   111,     0,   144,     0,
       0,   567,   561,   602,   603,     0,     0,   620,     0,   617,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   237,     0,   242,   140,     0,     0,   135,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,   273,   279,
     276,     0,   609,   608,   615,   623,     0,     0,     0,     0,
     566,     0,     0,     0,   418,     0,     0,     0,     0,   613,
       0,   611,     0,   195,     0,     0,   785,     0,     0,     0,
       0,   521,   519,     0,   510,     0,     0,   499,   500,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
       0,     0,     0,   664,     0,   209,     0,     0,     0,     0,
     165,     0,   165,     0,   173,   243,     0,   307,   303,   305,
       0,   293,   294,   362,     0,     0,     0,     0,   694,   370,
     667,   671,   673,   675,   677,   680,   687,   688,   696,   923,
     809,     0,   818,  1024,  1023,  1022,  1025,   389,   573,   579,
     580,   583,   631,   632,   584,   585,   794,   795,   796,   588,
     391,   393,   396,   589,   395,   423,   475,     0,   472,   502,
     125,    56,    57,    54,    55,   131,   130,     0,    90,     0,
       0,   109,   110,   115,    74,    75,    52,    53,    73,   734,
       0,   737,   764,     0,   727,   726,   731,   730,   762,     0,
       0,   739,     0,   735,   738,   717,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   146,   148,
       0,     0,     0,   113,   116,     0,     0,     0,   168,     0,
       0,   624,     0,     0,     0,   259,     0,   572,     0,   260,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   238,
       0,     0,     0,     0,   286,     0,   283,   288,   241,   141,
     136,   139,     0,   189,     0,     0,    71,    65,    68,    67,
       0,    63,   277,     0,     0,   168,     0,   321,   325,     0,
       0,     0,   328,     0,     0,   334,     0,     0,   341,     0,
     345,     0,   420,   419,   168,     0,     0,   196,     0,   198,
     322,     0,     0,     0,     0,   522,     0,   512,     0,   545,
     542,     0,   546,   547,     0,     0,   541,     0,   516,   544,
     543,     0,     0,     0,     0,   643,   644,   640,     0,     0,
     648,   649,   645,   787,   788,   654,   792,   652,     0,     0,
       0,     0,   658,   810,   817,   816,   971,   201,     0,     0,
       0,   659,   660,     0,     0,   210,   790,    26,     0,    17,
      21,    22,   304,   316,     0,   317,     0,   308,   309,   310,
     311,     0,   296,     0,     0,     0,   678,   691,     0,   367,
     371,     0,   710,     0,     0,     0,     0,     0,     0,   666,
     668,   669,   705,   706,   707,   709,   708,     0,     0,   682,
     681,     0,   685,   689,   703,   701,   700,   693,   697,     0,
       0,     0,     0,     0,     0,     0,     0,   576,   578,   577,
     574,   397,   504,   133,   132,    91,   105,   751,   732,     0,
     756,     0,   756,   745,   740,   147,   149,     0,     0,     0,
     117,   145,     0,    27,     0,   621,   622,   625,   618,   619,
     258,     0,     0,   272,   264,     0,   268,     0,   262,     0,
       0,     0,   281,     0,     0,     0,   240,   284,   287,     0,
     137,     0,     0,    70,     0,    64,   278,     0,     0,   324,
     326,   331,     0,   329,     0,     0,     0,     0,     0,   335,
       0,     0,   349,     0,     0,   342,     0,     0,   346,   421,
       0,   614,   612,   197,   786,     0,     0,   521,     0,     0,
     553,     0,   521,     0,   517,     0,    14,     0,     0,     0,
       0,     0,     0,     0,   657,     0,     0,     0,     0,     0,
       0,   661,   665,   320,   318,   319,   312,   313,   314,   306,
       0,     0,   301,     0,   295,   695,   686,   692,     0,     0,
     765,   766,   776,   775,   774,     0,     0,     0,     0,   767,
     672,   773,     0,   670,   674,     0,     0,   679,   683,     0,
     704,   699,   702,   698,     0,     0,   586,     0,   581,   636,
     575,   798,   799,   797,   582,   752,     0,     0,   750,   757,
     758,   754,     0,   749,     0,   747,     0,     0,     0,     0,
       0,     0,   563,   261,     0,   270,     0,     0,   266,     0,
     269,   282,   290,   291,   285,   239,     0,     0,     0,    66,
     280,   569,     0,     0,   332,   336,   330,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   565,
       0,     0,   521,     0,   548,     0,   521,   571,   641,   642,
     646,   647,     0,   653,   793,   655,     0,     0,     0,     0,
     662,   315,   302,   297,     0,   690,   777,     0,     0,   769,
       0,   715,   714,   713,   712,   711,   676,     0,   768,     0,
     633,     0,     0,   761,   760,   759,     0,   753,   746,   744,
       0,   741,   742,   736,   150,   152,   154,     0,     0,     0,
       0,     0,   265,   263,     0,   271,     0,   206,   351,    72,
     327,   333,     0,   347,   343,   350,     0,     0,     0,   337,
       0,     0,   339,     0,   531,   525,   520,     0,   521,   511,
       0,   789,     0,     0,     0,     0,   300,   298,   771,   770,
       0,     0,   634,   587,     0,   755,   748,     0,     0,   156,
     155,     0,     0,     0,     0,   151,   267,     0,     0,     0,
       0,     0,     0,   539,   533,     0,   532,   534,   540,   537,
     527,     0,   526,   528,   538,   513,     0,   514,     0,     0,
     663,   299,   772,   684,   635,   743,   153,   157,     0,     0,
       0,     0,   289,     0,     0,   340,   338,     0,     0,   524,
     535,   536,   523,   529,   530,   515,     0,   158,     0,     0,
       0,   348,   344,     0,     0,     0,     0,     0,     0,     0,
       0,   160,     0,     0,   159,     0,     0,     0,     0,     0,
       0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1495, -1495,  -218,  -186, -1495,  1223,  1224, -1495,  1231,  -539,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1010, -1495, -1495, -1495, -1495,  -216,  -580, -1495,   748,   -25,
   -1495, -1495, -1495, -1495, -1495,   290,   519, -1495, -1495,   -10,
    -128,  1060, -1495,  1045, -1495, -1495,  -646, -1495,   458, -1495,
     262, -1495,  -213,  -263, -1495,  -554, -1495,    16,    33,     8,
    -190,  -180, -1495,  -874, -1495, -1495,   366, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495,   628,   -93,  1459,
       0, -1495, -1495, -1495, -1495,   469, -1495, -1495,  -303, -1495,
      23, -1495,  1042,  -927,  -742,  -718, -1495, -1495,   714, -1495,
   -1495,    29,   243, -1495, -1495, -1495,   126, -1488, -1495,   384,
     130, -1495, -1495,   134, -1318, -1495,   961,   227, -1495, -1495,
     224, -1045, -1495, -1495,   222, -1495, -1495, -1257, -1245, -1495,
     218, -1423, -1495, -1495,   863,   864, -1495,  -456,   846, -1495,
   -1495,  -653,   169,  -648,   363,   358, -1495, -1495, -1495,   589,
   -1495, -1495,  1188, -1495, -1495, -1495, -1495, -1495,  -871,  -325,
    -692, -1495,   -94, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
     -17,  -829, -1495,  -546,   656,   294, -1495,  -417, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,   815, -1495, -1061, -1495,   208,
   -1495,   695,  -821, -1495, -1495, -1495, -1495, -1495,  -254,  -247,
   -1235,  -858, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495,  -745,  -868,  -171,  -836, -1495, -1495, -1495,
    -864, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,  1076,
    1077,  -386,   515,   345, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,   186, -1495,
   -1495,   174, -1495,   178, -1064, -1495, -1495, -1495,   141,   137,
     -33,   407, -1495, -1495, -1495, -1495, -1495, -1495, -1495, -1495,
   -1495, -1495, -1495, -1495, -1495,   145, -1495, -1495, -1495,   -24,
     404,   546, -1495, -1495, -1495, -1495, -1495,   338, -1495, -1495,
   -1494, -1495, -1495, -1495,  -536, -1495,   109, -1495,   -47, -1495,
   -1495, -1495, -1495, -1329, -1495,   157, -1495, -1495, -1495, -1495,
   -1495,   958, -1495, -1495, -1495, -1495, -1495,  -938, -1495, -1495,
   -1495,  -391,  -385,   260,   937, -1495
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   256,   637,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
    1276,   786,   274,   275,   276,   277,   278,   279,   965,   966,
     967,   280,   281,   282,   971,   972,   973,   283,   445,   284,
     285,   714,   286,   447,   448,   449,   464,   776,   777,   287,
    1227,   288,  1704,  1705,   289,   290,   291,   557,   292,   293,
     294,   295,   296,   779,   297,   298,   539,   299,   300,   301,
     302,   303,   304,   647,   305,   306,   872,   873,   307,   308,
     569,   310,   648,   462,  1032,  1033,   311,   649,   312,   651,
     570,   314,   766,   767,  1264,   471,   315,   472,   473,   773,
    1265,  1266,  1267,   652,   653,  1131,  1132,  1552,   654,  1128,
    1129,  1377,  1378,  1379,  1380,   316,   799,   800,   317,  1291,
    1292,  1494,   318,  1294,  1295,   319,   320,  1297,  1298,  1299,
    1300,  1501,   321,   322,   323,   324,   913,   325,   326,  1389,
     327,   328,   329,   330,   331,   332,   333,   334,   335,  1171,
     336,   337,   338,   339,   672,   673,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   707,   702,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   943,   367,   368,   369,  1327,
     832,   833,   834,  1736,  1781,  1782,  1775,  1776,  1783,  1777,
    1328,  1329,   370,   371,  1330,   372,   373,   374,   375,   376,
     377,   378,   379,  1027,  1502,  1430,  1158,  1587,  1159,  1172,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   806,  1240,   391,   392,   393,   394,  1161,  1162,  1163,
    1164,   395,   396,   397,   398,   399,   400,   862,   863,   401,
    1361,  1362,  1670,  1114,  1139,  1399,  1400,  1140,  1141,  1142,
    1143,  1144,  1409,  1577,  1578,  1145,  1412,  1146,  1558,  1147,
    1148,  1417,  1418,  1583,  1581,  1401,  1402,  1403,  1404,  1684,
     743,   992,   993,   994,   995,   996,   997,  1213,  1607,  1701,
    1214,  1605,  1699,   998,  1442,  1602,  1598,  1599,  1600,   999,
    1000,  1405,  1413,  1568,  1406,  1564,  1390,   402,   403,   404,
     405,   560,   406,   407,   408,   409,   410,  1165,  1166,  1167,
    1168,  1277,   578,   411,   412,   413
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -862;
  const short int
  xquery_parser::yytable_[] =
  {
       309,   609,   934,   446,   309,   309,   309,   309,   715,   715,
     650,  1083,   420,   420,   420,   424,  1293,   696,   568,   572,
     418,   421,   422,   313,  1326,   921,  1025,   313,   313,   313,
     313,   922,   923,   924,   925,  1281,   718,   419,   419,   419,
     423,   586,  1113,  1047,   627,   624,  1137,   850,   891,   893,
    1026,   625,  1505,   858,   738,   625,  1059,  1516,   534,   629,
    1547,  1548,  1157,  1170,  1229,   753,  1160,  1160,   616,   617,
    1073,  1385,   885,   889,   892,   894,   783,   787,  1186,   952,
    1643,  1253,  1579,  1647,   625,    10,    11,   883,   887,   625,
    1021,   796,  1524,  1245,   588,   625,    10,    11,   757,  1029,
     625,   625,   625,   632,  1160,  1707,   431,   625,    10,    11,
     309,   625,  1702,   625,  1677,   717,   758,   431,   558,   427,
     428,   820,   429,   430,   625,    12,   634,   432,   625,   431,
    1056,  1283,  1190,   313,   434,   598,   625,   625,  1228,   432,
     433,  1495,  1023,   419,   625,   434,   591,   425,   592,  1022,
     435,  1023,   611,   613,  1247,  1216,   631,   434,  1160,   636,
    1217,   757,   435,   636,   625,  1391,   727,  1270,   947,  1218,
    1084,  1160,   749,  -169,   625,   469,  1219,  1290,  1220,   758,
    1089,   466,   436,   437,  1123,  1746,   426,  1221,   837,   695,
    1492,   467,  1678,  1254,   436,   437,   438,  -170,   625,   728,
     633,   909,  1024,   910,   911,   450,   912,    81,   914,   635,
     636,  1057,  1708,   127,  1222,   636,   915,   916,   468,   427,
     428,    92,   429,   430,   599,   821,   625,  1496,  1671,  1193,
     632,  1565,   636,  1099,   632,   593,   636,  1085,  1392,  1090,
     433,   759,   625,   439,   636,   636,   106,   782,   948,  1498,
    1134,   697,   636,  1135,   309,   309,   625,  1326,   309,  1791,
    1316,  1030,   470,  1795,  1137,  1137,  1326,   650,   625,   625,
    1485,  1505,   636,  1106,   127,   626,  1700,   313,   313,   589,
     628,   313,   636,  1258,  1524,  1255,   878,  1160,   625,  1269,
     830,   880,  1120,   309,  1709,  1039,  1368,  1229,  1031,  1768,
     891,   893,  1122,   440,  1367,   625,   636,  1251,  1187,  1256,
     625,   625,  1061,  1434,   828,  1421,   313,  1460,   631,   470,
     625,  1393,  1394,  1557,  1395,  1062,  1250,   633,   470,  1284,
     470,   633,  1110,   703,   636,   535,   705,   625,   625,   883,
     887,  1397,  1223,   439,   441,   978,  1804,   750,  1807,   552,
     636,  1100,  1312,  1398,   625,   751,  1136,   838,   442,  -169,
     625,   625,   762,   625,   636,   875,   443,   874,   632,  1469,
     442,  1228,   780,   573,   444,   625,   636,   636,   443,  1056,
    1734,  1495,   793,  -170,  1560,   579,   444,   582,  1759,   804,
     805,  1566,  1567,  1363,   717,  1044,   636,  1040,   811,  1387,
    1043,  1107,   747,   440,  1480,   879,   881,   748,  1160,   774,
     884,   888,   600,   636,  1313,   896,   947,   601,   636,   636,
     309,  1561,  1022,   127,   309,   484,  1495,  1773,   636,   877,
    1314,  1319,  1160,   453,  1224,  1225,  1226,  1091,   700,  1095,
     706,  1015,  1797,   313,   441,   636,   636,   313,  1016,  1018,
    1364,   309,   470,   309,  1051,   904,  1742,  1133,  1326,   424,
    1075,   424,   636,  1036,   981,   633,   982,  1633,   636,   636,
    1735,   636,   676,  1067,   313,  1058,   313,  1391,   775,   784,
     309,   835,   836,   636,   754,   309,   756,  1789,   424,  1450,
     677,  1176,  1068,   424,   840,   470,   949,   479,  1743,  1744,
    1138,   602,   485,   313,  1462,  1086,  1070,   595,   313,   596,
     983,  1177,  1638,   802,   868,   870,  1137,   733,   808,   734,
    1290,  1533,  1087,  1088,   488,  1137,   785,    12,  1017,  1019,
    1180,  1113,   733,  1497,   734,  1542,  1137,  1470,  1447,  1112,
     891,   893,   891,  1037,  1505,  1175,  1555,  1322,  1790,  1323,
    1392,  1586,   735,    10,    11,  1160,  1644,  1774,   309,  1349,
    1793,  1092,  1093,  1096,  1097,   309,  1369,  1370,  1371,   821,
     486,   487,  1069,   420,  1177,  1439,  1094,  1324,  1098,   736,
    1317,   313,  1374,  1681,  1194,  1195,  1071,  1691,   313,  1198,
    1682,  1178,  1696,  1596,   736,  1733,   597,   639,   419,   676,
    1683,   640,   936,  1376,   937,   938,   641,   939,   309,    81,
     535,   446,   683,   535,  1669,   309,   869,   677,  1719,  1237,
     700,   684,   706,    92,  1645,   642,   309,   309,   309,   309,
    1239,   313,  1242,  1393,  1394,  1441,  1395,  1553,   313,  1160,
     630,   737,  1160,  1396,    12,   309,   822,  1318,   106,   313,
     313,   313,   313,  1397,  1179,   639,   737,  1023,  1597,   640,
    1210,   984,  1117,  1645,   641,  1398,  1121,  1692,   313,   639,
     881,  1364,  1697,   640,   985,   454,   986,  1211,   641,   632,
     679,  1102,  1305,   642,  1306,   463,  1773,   987,   988,   989,
    1319,   990,   726,   991,  1181,   730,  1651,   642,  1498,   579,
    1023,  1655,   744,   745,  1137,  1022,  1124,  1260,  1461,   680,
     579,  1182,  1261,   968,   489,  1022,   765,   768,  1138,  1138,
    1212,   768,   681,  1260,   643,  1617,    81,   644,  1261,   788,
    1078,  1079,  1080,  1319,   870,  1022,   579,   797,   798,   801,
      92,   700,   645,   706,   807,  1572,   465,  1262,  1319,  1320,
    1023,  1616,   814,  1779,  1319,  1320,   969,   682,  1257,  1022,
    1611,   970,   457,  1046,   458,   106,  1023,  1640,   646,  1134,
     886,  1550,  1135,  1725,  1414,  1415,  1111,  1160,   309,  1319,
    1320,   685,   643,  1072,   537,   644,   420,   891,  1263,   886,
    1333,  1641,  1334,   127,  1038,   686,   643,  1416,   815,   644,
     829,   313,  1439,  1119,  1727,  1427,  1322,  1551,  1323,   309,
     309,   419,   696,   801,  1539,  1731,  1810,   424,   424,  1440,
     474,  1752,  1118,  1753,   826,  1160,   646,  1160,  1641,   459,
    1803,  1737,   313,   313,   460,  1740,  1324,  1428,   622,  1641,
     646,  1319,  1065,  1066,  1321,   919,   920,  1319,  1320,  1322,
    1321,  1323,   621,   851,  1641,  1429,  1183,   490,  1160,   851,
    1780,  1779,  1441,   864,  1322,   676,  1323,   676,   622,   309,
    1322,   723,  1323,  1184,   477,  1321,  1778,  1784,  1823,  1324,
     446,   461,   538,   677,  1483,   677,  1794,   724,   491,   478,
    1160,   492,   313,   896,  1324,  1322,   309,  1323,   113,   881,
    1324,  1373,  1641,  1824,   113,  1160,   678,  1160,  1750,  1210,
     482,  1676,  1374,  1679,  1680,   125,  1706,  1786,  1778,   313,
    1357,   125,  1375,  1185,  1784,  1324,  1211,  1641,  1681,   113,
     719,  1433,  1231,  1376,  1365,  1682,  1325,   721,  1022,   778,
    1188,  1232,  1518,  1321,   720,  1683,   125,   778,  1562,  1503,
    1374,   722,  1188,  1506,   151,  1563,  1503,  1322,  1503,  1323,
     151,  1760,  1504,  1322,  1204,  1323,  1507,  1523,  1813,  1650,
    1138,  1816,  1338,  1206,  1339,  1205,  1199,  1200,  1201,  1138,
     483,  1260,  1202,  1543,  1207,   151,  1261,  1324,   451,   969,
    1138,   452,   974,  1324,   970,   940,   895,   113,   940,   455,
     897,   940,   456,   540,   475,   701,  1004,   476,   704,   541,
    1008,  1009,   536,   480,   125,   554,   481,   698,   699,  1706,
     739,   740,   741,   553,  1748,  1749,   536,  1196,  1197,   657,
    1544,  1545,  1028,   555,  1034,  1653,   574,   658,   659,   575,
     660,  1384,   579,   928,   929,   579,   926,   927,   661,  1048,
     536,   576,   662,   151,   663,   583,   650,  1445,  1446,   664,
    1693,  1694,   536,   309,   536,   584,  1706,   585,   587,   594,
     590,   424,   603,   604,   605,   607,   665,   608,   606,   614,
     618,   638,   656,   655,  1481,   675,   313,   674,   687,   688,
     689,  1081,   700,  1629,   690,   708,  1301,  1792,   709,   694,
     666,   667,   668,   669,   670,   671,   710,   711,   717,   446,
    1358,   712,   729,   731,   713,   732,   742,   772,   746,   755,
     309,   309,   309,   769,   778,   770,   781,   789,   791,   790,
     809,   535,   810,  1359,   792,   803,   452,   456,  1834,   476,
    1835,   481,   816,   313,   313,   313,   818,   492,   820,   823,
    1843,   824,   825,   831,   827,   839,   842,   852,  1138,  1672,
    1125,   955,   956,   957,   958,   959,   960,   961,   962,   963,
     964,   841,   860,   882,   861,   900,   609,   902,   865,   871,
     901,   903,   917,   930,   866,   931,   932,   933,   953,   944,
    1169,  1169,  1173,  1173,   950,   951,   975,   976,   979,   980,
    1002,  1001,  1003,  1005,  1007,  1010,  1011,  1012,  1020,  1035,
    1041,  1013,  1014,  1042,  1045,  1052,  1053,  1054,  1055,  1060,
    1101,  1063,  1064,   451,  1109,   455,  1108,   475,  1169,   480,
     491,  1104,  1119,  1105,  1126,  1103,  1116,  1189,   309,  1130,
     970,  1022,  1203,  1208,  1209,  1230,   420,  1235,  1236,  1238,
    1246,  1248,   774,  1272,  1454,  1252,  1274,  1275,  1259,  1273,
    1278,   313,  1279,  1280,  1285,  1290,  1286,  1234,  1296,  1289,
    1304,   419,  1311,  1302,   309,  1309,  1241,  1308,  1241,  1303,
     768,  1315,  1169,  1332,  1331,   309,  1360,   536,  1350,   735,
     536,  1381,  1383,   420,  1419,  1169,  1431,   313,  1388,  1411,
    1407,  1488,  1420,  1408,   309,  1422,  1635,    12,   313,  1438,
    1423,  1424,   420,  1425,  1426,  1443,  1449,  1452,   419,  1437,
    1510,  1457,  1453,  1455,   309,  1465,  1456,   313,   807,  1458,
     807,   309,   424,  1448,  1467,  1471,  1473,   419,  1474,   424,
    1475,  1479,  1484,  1459,  1487,  1509,  1503,   313,  1515,   904,
    1511,  1512,  1520,  1517,   313,  1531,  1526,  1521,  1363,  1535,
    1536,  1532,  1527,  1358,  1525,   851,  1374,  1537,   725,   536,
    1528,   869,   536,  1538,  1529,  1575,   536,  1530,  1556,   536,
     536,  1576,  1582,  1580,  1588,  1589,  1359,   536,  1590,  1595,
    1382,  1601,  1606,   536,   536,  1559,  1591,  1608,   536,  1592,
    1593,  1594,  1612,  1614,  1619,  1628,   536,  1631,  1626,  1627,
    1632,  1169,  1569,   536,   536,   536,   536,  1637,  1648,  1662,
    1649,   536,  1654,  1657,  1675,  1687,  1674,  1689,  1690,   536,
    1698,  1610,  1210,  1711,  1716,  1703,  1717,  1714,  1722,  1739,
    1550,  1755,  1604,  1666,  1667,  1668,  1754,  1721,  1635,  1757,
    1723,  1756,  1758,  1762,  1763,  1688,  1767,  1770,  1732,  1769,
    1771,  1800,  1785,  1710,  1787,  1809,  1788,  1815,  1801,  1820,
    1839,  1812,  1808,  1825,  1826,   536,  1836,  1833,  1840,  1837,
    1436,   619,   620,   977,  1798,  1818,   716,  1827,  1191,  1830,
     536,   752,   623,  1832,  1271,  1796,   309,  1451,  1765,  1842,
    1115,   536,  1268,   771,   768,  1050,  1624,  1478,  1463,  1554,
    1372,  1549,  1546,  1489,   817,  1493,  1499,  1508,   907,   313,
     908,   918,  1174,  1477,   946,   693,  1519,  1082,  1814,  1811,
     760,   761,  1169,  1243,  1435,  1541,  1534,  1570,  1540,  1358,
     536,  1723,  1686,  1386,  1574,  1573,   801,  1215,  1685,  1410,
    1444,  1603,  1695,     0,  1571,   856,  1169,     0,     0,     0,
       0,     0,  1359,     0,     0,     0,     0,     0,     0,   559,
       0,     0,     0,     0,     0,     0,  1745,     0,     0,     0,
    1805,     0,     0,     0,     0,  1522,     0,     0,     0,     0,
       0,     0,     0,     0,  1751,     0,     0,     0,  1481,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     864,     0,     0,  1821,     0,     0,     0,     0,     0,     0,
     535,     0,     0,     0,   535,     0,  1358,     0,     0,     0,
       0,     0,     0,     0,  1821,     0,     0,  1358,  1358,     0,
     309,     0,     0,  1805,     0,     0,     0,     0,  1358,  1359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1359,  1359,     0,   313,     0,     0,   954,     0,     0,   536,
       0,  1359,     0,     0,     0,     0,     0,     0,     0,  1169,
       0,     0,     0,   536,     0,     0,     0,   536,   536,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1609,   536,
       0,   536,     0,     0,     0,     0,     0,     0,     0,   536,
       0,     0,   536,     0,     0,     0,   536,     0,     0,     0,
       0,  1358,     0,     0,  1622,  1623,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1359,     0,     0,     0,     0,     0,
    1639,     0,     0,  1169,     0,     0,  1169,     0,   536,     0,
     309,     0,     0,     0,     0,     0,     0,     0,  1652,     0,
       0,     0,     0,  1656,     0,     0,     0,     0,  1358,     0,
       0,     0,     0,   313,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   309,     0,     0,     0,     0,   536,     0,
       0,  1359,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1358,     0,   313,     0,     0,     0,
       0,     0,     0,  1358,     0,     0,     0,   536,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1359,     0,     0,
       0,     0,     0,     0,     0,     0,  1359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   536,   536,   536,
     536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1169,  1726,     0,  1728,   536,  1730,     0,     0,     0,
       0,     0,     0,  1738,     0,     0,     0,     0,     0,   536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   536,     0,     0,     0,     0,  1169,
       0,  1169,     0,   536,     0,   536,     0,   536,     0,   536,
       0,     0,     0,     0,     0,     0,     0,  1761,     0,     0,
    1764,     0,   536,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1169,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1772,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   536,     0,   536,     0,     0,
       0,     0,     0,     0,  1169,     0,     0,     0,     0,     0,
       0,     0,  1799,     0,   559,     0,     0,  1802,     0,  1169,
       0,  1169,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     843,   844,     0,     0,   853,   854,   855,   857,     0,   859,
    1819,     0,     0,     0,     0,   867,     0,   536,     0,     0,
       0,     0,     0,   876,     0,     0,     0,     0,     0,     0,
    1828,     0,     0,     0,     0,  1829,     0,     0,   536,     0,
       0,     0,     0,     0,     0,   898,   899,  1838,     0,     0,
    1841,     0,     0,     0,   905,   906,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   942,     0,     0,   942,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,     0,     0,     0,   536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,  1006,     0,   536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   536,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   536,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1049,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   536,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1074,     0,     0,     0,  1076,
    1077,     0,     0,     0,     0,     0,     0,   536,   905,     0,
       0,     0,     0,     0,     0,     0,     0,   536,     0,     0,
       0,   536,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   899,   536,     0,     0,     0,
       0,  1127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,   536,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1192,
       0,     0,     0,     0,     0,     0,     0,   536,     0,     0,
     536,     0,     0,   536,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   536,     0,     0,     0,     0,
     536,     0,     0,     0,  1233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1287,  1288,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1307,     0,     0,  1310,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1335,  1336,  1337,     0,  1340,  1341,  1342,  1343,  1344,
    1345,  1346,  1347,  1348,     0,     0,  1351,  1352,     0,     0,
       0,     0,     0,     0,     0,  1366,     0,     0,   536,   536,
       0,   536,     0,   536,     0,  1127,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   536,     0,   536,     0,
       0,     0,     0,     0,     0,     0,  1432,     0,     0,     0,
       0,     0,     0,     0,   536,     0,     0,   536,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     536,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   536,     0,     0,     0,     0,     0,     0,     0,   536,
       0,     0,     0,     0,   536,     0,   536,     0,   536,  1464,
       0,  1466,     0,  1468,     0,     0,  1472,     0,     0,     0,
       0,  1476,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1482,     0,     0,     0,   536,     0,     0,
       0,     0,  1486,     0,     0,     0,     0,     0,  1490,  1491,
       0,     0,     0,     0,     0,     0,     0,   536,     0,     0,
       0,     0,   536,     0,     0,     0,     0,  1513,     0,     0,
    1514,     0,     0,     0,   536,     0,     0,   536,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1613,     0,     0,     0,  1615,     0,     0,     0,  1618,     0,
    1620,     0,  1621,     0,     0,     0,     0,     0,  1625,     0,
       0,     0,     0,     0,     0,     0,  1630,     0,     0,     0,
       0,     0,     0,     0,  1634,  1636,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1482,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1658,  1659,  1660,  1661,
       0,  1663,  1664,     0,  1665,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1673,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1712,     0,  1713,     0,     0,  1715,     0,
       0,     0,     0,     0,     0,     0,  1718,     0,     0,     0,
       0,  1720,  1636,     0,     0,     0,     0,     0,     0,  1724,
       0,     0,     0,     0,  1729,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1741,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1747,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1766,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1724,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1806,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -165,   886,     0,     0,  1817,     0,     0,
       0,     0,  1822,     0,     1,     2,     0,  1806,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,    11,  1822,    12,     0,     0,  1831,    13,   415,     0,
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
     248,   249,   250,   251,   252,   253,  -165,   886,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    12,     0,     0,     0,
     890,   415,     0,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,   416,    29,    30,    31,
      32,    33,     0,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,     0,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,    71,    72,    73,    74,    75,     0,    76,    77,
      78,     0,     0,    79,    80,     0,     0,     0,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     0,
       0,     0,    92,     0,    93,    94,    95,    96,     0,    97,
       0,     0,     0,    98,    99,   100,   101,   102,     0,     0,
       0,     0,     0,     0,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     0,   112,   113,   114,   115,   116,     0,
       0,     0,     0,   117,   118,   119,   120,   121,   122,   123,
     124,     0,   125,     0,   126,   127,     0,     0,   128,   129,
     130,     0,     0,     0,   131,     0,   132,   133,     0,   134,
     135,     0,   136,     0,   137,     0,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,     0,     0,   149,
     150,   151,     0,   417,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   886,
     246,     0,   247,   248,   249,   250,   251,   252,   253,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     0,    12,     0,
       0,     0,   414,   415,     0,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,   416,    29,
      30,    31,    32,    33,     0,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,    71,    72,    73,    74,    75,     0,
      76,    77,    78,     0,     0,    79,    80,     0,     0,     0,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,    92,     0,    93,    94,    95,    96,
       0,    97,     0,     0,     0,    98,    99,   100,   101,   102,
       0,     0,     0,     0,     0,     0,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,   114,   115,
     116,     0,     0,     0,     0,   117,   118,   119,   120,   121,
     122,   123,   124,     0,   125,     0,   126,   127,     0,     0,
     128,   129,   130,     0,     0,     0,   131,     0,   132,   133,
       0,   134,   135,     0,   136,     0,   137,     0,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,     0,
       0,   149,   150,   151,     0,   417,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     0,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   886,   246,     0,   247,   248,   249,   250,   251,   252,
     253,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,     0,     0,     0,
      12,     0,     0,     0,   414,   415,     0,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   561,
     416,    29,    30,    31,    32,    33,     0,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
       0,    47,    48,    49,   562,   563,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,    71,    72,    73,    74,
      75,     0,    76,    77,    78,     0,     0,    79,    80,     0,
       0,     0,    81,    82,   510,    84,    85,    86,    87,    88,
     564,    90,    91,     0,     0,     0,    92,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,    98,    99,   100,
     101,   102,     0,     0,     0,     0,     0,     0,   103,   104,
     105,   106,   107,   108,   109,   565,   111,     0,   112,   113,
     114,   115,   116,     0,     0,     0,     0,   117,   118,   119,
     120,   121,   122,   123,   124,     0,   125,     0,   126,   127,
       0,     0,   128,   129,   130,     0,     0,     0,   131,     0,
     132,   133,     0,   134,   135,     0,   136,     0,   137,     0,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,   151,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     528,   529,   530,   178,   179,   531,   567,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,     0,   246,     0,   247,   248,   249,   250,
     251,   252,   253,  -861,   457,     0,   458,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -861,     0,     0,     0,
    -861,     0,     0,     0,  -861,  -861,     0,     0,     0,     0,
    -861,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   459,     0,     0,  -861,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -861,     0,  -861,
    -861,  -861,     0,     0,  -861,  -861,  -861,  -861,     0,     0,
       0,  -861,  -861,     0,     0,     0,     0,     0,  -861,     0,
       0,  -861,  -861,   461,     0,     0,  -861,     0,     0,     0,
       0,  -861,  -861,     0,     0,     0,     0,  -861,     0,     0,
       0,  -861,     0,     0,     0,  -861,  -861,     0,  -861,     0,
    -861,  -861,     0,     0,     0,  -861,  -861,     0,     0,  -861,
    -861,  -861,  -861,  -861,  -861,     0,     0,  -861,     0,     0,
       0,     0,  -861,  -861,     0,     0,  -861,     0,     0,     0,
       0,  -861,     0,     0,  -861,     0,     0,     0,     0,  -861,
    -861,  -861,  -861,  -861,     0,  -861,  -861,  -861,  -861,  -861,
       0,     0,     0,     0,  -861,  -861,  -861,     0,  -861,  -861,
    -861,  -861,  -861,  -861,     0,  -861,     0,  -861,     0,     0,
       0,     0,  -861,  -861,  -861,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -861,     0,
    -861,     0,  -861,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -861,     0,     0,     0,     0,  -861,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    12,  -861,     0,  -861,    13,
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
       0,   247,   248,   249,   250,   251,   252,   253,   254,   255,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,    11,     0,    12,
       0,     0,     0,    13,    14,     0,    15,    16,    17,    18,
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
     252,   253,     0,   615,     1,     2,     0,     0,     0,     0,
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
       0,   126,   127,     0,     0,   128,   129,   130,     0,   556,
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
       8,     9,    10,    11,     0,    12,     0,     0,     0,   414,
     415,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   416,    29,    30,    31,    32,
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
       0,   819,     0,   131,     0,   132,   133,     0,   134,   135,
       0,   136,     0,   137,     0,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,     0,     0,   149,   150,
     151,     0,   417,   153,   154,   155,   156,   157,   158,   159,
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
       0,   414,   415,     0,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,  1353,   416,    29,    30,
      31,    32,    33,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    47,    48,
      49,  1354,  1355,    52,    53,    54,    55,    56,    57,    58,
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
     178,   179,   180,  1356,   182,   183,   184,   185,   186,   187,
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
       0,    12,     0,     0,     0,    13,    14,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,     0,    34,    35,
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
     147,   148,     0,     0,   149,   150,   151,     0,   152,   153,
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
     415,     0,    15,    16,    17,    18,    19,    20,    21,    22,
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
     151,     0,   417,   153,   154,   155,   156,   157,   158,   159,
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
       0,   890,   415,     0,    15,    16,    17,    18,    19,    20,
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
       0,     0,     0,   414,   415,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,  1353,   416,
      29,    30,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,     0,
      47,    48,    49,  1354,  1355,    52,    53,    54,    55,    56,
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
     176,   177,   178,   179,   180,  1356,   182,   183,   184,   185,
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
     127,     0,     0,   128,   129,   130,     0,     0,   566,   131,
       0,   132,   133,     0,   134,   135,     0,   136,     0,   137,
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
       0,   131,   571,   132,   133,     0,   134,   135,     0,   136,
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
     238,   239,   240,   241,   242,   243,   244,   245,   610,   246,
       0,   247,   248,   249,   250,   251,   252,   253,     1,     2,
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
     129,   130,     0,     0,     0,   131,     0,   132,   133,     0,
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
       0,   246,   612,   247,   248,   249,   250,   251,   252,   253,
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
       0,   128,   129,   130,     0,   935,     0,   131,     0,   132,
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
     941,   132,   133,     0,   134,   135,     0,   136,     0,   137,
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
       0,   131,   945,   132,   133,     0,   134,   135,     0,   136,
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
     565,   111,     0,   112,   113,   691,   115,   116,     0,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,   692,   127,     0,     0,   128,   129,   130,
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
     129,   130,     0,     0,     0,   131,     0,   132,   133,     0,
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
      19,    20,    21,    22,    23,    24,   496,    26,   498,   416,
      29,   499,    31,    32,    33,     0,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,   501,     0,
      47,    48,    49,   503,   504,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,    71,    72,    73,    74,    75,
       0,    76,    77,    78,     0,     0,    79,    80,     0,     0,
       0,    81,    82,   510,    84,    85,    86,    87,    88,   564,
      90,    91,     0,     0,     0,    92,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,   513,    99,   100,   101,
     102,     0,     0,     0,     0,     0,     0,   103,   104,   105,
     106,   107,   108,   109,   565,   111,     0,   112,   113,   114,
     115,   116,     0,     0,     0,     0,   117,   118,   119,   120,
     121,   122,   123,   124,     0,   125,     0,   126,   127,     0,
       0,   128,   129,   130,     0,     0,     0,   131,     0,   132,
     133,     0,   134,   135,     0,   136,     0,   137,     0,   138,
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
      94,    95,    96,     0,    97,     0,     0,     0,   513,    99,
     100,   101,   102,     0,     0,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   565,   111,     0,   112,
     113,     0,   115,   116,     0,     0,     0,     0,   117,   118,
     119,   120,   121,   122,   123,   124,     0,   125,     0,     0,
       0,     0,     0,   128,   129,   130,     0,     0,     0,   131,
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
     496,    26,   498,   416,    29,   499,    31,    32,    33,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,   501,     0,    47,    48,    49,   503,   504,    52,
     505,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,    71,
      72,    73,    74,    75,     0,    76,    77,    78,     0,     0,
      79,    80,     0,     0,     0,    81,    82,   510,    84,    85,
      86,    87,    88,   564,    90,    91,     0,     0,     0,    92,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
     513,    99,   100,   101,   102,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   565,   111,
       0,   112,   113,     0,   115,   116,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   124,     0,   125,
       0,     0,     0,     0,     0,   128,   129,   130,     0,     0,
       0,   131,     0,   132,   133,     0,     0,     0,     0,   136,
       0,   137,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,   151,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   523,
     162,   524,   164,   525,   526,   167,   168,   169,   170,   171,
     172,   527,   174,   528,   529,   530,   178,   179,   531,   532,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,   246,     0,   247,
     533,   249,   250,   251,   252,   253,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,     0,     0,     0,    12,     0,     0,     0,   414,
     415,     0,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   496,    26,   498,   416,    29,   499,    31,    32,
      33,     0,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,   501,     0,    47,    48,    49,   503,
     504,    52,   505,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,    71,    72,    73,    74,    75,     0,    76,    77,    78,
       0,     0,    79,    80,     0,     0,     0,    81,    82,   510,
      84,    85,    86,    87,    88,   564,    90,    91,     0,     0,
       0,    92,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,   513,     0,   100,   101,   102,     0,     0,     0,
       0,     0,     0,   103,   104,   105,   106,     0,   108,   109,
     565,   111,     0,   112,   113,     0,   115,   116,     0,     0,
       0,     0,   117,   118,   119,   120,   121,   122,   123,   124,
       0,   125,     0,     0,     0,     0,     0,   128,   129,   130,
       0,     0,     0,   131,     0,   132,   133,     0,     0,     0,
       0,   136,     0,   137,     0,   138,     0,   140,     0,   142,
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
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,   414,   415,     0,    15,    16,    17,   493,    19,    20,
      21,   494,    23,   495,   496,   497,   498,   416,    29,   499,
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
     108,   109,     0,     0,     0,     0,     0,     0,   115,   516,
       0,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,   136,     0,   137,     0,   138,   139,   140,
     141,   522,   143,   144,   145,   146,   147,   148,     0,     0,
     149,   150,     0,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   523,   162,   524,   164,   525,   526,   167,
     168,   169,   170,   171,   172,   527,   174,   528,   529,   530,
     178,   179,   531,   532,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
       0,     1,     2,   247,   533,   249,   250,   251,   252,   253,
       3,     0,     0,     0,     0,     8,     9,     0,     0,     0,
       0,     0,     0,     0,   414,   415,     0,    15,    16,    17,
     542,    19,    20,    21,   494,   543,   544,   496,   497,   498,
     416,    29,   499,    31,   545,    33,     0,    34,    35,    36,
      37,   546,    39,   547,   548,    42,    43,    44,    45,   501,
       0,    47,   549,    49,   503,   504,    52,   505,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,   506,   507,    70,     0,    71,    72,    73,   550,
       0,     0,    76,    77,    78,     0,     0,   509,    80,     0,
       0,     0,     0,    82,   510,    84,   511,   512,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,   513,    99,   100,
     514,   515,     0,     0,     0,     0,     0,     0,   103,   104,
     105,     0,   107,   108,   109,     0,     0,     0,     0,     0,
       0,   115,   516,     0,     0,     0,     0,   117,   118,   119,
     120,   517,   122,   123,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   130,     0,     0,     0,   131,     0,
     132,   521,     0,     0,     0,     0,   136,     0,   137,     0,
     138,   139,   140,   141,   522,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,     0,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   523,   551,   524,   164,
     525,   526,   167,   168,   169,   170,   171,   172,   527,   174,
     528,   529,   530,   178,   179,   531,   532,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,     0,   577,     0,   247,   533,   249,   250,
     251,   252,   253,     8,     9,     0,     0,     0,   794,     0,
       0,     0,   414,   415,     0,    15,    16,    17,   542,    19,
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
     519,   520,   130,     0,     0,     0,   131,   795,   132,   521,
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
       0,     0,   577,     0,   247,   533,   249,   250,   251,   252,
     253,     8,     9,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,   137,     0,   138,   139,   140,   141,
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
       0,     0,   247,   533,   249,   250,   251,   252,   253,   580,
     581,     0,     0,     0,     0,     0,     8,     9,     0,     0,
       0,     0,     0,     0,     0,   414,   415,     0,    15,    16,
      17,   542,    19,    20,    21,   494,   543,   544,   496,   497,
     498,   416,    29,   499,    31,   545,    33,     0,    34,    35,
      36,    37,   546,    39,   547,   548,    42,    43,    44,    45,
     501,     0,    47,   549,    49,   503,   504,    52,   505,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,   506,   507,    70,     0,    71,    72,    73,
     550,     0,     0,    76,    77,    78,     0,     0,   509,    80,
       0,     0,     0,     0,    82,   510,    84,   511,   512,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,   513,    99,
     100,   514,   515,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,   107,   108,   109,     0,     0,     0,     0,
       0,     0,   115,   516,     0,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
       0,   132,   521,     0,     0,     0,     0,     0,     0,   137,
       0,   138,   139,   140,   141,   522,   143,   144,   145,   146,
     147,   148,     0,     0,   149,   150,     0,     0,   417,   153,
     154,   155,   156,   157,   158,   159,   160,   523,   551,   524,
     164,   525,   526,   167,   168,   169,   170,   171,   172,   527,
     174,   528,   529,   530,   178,   179,   531,   532,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,     0,     0,     0,   247,   533,   249,
     250,   251,   252,   253,     4,     5,     6,     7,     8,     9,
       0,     0,     0,    12,     0,     0,     0,   414,   415,     0,
      15,    16,    17,   845,    19,    20,    21,    22,   543,   846,
     496,    26,   498,   416,    29,   499,    31,   545,    33,     0,
      34,    35,    36,    37,   847,    39,   547,   548,    42,    43,
      44,    45,   501,     0,    47,   848,    49,   503,   504,    52,
     505,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   506,   507,    70,     0,    71,
      72,    73,   849,     0,     0,    76,    77,    78,     0,     0,
     509,    80,     0,     0,     0,    81,    82,   510,    84,   511,
     512,    87,    88,   564,    90,     0,     0,     0,     0,    92,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
     513,    99,   100,   514,   515,     0,     0,     0,     0,     0,
       0,   103,   104,   105,   106,   107,   108,   109,   565,   111,
       0,   112,   113,     0,   115,   116,     0,     0,     0,     0,
     117,   118,   119,   120,   121,   122,   123,   518,     0,   125,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,     0,   132,   521,     0,     0,     0,     0,     0,
       0,   137,     0,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,   151,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   523,
     551,   524,   164,   525,   526,   167,   168,   169,   170,   171,
     172,   527,   174,   528,   529,   530,   178,   179,   531,   532,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,     0,   246,     0,   247,
     533,   249,   250,   251,   252,   253,     8,     9,     0,     0,
       0,     0,     0,     0,     0,   414,   415,     0,    15,    16,
      17,   493,    19,    20,    21,   494,    23,   495,   496,  1149,
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
     104,   105,     0,   107,   108,  1150,     0,     0,     0,  1151,
       0,     0,   115,   516,     0,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
    1584,   132,   521,     0,     0,     0,     0,  1585,     0,   137,
       0,   138,   139,   140,   141,   522,   143,   144,   145,   146,
     147,   148,     0,     0,  1152,   150,     0,     0,   417,   153,
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
    1153,  1154,  1155,  1156,   414,   415,     0,    15,    16,    17,
     542,    19,    20,    21,   494,   543,   544,   496,   497,   498,
     416,    29,   499,    31,   545,    33,     0,    34,    35,    36,
      37,   546,    39,   547,   548,    42,    43,    44,    45,   501,
       0,    47,   549,    49,   503,   504,    52,   505,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,   506,   507,    70,     0,    71,    72,    73,   550,
       0,     0,    76,    77,    78,     0,     0,   509,    80,     0,
       0,     0,     0,    82,   510,    84,   511,   512,    87,    88,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,     0,    97,     0,     0,     0,   513,    99,   100,
     514,   515,     0,     0,     0,     0,     0,     0,   103,   104,
     105,     0,   107,   108,   109,     0,     0,     0,     0,     0,
       0,   115,   516,     0,     0,     0,     0,   117,   118,   119,
     120,   517,   122,   123,   518,     0,     0,     0,     0,     0,
       0,     0,   519,   520,   130,     0,     0,     0,   131,   763,
     132,   521,     0,     0,     0,     0,   764,     0,   137,     0,
     138,   139,   140,   141,   522,   143,   144,   145,   146,   147,
     148,     0,     0,   149,   150,     0,     0,   417,   153,   154,
     155,   156,   157,   158,   159,   160,   523,   551,   524,   164,
     525,   526,   167,   168,   169,   170,   171,   172,   527,   174,
     528,   529,   530,   178,   179,   531,   532,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
       0,   195,   196,   197,     0,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,     0,     0,     8,     9,   247,   533,   249,   250,
     251,   252,   253,   414,   415,     0,    15,    16,    17,   542,
      19,    20,    21,   494,   543,   544,   496,   497,   498,   416,
      29,   499,    31,   545,    33,     0,    34,    35,    36,    37,
     546,    39,   547,   548,    42,    43,    44,    45,   501,     0,
      47,   549,    49,   503,   504,    52,   505,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   506,   507,    70,     0,    71,    72,    73,   550,     0,
       0,    76,    77,    78,     0,     0,   509,    80,     0,     0,
       0,     0,    82,   510,    84,   511,   512,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    95,
      96,     0,    97,     0,     0,     0,   513,    99,   100,   514,
     515,     0,     0,     0,     0,     0,     0,   103,   104,   105,
       0,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     115,   516,     0,     0,     0,     0,   117,   118,   119,   120,
     517,   122,   123,   518,     0,     0,     0,     0,     0,     0,
       0,   519,   520,   130,     0,     0,     0,   131,   812,   132,
     521,     0,     0,     0,     0,   813,     0,   137,     0,   138,
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
     252,   253,   414,   415,     0,    15,    16,    17,   493,    19,
      20,    21,   494,    23,   495,   496,  1149,   498,   416,    29,
     499,    31,    32,    33,     0,    34,    35,    36,    37,   500,
      39,    40,    41,    42,    43,    44,    45,   501,     0,    47,
     502,    49,   503,   504,    52,   505,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
     506,   507,    70,     0,    71,    72,    73,   508,     0,     0,
      76,    77,    78,     0,     0,   509,    80,     0,     0,     0,
       0,    82,   510,    84,   511,   512,    87,    88,  1500,     0,
       0,     0,     0,     0,     0,     0,    93,    94,    95,    96,
       0,    97,     0,     0,     0,   513,    99,   100,   514,   515,
       0,     0,     0,     0,     0,     0,   103,   104,   105,     0,
     107,   108,  1150,     0,     0,     0,  1151,     0,     0,   115,
     516,     0,     0,     0,     0,   117,   118,   119,   120,   517,
     122,   123,   518,     0,     0,     0,     0,     0,     0,     0,
     519,   520,   130,     0,     0,     0,   131,     0,   132,   521,
       0,     0,     0,     0,     0,     0,   137,     0,   138,   139,
     140,   141,   522,   143,   144,   145,   146,   147,   148,     0,
       0,  1152,   150,     0,     0,   417,   153,   154,   155,   156,
     157,   158,   159,   160,   523,   162,   524,   164,   525,   526,
     167,   168,   169,   170,   171,   172,   527,   174,   528,   529,
     530,   178,   179,   531,   532,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,     0,   195,
     196,   197,     0,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
       0,     0,     8,     9,   247,   533,   249,  1153,  1154,  1155,
    1156,   414,   415,     0,    15,    16,    17,   493,    19,    20,
      21,   494,    23,   495,   496,  1149,   498,   416,    29,   499,
      31,    32,    33,     0,    34,    35,    36,    37,   500,    39,
      40,    41,    42,    43,    44,    45,   501,     0,    47,   502,
      49,   503,   504,    52,   505,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,   506,
     507,    70,     0,    71,    72,    73,   508,     0,     0,    76,
      77,    78,     0,     0,   509,    80,     0,     0,     0,     0,
      82,   510,    84,   511,   512,    87,    88,  1642,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    95,    96,     0,
      97,     0,     0,     0,   513,    99,   100,   514,   515,     0,
       0,     0,     0,     0,     0,   103,   104,   105,     0,   107,
     108,  1150,     0,     0,     0,  1151,     0,     0,   115,   516,
       0,     0,     0,     0,   117,   118,   119,   120,   517,   122,
     123,   518,     0,     0,     0,     0,     0,     0,     0,   519,
     520,   130,     0,     0,     0,   131,     0,   132,   521,     0,
       0,     0,     0,     0,     0,   137,     0,   138,   139,   140,
     141,   522,   143,   144,   145,   146,   147,   148,     0,     0,
    1152,   150,     0,     0,   417,   153,   154,   155,   156,   157,
     158,   159,   160,   523,   162,   524,   164,   525,   526,   167,
     168,   169,   170,   171,   172,   527,   174,   528,   529,   530,
     178,   179,   531,   532,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,   195,   196,
     197,     0,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,     0,
       0,     8,     9,   247,   533,   249,  1153,  1154,  1155,  1156,
     414,   415,     0,    15,    16,    17,   493,    19,    20,    21,
     494,    23,   495,   496,  1149,   498,   416,    29,   499,    31,
      32,    33,     0,    34,    35,    36,    37,   500,    39,    40,
      41,    42,    43,    44,    45,   501,     0,    47,   502,    49,
     503,   504,    52,   505,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,   506,   507,
      70,     0,    71,    72,    73,   508,     0,     0,    76,    77,
      78,     0,     0,   509,    80,     0,     0,     0,     0,    82,
     510,    84,   511,   512,    87,    88,  1646,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,     0,    97,
       0,     0,     0,   513,    99,   100,   514,   515,     0,     0,
       0,     0,     0,     0,   103,   104,   105,     0,   107,   108,
    1150,     0,     0,     0,  1151,     0,     0,   115,   516,     0,
       0,     0,     0,   117,   118,   119,   120,   517,   122,   123,
     518,     0,     0,     0,     0,     0,     0,     0,   519,   520,
     130,     0,     0,     0,   131,     0,   132,   521,     0,     0,
       0,     0,     0,     0,   137,     0,   138,   139,   140,   141,
     522,   143,   144,   145,   146,   147,   148,     0,     0,  1152,
     150,     0,     0,   417,   153,   154,   155,   156,   157,   158,
     159,   160,   523,   162,   524,   164,   525,   526,   167,   168,
     169,   170,   171,   172,   527,   174,   528,   529,   530,   178,
     179,   531,   532,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,     0,   195,   196,   197,
       0,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,     0,     0,
       8,     9,   247,   533,   249,  1153,  1154,  1155,  1156,   414,
     415,     0,    15,    16,    17,   493,    19,    20,    21,   494,
      23,   495,   496,  1149,   498,   416,    29,   499,    31,    32,
      33,     0,    34,    35,    36,    37,   500,    39,    40,    41,
      42,    43,    44,    45,   501,     0,    47,   502,    49,   503,
     504,    52,   505,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,   506,   507,    70,
       0,    71,    72,    73,   508,     0,     0,    76,    77,    78,
       0,     0,   509,    80,     0,     0,     0,     0,    82,   510,
      84,   511,   512,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,    93,    94,    95,    96,     0,    97,     0,
       0,     0,   513,    99,   100,   514,   515,     0,     0,     0,
       0,     0,     0,   103,   104,   105,     0,   107,   108,  1150,
       0,     0,     0,  1151,     0,     0,   115,   516,     0,     0,
       0,     0,   117,   118,   119,   120,   517,   122,   123,   518,
       0,     0,     0,     0,     0,     0,     0,   519,   520,   130,
       0,     0,     0,   131,     0,   132,   521,     0,     0,     0,
       0,     0,     0,   137,     0,   138,   139,   140,   141,   522,
     143,   144,   145,   146,   147,   148,     0,     0,  1152,   150,
       0,     0,   417,   153,   154,   155,   156,   157,   158,   159,
     160,   523,   162,   524,   164,   525,   526,   167,   168,   169,
     170,   171,   172,   527,   174,   528,   529,   530,   178,   179,
     531,   532,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,     0,   195,   196,   197,     0,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,     0,     0,     8,
       9,   247,   533,   249,  1153,  1154,  1155,  1156,   414,   415,
       0,    15,    16,    17,   493,    19,    20,    21,   494,    23,
     495,   496,  1149,   498,   416,    29,   499,    31,    32,    33,
       0,    34,    35,    36,    37,   500,    39,    40,    41,    42,
      43,    44,    45,   501,     0,    47,   502,    49,   503,   504,
      52,   505,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,   506,   507,    70,     0,
      71,    72,    73,   508,     0,     0,    76,    77,    78,     0,
       0,   509,    80,     0,     0,     0,     0,    82,   510,    84,
     511,   512,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,    93,    94,    95,    96,     0,    97,     0,     0,
       0,   513,    99,   100,   514,   515,     0,     0,     0,     0,
       0,     0,   103,   104,   105,     0,   107,   108,  1150,     0,
       0,     0,  1151,     0,     0,   115,   516,     0,     0,     0,
       0,   117,   118,   119,   120,   517,   122,   123,   518,     0,
       0,     0,     0,     0,     0,     0,   519,   520,   130,     0,
       0,     0,   131,     0,   132,   521,     0,     0,     0,     0,
       0,     0,   137,     0,   138,   139,   140,   141,   522,   143,
     144,   145,   146,   147,   148,     0,     0,   149,   150,     0,
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
     247,   533,   249,  1153,  1154,  1155,  1156,   414,   415,     0,
      15,    16,    17,   542,    19,    20,    21,   494,   543,   544,
     496,   497,   498,   416,    29,   499,    31,   545,    33,     0,
      34,    35,    36,    37,   546,    39,   547,   548,    42,    43,
      44,    45,   501,     0,    47,   549,    49,   503,   504,    52,
     505,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,   506,   507,    70,     0,    71,
      72,    73,   550,     0,     0,    76,    77,    78,     0,     0,
     509,    80,     0,     0,     0,     0,    82,   510,    84,   511,
     512,    87,    88,  1244,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,     0,    97,     0,     0,     0,
     513,    99,   100,   514,   515,     0,     0,     0,     0,     0,
       0,   103,   104,   105,     0,   107,   108,   109,     0,     0,
       0,     0,     0,     0,   115,   516,     0,     0,     0,     0,
     117,   118,   119,   120,   517,   122,   123,   518,     0,     0,
       0,     0,     0,     0,     0,   519,   520,   130,     0,     0,
       0,   131,     0,   132,   521,     0,     0,     0,     0,     0,
       0,   137,     0,   138,   139,   140,   141,   522,   143,   144,
     145,   146,   147,   148,     0,     0,   149,   150,     0,     0,
     417,   153,   154,   155,   156,   157,   158,   159,   160,   523,
     551,   524,   164,   525,   526,   167,   168,   169,   170,   171,
     172,   527,   174,   528,   529,   530,   178,   179,   531,   532,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,     0,   195,   196,   197,     0,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,     0,     0,     8,     9,   247,
     533,   249,   250,   251,   252,   253,   414,   415,     0,    15,
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
     241,   242,   243,   244,     0,     0,     8,     9,   247,   533,
     249,   250,   251,   252,   253,   414,   415,     0,    15,    16,
      17,     0,    19,    20,    21,   494,     0,     0,   496,   497,
       0,   416,    29,   499,    31,     0,    33,     0,    34,    35,
      36,    37,     0,    39,     0,     0,    42,    43,    44,    45,
     501,     0,    47,     0,    49,     0,     0,    52,   505,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,   506,   507,    70,     0,    71,    72,    73,
       0,     0,     0,    76,    77,    78,     0,     0,   509,    80,
       0,     0,     0,     0,    82,   510,    84,   511,   512,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    96,     0,    97,     0,     0,     0,   513,    99,
     100,   514,   515,     0,     0,     0,     0,     0,     0,   103,
     104,   105,     0,   107,   108,     0,     0,     0,     0,     0,
       0,     0,   115,   516,     0,     0,     0,     0,   117,   118,
     119,   120,   517,   122,   123,   518,     0,     0,     0,     0,
       0,     0,     0,   519,   520,   130,     0,     0,     0,   131,
       0,   132,   521,     0,     0,     0,     0,     0,     0,   137,
       0,   138,   139,   140,   141,   522,   143,   144,   145,   146,
     147,   148,     0,     0,     0,   150,     0,     0,   417,   153,
     154,   155,   156,   157,   158,   159,   160,   523,     0,   524,
     164,   525,   526,   167,   168,   169,   170,   171,   172,   527,
     174,   528,   529,   530,   178,   179,     0,   532,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,     0,   195,   196,   197,     0,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,     0,     0,     0,     0,   247,   533,   249,
     250,   251,   252,   253
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   181,   694,    13,     4,     5,     6,     7,   425,   426,
     313,   832,     4,     5,     6,     7,  1061,   342,   111,   112,
       4,     5,     6,     0,  1085,   678,   768,     4,     5,     6,
       7,   679,   680,   681,   682,  1045,   427,     4,     5,     6,
       7,   135,   871,   788,   262,   261,   917,   593,   628,   629,
     768,     1,  1297,   599,   439,     1,   801,  1314,    75,   277,
    1378,  1379,   930,   931,  1002,   450,   930,   931,   254,   255,
     815,  1135,   626,   627,   628,   629,   467,   468,   952,   725,
    1503,    37,  1411,  1506,     1,    27,    28,   626,   627,     1,
      37,   476,  1327,  1020,    31,     1,    27,    28,    46,    57,
       1,     1,     1,   293,   968,   120,    48,     1,    27,    28,
     110,     1,  1606,     1,    53,    30,    64,    48,   110,    38,
      39,   123,    41,    42,     1,    30,   109,    58,     1,    48,
     109,   144,   968,   110,    76,   227,     1,     1,  1002,    58,
      59,   102,    98,   110,     1,    76,   227,   158,   229,    96,
      81,    98,   245,   246,  1022,    40,   284,    76,  1022,   109,
      45,    46,    81,   109,     1,    98,   171,  1035,   109,    54,
     132,  1035,   114,     0,     1,   120,    61,   102,    63,    64,
     133,    25,   113,   114,   115,  1673,   158,    72,     8,   155,
     115,    35,   131,   149,   113,   114,   115,     0,     1,   204,
     293,   657,   149,   659,   660,   162,   662,   112,   664,   192,
     109,   190,   227,   179,    99,   109,   672,   673,    62,    38,
      39,   126,    41,    42,   316,   109,     1,   188,  1546,   974,
     420,    98,   109,   235,   424,   316,   109,   199,   171,   192,
      59,   189,     1,   162,   109,   109,   151,   162,   189,  1294,
     155,   345,   109,   158,   254,   255,     1,  1318,   258,  1747,
    1081,   219,   275,  1757,  1135,  1136,  1327,   570,     1,     1,
    1280,  1516,   109,   109,   179,   192,  1605,   254,   255,   216,
     192,   258,   109,  1028,  1519,  1027,   192,  1151,     1,  1034,
     189,   192,   192,   293,   309,   189,   115,  1235,   256,  1722,
     880,   881,   192,   222,   192,     1,   109,  1025,   954,  1027,
       1,     1,   189,  1187,   187,  1151,   293,  1244,   446,   275,
       1,   254,   255,  1387,   257,   189,   149,   420,   275,  1047,
     275,   424,   189,   350,   109,    75,   353,     1,     1,   878,
     879,   274,   227,   162,   263,   736,  1769,   289,  1771,    89,
     109,   235,   189,   286,     1,   297,   261,   177,   289,   186,
       1,     1,   455,     1,   109,   315,   297,   313,   558,   149,
     289,  1235,   465,   113,   305,     1,   109,   109,   297,   109,
      95,   102,   475,   186,   219,   125,   305,   127,  1706,   482,
     483,   258,   259,   155,    30,   786,   109,   782,   491,   155,
     785,   237,   139,   222,  1272,   623,   624,   144,  1272,   120,
     626,   627,   227,   109,   189,   633,   109,   232,   109,   109,
     420,   256,    96,   179,   424,    78,   102,     5,   109,   615,
     189,     9,  1296,   155,   319,   320,   321,    96,   156,    96,
     158,   186,  1760,   420,   263,   109,   109,   424,   109,   109,
     212,   451,   275,   453,   186,   645,   189,   913,  1519,   451,
     190,   453,   109,   109,    56,   558,    58,   188,   109,   109,
     185,   109,   160,   186,   451,   149,   453,    98,   189,   115,
     480,   574,   575,   109,   451,   485,   453,  1744,   480,  1234,
     178,   187,   109,   485,   587,   275,   189,   120,   189,   189,
     917,   316,   155,   480,  1246,   186,   109,   227,   485,   229,
     102,   109,   188,   480,   607,   608,  1387,    46,   485,    48,
     102,   239,   186,   186,   124,  1396,   162,    30,   189,   189,
     947,  1360,    46,   115,    48,  1364,  1407,  1255,  1230,   186,
    1120,  1121,  1122,   189,  1789,   186,   186,   125,   186,   127,
     171,  1419,    81,    27,    28,  1419,   120,   135,   558,  1105,
     186,   220,   221,   220,   221,   565,  1120,  1121,  1122,   109,
     223,   224,   189,   565,   109,    98,   235,   155,   235,   108,
     132,   558,   108,   271,   975,   976,   189,   109,   565,   980,
     278,   189,   109,   138,   108,   120,   316,    43,   565,   160,
     288,    47,   695,   129,   698,   699,    52,   700,   608,   112,
     350,   621,   203,   353,   155,   615,   608,   178,  1628,  1010,
     156,   212,   158,   126,   188,    71,   626,   627,   628,   629,
    1016,   608,  1018,   254,   255,   158,   257,  1382,   615,  1503,
     114,   170,  1506,   264,    30,   645,   186,   199,   151,   626,
     627,   628,   629,   274,   189,    43,   170,    98,   203,    47,
      98,   253,   878,   188,    52,   286,   884,   189,   645,    43,
     888,   212,   189,    47,   266,   158,   268,   115,    52,   869,
     119,    96,  1068,    71,  1070,   158,     5,   279,   280,   281,
       9,   283,   432,   285,   150,   435,  1517,    71,  1743,   439,
      98,  1522,   442,   443,  1575,    96,   896,    55,   149,   148,
     450,   167,    60,    96,   124,    96,   456,   457,  1135,  1136,
     158,   461,   161,    55,   170,  1467,   112,   173,    60,   469,
     823,   824,   825,     9,   827,    96,   476,   477,   478,   479,
     126,   156,   188,   158,   484,  1398,   158,    79,     9,    10,
      98,   149,   492,    29,     9,    10,   139,   196,   149,    96,
    1452,   144,     1,   144,     3,   151,    98,   188,   214,   155,
       1,   108,   158,  1641,   249,   250,   869,  1641,   778,     9,
      10,   138,   170,   144,   124,   173,   778,  1367,   120,     1,
     234,   212,   236,   179,   778,   152,   170,   272,   538,   173,
     188,   778,    98,    34,   188,   146,   125,   144,   127,   809,
     810,   778,  1137,   553,   188,   188,   135,   809,   810,   115,
     158,  1689,    34,  1691,   564,  1689,   214,  1691,   212,    68,
     188,  1652,   809,   810,    73,  1656,   155,   178,    50,   212,
     214,     9,   809,   810,   105,   676,   677,     9,    10,   125,
     105,   127,    34,   593,   212,   196,   150,   124,  1722,   599,
     136,    29,   158,   603,   125,   160,   127,   160,    50,   869,
     125,   168,   127,   167,   158,   105,  1734,  1735,   188,   155,
     890,   120,   120,   178,  1275,   178,  1754,   184,   155,   158,
    1754,   158,   869,  1111,   155,   125,   896,   127,   159,  1117,
     155,    97,   212,   188,   159,  1769,   201,  1771,   201,    98,
     158,  1559,   108,  1566,  1567,   176,  1608,  1738,  1776,   896,
    1110,   176,   118,   139,  1782,   155,   115,   212,   271,   159,
     184,   139,   301,   129,  1114,   278,   197,   184,    96,   155,
     965,   310,   197,   105,   198,   288,   176,   155,   270,   102,
     108,   198,   977,   102,   215,   277,   102,   125,   102,   127,
     215,  1706,   115,   125,   265,   127,   115,   197,   136,   115,
    1387,   115,   234,   265,   236,   276,   279,   280,   281,  1396,
     158,    55,   285,  1374,   276,   215,    60,   155,   155,   139,
    1407,   158,   732,   155,   144,   701,   630,   159,   704,   155,
     634,   707,   158,   124,   155,   349,   746,   158,   352,   124,
     750,   751,    75,   155,   176,   124,   158,   193,   194,  1711,
     223,   224,   225,   120,  1677,  1678,    89,   130,   131,   134,
     130,   131,   772,   124,   774,   197,   155,   142,   143,   155,
     145,  1134,   782,   685,   686,   785,   683,   684,   153,   789,
     113,   124,   157,   215,   159,   124,  1359,  1228,  1229,   164,
    1596,  1597,   125,  1063,   127,   124,  1758,   124,   155,   158,
     218,  1063,   120,   243,   243,   158,   181,   155,   244,   316,
       0,   192,    94,   169,  1274,   101,  1063,   251,    51,   202,
     103,   831,   156,  1484,   104,   147,  1063,  1750,   158,   195,
     205,   206,   207,   208,   209,   210,   186,   186,    30,  1119,
    1110,   186,    48,   154,   186,   120,   248,   120,   306,   189,
    1120,  1121,  1122,   286,   155,   286,     1,   120,   109,   144,
     155,   871,   155,  1110,   189,   189,   158,   158,  1830,   158,
    1832,   158,   144,  1120,  1121,  1122,   186,   158,   123,   158,
    1842,   158,   158,    36,   155,    17,    30,   189,  1575,  1550,
     900,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   216,   233,     3,   232,   120,  1356,   172,   192,   247,
     170,   172,    72,   233,   192,    96,    96,    96,    30,   151,
     930,   931,   932,   933,   109,   109,   162,   162,   129,   134,
      96,   248,   301,   144,   120,   134,   186,   186,   109,    96,
      98,   189,   189,    46,    98,   189,   189,   189,   189,   186,
      96,   155,   186,   155,   192,   155,   144,   155,   968,   155,
     155,   227,    34,   233,   172,   239,   235,   134,  1238,   120,
     144,    96,   982,    30,   288,   229,  1238,    96,   301,   155,
     129,   120,   120,    96,  1238,   149,   200,   134,   256,   186,
     162,  1238,   134,    98,   155,   102,   120,  1007,   102,   149,
     155,  1238,   123,   186,  1274,   192,  1016,   144,  1018,   186,
    1020,    36,  1022,    30,   155,  1285,   247,   350,   120,    81,
     353,   109,   109,  1285,   158,  1035,   146,  1274,   287,   269,
     260,  1285,   158,   262,  1304,   158,  1496,    30,  1285,    30,
     158,   158,  1304,   158,   158,    30,   308,   229,  1285,   288,
    1304,   146,   192,   189,  1324,   149,   189,  1304,  1068,   189,
    1070,  1331,  1324,   289,   129,   149,   149,  1304,   120,  1331,
     120,    79,   109,   189,   144,   186,   102,  1324,   200,  1539,
     189,   189,     7,   134,  1331,    98,   192,  1324,   155,   188,
     158,   239,   235,  1363,  1331,  1105,   108,   158,   431,   432,
     235,  1363,   435,   158,   235,   149,   439,   235,   189,   442,
     443,   284,    80,   288,   189,   189,  1363,   450,   189,    30,
    1130,    30,   109,   456,   457,   252,   189,   172,   461,   189,
     189,   189,   186,   149,   149,    98,   469,   186,   128,   128,
     188,  1151,   252,   476,   477,   478,   479,   188,   188,   318,
     186,   484,   186,   186,   186,   155,   144,    96,   189,   492,
      30,   259,    98,   172,    55,   189,  1626,   149,    96,   199,
     108,    30,   273,  1536,  1537,  1538,    96,  1637,  1638,   109,
    1640,   267,   109,   120,   227,   282,   120,   188,  1648,    96,
      96,   120,   199,   289,   199,    95,   200,   199,   227,   120,
     227,   185,   188,   120,   295,   538,   201,   188,   120,   289,
    1190,   258,   258,   735,   307,   307,   426,   307,   969,   308,
     553,   446,   261,   308,  1036,  1758,  1496,  1235,  1711,   308,
     872,   564,  1033,   461,  1244,   791,  1477,  1264,  1248,  1383,
    1126,  1381,  1378,  1286,   553,  1291,  1294,  1299,   655,  1496,
     656,   675,   933,  1263,   709,   337,  1318,   832,  1782,  1776,
     454,   454,  1272,  1018,  1189,  1361,  1350,  1396,  1360,  1539,
     603,  1731,  1575,  1136,  1407,  1400,  1286,  1001,  1572,  1145,
    1212,  1442,  1599,    -1,  1397,   597,  1296,    -1,    -1,    -1,
      -1,    -1,  1539,    -1,    -1,    -1,    -1,    -1,    -1,   110,
      -1,    -1,    -1,    -1,    -1,    -1,  1669,    -1,    -1,    -1,
    1770,    -1,    -1,    -1,    -1,  1325,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1687,    -1,    -1,    -1,  1788,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1350,    -1,    -1,  1803,    -1,    -1,    -1,    -1,    -1,    -1,
    1360,    -1,    -1,    -1,  1364,    -1,  1626,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1824,    -1,    -1,  1637,  1638,    -1,
    1640,    -1,    -1,  1833,    -1,    -1,    -1,    -1,  1648,  1626,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1637,  1638,    -1,  1640,    -1,    -1,   729,    -1,    -1,   732,
      -1,  1648,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1419,
      -1,    -1,    -1,   746,    -1,    -1,    -1,   750,   751,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1448,   772,
      -1,   774,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   782,
      -1,    -1,   785,    -1,    -1,    -1,   789,    -1,    -1,    -1,
      -1,  1731,    -1,    -1,  1474,  1475,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1731,    -1,    -1,    -1,    -1,    -1,
    1500,    -1,    -1,  1503,    -1,    -1,  1506,    -1,   831,    -1,
    1770,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1518,    -1,
      -1,    -1,    -1,  1523,    -1,    -1,    -1,    -1,  1788,    -1,
      -1,    -1,    -1,  1770,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1803,    -1,    -1,    -1,    -1,   871,    -1,
      -1,  1788,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1824,    -1,  1803,    -1,    -1,    -1,
      -1,    -1,    -1,  1833,    -1,    -1,    -1,   900,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1824,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1833,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   930,   931,   932,
     933,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1641,  1642,    -1,  1644,   968,  1646,    -1,    -1,    -1,
      -1,    -1,    -1,  1653,    -1,    -1,    -1,    -1,    -1,   982,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1007,    -1,    -1,    -1,    -1,  1689,
      -1,  1691,    -1,  1016,    -1,  1018,    -1,  1020,    -1,  1022,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1707,    -1,    -1,
    1710,    -1,  1035,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1722,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1733,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1068,    -1,  1070,    -1,    -1,
      -1,    -1,    -1,    -1,  1754,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1762,    -1,   565,    -1,    -1,  1767,    -1,  1769,
      -1,  1771,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     591,   592,    -1,    -1,   595,   596,   597,   598,    -1,   600,
    1800,    -1,    -1,    -1,    -1,   606,    -1,  1130,    -1,    -1,
      -1,    -1,    -1,   614,    -1,    -1,    -1,    -1,    -1,    -1,
    1820,    -1,    -1,    -1,    -1,  1825,    -1,    -1,  1151,    -1,
      -1,    -1,    -1,    -1,    -1,   636,   637,  1837,    -1,    -1,
    1840,    -1,    -1,    -1,   645,   646,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   706,    -1,    -1,   709,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1244,    -1,    -1,    -1,  1248,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1263,    -1,    -1,    -1,    -1,    -1,    -1,   748,    -1,  1272,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1286,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1296,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   790,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1325,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   816,    -1,    -1,    -1,   820,
     821,    -1,    -1,    -1,    -1,    -1,    -1,  1350,   829,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1360,    -1,    -1,
      -1,  1364,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   896,  1419,    -1,    -1,    -1,
      -1,   902,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1448,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1474,  1475,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   970,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1500,    -1,    -1,
    1503,    -1,    -1,  1506,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1518,    -1,    -1,    -1,    -1,
    1523,    -1,    -1,    -1,  1005,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1024,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1046,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1057,  1058,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1072,    -1,    -1,  1075,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1092,  1093,  1094,    -1,  1096,  1097,  1098,  1099,  1100,
    1101,  1102,  1103,  1104,    -1,    -1,  1107,  1108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1116,    -1,    -1,  1641,  1642,
      -1,  1644,    -1,  1646,    -1,  1126,    -1,    -1,    -1,    -1,
    1653,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1689,    -1,  1691,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1177,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1707,    -1,    -1,  1710,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1722,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1733,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1754,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1762,
      -1,    -1,    -1,    -1,  1767,    -1,  1769,    -1,  1771,  1250,
      -1,  1252,    -1,  1254,    -1,    -1,  1257,    -1,    -1,    -1,
      -1,  1262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1274,    -1,    -1,    -1,  1800,    -1,    -1,
      -1,    -1,  1283,    -1,    -1,    -1,    -1,    -1,  1289,  1290,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1820,    -1,    -1,
      -1,    -1,  1825,    -1,    -1,    -1,    -1,  1308,    -1,    -1,
    1311,    -1,    -1,    -1,  1837,    -1,    -1,  1840,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1381,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1461,    -1,    -1,    -1,  1465,    -1,    -1,    -1,  1469,    -1,
    1471,    -1,  1473,    -1,    -1,    -1,    -1,    -1,  1479,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1487,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1495,  1496,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1515,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1527,  1528,  1529,  1530,
      -1,  1532,  1533,    -1,  1535,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1614,    -1,  1616,    -1,    -1,  1619,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1627,    -1,    -1,    -1,
      -1,  1632,  1633,    -1,    -1,    -1,    -1,    -1,    -1,  1640,
      -1,    -1,    -1,    -1,  1645,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1662,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1674,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1714,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1727,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1770,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    -1,    -1,  1798,    -1,    -1,
      -1,    -1,  1803,    -1,    11,    12,    -1,  1808,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,  1823,    30,    -1,    -1,  1827,    34,    35,    -1,
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
     317,   318,   319,   320,   321,   322,     0,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,   100,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,   126,    -1,   128,   129,   130,   131,    -1,   133,
      -1,    -1,    -1,   137,   138,   139,   140,   141,    -1,    -1,
      -1,    -1,    -1,    -1,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,   193,
     194,    -1,   196,    -1,   198,    -1,   200,   201,   202,   203,
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
     314,    -1,   316,   317,   318,   319,   320,   321,   322,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,   100,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,   126,    -1,   128,   129,   130,   131,
      -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,   141,
      -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,   151,
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
     162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,   193,   194,    -1,   196,    -1,   198,    -1,   200,   201,
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
     322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
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
     310,   311,   312,    -1,   314,    -1,   316,   317,   318,   319,
     320,   321,   322,     0,     1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    71,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    96,
      97,    98,    -1,    -1,   101,   102,   103,   104,    -1,    -1,
      -1,   108,   109,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,    -1,   134,    -1,    -1,
      -1,   138,    -1,    -1,    -1,   142,   143,    -1,   145,    -1,
     147,   148,    -1,    -1,    -1,   152,   153,    -1,    -1,   156,
     157,   158,   159,   160,   161,    -1,    -1,   164,    -1,    -1,
      -1,    -1,   169,   170,    -1,    -1,   173,    -1,    -1,    -1,
      -1,   178,    -1,    -1,   181,    -1,    -1,    -1,    -1,   186,
     187,   188,   189,   190,    -1,   192,   193,   194,   195,   196,
      -1,    -1,    -1,    -1,   201,   202,   203,    -1,   205,   206,
     207,   208,   209,   210,    -1,   212,    -1,   214,    -1,    -1,
      -1,    -1,   219,   220,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   235,    -1,
     237,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   251,    -1,    -1,    -1,    -1,   256,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,   313,    -1,   315,    34,
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
      -1,   316,   317,   318,   319,   320,   321,   322,   323,   324,
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
     321,   322,    -1,   324,    11,    12,    -1,    -1,    -1,    -1,
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
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,   186,
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
      -1,   186,    -1,   188,    -1,   190,   191,    -1,   193,   194,
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
     179,    -1,    -1,   182,   183,   184,    -1,    -1,   187,   188,
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
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
      -1,   314,   315,   316,   317,   318,   319,   320,   321,   322,
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
     159,    -1,   161,   162,    -1,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
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
      -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,   196,
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
      -1,    -1,   137,    -1,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,   148,   149,   150,   151,    -1,   153,   154,
     155,   156,    -1,   158,   159,    -1,   161,   162,    -1,    -1,
      -1,    -1,   167,   168,   169,   170,   171,   172,   173,   174,
      -1,   176,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,
      -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,
      -1,   196,    -1,   198,    -1,   200,    -1,   202,    -1,   204,
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
      -1,    11,    12,   316,   317,   318,   319,   320,   321,   322,
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
     320,   321,   322,    25,    26,    -1,    -1,    -1,    30,    -1,
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
      -1,    -1,    16,    -1,   316,   317,   318,   319,   320,   321,
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
      -1,    -1,   316,   317,   318,   319,   320,   321,   322,    18,
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
      -1,   158,   159,    -1,   161,   162,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,    -1,
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
     317,   318,   319,   320,   321,   322,    25,    26,    -1,    -1,
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
      -1,    -1,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     131,    -1,   133,    -1,    -1,    -1,   137,   138,   139,   140,
     141,    -1,    -1,    -1,    -1,    -1,    -1,   148,   149,   150,
      -1,   152,   153,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,   170,
     171,   172,   173,   174,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,   190,
     191,    -1,    -1,    -1,    -1,   196,    -1,   198,    -1,   200,
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
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
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
      -1,    -1,    -1,    -1,   161,   162,    -1,    -1,    -1,    -1,
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
     308,   309,   310,   311,    -1,    -1,    25,    26,   316,   317,
     318,   319,   320,   321,   322,    34,    35,    -1,    37,    38,
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
     219,   220,   221,   222,   223,   224,   225,   226,    -1,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,    -1,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,    -1,   261,   262,   263,    -1,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,    -1,    -1,    -1,    -1,   316,   317,   318,
     319,   320,   321,   322
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
     538,   539,   541,   542,   543,   544,   545,   546,   547,   548,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   569,   570,   571,   572,   577,   578,   579,   580,   581,
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
     565,   566,   414,   189,   196,   659,   428,   429,   659,   286,
     286,   428,   120,   435,   120,   189,   383,   384,   155,   399,
     414,     1,   162,   657,   115,   162,   357,   657,   659,   120,
     144,   109,   189,   414,    30,   189,   658,   659,   659,   452,
     453,   659,   394,   189,   414,   414,   567,   659,   394,   155,
     155,   414,   189,   196,   659,   659,   144,   452,   186,   186,
     123,   109,   186,   158,   158,   158,   659,   155,   187,   188,
     189,    36,   526,   527,   528,   414,   414,     8,   177,    17,
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
     511,   189,   415,   521,   151,   189,   521,   109,   189,   189,
     109,   109,   382,    30,   660,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   364,   365,   366,    96,   139,
     144,   370,   371,   372,   659,   162,   162,   364,   657,   129,
     134,    56,    58,   102,   253,   266,   268,   279,   280,   281,
     283,   285,   617,   618,   619,   620,   621,   622,   629,   635,
     636,   248,    96,   301,   659,   144,   415,   120,   659,   659,
     134,   186,   186,   189,   189,   186,   109,   189,   109,   189,
     109,    37,    96,    98,   149,   430,   431,   549,   659,    57,
     219,   256,   420,   421,   659,    96,   109,   189,   393,   189,
     658,    98,    46,   658,   657,    98,   144,   549,   659,   415,
     434,   186,   189,   189,   189,   189,   109,   190,   149,   549,
     186,   189,   189,   155,   186,   394,   394,   186,   109,   189,
     109,   189,   144,   549,   415,   190,   415,   415,   414,   414,
     414,   659,   527,   528,   132,   199,   186,   186,   186,   133,
     192,    96,   220,   221,   235,    96,   220,   221,   235,   235,
     235,    96,    96,   239,   227,   233,   109,   237,   144,   192,
     189,   414,   186,   507,   589,   413,   235,   361,    34,    34,
     192,   338,   192,   115,   396,   659,   172,   415,   445,   446,
     120,   441,   442,   473,   155,   158,   261,   494,   513,   590,
     593,   594,   595,   596,   597,   601,   603,   605,   606,    48,
     154,   158,   213,   319,   320,   321,   322,   550,   552,   554,
     556,   573,   574,   575,   576,   653,   654,   655,   656,   659,
     550,   485,   555,   659,   485,   186,   187,   109,   189,   189,
     513,   150,   167,   150,   167,   139,   399,   382,   365,   134,
     552,   372,   415,   549,   657,   657,   130,   131,   657,   279,
     280,   281,   285,   659,   265,   276,   265,   276,    30,   288,
      98,   115,   158,   623,   626,   617,    40,    45,    54,    61,
      63,    72,    99,   227,   319,   320,   321,   386,   556,   653,
     229,   301,   310,   415,   659,    96,   301,   657,   155,   567,
     568,   659,   567,   568,   120,   429,   129,   550,   120,   415,
     149,   431,   149,    37,   149,   430,   431,   149,   549,   256,
      55,    60,    79,   120,   430,   436,   437,   438,   421,   549,
     550,   384,    96,   186,   200,   134,   356,   657,   162,   134,
      98,   356,   415,   144,   431,   155,   120,   415,   415,   149,
     102,   455,   456,   457,   459,   460,   102,   463,   464,   465,
     466,   394,   186,   186,   155,   567,   567,   415,   144,   192,
     415,   123,   189,   189,   189,    36,   528,   132,   199,     9,
      10,   105,   125,   127,   155,   197,   523,   525,   536,   537,
     540,   155,    30,   234,   236,   415,   415,   415,   234,   236,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   509,
     120,   415,   415,    49,    74,    75,   246,   396,   416,   426,
     247,   586,   587,   155,   212,   397,   415,   192,   115,   391,
     391,   391,   445,    97,   108,   118,   129,   447,   448,   449,
     450,   109,   659,   109,   414,   590,   597,   155,   287,   475,
     642,    98,   171,   254,   255,   257,   264,   274,   286,   591,
     592,   611,   612,   613,   614,   637,   640,   260,   262,   598,
     616,   269,   602,   638,   249,   250,   272,   607,   608,   158,
     158,   552,   158,   158,   158,   158,   158,   146,   178,   196,
     551,   146,   415,   139,   399,   569,   371,   288,    30,    98,
     115,   158,   630,    30,   623,   551,   551,   496,   289,   308,
     549,   386,   229,   192,   393,   189,   189,   146,   189,   189,
     429,   149,   430,   659,   415,   149,   415,   129,   415,   149,
     431,   149,   415,   149,   120,   120,   415,   659,   438,    79,
     550,   396,   415,   657,   109,   356,   415,   144,   393,   453,
     415,   415,   115,   456,   457,   102,   188,   115,   457,   460,
     120,   467,   550,   102,   115,   464,   102,   115,   466,   186,
     393,   189,   189,   415,   415,   200,   463,   134,   197,   525,
       7,   394,   659,   197,   536,   394,   192,   235,   235,   235,
     235,    98,   239,   239,   584,   188,   158,   158,   158,   188,
     589,   587,   507,   657,   130,   131,   449,   450,   450,   446,
     108,   144,   443,   549,   442,   186,   189,   590,   604,   252,
     219,   256,   270,   277,   641,    98,   258,   259,   639,   252,
     594,   641,   477,   611,   595,   149,   284,   599,   600,   639,
     288,   610,    80,   609,   189,   196,   550,   553,   189,   189,
     189,   189,   189,   189,   189,    30,   138,   203,   632,   633,
     634,    30,   631,   632,   273,   627,   109,   624,   172,   659,
     259,   496,   186,   415,   149,   415,   149,   430,   415,   149,
     415,   415,   659,   659,   437,   415,   128,   128,    98,   657,
     415,   186,   188,   188,   415,   396,   415,   188,   188,   659,
     188,   212,   120,   467,   120,   188,   120,   467,   188,   186,
     115,   528,   659,   197,   186,   528,   659,   186,   415,   415,
     415,   415,   318,   415,   415,   415,   414,   414,   414,   155,
     588,   450,   657,   415,   144,   186,   479,    53,   131,   477,
     477,   271,   278,   288,   615,   615,   596,   155,   282,    96,
     189,   109,   189,   630,   630,   634,   109,   189,    30,   628,
     639,   625,   626,   189,   388,   389,   496,   120,   227,   309,
     289,   172,   415,   415,   149,   415,    55,   396,   415,   356,
     415,   396,    96,   396,   415,   550,   659,   188,   659,   415,
     659,   188,   396,   120,    95,   185,   529,   528,   659,   199,
     528,   415,   189,   189,   189,   414,   443,   415,   477,   477,
     201,   414,   550,   550,    96,    30,   267,   109,   109,   450,
     549,   659,   120,   227,   659,   388,   415,   120,   467,    96,
     188,    96,   659,     5,   135,   532,   533,   535,   537,    29,
     136,   530,   531,   534,   537,   199,   528,   199,   200,   463,
     186,   443,   477,   186,   550,   626,   389,   450,   307,   659,
     120,   227,   659,   188,   467,   396,   415,   467,   188,    95,
     135,   535,   185,   136,   534,   199,   115,   415,   307,   659,
     120,   396,   415,   188,   188,   120,   295,   307,   659,   659,
     308,   415,   308,   188,   496,   496,   201,   289,   659,   227,
     120,   659,   308,   496
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
     519,   520,   520,   521,   521,   522,   522,   523,   523,   523,
     524,   524,   524,   524,   524,   524,   525,   525,   526,   526,
     527,   528,   528,   529,   529,   530,   530,   531,   531,   531,
     531,   532,   532,   533,   533,   533,   533,   534,   534,   535,
     535,   536,   536,   536,   536,   537,   537,   537,   537,   538,
     538,   539,   539,   540,   541,   541,   541,   541,   541,   541,
     541,   542,   543,   543,   544,   544,   545,   546,   547,   547,
     548,   548,   549,   550,   550,   550,   551,   551,   551,   552,
     552,   552,   552,   552,   552,   552,   553,   553,   554,   555,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     557,   558,   558,   558,   559,   560,   561,   562,   562,   562,
     563,   563,   563,   563,   563,   564,   565,   565,   565,   565,
     565,   565,   565,   566,   567,   568,   569,   570,   570,   571,
     572,   573,   573,   574,   575,   575,   576,   577,   577,   577,
     578,   578,   578,   578,   578,   578,   578,   578,   578,   578,
     579,   579,   580,   580,   581,   582,   583,   583,   584,   585,
     586,   586,   587,   588,   589,   589,   590,   591,   591,   592,
     592,   593,   593,   594,   594,   595,   595,   596,   596,   597,
     598,   598,   599,   599,   600,   601,   601,   601,   602,   602,
     603,   604,   604,   605,   606,   606,   607,   607,   608,   608,
     608,   609,   609,   610,   610,   611,   611,   611,   611,   611,
     612,   613,   614,   615,   615,   615,   616,   616,   617,   617,
     617,   617,   617,   617,   617,   617,   618,   618,   618,   618,
     619,   619,   620,   621,   621,   622,   622,   622,   623,   623,
     624,   624,   625,   625,   626,   627,   627,   628,   628,   629,
     629,   629,   630,   630,   631,   631,   632,   632,   633,   633,
     634,   634,   635,   636,   636,   637,   637,   637,   638,   639,
     639,   639,   639,   640,   640,   641,   641,   642,   643,   643,
     644,   644,   645,   645,   646,   647,   647,   648,   648,   648,
     649,   650,   651,   652,   653,   653,   653,   654,   655,   656,
     657,   658,   658,   659,   659,   659,   659,   659,   659,   659,
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
     660,   660,   660,   660,   660,   660,   660,   660,   660,   660,
     660,   660,   660,   660,   660,   660,   661
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
       2,     3,     2,     3,     3,     3,     5,     5,     5,     8,
       5,     3,     5,     7,     1,     1,     1,     3,     3,     3,
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
       1,     1,     1,     1,     1,     1,     1
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
     569,    -1,    82,    -1,    90,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    91,    -1,    87,    -1,    88,    -1,
      89,    -1,    34,    58,   659,    30,    -1,    34,   263,   616,
      -1,    34,   113,   154,   370,    -1,    96,   552,   371,    -1,
     371,    -1,   372,    -1,   139,    -1,   139,   372,    -1,   144,
     415,    -1,    34,   374,   144,   415,    -1,    34,   374,   139,
      -1,    34,   374,   139,   144,   415,    -1,   114,   120,   659,
      -1,   114,   120,   659,   549,    -1,   375,   114,   120,   659,
      -1,   375,   114,   120,   659,   549,    -1,   376,    -1,   375,
     376,    -1,    27,    -1,    27,   158,   377,   189,    -1,    28,
      -1,    28,   158,   377,   189,    -1,   513,    -1,   377,   109,
     513,    -1,    34,   379,    -1,    34,   375,   379,    -1,   380,
      -1,   381,    -1,    48,   660,   382,   399,    -1,    48,   660,
     382,   139,    -1,    76,    48,   660,   382,   399,    -1,    76,
      48,   660,   382,   139,    -1,   158,   189,    -1,   158,   383,
     189,    -1,   158,   189,    96,   550,    -1,   158,   383,   189,
      96,   550,    -1,   384,    -1,   383,   109,   384,    -1,   120,
     659,    -1,   120,   659,   549,    -1,    34,   289,   659,    -1,
      34,   289,   659,    96,   386,    -1,    34,   375,   289,   659,
      -1,    34,   375,   289,   659,    96,   386,    -1,   556,    -1,
     556,   551,    -1,   653,    -1,   653,   551,    -1,    34,   297,
     659,   301,   229,   496,   172,   388,    -1,    34,   375,   297,
     659,   301,   229,   496,   172,   388,    -1,   389,    -1,   388,
     109,   389,    -1,   496,    -1,   496,   549,    -1,   496,   450,
      -1,   496,   549,   450,    -1,    34,   305,   306,   659,   301,
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
     659,    -1,   120,   659,   549,    -1,   120,   659,   144,   415,
      -1,   120,   659,   549,   144,   415,    -1,   120,   659,   144,
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
      37,   129,   149,   415,    -1,   659,   549,   149,   415,    -1,
     659,   549,    37,   129,   149,   415,    -1,   659,   430,   149,
     415,    -1,   659,    37,   129,   430,   149,   415,    -1,   659,
     549,   430,   149,   415,    -1,   659,   549,    37,   129,   430,
     149,   415,    -1,   659,   431,   149,   415,    -1,   659,   549,
     431,   149,   415,    -1,   659,   430,   431,   149,   415,    -1,
     659,   549,   430,   431,   149,   415,    -1,    98,   120,   659,
      -1,   275,   120,   659,    -1,    52,   433,    -1,   434,    -1,
     433,   109,   434,    -1,   120,   659,   144,   415,    -1,   120,
     659,   549,   144,   415,    -1,   431,   144,   415,    -1,   120,
     659,   549,   431,   144,   415,    -1,   120,   659,   149,   415,
      -1,   120,   659,   549,   149,   415,    -1,   437,    -1,   120,
     659,    -1,   120,   659,   437,    -1,   430,    -1,   430,   438,
      -1,   438,    -1,    60,   120,   659,    55,   120,   659,    -1,
      55,   120,   659,    -1,    60,   120,   659,    -1,   214,   415,
      -1,   173,   172,   441,    -1,   442,    -1,   441,   109,   442,
      -1,   120,   659,    -1,   120,   659,   144,   415,    -1,   120,
     659,   549,   144,   415,    -1,   120,   659,   549,   144,   415,
     443,    -1,   120,   659,   144,   415,   443,    -1,   120,   659,
     443,    -1,   108,   657,    -1,   170,   172,   445,    -1,    71,
     170,   172,   445,    -1,   446,    -1,   445,   109,   446,    -1,
     415,    -1,   415,   447,    -1,   448,    -1,   449,    -1,   450,
      -1,   448,   449,    -1,   448,   450,    -1,   449,   450,    -1,
     448,   449,   450,    -1,    97,    -1,   118,    -1,   129,   130,
      -1,   129,   131,    -1,   108,   657,    -1,    69,   120,   452,
     190,   415,    -1,   137,   120,   452,   190,   415,    -1,   453,
      -1,   452,   109,   120,   453,    -1,   659,   149,   415,    -1,
     659,   549,   149,   415,    -1,    74,   158,   414,   189,   455,
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
     467,   188,   396,    -1,   550,    -1,   467,   212,   550,    -1,
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
     482,    51,   233,   550,    -1,   483,    -1,   483,   202,    96,
     550,    -1,   484,    -1,   484,   103,    96,   485,    -1,   486,
      -1,   486,   104,    96,   485,    -1,   555,    -1,   555,   146,
      -1,   488,    -1,   487,   488,    -1,   178,    -1,   160,    -1,
     487,   178,    -1,   487,   160,    -1,   492,    -1,   489,    -1,
     493,    -1,   496,    -1,   489,   195,   496,    -1,   205,    -1,
     210,    -1,   209,    -1,   208,    -1,   207,    -1,   206,    -1,
     153,    -1,   181,    -1,   142,    -1,    77,   155,   394,   186,
      -1,    77,   224,   155,   394,   186,    -1,    77,   223,   155,
     394,   186,    -1,    77,    78,   567,   155,   394,   186,    -1,
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
      -1,   556,    -1,   507,    -1,   659,    -1,   508,    -1,   196,
      -1,    11,    -1,    12,    -1,    20,    -1,   512,    -1,   509,
     510,    -1,   509,   158,   189,    -1,   509,   158,   521,   189,
      -1,   511,    -1,   510,   511,    -1,   156,   414,   187,    -1,
     513,    -1,   515,    -1,   516,    -1,   517,    -1,   520,    -1,
     522,    -1,   518,    -1,   519,    -1,   570,    -1,   398,    -1,
     646,    -1,   643,    -1,   644,    -1,   645,    -1,   514,    -1,
     569,    -1,   112,    -1,   151,    -1,   126,    -1,   120,   659,
      -1,   158,   189,    -1,   158,   414,   189,    -1,   121,    -1,
     171,   155,   414,   186,    -1,   204,   155,   414,   186,    -1,
     660,   158,   189,    -1,   660,   158,   521,   189,    -1,   415,
      -1,   521,   109,   415,    -1,   523,    -1,   541,    -1,   524,
      -1,   538,    -1,   539,    -1,   159,   659,   528,   132,    -1,
     159,   659,   528,   199,   197,   659,   528,   199,    -1,   159,
     659,   526,   528,   132,    -1,   159,   659,   526,   528,   199,
     197,   659,   528,   199,    -1,   159,   659,   528,   199,   525,
     197,   659,   528,   199,    -1,   159,   659,   526,   528,   199,
     525,   197,   659,   528,   199,    -1,   536,    -1,   525,   536,
      -1,   527,    -1,   526,   527,    -1,    36,   659,   528,   134,
     528,   529,    -1,    -1,    36,    -1,   185,   530,   185,    -1,
      95,   532,    95,    -1,    -1,   531,    -1,   136,    -1,   534,
      -1,   531,   136,    -1,   531,   534,    -1,    -1,   533,    -1,
     135,    -1,   535,    -1,   533,   135,    -1,   533,   535,    -1,
      29,    -1,   537,    -1,     5,    -1,   537,    -1,   523,    -1,
      10,    -1,   540,    -1,   537,    -1,     9,    -1,   125,    -1,
     127,    -1,   155,   394,   186,    -1,   215,    31,   216,    -1,
     215,   216,    -1,   176,   658,   177,    -1,   176,   658,     8,
      -1,   105,     7,    -1,   542,    -1,   543,    -1,   544,    -1,
     545,    -1,   546,    -1,   547,    -1,   548,    -1,    44,   155,
     394,   186,    -1,    21,   393,   186,    -1,    46,   155,   414,
     186,   155,   393,   186,    -1,    22,   393,   186,    -1,    99,
     155,   414,   186,   155,   393,   186,    -1,    72,   155,   394,
     186,    -1,    40,   155,   394,   186,    -1,    23,   393,   186,
      -1,    61,   155,   414,   186,   155,   393,   186,    -1,    24,
     394,   186,    -1,   162,   155,   414,   186,   155,   394,   186,
      -1,    96,   550,    -1,   552,    -1,   552,   551,    -1,   213,
     158,   189,    -1,   146,    -1,   196,    -1,   178,    -1,   554,
      -1,   556,    -1,   154,   158,   189,    -1,   322,   158,   189,
      -1,   573,    -1,   576,    -1,   653,    -1,   550,    -1,   553,
     109,   550,    -1,   659,    -1,   659,    -1,   558,    -1,   565,
      -1,   563,    -1,   566,    -1,   564,    -1,   562,    -1,   561,
      -1,   560,    -1,   559,    -1,   557,    -1,   227,   158,   189,
      -1,    45,   158,   189,    -1,    45,   158,   565,   189,    -1,
      45,   158,   566,   189,    -1,    54,   158,   189,    -1,    72,
     158,   189,    -1,    40,   158,   189,    -1,    61,   158,   189,
      -1,    61,   158,   658,   189,    -1,    61,   158,    30,   189,
      -1,    99,   158,   189,    -1,    99,   158,   659,   189,    -1,
      99,   158,   659,   109,   567,   189,    -1,    99,   158,   196,
     189,    -1,    99,   158,   196,   109,   567,   189,    -1,    63,
     158,   659,   189,    -1,    46,   158,   189,    -1,    46,   158,
     659,   189,    -1,    46,   158,   659,   109,   567,   189,    -1,
      46,   158,   659,   109,   568,   189,    -1,    46,   158,   196,
     189,    -1,    46,   158,   196,   109,   567,   189,    -1,    46,
     158,   196,   109,   568,   189,    -1,    64,   158,   659,   189,
      -1,   659,    -1,   659,   146,    -1,    30,    -1,   571,    -1,
     572,    -1,   659,   147,   151,    -1,    48,   382,   399,    -1,
     574,    -1,   575,    -1,    48,   158,   196,   189,    -1,    48,
     158,   189,    96,   550,    -1,    48,   158,   553,   189,    96,
     550,    -1,   158,   552,   189,    -1,    34,   222,   223,    -1,
      34,   222,   224,    -1,    34,   222,   225,    -1,   228,   227,
     415,   235,   415,    -1,   228,   227,   415,    96,   234,   235,
     415,    -1,   228,   227,   415,    96,   236,   235,   415,    -1,
     228,   227,   415,   220,   415,    -1,   228,   227,   415,   221,
     415,    -1,   228,   229,   415,   235,   415,    -1,   228,   229,
     415,    96,   234,   235,   415,    -1,   228,   229,   415,    96,
     236,   235,   415,    -1,   228,   229,   415,   220,   415,    -1,
     228,   229,   415,   221,   415,    -1,   226,   227,   415,    -1,
     226,   229,   415,    -1,   231,   227,   415,   239,   415,    -1,
     231,   232,   233,   227,   415,   239,   415,    -1,   230,   227,
     415,    96,   415,    -1,   238,   120,   583,   237,   415,   188,
     415,    -1,   584,    -1,   583,   109,   120,   584,    -1,   659,
     144,   415,    -1,   246,   155,   414,   186,   586,    -1,   587,
      -1,   586,   587,    -1,   247,   589,   588,    -1,   155,   414,
     186,    -1,   507,    -1,   589,   212,   507,    -1,   593,   591,
      -1,    -1,   592,    -1,   611,    -1,   592,   611,    -1,   594,
      -1,   593,   264,   594,    -1,   595,    -1,   594,   260,   595,
      -1,   596,    -1,   595,   262,   149,   596,    -1,   597,    -1,
     261,   597,    -1,   601,   598,   599,    -1,    -1,   616,    -1,
      -1,   600,    -1,   284,   155,   414,   186,    -1,   605,   602,
      -1,   158,   590,   189,    -1,   603,    -1,    -1,   638,    -1,
     494,   155,   604,   186,    -1,    -1,   590,    -1,   606,   607,
      -1,   513,    -1,   155,   414,   186,    -1,    -1,   608,    -1,
     250,   609,    -1,   249,   610,    -1,   272,    -1,    -1,    80,
      -1,    -1,   288,    -1,   612,    -1,   613,    -1,   614,    -1,
     640,    -1,   637,    -1,   171,    -1,   286,   477,   615,    -1,
     255,   639,   615,    -1,   288,    -1,   278,    -1,   271,    -1,
     248,   617,    -1,   616,   248,   617,    -1,   618,    -1,   619,
      -1,   620,    -1,   635,    -1,   621,    -1,   629,    -1,   622,
      -1,   636,    -1,   102,   276,    -1,   102,   265,    -1,   268,
      -1,   283,    -1,   253,   276,    -1,   253,   265,    -1,    58,
     659,    30,    -1,   279,    -1,    56,   279,    -1,   281,   623,
      -1,   281,   158,   623,   624,   189,    -1,    56,   281,    -1,
     626,    -1,   115,    -1,    -1,   109,   625,    -1,   626,    -1,
     625,   109,   626,    -1,    98,    30,   627,   628,    -1,    -1,
     273,    30,    -1,    -1,   639,   267,    -1,   280,   288,   630,
     632,    -1,   280,   288,   115,   632,    -1,    56,   280,   288,
      -1,    98,    30,    -1,   158,   631,   189,    -1,    30,    -1,
     631,   109,    30,    -1,    -1,   633,    -1,   634,    -1,   633,
     634,    -1,   203,   630,    -1,   138,   630,    -1,   266,    30,
      -1,   285,    -1,    56,   285,    -1,    98,   219,    -1,    98,
     256,    -1,   257,   252,    -1,   269,   639,   282,    -1,   258,
     477,    -1,    98,   131,   477,    -1,    98,    53,   477,    -1,
     259,   477,   201,   477,    -1,   274,   641,    -1,   254,   641,
      -1,   277,    -1,   270,    -1,   287,   252,   479,    -1,   156,
     187,    -1,   156,   414,   187,    -1,   312,   313,    -1,   312,
     414,   313,    -1,   314,   315,    -1,   314,   414,   315,    -1,
     155,   647,   186,    -1,   415,   123,   415,    -1,   647,   109,
     415,   123,   415,    -1,   228,   316,   415,   235,   415,    -1,
     228,   316,   647,   235,   415,    -1,   228,   316,   415,   235,
     415,    98,   318,   415,    -1,   317,   316,   415,   235,   415,
      -1,   226,   316,   509,    -1,   230,   316,   509,    96,   415,
      -1,   231,   316,   232,   233,   509,   239,   415,    -1,   654,
      -1,   655,    -1,   656,    -1,   321,   158,   189,    -1,   319,
     158,   189,    -1,   320,   158,   189,    -1,    30,    -1,    16,
      -1,   659,    -1,   660,    -1,    99,    -1,    40,    -1,    45,
      -1,    54,    -1,    46,    -1,   154,    -1,    49,    -1,   227,
      -1,    61,    -1,    63,    -1,    64,    -1,    72,    -1,    75,
      -1,    74,    -1,   213,    -1,   245,    -1,   661,    -1,    25,
      -1,   217,    -1,   129,    -1,    39,    -1,   263,    -1,    38,
      -1,   224,    -1,   223,    -1,   148,    -1,    44,    -1,   261,
      -1,   262,    -1,   276,    -1,   265,    -1,   253,    -1,   287,
      -1,   279,    -1,   281,    -1,   280,    -1,   285,    -1,   257,
      -1,   252,    -1,    80,    -1,   219,    -1,   256,    -1,    53,
      -1,   225,    -1,   238,    -1,   304,    -1,   232,    -1,   205,
      -1,   210,    -1,   209,    -1,   208,    -1,   207,    -1,   206,
      -1,    98,    -1,   113,    -1,   114,    -1,   188,    -1,    47,
      -1,    37,    -1,    68,    -1,    73,    -1,    60,    -1,    55,
      -1,    57,    -1,    79,    -1,    43,    -1,   149,    -1,    52,
      -1,   214,    -1,   172,    -1,   173,    -1,   170,    -1,    71,
      -1,    97,    -1,   118,    -1,   130,    -1,   131,    -1,   108,
      -1,    69,    -1,   137,    -1,   190,    -1,   102,    -1,    96,
      -1,   200,    -1,   128,    -1,   169,    -1,    94,    -1,    51,
      -1,   233,    -1,   103,    -1,   201,    -1,   119,    -1,   161,
      -1,   203,    -1,   152,    -1,   138,    -1,    77,    -1,    78,
      -1,   104,    -1,   202,    -1,   153,    -1,   184,    -1,   198,
      -1,   162,    -1,   139,    -1,   133,    -1,   168,    -1,   150,
      -1,   167,    -1,    34,    -1,    41,    -1,    59,    -1,   115,
      -1,    42,    -1,    58,    -1,   218,    -1,    50,    -1,    62,
      -1,    35,    -1,    48,    -1,   275,    -1,   251,    -1,   284,
      -1,   286,    -1,   255,    -1,   269,    -1,   282,    -1,   274,
      -1,   254,    -1,   268,    -1,   283,    -1,   273,    -1,   267,
      -1,   266,    -1,   250,    -1,   249,    -1,   258,    -1,   259,
      -1,   288,    -1,   278,    -1,   277,    -1,   272,    -1,   270,
      -1,   271,    -1,   231,    -1,   237,    -1,   234,    -1,   228,
      -1,   221,    -1,   220,    -1,   222,    -1,   239,    -1,   229,
      -1,   230,    -1,   236,    -1,   226,    -1,   235,    -1,    67,
      -1,    65,    -1,    76,    -1,   171,    -1,   204,    -1,   244,
      -1,   242,    -1,   243,    -1,   240,    -1,   241,    -1,   246,
      -1,   247,    -1,   248,    -1,    66,    -1,   297,    -1,   295,
      -1,   296,    -1,   301,    -1,   302,    -1,   303,    -1,   298,
      -1,   299,    -1,   300,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,    90,    -1,    91,    -1,   289,    -1,   290,
      -1,   291,    -1,   292,    -1,   293,    -1,   294,    -1,   305,
      -1,   306,    -1,   307,    -1,   308,    -1,   309,    -1,   310,
      -1,   311,    -1,    92,    -1,   107,    -1,   116,    -1,   174,
      -1,   182,    -1,   191,    -1,   140,    -1,    93,    -1,   117,
      -1,   141,    -1,   183,    -1,   316,    -1,   317,    -1,   318,
      -1,   321,    -1,   320,    -1,   319,    -1,   322,    -1,    26,
      -1
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
    1775,  1780,  1784,  1789,  1791,  1795,  1797,  1799,  1801,  1803,
    1805,  1810,  1819,  1825,  1835,  1845,  1856,  1858,  1861,  1863,
    1866,  1873,  1874,  1876,  1880,  1884,  1885,  1887,  1889,  1891,
    1894,  1897,  1898,  1900,  1902,  1904,  1907,  1910,  1912,  1914,
    1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,  1936,
    1940,  1943,  1947,  1951,  1954,  1956,  1958,  1960,  1962,  1964,
    1966,  1968,  1973,  1977,  1985,  1989,  1997,  2002,  2007,  2011,
    2019,  2023,  2031,  2034,  2036,  2039,  2043,  2045,  2047,  2049,
    2051,  2053,  2057,  2061,  2063,  2065,  2067,  2069,  2073,  2075,
    2077,  2079,  2081,  2083,  2085,  2087,  2089,  2091,  2093,  2095,
    2097,  2101,  2105,  2110,  2115,  2119,  2123,  2127,  2131,  2136,
    2141,  2145,  2150,  2157,  2162,  2169,  2174,  2178,  2183,  2190,
    2197,  2202,  2209,  2216,  2221,  2223,  2226,  2228,  2230,  2232,
    2236,  2240,  2242,  2244,  2249,  2255,  2262,  2266,  2270,  2274,
    2278,  2284,  2292,  2300,  2306,  2312,  2318,  2326,  2334,  2340,
    2346,  2350,  2354,  2360,  2368,  2374,  2382,  2384,  2389,  2393,
    2399,  2401,  2404,  2408,  2412,  2414,  2418,  2421,  2422,  2424,
    2426,  2429,  2431,  2435,  2437,  2441,  2443,  2448,  2450,  2453,
    2457,  2458,  2460,  2461,  2463,  2468,  2471,  2475,  2477,  2478,
    2480,  2485,  2486,  2488,  2491,  2493,  2497,  2498,  2500,  2503,
    2506,  2508,  2509,  2511,  2512,  2514,  2516,  2518,  2520,  2522,
    2524,  2526,  2530,  2534,  2536,  2538,  2540,  2543,  2547,  2549,
    2551,  2553,  2555,  2557,  2559,  2561,  2563,  2566,  2569,  2571,
    2573,  2576,  2579,  2583,  2585,  2588,  2591,  2597,  2600,  2602,
    2604,  2605,  2608,  2610,  2614,  2619,  2620,  2623,  2624,  2627,
    2632,  2637,  2641,  2644,  2648,  2650,  2654,  2655,  2657,  2659,
    2662,  2665,  2668,  2671,  2673,  2676,  2679,  2682,  2685,  2689,
    2692,  2696,  2700,  2705,  2708,  2711,  2713,  2715,  2719,  2722,
    2726,  2729,  2733,  2736,  2740,  2744,  2748,  2754,  2760,  2766,
    2775,  2781,  2785,  2791,  2799,  2801,  2803,  2805,  2809,  2813,
    2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,  2833,  2835,
    2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,  2855,
    2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,  2875,
    2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,
    2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,
    2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,
    2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,
    2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,
    2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,
    2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,
    3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,
    3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,  3055,
    3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,  3075,
    3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,
    3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,
    3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,  3135,
    3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,
    3157,  3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173,  3175,
    3177,  3179,  3181,  3183,  3185,  3187,  3189,  3191,  3193,  3195,
    3197,  3199,  3201,  3203,  3205,  3207,  3209,  3211,  3213,  3215,
    3217,  3219,  3221,  3223,  3225,  3227,  3229,  3231,  3233,  3235,
    3237,  3239,  3241,  3243,  3245,  3247,  3249,  3251,  3253,  3255,
    3257,  3259,  3261,  3263,  3265,  3267,  3269
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
    4043,  4053,  4063,  4076,  4085,  4095,  4099,  4108,  4113,  4122,
    4128,  4136,  4142,  4154,  4160,  4170,  4174,  4178,  4182,  4186,
    4192,  4198,  4206,  4210,  4218,  4222,  4233,  4237,  4241,  4247,
    4251,  4265,  4269,  4277,  4281,  4291,  4295,  4299,  4303,  4312,
    4316,  4320,  4324,  4332,  4338,  4348,  4356,  4360,  4364,  4368,
    4372,  4376,  4380,  4384,  4388,  4392,  4397,  4401,  4405,  4409,
    4417,  4421,  4429,  4436,  4443,  4454,  4462,  4466,  4474,  4482,
    4490,  4544,  4548,  4558,  4564,  4574,  4578,  4586,  4590,  4594,
    4602,  4610,  4627,  4635,  4652,  4671,  4695,  4701,  4712,  4718,
    4729,  4738,  4740,  4744,  4749,  4759,  4762,  4769,  4775,  4781,
    4788,  4800,  4803,  4810,  4816,  4822,  4829,  4840,  4844,  4852,
    4856,  4864,  4868,  4872,  4877,  4886,  4890,  4894,  4898,  4906,
    4911,  4919,  4924,  4932,  4940,  4945,  4950,  4955,  4960,  4965,
    4970,  4976,  4984,  4988,  5005,  5009,  5017,  5025,  5033,  5037,
    5045,  5049,  5057,  5065,  5069,  5073,  5108,  5114,  5120,  5130,
    5134,  5138,  5142,  5146,  5150,  5154,  5161,  5167,  5177,  5185,
    5193,  5197,  5201,  5205,  5209,  5213,  5217,  5221,  5225,  5229,
    5237,  5245,  5249,  5253,  5261,  5268,  5276,  5284,  5288,  5292,
    5300,  5304,  5310,  5316,  5320,  5330,  5338,  5342,  5348,  5357,
    5366,  5372,  5378,  5388,  5405,  5412,  5427,  5463,  5467,  5475,
    5483,  5495,  5499,  5507,  5515,  5519,  5530,  5547,  5553,  5559,
    5569,  5573,  5579,  5585,  5589,  5595,  5599,  5605,  5611,  5618,
    5628,  5633,  5641,  5647,  5657,  5679,  5688,  5694,  5707,  5721,
    5728,  5734,  5744,  5753,  5761,  5767,  5785,  5793,  5797,  5804,
    5809,  5817,  5821,  5828,  5832,  5839,  5843,  5850,  5854,  5863,
    5876,  5879,  5887,  5890,  5898,  5906,  5914,  5918,  5926,  5929,
    5937,  5949,  5952,  5960,  5972,  5978,  5988,  5991,  5999,  6003,
    6007,  6015,  6018,  6026,  6029,  6037,  6041,  6045,  6049,  6053,
    6061,  6069,  6081,  6093,  6097,  6101,  6109,  6115,  6125,  6129,
    6133,  6137,  6141,  6145,  6149,  6153,  6161,  6165,  6169,  6173,
    6181,  6187,  6197,  6207,  6211,  6219,  6229,  6240,  6247,  6251,
    6259,  6262,  6269,  6274,  6283,  6293,  6296,  6303,  6307,  6315,
    6324,  6331,  6341,  6345,  6352,  6358,  6368,  6371,  6378,  6383,
    6395,  6403,  6415,  6423,  6427,  6435,  6439,  6443,  6451,  6459,
    6463,  6467,  6471,  6479,  6487,  6499,  6503,  6511,  6525,  6529,
    6536,  6541,  6549,  6554,  6563,  6571,  6577,  6587,  6593,  6603,
    6610,  6617,  6642,  6670,  6698,  6702,  6706,  6713,  6720,  6727,
    6739,  6743,  6744,  6757,  6758,  6759,  6760,  6761,  6762,  6763,
    6764,  6765,  6766,  6767,  6768,  6769,  6770,  6771,  6772,  6773,
    6777,  6778,  6779,  6780,  6781,  6782,  6783,  6784,  6785,  6786,
    6787,  6788,  6789,  6790,  6791,  6792,  6793,  6794,  6795,  6796,
    6797,  6798,  6799,  6800,  6801,  6802,  6803,  6804,  6805,  6806,
    6807,  6808,  6809,  6810,  6811,  6812,  6813,  6814,  6815,  6816,
    6817,  6818,  6819,  6820,  6821,  6822,  6823,  6824,  6825,  6826,
    6827,  6828,  6829,  6830,  6831,  6832,  6833,  6834,  6835,  6836,
    6837,  6838,  6839,  6840,  6841,  6842,  6843,  6844,  6845,  6846,
    6847,  6848,  6849,  6850,  6851,  6852,  6853,  6854,  6855,  6856,
    6857,  6858,  6859,  6860,  6861,  6862,  6863,  6864,  6865,  6866,
    6867,  6868,  6869,  6870,  6871,  6872,  6873,  6874,  6875,  6876,
    6877,  6878,  6879,  6880,  6881,  6882,  6883,  6884,  6885,  6886,
    6887,  6888,  6889,  6890,  6891,  6892,  6893,  6894,  6895,  6896,
    6897,  6898,  6899,  6900,  6901,  6902,  6903,  6904,  6905,  6906,
    6907,  6908,  6909,  6910,  6911,  6912,  6913,  6914,  6915,  6916,
    6917,  6918,  6919,  6920,  6921,  6922,  6923,  6924,  6925,  6926,
    6927,  6928,  6929,  6930,  6931,  6932,  6933,  6934,  6935,  6936,
    6937,  6938,  6939,  6940,  6941,  6942,  6943,  6944,  6945,  6946,
    6947,  6948,  6949,  6950,  6951,  6952,  6953,  6954,  6955,  6956,
    6957,  6958,  6959,  6960,  6961,  6962,  6963,  6964,  6965,  6966,
    6967,  6968,  6969,  6970,  6971,  6972,  6973,  6974,  6975,  6976,
    6977,  6978,  6979,  6980,  6981,  6982,  6987
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
  const int xquery_parser::yylast_ = 17313;
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
#line 17844 "/home/colea/xquery_bzr/new-jsoniq/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6991 "/home/colea/xquery_bzr/new-jsoniq/src/compiler/parser/xquery_parser.y"


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

