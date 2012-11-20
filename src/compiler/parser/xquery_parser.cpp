/* A Bison parser, made by GNU Bison 2.6.2.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++
   
      Copyright (C) 2002-2012 Free Software Foundation, Inc.
   
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
/* Line 278 of lalr1.cc  */
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


/* Line 278 of lalr1.cc  */
#line 75 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */
/* Line 284 of lalr1.cc  */
#line 908 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}
/* Line 284 of lalr1.cc  */
#line 1033 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex


/* Line 284 of lalr1.cc  */
#line 102 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"


# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

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

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


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
/* Line 352 of lalr1.cc  */
#line 197 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"

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
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
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
        case 110: /* "'DECIMAL'" */
/* Line 453 of lalr1.cc  */
#line 906 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).decval); };
/* Line 453 of lalr1.cc  */
#line 303 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "'DOUBLE'" */
/* Line 453 of lalr1.cc  */
#line 905 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).dval); };
/* Line 453 of lalr1.cc  */
#line 310 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "'INTEGER'" */
/* Line 453 of lalr1.cc  */
#line 904 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).ival); };
/* Line 453 of lalr1.cc  */
#line 317 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* VersionDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 324 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* MainModule */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 331 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* LibraryModule */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 338 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* ModuleDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 345 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* SIND_DeclList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 352 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* SIND_Decl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 359 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* Setter */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 366 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* BoundarySpaceDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 373 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* DefaultCollationDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 380 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* BaseURIDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 387 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* ConstructionDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 394 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* OrderingModeDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 401 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* EmptyOrderDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 408 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* CopyNamespacesDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 415 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* Import */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 422 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* SchemaImport */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 429 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* URILiteralList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 436 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* SchemaPrefix */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 443 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* ModuleImport */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 450 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* NamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 457 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* DefaultNamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 464 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* VFO_DeclList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 471 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* VFO_Decl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 478 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* DecimalFormatDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 485 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 362: /* DecimalFormatParamList */
/* Line 453 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).vstrpair); };
/* Line 453 of lalr1.cc  */
#line 492 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* DecimalFormatParam */
/* Line 453 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).strpair); };
/* Line 453 of lalr1.cc  */
#line 499 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* OptionDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 506 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* FTOptionDecl */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 513 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* CtxItemDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 520 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* CtxItemDecl2 */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 527 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* CtxItemDecl3 */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 534 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* CtxItemDecl4 */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 541 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* VarDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 548 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* VarNameAndType */
/* Line 453 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).varnametype); };
/* Line 453 of lalr1.cc  */
#line 555 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* AnnotationList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 562 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* Annotation */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 569 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* AnnotationLiteralList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 576 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* FunctionDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 583 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* FunctionDecl2 */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 590 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* FunctionDeclSimple */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 597 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* FunctionDeclUpdating */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 604 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* FunctionSig */
/* Line 453 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).fnsig); };
/* Line 453 of lalr1.cc  */
#line 611 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* ParamList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 618 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 382: /* Param */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 625 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* CollectionDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 632 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* IndexDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 639 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* IndexKeyList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 646 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* IndexKeySpec */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 653 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* IntegrityConstraintDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 660 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* QueryBody */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 667 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* StatementsAndOptionalExprTop */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 674 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* StatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 681 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* StatementsAndExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 688 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* Statements */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 695 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* Statement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 702 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* BlockStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 709 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* BlockExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 716 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 397: /* EnclosedStatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 723 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 398: /* VarDeclStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 730 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* AssignStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 737 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* ApplyStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 744 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* ExitStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 751 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* WhileStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 758 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* FlowCtlStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 765 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* FLWORStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 772 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* ReturnStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 779 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* IfStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 786 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* TryStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 793 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* CatchListStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 800 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* CatchStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 807 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* Expr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 814 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* ExprSingle */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 821 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* ExprSimple */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 828 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 415: /* FLWORExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 835 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 416: /* ReturnExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 842 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* FLWORWinCond */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 849 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* WindowClause */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 856 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 421: /* CountClause */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 863 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* ForLetWinClause */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 870 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* FLWORClauseList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 877 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* ForClause */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 884 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* VarInDeclList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 891 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* VarInDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 898 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* PositionalVar */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 905 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* FTScoreVar */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 912 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* LetClause */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 919 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* VarGetsDeclList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* VarGetsDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 933 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* WindowVarDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 940 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* WindowVars */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 947 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* WindowVars3 */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 954 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* WindowVars2 */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 961 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* WhereClause */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 968 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* GroupByClause */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 975 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* GroupSpecList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 982 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* GroupSpec */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 989 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* GroupCollationSpec */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 996 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* OrderByClause */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1003 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* OrderSpecList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1010 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* OrderSpec */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1017 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* OrderModifier */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1024 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* OrderDirSpec */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1031 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* OrderEmptySpec */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1038 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* OrderCollationSpec */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1045 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* QuantifiedExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1052 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* QVarInDeclList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1059 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* QVarInDecl */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1066 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* SwitchExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1073 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* SwitchCaseClauseList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1080 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* SwitchCaseClause */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1087 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 455: /* SwitchCaseOperandList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1094 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 456: /* SwitchStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1101 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* TypeswitchExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1108 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* TypeswitchStatement */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1115 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 461: /* CaseClauseList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1122 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 462: /* CaseClause */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1129 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* IfExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1136 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* OrExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1143 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 467: /* AndExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1150 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* ComparisonExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1157 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* FTContainsExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1164 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* StringConcatExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1171 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* opt_FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1178 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* RangeExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1185 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* AdditiveExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1192 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* MultiplicativeExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1199 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* UnionExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1206 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* IntersectExceptExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1213 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* InstanceofExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1220 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* TreatExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1227 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* CastableExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1234 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* CastExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1241 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* UnaryExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1248 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* SignList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1255 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* ValueExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1262 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* SimpleMapExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1269 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* ValueComp */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1276 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* NodeComp */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1283 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* ValidateExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1290 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* ExtensionExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1297 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 490: /* Pragma_list */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1304 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* Pragma */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1311 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* PathExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1318 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* RelativePathExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* StepExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1332 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* AxisStep */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1339 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* ForwardStep */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1346 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* ForwardAxis */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1353 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* AbbrevForwardStep */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1360 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* ReverseStep */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1367 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* ReverseAxis */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1374 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* NodeTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1381 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* NameTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1388 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* Wildcard */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1395 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* FilterExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1402 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* PredicateList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1409 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* Predicate */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1416 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* PrimaryExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1423 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* Literal */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1430 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* NumericLiteral */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1437 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* VarRef */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1444 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* ParenthesizedExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1451 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* ContextItemExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1458 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* OrderedExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1465 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* UnorderedExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1472 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* FunctionCall */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1479 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* ArgList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1486 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* Constructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1493 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* DirectConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1500 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* DirElemConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1507 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 521: /* DirElemContentList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1514 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* DirAttributeList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1521 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* DirAttr */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1528 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* DirAttributeValue */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1535 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* opt_QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1542 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1549 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* opt_AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1556 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1563 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* QuoteAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1570 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* AposAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1577 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* DirElemContent */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1584 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* CommonContent */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1591 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* DirCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1598 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* DirPIConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1605 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* CDataSection */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1612 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* ComputedConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1619 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* CompDocConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1626 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* CompElemConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1633 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* CompAttrConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1640 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* CompTextConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1647 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* CompCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1654 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* CompPIConstructor */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1661 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* SingleType */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1668 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* TypeDeclaration */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1675 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* SequenceType */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1682 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* OccurrenceIndicator */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1689 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* ItemType */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1696 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* TypeList */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1703 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* AtomicType */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1710 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* KindTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1717 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* AnyKindTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1724 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* DocumentTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1731 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* TextTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1738 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* CommentTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1745 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* PITest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1752 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* AttributeTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1759 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* SchemaAttributeTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1766 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* ElementTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1773 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* SchemaElementTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1780 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 561: /* TypeName */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1787 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 562: /* TypeName_WITH_HOOK */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1794 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 563: /* StringLiteral */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1801 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 568: /* AnyFunctionTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1808 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* TypedFunctionTest */
/* Line 453 of lalr1.cc  */
#line 920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1815 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* InsertExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1822 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* DeleteExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1829 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* ReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1836 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* RenameExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1843 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* TransformExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1850 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* VarNameList */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1857 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* VarNameDecl */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1864 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* TryExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1871 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* CatchListExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1878 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* CatchExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1885 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 582: /* BracedExpr */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1892 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 583: /* NameTestList */
/* Line 453 of lalr1.cc  */
#line 932 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).name_test_list); };
/* Line 453 of lalr1.cc  */
#line 1899 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* FTSelection */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1906 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* FTOr */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1913 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* FTAnd */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1920 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* FTMildNot */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1927 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 590: /* FTUnaryNot */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1934 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* FTPrimaryWithOptions */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1941 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* opt_FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1948 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* FTWeight */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1955 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 595: /* FTPrimary */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1962 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* opt_FTTimes */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1969 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* FTExtensionSelection */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1976 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* FTWords */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1983 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 600: /* FTWordsValue */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1990 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* FTAnyallOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1997 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* FTPosFilter */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2004 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* FTOrder */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2011 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* FTWindow */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2018 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* FTDistance */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2025 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* FTUnit */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2032 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2039 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* FTMatchOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2046 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* FTCaseOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2053 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* FTDiacriticsOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2060 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 614: /* FTExtensionOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2067 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 615: /* FTStemOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2074 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 616: /* FTThesaurusOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2081 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* FTThesaurusID */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2088 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 623: /* FTStopWordOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2095 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 624: /* FTStopWords */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2102 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* FTStopWordsInclExcl */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2109 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* FTLanguageOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2116 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* FTWildCardOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2123 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* FTContent */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2130 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* FTTimes */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2137 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* FTRange */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2144 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* FTScope */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2151 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* FTBigUnit */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2158 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2165 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* JSONArrayConstructor */
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2172 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* JSONSimpleObjectUnion */
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2179 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* JSONAccumulatorObjectUnion */
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2186 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* JSONObjectConstructor */
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2193 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* JSONPairList */
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2200 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* JSONInsertExpr */
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2207 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* JSONAppendExpr */
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2214 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 644: /* JSONDeleteExpr */
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2221 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 645: /* JSONRenameExpr */
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2228 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 646: /* JSONReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2235 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 653: /* QNAME */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2242 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 654: /* FUNCTION_NAME */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2249 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
	break;
      case 655: /* EQNAME */
/* Line 453 of lalr1.cc  */
#line 929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2256 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
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
/* Line 538 of lalr1.cc  */
#line 140 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}
/* Line 538 of lalr1.cc  */
#line 2351 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"

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
/* Line 661 of lalr1.cc  */
#line 1051 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:
/* Line 661 of lalr1.cc  */
#line 1055 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 1059 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 1070 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 1079 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 1085 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 1093 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 1099 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 1110 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 1115 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 1123 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 1130 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 1137 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 1146 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 1153 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 1161 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 1169 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 1177 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 1188 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 1193 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 1200 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 1207 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 1219 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 1229 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 1236 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 1243 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      // error
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 42:
/* Line 661 of lalr1.cc  */
#line 1278 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 1283 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 1291 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 1299 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 1307 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 1312 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 1320 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 1325 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 1333 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 1338 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 1346 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 1351 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 1356 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 1361 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 1374 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 1384 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 1389 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 1397 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 1405 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 1416 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 1423 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 1434 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 1439 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 67:
/* Line 661 of lalr1.cc  */
#line 1447 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 68:
/* Line 661 of lalr1.cc  */
#line 1454 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 1461 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 70:
/* Line 661 of lalr1.cc  */
#line 1470 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 71:
/* Line 661 of lalr1.cc  */
#line 1483 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 72:
/* Line 661 of lalr1.cc  */
#line 1491 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 73:
/* Line 661 of lalr1.cc  */
#line 1498 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 1508 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 1515 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 1522 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 1545 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 1551 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 1560 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 1567 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 1577 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 1586 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 1587 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 1588 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 1589 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 1590 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 1591 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 1592 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 1593 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 1594 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 1595 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 1601 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 1609 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 1617 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 1625 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 1632 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 1640 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 1647 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 1652 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 1660 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 1668 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 1682 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 1696 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 1713 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 1718 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 1726 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 1734 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 1745 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 1750 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 1759 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 1764 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 1771 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 1776 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 1786 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 1791 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 1800 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 1806 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 1819 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 1824 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 1832 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 1843 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 1858 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 1870 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 1885 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 1890 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 1895 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 1900 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 1908 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 1915 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 1926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 1931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 1941 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 1950 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 1959 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 1968 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 1980 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 1984 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 1990 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 1994 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 2004 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(8) - (1)].sval)) );
    }
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 2014 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));

      static_cast<AST_IndexDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(9) - (1)].sval)) );
    }
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 2027 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 2033 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 2042 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 2047 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 2054 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 2061 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 2073 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 157:
/* Line 661 of lalr1.cc  */
#line 2083 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 158:
/* Line 661 of lalr1.cc  */
#line 2093 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 159:
/* Line 661 of lalr1.cc  */
#line 2104 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2120 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2140 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 2144 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 2148 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 2156 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 2160 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 2164 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 2172 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 2177 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 2189 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 2196 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 2225 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 2230 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 2238 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2255 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 2263 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 2271 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 2278 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 2285 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 2296 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2305 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2314 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2323 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2336 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 2344 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 2352 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 2360 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2375 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 2380 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 2388 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2402 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2419 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2444 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 205:
/* Line 661 of lalr1.cc  */
#line 2452 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 206:
/* Line 661 of lalr1.cc  */
#line 2459 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 207:
/* Line 661 of lalr1.cc  */
#line 2470 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 2480 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 2485 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 210:
/* Line 661 of lalr1.cc  */
#line 2497 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr); // to prevent the Bison warning
      error((yylocation_stack_[(4) - (2)]), "syntax error, unexpected ExprSingle (missing comma \",\" between expressions?)");
      delete (yysemantic_stack_[(4) - (1)].expr); // these need to be deleted here because the parser deallocator will skip them
      delete (yysemantic_stack_[(4) - (3)].expr);
      YYERROR;
    }
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 2506 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      // This rule will never be reached, as the ERROR rule will stop the parser,
      // but it is nevertheless needed to fix a testcase with an unterminated comment which
      // would otherwise cycle indefinitely
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      YYERROR;
    }
    break;

  case 230:
/* Line 661 of lalr1.cc  */
#line 2549 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 231:
/* Line 661 of lalr1.cc  */
#line 2563 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 2571 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 2576 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 2584 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 2589 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 2594 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 2602 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 238:
/* Line 661 of lalr1.cc  */
#line 2611 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 239:
/* Line 661 of lalr1.cc  */
#line 2623 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 240:
/* Line 661 of lalr1.cc  */
#line 2633 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowClause (LOC ((yyloc)),
                             ((yysemantic_stack_[(4) - (2)].strval) == parser::the_tumbling ?
                              WindowClause::tumbling_window :
                              WindowClause::sliding_window),
                             dynamic_cast<WindowVarDecl *> ((yysemantic_stack_[(4) - (3)].node)),
                             dynamic_cast<FLWORWinCond *> ((yysemantic_stack_[(4) - (4)].node)), NULL);
    }
    break;

  case 241:
/* Line 661 of lalr1.cc  */
#line 2646 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 250:
/* Line 661 of lalr1.cc  */
#line 2670 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 251:
/* Line 661 of lalr1.cc  */
#line 2677 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 252:
/* Line 661 of lalr1.cc  */
#line 2687 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 253:
/* Line 661 of lalr1.cc  */
#line 2693 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected QName \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 254:
/* Line 661 of lalr1.cc  */
#line 2702 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 2712 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 2719 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 2727 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 258:
/* Line 661 of lalr1.cc  */
#line 2739 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 259:
/* Line 661 of lalr1.cc  */
#line 2749 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 260:
/* Line 661 of lalr1.cc  */
#line 2759 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 261:
/* Line 661 of lalr1.cc  */
#line 2769 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 262:
/* Line 661 of lalr1.cc  */
#line 2779 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 263:
/* Line 661 of lalr1.cc  */
#line 2789 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 264:
/* Line 661 of lalr1.cc  */
#line 2799 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 265:
/* Line 661 of lalr1.cc  */
#line 2809 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 266:
/* Line 661 of lalr1.cc  */
#line 2820 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarInDecl(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                         NULL,NULL,
                         dynamic_cast<FTScoreVar*>((yysemantic_stack_[(4) - (2)].node)),
                         (yysemantic_stack_[(4) - (4)].expr),
                         false);
    }
    break;

  case 267:
/* Line 661 of lalr1.cc  */
#line 2829 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 268:
/* Line 661 of lalr1.cc  */
#line 2839 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 269:
/* Line 661 of lalr1.cc  */
#line 2849 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 270:
/* Line 661 of lalr1.cc  */
#line 2865 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 2874 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 2883 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 2891 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 274:
/* Line 661 of lalr1.cc  */
#line 2897 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 2909 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 276:
/* Line 661 of lalr1.cc  */
#line 2917 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 2927 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 2935 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 279:
/* Line 661 of lalr1.cc  */
#line 2947 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 2953 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 2966 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 2970 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 2978 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 285:
/* Line 661 of lalr1.cc  */
#line 2982 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 2991 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 2995 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 2999 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 3009 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 3017 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 3024 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 3030 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 3040 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 3044 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 3048 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 3056 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 3064 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 3072 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 3084 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 3092 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 3098 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 3108 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 3114 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 3124 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 3128 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 3138 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 3144 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 3150 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 3156 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (2)].node)),
                NULL
            );
        }
    break;

  case 311:
/* Line 661 of lalr1.cc  */
#line 3165 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(2) - (1)].node)),
                NULL,
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 312:
/* Line 661 of lalr1.cc  */
#line 3174 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                NULL,
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 3183 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)),
                dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 3196 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 3200 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 3208 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 3214 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 3224 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 3232 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_some,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 3241 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new QuantifiedExpr(
                LOC((yyloc)),
                ParseConstants::quant_every,
                dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(5) - (3)].node)),
                (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 3254 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 3261 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 3273 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 3277 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 3289 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 3296 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 3302 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 3311 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 3318 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 3324 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 3335 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 3342 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 3348 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 3357 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 3366 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 3373 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 337:
/* Line 661 of lalr1.cc  */
#line 3384 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
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
/* Line 661 of lalr1.cc  */
#line 3403 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 3409 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 3421 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 3427 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 3438 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 3444 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 3455 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 3461 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 3472 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 3481 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 3485 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 3494 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 3498 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 3506 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 3510 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 354:
/* Line 661 of lalr1.cc  */
#line 3520 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 3527 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_eq ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 3536 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ne ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 357:
/* Line 661 of lalr1.cc  */
#line 3545 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 3550 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_lt ),
                (yysemantic_stack_[(4) - (1)].expr),
                (yysemantic_stack_[(4) - (4)].expr)
            );
        }
    break;

  case 359:
/* Line 661 of lalr1.cc  */
#line 3559 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_le ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 360:
/* Line 661 of lalr1.cc  */
#line 3568 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_gt ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 3577 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                new GeneralComp( LOC((yyloc)), ParseConstants::op_ge ),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 362:
/* Line 661 of lalr1.cc  */
#line 3590 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 3594 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FTContainsExpr(
                LOC((yyloc)),
                (yysemantic_stack_[(5) - (1)].expr),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(5) - (4)].node)),
                dynamic_cast<FTIgnoreOption*>((yysemantic_stack_[(5) - (5)].node))
            );
        }
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 3606 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 3610 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 3617 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 3621 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 3628 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 3632 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 3641 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 3645 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 3649 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 3657 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 3661 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 3667 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 3673 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 3679 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 3689 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 3693 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 3697 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 3705 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 3709 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 3715 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 3725 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 3729 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 3739 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 3743 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 3753 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 3757 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:
/* Line 661 of lalr1.cc  */
#line 3767 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:
/* Line 661 of lalr1.cc  */
#line 3771 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:
/* Line 661 of lalr1.cc  */
#line 3781 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:
/* Line 661 of lalr1.cc  */
#line 3785 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 394:
/* Line 661 of lalr1.cc  */
#line 3793 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 395:
/* Line 661 of lalr1.cc  */
#line 3797 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 396:
/* Line 661 of lalr1.cc  */
#line 3801 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 397:
/* Line 661 of lalr1.cc  */
#line 3805 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 398:
/* Line 661 of lalr1.cc  */
#line 3815 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:
/* Line 661 of lalr1.cc  */
#line 3819 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:
/* Line 661 of lalr1.cc  */
#line 3823 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:
/* Line 661 of lalr1.cc  */
#line 3830 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 402:
/* Line 661 of lalr1.cc  */
#line 3835 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 403:
/* Line 661 of lalr1.cc  */
#line 3843 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 404:
/* Line 661 of lalr1.cc  */
#line 3847 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 405:
/* Line 661 of lalr1.cc  */
#line 3851 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 406:
/* Line 661 of lalr1.cc  */
#line 3855 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 407:
/* Line 661 of lalr1.cc  */
#line 3859 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 408:
/* Line 661 of lalr1.cc  */
#line 3863 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 409:
/* Line 661 of lalr1.cc  */
#line 3871 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 410:
/* Line 661 of lalr1.cc  */
#line 3875 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 411:
/* Line 661 of lalr1.cc  */
#line 3879 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 412:
/* Line 661 of lalr1.cc  */
#line 3887 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 413:
/* Line 661 of lalr1.cc  */
#line 3891 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 414:
/* Line 661 of lalr1.cc  */
#line 3895 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 415:
/* Line 661 of lalr1.cc  */
#line 3899 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 416:
/* Line 661 of lalr1.cc  */
#line 3910 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 417:
/* Line 661 of lalr1.cc  */
#line 3916 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 418:
/* Line 661 of lalr1.cc  */
#line 3926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 419:
/* Line 661 of lalr1.cc  */
#line 3932 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 420:
/* Line 661 of lalr1.cc  */
#line 3942 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 421:
/* Line 661 of lalr1.cc  */
#line 3946 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 422:
/* Line 661 of lalr1.cc  */
#line 3950 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 423:
/* Line 661 of lalr1.cc  */
#line 3988 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 424:
/* Line 661 of lalr1.cc  */
#line 3992 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 425:
/* Line 661 of lalr1.cc  */
#line 4002 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 426:
/* Line 661 of lalr1.cc  */
#line 4012 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 427:
/* Line 661 of lalr1.cc  */
#line 4025 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 428:
/* Line 661 of lalr1.cc  */
#line 4034 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 429:
/* Line 661 of lalr1.cc  */
#line 4044 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 430:
/* Line 661 of lalr1.cc  */
#line 4048 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 431:
/* Line 661 of lalr1.cc  */
#line 4057 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 432:
/* Line 661 of lalr1.cc  */
#line 4061 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 433:
/* Line 661 of lalr1.cc  */
#line 4070 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 434:
/* Line 661 of lalr1.cc  */
#line 4076 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 435:
/* Line 661 of lalr1.cc  */
#line 4084 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 436:
/* Line 661 of lalr1.cc  */
#line 4090 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 437:
/* Line 661 of lalr1.cc  */
#line 4102 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 438:
/* Line 661 of lalr1.cc  */
#line 4108 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 439:
/* Line 661 of lalr1.cc  */
#line 4118 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 440:
/* Line 661 of lalr1.cc  */
#line 4122 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 441:
/* Line 661 of lalr1.cc  */
#line 4126 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 442:
/* Line 661 of lalr1.cc  */
#line 4130 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 443:
/* Line 661 of lalr1.cc  */
#line 4134 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 444:
/* Line 661 of lalr1.cc  */
#line 4140 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 445:
/* Line 661 of lalr1.cc  */
#line 4146 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 446:
/* Line 661 of lalr1.cc  */
#line 4154 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 447:
/* Line 661 of lalr1.cc  */
#line 4158 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 448:
/* Line 661 of lalr1.cc  */
#line 4166 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 449:
/* Line 661 of lalr1.cc  */
#line 4170 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 450:
/* Line 661 of lalr1.cc  */
#line 4181 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 451:
/* Line 661 of lalr1.cc  */
#line 4185 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 452:
/* Line 661 of lalr1.cc  */
#line 4189 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 453:
/* Line 661 of lalr1.cc  */
#line 4195 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 454:
/* Line 661 of lalr1.cc  */
#line 4199 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 455:
/* Line 661 of lalr1.cc  */
#line 4213 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 456:
/* Line 661 of lalr1.cc  */
#line 4217 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 457:
/* Line 661 of lalr1.cc  */
#line 4225 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 458:
/* Line 661 of lalr1.cc  */
#line 4229 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 459:
/* Line 661 of lalr1.cc  */
#line 4239 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 460:
/* Line 661 of lalr1.cc  */
#line 4243 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 461:
/* Line 661 of lalr1.cc  */
#line 4247 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 462:
/* Line 661 of lalr1.cc  */
#line 4251 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 463:
/* Line 661 of lalr1.cc  */
#line 4260 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 464:
/* Line 661 of lalr1.cc  */
#line 4264 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 465:
/* Line 661 of lalr1.cc  */
#line 4268 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 466:
/* Line 661 of lalr1.cc  */
#line 4272 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 467:
/* Line 661 of lalr1.cc  */
#line 4280 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 468:
/* Line 661 of lalr1.cc  */
#line 4286 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 469:
/* Line 661 of lalr1.cc  */
#line 4296 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 470:
/* Line 661 of lalr1.cc  */
#line 4304 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:
/* Line 661 of lalr1.cc  */
#line 4308 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:
/* Line 661 of lalr1.cc  */
#line 4312 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:
/* Line 661 of lalr1.cc  */
#line 4316 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:
/* Line 661 of lalr1.cc  */
#line 4320 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:
/* Line 661 of lalr1.cc  */
#line 4324 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:
/* Line 661 of lalr1.cc  */
#line 4328 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:
/* Line 661 of lalr1.cc  */
#line 4332 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:
/* Line 661 of lalr1.cc  */
#line 4336 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:
/* Line 661 of lalr1.cc  */
#line 4340 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:
/* Line 661 of lalr1.cc  */
#line 4345 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:
/* Line 661 of lalr1.cc  */
#line 4349 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:
/* Line 661 of lalr1.cc  */
#line 4353 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:
/* Line 661 of lalr1.cc  */
#line 4357 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:
/* Line 661 of lalr1.cc  */
#line 4365 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 485:
/* Line 661 of lalr1.cc  */
#line 4369 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 486:
/* Line 661 of lalr1.cc  */
#line 4377 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 487:
/* Line 661 of lalr1.cc  */
#line 4384 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 488:
/* Line 661 of lalr1.cc  */
#line 4391 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 489:
/* Line 661 of lalr1.cc  */
#line 4402 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 490:
/* Line 661 of lalr1.cc  */
#line 4410 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 491:
/* Line 661 of lalr1.cc  */
#line 4414 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 492:
/* Line 661 of lalr1.cc  */
#line 4422 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 493:
/* Line 661 of lalr1.cc  */
#line 4430 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 494:
/* Line 661 of lalr1.cc  */
#line 4438 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 495:
/* Line 661 of lalr1.cc  */
#line 4492 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 496:
/* Line 661 of lalr1.cc  */
#line 4496 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            ArgList* argList = dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node));

            if (argList->has_placeholder())
            {
                (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)),
                           new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)), new Integer(argList->size())), argList);
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

  case 497:
