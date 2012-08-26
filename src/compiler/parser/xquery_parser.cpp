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
#line 87 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"


#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/api/compilercb.h"
#include "store/api/update_consts.h"
#include "compiler/parser/xquery_driver.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )


namespace zorba
{
namespace parser
{
  extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_declare, *the_create;

}
}

#define YYDEBUG 1

using namespace std;
using namespace zorba;



/* Line 293 of lalr1.cc  */
#line 77 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 908 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1032 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 107 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 193 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
        case 110: /* "\"'DECIMAL'\"" */

/* Line 480 of lalr1.cc  */
#line 906 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 298 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 905 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 307 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 904 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 316 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 932 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 541 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 932 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 550 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 932 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 622 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 932 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 694 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2332 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2341 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 932 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2350 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2359 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2377 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 926 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 926 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2710 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 926 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2719 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 926 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2728 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 926 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2737 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 926 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2746 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 926 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2755 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 926 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2764 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 926 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2773 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 926 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2782 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 653: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2791 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 654: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2800 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 655: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 929 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2809 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2906 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1050 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1054 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1058 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1069 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1078 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1084 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1092 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1098 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1109 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1114 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1122 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1129 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1136 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1145 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1152 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1160 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1168 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1176 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1187 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1192 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1199 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1206 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1218 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1228 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1235 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1242 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 42:

/* Line 690 of lalr1.cc  */
#line 1277 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 43:

/* Line 690 of lalr1.cc  */
#line 1282 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 44:

/* Line 690 of lalr1.cc  */
#line 1290 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1298 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1306 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1311 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1319 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1324 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1332 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1337 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1345 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1352 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1359 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1366 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 58:

/* Line 690 of lalr1.cc  */
#line 1381 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 59:

/* Line 690 of lalr1.cc  */
#line 1391 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1396 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1404 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1412 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1423 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1430 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1441 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1446 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1454 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1461 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1468 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1477 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1490 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1498 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 73:

/* Line 690 of lalr1.cc  */
#line 1505 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1515 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1522 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1529 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 85:

/* Line 690 of lalr1.cc  */
#line 1552 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 86:

/* Line 690 of lalr1.cc  */
#line 1558 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1567 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1574 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1584 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1593 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1594 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1595 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1596 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1597 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1598 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1599 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1600 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1601 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1602 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1608 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1616 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1624 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1632 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1639 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1647 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1654 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1659 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1667 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1675 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 110:

/* Line 690 of lalr1.cc  */
#line 1689 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 111:

/* Line 690 of lalr1.cc  */
#line 1703 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 112:

/* Line 690 of lalr1.cc  */
#line 1720 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 113:

/* Line 690 of lalr1.cc  */
#line 1725 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 114:

/* Line 690 of lalr1.cc  */
#line 1733 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1741 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1752 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1757 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1766 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1771 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1778 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1783 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1793 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1798 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1807 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1813 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1826 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1831 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1839 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 129:

/* Line 690 of lalr1.cc  */
#line 1850 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 130:

/* Line 690 of lalr1.cc  */
#line 1865 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 131:

/* Line 690 of lalr1.cc  */
#line 1877 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 132:

/* Line 690 of lalr1.cc  */
#line 1892 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 133:

/* Line 690 of lalr1.cc  */
#line 1897 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 134:

/* Line 690 of lalr1.cc  */
#line 1902 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1907 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1915 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1922 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1933 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1938 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1948 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1955 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1962 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 143:

/* Line 690 of lalr1.cc  */
#line 1969 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 144:

/* Line 690 of lalr1.cc  */
#line 1979 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 145:

/* Line 690 of lalr1.cc  */
#line 1983 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 146:

/* Line 690 of lalr1.cc  */
#line 1989 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1993 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 2003 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2011 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2022 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 151:

/* Line 690 of lalr1.cc  */
#line 2028 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 152:

/* Line 690 of lalr1.cc  */
#line 2037 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2042 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2049 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2056 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2068 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2078 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2088 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 159:

/* Line 690 of lalr1.cc  */
#line 2099 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 160:

/* Line 690 of lalr1.cc  */
#line 2115 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ((yysemantic_stack_[(1) - (1)].expr) == NULL)
      {
        error((yylocation_stack_[(1) - (1)]), "syntax error, unexpected end of file, the query should not be empty");
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

  case 161:

/* Line 690 of lalr1.cc  */
#line 2135 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:

/* Line 690 of lalr1.cc  */
#line 2139 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 163:

/* Line 690 of lalr1.cc  */
#line 2143 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2151 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2155 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2159 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2167 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2172 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2184 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2191 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 183:

/* Line 690 of lalr1.cc  */
#line 2220 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 184:

/* Line 690 of lalr1.cc  */
#line 2225 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 185:

/* Line 690 of lalr1.cc  */
#line 2233 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 186:

/* Line 690 of lalr1.cc  */
#line 2250 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2258 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2266 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 189:

/* Line 690 of lalr1.cc  */
#line 2273 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2280 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2291 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,  // no type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2300 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)), // type
                                          NULL,  // no init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2309 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,  // no type
                                          (yysemantic_stack_[(4) - (4)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2318 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)), // type
                                          (yysemantic_stack_[(5) - (5)].expr),    // init expr
                                          NULL); // no annotations
      (yyval.node) = vd;
    }
    break;

  case 195:

/* Line 690 of lalr1.cc  */
#line 2331 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 196:

/* Line 690 of lalr1.cc  */
#line 2339 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 197:

/* Line 690 of lalr1.cc  */
#line 2347 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 198:

/* Line 690 of lalr1.cc  */
#line 2355 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 199:

/* Line 690 of lalr1.cc  */
#line 2370 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2375 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2383 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 202:

/* Line 690 of lalr1.cc  */
#line 2397 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 203:

/* Line 690 of lalr1.cc  */
#line 2414 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 204:

/* Line 690 of lalr1.cc  */
#line 2439 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 205:

/* Line 690 of lalr1.cc  */
#line 2447 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 206:

/* Line 690 of lalr1.cc  */
#line 2454 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 207:

/* Line 690 of lalr1.cc  */
#line 2465 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2475 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2480 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 228:

/* Line 690 of lalr1.cc  */
#line 2525 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 229:

/* Line 690 of lalr1.cc  */
#line 2539 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 230:

/* Line 690 of lalr1.cc  */
#line 2547 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 231:

/* Line 690 of lalr1.cc  */
#line 2552 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 232:

/* Line 690 of lalr1.cc  */
#line 2560 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 233:

/* Line 690 of lalr1.cc  */
#line 2565 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2570 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2578 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2587 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2599 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 238:

/* Line 690 of lalr1.cc  */
#line 2609 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2622 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 248:

/* Line 690 of lalr1.cc  */
#line 2646 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 249:

/* Line 690 of lalr1.cc  */
#line 2653 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 250:

/* Line 690 of lalr1.cc  */
#line 2663 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 251:

/* Line 690 of lalr1.cc  */
#line 2669 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected QName \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      YYERROR;
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2677 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2687 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList *vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2694 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList *vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2702 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      YYERROR;
    }
    break;

  case 256:

/* Line 690 of lalr1.cc  */
#line 2713 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 257:

/* Line 690 of lalr1.cc  */
#line 2723 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 258:

/* Line 690 of lalr1.cc  */
#line 2733 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 259:

/* Line 690 of lalr1.cc  */
#line 2743 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 260:

/* Line 690 of lalr1.cc  */
#line 2753 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 261:

/* Line 690 of lalr1.cc  */
#line 2763 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 262:

/* Line 690 of lalr1.cc  */
#line 2773 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 263:

/* Line 690 of lalr1.cc  */
#line 2783 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 264:

/* Line 690 of lalr1.cc  */
#line 2794 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 265:

/* Line 690 of lalr1.cc  */
#line 2803 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 266:

/* Line 690 of lalr1.cc  */
#line 2813 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 267:

/* Line 690 of lalr1.cc  */
#line 2823 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 268:

/* Line 690 of lalr1.cc  */
#line 2839 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 269:

/* Line 690 of lalr1.cc  */
#line 2848 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 270:

/* Line 690 of lalr1.cc  */
#line 2857 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 271:

/* Line 690 of lalr1.cc  */
#line 2865 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 272:

/* Line 690 of lalr1.cc  */
#line 2871 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2883 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2891 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2901 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2909 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2921 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 278:

/* Line 690 of lalr1.cc  */
#line 2927 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 280:

/* Line 690 of lalr1.cc  */
#line 2940 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 281:

/* Line 690 of lalr1.cc  */
#line 2944 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2952 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 283:

/* Line 690 of lalr1.cc  */
#line 2956 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2965 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2969 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 2973 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 288:

/* Line 690 of lalr1.cc  */
#line 2983 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 2991 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 2998 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3004 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3014 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3018 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3022 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3030 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3038 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3046 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3058 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 299:

/* Line 690 of lalr1.cc  */
#line 3066 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 300:

/* Line 690 of lalr1.cc  */
#line 3072 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 301:

/* Line 690 of lalr1.cc  */
#line 3082 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 302:

/* Line 690 of lalr1.cc  */
#line 3088 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3098 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3102 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3112 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3118 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3124 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3130 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3139 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3148 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3157 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3170 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 313:

/* Line 690 of lalr1.cc  */
#line 3174 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 314:

/* Line 690 of lalr1.cc  */
#line 3182 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 315:

/* Line 690 of lalr1.cc  */
#line 3188 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 316:

/* Line 690 of lalr1.cc  */
#line 3198 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3206 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3215 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3228 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3235 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3247 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 322:

/* Line 690 of lalr1.cc  */
#line 3251 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 323:

/* Line 690 of lalr1.cc  */
#line 3263 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3270 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3276 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3285 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3292 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3298 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3309 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3316 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3322 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3331 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3340 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3347 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3358 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3365 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3377 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3383 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3395 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3401 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3412 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3418 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3429 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3435 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3446 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3455 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3459 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3468 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3472 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3480 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3484 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 352:

/* Line 690 of lalr1.cc  */
#line 3494 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3501 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3510 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3519 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 356:

/* Line 690 of lalr1.cc  */
#line 3524 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3533 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3542 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3551 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3564 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3568 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3580 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3584 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3591 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3595 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3602 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3606 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3615 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3619 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3623 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3631 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3635 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3641 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3647 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3653 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3663 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3667 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3671 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3679 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3683 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3689 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3699 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3703 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3713 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3717 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3727 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3731 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3741 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3745 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3755 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3759 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3767 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3771 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3775 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3779 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3789 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3793 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3797 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3804 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3809 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3817 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3821 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3825 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3829 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3833 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3837 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3845 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3849 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3853 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3861 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3865 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3869 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3873 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3884 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3890 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3900 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3906 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3916 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3920 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3924 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3962 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3966 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3976 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3986 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3999 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 4008 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 4018 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4022 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4031 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4035 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4044 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4050 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 433:

/* Line 690 of lalr1.cc  */
#line 4058 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4064 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4076 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4082 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4092 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4096 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4100 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4104 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4108 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4114 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4120 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4128 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4132 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4140 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4144 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4155 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4159 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4163 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4169 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4173 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4187 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4191 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4199 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4203 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4213 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4217 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4221 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4225 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4234 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4238 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4242 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4246 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4254 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4260 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4270 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4278 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4282 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4286 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4290 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4294 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4298 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4302 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4306 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4310 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4314 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4319 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4323 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4327 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4331 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4339 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4343 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4351 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4358 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4365 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4376 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4384 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4388 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4396 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4404 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4412 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4466 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4470 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4483 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4489 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4499 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4503 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4511 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4515 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4519 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4527 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                NULL,
                NULL,
                NULL
            );
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4537 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                NULL,
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                NULL
            );
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4547 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname())
            {
              error((yylocation_stack_[(8) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(8) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(8) - (6)].expr)),
                NULL,
                NULL
            );
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4564 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
            {
              error((yylocation_stack_[(9) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                NULL,
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node))
            );
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4581 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname())
            {
              error((yylocation_stack_[(9) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(9) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(9) - (7)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(9) - (3)].node)),
                NULL
            );
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4598 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if (static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname() != static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname())
            {
              error((yylocation_stack_[(10) - (1)]), "syntax error, end tag </" + static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr))->get_qname().str() + "> does not match start tag <"
                                                   + static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr))->get_qname().str() + ">");
              YYERROR;
            }

            (yyval.expr) = new DirElemConstructor(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(10) - (2)].expr)),
                static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                dynamic_cast<DirAttributeList*>((yysemantic_stack_[(10) - (3)].node)),
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(10) - (6)].node))
            );
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4620 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4626 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4637 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 511:

/* Line 690 of lalr1.cc  */
#line 4643 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 512:

/* Line 690 of lalr1.cc  */
#line 4654 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 515:

/* Line 690 of lalr1.cc  */
#line 4671 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 516:

/* Line 690 of lalr1.cc  */
#line 4676 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4685 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4689 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4696 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4702 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 521:

/* Line 690 of lalr1.cc  */
#line 4708 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 522:

/* Line 690 of lalr1.cc  */
#line 4716 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4728 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4732 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4739 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4745 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4751 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4758 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4769 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4773 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4783 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4787 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4797 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4801 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4805 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4810 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4819 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4825 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4831 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4837 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4845 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4850 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4858 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4863 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4871 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4879 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4884 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4889 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4894 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4899 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4904 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4913 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4921 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4925 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4942 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4946 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4954 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4962 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4970 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4974 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 4982 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 4988 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 4998 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5006 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5010 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5014 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5049 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5055 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5061 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5071 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5075 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5079 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5083 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5087 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5091 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5095 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5102 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5108 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5118 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5126 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5130 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5134 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5138 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5142 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5146 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5150 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5154 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5158 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5166 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5174 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5178 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5182 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5192 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5200 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5208 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5212 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5216 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5224 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5228 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5234 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5240 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5244 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5254 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5262 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5266 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5272 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 5281 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 5290 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5296 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5302 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5312 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5329 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5336 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5351 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5387 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5391 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5399 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5407 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5419 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5423 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5431 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5439 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5443 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5454 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5471 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5477 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5483 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5493 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5497 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5503 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5509 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5513 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5519 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5523 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5529 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5535 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5542 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5552 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5557 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5565 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5571 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5581 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5603 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5612 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5618 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5631 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5645 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5652 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5658 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5668 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5677 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5685 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5691 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5709 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5717 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5721 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5728 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5733 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5741 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5745 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5752 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5756 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5763 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5767 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5774 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5778 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5787 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5799 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5803 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5810 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5814 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5822 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5830 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5838 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5842 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5849 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5853 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5861 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5872 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5876 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5884 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5896 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5902 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5911 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5915 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5923 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5927 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5931 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5938 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5942 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5949 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5953 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5961 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 5965 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 5969 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 5973 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 5977 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 5985 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 5993 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6005 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6017 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6021 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6025 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6033 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6039 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6049 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6053 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6057 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6061 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6065 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6069 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6073 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6077 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6085 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6089 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6093 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6097 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6105 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6111 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6121 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6131 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6135 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6143 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 724:

/* Line 690 of lalr1.cc  */
#line 6153 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 725:

/* Line 690 of lalr1.cc  */
#line 6164 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6171 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6175 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6182 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6186 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6193 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 731:

/* Line 690 of lalr1.cc  */
#line 6198 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 732:

