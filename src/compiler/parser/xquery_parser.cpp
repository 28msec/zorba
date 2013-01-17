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
#line 87 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"


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
#line 77 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */

/* Line 299 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 299 of lalr1.cc  */
#line 1035 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex



/* Line 299 of lalr1.cc  */
#line 107 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"

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
#line 193 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"

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
#line 908 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->decval); };

/* Line 480 of lalr1.cc  */
#line 298 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "\"'DOUBLE'\"" */

/* Line 480 of lalr1.cc  */
#line 907 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->dval); };

/* Line 480 of lalr1.cc  */
#line 307 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "\"'INTEGER'\"" */

/* Line 480 of lalr1.cc  */
#line 906 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->ival); };

/* Line 480 of lalr1.cc  */
#line 316 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* "VersionDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 325 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* "MainModule" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 334 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* "LibraryModule" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 343 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* "ModuleDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 352 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* "SIND_DeclList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 361 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* "SIND_Decl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 370 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* "Setter" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 379 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* "BoundarySpaceDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 388 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* "DefaultCollationDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 397 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* "BaseURIDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 406 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* "ConstructionDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 415 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* "OrderingModeDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 424 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* "EmptyOrderDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 433 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* "CopyNamespacesDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 442 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* "Import" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 451 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* "SchemaImport" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 460 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* "URILiteralList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 469 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* "SchemaPrefix" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 478 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* "ModuleImport" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 487 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* "NamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 496 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* "DefaultNamespaceDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 505 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* "VFO_DeclList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 514 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* "VFO_Decl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 523 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* "DecimalFormatDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 532 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* "DecimalFormatParamList" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->vstrpair); };

/* Line 480 of lalr1.cc  */
#line 541 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* "DecimalFormatParam" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->strpair); };

/* Line 480 of lalr1.cc  */
#line 550 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* "OptionDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 559 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* "FTOptionDecl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 568 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* "CtxItemDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 577 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* "CtxItemDecl2" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 586 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* "CtxItemDecl3" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 595 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* "CtxItemDecl4" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 604 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* "VarDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 613 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* "VarNameAndType" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->varnametype); };

/* Line 480 of lalr1.cc  */
#line 622 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* "AnnotationList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 631 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* "Annotation" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 640 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* "AnnotationLiteralList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 649 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* "FunctionDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 658 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* "FunctionDecl2" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 667 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* "FunctionDeclSimple" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 676 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* "FunctionDeclUpdating" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 685 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* "FunctionSig" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->fnsig); };

/* Line 480 of lalr1.cc  */
#line 694 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* "ParamList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 703 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* "Param" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 712 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* "CollectionDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 721 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* "IndexDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 730 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* "IndexKeyList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 739 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* "IndexKeySpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 748 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* "IntegrityConstraintDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 757 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* "QueryBody" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 766 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* "StatementsAndOptionalExprTop" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 775 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* "StatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 784 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* "StatementsAndExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 793 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* "Statements" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 802 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* "Statement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 811 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* "BlockStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 820 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* "BlockExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 829 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* "EnclosedStatementsAndOptionalExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 838 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* "VarDeclStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 847 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* "AssignStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 856 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* "ApplyStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 865 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* "ExitStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 874 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* "WhileStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 883 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* "FlowCtlStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 892 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* "FLWORStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 901 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* "ReturnStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 910 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* "IfStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 919 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* "TryStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* "CatchListStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 937 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* "CatchStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 946 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* "Expr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 955 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* "ExprSingle" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 964 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* "ExprSimple" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 973 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* "FLWORExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 982 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* "ReturnExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 991 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* "FLWORWinCond" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1000 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* "WindowClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1009 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* "CountClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1018 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* "ForLetWinClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1027 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* "FLWORClauseList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1036 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* "ForClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1045 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* "VarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1054 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* "VarInDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1063 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* "PositionalVar" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1072 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* "FTScoreVar" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1081 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* "LetClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1090 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* "VarGetsDeclList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1099 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* "VarGetsDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1108 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* "WindowVarDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1117 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* "WindowVars" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1126 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* "WindowVars3" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1135 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* "WindowVars2" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1144 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* "WhereClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1153 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* "GroupByClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1162 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* "GroupSpecList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1171 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* "GroupSpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1180 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* "GroupCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1189 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* "OrderByClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1198 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* "OrderSpecList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1207 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* "OrderSpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1216 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* "OrderModifier" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1225 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* "OrderDirSpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1234 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* "OrderEmptySpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1243 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* "OrderCollationSpec" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1252 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* "QuantifiedExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1261 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* "QVarInDeclList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1270 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* "QVarInDecl" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1279 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* "SwitchExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1288 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* "SwitchCaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1297 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* "SwitchCaseClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1306 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* "SwitchCaseOperandList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1315 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* "SwitchStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1324 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* "TypeswitchExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1333 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* "TypeswitchStatement" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1342 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* "CaseClauseList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1351 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* "CaseClause" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1360 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* "IfExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1369 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* "OrExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1378 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* "AndExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1387 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* "ComparisonExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1396 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* "FTContainsExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1405 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* "StringConcatExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1414 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* "opt_FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1423 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* "RangeExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1432 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* "AdditiveExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1441 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* "MultiplicativeExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1450 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* "UnionExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1459 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* "IntersectExceptExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1468 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* "InstanceofExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1477 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* "TreatExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1486 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* "CastableExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1495 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* "CastExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1504 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* "SingleType" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1513 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* "UnaryExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1522 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* "SignList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1531 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* "ValueExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1540 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* "SimpleMapExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1549 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* "ValueComp" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1558 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* "NodeComp" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1567 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* "ValidateExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1576 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* "ExtensionExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1585 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* "Pragma_list" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1594 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* "Pragma" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* "PathExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1612 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* "RelativePathExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1621 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* "StepExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1630 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* "AxisStep" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1639 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* "ForwardStep" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1648 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* "ForwardAxis" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1657 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* "AbbrevForwardStep" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1666 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* "ReverseStep" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1675 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* "ReverseAxis" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1684 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* "NodeTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1693 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* "NameTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1702 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* "Wildcard" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1711 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* "FilterExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1720 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* "PredicateList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1729 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* "Predicate" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1738 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* "PrimaryExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1747 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* "Literal" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1756 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* "NumericLiteral" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1765 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* "VarRef" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1774 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* "ParenthesizedExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1783 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* "ContextItemExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1792 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* "OrderedExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1801 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* "UnorderedExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1810 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* "FunctionCall" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1819 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* "ArgList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1828 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* "Constructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1837 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* "DirectConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1846 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* "DirElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1855 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* "DirElemContentList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1864 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* "DirAttributeList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1873 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* "DirAttr" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1882 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* "DirAttributeValue" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1891 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* "opt_QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1900 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* "QuoteAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1909 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* "opt_AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1918 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* "AposAttrContentList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1927 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* "QuoteAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1936 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* "AposAttrValueContent" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 1945 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* "DirElemContent" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1954 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* "CommonContent" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1963 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* "DirCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1972 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* "DirPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1981 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* "CDataSection" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1990 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* "ComputedConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 1999 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* "CompDocConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2008 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* "CompElemConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2017 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* "CompAttrConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2026 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* "CompTextConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2035 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* "CompCommentConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2044 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* "CompPIConstructor" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2053 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* "TypeDeclaration" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2062 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* "SequenceType" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2071 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* "OccurrenceIndicator" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2080 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* "ItemType" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2089 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* "TypeList" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2098 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* "AtomicType" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2107 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* "SimpleType" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2116 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* "KindTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2125 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* "AnyKindTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2134 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* "DocumentTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2143 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* "TextTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2152 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* "CommentTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2161 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* "PITest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2170 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* "AttributeTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2179 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* "SchemaAttributeTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2188 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* "ElementTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2197 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* "SchemaElementTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2206 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* "TypeName" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2215 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* "TypeName_WITH_HOOK" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2224 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 564: /* "StringLiteral" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2233 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* "AnyFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2242 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* "TypedFunctionTest" */

/* Line 480 of lalr1.cc  */
#line 922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2251 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* "InsertExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2260 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* "DeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2269 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* "ReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2278 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* "RenameExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2287 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* "TransformExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2296 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* "VarNameList" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2305 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* "VarNameDecl" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2314 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* "TryExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2323 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* "CatchListExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2332 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* "CatchExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2341 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* "BracedExpr" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2350 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* "NameTestList" */

/* Line 480 of lalr1.cc  */
#line 934 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete (yyvaluep->name_test_list); };

/* Line 480 of lalr1.cc  */
#line 2359 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* "FTSelection" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2368 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* "FTOr" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2377 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* "FTAnd" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2386 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* "FTMildNot" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2395 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* "FTUnaryNot" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2404 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* "FTPrimaryWithOptions" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2413 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* "opt_FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2422 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* "FTWeight" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2431 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* "FTPrimary" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2440 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* "opt_FTTimes" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2449 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 598: /* "FTExtensionSelection" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2458 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* "FTWords" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2467 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 601: /* "FTWordsValue" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2476 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* "FTAnyallOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2485 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* "FTPosFilter" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2494 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* "FTOrder" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2503 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* "FTWindow" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2512 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* "FTDistance" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2521 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* "FTUnit" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2530 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* "FTMatchOptions" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2539 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* "FTMatchOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2548 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* "FTCaseOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2557 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* "FTDiacriticsOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2566 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* "FTExtensionOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2575 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* "FTStemOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2584 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* "FTThesaurusOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2593 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* "FTThesaurusID" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2602 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* "FTStopWordOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2611 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* "FTStopWords" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2620 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* "FTStopWordsInclExcl" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2629 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* "FTLanguageOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2638 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* "FTWildCardOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2647 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* "FTContent" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2656 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* "FTTimes" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2665 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* "FTRange" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2674 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* "FTScope" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2683 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* "FTBigUnit" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2692 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* "FTIgnoreOption" */

/* Line 480 of lalr1.cc  */
#line 925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2701 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* "JSONArrayConstructor" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2710 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* "JSONSimpleObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2719 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* "JSONAccumulatorObjectUnion" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2728 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* "JSONObjectConstructor" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2737 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* "JSONPairList" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->node) ); };

/* Line 480 of lalr1.cc  */
#line 2746 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* "JSONInsertExpr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2755 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* "JSONAppendExpr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2764 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* "JSONDeleteExpr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2773 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* "JSONRenameExpr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2782 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 647: /* "JSONReplaceExpr" */

/* Line 480 of lalr1.cc  */
#line 928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2791 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 654: /* "QNAME" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2800 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 655: /* "FUNCTION_NAME" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2809 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 656: /* "EQNAME" */

/* Line 480 of lalr1.cc  */
#line 931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( (yyvaluep->expr) ); };

/* Line 480 of lalr1.cc  */
#line 2818 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}

/* Line 565 of lalr1.cc  */
#line 2915 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"

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
#line 1053 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:

/* Line 690 of lalr1.cc  */
#line 1057 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:

/* Line 690 of lalr1.cc  */
#line 1061 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:

/* Line 690 of lalr1.cc  */
#line 1069 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:

/* Line 690 of lalr1.cc  */
#line 1075 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:

/* Line 690 of lalr1.cc  */
#line 1079 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:

/* Line 690 of lalr1.cc  */
#line 1088 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:

/* Line 690 of lalr1.cc  */
#line 1094 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:

/* Line 690 of lalr1.cc  */
#line 1102 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:

/* Line 690 of lalr1.cc  */
#line 1108 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:

/* Line 690 of lalr1.cc  */
#line 1119 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:

/* Line 690 of lalr1.cc  */
#line 1124 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:

/* Line 690 of lalr1.cc  */
#line 1132 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 16:

/* Line 690 of lalr1.cc  */
#line 1139 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 17:

/* Line 690 of lalr1.cc  */
#line 1146 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 18:

/* Line 690 of lalr1.cc  */
#line 1155 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 19:

/* Line 690 of lalr1.cc  */
#line 1162 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 20:

/* Line 690 of lalr1.cc  */
#line 1170 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 21:

/* Line 690 of lalr1.cc  */
#line 1178 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 22:

/* Line 690 of lalr1.cc  */
#line 1186 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 23:

/* Line 690 of lalr1.cc  */
#line 1197 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 24:

/* Line 690 of lalr1.cc  */
#line 1202 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 25:

/* Line 690 of lalr1.cc  */
#line 1209 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 26:

/* Line 690 of lalr1.cc  */
#line 1216 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 27:

/* Line 690 of lalr1.cc  */
#line 1228 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 28:

/* Line 690 of lalr1.cc  */
#line 1238 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 29:

/* Line 690 of lalr1.cc  */
#line 1245 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 30:

/* Line 690 of lalr1.cc  */
#line 1252 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1287 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 45:

/* Line 690 of lalr1.cc  */
#line 1292 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 46:

/* Line 690 of lalr1.cc  */
#line 1300 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 47:

/* Line 690 of lalr1.cc  */
#line 1308 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 48:

/* Line 690 of lalr1.cc  */
#line 1316 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 49:

/* Line 690 of lalr1.cc  */
#line 1321 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 50:

/* Line 690 of lalr1.cc  */
#line 1329 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 51:

/* Line 690 of lalr1.cc  */
#line 1334 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 52:

/* Line 690 of lalr1.cc  */
#line 1342 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 53:

/* Line 690 of lalr1.cc  */
#line 1347 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 54:

/* Line 690 of lalr1.cc  */
#line 1355 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 55:

/* Line 690 of lalr1.cc  */
#line 1360 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 56:

/* Line 690 of lalr1.cc  */
#line 1365 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 57:

/* Line 690 of lalr1.cc  */
#line 1370 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 60:

/* Line 690 of lalr1.cc  */
#line 1383 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 61:

/* Line 690 of lalr1.cc  */
#line 1393 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 62:

/* Line 690 of lalr1.cc  */
#line 1398 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 63:

/* Line 690 of lalr1.cc  */
#line 1406 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 64:

/* Line 690 of lalr1.cc  */
#line 1414 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 65:

/* Line 690 of lalr1.cc  */
#line 1425 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 66:

/* Line 690 of lalr1.cc  */
#line 1432 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 67:

/* Line 690 of lalr1.cc  */
#line 1443 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 68:

/* Line 690 of lalr1.cc  */
#line 1448 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 69:

/* Line 690 of lalr1.cc  */
#line 1456 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 70:

/* Line 690 of lalr1.cc  */
#line 1463 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 71:

/* Line 690 of lalr1.cc  */
#line 1470 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 72:

/* Line 690 of lalr1.cc  */
#line 1479 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1492 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 74:

/* Line 690 of lalr1.cc  */
#line 1500 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 75:

/* Line 690 of lalr1.cc  */
#line 1507 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 76:

/* Line 690 of lalr1.cc  */
#line 1517 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 77:

/* Line 690 of lalr1.cc  */
#line 1524 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 78:

/* Line 690 of lalr1.cc  */
#line 1531 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 87:

/* Line 690 of lalr1.cc  */
#line 1554 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 88:

/* Line 690 of lalr1.cc  */
#line 1560 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 89:

/* Line 690 of lalr1.cc  */
#line 1569 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 90:

/* Line 690 of lalr1.cc  */
#line 1576 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 91:

/* Line 690 of lalr1.cc  */
#line 1586 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 92:

/* Line 690 of lalr1.cc  */
#line 1595 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 93:

/* Line 690 of lalr1.cc  */
#line 1596 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 94:

/* Line 690 of lalr1.cc  */
#line 1597 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 95:

/* Line 690 of lalr1.cc  */
#line 1598 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 96:

/* Line 690 of lalr1.cc  */
#line 1599 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 97:

/* Line 690 of lalr1.cc  */
#line 1600 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 98:

/* Line 690 of lalr1.cc  */
#line 1601 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 99:

/* Line 690 of lalr1.cc  */
#line 1602 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 100:

/* Line 690 of lalr1.cc  */
#line 1603 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 101:

/* Line 690 of lalr1.cc  */
#line 1604 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 102:

/* Line 690 of lalr1.cc  */
#line 1610 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 103:

/* Line 690 of lalr1.cc  */
#line 1618 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 104:

/* Line 690 of lalr1.cc  */
#line 1626 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 105:

/* Line 690 of lalr1.cc  */
#line 1634 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 106:

/* Line 690 of lalr1.cc  */
#line 1641 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 107:

/* Line 690 of lalr1.cc  */
#line 1649 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 108:

/* Line 690 of lalr1.cc  */
#line 1656 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 109:

/* Line 690 of lalr1.cc  */
#line 1661 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 110:

/* Line 690 of lalr1.cc  */
#line 1669 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 111:

/* Line 690 of lalr1.cc  */
#line 1677 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1691 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1705 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1722 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 115:

/* Line 690 of lalr1.cc  */
#line 1727 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 116:

/* Line 690 of lalr1.cc  */
#line 1735 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 117:

/* Line 690 of lalr1.cc  */
#line 1743 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 118:

/* Line 690 of lalr1.cc  */
#line 1754 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 119:

/* Line 690 of lalr1.cc  */
#line 1759 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 120:

/* Line 690 of lalr1.cc  */
#line 1768 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 121:

/* Line 690 of lalr1.cc  */
#line 1773 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:

/* Line 690 of lalr1.cc  */
#line 1780 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 123:

/* Line 690 of lalr1.cc  */
#line 1785 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:

/* Line 690 of lalr1.cc  */
#line 1795 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 125:

/* Line 690 of lalr1.cc  */
#line 1800 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 126:

/* Line 690 of lalr1.cc  */
#line 1809 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 127:

/* Line 690 of lalr1.cc  */
#line 1815 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 128:

/* Line 690 of lalr1.cc  */
#line 1828 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 129:

/* Line 690 of lalr1.cc  */
#line 1833 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 130:

/* Line 690 of lalr1.cc  */
#line 1841 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1852 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1867 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1879 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1894 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 135:

/* Line 690 of lalr1.cc  */
#line 1899 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 136:

/* Line 690 of lalr1.cc  */
#line 1904 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 137:

/* Line 690 of lalr1.cc  */
#line 1909 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 138:

/* Line 690 of lalr1.cc  */
#line 1917 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 139:

/* Line 690 of lalr1.cc  */
#line 1924 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 140:

/* Line 690 of lalr1.cc  */
#line 1935 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 141:

/* Line 690 of lalr1.cc  */
#line 1940 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 142:

/* Line 690 of lalr1.cc  */
#line 1950 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1959 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1968 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1977 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 1989 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:

/* Line 690 of lalr1.cc  */
#line 1993 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 148:

/* Line 690 of lalr1.cc  */
#line 1999 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:

/* Line 690 of lalr1.cc  */
#line 2003 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 150:

/* Line 690 of lalr1.cc  */
#line 2013 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2023 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2036 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 153:

/* Line 690 of lalr1.cc  */
#line 2042 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 154:

/* Line 690 of lalr1.cc  */
#line 2051 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 155:

/* Line 690 of lalr1.cc  */
#line 2056 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 156:

/* Line 690 of lalr1.cc  */
#line 2063 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 157:

/* Line 690 of lalr1.cc  */
#line 2070 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 158:

/* Line 690 of lalr1.cc  */
#line 2082 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2092 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2102 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2113 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2129 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2149 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 164:

/* Line 690 of lalr1.cc  */
#line 2153 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:

/* Line 690 of lalr1.cc  */
#line 2157 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 166:

/* Line 690 of lalr1.cc  */
#line 2165 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:

/* Line 690 of lalr1.cc  */
#line 2169 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:

/* Line 690 of lalr1.cc  */
#line 2173 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 169:

/* Line 690 of lalr1.cc  */
#line 2181 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:

/* Line 690 of lalr1.cc  */
#line 2186 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 171:

/* Line 690 of lalr1.cc  */
#line 2198 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 172:

/* Line 690 of lalr1.cc  */
#line 2205 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:

/* Line 690 of lalr1.cc  */
#line 2215 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2247 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:

/* Line 690 of lalr1.cc  */
#line 2252 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 188:

/* Line 690 of lalr1.cc  */
#line 2260 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2277 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:

/* Line 690 of lalr1.cc  */
#line 2285 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 191:

/* Line 690 of lalr1.cc  */
#line 2293 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 192:

/* Line 690 of lalr1.cc  */
#line 2300 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 193:

/* Line 690 of lalr1.cc  */
#line 2307 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:

/* Line 690 of lalr1.cc  */
#line 2318 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2327 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2336 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2345 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2358 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 199:

/* Line 690 of lalr1.cc  */
#line 2366 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 200:

/* Line 690 of lalr1.cc  */
#line 2374 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 201:

/* Line 690 of lalr1.cc  */
#line 2382 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2397 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 203:

/* Line 690 of lalr1.cc  */
#line 2402 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 204:

/* Line 690 of lalr1.cc  */
#line 2410 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2424 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2441 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2466 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 208:

/* Line 690 of lalr1.cc  */
#line 2474 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 209:

/* Line 690 of lalr1.cc  */
#line 2481 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 210:

/* Line 690 of lalr1.cc  */
#line 2492 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 211:

/* Line 690 of lalr1.cc  */
#line 2502 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 212:

/* Line 690 of lalr1.cc  */
#line 2507 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2520 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2567 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2581 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 234:

/* Line 690 of lalr1.cc  */
#line 2589 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 235:

/* Line 690 of lalr1.cc  */
#line 2594 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 236:

/* Line 690 of lalr1.cc  */
#line 2602 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 237:

/* Line 690 of lalr1.cc  */
#line 2607 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 238:

/* Line 690 of lalr1.cc  */
#line 2612 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 239:

/* Line 690 of lalr1.cc  */
#line 2620 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2629 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2641 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2651 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2664 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 252:

/* Line 690 of lalr1.cc  */
#line 2688 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 253:

/* Line 690 of lalr1.cc  */
#line 2695 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 254:

/* Line 690 of lalr1.cc  */
#line 2705 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 255:

/* Line 690 of lalr1.cc  */
#line 2711 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2720 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 257:

/* Line 690 of lalr1.cc  */
#line 2730 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 258:

/* Line 690 of lalr1.cc  */
#line 2737 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 259:

/* Line 690 of lalr1.cc  */
#line 2745 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2757 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2767 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2777 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2787 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2797 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2807 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2817 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2827 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2838 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2847 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2857 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2867 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2883 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 273:

/* Line 690 of lalr1.cc  */
#line 2892 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 274:

/* Line 690 of lalr1.cc  */
#line 2901 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 275:

/* Line 690 of lalr1.cc  */
#line 2909 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 276:

/* Line 690 of lalr1.cc  */
#line 2915 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 277:

/* Line 690 of lalr1.cc  */
#line 2927 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2935 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2945 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2953 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 2965 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 282:

/* Line 690 of lalr1.cc  */
#line 2971 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:

/* Line 690 of lalr1.cc  */
#line 2984 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 285:

/* Line 690 of lalr1.cc  */
#line 2988 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 286:

/* Line 690 of lalr1.cc  */
#line 2996 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 287:

/* Line 690 of lalr1.cc  */
#line 3000 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 289:

/* Line 690 of lalr1.cc  */
#line 3009 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 290:

/* Line 690 of lalr1.cc  */
#line 3013 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 291:

/* Line 690 of lalr1.cc  */
#line 3017 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 292:

/* Line 690 of lalr1.cc  */
#line 3027 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 293:

/* Line 690 of lalr1.cc  */
#line 3035 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 294:

/* Line 690 of lalr1.cc  */
#line 3042 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 295:

/* Line 690 of lalr1.cc  */
#line 3048 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 296:

/* Line 690 of lalr1.cc  */
#line 3058 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 297:

/* Line 690 of lalr1.cc  */
#line 3062 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 298:

/* Line 690 of lalr1.cc  */
#line 3066 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 3074 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 3082 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 3090 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 3102 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 303:

/* Line 690 of lalr1.cc  */
#line 3110 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 304:

/* Line 690 of lalr1.cc  */
#line 3116 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 305:

/* Line 690 of lalr1.cc  */
#line 3126 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 306:

/* Line 690 of lalr1.cc  */
#line 3132 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 307:

/* Line 690 of lalr1.cc  */
#line 3142 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 308:

/* Line 690 of lalr1.cc  */
#line 3146 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 309:

/* Line 690 of lalr1.cc  */
#line 3156 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 310:

/* Line 690 of lalr1.cc  */
#line 3162 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 311:

/* Line 690 of lalr1.cc  */
#line 3168 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 312:

/* Line 690 of lalr1.cc  */
#line 3174 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 3183 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 3192 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 3201 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 3214 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 317:

/* Line 690 of lalr1.cc  */
#line 3218 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 318:

/* Line 690 of lalr1.cc  */
#line 3226 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 319:

/* Line 690 of lalr1.cc  */
#line 3232 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 320:

/* Line 690 of lalr1.cc  */
#line 3242 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 321:

/* Line 690 of lalr1.cc  */
#line 3250 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 3259 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 3272 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 324:

/* Line 690 of lalr1.cc  */
#line 3279 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 325:

/* Line 690 of lalr1.cc  */
#line 3291 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 326:

/* Line 690 of lalr1.cc  */
#line 3295 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 327:

/* Line 690 of lalr1.cc  */
#line 3307 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 328:

/* Line 690 of lalr1.cc  */
#line 3314 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 329:

/* Line 690 of lalr1.cc  */
#line 3320 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 330:

/* Line 690 of lalr1.cc  */
#line 3329 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:

/* Line 690 of lalr1.cc  */
#line 3336 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 332:

/* Line 690 of lalr1.cc  */
#line 3342 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 333:

/* Line 690 of lalr1.cc  */
#line 3353 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:

/* Line 690 of lalr1.cc  */
#line 3360 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 335:

/* Line 690 of lalr1.cc  */
#line 3366 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 336:

/* Line 690 of lalr1.cc  */
#line 3375 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 337:

/* Line 690 of lalr1.cc  */
#line 3384 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:

/* Line 690 of lalr1.cc  */
#line 3391 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 339:

/* Line 690 of lalr1.cc  */
#line 3402 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 340:

/* Line 690 of lalr1.cc  */
#line 3409 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 341:

/* Line 690 of lalr1.cc  */
#line 3421 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:

/* Line 690 of lalr1.cc  */
#line 3427 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:

/* Line 690 of lalr1.cc  */
#line 3439 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:

/* Line 690 of lalr1.cc  */
#line 3445 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:

/* Line 690 of lalr1.cc  */
#line 3456 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 346:

/* Line 690 of lalr1.cc  */
#line 3462 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 347:

/* Line 690 of lalr1.cc  */
#line 3473 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 348:

/* Line 690 of lalr1.cc  */
#line 3479 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 349:

/* Line 690 of lalr1.cc  */
#line 3490 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 350:

/* Line 690 of lalr1.cc  */
#line 3499 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 351:

/* Line 690 of lalr1.cc  */
#line 3503 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 352:

/* Line 690 of lalr1.cc  */
#line 3512 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:

/* Line 690 of lalr1.cc  */
#line 3516 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 354:

