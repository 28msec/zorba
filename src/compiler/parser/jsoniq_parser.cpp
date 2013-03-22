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
#line 915 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1053 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"

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
#line 913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 290 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 126: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 912 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 299 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 151: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 911 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 308 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 345: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 317 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 346: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 326 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 347: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 335 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 348: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 344 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 349: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 353 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 350: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 362 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 351: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 371 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 352: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 380 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 353: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 389 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 354: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 398 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 355: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 407 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 356: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 416 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 357: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 425 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 358: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 434 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 359: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 443 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 360: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 452 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 361: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 461 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 362: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 470 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 363: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 479 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 364: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 488 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 365: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 497 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 366: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 506 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 367: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 515 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 368: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 524 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 369: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 533 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 370: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 542 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 372: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 551 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 373: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 560 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 374: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 569 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 375: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 578 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 376: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 587 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 377: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 596 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 378: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 605 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 379: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 614 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 380: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 623 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 381: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 632 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 382: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 641 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 383: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 650 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 384: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 659 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 385: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 668 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 386: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 677 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 387: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 686 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 388: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 695 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 389: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 704 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 390: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 713 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 392: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 722 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 393: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 731 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 394: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 740 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 395: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 749 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 396: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 758 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 397: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 767 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 398: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 776 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 399: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 785 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 400: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 794 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 401: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 803 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 402: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 812 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 403: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 821 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 404: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 830 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 405: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 839 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 408: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 848 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 409: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 857 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 410: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 866 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 411: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 875 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 412: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 884 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 413: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 893 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 414: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 902 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 415: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 911 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 416: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 920 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 417: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 929 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 418: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 938 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 420: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 947 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 421: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 956 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 422: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 965 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 423: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 974 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 424: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 983 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 427: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 992 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 428: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1001 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 429: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1010 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 430: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1019 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 432: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1028 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 433: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1037 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 435: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1046 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 436: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1055 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 437: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1064 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 438: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1073 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 439: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1082 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 440: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1091 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 441: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1100 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 442: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1109 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 443: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1118 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 444: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1127 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 445: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1136 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 446: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1145 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 447: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1154 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 448: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1163 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 449: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1172 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 450: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1181 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 451: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1190 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 452: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1199 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 453: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1208 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 454: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1217 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 455: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1226 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 456: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1235 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 457: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1244 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 458: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1253 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 459: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1262 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 460: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1271 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 461: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1280 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 462: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1289 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 463: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1298 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 464: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1307 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 465: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1316 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 468: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1325 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 469: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1334 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 470: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1343 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 471: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1352 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 474: /* "SequenceTypeList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1361 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 475: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1370 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 476: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1379 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 477: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1388 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 478: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1397 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 480: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1406 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 481: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1415 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 482: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1424 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 483: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1433 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 484: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1442 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 485: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1451 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 486: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1460 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 487: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1469 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 488: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1478 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 489: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1487 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 490: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1496 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 491: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1505 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 492: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1514 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 493: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1523 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 494: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1532 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 495: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1541 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 496: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1550 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 497: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1559 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 498: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1568 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 499: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1577 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 500: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1586 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 501: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1595 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 502: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1604 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 503: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1613 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 504: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1622 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 505: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1631 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 506: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1640 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 507: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1649 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 508: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1658 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 509: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1667 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 510: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1676 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 511: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1685 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 512: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1694 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 513: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1703 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 515: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1712 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 516: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1721 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 517: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1730 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 518: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1739 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 519: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1748 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 520: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1757 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 521: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1766 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 525: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1775 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 526: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1784 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 527: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1793 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 528: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1802 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 529: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1811 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 530: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1820 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 532: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1829 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 533: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1838 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 534: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1847 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 535: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1856 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 536: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1865 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 537: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1874 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 538: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1883 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 539: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1892 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 540: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1901 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 541: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1910 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 542: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1919 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 543: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1928 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 544: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1937 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 545: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1946 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 546: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1955 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 547: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1964 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 548: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1973 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 549: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1982 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 550: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1991 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 551: /* "CompNamespaceConstructor" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2000 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 552: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2009 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 553: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2018 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 554: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2027 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 555: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2036 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 556: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2045 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 557: /* "GeneralizedAtomicType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2054 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 558: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2063 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 559: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2072 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 560: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2081 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 561: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2090 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 562: /* "NamespaceTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2099 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 563: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2108 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 564: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2117 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 565: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2126 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 566: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2135 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 567: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2144 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 568: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2153 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 569: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2162 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 570: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2171 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 571: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2180 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 572: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2189 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 574: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2198 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 575: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2207 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 578: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2216 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 579: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2225 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 580: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2234 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 581: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2243 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 582: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2252 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 583: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2261 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 584: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2270 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 585: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2279 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 586: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2288 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 587: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2297 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 588: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2306 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 589: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2315 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 590: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2324 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 593: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2333 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 594: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2342 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 595: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2351 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 596: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2360 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 597: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2369 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 598: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2378 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 600: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2387 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 601: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2396 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 602: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2405 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 603: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2414 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 605: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2423 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 606: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2432 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 608: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2441 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 611: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2450 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 612: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2459 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 613: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2468 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 614: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2477 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 615: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2486 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 616: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2495 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 617: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2504 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 618: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2513 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 619: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2522 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 620: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2531 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 621: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2540 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 622: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2549 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 626: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2558 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 629: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2567 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 630: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2576 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 634: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2585 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 635: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2594 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 636: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2603 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 637: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2612 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 638: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2621 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 639: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2630 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 640: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2639 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 641: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2648 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 642: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2657 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 643: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2666 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 644: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2675 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 645: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2684 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 646: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2693 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 647: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2702 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 648: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2711 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 649: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2720 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 650: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2729 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 651: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2738 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 652: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2747 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 659: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2756 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 660: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2765 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
	break;
      case 661: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1071 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1075 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1079 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1087 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1093 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1097 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1106 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1112 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1120 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1126 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1137 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1142 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1146 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1151 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl(
        LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1160 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1167 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1174 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1183 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1190 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1198 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1206 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1214 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1225 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1230 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1237 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1244 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1256 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1266 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:

/* Line 690 of lalr1.cc  */
#line 1273 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:

/* Line 690 of lalr1.cc  */
#line 1280 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1315 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1320 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1328 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1336 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1344 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1349 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1357 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1362 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1370 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1375 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1383 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1388 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1393 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1398 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1411 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1421 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1426 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1434 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1442 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1453 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1460 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1471 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1476 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1484 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1491 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1498 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1507 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1520 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1528 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1535 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1545 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:

/* Line 690 of lalr1.cc  */
#line 1552 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:

/* Line 690 of lalr1.cc  */
#line 1559 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1582 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1588 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1597 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1614 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1623 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1624 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1625 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1626 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1627 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1628 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1629 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1630 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1631 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1632 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1638 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1646 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1654 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1662 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1669 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1677 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1684 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1689 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:

/* Line 690 of lalr1.cc  */
#line 1697 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1705 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1719 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1733 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1750 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1755 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1763 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1771 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1782 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1787 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1796 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1801 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1808 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1813 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1823 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1828 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1837 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1843 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1856 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 131:

/* Line 690 of lalr1.cc  */
#line 1861 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 132:

/* Line 690 of lalr1.cc  */
#line 1869 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1880 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1895 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1907 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1922 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1927 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1932 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1952 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1963 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1968 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1978 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1987 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 1996 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2005 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2017 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2021 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2027 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2031 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2041 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2051 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2064 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2070 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2079 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2084 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2091 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2098 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:

/* Line 690 of lalr1.cc  */
#line 2110 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2120 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2130 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2141 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2157 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2177 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
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
      (yyval.expr) =  NULL;
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2193 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
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
#line 2201 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2209 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2214 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2226 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:

/* Line 690 of lalr1.cc  */
#line 2233 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 175:

/* Line 690 of lalr1.cc  */
#line 2243 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2276 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2284 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2301 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2309 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2317 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2324 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 2331 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2342 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2351 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2360 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2369 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2382 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2390 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:

/* Line 690 of lalr1.cc  */
#line 2398 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2406 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2421 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2426 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2434 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2448 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2465 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2490 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2498 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2505 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2516 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:

/* Line 690 of lalr1.cc  */
#line 2525 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 214:

/* Line 690 of lalr1.cc  */
#line 2532 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 215:

/* Line 690 of lalr1.cc  */
#line 2537 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2550 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2597 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2611 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2619 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2624 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2632 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:

/* Line 690 of lalr1.cc  */
#line 2637 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:

/* Line 690 of lalr1.cc  */
#line 2642 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:

/* Line 690 of lalr1.cc  */
#line 2650 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2659 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2671 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2681 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2694 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2718 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2725 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2735 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2741 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2750 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 261:

/* Line 690 of lalr1.cc  */
#line 2760 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      // this adds on shift-reduce conflict (probably with FTRange expression)
    }
    break;

  case 262:

/* Line 690 of lalr1.cc  */
#line 2768 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 263:

/* Line 690 of lalr1.cc  */
#line 2775 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 264:

/* Line 690 of lalr1.cc  */
#line 2783 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2795 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2805 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2815 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2825 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2835 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2845 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2855 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2865 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2876 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2885 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2895 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:

/* Line 690 of lalr1.cc  */
#line 2939 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2947 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2953 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2965 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2973 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2983 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 2991 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3003 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3009 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3022 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3026 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3034 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3038 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3047 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3051 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3055 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3065 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3073 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3080 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3086 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3096 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3100 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3104 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3112 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3120 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3128 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3140 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3148 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3154 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3164 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3170 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3180 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3184 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3194 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3200 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3206 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3212 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3221 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3230 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3239 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3252 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3256 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3264 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3270 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3280 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3288 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3297 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3310 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3317 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3329 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3333 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3345 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3352 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3358 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3367 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3374 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3380 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3391 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3398 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3404 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3413 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3422 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3429 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3440 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3447 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 3459 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3465 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3477 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3483 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3494 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3500 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3511 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3517 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3528 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3534 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3554 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3558 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3567 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3571 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3579 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3583 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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

  case 363:

/* Line 690 of lalr1.cc  */
#line 3593 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3600 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3609 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3618 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3623 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3632 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3641 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3650 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3663 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3667 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3679 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3683 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3690 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3694 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3701 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3705 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
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
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3722 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3730 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3734 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3740 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3746 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3752 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
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
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3770 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3778 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3782 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3788 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3798 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3802 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3812 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3816 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3826 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3830 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3840 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3844 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3854 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3858 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3867 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3871 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3879 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3883 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3887 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3891 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3901 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3909 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3916 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3941 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3949 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3957 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3961 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3965 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3973 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3977 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3981 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3985 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 3996 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4002 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4012 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4018 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4028 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4032 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4036 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4099 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4121 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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

  case 436:

/* Line 690 of lalr1.cc  */
#line 4149 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4313 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4317 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4327 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4331 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4335 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4339 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4348 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4352 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4356 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4360 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4364 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4369 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4373 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4377 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4381 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4390 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4396 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4406 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4414 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4418 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4422 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4426 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4430 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4434 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4438 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4442 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4446 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4450 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4455 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 4475 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4479 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4483 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4487 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4495 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4502 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4509 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4519 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4523 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4531 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4539 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4543 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4551 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4559 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4567 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4621 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4625 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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

  case 486:

/* Line 690 of lalr1.cc  */
#line 4647 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4653 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4659 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4665 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4675 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4679 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4687 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4695 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4707 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4711 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4719 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4723 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4727 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4735 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4743 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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

  case 501:

/* Line 690 of lalr1.cc  */
#line 4760 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4768 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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

  case 503:

/* Line 690 of lalr1.cc  */
#line 4787 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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

  case 504:

/* Line 690 of lalr1.cc  */
#line 4806 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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

  case 505:

/* Line 690 of lalr1.cc  */
#line 4828 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4834 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4845 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4851 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4862 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4877 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 513:

/* Line 690 of lalr1.cc  */
#line 4882 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 514:

/* Line 690 of lalr1.cc  */
#line 4891 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4895 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4902 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4908 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4914 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4932 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4949 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4955 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4962 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4973 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4977 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4985 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4989 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4997 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 5001 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 5005 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 5010 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 5019 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 5023 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 5027 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 5031 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 5039 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 5044 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 5052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 5057 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 5065 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 5073 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 5078 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 5083 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 5088 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 5093 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 5098 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 5109 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 5117 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 5121 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 5138 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 5142 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 5150 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 5158 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 5166 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 5170 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 5178 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 5182 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5190 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5198 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5202 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5206 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5241 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5247 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5253 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5263 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5267 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5271 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5275 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5279 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5283 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5287 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5294 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5300 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5310 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5318 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5326 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5330 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5334 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5338 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5342 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5346 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5350 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5354 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5358 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5362 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5370 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5378 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5382 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5386 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5394 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5401 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5409 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5417 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5421 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5425 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5433 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5437 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5443 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5449 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5453 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5463 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5471 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5475 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5481 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5490 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5499 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5505 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5511 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5521 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5538 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5545 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5560 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5587 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5591 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5599 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5607 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5611 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5622 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5639 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5645 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5651 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5661 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5665 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5671 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5677 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5681 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5687 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5697 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5703 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5710 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5720 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5733 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5739 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5749 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5771 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5780 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5786 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5799 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5813 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5820 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5826 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5836 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5845 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5853 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5859 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5877 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5885 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5889 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5896 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5901 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5909 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5924 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5946 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5955 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5967 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5971 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5978 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5982 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5990 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5998 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 6006 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 6010 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 6017 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 6021 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 6029 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 6040 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 6044 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 6052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 6064 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 6070 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 6079 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 6083 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 6091 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 6095 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 6099 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 6106 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 6110 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 6117 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 6121 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 6129 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 6133 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 6137 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 6141 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6145 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6153 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6161 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6173 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6185 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6189 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6193 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6201 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6207 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6217 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6221 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6225 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6229 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6233 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6237 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6241 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6245 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6253 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6257 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6261 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6265 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6273 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6279 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6289 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6299 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6303 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6311 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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

  case 721:

/* Line 690 of lalr1.cc  */
#line 6321 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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

  case 722:

/* Line 690 of lalr1.cc  */
#line 6332 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6339 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6343 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6350 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6354 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6361 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6366 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6375 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6384 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6388 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6395 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6399 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6407 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6416 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6423 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6433 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6437 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6444 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6450 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6459 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6463 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6470 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6475 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6487 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6495 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6507 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6515 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6519 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6527 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6531 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6535 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6543 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6551 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6555 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6559 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6563 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6571 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6579 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6591 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6595 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6603 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6617 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6621 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6628 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6633 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6641 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6646 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6655 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)));
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6659 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6667 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6674 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6680 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6687 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6698 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6704 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6714 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6721 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6728 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6753 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6781 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6809 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6813 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6817 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6825 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6832 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 787:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
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
#line 6869 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6978 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6979 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6980 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6981 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6983 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6984 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6985 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6986 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6987 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6988 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6989 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6990 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6991 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6992 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6993 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6994 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6995 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6996 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6997 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6998 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6999 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 7000 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 7001 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 7002 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 7003 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 7004 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 7005 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 7006 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 7007 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 7008 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 7009 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 7010 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 7011 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 7012 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 7013 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 7014 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 7015 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 7016 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 7017 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 7018 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 7019 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 7020 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 7021 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 7022 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 7023 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 7024 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 7025 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 7026 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 7027 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 7028 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 7029 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 7030 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 7031 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 7032 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 7033 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 7034 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 7035 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 7036 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 7037 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 7038 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 7039 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 7040 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 7041 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 7042 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 7043 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 7044 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 7045 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 7046 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 7047 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 7048 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 7049 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 7050 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 7051 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 7052 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 7053 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 7054 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 7055 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 7056 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 7057 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 7058 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 7059 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 7060 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 7061 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 7062 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 7063 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 7064 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 7065 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 7066 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 7067 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 7068 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 7069 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 7070 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 7071 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 7072 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 7073 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 7074 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 7075 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 7076 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 7077 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 7078 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 7079 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 7080 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 7081 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 7082 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 7083 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 7084 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 7085 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 7086 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 7087 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 7088 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 7089 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 7091 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 7092 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 7093 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 7098 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12108 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
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
  const short int jsoniq_parser::yypact_ninf_ = -1494;
  const short int
  jsoniq_parser::yypact_[] =
  {
      6520,  7748,  7748,  7748,  7748, -1494, -1494,    82,   259, -1494,
     779,    15, -1494, -1494, -1494,    56, -1494, -1494, -1494,   268,
   -1494,   298,   696,   280,   350,   651, -1494,   -42, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494,   359, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494,   432, -1494,   474, -1494,   481,   533, -1494,
     387, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494,   598, -1494, -1494, -1494, -1494, -1494, -1494, -1494,   567,
   -1494, -1494, -1494, -1494, -1494, 15583, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494,   659, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494,  4689,  9890, 10196, 15583, -1494,
   -1494,   628, -1494, -1494, -1494, -1494,   634, -1494, -1494, -1494,
    5905, -1494,  6214, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494,   679, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494,   109,   767,   785, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,   141, -1494,
     200, -1494,  -110,   391, -1494, -1494, -1494, -1494, -1494, -1494,
     850, -1494,   763,   776,   793, -1494, -1494,   869,   878, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494,   772, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, 10502, 10808, -1494,   732, -1494, -1494, -1494, -1494,
    6828,  7136,  1051, -1494,  8054, -1494, -1494,   459,    72, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494,    83, -1494, -1494, -1494, -1494, -1494, -1494,
     458, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,  7748,
   -1494, -1494, -1494, -1494,    11, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494,   222, -1494,   861, -1494, -1494, -1494,
     578, -1494,   454, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
     885,   961, -1494,   922,   804,   957,   719,   661,   684,    31,
   -1494,  1010,   860,   960,   964, 11726, -1494,   874, -1494, -1494,
     506, -1494, -1494, -1494, -1494,    34, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,   924,
     916, -1494, -1494, -1494, -1494, -1494,   890, -1494,  7748,   891,
     892,   896,  7748,   119,   119,  1053,   562,   764,     4, 15876,
   15583,    -7,  1036, 15583,   931,   969,   571,  5905,   780,   849,
   15583, 15583,   792,   615,    53, -1494, -1494, -1494,  5905,  7748,
    7748, 12032,   273,   949, 12032,  1104,   176,   325, 15583,   987,
     967,  1003, -1494, 12032, 15583,  7748, 12032, 12032, 15583,  7748,
     962,   965, 12032, 15583, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494,   971, -1494, 15583, -1494,
   -1494,   930,  7442,   996,    35,   998,   924,   966,   975,   976,
   15583,  4689, -1494,   968,   172, -1494,   599, -1494,    78,  1086,
   12032, 12032,    67, -1494, -1494, -1494,  1108, 12032,   919, -1494,
    1106,  1107, 12032, 12032, 12644, 12032, 12032,  4998, 12032, 12644,
   12032,   902,   904, 15583,   950,   951, 12032, 12032,  7748,   893,
   -1494,    52, -1494,    41, 12032,  7136, -1494, -1494, -1494, -1494,
   -1494,   779,   651,    91,    94,  1138,  8360,  3105,  8666,  3432,
     567, -1494, -1494,   272,   567, -1494, 12032,  4064, -1494,  1025,
   -1494,   -42,   977,   974,   978,  7748, 12032, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, 15583, -1494,   858,   859,
   15583,  1031, 12338, 12338, 12338, -1494, 12338, 12338, -1494, 12338,
   -1494, 12338, -1494, -1494, -1494, -1494, -1494, -1494, -1494, 12338,
   12338,  1080, 12338, 12338, 12338, 12338, 12338, 12338, 12338, 12338,
   12338, 12338, 12338, 12338,   917,  1057,  1059,  1060, -1494, -1494,
   -1494, 12644, 11114, -1494,  5301, 12032,  9278,  1001, -1494,  1007,
    9584, -1494, -1494, -1494, -1494,   300, -1494,   328, -1494, -1494,
   -1494, -1494, -1494, -1494,  1050,  1052,   280,  1130, -1494, -1494,
   15876,  1009,   594, 15583,  1000,  1002,  1009,  1053,  1034,  1033,
   -1494, -1494, -1494,   107,   913,  1072,   864, 15583,  1026, 12032,
    1054, 15583, 15583, -1494,  1039,   989,   990,    71, 15583,  1083,
     500, -1494,  7748, -1494,    96, -1494,  5905,  1082,  1136,  5905,
    1053,  1085,    57, 15583, 12032,   -42,   238,   278, -1494,   494,
     999,   121,   129,  1032, -1494,  1004,  7748,  7748,   286,   434,
   12032,   290, -1494, -1494, 12032,  4998, -1494, 12032, 12032, 12032,
   12032, -1494, 12032, -1494, 12032, -1494, 15583,  1086, -1494,    20,
     355,   379, -1494, -1494, -1494,   403, -1494,    49,   315, -1494,
   -1494,    34,   188,   511,   212,   124,  1090,   618,   945,   963,
     954,   -26, -1494,  1048, -1494, -1494,  1005,   133,  7442,   417,
    4380,   893, -1494, -1494, -1494,   959, -1494,   459,   876,  1165,
     706, -1494, -1494,   110, -1494, -1494, -1494,   112, -1494,    28,
   -1494, -1494, -1494, -1494, -1494,  3748, -1494, -1494, -1494, 15583,
    1028, 12032,  1081, -1494, -1494, -1494,  1093, -1494,    37, -1494,
   -1494,  1093, 15583,    14,   961, -1494, -1494, -1494, -1494, -1494,
   12338, -1494, -1494, -1494,    69, -1494,   661,   661,   442,   684,
     684,   684,   684,    31,    31, -1494, -1494, 14118, 14118, 15583,
   15583, -1494, -1494,   419, -1494, -1494, -1494, -1494, -1494,   234,
   -1494, -1494, -1494,   507, -1494, -1494, -1494,   529,   119, -1494,
   -1494,   269,   641,   710, -1494,   280, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494,  1009, -1494,  1070, 14411,
    1062, 12032, -1494, -1494, -1494,  1111,  1053,  1053,  1009, -1494,
     760,  1053,   751, 15583,   680,   748,  1179, -1494, -1494,   918,
     717, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494,   107,   153,   979,   649, 12032, -1494, 15583,  1115,
     908,  1053, -1494, -1494,  1063,  1111, 14118,  1094,  1121,  1035,
    1019,  1089,  1053,  1058,  1091,  1126,  1053, 14118, 12032,    16,
   -1494, -1494, -1494,  1071,  1110, 12032, 12032,  1079, -1494,  1131,
    1133,  7748, -1494,  1046,  1056,  1098, 12032,  1092,  1045, 12032,
   -1494,  1123,  1125, -1494,   138,   144,   169,  1202, -1494,    30,
   -1494,   486,  1099, -1494, -1494,  1214, -1494,  1219, -1494,   683,
   12032, 12032, 12032,   762, 12032, 12032, 12032, 12032, 12032, 12032,
   12032, 12032, 12032, 12644,  1135, 12032, 12032, -1494,  8972,   343,
    1006, -1494, -1494, -1494, -1494, -1494, -1494,   438, -1494, -1494,
   12032,   114,   329,    28,  8666,  3432,  8666,  1175, -1494, -1494,
   12032,   816,  1150, -1494, 15583,  1151, -1494, 15290,  1132,  1143,
   12032,    51,  1116,    29,   532,  1011, -1494, -1494,   809,    14,
   -1494, 12032,    69,   887,   509, -1494,   973,   308,  1008,  1013,
   -1494, -1494,   849, -1494,   993,   704,  1117,  1118,  1119,  1122,
    1124,  1127,  1128,  1129,  1139,  1140,  1141, 14411,  1142,  1144,
    1149,  1152, -1494,  1153, -1494,   702, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,  1145,
   -1494, -1494, -1494, -1494, 11420, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494,   789, -1494,  1243,   845, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494,   992, -1494, -1494,
    1251, -1494, -1494, -1494, -1494, -1494,   731,  1258, -1494,   803,
   -1494, -1494, -1494,  1117,  1118,  1119,  1124,  1127,  1128,  1129,
    1139,  1140,  1144,  1149,  1152, -1494,   702,   702, 12644,   997,
     981, -1494,  1111,   153,  1061,  1109,  7748, -1494, -1494, -1494,
   14118, -1494,  7748,  1053,  1187, -1494, -1494, -1494,  1053,  1187,
   -1494, -1494, 12032,  1168,  7748, 15583, -1494, -1494, 12032, 12032,
     569, -1494,    44,   610, -1494, 13239,   686, -1494,   812, -1494,
    1134, -1494, -1494,  7748, -1494, 12032, -1494, -1494, 12032, 12032,
    1113,  1131,  1215, -1494,  1182, -1494,   638, -1494, -1494,  1312,
   -1494, -1494,  7748, 15583, -1494,   685, -1494, -1494, -1494,  7748,
    1146,  1148,  1084,  1087, -1494, -1494, -1494,  1088,  1095, -1494,
   -1494, -1494,  1224, -1494, -1494, -1494, -1494,  1100,   450, 15583,
    1137, -1494,  1166,  1170,  1173,  1178, -1494,   861,   611,  4380,
    1006, -1494,  8972,  4380, -1494, -1494,  1165,   607, -1494, -1494,
   -1494,  1150, -1494,  1053, -1494,   881, -1494,   303,  1227, -1494,
   12032,   734,  1081, 15583, -1494,    40, 15583, -1494, 12032,  1188,
   12032,  1207, 12032,   149,  1192, 12032,  1193, -1494,  1225,  1226,
   12032, 15583,   933,  1265, -1494, -1494, -1494,   424,  1163, -1494,
      69,  1097, -1494, -1494,   166, -1494,   270,   120,  1101,    69,
     270, 12338, -1494,   441, -1494, -1494, -1494, -1494, -1494, -1494,
      69,  1205,  1067,   913,   120, -1494, -1494,  1064,  1279, -1494,
   -1494, -1494,  1171,    54, 14704, 12946,  1172,  5603, 15583, 15583,
    1176, 14997,  1177,  1180,  1181,  1183,  1184,  1185,  1186, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494,  1332,    -1,  1334,    -1,  1102,  1259, -1494, -1494,
    1195, 15583,  1120, -1494, -1494, 12644, -1494,  1190, -1494,  1250,
    1252,  1273,  1053,  1187, -1494, 12032,  1196, -1494, -1494, -1494,
    1197, -1494,   283, 12032,  7748,  1198,   287, -1494, 15583,   720,
   -1494, 13532,   281, -1494, 13825,  1199, -1494, -1494,  1203, -1494,
   -1494, -1494, 12032,   877,  1202, 15583,   842, -1494,  1206,  1202,
   15583, -1494,  1210, -1494, -1494, 12032, 12032, 12032, 12032,  1066,
   12032, 12032, -1494, 12032, 12032, 12032, 12032,  8972,   463, -1494,
   -1494, -1494, -1494, -1494,  1227, -1494, -1494, -1494,  1053, 12032,
   -1494,  1237, -1494, -1494, 12032,  1249, -1494, -1494, 12032, -1494,
     362, -1494, 12032,  1253, 12032, -1494, 12032, 15583, 15583, -1494,
     813, -1494, 12032, -1494, -1494, -1494,  1213, 12338, -1494, -1494,
   -1494, -1494, -1494,   352, 12338, 12338,   699, -1494,  1008, -1494,
     584, -1494,  1013,    69,  1245, -1494, -1494,  1147, -1494, -1494,
   -1494, -1494, -1494, -1494,  1212,  1216, -1494,   535,   548,  1307,
    1217, -1494,   558, -1494,  1218, -1494,  1221,  1222,  1223, -1494,
   -1494,   563,   568, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494,   312,   312, -1494,    -1, -1494, -1494,   596, -1494,  1378,
      18,  1315,  1228, 12644,   -55,  1155,  1242, -1494,  8972, 12032,
    1053, -1494, -1494, -1494, 12032, 12032, -1494, -1494, -1494,  8972,
    8972,  1319,  7748, 14118, 15583,   724, 15583, 12032, 15583,   728,
    8972, -1494,   294,    19,  1202, 15583, -1494,  1229,  1202, -1494,
   -1494, -1494, -1494, -1494, 12032, -1494, -1494, -1494,   173,   184,
     211, 12032, -1494, -1494, -1494,  1310, 12032, -1494, 12032, -1494,
   12032,  1272, -1494, 12032, -1494, -1494, -1494,  1367, -1494, -1494,
   -1494,   684, 12338, 12338,   442,   721, -1494, -1494, -1494, -1494,
   -1494, -1494, 12032, -1494, -1494, -1494, 15583, -1494, 15583, -1494,
   14118, -1494, 14118,  1327, -1494, -1494, -1494, -1494, 15583, -1494,
   15583, -1494, -1494, -1494, -1494,  1394, -1494, -1494, -1494,  1154,
    1317, -1494, -1494,  1320, -1494,   882, 15583,  1311,  1201, 15583,
   12644, -1494, -1494,  1187, -1494, -1494, 14118, -1494, -1494, -1494,
    1338, 12032,  1247, -1494,  1340,  8972, -1494, 15583,   669,   631,
   -1494,  1231,  1202, -1494,  1238, -1494,  1239,  1131,  1133,   440,
   -1494,  1310, -1494, -1494, 12032, -1494,  1318,   442,   442, 12338,
     445,  1254,  1255,  1294,  1256,  1260, -1494, -1494, 14118,  1261,
    1262, -1494, -1494,  1315, 12644, -1494,  1227,  1156, 15583,  1321,
    1211,  1320,   743, 14118,  7748, 14118,  1267, -1494, -1494,  1358,
     701, -1494, -1494, -1494, -1494,  1271,   841, -1494, -1494, -1494,
    1263, -1494,  8972,   880, -1494, -1494, -1494, 15583,   442, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, 12032,  1158, 15583,  1339,  7748,   747, -1494, -1494,   749,
   12032, -1494, -1494, -1494, -1494, -1494, -1494, -1494,  1343, -1494,
   -1494,  1159,  1161, 15583, -1494, -1494, 12032,  8972, 15583,  1162,
   12032,  1167,  1277, 12644, -1494, 12644,  8972, -1494,  1269,  1189,
   15583,  1230,  1346, 15583,  1169, 12644, -1494
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   170,   170,   170,     0,   809,  1013,   122,   124,   615,
     901,   910,   850,   814,   812,   793,   902,   905,   857,   818,
     794,   796,   260,   911,   798,   908,   879,   859,   834,   795,
     854,   855,   906,   903,   853,   800,   909,   801,   802,   950,
     962,   949,   851,   870,   864,   803,   852,   805,   804,   951,
     888,   889,   856,   831,   972,   973,   974,   975,   976,   977,
     978,   979,   980,   981,   982,   996,  1003,   878,   874,   865,
     845,   792,   873,   881,   890,   997,   869,   473,   846,   847,
     904,   998,  1004,   866,   883,     0,   481,   475,   876,   811,
     867,   868,   897,   871,   887,   896,  1002,  1005,   817,   858,
     899,   474,   886,   892,   797,     0,     0,     0,     0,   406,
     884,   895,   900,   898,   877,   863,   952,   861,   862,   999,
       0,   405,     0,  1000,  1006,   893,   848,   872,  1001,   213,
     894,   875,   882,   891,   885,   953,   839,   844,   843,   842,
     841,   840,   806,   860,     0,   810,     0,   907,   832,   472,
     476,   477,   941,   940,   942,   816,   815,   835,   947,   799,
     939,   944,   945,   936,   838,   880,   938,   948,   946,   937,
     836,   943,   957,   958,   955,   956,   954,   807,   959,   960,
     961,   927,   926,   913,   830,   823,   920,   916,   833,   829,
     928,   261,   819,   820,   813,   822,   925,   924,   921,   917,
     934,   935,   933,   923,   919,   912,   821,   932,   931,   825,
     827,   826,   918,   922,   914,   828,   915,   824,   930,   983,
     984,   985,   986,   987,   988,   964,   965,   963,   969,   970,
     971,   966,   967,   968,   837,   989,   990,   991,   992,   993,
     994,   995,     0,     0,  1007,  1008,  1009,  1011,  1010,  1012,
     167,   167,     0,     2,   167,     9,    11,    25,     0,    30,
      33,    38,    39,    40,    41,    42,    43,    44,    34,    60,
      61,    35,    36,     0,    78,    81,    82,    37,    83,    84,
       0,   120,    85,    86,    87,    88,    20,   164,   165,   166,
     173,   176,   464,   177,     0,   178,   179,   180,   181,   182,
     183,   184,   187,   188,     0,   214,   222,   217,   249,   255,
       0,   247,     0,   248,   224,   218,   186,   219,   185,   220,
     223,   357,   359,   361,   371,   373,   377,   379,   382,   387,
     390,   393,   395,   397,   399,     0,   403,   410,   409,   411,
       0,   429,   412,   434,   435,   436,   443,   455,   469,   471,
     456,   457,   458,   461,   462,   459,   463,   490,   491,   460,
     494,   496,   497,   498,   495,   543,   544,   545,   546,   547,
     548,   549,   470,    45,   225,   226,   228,   227,   229,   221,
     466,   467,   468,   465,   231,   234,   230,   232,   233,     0,
     791,   808,   901,   910,   908,   810,     0,   168,   169,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   279,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   793,   818,   796,   849,   911,
     798,   859,   800,   870,   803,   805,   804,   888,   792,   847,
     871,   895,   952,   953,   947,   939,   945,   936,   836,   957,
     958,   955,   807,   959,   929,  1008,   478,   791,     0,   789,
     769,     0,     0,   214,     0,     0,   790,   798,   805,   804,
       0,     0,   763,   959,     0,   222,     0,   479,     0,   510,
       0,     0,     0,   790,   432,   433,     0,     0,     0,   539,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     765,     0,   767,     0,     0,   167,     3,     4,     1,    10,
      12,     0,     0,     0,     0,     6,   167,     0,   167,     0,
       0,   121,   174,     0,     0,   192,     0,     0,   201,     0,
     260,     0,     0,     0,     0,     0,     0,   261,   206,   235,
     254,   250,   256,   251,   253,   252,     0,   259,     0,     0,
       0,     0,     0,     0,     0,   422,     0,     0,   420,     0,
     366,     0,   421,   414,   419,   418,   417,   416,   415,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   408,   407,
     404,     0,     0,   430,     0,     0,     0,   444,   452,     0,
       0,   551,   553,   557,   559,     0,   126,     0,   788,    49,
      46,    47,    50,    51,     0,     0,     0,     0,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     622,   623,   624,     0,   105,   144,     0,     0,   114,     0,
       0,     0,     0,   129,     0,     0,     0,     0,     0,   136,
       0,   140,   170,   493,     0,    62,     0,    71,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,   328,     0,
       0,     0,     0,     0,   613,     0,     0,     0,     0,   196,
       0,     0,   190,   189,     0,     0,   770,     0,     0,     0,
       0,   478,     0,   764,     0,   480,   511,   510,   507,     0,
       0,     0,   541,   540,   431,     0,   538,     0,     0,   635,
     636,   779,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   641,     0,   204,   205,     0,     0,     0,     0,
       0,   209,   210,   766,   768,     0,     5,    26,     0,    27,
       0,     7,    31,     0,    17,     8,    32,     0,    21,   901,
      79,    18,    80,    22,   195,     0,   193,   215,   216,     0,
       0,     0,     0,   207,   236,   297,   258,   262,     0,   237,
     238,   257,     0,     0,   358,   360,   364,   370,   369,   368,
       0,   365,   362,   363,     0,   374,   381,   380,   378,   384,
     385,   386,   383,   388,   389,   392,   391,     0,     0,     0,
       0,   413,   427,     0,   451,   449,   448,   450,   447,     0,
     486,   445,   488,     0,   453,   492,   484,     0,     0,   123,
     125,     0,     0,     0,   104,     0,    94,    96,    97,    98,
      99,   101,   102,   103,    95,   100,    90,    91,     0,     0,
     110,     0,   106,   108,   109,   116,     0,     0,    89,    48,
       0,     0,     0,     0,     0,     0,     0,   713,   718,     0,
       0,   714,   748,   701,   703,   704,   705,   707,   709,   708,
     706,   710,     0,     0,     0,     0,     0,   113,     0,   146,
       0,     0,   556,   550,     0,   142,     0,     0,   137,     0,
       0,     0,     0,     0,     0,    64,     0,     0,     0,     0,
     278,   284,   281,     0,     0,     0,     0,     0,   555,     0,
       0,     0,   423,     0,     0,     0,     0,   197,     0,     0,
     772,     0,     0,   771,     0,     0,     0,   510,   508,     0,
     499,     0,     0,   482,   483,     0,    13,     0,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   202,     0,     0,
       0,   440,   441,   442,   439,   649,   438,     0,   437,   211,
       0,     0,     0,     0,   167,     0,   167,     0,   175,   246,
       0,   312,   308,   310,     0,   298,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,     0,   245,
     367,     0,     0,     0,     0,   679,   375,   652,   656,   658,
     660,   662,   665,   672,   673,   681,   793,   794,   796,   911,
     795,   800,   801,   802,   803,   792,   797,     0,   806,   799,
    1011,  1010,   785,  1012,   394,   562,   568,   569,   588,   579,
     587,   586,   585,   584,   581,   583,   580,   582,   572,   616,
     617,   573,   574,   782,   783,   784,   577,   396,   398,   401,
     578,   400,   428,   454,     0,   446,   485,   127,    58,    59,
      56,    57,   133,   132,     0,    92,     0,     0,   111,   112,
     117,    76,    77,    54,    55,    75,   719,     0,   722,   749,
       0,   712,   711,   716,   715,   747,     0,     0,   724,     0,
     720,   723,   702,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   145,   148,   150,     0,     0,
       0,   115,   118,     0,     0,     0,   170,   143,   138,   141,
       0,   191,     0,     0,    73,    67,    70,    69,     0,    65,
     561,   282,     0,     0,   170,     0,   326,   330,     0,     0,
       0,   333,     0,     0,   339,     0,     0,   346,     0,   350,
       0,   425,   424,   170,   198,     0,   200,   327,     0,     0,
       0,     0,     0,   511,     0,   501,     0,   534,   531,     0,
     535,   536,     0,     0,   530,     0,   505,   533,   532,     0,
       0,     0,     0,     0,   628,   629,   625,     0,     0,   633,
     634,   630,   775,   776,   639,   780,   637,     0,     0,     0,
       0,   643,   798,   805,   804,   959,   203,     0,     0,     0,
     644,   645,     0,     0,   212,   778,    28,     0,    19,    23,
      24,   309,   321,     0,   322,     0,   313,   314,   315,   316,
       0,   301,     0,     0,   264,     0,     0,   265,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   241,     0,     0,
       0,     0,   291,     0,   288,   293,   244,     0,     0,   663,
     676,     0,   372,   376,     0,   695,     0,     0,     0,     0,
       0,     0,   651,   653,   654,   690,   691,   692,   694,   693,
       0,     0,   667,   666,     0,   670,   674,   688,   686,   685,
     678,   682,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   565,
     567,   566,   563,   402,   487,   489,   135,   134,    93,   107,
     736,   717,     0,   741,     0,   741,   730,   725,   149,   151,
       0,     0,     0,   119,   147,     0,    29,     0,   139,     0,
       0,    72,     0,    66,   283,     0,     0,   329,   331,   336,
       0,   334,     0,     0,     0,     0,     0,   340,     0,     0,
     354,     0,     0,   347,     0,     0,   351,   426,     0,   199,
     773,   774,     0,     0,   510,     0,     0,   542,     0,   510,
       0,   506,     0,    14,    16,     0,     0,     0,     0,     0,
       0,     0,   642,     0,     0,     0,     0,     0,     0,   646,
     650,   325,   323,   324,   317,   318,   319,   311,     0,     0,
     306,     0,   300,   263,     0,     0,   277,   269,     0,   273,
       0,   267,     0,     0,     0,   286,     0,     0,     0,   243,
     289,   292,     0,   680,   671,   677,     0,     0,   750,   751,
     761,   760,   759,     0,     0,     0,     0,   752,   657,   758,
       0,   655,   659,     0,     0,   664,   668,     0,   689,   684,
     687,   683,   595,   590,     0,     0,   605,     0,     0,     0,
       0,   575,     0,   593,     0,   596,     0,     0,     0,   594,
     599,     0,     0,   570,   621,   564,   589,   786,   787,   571,
     737,     0,     0,   735,   742,   743,   739,     0,   734,     0,
     732,     0,     0,     0,     0,     0,     0,   552,     0,     0,
       0,    68,   285,   558,     0,     0,   337,   341,   335,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   554,     0,     0,   510,     0,   537,     0,   510,   560,
     626,   627,   631,   632,     0,   638,   781,   640,     0,     0,
       0,     0,   647,   320,   307,   302,     0,   266,     0,   275,
       0,     0,   271,     0,   274,   287,   295,   296,   290,   242,
     675,   762,     0,     0,   754,     0,   700,   699,   698,   697,
     696,   661,     0,   753,   591,   592,     0,   609,     0,   606,
       0,   618,     0,     0,   598,   597,   604,   612,     0,   602,
       0,   600,   746,   745,   744,     0,   738,   731,   729,     0,
     726,   727,   721,   152,   154,   156,     0,     0,     0,     0,
       0,   208,   356,    74,   332,   338,     0,   352,   348,   355,
       0,     0,     0,   342,     0,     0,   344,     0,   520,   514,
     509,     0,   510,   500,     0,   777,     0,     0,     0,     0,
     305,   303,   270,   268,     0,   276,     0,   756,   755,     0,
       0,     0,     0,   613,     0,     0,   619,   576,     0,     0,
       0,   740,   733,     0,     0,   158,   157,     0,     0,     0,
       0,   153,     0,     0,     0,     0,     0,   528,   522,     0,
     521,   523,   529,   526,   516,     0,   515,   517,   527,   502,
       0,   503,     0,     0,   648,   304,   272,     0,   757,   669,
     610,   611,   614,   607,   608,   620,   603,   601,   728,   155,
     159,     0,     0,     0,     0,     0,     0,   345,   343,     0,
       0,   513,   524,   525,   512,   518,   519,   504,     0,   294,
     160,     0,     0,     0,   353,   349,     0,     0,     0,     0,
       0,     0,     0,     0,   162,     0,     0,   161,     0,     0,
       0,     0,     0,     0,     0,     0,   163
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yypgoto_[] =
  {
     -1494, -1494,  -188,  -192, -1494,  1233,  1234, -1494,  1220,  -454,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
    -901, -1494, -1494, -1494, -1494,  -207,  -511, -1494,   807,   118,
   -1494, -1494, -1494, -1494, -1494,   358,   600, -1494, -1494,     9,
     -96,  1074, -1494,  1065, -1494, -1494,  -589, -1494,   556, -1494,
     321, -1494,  -185,  -233, -1494,  -433, -1494,    12,   155,    86,
    -266,  -168, -1494,  -803, -1494, -1494,  -385, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494,   723, -1494,   -95,
    1341,     0, -1494, -1494, -1494, -1494,   453, -1494, -1494,  -293,
   -1494,     5, -1494, -1494,   905,  -978,  -772,  -768, -1494, -1494,
     791, -1494, -1494,    17,   196, -1494, -1494, -1494,   217, -1493,
   -1494,   480,   221, -1494, -1494,   225, -1226, -1494,  1015,   319,
   -1494, -1494,   318,  -927, -1494, -1494,   317, -1494, -1494, -1174,
   -1152, -1494,   307, -1357, -1494, -1494,   921,   923, -1494,  -503,
     903, -1494, -1494,  -591,   412,  -585,   409,   421, -1494, -1494,
   -1494,   674, -1494, -1494,  1200, -1494, -1494, -1494, -1494, -1494,
    -742,  -315,  -610, -1494, -1494,   254, -1494,  -483, -1494,   883,
   -1494,  -377, -1494, -1494,   888,   894, -1494, -1494, -1494, -1494,
     879, -1494, -1494, -1494, -1494,  -928, -1494,   305, -1494,   788,
    -721, -1494, -1494, -1494, -1494, -1494,  -219,  -210, -1164, -1020,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494,  -689,  -809,  -109,  -771, -1494, -1494, -1494,  -851, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494,   189,   191,  -663,
    -100,  -595, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
   -1494, -1494, -1494,   292, -1494, -1494,   276, -1494,   284,  -997,
   -1494, -1494, -1494,   220,   214,    39,   502, -1494, -1494, -1494,
   -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494, -1494,
     223, -1494, -1494, -1494,    47,   496,   637, -1494, -1494, -1494,
   -1494, -1494,   411, -1494, -1494, -1474, -1494, -1494, -1494,  -492,
   -1494,   177, -1494,     7, -1494, -1494, -1494, -1494, -1271, -1494,
     233, -1494, -1494, -1494, -1494, -1494,  1027, -1494, -1494, -1494,
   -1494, -1494,  -849, -1494, -1494, -1494,  -368,  -102,    46,   830,
   -1494
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   252,   567,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
    1174,   700,   270,   271,   272,   273,   274,   275,   876,   877,
     878,   276,   277,   278,   882,   883,   884,   279,   423,   280,
     281,   645,   282,   425,   426,   427,   433,   690,   691,   283,
    1155,   284,  1663,  1664,   285,   286,   287,   491,   288,   289,
     290,   291,   292,   693,   293,   294,   454,   295,   296,   297,
     298,   299,   300,   578,   301,   302,   771,   772,   303,   304,
     305,   505,   307,   579,   591,  1038,  1039,   308,   580,   309,
     582,   506,   311,   312,   806,   807,  1302,   440,   313,   441,
     442,   813,  1303,  1304,  1305,   583,   584,  1025,  1026,  1460,
     585,  1022,  1023,  1276,  1277,  1278,  1279,   314,   707,   708,
     315,  1190,  1191,  1402,   316,  1193,  1194,   317,   318,  1196,
    1197,  1198,  1199,  1409,   319,   320,   321,   322,   820,   323,
     324,  1312,   325,   326,   327,   328,   329,   330,   331,   332,
     333,  1098,   334,   335,   336,   337,   609,   610,   338,   339,
     340,   341,   342,   343,   344,  1005,  1006,   345,   637,   638,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     853,   356,   357,   358,   359,   360,   361,  1225,   737,   738,
     739,  1690,  1745,  1746,  1739,  1740,  1747,  1741,  1226,  1227,
     362,   363,  1228,   364,   365,   366,   367,   368,   369,   370,
     371,   939,  1410,  1362,  1075,  1522,  1076,  1099,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,   713,
    1712,   372,  1088,  1089,  1090,  1091,   373,   374,   375,   376,
     377,   378,   761,   762,   379,  1260,  1261,  1602,  1007,  1046,
    1322,  1323,  1047,  1048,  1049,  1050,  1051,  1332,  1505,  1506,
    1052,  1335,  1053,  1486,  1054,  1055,  1340,  1341,  1511,  1509,
    1324,  1325,  1326,  1327,  1629,   674,   903,   904,   905,   906,
     907,   908,  1140,  1552,  1660,  1141,  1550,  1658,   909,  1375,
    1547,  1543,  1544,  1545,   910,   911,  1328,  1336,  1496,  1329,
    1492,  1313,   380,   381,   382,   383,   494,   384,   385,   386,
     387,   388,  1092,  1093,  1094,  1095,  1175,   495,   389,   390,
     391
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -930;
  const short int
  jsoniq_parser::yytable_[] =
  {
       306,   306,   306,   306,   306,   310,   310,   310,   310,   310,
     539,   504,   508,   396,   399,   400,   969,   581,   512,   424,
     947,   841,  1192,   562,   828,   633,   646,   646,  1074,  1097,
     957,   829,   830,   831,   832,  1179,  1031,   649,  1423,   847,
    1032,   751,   555,  1224,  1413,  1308,   757,   790,   792,  1284,
     554,  1455,  1456,   555,  1575,     7,     8,  1579,   546,   547,
    1113,  1431,  1156,  1507,  1157,  1666,  1291,   863,   697,   701,
     557,  1035,   555,   555,  1028,   742,   409,  1661,   438,   555,
       7,     8,  1044,   994,   555,   559,   410,   398,   398,   398,
     402,   816,   555,   817,   818,   555,   819,   555,   821,     9,
    1145,   409,   782,   786,   412,   306,   822,   823,  1117,   413,
     310,   555,  1700,   555,  1688,   555,  1493,  1168,  1149,  1033,
     564,   528,   555,   784,   788,   791,   793,  1029,  1180,   412,
     555,   486,   562,   937,   555,  1029,   562,  1541,  1029,   555,
     518,   414,   415,  1017,   725,   555,  1403,   541,   543,     9,
     566,   496,   970,   937,   509,   634,   397,   397,   397,   401,
    1182,   566,  1215,   892,   658,   893,   513,   680,   516,   622,
     555,  1183,   654,   555,   555,   794,  1667,   428,  1292,   796,
     566,    77,   975,   623,   561,   555,  1030,   566,   655,  1464,
     635,   492,   636,  1143,   563,    87,  1120,   659,  1144,  1145,
    1288,   938,  1542,   565,  1689,   566,   648,  1146,  1755,   894,
     529,   429,   555,   581,  1147,   995,  1148,  1149,  1493,   971,
     101,   726,  -171,   555,  1041,  1150,   562,  1042,  1603,  1216,
     566,    77,  1404,   725,  1036,   555,  1167,   439,   566,   555,
     403,   976,   566,  1513,   743,    87,  1214,   566,   122,  1768,
     306,   306,  1151,   566,   306,   310,   310,   924,  1668,   310,
     397,  1293,  1431,  1289,   556,  1294,  1406,   735,   790,   792,
     101,  1413,  -172,   555,  1037,   558,  1114,  1393,   566,  1659,
    1494,   566,   566,   777,   979,   930,   779,   555,  1224,   306,
     149,   150,   151,   566,   310,   439,  1353,  1224,  1472,   889,
    1044,  1044,  1014,   563,  1016,  1463,  1266,   563,   439,   803,
     949,  1367,  1156,  1485,  1157,   669,   439,  1040,   950,  1732,
     566,   420,   998,   782,   786,   519,   684,  1210,   561,   421,
     439,   566,   935,  1211,  1043,   724,   687,   422,   696,   694,
     149,   150,   151,   566,   555,  1296,   681,   566,   706,   783,
     787,   711,   712,   776,   682,   648,   555,   718,  1212,   733,
     774,  1388,  1696,   988,   895,   778,   780,   405,   406,   773,
     407,   408,   522,  1697,   523,   795,  1776,   896,  1779,   897,
     555,   566,  1494,  1495,  1152,  1403,  1488,   944,   411,  1403,
     898,   899,   900,   688,   901,   566,   902,   563,   306,   944,
    1698,  1576,   306,   310,   555,  1622,  1314,   310,  -171,   858,
    1372,  1273,   980,   981,  1687,   740,   741,   404,   555,  1108,
     555,  1103,   745,   430,   943,   555,  1489,   982,   439,   306,
     306,   525,  1275,   526,   310,   310,  1109,   858,   432,  1725,
     698,   555,   767,   769,  1267,   306,   555,  1045,   977,   306,
     310,   987,   566,   431,   310,   586,   657,   587,  -172,   661,
    1029,   524,   689,   513,   566,   448,   675,   676,   945,  1577,
    1374,  1565,   955,  1383,   513,  1570,  1153,  1154,  1072,  1315,
     959,  1107,  1577,  1623,   702,     7,     8,   699,   566,   859,
     709,   417,   306,   551,   714,  1217,  1218,   310,  1224,   719,
    1770,   306,   562,   790,   792,   790,   310,   978,   434,   552,
    1248,  1610,   566,  1465,   443,   402,   402,   860,  1121,  1122,
     527,  1368,   588,  1125,  1753,  1473,   566,   589,   566,  1018,
     937,   402,   848,   566,   709,   402,  1521,   843,   306,  1314,
     849,   972,   449,   310,  1490,   306,   731,   496,  1380,   566,
     310,  1491,   444,  1165,   566,   418,   306,   306,   306,   306,
     424,   310,   310,   310,   310,   973,  1316,  1317,  1044,  1318,
    1011,   634,   560,   496,   590,   306,  1319,  1044,   956,   763,
     310,  1268,  1269,  1270,   685,   686,  1320,   398,  1044,   974,
     937,  1219,  1461,  1262,   931,  1015,   419,   934,  1321,   780,
     710,  1413,   613,  1000,   715,  1102,   635,   983,   636,   927,
    1483,  1220,  1315,  1221,   450,   451,  1104,   664,  1601,   665,
     614,   569,   530,   962,   768,   570,  1754,   531,   937,   445,
     571,  1759,   808,   964,   965,   966,   808,   769,  1104,   446,
    1217,  1222,   569,   946,  1636,   108,   570,  1217,  1218,   572,
    1263,   571,   666,   664,   569,   665,   397,  1638,   570,  1673,
    1743,   632,   120,   571,  1310,  1045,  1045,  1642,  1742,  1748,
     572,  1189,  1648,   999,  1737,  1263,   435,  1650,  1217,   667,
     513,  1295,   572,  1223,  1400,   122,   436,   453,   122,   928,
     879,   447,   306,  1441,  1217,  1218,  1105,   310,  1611,  1316,
    1317,   144,  1318,  1583,   929,  1655,  1737,   785,  1587,   885,
    1217,   532,  1189,   437,   990,   667,   306,   306,  1106,  1320,
    1742,   310,   310,   915,  1637,  1405,  1748,   919,   920,   633,
    1500,  1321,  1256,   880,   925,   984,   985,  1639,   881,   634,
    1013,   668,   513,  1219,   613,   513,   650,  1643,   573,   940,
     986,   574,  1649,   452,   678,   790,  1220,  1651,  1221,   679,
     651,  1044,   614,  1220,  1679,  1221,   575,  1744,   306,   573,
    1406,   496,   574,   310,   635,  1556,   636,   668,   398,   488,
     616,   573,   967,   510,   574,  1656,  1222,   734,  1411,   511,
    1219,  1110,   576,  1222,  1220,   306,  1221,   108,   424,  1447,
     310,  1412,   402,   402,  1738,  1391,     7,     8,  1111,   617,
    1220,   795,  1221,   576,   120,  1137,  1008,   405,   406,  -849,
     407,   408,   618,   780,  1222,   576,  1220,   409,  1221,  1372,
     937,  1716,  1138,  1717,   517,  1425,  1782,   410,   411,  1264,
    1222,   577,  1458,  -849,   108,  1019,  1373,   397,  1359,  1112,
    1217,  1217,  1218,   144,  -849,   412,  1222,   619,  1034,  1626,
     413,   120,   577,  1691,  1298,   692,  1627,  1694,  1298,  1299,
    1743,   953,   954,  1299,   577,  1139,  1628,   785,  1459,   613,
    1360,   613,  1430,  1096,  1096,  1100,  1100,   620,  1300,  1374,
    1123,  1124,   414,   415,   416,  -929,   621,   614,  1361,   614,
     144,  1137,  1621,  1624,  1625,  1451,  1389,  1029,  1572,  1765,
    1012,  1029,  1681,  1272,  1414,   487,  1685,     9,  1138,  -929,
     615,  1232,  1709,  1233,  1273,  1096,   552,  1415,  1366,  1301,
    -929,  1775,  1573,  1045,  1274,  1796,  1573,  1797,   487,  1130,
    1573,   417,  1045,  1665,   692,  1275,  1307,  1219,   652,  1131,
     487,   306,   487,  1045,  1159,  1573,   310,  1337,  1338,  1573,
    1132,  1573,   653,  1160,  1162,   581,  1220,  1220,  1221,  1221,
     533,  1750,  1096,  1711,  1626,  1714,  1726,  1785,   937,  1411,
    1339,  1627,  1411,  1096,   880,  1719,   520,  1720,  1298,   881,
    1273,  1628,  1582,  1299,  1115,  1788,  1222,  1222,  1257,    77,
    1237,   108,  1238,  1258,   521,   418,  1115,   670,   671,   672,
     534,  1452,  1453,    87,   306,   306,   306,  1133,   120,   310,
     310,   310,   424,   535,  1561,   826,   827,   537,  1134,   833,
     834,  1707,  1708,   538,  1126,  1127,  1128,   402,   101,  1585,
    1129,   536,  1041,   835,   836,  1042,   419,  1378,  1379,  1652,
    1653,   548,   544,   568,   592,   593,   594,   144,   612,   611,
    1665,   624,   625,   626,   595,   596,   122,   597,   627,   631,
    1281,   639,   420,   808,   640,   598,   641,   642,   643,   599,
     421,   600,   644,   648,   660,   662,   601,   539,   422,   663,
    1604,   866,   867,   868,   869,   870,   871,   872,   873,   874,
     875,   673,   677,   602,   692,   695,  1200,   703,   149,   150,
     151,   704,   705,  1096,  1665,   720,   722,   716,  1758,   724,
     717,   727,   736,   732,   728,   744,  1045,   603,   604,   605,
     606,   607,   608,   729,   730,   746,   747,   748,  1567,   759,
     760,   781,   764,   765,   770,   799,   801,   800,   809,   810,
     802,   812,   824,   838,   837,   839,   840,   635,   855,   861,
     864,   862,   886,   890,   887,   912,   306,   891,   913,   914,
     916,   310,   306,   921,   918,   922,   923,   310,  1387,   926,
     932,   803,   933,   936,   306,   948,   989,   951,   991,   310,
     952,   993,   996,  1807,   992,  1808,  1396,   997,  1010,  1013,
    1020,  1024,  1027,   306,  1116,  1816,   881,   937,   310,  1135,
    1136,  1163,  1158,  1164,   688,  1418,  1096,  1170,  1166,  1172,
    1176,  1171,   306,  1173,  1178,  1177,  1184,   310,  1188,   306,
    1185,   709,  1201,  1189,   310,  1195,  1205,  1206,  1213,   656,
     487,  1096,  1202,   487,  1230,  1526,  1208,   487,  1209,  1231,
     487,   487,   398,  1203,  1229,  1249,   666,  1259,   487,  1280,
    1282,  1285,  1257,  1286,  1311,  1290,  1334,  1258,   487,  1429,
     398,  1297,  1330,     9,   487,  1342,  1343,  1344,   487,  1331,
    1345,  1371,  1346,   487,  1370,  1347,  1348,  1349,  1376,   398,
    1381,  1363,  1671,  1382,  1385,   763,  1392,  1350,  1351,  1352,
    1354,  1386,  1355,  1675,  1567,  1008,  1677,  1356,   402,  1008,
    1357,  1358,  1395,  1422,  1686,   402,  1424,  1411,   487,  1427,
    1417,   397,  1439,  1435,  1444,  1443,  1436,  1437,  1445,   808,
     487,  1446,  1466,  1262,  1438,  1273,  1470,  1468,  1433,   397,
    1434,  1474,  1476,  1440,  1482,  1477,  1478,  1480,   768,  1598,
    1599,  1600,  1484,  1487,  1503,  1504,  1508,  1497,   397,  1510,
    1512,  1523,  1540,   487,  1546,  1529,  1533,  1553,  1551,  1534,
    1535,  1560,  1536,  1537,  1538,  1539,  1557,  1428,  1558,  1549,
    1559,  1606,  1563,  1555,  1432,  1564,  1569,  1580,  1594,  1581,
    1518,  1096,  1586,   513,  1527,  1528,  1589,  1532,  1608,  1620,
    1632,  1634,  1613,  1640,   306,  1635,  1641,  1644,  1657,   310,
    1645,  1646,  1647,  1137,  1670,  1676,   487,  1662,  1458,  1677,
     487,  1704,  1706,  1718,  1721,  1722,  1723,  1554,  1693,  1724,
    1749,  1728,  1729,  1633,  1733,  1734,  1735,  1751,  1757,  1752,
    1762,  1773,  1774,  1760,  1761,  1763,   493,  1257,  1669,  1764,
    1766,  1767,  1258,  1781,  1571,  1780,  1784,  1096,  1799,  1793,
    1096,  1812,  1787,  1798,   487,  1806,  1813,  1771,  1777,  1791,
    1809,  1584,  1800,   888,  1803,  1369,  1588,   553,   647,  1805,
    1118,  1815,  1810,  1169,  1384,  1731,  1389,   549,   550,   683,
     865,  1769,  1306,   487,  1009,   811,   942,  1618,  1481,  1462,
    1271,  1457,  1454,   721,  1397,  1416,  1699,   487,  1401,  1794,
    1407,   487,   487,   814,  1101,   825,   815,  1450,   487,   857,
     854,  1426,   845,  1616,  1617,   968,   487,  1786,   846,   487,
    1783,  1794,  1514,   487,  1515,   630,  1449,  1710,  1715,  1498,
    1777,  1442,  1631,  1448,  1502,  1309,  1501,  1630,  1333,  1142,
    1377,  1654,  1548,  1499,   755,     0,     0,     0,  1257,     0,
       0,     0,     0,  1258,     0,     0,   487,     0,     0,  1257,
    1257,     0,   306,     0,  1258,  1258,     0,   310,     0,     0,
    1257,     0,     0,     0,     0,  1258,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     487,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1096,
    1680,     0,  1682,     0,  1684,     0,     0,     0,     0,   487,
       0,  1692,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   487,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,   487,   487,
     487,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1713,     0,  1713,  1257,  1096,     0,  1096,     0,
    1258,     0,     0,     0,   714,     0,   714,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,     0,  1727,     0,     0,  1730,     0,     0,     0,     0,
       0,     0,  1096,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1736,   306,     0,     0,     0,     0,   310,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,  1257,     0,     0,     0,   487,  1258,     0,     0,
       0,     0,     0,     0,  1096,     0,     0,   487,     0,     0,
       0,     0,     0,     0,  1772,   306,     0,     0,     0,  1096,
     310,  1096,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1257,     0,     0,
       0,     0,  1258,  1789,     0,     0,  1257,     0,     0,     0,
       0,  1258,     0,     0,     0,     0,     0,     0,     0,  1792,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1801,
       0,     0,   493,     0,  1802,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,     0,  1811,   487,     0,  1814,
       0,     0,     0,   749,   750,     0,   752,   753,   754,   756,
       0,   758,     0,     0,     0,     0,     0,   766,     0,     0,
       0,     0,     0,     0,     0,   775,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   797,   798,     0,
       0,     0,     0,     0,     0,     0,   804,   805,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   852,     0,     0,
       0,   852,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     487,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   487,     0,     0,     0,     0,
     917,     0,     0,     0,     0,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   941,     0,     0,     0,     0,
       0,     0,     0,   487,     0,     0,     0,     0,     0,     0,
       0,   958,     0,     0,     0,   960,   961,     0,   963,     0,
       0,     0,     0,     0,     0,   804,     0,     0,     0,   487,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   487,
       0,     0,     0,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,     0,     0,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,     0,   798,     0,     0,     0,
       0,     0,  1021,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,   487,     0,   487,   487,   487,
       0,   487,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   487,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,   487,     0,     0,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   487,     0,  1161,     0,     0,
     487,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1181,
       0,     0,     0,     0,     0,     0,  1186,  1187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1204,     0,     0,
    1207,     0,     0,     0,     0,     0,     0,   487,   487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1234,  1235,  1236,     0,  1239,  1240,  1241,  1242,  1243,
    1244,  1245,  1246,  1247,     0,     0,  1250,  1251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1021,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1287,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,   487,     0,   487,     0,   487,     0,
       0,     0,     0,     0,     0,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1365,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,   487,     0,
     487,     0,   487,     0,     0,     0,     0,     0,   487,     0,
     487,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   487,     0,     0,   487,
       0,     0,     0,     0,     0,     0,   487,     0,     0,     0,
       0,     0,     0,  1390,     0,     0,     0,   487,     0,     0,
       0,     0,     0,  1394,     0,     0,     0,     0,     0,  1398,
    1399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1419,     0,   487,  1420,
    1421,     0,     0,     0,     0,     0,     0,     0,   487,     0,
       0,     0,     0,   487,     0,   487,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   487,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1021,     0,   487,     0,     0,     0,     0,   487,  1467,
       0,  1469,     0,  1471,     0,     0,  1475,     0,     0,     0,
     487,  1479,     0,   487,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1562,     0,     0,     0,
       0,     0,     0,     0,  1566,  1568,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1390,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1590,  1591,  1592,  1593,
       0,  1595,  1596,     0,  1597,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1605,     0,     0,     0,     0,  1607,     0,     0,     0,  1609,
       0,     0,     0,  1612,     0,  1614,     0,  1615,     0,     0,
       0,     0,     0,  1619,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1672,     0,     0,     0,     0,  1674,  1568,     0,     0,     0,
       0,     0,     0,  1678,     0,     0,     0,     0,  1683,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1695,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1701,     0,  1702,
       0,  1703,     0,     0,  1705,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1678,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1756,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1778,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -167,   785,     0,     0,     0,
       0,     0,  1790,     0,     0,     0,  1795,     0,     0,     0,
       0,  1778,     0,     0,     0,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     0,     9,     0,  1795,     0,    10,
     393,  1804,    12,    13,    14,    15,    16,    17,    18,    19,
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
       0,     0,     0,   126,     0,   127,   128,   129,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
     144,     0,   395,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,   243,     0,   244,   245,   246,   247,   248,
       0,   249,  -167,   785,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   789,   393,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   394,    26,    27,    28,    29,    30,     0,    31,
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
     126,     0,   127,   128,   129,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   395,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   785,
     243,     0,   244,   245,   246,   247,   248,     0,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   392,   393,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   394,    26,
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
     129,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   395,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   785,   243,     0,   244,   245,
     246,   247,   248,     0,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   392,   393,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   497,   394,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   498,   499,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   469,    80,
      81,    82,    83,    84,   500,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   501,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   395,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   479,   480,
     481,   175,   176,   482,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,   243,     0,   244,   245,   246,   247,   248,     0,
     249,  1001,  1002,     0,     0,     0,     0,     0,     0,     0,
    1003,     0,     0,     0,     0,     5,     6,     0,     0,     0,
       0,     0,     0,     0,   392,   393,     0,    12,    13,    14,
     455,    16,    17,    18,   456,    20,   457,   458,   459,   460,
     394,    26,   461,    28,    29,    30,     0,    31,    32,    33,
      34,   462,    36,    37,    38,    39,    40,    41,    42,   463,
       0,    44,   464,    46,   465,   466,    49,   467,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   468,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   469,    80,    81,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   470,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   110,   471,     0,     0,     0,     0,   112,   113,   114,
     115,   472,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,  1004,     0,   130,     0,
     131,   132,   133,   134,   473,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,     0,     0,   395,     0,   147,
     148,     0,     0,     0,   152,   153,   154,   155,   156,   157,
     474,   159,   475,   161,   476,   477,   164,   165,   166,   167,
     168,   169,   478,   171,   479,   480,   481,   175,   176,   482,
     483,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   484,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,     0,     0,     0,
     244,   485,   246,   247,   248,   489,   249,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,   392,   393,     0,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   394,
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
       0,   123,   124,   125,     0,   490,     0,   126,     0,   127,
     128,   129,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,   142,   143,   144,     0,   395,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,   243,     0,   244,
     245,   246,   247,   248,   489,   249,     0,     0,     0,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   392,   393,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   497,   394,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   498,   499,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   469,    80,    81,    82,    83,    84,   500,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   501,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   395,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   479,   480,   481,   175,   176,   482,   503,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,   489,   244,   245,
     246,   247,   248,     0,   249,     0,     5,     6,     0,     0,
       0,     9,     0,     0,     0,   392,   393,     0,    12,    13,
      14,   455,    16,    17,    18,   456,    20,   457,   458,   459,
     460,   394,    26,   461,    28,    29,    30,     0,    31,    32,
      33,    34,   462,    36,    37,    38,    39,    40,    41,    42,
     463,     0,    44,   464,    46,   465,   466,    49,   467,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
     468,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   469,    80,    81,    82,    83,
      84,   500,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   470,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,   104,     0,     0,     0,   107,
       0,     0,   110,   471,     0,     0,     0,     0,   112,   113,
     114,   115,   472,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,   844,     0,   130,
       0,   131,   132,   133,   134,   473,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,     0,     0,   395,     0,
     147,   148,     0,     0,     0,   152,   153,   154,   155,   156,
     157,   474,   159,   475,   161,   476,   477,   164,   165,   166,
     167,   168,   169,   478,   171,   479,   480,   481,   175,   176,
     482,   483,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   484,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,     0,   489,
       0,   244,   485,   246,   247,   248,     0,   249,     5,     6,
       0,     0,     0,  1524,     0,     0,     0,   392,   393,     0,
      12,    13,    14,   455,    16,    17,    18,   456,    20,   457,
     458,   459,   460,   394,    26,   461,    28,    29,    30,     0,
      31,    32,    33,    34,   462,    36,    37,    38,    39,    40,
      41,    42,   463,     0,    44,   464,    46,   465,   466,    49,
     467,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,   468,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   469,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     470,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,   104,     0,     0,
       0,     0,     0,     0,   110,   471,     0,     0,     0,     0,
     112,   113,   114,   115,   472,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,  1525,   127,   128,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   473,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,     0,     0,
     395,     0,   147,   148,     0,     0,     0,   152,   153,   154,
     155,   156,   157,   474,   159,   475,   161,   476,   477,   164,
     165,   166,   167,   168,   169,   478,   171,   479,   480,   481,
     175,   176,   482,   483,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   484,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
       0,   489,     0,   244,   485,   246,   247,   248,     0,   249,
       5,     6,     0,     0,     0,     0,     0,     0,     0,   392,
     393,     0,    12,    13,    14,   455,    16,    17,    18,   456,
      20,   457,   458,   459,   460,   394,    26,   461,    28,    29,
      30,     0,    31,    32,    33,    34,   462,    36,    37,    38,
      39,    40,    41,    42,   463,     0,    44,   464,    46,   465,
     466,    49,   467,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,   468,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   469,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   470,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,   104,
       0,     0,     0,     0,     0,     0,   110,   471,     0,     0,
       0,     0,   112,   113,   114,   115,   472,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   473,
     136,   137,   138,   139,   140,   141,     0,     0,   142,   143,
       0,     0,   395,     0,   147,   148,     0,     0,     0,   152,
     153,   154,   155,   156,   157,   474,   159,   475,   161,   476,
     477,   164,   165,   166,   167,   168,   169,   478,   171,   479,
     480,   481,   175,   176,   482,   483,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   484,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,     0,     0,     0,   244,   485,   246,   247,   248,
       0,   249,   514,   515,     0,     0,     0,     0,     0,     5,
       6,     0,     0,     0,     0,     0,     0,     0,   392,   393,
       0,    12,    13,    14,   455,    16,    17,    18,   456,    20,
     457,   458,   459,   460,   394,    26,   461,    28,    29,    30,
       0,    31,    32,    33,    34,   462,    36,    37,    38,    39,
      40,    41,    42,   463,     0,    44,   464,    46,   465,   466,
      49,   467,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   468,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   469,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   470,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,   104,     0,
       0,     0,     0,     0,     0,   110,   471,     0,     0,     0,
       0,   112,   113,   114,   115,   472,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   473,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,     0,
       0,   395,     0,   147,   148,     0,     0,     0,   152,   153,
     154,   155,   156,   157,   474,   159,   475,   161,   476,   477,
     164,   165,   166,   167,   168,   169,   478,   171,   479,   480,
     481,   175,   176,   482,   483,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   484,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,     0,     0,     0,   244,   485,   246,   247,   248,     0,
     249,     1,     2,     3,     4,     5,     6,     7,     8,     0,
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
     127,   128,   129,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   145,   146,   147,
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
     244,   245,   246,   247,   248,     0,   249,   250,   251,     1,
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
     129,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,     0,   244,   245,
     246,   247,   248,     0,   249,     0,   545,     1,     2,     3,
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
     104,   105,   106,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,   129,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,     0,   244,   245,   246,   247,
     248,     0,   249,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   392,   393,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,   394,    26,    27,    28,    29,    30,     0,    31,
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
     121,   122,     0,     0,   123,   124,   125,     0,   723,     0,
     126,     0,   127,   128,   129,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   395,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     243,     0,   244,   245,   246,   247,   248,     0,   249,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   392,   393,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   394,    26,
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
     129,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   395,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,     0,   244,   245,
     246,   247,   248,     0,   249,     1,     2,     3,     4,     5,
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
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,   129,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   395,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,   243,     0,   244,   245,   246,   247,   248,     0,
     249,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,    10,   393,     0,    12,    13,    14,
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
     127,   128,   129,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   395,     0,   147,
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
     244,   245,   246,   247,   248,     0,   249,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     789,   393,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,   394,    26,    27,    28,
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
     125,     0,     0,     0,   126,     0,   127,   128,   129,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   395,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,     0,   244,   245,   246,   247,
     248,     0,   249,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,   392,   393,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,  1252,   394,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,  1253,  1254,    49,    50,
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
     126,     0,   127,   128,   129,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   395,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,  1255,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     243,     0,   244,   245,   246,   247,   248,     0,   249,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   392,   393,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   497,   394,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   498,   499,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   469,    80,    81,    82,    83,    84,   500,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,   850,     0,    98,    99,   100,   101,
     102,   103,   104,   501,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,   851,   127,   128,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   395,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   479,   480,   481,   175,   176,   482,   503,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,     0,   244,   245,
     246,   247,   248,     0,   249,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   392,   393,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   497,   394,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   498,   499,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   469,    80,
      81,    82,    83,    84,   500,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
     850,     0,    98,    99,   100,   101,   102,   103,   104,   501,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
       0,     0,   126,   856,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   395,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   479,   480,
     481,   175,   176,   482,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,   243,     0,   244,   245,   246,   247,   248,     0,
     249,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   392,   393,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   497,
     394,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   498,   499,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   469,    80,    81,    82,    83,    84,
     500,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,   104,   501,   106,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,   502,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   395,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   479,   480,   481,   175,   176,   482,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,   243,     0,
     244,   245,   246,   247,   248,     0,   249,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     392,   393,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   497,   394,    26,    27,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     0,    44,    45,    46,
     498,   499,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     469,    80,    81,    82,    83,    84,   500,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,    93,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   501,   106,     0,   107,   108,   109,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   121,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,   507,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   395,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     479,   480,   481,   175,   176,   482,   503,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,     0,   244,   245,   246,   247,
     248,     0,   249,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   392,   393,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   497,   394,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   498,   499,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   469,    80,    81,    82,
      83,    84,   500,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   501,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   395,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   479,   480,   481,   175,
     176,   482,   503,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   540,
     243,     0,   244,   245,   246,   247,   248,     0,   249,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   392,   393,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   497,   394,    26,
      27,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     0,    44,
      45,    46,   498,   499,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   469,    80,    81,    82,    83,    84,   500,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,    93,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   501,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   395,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   479,   480,   481,   175,   176,   482,   503,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,   542,   244,   245,
     246,   247,   248,     0,   249,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   392,   393,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   497,   394,    26,    27,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,     0,    44,    45,    46,   498,   499,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   469,    80,
      81,    82,    83,    84,   500,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,    93,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   501,
     106,     0,   107,   108,   109,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,   121,   122,     0,     0,   123,   124,   125,     0,
     842,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   395,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   479,   480,
     481,   175,   176,   482,   503,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,   243,     0,   244,   245,   246,   247,   248,     0,
     249,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   392,   393,     0,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,   497,
     394,    26,    27,    28,    29,    30,     0,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
       0,    44,    45,    46,   498,   499,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,    71,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,    77,    78,   469,    80,    81,    82,    83,    84,
     500,    86,     0,     0,     0,     0,    87,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,    93,    94,    95,
      96,    97,     0,     0,     0,     0,  1364,     0,    98,    99,
     100,   101,   102,   103,   104,   501,   106,     0,   107,   108,
     109,   110,   111,     0,     0,     0,     0,   112,   113,   114,
     115,   116,   117,   118,   119,     0,   120,     0,   121,   122,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,   144,     0,   395,     0,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   479,   480,   481,   175,   176,   482,
     503,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,   243,     0,
     244,   245,   246,   247,   248,     0,   249,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     392,   393,     0,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,   458,    23,   460,   394,    26,   461,    28,
      29,    30,     0,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   463,     0,    44,    45,    46,
     465,   466,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,    71,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,    77,    78,
     469,    80,    81,    82,    83,    84,   500,    86,     0,     0,
       0,     0,    87,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   470,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,   101,   102,   103,
     104,   501,   106,     0,   107,   108,   628,   110,   111,     0,
       0,     0,     0,   112,   113,   114,   115,   116,   117,   118,
     119,     0,   120,     0,   629,   122,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   142,
     143,   144,     0,   395,     0,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   474,   159,   475,   161,
     476,   477,   164,   165,   166,   167,   168,   169,   478,   171,
     479,   480,   481,   175,   176,   482,   483,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   484,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,   243,     0,   244,   485,   246,   247,
     248,     0,   249,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   392,   393,     0,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   497,   394,    26,    27,    28,    29,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,    44,    45,    46,   498,   499,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,    71,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,    77,    78,   469,    80,    81,    82,
      83,    84,   500,    86,     0,     0,     0,     0,    87,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,    93,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   501,   106,     0,
     107,   108,   109,   110,   111,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   117,   118,   119,     0,   120,     0,
     121,   122,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   142,   143,   144,     0,   395,
       0,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   479,   480,   481,   175,
     176,   482,   503,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
     243,     0,   244,   245,   246,   247,   248,     0,   249,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   392,   393,     0,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,   458,    23,   460,   394,    26,
     461,    28,    29,    30,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,   463,     0,    44,
      45,    46,   465,   466,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,    71,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
      77,    78,   469,    80,    81,    82,    83,    84,   500,    86,
       0,     0,     0,     0,    87,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   470,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   501,   106,     0,   107,   108,   109,   110,
     111,     0,     0,     0,     0,   112,   113,   114,   115,   116,
     117,   118,   119,     0,   120,     0,   121,   122,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   142,   143,   144,     0,   395,     0,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   474,   159,
     475,   161,   476,   477,   164,   165,   166,   167,   168,   169,
     478,   171,   479,   480,   481,   175,   176,   482,   483,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   484,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   243,     0,   244,   485,
     246,   247,   248,     0,   249,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   392,   393,
       0,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   458,    23,   460,   394,    26,   461,    28,    29,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   463,     0,    44,    45,    46,   465,   466,
      49,   467,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,    71,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,    77,    78,   469,    80,
      81,    82,    83,    84,   500,    86,     0,     0,     0,     0,
      87,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   470,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   501,
     106,     0,   107,   108,     0,   110,   111,     0,     0,     0,
       0,   112,   113,   114,   115,   116,   117,   118,   119,     0,
     120,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,     0,   127,   128,     0,     0,     0,     0,
       0,     0,   130,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,   144,
       0,   395,     0,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   474,   159,   475,   161,   476,   477,
     164,   165,   166,   167,   168,   169,   478,   171,   479,   480,
     481,   175,   176,   482,   483,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   484,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,   243,     0,   244,   485,   246,   247,   248,     0,
     249,     5,     6,     0,     0,     0,     0,     0,     0,     0,
     392,   393,     0,    12,    13,    14,  1056,    16,    17,    18,
     456,  1057,  1058,   458,  1059,   460,   394,    26,   461,    28,
    1060,    30,     0,    31,    32,    33,    34,  1061,    36,  1062,
    1063,    39,    40,    41,    42,   463,     0,    44,  1064,    46,
     465,   466,    49,   467,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,  1065,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     469,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   470,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
    1066,     0,     0,     0,  1067,     0,     0,   110,   471,     0,
       0,     0,     0,   112,   113,   114,   115,   472,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,  1519,   127,   128,     0,     0,
       0,     0,  1520,     0,   130,     0,   131,   132,   133,   134,
     473,   136,   137,   138,   139,   140,   141,     0,     0,  1068,
     143,     0,     0,   395,     0,   147,   148,     0,     0,     0,
     152,   153,   154,   155,   156,   157,   474,  1069,   475,   161,
     476,   477,   164,   165,   166,   167,   168,   169,   478,   171,
     479,   480,   481,   175,   176,   482,   483,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   484,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     5,     6,   244,   485,   246,  1070,
    1071,  1072,  1073,   392,   393,     0,    12,    13,    14,  1056,
      16,    17,    18,   456,  1057,  1058,   458,  1059,   460,   394,
      26,   461,    28,  1060,    30,     0,    31,    32,    33,    34,
    1061,    36,  1062,  1063,    39,    40,    41,    42,   463,     0,
      44,  1064,    46,   465,   466,    49,   467,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,     0,    68,    69,    70,  1065,     0,
       0,    72,    73,    74,     0,     0,    75,    76,     0,     0,
       0,     0,    78,   469,    80,    81,    82,    83,    84,  1408,
       0,     0,     0,     0,     0,     0,     0,    88,    89,    90,
      91,     0,    92,     0,     0,     0,   470,    94,    95,    96,
      97,     0,     0,     0,     0,     0,     0,    98,    99,   100,
       0,   102,   103,  1066,     0,     0,     0,  1067,     0,     0,
     110,   471,     0,     0,     0,     0,   112,   113,   114,   115,
     472,   117,   118,   119,     0,     0,     0,     0,     0,     0,
       0,   123,   124,   125,     0,     0,     0,   126,     0,   127,
     128,     0,     0,     0,     0,     0,     0,   130,     0,   131,
     132,   133,   134,   473,   136,   137,   138,   139,   140,   141,
       0,     0,  1068,   143,     0,     0,   395,     0,   147,   148,
       0,     0,     0,   152,   153,   154,   155,   156,   157,   474,
    1069,   475,   161,   476,   477,   164,   165,   166,   167,   168,
     169,   478,   171,   479,   480,   481,   175,   176,   482,   483,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   484,     0,   192,   193,   194,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,     0,     0,     5,     6,   244,
     485,   246,  1070,  1071,  1072,  1073,   392,   393,     0,    12,
      13,    14,  1056,    16,    17,    18,   456,  1057,  1058,   458,
    1059,   460,   394,    26,   461,    28,  1060,    30,     0,    31,
      32,    33,    34,  1061,    36,  1062,  1063,    39,    40,    41,
      42,   463,     0,    44,  1064,    46,   465,   466,    49,   467,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    68,    69,
      70,  1065,     0,     0,    72,    73,    74,     0,     0,    75,
      76,     0,     0,     0,     0,    78,   469,    80,    81,    82,
      83,    84,  1574,     0,     0,     0,     0,     0,     0,     0,
      88,    89,    90,    91,     0,    92,     0,     0,     0,   470,
      94,    95,    96,    97,     0,     0,     0,     0,     0,     0,
      98,    99,   100,     0,   102,   103,  1066,     0,     0,     0,
    1067,     0,     0,   110,   471,     0,     0,     0,     0,   112,
     113,   114,   115,   472,   117,   118,   119,     0,     0,     0,
       0,     0,     0,     0,   123,   124,   125,     0,     0,     0,
     126,     0,   127,   128,     0,     0,     0,     0,     0,     0,
     130,     0,   131,   132,   133,   134,   473,   136,   137,   138,
     139,   140,   141,     0,     0,  1068,   143,     0,     0,   395,
       0,   147,   148,     0,     0,     0,   152,   153,   154,   155,
     156,   157,   474,  1069,   475,   161,   476,   477,   164,   165,
     166,   167,   168,   169,   478,   171,   479,   480,   481,   175,
     176,   482,   483,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   484,     0,   192,   193,   194,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,     0,     0,
       5,     6,   244,   485,   246,  1070,  1071,  1072,  1073,   392,
     393,     0,    12,    13,    14,  1056,    16,    17,    18,   456,
    1057,  1058,   458,  1059,   460,   394,    26,   461,    28,  1060,
      30,     0,    31,    32,    33,    34,  1061,    36,  1062,  1063,
      39,    40,    41,    42,   463,     0,    44,  1064,    46,   465,
     466,    49,   467,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
       0,    68,    69,    70,  1065,     0,     0,    72,    73,    74,
       0,     0,    75,    76,     0,     0,     0,     0,    78,   469,
      80,    81,    82,    83,    84,  1578,     0,     0,     0,     0,
       0,     0,     0,    88,    89,    90,    91,     0,    92,     0,
       0,     0,   470,    94,    95,    96,    97,     0,     0,     0,
       0,     0,     0,    98,    99,   100,     0,   102,   103,  1066,
       0,     0,     0,  1067,     0,     0,   110,   471,     0,     0,
       0,     0,   112,   113,   114,   115,   472,   117,   118,   119,
       0,     0,     0,     0,     0,     0,     0,   123,   124,   125,
       0,     0,     0,   126,     0,   127,   128,     0,     0,     0,
       0,     0,     0,   130,     0,   131,   132,   133,   134,   473,
     136,   137,   138,   139,   140,   141,     0,     0,  1068,   143,
       0,     0,   395,     0,   147,   148,     0,     0,     0,   152,
     153,   154,   155,   156,   157,   474,  1069,   475,   161,   476,
     477,   164,   165,   166,   167,   168,   169,   478,   171,   479,
     480,   481,   175,   176,   482,   483,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   484,     0,
     192,   193,   194,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,     0,     0,     5,     6,   244,   485,   246,  1070,  1071,
    1072,  1073,   392,   393,     0,    12,    13,    14,  1056,    16,
      17,    18,   456,  1057,  1058,   458,  1059,   460,   394,    26,
     461,    28,  1060,    30,     0,    31,    32,    33,    34,  1061,
      36,  1062,  1063,    39,    40,    41,    42,   463,     0,    44,
    1064,    46,   465,   466,    49,   467,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,     0,    68,    69,    70,  1065,     0,     0,
      72,    73,    74,     0,     0,    75,    76,     0,     0,     0,
       0,    78,   469,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    89,    90,    91,
       0,    92,     0,     0,     0,   470,    94,    95,    96,    97,
       0,     0,     0,     0,     0,     0,    98,    99,   100,     0,
     102,   103,  1066,     0,     0,     0,  1067,     0,     0,   110,
     471,     0,     0,     0,     0,   112,   113,   114,   115,   472,
     117,   118,   119,     0,     0,     0,     0,     0,     0,     0,
     123,   124,   125,     0,     0,     0,   126,     0,   127,   128,
       0,     0,     0,     0,     0,     0,   130,     0,   131,   132,
     133,   134,   473,   136,   137,   138,   139,   140,   141,     0,
       0,  1068,   143,     0,     0,   395,     0,   147,   148,     0,
       0,     0,   152,   153,   154,   155,   156,   157,   474,  1069,
     475,   161,   476,   477,   164,   165,   166,   167,   168,   169,
     478,   171,   479,   480,   481,   175,   176,   482,   483,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   484,     0,   192,   193,   194,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,     0,     0,     5,     6,   244,   485,
     246,  1070,  1071,  1072,  1073,   392,   393,     0,    12,    13,
      14,  1056,    16,    17,    18,   456,  1057,  1058,   458,  1059,
     460,   394,    26,   461,    28,  1060,    30,     0,    31,    32,
      33,    34,  1061,    36,  1062,  1063,    39,    40,    41,    42,
     463,     0,    44,  1064,    46,   465,   466,    49,   467,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    68,    69,    70,
    1065,     0,     0,    72,    73,    74,     0,     0,    75,    76,
       0,     0,     0,     0,    78,   469,    80,    81,    82,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,     0,    92,     0,     0,     0,   470,    94,
      95,    96,    97,     0,     0,     0,     0,     0,     0,    98,
      99,   100,     0,   102,   103,  1066,     0,     0,     0,  1067,
       0,     0,   110,   471,     0,     0,     0,     0,   112,   113,
     114,   115,   472,   117,   118,   119,     0,     0,     0,     0,
       0,     0,     0,   123,   124,   125,     0,     0,     0,   126,
       0,   127,   128,     0,     0,     0,     0,     0,     0,   130,
       0,   131,   132,   133,   134,   473,   136,   137,   138,   139,
     140,   141,     0,     0,   142,   143,     0,     0,   395,     0,
     147,   148,     0,     0,     0,   152,   153,   154,   155,   156,
     157,   474,  1069,   475,   161,   476,   477,   164,   165,   166,
     167,   168,   169,   478,   171,   479,   480,   481,   175,   176,
     482,   483,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   484,     0,   192,   193,   194,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,     0,     0,     5,
       6,   244,   485,   246,  1070,  1071,  1072,  1073,   392,   393,
       0,    12,    13,    14,   455,    16,    17,    18,   456,    20,
     457,   458,   459,   460,   394,    26,   461,    28,    29,    30,
       0,    31,    32,    33,    34,   462,    36,    37,    38,    39,
      40,    41,    42,   463,     0,    44,   464,    46,   465,   466,
      49,   467,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,     0,
      68,    69,    70,   468,     0,     0,    72,    73,    74,     0,
       0,    75,    76,     0,     0,     0,     0,    78,   469,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    88,    89,    90,    91,     0,    92,     0,     0,
       0,   470,    94,    95,    96,    97,     0,     0,     0,     0,
       0,     0,    98,    99,   100,     0,   102,   103,   104,     0,
       0,     0,     0,     0,     0,   110,   471,     0,     0,     0,
       0,   112,   113,   114,   115,   472,   117,   118,   119,     0,
       0,     0,     0,     0,     0,     0,   123,   124,   125,     0,
       0,     0,   126,  1516,   127,   128,     0,     0,     0,     0,
    1517,     0,   130,     0,   131,   132,   133,   134,   473,   136,
     137,   138,   139,   140,   141,     0,     0,   142,   143,     0,
       0,   395,     0,   147,   148,     0,     0,     0,   152,   153,
     154,   155,   156,   157,   474,   159,   475,   161,   476,   477,
     164,   165,   166,   167,   168,   169,   478,   171,   479,   480,
     481,   175,   176,   482,   483,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   484,     0,   192,
     193,   194,     0,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
       0,     0,     5,     6,   244,   485,   246,   247,   248,     0,
     249,   392,   393,     0,    12,    13,    14,   455,    16,    17,
      18,   456,    20,   457,   458,   459,   460,   394,    26,   461,
      28,    29,    30,     0,    31,    32,    33,    34,   462,    36,
      37,    38,    39,    40,    41,    42,   463,     0,    44,   464,
      46,   465,   466,    49,   467,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,     0,    68,    69,    70,   468,     0,     0,    72,
      73,    74,     0,     0,    75,    76,     0,     0,     0,     0,
      78,   469,    80,    81,    82,    83,    84,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,     0,
      92,     0,     0,     0,   470,    94,    95,    96,    97,     0,
       0,     0,     0,     0,     0,    98,    99,   100,     0,   102,
     103,   104,     0,     0,     0,     0,     0,     0,   110,   471,
       0,     0,     0,     0,   112,   113,   114,   115,   472,   117,
     118,   119,     0,     0,     0,     0,     0,     0,     0,   123,
     124,   125,     0,     0,     0,   126,  1530,   127,   128,     0,
       0,     0,     0,  1531,     0,   130,     0,   131,   132,   133,
     134,   473,   136,   137,   138,   139,   140,   141,     0,     0,
     142,   143,     0,     0,   395,     0,   147,   148,     0,     0,
       0,   152,   153,   154,   155,   156,   157,   474,   159,   475,
     161,   476,   477,   164,   165,   166,   167,   168,   169,   478,
     171,   479,   480,   481,   175,   176,   482,   483,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     484,     0,   192,   193,   194,     0,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,     0,     0,     5,     6,   244,   485,   246,
     247,   248,     0,   249,   392,   393,     0,    12,    13,    14,
     455,    16,    17,    18,   456,    20,   457,   458,   459,   460,
     394,    26,   461,    28,    29,    30,     0,    31,    32,    33,
      34,   462,    36,    37,    38,    39,    40,    41,    42,   463,
       0,    44,   464,    46,   465,   466,    49,   467,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,     0,    68,    69,    70,   468,
       0,     0,    72,    73,    74,     0,     0,    75,    76,     0,
       0,     0,     0,    78,   469,    80,    81,    82,    83,    84,
    1283,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      90,    91,     0,    92,     0,     0,     0,   470,    94,    95,
      96,    97,     0,     0,     0,     0,     0,     0,    98,    99,
     100,     0,   102,   103,   104,     0,     0,     0,     0,     0,
       0,   110,   471,     0,     0,     0,     0,   112,   113,   114,
     115,   472,   117,   118,   119,     0,     0,     0,     0,     0,
       0,     0,   123,   124,   125,     0,     0,     0,   126,     0,
     127,   128,     0,     0,     0,     0,     0,     0,   130,     0,
     131,   132,   133,   134,   473,   136,   137,   138,   139,   140,
     141,     0,     0,   142,   143,     0,     0,   395,     0,   147,
     148,     0,     0,     0,   152,   153,   154,   155,   156,   157,
     474,   159,   475,   161,   476,   477,   164,   165,   166,   167,
     168,   169,   478,   171,   479,   480,   481,   175,   176,   482,
     483,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   484,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,     0,     0,     5,     6,
     244,   485,   246,   247,   248,     0,   249,   392,   393,     0,
      12,    13,    14,   455,    16,    17,    18,   456,    20,   457,
     458,   459,   460,   394,    26,   461,    28,    29,    30,     0,
      31,    32,    33,    34,   462,    36,    37,    38,    39,    40,
      41,    42,   463,     0,    44,   464,    46,   465,   466,    49,
     467,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     0,    68,
      69,    70,   468,     0,     0,    72,    73,    74,     0,     0,
      75,    76,     0,     0,     0,     0,    78,   469,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,     0,    92,     0,     0,     0,
     470,    94,    95,    96,    97,     0,     0,     0,     0,     0,
       0,    98,    99,   100,     0,   102,   103,   104,     0,     0,
       0,     0,     0,     0,   110,   471,     0,     0,     0,     0,
     112,   113,   114,   115,   472,   117,   118,   119,     0,     0,
       0,     0,     0,     0,     0,   123,   124,   125,     0,     0,
       0,   126,     0,   127,   128,     0,     0,     0,     0,     0,
       0,   130,     0,   131,   132,   133,   134,   473,   136,   137,
     138,   139,   140,   141,     0,     0,   142,   143,     0,     0,
     395,     0,   147,   148,     0,     0,     0,   152,   153,   154,
     155,   156,   157,   474,   159,   475,   161,   476,   477,   164,
     165,   166,   167,   168,   169,   478,   171,   479,   480,   481,
     175,   176,   482,   483,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   484,     0,   192,   193,
     194,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,     0,
       0,     5,     6,   244,   485,   246,   247,   248,     0,   249,
     392,   393,     0,    12,    13,    14,     0,    16,    17,    18,
     456,     0,     0,   458,   459,     0,   394,    26,   461,    28,
       0,    30,     0,    31,    32,    33,    34,     0,    36,     0,
       0,    39,    40,    41,    42,   463,     0,    44,     0,    46,
       0,     0,    49,   467,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,    68,    69,    70,     0,     0,     0,    72,    73,
      74,     0,     0,    75,    76,     0,     0,     0,     0,    78,
     469,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,    88,    89,    90,    91,     0,    92,
       0,     0,     0,   470,    94,    95,    96,    97,     0,     0,
       0,     0,     0,     0,    98,    99,   100,     0,   102,   103,
       0,     0,     0,     0,     0,     0,     0,   110,   471,     0,
       0,     0,     0,   112,   113,   114,   115,   472,   117,   118,
     119,     0,     0,     0,     0,     0,     0,     0,   123,   124,
     125,     0,     0,     0,   126,     0,   127,   128,     0,     0,
       0,     0,     0,     0,   130,     0,   131,   132,   133,   134,
     473,   136,   137,   138,   139,   140,   141,     0,     0,     0,
     143,     0,     0,   395,     0,   147,   148,     0,     0,     0,
     152,   153,   154,   155,   156,   157,   474,     0,   475,   161,
     476,   477,   164,   165,   166,   167,   168,   169,   478,   171,
     479,   480,   481,   175,   176,     0,   483,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   484,
       0,   192,   193,   194,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,     0,     0,     0,     0,   244,   485,   246,   247,
     248,     0,   249
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     178,   106,   107,     1,     2,     3,   737,   310,   120,    10,
     709,   631,   949,   289,   615,   340,   403,   404,   837,   838,
     719,   616,   617,   618,   619,   936,   808,   405,  1212,   634,
     808,   524,     1,   971,  1196,  1042,   529,   558,   559,  1027,
     257,  1277,  1278,     1,  1411,    27,    28,  1414,   250,   251,
     863,  1225,   913,  1334,   913,   120,    37,   656,   436,   437,
     258,    57,     1,     1,    37,     8,    48,  1551,   120,     1,
      27,    28,   824,   109,     1,   273,    58,     1,     2,     3,
       4,   594,     1,   596,   597,     1,   599,     1,   601,    30,
      46,    48,   556,   557,    76,   105,   609,   610,   879,    81,
     105,     1,  1605,     1,    95,     1,    98,   926,    64,   808,
     109,   231,     1,   556,   557,   558,   559,    98,   937,    76,
       1,    85,   398,    96,     1,    98,   402,   138,    98,     1,
      31,   113,   114,   115,   109,     1,   102,   242,   243,    30,
     109,   105,   132,    96,   108,   121,     1,     2,     3,     4,
     144,   109,   132,    56,   171,    58,   120,   114,   122,   138,
       1,   939,   168,     1,     1,   560,   231,   162,   149,   564,
     109,   112,   133,   152,   280,     1,   149,   109,   184,   149,
     156,   105,   158,    40,   289,   126,   885,   204,    45,    46,
     149,   144,   203,   192,   185,   109,    30,    54,  1701,   102,
     320,   155,     1,   506,    61,   241,    63,    64,    98,   199,
     151,   186,     0,     1,   155,    72,   492,   158,  1454,   199,
     109,   112,   188,   109,   220,     1,   925,   279,   109,     1,
     158,   192,   109,   189,   177,   126,   967,   109,   179,  1723,
     250,   251,    99,   109,   254,   250,   251,   186,   313,   254,
     105,  1033,  1426,  1031,   192,  1033,  1193,   189,   779,   780,
     151,  1423,     0,     1,   260,   192,   865,  1178,   109,  1550,
     262,   109,   109,   192,    96,   189,   192,     1,  1216,   289,
     221,   222,   223,   109,   289,   279,  1067,  1225,   149,   667,
    1042,  1043,   192,   398,   192,  1283,   192,   402,   279,   575,
     189,  1114,  1163,  1310,  1163,   417,   279,   820,   189,  1676,
     109,   293,   189,   777,   778,   216,   428,   189,   424,   301,
     279,   109,   700,   189,   265,   123,   431,   309,   162,   434,
     221,   222,   223,   109,     1,  1034,   293,   109,   443,   556,
     557,   446,   447,   545,   301,    30,     1,   452,   189,   187,
     319,  1170,   189,   239,   257,   553,   554,    38,    39,   317,
      41,    42,   231,   189,   233,   563,  1733,   270,  1735,   272,
       1,   109,   262,   263,   231,   102,   220,   109,    59,   102,
     283,   284,   285,   120,   287,   109,   289,   492,   398,   109,
     189,   120,   402,   398,     1,    53,    98,   402,   186,   109,
      98,   108,   224,   225,   120,   510,   511,   158,     1,   150,
       1,   187,   517,   155,   186,     1,   260,   239,   279,   429,
     430,   231,   129,   233,   429,   430,   167,   109,   158,  1665,
     115,     1,   537,   538,   115,   445,     1,   824,   133,   449,
     445,   239,   109,   155,   449,     1,   410,     3,   186,   413,
      98,   320,   189,   417,   109,    78,   420,   421,   190,   188,
     158,   188,   186,  1162,   428,   188,   323,   324,   325,   171,
     190,   858,   188,   131,   438,    27,    28,   162,   109,   189,
     444,   162,   492,    34,   448,     9,    10,   492,  1426,   453,
    1726,   501,   768,  1014,  1015,  1016,   501,   192,   158,    50,
     993,   149,   109,  1285,   155,   429,   430,   189,   886,   887,
     320,  1116,    68,   891,  1698,  1293,   109,    73,   109,   795,
      96,   445,   634,   109,   488,   449,  1345,   632,   538,    98,
     635,   186,   155,   538,   274,   545,   500,   501,  1158,   109,
     545,   281,   120,   921,   109,   226,   556,   557,   558,   559,
     551,   556,   557,   558,   559,   186,   258,   259,  1310,   261,
     777,   121,   114,   527,   120,   575,   268,  1319,   144,   533,
     575,  1014,  1015,  1016,   429,   430,   278,   501,  1330,   186,
      96,   105,  1281,   155,   696,   783,   267,   699,   290,   787,
     445,  1753,   160,   186,   449,   186,   156,    96,   158,   109,
     186,   125,   171,   127,   227,   228,   109,    46,   155,    48,
     178,    43,   231,   725,   538,    47,   186,   236,    96,   155,
      52,   186,   586,   728,   729,   730,   590,   732,   109,   158,
       9,   155,    43,   149,   109,   159,    47,     9,    10,    71,
     212,    52,    81,    46,    43,    48,   501,   109,    47,  1560,
      29,   155,   176,    52,   155,  1042,  1043,   109,  1688,  1689,
      71,   102,   109,   768,     5,   212,    25,   109,     9,   108,
     634,   149,    71,   197,   115,   179,    35,   120,   179,   189,
      96,   158,   692,   243,     9,    10,   189,   692,  1470,   258,
     259,   215,   261,  1424,   692,   109,     5,     1,  1429,   663,
       9,   320,   102,    62,    96,   108,   716,   717,   189,   278,
    1740,   716,   717,   677,   189,   115,  1746,   681,   682,  1044,
    1321,   290,   998,   139,   688,   224,   225,   189,   144,   121,
      34,   170,   696,   105,   160,   699,   184,   189,   170,   703,
     239,   173,   189,   155,   139,  1266,   125,   189,   127,   144,
     198,  1503,   178,   125,  1573,   127,   188,   136,   768,   170,
    1697,   725,   173,   768,   156,  1385,   158,   170,   692,   120,
     119,   170,   736,   155,   173,   189,   155,   188,   102,   155,
     105,   150,   214,   155,   125,   795,   127,   159,   789,   188,
     795,   115,   716,   717,   135,  1173,    27,    28,   167,   148,
     125,   999,   127,   214,   176,    98,   770,    38,    39,   123,
      41,    42,   161,  1011,   155,   214,   125,    48,   127,    98,
      96,  1640,   115,  1642,   155,   197,   135,    58,    59,  1007,
     155,   263,   108,   147,   159,   799,   115,   692,   146,   139,
       9,     9,    10,   215,   158,    76,   155,   196,   812,   275,
      81,   176,   263,  1584,    55,   155,   282,  1588,    55,    60,
      29,   716,   717,    60,   263,   158,   292,     1,   144,   160,
     178,   160,   197,   837,   838,   839,   840,   203,    79,   158,
     130,   131,   113,   114,   115,   123,   212,   178,   196,   178,
     215,    98,  1487,  1494,  1495,  1273,  1172,    98,   188,  1718,
      34,    98,   188,    97,   102,    85,   188,    30,   115,   147,
     201,   238,   201,   240,   108,   879,    50,   115,   139,   120,
     158,   188,   212,  1310,   118,   188,   212,   188,   108,   893,
     212,   162,  1319,  1553,   155,   129,  1041,   105,   184,   269,
     120,   951,   122,  1330,   305,   212,   951,   253,   254,   212,
     280,   212,   198,   314,   918,  1258,   125,   125,   127,   127,
     120,  1692,   926,  1636,   275,  1638,  1665,   136,    96,   102,
     276,   282,   102,   937,   139,  1648,   219,  1650,    55,   144,
     108,   292,   115,    60,   876,   115,   155,   155,   998,   112,
     238,   159,   240,   998,   219,   226,   888,   227,   228,   229,
     247,   130,   131,   126,  1014,  1015,  1016,   269,   176,  1014,
    1015,  1016,  1013,   247,  1392,   613,   614,   158,   280,   620,
     621,  1622,  1623,   155,   283,   284,   285,   951,   151,   197,
     289,   248,   155,   622,   623,   158,   267,  1156,  1157,  1541,
    1542,     0,   320,   192,   169,    94,   134,   215,   101,   255,
    1670,    51,   202,   103,   142,   143,   179,   145,   104,   195,
    1024,   147,   293,  1027,   158,   153,   186,   186,   186,   157,
     301,   159,   186,    30,    48,   154,   164,  1255,   309,   120,
    1458,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   252,   310,   181,   155,     1,   951,   120,   221,   222,
     223,   144,   109,  1067,  1724,   144,   186,   155,  1709,   123,
     155,   123,    36,   155,   158,    17,  1503,   205,   206,   207,
     208,   209,   210,   158,   158,   216,    30,    30,  1404,   237,
     236,     3,   192,   192,   251,   120,   172,   170,   290,   290,
     172,   120,    72,    96,   237,    96,    96,   156,   151,   109,
      30,   109,   162,   129,   162,   252,  1166,   134,    96,   305,
     144,  1166,  1172,   134,   120,   186,   186,  1172,  1166,    96,
      98,  1447,    46,    98,  1184,   186,    96,   155,   243,  1184,
     186,   237,   144,  1803,   231,  1805,  1184,   192,   239,    34,
     172,   120,   109,  1203,   134,  1815,   144,    96,  1203,    30,
     292,    96,   233,   305,   120,  1203,  1170,    96,   155,   200,
     162,   186,  1222,   134,    98,   134,   155,  1222,   149,  1229,
     120,  1185,   186,   102,  1229,   102,   144,   192,    36,   409,
     410,  1195,   186,   413,    30,  1347,   123,   417,   123,    30,
     420,   421,  1166,   155,   155,   120,    81,   251,   428,   109,
     109,   129,  1262,   120,   291,   149,   273,  1262,   438,  1223,
    1184,   260,   264,    30,   444,   158,   158,   158,   448,   266,
     158,    30,   158,   453,   292,   158,   158,   158,    30,  1203,
     293,   146,  1558,   312,   233,  1249,   109,   158,   158,   158,
     158,   192,   158,  1569,  1570,  1259,  1572,   158,  1222,  1263,
     158,   158,   144,   200,  1580,  1229,   134,   102,   488,     7,
     186,  1166,    98,   239,   158,   188,   239,   239,   158,  1283,
     500,   158,  1286,   155,   239,   108,   129,   149,   192,  1184,
     192,   149,   149,   243,    79,   120,   120,  1301,  1262,  1444,
    1445,  1446,   189,   256,   149,   288,   292,   256,  1203,    80,
     189,   189,    30,   533,    30,   189,   189,   172,   109,   189,
     189,    98,   189,   189,   189,   189,   186,  1222,   128,   277,
     128,   144,   186,   263,  1229,   188,   188,   188,   322,   186,
    1344,  1345,   186,  1347,  1348,  1349,   186,  1351,   149,   186,
     155,   189,   149,    96,  1404,   189,   189,   189,    30,  1404,
     189,   189,   189,    98,   172,    96,   586,   189,   108,  1685,
     590,   149,    55,    96,    30,   271,   109,  1381,   199,   109,
     199,   120,   231,   286,    96,   188,    96,   199,   120,   200,
     146,   120,   231,   189,   189,   189,   105,  1447,   293,   189,
     189,   189,  1447,    95,  1408,   188,   185,  1411,   299,   120,
    1414,   231,   199,   120,   634,   188,   120,   311,  1734,   311,
     201,  1425,   311,   666,   312,  1117,  1430,   257,   404,   312,
     880,   312,   293,   927,  1163,  1670,  1752,   254,   254,   424,
     660,  1724,  1039,   663,   771,   590,   705,  1480,  1302,  1282,
    1020,  1280,  1277,   488,  1185,  1198,  1601,   677,  1190,  1775,
    1193,   681,   682,   592,   840,   612,   593,  1263,   688,   640,
     637,  1216,   634,  1477,  1478,   737,   696,  1746,   634,   699,
    1740,  1797,  1343,   703,  1343,   335,  1260,  1632,  1638,  1319,
    1806,  1249,  1503,  1259,  1330,  1043,  1323,  1500,  1052,   912,
    1139,  1544,  1375,  1320,   527,    -1,    -1,    -1,  1558,    -1,
      -1,    -1,    -1,  1558,    -1,    -1,   736,    -1,    -1,  1569,
    1570,    -1,  1572,    -1,  1569,  1570,    -1,  1572,    -1,    -1,
    1580,    -1,    -1,    -1,    -1,  1580,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     770,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1573,
    1574,    -1,  1576,    -1,  1578,    -1,    -1,    -1,    -1,   799,
      -1,  1585,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   812,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   837,   838,   839,
     840,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1636,    -1,  1638,  1685,  1640,    -1,  1642,    -1,
    1685,    -1,    -1,    -1,  1648,    -1,  1650,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   879,
      -1,    -1,  1666,    -1,    -1,  1669,    -1,    -1,    -1,    -1,
      -1,    -1,  1676,   893,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1687,  1734,    -1,    -1,    -1,    -1,  1734,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   918,    -1,
      -1,    -1,  1752,    -1,    -1,    -1,   926,  1752,    -1,    -1,
      -1,    -1,    -1,    -1,  1718,    -1,    -1,   937,    -1,    -1,
      -1,    -1,    -1,    -1,  1728,  1775,    -1,    -1,    -1,  1733,
    1775,  1735,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1797,    -1,    -1,
      -1,    -1,  1797,  1757,    -1,    -1,  1806,    -1,    -1,    -1,
      -1,  1806,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1773,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1793,
      -1,    -1,   501,    -1,  1798,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1024,    -1,  1810,  1027,    -1,  1813,
      -1,    -1,    -1,   522,   523,    -1,   525,   526,   527,   528,
      -1,   530,    -1,    -1,    -1,    -1,    -1,   536,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1067,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   566,   567,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   575,   576,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   636,    -1,    -1,
      -1,   640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1185,    -1,    -1,    -1,    -1,
     679,    -1,    -1,    -1,    -1,  1195,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   704,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   720,    -1,    -1,    -1,   724,   725,    -1,   727,    -1,
      -1,    -1,    -1,    -1,    -1,   734,    -1,    -1,    -1,  1249,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1259,
      -1,    -1,    -1,  1263,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1283,    -1,    -1,  1286,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1301,    -1,    -1,    -1,    -1,   795,    -1,    -1,    -1,
      -1,    -1,   801,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1344,  1345,    -1,  1347,  1348,  1349,
      -1,  1351,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1381,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   881,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1408,    -1,
      -1,  1411,    -1,    -1,  1414,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1425,    -1,   916,    -1,    -1,
    1430,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   938,
      -1,    -1,    -1,    -1,    -1,    -1,   945,   946,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   956,    -1,    -1,
     959,    -1,    -1,    -1,    -1,    -1,    -1,  1477,  1478,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   980,   981,   982,    -1,   984,   985,   986,   987,   988,
     989,   990,   991,   992,    -1,    -1,   995,   996,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1010,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1020,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1030,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1573,  1574,    -1,  1576,    -1,  1578,    -1,
      -1,    -1,    -1,    -1,    -1,  1585,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1104,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1636,    -1,  1638,    -1,
    1640,    -1,  1642,    -1,    -1,    -1,    -1,    -1,  1648,    -1,
    1650,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1666,    -1,    -1,  1669,
      -1,    -1,    -1,    -1,    -1,    -1,  1676,    -1,    -1,    -1,
      -1,    -1,    -1,  1172,    -1,    -1,    -1,  1687,    -1,    -1,
      -1,    -1,    -1,  1182,    -1,    -1,    -1,    -1,    -1,  1188,
    1189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1205,    -1,  1718,  1208,
    1209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1728,    -1,
      -1,    -1,    -1,  1733,    -1,  1735,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1757,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1773,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1280,    -1,  1793,    -1,    -1,    -1,    -1,  1798,  1288,
      -1,  1290,    -1,  1292,    -1,    -1,  1295,    -1,    -1,    -1,
    1810,  1300,    -1,  1813,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1395,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1403,  1404,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1422,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1435,  1436,  1437,  1438,
      -1,  1440,  1441,    -1,  1443,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1459,    -1,    -1,    -1,    -1,  1464,    -1,    -1,    -1,  1468,
      -1,    -1,    -1,  1472,    -1,  1474,    -1,  1476,    -1,    -1,
      -1,    -1,    -1,  1482,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1559,    -1,    -1,    -1,    -1,  1564,  1565,    -1,    -1,    -1,
      -1,    -1,    -1,  1572,    -1,    -1,    -1,    -1,  1577,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1594,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1606,    -1,  1608,
      -1,  1610,    -1,    -1,  1613,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1681,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1704,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1734,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,    -1,    -1,
      -1,    -1,  1771,    -1,    -1,    -1,  1775,    -1,    -1,    -1,
      -1,  1780,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    30,    -1,  1796,    -1,    34,
      35,  1800,    37,    38,    39,    40,    41,    42,    43,    44,
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
      -1,    -1,    -1,   188,    -1,   190,   191,   192,    -1,    -1,
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
      -1,   326,     0,     1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     308,   309,   310,   311,   312,   313,   314,   315,   316,     1,
     318,    -1,   320,   321,   322,   323,   324,    -1,   326,    -1,
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
     312,   313,   314,   315,   316,     1,   318,    -1,   320,   321,
     322,   323,   324,    -1,   326,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
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
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,    -1,
     326,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     320,   321,   322,   323,   324,    16,   326,    -1,    -1,    -1,
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
     311,   312,   313,   314,   315,   316,    -1,   318,    -1,   320,
     321,   322,   323,   324,    16,   326,    -1,    -1,    -1,    21,
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
     312,   313,   314,   315,   316,    -1,   318,    16,   320,   321,
     322,   323,   324,    -1,   326,    -1,    25,    26,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,
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
      -1,   190,   191,    -1,    -1,    -1,    -1,   196,    -1,   198,
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
     309,   310,   311,   312,   313,   314,   315,    -1,    -1,    16,
      -1,   320,   321,   322,   323,   324,    -1,   326,    25,    26,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,
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
      -1,   188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,
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
      -1,    16,    -1,   320,   321,   322,   323,   324,    -1,   326,
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
     315,    -1,    -1,    -1,    -1,   320,   321,   322,   323,   324,
      -1,   326,    18,    19,    -1,    -1,    -1,    -1,    -1,    25,
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
      -1,    -1,    -1,    -1,   320,   321,   322,   323,   324,    -1,
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
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,   213,   214,   215,    -1,   217,   218,   219,
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
     320,   321,   322,   323,   324,    -1,   326,   327,   328,    21,
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
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,   323,   324,    -1,   326,    -1,   328,    21,    22,    23,
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
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,   323,
     324,    -1,   326,    21,    22,    23,    24,    25,    26,    27,
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
     318,    -1,   320,   321,   322,   323,   324,    -1,   326,    21,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,   323,   324,    -1,   326,    21,    22,    23,    24,    25,
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
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,    -1,
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
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
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
     320,   321,   322,   323,   324,    -1,   326,    21,    22,    23,
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
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,   323,
     324,    -1,   326,    21,    22,    23,    24,    25,    26,    27,
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
     318,    -1,   320,   321,   322,   323,   324,    -1,   326,    21,
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
     152,   153,   154,   155,   156,    -1,   158,   159,   160,   161,
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
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,   321,
     322,   323,   324,    -1,   326,    21,    22,    23,    24,    25,
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
     146,    -1,   148,   149,   150,   151,   152,   153,   154,   155,
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
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,    -1,
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
     150,   151,   152,   153,   154,   155,   156,    -1,   158,   159,
     160,   161,   162,    -1,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,   187,   188,    -1,
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
     320,   321,   322,   323,   324,    -1,   326,    21,    22,    23,
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
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
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
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,   323,
     324,    -1,   326,    21,    22,    23,    24,    25,    26,    -1,
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
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   317,
     318,    -1,   320,   321,   322,   323,   324,    -1,   326,    21,
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
     312,   313,   314,   315,   316,    -1,   318,   319,   320,   321,
     322,   323,   324,    -1,   326,    21,    22,    23,    24,    25,
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
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,    -1,
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
     320,   321,   322,   323,   324,    -1,   326,    21,    22,    23,
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
     154,   155,   156,    -1,   158,   159,   160,   161,   162,    -1,
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
     314,   315,   316,    -1,   318,    -1,   320,   321,   322,   323,
     324,    -1,   326,    21,    22,    23,    24,    25,    26,    -1,
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
     318,    -1,   320,   321,   322,   323,   324,    -1,   326,    21,
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
     322,   323,   324,    -1,   326,    21,    22,    23,    24,    25,
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
     316,    -1,   318,    -1,   320,   321,   322,   323,   324,    -1,
     326,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
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
      -1,    25,    26,   320,   321,   322,   323,   324,    -1,   326,
      34,    35,    -1,    37,    38,    39,    -1,    41,    42,    43,
      44,    -1,    -1,    47,    48,    -1,    50,    51,    52,    53,
      -1,    55,    -1,    57,    58,    59,    60,    -1,    62,    -1,
      -1,    65,    66,    67,    68,    69,    -1,    71,    -1,    73,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    -1,    -1,    -1,   102,   103,
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
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     214,    -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,
     224,   225,   226,   227,   228,   229,   230,    -1,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,    -1,    -1,    -1,    -1,   320,   321,   322,   323,
     324,    -1,   326
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
     176,   178,   179,   182,   183,   184,   188,   190,   191,   192,
     198,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   213,   214,   215,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   265,   266,   267,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   318,   320,   321,   322,   323,   324,   326,
     327,   328,   342,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     363,   364,   365,   366,   367,   368,   372,   373,   374,   378,
     380,   381,   383,   390,   392,   395,   396,   397,   399,   400,
     401,   402,   403,   405,   406,   408,   409,   410,   411,   412,
     413,   415,   416,   419,   420,   421,   422,   423,   428,   430,
     432,   433,   434,   439,   458,   461,   465,   468,   469,   475,
     476,   477,   478,   480,   481,   483,   484,   485,   486,   487,
     488,   489,   490,   491,   493,   494,   495,   496,   499,   500,
     501,   502,   503,   504,   505,   508,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   522,   523,   524,   525,
     526,   527,   541,   542,   544,   545,   546,   547,   548,   549,
     550,   551,   572,   577,   578,   579,   580,   581,   582,   585,
     643,   644,   645,   646,   648,   649,   650,   651,   652,   659,
     660,   661,    34,    35,    50,   217,   398,   399,   400,   398,
     398,   399,   400,   158,   158,    38,    39,    41,    42,    48,
      58,    59,    76,    81,   113,   114,   115,   162,   226,   267,
     293,   301,   309,   379,   380,   384,   385,   386,   162,   155,
     155,   155,   158,   387,   158,    25,    35,    62,   120,   279,
     438,   440,   441,   155,   120,   155,   158,   158,    78,   155,
     227,   228,   155,   120,   407,    40,    44,    46,    47,    48,
      49,    52,    61,    69,    72,    74,    75,    77,    99,   114,
     137,   162,   171,   204,   230,   232,   234,   235,   242,   244,
     245,   246,   249,   250,   263,   321,   659,   660,   120,    16,
     186,   398,   400,   421,   647,   658,   659,    49,    74,    75,
     120,   155,   187,   250,   420,   422,   432,   189,   420,   659,
     155,   155,   658,   659,    18,    19,   659,   155,    31,   216,
     219,   219,   231,   233,   320,   231,   233,   320,   231,   320,
     231,   236,   320,   120,   247,   247,   248,   158,   155,   402,
     317,   420,   319,   420,   320,   328,   344,   344,     0,   346,
     347,    34,    50,   349,   366,     1,   192,   343,   192,   343,
     114,   381,   401,   420,   109,   192,   109,   343,   192,    43,
      47,    52,    71,   170,   173,   188,   214,   263,   414,   424,
     429,   430,   431,   446,   447,   451,     1,     3,    68,    73,
     120,   425,   169,    94,   134,   142,   143,   145,   153,   157,
     159,   164,   181,   205,   206,   207,   208,   209,   210,   497,
     498,   255,   101,   160,   178,   201,   119,   148,   161,   196,
     203,   212,   138,   152,    51,   202,   103,   104,   160,   178,
     495,   195,   155,   502,   121,   156,   158,   509,   510,   147,
     158,   186,   186,   186,   186,   382,   512,   382,    30,   657,
     184,   198,   184,   198,   168,   184,   660,   659,   171,   204,
      48,   659,   154,   120,    46,    48,    81,   108,   170,   658,
     227,   228,   229,   252,   616,   659,   659,   310,   139,   144,
     114,   293,   301,   384,   658,   399,   399,   420,   120,   189,
     388,   389,   155,   404,   420,     1,   162,   657,   115,   162,
     362,   657,   659,   120,   144,   109,   420,   459,   460,   659,
     399,   420,   420,   570,   659,   399,   155,   155,   420,   659,
     144,   459,   186,   186,   123,   109,   186,   123,   158,   158,
     158,   659,   155,   187,   188,   189,    36,   529,   530,   531,
     420,   420,     8,   177,    17,   420,   216,    30,    30,   421,
     421,   508,   421,   421,   421,   647,   421,   508,   421,   237,
     236,   583,   584,   659,   192,   192,   421,   420,   400,   420,
     251,   417,   418,   317,   319,   421,   344,   192,   343,   192,
     343,     3,   350,   366,   396,     1,   350,   366,   396,    34,
     367,   396,   367,   396,   407,   343,   407,   421,   421,   120,
     170,   172,   172,   401,   421,   421,   435,   436,   659,   290,
     290,   435,   120,   442,   477,   478,   480,   480,   480,   480,
     479,   480,   480,   480,    72,   481,   485,   485,   484,   486,
     486,   486,   486,   487,   487,   488,   488,   237,    96,    96,
      96,   503,   186,   420,   196,   515,   516,   572,   658,   420,
     146,   189,   421,   521,   510,   151,   189,   521,   109,   189,
     189,   109,   109,   387,    30,   660,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   369,   370,   371,    96,
     139,   144,   375,   376,   377,   659,   162,   162,   369,   657,
     129,   134,    56,    58,   102,   257,   270,   272,   283,   284,
     285,   287,   289,   617,   618,   619,   620,   621,   622,   629,
     635,   636,   252,    96,   305,   659,   144,   421,   120,   659,
     659,   134,   186,   186,   186,   659,    96,   109,   189,   398,
     189,   658,    98,    46,   658,   657,    98,    96,   144,   552,
     659,   421,   441,   186,   109,   190,   149,   552,   186,   189,
     189,   155,   186,   399,   399,   186,   144,   552,   421,   190,
     421,   421,   658,   421,   420,   420,   420,   659,   530,   531,
     132,   199,   186,   186,   186,   133,   192,   133,   192,    96,
     224,   225,   239,    96,   224,   225,   239,   239,   239,    96,
      96,   243,   231,   237,   109,   241,   144,   192,   189,   420,
     186,    11,    12,    20,   196,   506,   507,   589,   659,   418,
     239,   366,    34,    34,   192,   343,   192,   115,   401,   659,
     172,   421,   452,   453,   120,   448,   449,   109,    37,    98,
     149,   437,   438,   552,   659,    57,   220,   260,   426,   427,
     480,   155,   158,   265,   501,   512,   590,   593,   594,   595,
     596,   597,   601,   603,   605,   606,    40,    45,    46,    48,
      54,    61,    63,    64,    72,    99,   154,   158,   213,   231,
     323,   324,   325,   326,   553,   555,   557,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   573,   574,
     575,   576,   653,   654,   655,   656,   659,   553,   492,   558,
     659,   492,   186,   187,   109,   189,   189,   512,   150,   167,
     150,   167,   139,   404,   387,   370,   134,   555,   377,   421,
     552,   657,   657,   130,   131,   657,   283,   284,   285,   289,
     659,   269,   280,   269,   280,    30,   292,    98,   115,   158,
     623,   626,   617,    40,    45,    46,    54,    61,    63,    64,
      72,    99,   231,   323,   324,   391,   559,   653,   233,   305,
     314,   421,   659,    96,   305,   657,   155,   552,   553,   389,
      96,   186,   200,   134,   361,   657,   162,   134,    98,   361,
     553,   421,   144,   438,   155,   120,   421,   421,   149,   102,
     462,   463,   464,   466,   467,   102,   470,   471,   472,   473,
     399,   186,   186,   155,   421,   144,   192,   421,   123,   123,
     189,   189,   189,    36,   531,   132,   199,     9,    10,   105,
     125,   127,   155,   197,   526,   528,   539,   540,   543,   155,
      30,    30,   238,   240,   421,   421,   421,   238,   240,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   508,   120,
     421,   421,    49,    74,    75,   250,   401,   422,   432,   251,
     586,   587,   155,   212,   402,   421,   192,   115,   396,   396,
     396,   452,    97,   108,   118,   129,   454,   455,   456,   457,
     109,   659,   109,   120,   436,   129,   120,   421,   149,   438,
     149,    37,   149,   437,   438,   149,   552,   260,    55,    60,
      79,   120,   437,   443,   444,   445,   427,   420,   590,   597,
     155,   291,   482,   642,    98,   171,   258,   259,   261,   268,
     278,   290,   591,   592,   611,   612,   613,   614,   637,   640,
     264,   266,   598,   616,   273,   602,   638,   253,   254,   276,
     607,   608,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   555,   158,   158,   158,   158,   158,   146,
     178,   196,   554,   146,   146,   421,   139,   404,   572,   376,
     292,    30,    98,   115,   158,   630,    30,   623,   554,   554,
     503,   293,   312,   552,   391,   233,   192,   398,   553,   401,
     421,   657,   109,   361,   421,   144,   398,   460,   421,   421,
     115,   463,   464,   102,   188,   115,   464,   467,   120,   474,
     553,   102,   115,   471,   102,   115,   473,   186,   398,   421,
     421,   421,   200,   470,   134,   197,   528,     7,   399,   659,
     197,   539,   399,   192,   192,   239,   239,   239,   239,    98,
     243,   243,   584,   188,   158,   158,   158,   188,   589,   587,
     506,   657,   130,   131,   456,   457,   457,   453,   108,   144,
     450,   552,   449,   436,   149,   437,   659,   421,   149,   421,
     129,   421,   149,   438,   149,   421,   149,   120,   120,   421,
     659,   445,    79,   186,   189,   590,   604,   256,   220,   260,
     274,   281,   641,    98,   262,   263,   639,   256,   594,   641,
     484,   611,   595,   149,   288,   599,   600,   639,   292,   610,
      80,   609,   189,   189,   568,   569,   189,   196,   659,   189,
     196,   553,   556,   189,    30,   189,   658,   659,   659,   189,
     189,   196,   659,   189,   189,   189,   189,   189,   189,   189,
      30,   138,   203,   632,   633,   634,    30,   631,   632,   277,
     627,   109,   624,   172,   659,   263,   503,   186,   128,   128,
      98,   657,   421,   186,   188,   188,   421,   401,   421,   188,
     188,   659,   188,   212,   120,   474,   120,   188,   120,   474,
     188,   186,   115,   531,   659,   197,   186,   531,   659,   186,
     421,   421,   421,   421,   322,   421,   421,   421,   420,   420,
     420,   155,   588,   457,   657,   421,   144,   421,   149,   421,
     149,   437,   421,   149,   421,   421,   659,   659,   444,   421,
     186,   486,    53,   131,   484,   484,   275,   282,   292,   615,
     615,   596,   155,   286,   189,   189,   109,   189,   109,   189,
      96,   189,   109,   189,   189,   189,   189,   189,   109,   189,
     109,   189,   630,   630,   634,   109,   189,    30,   628,   639,
     625,   626,   189,   393,   394,   503,   120,   231,   313,   293,
     172,   401,   421,   361,   421,   401,    96,   401,   421,   553,
     659,   188,   659,   421,   659,   188,   401,   120,    95,   185,
     532,   531,   659,   199,   531,   421,   189,   189,   189,   420,
     450,   421,   421,   421,   149,   421,    55,   484,   484,   201,
     420,   570,   571,   659,   570,   571,   553,   553,    96,   570,
     570,    30,   271,   109,   109,   457,   552,   659,   120,   231,
     659,   393,   474,    96,   188,    96,   659,     5,   135,   535,
     536,   538,   540,    29,   136,   533,   534,   537,   540,   199,
     531,   199,   200,   470,   186,   450,   421,   120,   484,   186,
     189,   189,   146,   189,   189,   553,   189,   189,   626,   394,
     457,   311,   659,   120,   231,   188,   474,   401,   421,   474,
     188,    95,   135,   538,   185,   136,   537,   199,   115,   659,
     421,   311,   659,   120,   401,   421,   188,   188,   120,   299,
     311,   659,   659,   312,   421,   312,   188,   503,   503,   201,
     293,   659,   231,   120,   659,   312,   503
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
     477,   478,   478,   478,   478,   478,   479,   478,   478,   478,
     478,   480,   480,   481,   481,   482,   482,   483,   483,   484,
     484,   484,   485,   485,   485,   485,   485,   486,   486,   486,
     487,   487,   487,   488,   488,   489,   489,   490,   490,   491,
     491,   492,   492,   493,   493,   494,   494,   494,   494,   495,
     495,   495,   496,   496,   497,   497,   497,   497,   497,   497,
     498,   498,   498,   499,   499,   499,   499,   500,   500,   501,
     501,   502,   502,   502,   503,   504,   505,   506,   506,   507,
     507,   507,   507,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   509,   509,   510,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   512,
     512,   512,   512,   513,   513,   513,   514,   514,   515,   516,
     516,   517,   518,   519,   520,   520,   521,   521,   521,   521,
     522,   522,   523,   524,   525,   525,   526,   526,   526,   527,
     527,   527,   527,   527,   527,   528,   528,   529,   529,   530,
     531,   531,   532,   532,   533,   533,   534,   534,   534,   534,
     535,   535,   536,   536,   536,   536,   537,   537,   538,   538,
     539,   539,   539,   539,   540,   540,   540,   540,   541,   541,
     542,   542,   543,   544,   544,   544,   544,   544,   544,   544,
     545,   546,   546,   547,   547,   548,   549,   550,   550,   551,
     551,   552,   553,   553,   553,   554,   554,   554,   555,   555,
     555,   555,   555,   555,   555,   556,   556,   557,   558,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   560,
     561,   561,   561,   562,   563,   564,   565,   565,   565,   566,
     566,   566,   566,   566,   567,   568,   568,   568,   568,   568,
     568,   568,   569,   570,   571,   572,   573,   573,   574,   575,
     575,   576,   577,   577,   577,   578,   578,   578,   578,   578,
     578,   578,   578,   578,   578,   579,   579,   580,   580,   581,
     582,   583,   583,   584,   585,   586,   586,   587,   588,   589,
     589,   590,   591,   591,   592,   592,   593,   593,   594,   594,
     595,   595,   596,   596,   597,   598,   598,   599,   599,   600,
     601,   601,   601,   602,   602,   603,   604,   604,   605,   606,
     606,   607,   607,   608,   608,   608,   609,   609,   610,   610,
     611,   611,   611,   611,   611,   612,   613,   614,   615,   615,
     615,   616,   616,   617,   617,   617,   617,   617,   617,   617,
     617,   618,   618,   618,   618,   619,   619,   620,   621,   621,
     622,   622,   622,   623,   623,   624,   624,   625,   625,   626,
     627,   627,   628,   628,   629,   629,   629,   630,   630,   631,
     631,   632,   632,   633,   633,   634,   634,   635,   636,   636,
     637,   637,   637,   638,   639,   639,   639,   639,   640,   640,
     641,   641,   642,   643,   643,   644,   644,   645,   645,   646,
     646,   647,   647,   647,   647,   648,   648,   648,   649,   650,
     651,   652,   653,   653,   653,   654,   655,   656,   657,   658,
     658,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   660,   660,
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
     660,   660,   660,   661
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
       3,     1,     3,     3,     3,     3,     0,     4,     3,     3,
       3,     1,     5,     1,     3,     0,     1,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     4,     1,     4,     1,     4,     1,
       4,     1,     2,     1,     2,     1,     1,     2,     2,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     5,     5,     6,     3,     4,     1,
       2,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     4,     3,     3,     3,
       3,     3,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       3,     1,     4,     4,     3,     4,     1,     3,     1,     3,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     4,
       8,     5,     9,     9,    10,     1,     2,     1,     2,     6,
       0,     1,     3,     3,     0,     1,     1,     1,     2,     2,
       0,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       3,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     7,     3,     7,     4,     4,     3,     7,     3,
       7,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     4,     3,     3,     3,     3,     4,     4,     3,
       4,     6,     4,     6,     4,     3,     4,     6,     6,     4,
       6,     6,     4,     1,     2,     1,     1,     1,     4,     5,
       6,     3,     3,     3,     3,     5,     7,     7,     5,     5,
       5,     7,     7,     5,     5,     3,     3,     5,     7,     5,
       7,     1,     4,     3,     5,     1,     2,     3,     3,     1,
       3,     2,     0,     1,     1,     2,     1,     3,     1,     3,
       1,     4,     1,     2,     3,     0,     1,     0,     1,     4,
       2,     3,     1,     0,     1,     4,     0,     1,     2,     1,
       3,     0,     1,     2,     2,     1,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     2,     2,     3,     1,     2,
       2,     5,     2,     1,     1,     0,     2,     1,     3,     4,
       0,     2,     0,     2,     4,     4,     3,     2,     3,     1,
       3,     0,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     3,     2,     3,     3,     4,     2,     2,
       1,     1,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     3,     3,     5,     5,     5,     5,     8,     5,     3,
       5,     7,     1,     1,     1,     1,     3,     3,     1,     1,
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
       1,     1,     1,     1
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
      -1,   144,   421,    -1,    34,   379,   144,   421,    -1,    34,
     379,   139,    -1,    34,   379,   139,   144,   421,    -1,   114,
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
     503,   457,    -1,   503,   552,   457,    -1,    34,   309,   310,
     659,   305,   293,   659,   120,   659,   311,   421,    -1,    34,
     309,   310,   659,   305,   293,   659,   231,   120,   659,   311,
     299,   312,   503,    -1,    34,   309,   310,   659,   305,   293,
     659,   313,   231,   120,   659,   311,   421,    -1,    34,   309,
     310,   659,   314,   312,   263,   293,   659,   231,   120,   659,
     312,   503,   201,   293,   659,   231,   120,   659,   312,   503,
      -1,   397,    -1,   399,    -1,   400,    -1,    -1,   399,    -1,
     400,    -1,    -1,   420,    -1,   400,   420,    -1,   401,    -1,
     400,   401,    -1,   400,   420,   343,   401,    -1,   402,    -1,
     405,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   413,    -1,   415,    -1,   469,    -1,   465,    -1,
     416,    -1,   419,    -1,   155,   400,   186,    -1,   155,   398,
     186,    -1,   155,   398,   186,    -1,   406,   192,    -1,   406,
     109,   407,    -1,   114,   407,    -1,   380,   114,   407,    -1,
     120,   659,    -1,   120,   659,   552,    -1,   120,   659,   144,
     421,    -1,   120,   659,   552,   144,   421,    -1,   120,   659,
     144,   421,   192,    -1,   422,   192,    -1,   246,   248,   421,
     192,    -1,   249,   158,   420,   189,   401,    -1,   244,   247,
     192,    -1,   245,   247,   192,    -1,   432,   414,    -1,   188,
     401,    -1,    49,   158,   420,   189,   200,   401,   128,   401,
      -1,   250,   402,   417,    -1,   418,    -1,   417,   418,    -1,
     251,   589,   402,    -1,   192,    -1,   421,    -1,   420,   109,
     421,    -1,   420,   343,   421,    -1,   423,    -1,   461,    -1,
     468,    -1,   475,    -1,   585,    -1,   422,    -1,   476,    -1,
     458,    -1,   578,    -1,   579,    -1,   581,    -1,   580,    -1,
     582,    -1,   650,    -1,   648,    -1,   651,    -1,   652,    -1,
     649,    -1,   432,   424,    -1,   188,   421,    -1,    68,   290,
      -1,    73,   290,    -1,   220,    -1,   260,    -1,    57,   260,
      -1,   426,   443,    79,   421,    -1,   426,    79,   421,    -1,
     434,   425,   442,   427,   427,    -1,   434,   425,   442,   427,
      -1,    43,   120,   659,    -1,   433,    -1,   439,    -1,   428,
      -1,   430,    -1,   446,    -1,   451,    -1,   447,    -1,   429,
      -1,   430,    -1,   432,   431,    -1,   434,   120,   435,    -1,
     434,     1,   435,    -1,   434,     3,    -1,    47,    -1,   263,
      -1,   436,    -1,   435,   109,   120,   436,    -1,   435,   109,
     436,    -1,   659,   149,   421,    -1,   659,    37,   129,   149,
     421,    -1,   659,   552,   149,   421,    -1,   659,   552,    37,
     129,   149,   421,    -1,   659,   437,   149,   421,    -1,   659,
      37,   129,   437,   149,   421,    -1,   659,   552,   437,   149,
     421,    -1,   659,   552,    37,   129,   437,   149,   421,    -1,
     659,   438,   149,   421,    -1,   659,   552,   438,   149,   421,
      -1,   659,   437,   438,   149,   421,    -1,   659,   552,   437,
     438,   149,   421,    -1,    98,   120,   659,    -1,   279,   120,
     659,    -1,    52,   440,    -1,   441,    -1,   440,   109,   441,
      -1,   120,   659,   144,   421,    -1,   120,   659,   552,   144,
     421,    -1,   438,   144,   421,    -1,   120,   659,   552,   438,
     144,   421,    -1,   120,   659,   149,   421,    -1,   120,   659,
     552,   149,   421,    -1,   444,    -1,   120,   659,    -1,   120,
     659,   444,    -1,   437,    -1,   437,   445,    -1,   445,    -1,
      60,   120,   659,    55,   120,   659,    -1,    55,   120,   659,
      -1,    60,   120,   659,    -1,   214,   421,    -1,   173,   172,
     448,    -1,   449,    -1,   448,   109,   449,    -1,   120,   659,
      -1,   120,   659,   144,   421,    -1,   120,   659,   552,   144,
     421,    -1,   120,   659,   552,   144,   421,   450,    -1,   120,
     659,   144,   421,   450,    -1,   120,   659,   450,    -1,   108,
     657,    -1,   170,   172,   452,    -1,    71,   170,   172,   452,
      -1,   453,    -1,   452,   109,   453,    -1,   421,    -1,   421,
     454,    -1,   455,    -1,   456,    -1,   457,    -1,   455,   456,
      -1,   455,   457,    -1,   456,   457,    -1,   455,   456,   457,
      -1,    97,    -1,   118,    -1,   129,   130,    -1,   129,   131,
      -1,   108,   657,    -1,    69,   120,   459,   190,   421,    -1,
     137,   120,   459,   190,   421,    -1,   460,    -1,   459,   109,
     120,   460,    -1,   659,   149,   421,    -1,   659,   552,   149,
     421,    -1,    74,   158,   420,   189,   462,   115,   188,   421,
      -1,   463,    -1,   462,   463,    -1,   464,   188,   421,    -1,
     102,   421,    -1,   464,   102,   421,    -1,    74,   158,   420,
     189,   466,   115,   188,   401,    -1,   467,    -1,   466,   467,
      -1,   464,   188,   401,    -1,    75,   158,   420,   189,   470,
     115,   188,   421,    -1,    75,   158,   420,   189,   470,   115,
     120,   659,   188,   421,    -1,    75,   158,   420,   189,   472,
     115,   188,   401,    -1,    75,   158,   420,   189,   470,   115,
     120,   659,   188,   401,    -1,   471,    -1,   470,   471,    -1,
     102,   474,   188,   421,    -1,   102,   120,   659,    96,   474,
     188,   421,    -1,   473,    -1,   472,   473,    -1,   102,   474,
     188,   401,    -1,   102,   120,   659,    96,   474,   188,   401,
      -1,   553,    -1,   474,   212,   553,    -1,    49,   158,   420,
     189,   200,   421,   128,   421,    -1,   477,    -1,   476,   169,
     477,    -1,   478,    -1,   477,    94,   478,    -1,   480,    -1,
     480,   497,   480,    -1,   480,   498,   480,    -1,   480,   134,
     480,    -1,   480,   164,   480,    -1,    -1,   480,   159,   479,
     480,    -1,   480,   157,   480,    -1,   480,   145,   480,    -1,
     480,   143,   480,    -1,   481,    -1,   481,   255,    72,   590,
     482,    -1,   483,    -1,   483,   101,   481,    -1,    -1,   642,
      -1,   484,    -1,   484,   201,   484,    -1,   485,    -1,   484,
     178,   485,    -1,   484,   160,   485,    -1,   486,    -1,   485,
     196,   486,    -1,   485,   119,   486,    -1,   485,   148,   486,
      -1,   485,   161,   486,    -1,   487,    -1,   486,   203,   487,
      -1,   486,   212,   487,    -1,   488,    -1,   487,   152,   488,
      -1,   487,   138,   488,    -1,   489,    -1,   489,    51,   237,
     553,    -1,   490,    -1,   490,   202,    96,   553,    -1,   491,
      -1,   491,   103,    96,   492,    -1,   493,    -1,   493,   104,
      96,   492,    -1,   558,    -1,   558,   146,    -1,   495,    -1,
     494,   495,    -1,   178,    -1,   160,    -1,   494,   178,    -1,
     494,   160,    -1,   499,    -1,   496,    -1,   500,    -1,   503,
      -1,   496,   195,   503,    -1,   205,    -1,   210,    -1,   209,
      -1,   208,    -1,   207,    -1,   206,    -1,   153,    -1,   181,
      -1,   142,    -1,    77,   155,   399,   186,    -1,    77,   228,
     155,   399,   186,    -1,    77,   227,   155,   399,   186,    -1,
      77,    78,   570,   155,   399,   186,    -1,   501,   155,   186,
      -1,   501,   155,   420,   186,    -1,   502,    -1,   501,   502,
      -1,   179,   659,    17,    -1,   179,    18,    -1,   179,    19,
      -1,   504,    -1,   505,    -1,   508,    -1,   659,    -1,   507,
      -1,   196,    -1,    11,    -1,    12,    -1,    20,    -1,   511,
      -1,   508,   509,    -1,   508,   158,   189,    -1,   508,   158,
     521,   189,    -1,   508,   121,   658,    -1,   508,   121,   516,
      -1,   508,   121,   515,    -1,   508,   121,   572,    -1,   508,
     121,   196,    -1,   510,    -1,   509,   510,    -1,   156,   420,
     187,    -1,   512,    -1,   515,    -1,   516,    -1,   517,    -1,
     520,    -1,   525,    -1,   518,    -1,   519,    -1,   522,    -1,
     403,    -1,   646,    -1,   643,    -1,   644,    -1,   645,    -1,
     513,    -1,   572,    -1,   514,    -1,   221,    -1,   112,    -1,
     151,    -1,   126,    -1,   222,    -1,   223,    -1,   120,   659,
      -1,   158,   189,    -1,   158,   420,   189,    -1,   121,    -1,
     171,   155,   420,   186,    -1,   204,   155,   420,   186,    -1,
     660,   158,   189,    -1,   660,   158,   521,   189,    -1,   146,
      -1,   521,   109,   146,    -1,   421,    -1,   521,   109,   421,
      -1,   523,    -1,   524,    -1,   659,   147,   151,    -1,    48,
     387,   404,    -1,   526,    -1,   544,    -1,   527,    -1,   541,
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
     155,   399,   186,    -1,   215,    31,   216,    -1,   215,   216,
      -1,   176,   658,   177,    -1,   176,   658,     8,    -1,   105,
       7,    -1,   545,    -1,   546,    -1,   547,    -1,   548,    -1,
     549,    -1,   550,    -1,   551,    -1,    44,   155,   399,   186,
      -1,    21,   398,   186,    -1,    46,   155,   420,   186,   155,
     398,   186,    -1,    22,   398,   186,    -1,    99,   155,   420,
     186,   155,   398,   186,    -1,    72,   155,   399,   186,    -1,
      40,   155,   399,   186,    -1,    23,   398,   186,    -1,    61,
     155,   420,   186,   155,   398,   186,    -1,    24,   399,   186,
      -1,   162,   155,   420,   186,   155,   399,   186,    -1,    96,
     553,    -1,   555,    -1,   555,   554,    -1,   213,   158,   189,
      -1,   146,    -1,   196,    -1,   178,    -1,   557,    -1,   559,
      -1,   154,   158,   189,    -1,   326,   158,   189,    -1,   573,
      -1,   576,    -1,   653,    -1,   553,    -1,   556,   109,   553,
      -1,   659,    -1,   659,    -1,   561,    -1,   568,    -1,   566,
      -1,   569,    -1,   567,    -1,   565,    -1,   564,    -1,   563,
      -1,   562,    -1,   560,    -1,   231,   158,   189,    -1,    45,
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
     189,    -1,    34,   226,   227,    -1,    34,   226,   228,    -1,
      34,   226,   229,    -1,   232,   231,   421,   239,   421,    -1,
     232,   231,   421,    96,   238,   239,   421,    -1,   232,   231,
     421,    96,   240,   239,   421,    -1,   232,   231,   421,   224,
     421,    -1,   232,   231,   421,   225,   421,    -1,   232,   233,
     421,   239,   421,    -1,   232,   233,   421,    96,   238,   239,
     421,    -1,   232,   233,   421,    96,   240,   239,   421,    -1,
     232,   233,   421,   224,   421,    -1,   232,   233,   421,   225,
     421,    -1,   230,   231,   421,    -1,   230,   233,   421,    -1,
     235,   231,   421,   243,   421,    -1,   235,   236,   237,   231,
     421,   243,   421,    -1,   234,   231,   421,    96,   421,    -1,
     242,   120,   583,   241,   421,   188,   421,    -1,   584,    -1,
     583,   109,   120,   584,    -1,   659,   144,   421,    -1,   250,
     155,   420,   186,   586,    -1,   587,    -1,   586,   587,    -1,
     251,   589,   588,    -1,   155,   420,   186,    -1,   506,    -1,
     589,   212,   506,    -1,   593,   591,    -1,    -1,   592,    -1,
     611,    -1,   592,   611,    -1,   594,    -1,   593,   268,   594,
      -1,   595,    -1,   594,   264,   595,    -1,   596,    -1,   595,
     266,   149,   596,    -1,   597,    -1,   265,   597,    -1,   601,
     598,   599,    -1,    -1,   616,    -1,    -1,   600,    -1,   288,
     155,   420,   186,    -1,   605,   602,    -1,   158,   590,   189,
      -1,   603,    -1,    -1,   638,    -1,   501,   155,   604,   186,
      -1,    -1,   590,    -1,   606,   607,    -1,   512,    -1,   155,
     420,   186,    -1,    -1,   608,    -1,   254,   609,    -1,   253,
     610,    -1,   276,    -1,    -1,    80,    -1,    -1,   292,    -1,
     612,    -1,   613,    -1,   614,    -1,   640,    -1,   637,    -1,
     171,    -1,   290,   484,   615,    -1,   259,   639,   615,    -1,
     292,    -1,   282,    -1,   275,    -1,   252,   617,    -1,   616,
     252,   617,    -1,   618,    -1,   619,    -1,   620,    -1,   635,
      -1,   621,    -1,   629,    -1,   622,    -1,   636,    -1,   102,
     280,    -1,   102,   269,    -1,   272,    -1,   287,    -1,   257,
     280,    -1,   257,   269,    -1,    58,   659,    30,    -1,   283,
      -1,    56,   283,    -1,   285,   623,    -1,   285,   158,   623,
     624,   189,    -1,    56,   285,    -1,   626,    -1,   115,    -1,
      -1,   109,   625,    -1,   626,    -1,   625,   109,   626,    -1,
      98,    30,   627,   628,    -1,    -1,   277,    30,    -1,    -1,
     639,   271,    -1,   284,   292,   630,   632,    -1,   284,   292,
     115,   632,    -1,    56,   284,   292,    -1,    98,    30,    -1,
     158,   631,   189,    -1,    30,    -1,   631,   109,    30,    -1,
      -1,   633,    -1,   634,    -1,   633,   634,    -1,   203,   630,
      -1,   138,   630,    -1,   270,    30,    -1,   289,    -1,    56,
     289,    -1,    98,   220,    -1,    98,   260,    -1,   261,   256,
      -1,   273,   639,   286,    -1,   262,   484,    -1,    98,   131,
     484,    -1,    98,    53,   484,    -1,   263,   484,   201,   484,
      -1,   278,   641,    -1,   258,   641,    -1,   281,    -1,   274,
      -1,   291,   256,   486,    -1,   156,   187,    -1,   156,   420,
     187,    -1,   316,   317,    -1,   316,   420,   317,    -1,   318,
     319,    -1,   318,   420,   319,    -1,   155,   186,    -1,   155,
     647,   186,    -1,   658,   123,   421,    -1,   421,   123,   421,
      -1,   647,   109,   421,   123,   421,    -1,   647,   109,   658,
     123,   421,    -1,   232,   320,   421,   239,   421,    -1,   232,
     320,   647,   239,   421,    -1,   232,   320,   421,   239,   421,
      98,   322,   421,    -1,   321,   320,   421,   239,   421,    -1,
     230,   320,   508,    -1,   234,   320,   508,    96,   421,    -1,
     235,   320,   236,   237,   508,   243,   421,    -1,   654,    -1,
     655,    -1,   656,    -1,   325,    -1,   323,   158,   189,    -1,
     324,   158,   189,    -1,    30,    -1,    16,    -1,   659,    -1,
     660,    -1,    99,    -1,    40,    -1,    45,    -1,    54,    -1,
      46,    -1,   154,    -1,    49,    -1,   231,    -1,    61,    -1,
      63,    -1,    64,    -1,    72,    -1,    75,    -1,    74,    -1,
     213,    -1,   249,    -1,   661,    -1,    25,    -1,   217,    -1,
     129,    -1,    39,    -1,   267,    -1,    38,    -1,   228,    -1,
     227,    -1,   148,    -1,    44,    -1,   265,    -1,   266,    -1,
     280,    -1,   269,    -1,   257,    -1,   291,    -1,   283,    -1,
     285,    -1,   284,    -1,   289,    -1,   261,    -1,   256,    -1,
      80,    -1,   220,    -1,   260,    -1,    53,    -1,   229,    -1,
     242,    -1,   308,    -1,   236,    -1,   205,    -1,   210,    -1,
     209,    -1,   208,    -1,   207,    -1,   206,    -1,    98,    -1,
     113,    -1,   114,    -1,   188,    -1,    47,    -1,    37,    -1,
      68,    -1,    73,    -1,    60,    -1,    55,    -1,    57,    -1,
      79,    -1,    43,    -1,   149,    -1,    52,    -1,   214,    -1,
     172,    -1,   173,    -1,   170,    -1,    71,    -1,    97,    -1,
     118,    -1,   130,    -1,   131,    -1,   108,    -1,    69,    -1,
     137,    -1,   190,    -1,   102,    -1,    96,    -1,   200,    -1,
     128,    -1,   169,    -1,    94,    -1,    51,    -1,   237,    -1,
     103,    -1,   201,    -1,   119,    -1,   161,    -1,   203,    -1,
     152,    -1,   138,    -1,    77,    -1,    78,    -1,   104,    -1,
     202,    -1,   153,    -1,   184,    -1,   198,    -1,   162,    -1,
     139,    -1,   133,    -1,   168,    -1,   150,    -1,   167,    -1,
      34,    -1,    41,    -1,    59,    -1,   115,    -1,    42,    -1,
      58,    -1,   219,    -1,    50,    -1,    62,    -1,    35,    -1,
      48,    -1,   279,    -1,   255,    -1,   288,    -1,   290,    -1,
     259,    -1,   273,    -1,   286,    -1,   278,    -1,   258,    -1,
     272,    -1,   287,    -1,   277,    -1,   271,    -1,   270,    -1,
     254,    -1,   253,    -1,   262,    -1,   263,    -1,   292,    -1,
     282,    -1,   281,    -1,   276,    -1,   274,    -1,   275,    -1,
     235,    -1,   241,    -1,   238,    -1,   232,    -1,   225,    -1,
     224,    -1,   226,    -1,   243,    -1,   233,    -1,   234,    -1,
     240,    -1,   230,    -1,   239,    -1,    67,    -1,    65,    -1,
      76,    -1,   171,    -1,   204,    -1,   248,    -1,   246,    -1,
     247,    -1,   244,    -1,   245,    -1,   250,    -1,   251,    -1,
     252,    -1,    66,    -1,   301,    -1,   299,    -1,   300,    -1,
     305,    -1,   306,    -1,   307,    -1,   302,    -1,   303,    -1,
     304,    -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    88,    -1,    89,    -1,
      90,    -1,    91,    -1,   293,    -1,   294,    -1,   295,    -1,
     296,    -1,   297,    -1,   298,    -1,   309,    -1,   310,    -1,
     311,    -1,   312,    -1,   313,    -1,   314,    -1,   315,    -1,
      92,    -1,   107,    -1,   116,    -1,   174,    -1,   182,    -1,
     191,    -1,   140,    -1,    93,    -1,   117,    -1,   141,    -1,
     183,    -1,   320,    -1,   321,    -1,   322,    -1,   324,    -1,
     323,    -1,   326,    -1,    26,    -1
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
    1374,  1378,  1380,  1384,  1388,  1392,  1396,  1397,  1402,  1406,
    1410,  1414,  1416,  1422,  1424,  1428,  1429,  1431,  1433,  1437,
    1439,  1443,  1447,  1449,  1453,  1457,  1461,  1465,  1467,  1471,
    1475,  1477,  1481,  1485,  1487,  1492,  1494,  1499,  1501,  1506,
    1508,  1513,  1515,  1518,  1520,  1523,  1525,  1527,  1530,  1533,
    1535,  1537,  1539,  1541,  1545,  1547,  1549,  1551,  1553,  1555,
    1557,  1559,  1561,  1563,  1568,  1574,  1580,  1587,  1591,  1596,
    1598,  1601,  1605,  1608,  1611,  1613,  1615,  1617,  1619,  1621,
    1623,  1625,  1627,  1629,  1631,  1634,  1638,  1643,  1647,  1651,
    1655,  1659,  1663,  1665,  1668,  1672,  1674,  1676,  1678,  1680,
    1682,  1684,  1686,  1688,  1690,  1692,  1694,  1696,  1698,  1700,
    1702,  1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1721,
    1724,  1728,  1730,  1735,  1740,  1744,  1749,  1751,  1755,  1757,
    1761,  1763,  1765,  1769,  1773,  1775,  1777,  1779,  1781,  1783,
    1788,  1797,  1803,  1813,  1823,  1834,  1836,  1839,  1841,  1844,
    1851,  1852,  1854,  1858,  1862,  1863,  1865,  1867,  1869,  1872,
    1875,  1876,  1878,  1880,  1882,  1885,  1888,  1890,  1892,  1894,
    1896,  1898,  1900,  1902,  1904,  1906,  1908,  1910,  1914,  1918,
    1921,  1925,  1929,  1932,  1934,  1936,  1938,  1940,  1942,  1944,
    1946,  1951,  1955,  1963,  1967,  1975,  1980,  1985,  1989,  1997,
    2001,  2009,  2012,  2014,  2017,  2021,  2023,  2025,  2027,  2029,
    2031,  2035,  2039,  2041,  2043,  2045,  2047,  2051,  2053,  2055,
    2057,  2059,  2061,  2063,  2065,  2067,  2069,  2071,  2073,  2075,
    2079,  2083,  2088,  2093,  2097,  2101,  2105,  2109,  2114,  2119,
    2123,  2128,  2135,  2140,  2147,  2152,  2156,  2161,  2168,  2175,
    2180,  2187,  2194,  2199,  2201,  2204,  2206,  2208,  2210,  2215,
    2221,  2228,  2232,  2236,  2240,  2244,  2250,  2258,  2266,  2272,
    2278,  2284,  2292,  2300,  2306,  2312,  2316,  2320,  2326,  2334,
    2340,  2348,  2350,  2355,  2359,  2365,  2367,  2370,  2374,  2378,
    2380,  2384,  2387,  2388,  2390,  2392,  2395,  2397,  2401,  2403,
    2407,  2409,  2414,  2416,  2419,  2423,  2424,  2426,  2427,  2429,
    2434,  2437,  2441,  2443,  2444,  2446,  2451,  2452,  2454,  2457,
    2459,  2463,  2464,  2466,  2469,  2472,  2474,  2475,  2477,  2478,
    2480,  2482,  2484,  2486,  2488,  2490,  2492,  2496,  2500,  2502,
    2504,  2506,  2509,  2513,  2515,  2517,  2519,  2521,  2523,  2525,
    2527,  2529,  2532,  2535,  2537,  2539,  2542,  2545,  2549,  2551,
    2554,  2557,  2563,  2566,  2568,  2570,  2571,  2574,  2576,  2580,
    2585,  2586,  2589,  2590,  2593,  2598,  2603,  2607,  2610,  2614,
    2616,  2620,  2621,  2623,  2625,  2628,  2631,  2634,  2637,  2639,
    2642,  2645,  2648,  2651,  2655,  2658,  2662,  2666,  2671,  2674,
    2677,  2679,  2681,  2685,  2688,  2692,  2695,  2699,  2702,  2706,
    2709,  2713,  2717,  2721,  2727,  2733,  2739,  2745,  2754,  2760,
    2764,  2770,  2778,  2780,  2782,  2784,  2786,  2790,  2794,  2796,
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
    3238,  3240,  3242,  3244
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
    3570,  3578,  3582,  3592,  3599,  3608,  3618,  3617,  3631,  3640,
    3649,  3662,  3666,  3678,  3682,  3690,  3693,  3700,  3704,  3713,
    3717,  3721,  3729,  3733,  3739,  3745,  3751,  3761,  3765,  3769,
    3777,  3781,  3787,  3797,  3801,  3811,  3815,  3825,  3829,  3839,
    3843,  3853,  3857,  3866,  3870,  3878,  3882,  3886,  3890,  3900,
    3904,  3908,  3915,  3920,  3928,  3932,  3936,  3940,  3944,  3948,
    3956,  3960,  3964,  3972,  3976,  3980,  3984,  3995,  4001,  4011,
    4017,  4027,  4031,  4035,  4098,  4120,  4148,  4312,  4316,  4326,
    4330,  4334,  4338,  4347,  4351,  4355,  4359,  4363,  4368,  4372,
    4376,  4380,  4389,  4395,  4405,  4413,  4417,  4421,  4425,  4429,
    4433,  4437,  4441,  4445,  4449,  4454,  4458,  4462,  4466,  4474,
    4478,  4482,  4486,  4494,  4501,  4508,  4518,  4522,  4530,  4538,
    4542,  4550,  4558,  4566,  4620,  4624,  4646,  4652,  4658,  4664,
    4674,  4678,  4686,  4694,  4706,  4710,  4718,  4722,  4726,  4734,
    4742,  4759,  4767,  4784,  4803,  4827,  4833,  4844,  4850,  4861,
    4870,  4872,  4876,  4881,  4891,  4894,  4901,  4907,  4913,  4920,
    4932,  4935,  4942,  4948,  4954,  4961,  4972,  4976,  4984,  4988,
    4996,  5000,  5004,  5009,  5018,  5022,  5026,  5030,  5038,  5043,
    5051,  5056,  5064,  5072,  5077,  5082,  5087,  5092,  5097,  5102,
    5108,  5116,  5120,  5137,  5141,  5149,  5157,  5165,  5169,  5177,
    5181,  5189,  5197,  5201,  5205,  5240,  5246,  5252,  5262,  5266,
    5270,  5274,  5278,  5282,  5286,  5293,  5299,  5309,  5317,  5325,
    5329,  5333,  5337,  5341,  5345,  5349,  5353,  5357,  5361,  5369,
    5377,  5381,  5385,  5393,  5400,  5408,  5416,  5420,  5424,  5432,
    5436,  5442,  5448,  5452,  5462,  5470,  5474,  5480,  5489,  5498,
    5504,  5510,  5520,  5537,  5544,  5559,  5586,  5590,  5598,  5606,
    5610,  5621,  5638,  5644,  5650,  5660,  5664,  5670,  5676,  5680,
    5686,  5690,  5696,  5702,  5709,  5719,  5724,  5732,  5738,  5748,
    5770,  5779,  5785,  5798,  5812,  5819,  5825,  5835,  5844,  5852,
    5858,  5876,  5884,  5888,  5895,  5900,  5908,  5912,  5919,  5923,
    5930,  5934,  5941,  5945,  5954,  5967,  5970,  5978,  5981,  5989,
    5997,  6005,  6009,  6017,  6020,  6028,  6040,  6043,  6051,  6063,
    6069,  6079,  6082,  6090,  6094,  6098,  6106,  6109,  6117,  6120,
    6128,  6132,  6136,  6140,  6144,  6152,  6160,  6172,  6184,  6188,
    6192,  6200,  6206,  6216,  6220,  6224,  6228,  6232,  6236,  6240,
    6244,  6252,  6256,  6260,  6264,  6272,  6278,  6288,  6298,  6302,
    6310,  6320,  6331,  6338,  6342,  6350,  6353,  6360,  6365,  6374,
    6384,  6387,  6394,  6398,  6406,  6415,  6422,  6432,  6436,  6443,
    6449,  6459,  6462,  6469,  6474,  6486,  6494,  6506,  6514,  6518,
    6526,  6530,  6534,  6542,  6550,  6554,  6558,  6562,  6570,  6578,
    6590,  6594,  6602,  6616,  6620,  6627,  6632,  6640,  6645,  6654,
    6658,  6666,  6673,  6679,  6686,  6697,  6703,  6713,  6720,  6727,
    6752,  6780,  6808,  6812,  6816,  6824,  6831,  6838,  6850,  6854,
    6855,  6868,  6869,  6870,  6871,  6872,  6873,  6874,  6875,  6876,
    6877,  6878,  6879,  6880,  6881,  6882,  6883,  6884,  6888,  6889,
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
    7050,  7051,  7052,  7053,  7054,  7055,  7056,  7057,  7058,  7059,
    7060,  7061,  7062,  7063,  7064,  7065,  7066,  7067,  7068,  7069,
    7070,  7071,  7072,  7073,  7074,  7075,  7076,  7077,  7078,  7079,
    7080,  7081,  7082,  7083,  7084,  7085,  7086,  7087,  7088,  7089,
    7091,  7092,  7093,  7098
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
  const int jsoniq_parser::yylast_ = 16202;
  const int jsoniq_parser::yynnts_ = 321;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 548;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 341;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 595;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17394 "/home/mbrantner/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 7102 "/home/mbrantner/zorba/sandbox/src/compiler/parser/jsoniq_parser.y"


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