/* Line 661 of lalr1.cc  */
#line 4519 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
            (yyval.node) = al;
        }
    break;

  case 498:
/* Line 661 of lalr1.cc  */
#line 4525 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 499:
/* Line 661 of lalr1.cc  */
#line 4531 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 500:
/* Line 661 of lalr1.cc  */
#line 4537 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 501:
/* Line 661 of lalr1.cc  */
#line 4547 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:
/* Line 661 of lalr1.cc  */
#line 4551 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 503:
/* Line 661 of lalr1.cc  */
#line 4559 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 504:
/* Line 661 of lalr1.cc  */
#line 4563 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 505:
/* Line 661 of lalr1.cc  */
#line 4567 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 506:
/* Line 661 of lalr1.cc  */
#line 4575 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 507:
/* Line 661 of lalr1.cc  */
#line 4585 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 508:
/* Line 661 of lalr1.cc  */
#line 4595 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 509:
/* Line 661 of lalr1.cc  */
#line 4612 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 510:
/* Line 661 of lalr1.cc  */
#line 4629 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 511:
/* Line 661 of lalr1.cc  */
#line 4646 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 512:
/* Line 661 of lalr1.cc  */
#line 4668 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 513:
/* Line 661 of lalr1.cc  */
#line 4674 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 514:
/* Line 661 of lalr1.cc  */
#line 4685 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 515:
/* Line 661 of lalr1.cc  */
#line 4691 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 516:
/* Line 661 of lalr1.cc  */
#line 4702 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 519:
/* Line 661 of lalr1.cc  */
#line 4719 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 520:
/* Line 661 of lalr1.cc  */
#line 4724 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 521:
/* Line 661 of lalr1.cc  */
#line 4733 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 522:
/* Line 661 of lalr1.cc  */
#line 4737 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:
/* Line 661 of lalr1.cc  */
#line 4744 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 524:
/* Line 661 of lalr1.cc  */
#line 4750 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 525:
/* Line 661 of lalr1.cc  */
#line 4756 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 526:
/* Line 661 of lalr1.cc  */
#line 4764 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 527:
/* Line 661 of lalr1.cc  */
#line 4776 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 528:
/* Line 661 of lalr1.cc  */
#line 4780 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 529:
/* Line 661 of lalr1.cc  */
#line 4787 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 530:
/* Line 661 of lalr1.cc  */
#line 4793 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 531:
/* Line 661 of lalr1.cc  */
#line 4799 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 532:
/* Line 661 of lalr1.cc  */
#line 4806 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 533:
/* Line 661 of lalr1.cc  */
#line 4817 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 534:
/* Line 661 of lalr1.cc  */
#line 4821 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 535:
/* Line 661 of lalr1.cc  */
#line 4831 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 536:
/* Line 661 of lalr1.cc  */
#line 4835 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 537:
/* Line 661 of lalr1.cc  */
#line 4845 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 538:
/* Line 661 of lalr1.cc  */
#line 4849 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 539:
/* Line 661 of lalr1.cc  */
#line 4853 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 540:
/* Line 661 of lalr1.cc  */
#line 4858 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 541:
/* Line 661 of lalr1.cc  */
#line 4867 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 542:
/* Line 661 of lalr1.cc  */
#line 4873 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 543:
/* Line 661 of lalr1.cc  */
#line 4879 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 544:
/* Line 661 of lalr1.cc  */
#line 4885 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 545:
/* Line 661 of lalr1.cc  */
#line 4893 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 546:
/* Line 661 of lalr1.cc  */
#line 4898 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 547:
/* Line 661 of lalr1.cc  */
#line 4906 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 548:
/* Line 661 of lalr1.cc  */
#line 4911 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 549:
/* Line 661 of lalr1.cc  */
#line 4919 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 550:
/* Line 661 of lalr1.cc  */
#line 4927 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:
/* Line 661 of lalr1.cc  */
#line 4932 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:
/* Line 661 of lalr1.cc  */
#line 4937 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 553:
/* Line 661 of lalr1.cc  */
#line 4942 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 554:
/* Line 661 of lalr1.cc  */
#line 4947 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 555:
/* Line 661 of lalr1.cc  */
#line 4952 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 556:
/* Line 661 of lalr1.cc  */
#line 4961 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 557:
/* Line 661 of lalr1.cc  */
#line 4969 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 558:
/* Line 661 of lalr1.cc  */
#line 4973 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 559:
/* Line 661 of lalr1.cc  */
#line 4990 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 560:
/* Line 661 of lalr1.cc  */
#line 4994 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 561:
/* Line 661 of lalr1.cc  */
#line 5002 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 562:
/* Line 661 of lalr1.cc  */
#line 5010 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 563:
/* Line 661 of lalr1.cc  */
#line 5018 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 564:
/* Line 661 of lalr1.cc  */
#line 5022 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 565:
/* Line 661 of lalr1.cc  */
#line 5030 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 566:
/* Line 661 of lalr1.cc  */
#line 5036 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 567:
/* Line 661 of lalr1.cc  */
#line 5046 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 568:
/* Line 661 of lalr1.cc  */
#line 5054 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 569:
/* Line 661 of lalr1.cc  */
#line 5058 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 570:
/* Line 661 of lalr1.cc  */
#line 5062 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 571:
/* Line 661 of lalr1.cc  */
#line 5097 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 572:
/* Line 661 of lalr1.cc  */
#line 5103 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 573:
/* Line 661 of lalr1.cc  */
#line 5109 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 574:
/* Line 661 of lalr1.cc  */
#line 5119 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:
/* Line 661 of lalr1.cc  */
#line 5123 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:
/* Line 661 of lalr1.cc  */
#line 5127 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 577:
/* Line 661 of lalr1.cc  */
#line 5131 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 578:
/* Line 661 of lalr1.cc  */
#line 5135 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:
/* Line 661 of lalr1.cc  */
#line 5139 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:
/* Line 661 of lalr1.cc  */
#line 5143 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:
/* Line 661 of lalr1.cc  */
#line 5150 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 582:
/* Line 661 of lalr1.cc  */
#line 5156 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 583:
/* Line 661 of lalr1.cc  */
#line 5166 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 584:
/* Line 661 of lalr1.cc  */
#line 5174 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:
/* Line 661 of lalr1.cc  */
#line 5178 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:
/* Line 661 of lalr1.cc  */
#line 5182 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:
/* Line 661 of lalr1.cc  */
#line 5186 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:
/* Line 661 of lalr1.cc  */
#line 5190 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:
/* Line 661 of lalr1.cc  */
#line 5194 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 590:
/* Line 661 of lalr1.cc  */
#line 5198 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 591:
/* Line 661 of lalr1.cc  */
#line 5202 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 592:
/* Line 661 of lalr1.cc  */
#line 5206 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 593:
/* Line 661 of lalr1.cc  */
#line 5214 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 594:
/* Line 661 of lalr1.cc  */
#line 5222 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 595:
/* Line 661 of lalr1.cc  */
#line 5226 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 596:
/* Line 661 of lalr1.cc  */
#line 5230 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 597:
/* Line 661 of lalr1.cc  */
#line 5240 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 598:
/* Line 661 of lalr1.cc  */
#line 5248 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 599:
/* Line 661 of lalr1.cc  */
#line 5256 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 600:
/* Line 661 of lalr1.cc  */
#line 5260 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 601:
/* Line 661 of lalr1.cc  */
#line 5264 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 602:
/* Line 661 of lalr1.cc  */
#line 5272 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 603:
/* Line 661 of lalr1.cc  */
#line 5276 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 604:
/* Line 661 of lalr1.cc  */
#line 5282 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 605:
/* Line 661 of lalr1.cc  */
#line 5288 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 606:
/* Line 661 of lalr1.cc  */
#line 5292 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 607:
/* Line 661 of lalr1.cc  */
#line 5302 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 608:
/* Line 661 of lalr1.cc  */
#line 5310 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 609:
/* Line 661 of lalr1.cc  */
#line 5314 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 610:
/* Line 661 of lalr1.cc  */
#line 5320 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 611:
/* Line 661 of lalr1.cc  */
#line 5329 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 612:
/* Line 661 of lalr1.cc  */
#line 5338 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 613:
/* Line 661 of lalr1.cc  */
#line 5344 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 614:
/* Line 661 of lalr1.cc  */
#line 5350 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 615:
/* Line 661 of lalr1.cc  */
#line 5360 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 616:
/* Line 661 of lalr1.cc  */
#line 5377 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 617:
/* Line 661 of lalr1.cc  */
#line 5384 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 618:
/* Line 661 of lalr1.cc  */
#line 5399 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 619:
/* Line 661 of lalr1.cc  */
#line 5435 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 620:
/* Line 661 of lalr1.cc  */
#line 5439 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 621:
/* Line 661 of lalr1.cc  */
#line 5447 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 622:
/* Line 661 of lalr1.cc  */
#line 5455 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 623:
/* Line 661 of lalr1.cc  */
#line 5467 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 624:
/* Line 661 of lalr1.cc  */
#line 5471 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 625:
/* Line 661 of lalr1.cc  */
#line 5479 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 626:
/* Line 661 of lalr1.cc  */
#line 5487 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 627:
/* Line 661 of lalr1.cc  */
#line 5491 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 628:
/* Line 661 of lalr1.cc  */
#line 5502 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 629:
/* Line 661 of lalr1.cc  */
#line 5519 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 630:
/* Line 661 of lalr1.cc  */
#line 5525 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 631:
/* Line 661 of lalr1.cc  */
#line 5531 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 632:
/* Line 661 of lalr1.cc  */
#line 5541 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 633:
/* Line 661 of lalr1.cc  */
#line 5545 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 634:
/* Line 661 of lalr1.cc  */
#line 5551 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 635:
/* Line 661 of lalr1.cc  */
#line 5557 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 636:
/* Line 661 of lalr1.cc  */
#line 5561 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 637:
/* Line 661 of lalr1.cc  */
#line 5567 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 638:
/* Line 661 of lalr1.cc  */
#line 5571 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 639:
/* Line 661 of lalr1.cc  */
#line 5577 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 640:
/* Line 661 of lalr1.cc  */
#line 5583 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 641:
/* Line 661 of lalr1.cc  */
#line 5590 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 642:
/* Line 661 of lalr1.cc  */
#line 5600 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 643:
/* Line 661 of lalr1.cc  */
#line 5605 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 644:
/* Line 661 of lalr1.cc  */
#line 5613 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 645:
/* Line 661 of lalr1.cc  */
#line 5619 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 646:
/* Line 661 of lalr1.cc  */
#line 5629 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 647:
/* Line 661 of lalr1.cc  */
#line 5651 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 648:
/* Line 661 of lalr1.cc  */
#line 5660 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 649:
/* Line 661 of lalr1.cc  */
#line 5666 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 650:
/* Line 661 of lalr1.cc  */
#line 5679 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 651:
/* Line 661 of lalr1.cc  */
#line 5693 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 652:
/* Line 661 of lalr1.cc  */
#line 5700 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 653:
/* Line 661 of lalr1.cc  */
#line 5706 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 654:
/* Line 661 of lalr1.cc  */
#line 5716 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 655:
/* Line 661 of lalr1.cc  */
#line 5725 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 656:
/* Line 661 of lalr1.cc  */
#line 5733 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 657:
/* Line 661 of lalr1.cc  */
#line 5739 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 658:
/* Line 661 of lalr1.cc  */
#line 5757 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 659:
/* Line 661 of lalr1.cc  */
#line 5765 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 660:
/* Line 661 of lalr1.cc  */
#line 5769 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 661:
/* Line 661 of lalr1.cc  */
#line 5776 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 662:
/* Line 661 of lalr1.cc  */
#line 5781 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 663:
/* Line 661 of lalr1.cc  */
#line 5789 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:
/* Line 661 of lalr1.cc  */
#line 5793 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 665:
/* Line 661 of lalr1.cc  */
#line 5800 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:
/* Line 661 of lalr1.cc  */
#line 5804 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 667:
/* Line 661 of lalr1.cc  */
#line 5811 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:
/* Line 661 of lalr1.cc  */
#line 5815 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 669:
/* Line 661 of lalr1.cc  */
#line 5822 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:
/* Line 661 of lalr1.cc  */
#line 5826 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 671:
/* Line 661 of lalr1.cc  */
#line 5835 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTPrimaryWithOptions(
                LOC((yyloc)),
                dynamic_cast<FTPrimary*>((yysemantic_stack_[(3) - (1)].node)),
                dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTWeight*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 672:
/* Line 661 of lalr1.cc  */
#line 5847 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 673:
/* Line 661 of lalr1.cc  */
#line 5851 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:
/* Line 661 of lalr1.cc  */
#line 5858 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 675:
/* Line 661 of lalr1.cc  */
#line 5862 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:
/* Line 661 of lalr1.cc  */
#line 5870 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 677:
/* Line 661 of lalr1.cc  */
#line 5878 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 678:
/* Line 661 of lalr1.cc  */
#line 5886 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 679:
/* Line 661 of lalr1.cc  */
#line 5890 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 680:
/* Line 661 of lalr1.cc  */
#line 5897 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 681:
/* Line 661 of lalr1.cc  */
#line 5901 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 682:
/* Line 661 of lalr1.cc  */
#line 5909 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 683:
/* Line 661 of lalr1.cc  */
#line 5920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 684:
/* Line 661 of lalr1.cc  */
#line 5924 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:
/* Line 661 of lalr1.cc  */
#line 5932 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 686:
/* Line 661 of lalr1.cc  */
#line 5944 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 687:
/* Line 661 of lalr1.cc  */
#line 5950 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 688:
/* Line 661 of lalr1.cc  */
#line 5959 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 689:
/* Line 661 of lalr1.cc  */
#line 5963 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 690:
/* Line 661 of lalr1.cc  */
#line 5971 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 691:
/* Line 661 of lalr1.cc  */
#line 5975 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 692:
/* Line 661 of lalr1.cc  */
#line 5979 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 693:
/* Line 661 of lalr1.cc  */
#line 5986 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 694:
/* Line 661 of lalr1.cc  */
#line 5990 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 695:
/* Line 661 of lalr1.cc  */
#line 5997 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 696:
/* Line 661 of lalr1.cc  */
#line 6001 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 697:
/* Line 661 of lalr1.cc  */
#line 6009 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:
/* Line 661 of lalr1.cc  */
#line 6013 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:
/* Line 661 of lalr1.cc  */
#line 6017 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:
/* Line 661 of lalr1.cc  */
#line 6021 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:
/* Line 661 of lalr1.cc  */
#line 6025 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:
/* Line 661 of lalr1.cc  */
#line 6033 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 703:
/* Line 661 of lalr1.cc  */
#line 6041 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 704:
/* Line 661 of lalr1.cc  */
#line 6053 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 705:
/* Line 661 of lalr1.cc  */
#line 6065 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 706:
/* Line 661 of lalr1.cc  */
#line 6069 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 707:
/* Line 661 of lalr1.cc  */
#line 6073 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 708:
/* Line 661 of lalr1.cc  */
#line 6081 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 709:
/* Line 661 of lalr1.cc  */
#line 6087 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 710:
/* Line 661 of lalr1.cc  */
#line 6097 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:
/* Line 661 of lalr1.cc  */
#line 6101 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:
/* Line 661 of lalr1.cc  */
#line 6105 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:
/* Line 661 of lalr1.cc  */
#line 6109 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:
/* Line 661 of lalr1.cc  */
#line 6113 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 715:
/* Line 661 of lalr1.cc  */
#line 6117 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 716:
/* Line 661 of lalr1.cc  */
#line 6121 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 717:
/* Line 661 of lalr1.cc  */
#line 6125 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:
/* Line 661 of lalr1.cc  */
#line 6133 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 719:
/* Line 661 of lalr1.cc  */
#line 6137 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 720:
/* Line 661 of lalr1.cc  */
#line 6141 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 721:
/* Line 661 of lalr1.cc  */
#line 6145 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 722:
/* Line 661 of lalr1.cc  */
#line 6153 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 723:
/* Line 661 of lalr1.cc  */
#line 6159 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 724:
/* Line 661 of lalr1.cc  */
#line 6169 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 725:
/* Line 661 of lalr1.cc  */
#line 6179 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 726:
/* Line 661 of lalr1.cc  */
#line 6183 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 727:
/* Line 661 of lalr1.cc  */
#line 6191 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 728:
/* Line 661 of lalr1.cc  */
#line 6201 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 729:
/* Line 661 of lalr1.cc  */
#line 6212 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 730:
/* Line 661 of lalr1.cc  */
#line 6219 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 731:
/* Line 661 of lalr1.cc  */
#line 6223 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 732:
/* Line 661 of lalr1.cc  */
#line 6230 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 733:
/* Line 661 of lalr1.cc  */
#line 6234 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 734:
/* Line 661 of lalr1.cc  */
#line 6241 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 735:
/* Line 661 of lalr1.cc  */
#line 6246 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 736:
/* Line 661 of lalr1.cc  */
#line 6255 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 737:
/* Line 661 of lalr1.cc  */
#line 6264 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 738:
/* Line 661 of lalr1.cc  */
#line 6268 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 739:
/* Line 661 of lalr1.cc  */
#line 6275 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 740:
/* Line 661 of lalr1.cc  */
#line 6279 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 741:
/* Line 661 of lalr1.cc  */
#line 6287 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(4) - (3)].node)), (yysemantic_stack_[(4) - (4)].incl_excl_list),
                ft_stop_words_mode::with
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 742:
/* Line 661 of lalr1.cc  */
#line 6296 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 743:
/* Line 661 of lalr1.cc  */
#line 6303 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 744:
/* Line 661 of lalr1.cc  */
#line 6313 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 745:
/* Line 661 of lalr1.cc  */
#line 6317 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 746:
/* Line 661 of lalr1.cc  */
#line 6324 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 747:
/* Line 661 of lalr1.cc  */
#line 6330 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 748:
/* Line 661 of lalr1.cc  */
#line 6339 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 749:
/* Line 661 of lalr1.cc  */
#line 6343 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 750:
/* Line 661 of lalr1.cc  */
#line 6350 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 751:
/* Line 661 of lalr1.cc  */
#line 6355 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 752:
/* Line 661 of lalr1.cc  */
#line 6367 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 753:
/* Line 661 of lalr1.cc  */
#line 6375 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 754:
/* Line 661 of lalr1.cc  */
#line 6387 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 755:
/* Line 661 of lalr1.cc  */
#line 6395 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 756:
/* Line 661 of lalr1.cc  */
#line 6399 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 757:
/* Line 661 of lalr1.cc  */
#line 6407 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 758:
/* Line 661 of lalr1.cc  */
#line 6411 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 759:
/* Line 661 of lalr1.cc  */
#line 6415 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 760:
/* Line 661 of lalr1.cc  */
#line 6423 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 761:
/* Line 661 of lalr1.cc  */
#line 6431 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 762:
/* Line 661 of lalr1.cc  */
#line 6435 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 763:
/* Line 661 of lalr1.cc  */
#line 6439 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 764:
/* Line 661 of lalr1.cc  */
#line 6443 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 765:
/* Line 661 of lalr1.cc  */
#line 6451 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 766:
/* Line 661 of lalr1.cc  */
#line 6459 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 767:
/* Line 661 of lalr1.cc  */
#line 6471 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 768:
/* Line 661 of lalr1.cc  */
#line 6475 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 769:
/* Line 661 of lalr1.cc  */
#line 6483 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 770:
/* Line 661 of lalr1.cc  */
#line 6497 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 771:
/* Line 661 of lalr1.cc  */
#line 6501 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 772:
/* Line 661 of lalr1.cc  */
#line 6508 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 773:
/* Line 661 of lalr1.cc  */
#line 6513 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 774:
/* Line 661 of lalr1.cc  */
#line 6521 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 775:
/* Line 661 of lalr1.cc  */
#line 6526 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 776:
/* Line 661 of lalr1.cc  */
#line 6535 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 777:
/* Line 661 of lalr1.cc  */
#line 6543 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 778:
/* Line 661 of lalr1.cc  */
#line 6549 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 779:
/* Line 661 of lalr1.cc  */
#line 6559 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 780:
/* Line 661 of lalr1.cc  */
#line 6565 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 6575 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 782:
/* Line 661 of lalr1.cc  */
#line 6582 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 783:
/* Line 661 of lalr1.cc  */
#line 6589 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 784:
/* Line 661 of lalr1.cc  */
#line 6614 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 785:
/* Line 661 of lalr1.cc  */
#line 6642 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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

  case 786:
/* Line 661 of lalr1.cc  */
#line 6670 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 787:
/* Line 661 of lalr1.cc  */
#line 6674 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 788:
/* Line 661 of lalr1.cc  */
#line 6678 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 789:
/* Line 661 of lalr1.cc  */
#line 6685 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 790:
/* Line 661 of lalr1.cc  */
#line 6692 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 791:
/* Line 661 of lalr1.cc  */
#line 6699 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 794:
/* Line 661 of lalr1.cc  */
#line 6716 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 6729 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 797:
/* Line 661 of lalr1.cc  */
#line 6730 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 798:
/* Line 661 of lalr1.cc  */
#line 6731 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 799:
/* Line 661 of lalr1.cc  */
#line 6732 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 800:
/* Line 661 of lalr1.cc  */
#line 6733 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 801:
/* Line 661 of lalr1.cc  */
#line 6734 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 802:
/* Line 661 of lalr1.cc  */
#line 6735 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 803:
/* Line 661 of lalr1.cc  */
#line 6736 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 804:
/* Line 661 of lalr1.cc  */
#line 6737 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 805:
/* Line 661 of lalr1.cc  */
#line 6738 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 806:
/* Line 661 of lalr1.cc  */
#line 6739 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 807:
/* Line 661 of lalr1.cc  */
#line 6740 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 808:
/* Line 661 of lalr1.cc  */
#line 6741 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 809:
/* Line 661 of lalr1.cc  */
#line 6742 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 810:
/* Line 661 of lalr1.cc  */
#line 6743 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 812:
/* Line 661 of lalr1.cc  */
#line 6748 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 813:
/* Line 661 of lalr1.cc  */
#line 6749 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 814:
/* Line 661 of lalr1.cc  */
#line 6750 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 815:
/* Line 661 of lalr1.cc  */
#line 6751 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 816:
/* Line 661 of lalr1.cc  */
#line 6752 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 817:
/* Line 661 of lalr1.cc  */
#line 6753 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 818:
/* Line 661 of lalr1.cc  */
#line 6754 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 819:
/* Line 661 of lalr1.cc  */
#line 6755 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 820:
/* Line 661 of lalr1.cc  */
#line 6756 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 821:
/* Line 661 of lalr1.cc  */
#line 6757 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 822:
/* Line 661 of lalr1.cc  */
#line 6758 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 823:
/* Line 661 of lalr1.cc  */
#line 6759 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 824:
/* Line 661 of lalr1.cc  */
#line 6760 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 825:
/* Line 661 of lalr1.cc  */
#line 6761 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 826:
/* Line 661 of lalr1.cc  */
#line 6762 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 827:
/* Line 661 of lalr1.cc  */
#line 6763 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 828:
/* Line 661 of lalr1.cc  */
#line 6764 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 829:
/* Line 661 of lalr1.cc  */
#line 6765 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 830:
/* Line 661 of lalr1.cc  */
#line 6766 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 831:
/* Line 661 of lalr1.cc  */
#line 6767 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 832:
/* Line 661 of lalr1.cc  */
#line 6768 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 833:
/* Line 661 of lalr1.cc  */
#line 6769 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 834:
/* Line 661 of lalr1.cc  */
#line 6770 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 835:
/* Line 661 of lalr1.cc  */
#line 6771 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 836:
/* Line 661 of lalr1.cc  */
#line 6772 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 837:
/* Line 661 of lalr1.cc  */
#line 6773 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 838:
/* Line 661 of lalr1.cc  */
#line 6774 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 839:
/* Line 661 of lalr1.cc  */
#line 6775 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 840:
/* Line 661 of lalr1.cc  */
#line 6776 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 841:
/* Line 661 of lalr1.cc  */
#line 6777 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 842:
/* Line 661 of lalr1.cc  */
#line 6778 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 843:
/* Line 661 of lalr1.cc  */
#line 6779 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 844:
/* Line 661 of lalr1.cc  */
#line 6780 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 845:
/* Line 661 of lalr1.cc  */
#line 6781 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 846:
/* Line 661 of lalr1.cc  */
#line 6782 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 847:
/* Line 661 of lalr1.cc  */
#line 6783 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 848:
/* Line 661 of lalr1.cc  */
#line 6784 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 849:
/* Line 661 of lalr1.cc  */
#line 6785 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 850:
/* Line 661 of lalr1.cc  */
#line 6786 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 851:
/* Line 661 of lalr1.cc  */
#line 6787 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 852:
/* Line 661 of lalr1.cc  */
#line 6788 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 853:
/* Line 661 of lalr1.cc  */
#line 6789 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 854:
/* Line 661 of lalr1.cc  */
#line 6790 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 855:
/* Line 661 of lalr1.cc  */
#line 6791 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 856:
/* Line 661 of lalr1.cc  */
#line 6792 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 857:
/* Line 661 of lalr1.cc  */
#line 6793 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 858:
/* Line 661 of lalr1.cc  */
#line 6794 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 859:
/* Line 661 of lalr1.cc  */
#line 6795 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 860:
/* Line 661 of lalr1.cc  */
#line 6796 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 861:
/* Line 661 of lalr1.cc  */
#line 6797 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 862:
/* Line 661 of lalr1.cc  */
#line 6798 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 863:
/* Line 661 of lalr1.cc  */
#line 6799 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 864:
/* Line 661 of lalr1.cc  */
#line 6800 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 865:
/* Line 661 of lalr1.cc  */
#line 6801 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 866:
/* Line 661 of lalr1.cc  */
#line 6802 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 867:
/* Line 661 of lalr1.cc  */
#line 6803 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 868:
/* Line 661 of lalr1.cc  */
#line 6804 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 869:
/* Line 661 of lalr1.cc  */
#line 6805 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 870:
/* Line 661 of lalr1.cc  */
#line 6806 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 871:
/* Line 661 of lalr1.cc  */
#line 6807 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 872:
/* Line 661 of lalr1.cc  */
#line 6808 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 873:
/* Line 661 of lalr1.cc  */
#line 6809 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 874:
/* Line 661 of lalr1.cc  */
#line 6810 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 875:
/* Line 661 of lalr1.cc  */
#line 6811 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 876:
/* Line 661 of lalr1.cc  */
#line 6812 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 877:
/* Line 661 of lalr1.cc  */
#line 6813 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 878:
/* Line 661 of lalr1.cc  */
#line 6814 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 879:
/* Line 661 of lalr1.cc  */
#line 6815 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 880:
/* Line 661 of lalr1.cc  */
#line 6816 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 881:
/* Line 661 of lalr1.cc  */
#line 6817 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 882:
/* Line 661 of lalr1.cc  */
#line 6818 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 883:
/* Line 661 of lalr1.cc  */
#line 6819 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 884:
/* Line 661 of lalr1.cc  */
#line 6820 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 885:
/* Line 661 of lalr1.cc  */
#line 6821 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 886:
/* Line 661 of lalr1.cc  */
#line 6822 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 887:
/* Line 661 of lalr1.cc  */
#line 6823 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 888:
/* Line 661 of lalr1.cc  */
#line 6824 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 889:
/* Line 661 of lalr1.cc  */
#line 6825 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 890:
/* Line 661 of lalr1.cc  */
#line 6826 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 891:
/* Line 661 of lalr1.cc  */
#line 6827 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 892:
/* Line 661 of lalr1.cc  */
#line 6828 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 893:
/* Line 661 of lalr1.cc  */
#line 6829 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 894:
/* Line 661 of lalr1.cc  */
#line 6830 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 895:
/* Line 661 of lalr1.cc  */
#line 6831 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 896:
/* Line 661 of lalr1.cc  */
#line 6832 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 897:
/* Line 661 of lalr1.cc  */
#line 6833 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 898:
/* Line 661 of lalr1.cc  */
#line 6834 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 899:
/* Line 661 of lalr1.cc  */
#line 6835 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 900:
/* Line 661 of lalr1.cc  */
#line 6836 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 901:
/* Line 661 of lalr1.cc  */
#line 6837 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 902:
/* Line 661 of lalr1.cc  */
#line 6838 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 903:
/* Line 661 of lalr1.cc  */
#line 6839 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 904:
/* Line 661 of lalr1.cc  */
#line 6840 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 905:
/* Line 661 of lalr1.cc  */
#line 6841 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 906:
/* Line 661 of lalr1.cc  */
#line 6842 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 907:
/* Line 661 of lalr1.cc  */
#line 6843 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 908:
/* Line 661 of lalr1.cc  */
#line 6844 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 909:
/* Line 661 of lalr1.cc  */
#line 6845 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 910:
/* Line 661 of lalr1.cc  */
#line 6846 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 911:
/* Line 661 of lalr1.cc  */
#line 6847 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 912:
/* Line 661 of lalr1.cc  */
#line 6848 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 913:
/* Line 661 of lalr1.cc  */
#line 6849 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 914:
/* Line 661 of lalr1.cc  */
#line 6850 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 915:
/* Line 661 of lalr1.cc  */
#line 6851 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 916:
/* Line 661 of lalr1.cc  */
#line 6852 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 917:
/* Line 661 of lalr1.cc  */
#line 6853 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 918:
/* Line 661 of lalr1.cc  */
#line 6854 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 919:
/* Line 661 of lalr1.cc  */
#line 6855 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 920:
/* Line 661 of lalr1.cc  */
#line 6856 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 921:
/* Line 661 of lalr1.cc  */
#line 6857 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 922:
/* Line 661 of lalr1.cc  */
#line 6858 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 923:
/* Line 661 of lalr1.cc  */
#line 6859 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 924:
/* Line 661 of lalr1.cc  */
#line 6860 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 925:
/* Line 661 of lalr1.cc  */
#line 6861 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 926:
/* Line 661 of lalr1.cc  */
#line 6862 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 927:
/* Line 661 of lalr1.cc  */
#line 6863 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 928:
/* Line 661 of lalr1.cc  */
#line 6864 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 929:
/* Line 661 of lalr1.cc  */
#line 6865 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 930:
/* Line 661 of lalr1.cc  */
#line 6866 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 931:
/* Line 661 of lalr1.cc  */
#line 6867 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 932:
/* Line 661 of lalr1.cc  */
#line 6868 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 933:
/* Line 661 of lalr1.cc  */
#line 6869 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 934:
/* Line 661 of lalr1.cc  */
#line 6870 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 935:
/* Line 661 of lalr1.cc  */
#line 6871 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 936:
/* Line 661 of lalr1.cc  */
#line 6872 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 937:
/* Line 661 of lalr1.cc  */
#line 6873 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 938:
/* Line 661 of lalr1.cc  */
#line 6874 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 939:
/* Line 661 of lalr1.cc  */
#line 6875 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 940:
/* Line 661 of lalr1.cc  */
#line 6876 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 941:
/* Line 661 of lalr1.cc  */
#line 6877 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 942:
/* Line 661 of lalr1.cc  */
#line 6878 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 943:
/* Line 661 of lalr1.cc  */
#line 6879 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 944:
/* Line 661 of lalr1.cc  */
#line 6880 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 945:
/* Line 661 of lalr1.cc  */
#line 6881 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 946:
/* Line 661 of lalr1.cc  */
#line 6882 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 947:
/* Line 661 of lalr1.cc  */
#line 6883 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 948:
/* Line 661 of lalr1.cc  */
#line 6884 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 949:
/* Line 661 of lalr1.cc  */
#line 6885 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 950:
/* Line 661 of lalr1.cc  */
#line 6886 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 951:
/* Line 661 of lalr1.cc  */
#line 6887 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 952:
/* Line 661 of lalr1.cc  */
#line 6888 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 953:
/* Line 661 of lalr1.cc  */
#line 6889 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 954:
/* Line 661 of lalr1.cc  */
#line 6890 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 955:
/* Line 661 of lalr1.cc  */
#line 6891 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 956:
/* Line 661 of lalr1.cc  */
#line 6892 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 957:
/* Line 661 of lalr1.cc  */
#line 6893 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 958:
/* Line 661 of lalr1.cc  */
#line 6894 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 959:
/* Line 661 of lalr1.cc  */
#line 6895 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 960:
/* Line 661 of lalr1.cc  */
#line 6896 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 961:
/* Line 661 of lalr1.cc  */
#line 6897 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 962:
/* Line 661 of lalr1.cc  */
#line 6898 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 963:
/* Line 661 of lalr1.cc  */
#line 6899 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 964:
/* Line 661 of lalr1.cc  */
#line 6900 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 965:
/* Line 661 of lalr1.cc  */
#line 6901 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 966:
/* Line 661 of lalr1.cc  */
#line 6902 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 967:
/* Line 661 of lalr1.cc  */
#line 6903 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 968:
/* Line 661 of lalr1.cc  */
#line 6904 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 969:
/* Line 661 of lalr1.cc  */
#line 6905 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 970:
/* Line 661 of lalr1.cc  */
#line 6906 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 971:
/* Line 661 of lalr1.cc  */
#line 6907 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 972:
/* Line 661 of lalr1.cc  */
#line 6908 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 973:
/* Line 661 of lalr1.cc  */
#line 6909 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 974:
/* Line 661 of lalr1.cc  */
#line 6910 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 975:
/* Line 661 of lalr1.cc  */
#line 6911 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 976:
/* Line 661 of lalr1.cc  */
#line 6912 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 977:
/* Line 661 of lalr1.cc  */
#line 6913 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 978:
/* Line 661 of lalr1.cc  */
#line 6914 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 979:
/* Line 661 of lalr1.cc  */
#line 6915 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 980:
/* Line 661 of lalr1.cc  */
#line 6916 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 981:
/* Line 661 of lalr1.cc  */
#line 6917 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 982:
/* Line 661 of lalr1.cc  */
#line 6918 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 983:
/* Line 661 of lalr1.cc  */
#line 6919 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 984:
/* Line 661 of lalr1.cc  */
#line 6920 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 985:
/* Line 661 of lalr1.cc  */
#line 6921 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 986:
/* Line 661 of lalr1.cc  */
#line 6922 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 987:
/* Line 661 of lalr1.cc  */
#line 6923 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 988:
/* Line 661 of lalr1.cc  */
#line 6924 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 989:
/* Line 661 of lalr1.cc  */
#line 6925 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 990:
/* Line 661 of lalr1.cc  */
#line 6926 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 991:
/* Line 661 of lalr1.cc  */
#line 6927 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 992:
/* Line 661 of lalr1.cc  */
#line 6928 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 993:
/* Line 661 of lalr1.cc  */
#line 6929 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 994:
/* Line 661 of lalr1.cc  */
#line 6930 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 995:
/* Line 661 of lalr1.cc  */
#line 6931 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 996:
/* Line 661 of lalr1.cc  */
#line 6932 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 997:
/* Line 661 of lalr1.cc  */
#line 6933 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 998:
/* Line 661 of lalr1.cc  */
#line 6934 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 999:
/* Line 661 of lalr1.cc  */
#line 6935 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 1000:
/* Line 661 of lalr1.cc  */
#line 6936 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 1001:
/* Line 661 of lalr1.cc  */
#line 6937 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 1002:
/* Line 661 of lalr1.cc  */
#line 6938 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 1003:
/* Line 661 of lalr1.cc  */
#line 6939 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1004:
/* Line 661 of lalr1.cc  */
#line 6940 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1005:
/* Line 661 of lalr1.cc  */
#line 6941 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1006:
/* Line 661 of lalr1.cc  */
#line 6942 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1007:
/* Line 661 of lalr1.cc  */
#line 6943 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1008:
/* Line 661 of lalr1.cc  */
#line 6944 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1009:
/* Line 661 of lalr1.cc  */
#line 6945 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1010:
/* Line 661 of lalr1.cc  */
#line 6946 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1011:
/* Line 661 of lalr1.cc  */
#line 6947 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1012:
/* Line 661 of lalr1.cc  */
#line 6948 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1013:
/* Line 661 of lalr1.cc  */
#line 6949 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1014:
/* Line 661 of lalr1.cc  */
#line 6950 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1015:
/* Line 661 of lalr1.cc  */
#line 6951 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1016:
/* Line 661 of lalr1.cc  */
#line 6952 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1017:
/* Line 661 of lalr1.cc  */
#line 6957 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;