/* Line 690 of lalr1.cc  */
#line 3524 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 355:

/* Line 690 of lalr1.cc  */
#line 3528 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 356:

/* Line 690 of lalr1.cc  */
#line 3538 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:

/* Line 690 of lalr1.cc  */
#line 3545 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 358:

/* Line 690 of lalr1.cc  */
#line 3554 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 359:

/* Line 690 of lalr1.cc  */
#line 3563 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 360:

/* Line 690 of lalr1.cc  */
#line 3568 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 361:

/* Line 690 of lalr1.cc  */
#line 3577 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:

/* Line 690 of lalr1.cc  */
#line 3586 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 363:

/* Line 690 of lalr1.cc  */
#line 3595 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 364:

/* Line 690 of lalr1.cc  */
#line 3608 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:

/* Line 690 of lalr1.cc  */
#line 3612 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 366:

/* Line 690 of lalr1.cc  */
#line 3624 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:

/* Line 690 of lalr1.cc  */
#line 3628 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 368:

/* Line 690 of lalr1.cc  */
#line 3635 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 369:

/* Line 690 of lalr1.cc  */
#line 3639 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 370:

/* Line 690 of lalr1.cc  */
#line 3646 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:

/* Line 690 of lalr1.cc  */
#line 3650 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 372:

/* Line 690 of lalr1.cc  */
#line 3659 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 373:

/* Line 690 of lalr1.cc  */
#line 3663 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 374:

/* Line 690 of lalr1.cc  */
#line 3667 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:

/* Line 690 of lalr1.cc  */
#line 3675 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 376:

/* Line 690 of lalr1.cc  */
#line 3679 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 377:

/* Line 690 of lalr1.cc  */
#line 3685 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:

/* Line 690 of lalr1.cc  */
#line 3691 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:

/* Line 690 of lalr1.cc  */
#line 3697 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:

/* Line 690 of lalr1.cc  */
#line 3707 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 381:

/* Line 690 of lalr1.cc  */
#line 3711 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 382:

/* Line 690 of lalr1.cc  */
#line 3715 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 383:

/* Line 690 of lalr1.cc  */
#line 3723 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 384:

/* Line 690 of lalr1.cc  */
#line 3727 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 385:

/* Line 690 of lalr1.cc  */
#line 3733 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:

/* Line 690 of lalr1.cc  */
#line 3743 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:

/* Line 690 of lalr1.cc  */
#line 3747 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:

/* Line 690 of lalr1.cc  */
#line 3757 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:

/* Line 690 of lalr1.cc  */
#line 3761 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:

/* Line 690 of lalr1.cc  */
#line 3771 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:

/* Line 690 of lalr1.cc  */
#line 3775 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:

/* Line 690 of lalr1.cc  */
#line 3785 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:

/* Line 690 of lalr1.cc  */
#line 3789 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 394:

/* Line 690 of lalr1.cc  */
#line 3799 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 395:

/* Line 690 of lalr1.cc  */
#line 3803 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 396:

/* Line 690 of lalr1.cc  */
#line 3812 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:

/* Line 690 of lalr1.cc  */
#line 3816 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 398:

/* Line 690 of lalr1.cc  */
#line 3824 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 399:

/* Line 690 of lalr1.cc  */
#line 3828 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 400:

/* Line 690 of lalr1.cc  */
#line 3832 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 401:

/* Line 690 of lalr1.cc  */
#line 3836 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 402:

/* Line 690 of lalr1.cc  */
#line 3846 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 403:

/* Line 690 of lalr1.cc  */
#line 3850 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:

/* Line 690 of lalr1.cc  */
#line 3854 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:

/* Line 690 of lalr1.cc  */
#line 3861 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 406:

/* Line 690 of lalr1.cc  */
#line 3866 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 407:

/* Line 690 of lalr1.cc  */
#line 3874 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 408:

/* Line 690 of lalr1.cc  */
#line 3878 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 409:

/* Line 690 of lalr1.cc  */
#line 3882 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 410:

/* Line 690 of lalr1.cc  */
#line 3886 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 411:

/* Line 690 of lalr1.cc  */
#line 3890 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 412:

/* Line 690 of lalr1.cc  */
#line 3894 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 413:

/* Line 690 of lalr1.cc  */
#line 3902 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 414:

/* Line 690 of lalr1.cc  */
#line 3906 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 415:

/* Line 690 of lalr1.cc  */
#line 3910 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 416:

/* Line 690 of lalr1.cc  */
#line 3918 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 417:

/* Line 690 of lalr1.cc  */
#line 3922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 418:

/* Line 690 of lalr1.cc  */
#line 3926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 419:

/* Line 690 of lalr1.cc  */
#line 3930 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 420:

/* Line 690 of lalr1.cc  */
#line 3941 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 421:

/* Line 690 of lalr1.cc  */
#line 3947 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 422:

/* Line 690 of lalr1.cc  */
#line 3957 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 423:

/* Line 690 of lalr1.cc  */
#line 3963 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 424:

/* Line 690 of lalr1.cc  */
#line 3973 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 425:

/* Line 690 of lalr1.cc  */
#line 3977 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 426:

/* Line 690 of lalr1.cc  */
#line 3981 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 427:

/* Line 690 of lalr1.cc  */
#line 4019 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 428:

/* Line 690 of lalr1.cc  */
#line 4023 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 429:

/* Line 690 of lalr1.cc  */
#line 4033 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 430:

/* Line 690 of lalr1.cc  */
#line 4043 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 431:

/* Line 690 of lalr1.cc  */
#line 4056 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 432:

/* Line 690 of lalr1.cc  */
#line 4065 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 4075 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 434:

/* Line 690 of lalr1.cc  */
#line 4079 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 435:

/* Line 690 of lalr1.cc  */
#line 4088 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 436:

/* Line 690 of lalr1.cc  */
#line 4092 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 437:

/* Line 690 of lalr1.cc  */
#line 4101 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 438:

/* Line 690 of lalr1.cc  */
#line 4107 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 439:

/* Line 690 of lalr1.cc  */
#line 4115 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 440:

/* Line 690 of lalr1.cc  */
#line 4121 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 441:

/* Line 690 of lalr1.cc  */
#line 4133 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 442:

/* Line 690 of lalr1.cc  */
#line 4139 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 443:

/* Line 690 of lalr1.cc  */
#line 4149 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 444:

/* Line 690 of lalr1.cc  */
#line 4153 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 445:

/* Line 690 of lalr1.cc  */
#line 4157 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 446:

/* Line 690 of lalr1.cc  */
#line 4161 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 447:

/* Line 690 of lalr1.cc  */
#line 4165 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 448:

/* Line 690 of lalr1.cc  */
#line 4171 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 449:

/* Line 690 of lalr1.cc  */
#line 4177 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 450:

/* Line 690 of lalr1.cc  */
#line 4185 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 451:

/* Line 690 of lalr1.cc  */
#line 4189 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 452:

/* Line 690 of lalr1.cc  */
#line 4197 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 453:

/* Line 690 of lalr1.cc  */
#line 4201 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 454:

/* Line 690 of lalr1.cc  */
#line 4212 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 455:

/* Line 690 of lalr1.cc  */
#line 4216 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 456:

/* Line 690 of lalr1.cc  */
#line 4220 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 457:

/* Line 690 of lalr1.cc  */
#line 4226 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 458:

/* Line 690 of lalr1.cc  */
#line 4230 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 459:

/* Line 690 of lalr1.cc  */
#line 4244 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 460:

/* Line 690 of lalr1.cc  */
#line 4248 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 461:

/* Line 690 of lalr1.cc  */
#line 4256 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 462:

/* Line 690 of lalr1.cc  */
#line 4260 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 463:

/* Line 690 of lalr1.cc  */
#line 4270 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 464:

/* Line 690 of lalr1.cc  */
#line 4274 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 465:

/* Line 690 of lalr1.cc  */
#line 4278 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 466:

/* Line 690 of lalr1.cc  */
#line 4282 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 467:

/* Line 690 of lalr1.cc  */
#line 4291 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 468:

/* Line 690 of lalr1.cc  */
#line 4295 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 469:

/* Line 690 of lalr1.cc  */
#line 4299 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 470:

/* Line 690 of lalr1.cc  */
#line 4303 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 471:

/* Line 690 of lalr1.cc  */
#line 4311 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 472:

/* Line 690 of lalr1.cc  */
#line 4317 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 473:

/* Line 690 of lalr1.cc  */
#line 4327 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 474:

/* Line 690 of lalr1.cc  */
#line 4335 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:

/* Line 690 of lalr1.cc  */
#line 4339 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:

/* Line 690 of lalr1.cc  */
#line 4343 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:

/* Line 690 of lalr1.cc  */
#line 4347 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:

/* Line 690 of lalr1.cc  */
#line 4351 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:

/* Line 690 of lalr1.cc  */
#line 4355 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:

/* Line 690 of lalr1.cc  */
#line 4359 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:

/* Line 690 of lalr1.cc  */
#line 4363 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:

/* Line 690 of lalr1.cc  */
#line 4367 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:

/* Line 690 of lalr1.cc  */
#line 4371 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:

/* Line 690 of lalr1.cc  */
#line 4376 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:

/* Line 690 of lalr1.cc  */
#line 4380 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:

/* Line 690 of lalr1.cc  */
#line 4384 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 487:

/* Line 690 of lalr1.cc  */
#line 4388 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 488:

/* Line 690 of lalr1.cc  */
#line 4396 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 489:

/* Line 690 of lalr1.cc  */
#line 4400 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 490:

/* Line 690 of lalr1.cc  */
#line 4408 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 491:

/* Line 690 of lalr1.cc  */
#line 4415 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 492:

/* Line 690 of lalr1.cc  */
#line 4422 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 493:

/* Line 690 of lalr1.cc  */
#line 4433 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 494:

/* Line 690 of lalr1.cc  */
#line 4441 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 495:

/* Line 690 of lalr1.cc  */
#line 4445 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 496:

/* Line 690 of lalr1.cc  */
#line 4453 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 497:

/* Line 690 of lalr1.cc  */
#line 4461 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 498:

/* Line 690 of lalr1.cc  */
#line 4469 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 499:

/* Line 690 of lalr1.cc  */
#line 4523 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 500:

/* Line 690 of lalr1.cc  */
#line 4527 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            ArgList* argList = dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node));

            if (argList->has_placeholder())
            {
                (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)),
                           new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), new Integer(argList->size())),
                           argList,
                           true);
            }
            else
            {
                (yyval.expr) = new FunctionCall(
                    LOC((yyloc)),
                    static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                    argList
                );
            }
        }
    break;

  case 501:

/* Line 690 of lalr1.cc  */
#line 4552 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
            (yyval.node) = al;
        }
    break;

  case 502:

/* Line 690 of lalr1.cc  */
#line 4558 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 503:

/* Line 690 of lalr1.cc  */
#line 4564 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 504:

/* Line 690 of lalr1.cc  */
#line 4570 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 505:

/* Line 690 of lalr1.cc  */
#line 4580 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:

/* Line 690 of lalr1.cc  */
#line 4584 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 507:

/* Line 690 of lalr1.cc  */
#line 4592 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 508:

/* Line 690 of lalr1.cc  */
#line 4596 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 509:

/* Line 690 of lalr1.cc  */
#line 4600 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 510:

/* Line 690 of lalr1.cc  */
#line 4608 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 511:

/* Line 690 of lalr1.cc  */
#line 4618 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 512:

/* Line 690 of lalr1.cc  */
#line 4628 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 513:

/* Line 690 of lalr1.cc  */
#line 4645 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 514:

/* Line 690 of lalr1.cc  */
#line 4662 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 515:

/* Line 690 of lalr1.cc  */
#line 4679 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 516:

/* Line 690 of lalr1.cc  */
#line 4701 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 517:

/* Line 690 of lalr1.cc  */
#line 4707 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 518:

/* Line 690 of lalr1.cc  */
#line 4718 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 519:

/* Line 690 of lalr1.cc  */
#line 4724 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 520:

/* Line 690 of lalr1.cc  */
#line 4735 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 523:

/* Line 690 of lalr1.cc  */
#line 4752 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 524:

/* Line 690 of lalr1.cc  */
#line 4757 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 525:

/* Line 690 of lalr1.cc  */
#line 4766 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 526:

/* Line 690 of lalr1.cc  */
#line 4770 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 527:

/* Line 690 of lalr1.cc  */
#line 4777 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 528:

/* Line 690 of lalr1.cc  */
#line 4783 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 529:

/* Line 690 of lalr1.cc  */
#line 4789 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 530:

/* Line 690 of lalr1.cc  */
#line 4797 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 531:

/* Line 690 of lalr1.cc  */
#line 4809 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 532:

/* Line 690 of lalr1.cc  */
#line 4813 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 533:

/* Line 690 of lalr1.cc  */
#line 4820 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 534:

/* Line 690 of lalr1.cc  */
#line 4826 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 535:

/* Line 690 of lalr1.cc  */
#line 4832 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 536:

/* Line 690 of lalr1.cc  */
#line 4839 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 537:

/* Line 690 of lalr1.cc  */
#line 4850 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 538:

/* Line 690 of lalr1.cc  */
#line 4854 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 539:

/* Line 690 of lalr1.cc  */
#line 4864 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 540:

/* Line 690 of lalr1.cc  */
#line 4868 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 541:

/* Line 690 of lalr1.cc  */
#line 4878 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 542:

/* Line 690 of lalr1.cc  */
#line 4882 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 543:

/* Line 690 of lalr1.cc  */
#line 4886 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 544:

/* Line 690 of lalr1.cc  */
#line 4891 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 545:

/* Line 690 of lalr1.cc  */
#line 4900 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 546:

/* Line 690 of lalr1.cc  */
#line 4906 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 547:

/* Line 690 of lalr1.cc  */
#line 4912 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 548:

/* Line 690 of lalr1.cc  */
#line 4918 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 549:

/* Line 690 of lalr1.cc  */
#line 4926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 550:

/* Line 690 of lalr1.cc  */
#line 4931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 551:

/* Line 690 of lalr1.cc  */
#line 4939 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 552:

/* Line 690 of lalr1.cc  */
#line 4944 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 553:

/* Line 690 of lalr1.cc  */
#line 4952 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 554:

/* Line 690 of lalr1.cc  */
#line 4960 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 555:

/* Line 690 of lalr1.cc  */
#line 4965 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 556:

/* Line 690 of lalr1.cc  */
#line 4970 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 557:

/* Line 690 of lalr1.cc  */
#line 4975 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 558:

/* Line 690 of lalr1.cc  */
#line 4980 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 559:

/* Line 690 of lalr1.cc  */
#line 4985 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 560:

/* Line 690 of lalr1.cc  */
#line 4994 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 561:

/* Line 690 of lalr1.cc  */
#line 5002 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 562:

/* Line 690 of lalr1.cc  */
#line 5006 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 563:

/* Line 690 of lalr1.cc  */
#line 5023 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 564:

/* Line 690 of lalr1.cc  */
#line 5027 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 565:

/* Line 690 of lalr1.cc  */
#line 5035 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 566:

/* Line 690 of lalr1.cc  */
#line 5043 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 567:

/* Line 690 of lalr1.cc  */
#line 5051 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 568:

/* Line 690 of lalr1.cc  */
#line 5055 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 569:

/* Line 690 of lalr1.cc  */
#line 5063 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 570:

/* Line 690 of lalr1.cc  */
#line 5071 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 571:

/* Line 690 of lalr1.cc  */
#line 5075 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 572:

/* Line 690 of lalr1.cc  */
#line 5079 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 573:

/* Line 690 of lalr1.cc  */
#line 5114 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 574:

/* Line 690 of lalr1.cc  */
#line 5120 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 575:

/* Line 690 of lalr1.cc  */
#line 5126 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 576:

/* Line 690 of lalr1.cc  */
#line 5136 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:

/* Line 690 of lalr1.cc  */
#line 5140 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 578:

/* Line 690 of lalr1.cc  */
#line 5144 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 579:

/* Line 690 of lalr1.cc  */
#line 5148 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 580:

/* Line 690 of lalr1.cc  */
#line 5152 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:

/* Line 690 of lalr1.cc  */
#line 5156 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:

/* Line 690 of lalr1.cc  */
#line 5160 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:

/* Line 690 of lalr1.cc  */
#line 5167 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 584:

/* Line 690 of lalr1.cc  */
#line 5173 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 585:

/* Line 690 of lalr1.cc  */
#line 5183 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 586:

/* Line 690 of lalr1.cc  */
#line 5191 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 587:

/* Line 690 of lalr1.cc  */
#line 5199 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:

/* Line 690 of lalr1.cc  */
#line 5203 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:

/* Line 690 of lalr1.cc  */
#line 5207 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:

/* Line 690 of lalr1.cc  */
#line 5211 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:

/* Line 690 of lalr1.cc  */
#line 5215 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:

/* Line 690 of lalr1.cc  */
#line 5219 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:

/* Line 690 of lalr1.cc  */
#line 5223 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 594:

/* Line 690 of lalr1.cc  */
#line 5227 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 595:

/* Line 690 of lalr1.cc  */
#line 5231 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 596:

/* Line 690 of lalr1.cc  */
#line 5239 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 597:

/* Line 690 of lalr1.cc  */
#line 5247 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 598:

/* Line 690 of lalr1.cc  */
#line 5251 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 599:

/* Line 690 of lalr1.cc  */
#line 5255 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 600:

/* Line 690 of lalr1.cc  */
#line 5265 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 601:

/* Line 690 of lalr1.cc  */
#line 5273 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 602:

/* Line 690 of lalr1.cc  */
#line 5281 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 603:

/* Line 690 of lalr1.cc  */
#line 5285 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 604:

/* Line 690 of lalr1.cc  */
#line 5289 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 605:

/* Line 690 of lalr1.cc  */
#line 5297 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 606:

/* Line 690 of lalr1.cc  */
#line 5301 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 607:

/* Line 690 of lalr1.cc  */
#line 5307 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 608:

/* Line 690 of lalr1.cc  */
#line 5313 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 609:

/* Line 690 of lalr1.cc  */
#line 5317 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 610:

/* Line 690 of lalr1.cc  */
#line 5327 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 611:

/* Line 690 of lalr1.cc  */
#line 5335 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 612:

/* Line 690 of lalr1.cc  */
#line 5339 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 613:

/* Line 690 of lalr1.cc  */
#line 5345 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 614:

/* Line 690 of lalr1.cc  */
#line 5354 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 615:

/* Line 690 of lalr1.cc  */
#line 5363 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 616:

/* Line 690 of lalr1.cc  */
#line 5369 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 617:

/* Line 690 of lalr1.cc  */
#line 5375 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 618:

/* Line 690 of lalr1.cc  */
#line 5385 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 619:

/* Line 690 of lalr1.cc  */
#line 5402 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 620:

/* Line 690 of lalr1.cc  */
#line 5409 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 621:

/* Line 690 of lalr1.cc  */
#line 5424 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 622:

/* Line 690 of lalr1.cc  */
#line 5460 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 623:

/* Line 690 of lalr1.cc  */
#line 5464 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 624:

/* Line 690 of lalr1.cc  */
#line 5472 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 625:

/* Line 690 of lalr1.cc  */
#line 5480 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 626:

/* Line 690 of lalr1.cc  */
#line 5492 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 627:

/* Line 690 of lalr1.cc  */
#line 5496 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 628:

/* Line 690 of lalr1.cc  */
#line 5504 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 629:

/* Line 690 of lalr1.cc  */
#line 5512 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 630:

/* Line 690 of lalr1.cc  */
#line 5516 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 631:

/* Line 690 of lalr1.cc  */
#line 5527 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 632:

/* Line 690 of lalr1.cc  */
#line 5544 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 633:

/* Line 690 of lalr1.cc  */
#line 5550 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 634:

/* Line 690 of lalr1.cc  */
#line 5556 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 635:

/* Line 690 of lalr1.cc  */
#line 5566 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 636:

/* Line 690 of lalr1.cc  */
#line 5570 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 637:

/* Line 690 of lalr1.cc  */
#line 5576 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 638:

/* Line 690 of lalr1.cc  */
#line 5582 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 639:

/* Line 690 of lalr1.cc  */
#line 5586 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 640:

/* Line 690 of lalr1.cc  */
#line 5592 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 641:

/* Line 690 of lalr1.cc  */
#line 5596 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 642:

/* Line 690 of lalr1.cc  */
#line 5602 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 643:

/* Line 690 of lalr1.cc  */
#line 5608 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 644:

/* Line 690 of lalr1.cc  */
#line 5615 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 645:

/* Line 690 of lalr1.cc  */
#line 5625 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 646:

/* Line 690 of lalr1.cc  */
#line 5630 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 647:

/* Line 690 of lalr1.cc  */
#line 5638 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 648:

/* Line 690 of lalr1.cc  */
#line 5644 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 649:

/* Line 690 of lalr1.cc  */
#line 5654 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 650:

/* Line 690 of lalr1.cc  */
#line 5676 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 651:

/* Line 690 of lalr1.cc  */
#line 5685 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 652:

/* Line 690 of lalr1.cc  */
#line 5691 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 653:

/* Line 690 of lalr1.cc  */
#line 5704 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 654:

/* Line 690 of lalr1.cc  */
#line 5718 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 655:

/* Line 690 of lalr1.cc  */
#line 5725 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 656:

/* Line 690 of lalr1.cc  */
#line 5731 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 657:

/* Line 690 of lalr1.cc  */
#line 5741 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 658:

/* Line 690 of lalr1.cc  */
#line 5750 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 659:

/* Line 690 of lalr1.cc  */
#line 5758 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 660:

/* Line 690 of lalr1.cc  */
#line 5764 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 661:

/* Line 690 of lalr1.cc  */
#line 5782 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 662:

/* Line 690 of lalr1.cc  */
#line 5790 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 663:

/* Line 690 of lalr1.cc  */
#line 5794 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 664:

/* Line 690 of lalr1.cc  */
#line 5801 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 665:

/* Line 690 of lalr1.cc  */
#line 5806 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 666:

/* Line 690 of lalr1.cc  */
#line 5814 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:

/* Line 690 of lalr1.cc  */
#line 5818 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 668:

/* Line 690 of lalr1.cc  */
#line 5825 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:

/* Line 690 of lalr1.cc  */
#line 5829 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 670:

/* Line 690 of lalr1.cc  */
#line 5836 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 671:

/* Line 690 of lalr1.cc  */
#line 5840 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 672:

/* Line 690 of lalr1.cc  */
#line 5847 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 673:

/* Line 690 of lalr1.cc  */
#line 5851 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 674:

/* Line 690 of lalr1.cc  */
#line 5860 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 675:

/* Line 690 of lalr1.cc  */
#line 5872 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 676:

/* Line 690 of lalr1.cc  */
#line 5876 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:

/* Line 690 of lalr1.cc  */
#line 5883 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 678:

/* Line 690 of lalr1.cc  */
#line 5887 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:

/* Line 690 of lalr1.cc  */
#line 5895 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 680:

/* Line 690 of lalr1.cc  */
#line 5903 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 681:

/* Line 690 of lalr1.cc  */
#line 5911 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 682:

/* Line 690 of lalr1.cc  */
#line 5915 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 683:

/* Line 690 of lalr1.cc  */
#line 5922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 684:

/* Line 690 of lalr1.cc  */
#line 5926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:

/* Line 690 of lalr1.cc  */
#line 5934 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 686:

/* Line 690 of lalr1.cc  */
#line 5945 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 687:

/* Line 690 of lalr1.cc  */
#line 5949 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:

/* Line 690 of lalr1.cc  */
#line 5957 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 689:

/* Line 690 of lalr1.cc  */
#line 5969 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 690:

/* Line 690 of lalr1.cc  */
#line 5975 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 691:

/* Line 690 of lalr1.cc  */
#line 5984 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 692:

/* Line 690 of lalr1.cc  */
#line 5988 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:

/* Line 690 of lalr1.cc  */
#line 5996 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 694:

/* Line 690 of lalr1.cc  */
#line 6000 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 695:

/* Line 690 of lalr1.cc  */
#line 6004 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 696:

/* Line 690 of lalr1.cc  */
#line 6011 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 697:

/* Line 690 of lalr1.cc  */
#line 6015 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 698:

/* Line 690 of lalr1.cc  */
#line 6022 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 699:

/* Line 690 of lalr1.cc  */
#line 6026 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 700:

/* Line 690 of lalr1.cc  */
#line 6034 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:

/* Line 690 of lalr1.cc  */
#line 6038 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:

/* Line 690 of lalr1.cc  */
#line 6042 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:

/* Line 690 of lalr1.cc  */
#line 6046 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:

/* Line 690 of lalr1.cc  */
#line 6050 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:

/* Line 690 of lalr1.cc  */
#line 6058 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 706:

/* Line 690 of lalr1.cc  */
#line 6066 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 707:

/* Line 690 of lalr1.cc  */
#line 6078 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 708:

/* Line 690 of lalr1.cc  */
#line 6090 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 709:

/* Line 690 of lalr1.cc  */
#line 6094 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 710:

/* Line 690 of lalr1.cc  */
#line 6098 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 711:

/* Line 690 of lalr1.cc  */
#line 6106 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 712:

/* Line 690 of lalr1.cc  */
#line 6112 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 713:

/* Line 690 of lalr1.cc  */
#line 6122 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:

/* Line 690 of lalr1.cc  */
#line 6126 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:

/* Line 690 of lalr1.cc  */
#line 6130 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:

/* Line 690 of lalr1.cc  */
#line 6134 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:

/* Line 690 of lalr1.cc  */
#line 6138 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:

/* Line 690 of lalr1.cc  */
#line 6142 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 719:

/* Line 690 of lalr1.cc  */
#line 6146 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 720:

/* Line 690 of lalr1.cc  */
#line 6150 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 721:

/* Line 690 of lalr1.cc  */
#line 6158 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 722:

/* Line 690 of lalr1.cc  */
#line 6162 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 723:

/* Line 690 of lalr1.cc  */
#line 6166 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 724:

/* Line 690 of lalr1.cc  */
#line 6170 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 725:

/* Line 690 of lalr1.cc  */
#line 6178 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 726:

/* Line 690 of lalr1.cc  */
#line 6184 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 727:

/* Line 690 of lalr1.cc  */
#line 6194 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 728:

/* Line 690 of lalr1.cc  */
#line 6204 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 729:

/* Line 690 of lalr1.cc  */
#line 6208 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 730:

/* Line 690 of lalr1.cc  */
#line 6216 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 731:

/* Line 690 of lalr1.cc  */
#line 6226 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 732:

/* Line 690 of lalr1.cc  */
#line 6237 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 733:

/* Line 690 of lalr1.cc  */
#line 6244 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 734:

/* Line 690 of lalr1.cc  */
#line 6248 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 735:

/* Line 690 of lalr1.cc  */
#line 6255 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 736:

/* Line 690 of lalr1.cc  */
#line 6259 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 737:

/* Line 690 of lalr1.cc  */
#line 6266 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 738:

/* Line 690 of lalr1.cc  */
#line 6271 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 739:

/* Line 690 of lalr1.cc  */
#line 6280 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 740:

/* Line 690 of lalr1.cc  */
#line 6289 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 741:

/* Line 690 of lalr1.cc  */
#line 6293 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 742:

/* Line 690 of lalr1.cc  */
#line 6300 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 743:

/* Line 690 of lalr1.cc  */
#line 6304 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 744:

/* Line 690 of lalr1.cc  */
#line 6312 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 745:

/* Line 690 of lalr1.cc  */
#line 6321 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 746:

/* Line 690 of lalr1.cc  */
#line 6328 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 747:

/* Line 690 of lalr1.cc  */
#line 6338 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 748:

/* Line 690 of lalr1.cc  */
#line 6342 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 749:

/* Line 690 of lalr1.cc  */
#line 6349 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 750:

/* Line 690 of lalr1.cc  */
#line 6355 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 751:

/* Line 690 of lalr1.cc  */
#line 6364 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 752:

/* Line 690 of lalr1.cc  */
#line 6368 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 753:

/* Line 690 of lalr1.cc  */
#line 6375 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 754:

/* Line 690 of lalr1.cc  */
#line 6380 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 755:

/* Line 690 of lalr1.cc  */
#line 6392 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 756:

/* Line 690 of lalr1.cc  */
#line 6400 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 757:

/* Line 690 of lalr1.cc  */
#line 6412 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 758:

/* Line 690 of lalr1.cc  */
#line 6420 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 759:

/* Line 690 of lalr1.cc  */
#line 6424 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 760:

/* Line 690 of lalr1.cc  */
#line 6432 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 761:

/* Line 690 of lalr1.cc  */
#line 6436 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 762:

/* Line 690 of lalr1.cc  */
#line 6440 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 763:

/* Line 690 of lalr1.cc  */
#line 6448 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 764:

/* Line 690 of lalr1.cc  */
#line 6456 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 765:

/* Line 690 of lalr1.cc  */
#line 6460 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 766:

/* Line 690 of lalr1.cc  */
#line 6464 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 767:

/* Line 690 of lalr1.cc  */
#line 6468 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 768:

/* Line 690 of lalr1.cc  */
#line 6476 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 769:

/* Line 690 of lalr1.cc  */
#line 6484 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 770:

/* Line 690 of lalr1.cc  */
#line 6496 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 771:

/* Line 690 of lalr1.cc  */
#line 6500 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 772:

/* Line 690 of lalr1.cc  */
#line 6508 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 773:

/* Line 690 of lalr1.cc  */
#line 6522 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 774:

/* Line 690 of lalr1.cc  */
#line 6526 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 775:

/* Line 690 of lalr1.cc  */
#line 6533 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 776:

/* Line 690 of lalr1.cc  */
#line 6538 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 777:

/* Line 690 of lalr1.cc  */
#line 6546 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 778:

/* Line 690 of lalr1.cc  */
#line 6551 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 779:

/* Line 690 of lalr1.cc  */
#line 6560 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 780:

/* Line 690 of lalr1.cc  */
#line 6568 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 781:

/* Line 690 of lalr1.cc  */
#line 6574 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 782:

/* Line 690 of lalr1.cc  */
#line 6584 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 783:

/* Line 690 of lalr1.cc  */
#line 6590 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 784:

/* Line 690 of lalr1.cc  */
#line 6600 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 785:

/* Line 690 of lalr1.cc  */
#line 6607 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 786:

/* Line 690 of lalr1.cc  */
#line 6614 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
#line 6639 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 788:

/* Line 690 of lalr1.cc  */
#line 6667 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 789:

/* Line 690 of lalr1.cc  */
#line 6695 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 790:

/* Line 690 of lalr1.cc  */
#line 6699 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 791:

/* Line 690 of lalr1.cc  */
#line 6703 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 792:

/* Line 690 of lalr1.cc  */
#line 6710 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 793:

/* Line 690 of lalr1.cc  */
#line 6717 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 794:

/* Line 690 of lalr1.cc  */
#line 6724 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 797:

/* Line 690 of lalr1.cc  */
#line 6741 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 799:

/* Line 690 of lalr1.cc  */
#line 6754 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 800:

/* Line 690 of lalr1.cc  */
#line 6755 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 801:

/* Line 690 of lalr1.cc  */
#line 6756 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 802:

/* Line 690 of lalr1.cc  */
#line 6757 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 803:

/* Line 690 of lalr1.cc  */
#line 6758 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 804:

/* Line 690 of lalr1.cc  */
#line 6759 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 805:

/* Line 690 of lalr1.cc  */
#line 6760 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 806:

/* Line 690 of lalr1.cc  */
#line 6761 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 807:

/* Line 690 of lalr1.cc  */
#line 6762 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 808:

/* Line 690 of lalr1.cc  */
#line 6763 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 809:

/* Line 690 of lalr1.cc  */
#line 6764 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 810:

/* Line 690 of lalr1.cc  */
#line 6765 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 811:

/* Line 690 of lalr1.cc  */
#line 6766 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 812:

/* Line 690 of lalr1.cc  */
#line 6767 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 813:

/* Line 690 of lalr1.cc  */
#line 6768 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 815:

/* Line 690 of lalr1.cc  */
#line 6773 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 816:

/* Line 690 of lalr1.cc  */
#line 6774 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 817:

/* Line 690 of lalr1.cc  */
#line 6775 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 818:

/* Line 690 of lalr1.cc  */
#line 6776 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 819:

/* Line 690 of lalr1.cc  */
#line 6777 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 820:

/* Line 690 of lalr1.cc  */
#line 6778 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 821:

/* Line 690 of lalr1.cc  */
#line 6779 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 822:

/* Line 690 of lalr1.cc  */
#line 6780 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 823:

/* Line 690 of lalr1.cc  */
#line 6781 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 824:

/* Line 690 of lalr1.cc  */
#line 6782 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 825:

/* Line 690 of lalr1.cc  */
#line 6783 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 826:

/* Line 690 of lalr1.cc  */
#line 6784 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 827:

/* Line 690 of lalr1.cc  */
#line 6785 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 828:

/* Line 690 of lalr1.cc  */
#line 6786 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 829:

/* Line 690 of lalr1.cc  */
#line 6787 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 830:

/* Line 690 of lalr1.cc  */
#line 6788 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 831:

/* Line 690 of lalr1.cc  */
#line 6789 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 832:

/* Line 690 of lalr1.cc  */
#line 6790 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 833:

/* Line 690 of lalr1.cc  */
#line 6791 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 834:

/* Line 690 of lalr1.cc  */
#line 6792 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 835:

/* Line 690 of lalr1.cc  */
#line 6793 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 836:

/* Line 690 of lalr1.cc  */
#line 6794 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 837:

/* Line 690 of lalr1.cc  */
#line 6795 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 838:

/* Line 690 of lalr1.cc  */
#line 6796 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 839:

/* Line 690 of lalr1.cc  */
#line 6797 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 840:

/* Line 690 of lalr1.cc  */
#line 6798 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 841:

/* Line 690 of lalr1.cc  */
#line 6799 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 842:

/* Line 690 of lalr1.cc  */
#line 6800 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 843:

/* Line 690 of lalr1.cc  */
#line 6801 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 844:

/* Line 690 of lalr1.cc  */
#line 6802 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 845:

/* Line 690 of lalr1.cc  */
#line 6803 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 846:

/* Line 690 of lalr1.cc  */
#line 6804 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 847:

/* Line 690 of lalr1.cc  */
#line 6805 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 848:

/* Line 690 of lalr1.cc  */
#line 6806 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 849:

/* Line 690 of lalr1.cc  */
#line 6807 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 850:

/* Line 690 of lalr1.cc  */
#line 6808 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 851:

/* Line 690 of lalr1.cc  */
#line 6809 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 852:

/* Line 690 of lalr1.cc  */
#line 6810 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 853:

/* Line 690 of lalr1.cc  */
#line 6811 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 854:

/* Line 690 of lalr1.cc  */
#line 6812 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 855:

/* Line 690 of lalr1.cc  */
#line 6813 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 856:

/* Line 690 of lalr1.cc  */
#line 6814 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 857:

/* Line 690 of lalr1.cc  */
#line 6815 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 858:

/* Line 690 of lalr1.cc  */
#line 6816 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 859:

/* Line 690 of lalr1.cc  */
#line 6817 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 860:

/* Line 690 of lalr1.cc  */
#line 6818 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 861:

/* Line 690 of lalr1.cc  */
#line 6819 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 862:

/* Line 690 of lalr1.cc  */
#line 6820 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 863:

/* Line 690 of lalr1.cc  */
#line 6821 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 864:

/* Line 690 of lalr1.cc  */
#line 6822 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 865:

/* Line 690 of lalr1.cc  */
#line 6823 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 866:

/* Line 690 of lalr1.cc  */
#line 6824 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 867:

/* Line 690 of lalr1.cc  */
#line 6825 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 868:

/* Line 690 of lalr1.cc  */
#line 6826 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 869:

/* Line 690 of lalr1.cc  */
#line 6827 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 870:

/* Line 690 of lalr1.cc  */
#line 6828 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 871:

/* Line 690 of lalr1.cc  */
#line 6829 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 872:

/* Line 690 of lalr1.cc  */
#line 6830 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 873:

/* Line 690 of lalr1.cc  */
#line 6831 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 874:

/* Line 690 of lalr1.cc  */
#line 6832 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 875:

/* Line 690 of lalr1.cc  */
#line 6833 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 876:

/* Line 690 of lalr1.cc  */
#line 6834 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 877:

/* Line 690 of lalr1.cc  */
#line 6835 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 878:

/* Line 690 of lalr1.cc  */
#line 6836 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 879:

/* Line 690 of lalr1.cc  */
#line 6837 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 880:

/* Line 690 of lalr1.cc  */
#line 6838 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 881:

/* Line 690 of lalr1.cc  */
#line 6839 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 882:

/* Line 690 of lalr1.cc  */
#line 6840 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 883:

/* Line 690 of lalr1.cc  */
#line 6841 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 884:

/* Line 690 of lalr1.cc  */
#line 6842 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 885:

/* Line 690 of lalr1.cc  */
#line 6843 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 886:

/* Line 690 of lalr1.cc  */
#line 6844 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 887:

/* Line 690 of lalr1.cc  */
#line 6845 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 888:

/* Line 690 of lalr1.cc  */
#line 6846 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 889:

/* Line 690 of lalr1.cc  */
#line 6847 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 890:

/* Line 690 of lalr1.cc  */
#line 6848 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 891:

/* Line 690 of lalr1.cc  */
#line 6849 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 892:

/* Line 690 of lalr1.cc  */
#line 6850 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 893:

/* Line 690 of lalr1.cc  */
#line 6851 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 894:

/* Line 690 of lalr1.cc  */
#line 6852 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 895:

/* Line 690 of lalr1.cc  */
#line 6853 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 896:

/* Line 690 of lalr1.cc  */
#line 6854 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 897:

/* Line 690 of lalr1.cc  */
#line 6855 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 898:

/* Line 690 of lalr1.cc  */
#line 6856 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 899:

/* Line 690 of lalr1.cc  */
#line 6857 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 900:

/* Line 690 of lalr1.cc  */
#line 6858 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 901:

/* Line 690 of lalr1.cc  */
#line 6859 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 902:

/* Line 690 of lalr1.cc  */
#line 6860 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 903:

/* Line 690 of lalr1.cc  */
#line 6861 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 904:

/* Line 690 of lalr1.cc  */
#line 6862 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 905:

/* Line 690 of lalr1.cc  */
#line 6863 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 906:

/* Line 690 of lalr1.cc  */
#line 6864 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 907:

/* Line 690 of lalr1.cc  */
#line 6865 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 908:

/* Line 690 of lalr1.cc  */
#line 6866 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 909:

/* Line 690 of lalr1.cc  */
#line 6867 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 910:

/* Line 690 of lalr1.cc  */
#line 6868 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 911:

/* Line 690 of lalr1.cc  */
#line 6869 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 912:

/* Line 690 of lalr1.cc  */
#line 6870 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 913:

/* Line 690 of lalr1.cc  */
#line 6871 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 914:

/* Line 690 of lalr1.cc  */
#line 6872 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 915:

/* Line 690 of lalr1.cc  */
#line 6873 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 916:

/* Line 690 of lalr1.cc  */
#line 6874 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 917:

/* Line 690 of lalr1.cc  */
#line 6875 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 918:

/* Line 690 of lalr1.cc  */
#line 6876 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 919:

/* Line 690 of lalr1.cc  */
#line 6877 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 920:

/* Line 690 of lalr1.cc  */
#line 6878 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 921:

/* Line 690 of lalr1.cc  */
#line 6879 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 922:

/* Line 690 of lalr1.cc  */
#line 6880 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 923:

/* Line 690 of lalr1.cc  */
#line 6881 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 924:

/* Line 690 of lalr1.cc  */
#line 6882 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 925:

/* Line 690 of lalr1.cc  */
#line 6883 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 926:

/* Line 690 of lalr1.cc  */
#line 6884 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 927:

/* Line 690 of lalr1.cc  */
#line 6885 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 928:

/* Line 690 of lalr1.cc  */
#line 6886 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 929:

/* Line 690 of lalr1.cc  */
#line 6887 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 930:

/* Line 690 of lalr1.cc  */
#line 6888 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 931:

/* Line 690 of lalr1.cc  */
#line 6889 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 932:

/* Line 690 of lalr1.cc  */
#line 6890 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 933:

/* Line 690 of lalr1.cc  */
#line 6891 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 934:

/* Line 690 of lalr1.cc  */
#line 6892 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 935:

/* Line 690 of lalr1.cc  */
#line 6893 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 936:

/* Line 690 of lalr1.cc  */
#line 6894 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 937:

/* Line 690 of lalr1.cc  */
#line 6895 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 938:

/* Line 690 of lalr1.cc  */
#line 6896 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 939:

/* Line 690 of lalr1.cc  */
#line 6897 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 940:

/* Line 690 of lalr1.cc  */
#line 6898 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 941:

/* Line 690 of lalr1.cc  */
#line 6899 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 942:

/* Line 690 of lalr1.cc  */
#line 6900 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 943:

/* Line 690 of lalr1.cc  */
#line 6901 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 944:

/* Line 690 of lalr1.cc  */
#line 6902 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 945:

/* Line 690 of lalr1.cc  */
#line 6903 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 946:

/* Line 690 of lalr1.cc  */
#line 6904 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 947:

/* Line 690 of lalr1.cc  */
#line 6905 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 948:

/* Line 690 of lalr1.cc  */
#line 6906 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 949:

/* Line 690 of lalr1.cc  */
#line 6907 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 950:

/* Line 690 of lalr1.cc  */
#line 6908 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 951:

/* Line 690 of lalr1.cc  */
#line 6909 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 952:

/* Line 690 of lalr1.cc  */
#line 6910 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 953:

/* Line 690 of lalr1.cc  */
#line 6911 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 954:

/* Line 690 of lalr1.cc  */
#line 6912 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 955:

/* Line 690 of lalr1.cc  */
#line 6913 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 956:

/* Line 690 of lalr1.cc  */
#line 6914 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 957:

/* Line 690 of lalr1.cc  */
#line 6915 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 958:

/* Line 690 of lalr1.cc  */
#line 6916 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 959:

/* Line 690 of lalr1.cc  */
#line 6917 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 960:

/* Line 690 of lalr1.cc  */
#line 6918 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 961:

/* Line 690 of lalr1.cc  */
#line 6919 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 962:

/* Line 690 of lalr1.cc  */
#line 6920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 963:

/* Line 690 of lalr1.cc  */
#line 6921 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 964:

/* Line 690 of lalr1.cc  */
#line 6922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 965:

/* Line 690 of lalr1.cc  */
#line 6923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 966:

/* Line 690 of lalr1.cc  */
#line 6924 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 967:

/* Line 690 of lalr1.cc  */
#line 6925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 968:

/* Line 690 of lalr1.cc  */
#line 6926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 969:

/* Line 690 of lalr1.cc  */
#line 6927 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 970:

/* Line 690 of lalr1.cc  */
#line 6928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 971:

/* Line 690 of lalr1.cc  */
#line 6929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 972:

/* Line 690 of lalr1.cc  */
#line 6930 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 973:

/* Line 690 of lalr1.cc  */
#line 6931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 974:

/* Line 690 of lalr1.cc  */
#line 6932 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 975:

/* Line 690 of lalr1.cc  */
#line 6933 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 976:

/* Line 690 of lalr1.cc  */
#line 6934 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 977:

/* Line 690 of lalr1.cc  */
#line 6935 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 978:

/* Line 690 of lalr1.cc  */
#line 6936 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 979:

/* Line 690 of lalr1.cc  */
#line 6937 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 980:

/* Line 690 of lalr1.cc  */
#line 6938 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 981:

/* Line 690 of lalr1.cc  */
#line 6939 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 982:

/* Line 690 of lalr1.cc  */
#line 6940 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 983:

/* Line 690 of lalr1.cc  */
#line 6941 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 984:

/* Line 690 of lalr1.cc  */
#line 6942 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 985:

/* Line 690 of lalr1.cc  */
#line 6943 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 986:

/* Line 690 of lalr1.cc  */
#line 6944 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 987:

/* Line 690 of lalr1.cc  */
#line 6945 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 988:

/* Line 690 of lalr1.cc  */
#line 6946 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 989:

/* Line 690 of lalr1.cc  */
#line 6947 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 990:

/* Line 690 of lalr1.cc  */
#line 6948 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 991:

/* Line 690 of lalr1.cc  */
#line 6949 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 992:

/* Line 690 of lalr1.cc  */
#line 6950 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 993:

/* Line 690 of lalr1.cc  */
#line 6951 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 994:

/* Line 690 of lalr1.cc  */
#line 6952 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 995:

/* Line 690 of lalr1.cc  */
#line 6953 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 996:

/* Line 690 of lalr1.cc  */
#line 6954 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 997:

/* Line 690 of lalr1.cc  */
#line 6955 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 998:

/* Line 690 of lalr1.cc  */
#line 6956 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 999:

/* Line 690 of lalr1.cc  */
#line 6957 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 1000:

/* Line 690 of lalr1.cc  */
#line 6958 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 1001:

/* Line 690 of lalr1.cc  */
#line 6959 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 1002:

/* Line 690 of lalr1.cc  */
#line 6960 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1003:

/* Line 690 of lalr1.cc  */
#line 6961 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1004:

/* Line 690 of lalr1.cc  */
#line 6962 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1005:

/* Line 690 of lalr1.cc  */
#line 6963 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1006:

/* Line 690 of lalr1.cc  */
#line 6964 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1007:

/* Line 690 of lalr1.cc  */
#line 6965 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1008:

/* Line 690 of lalr1.cc  */
#line 6966 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1009:

/* Line 690 of lalr1.cc  */
#line 6967 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1010:

/* Line 690 of lalr1.cc  */
#line 6968 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1011:

/* Line 690 of lalr1.cc  */
#line 6969 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1012:

/* Line 690 of lalr1.cc  */
#line 6970 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1013:

/* Line 690 of lalr1.cc  */
#line 6971 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1014:

/* Line 690 of lalr1.cc  */
#line 6972 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1015:

/* Line 690 of lalr1.cc  */
#line 6973 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1016:

/* Line 690 of lalr1.cc  */
#line 6974 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1017:

/* Line 690 of lalr1.cc  */
#line 6975 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1018:

/* Line 690 of lalr1.cc  */
#line 6976 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1019:

/* Line 690 of lalr1.cc  */
#line 6977 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1020:

/* Line 690 of lalr1.cc  */
#line 6982 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;