/* Line 690 of lalr1.cc  */
#line 6207 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6216 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6220 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6227 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6231 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6239 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6248 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6255 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6265 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6269 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6276 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6282 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6291 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6295 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6302 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6307 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6319 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6327 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6339 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6347 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6351 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6359 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6363 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6367 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6375 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6383 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6387 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6391 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6395 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6403 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6411 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6423 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6427 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6435 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6449 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6453 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6460 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6465 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6473 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6478 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6487 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6495 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6501 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6511 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        static_cast<JSONPairList*>((yysemantic_stack_[(7) - (4)].node)),
                                        (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6517 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(10) - (4)].expr), (yysemantic_stack_[(10) - (7)].expr), (yysemantic_stack_[(10) - (10)].expr));
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6524 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6531 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation = 
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(3) - (3)].expr));

          if (lDynamicFunctionInvocation == NULL)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          rchandle<exprnode> lPrimaryExpr =
          lDynamicFunctionInvocation->getPrimaryExpr().release();

          rchandle<ArgList> lArgList =
          lDynamicFunctionInvocation->getArgList().release();

          if (lArgList->size() != 1)
          {
            error((yylocation_stack_[(3) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          rchandle<exprnode> lKey = (*lArgList)[0].release();
          (yyval.expr) = new JSONDeleteExpr(LOC((yyloc)), lPrimaryExpr.release(), lKey.release());
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6560 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation = 
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(5) - (3)].expr));

          if(lDynamicFunctionInvocation == NULL) 
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          rchandle<exprnode> lPrimaryExpr =
          lDynamicFunctionInvocation->getPrimaryExpr().release();

          rchandle<ArgList> lArgList =
          lDynamicFunctionInvocation->getArgList().release();

          if (lArgList->size() != 1)
          {
            error((yylocation_stack_[(5) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          rchandle<exprnode> lKey = (*lArgList)[0].release();
          (yyval.expr) = new JSONRenameExpr(LOC((yyloc)), lPrimaryExpr.release(), lKey.release(), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6589 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          rchandle<DynamicFunctionInvocation> lDynamicFunctionInvocation = 
          dynamic_cast<DynamicFunctionInvocation*>((yysemantic_stack_[(7) - (5)].expr));

          if(lDynamicFunctionInvocation == NULL) 
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation is expected. A filter was found instead.");
            YYERROR;
          }

          rchandle<exprnode> lPrimaryExpr =
          lDynamicFunctionInvocation->getPrimaryExpr().release();

          rchandle<ArgList> lArgList =
          lDynamicFunctionInvocation->getArgList().release();

          if (lArgList->size() != 1)
          {
            error((yylocation_stack_[(7) - (3)]), "An object invocation with exactly one argument is expected. Zero or more than one argument were found.");
            YYERROR;
          }

          rchandle<exprnode> lKey = (*lArgList)[0].release();
          (yyval.expr) = new JSONReplaceExpr(LOC((yyloc)), lPrimaryExpr.release(), lKey.release(), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6618 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6622 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6626 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 784:

/* Line 690 of lalr1.cc  */
#line 6633 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6640 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6647 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 789:

/* Line 690 of lalr1.cc  */
#line 6664 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 791:

/* Line 690 of lalr1.cc  */
#line 6677 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6678 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6679 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6680 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 795:

/* Line 690 of lalr1.cc  */
#line 6681 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 796:

/* Line 690 of lalr1.cc  */
#line 6682 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6683 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 798:

/* Line 690 of lalr1.cc  */
#line 6684 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 799:

/* Line 690 of lalr1.cc  */
#line 6685 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6686 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6687 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6688 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6689 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6690 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6691 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6696 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6697 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6698 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6699 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6700 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6701 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6702 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 814:

/* Line 690 of lalr1.cc  */
#line 6703 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6704 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6705 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6706 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6707 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6708 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6709 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6710 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6711 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6712 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6713 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6714 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6715 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6716 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6717 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6718 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6719 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6720 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6721 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6722 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6723 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6724 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6725 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6726 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6727 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6728 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6729 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6730 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6731 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6732 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6733 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6734 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6735 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6736 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6737 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6738 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6739 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6740 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6741 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6742 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6743 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6744 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6745 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6746 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6747 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6748 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6749 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6750 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6751 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6752 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6753 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6754 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6755 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6756 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6757 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6758 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6759 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6760 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6761 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6762 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6763 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6764 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6765 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6766 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6767 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6768 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6769 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6770 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6771 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6772 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6773 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6774 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6775 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6776 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6777 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6778 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6779 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6780 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6781 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6782 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6783 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6784 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6785 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6786 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6787 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6788 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6789 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6790 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6791 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6792 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6793 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6794 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6795 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6796 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6797 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6798 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6799 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6800 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6801 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6802 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6803 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6804 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6805 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6806 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6807 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6808 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6809 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6810 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6811 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6812 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6813 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6814 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6815 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6816 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6817 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6818 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6819 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6820 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6821 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6822 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6823 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6824 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6825 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6826 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6827 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6828 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6829 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6830 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6831 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6832 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6833 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6834 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6835 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6836 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6837 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6838 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6839 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6840 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6841 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6842 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6843 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6844 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6845 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6846 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6847 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6848 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6849 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6850 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6851 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6852 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6853 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6854 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6855 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6856 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6857 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6858 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6859 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6860 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6861 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6862 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6863 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6864 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6865 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6866 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6867 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6868 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6869 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6870 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6871 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6872 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6873 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6874 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6875 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6876 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6877 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6878 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6879 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 6880 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 6881 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 6882 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 6883 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 6884 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 6885 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 6886 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 6887 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 6888 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 6889 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 6890 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 6891 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 6892 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 6893 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 6894 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 6895 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 6896 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 6897 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 6898 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 6899 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 6900 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 6905 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12175 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1512;
  const short int
  xquery_parser::yypact_[] =
  {
      3150, -1512, -1512, -1512,  5014,  5014,  5014, -1512, -1512,    80,
     211, -1512,   127,   213, -1512, -1512, -1512,   784, -1512, -1512,
   -1512,   224,   255,   797,  2869,   327,   391,   776, -1512,     9,
   -1512, -1512, -1512, -1512, -1512, -1512,   799, -1512,   530,   610,
   -1512, -1512, -1512, -1512,    57, -1512,   801, -1512,   686,   709,
   -1512,   245, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512,   521,   747, -1512, -1512,
   -1512, -1512,   626, 10904, -1512, -1512, -1512,   751, -1512, -1512,
   -1512,   791, -1512,   807,   809, -1512, -1512, 15291, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512,   815, -1512, -1512,   813,
     820, -1512, -1512, -1512, -1512, -1512, -1512, -1512,  3774,  6874,
    7184, 15291, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   795,
   -1512, -1512,   834, 11799, -1512, 12102,   869,   871, -1512, -1512,
   -1512,   879, -1512, 10284, -1512, -1512, -1512, -1512, -1512, -1512,
     850, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,    67,
     728, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   -84,
     853,   -80, -1512,   -97,   165, -1512, -1512, -1512, -1512, -1512,
   -1512,   888, -1512,   771,   773,   774, -1512, -1512,   866,   870,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512,  7494,  7804, -1512,   710, -1512, -1512, -1512,
   -1512, -1512,  3462,  5324,  1025, -1512,  5634, -1512, -1512,   664,
      90, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,   118, -1512, -1512, -1512, -1512,
   -1512, -1512,   162, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512,  5014, -1512, -1512, -1512, -1512,    35, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,   919, -1512,   837, -1512, -1512,
   -1512,   172, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
     863,   936, -1512,   779,   782,   933,   522,   487,   685,    43,
   -1512,   983,   835,   935,   932,  9044, -1512,   844, -1512, -1512,
      19, -1512, -1512, 10594, -1512,   732, -1512,   884, 10904, -1512,
     884, 10904, -1512, -1512, -1512,   707, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512,   894,   885, -1512,
   -1512, -1512, -1512, -1512,   856, -1512,  5014,   858,   859,   319,
     319,  1015,   495,   578,   210, 15579, 15291,   348,   998, 15291,
     896,   928,   418, 11799,   695,   804, 15291, 15291,   749,   683,
      49, -1512, -1512, -1512, 11799,  5014,   864,  5014,   114,  9354,
   12987, 15291, -1512,   770,   778, 15291,   934,   295,   904,  9354,
    1058,   171,    89, 15291,   942,   921,   957, -1512,  9354, 11502,
   15291, 15291, 15291,  5014,   878,  9354,  9354, 15291,  5014,   913,
     914, -1512, -1512, -1512,  9354, 13275,   912, -1512,   915, -1512,
   -1512, -1512, -1512,   916, -1512,   917, -1512, -1512, -1512, -1512,
   -1512,   918, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   15291, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512,   927, 15291, -1512, -1512, -1512,   886,  4084,
     954,    53,   923,   924,   925, 15291,  5014, -1512,   929,    18,
   -1512,   395, -1512,    48,  1042,  9354, -1512, -1512,    91, -1512,
   -1512, -1512,  1066, -1512, -1512, -1512, -1512,  9354,   872, -1512,
    1055,  9354,  9354, 12402,   898,  9354,  9354,   822,  9354, 12402,
    9354,   857,   860, 15291,   897,   899,  9354,  9354,  3774,   846,
   -1512,   -17, -1512,   -13,   938,  5324, -1512, -1512, -1512, -1512,
   -1512,   127,   776,   123,   125,  1090,  5944,  5944,  6254,  6254,
     791, -1512, -1512,   919,   791, -1512,  9354, -1512,   977,   629,
       9,   931,   926,   930,  5014,  9354, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512,  9664,  9664,  9664, -1512,  9664,  9664,
   -1512,  9664, -1512,  9664, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512,  9664,  9664,  1031,  9664,  9664,  9664,  9664,  9664,  9664,
    9664,  9664,  9664,  9664,  9664,  9664,   873,  1009,  1011,  1012,
   -1512, -1512, -1512,  9974,  8114, -1512, -1512, 10284, 10284,  9354,
     884, -1512, -1512,   884, -1512,  8424,   884,   958,  8734, -1512,
   -1512, -1512,    63, -1512,   244, -1512, -1512, -1512, -1512, -1512,
   -1512,  1001,  1005,   327,  1084, -1512, -1512, 15579,   880,   665,
   15291,   955,   956,   880,  1015,   994,   990, -1512, -1512, -1512,
     593,   881,  1030,   826, 15291,   984,  9354,  1010, 15291, 15291,
   -1512,  1000,   946,  5014, -1512,   949,   915,   610, -1512,   947,
     948,   326, -1512,   302,   303,  1029, -1512,    38, -1512, -1512,
    1029, 15291,    30, 15291,  1043,   313, -1512,  5014, -1512,   328,
   -1512, 11799,  1045,  1093, 11799,  1015,  1046,   647, 15291,  9354,
       9,   389,   952, -1512,   959,   960,   961,    24, -1512,    72,
     965, -1512,   332,   333,   991, -1512,   966,  5014,  5014,   411,
   -1512,   335,   343,   661,  9354,    33, -1512, -1512,  9354,  9354,
   -1512,  9354,  9354,  9354, -1512,  9354, -1512,  9354, -1512, 15291,
    1042, -1512,   215,   430, -1512, -1512, -1512,   460, -1512,   368,
   -1512, -1512,   992,   999,  1004,  1007,  1008,   707,   894, -1512,
      13,   135,  9354,  9354,  1049,   588,   937,   939,   920,    22,
   -1512,  1016, -1512, -1512,   972,   345,  4394,   494, 11205,   846,
   -1512, -1512, -1512,  9354, -1512,   664,   755,  1130,  1130, -1512,
   -1512,   132, -1512, -1512,   134, -1512,   131, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, 15291,   995,  9354,  1048, -1512, -1512,
   -1512,   936, -1512, -1512, -1512, -1512, -1512,  9664, -1512, -1512,
   -1512,    71, -1512,   487,   487,    15,   685,   685,   685,   685,
      43,    43, -1512, -1512, 14427, 14427, 15291, 15291, -1512, -1512,
     501, -1512, -1512,   232, -1512, -1512, -1512,   353, -1512, -1512,
     364,   319, -1512, -1512,   231,   606,   676, -1512,   327, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   880,
   -1512,  1035, 14715,  1026,  9354, -1512, -1512, -1512,  1075,  1015,
    1015,   880, -1512,   851,  1015,   668, 15291,   619,   640,  1141,
   -1512, -1512,   887,   545, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,   593,    42,   944,   607,  9354,
   -1512, 15291,  1078,   876,  1015, -1512, -1512, -1512, -1512,  1023,
   15291, -1512, 15291, -1512, 15003,  1050, 14427,  1060,  9354,    60,
    1032,    52,    98,   940, -1512, -1512,   699,    30,  1075, 14427,
    1062,  1088,  1002,   985,  1052,  1015,  1027,  1053,  1092,  1015,
    9354,   -22, -1512, -1512, -1512,  1036, -1512, -1512, -1512, -1512,
    1072,  9354,  9354,  1051, -1512,  1096,  1097,  5014, -1512,  1017,
    1018,  1039, 15291, -1512, 15291, -1512,  9354,  1057,  1003,  9354,
   -1512,  1079,   378,   381,   388,  1168, -1512,   463, -1512,   249,
   -1512, -1512,  1175, -1512,   559,  9354,  9354,  9354,   657,  9354,
    9354,  9354,   954,   503,   341,  9354,  9354,  9354,  9354, 12402,
    1089,  9354,  9354, -1512,  6564,  1054,  1056,  1059,  1061,   837,
     502,   963, -1512,    -1, -1512,   370,   137,    73,   131,  6254,
    6254,  6254,  1127, -1512,  9354,   724,  1102, -1512, 15291,  1104,
   -1512, -1512,  9354,    71,   193,   216, -1512,   941,   259,   962,
     953, -1512, -1512,   804, -1512,   950,   590,  1065,  1067, 14715,
    1069,  1071,  1080,  1081,  1086, -1512,   586, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
    1074, -1512, -1512, -1512,  9354, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512,   697, -1512,  1187,   748, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512,   964, -1512, -1512,
    1193, -1512, -1512, -1512, -1512, -1512,   561,  1199, -1512,   571,
   -1512, -1512, -1512,   912,   255,   916,   530,   917,   918,   853,
    1071,  1080,  1081, -1512,   586,   586,  9974,   967,   943, -1512,
    1075,    42,  1013,  1073,  5014,  1064,  1068,  1091,  1070,  1077,
   15291, -1512,    50, -1512, 15291, -1512,  9354,  1105,  9354,  1117,
    9354,    68,  1109,  9354,  1112, -1512,  1143,  1144,  9354, 15291,
     448,  1188, -1512, -1512, -1512, -1512, -1512, -1512, 14427, -1512,
    5014,  1015,  1159, -1512, -1512, -1512,  1015,  1159, -1512,  9354,
    1125,  5014, 15291, -1512, -1512,  9354,  9354,   735, -1512,   104,
     739, -1512, 13563,   762, -1512,   766, -1512,  1085, -1512, -1512,
    5014,  1083,  1087, -1512,  9354, -1512, -1512,  9354,  1082,  1096,
    1172, -1512,  1145, -1512,   262, -1512, -1512,  1266, -1512, -1512,
    5014, 15291, -1512,   730, -1512, -1512, -1512,  1094,  1063,  1076,
   -1512, -1512, -1512,  1098,  1099, -1512, -1512, -1512,  1100,  1101,
   -1512, -1512, -1512,  1038,    26, 15291,  1095, -1512, -1512,  9354,
    9354,  9354,  4704,  6564, 11205,   963, -1512, 11205, -1512,  1103,
    1130,   547, -1512, -1512, -1512,  1102, -1512,  1015, -1512,   861,
   -1512,   565,  1176, -1512,  9354,   667,  1048,   544,  1107, -1512,
      71,  1028, -1512, -1512,   532, -1512,   637,    81,  1033,    71,
     637,  9664, -1512,   325, -1512, -1512, -1512, -1512, -1512, -1512,
      71,  1139,  1006,   881,    81, -1512, -1512,  1019,  1209, -1512,
   -1512, -1512, 12699,  1114,  1116,  1119,  1120,  1121,  1124,  1126,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512,  1260,    27,  1263,    27,  1041,  1192, -1512, -1512,
    1146, 15291,  1110, -1512, -1512,  9974, -1512,  1131, -1512, -1512,
   -1512, -1512, -1512, -1512,  9354,  1167, -1512, -1512,  9354, -1512,
     552, -1512,  9354,  1170,  9354, -1512,  9354, 15291, 15291, -1512,
     705, -1512,  9354, -1512,  1194,  1195,  1226,  1015,  1159, -1512,
    9354,  1142, -1512, -1512, -1512,  1137, -1512,   263,  9354,  5014,
    1149,   294, -1512, 15291,  1150, 13851,   519, -1512, 14139,  1151,
   -1512, -1512,  1154, -1512, -1512, -1512, -1512,  9354,   767,  1168,
   15291,   775, -1512,  1156,  1168, 15291, -1512, -1512,  9354,  9354,
    9354,  9354,  9354,  9354,  9354,  9354, -1512,  9354,   401,   402,
     416,   513, -1512, -1512,  9354, -1512, -1512, -1512,  1176, -1512,
   -1512, -1512,  1015,  9354, -1512,  1183, -1512, -1512, -1512, -1512,
    1157,  9664, -1512, -1512, -1512, -1512, -1512,   603,  9664,  9664,
     393, -1512,   962, -1512,   293, -1512,   953,    71,  1174, -1512,
   -1512,  1106, -1512, -1512, -1512, -1512,  1235,  1158, -1512,   476,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   600,   600,
   -1512,    27, -1512, -1512,   477, -1512,  1301,    81,  1248,  1160,
    9974,   -12,  1111,  1178, -1512, -1512,  9354, -1512,  9354,  1202,
   -1512,  9354, -1512, -1512, -1512,  1293, -1512, -1512,  6564,  9354,
    1015, -1512, -1512, -1512,  9354,  9354, -1512, -1512, -1512,  6564,
    6564,  1258,  5014, 15291,  1169, 15291,  9354, 15291,  1173,  6564,
   -1512,   541,    28,  1168, 15291, -1512,  1161,  1168, -1512, -1512,
   -1512, -1512, -1512,  1257, -1512, -1512, -1512,  1162,  1096,  1097,
    9354, -1512, -1512, -1512, -1512,  1255,  9354, -1512,   685,  9664,
    9664,    15,   632, -1512, -1512, -1512, -1512, -1512, -1512,  9354,
   -1512, 14427, -1512, 14427,  1268, -1512, -1512, -1512,  1325, -1512,
   -1512, -1512,  1115,  1259, -1512, -1512,  1261, -1512,   693, 15291,
    1246,  1140, 15291,  9974, -1512, -1512,  9354, -1512,  1251, -1512,
   -1512,  1159, -1512, -1512, 14427, -1512, -1512,  1276,  9354,  1185,
   -1512,  1278,  6564, -1512, 15291,   274,   611, -1512,  1179,  1168,
   -1512,  1182,  1113,  6564,   768,   549, -1512,  1255,    15,    15,
    9664,   554, -1512, -1512, 14427, -1512, -1512,  1248,  9974, -1512,
    1176,  1118, 15291,  1264,  1148,  1261, -1512, 15291,  1197, 14427,
    5014, 14427,  1201, -1512, -1512,  1288,   449, -1512, -1512, -1512,
   -1512,  1205,   612, -1512, -1512, -1512,  1196, -1512,  9354,  1267,
   -1512, -1512,    15, -1512, -1512, -1512, -1512, -1512,  9354,  1122,
   15291,  1271, -1512,  5014,  1204, -1512, -1512,  1206,  9354, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, 15291, -1512,  1123,
    1128, 15291, -1512, -1512,  9354,  6564,  1208,  1129,  9354,  1132,
    6564,  9974, -1512,  9974, -1512,  1198,  1133, 15291,  1166,  1277,
   15291,  1134,  9974, -1512
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       163,   458,   459,   460,   166,   166,   166,   807,  1012,   118,
     120,   614,   899,   908,   848,   812,   810,   792,   900,   903,
     855,   816,   793,   794,     0,   909,   796,   906,   877,   857,
     832,   852,   853,   904,   901,   851,   798,   907,   799,   800,
     948,   960,   947,   849,   868,   862,   801,   850,   803,   802,
     949,   886,   887,   854,   829,   970,   971,   972,   973,   974,
     975,   976,   977,   978,   979,   980,   994,  1001,   876,   872,
     863,   843,   791,     0,   871,   879,   888,   995,   867,   484,
     844,   845,   902,   996,  1002,   864,   881,     0,   490,   447,
     486,   874,   809,   865,   866,   895,   869,   885,   894,  1000,
    1003,   815,   856,   897,   485,   884,   890,   795,     0,     0,
       0,     0,   393,   882,   893,   898,   896,   875,   861,   950,
     859,   860,   997,     0,   392,     0,   998,  1004,   891,   846,
     870,   999,   425,     0,   457,   892,   873,   880,   889,   883,
     951,   837,   842,   841,   840,   839,   838,   804,   858,     0,
     808,   905,   830,   939,   938,   940,   814,   813,   833,   945,
     797,   937,   942,   943,   934,   836,   878,   936,   946,   944,
     935,   834,   941,   955,   956,   953,   954,   952,   805,   957,
     958,   959,   925,   924,   911,   828,   821,   918,   914,   831,
     827,   926,   927,   817,   818,   811,   820,   923,   922,   919,
     915,   932,   933,   931,   921,   917,   910,   819,   930,   929,
     823,   825,   824,   916,   920,   912,   826,   913,   822,   928,
     981,   982,   983,   984,   985,   986,   962,   963,   961,   967,
     968,   969,   964,   965,   966,   835,   987,   988,   989,   990,
     991,   992,   993,     0,     0,  1005,  1006,  1007,  1010,  1009,
    1008,  1011,   163,   163,     0,     2,   163,     7,     9,    21,
       0,    26,    29,    34,    35,    36,    37,    38,    39,    40,
      30,    56,    57,    31,    32,     0,    74,    77,    78,    33,
      79,    80,     0,   116,    81,    82,    83,    84,    16,   160,
     161,   162,   169,   171,   477,   172,     0,   173,   174,   175,
     176,   177,   178,   179,   182,   167,   208,   215,   210,   242,
     248,     0,   240,   241,   217,   211,   181,   212,   180,   213,
     216,   346,   348,   350,   360,   362,   366,   368,   371,   376,
     379,   382,   384,   386,   388,     0,   390,   397,   396,   398,
       0,   416,   399,   421,   424,   426,   429,   431,     0,   436,
     433,     0,   444,   454,   456,   430,   461,   468,   482,   469,
     470,   471,   474,   475,   472,   473,   497,   499,   500,   501,
     498,   546,   547,   548,   549,   550,   551,   453,   588,   580,
     587,   586,   585,   582,   584,   581,   583,   483,   476,   615,
     616,    41,   218,   219,   221,   220,   222,   214,   479,   480,
     481,   478,   224,   227,   223,   225,   226,   455,   790,   806,
     899,   908,   906,   808,     0,   164,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   270,   271,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   449,   452,   439,     0,     0,   792,   816,   794,   847,
     909,   796,   857,   798,   868,   801,   803,   802,   886,   994,
    1001,   791,   995,   845,   996,  1002,   869,  1000,  1003,   950,
     997,   998,  1004,   999,   951,   945,   937,   943,   934,   834,
     955,   956,   953,   805,   957,  1006,   445,   455,   790,   437,
       0,   189,   438,   441,   792,   793,   794,   798,   799,   800,
     801,   791,   797,   487,     0,   443,   442,   184,     0,     0,
     208,     0,   796,   803,   802,     0,   166,   766,   957,     0,
     215,     0,   488,     0,   513,     0,   448,   788,     0,   789,
     419,   420,     0,   451,   450,   440,   423,     0,     0,   542,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     768,     0,   770,     0,     0,   163,     3,     4,     1,     8,
      10,     0,     0,     0,     0,     0,   163,   163,   163,   163,
       0,   117,   170,   168,     0,   187,     0,   196,     0,     0,
       0,     0,     0,     0,     0,     0,   201,   228,   247,   243,
     249,   244,   246,   245,     0,     0,     0,   409,     0,     0,
     407,     0,   355,     0,   408,   401,   406,   405,   404,   403,
     402,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     395,   394,   391,     0,     0,   417,   422,     0,     0,     0,
     432,   465,   435,   434,   446,     0,   462,     0,     0,   553,
     555,   559,     0,   122,     0,   787,    45,    42,    43,    46,
      47,     0,     0,     0,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   625,   626,   627,
       0,   101,   140,     0,     0,   110,     0,     0,     0,     0,
     125,     0,     0,     0,   594,     0,     0,     0,   590,     0,
       0,     0,   604,     0,     0,   251,   253,     0,   230,   231,
     250,     0,     0,     0,   132,     0,   136,   166,   618,     0,
      58,     0,    67,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,   595,     0,     0,     0,     0,   319,     0,
       0,   593,     0,     0,     0,   612,     0,     0,     0,     0,
     598,     0,     0,   191,     0,     0,   185,   183,     0,     0,
     772,     0,     0,     0,   487,     0,   767,     0,   489,   514,
     513,   510,     0,     0,   544,   543,   418,     0,   541,     0,
     638,   639,   792,   794,   798,   801,   791,   778,     0,   589,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     644,     0,   199,   200,     0,     0,     0,     0,     0,   204,
     205,   769,   771,     0,     5,    22,     0,    23,     0,     6,
      27,     0,    13,    28,     0,    17,   899,    75,    14,    76,
      18,   190,   188,   209,     0,     0,     0,     0,   202,   229,
     288,   347,   349,   353,   359,   358,   357,     0,   354,   351,
     352,     0,   363,   370,   369,   367,   373,   374,   375,   372,
     377,   378,   381,   380,     0,     0,     0,     0,   400,   414,
       0,   427,   428,     0,   466,   463,   495,     0,   617,   493,
       0,     0,   119,   121,     0,     0,     0,   100,     0,    90,
      92,    93,    94,    95,    97,    98,    99,    91,    96,    86,
      87,     0,     0,   106,     0,   102,   104,   105,   112,     0,
       0,    85,    44,     0,     0,     0,     0,     0,     0,     0,
     716,   721,     0,     0,   717,   751,   704,   706,   707,   708,
     710,   712,   711,   709,   713,     0,     0,     0,     0,     0,
     109,     0,   142,     0,     0,   558,   552,   591,   592,     0,
       0,   608,     0,   605,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,   233,     0,   238,   138,     0,
       0,   133,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,   269,   275,   272,     0,   597,   596,   603,   611,
       0,     0,     0,     0,   557,     0,     0,     0,   410,     0,
       0,     0,     0,   601,     0,   599,     0,   192,     0,     0,
     773,     0,     0,     0,     0,   513,   511,     0,   502,     0,
     491,   492,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   197,     0,   796,   803,   802,   957,     0,
       0,     0,   652,     0,   206,     0,     0,     0,     0,   163,
     163,   163,     0,   239,     0,   303,   299,   301,     0,   289,
     290,   356,     0,     0,     0,     0,   682,   364,   655,   659,
     661,   663,   665,   668,   675,   676,   684,   909,   795,     0,
     804,  1010,  1009,  1008,  1011,   383,   564,   570,   571,   574,
     619,   620,   575,   576,   781,   782,   783,   579,   385,   387,
     561,   389,   415,   467,     0,   464,   494,   123,    54,    55,
      52,    53,   129,   128,     0,    88,     0,     0,   107,   108,
     113,    72,    73,    50,    51,    71,   722,     0,   725,   752,
       0,   715,   714,   719,   718,   750,     0,     0,   727,     0,
     723,   726,   705,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   141,   144,   146,     0,     0,     0,   111,
     114,     0,     0,     0,   166,     0,     0,   612,     0,     0,
       0,   255,     0,   563,     0,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,     0,     0,     0,
     282,     0,   279,   284,   237,   139,   134,   137,     0,   186,
       0,     0,    69,    63,    66,    65,     0,    61,   273,     0,
       0,   166,     0,   317,   321,     0,     0,     0,   324,     0,
       0,   330,     0,     0,   337,     0,   341,     0,   412,   411,
     166,     0,     0,   193,     0,   195,   318,     0,     0,     0,
       0,   514,     0,   503,     0,   537,   534,     0,   538,   539,
       0,     0,   533,     0,   508,   536,   535,     0,     0,     0,
     631,   632,   628,     0,     0,   636,   637,   633,     0,     0,
     642,   779,   640,     0,     0,     0,     0,   646,   198,     0,
       0,     0,     0,     0,     0,   647,   648,     0,   207,     0,
      24,     0,    15,    19,    20,   300,   312,     0,   313,     0,
     304,   305,   306,   307,     0,   292,     0,     0,     0,   666,
     679,     0,   361,   365,     0,   698,     0,     0,     0,     0,
       0,     0,   654,   656,   657,   693,   694,   695,   697,   696,
       0,     0,   670,   669,     0,   673,   677,   691,   689,   688,
     681,   685,     0,     0,     0,     0,     0,     0,     0,     0,
     567,   569,   568,   565,   562,   496,   131,   130,    89,   103,
     739,   720,     0,   744,     0,   744,   733,   728,   145,   147,
       0,     0,     0,   115,   143,     0,    25,     0,   609,   610,
     613,   606,   607,   254,     0,     0,   268,   260,     0,   264,
       0,   258,     0,     0,     0,   277,     0,     0,     0,   236,
     280,   283,     0,   135,     0,     0,    68,     0,    62,   274,
       0,     0,   320,   322,   327,     0,   325,     0,     0,     0,
       0,     0,   331,     0,     0,     0,     0,   338,     0,     0,
     342,   413,     0,   602,   600,   194,   774,     0,     0,   513,
       0,     0,   545,     0,   513,     0,   509,    12,     0,     0,
       0,     0,     0,     0,     0,     0,   645,     0,     0,     0,
       0,     0,   649,   653,     0,   316,   314,   315,   308,   309,
     310,   302,     0,     0,   297,     0,   291,   683,   674,   680,
       0,     0,   753,   754,   764,   763,   762,     0,     0,     0,
       0,   755,   660,   761,     0,   658,   662,     0,     0,   667,
     671,     0,   692,   687,   690,   686,     0,     0,   577,     0,
     572,   624,   566,   785,   786,   784,   573,   740,     0,     0,
     738,   745,   746,   742,     0,   737,     0,   735,     0,     0,
       0,     0,     0,     0,   554,   257,     0,   266,     0,     0,
     262,     0,   265,   278,   286,   287,   281,   235,     0,     0,
       0,    64,   276,   560,     0,     0,   328,   332,   326,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     556,     0,     0,   513,     0,   540,     0,   513,   629,   630,
     634,   635,   775,     0,   641,   780,   643,     0,     0,     0,
       0,   650,   777,   311,   298,   293,     0,   678,   765,     0,
       0,   757,     0,   703,   702,   701,   700,   699,   664,     0,
     756,     0,   621,     0,     0,   749,   748,   747,     0,   741,
     734,   732,     0,   729,   730,   724,   148,   150,   152,     0,
       0,     0,     0,     0,   261,   259,     0,   267,     0,   203,
     345,    70,   323,   329,     0,   343,   339,     0,     0,     0,
     333,     0,     0,   335,     0,   523,   517,   512,     0,   513,
     504,     0,     0,     0,     0,     0,   296,   294,   759,   758,
       0,     0,   622,   578,     0,   743,   736,     0,     0,   154,
     153,     0,     0,     0,     0,   149,   263,     0,     0,     0,
       0,     0,     0,   531,   525,     0,   524,   526,   532,   529,
     519,     0,   518,   520,   530,   506,     0,   505,     0,     0,
     651,   295,   760,   672,   623,   731,   151,   155,     0,     0,
       0,     0,   285,     0,     0,   336,   334,     0,     0,   516,
     527,   528,   515,   521,   522,   507,   776,     0,   156,     0,
       0,     0,   344,   340,     0,     0,     0,     0,     0,     0,
       0,     0,   158,     0,   157,     0,     0,     0,     0,     0,
       0,     0,     0,   159
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1512, -1512,  -235,  -201, -1512,  1147,  1152, -1512,  1153,  -546,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
    -988, -1512, -1512, -1512, -1512,  -236,  -582, -1512,   673,  -103,
   -1512, -1512, -1512, -1512, -1512,   222,   447, -1512, -1512,    12,
    -165,   981, -1512,   969, -1512, -1512,  -624, -1512,   382, -1512,
     183, -1512,  -288,  -332, -1512,  -550, -1512,     5,    29,    14,
    -245,  -177, -1512,  -858, -1512, -1512,  -430, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512,   548,   -93,  1189,
       0, -1512, -1512, -1512, -1512,   394, -1512, -1512,  -285, -1512,
       8, -1512,   970,  -932,  -719,  -702, -1512, -1512,   630, -1512,
   -1512,   -47,   164, -1512, -1512, -1512,    51, -1511, -1512,   301,
      54, -1512, -1512,    58, -1302, -1512,   877,   150, -1512, -1512,
     147, -1003, -1512, -1512,   146, -1512, -1512, -1244, -1233, -1512,
     143, -1512, -1512,   786,   787, -1512,  -569,   772, -1512, -1512,
    -652,   329,  -639,   324,   330, -1512, -1512, -1512, -1512, -1512,
    1135, -1512, -1512, -1512, -1512, -1512,  -854,  -333,  -682, -1512,
     -88, -1512, -1512, -1512, -1512, -1512, -1512, -1512,   -16,  -809,
   -1512,  -535,   624,   217, -1512,  -398, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512,   733, -1512, -1008, -1512,   130, -1512,   617,
    -792, -1512, -1512, -1512, -1512, -1512,  -323,  -315, -1204,  -938,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
     525,  -750,  -857,  -216,  -837, -1512,   102,  -850, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512,   996,   997,  -348,   441,   270,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512, -1512, -1512, -1512,   112, -1512, -1512,   103, -1512,   105,
   -1060, -1512, -1512, -1512,    74,    61,  -107,   331, -1512, -1512,
   -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512, -1512,
   -1512,    69, -1512, -1512, -1512,  -100,   338,   472, -1512, -1512,
   -1512, -1512, -1512,   261, -1512, -1512, -1483, -1512, -1512, -1512,
    -558, -1512,    36, -1512,  -123, -1512, -1512, -1512, -1512, -1299,
   -1512,    82, -1512, -1512, -1512, -1512, -1512,   621, -1512, -1512,
   -1512, -1512, -1512,  -903, -1512, -1512, -1512,  -418,  -371,   239,
    1108, -1512
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   254,   868,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
    1262,   775,   272,   273,   274,   275,   276,   277,   949,   950,
     951,   278,   279,   280,   955,   956,   957,   281,   439,   282,
     283,   702,   284,   441,   442,   443,   458,   765,   766,   285,
    1213,   286,  1686,  1687,   287,   288,   289,   548,   290,   291,
     292,   293,   294,   768,   295,   296,   531,   297,   298,   299,
     300,   301,   302,   636,   303,   304,   859,   860,   305,   306,
     560,   308,   637,   456,  1016,  1017,   309,   638,   310,   640,
     561,   312,   755,   756,  1250,   465,   313,   466,   467,   762,
    1251,  1252,  1253,   641,   642,  1119,  1120,  1534,   643,  1116,
    1117,  1360,  1361,  1362,  1363,   314,   787,   788,   315,  1277,
    1278,  1477,   316,  1280,  1281,   317,   318,  1283,  1284,  1285,
    1286,   319,   320,   321,   322,   897,   323,   324,  1372,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   661,   662,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   696,   691,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   927,   365,   366,   367,  1313,   820,   821,
     822,  1717,  1761,  1762,  1755,  1756,  1763,  1757,  1314,  1315,
     368,   369,  1316,   370,   371,   372,   373,   374,   375,   376,
    1159,  1011,  1145,  1413,  1146,  1569,  1147,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   794,  1226,   387,
     388,   389,   390,  1149,  1150,  1151,  1152,   391,   392,   393,
     394,   395,   396,   849,   850,   397,  1345,  1346,  1651,  1103,
    1127,  1382,  1383,  1128,  1129,  1130,  1131,  1132,  1392,  1559,
    1560,  1133,  1395,  1134,  1540,  1135,  1136,  1400,  1401,  1565,
    1563,  1384,  1385,  1386,  1387,  1666,   731,   976,   977,   978,
     979,   980,   981,  1200,  1589,  1683,  1201,  1587,  1681,   982,
    1425,  1584,  1580,  1581,  1582,   983,   984,  1388,  1396,  1550,
    1389,  1546,  1373,   398,   399,   400,   401,   551,   402,   403,
     404,   405,   406,  1153,  1154,  1155,  1156,  1263,   568,   407,
     408,   409
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -848;
  const short int
  xquery_parser::yytable_[] =
  {
       307,   918,   599,   706,   307,   307,   307,   685,   311,   414,
     417,   418,   311,   311,   311,   905,   559,   563,   416,   416,
     416,   703,   703,   614,   440,   617,   639,  1031,  1067,   906,
     907,   908,   909,   415,   415,   415,   877,   879,  1009,  1043,
     619,  1267,  1279,   772,   776,   576,   622,  1125,   837,  1102,
    1487,   606,   607,  1057,   845,  1010,  1498,   526,  1158,  1529,
    1530,  1312,   726,  1368,  1148,  1148,   872,   875,   878,   880,
     870,   873,  1231,   741,  1005,     9,    10,   893,  1173,   894,
     895,  1203,   896,  1215,   898,  1013,  1204,   746,  1239,   936,
     626,   615,   899,   900,   626,  1561,   425,   578,   784,   824,
      11,  1205,  1148,  1206,   747,  1684,  1689,  1074,   307,  1506,
     421,   422,  1207,   423,   424,  1177,   311,   621,   705,   615,
    1269,  1715,   549,   428,   615,   626,   615,   463,   588,  1090,
     427,  1040,  1006,   615,  1007,   615,  1214,   415,   615,  1208,
    1040,   581,   624,   582,  1726,   585,  1007,   586,  1007,  1233,
     601,   603,  1342,     9,    10,   626,  1148,     9,    10,   746,
     809,   737,  1256,  1578,   421,   422,  1006,   423,   424,  1148,
     931,   622,   684,   665,   425,   472,   747,  1547,   425,   674,
     689,    79,   695,   426,   427,  1008,  1351,   426,     9,    10,
     881,   666,  1006,   675,   882,    90,   125,  1444,   623,  1240,
     705,   428,   773,   816,  1478,   428,   429,  1236,  1180,  1347,
     429,  1716,  1041,  1690,   628,  1452,  1771,   589,   629,  1042,
     104,  1059,    11,   630,  1122,   625,  1653,  1123,  1579,  1078,
     583,  1075,  1076,   433,   587,   818,   419,   810,   430,   431,
     432,   631,   430,   431,  1112,  1243,  1077,  1014,   125,   774,
     932,   464,   307,   307,  1775,   686,   307,  1091,  1305,  1306,
     311,   311,  1244,  1515,   311,  1487,   825,  1209,  1255,  1125,
    1125,  1305,  1306,  1302,   620,   621,   639,  1481,  1468,  1753,
     616,   579,   464,  1305,  1015,   877,   879,   433,  1682,  1148,
    1479,   307,  1241,   434,   861,  1691,  1312,  1506,  1443,   311,
     862,   748,  1404,    79,   622,  1312,   962,  1237,   618,  1242,
    1539,   464,   527,   865,  1174,   867,  1417,    90,  1215,   870,
     873,   477,  1109,   623,  1111,   464,   543,  1350,  1121,  1270,
    1124,   771,   692,   464,   435,   694,   738,  1548,  1549,   626,
     632,   464,   104,   633,   739,  1068,  1122,   434,    11,  1123,
     564,   931,  1307,  1079,  1080,  1374,   751,  1028,   634,  1210,
    1211,  1212,   569,  1478,   572,  1307,   769,   420,  1081,  1370,
     125,  1214,  1308,   444,  1309,   781,   711,   447,   866,  1168,
     871,   874,   792,   793,   635,  1308,  1739,  1309,   435,   888,
     590,   799,   712,   125,  1478,   591,  1169,  1308,   478,  1309,
    1024,  1463,  1310,  1027,   864,  1724,   111,  1754,  1148,  1000,
    1002,   448,  1069,   763,   436,  1310,   307,  1163,   436,   111,
    1020,  1374,   437,   123,   311,  1484,   437,  1310,  1375,    79,
     438,   933,  1148,   626,   438,   626,   123,   628,  1777,   626,
     626,   629,  1052,    90,  1311,   307,   630,   307,   626,  1615,
    1054,   665,   626,   311,  1753,   311,   623,  1500,  1305,   743,
    1164,   743,   149,   721,   631,   722,   479,   480,   104,   666,
    1433,  1164,   823,   307,   742,   149,   745,   626,   307,   592,
    1620,   311,   764,   457,   827,   626,   311,   743,   626,  1001,
    1003,  1487,   743,  1312,  1375,   626,   626,   723,   622,  1072,
    1021,  1246,   790,  1126,   855,   857,  1247,   796,   626,   626,
     999,  1376,  1377,  1445,  1378,  1023,  1125,   715,   626,  1045,
    1046,  1379,  1053,   626,   724,  1125,  1329,   877,   879,   877,
    1055,  1380,  1094,  1167,  1430,  1102,  1125,   626,  1523,  1453,
    1165,  1181,  1182,  1381,   628,  1568,  1185,   459,   629,   307,
     716,  1166,  1148,   630,  1334,  1349,   307,   311,  1073,  1352,
    1353,  1354,  1663,   632,   311,  1298,   633,   626,  1299,  1664,
     416,   631,  1308,  1035,  1309,  1300,  1223,  1376,  1377,  1665,
    1378,   817,  1790,  1673,  1678,   415,   725,   527,  1647,  1648,
     527,   920,   721,  1303,   722,  1051,   923,  1380,   307,   921,
     922,   626,  1310,  1649,   668,   307,   311,   635,   626,  1381,
     809,   622,   856,   311,  1070,  1535,   307,   307,   307,   307,
    1305,  1305,  1701,   440,   311,   311,   311,   311,  1624,  1106,
     451,  1628,   452,   669,   307,  1148,  1110,  1625,  1148,  1759,
    1759,  1197,   311,   481,  1071,  1481,   670,   965,  1007,   966,
     623,   626,  1225,   724,  1228,  1659,   626,  1422,  1198,  1714,
    1304,   626,  1663,  1674,  1679,   714,  1650,  1197,   718,  1664,
     632,  1357,   569,   633,  1423,   732,   733,   707,  1101,  1665,
     665,   671,  1086,   569,  1198,  1162,   470,  1328,  1343,   754,
     757,   708,  1359,   967,   757,   453,  1422,   611,   666,  1598,
     454,  1199,   777,  1125,  1291,  1626,  1292,  1632,   569,   785,
     786,   789,  1636,   612,   635,   725,   795,  1424,  1062,  1063,
    1064,   667,   857,  1347,   802,  1126,  1126,  1626,  1537,  1554,
    1410,  1599,  1660,  1770,  1308,  1308,  1309,  1309,  1773,  1305,
    1306,  1006,   689,   307,   695,  1760,  1793,   455,   483,  1542,
    1084,   311,  1246,  1593,  1170,  1006,  1424,  1247,  1246,   952,
     709,  1006,  1411,  1247,  1310,  1310,   471,   307,   877,   803,
    1105,  1171,  1022,  1532,   710,   311,  1248,  1758,  1764,   484,
    1412,   416,   485,   789,  1305,  1306,  1543,  1006,  1107,  1030,
     665,  1318,   685,  1319,   814,  1007,   415,   307,   307,  1357,
     460,  1007,   953,  1056,   612,   311,   311,   954,   666,  1533,
     461,   743,   743,  1172,  1732,   639,  1733,  1249,  1758,  1356,
     735,  1148,   838,  1148,  1764,   736,  1049,  1050,   838,   767,
    1357,  1730,   851,  1307,  1416,  1276,   462,  1397,  1398,  1276,
    1358,  1718,   475,  1466,   968,  1721,  1175,  1748,  1475,  1338,
     767,  1359,  1480,  1308,  1148,  1309,  1099,   969,  1175,   970,
    1399,   689,  1485,   695,  1100,   476,  1488,  1485,  1485,   482,
     971,   972,   973,   529,   974,  1486,   975,  1774,  1307,  1489,
    1631,  1769,  1191,  1310,  1148,   953,   672,   111,   440,  1323,
     954,  1324,  1784,  1192,  1787,   673,  1661,  1662,  1308,  1148,
    1309,  1148,  1658,  1193,   123,  1544,  1217,   924,  1688,   530,
     924,   646,  1545,   924,  1194,  1218,   727,   728,   729,   647,
     648,   599,   649,   687,   688,  1505,  1348,  1766,  1310,   532,
     650,   533,   111,   544,   651,   545,   652,   445,  1740,  1525,
     446,   653,   546,   149,   580,  1186,  1187,  1188,   565,   123,
     449,  1189,   468,   450,   473,   469,   566,   474,   654,   958,
     939,   940,   941,   942,   943,   944,   945,   946,   947,   948,
    1634,   690,  1126,   988,   693,   842,   843,   992,   993,  1183,
    1184,  1126,   655,   656,   657,   658,   659,   660,   149,  1526,
    1527,   573,  1126,   574,   903,   904,   910,   911,  1428,  1429,
    1012,   575,  1018,   577,   912,   913,   593,  1728,  1729,   584,
     569,  1688,   594,   569,   595,  1464,   596,  1032,  1160,  1160,
    1675,  1676,   597,   598,   604,   608,   626,   627,   645,  1367,
     644,   663,   664,   676,   679,   677,   678,   683,   689,   697,
     699,   698,   700,   701,   705,   717,   720,   307,   719,  1611,
     730,   744,   761,   734,   758,   311,  1688,   767,  1065,   770,
     778,   743,   759,   779,   780,   791,   797,   798,   446,   804,
     806,   450,   469,   474,   485,   808,  1287,   819,  1772,   811,
     812,   813,   815,   826,   829,   839,   828,   852,   847,   853,
     848,   858,   863,   869,  1099,   884,   886,   527,   888,   885,
     887,   901,  1100,   915,   914,   916,   917,   928,   934,   307,
     307,   307,   935,   937,  1654,   959,   960,   311,   311,   311,
     440,   963,   964,  1113,   986,   987,   989,   985,   991,  1814,
     995,  1815,   994,   996,   997,   998,  1004,  1019,  1026,  1036,
    1823,  1025,  1029,  1085,  1047,   445,  1037,  1038,  1039,  1044,
    1048,  1089,   449,  1157,  1157,  1157,  1157,   468,  1092,  1126,
     473,   484,  1093,  1108,  1088,  1114,  1118,  1176,   954,  1006,
    1195,  1216,  1221,  1196,  1087,  1222,  1224,  1232,  1234,  1238,
     763,   528,  1258,  1260,  1261,  1265,  1259,  1264,  1266,  1271,
    1272,  1157,  1290,  1295,  1245,   528,  1276,  1282,  1275,  1294,
    1297,  1288,  1289,  1301,  1317,  1190,   723,  1335,  1344,  1364,
    1339,  1366,  1340,  1391,  1342,  1341,    11,  1394,  1414,   528,
    1390,  1402,  1421,  1403,   307,  1405,  1371,  1406,  1426,  1437,
    1220,   528,   311,   528,  1617,  1440,  1407,  1408,   416,  1227,
    1435,  1227,  1409,   757,  1450,  1157,  1518,  1519,  1520,  1432,
    1420,  1438,  1448,   415,  1431,  1439,  1454,  1441,  1157,  1456,
     307,  1457,  1458,  1436,  1442,  1462,  1467,  1470,   311,  1491,
    1493,   307,  1485,  1502,  1494,  1514,  1471,  1499,  1541,   311,
    1497,  1517,  1357,  1551,  1507,   416,  1557,  1564,  1558,  1577,
     307,   795,  1583,   795,  1538,  1492,  1508,   550,   311,  1588,
     415,  1570,  1524,  1571,   416,  1562,  1572,  1573,  1574,  1509,
     307,  1575,  1586,  1576,  1596,  1594,  1590,  1601,   311,   415,
    1608,  1609,  1610,  1614,   743,  1656,  1613,  1669,   838,  1671,
    1680,  1510,  1511,  1512,  1513,  1619,  1622,  1629,  1630,  1503,
    1635,  1657,  1099,  1099,  1197,  1672,  1698,  1685,  1693,  1696,
    1100,  1100,  1704,  1722,  1735,  1708,   856,  1365,  1720,  1712,
    1723,  1532,  1734,  1699,  1742,  1743,  1737,  1592,  1738,  1747,
    1749,  1750,  1751,  1781,  1703,  1617,  1765,  1705,  1157,  1767,
    1736,  1789,  1780,  1783,  1713,  1797,  1670,  1788,  1792,  1801,
    1804,  1819,  1805,  1795,  1810,  1820,   961,  1816,  1692,  1419,
    1178,   704,  1257,   609,  1434,  1745,  1776,  1104,   610,   740,
    1034,  1254,   613,  1606,  1461,  1355,  1807,  1536,  1531,  1528,
    1817,   805,  1472,  1778,  1476,   760,  1482,  1799,  1490,  1768,
     891,   930,   892,  1808,  1501,  1811,   902,  1066,  1813,  1794,
    1822,  1791,  1161,  1229,   749,   750,  1418,  1516,  1522,  1521,
    1668,  1556,  1555,  1552,  1667,  1369,   528,  1202,  1677,   528,
    1427,  1585,  1553,  1083,     0,     0,     0,  1705,     0,   757,
     682,  1393,     0,  1446,     0,     0,     0,     0,  1464,   307,
       0,     0,     0,     0,     0,     0,     0,   311,  1460,     0,
       0,     0,     0,     0,     0,     0,     0,  1157,     0,     0,
       0,     0,     0,     0,     0,  1785,     0,     0,     0,     0,
       0,   789,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   713,   528,     0,     0,   528,  1802,     0,
       0,   528,     0,     0,   528,   528,     0,     0,     0,     0,
    1504,     0,   528,     0,     0,     0,     0,  1725,   528,   528,
    1802,     0,     0,   528,     0,  1785,     0,     0,     0,     0,
       0,   528,     0,     0,   851,     0,  1731,   528,   528,   528,
     528,     0,     0,   527,     0,   528,   527,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1099,     0,
       0,     0,     0,     0,     0,     0,  1100,     0,     0,  1099,
    1099,     0,   307,     0,     0,     0,     0,  1100,  1100,  1099,
     311,     0,     0,     0,     0,     0,     0,  1100,   528,     0,
       0,  1157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
    1591,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1604,  1605,     0,     0,
       0,   528,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1099,     0,     0,     0,     0,     0,     0,     0,
    1100,     0,  1621,  1099,  1157,     0,     0,  1157,     0,     0,
       0,  1100,     0,     0,     0,     0,     0,     0,     0,  1633,
       0,     0,     0,     0,  1637,   550,     0,     0,     0,     0,
     307,     0,     0,     0,     0,     0,     0,     0,   311,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     830,   831,     0,     0,   840,   841,     0,   844,     0,   846,
       0,     0,     0,   307,     0,   854,     0,     0,     0,     0,
       0,   311,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1099,     0,     0,     0,     0,
    1099,     0,     0,  1100,     0,   883,     0,     0,  1100,     0,
       0,     0,     0,   889,   890,   938,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,   528,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1707,     0,  1709,     0,  1711,     0,     0,   528,
       0,   528,     0,  1719,     0,     0,     0,     0,     0,   528,
       0,     0,   528,     0,   926,     0,   528,   926,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1157,     0,  1157,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   990,     0,   528,  1741,     0,
       0,  1744,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1157,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1752,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,  1033,     0,
       0,     0,     0,  1157,     0,     0,     0,     0,     0,     0,
       0,  1779,     0,     0,     0,     0,  1782,     0,  1157,     0,
    1157,     0,   528,  1058,     0,     0,     0,  1060,  1061,     0,
       0,     0,     0,     0,     0,     0,   889,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1800,
       0,     0,   528,   528,   528,   528,     0,     0,     0,     0,
       0,  1082,     0,     0,     0,     0,  1806,     0,     0,     0,
    1809,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1818,     0,     0,  1821,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,  1115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,   528,     0,
     528,     0,   528,     0,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1179,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1268,
       0,     0,     0,     0,     0,     0,   528,     0,     0,     0,
    1273,  1274,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1293,     0,   528,  1296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1320,  1321,  1322,     0,  1325,  1326,
    1327,     0,     0,     0,  1330,  1331,  1332,  1333,     0,     0,
    1336,  1337,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1415,     0,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,  1447,     0,  1449,     0,  1451,
       0,     0,  1455,     0,     0,     0,     0,  1459,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,  1465,
       0,     0,   528,     0,     0,   528,     0,     0,  1469,     0,
       0,     0,     0,     0,  1473,  1474,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1495,     0,     0,  1496,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,   528,     0,     0,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1595,     0,     0,     0,  1597,     0,     0,
       0,  1600,     0,  1602,     0,  1603,     0,     0,     0,     0,
       0,  1607,     0,     0,     0,     0,     0,     0,     0,  1612,
       0,     0,     0,     0,     0,     0,     0,  1616,  1618,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1465,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1638,  1639,  1640,
    1641,  1642,  1643,  1644,  1645,     0,  1646,     0,     0,     0,
       0,     0,     0,  1652,     0,     0,     0,     0,     0,     0,
       0,     0,  1655,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,   528,     0,   528,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,   528,     0,     0,     0,  1694,     0,  1695,     0,     0,
    1697,     0,     0,     0,     0,     0,     0,   528,  1700,     0,
     528,     0,     0,  1702,  1618,     0,     0,     0,     0,     0,
       0,  1706,   528,     0,     0,  1710,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,  1727,     0,     0,     0,     0,
     528,     0,     0,     0,     0,   528,     0,   528,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -847,
     451,     0,   452,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1746,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,  1706,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,   528,
       0,  -847,     0,     0,     0,  -847,     0,     0,     0,  -847,
    -847,     0,     0,     0,  -847,   528,     0,     0,   528,     0,
       0,     0,     0,     0,     0,   453,     0,     0,  -847,  1786,
     454,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1796,     0,     0,
       0,  -847,     0,  -847,  -847,  -847,     0,  1798,  -847,  -847,
    -847,  -847,  1803,     0,     0,  -847,  -847,  1786,     0,     0,
       0,     0,  -847,     0,     0,  -847,  -847,   455,     0,     0,
    -847,     0,     0,  1803,     0,  -847,  -847,  1812,     0,     0,
       0,  -847,     0,     0,     0,  -847,     0,     0,     0,  -847,
    -847,     0,  -847,     0,  -847,  -847,     0,     0,     0,  -847,
    -847,     0,     0,  -847,  -847,  -847,  -847,  -847,  -847,     0,
       0,  -847,     0,     0,     0,     0,  -847,  -847,     0,     0,
    -847,     0,     0,     0,     0,  -847,     0,     0,  -847,     0,
       0,     0,     0,  -847,  -847,  -847,  -847,  -847,     0,  -847,
    -847,  -847,  -847,  -847,     0,     0,     0,     0,  -847,  -847,
    -847,     0,  -847,  -847,  -847,  -847,  -847,  -847,     0,  -847,
       0,  -847,     0,     0,     0,     0,  -847,  -847,  -847,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -847,     0,  -847,     0,  -847,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -847,     0,
       0,     0,     0,  -847,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
    -847,     0,  -847,    12,    13,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,   132,   133,     0,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   246,   247,   248,   249,   250,
     251,   252,   253,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,    12,    13,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     0,   605,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,   547,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,   807,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1095,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1096,  1097,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,   807,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1098,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1095,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1096,  1097,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,   547,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1098,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,    12,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   876,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1095,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1096,  1097,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1098,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,   557,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,   562,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   600,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,   602,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,   919,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,   925,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,   929,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,    25,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,    46,    47,   496,   497,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   680,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     681,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   525,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   552,   412,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   553,   554,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   520,   521,   522,   176,   177,   523,   558,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,    25,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,    46,    47,   496,   497,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   525,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,    25,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,    46,    47,   496,   497,    50,   498,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
       0,     0,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   525,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,    25,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,    46,    47,   496,   497,    50,   498,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   556,   109,     0,
     110,   111,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
       0,     0,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,     0,     0,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   525,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   410,   411,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
     489,    25,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,    46,    47,   496,   497,    50,   498,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   503,    82,    83,    84,
      85,    86,   555,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
       0,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,     0,   106,   107,   556,   109,     0,
     110,   111,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
       0,     0,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,     0,     0,     0,   134,     0,
     135,     0,   136,     0,   138,     0,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   525,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   410,   411,     0,
      14,    15,    16,   486,    18,    19,    20,   487,    22,   488,
     489,   490,   491,   412,    28,   492,    30,    31,     0,    32,
      33,    34,    35,   493,    37,    38,    39,    40,    41,    42,
      43,   494,     0,    45,   495,    47,   496,   497,    50,   498,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   499,   500,    68,     0,    69,    70,
      71,   501,     0,     0,    74,    75,    76,     0,     0,   502,
      78,     0,     0,     0,     0,    80,   503,    82,   504,   505,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   506,
      97,    98,   507,   508,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   509,   120,   121,   510,     0,     0,     0,
       0,     0,     0,     0,   511,   512,   128,     0,     0,     0,
     129,     0,   130,   513,     0,     0,     0,     0,   134,     0,
     135,     0,   136,   137,   138,   139,   514,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,     0,     0,   413,
     151,   152,   153,   154,   155,   156,   157,   158,   515,   160,
     516,   162,   517,   518,   165,   166,   167,   168,   169,   170,
     519,   172,   520,   521,   522,   176,   177,   523,   524,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     1,     2,   245,   525,
     247,   248,   249,   250,   251,     3,     0,     0,     0,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   410,   411,
       0,    14,    15,    16,   534,    18,    19,    20,   487,   535,
     536,   489,   490,   491,   412,    28,   492,    30,    31,     0,
      32,    33,    34,    35,   537,    37,   538,   539,    40,    41,
      42,    43,   494,     0,    45,   540,    47,   496,   497,    50,
     498,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   499,   500,    68,     0,    69,
      70,    71,   541,     0,     0,    74,    75,    76,     0,     0,
     502,    78,     0,     0,     0,     0,    80,   503,    82,   504,
     505,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     506,    97,    98,   507,   508,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   509,   120,   121,   510,     0,     0,
       0,     0,     0,     0,     0,   511,   512,   128,     0,     0,
       0,   129,     0,   130,   513,     0,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   514,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     413,   151,   152,   153,   154,   155,   156,   157,   158,   515,
     542,   516,   162,   517,   518,   165,   166,   167,   168,   169,
     170,   519,   172,   520,   521,   522,   176,   177,   523,   524,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     0,   567,   245,
     525,   247,   248,   249,   250,   251,     7,     8,     0,     0,
       0,   782,     0,     0,     0,   410,   411,     0,    14,    15,
      16,   534,    18,    19,    20,   487,   535,   536,   489,   490,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,   537,    37,   538,   539,    40,    41,    42,    43,   494,
       0,    45,   540,    47,   496,   497,    50,   498,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   499,   500,    68,     0,    69,    70,    71,   541,
       0,     0,    74,    75,    76,     0,     0,   502,    78,     0,
       0,     0,     0,    80,   503,    82,   504,   505,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
     507,   508,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   509,   120,   121,   510,     0,     0,     0,     0,     0,
       0,     0,   511,   512,   128,     0,     0,     0,   129,   783,
     130,   513,     0,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   514,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   542,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,   567,   245,   525,   247,   248,
     249,   250,   251,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   410,   411,     0,    14,    15,    16,   534,    18,
      19,    20,   487,   535,   536,   489,   490,   491,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,   537,    37,
     538,   539,    40,    41,    42,    43,   494,     0,    45,   540,
      47,   496,   497,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,   541,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,     0,   130,   513,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   542,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   245,   525,   247,   248,   249,   250,   251,
     570,   571,     0,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   410,   411,     0,    14,    15,
      16,   534,    18,    19,    20,   487,   535,   536,   489,   490,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,   537,    37,   538,   539,    40,    41,    42,    43,   494,
       0,    45,   540,    47,   496,   497,    50,   498,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   499,   500,    68,     0,    69,    70,    71,   541,
       0,     0,    74,    75,    76,     0,     0,   502,    78,     0,
       0,     0,     0,    80,   503,    82,   504,   505,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
     507,   508,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   509,   120,   121,   510,     0,     0,     0,     0,     0,
       0,     0,   511,   512,   128,     0,     0,     0,   129,     0,
     130,   513,     0,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   514,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   542,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,     0,   245,   525,   247,   248,
     249,   250,   251,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,   832,    18,    19,    20,    21,   535,   833,   489,    25,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,   834,    37,   538,   539,    40,    41,    42,    43,   494,
       0,    45,   835,    47,   496,   497,    50,   498,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   499,   500,    68,     0,    69,    70,    71,   836,
       0,     0,    74,    75,    76,     0,     0,   502,    78,     0,
       0,     0,    79,    80,   503,    82,   504,   505,    85,    86,
     555,    88,     0,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
     507,   508,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   510,     0,   123,     0,     0,     0,
       0,     0,   511,   512,   128,     0,     0,     0,   129,     0,
     130,   513,     0,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   542,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   525,   247,   248,
     249,   250,   251,     7,     8,     0,     0,     0,     0,     0,
       0,     0,   410,   411,     0,    14,    15,    16,   486,    18,
      19,    20,   487,    22,   488,   489,  1137,   491,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,   493,    37,
      38,    39,    40,    41,    42,    43,   494,     0,    45,   495,
      47,   496,   497,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,   501,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1138,     0,     0,     0,  1139,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,  1566,   130,   513,     0,
       0,     0,     0,  1567,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
    1140,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   160,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   525,   247,  1141,  1142,  1143,  1144,
     410,   411,     0,    14,    15,    16,   534,    18,    19,    20,
     487,   535,   536,   489,   490,   491,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,   537,    37,   538,   539,
      40,    41,    42,    43,   494,     0,    45,   540,    47,   496,
     497,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,   541,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   506,    97,    98,   507,   508,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   509,   120,   121,   510,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   128,
       0,     0,     0,   129,   752,   130,   513,     0,     0,     0,
       0,   753,     0,   135,     0,   136,   137,   138,   139,   514,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   413,   151,   152,   153,   154,   155,   156,   157,
     158,   515,   542,   516,   162,   517,   518,   165,   166,   167,
     168,   169,   170,   519,   172,   520,   521,   522,   176,   177,
     523,   524,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   525,   247,   248,   249,   250,   251,   410,   411,
       0,    14,    15,    16,   534,    18,    19,    20,   487,   535,
     536,   489,   490,   491,   412,    28,   492,    30,    31,     0,
      32,    33,    34,    35,   537,    37,   538,   539,    40,    41,
      42,    43,   494,     0,    45,   540,    47,   496,   497,    50,
     498,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   499,   500,    68,     0,    69,
      70,    71,   541,     0,     0,    74,    75,    76,     0,     0,
     502,    78,     0,     0,     0,     0,    80,   503,    82,   504,
     505,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     506,    97,    98,   507,   508,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,   107,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   509,   120,   121,   510,     0,     0,
       0,     0,     0,     0,     0,   511,   512,   128,     0,     0,
       0,   129,   800,   130,   513,     0,     0,     0,     0,   801,
       0,   135,     0,   136,   137,   138,   139,   514,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     413,   151,   152,   153,   154,   155,   156,   157,   158,   515,
     542,   516,   162,   517,   518,   165,   166,   167,   168,   169,
     170,   519,   172,   520,   521,   522,   176,   177,   523,   524,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     525,   247,   248,   249,   250,   251,   410,   411,     0,    14,
      15,    16,   486,    18,    19,    20,   487,    22,   488,   489,
    1137,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   493,    37,    38,    39,    40,    41,    42,    43,
     494,     0,    45,   495,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     501,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,  1483,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1138,     0,     0,     0,  1139,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,  1140,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,   160,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,   523,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   525,   247,
    1141,  1142,  1143,  1144,   410,   411,     0,    14,    15,    16,
     486,    18,    19,    20,   487,    22,   488,   489,  1137,   491,
     412,    28,   492,    30,    31,     0,    32,    33,    34,    35,
     493,    37,    38,    39,    40,    41,    42,    43,   494,     0,
      45,   495,    47,   496,   497,    50,   498,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   499,   500,    68,     0,    69,    70,    71,   501,     0,
       0,    74,    75,    76,     0,     0,   502,    78,     0,     0,
       0,     0,    80,   503,    82,   504,   505,    85,    86,  1623,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   506,    97,    98,   507,
     508,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1138,     0,     0,     0,  1139,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     509,   120,   121,   510,     0,     0,     0,     0,     0,     0,
       0,   511,   512,   128,     0,     0,     0,   129,     0,   130,
     513,     0,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   514,   141,   142,   143,   144,   145,   146,
       0,     0,  1140,   148,     0,     0,   413,   151,   152,   153,
     154,   155,   156,   157,   158,   515,   160,   516,   162,   517,
     518,   165,   166,   167,   168,   169,   170,   519,   172,   520,
     521,   522,   176,   177,   523,   524,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   525,   247,  1141,  1142,
    1143,  1144,   410,   411,     0,    14,    15,    16,   486,    18,
      19,    20,   487,    22,   488,   489,  1137,   491,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,   493,    37,
      38,    39,    40,    41,    42,    43,   494,     0,    45,   495,
      47,   496,   497,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,   501,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,  1627,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,  1138,     0,     0,     0,  1139,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,     0,   130,   513,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
    1140,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   160,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   525,   247,  1141,  1142,  1143,  1144,
     410,   411,     0,    14,    15,    16,   486,    18,    19,    20,
     487,    22,   488,   489,  1137,   491,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,   493,    37,    38,    39,
      40,    41,    42,    43,   494,     0,    45,   495,    47,   496,
     497,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,   501,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   506,    97,    98,   507,   508,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1138,
       0,     0,     0,  1139,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   509,   120,   121,   510,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   128,
       0,     0,     0,   129,     0,   130,   513,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   514,
     141,   142,   143,   144,   145,   146,     0,     0,  1140,   148,
       0,     0,   413,   151,   152,   153,   154,   155,   156,   157,
     158,   515,   160,   516,   162,   517,   518,   165,   166,   167,
     168,   169,   170,   519,   172,   520,   521,   522,   176,   177,
     523,   524,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   525,   247,  1141,  1142,  1143,  1144,   410,   411,
       0,    14,    15,    16,   486,    18,    19,    20,   487,    22,
     488,   489,  1137,   491,   412,    28,   492,    30,    31,     0,
      32,    33,    34,    35,   493,    37,    38,    39,    40,    41,
      42,    43,   494,     0,    45,   495,    47,   496,   497,    50,
     498,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   499,   500,    68,     0,    69,
      70,    71,   501,     0,     0,    74,    75,    76,     0,     0,
     502,    78,     0,     0,     0,     0,    80,   503,    82,   504,
     505,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     506,    97,    98,   507,   508,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1138,     0,     0,
       0,  1139,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   509,   120,   121,   510,     0,     0,
       0,     0,     0,     0,     0,   511,   512,   128,     0,     0,
       0,   129,     0,   130,   513,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   514,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     413,   151,   152,   153,   154,   155,   156,   157,   158,   515,
     160,   516,   162,   517,   518,   165,   166,   167,   168,   169,
     170,   519,   172,   520,   521,   522,   176,   177,   523,   524,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     525,   247,  1141,  1142,  1143,  1144,   410,   411,     0,    14,
      15,    16,   534,    18,    19,    20,   487,   535,   536,   489,
     490,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   537,    37,   538,   539,    40,    41,    42,    43,
     494,     0,    45,   540,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     541,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,  1230,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,   542,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,   523,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   525,   247,
     248,   249,   250,   251,   410,   411,     0,    14,    15,    16,
     534,    18,    19,    20,   487,   535,   536,   489,   490,   491,
     412,    28,   492,    30,    31,     0,    32,    33,    34,    35,
     537,    37,   538,   539,    40,    41,    42,    43,   494,     0,
      45,   540,    47,   496,   497,    50,   498,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   499,   500,    68,     0,    69,    70,    71,   541,     0,
       0,    74,    75,    76,     0,     0,   502,    78,     0,     0,
       0,     0,    80,   503,    82,   504,   505,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   506,    97,    98,   507,
     508,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     509,   120,   121,   510,     0,     0,     0,     0,     0,     0,
       0,   511,   512,   128,     0,     0,     0,   129,     0,   130,
     513,     0,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   514,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   413,   151,   152,   153,
     154,   155,   156,   157,   158,   515,   542,   516,   162,   517,
     518,   165,   166,   167,   168,   169,   170,   519,   172,   520,
     521,   522,   176,   177,   523,   524,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   525,   247,   248,   249,
     250,   251,   410,   411,     0,    14,    15,    16,     0,    18,
      19,    20,   487,     0,     0,   489,   490,     0,   412,    28,
     492,    30,    31,     0,    32,    33,    34,    35,     0,    37,
       0,     0,    40,    41,    42,    43,   494,     0,    45,     0,
      47,     0,     0,    50,   498,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   499,
     500,    68,     0,    69,    70,    71,     0,     0,     0,    74,
      75,    76,     0,     0,   502,    78,     0,     0,     0,     0,
      80,   503,    82,   504,   505,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   506,    97,    98,   507,   508,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,     0,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,     0,   130,   513,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
       0,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,     0,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,     0,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,     0,   245,   525,   247,   248,   249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   683,   179,   421,     4,     5,     6,   340,     0,     4,
       5,     6,     4,     5,     6,   667,   109,   110,     4,     5,
       6,   419,   420,   259,    12,   260,   311,   777,   820,   668,
     669,   670,   671,     4,     5,     6,   618,   619,   757,   789,
     275,  1029,  1045,   461,   462,   133,   291,   901,   583,   858,
    1283,   252,   253,   803,   589,   757,  1300,    73,   915,  1361,
    1362,  1069,   433,  1123,   914,   915,   616,   617,   618,   619,
     616,   617,  1004,   444,    36,    26,    27,   646,   936,   648,
     649,    39,   651,   986,   653,    55,    44,    45,    36,   713,
     107,     1,   661,   662,   107,  1394,    47,    30,   469,     8,
      29,    59,   952,    61,    62,  1588,   118,    94,   108,  1313,
      37,    38,    70,    40,    41,   952,   108,   282,    29,     1,
     142,    93,   108,    74,     1,   107,     1,   118,   225,   107,
      57,   107,    94,     1,    96,     1,   986,   108,     1,    97,
     107,   225,   107,   227,  1655,   225,    96,   227,    96,  1006,
     243,   244,   153,    26,    27,   107,  1006,    26,    27,    45,
     107,   112,  1019,   136,    37,    38,    94,    40,    41,  1019,
     107,   416,   153,   158,    47,   118,    62,    96,    47,   136,
     154,   110,   156,    56,    57,   147,   113,    56,    26,    27,
     620,   176,    94,   150,   624,   124,   177,   147,   291,   147,
      29,    74,   113,   185,   100,    74,    79,   147,   958,   210,
      79,   183,   188,   225,    42,   147,  1727,   314,    46,   147,
     149,   188,    29,    51,   153,   190,  1528,   156,   201,    94,
     314,   218,   219,   160,   314,   187,   156,   184,   111,   112,
     113,    69,   111,   112,   113,   147,   233,   217,   177,   160,
     187,   273,   252,   253,  1737,   343,   256,   235,     9,    10,
     252,   253,  1012,   237,   256,  1498,   175,   225,  1018,  1123,
    1124,     9,    10,  1065,   112,   440,   561,  1280,  1266,     5,
     190,   214,   273,     9,   254,   867,   868,   160,  1587,  1139,
     186,   291,  1011,   220,   311,   307,  1304,  1501,  1230,   291,
     313,   187,  1139,   110,   549,  1313,   724,  1009,   190,  1011,
    1370,   273,    73,   190,   938,   190,  1174,   124,  1221,   865,
     866,    76,   190,   416,   190,   273,    87,   190,   897,  1031,
     259,   160,   348,   273,   261,   351,   287,   256,   257,   107,
     168,   273,   149,   171,   295,   130,   153,   220,    29,   156,
     111,   107,   103,   218,   219,    96,   449,   775,   186,   317,
     318,   319,   123,   100,   125,   103,   459,   156,   233,   153,
     177,  1221,   123,   160,   125,   468,   166,   153,   613,   148,
     616,   617,   475,   476,   212,   123,  1688,   125,   261,   634,
     225,   484,   182,   177,   100,   230,   165,   123,   153,   125,
     771,  1258,   153,   774,   605,  1649,   157,   133,  1258,   107,
     107,   156,   197,   118,   287,   153,   416,   185,   287,   157,
     107,    96,   295,   174,   416,  1282,   295,   153,   169,   110,
     303,   187,  1282,   107,   303,   107,   174,    42,  1740,   107,
     107,    46,   107,   124,   195,   445,    51,   447,   107,   186,
     107,   158,   107,   445,     5,   447,   549,   195,     9,   445,
     107,   447,   213,    45,    69,    47,   221,   222,   149,   176,
    1220,   107,   565,   473,   445,   213,   447,   107,   478,   314,
     186,   473,   187,   156,   577,   107,   478,   473,   107,   187,
     187,  1724,   478,  1501,   169,   107,   107,    79,   743,   131,
     187,    53,   473,   901,   597,   598,    58,   478,   107,   107,
     184,   252,   253,  1232,   255,   187,  1370,   169,   107,   187,
     187,   262,   187,   107,   106,  1379,   185,  1109,  1110,  1111,
     187,   272,   187,   931,  1216,  1344,  1390,   107,  1347,  1241,
     187,   959,   960,   284,    42,  1402,   964,   156,    46,   549,
     202,   187,  1402,    51,  1089,   185,   556,   549,   190,  1109,
    1110,  1111,   269,   168,   556,   187,   171,   107,   187,   276,
     556,    69,   123,   184,   125,   187,   994,   252,   253,   286,
     255,   186,   133,   107,   107,   556,   168,   348,   187,   187,
     351,   684,    45,   130,    47,   184,   689,   272,   598,   687,
     688,   107,   153,   187,   117,   605,   598,   212,   107,   284,
     107,   856,   598,   605,   184,  1365,   616,   617,   618,   619,
       9,     9,  1610,   611,   616,   617,   618,   619,  1485,   865,
       1,  1488,     3,   146,   634,  1485,   871,   118,  1488,    28,
      28,    96,   634,   122,   184,  1648,   159,    54,    96,    56,
     743,   107,  1000,   106,  1002,    52,   107,    96,   113,   118,
     197,   107,   269,   187,   187,   426,   153,    96,   429,   276,
     168,   106,   433,   171,   113,   436,   437,   182,   184,   286,
     158,   194,    94,   444,   113,   184,   156,   184,   186,   450,
     451,   196,   127,   100,   455,    66,    96,    33,   176,   147,
      71,   156,   463,  1557,  1052,   186,  1054,  1499,   469,   470,
     471,   472,  1504,    49,   212,   168,   477,   156,   811,   812,
     813,   199,   815,   210,   485,  1123,  1124,   186,   184,  1381,
     144,  1450,   129,   184,   123,   123,   125,   125,   184,     9,
      10,    94,   154,   743,   156,   134,   134,   118,   122,   217,
     843,   743,    53,  1435,   148,    94,   156,    58,    53,    94,
     182,    94,   176,    58,   153,   153,   156,   767,  1350,   530,
     863,   165,   767,   106,   196,   767,    77,  1715,  1716,   153,
     194,   767,   156,   544,     9,    10,   254,    94,    33,   142,
     158,   232,  1125,   234,   555,    96,   767,   797,   798,   106,
      24,    96,   137,   142,    49,   797,   798,   142,   176,   142,
      34,   797,   798,   137,  1671,  1100,  1673,   118,  1756,    95,
     137,  1671,   583,  1673,  1762,   142,   797,   798,   589,   153,
     106,   199,   593,   103,   137,   100,    60,   247,   248,   100,
     116,  1633,   156,  1261,   251,  1637,   949,  1704,   113,  1094,
     153,   127,   113,   123,  1704,   125,   856,   264,   961,   266,
     270,   154,   100,   156,   856,   156,   100,   100,   100,   122,
     277,   278,   279,   122,   281,   113,   283,  1734,   103,   113,
     113,   113,   263,   153,  1734,   137,   201,   157,   876,   232,
     142,   234,  1749,   274,  1751,   210,  1548,  1549,   123,  1749,
     125,  1751,  1541,   263,   174,   268,   299,   690,  1590,   118,
     693,   132,   275,   696,   274,   308,   221,   222,   223,   140,
     141,  1098,   143,   191,   192,   195,  1103,  1719,   153,   122,
     151,   122,   157,   118,   155,   122,   157,   153,  1688,  1357,
     156,   162,   122,   213,   216,   277,   278,   279,   153,   174,
     153,   283,   153,   156,   153,   156,   122,   156,   179,   720,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
     195,   347,  1370,   734,   350,   153,   154,   738,   739,   128,
     129,  1379,   203,   204,   205,   206,   207,   208,   213,   128,
     129,   122,  1390,   122,   665,   666,   672,   673,  1214,  1215,
     761,   122,   763,   153,   674,   675,   118,  1659,  1660,   156,
     771,  1693,   241,   774,   241,  1260,   242,   778,   916,   917,
    1578,  1579,   156,   153,   314,     0,   107,   190,    92,  1122,
     167,   249,    99,    50,   102,   200,   101,   193,   154,   145,
     184,   156,   184,   184,    29,    47,   118,  1047,   152,  1467,
     246,   187,   118,   304,   284,  1047,  1738,   153,   819,     1,
     118,  1047,   284,   142,   107,   187,   153,   153,   156,   142,
     184,   156,   156,   156,   156,   121,  1047,    35,  1730,   156,
     156,   156,   153,    17,    29,   187,   214,   190,   231,   190,
     230,   245,   154,     3,  1094,   118,   170,   858,  1343,   168,
     170,    70,  1094,    94,   231,    94,    94,   149,   107,  1109,
    1110,  1111,   107,    29,  1532,   160,   160,  1109,  1110,  1111,
    1108,   127,   132,   884,    94,   299,   142,   246,   118,  1811,
     184,  1813,   132,   184,   187,   187,   107,    94,    45,   187,
    1822,    96,    96,    94,   153,   153,   187,   187,   187,   184,
     184,   231,   153,   914,   915,   916,   917,   153,   142,  1557,
     153,   153,   190,    33,   225,   170,   118,   132,   142,    94,
      29,   227,    94,   286,   237,   299,   153,   127,   118,   147,
     118,    73,    94,   198,   132,   132,   184,   160,    96,   153,
     118,   952,   153,   190,   254,    87,   100,   100,   147,   142,
     121,   184,   184,    35,    29,   966,    79,   118,   245,   107,
     156,   107,   156,   260,   153,   156,    29,   267,   144,   111,
     258,   156,    29,   156,  1224,   156,   285,   156,    29,  1224,
     991,   123,  1224,   125,  1479,   144,   156,   156,  1224,  1000,
     227,  1002,   156,  1004,   127,  1006,  1339,  1340,  1341,   306,
     286,   187,   147,  1224,   287,   187,   147,   187,  1019,   147,
    1260,   118,   118,   190,   187,    77,   107,   142,  1260,   184,
     187,  1271,   100,     7,   187,   237,  1271,   132,   250,  1271,
     198,   186,   106,   250,   190,  1271,   147,    78,   282,    29,
    1290,  1052,    29,  1054,   187,  1290,   233,   108,  1290,   107,
    1271,   187,   199,   187,  1290,   286,   187,   187,   187,   233,
    1310,   187,   271,   187,   147,   184,   170,   147,  1310,  1290,
     126,   126,    96,   186,  1310,   142,   184,   153,  1089,    94,
      29,   233,   233,   233,   233,   186,   186,   186,   184,  1310,
     184,   184,  1342,  1343,    96,   187,    53,   187,   170,   147,
    1342,  1343,    94,    96,    29,   186,  1342,  1118,   197,   186,
     198,   106,    94,  1608,   118,   225,   107,   257,   107,   118,
      94,   186,    94,   225,  1619,  1620,   197,  1622,  1139,   197,
     265,    93,   118,   186,  1629,   118,   280,   186,   183,   118,
     186,   225,   186,   197,   186,   118,   723,   199,   287,  1177,
     953,   420,  1020,   256,  1221,  1693,  1738,   859,   256,   440,
     780,  1017,   259,  1460,  1250,  1114,   293,  1366,  1364,  1361,
     287,   544,  1272,   305,  1277,   455,  1280,   305,  1285,   316,
     644,   698,   645,   305,  1304,   306,   664,   820,   306,  1762,
     306,  1756,   917,  1002,   448,   448,  1176,  1335,  1345,  1344,
    1557,  1390,  1383,  1379,  1554,  1124,   348,   985,  1581,   351,
    1199,  1425,  1380,   842,    -1,    -1,    -1,  1712,    -1,  1230,
     335,  1133,    -1,  1234,    -1,    -1,    -1,    -1,  1723,  1479,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1479,  1249,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1258,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1750,    -1,    -1,    -1,    -1,
      -1,  1272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   425,   426,    -1,    -1,   429,  1783,    -1,
      -1,   433,    -1,    -1,   436,   437,    -1,    -1,    -1,    -1,
    1311,    -1,   444,    -1,    -1,    -1,    -1,  1650,   450,   451,
    1805,    -1,    -1,   455,    -1,  1810,    -1,    -1,    -1,    -1,
      -1,   463,    -1,    -1,  1335,    -1,  1669,   469,   470,   471,
     472,    -1,    -1,  1344,    -1,   477,  1347,    -1,    -1,    -1,
      -1,    -1,    -1,   485,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1608,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1608,    -1,    -1,  1619,
    1620,    -1,  1622,    -1,    -1,    -1,    -1,  1619,  1620,  1629,
    1622,    -1,    -1,    -1,    -1,    -1,    -1,  1629,   530,    -1,
      -1,  1402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   544,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   555,    -1,    -1,    -1,    -1,    -1,    -1,
    1431,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1457,  1458,    -1,    -1,
      -1,   593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1712,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1712,    -1,  1483,  1723,  1485,    -1,    -1,  1488,    -1,    -1,
      -1,  1723,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1500,
      -1,    -1,    -1,    -1,  1505,   556,    -1,    -1,    -1,    -1,
    1750,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1750,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     581,   582,    -1,    -1,   585,   586,    -1,   588,    -1,   590,
      -1,    -1,    -1,  1783,    -1,   596,    -1,    -1,    -1,    -1,
      -1,  1783,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1805,    -1,    -1,    -1,    -1,
    1810,    -1,    -1,  1805,    -1,   626,    -1,    -1,  1810,    -1,
      -1,    -1,    -1,   634,   635,   717,    -1,    -1,   720,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   734,    -1,    -1,    -1,   738,   739,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1623,    -1,  1625,    -1,  1627,    -1,    -1,   761,
      -1,   763,    -1,  1634,    -1,    -1,    -1,    -1,    -1,   771,
      -1,    -1,   774,    -1,   695,    -1,   778,   698,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1671,    -1,  1673,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   736,    -1,   819,  1689,    -1,
      -1,  1692,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1704,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1714,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   858,    -1,   779,    -1,
      -1,    -1,    -1,  1734,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1742,    -1,    -1,    -1,    -1,  1747,    -1,  1749,    -1,
    1751,    -1,   884,   804,    -1,    -1,    -1,   808,   809,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   817,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1780,
      -1,    -1,   914,   915,   916,   917,    -1,    -1,    -1,    -1,
      -1,   842,    -1,    -1,    -1,    -1,  1797,    -1,    -1,    -1,
    1801,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1817,    -1,    -1,  1820,
     952,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   966,   886,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   991,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1000,    -1,
    1002,    -1,  1004,    -1,  1006,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1019,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   954,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1052,    -1,  1054,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   989,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1008,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1030,
      -1,    -1,    -1,    -1,    -1,    -1,  1118,    -1,    -1,    -1,
    1041,  1042,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1056,    -1,  1139,  1059,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1075,  1076,  1077,    -1,  1079,  1080,
    1081,    -1,    -1,    -1,  1085,  1086,  1087,  1088,    -1,    -1,
    1091,  1092,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1114,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1230,    -1,
      -1,    -1,  1234,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1164,    -1,    -1,    -1,  1249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1258,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1282,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1311,
      -1,    -1,    -1,    -1,    -1,  1236,    -1,  1238,    -1,  1240,
      -1,    -1,  1243,    -1,    -1,    -1,    -1,  1248,    -1,    -1,
      -1,    -1,    -1,  1335,    -1,    -1,    -1,    -1,    -1,  1260,
      -1,    -1,  1344,    -1,    -1,  1347,    -1,    -1,  1269,    -1,
      -1,    -1,    -1,    -1,  1275,  1276,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1294,    -1,    -1,  1297,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1402,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1431,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1457,  1458,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1483,    -1,  1485,    -1,    -1,  1488,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1500,    -1,
      -1,    -1,    -1,  1505,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1444,    -1,    -1,    -1,  1448,    -1,    -1,
      -1,  1452,    -1,  1454,    -1,  1456,    -1,    -1,    -1,    -1,
      -1,  1462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1470,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1478,  1479,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1497,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1508,  1509,  1510,
    1511,  1512,  1513,  1514,  1515,    -1,  1517,    -1,    -1,    -1,
      -1,    -1,    -1,  1524,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1533,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1623,    -1,  1625,    -1,  1627,    -1,    -1,    -1,    -1,
      -1,    -1,  1634,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1671,
      -1,  1673,    -1,    -1,    -1,  1596,    -1,  1598,    -1,    -1,
    1601,    -1,    -1,    -1,    -1,    -1,    -1,  1689,  1609,    -1,
    1692,    -1,    -1,  1614,  1615,    -1,    -1,    -1,    -1,    -1,
      -1,  1622,  1704,    -1,    -1,  1626,    -1,    -1,    -1,    -1,
      -1,    -1,  1714,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1734,    -1,    -1,  1656,    -1,    -1,    -1,    -1,
    1742,    -1,    -1,    -1,    -1,  1747,    -1,  1749,    -1,  1751,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,
       1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1696,    -1,    -1,  1780,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1708,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1797,    -1,    -1,    -1,  1801,
      -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    50,
      51,    -1,    -1,    -1,    55,  1817,    -1,    -1,  1820,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    69,  1750,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1768,    -1,    -1,
      -1,    92,    -1,    94,    95,    96,    -1,  1778,    99,   100,
     101,   102,  1783,    -1,    -1,   106,   107,  1788,    -1,    -1,
      -1,    -1,   113,    -1,    -1,   116,   117,   118,    -1,    -1,
     121,    -1,    -1,  1804,    -1,   126,   127,  1808,    -1,    -1,
      -1,   132,    -1,    -1,    -1,   136,    -1,    -1,    -1,   140,
     141,    -1,   143,    -1,   145,   146,    -1,    -1,    -1,   150,
     151,    -1,    -1,   154,   155,   156,   157,   158,   159,    -1,
      -1,   162,    -1,    -1,    -1,    -1,   167,   168,    -1,    -1,
     171,    -1,    -1,    -1,    -1,   176,    -1,    -1,   179,    -1,
      -1,    -1,    -1,   184,   185,   186,   187,   188,    -1,   190,
     191,   192,   193,   194,    -1,    -1,    -1,    -1,   199,   200,
     201,    -1,   203,   204,   205,   206,   207,   208,    -1,   210,
      -1,   212,    -1,    -1,    -1,    -1,   217,   218,   219,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   233,    -1,   235,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,
      -1,    -1,    -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
     311,    -1,   313,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    98,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,   158,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,   191,   192,    -1,   194,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,   213,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,    -1,   312,    -1,   314,   315,   316,   317,   318,   319,
     320,   321,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      98,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,   191,   192,    -1,   194,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,    -1,   322,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,   185,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,   313,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,   187,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
     176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,   191,   192,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
      -1,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,   149,    -1,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,   174,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
     196,    -1,   198,    -1,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,   213,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,    -1,   312,    -1,   314,   315,
     316,   317,   318,   319,   320,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
      -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,
     196,    -1,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,    -1,   259,   260,   261,    -1,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,    -1,    11,    12,   314,   315,
     316,   317,   318,   319,   320,    20,    -1,    -1,    -1,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,    -1,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,    -1,    16,   314,
     315,   316,   317,   318,   319,   320,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,    -1,    -1,    16,   314,   315,   316,   317,
     318,   319,   320,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    -1,    -1,   314,   315,   316,   317,   318,   319,   320,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,   317,
     318,   319,   320,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    -1,    94,    95,    96,    97,
      -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,
      -1,    -1,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,    -1,    -1,    -1,    -1,   124,    -1,   126,   127,
     128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,    -1,    -1,   211,   212,   213,    -1,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
      -1,   259,   260,   261,    -1,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,    -1,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
      -1,    -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    24,    25,   314,   315,   316,   317,   318,   319,   320,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,
      -1,   194,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    24,
      25,   314,   315,   316,   317,   318,   319,   320,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,    -1,   150,   151,   152,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,    24,    25,   314,
     315,   316,   317,   318,   319,   320,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,   156,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    24,    25,   314,   315,   316,
     317,   318,   319,   320,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,    24,    25,   314,   315,   316,   317,   318,
     319,   320,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
     211,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    24,    25,   314,   315,   316,   317,   318,   319,   320,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,   152,
      -1,    -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,   211,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    24,
      25,   314,   315,   316,   317,   318,   319,   320,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,    -1,   150,   151,   152,    -1,    -1,
      -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,    -1,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,    -1,    24,    25,   314,
     315,   316,   317,   318,   319,   320,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,   211,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    24,    25,   314,   315,   316,
     317,   318,   319,   320,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
      -1,    -1,   211,   212,    -1,    -1,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,    -1,
     259,   260,   261,    -1,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,    -1,    24,    25,   314,   315,   316,   317,   318,
     319,   320,    33,    34,    -1,    36,    37,    38,    -1,    40,
      41,    42,    43,    -1,    -1,    46,    47,    -1,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    -1,    60,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    69,    -1,
      71,    -1,    -1,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    -1,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,    -1,    -1,
      -1,   212,    -1,    -1,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,    -1,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,    -1,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,    -1,   259,   260,
     261,    -1,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
      -1,    -1,    -1,   314,   315,   316,   317,   318,   319,   320
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned short int
  xquery_parser::yystos_[] =
  {
         0,    11,    12,    20,    21,    22,    23,    24,    25,    26,
      27,    29,    33,    34,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    94,
      95,    96,    97,    98,   100,   101,   102,   105,   106,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     124,   126,   127,   128,   129,   131,   135,   136,   137,   138,
     139,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     156,   157,   158,   159,   160,   165,   166,   167,   168,   169,
     170,   171,   172,   174,   176,   177,   180,   181,   182,   186,
     188,   189,   191,   192,   194,   196,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   211,   212,   213,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   259,   260,   261,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   312,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   335,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   356,   357,   358,   359,   360,   361,   365,   366,
     367,   371,   373,   374,   376,   383,   385,   388,   389,   390,
     392,   393,   394,   395,   396,   398,   399,   401,   402,   403,
     404,   405,   406,   408,   409,   412,   413,   414,   415,   420,
     422,   424,   425,   430,   449,   452,   456,   459,   460,   465,
     466,   467,   468,   470,   471,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   518,   519,   520,   534,   535,
     537,   538,   539,   540,   541,   542,   543,   551,   552,   553,
     554,   555,   556,   557,   558,   559,   560,   563,   564,   565,
     566,   571,   572,   573,   574,   575,   576,   579,   637,   638,
     639,   640,   642,   643,   644,   645,   646,   653,   654,   655,
      33,    34,    49,   215,   391,   392,   393,   391,   391,   156,
     156,    37,    38,    40,    41,    47,    56,    57,    74,    79,
     111,   112,   113,   160,   220,   261,   287,   295,   303,   372,
     373,   377,   378,   379,   160,   153,   156,   153,   156,   153,
     156,     1,     3,    66,    71,   118,   417,   156,   380,   156,
      24,    34,    60,   118,   273,   429,   431,   432,   153,   156,
     156,   156,   118,   153,   156,   156,   156,    76,   153,   221,
     222,   122,   122,   122,   153,   156,    39,    43,    45,    46,
      47,    48,    51,    59,    67,    70,    72,    73,    75,    90,
      91,    97,   105,   112,   114,   115,   135,   138,   139,   169,
     172,   180,   181,   189,   202,   224,   226,   228,   229,   236,
     238,   239,   240,   243,   244,   315,   502,   653,   654,   122,
     118,   400,   122,   122,    39,    44,    45,    59,    61,    62,
      70,    97,   225,   653,   118,   122,   122,   184,   391,   393,
     413,   641,    48,    72,    73,   118,   153,   185,   244,   412,
     414,   424,   187,   412,   653,   153,   122,    16,   652,   653,
      18,    19,   653,   122,   122,   122,   494,   153,    30,   214,
     216,   225,   227,   314,   156,   225,   227,   314,   225,   314,
     225,   230,   314,   118,   241,   241,   242,   156,   153,   395,
     311,   412,   313,   412,   314,   322,   337,   337,     0,   339,
     340,    33,    49,   342,   359,     1,   190,   336,   190,   336,
     112,   374,   394,   412,   107,   190,   107,   190,    42,    46,
      51,    69,   168,   171,   186,   212,   407,   416,   421,   422,
     423,   437,   438,   442,   167,    92,   132,   140,   141,   143,
     151,   155,   157,   162,   179,   203,   204,   205,   206,   207,
     208,   486,   487,   249,    99,   158,   176,   199,   117,   146,
     159,   194,   201,   210,   136,   150,    50,   200,   101,   102,
     158,   176,   484,   193,   153,   491,   494,   191,   192,   154,
     506,   507,   502,   506,   502,   156,   506,   145,   156,   184,
     184,   184,   375,   509,   375,    29,   651,   182,   196,   182,
     196,   166,   182,   654,   653,   169,   202,    47,   653,   152,
     118,    45,    47,    79,   106,   168,   652,   221,   222,   223,
     246,   610,   653,   653,   304,   137,   142,   112,   287,   295,
     377,   652,   392,   393,   187,   392,    45,    62,   187,   559,
     560,   412,   187,   194,   653,   426,   427,   653,   284,   284,
     426,   118,   433,   118,   187,   381,   382,   153,   397,   412,
       1,   160,   651,   113,   160,   355,   651,   653,   118,   142,
     107,   412,    29,   187,   652,   653,   653,   450,   451,   653,
     392,   187,   412,   412,   561,   653,   392,   153,   153,   412,
     187,   194,   653,   653,   142,   450,   184,   184,   121,   107,
     184,   156,   156,   156,   653,   153,   185,   186,   187,    35,
     522,   523,   524,   412,     8,   175,    17,   412,   214,    29,
     413,   413,    39,    45,    59,    70,    97,   505,   653,   187,
     413,   413,   153,   154,   413,   505,   413,   231,   230,   577,
     578,   653,   190,   190,   413,   412,   393,   412,   245,   410,
     411,   311,   313,   154,   337,   190,   336,   190,   336,     3,
     343,   359,   389,   343,   359,   389,    33,   360,   389,   360,
     389,   400,   400,   413,   118,   168,   170,   170,   394,   413,
     413,   467,   468,   470,   470,   470,   470,   469,   470,   470,
     470,    70,   471,   475,   475,   474,   476,   476,   476,   476,
     477,   477,   478,   478,   231,    94,    94,    94,   492,   184,
     412,   494,   494,   412,   507,   187,   413,   517,   149,   187,
     517,   107,   187,   187,   107,   107,   380,    29,   654,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   362,
     363,   364,    94,   137,   142,   368,   369,   370,   653,   160,
     160,   362,   651,   127,   132,    54,    56,   100,   251,   264,
     266,   277,   278,   279,   281,   283,   611,   612,   613,   614,
     615,   616,   623,   629,   630,   246,    94,   299,   653,   142,
     413,   118,   653,   653,   132,   184,   184,   187,   187,   184,
     107,   187,   107,   187,   107,    36,    94,    96,   147,   428,
     429,   545,   653,    55,   217,   254,   418,   419,   653,    94,
     107,   187,   391,   187,   652,    96,    45,   652,   651,    96,
     142,   545,   653,   413,   432,   184,   187,   187,   187,   187,
     107,   188,   147,   545,   184,   187,   187,   153,   184,   392,
     392,   184,   107,   187,   107,   187,   142,   545,   413,   188,
     413,   413,   412,   412,   412,   653,   523,   524,   130,   197,
     184,   184,   131,   190,    94,   218,   219,   233,    94,   218,
     219,   233,   413,   641,   412,    94,    94,   237,   225,   231,
     107,   235,   142,   190,   187,    48,    72,    73,   244,   414,
     424,   184,   503,   583,   411,   412,   359,    33,    33,   190,
     336,   190,   113,   653,   170,   413,   443,   444,   118,   439,
     440,   470,   153,   156,   259,   490,   509,   584,   587,   588,
     589,   590,   591,   595,   597,   599,   600,    47,   152,   156,
     211,   317,   318,   319,   320,   546,   548,   550,   551,   567,
     568,   569,   570,   647,   648,   649,   650,   653,   546,   544,
     550,   544,   184,   185,   107,   187,   187,   509,   148,   165,
     148,   165,   137,   397,   380,   363,   132,   548,   370,   413,
     545,   651,   651,   128,   129,   651,   277,   278,   279,   283,
     653,   263,   274,   263,   274,    29,   286,    96,   113,   156,
     617,   620,   611,    39,    44,    59,    61,    70,    97,   225,
     317,   318,   319,   384,   551,   647,   227,   299,   308,   413,
     653,    94,   299,   651,   153,   561,   562,   653,   561,   562,
     118,   427,   127,   546,   118,   413,   147,   429,   147,    36,
     147,   428,   429,   147,   545,   254,    53,    58,    77,   118,
     428,   434,   435,   436,   419,   545,   546,   382,    94,   184,
     198,   132,   354,   651,   160,   132,    96,   354,   413,   142,
     429,   153,   118,   413,   413,   147,   100,   453,   454,   455,
     457,   458,   100,   461,   462,   463,   464,   392,   184,   184,
     153,   561,   561,   413,   142,   190,   413,   121,   187,   187,
     187,    35,   524,   130,   197,     9,    10,   103,   123,   125,
     153,   195,   519,   521,   532,   533,   536,    29,   232,   234,
     413,   413,   413,   232,   234,   413,   413,   413,   184,   185,
     413,   413,   413,   413,   505,   118,   413,   413,   394,   156,
     156,   156,   153,   186,   245,   580,   581,   210,   395,   185,
     190,   113,   389,   389,   389,   443,    95,   106,   116,   127,
     445,   446,   447,   448,   107,   653,   107,   412,   584,   591,
     153,   285,   472,   636,    96,   169,   252,   253,   255,   262,
     272,   284,   585,   586,   605,   606,   607,   608,   631,   634,
     258,   260,   592,   610,   267,   596,   632,   247,   248,   270,
     601,   602,   156,   156,   548,   156,   156,   156,   156,   156,
     144,   176,   194,   547,   144,   413,   137,   397,   563,   369,
     286,    29,    96,   113,   156,   624,    29,   617,   547,   547,
     492,   287,   306,   545,   384,   227,   190,   391,   187,   187,
     144,   187,   187,   427,   147,   428,   653,   413,   147,   413,
     127,   413,   147,   429,   147,   413,   147,   118,   118,   413,
     653,   436,    77,   546,   394,   413,   651,   107,   354,   413,
     142,   391,   451,   413,   413,   113,   454,   455,   100,   186,
     113,   455,   458,   118,   546,   100,   113,   462,   100,   113,
     464,   184,   391,   187,   187,   413,   413,   198,   461,   132,
     195,   521,     7,   392,   653,   195,   532,   190,   233,   233,
     233,   233,   233,   233,   237,   237,   578,   186,   412,   412,
     412,   583,   581,   503,   199,   651,   128,   129,   447,   448,
     448,   444,   106,   142,   441,   545,   440,   184,   187,   584,
     598,   250,   217,   254,   268,   275,   635,    96,   256,   257,
     633,   250,   588,   635,   474,   605,   589,   147,   282,   593,
     594,   633,   286,   604,    78,   603,   187,   194,   546,   549,
     187,   187,   187,   187,   187,   187,   187,    29,   136,   201,
     626,   627,   628,    29,   625,   626,   271,   621,   107,   618,
     170,   653,   257,   492,   184,   413,   147,   413,   147,   428,
     413,   147,   413,   413,   653,   653,   435,   413,   126,   126,
      96,   651,   413,   184,   186,   186,   413,   394,   413,   186,
     186,   653,   186,   118,   546,   118,   186,   118,   546,   186,
     184,   113,   524,   653,   195,   184,   524,   653,   413,   413,
     413,   413,   413,   413,   413,   413,   413,   187,   187,   187,
     153,   582,   413,   448,   651,   413,   142,   184,   476,    52,
     129,   474,   474,   269,   276,   286,   609,   609,   590,   153,
     280,    94,   187,   107,   187,   624,   624,   628,   107,   187,
      29,   622,   633,   619,   620,   187,   386,   387,   492,   118,
     225,   307,   287,   170,   413,   413,   147,   413,    53,   394,
     413,   354,   413,   394,    94,   394,   413,   653,   186,   653,
     413,   653,   186,   394,   118,    93,   183,   525,   524,   653,
     197,   524,    96,   198,   461,   412,   441,   413,   474,   474,
     199,   412,   546,   546,    94,    29,   265,   107,   107,   448,
     545,   653,   118,   225,   653,   386,   413,   118,   546,    94,
     186,    94,   653,     5,   133,   528,   529,   531,   533,    28,
     134,   526,   527,   530,   533,   197,   524,   197,   316,   113,
     184,   441,   474,   184,   546,   620,   387,   448,   305,   653,
     118,   225,   653,   186,   546,   394,   413,   546,   186,    93,
     133,   531,   183,   134,   530,   197,   413,   118,   413,   305,
     653,   118,   394,   413,   186,   186,   653,   293,   305,   653,
     186,   306,   413,   306,   492,   492,   199,   287,   653,   225,
     118,   653,   306,   492
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
     585,   586,   587,   588
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   334,   335,   335,   335,   335,   336,   337,   337,   337,
     337,   338,   338,   339,   339,   339,   339,   339,   339,   339,
     339,   340,   340,   340,   340,   341,   342,   342,   342,   343,
     343,   343,   343,   343,   344,   344,   344,   344,   344,   344,
     344,   344,   345,   345,   346,   347,   348,   348,   349,   349,
     350,   350,   351,   351,   351,   351,   352,   352,   352,   353,
     353,   353,   353,   354,   354,   355,   355,   356,   356,   356,
     356,   357,   358,   358,   359,   359,   359,   360,   360,   360,
     360,   360,   360,   360,   360,   361,   361,   362,   362,   363,
     364,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     365,   366,   367,   368,   368,   369,   369,   369,   370,   371,
     371,   371,   372,   372,   372,   372,   373,   373,   374,   374,
     374,   374,   375,   375,   376,   376,   377,   377,   378,   378,
     379,   379,   380,   380,   380,   380,   381,   381,   382,   382,
     383,   383,   383,   383,   384,   384,   384,   384,   385,   385,
     386,   386,   387,   387,   387,   387,   388,   388,   388,   388,
     389,   390,   390,   390,   391,   391,   391,   392,   392,   393,
     393,   394,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   395,   395,   396,   397,   398,   399,   399,
     399,   400,   400,   400,   400,   401,   402,   403,   404,   405,
     405,   406,   407,   408,   409,   410,   410,   411,   412,   412,
     413,   413,   413,   413,   413,   413,   414,   414,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   415,   416,
     417,   417,   418,   418,   418,   419,   419,   420,   420,   421,
     422,   422,   422,   423,   423,   423,   423,   423,   424,   424,
     425,   425,   425,   426,   426,   426,   427,   427,   427,   427,
     427,   427,   427,   427,   427,   427,   427,   427,   428,   429,
     430,   431,   431,   432,   432,   432,   432,   433,   433,   434,
     434,   434,   435,   435,   435,   436,   436,   436,   437,   438,
     439,   439,   440,   440,   440,   440,   440,   440,   441,   442,
     442,   443,   443,   444,   444,   445,   445,   445,   445,   445,
     445,   445,   446,   446,   447,   447,   448,   449,   449,   450,
     450,   451,   451,   452,   453,   453,   454,   455,   455,   456,
     457,   457,   458,   459,   459,   460,   460,   461,   461,   462,
     462,   463,   463,   464,   464,   465,   466,   466,   467,   467,
     468,   468,   468,   468,   468,   469,   468,   468,   468,   468,
     470,   470,   471,   471,   472,   472,   473,   473,   474,   474,
     474,   475,   475,   475,   475,   475,   476,   476,   476,   477,
     477,   477,   478,   478,   479,   479,   480,   480,   481,   481,
     482,   482,   483,   483,   483,   483,   484,   484,   484,   485,
     485,   486,   486,   486,   486,   486,   486,   487,   487,   487,
     488,   488,   488,   488,   489,   489,   490,   490,   491,   491,
     491,   492,   492,   492,   492,   493,   494,   494,   494,   495,
     495,   496,   496,   496,   496,   497,   497,   498,   498,   498,
     498,   498,   498,   498,   499,   499,   500,   500,   501,   501,
     501,   501,   501,   502,   502,   503,   503,   504,   504,   504,
     504,   505,   505,   505,   505,   506,   506,   507,   508,   508,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   509,   509,   510,   510,   510,   511,   512,   512,
     513,   514,   515,   516,   516,   517,   517,   518,   518,   519,
     519,   519,   520,   520,   520,   520,   520,   520,   521,   521,
     522,   522,   523,   524,   524,   525,   525,   526,   526,   527,
     527,   527,   527,   528,   528,   529,   529,   529,   529,   530,
     530,   531,   531,   532,   532,   532,   532,   533,   533,   533,
     533,   534,   534,   535,   535,   536,   537,   537,   537,   537,
     537,   537,   538,   539,   539,   540,   540,   541,   542,   543,
     543,   544,   544,   545,   546,   546,   546,   547,   547,   547,
     548,   548,   548,   548,   548,   548,   548,   549,   549,   550,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   552,
     553,   553,   553,   554,   555,   556,   556,   556,   557,   557,
     557,   557,   557,   558,   559,   559,   559,   559,   559,   559,
     559,   560,   561,   562,   563,   564,   564,   565,   566,   567,
     567,   568,   569,   569,   570,   571,   571,   571,   572,   572,
     572,   572,   572,   572,   572,   572,   572,   572,   573,   573,
     574,   574,   575,   576,   577,   577,   578,   579,   580,   580,
     581,   582,   583,   583,   584,   585,   585,   586,   586,   587,
     587,   588,   588,   589,   589,   590,   590,   591,   592,   592,
     593,   593,   594,   595,   595,   595,   596,   596,   597,   598,
     598,   599,   600,   600,   601,   601,   602,   602,   602,   603,
     603,   604,   604,   605,   605,   605,   605,   605,   606,   607,
     608,   609,   609,   609,   610,   610,   611,   611,   611,   611,
     611,   611,   611,   611,   612,   612,   612,   612,   613,   613,
     614,   615,   615,   616,   616,   616,   617,   617,   618,   618,
     619,   619,   620,   621,   621,   622,   622,   623,   623,   623,
     624,   624,   625,   625,   626,   626,   627,   627,   628,   628,
     629,   630,   630,   631,   631,   631,   632,   633,   633,   633,
     633,   634,   634,   635,   635,   636,   637,   637,   638,   638,
     639,   639,   640,   641,   641,   642,   642,   643,   644,   645,
     646,   647,   647,   647,   648,   649,   650,   651,   652,   652,
     653,   653,   653,   653,   653,   653,   653,   653,   653,   653,
     653,   653,   653,   653,   653,   653,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   655
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  xquery_parser::yyr2_[] =
  {
         0,     2,     1,     2,     2,     3,     2,     1,     2,     1,
       2,     4,     6,     3,     3,     5,     1,     3,     3,     5,
       5,     1,     3,     3,     5,     6,     1,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     3,     3,     3,     3,     3,
       5,     5,     5,     5,     5,     5,     1,     1,     3,     3,
       4,     5,     6,     1,     3,     3,     3,     3,     6,     5,
       8,     5,     5,     5,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     4,     3,     1,     1,     1,     2,     2,     4,
       3,     5,     3,     4,     4,     5,     1,     2,     1,     4,
       1,     4,     1,     3,     2,     3,     1,     1,     4,     4,
       5,     5,     2,     3,     4,     5,     1,     3,     2,     3,
       3,     5,     4,     6,     1,     2,     1,     2,     8,     9,
       1,     3,     1,     2,     2,     3,    11,    14,    13,    22,
       1,     1,     1,     0,     1,     1,     0,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     3,     2,     3,     2,
       3,     2,     3,     4,     5,     5,     2,     4,     5,     3,
       3,     2,     2,     8,     3,     1,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     2,     4,     3,     5,     4,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     3,     2,     1,     4,     3,     3,     5,     4,     6,
       4,     6,     5,     7,     4,     5,     5,     6,     3,     3,
       2,     1,     3,     4,     5,     3,     6,     4,     5,     1,
       2,     3,     1,     2,     1,     6,     3,     3,     2,     3,
       1,     3,     2,     4,     5,     6,     5,     3,     2,     3,
       4,     1,     3,     1,     2,     1,     1,     1,     2,     2,
       2,     3,     1,     1,     2,     2,     2,     5,     5,     1,
       4,     3,     4,     8,     1,     2,     3,     2,     3,     8,
       1,     2,     3,     8,    10,     8,    10,     1,     2,     4,
       7,     1,     2,     4,     7,     8,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     0,     4,     3,     3,     3,
       1,     5,     1,     3,     0,     1,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     4,     1,     4,     1,     4,     1,     4,
       1,     2,     1,     1,     2,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     5,     6,     3,     4,     1,     2,     3,     2,
       2,     1,     2,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     1,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     1,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     4,     4,     3,     4,     1,     3,     1,     1,     1,
       1,     1,     4,     5,     8,     9,     9,    10,     1,     2,
       1,     2,     6,     0,     1,     3,     3,     0,     1,     1,
       1,     2,     2,     0,     1,     1,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     2,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     4,     3,     7,     3,     7,     4,     4,     3,
       7,     1,     2,     2,     1,     2,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     4,     4,     3,     3,     3,     4,     4,     3,     4,
       6,     4,     6,     4,     3,     4,     6,     6,     4,     6,
       6,     4,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     4,     5,     6,     3,     3,     3,     3,     5,     7,
       7,     5,     5,     5,     7,     7,     5,     5,     3,     3,
       5,     7,     5,     7,     1,     4,     3,     5,     1,     2,
       3,     3,     1,     3,     2,     0,     1,     1,     2,     1,
       3,     1,     3,     1,     4,     1,     2,     3,     0,     1,
       0,     1,     4,     2,     3,     1,     0,     1,     4,     0,
       1,     2,     1,     3,     0,     1,     2,     2,     1,     0,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       3,     1,     2,     2,     5,     2,     1,     1,     0,     2,
       1,     3,     4,     0,     2,     0,     2,     4,     4,     3,
       2,     3,     1,     3,     0,     1,     1,     2,     2,     2,
       2,     1,     2,     2,     2,     2,     3,     2,     3,     3,
       4,     2,     2,     1,     1,     3,     2,     3,     2,     3,
       2,     3,     3,     3,     5,     7,    10,     7,     3,     5,
       7,     1,     1,     1,     3,     3,     3,     1,     1,     1,
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
       1,     1,     1
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
  "\"'processing-instruction NCName {'\"", "\"'QName'\"", "\"'EQName'\"",
  "\"'%QName'\"", "\"'%EQName'\"", "\"'quote attribute content'\"",
  "\"'STRING'\"", "\"'XML comment'\"", "\"'URI'\"", "\"'NCName'\"",
  "\"'declare'\"", "\"'module'\"", "\"'<blank>'\"", "\"'allowing'\"",
  "\"'base-uri'\"", "\"'boundary-space'\"", "\"'comment'\"",
  "\"'construction'\"", "\"'copy-namespaces'\"", "\"'count'\"",
  "\"'document'\"", "\"'document-node'\"", "\"'element'\"", "\"'for'\"",
  "\"'function'\"", "\"'if'\"", "\"'import'\"", "\"'instance'\"",
  "\"'let'\"", "\"'most'\"", "\"'next'\"", "\"'no'\"", "\"'only'\"",
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
  "IfExpr", "OrExpr", "AndExpr", "ComparisonExpr", "$@1", "FTContainsExpr",
  "StringConcatExpr", "opt_FTIgnoreOption", "RangeExpr", "AdditiveExpr",
  "MultiplicativeExpr", "UnionExpr", "IntersectExceptExpr",
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "UnaryExpr",
  "SignList", "ValueExpr", "SimpleMapExpr", "ValueComp", "NodeComp",
  "ValidateExpr", "ExtensionExpr", "Pragma_list", "Pragma", "PathExpr",
  "LeadingSlash", "RelativePathExpr", "StepExpr", "AxisStep",
  "ForwardStep", "ForwardAxis", "AbbrevForwardStep", "ReverseStep",
  "ReverseAxis", "NodeTest", "NameTest", "Wildcard", "FilterExpr",
  "PredicateList", "Predicate", "PrimaryExpr", "Literal", "NumericLiteral",
  "VarRef", "ParenthesizedExpr", "ContextItemExpr", "OrderedExpr",
  "UnorderedExpr", "FunctionCall", "ArgList", "Constructor",
  "DirectConstructor", "DirElemConstructor", "DirElemContentList",
  "DirAttributeList", "DirAttr", "OptionalBlank", "DirAttributeValue",
  "opt_QuoteAttrContentList", "QuoteAttrContentList",
  "opt_AposAttrContentList", "AposAttrContentList",
  "QuoteAttrValueContent", "AposAttrValueContent", "DirElemContent",
  "CommonContent", "DirCommentConstructor", "DirPIConstructor",
  "CDataSection", "ComputedConstructor", "CompDocConstructor",
  "CompElemConstructor", "CompAttrConstructor", "CompTextConstructor",
  "CompCommentConstructor", "CompPIConstructor", "SingleType",
  "TypeDeclaration", "SequenceType", "OccurrenceIndicator", "ItemType",
  "TypeList", "AtomicType", "KindTest", "AnyKindTest", "DocumentTest",
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
       335,     0,    -1,   337,    -1,   321,   337,    -1,   322,   337,
      -1,   321,   322,   337,    -1,     1,     3,    -1,   339,    -1,
     338,   339,    -1,   340,    -1,   338,   340,    -1,   215,   216,
      29,   190,    -1,   215,   216,    29,   131,    29,   190,    -1,
     342,   190,   389,    -1,   359,   190,   389,    -1,   342,   190,
     359,   190,   389,    -1,   389,    -1,   342,   336,   389,    -1,
     359,   336,   389,    -1,   342,   190,   359,   336,   389,    -1,
     342,   336,   359,   190,   389,    -1,   341,    -1,   341,   342,
     190,    -1,   341,   359,   190,    -1,   341,   342,   190,   359,
     190,    -1,    34,   160,   652,   132,   651,   190,    -1,   343,
      -1,   342,   190,   343,    -1,   342,   336,   343,    -1,   344,
      -1,   352,    -1,   357,    -1,   358,    -1,   366,    -1,   345,
      -1,   346,    -1,   347,    -1,   348,    -1,   349,    -1,   350,
      -1,   351,    -1,   571,    -1,    33,    38,   182,    -1,    33,
      38,   196,    -1,    33,   113,   106,   651,    -1,    33,    37,
     651,    -1,    33,    40,   182,    -1,    33,    40,   196,    -1,
      33,    57,   169,    -1,    33,    57,   202,    -1,    33,   113,
     168,   127,   128,    -1,    33,   113,   168,   127,   129,    -1,
      33,    41,   182,   107,   148,    -1,    33,    41,   182,   107,
     165,    -1,    33,    41,   166,   107,   148,    -1,    33,    41,
     166,   107,   165,    -1,   353,    -1,   356,    -1,    49,    24,
       1,    -1,    49,    60,   651,    -1,    49,    60,   355,   651,
      -1,    49,    60,   651,    96,   354,    -1,    49,    60,   355,
     651,    96,   354,    -1,   651,    -1,   354,   107,   651,    -1,
     160,   652,   132,    -1,   113,    45,   160,    -1,    49,    34,
     651,    -1,    49,    34,   160,   652,   132,   651,    -1,    49,
      34,   651,    96,   354,    -1,    49,    34,   160,   652,   132,
     651,    96,   354,    -1,    33,   160,   652,   132,   651,    -1,
      33,   113,    45,   160,   651,    -1,    33,   113,    47,   160,
     651,    -1,   360,    -1,   359,   190,   360,    -1,   359,   336,
     360,    -1,   361,    -1,   365,    -1,   367,    -1,   371,    -1,
     376,    -1,   383,    -1,   385,    -1,   388,    -1,    33,   113,
      79,   362,    -1,    33,    79,   653,   362,    -1,   363,    -1,
     362,   363,    -1,   364,   132,   563,    -1,    80,    -1,    88,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    89,
      -1,    85,    -1,    86,    -1,    87,    -1,    33,    56,   653,
      29,    -1,    33,   261,   610,    -1,    33,   111,   152,   368,
      -1,    94,   548,   369,    -1,   369,    -1,   370,    -1,   137,
      -1,   137,   370,    -1,   142,   413,    -1,    33,   372,   142,
     413,    -1,    33,   372,   137,    -1,    33,   372,   137,   142,
     413,    -1,   112,   118,   653,    -1,   112,   118,   653,   545,
      -1,   373,   112,   118,   653,    -1,   373,   112,   118,   653,
     545,    -1,   374,    -1,   373,   374,    -1,    26,    -1,    26,
     156,   375,   187,    -1,    27,    -1,    27,   156,   375,   187,
      -1,   509,    -1,   375,   107,   509,    -1,    33,   377,    -1,
      33,   373,   377,    -1,   378,    -1,   379,    -1,    47,   654,
     380,   397,    -1,    47,   654,   380,   137,    -1,    74,    47,
     654,   380,   397,    -1,    74,    47,   654,   380,   137,    -1,
     156,   187,    -1,   156,   381,   187,    -1,   156,   187,    94,
     546,    -1,   156,   381,   187,    94,   546,    -1,   382,    -1,
     381,   107,   382,    -1,   118,   653,    -1,   118,   653,   545,
      -1,    33,   287,   653,    -1,    33,   287,   653,    94,   384,
      -1,    33,   373,   287,   653,    -1,    33,   373,   287,   653,
      94,   384,    -1,   551,    -1,   551,   547,    -1,   647,    -1,
     647,   547,    -1,    33,   295,   653,   299,   227,   492,   170,
     386,    -1,    33,   373,   295,   653,   299,   227,   492,   170,
     386,    -1,   387,    -1,   386,   107,   387,    -1,   492,    -1,
     492,   545,    -1,   492,   448,    -1,   492,   545,   448,    -1,
      33,   303,   304,   653,   299,   287,   653,   118,   653,   305,
     413,    -1,    33,   303,   304,   653,   299,   287,   653,   225,
     118,   653,   305,   293,   306,   492,    -1,    33,   303,   304,
     653,   299,   287,   653,   307,   225,   118,   653,   305,   413,
      -1,    33,   303,   304,   653,   308,   306,   257,   287,   653,
     225,   118,   653,   306,   492,   199,   287,   653,   225,   118,
     653,   306,   492,    -1,   390,    -1,   392,    -1,   393,    -1,
      -1,   392,    -1,   393,    -1,    -1,   412,    -1,   393,   412,
      -1,   394,    -1,   393,   394,    -1,   395,    -1,   398,    -1,
     401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,    -1,
     406,    -1,   408,    -1,   460,    -1,   456,    -1,   409,    -1,
     153,   393,   184,    -1,   153,   184,    -1,   153,   391,   184,
      -1,   153,   391,   184,    -1,   399,   190,    -1,   399,   107,
     400,    -1,   112,   400,    -1,   373,   112,   400,    -1,   118,
     653,    -1,   118,   653,   545,    -1,   118,   653,   142,   413,
      -1,   118,   653,   545,   142,   413,    -1,   118,   653,   142,
     413,   190,    -1,   414,   190,    -1,   240,   242,   413,   190,
      -1,   243,   156,   412,   187,   394,    -1,   238,   241,   190,
      -1,   239,   241,   190,    -1,   424,   407,    -1,   186,   394,
      -1,    48,   156,   412,   187,   198,   394,   126,   394,    -1,
     244,   395,   410,    -1,   411,    -1,   410,   411,    -1,   245,
     583,   395,    -1,   413,    -1,   412,   107,   413,    -1,   415,
      -1,   452,    -1,   459,    -1,   465,    -1,   579,    -1,   414,
      -1,   466,    -1,   449,    -1,   572,    -1,   573,    -1,   575,
      -1,   574,    -1,   576,    -1,   644,    -1,   642,    -1,   645,
      -1,   646,    -1,   643,    -1,   424,   416,    -1,   186,   413,
      -1,    66,   284,    -1,    71,   284,    -1,   217,    -1,   254,
      -1,    55,   254,    -1,   418,   434,    77,   413,    -1,   418,
      77,   413,    -1,    46,   417,   433,   419,   419,    -1,    46,
     417,   433,   419,    -1,    42,   118,   653,    -1,   425,    -1,
     430,    -1,   420,    -1,   422,    -1,   437,    -1,   442,    -1,
     438,    -1,   421,    -1,   422,    -1,   424,   423,    -1,    46,
     118,   426,    -1,    46,     1,   426,    -1,    46,     3,    -1,
     427,    -1,   426,   107,   118,   427,    -1,   426,   107,   427,
      -1,   653,   147,   413,    -1,   653,    36,   127,   147,   413,
      -1,   653,   545,   147,   413,    -1,   653,   545,    36,   127,
     147,   413,    -1,   653,   428,   147,   413,    -1,   653,    36,
     127,   428,   147,   413,    -1,   653,   545,   428,   147,   413,
      -1,   653,   545,    36,   127,   428,   147,   413,    -1,   653,
     429,   147,   413,    -1,   653,   545,   429,   147,   413,    -1,
     653,   428,   429,   147,   413,    -1,   653,   545,   428,   429,
     147,   413,    -1,    96,   118,   653,    -1,   273,   118,   653,
      -1,    51,   431,    -1,   432,    -1,   431,   107,   432,    -1,
     118,   653,   142,   413,    -1,   118,   653,   545,   142,   413,
      -1,   429,   142,   413,    -1,   118,   653,   545,   429,   142,
     413,    -1,   118,   653,   147,   413,    -1,   118,   653,   545,
     147,   413,    -1,   435,    -1,   118,   653,    -1,   118,   653,
     435,    -1,   428,    -1,   428,   436,    -1,   436,    -1,    58,
     118,   653,    53,   118,   653,    -1,    53,   118,   653,    -1,
      58,   118,   653,    -1,   212,   413,    -1,   171,   170,   439,
      -1,   440,    -1,   439,   107,   440,    -1,   118,   653,    -1,
     118,   653,   142,   413,    -1,   118,   653,   545,   142,   413,
      -1,   118,   653,   545,   142,   413,   441,    -1,   118,   653,
     142,   413,   441,    -1,   118,   653,   441,    -1,   106,   651,
      -1,   168,   170,   443,    -1,    69,   168,   170,   443,    -1,
     444,    -1,   443,   107,   444,    -1,   413,    -1,   413,   445,
      -1,   446,    -1,   447,    -1,   448,    -1,   446,   447,    -1,
     446,   448,    -1,   447,   448,    -1,   446,   447,   448,    -1,
      95,    -1,   116,    -1,   127,   128,    -1,   127,   129,    -1,
     106,   651,    -1,    67,   118,   450,   188,   413,    -1,   135,
     118,   450,   188,   413,    -1,   451,    -1,   450,   107,   118,
     451,    -1,   653,   147,   413,    -1,   653,   545,   147,   413,
      -1,    72,   156,   412,   187,   453,   113,   186,   413,    -1,
     454,    -1,   453,   454,    -1,   455,   186,   413,    -1,   100,
     413,    -1,   455,   100,   413,    -1,    72,   156,   412,   187,
     457,   113,   186,   394,    -1,   458,    -1,   457,   458,    -1,
     455,   186,   394,    -1,    73,   156,   412,   187,   461,   113,
     186,   413,    -1,    73,   156,   412,   187,   461,   113,   118,
     653,   186,   413,    -1,    73,   156,   412,   187,   463,   113,
     186,   394,    -1,    73,   156,   412,   187,   461,   113,   118,
     653,   186,   394,    -1,   462,    -1,   461,   462,    -1,   100,
     546,   186,   413,    -1,   100,   118,   653,    94,   546,   186,
     413,    -1,   464,    -1,   463,   464,    -1,   100,   546,   186,
     394,    -1,   100,   118,   653,    94,   546,   186,   394,    -1,
      48,   156,   412,   187,   198,   413,   126,   413,    -1,   467,
      -1,   466,   167,   467,    -1,   468,    -1,   467,    92,   468,
      -1,   470,    -1,   470,   486,   470,    -1,   470,   487,   470,
      -1,   470,   132,   470,    -1,   470,   162,   470,    -1,    -1,
     470,   157,   469,   470,    -1,   470,   155,   470,    -1,   470,
     143,   470,    -1,   470,   141,   470,    -1,   471,    -1,   471,
     249,    70,   584,   472,    -1,   473,    -1,   473,    99,   471,
      -1,    -1,   636,    -1,   474,    -1,   474,   199,   474,    -1,
     475,    -1,   474,   176,   475,    -1,   474,   158,   475,    -1,
     476,    -1,   475,   194,   476,    -1,   475,   117,   476,    -1,
     475,   146,   476,    -1,   475,   159,   476,    -1,   477,    -1,
     476,   201,   477,    -1,   476,   210,   477,    -1,   478,    -1,
     477,   150,   478,    -1,   477,   136,   478,    -1,   479,    -1,
     479,    50,   231,   546,    -1,   480,    -1,   480,   200,    94,
     546,    -1,   481,    -1,   481,   101,    94,   544,    -1,   482,
      -1,   482,   102,    94,   544,    -1,   484,    -1,   483,   484,
      -1,   176,    -1,   158,    -1,   483,   176,    -1,   483,   158,
      -1,   488,    -1,   485,    -1,   489,    -1,   492,    -1,   485,
     193,   492,    -1,   203,    -1,   208,    -1,   207,    -1,   206,
      -1,   205,    -1,   204,    -1,   151,    -1,   179,    -1,   140,
      -1,    75,   153,   392,   184,    -1,    75,   222,   153,   392,
     184,    -1,    75,   221,   153,   392,   184,    -1,    75,    76,
     561,   153,   392,   184,    -1,   490,   153,   184,    -1,   490,
     153,   412,   184,    -1,   491,    -1,   490,   491,    -1,   177,
     653,    17,    -1,   177,    18,    -1,   177,    19,    -1,   493,
      -1,   493,   494,    -1,   192,   494,    -1,   494,    -1,   191,
      -1,   495,    -1,   495,   191,   494,    -1,   495,   192,   494,
      -1,   496,    -1,   505,    -1,   497,    -1,   497,   506,    -1,
     500,    -1,   500,   506,    -1,   498,   502,    -1,   499,    -1,
     105,   122,    -1,   114,   122,    -1,    97,   122,    -1,   189,
     122,    -1,   115,   122,    -1,   139,   122,    -1,   138,   122,
      -1,   502,    -1,    98,   502,    -1,   501,   502,    -1,   120,
      -1,   172,   122,    -1,    90,   122,    -1,   181,   122,    -1,
     180,   122,    -1,    91,   122,    -1,   551,    -1,   503,    -1,
     653,    -1,   504,    -1,   194,    -1,    11,    -1,    12,    -1,
      20,    -1,   508,    -1,   505,   506,    -1,   505,   156,   187,
      -1,   505,   156,   517,   187,    -1,   507,    -1,   506,   507,
      -1,   154,   412,   185,    -1,   509,    -1,   511,    -1,   512,
      -1,   513,    -1,   516,    -1,   518,    -1,   514,    -1,   515,
      -1,   564,    -1,   396,    -1,   640,    -1,   637,    -1,   638,
      -1,   639,    -1,   510,    -1,   563,    -1,   110,    -1,   149,
      -1,   124,    -1,   118,   653,    -1,   156,   187,    -1,   156,
     412,   187,    -1,   119,    -1,   169,   153,   412,   184,    -1,
     202,   153,   412,   184,    -1,   654,   156,   187,    -1,   654,
     156,   517,   187,    -1,   413,    -1,   517,   107,   413,    -1,
     519,    -1,   537,    -1,   520,    -1,   534,    -1,   535,    -1,
     157,   653,   524,   130,    -1,   157,   653,   522,   524,   130,
      -1,   157,   653,   524,   197,   195,   653,   524,   197,    -1,
     157,   653,   524,   197,   521,   195,   653,   524,   197,    -1,
     157,   653,   522,   524,   197,   195,   653,   524,   197,    -1,
     157,   653,   522,   524,   197,   521,   195,   653,   524,   197,
      -1,   532,    -1,   521,   532,    -1,   523,    -1,   522,   523,
      -1,    35,   653,   524,   132,   524,   525,    -1,    -1,    35,
      -1,   183,   526,   183,    -1,    93,   528,    93,    -1,    -1,
     527,    -1,   134,    -1,   530,    -1,   527,   134,    -1,   527,
     530,    -1,    -1,   529,    -1,   133,    -1,   531,    -1,   529,
     133,    -1,   529,   531,    -1,    28,    -1,   533,    -1,     5,
      -1,   533,    -1,   519,    -1,    10,    -1,   536,    -1,   533,
      -1,     9,    -1,   123,    -1,   125,    -1,   153,   392,   184,
      -1,   213,    30,   214,    -1,   213,   214,    -1,   174,   652,
     175,    -1,   174,   652,     8,    -1,   103,     7,    -1,   538,
      -1,   539,    -1,   540,    -1,   541,    -1,   542,    -1,   543,
      -1,    43,   153,   392,   184,    -1,    21,   391,   184,    -1,
      45,   153,   412,   184,   153,   391,   184,    -1,    22,   391,
     184,    -1,    97,   153,   412,   184,   153,   391,   184,    -1,
      70,   153,   392,   184,    -1,    39,   153,   392,   184,    -1,
      23,   391,   184,    -1,    59,   153,   412,   184,   153,   391,
     184,    -1,   550,    -1,   550,   144,    -1,    94,   546,    -1,
     548,    -1,   548,   547,    -1,   211,   156,   187,    -1,   144,
      -1,   194,    -1,   176,    -1,   550,    -1,   551,    -1,   152,
     156,   187,    -1,   320,   156,   187,    -1,   567,    -1,   570,
      -1,   647,    -1,   546,    -1,   549,   107,   546,    -1,   653,
      -1,   553,    -1,   559,    -1,   557,    -1,   560,    -1,   558,
      -1,   556,    -1,   555,    -1,   554,    -1,   552,    -1,   225,
     156,   187,    -1,    44,   156,   187,    -1,    44,   156,   559,
     187,    -1,    44,   156,   560,   187,    -1,    70,   156,   187,
      -1,    39,   156,   187,    -1,    59,   156,   187,    -1,    59,
     156,   652,   187,    -1,    59,   156,    29,   187,    -1,    97,
     156,   187,    -1,    97,   156,   653,   187,    -1,    97,   156,
     653,   107,   561,   187,    -1,    97,   156,   194,   187,    -1,
      97,   156,   194,   107,   561,   187,    -1,    61,   156,   653,
     187,    -1,    45,   156,   187,    -1,    45,   156,   653,   187,
      -1,    45,   156,   653,   107,   561,   187,    -1,    45,   156,
     653,   107,   562,   187,    -1,    45,   156,   194,   187,    -1,
      45,   156,   194,   107,   561,   187,    -1,    45,   156,   194,
     107,   562,   187,    -1,    62,   156,   653,   187,    -1,   653,
      -1,   653,   144,    -1,    29,    -1,   565,    -1,   566,    -1,
     653,   145,   149,    -1,    47,   380,   397,    -1,   568,    -1,
     569,    -1,    47,   156,   194,   187,    -1,    47,   156,   187,
      94,   546,    -1,    47,   156,   549,   187,    94,   546,    -1,
     156,   548,   187,    -1,    33,   220,   221,    -1,    33,   220,
     222,    -1,    33,   220,   223,    -1,   226,   225,   413,   233,
     413,    -1,   226,   225,   413,    94,   232,   233,   413,    -1,
     226,   225,   413,    94,   234,   233,   413,    -1,   226,   225,
     413,   218,   413,    -1,   226,   225,   413,   219,   413,    -1,
     226,   227,   413,   233,   413,    -1,   226,   227,   413,    94,
     232,   233,   413,    -1,   226,   227,   413,    94,   234,   233,
     413,    -1,   226,   227,   413,   218,   413,    -1,   226,   227,
     413,   219,   413,    -1,   224,   225,   413,    -1,   224,   227,
     413,    -1,   229,   225,   413,   237,   413,    -1,   229,   230,
     231,   225,   413,   237,   413,    -1,   228,   225,   413,    94,
     413,    -1,   236,   118,   577,   235,   413,   186,   413,    -1,
     578,    -1,   577,   107,   118,   578,    -1,   653,   142,   413,
      -1,   244,   153,   412,   184,   580,    -1,   581,    -1,   580,
     581,    -1,   245,   583,   582,    -1,   153,   412,   184,    -1,
     503,    -1,   583,   210,   503,    -1,   587,   585,    -1,    -1,
     586,    -1,   605,    -1,   586,   605,    -1,   588,    -1,   587,
     262,   588,    -1,   589,    -1,   588,   258,   589,    -1,   590,
      -1,   589,   260,   147,   590,    -1,   591,    -1,   259,   591,
      -1,   595,   592,   593,    -1,    -1,   610,    -1,    -1,   594,
      -1,   282,   153,   412,   184,    -1,   599,   596,    -1,   156,
     584,   187,    -1,   597,    -1,    -1,   632,    -1,   490,   153,
     598,   184,    -1,    -1,   584,    -1,   600,   601,    -1,   509,
      -1,   153,   412,   184,    -1,    -1,   602,    -1,   248,   603,
      -1,   247,   604,    -1,   270,    -1,    -1,    78,    -1,    -1,
     286,    -1,   606,    -1,   607,    -1,   608,    -1,   634,    -1,
     631,    -1,   169,    -1,   284,   474,   609,    -1,   253,   633,
     609,    -1,   286,    -1,   276,    -1,   269,    -1,   246,   611,
      -1,   610,   246,   611,    -1,   612,    -1,   613,    -1,   614,
      -1,   629,    -1,   615,    -1,   623,    -1,   616,    -1,   630,
      -1,   100,   274,    -1,   100,   263,    -1,   266,    -1,   281,
      -1,   251,   274,    -1,   251,   263,    -1,    56,   653,    29,
      -1,   277,    -1,    54,   277,    -1,   279,   617,    -1,   279,
     156,   617,   618,   187,    -1,    54,   279,    -1,   620,    -1,
     113,    -1,    -1,   107,   619,    -1,   620,    -1,   619,   107,
     620,    -1,    96,    29,   621,   622,    -1,    -1,   271,    29,
      -1,    -1,   633,   265,    -1,   278,   286,   624,   626,    -1,
     278,   286,   113,   626,    -1,    54,   278,   286,    -1,    96,
      29,    -1,   156,   625,   187,    -1,    29,    -1,   625,   107,
      29,    -1,    -1,   627,    -1,   628,    -1,   627,   628,    -1,
     201,   624,    -1,   136,   624,    -1,   264,    29,    -1,   283,
      -1,    54,   283,    -1,    96,   217,    -1,    96,   254,    -1,
     255,   250,    -1,   267,   633,   280,    -1,   256,   474,    -1,
      96,   129,   474,    -1,    96,    52,   474,    -1,   257,   474,
     199,   474,    -1,   272,   635,    -1,   252,   635,    -1,   275,
      -1,   268,    -1,   285,   250,   476,    -1,   154,   185,    -1,
     154,   412,   185,    -1,   310,   311,    -1,   310,   412,   311,
      -1,   312,   313,    -1,   312,   412,   313,    -1,   153,   641,
     184,    -1,   413,   121,   413,    -1,   641,   107,   413,   121,
     413,    -1,   226,   314,   153,   641,   184,   233,   413,    -1,
     226,   314,   154,   412,   185,   233,   413,    96,   316,   413,
      -1,   315,   314,   154,   412,   185,   199,   413,    -1,   224,
     314,   505,    -1,   228,   314,   505,    94,   413,    -1,   229,
     314,   230,   231,   505,   237,   413,    -1,   648,    -1,   649,
      -1,   650,    -1,   319,   156,   187,    -1,   317,   156,   187,
      -1,   318,   156,   187,    -1,    29,    -1,    16,    -1,   653,
      -1,   654,    -1,    97,    -1,    39,    -1,    44,    -1,    45,
      -1,   152,    -1,    48,    -1,   225,    -1,    59,    -1,    61,
      -1,    62,    -1,    70,    -1,    73,    -1,    72,    -1,   211,
      -1,   243,    -1,   655,    -1,    24,    -1,   215,    -1,   127,
      -1,    38,    -1,   261,    -1,    37,    -1,   222,    -1,   221,
      -1,   146,    -1,    43,    -1,   259,    -1,   260,    -1,   274,
      -1,   263,    -1,   251,    -1,   285,    -1,   277,    -1,   279,
      -1,   278,    -1,   283,    -1,   255,    -1,   250,    -1,    78,
      -1,   217,    -1,   254,    -1,    52,    -1,   223,    -1,   236,
      -1,   302,    -1,   230,    -1,   203,    -1,   208,    -1,   207,
      -1,   206,    -1,   205,    -1,   204,    -1,    96,    -1,   111,
      -1,   112,    -1,   186,    -1,    46,    -1,    36,    -1,    66,
      -1,    71,    -1,    58,    -1,    53,    -1,    55,    -1,    77,
      -1,    42,    -1,   147,    -1,    51,    -1,   212,    -1,   170,
      -1,   171,    -1,   168,    -1,    69,    -1,    95,    -1,   116,
      -1,   128,    -1,   129,    -1,   106,    -1,    67,    -1,   135,
      -1,   188,    -1,   100,    -1,    94,    -1,   198,    -1,   126,
      -1,   167,    -1,    92,    -1,    50,    -1,   231,    -1,   101,
      -1,   199,    -1,   117,    -1,   159,    -1,   201,    -1,   150,
      -1,   136,    -1,    75,    -1,    76,    -1,   102,    -1,   200,
      -1,   151,    -1,   182,    -1,   196,    -1,   160,    -1,   137,
      -1,   131,    -1,   166,    -1,   148,    -1,   165,    -1,    33,
      -1,    40,    -1,    57,    -1,   113,    -1,    41,    -1,    56,
      -1,   216,    -1,    49,    -1,    60,    -1,    34,    -1,    47,
      -1,   273,    -1,   249,    -1,   282,    -1,   284,    -1,   253,
      -1,   267,    -1,   280,    -1,   272,    -1,   252,    -1,   266,
      -1,   281,    -1,   271,    -1,   265,    -1,   264,    -1,   248,
      -1,   247,    -1,   256,    -1,   257,    -1,   286,    -1,   276,
      -1,   275,    -1,   270,    -1,   268,    -1,   269,    -1,   229,
      -1,   235,    -1,   232,    -1,   226,    -1,   219,    -1,   218,
      -1,   220,    -1,   237,    -1,   227,    -1,   228,    -1,   234,
      -1,   224,    -1,   233,    -1,    65,    -1,    63,    -1,    74,
      -1,   169,    -1,   202,    -1,   242,    -1,   240,    -1,   241,
      -1,   238,    -1,   239,    -1,   244,    -1,   245,    -1,   246,
      -1,    64,    -1,   295,    -1,   293,    -1,   294,    -1,   299,
      -1,   300,    -1,   301,    -1,   296,    -1,   297,    -1,   298,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,   287,    -1,   288,    -1,   289,    -1,   290,
      -1,   291,    -1,   292,    -1,   303,    -1,   304,    -1,   305,
      -1,   306,    -1,   307,    -1,   308,    -1,   309,    -1,    90,
      -1,   105,    -1,   114,    -1,   172,    -1,   180,    -1,   189,
      -1,   138,    -1,    91,    -1,   115,    -1,   139,    -1,   181,
      -1,   314,    -1,   315,    -1,   316,    -1,   319,    -1,   318,
      -1,   317,    -1,   320,    -1,    25,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  xquery_parser::yyprhs_[] =
  {
         0,     0,     3,     5,     8,    11,    15,    18,    20,    23,
      25,    28,    33,    40,    44,    48,    54,    56,    60,    64,
      70,    76,    78,    82,    86,    92,    99,   101,   105,   109,
     111,   113,   115,   117,   119,   121,   123,   125,   127,   129,
     131,   133,   135,   139,   143,   148,   152,   156,   160,   164,
     168,   174,   180,   186,   192,   198,   204,   206,   208,   212,
     216,   221,   227,   234,   236,   240,   244,   248,   252,   259,
     265,   274,   280,   286,   292,   294,   298,   302,   304,   306,
     308,   310,   312,   314,   316,   318,   323,   328,   330,   333,
     337,   339,   341,   343,   345,   347,   349,   351,   353,   355,
     357,   362,   366,   371,   375,   377,   379,   381,   384,   387,
     392,   396,   402,   406,   411,   416,   422,   424,   427,   429,
     434,   436,   441,   443,   447,   450,   454,   456,   458,   463,
     468,   474,   480,   483,   487,   492,   498,   500,   504,   507,
     511,   515,   521,   526,   533,   535,   538,   540,   543,   552,
     562,   564,   568,   570,   573,   576,   580,   592,   607,   621,
     644,   646,   648,   650,   651,   653,   655,   656,   658,   661,
     663,   666,   668,   670,   672,   674,   676,   678,   680,   682,
     684,   686,   688,   690,   694,   697,   701,   705,   708,   712,
     715,   719,   722,   726,   731,   737,   743,   746,   751,   757,
     761,   765,   768,   771,   780,   784,   786,   789,   793,   795,
     799,   801,   803,   805,   807,   809,   811,   813,   815,   817,
     819,   821,   823,   825,   827,   829,   831,   833,   835,   838,
     841,   844,   847,   849,   851,   854,   859,   863,   869,   874,
     878,   880,   882,   884,   886,   888,   890,   892,   894,   896,
     899,   903,   907,   910,   912,   917,   921,   925,   931,   936,
     943,   948,   955,   961,   969,   974,   980,   986,   993,   997,
    1001,  1004,  1006,  1010,  1015,  1021,  1025,  1032,  1037,  1043,
    1045,  1048,  1052,  1054,  1057,  1059,  1066,  1070,  1074,  1077,
    1081,  1083,  1087,  1090,  1095,  1101,  1108,  1114,  1118,  1121,
    1125,  1130,  1132,  1136,  1138,  1141,  1143,  1145,  1147,  1150,
    1153,  1156,  1160,  1162,  1164,  1167,  1170,  1173,  1179,  1185,
    1187,  1192,  1196,  1201,  1210,  1212,  1215,  1219,  1222,  1226,
    1235,  1237,  1240,  1244,  1253,  1264,  1273,  1284,  1286,  1289,
    1294,  1302,  1304,  1307,  1312,  1320,  1329,  1331,  1335,  1337,
    1341,  1343,  1347,  1351,  1355,  1359,  1360,  1365,  1369,  1373,
    1377,  1379,  1385,  1387,  1391,  1392,  1394,  1396,  1400,  1402,
    1406,  1410,  1412,  1416,  1420,  1424,  1428,  1430,  1434,  1438,
    1440,  1444,  1448,  1450,  1455,  1457,  1462,  1464,  1469,  1471,
    1476,  1478,  1481,  1483,  1485,  1488,  1491,  1493,  1495,  1497,
    1499,  1503,  1505,  1507,  1509,  1511,  1513,  1515,  1517,  1519,
    1521,  1526,  1532,  1538,  1545,  1549,  1554,  1556,  1559,  1563,
    1566,  1569,  1571,  1574,  1577,  1579,  1581,  1583,  1587,  1591,
    1593,  1595,  1597,  1600,  1602,  1605,  1608,  1610,  1613,  1616,
    1619,  1622,  1625,  1628,  1631,  1633,  1636,  1639,  1641,  1644,
    1647,  1650,  1653,  1656,  1658,  1660,  1662,  1664,  1666,  1668,
    1670,  1672,  1674,  1677,  1681,  1686,  1688,  1691,  1695,  1697,
    1699,  1701,  1703,  1705,  1707,  1709,  1711,  1713,  1715,  1717,
    1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1736,  1739,
    1743,  1745,  1750,  1755,  1759,  1764,  1766,  1770,  1772,  1774,
    1776,  1778,  1780,  1785,  1791,  1800,  1810,  1820,  1831,  1833,
    1836,  1838,  1841,  1848,  1849,  1851,  1855,  1859,  1860,  1862,
    1864,  1866,  1869,  1872,  1873,  1875,  1877,  1879,  1882,  1885,
    1887,  1889,  1891,  1893,  1895,  1897,  1899,  1901,  1903,  1905,
    1907,  1911,  1915,  1918,  1922,  1926,  1929,  1931,  1933,  1935,
    1937,  1939,  1941,  1946,  1950,  1958,  1962,  1970,  1975,  1980,
    1984,  1992,  1994,  1997,  2000,  2002,  2005,  2009,  2011,  2013,
    2015,  2017,  2019,  2023,  2027,  2029,  2031,  2033,  2035,  2039,
    2041,  2043,  2045,  2047,  2049,  2051,  2053,  2055,  2057,  2059,
    2063,  2067,  2072,  2077,  2081,  2085,  2089,  2094,  2099,  2103,
    2108,  2115,  2120,  2127,  2132,  2136,  2141,  2148,  2155,  2160,
    2167,  2174,  2179,  2181,  2184,  2186,  2188,  2190,  2194,  2198,
    2200,  2202,  2207,  2213,  2220,  2224,  2228,  2232,  2236,  2242,
    2250,  2258,  2264,  2270,  2276,  2284,  2292,  2298,  2304,  2308,
    2312,  2318,  2326,  2332,  2340,  2342,  2347,  2351,  2357,  2359,
    2362,  2366,  2370,  2372,  2376,  2379,  2380,  2382,  2384,  2387,
    2389,  2393,  2395,  2399,  2401,  2406,  2408,  2411,  2415,  2416,
    2418,  2419,  2421,  2426,  2429,  2433,  2435,  2436,  2438,  2443,
    2444,  2446,  2449,  2451,  2455,  2456,  2458,  2461,  2464,  2466,
    2467,  2469,  2470,  2472,  2474,  2476,  2478,  2480,  2482,  2484,
    2488,  2492,  2494,  2496,  2498,  2501,  2505,  2507,  2509,  2511,
    2513,  2515,  2517,  2519,  2521,  2524,  2527,  2529,  2531,  2534,
    2537,  2541,  2543,  2546,  2549,  2555,  2558,  2560,  2562,  2563,
    2566,  2568,  2572,  2577,  2578,  2581,  2582,  2585,  2590,  2595,
    2599,  2602,  2606,  2608,  2612,  2613,  2615,  2617,  2620,  2623,
    2626,  2629,  2631,  2634,  2637,  2640,  2643,  2647,  2650,  2654,
    2658,  2663,  2666,  2669,  2671,  2673,  2677,  2680,  2684,  2687,
    2691,  2694,  2698,  2702,  2706,  2712,  2720,  2731,  2739,  2743,
    2749,  2757,  2759,  2761,  2763,  2767,  2771,  2775,  2777,  2779,
    2781,  2783,  2785,  2787,  2789,  2791,  2793,  2795,  2797,  2799,
    2801,  2803,  2805,  2807,  2809,  2811,  2813,  2815,  2817,  2819,
    2821,  2823,  2825,  2827,  2829,  2831,  2833,  2835,  2837,  2839,
    2841,  2843,  2845,  2847,  2849,  2851,  2853,  2855,  2857,  2859,
    2861,  2863,  2865,  2867,  2869,  2871,  2873,  2875,  2877,  2879,
    2881,  2883,  2885,  2887,  2889,  2891,  2893,  2895,  2897,  2899,
    2901,  2903,  2905,  2907,  2909,  2911,  2913,  2915,  2917,  2919,
    2921,  2923,  2925,  2927,  2929,  2931,  2933,  2935,  2937,  2939,
    2941,  2943,  2945,  2947,  2949,  2951,  2953,  2955,  2957,  2959,
    2961,  2963,  2965,  2967,  2969,  2971,  2973,  2975,  2977,  2979,
    2981,  2983,  2985,  2987,  2989,  2991,  2993,  2995,  2997,  2999,
    3001,  3003,  3005,  3007,  3009,  3011,  3013,  3015,  3017,  3019,
    3021,  3023,  3025,  3027,  3029,  3031,  3033,  3035,  3037,  3039,
    3041,  3043,  3045,  3047,  3049,  3051,  3053,  3055,  3057,  3059,
    3061,  3063,  3065,  3067,  3069,  3071,  3073,  3075,  3077,  3079,
    3081,  3083,  3085,  3087,  3089,  3091,  3093,  3095,  3097,  3099,
    3101,  3103,  3105,  3107,  3109,  3111,  3113,  3115,  3117,  3119,
    3121,  3123,  3125,  3127,  3129,  3131,  3133,  3135,  3137,  3139,
    3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,  3159,
    3161,  3163,  3165,  3167,  3169,  3171,  3173,  3175,  3177,  3179,
    3181,  3183,  3185,  3187,  3189,  3191,  3193,  3195,  3197,  3199,
    3201,  3203,  3205,  3207,  3209,  3211,  3213,  3215,  3217,  3219,
    3221,  3223,  3225
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1048,  1048,  1049,  1053,  1057,  1068,  1077,  1083,  1091,
    1097,  1108,  1113,  1121,  1128,  1135,  1144,  1151,  1159,  1167,
    1175,  1186,  1191,  1198,  1205,  1217,  1227,  1234,  1241,  1253,
    1254,  1255,  1256,  1257,  1262,  1263,  1264,  1265,  1266,  1267,
    1268,  1271,  1276,  1281,  1289,  1297,  1305,  1310,  1318,  1323,
    1331,  1336,  1344,  1351,  1358,  1365,  1375,  1377,  1380,  1390,
    1395,  1403,  1411,  1422,  1429,  1440,  1445,  1453,  1460,  1467,
    1476,  1489,  1497,  1504,  1514,  1521,  1528,  1539,  1540,  1541,
    1542,  1543,  1544,  1545,  1546,  1551,  1557,  1566,  1573,  1583,
    1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,
    1607,  1615,  1623,  1631,  1638,  1646,  1653,  1658,  1666,  1674,
    1688,  1702,  1719,  1724,  1732,  1740,  1751,  1756,  1765,  1770,
    1777,  1782,  1792,  1797,  1806,  1812,  1825,  1830,  1838,  1849,
    1864,  1876,  1891,  1896,  1901,  1906,  1914,  1921,  1932,  1937,
    1947,  1954,  1961,  1968,  1978,  1982,  1988,  1992,  2002,  2010,
    2021,  2027,  2036,  2041,  2048,  2055,  2066,  2076,  2086,  2096,
    2114,  2134,  2138,  2143,  2150,  2154,  2159,  2166,  2171,  2183,
    2190,  2202,  2203,  2204,  2205,  2206,  2207,  2208,  2210,  2211,
    2212,  2213,  2214,  2219,  2224,  2232,  2249,  2257,  2265,  2272,
    2279,  2290,  2299,  2308,  2317,  2330,  2338,  2346,  2354,  2369,
    2374,  2382,  2396,  2413,  2438,  2446,  2453,  2464,  2474,  2479,
    2494,  2495,  2496,  2497,  2498,  2499,  2504,  2505,  2508,  2509,
    2510,  2511,  2512,  2515,  2516,  2517,  2518,  2519,  2524,  2538,
    2546,  2551,  2559,  2564,  2569,  2577,  2586,  2598,  2608,  2621,
    2629,  2630,  2631,  2636,  2637,  2638,  2639,  2640,  2645,  2652,
    2662,  2668,  2676,  2686,  2693,  2701,  2712,  2722,  2732,  2742,
    2752,  2762,  2772,  2782,  2793,  2802,  2812,  2822,  2838,  2847,
    2856,  2864,  2870,  2882,  2890,  2900,  2908,  2920,  2926,  2937,
    2939,  2943,  2951,  2955,  2960,  2964,  2968,  2972,  2982,  2990,
    2997,  3003,  3013,  3017,  3021,  3029,  3037,  3045,  3057,  3065,
    3071,  3081,  3087,  3097,  3101,  3111,  3117,  3123,  3129,  3138,
    3147,  3156,  3169,  3173,  3181,  3187,  3197,  3205,  3214,  3227,
    3234,  3246,  3250,  3262,  3269,  3275,  3284,  3291,  3297,  3308,
    3315,  3321,  3330,  3339,  3346,  3357,  3364,  3376,  3382,  3394,
    3400,  3411,  3417,  3428,  3434,  3445,  3454,  3458,  3467,  3471,
    3479,  3483,  3493,  3500,  3509,  3519,  3518,  3532,  3541,  3550,
    3563,  3567,  3579,  3583,  3591,  3594,  3601,  3605,  3614,  3618,
    3622,  3630,  3634,  3640,  3646,  3652,  3662,  3666,  3670,  3678,
    3682,  3688,  3698,  3702,  3712,  3716,  3726,  3730,  3740,  3744,
    3754,  3758,  3766,  3770,  3774,  3778,  3788,  3792,  3796,  3803,
    3808,  3816,  3820,  3824,  3828,  3832,  3836,  3844,  3848,  3852,
    3860,  3864,  3868,  3872,  3883,  3889,  3899,  3905,  3915,  3919,
    3923,  3961,  3965,  3975,  3985,  3998,  4007,  4017,  4021,  4030,
    4034,  4043,  4049,  4057,  4063,  4075,  4081,  4091,  4095,  4099,
    4103,  4107,  4113,  4119,  4127,  4131,  4139,  4143,  4154,  4158,
    4162,  4168,  4172,  4186,  4190,  4198,  4202,  4212,  4216,  4220,
    4224,  4233,  4237,  4241,  4245,  4253,  4259,  4269,  4277,  4281,
    4285,  4289,  4293,  4297,  4301,  4305,  4309,  4313,  4318,  4322,
    4326,  4330,  4338,  4342,  4350,  4357,  4364,  4375,  4383,  4387,
    4395,  4403,  4411,  4465,  4469,  4482,  4488,  4498,  4502,  4510,
    4514,  4518,  4526,  4536,  4546,  4563,  4580,  4597,  4619,  4625,
    4636,  4642,  4653,  4664,  4666,  4670,  4675,  4685,  4688,  4695,
    4701,  4707,  4715,  4728,  4731,  4738,  4744,  4750,  4757,  4768,
    4772,  4782,  4786,  4796,  4800,  4804,  4809,  4818,  4824,  4830,
    4836,  4844,  4849,  4857,  4862,  4870,  4878,  4883,  4888,  4893,
    4898,  4903,  4912,  4920,  4924,  4941,  4945,  4953,  4961,  4969,
    4973,  4981,  4987,  4997,  5005,  5009,  5013,  5048,  5054,  5060,
    5070,  5074,  5078,  5082,  5086,  5090,  5094,  5101,  5107,  5117,
    5125,  5129,  5133,  5137,  5141,  5145,  5149,  5153,  5157,  5165,
    5173,  5177,  5181,  5191,  5199,  5207,  5211,  5215,  5223,  5227,
    5233,  5239,  5243,  5253,  5261,  5265,  5271,  5280,  5289,  5295,
    5301,  5311,  5328,  5335,  5350,  5386,  5390,  5398,  5406,  5418,
    5422,  5430,  5438,  5442,  5453,  5470,  5476,  5482,  5492,  5496,
    5502,  5508,  5512,  5518,  5522,  5528,  5534,  5541,  5551,  5556,
    5564,  5570,  5580,  5602,  5611,  5617,  5630,  5644,  5651,  5657,
    5667,  5676,  5684,  5690,  5708,  5716,  5720,  5727,  5732,  5740,
    5744,  5751,  5755,  5762,  5766,  5773,  5777,  5786,  5799,  5802,
    5810,  5813,  5821,  5829,  5837,  5841,  5849,  5852,  5860,  5872,
    5875,  5883,  5895,  5901,  5911,  5914,  5922,  5926,  5930,  5938,
    5941,  5949,  5952,  5960,  5964,  5968,  5972,  5976,  5984,  5992,
    6004,  6016,  6020,  6024,  6032,  6038,  6048,  6052,  6056,  6060,
    6064,  6068,  6072,  6076,  6084,  6088,  6092,  6096,  6104,  6110,
    6120,  6130,  6134,  6142,  6152,  6163,  6170,  6174,  6182,  6185,
    6192,  6197,  6206,  6216,  6219,  6226,  6230,  6238,  6247,  6254,
    6264,  6268,  6275,  6281,  6291,  6294,  6301,  6306,  6318,  6326,
    6338,  6346,  6350,  6358,  6362,  6366,  6374,  6382,  6386,  6390,
    6394,  6402,  6410,  6422,  6426,  6434,  6448,  6452,  6459,  6464,
    6472,  6477,  6486,  6494,  6500,  6510,  6516,  6523,  6530,  6559,
    6588,  6617,  6621,  6625,  6632,  6639,  6646,  6658,  6662,  6663,
    6676,  6677,  6678,  6679,  6680,  6681,  6682,  6683,  6684,  6685,
    6686,  6687,  6688,  6689,  6690,  6691,  6695,  6696,  6697,  6698,
    6699,  6700,  6701,  6702,  6703,  6704,  6705,  6706,  6707,  6708,
    6709,  6710,  6711,  6712,  6713,  6714,  6715,  6716,  6717,  6718,
    6719,  6720,  6721,  6722,  6723,  6724,  6725,  6726,  6727,  6728,
    6729,  6730,  6731,  6732,  6733,  6734,  6735,  6736,  6737,  6738,
    6739,  6740,  6741,  6742,  6743,  6744,  6745,  6746,  6747,  6748,
    6749,  6750,  6751,  6752,  6753,  6754,  6755,  6756,  6757,  6758,
    6759,  6760,  6761,  6762,  6763,  6764,  6765,  6766,  6767,  6768,
    6769,  6770,  6771,  6772,  6773,  6774,  6775,  6776,  6777,  6778,
    6779,  6780,  6781,  6782,  6783,  6784,  6785,  6786,  6787,  6788,
    6789,  6790,  6791,  6792,  6793,  6794,  6795,  6796,  6797,  6798,
    6799,  6800,  6801,  6802,  6803,  6804,  6805,  6806,  6807,  6808,
    6809,  6810,  6811,  6812,  6813,  6814,  6815,  6816,  6817,  6818,
    6819,  6820,  6821,  6822,  6823,  6824,  6825,  6826,  6827,  6828,
    6829,  6830,  6831,  6832,  6833,  6834,  6835,  6836,  6837,  6838,
    6839,  6840,  6841,  6842,  6843,  6844,  6845,  6846,  6847,  6848,
    6849,  6850,  6851,  6852,  6853,  6854,  6855,  6856,  6857,  6858,
    6859,  6860,  6861,  6862,  6863,  6864,  6865,  6866,  6867,  6868,
    6869,  6870,  6871,  6872,  6873,  6874,  6875,  6876,  6877,  6878,
    6879,  6880,  6881,  6882,  6883,  6884,  6885,  6886,  6887,  6888,
    6889,  6890,  6891,  6892,  6893,  6894,  6895,  6896,  6897,  6898,
    6899,  6900,  6905
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
     325,   326,   327,   328,   329,   330,   331,   332,   333
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 15899;
  const int xquery_parser::yynnts_ = 322;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 608;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 334;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 588;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17398 "/Users/wcandillon/28msec/zorba/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6909 "/Users/wcandillon/28msec/zorba/sandbox/src/compiler/parser/xquery_parser.y"


namespace zorba {

namespace parser {

const char *the_tumbling = "tumbling", *the_sliding = "sliding",
  *the_start = "start", *the_end = "end", *the_only_end = "only end",
  *the_declare = "declare", *the_create = "create";

} // namespace parser

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
    // remove the double quoting "''" from every token description
    string message = msg;
    int pos;
    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

} // namespace zorba