/* Line 661 of lalr1.cc  */
#line 10748 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
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

    char const* yyformat = YY_NULL;
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
  const short int xquery_parser::yypact_ninf_ = -1475;
  const short int
  xquery_parser::yypact_[] =
  {
      3934, -1475, -1475, -1475,  5798,  5798,  5798, -1475, -1475,    50,
     149, -1475,   876,    56, -1475, -1475, -1475,   781, -1475, -1475,
   -1475,   228,   281,   807,  3653,   359,   385,   746, -1475,   -32,
   -1475, -1475, -1475, -1475, -1475, -1475,   817, -1475,   418,   424,
   -1475, -1475, -1475, -1475,   525, -1475,   823, -1475,   443,   497,
   -1475,   304, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475,   671,   716, -1475, -1475,
   -1475, -1475,   645, 11998, -1475, -1475, -1475,   767, -1475, -1475,
   -1475,   778, -1475,   790,   799, -1475, -1475, 16385, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475,   820, -1475, -1475,   830,
     837, -1475, -1475, -1475, -1475, -1475, -1475, -1475,  4558,  8278,
    8588, 16385, -1475, -1475, -1475, -1475, -1475, -1475, -1475,   542,
   -1475, -1475,   847, 12893, -1475, 13196,   853,   863, -1475, -1475,
   -1475,   871, -1475, 11378, -1475, -1475, -1475, -1475, -1475, -1475,
     607, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,    57,
     779, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,   -82,
     844,   213, -1475,   -67,   -64, -1475, -1475, -1475, -1475, -1475,
   -1475,   886, -1475,   766,   773,   768, -1475, -1475,   862,   872,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475,  8898,  9208, -1475,   713, -1475, -1475, -1475,
   -1475, -1475,  4246,  6108,  1028, -1475,  6418, -1475, -1475,   151,
     103, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475,   110, -1475, -1475, -1475, -1475,
   -1475, -1475,   147, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475,  5798, -1475, -1475, -1475, -1475,   232, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475,   181, -1475,   839, -1475, -1475,
   -1475,   610, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
     864,   938, -1475,   883,   783,   934,   685,   603,   558,   539,
   -1475,   985,   841,   942,   937, 10138, -1475,   851, -1475, -1475,
     417, -1475, -1475, 11688, -1475,   755, -1475,   892, 11998, -1475,
     892, 11998, -1475, -1475, -1475,   826, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475,   902,   893, -1475,
   -1475, -1475, -1475, -1475,   866, -1475,  5798,   867,   869,   419,
     419,  1019,   606,   623,   270, 16673, 16385,   275,  1007, 16385,
     903,   939,   465, 12893,   705,   812, 16385, 16385,   757,    61,
      73, -1475, -1475, -1475, 12893,  5798,   877,  5798,   322, 10448,
   14081, 16385, -1475,   775,   782, 16385,   945,    32,   912, 10448,
    1067,    78,   117, 16385,   952,   929,   965, -1475, 10448, 12596,
   16385, 16385, 16385,  5798,   888, 10448, 10448, 16385,  5798,   923,
     924, -1475, -1475, -1475, 10448, 14369,   922, -1475,   926, -1475,
   -1475, -1475, -1475,   927, -1475,   928, -1475, -1475, -1475, -1475,
   -1475,   936, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   16385, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475,   943, 16385, -1475, -1475, -1475,   896,  4868,
     972,   319,   941,   944,   946, 16385,  5798, -1475,   948,    95,
   -1475,   686, -1475,   148,  1059, 10448, -1475, -1475,    98, -1475,
   -1475, -1475,  1078, -1475, -1475, -1475, -1475, 10448,   885, -1475,
    1074, 10448, 10448, 13496,   917, 10448, 10448, 10448, 10448, 13496,
   10448,   874,   878, 16385,   920,   921, 10448, 10448,  4558,   873,
   -1475,    53, -1475,    60, 10448,  6108, -1475, -1475, -1475, -1475,
   -1475,   876,   746,   111,   112,  1104,  6728,  6728,  7038,  7038,
     778, -1475, -1475,   212,   778, -1475,  3332, 10448, 10448, -1475,
     994,   636,   -32,   949,   950,   955,  5798, 10448, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, 10758, 10758, 10758, -1475,
   10758, 10758, -1475, 10758, -1475, 10758, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, 10758, 10758,  1046, 10758, 10758, 10758, 10758,
   10758, 10758, 10758, 10758, 10758, 10758, 10758, 10758,   895,  1025,
    1034,  1037, -1475, -1475, -1475, 11068,  9518, -1475, -1475, 11378,
   11378, 10448,   892, -1475, -1475,   892, -1475,  7348,   892,   983,
    7658, -1475, -1475, -1475,    48, -1475,   302, -1475, -1475, -1475,
   -1475, -1475, -1475,  1026,  1027,   359,  1106, -1475, -1475, 16673,
    1071,   647, 16385,   986,   987,  1071,  1019,  1016,  1013, -1475,
   -1475, -1475,   140,   915,  1054,   850, 16385,  1020, 10448,  1047,
   16385, 16385, -1475,  1032,   982,  5798, -1475,   984,   926,   424,
   -1475,   980,   988,   216, -1475,   318,   353,  1062, -1475,    45,
   -1475, -1475,  1062, 16385,    27, 16385,  1076,   358, -1475,  5798,
   -1475,   155, -1475, 12893,  1077,  1127, 12893,  1019,  1080,   382,
   16385, 10448,   -32,   327,   990, -1475,   993,   995,   996,    41,
   -1475,   355,   997, -1475,   156,   167,  1031, -1475,  1001,  5798,
    5798,   332, -1475,   421,   427,   592, 10448,   263, -1475, -1475,
   10448, 10448, -1475, 10448, 10448, 10448, -1475, 10448, -1475, 10448,
   -1475, 16385,  1059, -1475,   257,   336, -1475, -1475, -1475,   339,
   -1475,    31, -1475, -1475,  1036,  1038,  1040,  1041,  1042,   826,
     902, -1475,   364,   367,    -6,     3,  1093,   586,   953,   971,
     966,     2, -1475,  1056, -1475, -1475,  1009,   176,  5178,   378,
   12299,   873, -1475, -1475, -1475,   967, -1475,   151,   714,  1168,
    1168, -1475, -1475,   116, -1475, -1475,   126, -1475,    58, -1475,
   -1475, -1475, -1475, -1475, -1475,  1201, -1475, -1475, 16385,  1033,
   10448,  1086, -1475, -1475, -1475,   938, -1475, -1475, -1475, -1475,
   -1475, 10758, -1475, -1475, -1475,    62, -1475,   603,   603,    47,
     558,   558,   558,   558,   539,   539, -1475, -1475, 15521, 15521,
   16385, 16385, -1475, -1475,   391, -1475, -1475,   139, -1475, -1475,
   -1475, -1475,   454, -1475, -1475,   472,   419, -1475, -1475,   315,
     529,   634, -1475,   359, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475,  1071, -1475,  1073, 15809,  1064, 10448,
   -1475, -1475, -1475,  1113,  1019,  1019,  1071, -1475,   836,  1019,
     662, 16385,   599,   604,  1179, -1475, -1475,   930,   574, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
     140,    33,   991,   504, 10448, -1475, 16385,  1115,   911,  1019,
   -1475, -1475, -1475, -1475,  1060, 16385, -1475, 16385, -1475, 16097,
    1085, 15521,  1096, 10448,    16,  1068,    40,   389,   968, -1475,
   -1475,   774,    27,  1113, 15521,  1101,  1126,  1039,  1023,  1092,
    1019,  1065,  1095,  1135,  1019, 10448,   -40, -1475, -1475, -1475,
    1082, -1475, -1475, -1475, -1475,  1118, 10448, 10448,  1091, -1475,
    1133,  1139,  5798, -1475,  1057,  1058,  1087, 16385, -1475, 16385,
   -1475, 10448,  1102,  1053, 10448, -1475,  1128,   190,   203,   227,
    1212, -1475,   481, -1475,   347, -1475, -1475,  1219, -1475,   749,
   10448, 10448, 10448,   758, 10448, 10448, 10448, 10448, 10448, 10448,
   10448, 10448, 10448, 13496,  1134, 10448, 10448, -1475,  7968,  1097,
    1103,  1105,  1098,   839,   697,  1012, -1475,   183, -1475, 10448,
     127,   138,    58,  7038,  7038,  7038,  1181, -1475, -1475, 10448,
     809,  1151, -1475, 16385,  1155, -1475, -1475, 10448,    62,   573,
     496, -1475,   978,   158,  1006,  1008, -1475, -1475,   812, -1475,
     999,   638,  1111,  1114, 15809,  1116,  1119,  1121,  1123,  1129,
   -1475,   491, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475,  1125, -1475, -1475, -1475,  9828,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,   642,
   -1475,  1242,   577, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475,  1000, -1475, -1475,  1245, -1475, -1475, -1475, -1475,
   -1475,   608,  1253, -1475,   648, -1475, -1475, -1475,   922,   281,
     927,   418,   928,   936,   844,  1119,  1121,  1123, -1475,   491,
     491, 11068,  1002,   977, -1475,  1113,    33,  1061,  1100,  5798,
    1107,  1109,  1143,  1112,  1117, 16385, -1475,   335, -1475, 16385,
   -1475, 10448,  1144, 10448,  1165, 10448,    52,  1154, 10448,  1158,
   -1475,  1180,  1184, 10448, 16385,   797,  1229, -1475, -1475, -1475,
   -1475, -1475, -1475, 15521, -1475,  5798,  1019,  1200, -1475, -1475,
   -1475,  1019,  1200, -1475, 10448,  1166,  5798, 16385, -1475, -1475,
   10448, 10448,   726, -1475,    23,   764, -1475, 14657,   769, -1475,
     794, -1475,  1136, -1475, -1475,  5798,  1122,  1124, -1475, 10448,
   -1475, -1475, 10448,  1120,  1133,  1210, -1475,  1185, -1475,   543,
   -1475, -1475,  1306, -1475, -1475,  5798, 16385, -1475,   578, -1475,
   -1475, -1475,  1131,  1089,  1094, -1475, -1475, -1475,  1108,  1110,
   -1475, -1475, -1475,  1223, -1475, -1475, -1475, -1475,  1088,   313,
   16385,  1138, -1475, -1475, 10448, 10448, 10448,  5488,  7968, 12299,
    1012, -1475, 12299, -1475, -1475,  1168,   501, -1475, -1475, -1475,
    1151, -1475,  1019, -1475,   870, -1475,    83,  1220, -1475, 10448,
     652,  1086,   394,  1141, -1475,    62,  1079, -1475, -1475,   434,
   -1475,   620,   118,  1081,    62,   620, 10758, -1475,   337, -1475,
   -1475, -1475, -1475, -1475, -1475,    62,  1183,  1051,   915,   118,
   -1475, -1475,  1048,  1257, -1475, -1475, -1475, 13793,  1150,  1152,
    1153,  1159,  1164,  1167,  1170, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,  1313,   175,
    1316,   175,  1090,  1246, -1475, -1475,  1188, 16385,  1130, -1475,
   -1475, 11068, -1475,  1176, -1475, -1475, -1475, -1475, -1475, -1475,
   10448,  1215, -1475, -1475, 10448, -1475,   485, -1475, 10448,  1216,
   10448, -1475, 10448, 16385, 16385, -1475,   130, -1475, 10448, -1475,
    1240,  1241,  1272,  1019,  1200, -1475, 10448,  1186, -1475, -1475,
   -1475,  1187, -1475,    38, 10448,  5798,  1189,    59, -1475, 16385,
    1190, 14945,    34, -1475, 15233,  1191, -1475, -1475,  1194, -1475,
   -1475, -1475, -1475, 10448,   811,  1212, 16385,   706, -1475,  1195,
    1212, 16385, -1475, -1475, 10448, 10448, 10448, 10448,  1055, 10448,
   10448, -1475, 10448,   241,   242,   248,   344, -1475, -1475, -1475,
   -1475, -1475,  1220, -1475, -1475, -1475,  1019, 10448, -1475,  1227,
   -1475, -1475, -1475, -1475,  1196, 10758, -1475, -1475, -1475, -1475,
   -1475,   422, 10758, 10758,   -79, -1475,  1006, -1475,   506, -1475,
    1008,    62,  1221, -1475, -1475,  1132, -1475, -1475, -1475, -1475,
    1278,  1197, -1475,   521, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475,    69,    69, -1475,   175, -1475, -1475,   523, -1475,
    1352,   118,  1286,  1198, 11068,   -17,  1099,  1213, -1475, -1475,
   10448, -1475, 10448,  1243, -1475, 10448, -1475, -1475, -1475,  1335,
   -1475, -1475,  7968, 10448,  1019, -1475, -1475, -1475, 10448, 10448,
   -1475, -1475, -1475,  7968,  7968,  1295,  5798, 16385,  1205, 16385,
   10448, 16385,  1206,  7968, -1475,   229,    51,  1212, 16385, -1475,
    1199,  1212, -1475, -1475, -1475, -1475, 10448, -1475, -1475, -1475,
    1202,  1133,  1139, 10448, -1475, -1475, -1475,  1287, 10448, -1475,
     558, 10758, 10758,    47,   698, -1475, -1475, -1475, -1475, -1475,
   -1475, 10448, -1475, 15521, -1475, 15521,  1300, -1475, -1475, -1475,
    1366, -1475, -1475, -1475,  1137,  1290, -1475, -1475,  1291, -1475,
     568, 16385,  1281,  1178, 16385, 11068, -1475, -1475, 10448, -1475,
    1283, -1475, -1475,  1200, -1475, -1475, 15521, -1475, -1475,  1310,
   10448,  1222, -1475,  1311,  7968, -1475, 16385,   487,   819, -1475,
    1209,  1212, -1475,  1218, -1475,  7968,   818,   407, -1475,  1287,
      47,    47, 10758,   411, -1475, -1475, 15521, -1475, -1475,  1286,
   11068, -1475,  1220,  1140, 16385,  1289,  1192,  1291, -1475, 16385,
    1224, 15521,  5798, 15521,  1230, -1475, -1475,  1320,   700, -1475,
   -1475, -1475, -1475,  1226,   843, -1475, -1475, -1475,  1225, -1475,
    1301, -1475, -1475,    47, -1475, -1475, -1475, -1475, -1475, 10448,
    1142, 16385,  1302, -1475,  5798,  1232, -1475, -1475,  1235, 10448,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, 16385, -1475,  1145,
    1147, 16385, -1475, -1475, 10448,  7968,  1237,  1148, 10448,  1149,
    7968, 11068, -1475, 11068, -1475,  1228,  1146, 16385,  1203,  1307,
   16385,  1156, 11068, -1475
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       163,   460,   461,   462,   166,   166,   166,   812,  1017,   118,
     120,   618,   904,   913,   853,   817,   815,   797,   905,   908,
     860,   821,   798,   799,     0,   914,   801,   911,   882,   862,
     837,   857,   858,   909,   906,   856,   803,   912,   804,   805,
     953,   965,   952,   854,   873,   867,   806,   855,   808,   807,
     954,   891,   892,   859,   834,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   985,   999,  1006,   881,   877,
     868,   848,   796,     0,   876,   884,   893,  1000,   872,   486,
     849,   850,   907,  1001,  1007,   869,   886,     0,   492,   449,
     488,   879,   814,   870,   871,   900,   874,   890,   899,  1005,
    1008,   820,   861,   902,   487,   889,   895,   800,     0,     0,
       0,     0,   395,   887,   898,   903,   901,   880,   866,   955,
     864,   865,  1002,     0,   394,     0,  1003,  1009,   896,   851,
     875,  1004,   427,     0,   459,   897,   878,   885,   894,   888,
     956,   842,   847,   846,   845,   844,   843,   809,   863,     0,
     813,   910,   835,   944,   943,   945,   819,   818,   838,   950,
     802,   942,   947,   948,   939,   841,   883,   941,   951,   949,
     940,   839,   946,   960,   961,   958,   959,   957,   810,   962,
     963,   964,   930,   929,   916,   833,   826,   923,   919,   836,
     832,   931,   932,   822,   823,   816,   825,   928,   927,   924,
     920,   937,   938,   936,   926,   922,   915,   824,   935,   934,
     828,   830,   829,   921,   925,   917,   831,   918,   827,   933,
     986,   987,   988,   989,   990,   991,   967,   968,   966,   972,
     973,   974,   969,   970,   971,   840,   992,   993,   994,   995,
     996,   997,   998,     0,     0,  1010,  1011,  1012,  1015,  1014,
    1013,  1016,   163,   163,     0,     2,   163,     7,     9,    21,
       0,    26,    29,    34,    35,    36,    37,    38,    39,    40,
      30,    56,    57,    31,    32,     0,    74,    77,    78,    33,
      79,    80,     0,   116,    81,    82,    83,    84,    16,   160,
     161,   162,   169,   171,   479,   172,     0,   173,   174,   175,
     176,   177,   178,   179,   182,     0,   208,   217,   212,   244,
     250,     0,   242,   243,   219,   213,   181,   214,   180,   215,
     218,   348,   350,   352,   362,   364,   368,   370,   373,   378,
     381,   384,   386,   388,   390,     0,   392,   399,   398,   400,
       0,   418,   401,   423,   426,   428,   431,   433,     0,   438,
     435,     0,   446,   456,   458,   432,   463,   470,   484,   471,
     472,   473,   476,   477,   474,   475,   501,   503,   504,   505,
     502,   550,   551,   552,   553,   554,   555,   455,   592,   584,
     591,   590,   589,   586,   588,   585,   587,   485,   478,   619,
     620,    41,   220,   221,   223,   222,   224,   216,   481,   482,
     483,   480,   226,   229,   225,   227,   228,   457,   795,   811,
     904,   913,   911,   813,     0,   164,   165,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   124,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,   254,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,   273,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   451,   454,   441,     0,     0,   797,   821,   799,   852,
     914,   801,   862,   803,   873,   806,   808,   807,   891,   999,
    1006,   796,  1000,   850,  1001,  1007,   874,  1005,  1008,   955,
    1002,  1003,  1009,  1004,   956,   950,   942,   948,   939,   839,
     960,   961,   958,   810,   962,  1011,   447,   457,   795,   439,
       0,   189,   440,   443,   797,   798,   799,   803,   804,   805,
     806,   796,   802,   489,     0,   445,   444,   184,     0,     0,
     208,     0,   801,   808,   807,     0,   166,   770,   962,     0,
     217,     0,   490,     0,   517,     0,   450,   793,     0,   794,
     421,   422,     0,   453,   452,   442,   425,     0,     0,   546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     772,     0,   774,     0,     0,   163,     3,     4,     1,     8,
      10,     0,     0,     0,     0,     0,   163,   163,   163,   163,
       0,   117,   170,     0,     0,   187,     0,     0,     0,   196,
       0,     0,     0,     0,     0,     0,     0,     0,   201,   230,
     249,   245,   251,   246,   248,   247,     0,     0,     0,   411,
       0,     0,   409,     0,   357,     0,   410,   403,   408,   407,
     406,   405,   404,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   397,   396,   393,     0,     0,   419,   424,     0,
       0,     0,   434,   467,   437,   436,   448,     0,   464,     0,
       0,   557,   559,   563,     0,   122,     0,   792,    45,    42,
      43,    46,    47,     0,     0,     0,     0,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   629,
     630,   631,     0,   101,   140,     0,     0,   110,     0,     0,
       0,     0,   125,     0,     0,     0,   598,     0,     0,     0,
     594,     0,     0,     0,   608,     0,     0,   253,   255,     0,
     232,   233,   252,     0,     0,     0,   132,     0,   136,   166,
     622,     0,    58,     0,    67,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,   599,     0,     0,     0,     0,
     321,     0,     0,   597,     0,     0,     0,   616,     0,     0,
       0,     0,   602,     0,     0,   191,     0,     0,   185,   183,
       0,     0,   776,     0,     0,     0,   489,     0,   771,     0,
     491,   518,   517,   514,     0,     0,   548,   547,   420,     0,
     545,     0,   642,   643,   797,   799,   803,   806,   796,   783,
       0,   593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   648,     0,   199,   200,     0,     0,     0,     0,
       0,   204,   205,   773,   775,     0,     5,    22,     0,    23,
       0,     6,    27,     0,    13,    28,     0,    17,   904,    75,
      14,    76,    18,   190,   188,     0,   209,   211,     0,     0,
       0,     0,   202,   231,   290,   349,   351,   355,   361,   360,
     359,     0,   356,   353,   354,     0,   365,   372,   371,   369,
     375,   376,   377,   374,   379,   380,   383,   382,     0,     0,
       0,     0,   402,   416,     0,   429,   430,     0,   468,   497,
     465,   499,     0,   621,   495,     0,     0,   119,   121,     0,
       0,     0,   100,     0,    90,    92,    93,    94,    95,    97,
      98,    99,    91,    96,    86,    87,     0,     0,   106,     0,
     102,   104,   105,   112,     0,     0,    85,    44,     0,     0,
       0,     0,     0,     0,     0,   720,   725,     0,     0,   721,
     755,   708,   710,   711,   712,   714,   716,   715,   713,   717,
       0,     0,     0,     0,     0,   109,     0,   142,     0,     0,
     562,   556,   595,   596,     0,     0,   612,     0,   609,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,     0,   240,   138,     0,     0,   133,     0,     0,     0,
       0,     0,     0,    60,     0,     0,     0,   271,   277,   274,
       0,   601,   600,   607,   615,     0,     0,     0,     0,   561,
       0,     0,     0,   412,     0,     0,     0,     0,   605,     0,
     603,     0,   192,     0,     0,   777,     0,     0,     0,     0,
     517,   515,     0,   506,     0,   493,   494,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   197,     0,   801,
     808,   807,   962,     0,     0,     0,   656,     0,   206,     0,
       0,     0,     0,   163,   163,   163,     0,   210,   241,     0,
     305,   301,   303,     0,   291,   292,   358,     0,     0,     0,
       0,   686,   366,   659,   663,   665,   667,   669,   672,   679,
     680,   688,   914,   800,     0,   809,  1015,  1014,  1013,  1016,
     385,   568,   574,   575,   578,   623,   624,   579,   580,   786,
     787,   788,   583,   387,   389,   565,   391,   417,   469,     0,
     466,   496,   123,    54,    55,    52,    53,   129,   128,     0,
      88,     0,     0,   107,   108,   113,    72,    73,    50,    51,
      71,   726,     0,   729,   756,     0,   719,   718,   723,   722,
     754,     0,     0,   731,     0,   727,   730,   709,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   141,   144,
     146,     0,     0,     0,   111,   114,     0,     0,     0,   166,
       0,     0,   616,     0,     0,     0,   257,     0,   567,     0,
     258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,     0,   284,     0,   281,   286,   239,
     139,   134,   137,     0,   186,     0,     0,    69,    63,    66,
      65,     0,    61,   275,     0,     0,   166,     0,   319,   323,
       0,     0,     0,   326,     0,     0,   332,     0,     0,   339,
       0,   343,     0,   414,   413,   166,     0,     0,   193,     0,
     195,   320,     0,     0,     0,     0,   518,     0,   507,     0,
     541,   538,     0,   542,   543,     0,     0,   537,     0,   512,
     540,   539,     0,     0,     0,   635,   636,   632,     0,     0,
     640,   641,   637,   779,   780,   646,   784,   644,     0,     0,
       0,     0,   650,   198,     0,     0,     0,     0,     0,     0,
     651,   652,     0,   207,   782,    24,     0,    15,    19,    20,
     302,   314,     0,   315,     0,   306,   307,   308,   309,     0,
     294,     0,     0,     0,   670,   683,     0,   363,   367,     0,
     702,     0,     0,     0,     0,     0,     0,   658,   660,   661,
     697,   698,   699,   701,   700,     0,     0,   674,   673,     0,
     677,   681,   695,   693,   692,   685,   689,     0,     0,     0,
       0,     0,     0,     0,     0,   571,   573,   572,   569,   566,
     498,   500,   131,   130,    89,   103,   743,   724,     0,   748,
       0,   748,   737,   732,   145,   147,     0,     0,     0,   115,
     143,     0,    25,     0,   613,   614,   617,   610,   611,   256,
       0,     0,   270,   262,     0,   266,     0,   260,     0,     0,
       0,   279,     0,     0,     0,   238,   282,   285,     0,   135,
       0,     0,    68,     0,    62,   276,     0,     0,   322,   324,
     329,     0,   327,     0,     0,     0,     0,     0,   333,     0,
       0,     0,     0,   340,     0,     0,   344,   415,     0,   606,
     604,   194,   778,     0,     0,   517,     0,     0,   549,     0,
     517,     0,   513,    12,     0,     0,     0,     0,     0,     0,
       0,   649,     0,     0,     0,     0,     0,   653,   657,   318,
     316,   317,   310,   311,   312,   304,     0,     0,   299,     0,
     293,   687,   678,   684,     0,     0,   757,   758,   768,   767,
     766,     0,     0,     0,     0,   759,   664,   765,     0,   662,
     666,     0,     0,   671,   675,     0,   696,   691,   694,   690,
       0,     0,   581,     0,   576,   628,   570,   790,   791,   789,
     577,   744,     0,     0,   742,   749,   750,   746,     0,   741,
       0,   739,     0,     0,     0,     0,     0,     0,   558,   259,
       0,   268,     0,     0,   264,     0,   267,   280,   288,   289,
     283,   237,     0,     0,     0,    64,   278,   564,     0,     0,
     330,   334,   328,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   560,     0,     0,   517,     0,   544,
       0,   517,   633,   634,   638,   639,     0,   645,   785,   647,
       0,     0,     0,     0,   654,   313,   300,   295,     0,   682,
     769,     0,     0,   761,     0,   707,   706,   705,   704,   703,
     668,     0,   760,     0,   625,     0,     0,   753,   752,   751,
       0,   745,   738,   736,     0,   733,   734,   728,   148,   150,
     152,     0,     0,     0,     0,     0,   263,   261,     0,   269,
       0,   203,   347,    70,   325,   331,     0,   345,   341,     0,
       0,     0,   335,     0,     0,   337,     0,   527,   521,   516,
       0,   517,   508,     0,   781,     0,     0,     0,   298,   296,
     763,   762,     0,     0,   626,   582,     0,   747,   740,     0,
       0,   154,   153,     0,     0,     0,     0,   149,   265,     0,
       0,     0,     0,     0,     0,   535,   529,     0,   528,   530,
     536,   533,   523,     0,   522,   524,   534,   510,     0,   509,
       0,   655,   297,   764,   676,   627,   735,   151,   155,     0,
       0,     0,     0,   287,     0,     0,   338,   336,     0,     0,
     520,   531,   532,   519,   525,   526,   511,     0,   156,     0,
       0,     0,   346,   342,     0,     0,     0,     0,     0,     0,
       0,     0,   158,     0,   157,     0,     0,     0,     0,     0,
       0,     0,     0,   159
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1475, -1475,  -231,  -204, -1475,  1173,  1174, -1475,  1172,  -537,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
    -992, -1475, -1475, -1475, -1475,  -219,  -583, -1475,   699,  -118,
   -1475, -1475, -1475, -1475, -1475,   244,   474, -1475, -1475,    12,
    -192,  1014, -1475,  1003, -1475, -1475,  -640, -1475,   410, -1475,
     211, -1475,  -259,  -301, -1475,  -548, -1475,     5,    21,    17,
    -274,  -172, -1475,  -867, -1475, -1475,   210, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475,   580,   -90,  1543,
       0, -1475, -1475, -1475, -1475,   420, -1475, -1475,  -293, -1475,
       8, -1475,   989,  -920,  -720,  -707, -1475, -1475,   664, -1475,
   -1475,   -18,   194, -1475, -1475, -1475,    79, -1250, -1475,   334,
      88, -1475, -1475,    92, -1301, -1475,   919,   182, -1475, -1475,
     179, -1013, -1475, -1475,   180, -1475, -1475, -1264, -1235, -1475,
     174, -1475, -1475,   821,   822, -1475,  -529,   800, -1475, -1475,
    -653,   338,  -639,   328,   340, -1475, -1475, -1475, -1475, -1475,
    1160, -1475, -1475, -1475, -1475, -1475,  -862,  -312,  -684, -1475,
     -86, -1475, -1475, -1475, -1475, -1475, -1475, -1475,   -10,  -814,
   -1475,  -538,   624,   256, -1475,  -417, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475,   770, -1475, -1014, -1475,   159, -1475,   649,
    -792, -1475, -1475, -1475, -1475, -1475,  -292,  -285, -1185,  -877,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
     553,  -741,  -831,  -207,  -874, -1475,    99,  -860, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475,  1029,  1035,  -222,   469,   298,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475, -1475, -1475, -1475,   141, -1475, -1475,   132, -1475,   131,
   -1061, -1475, -1475, -1475,   102,    96,   -74,   361, -1475, -1475,
   -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475, -1475,
   -1475,   106, -1475, -1475, -1475,   -61,   363,   512, -1475, -1475,
   -1475, -1475, -1475,   299, -1475, -1475, -1474, -1475, -1475, -1475,
    -561, -1475,    74, -1475,   -81, -1475, -1475, -1475, -1475, -1306,
   -1475,   121, -1475, -1475, -1475, -1475, -1475,   925, -1475, -1475,
   -1475, -1475, -1475,  -934, -1475, -1475, -1475,  -406,  -371,   221,
    1063, -1475
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   254,   628,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
    1267,   777,   272,   273,   274,   275,   276,   277,   954,   955,
     956,   278,   279,   280,   960,   961,   962,   281,   439,   282,
     283,   704,   284,   441,   442,   443,   458,   767,   768,   285,
    1218,   286,  1688,  1689,   287,   288,   289,   548,   290,   291,
     292,   293,   294,   770,   295,   296,   531,   297,   298,   299,
     300,   301,   302,   638,   303,   304,   861,   862,   305,   306,
     560,   308,   639,   456,  1021,  1022,   309,   640,   310,   642,
     561,   312,   757,   758,  1255,   465,   313,   466,   467,   764,
    1256,  1257,  1258,   643,   644,  1124,  1125,  1538,   645,  1121,
    1122,  1365,  1366,  1367,  1368,   314,   789,   790,   315,  1282,
    1283,  1483,   316,  1285,  1286,   317,   318,  1288,  1289,  1290,
    1291,   319,   320,   321,   322,   901,   323,   324,  1377,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   663,   664,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   698,   693,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   932,   365,   366,   367,  1318,   822,   823,
     824,  1719,  1763,  1764,  1757,  1758,  1765,  1759,  1319,  1320,
     368,   369,  1321,   370,   371,   372,   373,   374,   375,   376,
    1164,  1016,  1150,  1418,  1151,  1573,  1152,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   796,  1231,   387,
     388,   389,   390,  1154,  1155,  1156,  1157,   391,   392,   393,
     394,   395,   396,   851,   852,   397,  1350,  1351,  1654,  1107,
    1132,  1387,  1388,  1133,  1134,  1135,  1136,  1137,  1397,  1563,
    1564,  1138,  1400,  1139,  1544,  1140,  1141,  1405,  1406,  1569,
    1567,  1389,  1390,  1391,  1392,  1668,   733,   981,   982,   983,
     984,   985,   986,  1205,  1593,  1685,  1206,  1591,  1683,   987,
    1431,  1588,  1584,  1585,  1586,   988,   989,  1393,  1401,  1554,
    1394,  1550,  1378,   398,   399,   400,   401,   551,   402,   403,
     404,   405,   406,  1158,  1159,  1160,  1161,  1268,   568,   407,
     408,   409
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -853;
  const short int
  xquery_parser::yytable_[] =
  {
       307,   922,   705,   705,   307,   307,   307,   599,   311,   414,
     417,   418,   311,   311,   311,   708,   909,   622,   641,   559,
     563,   416,   416,   416,   440,   415,   415,   415,   687,   617,
    1072,   910,   911,   912,   913,   879,   881,  1284,  1036,  1014,
     614,  1504,  1272,  1130,   619,   839,  1106,   576,   606,   607,
    1048,   847,  1015,  1493,   626,   774,   778,  1220,  1153,  1153,
    1317,   626,   728,   526,  1062,  1533,  1534,  1373,   874,   877,
     880,   882,  1208,   743,  1178,   941,  1244,  1209,   748,   872,
     875,  1010,  1018,  1182,     9,    10,   463,   578,  1163,  1236,
     621,    11,  1210,  1565,  1211,   749,   626,  1153,   786,     9,
      10,  1691,  1274,  1212,   615,   425,   826,   707,   307,  1094,
     811,   615,   615,   615,   426,   810,   311,   615,  1686,   897,
     425,   898,   899,  1484,   900,   549,   902,   615,   615,   415,
    1213,  1219,   428,  1512,   903,   904,  1012,   429,  1484,  1011,
     626,  1012,   622,   581,  1717,   582,   707,   428,  1045,   626,
     765,  1153,  1629,   601,   603,   936,   626,   626,   588,  1484,
     627,   590,  1077,  1241,  1153,  1428,   591,   627,   626,   430,
     431,  1116,    79,     9,    10,   421,   422,   626,   423,   424,
    1238,  -167,   626,  1251,   611,   739,    90,  1245,  1252,  1362,
    1665,   626,  1013,  1261,   970,   427,   971,  1666,   737,  1458,
     612,   623,   627,   738,   626,   667,   419,  1667,  1692,  1485,
    1364,   104,  -168,   626,  1551,  1127,   444,   626,  1128,   766,
    1630,  1078,  1185,   668,  1619,  1430,  1012,  1087,   626,  1046,
     775,  1655,   583,   464,  1718,   937,  1088,  1095,   773,   125,
     972,   464,   626,   626,  1019,  1624,   627,   589,   621,   626,
     592,  1356,   307,   307,  1379,   627,   307,   688,  1214,   620,
     311,   311,   627,   627,   311,  1776,  1130,  1130,   641,  1493,
    1409,   579,  1487,   827,   627,   622,  1249,   776,  1307,  1474,
     818,  1020,  1260,   627,  1153,  1684,   879,   881,   627,   464,
    1693,   307,  1220,   616,   527,  1317,  1246,   627,   433,   311,
     618,   867,   869,  1179,  1317,   420,  1113,  1242,   543,  1247,
     627,  1582,  1423,   464,  1543,  1449,  1115,  1355,   464,   627,
     967,  1129,  1512,   627,  1168,   464,   623,  1380,   626,  1275,
     872,   875,   564,   626,   627,   820,  1347,   626,   694,   624,
     626,   696,  1028,  1050,   569,   436,   572,  1716,   627,   627,
    1215,  1216,  1217,   437,  1051,   627,  1310,  1311,   434,   753,
     740,   438,   892,  1098,   863,  -167,  1219,   748,   741,   771,
    1045,  1033,  1126,   864,  1552,  1553,  1583,  1303,   783,   626,
     477,   447,   868,   870,   749,   794,   795,  1073,  1726,  1741,
    1304,   973,   626,  1352,   801,   626,  -168,   873,   876,   435,
    1004,   866,  1029,  1153,   974,  1032,   975,  1728,   626,   936,
    1381,  1382,   626,  1383,  1305,  1630,   307,   976,   977,   978,
    1384,   979,   625,   980,   311,  1005,   811,  1153,  1650,  1651,
    1385,  1012,  1469,  1379,   627,  1652,   713,   448,   585,   627,
     586,  1778,  1386,   627,   717,   307,   627,   307,    11,  1011,
    1312,  1064,   714,   311,  1074,   311,  1490,   478,  1079,   623,
    1007,  1083,   745,  1173,   745,  1025,   744,   691,   747,   697,
    1313,   622,  1314,   307,  1661,   825,  1011,   718,   307,  1772,
    1174,   311,  1450,  1011,  1439,   627,   311,   829,  1131,   938,
     745,  1493,  1755,  1317,   792,   745,  1310,  1653,   627,   798,
    1315,   627,  1047,   812,   111,  1006,  1380,   857,   859,   750,
     723,  1040,   724,  1130,   627,   457,  1056,  1451,   627,  1172,
    1075,   123,  1130,  1076,  1035,   479,   480,   587,  1057,    79,
     879,   881,   879,  1130,  1059,  1106,  1248,  1436,  1528,  1459,
    1008,   459,  1316,    90,   725,  1026,   723,  1153,   724,   307,
    1520,  1662,  1310,  1311,  1352,  1339,   307,   311,  1186,  1187,
     149,  1169,  1105,  1190,   311,  1357,  1358,  1359,   104,   527,
     686,   726,   527,   416,   470,  1167,  1572,   415,  1541,  1169,
     471,  1012,  1080,  1081,   622,  1084,  1085,  1310,  1311,  1381,
    1382,  1771,  1383,  1228,   125,  1774,   924,  1082,   307,   475,
    1086,   927,    11,   925,   926,   307,   311,   726,  1058,  1385,
    1313,  1308,  1314,   311,  1060,   858,   307,   307,   307,   307,
    1756,  1386,  1703,   440,   311,   311,   311,   311,  1675,  1539,
    1680,  1153,  1602,   727,  1153,  1415,   307,   451,  1487,   452,
    1315,  1170,  1114,   472,   311,   870,  1312,   716,  1110,  1375,
     720,  1546,   630,   476,   569,   623,   631,   734,   735,  1171,
    1628,   632,  1011,  1632,   667,   569,  1313,  1416,  1314,   727,
    1202,   756,   759,   125,  1362,   676,   759,  1175,  1309,   633,
    1090,  1312,   668,    79,   779,  1417,  1011,  1203,  1547,   677,
     569,   787,   788,   791,  1176,   565,  1315,    90,   797,  1130,
     111,  1313,   453,  1314,  1428,  1755,   804,   454,  1676,  1310,
    1681,  1131,  1131,  1636,   958,  1310,  1311,   123,  1640,   959,
     670,  1429,   104,  1067,  1068,  1069,  1127,   859,   630,  1128,
    1204,  1315,   631,  1558,  1061,   111,  1603,   632,  1506,   630,
     691,   957,   697,   631,  1202,   307,  1011,  1111,   632,   671,
     125,   805,   123,   311,   455,   633,   149,  1597,  1536,   674,
     577,  1203,   672,   612,  1430,   791,   633,   483,   675,   307,
     460,  1177,   879,  1511,  1027,  1665,   816,   311,   634,  1422,
     461,   635,  1666,  1230,   958,  1233,   416,   769,   709,   959,
     415,   149,  1667,   481,  1537,   769,   636,   673,   484,   307,
     307,   485,   710,  1222,   840,   711,   462,   311,   311,  1312,
     840,   641,  1223,  1153,   853,  1153,   745,   745,   687,   712,
    1054,  1055,   637,  1313,  1343,  1314,  1281,  1251,  1310,  1313,
     883,  1314,  1252,  1791,   884,  1296,  1180,  1297,   482,  1481,
    1760,  1766,  1734,   667,  1735,  1720,  1153,  1761,  1180,  1723,
    1251,  1253,  1310,  1315,   634,  1252,   667,   635,  1103,  1315,
    1472,   668,  1196,   111,  1281,   634,  1104,  1198,   635,  1491,
    1012,  1761,   819,  1197,   668,  1750,  1153,  1486,  1199,   870,
     123,  1760,  1492,  1348,   669,  1402,  1403,  1766,  1548,   529,
     440,  1153,  1254,  1153,  1494,  1549,   530,  1732,   637,  1663,
    1664,  1638,     9,    10,  1361,  1775,  1660,  1495,  1404,   637,
    1690,  1491,   532,   421,   422,  1362,   423,   424,  1491,   149,
    1785,   533,  1788,   425,  1635,  1363,   729,   730,   731,  1768,
     599,  1770,   426,   427,   445,  1353,  1364,   446,   544,  1191,
    1192,  1193,  1313,   963,  1314,  1194,   689,   690,   928,  1742,
     428,   928,   545,  1762,   928,   429,  1529,   993,  1131,   546,
     449,   997,   998,   450,  1188,  1189,  1313,  1131,  1314,   566,
     468,   692,  1315,   469,   695,   573,   473,  1794,  1131,   474,
     691,  1323,   697,  1324,  1017,   574,  1023,   430,   431,   432,
    1328,  1470,  1329,   575,   569,   580,  1315,   569,  1530,  1531,
     584,  1037,   914,   915,   593,   907,   908,   594,  1730,  1731,
     596,  1690,  1434,  1435,   595,   648,   916,   917,   597,  1165,
    1165,  1677,  1678,   649,   650,   598,   651,   604,   608,   629,
     647,   646,   665,   666,   652,   678,   433,  1372,   653,   681,
     654,   679,  1070,   680,   685,   655,   691,   699,   707,   700,
     701,   702,   307,   703,   719,   721,  1690,   722,   732,   760,
     311,   736,   656,   763,   746,   769,   761,  1615,   772,   745,
     780,   781,   782,  1292,   892,   793,   799,   800,   446,  1773,
     808,   527,   450,   469,   474,   806,   657,   658,   659,   660,
     661,   662,   485,   810,   821,   828,   434,   813,  1103,   830,
     814,   817,   815,   831,   841,   849,  1104,   871,   850,  1118,
     854,   855,   888,   307,   307,   307,   905,   889,   860,   919,
     890,   311,   311,   311,   440,   891,   918,  1814,   920,  1815,
    1656,   921,   933,   939,   940,   942,   528,   435,  1823,  1162,
    1162,  1162,  1162,   968,  1131,   969,   964,   965,   991,   992,
     528,   944,   945,   946,   947,   948,   949,   950,   951,   952,
     953,   990,   994,   436,   999,   996,  1000,  1002,  1001,  1009,
    1024,   437,  1031,  1030,   528,  1003,  1034,  1041,  1162,   438,
    1042,  1049,  1043,  1044,  1052,  1053,   528,  1089,   528,   445,
    1091,   449,  1195,   468,   473,   484,  1092,  1093,  1096,  1097,
    1109,  1112,  1117,  1119,  1123,  1181,   959,  1011,  1200,  1226,
    1227,  1621,  1237,  1229,  1239,  1243,  1201,  1225,  1221,   765,
    1263,  1265,  1250,  1264,  1266,  1269,  1232,  1270,  1232,   307,
     759,  1271,  1162,  1281,  1443,  1276,  1277,   311,  1280,  1287,
    1295,  1293,  1294,  1300,  1299,  1162,   416,  1306,  1322,  1302,
     415,  1347,  1340,  1344,  1523,  1524,  1525,  1349,  1369,  1345,
     725,  1346,  1371,  1376,  1395,   307,  1399,  1407,  1396,  1419,
    1408,    11,  1410,   311,  1427,  1411,   307,  1412,   797,  1413,
     797,  1477,  1432,  1438,   311,  1414,  1426,  1446,  1441,  1437,
    1442,  1454,  1456,   416,  1444,   307,  1445,   415,  1463,  1447,
    1498,  1460,  1464,   311,  1448,  1462,  1468,  1473,  1476,  1499,
    1491,  1500,   416,  1508,   840,   307,   415,  1505,  1503,  1518,
    1497,  1513,  1514,   311,  1522,  1519,  1362,  1515,  1542,  1545,
    1561,  1555,   745,  1562,  1566,  1568,  1509,  1574,  1701,  1575,
    1576,  1516,  1581,  1517,  1370,  1587,  1577,  1103,  1103,  1705,
    1621,  1578,  1707,  1592,  1579,  1104,  1104,  1580,  1594,  1715,
    1598,  1590,  1600,  1605,   858,  1162,  1612,  1613,  1614,  1658,
    1617,  1646,  1673,  1618,  1671,  1623,  1626,  1633,  1634,  1639,
    1659,  1682,  1202,  1695,  1674,  1687,  1694,  1596,  1700,  1706,
    1698,  1710,  1714,  1536,  1736,  1737,  1722,  1739,  1740,  1744,
    1725,  1749,  1738,  1745,  1751,  1753,  1767,  1781,  1752,  1793,
    1784,   528,  1672,  1790,   528,  1769,  1789,  1782,  1804,  1797,
    1801,  1805,  1796,  1810,   966,  1820,  1425,  1816,  1819,   609,
     610,   613,  1183,  1817,   706,  1262,  1747,  1440,  1807,  1777,
    1707,  1108,  1259,   742,   762,  1779,  1039,  1799,  1610,  1467,
    1540,  1470,  1808,  1360,  1811,  1813,   759,  1535,  1532,  1478,
    1452,  1482,  1822,   807,  1496,  1488,   906,   895,  1507,   896,
     935,  1071,  1795,  1792,  1166,  1466,  1234,   751,  1786,  1424,
    1526,  1521,  1527,   752,  1162,   307,  1556,  1670,   715,   528,
    1374,  1560,   528,   311,  1559,   684,   528,  1669,   791,   528,
     528,  1398,  1207,  1433,  1679,  1589,  1557,   528,  1162,     0,
    1802,     0,   845,   528,   528,     0,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,   528,     0,     0,     0,
       0,  1802,   528,   528,   528,   528,  1786,  1510,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   853,     0,  1727,     0,     0,     0,     0,     0,     0,
     527,     0,     0,   527,     0,     0,     0,     0,     0,     0,
       0,  1733,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,     0,     0,
       0,     0,  1103,     0,     0,     0,     0,     0,   528,     0,
    1104,     0,     0,  1103,  1103,     0,   307,     0,  1162,     0,
       0,  1104,  1104,  1103,   311,     0,     0,     0,     0,     0,
       0,  1104,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   550,     0,     0,     0,     0,   528,     0,  1595,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1608,  1609,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1625,     0,  1162,     0,  1103,  1162,     0,     0,     0,     0,
       0,     0,  1104,     0,     0,  1103,     0,  1637,     0,     0,
       0,     0,  1641,  1104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   307,     0,     0,     0,     0,     0,     0,     0,
     311,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   943,     0,   307,   528,     0,     0,     0,     0,
       0,     0,   311,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,   528,   528,  1103,     0,     0,     0,     0,
    1103,     0,     0,  1104,     0,     0,     0,     0,  1104,     0,
       0,     0,     0,     0,     0,     0,   528,     0,   528,     0,
       0,     0,     0,     0,     0,     0,   528,     0,     0,   528,
       0,     0,     0,   528,     0,     0,     0,     0,  1709,     0,
    1711,     0,  1713,     0,     0,     0,     0,     0,     0,  1721,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1162,     0,  1162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1743,     0,     0,  1746,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,  1162,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1754,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,     0,     0,  1162,     0,     0,
       0,     0,     0,     0,     0,  1780,     0,     0,     0,     0,
    1783,     0,  1162,     0,  1162,     0,     0,     0,     0,     0,
       0,   528,   528,   528,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1800,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1806,     0,
     528,     0,  1809,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,     0,     0,     0,  1818,     0,
       0,  1821,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,   528,     0,
     528,     0,   528,     0,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   550,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,   528,     0,   832,   833,     0,     0,   842,   843,
     844,   846,     0,   848,     0,     0,     0,     0,     0,   856,
       0,     0,     0,     0,     0,     0,     0,   865,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   885,
     886,   887,     0,     0,     0,     0,     0,     0,     0,   893,
     894,     0,     0,     0,     0,     0,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     931,     0,     0,   931,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   995,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   528,     0,
       0,     0,   528,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   528,     0,     0,
       0,     0,     0,     0,  1038,     0,   528,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,  1063,
     528,     0,     0,  1065,  1066,     0,     0,     0,     0,     0,
       0,     0,   893,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,     0,   528,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1120,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,  1184,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1224,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   528,     0,   528,     0,  1240,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,   528,     0,     0,     0,  1273,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1278,
    1279,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1298,     0,     0,  1301,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1325,  1326,  1327,     0,  1330,  1331,  1332,
    1333,  1334,  1335,  1336,  1337,  1338,     0,     0,  1341,  1342,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1354,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,   528,     0,   528,     0,     0,     0,     0,     0,
       0,   528,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1421,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   528,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   528,     0,     0,   528,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   528,
       0,     0,     0,     0,  1453,     0,  1455,     0,  1457,     0,
       0,  1461,     0,     0,     0,     0,  1465,     0,     0,   528,
       0,     0,     0,     0,     0,     0,     0,   528,  1471,     0,
       0,     0,   528,     0,   528,     0,   528,  1475,     0,     0,
       0,     0,     0,  1479,  1480,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1501,     0,   528,  1502,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,     0,   528,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     528,     0,     0,   528,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1599,     0,     0,     0,  1601,     0,     0,
       0,  1604,     0,  1606,     0,  1607,     0,     0,     0,     0,
       0,  1611,     0,     0,     0,     0,     0,     0,     0,  1616,
       0,     0,     0,     0,     0,     0,     0,  1620,  1622,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1471,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1642,  1643,  1644,
    1645,     0,  1647,  1648,     0,  1649,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1657,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1696,     0,  1697,     0,     0,  1699,     0,
       0,     0,     0,     0,     0,     0,  1702,     0,     0,     0,
       0,  1704,  1622,     0,     0,     0,     0,     0,     0,  1708,
       0,     0,     0,  1712,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1724,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1729,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1748,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1708,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1787,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1798,     0,     0,     0,     0,  1803,     0,     0,
       0,     0,  1787,     0,     0,   871,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     0,     0,  1803,     0,     0,
       0,  1812,     3,     4,     5,     6,     7,     8,     0,     0,
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
     249,   250,   251,  -852,   451,     0,   452,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -852,     0,     0,     0,  -852,
       0,     0,     0,  -852,  -852,     0,     0,     0,  -852,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   453,
       0,     0,  -852,     0,   454,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -852,     0,  -852,  -852,  -852,
       0,     0,  -852,  -852,  -852,  -852,     0,     0,     0,  -852,
    -852,     0,     0,     0,     0,     0,  -852,     0,     0,  -852,
    -852,   455,     0,     0,  -852,     0,     0,     0,     0,  -852,
    -852,     0,     0,     0,     0,  -852,     0,     0,     0,  -852,
       0,     0,     0,  -852,  -852,     0,  -852,     0,  -852,  -852,
       0,     0,     0,  -852,  -852,     0,     0,  -852,  -852,  -852,
    -852,  -852,  -852,     0,     0,  -852,     0,     0,     0,     0,
    -852,  -852,     0,     0,  -852,     0,     0,     0,     0,  -852,
       0,     0,  -852,     0,     0,     0,     0,  -852,  -852,  -852,
    -852,  -852,     0,  -852,  -852,  -852,  -852,  -852,     0,     0,
       0,     0,  -852,  -852,  -852,     0,  -852,  -852,  -852,  -852,
    -852,  -852,     0,  -852,     0,  -852,     0,     0,     0,     0,
    -852,  -852,  -852,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -852,     0,  -852,     0,
    -852,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -852,     0,     0,     0,     0,  -852,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,  -852,     0,  -852,    12,    13,     0,
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
     247,   248,   249,   250,   251,   252,   253,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
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
       0,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     0,   605,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
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
     128,     0,   547,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
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
     128,     0,   809,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1099,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1100,  1101,    50,    51,    52,    53,    54,    55,    56,    57,
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
     128,     0,   809,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1102,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1099,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1100,  1101,    50,    51,    52,    53,    54,    55,    56,    57,
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
     128,     0,   547,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1102,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
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
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,    13,     0,    14,    15,    16,    17,    18,    19,
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
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,    13,     0,    14,    15,    16,    17,    18,    19,
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
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,    12,   411,     0,    14,    15,    16,    17,    18,    19,
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
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   878,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,   412,    28,    29,
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
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,   929,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   930,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,   929,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   934,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     9,    10,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1099,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1100,  1101,    50,    51,    52,    53,    54,    55,    56,    57,
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
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,  1102,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,   557,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   562,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   600,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,   602,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,   923,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,  1420,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   682,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   683,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   552,   412,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     553,   554,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   520,   521,   522,   176,
     177,   523,   558,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   556,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   410,   411,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   489,    25,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,    46,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     503,    82,    83,    84,    85,    86,   555,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,     0,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,     0,   106,
     107,   556,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,     0,   134,     0,   135,     0,   136,     0,   138,     0,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   525,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   410,   411,     0,    14,    15,    16,   486,    18,    19,
      20,   487,    22,   488,   489,   490,   491,   412,    28,   492,
      30,    31,     0,    32,    33,    34,    35,   493,    37,    38,
      39,    40,    41,    42,    43,   494,     0,    45,   495,    47,
     496,   497,    50,   498,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   499,   500,
      68,     0,    69,    70,    71,   501,     0,     0,    74,    75,
      76,     0,     0,   502,    78,     0,     0,     0,     0,    80,
     503,    82,   504,   505,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   506,    97,    98,   507,   508,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   509,   120,   121,
     510,     0,     0,     0,     0,     0,     0,     0,   511,   512,
     128,     0,     0,     0,   129,     0,   130,   513,     0,     0,
       0,     0,   134,     0,   135,     0,   136,   137,   138,   139,
     514,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   413,   151,   152,   153,   154,   155,   156,
     157,   158,   515,   160,   516,   162,   517,   518,   165,   166,
     167,   168,   169,   170,   519,   172,   520,   521,   522,   176,
     177,   523,   524,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       1,     2,   245,   525,   247,   248,   249,   250,   251,     3,
       0,     0,     0,     7,     8,     0,     0,     0,     0,     0,
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
       0,     0,     0,   134,     0,   135,     0,   136,   137,   138,
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
       0,     0,   567,   245,   525,   247,   248,   249,   250,   251,
       7,     8,     0,     0,     0,   784,     0,     0,     0,   410,
     411,     0,    14,    15,    16,   534,    18,    19,    20,   487,
     535,   536,   489,   490,   491,   412,    28,   492,    30,    31,
       0,    32,    33,    34,    35,   537,    37,   538,   539,    40,
      41,    42,    43,   494,     0,    45,   540,    47,   496,   497,
      50,   498,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   499,   500,    68,     0,
      69,    70,    71,   541,     0,     0,    74,    75,    76,     0,
       0,   502,    78,     0,     0,     0,     0,    80,   503,    82,
     504,   505,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   506,    97,    98,   507,   508,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   509,   120,   121,   510,     0,
       0,     0,     0,     0,     0,     0,   511,   512,   128,     0,
       0,     0,   129,   785,   130,   513,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   514,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     515,   542,   516,   162,   517,   518,   165,   166,   167,   168,
     169,   170,   519,   172,   520,   521,   522,   176,   177,   523,
     524,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,   567,
     245,   525,   247,   248,   249,   250,   251,     7,     8,     0,
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
     240,   241,   242,     0,     0,     0,     0,   245,   525,   247,
     248,   249,   250,   251,   570,   571,     0,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   410,
     411,     0,    14,    15,    16,   534,    18,    19,    20,   487,
     535,   536,   489,   490,   491,   412,    28,   492,    30,    31,
       0,    32,    33,    34,    35,   537,    37,   538,   539,    40,
      41,    42,    43,   494,     0,    45,   540,    47,   496,   497,
      50,   498,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   499,   500,    68,     0,
      69,    70,    71,   541,     0,     0,    74,    75,    76,     0,
       0,   502,    78,     0,     0,     0,     0,    80,   503,    82,
     504,   505,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   506,    97,    98,   507,   508,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   509,   120,   121,   510,     0,
       0,     0,     0,     0,     0,     0,   511,   512,   128,     0,
       0,     0,   129,     0,   130,   513,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   514,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     515,   542,   516,   162,   517,   518,   165,   166,   167,   168,
     169,   170,   519,   172,   520,   521,   522,   176,   177,   523,
     524,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     0,     0,
     245,   525,   247,   248,   249,   250,   251,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   410,
     411,     0,    14,    15,    16,   834,    18,    19,    20,    21,
     535,   835,   489,    25,   491,   412,    28,   492,    30,    31,
       0,    32,    33,    34,    35,   836,    37,   538,   539,    40,
      41,    42,    43,   494,     0,    45,   837,    47,   496,   497,
      50,   498,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   499,   500,    68,     0,
      69,    70,    71,   838,     0,     0,    74,    75,    76,     0,
       0,   502,    78,     0,     0,     0,    79,    80,   503,    82,
     504,   505,    85,    86,   555,    88,     0,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   506,    97,    98,   507,   508,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   556,
     109,     0,   110,   111,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   510,     0,
     123,     0,     0,     0,     0,     0,   511,   512,   128,     0,
       0,     0,   129,     0,   130,   513,     0,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   413,   151,   152,   153,   154,   155,   156,   157,   158,
     515,   542,   516,   162,   517,   518,   165,   166,   167,   168,
     169,   170,   519,   172,   520,   521,   522,   176,   177,   523,
     524,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   525,   247,   248,   249,   250,   251,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   410,   411,     0,    14,
      15,    16,   486,    18,    19,    20,   487,    22,   488,   489,
    1142,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   493,    37,    38,    39,    40,    41,    42,    43,
     494,     0,    45,   495,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     501,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1143,     0,     0,     0,  1144,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
    1570,   130,   513,     0,     0,     0,     0,  1571,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,  1145,   148,     0,     0,   413,   151,
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
    1146,  1147,  1148,  1149,   410,   411,     0,    14,    15,    16,
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
       0,   511,   512,   128,     0,     0,     0,   129,   754,   130,
     513,     0,     0,     0,     0,   755,     0,   135,     0,   136,
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
     512,   128,     0,     0,     0,   129,   802,   130,   513,     0,
       0,     0,     0,   803,     0,   135,     0,   136,   137,   138,
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
     410,   411,     0,    14,    15,    16,   486,    18,    19,    20,
     487,    22,   488,   489,  1142,   491,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,   493,    37,    38,    39,
      40,    41,    42,    43,   494,     0,    45,   495,    47,   496,
     497,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,   501,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,  1489,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   506,    97,    98,   507,   508,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1143,
       0,     0,     0,  1144,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   509,   120,   121,   510,
       0,     0,     0,     0,     0,     0,     0,   511,   512,   128,
       0,     0,     0,   129,     0,   130,   513,     0,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   514,
     141,   142,   143,   144,   145,   146,     0,     0,  1145,   148,
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
       8,   245,   525,   247,  1146,  1147,  1148,  1149,   410,   411,
       0,    14,    15,    16,   486,    18,    19,    20,   487,    22,
     488,   489,  1142,   491,   412,    28,   492,    30,    31,     0,
      32,    33,    34,    35,   493,    37,    38,    39,    40,    41,
      42,    43,   494,     0,    45,   495,    47,   496,   497,    50,
     498,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   499,   500,    68,     0,    69,
      70,    71,   501,     0,     0,    74,    75,    76,     0,     0,
     502,    78,     0,     0,     0,     0,    80,   503,    82,   504,
     505,    85,    86,  1627,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     506,    97,    98,   507,   508,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1143,     0,     0,
       0,  1144,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   509,   120,   121,   510,     0,     0,
       0,     0,     0,     0,     0,   511,   512,   128,     0,     0,
       0,   129,     0,   130,   513,     0,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   514,   141,   142,
     143,   144,   145,   146,     0,     0,  1145,   148,     0,     0,
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
     525,   247,  1146,  1147,  1148,  1149,   410,   411,     0,    14,
      15,    16,   486,    18,    19,    20,   487,    22,   488,   489,
    1142,   491,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,   493,    37,    38,    39,    40,    41,    42,    43,
     494,     0,    45,   495,    47,   496,   497,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
     501,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,  1631,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1143,     0,     0,     0,  1144,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,  1145,   148,     0,     0,   413,   151,
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
    1146,  1147,  1148,  1149,   410,   411,     0,    14,    15,    16,
     486,    18,    19,    20,   487,    22,   488,   489,  1142,   491,
     412,    28,   492,    30,    31,     0,    32,    33,    34,    35,
     493,    37,    38,    39,    40,    41,    42,    43,   494,     0,
      45,   495,    47,   496,   497,    50,   498,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   499,   500,    68,     0,    69,    70,    71,   501,     0,
       0,    74,    75,    76,     0,     0,   502,    78,     0,     0,
       0,     0,    80,   503,    82,   504,   505,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   506,    97,    98,   507,
     508,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1143,     0,     0,     0,  1144,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     509,   120,   121,   510,     0,     0,     0,     0,     0,     0,
       0,   511,   512,   128,     0,     0,     0,   129,     0,   130,
     513,     0,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   514,   141,   142,   143,   144,   145,   146,
       0,     0,  1145,   148,     0,     0,   413,   151,   152,   153,
     154,   155,   156,   157,   158,   515,   160,   516,   162,   517,
     518,   165,   166,   167,   168,   169,   170,   519,   172,   520,
     521,   522,   176,   177,   523,   524,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   525,   247,  1146,  1147,
    1148,  1149,   410,   411,     0,    14,    15,    16,   486,    18,
      19,    20,   487,    22,   488,   489,  1142,   491,   412,    28,
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
     106,  1143,     0,     0,     0,  1144,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   509,   120,
     121,   510,     0,     0,     0,     0,     0,     0,     0,   511,
     512,   128,     0,     0,     0,   129,     0,   130,   513,     0,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   514,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   413,   151,   152,   153,   154,   155,
     156,   157,   158,   515,   160,   516,   162,   517,   518,   165,
     166,   167,   168,   169,   170,   519,   172,   520,   521,   522,
     176,   177,   523,   524,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   525,   247,  1146,  1147,  1148,  1149,
     410,   411,     0,    14,    15,    16,   534,    18,    19,    20,
     487,   535,   536,   489,   490,   491,   412,    28,   492,    30,
      31,     0,    32,    33,    34,    35,   537,    37,   538,   539,
      40,    41,    42,    43,   494,     0,    45,   540,    47,   496,
     497,    50,   498,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   499,   500,    68,
       0,    69,    70,    71,   541,     0,     0,    74,    75,    76,
       0,     0,   502,    78,     0,     0,     0,     0,    80,   503,
      82,   504,   505,    85,    86,  1235,     0,     0,     0,     0,
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
       0,   129,     0,   130,   513,     0,     0,     0,     0,     0,
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
      15,    16,     0,    18,    19,    20,   487,     0,     0,   489,
     490,     0,   412,    28,   492,    30,    31,     0,    32,    33,
      34,    35,     0,    37,     0,     0,    40,    41,    42,    43,
     494,     0,    45,     0,    47,     0,     0,    50,   498,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   499,   500,    68,     0,    69,    70,    71,
       0,     0,     0,    74,    75,    76,     0,     0,   502,    78,
       0,     0,     0,     0,    80,   503,    82,   504,   505,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   506,    97,
      98,   507,   508,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   509,   120,   121,   510,     0,     0,     0,     0,
       0,     0,     0,   511,   512,   128,     0,     0,     0,   129,
       0,   130,   513,     0,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   514,   141,   142,   143,   144,
     145,   146,     0,     0,     0,   148,     0,     0,   413,   151,
     152,   153,   154,   155,   156,   157,   158,   515,     0,   516,
     162,   517,   518,   165,   166,   167,   168,   169,   170,   519,
     172,   520,   521,   522,   176,   177,     0,   524,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,     0,   245,   525,   247,
     248,   249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   685,   419,   420,     4,     5,     6,   179,     0,     4,
       5,     6,     4,     5,     6,   421,   669,   291,   311,   109,
     110,     4,     5,     6,    12,     4,     5,     6,   340,   260,
     822,   670,   671,   672,   673,   618,   619,  1050,   779,   759,
     259,  1305,  1034,   905,   275,   583,   860,   133,   252,   253,
     791,   589,   759,  1288,     1,   461,   462,   991,   918,   919,
    1074,     1,   433,    73,   805,  1366,  1367,  1128,   616,   617,
     618,   619,    39,   444,   941,   715,    36,    44,    45,   616,
     617,    36,    55,   957,    26,    27,   118,    30,   919,  1009,
     282,    29,    59,  1399,    61,    62,     1,   957,   469,    26,
      27,   118,   142,    70,     1,    47,     8,    29,   108,   107,
     107,     1,     1,     1,    56,   121,   108,     1,  1592,   648,
      47,   650,   651,   100,   653,   108,   655,     1,     1,   108,
      97,   991,    74,  1318,   663,   664,    96,    79,   100,    94,
       1,    96,   416,   225,    93,   227,    29,    74,   107,     1,
     118,  1011,   118,   243,   244,   107,     1,     1,   225,   100,
     107,   225,   131,   147,  1024,    96,   230,   107,     1,   111,
     112,   113,   110,    26,    27,    37,    38,     1,    40,    41,
    1011,     0,     1,    53,    33,   112,   124,   147,    58,   106,
     269,     1,   147,  1024,    54,    57,    56,   276,   137,   147,
      49,   291,   107,   142,     1,   158,   156,   286,   225,   186,
     127,   149,     0,     1,    96,   153,   160,     1,   156,   187,
     186,   190,   963,   176,   186,   156,    96,   233,     1,   188,
     113,  1532,   314,   273,   183,   187,   233,   235,   160,   177,
     100,   273,     1,     1,   217,   186,   107,   314,   440,     1,
     314,   113,   252,   253,    96,   107,   256,   343,   225,   112,
     252,   253,   107,   107,   256,  1739,  1128,  1129,   561,  1504,
    1144,   214,  1285,   175,   107,   549,  1017,   160,  1070,  1271,
     185,   254,  1023,   107,  1144,  1591,   869,   870,   107,   273,
     307,   291,  1226,   190,    73,  1309,  1016,   107,   160,   291,
     190,   190,   190,   943,  1318,   156,   190,  1014,    87,  1016,
     107,   136,  1179,   273,  1375,  1235,   190,   190,   273,   107,
     726,   259,  1507,   107,   185,   273,   416,   169,     1,  1036,
     867,   868,   111,     1,   107,   187,   153,     1,   348,   107,
       1,   351,   187,   187,   123,   287,   125,   118,   107,   107,
     317,   318,   319,   295,   187,   107,     9,    10,   220,   449,
     287,   303,   636,   187,   311,   184,  1226,    45,   295,   459,
     107,   777,   901,   313,   256,   257,   201,   187,   468,     1,
      76,   153,   613,   614,    62,   475,   476,   130,  1652,  1690,
     187,   251,     1,   210,   484,     1,   184,   616,   617,   261,
     184,   605,   773,  1263,   264,   776,   266,  1657,     1,   107,
     252,   253,     1,   255,   187,   186,   416,   277,   278,   279,
     262,   281,   190,   283,   416,   107,   107,  1287,   187,   187,
     272,    96,  1263,    96,   107,   187,   166,   156,   225,   107,
     227,  1742,   284,   107,   169,   445,   107,   447,    29,    94,
     103,   188,   182,   445,   197,   447,  1287,   153,    94,   549,
     107,    94,   445,   148,   447,   107,   445,   154,   447,   156,
     123,   745,   125,   473,    52,   565,    94,   202,   478,  1729,
     165,   473,   147,    94,  1225,   107,   478,   577,   905,   187,
     473,  1726,     5,  1507,   473,   478,     9,   153,   107,   478,
     153,   107,   147,   184,   157,   187,   169,   597,   598,   187,
      45,   184,    47,  1375,   107,   156,   184,  1237,   107,   936,
     184,   174,  1384,   184,   142,   221,   222,   314,   107,   110,
    1113,  1114,  1115,  1395,   107,  1349,   147,  1221,  1352,  1246,
     187,   156,   195,   124,    79,   187,    45,  1407,    47,   549,
     237,   129,     9,    10,   210,  1093,   556,   549,   964,   965,
     213,   107,   184,   969,   556,  1113,  1114,  1115,   149,   348,
     153,   106,   351,   556,   156,   184,  1407,   556,   184,   107,
     156,    96,   218,   219,   858,   218,   219,     9,    10,   252,
     253,   184,   255,   999,   177,   184,   686,   233,   598,   156,
     233,   691,    29,   689,   690,   605,   598,   106,   187,   272,
     123,   130,   125,   605,   187,   598,   616,   617,   618,   619,
     133,   284,  1614,   611,   616,   617,   618,   619,   107,  1370,
     107,  1491,   147,   168,  1494,   144,   636,     1,  1651,     3,
     153,   187,   873,   118,   636,   876,   103,   426,   867,   153,
     429,   217,    42,   156,   433,   745,    46,   436,   437,   187,
    1491,    51,    94,  1494,   158,   444,   123,   176,   125,   168,
      96,   450,   451,   177,   106,   136,   455,   148,   197,    69,
      94,   103,   176,   110,   463,   194,    94,   113,   254,   150,
     469,   470,   471,   472,   165,   153,   153,   124,   477,  1561,
     157,   123,    66,   125,    96,     5,   485,    71,   187,     9,
     187,  1128,  1129,  1505,   137,     9,    10,   174,  1510,   142,
     117,   113,   149,   813,   814,   815,   153,   817,    42,   156,
     156,   153,    46,  1386,   142,   157,  1456,    51,   195,    42,
     154,    94,   156,    46,    96,   745,    94,    33,    51,   146,
     177,   530,   174,   745,   118,    69,   213,  1441,   106,   201,
     153,   113,   159,    49,   156,   544,    69,   122,   210,   769,
      24,   137,  1355,   195,   769,   269,   555,   769,   168,   137,
      34,   171,   276,  1005,   137,  1007,   769,   153,   182,   142,
     769,   213,   286,   122,   142,   153,   186,   194,   153,   799,
     800,   156,   196,   299,   583,   182,    60,   799,   800,   103,
     589,  1104,   308,  1673,   593,  1675,   799,   800,  1130,   196,
     799,   800,   212,   123,  1098,   125,   100,    53,     9,   123,
     620,   125,    58,   133,   624,  1057,   954,  1059,   122,   113,
    1717,  1718,  1673,   158,  1675,  1637,  1706,    28,   966,  1641,
      53,    77,     9,   153,   168,    58,   158,   171,   858,   153,
    1266,   176,   263,   157,   100,   168,   858,   263,   171,   100,
      96,    28,   186,   274,   176,  1706,  1736,   113,   274,  1110,
     174,  1758,   113,   186,   199,   247,   248,  1764,   268,   122,
     878,  1751,   118,  1753,   100,   275,   118,   199,   212,  1552,
    1553,   195,    26,    27,    95,  1736,  1545,   113,   270,   212,
    1594,   100,   122,    37,    38,   106,    40,    41,   100,   213,
    1751,   122,  1753,    47,   113,   116,   221,   222,   223,  1721,
    1102,   113,    56,    57,   153,  1107,   127,   156,   118,   277,
     278,   279,   123,   722,   125,   283,   191,   192,   692,  1690,
      74,   695,   122,   134,   698,    79,  1362,   736,  1375,   122,
     153,   740,   741,   156,   128,   129,   123,  1384,   125,   122,
     153,   347,   153,   156,   350,   122,   153,   134,  1395,   156,
     154,   232,   156,   234,   763,   122,   765,   111,   112,   113,
     232,  1265,   234,   122,   773,   216,   153,   776,   128,   129,
     156,   780,   674,   675,   118,   667,   668,   241,  1661,  1662,
     242,  1695,  1219,  1220,   241,   132,   676,   677,   156,   920,
     921,  1582,  1583,   140,   141,   153,   143,   314,     0,   190,
      92,   167,   249,    99,   151,    50,   160,  1127,   155,   102,
     157,   200,   821,   101,   193,   162,   154,   145,    29,   156,
     184,   184,  1052,   184,    47,   152,  1740,   118,   246,   284,
    1052,   304,   179,   118,   187,   153,   284,  1473,     1,  1052,
     118,   142,   107,  1052,  1348,   187,   153,   153,   156,  1732,
     184,   860,   156,   156,   156,   142,   203,   204,   205,   206,
     207,   208,   156,   121,    35,    17,   220,   156,  1098,   214,
     156,   153,   156,    29,   187,   231,  1098,     3,   230,   888,
     190,   190,   118,  1113,  1114,  1115,    70,   168,   245,    94,
     170,  1113,  1114,  1115,  1112,   170,   231,  1811,    94,  1813,
    1536,    94,   149,   107,   107,    29,    73,   261,  1822,   918,
     919,   920,   921,   127,  1561,   132,   160,   160,    94,   299,
      87,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,   246,   142,   287,   132,   118,   184,   187,   184,   107,
      94,   295,    45,    96,   111,   187,    96,   187,   957,   303,
     187,   184,   187,   187,   153,   184,   123,    94,   125,   153,
     237,   153,   971,   153,   153,   153,   225,   231,   142,   190,
     233,    33,     1,   170,   118,   132,   142,    94,    29,    94,
     299,  1485,   127,   153,   118,   147,   286,   996,   227,   118,
      94,   198,   254,   184,   132,   160,  1005,   132,  1007,  1229,
    1009,    96,  1011,   100,  1229,   153,   118,  1229,   147,   100,
     153,   184,   184,   190,   142,  1024,  1229,    35,    29,   121,
    1229,   153,   118,   156,  1344,  1345,  1346,   245,   107,   156,
      79,   156,   107,   285,   258,  1265,   267,   156,   260,   144,
     156,    29,   156,  1265,    29,   156,  1276,   156,  1057,   156,
    1059,  1276,    29,   306,  1276,   156,   286,   144,   227,   287,
     190,   147,   127,  1276,   187,  1295,   187,  1276,   118,   187,
    1295,   147,   118,  1295,   187,   147,    77,   107,   142,   187,
     100,   187,  1295,     7,  1093,  1315,  1295,   132,   198,    96,
     184,   190,   233,  1315,   186,   237,   106,   233,   187,   250,
     147,   250,  1315,   282,   286,    78,  1315,   187,  1612,   187,
     187,   233,    29,   233,  1123,    29,   187,  1347,  1348,  1623,
    1624,   187,  1626,   107,   187,  1347,  1348,   187,   170,  1633,
     184,   271,   147,   147,  1347,  1144,   126,   126,    96,   142,
     184,   316,    94,   186,   153,   186,   186,   186,   184,   184,
     184,    29,    96,   170,   187,   187,   287,   257,    53,    94,
     147,   186,   186,   106,    94,    29,   197,   107,   107,   118,
     198,   118,   265,   225,    94,    94,   197,   118,   186,   183,
     186,   348,   280,    93,   351,   197,   186,   225,   186,   118,
     118,   186,   197,   186,   725,   118,  1182,   199,   225,   256,
     256,   259,   958,   287,   420,  1025,  1695,  1226,   293,  1740,
    1714,   861,  1022,   440,   455,   305,   782,   305,  1466,  1255,
    1371,  1725,   305,  1119,   306,   306,  1235,  1369,  1366,  1277,
    1239,  1282,   306,   544,  1290,  1285,   666,   646,  1309,   647,
     700,   822,  1764,  1758,   921,  1254,  1007,   448,  1752,  1181,
    1349,  1340,  1350,   448,  1263,  1485,  1384,  1561,   425,   426,
    1129,  1395,   429,  1485,  1388,   335,   433,  1558,  1277,   436,
     437,  1138,   990,  1204,  1585,  1431,  1385,   444,  1287,    -1,
    1784,    -1,   587,   450,   451,    -1,    -1,    -1,   455,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   463,    -1,    -1,    -1,
      -1,  1805,   469,   470,   471,   472,  1810,  1316,    -1,    -1,
     477,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1340,    -1,  1653,    -1,    -1,    -1,    -1,    -1,    -1,
    1349,    -1,    -1,  1352,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1671,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   530,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   544,    -1,    -1,
      -1,    -1,  1612,    -1,    -1,    -1,    -1,    -1,   555,    -1,
    1612,    -1,    -1,  1623,  1624,    -1,  1626,    -1,  1407,    -1,
      -1,  1623,  1624,  1633,  1626,    -1,    -1,    -1,    -1,    -1,
      -1,  1633,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,   593,    -1,  1437,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1463,  1464,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1489,    -1,  1491,    -1,  1714,  1494,    -1,    -1,    -1,    -1,
      -1,    -1,  1714,    -1,    -1,  1725,    -1,  1506,    -1,    -1,
      -1,    -1,  1511,  1725,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1752,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   719,    -1,  1784,   722,    -1,    -1,    -1,    -1,
      -1,    -1,  1784,    -1,    -1,    -1,    -1,    -1,    -1,   736,
      -1,    -1,    -1,   740,   741,  1805,    -1,    -1,    -1,    -1,
    1810,    -1,    -1,  1805,    -1,    -1,    -1,    -1,  1810,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   763,    -1,   765,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   773,    -1,    -1,   776,
      -1,    -1,    -1,   780,    -1,    -1,    -1,    -1,  1627,    -1,
    1629,    -1,  1631,    -1,    -1,    -1,    -1,    -1,    -1,  1638,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   821,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1673,    -1,  1675,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1691,    -1,    -1,  1694,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   860,    -1,    -1,    -1,  1706,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1716,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   888,    -1,    -1,    -1,    -1,    -1,  1736,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1744,    -1,    -1,    -1,    -1,
    1749,    -1,  1751,    -1,  1753,    -1,    -1,    -1,    -1,    -1,
      -1,   918,   919,   920,   921,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1781,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1797,    -1,
     957,    -1,  1801,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   971,    -1,    -1,    -1,  1817,    -1,
      -1,  1820,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   996,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1005,    -1,
    1007,    -1,  1009,    -1,  1011,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1024,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   556,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1057,    -1,  1059,    -1,   581,   582,    -1,    -1,   585,   586,
     587,   588,    -1,   590,    -1,    -1,    -1,    -1,    -1,   596,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   604,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   626,
     627,   628,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   636,
     637,    -1,    -1,    -1,    -1,    -1,  1123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     697,    -1,    -1,   700,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   738,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1235,    -1,
      -1,    -1,  1239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1254,    -1,    -1,
      -1,    -1,    -1,    -1,   781,    -1,  1263,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1277,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   806,
    1287,    -1,    -1,   810,   811,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   819,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1316,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1340,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1349,    -1,    -1,  1352,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   890,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1407,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1437,    -1,   959,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1463,  1464,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   994,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1489,    -1,  1491,    -1,  1013,  1494,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1506,
      -1,    -1,    -1,    -1,  1511,    -1,    -1,    -1,  1035,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1046,
    1047,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1061,    -1,    -1,  1064,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1080,  1081,  1082,    -1,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,    -1,    -1,  1095,  1096,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1627,    -1,  1629,    -1,  1631,    -1,    -1,    -1,    -1,    -1,
      -1,  1638,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1673,    -1,  1675,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1691,    -1,    -1,  1694,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1706,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1716,
      -1,    -1,    -1,    -1,  1241,    -1,  1243,    -1,  1245,    -1,
      -1,  1248,    -1,    -1,    -1,    -1,  1253,    -1,    -1,  1736,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1744,  1265,    -1,
      -1,    -1,  1749,    -1,  1751,    -1,  1753,  1274,    -1,    -1,
      -1,    -1,    -1,  1280,  1281,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1299,    -1,  1781,  1302,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1797,    -1,    -1,    -1,  1801,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1817,    -1,    -1,  1820,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1450,    -1,    -1,    -1,  1454,    -1,    -1,
      -1,  1458,    -1,  1460,    -1,  1462,    -1,    -1,    -1,    -1,
      -1,  1468,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1476,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1484,  1485,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1503,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1514,  1515,  1516,
    1517,    -1,  1519,  1520,    -1,  1522,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1537,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1600,    -1,  1602,    -1,    -1,  1605,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1613,    -1,    -1,    -1,
      -1,  1618,  1619,    -1,    -1,    -1,    -1,    -1,    -1,  1626,
      -1,    -1,    -1,  1630,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1646,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1658,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1698,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1710,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1752,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1779,    -1,    -1,    -1,    -1,  1784,    -1,    -1,
      -1,    -1,  1789,    -1,    -1,     3,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    11,    12,    -1,    -1,  1804,    -1,    -1,
      -1,  1808,    20,    21,    22,    23,    24,    25,    -1,    -1,
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
     318,   319,   320,     0,     1,    -1,     3,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    50,    51,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    69,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    -1,    94,    95,    96,
      -1,    -1,    99,   100,   101,   102,    -1,    -1,    -1,   106,
     107,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,
     117,   118,    -1,    -1,   121,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,   132,    -1,    -1,    -1,   136,
      -1,    -1,    -1,   140,   141,    -1,   143,    -1,   145,   146,
      -1,    -1,    -1,   150,   151,    -1,    -1,   154,   155,   156,
     157,   158,   159,    -1,    -1,   162,    -1,    -1,    -1,    -1,
     167,   168,    -1,    -1,   171,    -1,    -1,    -1,    -1,   176,
      -1,    -1,   179,    -1,    -1,    -1,    -1,   184,   185,   186,
     187,   188,    -1,   190,   191,   192,   193,   194,    -1,    -1,
      -1,    -1,   199,   200,   201,    -1,   203,   204,   205,   206,
     207,   208,    -1,   210,    -1,   212,    -1,    -1,    -1,    -1,
     217,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,   235,    -1,
     237,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   249,    -1,    -1,    -1,    -1,   254,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,   311,    -1,   313,    33,    34,    -1,
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
     316,   317,   318,   319,   320,   321,   322,    11,    12,    -1,
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
     304,   305,   306,   307,   308,   309,   310,    -1,   312,    -1,
     314,   315,   316,   317,   318,   319,   320,    -1,   322,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
      -1,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
      -1,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,   158,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     182,    -1,    -1,   185,   186,    -1,   188,   189,    -1,   191,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     312,   313,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
      -1,    -1,   144,    -1,   146,   147,   148,   149,   150,   151,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
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
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    98,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,    -1,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,   149,    -1,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,    -1,   200,    -1,
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
     312,    -1,   314,   315,   316,   317,   318,   319,   320,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,   194,    -1,   196,    -1,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,    -1,    -1,   211,
     212,    -1,    -1,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   257,    -1,   259,   260,   261,
      -1,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,    -1,
      11,    12,   314,   315,   316,   317,   318,   319,   320,    20,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    16,   314,   315,   316,   317,   318,   319,   320,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,   187,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    16,
     314,   315,   316,   317,   318,   319,   320,    24,    25,    -1,
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
     307,   308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,    -1,
      -1,    -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,    -1,    -1,   211,   212,    -1,
      -1,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,    -1,   259,   260,   261,    -1,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,    -1,    -1,    -1,
     314,   315,   316,   317,   318,   319,   320,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    -1,
      94,    95,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
     124,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,
      -1,    -1,   196,    -1,   198,   199,   200,   201,   202,   203,
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
     314,   315,   316,   317,   318,   319,   320,    24,    25,    -1,
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
     147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,   156,
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
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,    -1,    -1,    -1,   194,    -1,   196,    -1,   198,
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
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,    -1,
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
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
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
      37,    38,    -1,    40,    41,    42,    43,    -1,    -1,    46,
      47,    -1,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    -1,    60,    -1,    -1,    63,    64,    65,    66,
      67,    -1,    69,    -1,    71,    -1,    -1,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      -1,    -1,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,    -1,   150,   151,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,    -1,   196,
      -1,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,    -1,    -1,    -1,   212,    -1,    -1,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,    -1,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,    -1,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,    -1,   259,   260,   261,    -1,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,    -1,    -1,    -1,   314,   315,   316,
     317,   318,   319,   320
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
     112,   374,   394,   412,   107,   190,     1,   107,   336,   190,
      42,    46,    51,    69,   168,   171,   186,   212,   407,   416,
     421,   422,   423,   437,   438,   442,   167,    92,   132,   140,
     141,   143,   151,   155,   157,   162,   179,   203,   204,   205,
     206,   207,   208,   486,   487,   249,    99,   158,   176,   199,
     117,   146,   159,   194,   201,   210,   136,   150,    50,   200,
     101,   102,   158,   176,   484,   193,   153,   491,   494,   191,
     192,   154,   506,   507,   502,   506,   502,   156,   506,   145,
     156,   184,   184,   184,   375,   509,   375,    29,   651,   182,
     196,   182,   196,   166,   182,   654,   653,   169,   202,    47,
     653,   152,   118,    45,    47,    79,   106,   168,   652,   221,
     222,   223,   246,   610,   653,   653,   304,   137,   142,   112,
     287,   295,   377,   652,   392,   393,   187,   392,    45,    62,
     187,   559,   560,   412,   187,   194,   653,   426,   427,   653,
     284,   284,   426,   118,   433,   118,   187,   381,   382,   153,
     397,   412,     1,   160,   651,   113,   160,   355,   651,   653,
     118,   142,   107,   412,    29,   187,   652,   653,   653,   450,
     451,   653,   392,   187,   412,   412,   561,   653,   392,   153,
     153,   412,   187,   194,   653,   653,   142,   450,   184,   184,
     121,   107,   184,   156,   156,   156,   653,   153,   185,   186,
     187,    35,   522,   523,   524,   412,     8,   175,    17,   412,
     214,    29,   413,   413,    39,    45,    59,    70,    97,   505,
     653,   187,   413,   413,   413,   641,   413,   505,   413,   231,
     230,   577,   578,   653,   190,   190,   413,   412,   393,   412,
     245,   410,   411,   311,   313,   413,   337,   190,   336,   190,
     336,     3,   343,   359,   389,   343,   359,   389,    33,   360,
     389,   360,   389,   400,   400,   413,   413,   413,   118,   168,
     170,   170,   394,   413,   413,   467,   468,   470,   470,   470,
     470,   469,   470,   470,   470,    70,   471,   475,   475,   474,
     476,   476,   476,   476,   477,   477,   478,   478,   231,    94,
      94,    94,   492,   184,   412,   494,   494,   412,   507,   144,
     187,   413,   517,   149,   187,   517,   107,   187,   187,   107,
     107,   380,    29,   654,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,   362,   363,   364,    94,   137,   142,
     368,   369,   370,   653,   160,   160,   362,   651,   127,   132,
      54,    56,   100,   251,   264,   266,   277,   278,   279,   281,
     283,   611,   612,   613,   614,   615,   616,   623,   629,   630,
     246,    94,   299,   653,   142,   413,   118,   653,   653,   132,
     184,   184,   187,   187,   184,   107,   187,   107,   187,   107,
      36,    94,    96,   147,   428,   429,   545,   653,    55,   217,
     254,   418,   419,   653,    94,   107,   187,   391,   187,   652,
      96,    45,   652,   651,    96,   142,   545,   653,   413,   432,
     184,   187,   187,   187,   187,   107,   188,   147,   545,   184,
     187,   187,   153,   184,   392,   392,   184,   107,   187,   107,
     187,   142,   545,   413,   188,   413,   413,   412,   412,   412,
     653,   523,   524,   130,   197,   184,   184,   131,   190,    94,
     218,   219,   233,    94,   218,   219,   233,   233,   233,    94,
      94,   237,   225,   231,   107,   235,   142,   190,   187,    48,
      72,    73,   244,   414,   424,   184,   503,   583,   411,   233,
     359,    33,    33,   190,   336,   190,   113,     1,   653,   170,
     413,   443,   444,   118,   439,   440,   470,   153,   156,   259,
     490,   509,   584,   587,   588,   589,   590,   591,   595,   597,
     599,   600,    47,   152,   156,   211,   317,   318,   319,   320,
     546,   548,   550,   551,   567,   568,   569,   570,   647,   648,
     649,   650,   653,   546,   544,   550,   544,   184,   185,   107,
     187,   187,   509,   148,   165,   148,   165,   137,   397,   380,
     363,   132,   548,   370,   413,   545,   651,   651,   128,   129,
     651,   277,   278,   279,   283,   653,   263,   274,   263,   274,
      29,   286,    96,   113,   156,   617,   620,   611,    39,    44,
      59,    61,    70,    97,   225,   317,   318,   319,   384,   551,
     647,   227,   299,   308,   413,   653,    94,   299,   651,   153,
     561,   562,   653,   561,   562,   118,   427,   127,   546,   118,
     413,   147,   429,   147,    36,   147,   428,   429,   147,   545,
     254,    53,    58,    77,   118,   428,   434,   435,   436,   419,
     545,   546,   382,    94,   184,   198,   132,   354,   651,   160,
     132,    96,   354,   413,   142,   429,   153,   118,   413,   413,
     147,   100,   453,   454,   455,   457,   458,   100,   461,   462,
     463,   464,   392,   184,   184,   153,   561,   561,   413,   142,
     190,   413,   121,   187,   187,   187,    35,   524,   130,   197,
       9,    10,   103,   123,   125,   153,   195,   519,   521,   532,
     533,   536,    29,   232,   234,   413,   413,   413,   232,   234,
     413,   413,   413,   413,   413,   413,   413,   413,   413,   505,
     118,   413,   413,   394,   156,   156,   156,   153,   186,   245,
     580,   581,   210,   395,   413,   190,   113,   389,   389,   389,
     443,    95,   106,   116,   127,   445,   446,   447,   448,   107,
     653,   107,   412,   584,   591,   153,   285,   472,   636,    96,
     169,   252,   253,   255,   262,   272,   284,   585,   586,   605,
     606,   607,   608,   631,   634,   258,   260,   592,   610,   267,
     596,   632,   247,   248,   270,   601,   602,   156,   156,   548,
     156,   156,   156,   156,   156,   144,   176,   194,   547,   144,
     144,   413,   137,   397,   563,   369,   286,    29,    96,   113,
     156,   624,    29,   617,   547,   547,   492,   287,   306,   545,
     384,   227,   190,   391,   187,   187,   144,   187,   187,   427,
     147,   428,   653,   413,   147,   413,   127,   413,   147,   429,
     147,   413,   147,   118,   118,   413,   653,   436,    77,   546,
     394,   413,   651,   107,   354,   413,   142,   391,   451,   413,
     413,   113,   454,   455,   100,   186,   113,   455,   458,   118,
     546,   100,   113,   462,   100,   113,   464,   184,   391,   187,
     187,   413,   413,   198,   461,   132,   195,   521,     7,   392,
     653,   195,   532,   190,   233,   233,   233,   233,    96,   237,
     237,   578,   186,   412,   412,   412,   583,   581,   503,   651,
     128,   129,   447,   448,   448,   444,   106,   142,   441,   545,
     440,   184,   187,   584,   598,   250,   217,   254,   268,   275,
     635,    96,   256,   257,   633,   250,   588,   635,   474,   605,
     589,   147,   282,   593,   594,   633,   286,   604,    78,   603,
     187,   194,   546,   549,   187,   187,   187,   187,   187,   187,
     187,    29,   136,   201,   626,   627,   628,    29,   625,   626,
     271,   621,   107,   618,   170,   653,   257,   492,   184,   413,
     147,   413,   147,   428,   413,   147,   413,   413,   653,   653,
     435,   413,   126,   126,    96,   651,   413,   184,   186,   186,
     413,   394,   413,   186,   186,   653,   186,   118,   546,   118,
     186,   118,   546,   186,   184,   113,   524,   653,   195,   184,
     524,   653,   413,   413,   413,   413,   316,   413,   413,   413,
     187,   187,   187,   153,   582,   448,   651,   413,   142,   184,
     476,    52,   129,   474,   474,   269,   276,   286,   609,   609,
     590,   153,   280,    94,   187,   107,   187,   624,   624,   628,
     107,   187,    29,   622,   633,   619,   620,   187,   386,   387,
     492,   118,   225,   307,   287,   170,   413,   413,   147,   413,
      53,   394,   413,   354,   413,   394,    94,   394,   413,   653,
     186,   653,   413,   653,   186,   394,   118,    93,   183,   525,
     524,   653,   197,   524,   413,   198,   461,   412,   441,   413,
     474,   474,   199,   412,   546,   546,    94,    29,   265,   107,
     107,   448,   545,   653,   118,   225,   653,   386,   413,   118,
     546,    94,   186,    94,   653,     5,   133,   528,   529,   531,
     533,    28,   134,   526,   527,   530,   533,   197,   524,   197,
     113,   184,   441,   474,   184,   546,   620,   387,   448,   305,
     653,   118,   225,   653,   186,   546,   394,   413,   546,   186,
      93,   133,   531,   183,   134,   530,   197,   118,   413,   305,
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
     412,   412,   413,   413,   413,   413,   413,   413,   414,   414,
     414,   414,   414,   414,   414,   414,   414,   414,   414,   414,
     415,   416,   417,   417,   418,   418,   418,   419,   419,   420,
     420,   421,   422,   422,   422,   423,   423,   423,   423,   423,
     424,   424,   425,   425,   425,   426,   426,   426,   427,   427,
     427,   427,   427,   427,   427,   427,   427,   427,   427,   427,
     428,   429,   430,   431,   431,   432,   432,   432,   432,   433,
     433,   434,   434,   434,   435,   435,   435,   436,   436,   436,
     437,   438,   439,   439,   440,   440,   440,   440,   440,   440,
     441,   442,   442,   443,   443,   444,   444,   445,   445,   445,
     445,   445,   445,   445,   446,   446,   447,   447,   448,   449,
     449,   450,   450,   451,   451,   452,   453,   453,   454,   455,
     455,   456,   457,   457,   458,   459,   459,   460,   460,   461,
     461,   462,   462,   463,   463,   464,   464,   465,   466,   466,
     467,   467,   468,   468,   468,   468,   468,   469,   468,   468,
     468,   468,   470,   470,   471,   471,   472,   472,   473,   473,
     474,   474,   474,   475,   475,   475,   475,   475,   476,   476,
     476,   477,   477,   477,   478,   478,   479,   479,   480,   480,
     481,   481,   482,   482,   483,   483,   483,   483,   484,   484,
     484,   485,   485,   486,   486,   486,   486,   486,   486,   487,
     487,   487,   488,   488,   488,   488,   489,   489,   490,   490,
     491,   491,   491,   492,   492,   492,   492,   493,   494,   494,
     494,   495,   495,   496,   496,   496,   496,   497,   497,   498,
     498,   498,   498,   498,   498,   498,   499,   499,   500,   500,
     501,   501,   501,   501,   501,   502,   502,   503,   503,   504,
     504,   504,   504,   505,   505,   505,   505,   506,   506,   507,
     508,   508,   508,   508,   508,   508,   508,   508,   508,   508,
     508,   508,   508,   508,   509,   509,   510,   510,   510,   511,
     512,   512,   513,   514,   515,   516,   516,   517,   517,   517,
     517,   518,   518,   519,   519,   519,   520,   520,   520,   520,
     520,   520,   521,   521,   522,   522,   523,   524,   524,   525,
     525,   526,   526,   527,   527,   527,   527,   528,   528,   529,
     529,   529,   529,   530,   530,   531,   531,   532,   532,   532,
     532,   533,   533,   533,   533,   534,   534,   535,   535,   536,
     537,   537,   537,   537,   537,   537,   538,   539,   539,   540,
     540,   541,   542,   543,   543,   544,   544,   545,   546,   546,
     546,   547,   547,   547,   548,   548,   548,   548,   548,   548,
     548,   549,   549,   550,   551,   551,   551,   551,   551,   551,
     551,   551,   551,   552,   553,   553,   553,   554,   555,   556,
     556,   556,   557,   557,   557,   557,   557,   558,   559,   559,
     559,   559,   559,   559,   559,   560,   561,   562,   563,   564,
     564,   565,   566,   567,   567,   568,   569,   569,   570,   571,
     571,   571,   572,   572,   572,   572,   572,   572,   572,   572,
     572,   572,   573,   573,   574,   574,   575,   576,   577,   577,
     578,   579,   580,   580,   581,   582,   583,   583,   584,   585,
     585,   586,   586,   587,   587,   588,   588,   589,   589,   590,
     590,   591,   592,   592,   593,   593,   594,   595,   595,   595,
     596,   596,   597,   598,   598,   599,   600,   600,   601,   601,
     602,   602,   602,   603,   603,   604,   604,   605,   605,   605,
     605,   605,   606,   607,   608,   609,   609,   609,   610,   610,
     611,   611,   611,   611,   611,   611,   611,   611,   612,   612,
     612,   612,   613,   613,   614,   615,   615,   616,   616,   616,
     617,   617,   618,   618,   619,   619,   620,   621,   621,   622,
     622,   623,   623,   623,   624,   624,   625,   625,   626,   626,
     627,   627,   628,   628,   629,   630,   630,   631,   631,   631,
     632,   633,   633,   633,   633,   634,   634,   635,   635,   636,
     637,   637,   638,   638,   639,   639,   640,   641,   641,   642,
     642,   642,   643,   644,   645,   646,   647,   647,   647,   648,
     649,   650,   651,   652,   652,   653,   653,   653,   653,   653,
     653,   653,   653,   653,   653,   653,   653,   653,   653,   653,
     653,   654,   654,   654,   654,   654,   654,   654,   654,   654,
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
     654,   654,   654,   654,   654,   654,   654,   655
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
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     2,     1,     1,     2,     4,     3,     5,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     3,     2,     1,     4,     3,     3,     5,
       4,     6,     4,     6,     5,     7,     4,     5,     5,     6,
       3,     3,     2,     1,     3,     4,     5,     3,     6,     4,
       5,     1,     2,     3,     1,     2,     1,     6,     3,     3,
       2,     3,     1,     3,     2,     4,     5,     6,     5,     3,
       2,     3,     4,     1,     3,     1,     2,     1,     1,     1,
       2,     2,     2,     3,     1,     1,     2,     2,     2,     5,
       5,     1,     4,     3,     4,     8,     1,     2,     3,     2,
       3,     8,     1,     2,     3,     8,    10,     8,    10,     1,
       2,     4,     7,     1,     2,     4,     7,     8,     1,     3,
       1,     3,     1,     3,     3,     3,     3,     0,     4,     3,
       3,     3,     1,     5,     1,     3,     0,     1,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     4,     1,     4,     1,     4,
       1,     4,     1,     2,     1,     1,     2,     2,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     5,     6,     3,     4,     1,     2,
       3,     2,     2,     1,     2,     2,     1,     1,     1,     3,
       3,     1,     1,     1,     2,     1,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     2,     1,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     4,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     1,     4,     4,     3,     4,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     4,     5,     8,     9,
       9,    10,     1,     2,     1,     2,     6,     0,     1,     3,
       3,     0,     1,     1,     1,     2,     2,     0,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     4,     3,     7,     3,
       7,     4,     4,     3,     7,     1,     2,     2,     1,     2,
       3,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     4,     4,     3,     3,     3,
       4,     4,     3,     4,     6,     4,     6,     4,     3,     4,
       6,     6,     4,     6,     6,     4,     1,     2,     1,     1,
       1,     3,     3,     1,     1,     4,     5,     6,     3,     3,
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
       1,     1,     1,     1,     1,     1,     1,     1
  };


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
  "EQNAME", YY_NULL
  };

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
     583,   395,    -1,   413,    -1,   412,   107,   413,    -1,   412,
       1,   413,     1,    -1,   412,   336,   413,    -1,   415,    -1,
     452,    -1,   459,    -1,   465,    -1,   579,    -1,   414,    -1,
     466,    -1,   449,    -1,   572,    -1,   573,    -1,   575,    -1,
     574,    -1,   576,    -1,   644,    -1,   642,    -1,   645,    -1,
     646,    -1,   643,    -1,   424,   416,    -1,   186,   413,    -1,
      66,   284,    -1,    71,   284,    -1,   217,    -1,   254,    -1,
      55,   254,    -1,   418,   434,    77,   413,    -1,   418,    77,
     413,    -1,    46,   417,   433,   419,   419,    -1,    46,   417,
     433,   419,    -1,    42,   118,   653,    -1,   425,    -1,   430,
      -1,   420,    -1,   422,    -1,   437,    -1,   442,    -1,   438,
      -1,   421,    -1,   422,    -1,   424,   423,    -1,    46,   118,
     426,    -1,    46,     1,   426,    -1,    46,     3,    -1,   427,
      -1,   426,   107,   118,   427,    -1,   426,   107,   427,    -1,
     653,   147,   413,    -1,   653,    36,   127,   147,   413,    -1,
     653,   545,   147,   413,    -1,   653,   545,    36,   127,   147,
     413,    -1,   653,   428,   147,   413,    -1,   653,    36,   127,
     428,   147,   413,    -1,   653,   545,   428,   147,   413,    -1,
     653,   545,    36,   127,   428,   147,   413,    -1,   653,   429,
     147,   413,    -1,   653,   545,   429,   147,   413,    -1,   653,
     428,   429,   147,   413,    -1,   653,   545,   428,   429,   147,
     413,    -1,    96,   118,   653,    -1,   273,   118,   653,    -1,
      51,   431,    -1,   432,    -1,   431,   107,   432,    -1,   118,
     653,   142,   413,    -1,   118,   653,   545,   142,   413,    -1,
     429,   142,   413,    -1,   118,   653,   545,   429,   142,   413,
      -1,   118,   653,   147,   413,    -1,   118,   653,   545,   147,
     413,    -1,   435,    -1,   118,   653,    -1,   118,   653,   435,
      -1,   428,    -1,   428,   436,    -1,   436,    -1,    58,   118,
     653,    53,   118,   653,    -1,    53,   118,   653,    -1,    58,
     118,   653,    -1,   212,   413,    -1,   171,   170,   439,    -1,
     440,    -1,   439,   107,   440,    -1,   118,   653,    -1,   118,
     653,   142,   413,    -1,   118,   653,   545,   142,   413,    -1,
     118,   653,   545,   142,   413,   441,    -1,   118,   653,   142,
     413,   441,    -1,   118,   653,   441,    -1,   106,   651,    -1,
     168,   170,   443,    -1,    69,   168,   170,   443,    -1,   444,
      -1,   443,   107,   444,    -1,   413,    -1,   413,   445,    -1,
     446,    -1,   447,    -1,   448,    -1,   446,   447,    -1,   446,
     448,    -1,   447,   448,    -1,   446,   447,   448,    -1,    95,
      -1,   116,    -1,   127,   128,    -1,   127,   129,    -1,   106,
     651,    -1,    67,   118,   450,   188,   413,    -1,   135,   118,
     450,   188,   413,    -1,   451,    -1,   450,   107,   118,   451,
      -1,   653,   147,   413,    -1,   653,   545,   147,   413,    -1,
      72,   156,   412,   187,   453,   113,   186,   413,    -1,   454,
      -1,   453,   454,    -1,   455,   186,   413,    -1,   100,   413,
      -1,   455,   100,   413,    -1,    72,   156,   412,   187,   457,
     113,   186,   394,    -1,   458,    -1,   457,   458,    -1,   455,
     186,   394,    -1,    73,   156,   412,   187,   461,   113,   186,
     413,    -1,    73,   156,   412,   187,   461,   113,   118,   653,
     186,   413,    -1,    73,   156,   412,   187,   463,   113,   186,
     394,    -1,    73,   156,   412,   187,   461,   113,   118,   653,
     186,   394,    -1,   462,    -1,   461,   462,    -1,   100,   546,
     186,   413,    -1,   100,   118,   653,    94,   546,   186,   413,
      -1,   464,    -1,   463,   464,    -1,   100,   546,   186,   394,
      -1,   100,   118,   653,    94,   546,   186,   394,    -1,    48,
     156,   412,   187,   198,   413,   126,   413,    -1,   467,    -1,
     466,   167,   467,    -1,   468,    -1,   467,    92,   468,    -1,
     470,    -1,   470,   486,   470,    -1,   470,   487,   470,    -1,
     470,   132,   470,    -1,   470,   162,   470,    -1,    -1,   470,
     157,   469,   470,    -1,   470,   155,   470,    -1,   470,   143,
     470,    -1,   470,   141,   470,    -1,   471,    -1,   471,   249,
      70,   584,   472,    -1,   473,    -1,   473,    99,   471,    -1,
      -1,   636,    -1,   474,    -1,   474,   199,   474,    -1,   475,
      -1,   474,   176,   475,    -1,   474,   158,   475,    -1,   476,
      -1,   475,   194,   476,    -1,   475,   117,   476,    -1,   475,
     146,   476,    -1,   475,   159,   476,    -1,   477,    -1,   476,
     201,   477,    -1,   476,   210,   477,    -1,   478,    -1,   477,
     150,   478,    -1,   477,   136,   478,    -1,   479,    -1,   479,
      50,   231,   546,    -1,   480,    -1,   480,   200,    94,   546,
      -1,   481,    -1,   481,   101,    94,   544,    -1,   482,    -1,
     482,   102,    94,   544,    -1,   484,    -1,   483,   484,    -1,
     176,    -1,   158,    -1,   483,   176,    -1,   483,   158,    -1,
     488,    -1,   485,    -1,   489,    -1,   492,    -1,   485,   193,
     492,    -1,   203,    -1,   208,    -1,   207,    -1,   206,    -1,
     205,    -1,   204,    -1,   151,    -1,   179,    -1,   140,    -1,
      75,   153,   392,   184,    -1,    75,   222,   153,   392,   184,
      -1,    75,   221,   153,   392,   184,    -1,    75,    76,   561,
     153,   392,   184,    -1,   490,   153,   184,    -1,   490,   153,
     412,   184,    -1,   491,    -1,   490,   491,    -1,   177,   653,
      17,    -1,   177,    18,    -1,   177,    19,    -1,   493,    -1,
     493,   494,    -1,   192,   494,    -1,   494,    -1,   191,    -1,
     495,    -1,   495,   191,   494,    -1,   495,   192,   494,    -1,
     496,    -1,   505,    -1,   497,    -1,   497,   506,    -1,   500,
      -1,   500,   506,    -1,   498,   502,    -1,   499,    -1,   105,
     122,    -1,   114,   122,    -1,    97,   122,    -1,   189,   122,
      -1,   115,   122,    -1,   139,   122,    -1,   138,   122,    -1,
     502,    -1,    98,   502,    -1,   501,   502,    -1,   120,    -1,
     172,   122,    -1,    90,   122,    -1,   181,   122,    -1,   180,
     122,    -1,    91,   122,    -1,   551,    -1,   503,    -1,   653,
      -1,   504,    -1,   194,    -1,    11,    -1,    12,    -1,    20,
      -1,   508,    -1,   505,   506,    -1,   505,   156,   187,    -1,
     505,   156,   517,   187,    -1,   507,    -1,   506,   507,    -1,
     154,   412,   185,    -1,   509,    -1,   511,    -1,   512,    -1,
     513,    -1,   516,    -1,   518,    -1,   514,    -1,   515,    -1,
     564,    -1,   396,    -1,   640,    -1,   637,    -1,   638,    -1,
     639,    -1,   510,    -1,   563,    -1,   110,    -1,   149,    -1,
     124,    -1,   118,   653,    -1,   156,   187,    -1,   156,   412,
     187,    -1,   119,    -1,   169,   153,   412,   184,    -1,   202,
     153,   412,   184,    -1,   654,   156,   187,    -1,   654,   156,
     517,   187,    -1,   144,    -1,   517,   107,   144,    -1,   413,
      -1,   517,   107,   413,    -1,   519,    -1,   537,    -1,   520,
      -1,   534,    -1,   535,    -1,   157,   653,   524,   130,    -1,
     157,   653,   522,   524,   130,    -1,   157,   653,   524,   197,
     195,   653,   524,   197,    -1,   157,   653,   524,   197,   521,
     195,   653,   524,   197,    -1,   157,   653,   522,   524,   197,
     195,   653,   524,   197,    -1,   157,   653,   522,   524,   197,
     521,   195,   653,   524,   197,    -1,   532,    -1,   521,   532,
      -1,   523,    -1,   522,   523,    -1,    35,   653,   524,   132,
     524,   525,    -1,    -1,    35,    -1,   183,   526,   183,    -1,
      93,   528,    93,    -1,    -1,   527,    -1,   134,    -1,   530,
      -1,   527,   134,    -1,   527,   530,    -1,    -1,   529,    -1,
     133,    -1,   531,    -1,   529,   133,    -1,   529,   531,    -1,
      28,    -1,   533,    -1,     5,    -1,   533,    -1,   519,    -1,
      10,    -1,   536,    -1,   533,    -1,     9,    -1,   123,    -1,
     125,    -1,   153,   392,   184,    -1,   213,    30,   214,    -1,
     213,   214,    -1,   174,   652,   175,    -1,   174,   652,     8,
      -1,   103,     7,    -1,   538,    -1,   539,    -1,   540,    -1,
     541,    -1,   542,    -1,   543,    -1,    43,   153,   392,   184,
      -1,    21,   391,   184,    -1,    45,   153,   412,   184,   153,
     391,   184,    -1,    22,   391,   184,    -1,    97,   153,   412,
     184,   153,   391,   184,    -1,    70,   153,   392,   184,    -1,
      39,   153,   392,   184,    -1,    23,   391,   184,    -1,    59,
     153,   412,   184,   153,   391,   184,    -1,   550,    -1,   550,
     144,    -1,    94,   546,    -1,   548,    -1,   548,   547,    -1,
     211,   156,   187,    -1,   144,    -1,   194,    -1,   176,    -1,
     550,    -1,   551,    -1,   152,   156,   187,    -1,   320,   156,
     187,    -1,   567,    -1,   570,    -1,   647,    -1,   546,    -1,
     549,   107,   546,    -1,   653,    -1,   553,    -1,   559,    -1,
     557,    -1,   560,    -1,   558,    -1,   556,    -1,   555,    -1,
     554,    -1,   552,    -1,   225,   156,   187,    -1,    44,   156,
     187,    -1,    44,   156,   559,   187,    -1,    44,   156,   560,
     187,    -1,    70,   156,   187,    -1,    39,   156,   187,    -1,
      59,   156,   187,    -1,    59,   156,   652,   187,    -1,    59,
     156,    29,   187,    -1,    97,   156,   187,    -1,    97,   156,
     653,   187,    -1,    97,   156,   653,   107,   561,   187,    -1,
      97,   156,   194,   187,    -1,    97,   156,   194,   107,   561,
     187,    -1,    61,   156,   653,   187,    -1,    45,   156,   187,
      -1,    45,   156,   653,   187,    -1,    45,   156,   653,   107,
     561,   187,    -1,    45,   156,   653,   107,   562,   187,    -1,
      45,   156,   194,   187,    -1,    45,   156,   194,   107,   561,
     187,    -1,    45,   156,   194,   107,   562,   187,    -1,    62,
     156,   653,   187,    -1,   653,    -1,   653,   144,    -1,    29,
      -1,   565,    -1,   566,    -1,   653,   145,   149,    -1,    47,
     380,   397,    -1,   568,    -1,   569,    -1,    47,   156,   194,
     187,    -1,    47,   156,   187,    94,   546,    -1,    47,   156,
     549,   187,    94,   546,    -1,   156,   548,   187,    -1,    33,
     220,   221,    -1,    33,   220,   222,    -1,    33,   220,   223,
      -1,   226,   225,   413,   233,   413,    -1,   226,   225,   413,
      94,   232,   233,   413,    -1,   226,   225,   413,    94,   234,
     233,   413,    -1,   226,   225,   413,   218,   413,    -1,   226,
     225,   413,   219,   413,    -1,   226,   227,   413,   233,   413,
      -1,   226,   227,   413,    94,   232,   233,   413,    -1,   226,
     227,   413,    94,   234,   233,   413,    -1,   226,   227,   413,
     218,   413,    -1,   226,   227,   413,   219,   413,    -1,   224,
     225,   413,    -1,   224,   227,   413,    -1,   229,   225,   413,
     237,   413,    -1,   229,   230,   231,   225,   413,   237,   413,
      -1,   228,   225,   413,    94,   413,    -1,   236,   118,   577,
     235,   413,   186,   413,    -1,   578,    -1,   577,   107,   118,
     578,    -1,   653,   142,   413,    -1,   244,   153,   412,   184,
     580,    -1,   581,    -1,   580,   581,    -1,   245,   583,   582,
      -1,   153,   412,   184,    -1,   503,    -1,   583,   210,   503,
      -1,   587,   585,    -1,    -1,   586,    -1,   605,    -1,   586,
     605,    -1,   588,    -1,   587,   262,   588,    -1,   589,    -1,
     588,   258,   589,    -1,   590,    -1,   589,   260,   147,   590,
      -1,   591,    -1,   259,   591,    -1,   595,   592,   593,    -1,
      -1,   610,    -1,    -1,   594,    -1,   282,   153,   412,   184,
      -1,   599,   596,    -1,   156,   584,   187,    -1,   597,    -1,
      -1,   632,    -1,   490,   153,   598,   184,    -1,    -1,   584,
      -1,   600,   601,    -1,   509,    -1,   153,   412,   184,    -1,
      -1,   602,    -1,   248,   603,    -1,   247,   604,    -1,   270,
      -1,    -1,    78,    -1,    -1,   286,    -1,   606,    -1,   607,
      -1,   608,    -1,   634,    -1,   631,    -1,   169,    -1,   284,
     474,   609,    -1,   253,   633,   609,    -1,   286,    -1,   276,
      -1,   269,    -1,   246,   611,    -1,   610,   246,   611,    -1,
     612,    -1,   613,    -1,   614,    -1,   629,    -1,   615,    -1,
     623,    -1,   616,    -1,   630,    -1,   100,   274,    -1,   100,
     263,    -1,   266,    -1,   281,    -1,   251,   274,    -1,   251,
     263,    -1,    56,   653,    29,    -1,   277,    -1,    54,   277,
      -1,   279,   617,    -1,   279,   156,   617,   618,   187,    -1,
      54,   279,    -1,   620,    -1,   113,    -1,    -1,   107,   619,
      -1,   620,    -1,   619,   107,   620,    -1,    96,    29,   621,
     622,    -1,    -1,   271,    29,    -1,    -1,   633,   265,    -1,
     278,   286,   624,   626,    -1,   278,   286,   113,   626,    -1,
      54,   278,   286,    -1,    96,    29,    -1,   156,   625,   187,
      -1,    29,    -1,   625,   107,    29,    -1,    -1,   627,    -1,
     628,    -1,   627,   628,    -1,   201,   624,    -1,   136,   624,
      -1,   264,    29,    -1,   283,    -1,    54,   283,    -1,    96,
     217,    -1,    96,   254,    -1,   255,   250,    -1,   267,   633,
     280,    -1,   256,   474,    -1,    96,   129,   474,    -1,    96,
      52,   474,    -1,   257,   474,   199,   474,    -1,   272,   635,
      -1,   252,   635,    -1,   275,    -1,   268,    -1,   285,   250,
     476,    -1,   154,   185,    -1,   154,   412,   185,    -1,   310,
     311,    -1,   310,   412,   311,    -1,   312,   313,    -1,   312,
     412,   313,    -1,   153,   641,   184,    -1,   413,   121,   413,
      -1,   641,   107,   413,   121,   413,    -1,   226,   314,   413,
     233,   413,    -1,   226,   314,   641,   233,   413,    -1,   226,
     314,   413,   233,   413,    96,   316,   413,    -1,   315,   314,
     413,   233,   413,    -1,   224,   314,   505,    -1,   228,   314,
     505,    94,   413,    -1,   229,   314,   230,   231,   505,   237,
     413,    -1,   648,    -1,   649,    -1,   650,    -1,   319,   156,
     187,    -1,   317,   156,   187,    -1,   318,   156,   187,    -1,
      29,    -1,    16,    -1,   653,    -1,   654,    -1,    97,    -1,
      39,    -1,    44,    -1,    45,    -1,   152,    -1,    48,    -1,
     225,    -1,    59,    -1,    61,    -1,    62,    -1,    70,    -1,
      73,    -1,    72,    -1,   211,    -1,   243,    -1,   655,    -1,
      24,    -1,   215,    -1,   127,    -1,    38,    -1,   261,    -1,
      37,    -1,   222,    -1,   221,    -1,   146,    -1,    43,    -1,
     259,    -1,   260,    -1,   274,    -1,   263,    -1,   251,    -1,
     285,    -1,   277,    -1,   279,    -1,   278,    -1,   283,    -1,
     255,    -1,   250,    -1,    78,    -1,   217,    -1,   254,    -1,
      52,    -1,   223,    -1,   236,    -1,   302,    -1,   230,    -1,
     203,    -1,   208,    -1,   207,    -1,   206,    -1,   205,    -1,
     204,    -1,    96,    -1,   111,    -1,   112,    -1,   186,    -1,
      46,    -1,    36,    -1,    66,    -1,    71,    -1,    58,    -1,
      53,    -1,    55,    -1,    77,    -1,    42,    -1,   147,    -1,
      51,    -1,   212,    -1,   170,    -1,   171,    -1,   168,    -1,
      69,    -1,    95,    -1,   116,    -1,   128,    -1,   129,    -1,
     106,    -1,    67,    -1,   135,    -1,   188,    -1,   100,    -1,
      94,    -1,   198,    -1,   126,    -1,   167,    -1,    92,    -1,
      50,    -1,   231,    -1,   101,    -1,   199,    -1,   117,    -1,
     159,    -1,   201,    -1,   150,    -1,   136,    -1,    75,    -1,
      76,    -1,   102,    -1,   200,    -1,   151,    -1,   182,    -1,
     196,    -1,   160,    -1,   137,    -1,   131,    -1,   166,    -1,
     148,    -1,   165,    -1,    33,    -1,    40,    -1,    57,    -1,
     113,    -1,    41,    -1,    56,    -1,   216,    -1,    49,    -1,
      60,    -1,    34,    -1,    47,    -1,   273,    -1,   249,    -1,
     282,    -1,   284,    -1,   253,    -1,   267,    -1,   280,    -1,
     272,    -1,   252,    -1,   266,    -1,   281,    -1,   271,    -1,
     265,    -1,   264,    -1,   248,    -1,   247,    -1,   256,    -1,
     257,    -1,   286,    -1,   276,    -1,   275,    -1,   270,    -1,
     268,    -1,   269,    -1,   229,    -1,   235,    -1,   232,    -1,
     226,    -1,   219,    -1,   218,    -1,   220,    -1,   237,    -1,
     227,    -1,   228,    -1,   234,    -1,   224,    -1,   233,    -1,
      65,    -1,    63,    -1,    74,    -1,   169,    -1,   202,    -1,
     242,    -1,   240,    -1,   241,    -1,   238,    -1,   239,    -1,
     244,    -1,   245,    -1,   246,    -1,    64,    -1,   295,    -1,
     293,    -1,   294,    -1,   299,    -1,   300,    -1,   301,    -1,
     296,    -1,   297,    -1,   298,    -1,    79,    -1,    80,    -1,
      81,    -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,
      86,    -1,    87,    -1,    88,    -1,    89,    -1,   287,    -1,
     288,    -1,   289,    -1,   290,    -1,   291,    -1,   292,    -1,
     303,    -1,   304,    -1,   305,    -1,   306,    -1,   307,    -1,
     308,    -1,   309,    -1,    90,    -1,   105,    -1,   114,    -1,
     172,    -1,   180,    -1,   189,    -1,   138,    -1,    91,    -1,
     115,    -1,   139,    -1,   181,    -1,   314,    -1,   315,    -1,
     316,    -1,   319,    -1,   318,    -1,   317,    -1,   320,    -1,
      25,    -1
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
     799,   804,   808,   810,   812,   814,   816,   818,   820,   822,
     824,   826,   828,   830,   832,   834,   836,   838,   840,   842,
     844,   847,   850,   853,   856,   858,   860,   863,   868,   872,
     878,   883,   887,   889,   891,   893,   895,   897,   899,   901,
     903,   905,   908,   912,   916,   919,   921,   926,   930,   934,
     940,   945,   952,   957,   964,   970,   978,   983,   989,   995,
    1002,  1006,  1010,  1013,  1015,  1019,  1024,  1030,  1034,  1041,
    1046,  1052,  1054,  1057,  1061,  1063,  1066,  1068,  1075,  1079,
    1083,  1086,  1090,  1092,  1096,  1099,  1104,  1110,  1117,  1123,
    1127,  1130,  1134,  1139,  1141,  1145,  1147,  1150,  1152,  1154,
    1156,  1159,  1162,  1165,  1169,  1171,  1173,  1176,  1179,  1182,
    1188,  1194,  1196,  1201,  1205,  1210,  1219,  1221,  1224,  1228,
    1231,  1235,  1244,  1246,  1249,  1253,  1262,  1273,  1282,  1293,
    1295,  1298,  1303,  1311,  1313,  1316,  1321,  1329,  1338,  1340,
    1344,  1346,  1350,  1352,  1356,  1360,  1364,  1368,  1369,  1374,
    1378,  1382,  1386,  1388,  1394,  1396,  1400,  1401,  1403,  1405,
    1409,  1411,  1415,  1419,  1421,  1425,  1429,  1433,  1437,  1439,
    1443,  1447,  1449,  1453,  1457,  1459,  1464,  1466,  1471,  1473,
    1478,  1480,  1485,  1487,  1490,  1492,  1494,  1497,  1500,  1502,
    1504,  1506,  1508,  1512,  1514,  1516,  1518,  1520,  1522,  1524,
    1526,  1528,  1530,  1535,  1541,  1547,  1554,  1558,  1563,  1565,
    1568,  1572,  1575,  1578,  1580,  1583,  1586,  1588,  1590,  1592,
    1596,  1600,  1602,  1604,  1606,  1609,  1611,  1614,  1617,  1619,
    1622,  1625,  1628,  1631,  1634,  1637,  1640,  1642,  1645,  1648,
    1650,  1653,  1656,  1659,  1662,  1665,  1667,  1669,  1671,  1673,
    1675,  1677,  1679,  1681,  1683,  1686,  1690,  1695,  1697,  1700,
    1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1720,  1722,
    1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,
    1745,  1748,  1752,  1754,  1759,  1764,  1768,  1773,  1775,  1779,
    1781,  1785,  1787,  1789,  1791,  1793,  1795,  1800,  1806,  1815,
    1825,  1835,  1846,  1848,  1851,  1853,  1856,  1863,  1864,  1866,
    1870,  1874,  1875,  1877,  1879,  1881,  1884,  1887,  1888,  1890,
    1892,  1894,  1897,  1900,  1902,  1904,  1906,  1908,  1910,  1912,
    1914,  1916,  1918,  1920,  1922,  1926,  1930,  1933,  1937,  1941,
    1944,  1946,  1948,  1950,  1952,  1954,  1956,  1961,  1965,  1973,
    1977,  1985,  1990,  1995,  1999,  2007,  2009,  2012,  2015,  2017,
    2020,  2024,  2026,  2028,  2030,  2032,  2034,  2038,  2042,  2044,
    2046,  2048,  2050,  2054,  2056,  2058,  2060,  2062,  2064,  2066,
    2068,  2070,  2072,  2074,  2078,  2082,  2087,  2092,  2096,  2100,
    2104,  2109,  2114,  2118,  2123,  2130,  2135,  2142,  2147,  2151,
    2156,  2163,  2170,  2175,  2182,  2189,  2194,  2196,  2199,  2201,
    2203,  2205,  2209,  2213,  2215,  2217,  2222,  2228,  2235,  2239,
    2243,  2247,  2251,  2257,  2265,  2273,  2279,  2285,  2291,  2299,
    2307,  2313,  2319,  2323,  2327,  2333,  2341,  2347,  2355,  2357,
    2362,  2366,  2372,  2374,  2377,  2381,  2385,  2387,  2391,  2394,
    2395,  2397,  2399,  2402,  2404,  2408,  2410,  2414,  2416,  2421,
    2423,  2426,  2430,  2431,  2433,  2434,  2436,  2441,  2444,  2448,
    2450,  2451,  2453,  2458,  2459,  2461,  2464,  2466,  2470,  2471,
    2473,  2476,  2479,  2481,  2482,  2484,  2485,  2487,  2489,  2491,
    2493,  2495,  2497,  2499,  2503,  2507,  2509,  2511,  2513,  2516,
    2520,  2522,  2524,  2526,  2528,  2530,  2532,  2534,  2536,  2539,
    2542,  2544,  2546,  2549,  2552,  2556,  2558,  2561,  2564,  2570,
    2573,  2575,  2577,  2578,  2581,  2583,  2587,  2592,  2593,  2596,
    2597,  2600,  2605,  2610,  2614,  2617,  2621,  2623,  2627,  2628,
    2630,  2632,  2635,  2638,  2641,  2644,  2646,  2649,  2652,  2655,
    2658,  2662,  2665,  2669,  2673,  2678,  2681,  2684,  2686,  2688,
    2692,  2695,  2699,  2702,  2706,  2709,  2713,  2717,  2721,  2727,
    2733,  2739,  2748,  2754,  2758,  2764,  2772,  2774,  2776,  2778,
    2782,  2786,  2790,  2792,  2794,  2796,  2798,  2800,  2802,  2804,
    2806,  2808,  2810,  2812,  2814,  2816,  2818,  2820,  2822,  2824,
    2826,  2828,  2830,  2832,  2834,  2836,  2838,  2840,  2842,  2844,
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
    3226,  3228,  3230,  3232,  3234,  3236,  3238,  3240
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1049,  1049,  1050,  1054,  1058,  1069,  1078,  1084,  1092,
    1098,  1109,  1114,  1122,  1129,  1136,  1145,  1152,  1160,  1168,
    1176,  1187,  1192,  1199,  1206,  1218,  1228,  1235,  1242,  1254,
    1255,  1256,  1257,  1258,  1263,  1264,  1265,  1266,  1267,  1268,
    1269,  1272,  1277,  1282,  1290,  1298,  1306,  1311,  1319,  1324,
    1332,  1337,  1345,  1350,  1355,  1360,  1368,  1370,  1373,  1383,
    1388,  1396,  1404,  1415,  1422,  1433,  1438,  1446,  1453,  1460,
    1469,  1482,  1490,  1497,  1507,  1514,  1521,  1532,  1533,  1534,
    1535,  1536,  1537,  1538,  1539,  1544,  1550,  1559,  1566,  1576,
    1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,  1595,
    1600,  1608,  1616,  1624,  1631,  1639,  1646,  1651,  1659,  1667,
    1681,  1695,  1712,  1717,  1725,  1733,  1744,  1749,  1758,  1763,
    1770,  1775,  1785,  1790,  1799,  1805,  1818,  1823,  1831,  1842,
    1857,  1869,  1884,  1889,  1894,  1899,  1907,  1914,  1925,  1930,
    1940,  1949,  1958,  1967,  1979,  1983,  1989,  1993,  2003,  2013,
    2026,  2032,  2041,  2046,  2053,  2060,  2071,  2081,  2091,  2101,
    2119,  2139,  2143,  2148,  2155,  2159,  2164,  2171,  2176,  2188,
    2195,  2207,  2208,  2209,  2210,  2211,  2212,  2213,  2215,  2216,
    2217,  2218,  2219,  2224,  2229,  2237,  2254,  2262,  2270,  2277,
    2284,  2295,  2304,  2313,  2322,  2335,  2343,  2351,  2359,  2374,
    2379,  2387,  2401,  2418,  2443,  2451,  2458,  2469,  2479,  2484,
    2496,  2505,  2518,  2519,  2520,  2521,  2522,  2523,  2528,  2529,
    2532,  2533,  2534,  2535,  2536,  2539,  2540,  2541,  2542,  2543,
    2548,  2562,  2570,  2575,  2583,  2588,  2593,  2601,  2610,  2622,
    2632,  2645,  2653,  2654,  2655,  2660,  2661,  2662,  2663,  2664,
    2669,  2676,  2686,  2692,  2701,  2711,  2718,  2726,  2738,  2748,
    2758,  2768,  2778,  2788,  2798,  2808,  2819,  2828,  2838,  2848,
    2864,  2873,  2882,  2890,  2896,  2908,  2916,  2926,  2934,  2946,
    2952,  2963,  2965,  2969,  2977,  2981,  2986,  2990,  2994,  2998,
    3008,  3016,  3023,  3029,  3039,  3043,  3047,  3055,  3063,  3071,
    3083,  3091,  3097,  3107,  3113,  3123,  3127,  3137,  3143,  3149,
    3155,  3164,  3173,  3182,  3195,  3199,  3207,  3213,  3223,  3231,
    3240,  3253,  3260,  3272,  3276,  3288,  3295,  3301,  3310,  3317,
    3323,  3334,  3341,  3347,  3356,  3365,  3372,  3383,  3390,  3402,
    3408,  3420,  3426,  3437,  3443,  3454,  3460,  3471,  3480,  3484,
    3493,  3497,  3505,  3509,  3519,  3526,  3535,  3545,  3544,  3558,
    3567,  3576,  3589,  3593,  3605,  3609,  3617,  3620,  3627,  3631,
    3640,  3644,  3648,  3656,  3660,  3666,  3672,  3678,  3688,  3692,
    3696,  3704,  3708,  3714,  3724,  3728,  3738,  3742,  3752,  3756,
    3766,  3770,  3780,  3784,  3792,  3796,  3800,  3804,  3814,  3818,
    3822,  3829,  3834,  3842,  3846,  3850,  3854,  3858,  3862,  3870,
    3874,  3878,  3886,  3890,  3894,  3898,  3909,  3915,  3925,  3931,
    3941,  3945,  3949,  3987,  3991,  4001,  4011,  4024,  4033,  4043,
    4047,  4056,  4060,  4069,  4075,  4083,  4089,  4101,  4107,  4117,
    4121,  4125,  4129,  4133,  4139,  4145,  4153,  4157,  4165,  4169,
    4180,  4184,  4188,  4194,  4198,  4212,  4216,  4224,  4228,  4238,
    4242,  4246,  4250,  4259,  4263,  4267,  4271,  4279,  4285,  4295,
    4303,  4307,  4311,  4315,  4319,  4323,  4327,  4331,  4335,  4339,
    4344,  4348,  4352,  4356,  4364,  4368,  4376,  4383,  4390,  4401,
    4409,  4413,  4421,  4429,  4437,  4491,  4495,  4518,  4524,  4530,
    4536,  4546,  4550,  4558,  4562,  4566,  4574,  4584,  4594,  4611,
    4628,  4645,  4667,  4673,  4684,  4690,  4701,  4712,  4714,  4718,
    4723,  4733,  4736,  4743,  4749,  4755,  4763,  4776,  4779,  4786,
    4792,  4798,  4805,  4816,  4820,  4830,  4834,  4844,  4848,  4852,
    4857,  4866,  4872,  4878,  4884,  4892,  4897,  4905,  4910,  4918,
    4926,  4931,  4936,  4941,  4946,  4951,  4960,  4968,  4972,  4989,
    4993,  5001,  5009,  5017,  5021,  5029,  5035,  5045,  5053,  5057,
    5061,  5096,  5102,  5108,  5118,  5122,  5126,  5130,  5134,  5138,
    5142,  5149,  5155,  5165,  5173,  5177,  5181,  5185,  5189,  5193,
    5197,  5201,  5205,  5213,  5221,  5225,  5229,  5239,  5247,  5255,
    5259,  5263,  5271,  5275,  5281,  5287,  5291,  5301,  5309,  5313,
    5319,  5328,  5337,  5343,  5349,  5359,  5376,  5383,  5398,  5434,
    5438,  5446,  5454,  5466,  5470,  5478,  5486,  5490,  5501,  5518,
    5524,  5530,  5540,  5544,  5550,  5556,  5560,  5566,  5570,  5576,
    5582,  5589,  5599,  5604,  5612,  5618,  5628,  5650,  5659,  5665,
    5678,  5692,  5699,  5705,  5715,  5724,  5732,  5738,  5756,  5764,
    5768,  5775,  5780,  5788,  5792,  5799,  5803,  5810,  5814,  5821,
    5825,  5834,  5847,  5850,  5858,  5861,  5869,  5877,  5885,  5889,
    5897,  5900,  5908,  5920,  5923,  5931,  5943,  5949,  5959,  5962,
    5970,  5974,  5978,  5986,  5989,  5997,  6000,  6008,  6012,  6016,
    6020,  6024,  6032,  6040,  6052,  6064,  6068,  6072,  6080,  6086,
    6096,  6100,  6104,  6108,  6112,  6116,  6120,  6124,  6132,  6136,
    6140,  6144,  6152,  6158,  6168,  6178,  6182,  6190,  6200,  6211,
    6218,  6222,  6230,  6233,  6240,  6245,  6254,  6264,  6267,  6274,
    6278,  6286,  6295,  6302,  6312,  6316,  6323,  6329,  6339,  6342,
    6349,  6354,  6366,  6374,  6386,  6394,  6398,  6406,  6410,  6414,
    6422,  6430,  6434,  6438,  6442,  6450,  6458,  6470,  6474,  6482,
    6496,  6500,  6507,  6512,  6520,  6525,  6534,  6542,  6548,  6558,
    6564,  6574,  6581,  6588,  6613,  6641,  6669,  6673,  6677,  6684,
    6691,  6698,  6710,  6714,  6715,  6728,  6729,  6730,  6731,  6732,
    6733,  6734,  6735,  6736,  6737,  6738,  6739,  6740,  6741,  6742,
    6743,  6747,  6748,  6749,  6750,  6751,  6752,  6753,  6754,  6755,
    6756,  6757,  6758,  6759,  6760,  6761,  6762,  6763,  6764,  6765,
    6766,  6767,  6768,  6769,  6770,  6771,  6772,  6773,  6774,  6775,
    6776,  6777,  6778,  6779,  6780,  6781,  6782,  6783,  6784,  6785,
    6786,  6787,  6788,  6789,  6790,  6791,  6792,  6793,  6794,  6795,
    6796,  6797,  6798,  6799,  6800,  6801,  6802,  6803,  6804,  6805,
    6806,  6807,  6808,  6809,  6810,  6811,  6812,  6813,  6814,  6815,
    6816,  6817,  6818,  6819,  6820,  6821,  6822,  6823,  6824,  6825,
    6826,  6827,  6828,  6829,  6830,  6831,  6832,  6833,  6834,  6835,
    6836,  6837,  6838,  6839,  6840,  6841,  6842,  6843,  6844,  6845,
    6846,  6847,  6848,  6849,  6850,  6851,  6852,  6853,  6854,  6855,
    6856,  6857,  6858,  6859,  6860,  6861,  6862,  6863,  6864,  6865,
    6866,  6867,  6868,  6869,  6870,  6871,  6872,  6873,  6874,  6875,
    6876,  6877,  6878,  6879,  6880,  6881,  6882,  6883,  6884,  6885,
    6886,  6887,  6888,  6889,  6890,  6891,  6892,  6893,  6894,  6895,
    6896,  6897,  6898,  6899,  6900,  6901,  6902,  6903,  6904,  6905,
    6906,  6907,  6908,  6909,  6910,  6911,  6912,  6913,  6914,  6915,
    6916,  6917,  6918,  6919,  6920,  6921,  6922,  6923,  6924,  6925,
    6926,  6927,  6928,  6929,  6930,  6931,  6932,  6933,  6934,  6935,
    6936,  6937,  6938,  6939,  6940,  6941,  6942,  6943,  6944,  6945,
    6946,  6947,  6948,  6949,  6950,  6951,  6952,  6957
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
  const int xquery_parser::yylast_ = 16993;
  const int xquery_parser::yynnts_ = 322;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 608;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 334;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 588;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba
/* Line 1106 of lalr1.cc  */
#line 16191 "/home/colea/xquery_bzr/hof/build/src/compiler/parser/xquery_parser.cpp"
/* Line 1107 of lalr1.cc  */
#line 6961 "/home/colea/xquery_bzr/hof/src/compiler/parser/xquery_parser.y"


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