/* Line 690 of lalr1.cc  */
#line 12290 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1520;
  const short int
  xquery_parser::yypact_[] =
  {
      4818, -1520, -1520, -1520,  6372,  6372,  6372, -1520, -1520,     2,
      31, -1520,    83,   274, -1520, -1520, -1520,   716, -1520, -1520,
   -1520,   261,   365,   834,  4537,   380,   439,   842, -1520,    -7,
   -1520, -1520, -1520, -1520, -1520, -1520,   836, -1520,   512,   586,
   -1520, -1520, -1520, -1520,    59, -1520,   838, -1520,   595,   613,
   -1520,    18, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520,   342,   509, -1520, -1520,
   -1520, -1520,   783, 12572, -1520, -1520, -1520,   668, -1520, -1520,
   -1520,   723, -1520,   686,   748, -1520, -1520, 16959, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520,   823, -1520, -1520,   871,
     875, -1520, -1520, -1520, -1520, -1520, -1520, -1520,  5442,  8852,
    9162, 16959, -1520, -1520, -1520, -1520, -1520, -1520, -1520,   807,
   -1520, -1520,   880, 13467, -1520, 13770,   886,   893, -1520, -1520,
   -1520,   899, -1520, 11952, -1520, -1520, -1520, -1520, -1520, -1520,
     811, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,    56,
     809, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,   205,
     874,   215, -1520,   -91,   158, -1520, -1520, -1520, -1520, -1520,
   -1520,   909, -1520,   797,   803,   792, -1520, -1520,   889,   894,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520,  9472,  9782, -1520,   735, -1520, -1520, -1520,
   -1520, -1520,  5130,  6682,  1046, -1520,  6992, -1520, -1520,   796,
      99, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520,   102, -1520, -1520, -1520, -1520,
   -1520, -1520,   331, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520,  6372, -1520, -1520, -1520, -1520,    38, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520,   301, -1520,   860, -1520, -1520,
   -1520,   569, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
     884,   961, -1520,   869,   805,   956,   721,   579,   379,   535,
   -1520,  1006,   858,   958,   959, 10712, -1520,   872, -1520, -1520,
     638, -1520, -1520, 12262, -1520,   793, -1520,   910, 12572, -1520,
     910, 12572, -1520, -1520, -1520,   775, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520,   923,   913, -1520,
   -1520, -1520, -1520, -1520,   887, -1520,  6372,   895,   908,   442,
     442,  1041,   726,   758,   727, 17247, 16959,   390,  1031, 16959,
     941,   976,   681, 13467,   782,   851, 16959, 16959,   798,   819,
      58, -1520, -1520, -1520, 13467,  6372,   912,  6372,   173, 11022,
   14655, 16959, -1520,   812,   816, 16959,   977,    60,   948, 11022,
    1102,    78,    69, 16959,   986,   963,  1000, -1520, 11022, 13170,
   16959, 16959, 16959,  6372,   924, 11022, 11022, 16959,  6372,   960,
     962, -1520, -1520, -1520, 11022, 14943,   964, -1520,   969, -1520,
   -1520, -1520, -1520,   970, -1520,   971, -1520, -1520, -1520, -1520,
   -1520,   972, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   16959, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520,   988, 16959, -1520, -1520, -1520,   928,  5752,
     993,   500,   978,   979,   980, 16959,  6372, -1520,   984,   166,
   -1520,   652, -1520,    94,  1097, 11022, -1520, -1520,   123, -1520,
   -1520, -1520,  1116, -1520, -1520, -1520, -1520, 11022,   925, -1520,
    1109, 11022, 11022, 14070,   953, 11022, 11022, 11022, 11022, 14070,
   11022,   911,   916, 16959,   955,   957, 11022, 11022,  5442,   898,
   -1520,    61, -1520,    52, 11022,  6682, -1520, -1520, -1520, -1520,
   -1520,    83,   842,   116,   128,  1145,  7302,  3275,  7612,  3596,
     723, -1520, -1520,   341,   723, -1520, 11022,  4216, -1520,  1032,
     760,    -7,   981,   982,   983,  6372, 11022, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, 11332, 11332, 11332, -1520, 11332,
   11332, -1520, 11332, -1520, 11332, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, 11332, 11332,  1081, 11332, 11332, 11332, 11332, 11332,
   11332, 11332, 11332, 11332, 11332, 11332, 11332,   926,  1060,  1061,
    1062, -1520, -1520, -1520, 11642, 10092, -1520, -1520, 11952, 11952,
   11022,   910, -1520, -1520,   910, -1520,  7922,   910,  1009,  8232,
   -1520, -1520, -1520,   270, -1520,   287, -1520, -1520, -1520, -1520,
   -1520, -1520,  1052,  1054,   380,  1133, -1520, -1520, 17247,  1001,
     617, 16959,  1003,  1004,  1001,  1041,  1040,  1036, -1520, -1520,
   -1520,   224,   927,  1075,   873, 16959,  1028, 11022,  1053, 16959,
   16959, -1520,  1043,   992,  6372, -1520,   994,   969,   586, -1520,
     990,   995,   330, -1520,   322,   409,  1072, -1520,    79, -1520,
   -1520,  1072, 16959,    34, 16959,  1086,   417, -1520,  6372, -1520,
     124, -1520, 13467,  1085,  1138, 13467,  1041,  1088,   419, 16959,
   11022,    -7,   361,   998, -1520,   999,  1002,  1005,   256, -1520,
     599,  1007, -1520,   126,   208,  1034, -1520,  1010,  6372,  6372,
     363, -1520,   441,   464,   607, 11022,   262, -1520, -1520, 11022,
   11022, -1520, 11022, 11022, 11022, -1520, 11022, -1520, 11022, -1520,
   16959,  1097, -1520,    22,   426, -1520, -1520, -1520,   461, -1520,
      15, -1520, -1520,  1035,  1037,  1042,  1044,  1045,   775,   923,
   -1520,   299,   570,   258,   104,  1099,   690,   965,   975,   973,
      -3, -1520,  1059, -1520, -1520,  1015,   214,  5752,   462, 12873,
     898, -1520, -1520, -1520,   974, -1520,   796,   744,  1163,   183,
   -1520, -1520,   137, -1520, -1520, -1520,   146, -1520,    86, -1520,
   -1520, -1520, -1520, -1520,  3906, -1520, -1520, -1520, 16959,  1039,
   11022,  1093, -1520, -1520, -1520,   961, -1520, -1520, -1520, -1520,
   -1520, 11332, -1520, -1520, -1520,    64, -1520,   579,   579,   293,
     379,   379,   379,   379,   535,   535, -1520, -1520, 16095, 16095,
   16959, 16959, -1520, -1520,   465, -1520, -1520,   308, -1520, -1520,
   -1520, -1520,   475, -1520, -1520,   480,   442, -1520, -1520,    35,
      37,   780, -1520,   380, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520,  1001, -1520,  1074, 16383,  1071, 11022,
   -1520, -1520, -1520,  1121,  1041,  1041,  1001, -1520,   878,  1041,
     693, 16959,   660,   692,  1187, -1520, -1520,   932,    80, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
     224,    29,   996,   435, 11022, -1520, 16959,  1125,   921,  1041,
   -1520, -1520, -1520, -1520,  1068, 16959, -1520, 16959, -1520, 16671,
    1095, 16095,  1106, 11022,    -6,  1079,    39,   601,   989, -1520,
   -1520,   781,    34,  1121, 16095,  1110,  1135,  1047,  1048,  1098,
    1041,  1077,  1100,  1139,  1041, 11022,    66, -1520, -1520, -1520,
    1087, -1520, -1520, -1520, -1520,  1120, 11022, 11022,  1101, -1520,
    1134,  1144,  6372, -1520,  1063,  1065,  1092, 16959, -1520, 16959,
   -1520, 11022,  1108,  1064, 11022, -1520,  1131,   226,   233,   236,
    1216, -1520,    24, -1520,   197, -1520, -1520,  1227, -1520,   784,
   11022, 11022, 11022,   785, 11022, 11022, 11022, 11022, 11022, 11022,
   11022, 11022, 11022, 14070,  1140, 11022, 11022, -1520,  8542,   117,
    1012, -1520,   229, -1520, 11022,   148,   381,    86,  7612,  3596,
    7612,  1184, -1520, -1520, 11022,   831,  1157, -1520, 16959,  1158,
   -1520, -1520, 11022,    64,   706,   674, -1520,   985,   291,  1008,
    1011, -1520, -1520,   851, -1520,  1014,   -67,  1111,  1112, 16383,
    1117,  1118,  1119,  1122,  1123, -1520,   691, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
    1132, -1520, -1520, -1520, -1520, 10402, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520,   795, -1520,  1248,   844, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,  1017, -1520,
   -1520,  1253, -1520, -1520, -1520, -1520, -1520,   609,  1255, -1520,
      76, -1520, -1520, -1520,   964,   365,   970,   512,   971,   972,
     874,  1118,  1119,  1122, -1520,   691,   691, 11642,  1019,   987,
   -1520,  1121,    29,  1058,  1104,  6372,  1103,  1105,  1143,  1114,
    1126, 16959, -1520,    65, -1520, 16959, -1520, 11022,  1141, 11022,
    1168, 11022,   227,  1150, 11022,  1151, -1520,  1186,  1189, 11022,
   16959,   915,  1232, -1520, -1520, -1520, -1520, -1520, -1520, 16095,
   -1520,  6372,  1041,  1203, -1520, -1520, -1520,  1041,  1203, -1520,
   11022,  1170,  6372, 16959, -1520, -1520, 11022, 11022,   484, -1520,
      28,   604, -1520, 15231,   791, -1520,   846, -1520,  1136, -1520,
   -1520,  6372,  1127,  1128, -1520, 11022, -1520, -1520, 11022,  1129,
    1134,  1217, -1520,  1191, -1520,   567, -1520, -1520,  1309, -1520,
   -1520,  6372, 16959, -1520,   647, -1520, -1520, -1520,  1142,  1091,
    1096, -1520, -1520, -1520,  1107,  1113, -1520, -1520, -1520,  1222,
   -1520, -1520, -1520, -1520,  1089,   404, 16959,  1147, -1520,  1172,
    1174,  1175,  1181, -1520,   860,   732, 12873,  1012, -1520,  6062,
   12873, -1520, -1520,  1163,   555, -1520, -1520, -1520,  1157, -1520,
    1041, -1520,   885, -1520,   626,  1229, -1520, 11022,   774,  1093,
     479,  1149, -1520,    64,  1094, -1520, -1520,   192, -1520,   565,
     134,  1115,    64,   565, 11332, -1520,    10, -1520, -1520, -1520,
   -1520, -1520, -1520,    64,  1190,  1056,   927,   134, -1520, -1520,
    1055,  1261, -1520, -1520, -1520, 14367,  1156,  1160,  1161,  1164,
    1165,  1166,  1167, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520,  1316,   566,  1321,   566,
    1084,  1249, -1520, -1520,  1188, 16959,  1124, -1520, -1520, 11642,
   -1520,  1177, -1520, -1520, -1520, -1520, -1520, -1520, 11022,  1212,
   -1520, -1520, 11022, -1520,   329, -1520, 11022,  1215, 11022, -1520,
   11022, 16959, 16959, -1520,   779, -1520, 11022, -1520,  1237,  1238,
    1270,  1041,  1203, -1520, 11022,  1183, -1520, -1520, -1520,  1182,
   -1520,   266, 11022,  6372,  1185,   326, -1520, 16959,  1192, 15519,
     313, -1520, 15807,  1193, -1520, -1520,  1196, -1520, -1520, -1520,
   -1520, 11022,   849,  1216, 16959,   699, -1520,  1198,  1216, 16959,
   -1520, -1520, 11022, 11022, 11022, 11022,  1057, 11022, 11022, -1520,
   11022, 11022, 11022, 11022,  8542,   412, -1520, -1520, -1520, -1520,
   -1520,  1229, -1520, -1520, -1520,  1041, 11022, -1520,  1228, -1520,
   -1520, -1520, -1520,  1199, 11332, -1520, -1520, -1520, -1520, -1520,
     560, 11332, 11332,   659, -1520,  1008, -1520,   542, -1520,  1011,
      64,  1219, -1520, -1520,  1137, -1520, -1520, -1520, -1520,  1275,
    1197, -1520,   492, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520,   311,   311, -1520,   566, -1520, -1520,   496, -1520,  1345,
     134,  1279,  1201, 11642,   -35,  1090,  1206, -1520, -1520, 11022,
   -1520, 11022,  1239, -1520, 11022, -1520, -1520, -1520,  1332, -1520,
   -1520,  8542, 11022,  1041, -1520, -1520, -1520, 11022, 11022, -1520,
   -1520, -1520,  8542,  8542,  1295,  6372, 16959,  1204, 16959, 11022,
   16959,  1205,  8542, -1520,   336,    21,  1216, 16959, -1520,  1195,
    1216, -1520, -1520, -1520, -1520, 11022, -1520, -1520, -1520,   248,
     249,   254, 11022, -1520, -1520, -1520,  1287, 11022, -1520,   379,
   11332, 11332,   293,   731, -1520, -1520, -1520, -1520, -1520, -1520,
   11022, -1520, 16095, -1520, 16095,  1300, -1520, -1520, -1520,  1366,
   -1520, -1520, -1520,  1146,  1289, -1520, -1520,  1290, -1520,   742,
   16959,  1282,  1178, 16959, 11642, -1520, -1520, 11022, -1520,  1284,
   -1520, -1520,  1203, -1520, -1520, 16095, -1520, -1520,  1310, 11022,
    1220, -1520,  1311,  8542, -1520, 16959,   574,   553, -1520,  1210,
    1216, -1520,  1213, -1520,  1211,  1134,  1144,   481, -1520,  1287,
     293,   293, 11332,   507, -1520, -1520, 16095, -1520, -1520,  1279,
   11642, -1520,  1229,  1152, 16959,  1294,  1194,  1290, -1520, 16959,
    1230, 16095,  6372, 16095,  1234, -1520, -1520,  1320,   672, -1520,
   -1520, -1520, -1520,  1231,   641, -1520, -1520, -1520,  1218, -1520,
    8542,   850, -1520, -1520,   293, -1520, -1520, -1520, -1520, -1520,
   11022,  1153, 16959,  1306, -1520,  6372,  1240, -1520, -1520,  1241,
   11022, -1520, -1520, -1520, -1520, -1520, -1520, -1520,  1307, -1520,
    1148,  1154, 16959, -1520, -1520, 11022,  8542, 16959,  1155, 11022,
    1159,  1242, 11642, -1520, 11642,  8542, -1520,  1233,  1162, 16959,
    1208,  1312, 16959,  1169, 11642, -1520
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       165,   464,   465,   466,   168,   168,   168,   815,  1020,   120,
     122,   621,   907,   916,   856,   820,   818,   800,   908,   911,
     863,   824,   801,   802,     0,   917,   804,   914,   885,   865,
     840,   860,   861,   912,   909,   859,   806,   915,   807,   808,
     956,   968,   955,   857,   876,   870,   809,   858,   811,   810,
     957,   894,   895,   862,   837,   978,   979,   980,   981,   982,
     983,   984,   985,   986,   987,   988,  1002,  1009,   884,   880,
     871,   851,   799,     0,   879,   887,   896,  1003,   875,   490,
     852,   853,   910,  1004,  1010,   872,   889,     0,   496,   453,
     492,   882,   817,   873,   874,   903,   877,   893,   902,  1008,
    1011,   823,   864,   905,   491,   892,   898,   803,     0,     0,
       0,     0,   399,   890,   901,   906,   904,   883,   869,   958,
     867,   868,  1005,     0,   398,     0,  1006,  1012,   899,   854,
     878,  1007,   431,     0,   463,   900,   881,   888,   897,   891,
     959,   845,   850,   849,   848,   847,   846,   812,   866,     0,
     816,   913,   838,   947,   946,   948,   822,   821,   841,   953,
     805,   945,   950,   951,   942,   844,   886,   944,   954,   952,
     943,   842,   949,   963,   964,   961,   962,   960,   813,   965,
     966,   967,   933,   932,   919,   836,   829,   926,   922,   839,
     835,   934,   935,   825,   826,   819,   828,   931,   930,   927,
     923,   940,   941,   939,   929,   925,   918,   827,   938,   937,
     831,   833,   832,   924,   928,   920,   834,   921,   830,   936,
     989,   990,   991,   992,   993,   994,   970,   971,   969,   975,
     976,   977,   972,   973,   974,   843,   995,   996,   997,   998,
     999,  1000,  1001,     0,     0,  1013,  1014,  1015,  1018,  1017,
    1016,  1019,   165,   165,     0,     2,   165,     9,    11,    23,
       0,    28,    31,    36,    37,    38,    39,    40,    41,    42,
      32,    58,    59,    33,    34,     0,    76,    79,    80,    35,
      81,    82,     0,   118,    83,    84,    85,    86,    18,   162,
     163,   164,   171,   174,   483,   175,     0,   176,   177,   178,
     179,   180,   181,   182,   185,     0,   211,   219,   214,   246,
     252,     0,   244,   245,   221,   215,   184,   216,   183,   217,
     220,   350,   352,   354,   364,   366,   370,   372,   375,   380,
     383,   386,   388,   390,   392,     0,   396,   403,   402,   404,
       0,   422,   405,   427,   430,   432,   435,   437,     0,   442,
     439,     0,   450,   460,   462,   436,   467,   474,   488,   475,
     476,   477,   480,   481,   478,   479,   505,   507,   508,   509,
     506,   554,   555,   556,   557,   558,   559,   459,   595,   587,
     594,   593,   592,   589,   591,   588,   590,   489,   482,   622,
     623,    43,   222,   223,   225,   224,   226,   218,   485,   486,
     487,   484,   228,   231,   227,   229,   230,   461,   798,   814,
     907,   916,   914,   816,     0,   166,   167,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,   275,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   455,   458,   445,     0,     0,   800,   824,   802,   855,
     917,   804,   865,   806,   876,   809,   811,   810,   894,  1002,
    1009,   799,  1003,   853,  1004,  1010,   877,  1008,  1011,   958,
    1005,  1006,  1012,  1007,   959,   953,   945,   951,   942,   842,
     963,   964,   961,   813,   965,  1014,   451,   461,   798,   443,
       0,   192,   444,   447,   800,   801,   802,   806,   807,   808,
     809,   799,   805,   493,     0,   449,   448,   187,     0,     0,
     211,     0,   804,   811,   810,     0,   168,   773,   965,     0,
     219,     0,   494,     0,   521,     0,   454,   796,     0,   797,
     425,   426,     0,   457,   456,   446,   429,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     775,     0,   777,     0,     0,   165,     3,     4,     1,    10,
      12,     0,     0,     0,     0,     6,   165,     0,   165,     0,
       0,   119,   172,     0,     0,   190,     0,     0,   199,     0,
       0,     0,     0,     0,     0,     0,     0,   204,   232,   251,
     247,   253,   248,   250,   249,     0,     0,     0,   415,     0,
       0,   413,     0,   359,     0,   414,   407,   412,   411,   410,
     409,   408,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,   400,   397,     0,     0,   423,   428,     0,     0,
       0,   438,   471,   441,   440,   452,     0,   468,     0,     0,
     561,   563,   567,     0,   124,     0,   795,    47,    44,    45,
      48,    49,     0,     0,     0,     0,    50,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   632,   633,
     634,     0,   103,   142,     0,     0,   112,     0,     0,     0,
       0,   127,     0,     0,     0,   601,     0,     0,     0,   597,
       0,     0,     0,   611,     0,     0,   255,   257,     0,   234,
     235,   254,     0,     0,     0,   134,     0,   138,   168,   625,
       0,    60,     0,    69,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,   602,     0,     0,     0,     0,   323,
       0,     0,   600,     0,     0,     0,   619,     0,     0,     0,
       0,   605,     0,     0,   194,     0,     0,   188,   186,     0,
       0,   779,     0,     0,     0,   493,     0,   774,     0,   495,
     522,   521,   518,     0,     0,   552,   551,   424,     0,   549,
       0,   645,   646,   800,   802,   806,   809,   799,   786,     0,
     596,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   651,     0,   202,   203,     0,     0,     0,     0,     0,
     207,   208,   776,   778,     0,     5,    24,     0,    25,     0,
       7,    29,     0,    15,     8,    30,     0,    19,   907,    77,
      16,    78,    20,   193,     0,   191,   212,   213,     0,     0,
       0,     0,   205,   233,   292,   351,   353,   357,   363,   362,
     361,     0,   358,   355,   356,     0,   367,   374,   373,   371,
     377,   378,   379,   376,   381,   382,   385,   384,     0,     0,
       0,     0,   406,   420,     0,   433,   434,     0,   472,   501,
     469,   503,     0,   624,   499,     0,     0,   121,   123,     0,
       0,     0,   102,     0,    92,    94,    95,    96,    97,    99,
     100,   101,    93,    98,    88,    89,     0,     0,   108,     0,
     104,   106,   107,   114,     0,     0,    87,    46,     0,     0,
       0,     0,     0,     0,     0,   723,   728,     0,     0,   724,
     758,   711,   713,   714,   715,   717,   719,   718,   716,   720,
       0,     0,     0,     0,     0,   111,     0,   144,     0,     0,
     566,   560,   598,   599,     0,     0,   615,     0,   612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     237,     0,   242,   140,     0,     0,   135,     0,     0,     0,
       0,     0,     0,    62,     0,     0,     0,   273,   279,   276,
       0,   604,   603,   610,   618,     0,     0,     0,     0,   565,
       0,     0,     0,   416,     0,     0,     0,     0,   608,     0,
     606,     0,   195,     0,     0,   780,     0,     0,     0,     0,
     521,   519,     0,   510,     0,   497,   498,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   200,     0,     0,
       0,   659,     0,   209,     0,     0,     0,     0,   165,     0,
     165,     0,   173,   243,     0,   307,   303,   305,     0,   293,
     294,   360,     0,     0,     0,     0,   689,   368,   662,   666,
     668,   670,   672,   675,   682,   683,   691,   917,   803,     0,
     812,  1018,  1017,  1016,  1019,   387,   570,   576,   577,   580,
     626,   627,   581,   582,   789,   790,   791,   585,   389,   391,
     394,   586,   393,   421,   473,     0,   470,   500,   125,    56,
      57,    54,    55,   131,   130,     0,    90,     0,     0,   109,
     110,   115,    74,    75,    52,    53,    73,   729,     0,   732,
     759,     0,   722,   721,   726,   725,   757,     0,     0,   734,
       0,   730,   733,   712,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   146,   148,     0,     0,     0,
     113,   116,     0,     0,     0,   168,     0,     0,   619,     0,
       0,     0,   259,     0,   569,     0,   260,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   238,     0,     0,     0,
       0,   286,     0,   283,   288,   241,   141,   136,   139,     0,
     189,     0,     0,    71,    65,    68,    67,     0,    63,   277,
       0,     0,   168,     0,   321,   325,     0,     0,     0,   328,
       0,     0,   334,     0,     0,   341,     0,   345,     0,   418,
     417,   168,     0,     0,   196,     0,   198,   322,     0,     0,
       0,     0,   522,     0,   511,     0,   545,   542,     0,   546,
     547,     0,     0,   541,     0,   516,   544,   543,     0,     0,
       0,   638,   639,   635,     0,     0,   643,   644,   640,   782,
     783,   649,   787,   647,     0,     0,     0,     0,   653,   804,
     811,   810,   965,   201,     0,     0,     0,   654,   655,     0,
       0,   210,   785,    26,     0,    17,    21,    22,   304,   316,
       0,   317,     0,   308,   309,   310,   311,     0,   296,     0,
       0,     0,   673,   686,     0,   365,   369,     0,   705,     0,
       0,     0,     0,     0,     0,   661,   663,   664,   700,   701,
     702,   704,   703,     0,     0,   677,   676,     0,   680,   684,
     698,   696,   695,   688,   692,     0,     0,     0,     0,     0,
       0,     0,     0,   573,   575,   574,   571,   395,   502,   504,
     133,   132,    91,   105,   746,   727,     0,   751,     0,   751,
     740,   735,   147,   149,     0,     0,     0,   117,   145,     0,
      27,     0,   616,   617,   620,   613,   614,   258,     0,     0,
     272,   264,     0,   268,     0,   262,     0,     0,     0,   281,
       0,     0,     0,   240,   284,   287,     0,   137,     0,     0,
      70,     0,    64,   278,     0,     0,   324,   326,   331,     0,
     329,     0,     0,     0,     0,     0,   335,     0,     0,     0,
       0,   342,     0,     0,   346,   419,     0,   609,   607,   197,
     781,     0,     0,   521,     0,     0,   553,     0,   521,     0,
     517,    14,     0,     0,     0,     0,     0,     0,     0,   652,
       0,     0,     0,     0,     0,     0,   656,   660,   320,   318,
     319,   312,   313,   314,   306,     0,     0,   301,     0,   295,
     690,   681,   687,     0,     0,   760,   761,   771,   770,   769,
       0,     0,     0,     0,   762,   667,   768,     0,   665,   669,
       0,     0,   674,   678,     0,   699,   694,   697,   693,     0,
       0,   583,     0,   578,   631,   572,   793,   794,   792,   579,
     747,     0,     0,   745,   752,   753,   749,     0,   744,     0,
     742,     0,     0,     0,     0,     0,     0,   562,   261,     0,
     270,     0,     0,   266,     0,   269,   282,   290,   291,   285,
     239,     0,     0,     0,    66,   280,   568,     0,     0,   332,
     336,   330,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   564,     0,     0,   521,     0,   548,     0,
     521,   636,   637,   641,   642,     0,   648,   788,   650,     0,
       0,     0,     0,   657,   315,   302,   297,     0,   685,   772,
       0,     0,   764,     0,   710,   709,   708,   707,   706,   671,
       0,   763,     0,   628,     0,     0,   756,   755,   754,     0,
     748,   741,   739,     0,   736,   737,   731,   150,   152,   154,
       0,     0,     0,     0,     0,   265,   263,     0,   271,     0,
     206,   349,    72,   327,   333,     0,   347,   343,     0,     0,
       0,   337,     0,     0,   339,     0,   531,   525,   520,     0,
     521,   512,     0,   784,     0,     0,     0,     0,   300,   298,
     766,   765,     0,     0,   629,   584,     0,   750,   743,     0,
       0,   156,   155,     0,     0,     0,     0,   151,   267,     0,
       0,     0,     0,     0,     0,   539,   533,     0,   532,   534,
     540,   537,   527,     0,   526,   528,   538,   514,     0,   513,
       0,     0,   658,   299,   767,   679,   630,   738,   153,   157,
       0,     0,     0,     0,   289,     0,     0,   340,   338,     0,
       0,   524,   535,   536,   523,   529,   530,   515,     0,   158,
       0,     0,     0,   348,   344,     0,     0,     0,     0,     0,
       0,     0,     0,   160,     0,     0,   159,     0,     0,     0,
       0,     0,     0,     0,     0,   161
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1520, -1520,  -217,  -193, -1520,  1173,  1179, -1520,  1180,  -537,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
    -992, -1520, -1520, -1520, -1520,  -218,  -582, -1520,   694,  -549,
   -1520, -1520, -1520, -1520, -1520,   253,   478, -1520, -1520,    12,
    -181,  1020, -1520,   997, -1520, -1520,  -636, -1520,   418, -1520,
     220, -1520,  -250,  -295, -1520,  -570, -1520,    17,    14,    11,
    -224,  -177, -1520,  -865, -1520, -1520,   333, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520,   587,  -100,  1498,
       0, -1520, -1520, -1520, -1520,   424, -1520, -1520,  -304, -1520,
       8, -1520,  1013,  -927,  -723,  -719, -1520, -1520,   667, -1520,
   -1520,   -14,   200, -1520, -1520, -1520,    85, -1519, -1520,   338,
      88, -1520, -1520,    92, -1309, -1520,   919,   187, -1520, -1520,
     186, -1039, -1520, -1520,   185, -1520, -1520, -1247, -1234, -1520,
     181, -1520, -1520,   824,   825, -1520,  -499,   808, -1520, -1520,
    -665,   362,  -638,   359,   360, -1520, -1520, -1520,   549, -1520,
   -1520,  1171, -1520, -1520, -1520, -1520, -1520,  -878,  -311,  -683,
   -1520,   -95, -1520, -1520, -1520, -1520, -1520, -1520, -1520,   -16,
    -815, -1520,  -538,   564,   283, -1520,  -394, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520,   773, -1520, -1009, -1520,   169, -1520,
     656,  -793, -1520, -1520, -1520, -1520, -1520,  -285,  -278, -1222,
    -863, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520,  -738,  -753,  -176,  -870, -1520, -1520, -1520,  -855, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520,  1049,  1050,  -144,   477,
     305, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520, -1520, -1520, -1520,   149, -1520, -1520,   140, -1520,
     142, -1054, -1520, -1520, -1520,   108,   100,   -68,   370, -1520,
   -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520, -1520,
   -1520, -1520,   109, -1520, -1520, -1520,   -61,   366,   510, -1520,
   -1520, -1520, -1520, -1520,   302, -1520, -1520, -1495, -1520, -1520,
   -1520,  -539, -1520,    72, -1520,   -81, -1520, -1520, -1520, -1520,
   -1316, -1520,   121, -1520, -1520, -1520, -1520, -1520,   918, -1520,
   -1520, -1520, -1520, -1520,  -914, -1520, -1520, -1520,  -391,  -372,
     203,  1130, -1520
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   254,   627,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
    1263,   776,   272,   273,   274,   275,   276,   277,   954,   955,
     956,   278,   279,   280,   960,   961,   962,   281,   439,   282,
     283,   703,   284,   441,   442,   443,   458,   766,   767,   285,
    1214,   286,  1687,  1688,   287,   288,   289,   548,   290,   291,
     292,   293,   294,   769,   295,   296,   531,   297,   298,   299,
     300,   301,   302,   637,   303,   304,   860,   861,   305,   306,
     560,   308,   638,   456,  1021,  1022,   309,   639,   310,   641,
     561,   312,   756,   757,  1251,   465,   313,   466,   467,   763,
    1252,  1253,  1254,   642,   643,  1119,  1120,  1537,   644,  1116,
    1117,  1363,  1364,  1365,  1366,   314,   788,   789,   315,  1278,
    1279,  1481,   316,  1281,  1282,   317,   318,  1284,  1285,  1286,
    1287,   319,   320,   321,   322,   901,   323,   324,  1375,   325,
     326,   327,   328,   329,   330,   331,   332,   333,  1159,   334,
     335,   336,   337,   662,   663,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   697,   692,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   932,   365,   366,   367,  1314,   821,
     822,   823,  1718,  1763,  1764,  1757,  1758,  1765,  1759,  1315,
    1316,   368,   369,  1317,   370,   371,   372,   373,   374,   375,
     376,  1016,  1145,  1416,  1146,  1572,  1147,  1160,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   795,  1227,
     387,   388,   389,   390,  1149,  1150,  1151,  1152,   391,   392,
     393,   394,   395,   396,   850,   851,   397,  1347,  1348,  1653,
    1102,  1127,  1385,  1386,  1128,  1129,  1130,  1131,  1132,  1395,
    1562,  1563,  1133,  1398,  1134,  1543,  1135,  1136,  1403,  1404,
    1568,  1566,  1387,  1388,  1389,  1390,  1667,   732,   981,   982,
     983,   984,   985,   986,  1201,  1592,  1684,  1202,  1590,  1682,
     987,  1429,  1587,  1583,  1584,  1585,   988,   989,  1391,  1399,
    1553,  1392,  1549,  1376,   398,   399,   400,   401,   551,   402,
     403,   404,   405,   406,  1153,  1154,  1155,  1156,  1264,   568,
     407,   408,   409
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -856;
  const short int
  xquery_parser::yytable_[] =
  {
       307,   922,   599,   909,   307,   307,   307,   640,   311,   559,
     563,  1280,   311,   311,   311,   416,   416,   416,   415,   415,
     415,   414,   417,   418,   440,   704,   704,  1125,  1072,   686,
     707,   910,   911,   912,   913,  1014,   879,   881,   576,  1015,
    1036,   614,  1268,   617,  1101,   838,   873,   877,   880,   882,
    1491,   846,  1048,   615,  1502,  1532,  1533,   526,   619,   606,
     607,   727,   615,  1148,  1148,  1313,  1062,   622,  1204,  1371,
     773,   777,   742,  1205,   747,  1240,  1174,  1216,   941,   871,
     875,  1564,  1232,  1690,     9,    10,   578,  1178,  1206,  1018,
    1207,   748,  1510,    11,   477,   615,  1685,   785,   706,  1208,
     615,   621,  1148,   615,  1094,   425,  1377,   706,   307,     9,
      10,   463,     9,    10,  1716,  1010,   311,   615,   615,   549,
     421,   422,   415,   423,   424,   615,  1209,   615,  1482,   615,
     425,   825,   428,   425,   588,  1012,  1215,  1728,   615,   426,
     427,  1237,   426,   601,   603,   624,  1077,   615,   897,   615,
     898,   899,  1073,   900,  1304,   902,  1148,   428,   419,   626,
     428,  1012,   429,   903,   904,   429,  1158,   615,   626,  1148,
     738,   478,  1198,  1011,    79,  1012,  1198,   472,   764,  1378,
    1400,  1401,   774,  1169,   874,  1171,  1241,   420,    90,  1199,
    1691,   623,   622,  1199,   430,   431,   432,   430,   431,  1111,
    1170,   626,  1172,  1402,  1717,  1078,  1306,  1307,  1270,   615,
    1773,   810,  1448,   104,  1483,   615,  1107,  1122,   747,  1074,
    1123,  1305,  1654,   589,   626,  1181,  1013,   615,   625,   775,
    1550,   626,  1095,   626,   615,   748,  1200,   615,   772,   479,
     480,   125,  1485,   433,  1777,  1125,  1125,   765,   687,   615,
     615,  1019,   307,   307,  1210,   615,   307,   640,  1234,   621,
     311,   311,  1379,  1380,   311,  1381,   464,   464,  1491,  1407,
     579,  1257,  1692,   626,  1683,  1472,   527,  1303,   970,  1245,
     971,   819,  1383,  1510,  1148,  1256,   879,   881,  1020,   616,
     543,   307,   618,  1242,  1384,  1238,  1313,  1243,   826,   311,
    1308,  -169,   615,   434,  1447,  1313,   866,  1175,  1216,   615,
    1421,  1028,   464,  1050,   564,   626,   623,  1271,   868,  1542,
    1309,   626,  1310,  1124,   972,   622,   569,  1108,   572,   871,
     875,   615,   693,   626,   967,   695,  1110,  1088,  1353,   464,
     626,  -170,   615,   626,   435,   739,  1211,  1212,  1213,   752,
    1311,   817,   464,   740,   111,   626,   626,     9,    10,   770,
     749,   626,   615,  1045,   615,   863,  1482,  1215,   782,  1045,
     436,   123,   862,   436,  1456,   793,   794,   936,   437,   809,
    1741,   437,  1349,   590,   800,  1033,   438,  1377,   591,   438,
    1551,  1552,  1312,  1079,   936,  1051,   867,   869,   872,   876,
    1029,  1098,  1121,  1032,  1148,  1176,   884,  1426,   626,  1545,
     149,   892,   865,  1299,   447,   626,   307,  1176,   421,   422,
    1300,   423,   424,  1301,   311,  1012,  1482,   615,  1148,  1005,
     581,  1628,   582,  1779,   444,  1724,  1725,   626,   427,  1350,
     585,  1726,   586,   620,  1046,   307,  1546,   307,   626,   623,
    1064,   666,  1618,   311,  1715,   311,   744,   937,   744,   743,
    1378,   746,   615,   615,   481,   824,   615,  1428,   626,   667,
     626,    11,   592,   307,   938,   973,  1601,   828,   307,  1771,
     615,   311,   615,  1437,   744,  -169,   311,   791,   974,   744,
     975,  1087,   797,  1164,  1354,  1125,  1313,   856,   858,  1629,
     464,   976,   977,   978,  1125,   979,  1467,   980,   615,  1006,
    1449,  1126,  1623,  1011,  1004,  1125,  1007,  1080,  1081,   583,
     622,   448,  1629,  1457,  1025,  -170,   879,   881,   879,   587,
    1488,  1101,  1082,   626,  1434,  1527,   457,  1491,  1355,  1356,
    1357,   433,  1168,  1379,  1380,  1040,  1381,  1056,  1057,   307,
    1148,   527,    79,  1382,   527,  1335,   307,   311,   690,   716,
     696,  1035,  1306,  1383,   311,  1652,    90,   416,   626,   626,
     415,  1059,   626,  1182,  1183,  1384,  1306,  1307,  1186,  1755,
     673,  1761,  1165,  1306,  1277,   924,   626,  1165,   626,   674,
     927,   104,   717,   925,   926,   459,  1008,  1479,   307,  1674,
     722,   434,   723,  1679,  1026,   307,   311,   810,  1224,   857,
    1075,   629,  1660,   311,   626,   630,   307,   307,   307,   307,
     631,  1702,  1350,   440,   311,   311,   311,   311,  1058,   715,
    1538,   482,   719,   622,  1148,   307,   569,  1148,   632,   733,
     734,  1518,   435,   311,   623,  1076,  1100,   569,  1105,  1163,
    1306,  1060,  1571,   755,   758,  1109,  1306,  1307,   758,   869,
    1112,   725,  1166,  1540,  1083,  1772,   778,  1167,   470,  1761,
    1308,   675,   569,   786,   787,   790,  1309,  1755,  1310,  1675,
     796,  1306,  1125,  1680,   811,   676,  1485,  1762,   803,  1661,
    1309,  1775,  1310,  1011,   629,  1011,   669,  1309,   630,  1310,
     666,  1011,  1581,   631,  1277,  1426,  1311,  1756,  1306,  1307,
    1635,   957,  1067,  1068,  1069,  1639,   858,  1484,   667,  1557,
    1311,   632,  1427,   726,   111,   670,   722,  1311,   723,  1126,
    1126,  1602,  1360,   804,  1218,    11,  1627,   633,   671,  1631,
     634,   123,   471,  1219,   307,   874,  1047,   790,  1244,  1061,
    1308,   475,   311,  1362,   958,   635,  1596,  1099,   815,   959,
     724,   451,  1504,   452,  1309,  1428,  1310,  1582,   307,   476,
    1309,   879,  1310,   672,   629,  1795,   311,  1106,   630,   416,
     149,   636,   415,   631,  1090,  1027,   839,   725,  1084,  1085,
     529,   685,   839,   612,  1311,  1309,   852,  1310,   307,   307,
    1311,   632,  1308,  1086,   111,  1792,   311,   311,   532,   744,
     744,  1664,  1054,  1055,   686,   125,    79,  1148,  1665,  1148,
     633,   123,  1309,   634,  1310,  1311,   453,  1373,  1666,   611,
      90,   454,  1247,  1547,  1247,  1413,  1011,  1248,   818,  1248,
    1548,   530,  1509,  1719,   690,   612,   696,  1722,  1360,   726,
    1148,   125,  1311,  1760,  1766,   104,   111,   307,  1249,  1122,
     149,  1226,  1123,  1229,   636,   311,   460,  1414,  1011,   445,
     533,  1470,   446,   123,  1343,  1012,   461,  1012,   455,   666,
    1535,  1148,   884,   125,   307,  1415,  1662,  1663,   869,   666,
     440,  1489,   311,   712,  1637,  1760,  1148,   667,  1148,  1250,
     633,  1766,   462,   634,  1490,   483,  1659,   667,   708,   713,
    1689,   691,   149,  1292,   694,  1293,  1536,  1173,  1524,  1734,
     668,  1735,   709,  1192,   963,  1351,  1359,  1768,  1664,   690,
    1732,   696,  1420,   768,  1193,  1665,   484,  1360,   993,   485,
     710,   544,   997,   998,   636,  1666,  1492,  1361,   768,  1489,
    1489,  1742,  1750,   883,   711,  1194,   736,   885,  1362,  1493,
     565,   737,  1634,  1798,   577,  1017,  1195,  1023,  1247,  1528,
    1187,  1188,  1189,  1248,   928,   569,  1190,   928,   569,  1126,
     928,   958,  1037,  1776,   688,   689,   959,   449,  1126,   468,
     450,   473,   469,   545,   474,  1730,  1731,   546,  1786,  1126,
    1789,   647,   566,   728,   729,   730,  1184,  1185,   573,   648,
     649,  1689,   650,  1529,  1530,   574,  1319,  1324,  1320,  1325,
     651,   575,  1370,  1070,   652,   580,   653,   593,   907,   908,
     584,   654,   914,   915,   596,   916,   917,  1468,   594,  1432,
    1433,   640,  1676,  1677,   595,   597,   608,   598,   655,   604,
     628,   645,   307,   646,   664,   665,   677,  1689,   678,   679,
     311,   680,   527,   744,   690,   684,  1288,  1774,   698,   699,
     706,   700,   656,   657,   658,   659,   660,   661,   718,   701,
    1614,   944,   945,   946,   947,   948,   949,   950,   951,   952,
     953,  1113,   702,   720,   721,   762,   759,   731,  1344,   745,
     760,   768,   735,   771,   779,   780,  1345,   781,   307,   307,
     307,   792,   807,   798,   809,   799,   311,   311,   311,   440,
     446,  1157,  1157,  1161,  1161,   450,   469,   474,   485,  1816,
     805,  1817,   820,   827,   812,   813,   814,   816,   830,   829,
     840,  1825,   848,   859,  1655,   853,   849,   854,   870,   889,
     888,   905,   890,   891,   919,   920,   921,   918,   933,   939,
    1157,   940,   942,   964,   965,   599,  1126,   968,   969,   991,
     994,   996,   992,   990,  1191,   999,  1000,  1002,  1001,  1009,
    1024,  1030,  1003,  1031,  1034,  1041,  1042,  1052,   445,  1043,
     449,  1049,  1044,  1089,  1053,   468,  1107,   473,   484,  1221,
    1092,  1096,  1091,   528,  1093,  1097,  1177,  1104,  1228,  1114,
    1228,  1118,   758,   959,  1157,  1011,  1196,   528,  1197,  1222,
    1223,  1225,  1233,  1217,  1235,   307,  1239,  1157,   764,  1259,
    1262,  1260,  1266,   311,  1277,  1267,   416,  1265,  1273,   415,
    1272,   528,  1441,  1246,  1283,  1291,  1261,  1289,  1276,  1290,
    1295,  1302,  1298,   528,  1296,   528,  1318,  1346,  1336,  1620,
     796,   307,   796,   724,  1367,  1369,  1393,  1405,  1406,   311,
    1374,  1394,   307,  1408,  1409,  1410,  1417,    11,  1411,  1412,
     311,  1397,  1425,   416,  1430,  1439,   415,  1444,  1452,  1475,
    1442,   307,  1443,  1436,  1440,  1454,   839,  1458,  1460,   311,
     892,  1445,   416,  1424,  1461,   415,  1435,  1462,  1496,  1466,
    1471,   307,  1474,  1446,  1497,  1498,  1506,  1489,  1516,   311,
    1495,  1368,   744,  1503,  1512,  1507,  1517,  1501,  1521,  1513,
    1522,  1523,  1511,  1520,  1349,  1360,  1541,  1560,  1561,  1567,
    1514,  1565,  1157,  1573,  1544,  1580,  1515,  1574,  1575,  1344,
    1586,  1576,  1577,  1578,  1579,  1589,  1591,  1345,  1593,  1599,
     857,  1597,  1604,  1611,  1612,  1554,  1613,  1616,  1617,  1672,
    1657,  1622,  1670,  1645,  1681,  1198,  1694,  1693,  1625,  1632,
    1633,  1595,  1638,  1658,  1673,  1699,  1697,  1700,  1686,  1705,
    1709,  1713,  1721,  1535,  1736,  1737,  1739,  1740,  1704,  1620,
    1744,  1706,  1749,  1745,  1751,  1753,  1752,  1767,  1714,  1770,
    1769,  1738,  1782,  1791,  1794,  1797,  1785,  1671,   966,  1783,
    1790,  1649,  1650,  1651,  1802,  1807,  1805,  1806,  1815,   609,
    1822,  1423,  1818,  1821,   758,   610,  1179,   741,  1450,   613,
     705,  1808,  1438,  1258,  1747,  1778,  1255,  1103,  1039,  1819,
    1609,  1465,  1358,  1464,  1539,  1534,  1531,  1780,  1800,  1809,
    1476,  1812,  1157,   806,  1480,  1814,  1486,  1494,   761,   895,
    1162,   896,   935,   906,  1505,  1824,   790,  1071,   528,  1796,
    1793,   528,  1422,   307,  1230,  1519,  1157,  1526,  1525,  1706,
    1555,   311,  1669,  1559,  1372,  1558,  1668,   750,   751,  1396,
    1203,  1588,  1431,  1678,  1556,   844,   683,     0,     0,     0,
       0,     0,     0,     0,     0,  1508,     0,     0,     0,     0,
       0,     0,     0,     0,  1344,     0,     0,     0,  1787,     0,
       0,     0,  1345,     0,     0,     0,     0,     0,     0,   852,
       0,     0,     0,     0,     0,     0,  1468,     0,     0,   527,
       0,     0,  1727,   527,     0,   714,   528,     0,     0,   528,
       0,  1803,     0,   528,     0,     0,   528,   528,     0,     0,
    1733,     0,     0,     0,   528,     0,     0,     0,     0,     0,
     528,   528,  1803,     0,     0,   528,     0,     0,     0,     0,
       0,  1787,     0,   528,     0,     0,     0,     0,     0,   528,
     528,   528,   528,     0,     0,     0,   550,   528,  1157,     0,
       0,  1344,     0,     0,     0,   528,     0,     0,     0,  1345,
       0,     0,  1344,  1344,     0,   307,     0,     0,     0,     0,
    1345,  1345,  1344,   311,     0,     0,     0,     0,  1594,     0,
    1345,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,  1607,  1608,     0,     0,     0,     0,
       0,     0,     0,     0,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
    1624,     0,  1157,     0,     0,  1157,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1636,     0,     0,
       0,     0,  1640,  1344,     0,     0,     0,     0,     0,     0,
       0,  1345,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   307,     0,     0,     0,     0,     0,     0,     0,
     311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1344,     0,     0,     0,     0,     0,     0,     0,  1345,     0,
       0,     0,     0,     0,     0,   307,     0,     0,     0,     0,
       0,     0,     0,   311,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1344,     0,     0,     0,
       0,     0,     0,     0,  1345,  1344,     0,     0,     0,     0,
       0,     0,     0,  1345,     0,     0,     0,     0,     0,  1708,
       0,  1710,     0,  1712,     0,     0,     0,     0,     0,     0,
    1720,     0,     0,     0,     0,     0,     0,     0,   943,     0,
       0,   528,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,   528,
     528,     0,     0,     0,     0,  1157,     0,  1157,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,  1743,   528,     0,  1746,     0,     0,     0,
       0,     0,   528,     0,     0,   528,     0,     0,  1157,   528,
       0,     0,     0,     0,     0,     0,     0,     0,  1754,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1157,
       0,     0,     0,     0,     0,     0,     0,  1781,     0,     0,
     528,     0,  1784,     0,  1157,     0,  1157,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1801,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1810,     0,     0,     0,     0,
    1811,     0,     0,     0,     0,     0,     0,     0,   528,     0,
       0,     0,  1820,     0,     0,  1823,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,   528,
     528,   528,     0,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   831,
     832,     0,     0,   841,   842,   843,   845,   528,   847,     0,
       0,     0,     0,     0,   855,     0,     0,     0,     0,     0,
       0,   528,   864,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   886,   887,   528,     0,     0,     0,
       0,     0,     0,   893,   894,   528,     0,   528,     0,   528,
       0,   528,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,     0,   528,
       0,     0,     0,     0,   931,     0,     0,   931,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   995,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,  1038,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1063,     0,     0,     0,  1065,  1066,     0,
       0,     0,     0,     0,     0,     0,   893,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,   887,     0,     0,     0,     0,     0,  1115,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1180,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1236,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1269,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,  1274,  1275,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1294,
       0,     0,  1297,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1321,  1322,
    1323,     0,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,
    1334,   528,   528,  1337,  1338,     0,     0,     0,     0,     0,
       0,     0,  1352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1115,     0,     0,     0,     0,   528,     0,   528,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1419,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1451,     0,  1453,     0,  1455,
       0,     0,  1459,     0,     0,     0,     0,  1463,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,   528,  1469,
     528,     0,     0,     0,     0,     0,     0,   528,  1473,     0,
       0,     0,     0,     0,  1477,  1478,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1499,     0,     0,  1500,     0,     0,     0,
       0,     0,   528,     0,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1115,   528,     0,     0,     0,
       0,     0,     0,     0,   528,     0,     0,     0,     0,   528,
       0,   528,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,  1598,     0,     0,   528,
    1600,     0,   528,     0,  1603,     0,  1605,     0,  1606,     0,
       0,     0,     0,     0,  1610,     0,     0,     0,     0,     0,
       0,     0,  1615,     0,     0,     0,     0,     0,     0,     0,
    1619,  1621,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1469,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1641,  1642,  1643,  1644,     0,  1646,  1647,     0,  1648,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1656,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1695,     0,  1696,
       0,     0,  1698,     0,     0,     0,     0,     0,     0,     0,
    1701,     0,     0,     0,     0,  1703,  1621,     0,     0,     0,
       0,     0,     0,  1707,     0,     0,     0,  1711,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1723,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1729,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1748,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1707,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1788,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -165,   874,     0,  1799,     0,
       0,     0,     0,  1804,     0,     0,     1,     2,  1788,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,  1804,    11,     0,     0,  1813,    12,   411,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     413,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,   248,   249,   250,   251,  -165,   874,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   878,
     411,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   412,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   874,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   410,
     411,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   412,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   874,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   410,
     411,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   552,   412,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   553,   554,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   503,    82,
      83,    84,    85,    86,   555,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   556,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,   132,   133,     0,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   520,   521,   522,   176,   177,   523,
     558,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,   248,   249,   250,   251,  -855,   451,     0,
     452,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -855,
       0,     0,     0,  -855,     0,     0,     0,  -855,  -855,     0,
       0,     0,  -855,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   453,     0,     0,  -855,     0,   454,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -855,
       0,  -855,  -855,  -855,     0,     0,  -855,  -855,  -855,  -855,
       0,     0,     0,  -855,  -855,     0,     0,     0,     0,     0,
    -855,     0,     0,  -855,  -855,   455,     0,     0,  -855,     0,
       0,     0,     0,  -855,  -855,     0,     0,     0,     0,  -855,
       0,     0,     0,  -855,     0,     0,     0,  -855,  -855,     0,
    -855,     0,  -855,  -855,     0,     0,     0,  -855,  -855,     0,
       0,  -855,  -855,  -855,  -855,  -855,  -855,     0,     0,  -855,
       0,     0,     0,     0,  -855,  -855,     0,     0,  -855,     0,
       0,     0,     0,  -855,     0,     0,  -855,     0,     0,     0,
       0,  -855,  -855,  -855,  -855,  -855,     0,  -855,  -855,  -855,
    -855,  -855,     0,     0,     0,     0,  -855,  -855,  -855,     0,
    -855,  -855,  -855,  -855,  -855,  -855,     0,  -855,     0,  -855,
       0,     0,     0,     0,  -855,  -855,  -855,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -855,     0,  -855,     0,  -855,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -855,     0,     0,     0,
       0,  -855,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,  -855,     0,
    -855,    12,    13,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,   252,
     253,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,    12,    13,     0,    14,    15,    16,    17,
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
     251,     0,   605,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   412,    28,    29,    30,    31,     0,    32,    33,    34,
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
       0,     0,   126,   127,   128,     0,   547,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
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
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   412,    28,    29,    30,    31,     0,    32,    33,    34,
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
       0,     0,   126,   127,   128,     0,   808,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
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
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    1339,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,  1340,  1341,    50,    51,    52,    53,
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
       0,     0,   126,   127,   128,     0,   547,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,  1342,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   412,    28,    29,    30,    31,     0,    32,    33,    34,
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
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
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
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
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
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
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
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
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
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,    12,   411,     0,    14,    15,
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
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
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
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   878,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,   412,    28,    29,    30,    31,     0,    32,    33,    34,
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
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
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
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     552,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   553,   554,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,   929,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,   930,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     520,   521,   522,   176,   177,   523,   558,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     552,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   553,   554,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,   929,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,   934,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     520,   521,   522,   176,   177,   523,   558,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     9,    10,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    1339,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,  1340,  1341,    50,    51,    52,    53,
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
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,  1342,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     552,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   553,   554,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,   557,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     520,   521,   522,   176,   177,   523,   558,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     552,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   553,   554,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,   562,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     520,   521,   522,   176,   177,   523,   558,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     552,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   553,   554,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     520,   521,   522,   176,   177,   523,   558,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   600,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     552,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   553,   554,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     520,   521,   522,   176,   177,   523,   558,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,   602,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     552,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   553,   554,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,   923,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     520,   521,   522,   176,   177,   523,   558,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     552,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   553,   554,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,  1418,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     520,   521,   522,   176,   177,   523,   558,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   489,    25,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   494,
       0,    45,    46,    47,   496,   497,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     681,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   682,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   160,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   525,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     552,   412,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   553,   554,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     520,   521,   522,   176,   177,   523,   558,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   489,    25,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   494,
       0,    45,    46,    47,   496,   497,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   160,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   525,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   489,    25,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   494,
       0,    45,    46,    47,   496,   497,    50,   498,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,     0,     0,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   160,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   525,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   489,    25,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   494,
       0,    45,    46,    47,   496,   497,    50,   498,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   556,   109,     0,   110,   111,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,     0,     0,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,     0,     0,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   160,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   525,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   410,   411,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,   489,    25,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   494,
       0,    45,    46,    47,   496,   497,    50,   498,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   503,    82,    83,    84,    85,    86,
     555,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,     0,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,     0,   106,   107,   556,   109,     0,   110,   111,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,     0,     0,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,     0,     0,     0,   134,     0,   135,     0,
     136,     0,   138,     0,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   160,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   525,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,     7,     8,     0,     0,
       0,     0,     0,     0,     0,   410,   411,     0,    14,    15,
      16,   486,    18,    19,    20,   487,    22,   488,   489,   490,
     491,   412,    28,   492,    30,    31,     0,    32,    33,    34,
      35,   493,    37,    38,    39,    40,    41,    42,    43,   494,
       0,    45,   495,    47,   496,   497,    50,   498,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   499,   500,    68,     0,    69,    70,    71,   501,
       0,     0,    74,    75,    76,     0,     0,   502,    78,     0,
       0,     0,     0,    80,   503,    82,   504,   505,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   506,    97,    98,
     507,   508,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   509,   120,   121,   510,     0,     0,     0,     0,     0,
       0,     0,   511,   512,   128,     0,     0,     0,   129,     0,
     130,   513,     0,     0,     0,     0,   134,     0,   135,     0,
     136,   137,   138,   139,   514,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,     0,     0,   413,   151,   152,
     153,   154,   155,   156,   157,   158,   515,   160,   516,   162,
     517,   518,   165,   166,   167,   168,   169,   170,   519,   172,
     520,   521,   522,   176,   177,   523,   524,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     1,     2,   245,   525,   247,   248,
     249,   250,   251,     3,     0,     0,     0,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   410,   411,     0,    14,
      15,    16,   534,    18,    19,    20,   487,   535,   536,   489,
     490,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   537,    37,   538,   539,    40,    41,    42,    43,
     494,     0,    45,   540,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     541,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,   134,     0,   135,
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
     240,   241,   242,     0,     0,     0,   567,   245,   525,   247,
     248,   249,   250,   251,     7,     8,     0,     0,     0,   783,
       0,     0,     0,   410,   411,     0,    14,    15,    16,   534,
      18,    19,    20,   487,   535,   536,   489,   490,   491,   412,
      28,   492,    30,    31,     0,    32,    33,    34,    35,   537,
      37,   538,   539,    40,    41,    42,    43,   494,     0,    45,
     540,    47,   496,   497,    50,   498,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     499,   500,    68,     0,    69,    70,    71,   541,     0,     0,
      74,    75,    76,     0,     0,   502,    78,     0,     0,     0,
       0,    80,   503,    82,   504,   505,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   506,    97,    98,   507,   508,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   509,
     120,   121,   510,     0,     0,     0,     0,     0,     0,     0,
     511,   512,   128,     0,     0,     0,   129,   784,   130,   513,
       0,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   514,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   413,   151,   152,   153,   154,
     155,   156,   157,   158,   515,   542,   516,   162,   517,   518,
     165,   166,   167,   168,   169,   170,   519,   172,   520,   521,
     522,   176,   177,   523,   524,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     0,   567,   245,   525,   247,   248,   249,   250,
     251,     7,     8,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   129,     0,   130,   513,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   514,
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
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,   245,   525,   247,   248,   249,   250,   251,   570,   571,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
       0,     0,     0,   410,   411,     0,    14,    15,    16,   534,
      18,    19,    20,   487,   535,   536,   489,   490,   491,   412,
      28,   492,    30,    31,     0,    32,    33,    34,    35,   537,
      37,   538,   539,    40,    41,    42,    43,   494,     0,    45,
     540,    47,   496,   497,    50,   498,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     499,   500,    68,     0,    69,    70,    71,   541,     0,     0,
      74,    75,    76,     0,     0,   502,    78,     0,     0,     0,
       0,    80,   503,    82,   504,   505,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   506,    97,    98,   507,   508,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   509,
     120,   121,   510,     0,     0,     0,     0,     0,     0,     0,
     511,   512,   128,     0,     0,     0,   129,     0,   130,   513,
       0,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   514,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   413,   151,   152,   153,   154,
     155,   156,   157,   158,   515,   542,   516,   162,   517,   518,
     165,   166,   167,   168,   169,   170,   519,   172,   520,   521,
     522,   176,   177,   523,   524,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     0,     0,   245,   525,   247,   248,   249,   250,
     251,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   410,   411,     0,    14,    15,    16,   833,
      18,    19,    20,    21,   535,   834,   489,    25,   491,   412,
      28,   492,    30,    31,     0,    32,    33,    34,    35,   835,
      37,   538,   539,    40,    41,    42,    43,   494,     0,    45,
     836,    47,   496,   497,    50,   498,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     499,   500,    68,     0,    69,    70,    71,   837,     0,     0,
      74,    75,    76,     0,     0,   502,    78,     0,     0,     0,
      79,    80,   503,    82,   504,   505,    85,    86,   555,    88,
       0,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   506,    97,    98,   507,   508,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   556,   109,     0,   110,   111,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   510,     0,   123,     0,     0,     0,     0,     0,
     511,   512,   128,     0,     0,     0,   129,     0,   130,   513,
       0,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   413,   151,   152,   153,   154,
     155,   156,   157,   158,   515,   542,   516,   162,   517,   518,
     165,   166,   167,   168,   169,   170,   519,   172,   520,   521,
     522,   176,   177,   523,   524,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   525,   247,   248,   249,   250,
     251,     7,     8,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,   129,  1569,   130,   513,     0,     0,     0,
       0,  1570,     0,   135,     0,   136,   137,   138,   139,   514,
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
       0,   129,   753,   130,   513,     0,     0,     0,     0,   754,
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
      15,    16,   534,    18,    19,    20,   487,   535,   536,   489,
     490,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   537,    37,   538,   539,    40,    41,    42,    43,
     494,     0,    45,   540,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     541,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,   107,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
     801,   130,   513,     0,     0,     0,     0,   802,     0,   135,
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
     486,    18,    19,    20,   487,    22,   488,   489,  1137,   491,
     412,    28,   492,    30,    31,     0,    32,    33,    34,    35,
     493,    37,    38,    39,    40,    41,    42,    43,   494,     0,
      45,   495,    47,   496,   497,    50,   498,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   499,   500,    68,     0,    69,    70,    71,   501,     0,
       0,    74,    75,    76,     0,     0,   502,    78,     0,     0,
       0,     0,    80,   503,    82,   504,   505,    85,    86,  1487,
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
      80,   503,    82,   504,   505,    85,    86,  1626,     0,     0,
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
      82,   504,   505,    85,    86,  1630,     0,     0,     0,     0,
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
     143,   144,   145,   146,     0,     0,  1140,   148,     0,     0,
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
      15,    16,   486,    18,    19,    20,   487,    22,   488,   489,
    1137,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   493,    37,    38,    39,    40,    41,    42,    43,
     494,     0,    45,   495,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     501,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1138,     0,     0,     0,  1139,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   413,   151,
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
     534,    18,    19,    20,   487,   535,   536,   489,   490,   491,
     412,    28,   492,    30,    31,     0,    32,    33,    34,    35,
     537,    37,   538,   539,    40,    41,    42,    43,   494,     0,
      45,   540,    47,   496,   497,    50,   498,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   499,   500,    68,     0,    69,    70,    71,   541,     0,
       0,    74,    75,    76,     0,     0,   502,    78,     0,     0,
       0,     0,    80,   503,    82,   504,   505,    85,    86,  1231,
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
     250,   251,   410,   411,     0,    14,    15,    16,   534,    18,
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
       0,     7,     8,   245,   525,   247,   248,   249,   250,   251,
     410,   411,     0,    14,    15,    16,     0,    18,    19,    20,
     487,     0,     0,   489,   490,     0,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,     0,    37,     0,     0,
      40,    41,    42,    43,   494,     0,    45,     0,    47,     0,
       0,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,     0,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   506,    97,    98,   507,   508,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,     0,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   509,   120,   121,   510,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   128,
       0,     0,     0,   129,     0,   130,   513,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   514,
     141,   142,   143,   144,   145,   146,     0,     0,     0,   148,
       0,     0,   413,   151,   152,   153,   154,   155,   156,   157,
     158,   515,     0,   516,   162,   517,   518,   165,   166,   167,
     168,   169,   170,   519,   172,   520,   521,   522,   176,   177,
       0,   524,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,   245,   525,   247,   248,   249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   684,   179,   668,     4,     5,     6,   311,     0,   109,
     110,  1050,     4,     5,     6,     4,     5,     6,     4,     5,
       6,     4,     5,     6,    12,   419,   420,   905,   821,   340,
     421,   669,   670,   671,   672,   758,   618,   619,   133,   758,
     778,   259,  1034,   260,   859,   583,   616,   617,   618,   619,
    1284,   589,   790,     1,  1301,  1364,  1365,    73,   275,   252,
     253,   433,     1,   918,   919,  1074,   804,   291,    39,  1123,
     461,   462,   444,    44,    45,    36,   941,   991,   714,   616,
     617,  1397,  1009,   118,    26,    27,    30,   957,    59,    55,
      61,    62,  1314,    29,    76,     1,  1591,   469,    29,    70,
       1,   282,   957,     1,   107,    47,    96,    29,   108,    26,
      27,   118,    26,    27,    93,    36,   108,     1,     1,   108,
      37,    38,   108,    40,    41,     1,    97,     1,   100,     1,
      47,     8,    74,    47,   225,    96,   991,  1656,     1,    56,
      57,   147,    56,   243,   244,   107,   131,     1,   647,     1,
     649,   650,   130,   652,   130,   654,  1011,    74,   156,   107,
      74,    96,    79,   662,   663,    79,   919,     1,   107,  1024,
     112,   153,    96,    94,   110,    96,    96,   118,   118,   169,
     247,   248,   113,   148,     1,   148,   147,   156,   124,   113,
     225,   291,   416,   113,   111,   112,   113,   111,   112,   113,
     165,   107,   165,   270,   183,   190,     9,    10,   142,     1,
    1729,   107,   147,   149,   186,     1,    33,   153,    45,   197,
     156,   197,  1531,   314,   107,   963,   147,     1,   190,   160,
      96,   107,   235,   107,     1,    62,   156,     1,   160,   221,
     222,   177,  1281,   160,  1739,  1123,  1124,   187,   343,     1,
       1,   217,   252,   253,   225,     1,   256,   561,  1011,   440,
     252,   253,   252,   253,   256,   255,   273,   273,  1502,  1139,
     214,  1024,   307,   107,  1590,  1267,    73,  1070,    54,  1017,
      56,   187,   272,  1505,  1139,  1023,   868,   869,   254,   190,
      87,   291,   190,  1016,   284,  1014,  1305,  1016,   175,   291,
     103,     0,     1,   220,  1231,  1314,   190,   943,  1222,     1,
    1175,   187,   273,   187,   111,   107,   416,  1036,   190,  1373,
     123,   107,   125,   259,   100,   549,   123,   190,   125,   866,
     867,     1,   348,   107,   725,   351,   190,   233,   190,   273,
     107,     0,     1,   107,   261,   287,   317,   318,   319,   449,
     153,   185,   273,   295,   157,   107,   107,    26,    27,   459,
     187,   107,     1,   107,     1,   313,   100,  1222,   468,   107,
     287,   174,   311,   287,   147,   475,   476,   107,   295,   121,
    1689,   295,   153,   225,   484,   776,   303,    96,   230,   303,
     256,   257,   195,    94,   107,   187,   613,   614,   616,   617,
     772,   187,   901,   775,  1259,   954,   623,    96,   107,   217,
     213,   635,   605,   187,   153,   107,   416,   966,    37,    38,
     187,    40,    41,   187,   416,    96,   100,     1,  1283,   107,
     225,   118,   227,  1742,   160,   187,   187,   107,    57,   210,
     225,   187,   227,   112,   188,   445,   254,   447,   107,   549,
     188,   158,   186,   445,   118,   447,   445,   187,   447,   445,
     169,   447,     1,     1,   122,   565,     1,   156,   107,   176,
     107,    29,   314,   473,   187,   251,   147,   577,   478,  1726,
       1,   473,     1,  1221,   473,   184,   478,   473,   264,   478,
     266,   233,   478,   185,   113,  1373,  1505,   597,   598,   186,
     273,   277,   278,   279,  1382,   281,  1259,   283,     1,   187,
    1233,   905,   186,    94,   184,  1393,   107,   218,   219,   314,
     744,   156,   186,  1242,   107,   184,  1108,  1109,  1110,   314,
    1283,  1346,   233,   107,  1217,  1350,   156,  1771,  1108,  1109,
    1110,   160,   936,   252,   253,   184,   255,   184,   107,   549,
    1405,   348,   110,   262,   351,  1093,   556,   549,   154,   169,
     156,   142,     9,   272,   556,   153,   124,   556,   107,   107,
     556,   107,   107,   964,   965,   284,     9,    10,   969,     5,
     201,    28,   107,     9,   100,   685,   107,   107,   107,   210,
     690,   149,   202,   688,   689,   156,   187,   113,   598,   107,
      45,   220,    47,   107,   187,   605,   598,   107,   999,   598,
     184,    42,    52,   605,   107,    46,   616,   617,   618,   619,
      51,  1613,   210,   611,   616,   617,   618,   619,   187,   426,
    1368,   122,   429,   857,  1489,   635,   433,  1492,    69,   436,
     437,   237,   261,   635,   744,   184,   184,   444,   866,   184,
       9,   187,  1405,   450,   451,   872,     9,    10,   455,   876,
     884,   106,   187,   184,    94,   184,   463,   187,   156,    28,
     103,   136,   469,   470,   471,   472,   123,     5,   125,   187,
     477,     9,  1560,   187,   184,   150,  1725,   134,   485,   129,
     123,   184,   125,    94,    42,    94,   117,   123,    46,   125,
     158,    94,   136,    51,   100,    96,   153,   133,     9,    10,
    1503,    94,   812,   813,   814,  1508,   816,   113,   176,  1384,
     153,    69,   113,   168,   157,   146,    45,   153,    47,  1123,
    1124,  1454,   106,   530,   299,    29,  1489,   168,   159,  1492,
     171,   174,   156,   308,   744,     1,   147,   544,   147,   142,
     103,   156,   744,   127,   137,   186,  1439,   857,   555,   142,
      79,     1,   195,     3,   123,   156,   125,   201,   768,   156,
     123,  1353,   125,   194,    42,   134,   768,    33,    46,   768,
     213,   212,   768,    51,    94,   768,   583,   106,   218,   219,
     122,   153,   589,    49,   153,   123,   593,   125,   798,   799,
     153,    69,   103,   233,   157,   133,   798,   799,   122,   798,
     799,   269,   798,   799,  1125,   177,   110,  1672,   276,  1674,
     168,   174,   123,   171,   125,   153,    66,   153,   286,    33,
     124,    71,    53,   268,    53,   144,    94,    58,   186,    58,
     275,   118,   195,  1636,   154,    49,   156,  1640,   106,   168,
    1705,   177,   153,  1716,  1717,   149,   157,   857,    77,   153,
     213,  1005,   156,  1007,   212,   857,    24,   176,    94,   153,
     122,  1262,   156,   174,  1098,    96,    34,    96,   118,   158,
     106,  1736,  1099,   177,   884,   194,  1551,  1552,  1105,   158,
     878,   100,   884,   166,   195,  1758,  1751,   176,  1753,   118,
     168,  1764,    60,   171,   113,   122,  1544,   176,   182,   182,
    1593,   347,   213,  1057,   350,  1059,   142,   137,   186,  1672,
     199,  1674,   196,   263,   721,  1102,    95,  1720,   269,   154,
     199,   156,   137,   153,   274,   276,   153,   106,   735,   156,
     182,   118,   739,   740,   212,   286,   100,   116,   153,   100,
     100,  1689,  1705,   620,   196,   263,   137,   624,   127,   113,
     153,   142,   113,   113,   153,   762,   274,   764,    53,  1360,
     277,   278,   279,    58,   691,   772,   283,   694,   775,  1373,
     697,   137,   779,  1736,   191,   192,   142,   153,  1382,   153,
     156,   153,   156,   122,   156,  1660,  1661,   122,  1751,  1393,
    1753,   132,   122,   221,   222,   223,   128,   129,   122,   140,
     141,  1694,   143,   128,   129,   122,   232,   232,   234,   234,
     151,   122,  1122,   820,   155,   216,   157,   118,   666,   667,
     156,   162,   673,   674,   242,   675,   676,  1261,   241,  1215,
    1216,  1345,  1581,  1582,   241,   156,     0,   153,   179,   314,
     190,   167,  1052,    92,   249,    99,    50,  1740,   200,   101,
    1052,   102,   859,  1052,   154,   193,  1052,  1732,   145,   156,
      29,   184,   203,   204,   205,   206,   207,   208,    47,   184,
    1471,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,   888,   184,   152,   118,   118,   284,   246,  1098,   187,
     284,   153,   304,     1,   118,   142,  1098,   107,  1108,  1109,
    1110,   187,   184,   153,   121,   153,  1108,  1109,  1110,  1107,
     156,   918,   919,   920,   921,   156,   156,   156,   156,  1812,
     142,  1814,    35,    17,   156,   156,   156,   153,    29,   214,
     187,  1824,   231,   245,  1535,   190,   230,   190,     3,   168,
     118,    70,   170,   170,    94,    94,    94,   231,   149,   107,
     957,   107,    29,   160,   160,  1342,  1560,   127,   132,    94,
     142,   118,   299,   246,   971,   132,   184,   187,   184,   107,
      94,    96,   187,    45,    96,   187,   187,   153,   153,   187,
     153,   184,   187,    94,   184,   153,    33,   153,   153,   996,
     225,   142,   237,    73,   231,   190,   132,   233,  1005,   170,
    1007,   118,  1009,   142,  1011,    94,    29,    87,   286,    94,
     299,   153,   127,   227,   118,  1225,   147,  1024,   118,    94,
     132,   184,   132,  1225,   100,    96,  1225,   160,   118,  1225,
     153,   111,  1225,   254,   100,   153,   198,   184,   147,   184,
     142,    35,   121,   123,   190,   125,    29,   245,   118,  1483,
    1057,  1261,  1059,    79,   107,   107,   258,   156,   156,  1261,
     285,   260,  1272,   156,   156,   156,   144,    29,   156,   156,
    1272,   267,    29,  1272,    29,   227,  1272,   144,   147,  1272,
     187,  1291,   187,   306,   190,   127,  1093,   147,   147,  1291,
    1524,   187,  1291,   286,   118,  1291,   287,   118,  1291,    77,
     107,  1311,   142,   187,   187,   187,     7,   100,    96,  1311,
     184,  1118,  1311,   132,   233,  1311,   237,   198,   156,   233,
     156,   156,   190,   186,   153,   106,   187,   147,   282,    78,
     233,   286,  1139,   187,   250,    29,   233,   187,   187,  1349,
      29,   187,   187,   187,   187,   271,   107,  1349,   170,   147,
    1349,   184,   147,   126,   126,   250,    96,   184,   186,    94,
     142,   186,   153,   316,    29,    96,   170,   287,   186,   186,
     184,   257,   184,   184,   187,    53,   147,  1611,   187,    94,
     186,   186,   197,   106,    94,    29,   107,   107,  1622,  1623,
     118,  1625,   118,   225,    94,    94,   186,   197,  1632,   198,
     197,   265,   118,    93,   183,   197,   186,   280,   724,   225,
     186,  1521,  1522,  1523,   118,   118,   186,   186,   186,   256,
     118,  1178,   199,   225,  1231,   256,   958,   440,  1235,   259,
     420,   293,  1222,  1025,  1694,  1740,  1022,   860,   781,   287,
    1464,  1251,  1114,  1250,  1369,  1367,  1364,   305,   305,   305,
    1273,   306,  1259,   544,  1278,   306,  1281,  1286,   455,   645,
     921,   646,   699,   665,  1305,   306,  1273,   821,   348,  1764,
    1758,   351,  1177,  1483,  1007,  1336,  1283,  1347,  1346,  1713,
    1382,  1483,  1560,  1393,  1124,  1386,  1557,   448,   448,  1133,
     990,  1429,  1200,  1584,  1383,   587,   335,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1312,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1524,    -1,    -1,    -1,  1752,    -1,
      -1,    -1,  1524,    -1,    -1,    -1,    -1,    -1,    -1,  1336,
      -1,    -1,    -1,    -1,    -1,    -1,  1770,    -1,    -1,  1346,
      -1,    -1,  1652,  1350,    -1,   425,   426,    -1,    -1,   429,
      -1,  1785,    -1,   433,    -1,    -1,   436,   437,    -1,    -1,
    1670,    -1,    -1,    -1,   444,    -1,    -1,    -1,    -1,    -1,
     450,   451,  1806,    -1,    -1,   455,    -1,    -1,    -1,    -1,
      -1,  1815,    -1,   463,    -1,    -1,    -1,    -1,    -1,   469,
     470,   471,   472,    -1,    -1,    -1,   108,   477,  1405,    -1,
      -1,  1611,    -1,    -1,    -1,   485,    -1,    -1,    -1,  1611,
      -1,    -1,  1622,  1623,    -1,  1625,    -1,    -1,    -1,    -1,
    1622,  1623,  1632,  1625,    -1,    -1,    -1,    -1,  1435,    -1,
    1632,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     530,    -1,    -1,    -1,  1461,  1462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   544,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   555,    -1,    -1,    -1,    -1,
    1487,    -1,  1489,    -1,    -1,  1492,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1504,    -1,    -1,
      -1,    -1,  1509,  1713,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1713,    -1,   593,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1770,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1770,    -1,
      -1,    -1,    -1,    -1,    -1,  1785,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1785,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1806,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1806,  1815,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1815,    -1,    -1,    -1,    -1,    -1,  1626,
      -1,  1628,    -1,  1630,    -1,    -1,    -1,    -1,    -1,    -1,
    1637,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   718,    -1,
      -1,   721,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   735,    -1,    -1,    -1,   739,
     740,    -1,    -1,    -1,    -1,  1672,    -1,  1674,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   762,  1690,   764,    -1,  1693,    -1,    -1,    -1,
      -1,    -1,   772,    -1,    -1,   775,    -1,    -1,  1705,   779,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1715,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1736,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1744,    -1,    -1,
     820,    -1,  1749,    -1,  1751,    -1,  1753,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1782,    -1,    -1,    -1,   859,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1802,    -1,    -1,    -1,    -1,
    1807,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   888,    -1,
      -1,    -1,  1819,    -1,    -1,  1822,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   918,   919,
     920,   921,    -1,    -1,   556,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,
     582,    -1,    -1,   585,   586,   587,   588,   957,   590,    -1,
      -1,    -1,    -1,    -1,   596,    -1,    -1,    -1,    -1,    -1,
      -1,   971,   604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   626,   627,   996,    -1,    -1,    -1,
      -1,    -1,    -1,   635,   636,  1005,    -1,  1007,    -1,  1009,
      -1,  1011,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1024,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1057,    -1,  1059,
      -1,    -1,    -1,    -1,   696,    -1,    -1,   699,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   737,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1139,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   780,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   805,    -1,    -1,    -1,   809,   810,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   818,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1231,    -1,    -1,    -1,  1235,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1250,    -1,   884,    -1,    -1,    -1,    -1,    -1,   890,  1259,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1273,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1283,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1312,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   959,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1336,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1346,    -1,    -1,    -1,
    1350,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   994,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1013,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1035,    -1,  1405,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1046,  1047,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1061,
      -1,    -1,  1064,    -1,    -1,  1435,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1080,  1081,
    1082,    -1,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1461,  1462,  1095,  1096,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1104,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1114,    -1,    -1,    -1,    -1,  1487,    -1,  1489,
      -1,    -1,  1492,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1504,    -1,    -1,    -1,    -1,  1509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1165,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1237,    -1,  1239,    -1,  1241,
      -1,    -1,  1244,    -1,    -1,    -1,    -1,  1249,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1626,    -1,  1628,  1261,
    1630,    -1,    -1,    -1,    -1,    -1,    -1,  1637,  1270,    -1,
      -1,    -1,    -1,    -1,  1276,  1277,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1295,    -1,    -1,  1298,    -1,    -1,    -1,
      -1,    -1,  1672,    -1,  1674,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1690,    -1,    -1,  1693,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1705,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1715,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1367,  1736,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1744,    -1,    -1,    -1,    -1,  1749,
      -1,  1751,    -1,  1753,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1782,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1802,    -1,    -1,    -1,    -1,  1807,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1448,    -1,    -1,  1819,
    1452,    -1,  1822,    -1,  1456,    -1,  1458,    -1,  1460,    -1,
      -1,    -1,    -1,    -1,  1466,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1474,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1482,  1483,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1501,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1512,  1513,  1514,  1515,    -1,  1517,  1518,    -1,  1520,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1536,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1599,    -1,  1601,
      -1,    -1,  1604,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1612,    -1,    -1,    -1,    -1,  1617,  1618,    -1,    -1,    -1,
      -1,    -1,    -1,  1625,    -1,    -1,    -1,  1629,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1645,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1657,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1697,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1709,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,  1780,    -1,
      -1,    -1,    -1,  1785,    -1,    -1,    11,    12,  1790,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,  1805,    29,    -1,    -1,  1809,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    97,    98,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,   124,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,   194,
      -1,   196,    -1,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,    -1,    -1,   211,   212,   213,    -1,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,    -1,   259,   260,   261,    -1,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,   312,    -1,   314,
     315,   316,   317,   318,   319,   320,     0,     1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,     1,   312,    -1,
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,     1,   312,    -1,
     314,   315,   316,   317,   318,   319,   320,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    98,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,   158,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,    -1,
     194,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,   213,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,    -1,   312,    -1,
     314,   315,   316,   317,   318,   319,   320,     0,     1,    -1,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    50,    51,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    69,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    94,    95,    96,    -1,    -1,    99,   100,   101,   102,
      -1,    -1,    -1,   106,   107,    -1,    -1,    -1,    -1,    -1,
     113,    -1,    -1,   116,   117,   118,    -1,    -1,   121,    -1,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,    -1,   132,
      -1,    -1,    -1,   136,    -1,    -1,    -1,   140,   141,    -1,
     143,    -1,   145,   146,    -1,    -1,    -1,   150,   151,    -1,
      -1,   154,   155,   156,   157,   158,   159,    -1,    -1,   162,
      -1,    -1,    -1,    -1,   167,   168,    -1,    -1,   171,    -1,
      -1,    -1,    -1,   176,    -1,    -1,   179,    -1,    -1,    -1,
      -1,   184,   185,   186,   187,   188,    -1,   190,   191,   192,
     193,   194,    -1,    -1,    -1,    -1,   199,   200,   201,    -1,
     203,   204,   205,   206,   207,   208,    -1,   210,    -1,   212,
      -1,    -1,    -1,    -1,   217,   218,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     233,    -1,   235,    -1,   237,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   249,    -1,    -1,    -1,
      -1,   254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,   311,    -1,
     313,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,
     192,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,   213,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,    -1,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,   321,
     322,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
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
     320,    -1,   322,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     138,   139,    -1,    -1,    -1,    -1,   144,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     138,   139,    -1,    -1,    -1,    -1,   144,    -1,   146,   147,
     148,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
     158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,   176,   177,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
      -1,    -1,   180,   181,   182,    -1,    -1,   185,   186,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     308,   309,   310,   311,   312,    -1,   314,   315,   316,   317,
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     308,   309,   310,    -1,   312,   313,   314,   315,   316,   317,
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
      -1,    -1,   180,   181,   182,    -1,   184,    -1,   186,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     138,   139,    -1,    -1,    -1,    -1,   144,    -1,   146,   147,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     128,   129,    -1,   131,    -1,    -1,    -1,   135,    -1,   137,
     138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,
     148,   149,    -1,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,   174,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,
     198,    -1,   200,    -1,   202,   203,   204,   205,   206,   207,
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
     318,   319,   320,    11,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,    -1,    24,    25,    -1,    -1,
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
     188,   189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,
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
     308,   309,    -1,    -1,    11,    12,   314,   315,   316,   317,
     318,   319,   320,    20,    -1,    -1,    -1,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,   196,
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
     307,   308,   309,    -1,    -1,    -1,    16,   314,   315,   316,
     317,   318,   319,   320,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,   187,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,    -1,    -1,    16,   314,   315,   316,   317,   318,   319,
     320,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    -1,
      -1,   314,   315,   316,   317,   318,   319,   320,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,    -1,
      -1,   211,   212,    -1,    -1,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,    -1,   259,
     260,   261,    -1,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,    -1,    -1,    -1,   314,   315,   316,   317,   318,   319,
     320,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
      -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    -1,    94,    95,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
      -1,    -1,    -1,    -1,    -1,    -1,   196,    -1,   198,   199,
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
     320,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,    -1,    -1,    -1,   194,    -1,   196,
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
     113,   114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
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
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
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
     319,   320,    33,    34,    -1,    36,    37,    38,    39,    40,
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
      -1,    24,    25,   314,   315,   316,   317,   318,   319,   320,
      33,    34,    -1,    36,    37,    38,    -1,    40,    41,    42,
      43,    -1,    -1,    46,    47,    -1,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    -1,    60,    -1,    -1,
      63,    64,    65,    66,    67,    -1,    69,    -1,    71,    -1,
      -1,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    -1,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,
     113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,    -1,   196,    -1,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,    -1,    -1,    -1,   212,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,    -1,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
      -1,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,    -1,   259,   260,   261,    -1,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,    -1,    -1,
      -1,   314,   315,   316,   317,   318,   319,   320
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
     478,   479,   480,   481,   483,   484,   485,   486,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   519,   520,   521,   535,   536,
     538,   539,   540,   541,   542,   543,   544,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   564,   565,   566,
     567,   572,   573,   574,   575,   576,   577,   580,   638,   639,
     640,   641,   643,   644,   645,   646,   647,   654,   655,   656,
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
     238,   239,   240,   243,   244,   315,   503,   654,   655,   122,
     118,   400,   122,   122,    39,    44,    45,    59,    61,    62,
      70,    97,   225,   654,   118,   122,   122,   184,   391,   393,
     413,   642,    48,    72,    73,   118,   153,   185,   244,   412,
     414,   424,   187,   412,   654,   153,   122,    16,   653,   654,
      18,    19,   654,   122,   122,   122,   495,   153,    30,   214,
     216,   225,   227,   314,   156,   225,   227,   314,   225,   314,
     225,   230,   314,   118,   241,   241,   242,   156,   153,   395,
     311,   412,   313,   412,   314,   322,   337,   337,     0,   339,
     340,    33,    49,   342,   359,     1,   190,   336,   190,   336,
     112,   374,   394,   412,   107,   190,   107,   336,   190,    42,
      46,    51,    69,   168,   171,   186,   212,   407,   416,   421,
     422,   423,   437,   438,   442,   167,    92,   132,   140,   141,
     143,   151,   155,   157,   162,   179,   203,   204,   205,   206,
     207,   208,   487,   488,   249,    99,   158,   176,   199,   117,
     146,   159,   194,   201,   210,   136,   150,    50,   200,   101,
     102,   158,   176,   485,   193,   153,   492,   495,   191,   192,
     154,   507,   508,   503,   507,   503,   156,   507,   145,   156,
     184,   184,   184,   375,   510,   375,    29,   652,   182,   196,
     182,   196,   166,   182,   655,   654,   169,   202,    47,   654,
     152,   118,    45,    47,    79,   106,   168,   653,   221,   222,
     223,   246,   611,   654,   654,   304,   137,   142,   112,   287,
     295,   377,   653,   392,   393,   187,   392,    45,    62,   187,
     560,   561,   412,   187,   194,   654,   426,   427,   654,   284,
     284,   426,   118,   433,   118,   187,   381,   382,   153,   397,
     412,     1,   160,   652,   113,   160,   355,   652,   654,   118,
     142,   107,   412,    29,   187,   653,   654,   654,   450,   451,
     654,   392,   187,   412,   412,   562,   654,   392,   153,   153,
     412,   187,   194,   654,   654,   142,   450,   184,   184,   121,
     107,   184,   156,   156,   156,   654,   153,   185,   186,   187,
      35,   523,   524,   525,   412,     8,   175,    17,   412,   214,
      29,   413,   413,    39,    45,    59,    70,    97,   506,   654,
     187,   413,   413,   413,   642,   413,   506,   413,   231,   230,
     578,   579,   654,   190,   190,   413,   412,   393,   412,   245,
     410,   411,   311,   313,   413,   337,   190,   336,   190,   336,
       3,   343,   359,   389,     1,   343,   359,   389,    33,   360,
     389,   360,   389,   400,   336,   400,   413,   413,   118,   168,
     170,   170,   394,   413,   413,   467,   468,   470,   470,   470,
     470,   469,   470,   470,   470,    70,   471,   475,   475,   474,
     476,   476,   476,   476,   477,   477,   478,   478,   231,    94,
      94,    94,   493,   184,   412,   495,   495,   412,   508,   144,
     187,   413,   518,   149,   187,   518,   107,   187,   187,   107,
     107,   380,    29,   655,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   362,   363,   364,    94,   137,   142,
     368,   369,   370,   654,   160,   160,   362,   652,   127,   132,
      54,    56,   100,   251,   264,   266,   277,   278,   279,   281,
     283,   612,   613,   614,   615,   616,   617,   624,   630,   631,
     246,    94,   299,   654,   142,   413,   118,   654,   654,   132,
     184,   184,   187,   187,   184,   107,   187,   107,   187,   107,
      36,    94,    96,   147,   428,   429,   545,   654,    55,   217,
     254,   418,   419,   654,    94,   107,   187,   391,   187,   653,
      96,    45,   653,   652,    96,   142,   545,   654,   413,   432,
     184,   187,   187,   187,   187,   107,   188,   147,   545,   184,
     187,   187,   153,   184,   392,   392,   184,   107,   187,   107,
     187,   142,   545,   413,   188,   413,   413,   412,   412,   412,
     654,   524,   525,   130,   197,   184,   184,   131,   190,    94,
     218,   219,   233,    94,   218,   219,   233,   233,   233,    94,
      94,   237,   225,   231,   107,   235,   142,   190,   187,   412,
     184,   504,   584,   411,   233,   359,    33,    33,   190,   336,
     190,   113,   394,   654,   170,   413,   443,   444,   118,   439,
     440,   470,   153,   156,   259,   491,   510,   585,   588,   589,
     590,   591,   592,   596,   598,   600,   601,    47,   152,   156,
     211,   317,   318,   319,   320,   546,   548,   550,   552,   568,
     569,   570,   571,   648,   649,   650,   651,   654,   546,   482,
     551,   654,   482,   184,   185,   107,   187,   187,   510,   148,
     165,   148,   165,   137,   397,   380,   363,   132,   548,   370,
     413,   545,   652,   652,   128,   129,   652,   277,   278,   279,
     283,   654,   263,   274,   263,   274,    29,   286,    96,   113,
     156,   618,   621,   612,    39,    44,    59,    61,    70,    97,
     225,   317,   318,   319,   384,   552,   648,   227,   299,   308,
     413,   654,    94,   299,   652,   153,   562,   563,   654,   562,
     563,   118,   427,   127,   546,   118,   413,   147,   429,   147,
      36,   147,   428,   429,   147,   545,   254,    53,    58,    77,
     118,   428,   434,   435,   436,   419,   545,   546,   382,    94,
     184,   198,   132,   354,   652,   160,   132,    96,   354,   413,
     142,   429,   153,   118,   413,   413,   147,   100,   453,   454,
     455,   457,   458,   100,   461,   462,   463,   464,   392,   184,
     184,   153,   562,   562,   413,   142,   190,   413,   121,   187,
     187,   187,    35,   525,   130,   197,     9,    10,   103,   123,
     125,   153,   195,   520,   522,   533,   534,   537,    29,   232,
     234,   413,   413,   413,   232,   234,   413,   413,   413,   413,
     413,   413,   413,   413,   413,   506,   118,   413,   413,    48,
      72,    73,   244,   394,   414,   424,   245,   581,   582,   153,
     210,   395,   413,   190,   113,   389,   389,   389,   443,    95,
     106,   116,   127,   445,   446,   447,   448,   107,   654,   107,
     412,   585,   592,   153,   285,   472,   637,    96,   169,   252,
     253,   255,   262,   272,   284,   586,   587,   606,   607,   608,
     609,   632,   635,   258,   260,   593,   611,   267,   597,   633,
     247,   248,   270,   602,   603,   156,   156,   548,   156,   156,
     156,   156,   156,   144,   176,   194,   547,   144,   144,   413,
     137,   397,   564,   369,   286,    29,    96,   113,   156,   625,
      29,   618,   547,   547,   493,   287,   306,   545,   384,   227,
     190,   391,   187,   187,   144,   187,   187,   427,   147,   428,
     654,   413,   147,   413,   127,   413,   147,   429,   147,   413,
     147,   118,   118,   413,   654,   436,    77,   546,   394,   413,
     652,   107,   354,   413,   142,   391,   451,   413,   413,   113,
     454,   455,   100,   186,   113,   455,   458,   118,   546,   100,
     113,   462,   100,   113,   464,   184,   391,   187,   187,   413,
     413,   198,   461,   132,   195,   522,     7,   392,   654,   195,
     533,   190,   233,   233,   233,   233,    96,   237,   237,   579,
     186,   156,   156,   156,   186,   584,   582,   504,   652,   128,
     129,   447,   448,   448,   444,   106,   142,   441,   545,   440,
     184,   187,   585,   599,   250,   217,   254,   268,   275,   636,
      96,   256,   257,   634,   250,   589,   636,   474,   606,   590,
     147,   282,   594,   595,   634,   286,   605,    78,   604,   187,
     194,   546,   549,   187,   187,   187,   187,   187,   187,   187,
      29,   136,   201,   627,   628,   629,    29,   626,   627,   271,
     622,   107,   619,   170,   654,   257,   493,   184,   413,   147,
     413,   147,   428,   413,   147,   413,   413,   654,   654,   435,
     413,   126,   126,    96,   652,   413,   184,   186,   186,   413,
     394,   413,   186,   186,   654,   186,   118,   546,   118,   186,
     118,   546,   186,   184,   113,   525,   654,   195,   184,   525,
     654,   413,   413,   413,   413,   316,   413,   413,   413,   412,
     412,   412,   153,   583,   448,   652,   413,   142,   184,   476,
      52,   129,   474,   474,   269,   276,   286,   610,   610,   591,
     153,   280,    94,   187,   107,   187,   625,   625,   629,   107,
     187,    29,   623,   634,   620,   621,   187,   386,   387,   493,
     118,   225,   307,   287,   170,   413,   413,   147,   413,    53,
     394,   413,   354,   413,   394,    94,   394,   413,   654,   186,
     654,   413,   654,   186,   394,   118,    93,   183,   526,   525,
     654,   197,   525,   413,   187,   187,   187,   412,   441,   413,
     474,   474,   199,   412,   546,   546,    94,    29,   265,   107,
     107,   448,   545,   654,   118,   225,   654,   386,   413,   118,
     546,    94,   186,    94,   654,     5,   133,   529,   530,   532,
     534,    28,   134,   527,   528,   531,   534,   197,   525,   197,
     198,   461,   184,   441,   474,   184,   546,   621,   387,   448,
     305,   654,   118,   225,   654,   186,   546,   394,   413,   546,
     186,    93,   133,   532,   183,   134,   531,   197,   113,   413,
     305,   654,   118,   394,   413,   186,   186,   118,   293,   305,
     654,   654,   306,   413,   306,   186,   493,   493,   199,   287,
     654,   225,   118,   654,   306,   493
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
         0,   334,   335,   335,   335,   335,   336,   336,   336,   337,
     337,   337,   337,   338,   338,   339,   339,   339,   339,   339,
     339,   339,   339,   340,   340,   340,   340,   341,   342,   342,
     342,   343,   343,   343,   343,   343,   344,   344,   344,   344,
     344,   344,   344,   344,   345,   345,   346,   347,   348,   348,
     349,   349,   350,   350,   351,   351,   351,   351,   352,   352,
     352,   353,   353,   353,   353,   354,   354,   355,   355,   356,
     356,   356,   356,   357,   358,   358,   359,   359,   359,   360,
     360,   360,   360,   360,   360,   360,   360,   361,   361,   362,
     362,   363,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   364,   365,   366,   367,   368,   368,   369,   369,   369,
     370,   371,   371,   371,   372,   372,   372,   372,   373,   373,
     374,   374,   374,   374,   375,   375,   376,   376,   377,   377,
     378,   378,   379,   379,   380,   380,   380,   380,   381,   381,
     382,   382,   383,   383,   383,   383,   384,   384,   384,   384,
     385,   385,   386,   386,   387,   387,   387,   387,   388,   388,
     388,   388,   389,   390,   390,   390,   391,   391,   391,   392,
     392,   393,   393,   393,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   394,   395,   395,   396,   397,
     398,   399,   399,   399,   400,   400,   400,   400,   401,   402,
     403,   404,   405,   405,   406,   407,   408,   409,   410,   410,
     411,   412,   412,   412,   413,   413,   413,   413,   413,   413,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     414,   414,   415,   416,   417,   417,   418,   418,   418,   419,
     419,   420,   420,   421,   422,   422,   422,   423,   423,   423,
     423,   423,   424,   424,   425,   425,   425,   426,   426,   426,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   427,
     427,   427,   428,   429,   430,   431,   431,   432,   432,   432,
     432,   433,   433,   434,   434,   434,   435,   435,   435,   436,
     436,   436,   437,   438,   439,   439,   440,   440,   440,   440,
     440,   440,   441,   442,   442,   443,   443,   444,   444,   445,
     445,   445,   445,   445,   445,   445,   446,   446,   447,   447,
     448,   449,   449,   450,   450,   451,   451,   452,   453,   453,
     454,   455,   455,   456,   457,   457,   458,   459,   459,   460,
     460,   461,   461,   462,   462,   463,   463,   464,   464,   465,
     466,   466,   467,   467,   468,   468,   468,   468,   468,   469,
     468,   468,   468,   468,   470,   470,   471,   471,   472,   472,
     473,   473,   474,   474,   474,   475,   475,   475,   475,   475,
     476,   476,   476,   477,   477,   477,   478,   478,   479,   479,
     480,   480,   481,   481,   482,   482,   483,   483,   484,   484,
     484,   484,   485,   485,   485,   486,   486,   487,   487,   487,
     487,   487,   487,   488,   488,   488,   489,   489,   489,   489,
     490,   490,   491,   491,   492,   492,   492,   493,   493,   493,
     493,   494,   495,   495,   495,   496,   496,   497,   497,   497,
     497,   498,   498,   499,   499,   499,   499,   499,   499,   499,
     500,   500,   501,   501,   502,   502,   502,   502,   502,   503,
     503,   504,   504,   505,   505,   505,   505,   506,   506,   506,
     506,   507,   507,   508,   509,   509,   509,   509,   509,   509,
     509,   509,   509,   509,   509,   509,   509,   509,   510,   510,
     511,   511,   511,   512,   513,   513,   514,   515,   516,   517,
     517,   518,   518,   518,   518,   519,   519,   520,   520,   520,
     521,   521,   521,   521,   521,   521,   522,   522,   523,   523,
     524,   525,   525,   526,   526,   527,   527,   528,   528,   528,
     528,   529,   529,   530,   530,   530,   530,   531,   531,   532,
     532,   533,   533,   533,   533,   534,   534,   534,   534,   535,
     535,   536,   536,   537,   538,   538,   538,   538,   538,   538,
     539,   540,   540,   541,   541,   542,   543,   544,   544,   545,
     546,   546,   546,   547,   547,   547,   548,   548,   548,   548,
     548,   548,   548,   549,   549,   550,   551,   552,   552,   552,
     552,   552,   552,   552,   552,   552,   553,   554,   554,   554,
     555,   556,   557,   557,   557,   558,   558,   558,   558,   558,
     559,   560,   560,   560,   560,   560,   560,   560,   561,   562,
     563,   564,   565,   565,   566,   567,   568,   568,   569,   570,
     570,   571,   572,   572,   572,   573,   573,   573,   573,   573,
     573,   573,   573,   573,   573,   574,   574,   575,   575,   576,
     577,   578,   578,   579,   580,   581,   581,   582,   583,   584,
     584,   585,   586,   586,   587,   587,   588,   588,   589,   589,
     590,   590,   591,   591,   592,   593,   593,   594,   594,   595,
     596,   596,   596,   597,   597,   598,   599,   599,   600,   601,
     601,   602,   602,   603,   603,   603,   604,   604,   605,   605,
     606,   606,   606,   606,   606,   607,   608,   609,   610,   610,
     610,   611,   611,   612,   612,   612,   612,   612,   612,   612,
     612,   613,   613,   613,   613,   614,   614,   615,   616,   616,
     617,   617,   617,   618,   618,   619,   619,   620,   620,   621,
     622,   622,   623,   623,   624,   624,   624,   625,   625,   626,
     626,   627,   627,   628,   628,   629,   629,   630,   631,   631,
     632,   632,   632,   633,   634,   634,   634,   634,   635,   635,
     636,   636,   637,   638,   638,   639,   639,   640,   640,   641,
     642,   642,   643,   643,   643,   644,   645,   646,   647,   648,
     648,   648,   649,   650,   651,   652,   653,   653,   654,   654,
     654,   654,   654,   654,   654,   654,   654,   654,   654,   654,
     654,   654,   654,   654,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     655,   655,   655,   655,   655,   655,   655,   655,   655,   655,
     656
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
      10,     1,     2,     4,     7,     1,     2,     4,     7,     8,
       1,     3,     1,     3,     1,     3,     3,     3,     3,     0,
       4,     3,     3,     3,     1,     5,     1,     3,     0,     1,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     4,     1,     4,
       1,     4,     1,     4,     1,     2,     1,     2,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     5,     5,     6,
       3,     4,     1,     2,     3,     2,     2,     1,     2,     2,
       1,     1,     1,     3,     3,     1,     1,     1,     2,     1,
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       1,     2,     2,     1,     2,     2,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     1,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     4,     4,     3,
       4,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     7,     3,     7,     4,     4,     3,     7,     2,
       1,     2,     3,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     4,     4,
       3,     3,     3,     4,     4,     3,     4,     6,     4,     6,
       4,     3,     4,     6,     6,     4,     6,     6,     4,     1,
       2,     1,     1,     1,     3,     3,     1,     1,     4,     5,
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
       1,     1,     3,     2,     3,     2,     3,     2,     3,     3,
       3,     5,     5,     5,     8,     5,     3,     5,     7,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     1,     1,
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
  "InstanceofExpr", "TreatExpr", "CastableExpr", "CastExpr", "SingleType",
  "UnaryExpr", "SignList", "ValueExpr", "SimpleMapExpr", "ValueComp",
  "NodeComp", "ValidateExpr", "ExtensionExpr", "Pragma_list", "Pragma",
  "PathExpr", "LeadingSlash", "RelativePathExpr", "StepExpr", "AxisStep",
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
  "CompCommentConstructor", "CompPIConstructor", "TypeDeclaration",
  "SequenceType", "OccurrenceIndicator", "ItemType", "TypeList",
  "AtomicType", "SimpleType", "KindTest", "AnyKindTest", "DocumentTest",
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
      -1,   321,   322,   337,    -1,     1,    -1,     1,     3,    -1,
     336,     1,    -1,   339,    -1,   338,   339,    -1,   340,    -1,
     338,   340,    -1,   215,   216,    29,   190,    -1,   215,   216,
      29,   131,    29,   190,    -1,   342,   190,   389,    -1,   359,
     190,   389,    -1,   342,   190,   359,   190,   389,    -1,   389,
      -1,   342,   336,   389,    -1,   359,   336,   389,    -1,   342,
     190,   359,   336,   389,    -1,   342,   336,   359,   190,   389,
      -1,   341,    -1,   341,   342,   190,    -1,   341,   359,   190,
      -1,   341,   342,   190,   359,   190,    -1,    34,   160,   653,
     132,   652,   190,    -1,   343,    -1,   342,   190,   343,    -1,
     342,   336,   343,    -1,   344,    -1,   352,    -1,   357,    -1,
     358,    -1,   366,    -1,   345,    -1,   346,    -1,   347,    -1,
     348,    -1,   349,    -1,   350,    -1,   351,    -1,   572,    -1,
      33,    38,   182,    -1,    33,    38,   196,    -1,    33,   113,
     106,   652,    -1,    33,    37,   652,    -1,    33,    40,   182,
      -1,    33,    40,   196,    -1,    33,    57,   169,    -1,    33,
      57,   202,    -1,    33,   113,   168,   127,   128,    -1,    33,
     113,   168,   127,   129,    -1,    33,    41,   182,   107,   148,
      -1,    33,    41,   182,   107,   165,    -1,    33,    41,   166,
     107,   148,    -1,    33,    41,   166,   107,   165,    -1,   353,
      -1,   356,    -1,    49,    24,     1,    -1,    49,    60,   652,
      -1,    49,    60,   355,   652,    -1,    49,    60,   652,    96,
     354,    -1,    49,    60,   355,   652,    96,   354,    -1,   652,
      -1,   354,   107,   652,    -1,   160,   653,   132,    -1,   113,
      45,   160,    -1,    49,    34,   652,    -1,    49,    34,   160,
     653,   132,   652,    -1,    49,    34,   652,    96,   354,    -1,
      49,    34,   160,   653,   132,   652,    96,   354,    -1,    33,
     160,   653,   132,   652,    -1,    33,   113,    45,   160,   652,
      -1,    33,   113,    47,   160,   652,    -1,   360,    -1,   359,
     190,   360,    -1,   359,   336,   360,    -1,   361,    -1,   365,
      -1,   367,    -1,   371,    -1,   376,    -1,   383,    -1,   385,
      -1,   388,    -1,    33,   113,    79,   362,    -1,    33,    79,
     654,   362,    -1,   363,    -1,   362,   363,    -1,   364,   132,
     564,    -1,    80,    -1,    88,    -1,    81,    -1,    82,    -1,
      83,    -1,    84,    -1,    89,    -1,    85,    -1,    86,    -1,
      87,    -1,    33,    56,   654,    29,    -1,    33,   261,   611,
      -1,    33,   111,   152,   368,    -1,    94,   548,   369,    -1,
     369,    -1,   370,    -1,   137,    -1,   137,   370,    -1,   142,
     413,    -1,    33,   372,   142,   413,    -1,    33,   372,   137,
      -1,    33,   372,   137,   142,   413,    -1,   112,   118,   654,
      -1,   112,   118,   654,   545,    -1,   373,   112,   118,   654,
      -1,   373,   112,   118,   654,   545,    -1,   374,    -1,   373,
     374,    -1,    26,    -1,    26,   156,   375,   187,    -1,    27,
      -1,    27,   156,   375,   187,    -1,   510,    -1,   375,   107,
     510,    -1,    33,   377,    -1,    33,   373,   377,    -1,   378,
      -1,   379,    -1,    47,   655,   380,   397,    -1,    47,   655,
     380,   137,    -1,    74,    47,   655,   380,   397,    -1,    74,
      47,   655,   380,   137,    -1,   156,   187,    -1,   156,   381,
     187,    -1,   156,   187,    94,   546,    -1,   156,   381,   187,
      94,   546,    -1,   382,    -1,   381,   107,   382,    -1,   118,
     654,    -1,   118,   654,   545,    -1,    33,   287,   654,    -1,
      33,   287,   654,    94,   384,    -1,    33,   373,   287,   654,
      -1,    33,   373,   287,   654,    94,   384,    -1,   552,    -1,
     552,   547,    -1,   648,    -1,   648,   547,    -1,    33,   295,
     654,   299,   227,   493,   170,   386,    -1,    33,   373,   295,
     654,   299,   227,   493,   170,   386,    -1,   387,    -1,   386,
     107,   387,    -1,   493,    -1,   493,   545,    -1,   493,   448,
      -1,   493,   545,   448,    -1,    33,   303,   304,   654,   299,
     287,   654,   118,   654,   305,   413,    -1,    33,   303,   304,
     654,   299,   287,   654,   225,   118,   654,   305,   293,   306,
     493,    -1,    33,   303,   304,   654,   299,   287,   654,   307,
     225,   118,   654,   305,   413,    -1,    33,   303,   304,   654,
     308,   306,   257,   287,   654,   225,   118,   654,   306,   493,
     199,   287,   654,   225,   118,   654,   306,   493,    -1,   390,
      -1,   392,    -1,   393,    -1,    -1,   392,    -1,   393,    -1,
      -1,   412,    -1,   393,   412,    -1,   394,    -1,   393,   394,
      -1,   393,   412,   336,   394,    -1,   395,    -1,   398,    -1,
     401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,    -1,
     406,    -1,   408,    -1,   460,    -1,   456,    -1,   409,    -1,
     153,   393,   184,    -1,   153,   184,    -1,   153,   391,   184,
      -1,   153,   391,   184,    -1,   399,   190,    -1,   399,   107,
     400,    -1,   112,   400,    -1,   373,   112,   400,    -1,   118,
     654,    -1,   118,   654,   545,    -1,   118,   654,   142,   413,
      -1,   118,   654,   545,   142,   413,    -1,   118,   654,   142,
     413,   190,    -1,   414,   190,    -1,   240,   242,   413,   190,
      -1,   243,   156,   412,   187,   394,    -1,   238,   241,   190,
      -1,   239,   241,   190,    -1,   424,   407,    -1,   186,   394,
      -1,    48,   156,   412,   187,   198,   394,   126,   394,    -1,
     244,   395,   410,    -1,   411,    -1,   410,   411,    -1,   245,
     584,   395,    -1,   413,    -1,   412,   107,   413,    -1,   412,
     336,   413,    -1,   415,    -1,   452,    -1,   459,    -1,   465,
      -1,   580,    -1,   414,    -1,   466,    -1,   449,    -1,   573,
      -1,   574,    -1,   576,    -1,   575,    -1,   577,    -1,   645,
      -1,   643,    -1,   646,    -1,   647,    -1,   644,    -1,   424,
     416,    -1,   186,   413,    -1,    66,   284,    -1,    71,   284,
      -1,   217,    -1,   254,    -1,    55,   254,    -1,   418,   434,
      77,   413,    -1,   418,    77,   413,    -1,    46,   417,   433,
     419,   419,    -1,    46,   417,   433,   419,    -1,    42,   118,
     654,    -1,   425,    -1,   430,    -1,   420,    -1,   422,    -1,
     437,    -1,   442,    -1,   438,    -1,   421,    -1,   422,    -1,
     424,   423,    -1,    46,   118,   426,    -1,    46,     1,   426,
      -1,    46,     3,    -1,   427,    -1,   426,   107,   118,   427,
      -1,   426,   107,   427,    -1,   654,   147,   413,    -1,   654,
      36,   127,   147,   413,    -1,   654,   545,   147,   413,    -1,
     654,   545,    36,   127,   147,   413,    -1,   654,   428,   147,
     413,    -1,   654,    36,   127,   428,   147,   413,    -1,   654,
     545,   428,   147,   413,    -1,   654,   545,    36,   127,   428,
     147,   413,    -1,   654,   429,   147,   413,    -1,   654,   545,
     429,   147,   413,    -1,   654,   428,   429,   147,   413,    -1,
     654,   545,   428,   429,   147,   413,    -1,    96,   118,   654,
      -1,   273,   118,   654,    -1,    51,   431,    -1,   432,    -1,
     431,   107,   432,    -1,   118,   654,   142,   413,    -1,   118,
     654,   545,   142,   413,    -1,   429,   142,   413,    -1,   118,
     654,   545,   429,   142,   413,    -1,   118,   654,   147,   413,
      -1,   118,   654,   545,   147,   413,    -1,   435,    -1,   118,
     654,    -1,   118,   654,   435,    -1,   428,    -1,   428,   436,
      -1,   436,    -1,    58,   118,   654,    53,   118,   654,    -1,
      53,   118,   654,    -1,    58,   118,   654,    -1,   212,   413,
      -1,   171,   170,   439,    -1,   440,    -1,   439,   107,   440,
      -1,   118,   654,    -1,   118,   654,   142,   413,    -1,   118,
     654,   545,   142,   413,    -1,   118,   654,   545,   142,   413,
     441,    -1,   118,   654,   142,   413,   441,    -1,   118,   654,
     441,    -1,   106,   652,    -1,   168,   170,   443,    -1,    69,
     168,   170,   443,    -1,   444,    -1,   443,   107,   444,    -1,
     413,    -1,   413,   445,    -1,   446,    -1,   447,    -1,   448,
      -1,   446,   447,    -1,   446,   448,    -1,   447,   448,    -1,
     446,   447,   448,    -1,    95,    -1,   116,    -1,   127,   128,
      -1,   127,   129,    -1,   106,   652,    -1,    67,   118,   450,
     188,   413,    -1,   135,   118,   450,   188,   413,    -1,   451,
      -1,   450,   107,   118,   451,    -1,   654,   147,   413,    -1,
     654,   545,   147,   413,    -1,    72,   156,   412,   187,   453,
     113,   186,   413,    -1,   454,    -1,   453,   454,    -1,   455,
     186,   413,    -1,   100,   413,    -1,   455,   100,   413,    -1,
      72,   156,   412,   187,   457,   113,   186,   394,    -1,   458,
      -1,   457,   458,    -1,   455,   186,   394,    -1,    73,   156,
     412,   187,   461,   113,   186,   413,    -1,    73,   156,   412,
     187,   461,   113,   118,   654,   186,   413,    -1,    73,   156,
     412,   187,   463,   113,   186,   394,    -1,    73,   156,   412,
     187,   461,   113,   118,   654,   186,   394,    -1,   462,    -1,
     461,   462,    -1,   100,   546,   186,   413,    -1,   100,   118,
     654,    94,   546,   186,   413,    -1,   464,    -1,   463,   464,
      -1,   100,   546,   186,   394,    -1,   100,   118,   654,    94,
     546,   186,   394,    -1,    48,   156,   412,   187,   198,   413,
     126,   413,    -1,   467,    -1,   466,   167,   467,    -1,   468,
      -1,   467,    92,   468,    -1,   470,    -1,   470,   487,   470,
      -1,   470,   488,   470,    -1,   470,   132,   470,    -1,   470,
     162,   470,    -1,    -1,   470,   157,   469,   470,    -1,   470,
     155,   470,    -1,   470,   143,   470,    -1,   470,   141,   470,
      -1,   471,    -1,   471,   249,    70,   585,   472,    -1,   473,
      -1,   473,    99,   471,    -1,    -1,   637,    -1,   474,    -1,
     474,   199,   474,    -1,   475,    -1,   474,   176,   475,    -1,
     474,   158,   475,    -1,   476,    -1,   475,   194,   476,    -1,
     475,   117,   476,    -1,   475,   146,   476,    -1,   475,   159,
     476,    -1,   477,    -1,   476,   201,   477,    -1,   476,   210,
     477,    -1,   478,    -1,   477,   150,   478,    -1,   477,   136,
     478,    -1,   479,    -1,   479,    50,   231,   546,    -1,   480,
      -1,   480,   200,    94,   546,    -1,   481,    -1,   481,   101,
      94,   482,    -1,   483,    -1,   483,   102,    94,   482,    -1,
     551,    -1,   551,   144,    -1,   485,    -1,   484,   485,    -1,
     176,    -1,   158,    -1,   484,   176,    -1,   484,   158,    -1,
     489,    -1,   486,    -1,   490,    -1,   493,    -1,   486,   193,
     493,    -1,   203,    -1,   208,    -1,   207,    -1,   206,    -1,
     205,    -1,   204,    -1,   151,    -1,   179,    -1,   140,    -1,
      75,   153,   392,   184,    -1,    75,   222,   153,   392,   184,
      -1,    75,   221,   153,   392,   184,    -1,    75,    76,   562,
     153,   392,   184,    -1,   491,   153,   184,    -1,   491,   153,
     412,   184,    -1,   492,    -1,   491,   492,    -1,   177,   654,
      17,    -1,   177,    18,    -1,   177,    19,    -1,   494,    -1,
     494,   495,    -1,   192,   495,    -1,   495,    -1,   191,    -1,
     496,    -1,   496,   191,   495,    -1,   496,   192,   495,    -1,
     497,    -1,   506,    -1,   498,    -1,   498,   507,    -1,   501,
      -1,   501,   507,    -1,   499,   503,    -1,   500,    -1,   105,
     122,    -1,   114,   122,    -1,    97,   122,    -1,   189,   122,
      -1,   115,   122,    -1,   139,   122,    -1,   138,   122,    -1,
     503,    -1,    98,   503,    -1,   502,   503,    -1,   120,    -1,
     172,   122,    -1,    90,   122,    -1,   181,   122,    -1,   180,
     122,    -1,    91,   122,    -1,   552,    -1,   504,    -1,   654,
      -1,   505,    -1,   194,    -1,    11,    -1,    12,    -1,    20,
      -1,   509,    -1,   506,   507,    -1,   506,   156,   187,    -1,
     506,   156,   518,   187,    -1,   508,    -1,   507,   508,    -1,
     154,   412,   185,    -1,   510,    -1,   512,    -1,   513,    -1,
     514,    -1,   517,    -1,   519,    -1,   515,    -1,   516,    -1,
     565,    -1,   396,    -1,   641,    -1,   638,    -1,   639,    -1,
     640,    -1,   511,    -1,   564,    -1,   110,    -1,   149,    -1,
     124,    -1,   118,   654,    -1,   156,   187,    -1,   156,   412,
     187,    -1,   119,    -1,   169,   153,   412,   184,    -1,   202,
     153,   412,   184,    -1,   655,   156,   187,    -1,   655,   156,
     518,   187,    -1,   144,    -1,   518,   107,   144,    -1,   413,
      -1,   518,   107,   413,    -1,   520,    -1,   538,    -1,   521,
      -1,   535,    -1,   536,    -1,   157,   654,   525,   130,    -1,
     157,   654,   523,   525,   130,    -1,   157,   654,   525,   197,
     195,   654,   525,   197,    -1,   157,   654,   525,   197,   522,
     195,   654,   525,   197,    -1,   157,   654,   523,   525,   197,
     195,   654,   525,   197,    -1,   157,   654,   523,   525,   197,
     522,   195,   654,   525,   197,    -1,   533,    -1,   522,   533,
      -1,   524,    -1,   523,   524,    -1,    35,   654,   525,   132,
     525,   526,    -1,    -1,    35,    -1,   183,   527,   183,    -1,
      93,   529,    93,    -1,    -1,   528,    -1,   134,    -1,   531,
      -1,   528,   134,    -1,   528,   531,    -1,    -1,   530,    -1,
     133,    -1,   532,    -1,   530,   133,    -1,   530,   532,    -1,
      28,    -1,   534,    -1,     5,    -1,   534,    -1,   520,    -1,
      10,    -1,   537,    -1,   534,    -1,     9,    -1,   123,    -1,
     125,    -1,   153,   392,   184,    -1,   213,    30,   214,    -1,
     213,   214,    -1,   174,   653,   175,    -1,   174,   653,     8,
      -1,   103,     7,    -1,   539,    -1,   540,    -1,   541,    -1,
     542,    -1,   543,    -1,   544,    -1,    43,   153,   392,   184,
      -1,    21,   391,   184,    -1,    45,   153,   412,   184,   153,
     391,   184,    -1,    22,   391,   184,    -1,    97,   153,   412,
     184,   153,   391,   184,    -1,    70,   153,   392,   184,    -1,
      39,   153,   392,   184,    -1,    23,   391,   184,    -1,    59,
     153,   412,   184,   153,   391,   184,    -1,    94,   546,    -1,
     548,    -1,   548,   547,    -1,   211,   156,   187,    -1,   144,
      -1,   194,    -1,   176,    -1,   550,    -1,   552,    -1,   152,
     156,   187,    -1,   320,   156,   187,    -1,   568,    -1,   571,
      -1,   648,    -1,   546,    -1,   549,   107,   546,    -1,   654,
      -1,   654,    -1,   554,    -1,   560,    -1,   558,    -1,   561,
      -1,   559,    -1,   557,    -1,   556,    -1,   555,    -1,   553,
      -1,   225,   156,   187,    -1,    44,   156,   187,    -1,    44,
     156,   560,   187,    -1,    44,   156,   561,   187,    -1,    70,
     156,   187,    -1,    39,   156,   187,    -1,    59,   156,   187,
      -1,    59,   156,   653,   187,    -1,    59,   156,    29,   187,
      -1,    97,   156,   187,    -1,    97,   156,   654,   187,    -1,
      97,   156,   654,   107,   562,   187,    -1,    97,   156,   194,
     187,    -1,    97,   156,   194,   107,   562,   187,    -1,    61,
     156,   654,   187,    -1,    45,   156,   187,    -1,    45,   156,
     654,   187,    -1,    45,   156,   654,   107,   562,   187,    -1,
      45,   156,   654,   107,   563,   187,    -1,    45,   156,   194,
     187,    -1,    45,   156,   194,   107,   562,   187,    -1,    45,
     156,   194,   107,   563,   187,    -1,    62,   156,   654,   187,
      -1,   654,    -1,   654,   144,    -1,    29,    -1,   566,    -1,
     567,    -1,   654,   145,   149,    -1,    47,   380,   397,    -1,
     569,    -1,   570,    -1,    47,   156,   194,   187,    -1,    47,
     156,   187,    94,   546,    -1,    47,   156,   549,   187,    94,
     546,    -1,   156,   548,   187,    -1,    33,   220,   221,    -1,
      33,   220,   222,    -1,    33,   220,   223,    -1,   226,   225,
     413,   233,   413,    -1,   226,   225,   413,    94,   232,   233,
     413,    -1,   226,   225,   413,    94,   234,   233,   413,    -1,
     226,   225,   413,   218,   413,    -1,   226,   225,   413,   219,
     413,    -1,   226,   227,   413,   233,   413,    -1,   226,   227,
     413,    94,   232,   233,   413,    -1,   226,   227,   413,    94,
     234,   233,   413,    -1,   226,   227,   413,   218,   413,    -1,
     226,   227,   413,   219,   413,    -1,   224,   225,   413,    -1,
     224,   227,   413,    -1,   229,   225,   413,   237,   413,    -1,
     229,   230,   231,   225,   413,   237,   413,    -1,   228,   225,
     413,    94,   413,    -1,   236,   118,   578,   235,   413,   186,
     413,    -1,   579,    -1,   578,   107,   118,   579,    -1,   654,
     142,   413,    -1,   244,   153,   412,   184,   581,    -1,   582,
      -1,   581,   582,    -1,   245,   584,   583,    -1,   153,   412,
     184,    -1,   504,    -1,   584,   210,   504,    -1,   588,   586,
      -1,    -1,   587,    -1,   606,    -1,   587,   606,    -1,   589,
      -1,   588,   262,   589,    -1,   590,    -1,   589,   258,   590,
      -1,   591,    -1,   590,   260,   147,   591,    -1,   592,    -1,
     259,   592,    -1,   596,   593,   594,    -1,    -1,   611,    -1,
      -1,   595,    -1,   282,   153,   412,   184,    -1,   600,   597,
      -1,   156,   585,   187,    -1,   598,    -1,    -1,   633,    -1,
     491,   153,   599,   184,    -1,    -1,   585,    -1,   601,   602,
      -1,   510,    -1,   153,   412,   184,    -1,    -1,   603,    -1,
     248,   604,    -1,   247,   605,    -1,   270,    -1,    -1,    78,
      -1,    -1,   286,    -1,   607,    -1,   608,    -1,   609,    -1,
     635,    -1,   632,    -1,   169,    -1,   284,   474,   610,    -1,
     253,   634,   610,    -1,   286,    -1,   276,    -1,   269,    -1,
     246,   612,    -1,   611,   246,   612,    -1,   613,    -1,   614,
      -1,   615,    -1,   630,    -1,   616,    -1,   624,    -1,   617,
      -1,   631,    -1,   100,   274,    -1,   100,   263,    -1,   266,
      -1,   281,    -1,   251,   274,    -1,   251,   263,    -1,    56,
     654,    29,    -1,   277,    -1,    54,   277,    -1,   279,   618,
      -1,   279,   156,   618,   619,   187,    -1,    54,   279,    -1,
     621,    -1,   113,    -1,    -1,   107,   620,    -1,   621,    -1,
     620,   107,   621,    -1,    96,    29,   622,   623,    -1,    -1,
     271,    29,    -1,    -1,   634,   265,    -1,   278,   286,   625,
     627,    -1,   278,   286,   113,   627,    -1,    54,   278,   286,
      -1,    96,    29,    -1,   156,   626,   187,    -1,    29,    -1,
     626,   107,    29,    -1,    -1,   628,    -1,   629,    -1,   628,
     629,    -1,   201,   625,    -1,   136,   625,    -1,   264,    29,
      -1,   283,    -1,    54,   283,    -1,    96,   217,    -1,    96,
     254,    -1,   255,   250,    -1,   267,   634,   280,    -1,   256,
     474,    -1,    96,   129,   474,    -1,    96,    52,   474,    -1,
     257,   474,   199,   474,    -1,   272,   636,    -1,   252,   636,
      -1,   275,    -1,   268,    -1,   285,   250,   476,    -1,   154,
     185,    -1,   154,   412,   185,    -1,   310,   311,    -1,   310,
     412,   311,    -1,   312,   313,    -1,   312,   412,   313,    -1,
     153,   642,   184,    -1,   413,   121,   413,    -1,   642,   107,
     413,   121,   413,    -1,   226,   314,   413,   233,   413,    -1,
     226,   314,   642,   233,   413,    -1,   226,   314,   413,   233,
     413,    96,   316,   413,    -1,   315,   314,   413,   233,   413,
      -1,   224,   314,   506,    -1,   228,   314,   506,    94,   413,
      -1,   229,   314,   230,   231,   506,   237,   413,    -1,   649,
      -1,   650,    -1,   651,    -1,   319,   156,   187,    -1,   317,
     156,   187,    -1,   318,   156,   187,    -1,    29,    -1,    16,
      -1,   654,    -1,   655,    -1,    97,    -1,    39,    -1,    44,
      -1,    45,    -1,   152,    -1,    48,    -1,   225,    -1,    59,
      -1,    61,    -1,    62,    -1,    70,    -1,    73,    -1,    72,
      -1,   211,    -1,   243,    -1,   656,    -1,    24,    -1,   215,
      -1,   127,    -1,    38,    -1,   261,    -1,    37,    -1,   222,
      -1,   221,    -1,   146,    -1,    43,    -1,   259,    -1,   260,
      -1,   274,    -1,   263,    -1,   251,    -1,   285,    -1,   277,
      -1,   279,    -1,   278,    -1,   283,    -1,   255,    -1,   250,
      -1,    78,    -1,   217,    -1,   254,    -1,    52,    -1,   223,
      -1,   236,    -1,   302,    -1,   230,    -1,   203,    -1,   208,
      -1,   207,    -1,   206,    -1,   205,    -1,   204,    -1,    96,
      -1,   111,    -1,   112,    -1,   186,    -1,    46,    -1,    36,
      -1,    66,    -1,    71,    -1,    58,    -1,    53,    -1,    55,
      -1,    77,    -1,    42,    -1,   147,    -1,    51,    -1,   212,
      -1,   170,    -1,   171,    -1,   168,    -1,    69,    -1,    95,
      -1,   116,    -1,   128,    -1,   129,    -1,   106,    -1,    67,
      -1,   135,    -1,   188,    -1,   100,    -1,    94,    -1,   198,
      -1,   126,    -1,   167,    -1,    92,    -1,    50,    -1,   231,
      -1,   101,    -1,   199,    -1,   117,    -1,   159,    -1,   201,
      -1,   150,    -1,   136,    -1,    75,    -1,    76,    -1,   102,
      -1,   200,    -1,   151,    -1,   182,    -1,   196,    -1,   160,
      -1,   137,    -1,   131,    -1,   166,    -1,   148,    -1,   165,
      -1,    33,    -1,    40,    -1,    57,    -1,   113,    -1,    41,
      -1,    56,    -1,   216,    -1,    49,    -1,    60,    -1,    34,
      -1,    47,    -1,   273,    -1,   249,    -1,   282,    -1,   284,
      -1,   253,    -1,   267,    -1,   280,    -1,   272,    -1,   252,
      -1,   266,    -1,   281,    -1,   271,    -1,   265,    -1,   264,
      -1,   248,    -1,   247,    -1,   256,    -1,   257,    -1,   286,
      -1,   276,    -1,   275,    -1,   270,    -1,   268,    -1,   269,
      -1,   229,    -1,   235,    -1,   232,    -1,   226,    -1,   219,
      -1,   218,    -1,   220,    -1,   237,    -1,   227,    -1,   228,
      -1,   234,    -1,   224,    -1,   233,    -1,    65,    -1,    63,
      -1,    74,    -1,   169,    -1,   202,    -1,   242,    -1,   240,
      -1,   241,    -1,   238,    -1,   239,    -1,   244,    -1,   245,
      -1,   246,    -1,    64,    -1,   295,    -1,   293,    -1,   294,
      -1,   299,    -1,   300,    -1,   301,    -1,   296,    -1,   297,
      -1,   298,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,    87,
      -1,    88,    -1,    89,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   291,    -1,   292,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,   309,
      -1,    90,    -1,   105,    -1,   114,    -1,   172,    -1,   180,
      -1,   189,    -1,   138,    -1,    91,    -1,   115,    -1,   139,
      -1,   181,    -1,   314,    -1,   315,    -1,   316,    -1,   319,
      -1,   318,    -1,   317,    -1,   320,    -1,    25,    -1
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
    1343,  1345,  1349,  1351,  1355,  1357,  1361,  1365,  1369,  1373,
    1374,  1379,  1383,  1387,  1391,  1393,  1399,  1401,  1405,  1406,
    1408,  1410,  1414,  1416,  1420,  1424,  1426,  1430,  1434,  1438,
    1442,  1444,  1448,  1452,  1454,  1458,  1462,  1464,  1469,  1471,
    1476,  1478,  1483,  1485,  1490,  1492,  1495,  1497,  1500,  1502,
    1504,  1507,  1510,  1512,  1514,  1516,  1518,  1522,  1524,  1526,
    1528,  1530,  1532,  1534,  1536,  1538,  1540,  1545,  1551,  1557,
    1564,  1568,  1573,  1575,  1578,  1582,  1585,  1588,  1590,  1593,
    1596,  1598,  1600,  1602,  1606,  1610,  1612,  1614,  1616,  1619,
    1621,  1624,  1627,  1629,  1632,  1635,  1638,  1641,  1644,  1647,
    1650,  1652,  1655,  1658,  1660,  1663,  1666,  1669,  1672,  1675,
    1677,  1679,  1681,  1683,  1685,  1687,  1689,  1691,  1693,  1696,
    1700,  1705,  1707,  1710,  1714,  1716,  1718,  1720,  1722,  1724,
    1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,
    1746,  1748,  1750,  1752,  1755,  1758,  1762,  1764,  1769,  1774,
    1778,  1783,  1785,  1789,  1791,  1795,  1797,  1799,  1801,  1803,
    1805,  1810,  1816,  1825,  1835,  1845,  1856,  1858,  1861,  1863,
    1866,  1873,  1874,  1876,  1880,  1884,  1885,  1887,  1889,  1891,
    1894,  1897,  1898,  1900,  1902,  1904,  1907,  1910,  1912,  1914,
    1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,  1936,
    1940,  1943,  1947,  1951,  1954,  1956,  1958,  1960,  1962,  1964,
    1966,  1971,  1975,  1983,  1987,  1995,  2000,  2005,  2009,  2017,
    2020,  2022,  2025,  2029,  2031,  2033,  2035,  2037,  2039,  2043,
    2047,  2049,  2051,  2053,  2055,  2059,  2061,  2063,  2065,  2067,
    2069,  2071,  2073,  2075,  2077,  2079,  2081,  2085,  2089,  2094,
    2099,  2103,  2107,  2111,  2116,  2121,  2125,  2130,  2137,  2142,
    2149,  2154,  2158,  2163,  2170,  2177,  2182,  2189,  2196,  2201,
    2203,  2206,  2208,  2210,  2212,  2216,  2220,  2222,  2224,  2229,
    2235,  2242,  2246,  2250,  2254,  2258,  2264,  2272,  2280,  2286,
    2292,  2298,  2306,  2314,  2320,  2326,  2330,  2334,  2340,  2348,
    2354,  2362,  2364,  2369,  2373,  2379,  2381,  2384,  2388,  2392,
    2394,  2398,  2401,  2402,  2404,  2406,  2409,  2411,  2415,  2417,
    2421,  2423,  2428,  2430,  2433,  2437,  2438,  2440,  2441,  2443,
    2448,  2451,  2455,  2457,  2458,  2460,  2465,  2466,  2468,  2471,
    2473,  2477,  2478,  2480,  2483,  2486,  2488,  2489,  2491,  2492,
    2494,  2496,  2498,  2500,  2502,  2504,  2506,  2510,  2514,  2516,
    2518,  2520,  2523,  2527,  2529,  2531,  2533,  2535,  2537,  2539,
    2541,  2543,  2546,  2549,  2551,  2553,  2556,  2559,  2563,  2565,
    2568,  2571,  2577,  2580,  2582,  2584,  2585,  2588,  2590,  2594,
    2599,  2600,  2603,  2604,  2607,  2612,  2617,  2621,  2624,  2628,
    2630,  2634,  2635,  2637,  2639,  2642,  2645,  2648,  2651,  2653,
    2656,  2659,  2662,  2665,  2669,  2672,  2676,  2680,  2685,  2688,
    2691,  2693,  2695,  2699,  2702,  2706,  2709,  2713,  2716,  2720,
    2724,  2728,  2734,  2740,  2746,  2755,  2761,  2765,  2771,  2779,
    2781,  2783,  2785,  2789,  2793,  2797,  2799,  2801,  2803,  2805,
    2807,  2809,  2811,  2813,  2815,  2817,  2819,  2821,  2823,  2825,
    2827,  2829,  2831,  2833,  2835,  2837,  2839,  2841,  2843,  2845,
    2847,  2849,  2851,  2853,  2855,  2857,  2859,  2861,  2863,  2865,
    2867,  2869,  2871,  2873,  2875,  2877,  2879,  2881,  2883,  2885,
    2887,  2889,  2891,  2893,  2895,  2897,  2899,  2901,  2903,  2905,
    2907,  2909,  2911,  2913,  2915,  2917,  2919,  2921,  2923,  2925,
    2927,  2929,  2931,  2933,  2935,  2937,  2939,  2941,  2943,  2945,
    2947,  2949,  2951,  2953,  2955,  2957,  2959,  2961,  2963,  2965,
    2967,  2969,  2971,  2973,  2975,  2977,  2979,  2981,  2983,  2985,
    2987,  2989,  2991,  2993,  2995,  2997,  2999,  3001,  3003,  3005,
    3007,  3009,  3011,  3013,  3015,  3017,  3019,  3021,  3023,  3025,
    3027,  3029,  3031,  3033,  3035,  3037,  3039,  3041,  3043,  3045,
    3047,  3049,  3051,  3053,  3055,  3057,  3059,  3061,  3063,  3065,
    3067,  3069,  3071,  3073,  3075,  3077,  3079,  3081,  3083,  3085,
    3087,  3089,  3091,  3093,  3095,  3097,  3099,  3101,  3103,  3105,
    3107,  3109,  3111,  3113,  3115,  3117,  3119,  3121,  3123,  3125,
    3127,  3129,  3131,  3133,  3135,  3137,  3139,  3141,  3143,  3145,
    3147,  3149,  3151,  3153,  3155,  3157,  3159,  3161,  3163,  3165,
    3167,  3169,  3171,  3173,  3175,  3177,  3179,  3181,  3183,  3185,
    3187,  3189,  3191,  3193,  3195,  3197,  3199,  3201,  3203,  3205,
    3207,  3209,  3211,  3213,  3215,  3217,  3219,  3221,  3223,  3225,
    3227,  3229,  3231,  3233,  3235,  3237,  3239,  3241,  3243,  3245,
    3247
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1051,  1051,  1052,  1056,  1060,  1068,  1074,  1078,  1087,
    1093,  1101,  1107,  1118,  1123,  1131,  1138,  1145,  1154,  1161,
    1169,  1177,  1185,  1196,  1201,  1208,  1215,  1227,  1237,  1244,
    1251,  1263,  1264,  1265,  1266,  1267,  1272,  1273,  1274,  1275,
    1276,  1277,  1278,  1281,  1286,  1291,  1299,  1307,  1315,  1320,
    1328,  1333,  1341,  1346,  1354,  1359,  1364,  1369,  1377,  1379,
    1382,  1392,  1397,  1405,  1413,  1424,  1431,  1442,  1447,  1455,
    1462,  1469,  1478,  1491,  1499,  1506,  1516,  1523,  1530,  1541,
    1542,  1543,  1544,  1545,  1546,  1547,  1548,  1553,  1559,  1568,
    1575,  1585,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,
    1603,  1604,  1609,  1617,  1625,  1633,  1640,  1648,  1655,  1660,
    1668,  1676,  1690,  1704,  1721,  1726,  1734,  1742,  1753,  1758,
    1767,  1772,  1779,  1784,  1794,  1799,  1808,  1814,  1827,  1832,
    1840,  1851,  1866,  1878,  1893,  1898,  1903,  1908,  1916,  1923,
    1934,  1939,  1949,  1958,  1967,  1976,  1988,  1992,  1998,  2002,
    2012,  2022,  2035,  2041,  2050,  2055,  2062,  2069,  2080,  2090,
    2100,  2110,  2128,  2148,  2152,  2157,  2164,  2168,  2173,  2180,
    2185,  2197,  2204,  2214,  2229,  2230,  2231,  2232,  2233,  2234,
    2235,  2237,  2238,  2239,  2240,  2241,  2246,  2251,  2259,  2276,
    2284,  2292,  2299,  2306,  2317,  2326,  2335,  2344,  2357,  2365,
    2373,  2381,  2396,  2401,  2409,  2423,  2440,  2465,  2473,  2480,
    2491,  2501,  2506,  2519,  2536,  2537,  2538,  2539,  2540,  2541,
    2546,  2547,  2550,  2551,  2552,  2553,  2554,  2557,  2558,  2559,
    2560,  2561,  2566,  2580,  2588,  2593,  2601,  2606,  2611,  2619,
    2628,  2640,  2650,  2663,  2671,  2672,  2673,  2678,  2679,  2680,
    2681,  2682,  2687,  2694,  2704,  2710,  2719,  2729,  2736,  2744,
    2756,  2766,  2776,  2786,  2796,  2806,  2816,  2826,  2837,  2846,
    2856,  2866,  2882,  2891,  2900,  2908,  2914,  2926,  2934,  2944,
    2952,  2964,  2970,  2981,  2983,  2987,  2995,  2999,  3004,  3008,
    3012,  3016,  3026,  3034,  3041,  3047,  3057,  3061,  3065,  3073,
    3081,  3089,  3101,  3109,  3115,  3125,  3131,  3141,  3145,  3155,
    3161,  3167,  3173,  3182,  3191,  3200,  3213,  3217,  3225,  3231,
    3241,  3249,  3258,  3271,  3278,  3290,  3294,  3306,  3313,  3319,
    3328,  3335,  3341,  3352,  3359,  3365,  3374,  3383,  3390,  3401,
    3408,  3420,  3426,  3438,  3444,  3455,  3461,  3472,  3478,  3489,
    3498,  3502,  3511,  3515,  3523,  3527,  3537,  3544,  3553,  3563,
    3562,  3576,  3585,  3594,  3607,  3611,  3623,  3627,  3635,  3638,
    3645,  3649,  3658,  3662,  3666,  3674,  3678,  3684,  3690,  3696,
    3706,  3710,  3714,  3722,  3726,  3732,  3742,  3746,  3756,  3760,
    3770,  3774,  3784,  3788,  3798,  3802,  3811,  3815,  3823,  3827,
    3831,  3835,  3845,  3849,  3853,  3860,  3865,  3873,  3877,  3881,
    3885,  3889,  3893,  3901,  3905,  3909,  3917,  3921,  3925,  3929,
    3940,  3946,  3956,  3962,  3972,  3976,  3980,  4018,  4022,  4032,
    4042,  4055,  4064,  4074,  4078,  4087,  4091,  4100,  4106,  4114,
    4120,  4132,  4138,  4148,  4152,  4156,  4160,  4164,  4170,  4176,
    4184,  4188,  4196,  4200,  4211,  4215,  4219,  4225,  4229,  4243,
    4247,  4255,  4259,  4269,  4273,  4277,  4281,  4290,  4294,  4298,
    4302,  4310,  4316,  4326,  4334,  4338,  4342,  4346,  4350,  4354,
    4358,  4362,  4366,  4370,  4375,  4379,  4383,  4387,  4395,  4399,
    4407,  4414,  4421,  4432,  4440,  4444,  4452,  4460,  4468,  4522,
    4526,  4551,  4557,  4563,  4569,  4579,  4583,  4591,  4595,  4599,
    4607,  4617,  4627,  4644,  4661,  4678,  4700,  4706,  4717,  4723,
    4734,  4745,  4747,  4751,  4756,  4766,  4769,  4776,  4782,  4788,
    4796,  4809,  4812,  4819,  4825,  4831,  4838,  4849,  4853,  4863,
    4867,  4877,  4881,  4885,  4890,  4899,  4905,  4911,  4917,  4925,
    4930,  4938,  4943,  4951,  4959,  4964,  4969,  4974,  4979,  4984,
    4993,  5001,  5005,  5022,  5026,  5034,  5042,  5050,  5054,  5062,
    5070,  5074,  5078,  5113,  5119,  5125,  5135,  5139,  5143,  5147,
    5151,  5155,  5159,  5166,  5172,  5182,  5190,  5198,  5202,  5206,
    5210,  5214,  5218,  5222,  5226,  5230,  5238,  5246,  5250,  5254,
    5264,  5272,  5280,  5284,  5288,  5296,  5300,  5306,  5312,  5316,
    5326,  5334,  5338,  5344,  5353,  5362,  5368,  5374,  5384,  5401,
    5408,  5423,  5459,  5463,  5471,  5479,  5491,  5495,  5503,  5511,
    5515,  5526,  5543,  5549,  5555,  5565,  5569,  5575,  5581,  5585,
    5591,  5595,  5601,  5607,  5614,  5624,  5629,  5637,  5643,  5653,
    5675,  5684,  5690,  5703,  5717,  5724,  5730,  5740,  5749,  5757,
    5763,  5781,  5789,  5793,  5800,  5805,  5813,  5817,  5824,  5828,
    5835,  5839,  5846,  5850,  5859,  5872,  5875,  5883,  5886,  5894,
    5902,  5910,  5914,  5922,  5925,  5933,  5945,  5948,  5956,  5968,
    5974,  5984,  5987,  5995,  5999,  6003,  6011,  6014,  6022,  6025,
    6033,  6037,  6041,  6045,  6049,  6057,  6065,  6077,  6089,  6093,
    6097,  6105,  6111,  6121,  6125,  6129,  6133,  6137,  6141,  6145,
    6149,  6157,  6161,  6165,  6169,  6177,  6183,  6193,  6203,  6207,
    6215,  6225,  6236,  6243,  6247,  6255,  6258,  6265,  6270,  6279,
    6289,  6292,  6299,  6303,  6311,  6320,  6327,  6337,  6341,  6348,
    6354,  6364,  6367,  6374,  6379,  6391,  6399,  6411,  6419,  6423,
    6431,  6435,  6439,  6447,  6455,  6459,  6463,  6467,  6475,  6483,
    6495,  6499,  6507,  6521,  6525,  6532,  6537,  6545,  6550,  6559,
    6567,  6573,  6583,  6589,  6599,  6606,  6613,  6638,  6666,  6694,
    6698,  6702,  6709,  6716,  6723,  6735,  6739,  6740,  6753,  6754,
    6755,  6756,  6757,  6758,  6759,  6760,  6761,  6762,  6763,  6764,
    6765,  6766,  6767,  6768,  6772,  6773,  6774,  6775,  6776,  6777,
    6778,  6779,  6780,  6781,  6782,  6783,  6784,  6785,  6786,  6787,
    6788,  6789,  6790,  6791,  6792,  6793,  6794,  6795,  6796,  6797,
    6798,  6799,  6800,  6801,  6802,  6803,  6804,  6805,  6806,  6807,
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
    6982
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
  const int xquery_parser::yylast_ = 17567;
  const int xquery_parser::yynnts_ = 323;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 608;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 334;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 588;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba

/* Line 1136 of lalr1.cc  */
#line 17853 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"


/* Line 1138 of lalr1.cc  */
#line 6986 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"


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

