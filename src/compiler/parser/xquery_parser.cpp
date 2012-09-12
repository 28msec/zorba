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
#line 87 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"


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
#line 75 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"


#include "xquery_parser.hpp"

/* User implementation prologue.  */
/* Line 284 of lalr1.cc  */
#line 906 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"

// HACK to trigger rchandle release: rchandles are freed when refcount == 0
// (not <= 0); but Bison never increments the refcount, so we do it manually...
template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}
/* Line 284 of lalr1.cc  */
#line 1023 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"

#include "compiler/parser/xquery_scanner.h"

#undef yylex
#define yylex driver.lexer->lex


/* Line 284 of lalr1.cc  */
#line 102 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"


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
#line 197 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"

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
#line 904 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).decval); };
/* Line 453 of lalr1.cc  */
#line 303 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "'DOUBLE'" */
/* Line 453 of lalr1.cc  */
#line 903 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).dval); };
/* Line 453 of lalr1.cc  */
#line 310 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "'INTEGER'" */
/* Line 453 of lalr1.cc  */
#line 902 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).ival); };
/* Line 453 of lalr1.cc  */
#line 317 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* VersionDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 324 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* MainModule */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 331 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* LibraryModule */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 338 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* ModuleDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 345 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* SIND_DeclList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 352 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* SIND_Decl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 359 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* Setter */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 366 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* BoundarySpaceDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 373 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* DefaultCollationDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 380 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* BaseURIDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 387 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* ConstructionDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 394 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* OrderingModeDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 401 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* EmptyOrderDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 408 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* CopyNamespacesDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 415 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* Import */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 422 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* SchemaImport */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 429 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* URILiteralList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 436 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* SchemaPrefix */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 443 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* ModuleImport */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 450 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* NamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 457 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* DefaultNamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 464 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* VFO_DeclList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 471 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* VFO_Decl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 478 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* DecimalFormatDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 485 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* DecimalFormatParamList */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).vstrpair); };
/* Line 453 of lalr1.cc  */
#line 492 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* DecimalFormatParam */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).strpair); };
/* Line 453 of lalr1.cc  */
#line 499 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* OptionDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 506 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* FTOptionDecl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 513 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* CtxItemDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 520 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* CtxItemDecl2 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 527 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* CtxItemDecl3 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 534 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* CtxItemDecl4 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 541 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* VarDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 548 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* VarNameAndType */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).varnametype); };
/* Line 453 of lalr1.cc  */
#line 555 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* AnnotationList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 562 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* Annotation */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 569 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* AnnotationLiteralList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 576 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* FunctionDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 583 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* FunctionDecl2 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 590 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* FunctionDeclSimple */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 597 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* FunctionDeclUpdating */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 604 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* FunctionSig */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).fnsig); };
/* Line 453 of lalr1.cc  */
#line 611 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* ParamList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 618 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* Param */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 625 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* CollectionDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 632 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* IndexDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 639 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* IndexKeyList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 646 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* IndexKeySpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 653 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* IntegrityConstraintDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 660 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* QueryBody */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 667 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* StatementsAndOptionalExprTop */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 674 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* StatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 681 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* StatementsAndExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 688 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* Statements */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 695 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* Statement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 702 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* BlockStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 709 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* BlockExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 716 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* EnclosedStatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 723 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* VarDeclStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 730 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* AssignStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 737 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* ApplyStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 744 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* ExitStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 751 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* WhileStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 758 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* FlowCtlStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 765 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* FLWORStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 772 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* ReturnStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 779 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* IfStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 786 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* TryStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 793 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* CatchListStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 800 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* CatchStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 807 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* Expr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 814 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* ExprSingle */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 821 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* ExprSimple */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 828 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* FLWORExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 835 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* ReturnExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 842 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* FLWORWinCond */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 849 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* WindowClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 856 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* CountClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 863 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* ForLetWinClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 870 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* FLWORClauseList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 877 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* ForClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 884 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* VarInDeclList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 891 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* VarInDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 898 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* PositionalVar */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 905 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* FTScoreVar */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 912 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* LetClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 919 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* VarGetsDeclList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* VarGetsDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 933 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* WindowVarDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 940 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* WindowVars */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 947 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* WindowVars3 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 954 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* WindowVars2 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 961 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* WhereClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 968 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* GroupByClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 975 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* GroupSpecList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 982 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* GroupSpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 989 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* GroupCollationSpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 996 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* OrderByClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1003 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* OrderSpecList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1010 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* OrderSpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1017 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* OrderModifier */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1024 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* OrderDirSpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1031 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* OrderEmptySpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1038 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* OrderCollationSpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1045 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* QuantifiedExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1052 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* QVarInDeclList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1059 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* QVarInDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1066 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* SwitchExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1073 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* SwitchCaseClauseList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1080 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* SwitchCaseClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1087 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* SwitchCaseOperandList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1094 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* SwitchStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1101 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* TypeswitchExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1108 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* TypeswitchStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1115 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* CaseClauseList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1122 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* CaseClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1129 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* IfExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1136 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* OrExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1143 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* AndExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1150 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* ComparisonExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1157 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* FTContainsExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1164 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* StringConcatExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1171 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* opt_FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1178 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* RangeExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1185 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* AdditiveExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1192 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* MultiplicativeExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1199 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* UnionExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1206 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* IntersectExceptExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1213 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* InstanceofExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1220 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* TreatExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1227 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* CastableExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1234 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* CastExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1241 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* UnaryExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1248 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* SignList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1255 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* ValueExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1262 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* ValueComp */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1269 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* NodeComp */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1276 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* ValidateExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1283 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* ExtensionExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1290 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* Pragma_list */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1297 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* Pragma */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1304 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* PathExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1311 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* RelativePathExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1318 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* StepExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1325 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* AxisStep */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1332 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* ForwardStep */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1339 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* ForwardAxis */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1346 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* AbbrevForwardStep */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1353 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* ReverseStep */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1360 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* ReverseAxis */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1367 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* NodeTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1374 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* NameTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1381 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* Wildcard */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1388 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* FilterExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1395 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* PredicateList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1402 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* Predicate */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1409 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* PrimaryExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1416 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* Literal */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1423 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* NumericLiteral */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1430 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* VarRef */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1437 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* ParenthesizedExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1444 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* ContextItemExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1451 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* OrderedExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1458 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* UnorderedExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1465 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* FunctionCall */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1472 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* ArgList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1479 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* Constructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1486 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* DirectConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1493 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* DirElemConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1500 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* DirElemContentList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1507 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* DirAttributeList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1514 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* DirAttr */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1521 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* DirAttributeValue */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1528 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* opt_QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1535 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1542 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* opt_AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1549 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1556 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* QuoteAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1563 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* AposAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1570 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* DirElemContent */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1577 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* CommonContent */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1584 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* DirCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1591 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* DirPIConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1598 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* CDataSection */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1605 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* ComputedConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1612 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* CompDocConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1619 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* CompElemConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1626 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* CompAttrConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1633 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* CompTextConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1640 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* CompCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1647 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* CompPIConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1654 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* SingleType */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1661 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* TypeDeclaration */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1668 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* SequenceType */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1675 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* OccurrenceIndicator */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1682 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* ItemType */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1689 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* TypeList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1696 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* AtomicType */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1703 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* KindTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1710 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* AnyKindTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1717 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* DocumentTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1724 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* TextTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1731 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* CommentTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1738 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* PITest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1745 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* AttributeTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1752 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* SchemaAttributeTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1759 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* ElementTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1766 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* SchemaElementTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1773 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* TypeName */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1780 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* TypeName_WITH_HOOK */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1787 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* StringLiteral */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1794 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* AnyFunctionTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1801 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* TypedFunctionTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1808 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* InsertExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1815 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* DeleteExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1822 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* ReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1829 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* RenameExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1836 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* TransformExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1843 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* VarNameList */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1850 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* VarNameDecl */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1857 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* TryExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1864 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* CatchListExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1871 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* CatchExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1878 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* BracedExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1885 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* NameTestList */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).name_test_list); };
/* Line 453 of lalr1.cc  */
#line 1892 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* FTSelection */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1899 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* FTOr */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1906 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* FTAnd */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1913 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* FTMildNot */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1920 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* FTUnaryNot */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1927 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* FTPrimaryWithOptions */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1934 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* opt_FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1941 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* FTWeight */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1948 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* FTPrimary */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1955 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* opt_FTTimes */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1962 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* FTExtensionSelection */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1969 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* FTWords */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1976 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* FTWordsValue */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1983 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* FTAnyallOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1990 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* FTPosFilter */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1997 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* FTOrder */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2004 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* FTWindow */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2011 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* FTDistance */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2018 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* FTUnit */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2025 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2032 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* FTMatchOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2039 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* FTCaseOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2046 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* FTDiacriticsOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2053 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* FTExtensionOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2060 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* FTStemOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2067 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* FTThesaurusOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2074 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* FTThesaurusID */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2081 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* FTStopWordOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2088 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* FTStopWords */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2095 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* FTStopWordsInclExcl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2102 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* FTLanguageOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2109 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* FTWildCardOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2116 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* FTContent */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2123 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* FTTimes */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2130 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* FTRange */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2137 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* FTScope */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2144 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* FTBigUnit */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2151 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2158 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* JSONArrayConstructor */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2165 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* JSONSimpleObjectUnion */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2172 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* JSONAccumulatorObjectUnion */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2179 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* JSONObjectConstructor */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2186 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* JSONPairList */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2193 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* JSONInsertExpr */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2200 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* JSONAppendExpr */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2207 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* JSONDeleteExpr */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2214 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* JSONRenameExpr */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2221 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* JSONReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2228 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* QNAME */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2235 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* FUNCTION_NAME */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2242 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* EQNAME */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2249 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
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
#line 140 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}
/* Line 538 of lalr1.cc  */
#line 2344 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"

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
#line 1041 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:
/* Line 661 of lalr1.cc  */
#line 1045 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:
/* Line 661 of lalr1.cc  */
#line 1049 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:
/* Line 661 of lalr1.cc  */
#line 1060 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 7:
/* Line 661 of lalr1.cc  */
#line 1069 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 8:
/* Line 661 of lalr1.cc  */
#line 1075 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 9:
/* Line 661 of lalr1.cc  */
#line 1083 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:
/* Line 661 of lalr1.cc  */
#line 1089 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:
/* Line 661 of lalr1.cc  */
#line 1100 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 12:
/* Line 661 of lalr1.cc  */
#line 1105 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 13:
/* Line 661 of lalr1.cc  */
#line 1113 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 14:
/* Line 661 of lalr1.cc  */
#line 1120 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 15:
/* Line 661 of lalr1.cc  */
#line 1127 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 16:
/* Line 661 of lalr1.cc  */
#line 1136 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 17:
/* Line 661 of lalr1.cc  */
#line 1143 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 18:
/* Line 661 of lalr1.cc  */
#line 1151 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 19:
/* Line 661 of lalr1.cc  */
#line 1159 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 20:
/* Line 661 of lalr1.cc  */
#line 1167 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr); // to prevent the Bison warning
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 21:
/* Line 661 of lalr1.cc  */
#line 1178 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 22:
/* Line 661 of lalr1.cc  */
#line 1183 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 23:
/* Line 661 of lalr1.cc  */
#line 1190 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 24:
/* Line 661 of lalr1.cc  */
#line 1197 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 25:
/* Line 661 of lalr1.cc  */
#line 1209 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 26:
/* Line 661 of lalr1.cc  */
#line 1219 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 27:
/* Line 661 of lalr1.cc  */
#line 1226 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 28:
/* Line 661 of lalr1.cc  */
#line 1233 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1268 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 43:
/* Line 661 of lalr1.cc  */
#line 1273 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 44:
/* Line 661 of lalr1.cc  */
#line 1281 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 45:
/* Line 661 of lalr1.cc  */
#line 1289 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 46:
/* Line 661 of lalr1.cc  */
#line 1297 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 47:
/* Line 661 of lalr1.cc  */
#line 1302 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 48:
/* Line 661 of lalr1.cc  */
#line 1310 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 49:
/* Line 661 of lalr1.cc  */
#line 1315 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 50:
/* Line 661 of lalr1.cc  */
#line 1323 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 51:
/* Line 661 of lalr1.cc  */
#line 1328 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 52:
/* Line 661 of lalr1.cc  */
#line 1336 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 53:
/* Line 661 of lalr1.cc  */
#line 1343 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 54:
/* Line 661 of lalr1.cc  */
#line 1350 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::inherit_ns);
    }
    break;

  case 55:
/* Line 661 of lalr1.cc  */
#line 1357 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)),
                                  StaticContextConsts::no_preserve_ns,
                                  StaticContextConsts::no_inherit_ns);
    }
    break;

  case 58:
/* Line 661 of lalr1.cc  */
#line 1372 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yyval.node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 59:
/* Line 661 of lalr1.cc  */
#line 1382 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 60:
/* Line 661 of lalr1.cc  */
#line 1387 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 61:
/* Line 661 of lalr1.cc  */
#line 1395 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 62:
/* Line 661 of lalr1.cc  */
#line 1403 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 63:
/* Line 661 of lalr1.cc  */
#line 1414 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 64:
/* Line 661 of lalr1.cc  */
#line 1421 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 65:
/* Line 661 of lalr1.cc  */
#line 1432 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 66:
/* Line 661 of lalr1.cc  */
#line 1437 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 67:
/* Line 661 of lalr1.cc  */
#line 1445 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 68:
/* Line 661 of lalr1.cc  */
#line 1452 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 69:
/* Line 661 of lalr1.cc  */
#line 1459 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 70:
/* Line 661 of lalr1.cc  */
#line 1468 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1481 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 72:
/* Line 661 of lalr1.cc  */
#line 1489 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 73:
/* Line 661 of lalr1.cc  */
#line 1496 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 74:
/* Line 661 of lalr1.cc  */
#line 1506 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 75:
/* Line 661 of lalr1.cc  */
#line 1513 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 76:
/* Line 661 of lalr1.cc  */
#line 1520 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 85:
/* Line 661 of lalr1.cc  */
#line 1543 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 86:
/* Line 661 of lalr1.cc  */
#line 1549 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 87:
/* Line 661 of lalr1.cc  */
#line 1558 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 88:
/* Line 661 of lalr1.cc  */
#line 1565 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 89:
/* Line 661 of lalr1.cc  */
#line 1575 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 90:
/* Line 661 of lalr1.cc  */
#line 1584 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 91:
/* Line 661 of lalr1.cc  */
#line 1585 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 92:
/* Line 661 of lalr1.cc  */
#line 1586 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 93:
/* Line 661 of lalr1.cc  */
#line 1587 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "infinty"; }
    break;

  case 94:
/* Line 661 of lalr1.cc  */
#line 1588 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 95:
/* Line 661 of lalr1.cc  */
#line 1589 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 96:
/* Line 661 of lalr1.cc  */
#line 1590 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 97:
/* Line 661 of lalr1.cc  */
#line 1591 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 98:
/* Line 661 of lalr1.cc  */
#line 1592 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 99:
/* Line 661 of lalr1.cc  */
#line 1593 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 100:
/* Line 661 of lalr1.cc  */
#line 1599 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 101:
/* Line 661 of lalr1.cc  */
#line 1607 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 102:
/* Line 661 of lalr1.cc  */
#line 1615 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 103:
/* Line 661 of lalr1.cc  */
#line 1623 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 104:
/* Line 661 of lalr1.cc  */
#line 1630 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 105:
/* Line 661 of lalr1.cc  */
#line 1638 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 106:
/* Line 661 of lalr1.cc  */
#line 1645 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 107:
/* Line 661 of lalr1.cc  */
#line 1650 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 108:
/* Line 661 of lalr1.cc  */
#line 1658 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 109:
/* Line 661 of lalr1.cc  */
#line 1666 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1680 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1694 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1711 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 113:
/* Line 661 of lalr1.cc  */
#line 1716 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 114:
/* Line 661 of lalr1.cc  */
#line 1724 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 115:
/* Line 661 of lalr1.cc  */
#line 1732 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 116:
/* Line 661 of lalr1.cc  */
#line 1743 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 117:
/* Line 661 of lalr1.cc  */
#line 1748 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 118:
/* Line 661 of lalr1.cc  */
#line 1757 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 119:
/* Line 661 of lalr1.cc  */
#line 1762 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 120:
/* Line 661 of lalr1.cc  */
#line 1769 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 121:
/* Line 661 of lalr1.cc  */
#line 1774 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 122:
/* Line 661 of lalr1.cc  */
#line 1784 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 123:
/* Line 661 of lalr1.cc  */
#line 1789 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 124:
/* Line 661 of lalr1.cc  */
#line 1798 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 125:
/* Line 661 of lalr1.cc  */
#line 1804 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 126:
/* Line 661 of lalr1.cc  */
#line 1817 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 127:
/* Line 661 of lalr1.cc  */
#line 1822 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 128:
/* Line 661 of lalr1.cc  */
#line 1830 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1841 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1856 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1868 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 1883 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 133:
/* Line 661 of lalr1.cc  */
#line 1888 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 134:
/* Line 661 of lalr1.cc  */
#line 1893 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 135:
/* Line 661 of lalr1.cc  */
#line 1898 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 136:
/* Line 661 of lalr1.cc  */
#line 1906 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 137:
/* Line 661 of lalr1.cc  */
#line 1913 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 138:
/* Line 661 of lalr1.cc  */
#line 1924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 139:
/* Line 661 of lalr1.cc  */
#line 1929 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 140:
/* Line 661 of lalr1.cc  */
#line 1939 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);
    }
    break;

  case 141:
/* Line 661 of lalr1.cc  */
#line 1946 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 142:
/* Line 661 of lalr1.cc  */
#line 1953 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);
    }
    break;

  case 143:
/* Line 661 of lalr1.cc  */
#line 1960 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 144:
/* Line 661 of lalr1.cc  */
#line 1970 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 145:
/* Line 661 of lalr1.cc  */
#line 1974 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 146:
/* Line 661 of lalr1.cc  */
#line 1980 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 147:
/* Line 661 of lalr1.cc  */
#line 1984 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 148:
/* Line 661 of lalr1.cc  */
#line 1994 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(8) - (3)].expr)),
                             (yysemantic_stack_[(8) - (6)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(8) - (8)].node)),
                             NULL);
    }
    break;

  case 149:
/* Line 661 of lalr1.cc  */
#line 2002 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AST_IndexDecl(LOC((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(9) - (4)].expr)),
                             (yysemantic_stack_[(9) - (7)].expr),
                             dynamic_cast<IndexKeyList*>((yysemantic_stack_[(9) - (9)].node)),
                             static_cast<AnnotationListParsenode*>((yysemantic_stack_[(9) - (2)].node)));
    }
    break;

  case 150:
/* Line 661 of lalr1.cc  */
#line 2013 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 151:
/* Line 661 of lalr1.cc  */
#line 2019 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 152:
/* Line 661 of lalr1.cc  */
#line 2028 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 153:
/* Line 661 of lalr1.cc  */
#line 2033 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 154:
/* Line 661 of lalr1.cc  */
#line 2040 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 155:
/* Line 661 of lalr1.cc  */
#line 2047 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 156:
/* Line 661 of lalr1.cc  */
#line 2059 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2069 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2079 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2090 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2106 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2126 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 162:
/* Line 661 of lalr1.cc  */
#line 2130 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 163:
/* Line 661 of lalr1.cc  */
#line 2134 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  NULL;
    }
    break;

  case 164:
/* Line 661 of lalr1.cc  */
#line 2142 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 165:
/* Line 661 of lalr1.cc  */
#line 2146 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:
/* Line 661 of lalr1.cc  */
#line 2150 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) =  new BlockBody(LOC((yyloc)));
    }
    break;

  case 167:
/* Line 661 of lalr1.cc  */
#line 2158 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 168:
/* Line 661 of lalr1.cc  */
#line 2163 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 169:
/* Line 661 of lalr1.cc  */
#line 2175 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 170:
/* Line 661 of lalr1.cc  */
#line 2182 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 183:
/* Line 661 of lalr1.cc  */
#line 2211 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 184:
/* Line 661 of lalr1.cc  */
#line 2216 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 185:
/* Line 661 of lalr1.cc  */
#line 2224 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2241 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 187:
/* Line 661 of lalr1.cc  */
#line 2249 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 188:
/* Line 661 of lalr1.cc  */
#line 2257 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 189:
/* Line 661 of lalr1.cc  */
#line 2264 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 190:
/* Line 661 of lalr1.cc  */
#line 2271 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 191:
/* Line 661 of lalr1.cc  */
#line 2282 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2291 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2300 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2309 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2322 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 196:
/* Line 661 of lalr1.cc  */
#line 2330 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 197:
/* Line 661 of lalr1.cc  */
#line 2338 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 198:
/* Line 661 of lalr1.cc  */
#line 2346 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2361 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 200:
/* Line 661 of lalr1.cc  */
#line 2366 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 201:
/* Line 661 of lalr1.cc  */
#line 2374 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2388 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2405 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2430 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 205:
/* Line 661 of lalr1.cc  */
#line 2438 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 206:
/* Line 661 of lalr1.cc  */
#line 2445 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 207:
/* Line 661 of lalr1.cc  */
#line 2456 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 208:
/* Line 661 of lalr1.cc  */
#line 2466 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 209:
/* Line 661 of lalr1.cc  */
#line 2471 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2516 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2530 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 230:
/* Line 661 of lalr1.cc  */
#line 2538 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 231:
/* Line 661 of lalr1.cc  */
#line 2543 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 2551 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 2556 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 2561 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 2569 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 2578 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 2590 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2600 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2613 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 248:
/* Line 661 of lalr1.cc  */
#line 2637 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 249:
/* Line 661 of lalr1.cc  */
#line 2644 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 250:
/* Line 661 of lalr1.cc  */
#line 2654 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 251:
/* Line 661 of lalr1.cc  */
#line 2660 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected QName \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 252:
/* Line 661 of lalr1.cc  */
#line 2669 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 253:
/* Line 661 of lalr1.cc  */
#line 2679 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 254:
/* Line 661 of lalr1.cc  */
#line 2686 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 2694 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); // to prevent the Bison warning
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 2706 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2716 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2726 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2736 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2746 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2756 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2766 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2776 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2787 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2796 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2806 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2816 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 2832 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 269:
/* Line 661 of lalr1.cc  */
#line 2841 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 270:
/* Line 661 of lalr1.cc  */
#line 2850 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 2858 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 2864 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 2876 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 274:
/* Line 661 of lalr1.cc  */
#line 2884 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 2894 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 276:
/* Line 661 of lalr1.cc  */
#line 2902 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 277:
/* Line 661 of lalr1.cc  */
#line 2914 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 278:
/* Line 661 of lalr1.cc  */
#line 2920 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 2933 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 281:
/* Line 661 of lalr1.cc  */
#line 2937 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 2945 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 2949 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 285:
/* Line 661 of lalr1.cc  */
#line 2958 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 286:
/* Line 661 of lalr1.cc  */
#line 2962 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 2966 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 2976 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 2984 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 2991 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 2997 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 3007 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 3011 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 3015 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 3023 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 3031 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 297:
/* Line 661 of lalr1.cc  */
#line 3039 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 298:
/* Line 661 of lalr1.cc  */
#line 3051 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 299:
/* Line 661 of lalr1.cc  */
#line 3059 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 300:
/* Line 661 of lalr1.cc  */
#line 3065 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 3075 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 3081 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 3091 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 3095 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 3105 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 3111 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 3117 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 3123 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3132 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3141 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3150 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3163 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 313:
/* Line 661 of lalr1.cc  */
#line 3167 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 314:
/* Line 661 of lalr1.cc  */
#line 3175 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 3181 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 3191 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 3199 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3208 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3221 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 320:
/* Line 661 of lalr1.cc  */
#line 3228 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 321:
/* Line 661 of lalr1.cc  */
#line 3240 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 3244 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 3256 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 3263 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 3269 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 3278 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 3285 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 3291 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 3302 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 3309 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 3315 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 3324 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 3333 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 3340 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 3351 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 3358 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3370 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 3376 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 339:
/* Line 661 of lalr1.cc  */
#line 3388 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 3394 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 3405 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 3411 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 3422 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 3428 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 3439 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 3448 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 3452 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 3461 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 3465 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 3473 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 3477 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3487 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 3494 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3503 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3512 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 356:
/* Line 661 of lalr1.cc  */
#line 3517 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3526 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3535 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3544 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3557 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 361:
/* Line 661 of lalr1.cc  */
#line 3561 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 3573 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 3577 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 364:
/* Line 661 of lalr1.cc  */
#line 3584 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 3588 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 3595 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 3599 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 3608 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 3612 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 3616 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 3624 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 3628 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 3634 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 3640 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 3646 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 3656 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 3660 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 3664 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 3672 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 3676 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 3682 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 3692 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 3696 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 3706 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 3710 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 3720 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 3724 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 3734 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 3738 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:
/* Line 661 of lalr1.cc  */
#line 3748 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:
/* Line 661 of lalr1.cc  */
#line 3752 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 392:
/* Line 661 of lalr1.cc  */
#line 3760 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 393:
/* Line 661 of lalr1.cc  */
#line 3764 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 394:
/* Line 661 of lalr1.cc  */
#line 3768 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 395:
/* Line 661 of lalr1.cc  */
#line 3772 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 396:
/* Line 661 of lalr1.cc  */
#line 3782 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 397:
/* Line 661 of lalr1.cc  */
#line 3786 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:
/* Line 661 of lalr1.cc  */
#line 3790 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:
/* Line 661 of lalr1.cc  */
#line 3798 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 400:
/* Line 661 of lalr1.cc  */
#line 3802 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 401:
/* Line 661 of lalr1.cc  */
#line 3806 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 402:
/* Line 661 of lalr1.cc  */
#line 3810 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 403:
/* Line 661 of lalr1.cc  */
#line 3814 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 404:
/* Line 661 of lalr1.cc  */
#line 3818 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 405:
/* Line 661 of lalr1.cc  */
#line 3826 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 406:
/* Line 661 of lalr1.cc  */
#line 3830 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 407:
/* Line 661 of lalr1.cc  */
#line 3834 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 408:
/* Line 661 of lalr1.cc  */
#line 3842 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 409:
/* Line 661 of lalr1.cc  */
#line 3846 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 410:
/* Line 661 of lalr1.cc  */
#line 3850 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 411:
/* Line 661 of lalr1.cc  */
#line 3854 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 412:
/* Line 661 of lalr1.cc  */
#line 3865 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 413:
/* Line 661 of lalr1.cc  */
#line 3871 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 414:
/* Line 661 of lalr1.cc  */
#line 3881 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 415:
/* Line 661 of lalr1.cc  */
#line 3887 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 416:
/* Line 661 of lalr1.cc  */
#line 3897 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 417:
/* Line 661 of lalr1.cc  */
#line 3901 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 418:
/* Line 661 of lalr1.cc  */
#line 3905 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 419:
/* Line 661 of lalr1.cc  */
#line 3943 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 420:
/* Line 661 of lalr1.cc  */
#line 3947 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 421:
/* Line 661 of lalr1.cc  */
#line 3957 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 422:
/* Line 661 of lalr1.cc  */
#line 3967 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 423:
/* Line 661 of lalr1.cc  */
#line 3980 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 424:
/* Line 661 of lalr1.cc  */
#line 3989 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 425:
/* Line 661 of lalr1.cc  */
#line 3999 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 426:
/* Line 661 of lalr1.cc  */
#line 4003 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 427:
/* Line 661 of lalr1.cc  */
#line 4012 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 428:
/* Line 661 of lalr1.cc  */
#line 4016 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 429:
/* Line 661 of lalr1.cc  */
#line 4025 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 430:
/* Line 661 of lalr1.cc  */
#line 4031 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 431:
/* Line 661 of lalr1.cc  */
#line 4039 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 432:
/* Line 661 of lalr1.cc  */
#line 4045 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 433:
/* Line 661 of lalr1.cc  */
#line 4057 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 434:
/* Line 661 of lalr1.cc  */
#line 4063 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 435:
/* Line 661 of lalr1.cc  */
#line 4073 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 436:
/* Line 661 of lalr1.cc  */
#line 4077 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 437:
/* Line 661 of lalr1.cc  */
#line 4081 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 438:
/* Line 661 of lalr1.cc  */
#line 4085 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 439:
/* Line 661 of lalr1.cc  */
#line 4089 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 440:
/* Line 661 of lalr1.cc  */
#line 4095 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 441:
/* Line 661 of lalr1.cc  */
#line 4101 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 442:
/* Line 661 of lalr1.cc  */
#line 4109 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 443:
/* Line 661 of lalr1.cc  */
#line 4113 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 444:
/* Line 661 of lalr1.cc  */
#line 4121 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 445:
/* Line 661 of lalr1.cc  */
#line 4125 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 446:
/* Line 661 of lalr1.cc  */
#line 4136 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 447:
/* Line 661 of lalr1.cc  */
#line 4140 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 448:
/* Line 661 of lalr1.cc  */
#line 4144 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 449:
/* Line 661 of lalr1.cc  */
#line 4150 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 450:
/* Line 661 of lalr1.cc  */
#line 4154 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 451:
/* Line 661 of lalr1.cc  */
#line 4168 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 452:
/* Line 661 of lalr1.cc  */
#line 4172 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 453:
/* Line 661 of lalr1.cc  */
#line 4180 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 454:
/* Line 661 of lalr1.cc  */
#line 4184 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 455:
/* Line 661 of lalr1.cc  */
#line 4194 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 456:
/* Line 661 of lalr1.cc  */
#line 4198 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 457:
/* Line 661 of lalr1.cc  */
#line 4202 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 458:
/* Line 661 of lalr1.cc  */
#line 4206 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 459:
/* Line 661 of lalr1.cc  */
#line 4215 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 460:
/* Line 661 of lalr1.cc  */
#line 4219 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 461:
/* Line 661 of lalr1.cc  */
#line 4223 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 462:
/* Line 661 of lalr1.cc  */
#line 4227 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 463:
/* Line 661 of lalr1.cc  */
#line 4235 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 464:
/* Line 661 of lalr1.cc  */
#line 4241 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 465:
/* Line 661 of lalr1.cc  */
#line 4251 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 466:
/* Line 661 of lalr1.cc  */
#line 4259 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 467:
/* Line 661 of lalr1.cc  */
#line 4263 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 468:
/* Line 661 of lalr1.cc  */
#line 4267 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:
/* Line 661 of lalr1.cc  */
#line 4271 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:
/* Line 661 of lalr1.cc  */
#line 4275 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:
/* Line 661 of lalr1.cc  */
#line 4279 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:
/* Line 661 of lalr1.cc  */
#line 4283 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:
/* Line 661 of lalr1.cc  */
#line 4287 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:
/* Line 661 of lalr1.cc  */
#line 4291 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:
/* Line 661 of lalr1.cc  */
#line 4295 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:
/* Line 661 of lalr1.cc  */
#line 4300 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:
/* Line 661 of lalr1.cc  */
#line 4304 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:
/* Line 661 of lalr1.cc  */
#line 4308 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:
/* Line 661 of lalr1.cc  */
#line 4312 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:
/* Line 661 of lalr1.cc  */
#line 4320 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:
/* Line 661 of lalr1.cc  */
#line 4324 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:
/* Line 661 of lalr1.cc  */
#line 4332 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 483:
/* Line 661 of lalr1.cc  */
#line 4339 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 484:
/* Line 661 of lalr1.cc  */
#line 4346 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 485:
/* Line 661 of lalr1.cc  */
#line 4357 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 486:
/* Line 661 of lalr1.cc  */
#line 4365 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 487:
/* Line 661 of lalr1.cc  */
#line 4369 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 488:
/* Line 661 of lalr1.cc  */
#line 4377 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 489:
/* Line 661 of lalr1.cc  */
#line 4385 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 490:
/* Line 661 of lalr1.cc  */
#line 4393 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 491:
/* Line 661 of lalr1.cc  */
#line 4447 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 492:
/* Line 661 of lalr1.cc  */
#line 4451 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 493:
/* Line 661 of lalr1.cc  */
#line 4464 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 494:
/* Line 661 of lalr1.cc  */
#line 4470 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 495:
/* Line 661 of lalr1.cc  */
#line 4480 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 496:
/* Line 661 of lalr1.cc  */
#line 4484 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 497:
/* Line 661 of lalr1.cc  */
#line 4492 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:
/* Line 661 of lalr1.cc  */
#line 4496 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:
/* Line 661 of lalr1.cc  */
#line 4500 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 500:
/* Line 661 of lalr1.cc  */
#line 4508 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 501:
/* Line 661 of lalr1.cc  */
#line 4518 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 502:
/* Line 661 of lalr1.cc  */
#line 4528 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 503:
/* Line 661 of lalr1.cc  */
#line 4545 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 504:
/* Line 661 of lalr1.cc  */
#line 4562 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 505:
/* Line 661 of lalr1.cc  */
#line 4579 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 506:
/* Line 661 of lalr1.cc  */
#line 4601 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 507:
/* Line 661 of lalr1.cc  */
#line 4607 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 508:
/* Line 661 of lalr1.cc  */
#line 4618 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 509:
/* Line 661 of lalr1.cc  */
#line 4624 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:
/* Line 661 of lalr1.cc  */
#line 4635 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 513:
/* Line 661 of lalr1.cc  */
#line 4652 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 514:
/* Line 661 of lalr1.cc  */
#line 4657 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 515:
/* Line 661 of lalr1.cc  */
#line 4666 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 516:
/* Line 661 of lalr1.cc  */
#line 4670 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 517:
/* Line 661 of lalr1.cc  */
#line 4677 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 518:
/* Line 661 of lalr1.cc  */
#line 4683 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 519:
/* Line 661 of lalr1.cc  */
#line 4689 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 520:
/* Line 661 of lalr1.cc  */
#line 4697 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 521:
/* Line 661 of lalr1.cc  */
#line 4709 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 522:
/* Line 661 of lalr1.cc  */
#line 4713 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 523:
/* Line 661 of lalr1.cc  */
#line 4720 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 524:
/* Line 661 of lalr1.cc  */
#line 4726 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 525:
/* Line 661 of lalr1.cc  */
#line 4732 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 526:
/* Line 661 of lalr1.cc  */
#line 4739 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 527:
/* Line 661 of lalr1.cc  */
#line 4750 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 528:
/* Line 661 of lalr1.cc  */
#line 4754 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 529:
/* Line 661 of lalr1.cc  */
#line 4764 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 530:
/* Line 661 of lalr1.cc  */
#line 4768 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 531:
/* Line 661 of lalr1.cc  */
#line 4778 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 532:
/* Line 661 of lalr1.cc  */
#line 4782 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 533:
/* Line 661 of lalr1.cc  */
#line 4786 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 534:
/* Line 661 of lalr1.cc  */
#line 4791 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 535:
/* Line 661 of lalr1.cc  */
#line 4800 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 536:
/* Line 661 of lalr1.cc  */
#line 4806 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 537:
/* Line 661 of lalr1.cc  */
#line 4812 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 538:
/* Line 661 of lalr1.cc  */
#line 4818 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 539:
/* Line 661 of lalr1.cc  */
#line 4826 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 540:
/* Line 661 of lalr1.cc  */
#line 4831 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 541:
/* Line 661 of lalr1.cc  */
#line 4839 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 542:
/* Line 661 of lalr1.cc  */
#line 4844 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 543:
/* Line 661 of lalr1.cc  */
#line 4852 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 544:
/* Line 661 of lalr1.cc  */
#line 4860 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 545:
/* Line 661 of lalr1.cc  */
#line 4865 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 546:
/* Line 661 of lalr1.cc  */
#line 4870 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:
/* Line 661 of lalr1.cc  */
#line 4875 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:
/* Line 661 of lalr1.cc  */
#line 4880 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:
/* Line 661 of lalr1.cc  */
#line 4885 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:
/* Line 661 of lalr1.cc  */
#line 4894 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 551:
/* Line 661 of lalr1.cc  */
#line 4902 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 552:
/* Line 661 of lalr1.cc  */
#line 4906 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 553:
/* Line 661 of lalr1.cc  */
#line 4923 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 554:
/* Line 661 of lalr1.cc  */
#line 4927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 555:
/* Line 661 of lalr1.cc  */
#line 4935 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 556:
/* Line 661 of lalr1.cc  */
#line 4943 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 557:
/* Line 661 of lalr1.cc  */
#line 4951 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 558:
/* Line 661 of lalr1.cc  */
#line 4955 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 559:
/* Line 661 of lalr1.cc  */
#line 4963 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 560:
/* Line 661 of lalr1.cc  */
#line 4969 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 561:
/* Line 661 of lalr1.cc  */
#line 4979 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 562:
/* Line 661 of lalr1.cc  */
#line 4987 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 563:
/* Line 661 of lalr1.cc  */
#line 4991 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 564:
/* Line 661 of lalr1.cc  */
#line 4995 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 565:
/* Line 661 of lalr1.cc  */
#line 5030 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 566:
/* Line 661 of lalr1.cc  */
#line 5036 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 567:
/* Line 661 of lalr1.cc  */
#line 5042 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 568:
/* Line 661 of lalr1.cc  */
#line 5052 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:
/* Line 661 of lalr1.cc  */
#line 5056 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 570:
/* Line 661 of lalr1.cc  */
#line 5060 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 571:
/* Line 661 of lalr1.cc  */
#line 5064 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 572:
/* Line 661 of lalr1.cc  */
#line 5068 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 573:
/* Line 661 of lalr1.cc  */
#line 5072 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 574:
/* Line 661 of lalr1.cc  */
#line 5076 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:
/* Line 661 of lalr1.cc  */
#line 5083 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 576:
/* Line 661 of lalr1.cc  */
#line 5089 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 577:
/* Line 661 of lalr1.cc  */
#line 5099 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 578:
/* Line 661 of lalr1.cc  */
#line 5107 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 579:
/* Line 661 of lalr1.cc  */
#line 5111 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 580:
/* Line 661 of lalr1.cc  */
#line 5115 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:
/* Line 661 of lalr1.cc  */
#line 5119 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:
/* Line 661 of lalr1.cc  */
#line 5123 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:
/* Line 661 of lalr1.cc  */
#line 5127 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:
/* Line 661 of lalr1.cc  */
#line 5131 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:
/* Line 661 of lalr1.cc  */
#line 5135 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:
/* Line 661 of lalr1.cc  */
#line 5139 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:
/* Line 661 of lalr1.cc  */
#line 5147 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 588:
/* Line 661 of lalr1.cc  */
#line 5155 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 589:
/* Line 661 of lalr1.cc  */
#line 5159 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 590:
/* Line 661 of lalr1.cc  */
#line 5163 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 591:
/* Line 661 of lalr1.cc  */
#line 5173 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 592:
/* Line 661 of lalr1.cc  */
#line 5181 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 593:
/* Line 661 of lalr1.cc  */
#line 5189 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 594:
/* Line 661 of lalr1.cc  */
#line 5193 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 595:
/* Line 661 of lalr1.cc  */
#line 5197 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 596:
/* Line 661 of lalr1.cc  */
#line 5205 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 597:
/* Line 661 of lalr1.cc  */
#line 5209 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 598:
/* Line 661 of lalr1.cc  */
#line 5215 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 599:
/* Line 661 of lalr1.cc  */
#line 5221 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 600:
/* Line 661 of lalr1.cc  */
#line 5225 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 601:
/* Line 661 of lalr1.cc  */
#line 5235 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 602:
/* Line 661 of lalr1.cc  */
#line 5243 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 603:
/* Line 661 of lalr1.cc  */
#line 5247 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 604:
/* Line 661 of lalr1.cc  */
#line 5253 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                false
            );
        }
    break;

  case 605:
/* Line 661 of lalr1.cc  */
#line 5262 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)),
                dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)),
                true
            );
        }
    break;

  case 606:
/* Line 661 of lalr1.cc  */
#line 5271 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 607:
/* Line 661 of lalr1.cc  */
#line 5277 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 608:
/* Line 661 of lalr1.cc  */
#line 5283 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 609:
/* Line 661 of lalr1.cc  */
#line 5293 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 610:
/* Line 661 of lalr1.cc  */
#line 5310 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 611:
/* Line 661 of lalr1.cc  */
#line 5317 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 612:
/* Line 661 of lalr1.cc  */
#line 5332 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 613:
/* Line 661 of lalr1.cc  */
#line 5368 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 614:
/* Line 661 of lalr1.cc  */
#line 5372 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 615:
/* Line 661 of lalr1.cc  */
#line 5380 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 616:
/* Line 661 of lalr1.cc  */
#line 5388 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 617:
/* Line 661 of lalr1.cc  */
#line 5400 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 618:
/* Line 661 of lalr1.cc  */
#line 5404 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 619:
/* Line 661 of lalr1.cc  */
#line 5412 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 620:
/* Line 661 of lalr1.cc  */
#line 5420 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 621:
/* Line 661 of lalr1.cc  */
#line 5424 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 622:
/* Line 661 of lalr1.cc  */
#line 5435 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 623:
/* Line 661 of lalr1.cc  */
#line 5452 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 624:
/* Line 661 of lalr1.cc  */
#line 5458 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 625:
/* Line 661 of lalr1.cc  */
#line 5464 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 626:
/* Line 661 of lalr1.cc  */
#line 5474 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 627:
/* Line 661 of lalr1.cc  */
#line 5478 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 628:
/* Line 661 of lalr1.cc  */
#line 5484 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 629:
/* Line 661 of lalr1.cc  */
#line 5490 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 630:
/* Line 661 of lalr1.cc  */
#line 5494 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 631:
/* Line 661 of lalr1.cc  */
#line 5500 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:
/* Line 661 of lalr1.cc  */
#line 5504 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:
/* Line 661 of lalr1.cc  */
#line 5510 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 634:
/* Line 661 of lalr1.cc  */
#line 5516 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 635:
/* Line 661 of lalr1.cc  */
#line 5523 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 636:
/* Line 661 of lalr1.cc  */
#line 5533 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 637:
/* Line 661 of lalr1.cc  */
#line 5538 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 638:
/* Line 661 of lalr1.cc  */
#line 5546 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 639:
/* Line 661 of lalr1.cc  */
#line 5552 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 640:
/* Line 661 of lalr1.cc  */
#line 5562 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 641:
/* Line 661 of lalr1.cc  */
#line 5584 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 642:
/* Line 661 of lalr1.cc  */
#line 5593 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 643:
/* Line 661 of lalr1.cc  */
#line 5599 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 644:
/* Line 661 of lalr1.cc  */
#line 5612 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 645:
/* Line 661 of lalr1.cc  */
#line 5626 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 646:
/* Line 661 of lalr1.cc  */
#line 5633 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 647:
/* Line 661 of lalr1.cc  */
#line 5639 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 648:
/* Line 661 of lalr1.cc  */
#line 5649 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 649:
/* Line 661 of lalr1.cc  */
#line 5658 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 650:
/* Line 661 of lalr1.cc  */
#line 5666 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 651:
/* Line 661 of lalr1.cc  */
#line 5672 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 652:
/* Line 661 of lalr1.cc  */
#line 5690 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 653:
/* Line 661 of lalr1.cc  */
#line 5698 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 654:
/* Line 661 of lalr1.cc  */
#line 5702 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 655:
/* Line 661 of lalr1.cc  */
#line 5709 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 656:
/* Line 661 of lalr1.cc  */
#line 5714 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 657:
/* Line 661 of lalr1.cc  */
#line 5722 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 658:
/* Line 661 of lalr1.cc  */
#line 5726 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 659:
/* Line 661 of lalr1.cc  */
#line 5733 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:
/* Line 661 of lalr1.cc  */
#line 5737 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 661:
/* Line 661 of lalr1.cc  */
#line 5744 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:
/* Line 661 of lalr1.cc  */
#line 5748 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 663:
/* Line 661 of lalr1.cc  */
#line 5755 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:
/* Line 661 of lalr1.cc  */
#line 5759 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 665:
/* Line 661 of lalr1.cc  */
#line 5768 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 5780 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 667:
/* Line 661 of lalr1.cc  */
#line 5784 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 668:
/* Line 661 of lalr1.cc  */
#line 5791 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 669:
/* Line 661 of lalr1.cc  */
#line 5795 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:
/* Line 661 of lalr1.cc  */
#line 5803 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 671:
/* Line 661 of lalr1.cc  */
#line 5811 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 672:
/* Line 661 of lalr1.cc  */
#line 5819 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 673:
/* Line 661 of lalr1.cc  */
#line 5823 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 674:
/* Line 661 of lalr1.cc  */
#line 5830 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 675:
/* Line 661 of lalr1.cc  */
#line 5834 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:
/* Line 661 of lalr1.cc  */
#line 5842 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 677:
/* Line 661 of lalr1.cc  */
#line 5853 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 678:
/* Line 661 of lalr1.cc  */
#line 5857 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 679:
/* Line 661 of lalr1.cc  */
#line 5865 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 680:
/* Line 661 of lalr1.cc  */
#line 5877 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 681:
/* Line 661 of lalr1.cc  */
#line 5883 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 682:
/* Line 661 of lalr1.cc  */
#line 5892 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 683:
/* Line 661 of lalr1.cc  */
#line 5896 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 684:
/* Line 661 of lalr1.cc  */
#line 5904 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 685:
/* Line 661 of lalr1.cc  */
#line 5908 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 686:
/* Line 661 of lalr1.cc  */
#line 5912 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 687:
/* Line 661 of lalr1.cc  */
#line 5919 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 688:
/* Line 661 of lalr1.cc  */
#line 5923 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 689:
/* Line 661 of lalr1.cc  */
#line 5930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 690:
/* Line 661 of lalr1.cc  */
#line 5934 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 691:
/* Line 661 of lalr1.cc  */
#line 5942 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 692:
/* Line 661 of lalr1.cc  */
#line 5946 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 693:
/* Line 661 of lalr1.cc  */
#line 5950 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:
/* Line 661 of lalr1.cc  */
#line 5954 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:
/* Line 661 of lalr1.cc  */
#line 5958 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:
/* Line 661 of lalr1.cc  */
#line 5966 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 697:
/* Line 661 of lalr1.cc  */
#line 5974 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 698:
/* Line 661 of lalr1.cc  */
#line 5986 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 699:
/* Line 661 of lalr1.cc  */
#line 5998 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 700:
/* Line 661 of lalr1.cc  */
#line 6002 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 701:
/* Line 661 of lalr1.cc  */
#line 6006 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 702:
/* Line 661 of lalr1.cc  */
#line 6014 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 703:
/* Line 661 of lalr1.cc  */
#line 6020 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 704:
/* Line 661 of lalr1.cc  */
#line 6030 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:
/* Line 661 of lalr1.cc  */
#line 6034 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 706:
/* Line 661 of lalr1.cc  */
#line 6038 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:
/* Line 661 of lalr1.cc  */
#line 6042 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:
/* Line 661 of lalr1.cc  */
#line 6046 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:
/* Line 661 of lalr1.cc  */
#line 6050 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:
/* Line 661 of lalr1.cc  */
#line 6054 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:
/* Line 661 of lalr1.cc  */
#line 6058 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:
/* Line 661 of lalr1.cc  */
#line 6066 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 713:
/* Line 661 of lalr1.cc  */
#line 6070 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 714:
/* Line 661 of lalr1.cc  */
#line 6074 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 715:
/* Line 661 of lalr1.cc  */
#line 6078 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 716:
/* Line 661 of lalr1.cc  */
#line 6086 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 717:
/* Line 661 of lalr1.cc  */
#line 6092 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 718:
/* Line 661 of lalr1.cc  */
#line 6102 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 719:
/* Line 661 of lalr1.cc  */
#line 6112 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 720:
/* Line 661 of lalr1.cc  */
#line 6116 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 721:
/* Line 661 of lalr1.cc  */
#line 6124 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 6134 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 6145 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 724:
/* Line 661 of lalr1.cc  */
#line 6152 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 725:
/* Line 661 of lalr1.cc  */
#line 6156 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 726:
/* Line 661 of lalr1.cc  */
#line 6163 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 727:
/* Line 661 of lalr1.cc  */
#line 6167 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 728:
/* Line 661 of lalr1.cc  */
#line 6174 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 729:
/* Line 661 of lalr1.cc  */
#line 6179 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 730:
/* Line 661 of lalr1.cc  */
#line 6188 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 731:
/* Line 661 of lalr1.cc  */
#line 6197 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 732:
/* Line 661 of lalr1.cc  */
#line 6201 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 733:
/* Line 661 of lalr1.cc  */
#line 6208 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 734:
/* Line 661 of lalr1.cc  */
#line 6212 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 735:
/* Line 661 of lalr1.cc  */
#line 6220 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 6229 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 737:
/* Line 661 of lalr1.cc  */
#line 6236 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 738:
/* Line 661 of lalr1.cc  */
#line 6246 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 739:
/* Line 661 of lalr1.cc  */
#line 6250 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 740:
/* Line 661 of lalr1.cc  */
#line 6257 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 741:
/* Line 661 of lalr1.cc  */
#line 6263 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 742:
/* Line 661 of lalr1.cc  */
#line 6272 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 743:
/* Line 661 of lalr1.cc  */
#line 6276 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 744:
/* Line 661 of lalr1.cc  */
#line 6283 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 745:
/* Line 661 of lalr1.cc  */
#line 6288 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 746:
/* Line 661 of lalr1.cc  */
#line 6300 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 747:
/* Line 661 of lalr1.cc  */
#line 6308 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 748:
/* Line 661 of lalr1.cc  */
#line 6320 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 749:
/* Line 661 of lalr1.cc  */
#line 6328 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 750:
/* Line 661 of lalr1.cc  */
#line 6332 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 751:
/* Line 661 of lalr1.cc  */
#line 6340 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 752:
/* Line 661 of lalr1.cc  */
#line 6344 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 753:
/* Line 661 of lalr1.cc  */
#line 6348 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 754:
/* Line 661 of lalr1.cc  */
#line 6356 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 755:
/* Line 661 of lalr1.cc  */
#line 6364 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 756:
/* Line 661 of lalr1.cc  */
#line 6368 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 757:
/* Line 661 of lalr1.cc  */
#line 6372 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 758:
/* Line 661 of lalr1.cc  */
#line 6376 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 759:
/* Line 661 of lalr1.cc  */
#line 6384 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 760:
/* Line 661 of lalr1.cc  */
#line 6392 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 761:
/* Line 661 of lalr1.cc  */
#line 6404 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 762:
/* Line 661 of lalr1.cc  */
#line 6408 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 763:
/* Line 661 of lalr1.cc  */
#line 6416 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 764:
/* Line 661 of lalr1.cc  */
#line 6430 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 765:
/* Line 661 of lalr1.cc  */
#line 6434 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 766:
/* Line 661 of lalr1.cc  */
#line 6441 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 767:
/* Line 661 of lalr1.cc  */
#line 6446 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 768:
/* Line 661 of lalr1.cc  */
#line 6454 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 769:
/* Line 661 of lalr1.cc  */
#line 6459 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 770:
/* Line 661 of lalr1.cc  */
#line 6468 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 771:
/* Line 661 of lalr1.cc  */
#line 6476 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 772:
/* Line 661 of lalr1.cc  */
#line 6482 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 773:
/* Line 661 of lalr1.cc  */
#line 6492 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 774:
/* Line 661 of lalr1.cc  */
#line 6498 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 775:
/* Line 661 of lalr1.cc  */
#line 6505 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 776:
/* Line 661 of lalr1.cc  */
#line 6512 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 777:
/* Line 661 of lalr1.cc  */
#line 6541 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 778:
/* Line 661 of lalr1.cc  */
#line 6570 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 779:
/* Line 661 of lalr1.cc  */
#line 6599 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 780:
/* Line 661 of lalr1.cc  */
#line 6603 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 781:
/* Line 661 of lalr1.cc  */
#line 6607 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 782:
/* Line 661 of lalr1.cc  */
#line 6614 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 783:
/* Line 661 of lalr1.cc  */
#line 6621 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 784:
/* Line 661 of lalr1.cc  */
#line 6628 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 787:
/* Line 661 of lalr1.cc  */
#line 6645 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 789:
/* Line 661 of lalr1.cc  */
#line 6658 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 790:
/* Line 661 of lalr1.cc  */
#line 6659 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 791:
/* Line 661 of lalr1.cc  */
#line 6660 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 792:
/* Line 661 of lalr1.cc  */
#line 6661 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 793:
/* Line 661 of lalr1.cc  */
#line 6662 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 794:
/* Line 661 of lalr1.cc  */
#line 6663 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 795:
/* Line 661 of lalr1.cc  */
#line 6664 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 796:
/* Line 661 of lalr1.cc  */
#line 6665 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 797:
/* Line 661 of lalr1.cc  */
#line 6666 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 798:
/* Line 661 of lalr1.cc  */
#line 6667 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 799:
/* Line 661 of lalr1.cc  */
#line 6668 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 800:
/* Line 661 of lalr1.cc  */
#line 6669 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 801:
/* Line 661 of lalr1.cc  */
#line 6670 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 802:
/* Line 661 of lalr1.cc  */
#line 6671 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 803:
/* Line 661 of lalr1.cc  */
#line 6672 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 805:
/* Line 661 of lalr1.cc  */
#line 6677 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 806:
/* Line 661 of lalr1.cc  */
#line 6678 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 807:
/* Line 661 of lalr1.cc  */
#line 6679 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 808:
/* Line 661 of lalr1.cc  */
#line 6680 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 809:
/* Line 661 of lalr1.cc  */
#line 6681 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 810:
/* Line 661 of lalr1.cc  */
#line 6682 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 811:
/* Line 661 of lalr1.cc  */
#line 6683 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 812:
/* Line 661 of lalr1.cc  */
#line 6684 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 813:
/* Line 661 of lalr1.cc  */
#line 6685 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 814:
/* Line 661 of lalr1.cc  */
#line 6686 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 815:
/* Line 661 of lalr1.cc  */
#line 6687 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 816:
/* Line 661 of lalr1.cc  */
#line 6688 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 817:
/* Line 661 of lalr1.cc  */
#line 6689 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 818:
/* Line 661 of lalr1.cc  */
#line 6690 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 819:
/* Line 661 of lalr1.cc  */
#line 6691 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 820:
/* Line 661 of lalr1.cc  */
#line 6692 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 821:
/* Line 661 of lalr1.cc  */
#line 6693 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 822:
/* Line 661 of lalr1.cc  */
#line 6694 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 823:
/* Line 661 of lalr1.cc  */
#line 6695 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 824:
/* Line 661 of lalr1.cc  */
#line 6696 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 825:
/* Line 661 of lalr1.cc  */
#line 6697 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 826:
/* Line 661 of lalr1.cc  */
#line 6698 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 827:
/* Line 661 of lalr1.cc  */
#line 6699 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 828:
/* Line 661 of lalr1.cc  */
#line 6700 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 829:
/* Line 661 of lalr1.cc  */
#line 6701 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 830:
/* Line 661 of lalr1.cc  */
#line 6702 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 831:
/* Line 661 of lalr1.cc  */
#line 6703 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 832:
/* Line 661 of lalr1.cc  */
#line 6704 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 833:
/* Line 661 of lalr1.cc  */
#line 6705 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 834:
/* Line 661 of lalr1.cc  */
#line 6706 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 835:
/* Line 661 of lalr1.cc  */
#line 6707 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 836:
/* Line 661 of lalr1.cc  */
#line 6708 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 837:
/* Line 661 of lalr1.cc  */
#line 6709 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 838:
/* Line 661 of lalr1.cc  */
#line 6710 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 839:
/* Line 661 of lalr1.cc  */
#line 6711 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 840:
/* Line 661 of lalr1.cc  */
#line 6712 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 841:
/* Line 661 of lalr1.cc  */
#line 6713 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 842:
/* Line 661 of lalr1.cc  */
#line 6714 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 843:
/* Line 661 of lalr1.cc  */
#line 6715 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 844:
/* Line 661 of lalr1.cc  */
#line 6716 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 845:
/* Line 661 of lalr1.cc  */
#line 6717 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 846:
/* Line 661 of lalr1.cc  */
#line 6718 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 847:
/* Line 661 of lalr1.cc  */
#line 6719 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 848:
/* Line 661 of lalr1.cc  */
#line 6720 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 849:
/* Line 661 of lalr1.cc  */
#line 6721 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 850:
/* Line 661 of lalr1.cc  */
#line 6722 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 851:
/* Line 661 of lalr1.cc  */
#line 6723 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 852:
/* Line 661 of lalr1.cc  */
#line 6724 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 853:
/* Line 661 of lalr1.cc  */
#line 6725 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 854:
/* Line 661 of lalr1.cc  */
#line 6726 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 855:
/* Line 661 of lalr1.cc  */
#line 6727 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 856:
/* Line 661 of lalr1.cc  */
#line 6728 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 857:
/* Line 661 of lalr1.cc  */
#line 6729 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 858:
/* Line 661 of lalr1.cc  */
#line 6730 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 859:
/* Line 661 of lalr1.cc  */
#line 6731 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 860:
/* Line 661 of lalr1.cc  */
#line 6732 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 861:
/* Line 661 of lalr1.cc  */
#line 6733 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 862:
/* Line 661 of lalr1.cc  */
#line 6734 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 863:
/* Line 661 of lalr1.cc  */
#line 6735 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 864:
/* Line 661 of lalr1.cc  */
#line 6736 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 865:
/* Line 661 of lalr1.cc  */
#line 6737 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 866:
/* Line 661 of lalr1.cc  */
#line 6738 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 867:
/* Line 661 of lalr1.cc  */
#line 6739 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 868:
/* Line 661 of lalr1.cc  */
#line 6740 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 869:
/* Line 661 of lalr1.cc  */
#line 6741 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 870:
/* Line 661 of lalr1.cc  */
#line 6742 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 871:
/* Line 661 of lalr1.cc  */
#line 6743 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 872:
/* Line 661 of lalr1.cc  */
#line 6744 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 873:
/* Line 661 of lalr1.cc  */
#line 6745 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 874:
/* Line 661 of lalr1.cc  */
#line 6746 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 875:
/* Line 661 of lalr1.cc  */
#line 6747 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 876:
/* Line 661 of lalr1.cc  */
#line 6748 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 877:
/* Line 661 of lalr1.cc  */
#line 6749 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 878:
/* Line 661 of lalr1.cc  */
#line 6750 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 879:
/* Line 661 of lalr1.cc  */
#line 6751 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 880:
/* Line 661 of lalr1.cc  */
#line 6752 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 881:
/* Line 661 of lalr1.cc  */
#line 6753 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 882:
/* Line 661 of lalr1.cc  */
#line 6754 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 883:
/* Line 661 of lalr1.cc  */
#line 6755 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 884:
/* Line 661 of lalr1.cc  */
#line 6756 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 885:
/* Line 661 of lalr1.cc  */
#line 6757 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 886:
/* Line 661 of lalr1.cc  */
#line 6758 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 887:
/* Line 661 of lalr1.cc  */
#line 6759 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 888:
/* Line 661 of lalr1.cc  */
#line 6760 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 889:
/* Line 661 of lalr1.cc  */
#line 6761 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 890:
/* Line 661 of lalr1.cc  */
#line 6762 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 891:
/* Line 661 of lalr1.cc  */
#line 6763 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 892:
/* Line 661 of lalr1.cc  */
#line 6764 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 893:
/* Line 661 of lalr1.cc  */
#line 6765 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 894:
/* Line 661 of lalr1.cc  */
#line 6766 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 895:
/* Line 661 of lalr1.cc  */
#line 6767 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 896:
/* Line 661 of lalr1.cc  */
#line 6768 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 897:
/* Line 661 of lalr1.cc  */
#line 6769 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 898:
/* Line 661 of lalr1.cc  */
#line 6770 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 899:
/* Line 661 of lalr1.cc  */
#line 6771 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 900:
/* Line 661 of lalr1.cc  */
#line 6772 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 901:
/* Line 661 of lalr1.cc  */
#line 6773 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 902:
/* Line 661 of lalr1.cc  */
#line 6774 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 903:
/* Line 661 of lalr1.cc  */
#line 6775 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 904:
/* Line 661 of lalr1.cc  */
#line 6776 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 905:
/* Line 661 of lalr1.cc  */
#line 6777 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 906:
/* Line 661 of lalr1.cc  */
#line 6778 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 907:
/* Line 661 of lalr1.cc  */
#line 6779 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 908:
/* Line 661 of lalr1.cc  */
#line 6780 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 909:
/* Line 661 of lalr1.cc  */
#line 6781 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 910:
/* Line 661 of lalr1.cc  */
#line 6782 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 911:
/* Line 661 of lalr1.cc  */
#line 6783 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 912:
/* Line 661 of lalr1.cc  */
#line 6784 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 913:
/* Line 661 of lalr1.cc  */
#line 6785 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 914:
/* Line 661 of lalr1.cc  */
#line 6786 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 915:
/* Line 661 of lalr1.cc  */
#line 6787 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 916:
/* Line 661 of lalr1.cc  */
#line 6788 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 917:
/* Line 661 of lalr1.cc  */
#line 6789 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 918:
/* Line 661 of lalr1.cc  */
#line 6790 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 919:
/* Line 661 of lalr1.cc  */
#line 6791 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 920:
/* Line 661 of lalr1.cc  */
#line 6792 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 921:
/* Line 661 of lalr1.cc  */
#line 6793 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 922:
/* Line 661 of lalr1.cc  */
#line 6794 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 923:
/* Line 661 of lalr1.cc  */
#line 6795 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 924:
/* Line 661 of lalr1.cc  */
#line 6796 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 925:
/* Line 661 of lalr1.cc  */
#line 6797 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 926:
/* Line 661 of lalr1.cc  */
#line 6798 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 927:
/* Line 661 of lalr1.cc  */
#line 6799 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 928:
/* Line 661 of lalr1.cc  */
#line 6800 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 929:
/* Line 661 of lalr1.cc  */
#line 6801 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 930:
/* Line 661 of lalr1.cc  */
#line 6802 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 931:
/* Line 661 of lalr1.cc  */
#line 6803 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 932:
/* Line 661 of lalr1.cc  */
#line 6804 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 933:
/* Line 661 of lalr1.cc  */
#line 6805 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 934:
/* Line 661 of lalr1.cc  */
#line 6806 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 935:
/* Line 661 of lalr1.cc  */
#line 6807 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 936:
/* Line 661 of lalr1.cc  */
#line 6808 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 937:
/* Line 661 of lalr1.cc  */
#line 6809 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 938:
/* Line 661 of lalr1.cc  */
#line 6810 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 939:
/* Line 661 of lalr1.cc  */
#line 6811 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 940:
/* Line 661 of lalr1.cc  */
#line 6812 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 941:
/* Line 661 of lalr1.cc  */
#line 6813 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 942:
/* Line 661 of lalr1.cc  */
#line 6814 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 943:
/* Line 661 of lalr1.cc  */
#line 6815 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 944:
/* Line 661 of lalr1.cc  */
#line 6816 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 945:
/* Line 661 of lalr1.cc  */
#line 6817 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 946:
/* Line 661 of lalr1.cc  */
#line 6818 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 947:
/* Line 661 of lalr1.cc  */
#line 6819 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 948:
/* Line 661 of lalr1.cc  */
#line 6820 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 949:
/* Line 661 of lalr1.cc  */
#line 6821 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 950:
/* Line 661 of lalr1.cc  */
#line 6822 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 951:
/* Line 661 of lalr1.cc  */
#line 6823 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 952:
/* Line 661 of lalr1.cc  */
#line 6824 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 953:
/* Line 661 of lalr1.cc  */
#line 6825 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 954:
/* Line 661 of lalr1.cc  */
#line 6826 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 955:
/* Line 661 of lalr1.cc  */
#line 6827 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 956:
/* Line 661 of lalr1.cc  */
#line 6828 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 957:
/* Line 661 of lalr1.cc  */
#line 6829 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 958:
/* Line 661 of lalr1.cc  */
#line 6830 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 959:
/* Line 661 of lalr1.cc  */
#line 6831 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 960:
/* Line 661 of lalr1.cc  */
#line 6832 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 961:
/* Line 661 of lalr1.cc  */
#line 6833 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 962:
/* Line 661 of lalr1.cc  */
#line 6834 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 963:
/* Line 661 of lalr1.cc  */
#line 6835 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 964:
/* Line 661 of lalr1.cc  */
#line 6836 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 965:
/* Line 661 of lalr1.cc  */
#line 6837 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 966:
/* Line 661 of lalr1.cc  */
#line 6838 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 967:
/* Line 661 of lalr1.cc  */
#line 6839 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 968:
/* Line 661 of lalr1.cc  */
#line 6840 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 969:
/* Line 661 of lalr1.cc  */
#line 6841 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 970:
/* Line 661 of lalr1.cc  */
#line 6842 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 971:
/* Line 661 of lalr1.cc  */
#line 6843 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 972:
/* Line 661 of lalr1.cc  */
#line 6844 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 973:
/* Line 661 of lalr1.cc  */
#line 6845 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 974:
/* Line 661 of lalr1.cc  */
#line 6846 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 975:
/* Line 661 of lalr1.cc  */
#line 6847 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 976:
/* Line 661 of lalr1.cc  */
#line 6848 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 977:
/* Line 661 of lalr1.cc  */
#line 6849 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 978:
/* Line 661 of lalr1.cc  */
#line 6850 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 979:
/* Line 661 of lalr1.cc  */
#line 6851 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 980:
/* Line 661 of lalr1.cc  */
#line 6852 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 981:
/* Line 661 of lalr1.cc  */
#line 6853 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 982:
/* Line 661 of lalr1.cc  */
#line 6854 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 983:
/* Line 661 of lalr1.cc  */
#line 6855 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 984:
/* Line 661 of lalr1.cc  */
#line 6856 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 985:
/* Line 661 of lalr1.cc  */
#line 6857 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 986:
/* Line 661 of lalr1.cc  */
#line 6858 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 987:
/* Line 661 of lalr1.cc  */
#line 6859 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 988:
/* Line 661 of lalr1.cc  */
#line 6860 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 989:
/* Line 661 of lalr1.cc  */
#line 6861 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 990:
/* Line 661 of lalr1.cc  */
#line 6862 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 991:
/* Line 661 of lalr1.cc  */
#line 6863 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 992:
/* Line 661 of lalr1.cc  */
#line 6864 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 993:
/* Line 661 of lalr1.cc  */
#line 6865 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 994:
/* Line 661 of lalr1.cc  */
#line 6866 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 995:
/* Line 661 of lalr1.cc  */
#line 6867 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 996:
/* Line 661 of lalr1.cc  */
#line 6868 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 997:
/* Line 661 of lalr1.cc  */
#line 6869 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 998:
/* Line 661 of lalr1.cc  */
#line 6870 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 999:
/* Line 661 of lalr1.cc  */
#line 6871 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1000:
/* Line 661 of lalr1.cc  */
#line 6872 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1001:
/* Line 661 of lalr1.cc  */
#line 6873 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1002:
/* Line 661 of lalr1.cc  */
#line 6874 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1003:
/* Line 661 of lalr1.cc  */
#line 6875 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1004:
/* Line 661 of lalr1.cc  */
#line 6876 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1005:
/* Line 661 of lalr1.cc  */
#line 6877 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1006:
/* Line 661 of lalr1.cc  */
#line 6878 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1007:
/* Line 661 of lalr1.cc  */
#line 6879 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1008:
/* Line 661 of lalr1.cc  */
#line 6880 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1009:
/* Line 661 of lalr1.cc  */
#line 6881 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1010:
/* Line 661 of lalr1.cc  */
#line 6886 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;


/* Line 661 of lalr1.cc  */
#line 10657 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1500;
  const short int
  xquery_parser::yypact_[] =
  {
      3175, -1500, -1500, -1500,  5033,  5033,  5033, -1500, -1500,    21,
     253, -1500,   449,   212, -1500, -1500, -1500,   814, -1500, -1500,
   -1500,   289,   326,   818,  2895,   429,   433,   146, -1500,     1,
   -1500, -1500, -1500, -1500, -1500, -1500,   819, -1500,   537,   555,
   -1500, -1500, -1500, -1500,   604, -1500,   823, -1500,   588,   673,
   -1500,   109, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500,   342,   734, -1500, -1500,
   -1500, -1500,   668, 10904, -1500, -1500, -1500,   742, -1500, -1500,
   -1500,   807, -1500,   769,   811, -1500, -1500, 15276, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500,   859, -1500, -1500,   874,
     893, -1500, -1500, -1500, -1500, -1500, -1500, -1500,  3797,  6887,
    7196, 15276, -1500, -1500, -1500, -1500, -1500, -1500, -1500,   849,
   -1500, -1500,   895, 11796, -1500, 12098,   907,   908, -1500, -1500,
   -1500,   909, -1500, 10286, -1500, -1500, -1500, -1500, -1500, -1500,
     867, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,   106,
     817, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,   -89,
     877,   -86, -1500,   -79,   -85, -1500, -1500, -1500, -1500, -1500,
   -1500,   916, -1500,   797,   798,   799, -1500, -1500,   883,   888,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500,  7505,  7814, -1500,   731, -1500, -1500, -1500,
   -1500, -1500,  3486,  5342,  1045, -1500,  5651, -1500, -1500,   150,
      96, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500,    98, -1500, -1500, -1500, -1500,
   -1500, -1500,   166, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500,  5033, -1500, -1500, -1500, -1500,   119, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500,   939, -1500,   857, -1500, -1500,
   -1500,   545, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
     882,   960, -1500,   758,   806,   954,   529,   577,   707,    52,
   -1500,  1006,   858,   957,   958,  9050, -1500, -1500, -1500,    37,
   -1500, -1500, 10595, -1500,   447, -1500,   905, 10904, -1500,   905,
   10904, -1500, -1500, -1500,   765, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500,   919,   910, -1500, -1500,
   -1500, -1500, -1500,   881, -1500,  5033,   884,   885,   298,   298,
    1032,   144,   676,    30, 15563, 15276,    12,  1020, 15276,   918,
     953,   582, 11796,   737,   827, 15276, 15276,   770,   689,    49,
   -1500, -1500, -1500, 11796,  5033,   887,  5033,   149,  9359, 12980,
   15276, -1500,   792,   793, 15276,   959,    33,   926,  9359,  1079,
      84,    82, 15276,   963,   940,   976, -1500,  9359, 11500, 15276,
   15276, 15276,  5033,   897,  9359,  9359, 15276,  5033,   932,   933,
   -1500, -1500, -1500,  9359, 13267,   931, -1500,   934, -1500, -1500,
   -1500, -1500,   935, -1500,   936, -1500, -1500, -1500, -1500, -1500,
     937, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, 15276,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500,   947, 15276, -1500, -1500, -1500,   911,  4106,   973,
     249,   941,   942,   944, 15276,  5033, -1500,   948,    58, -1500,
     601, -1500,   231,  1067,  9359, -1500, -1500,    74, -1500, -1500,
   -1500,  1089, -1500, -1500, -1500, -1500,  9359,   894, -1500,  1080,
    9359,  9359, 12397,   921,  9359,  9359,  9359,  9359, 12397,  9359,
     886,   889, 15276,   924,   927,  9359,  9359,  3797,   871, -1500,
     -15, -1500,   -27,   965,  5342, -1500, -1500, -1500, -1500, -1500,
     449,   146,   100,   108,  1117,  5960,  5960,  6269,  6269,   807,
   -1500, -1500,   939,   807, -1500,  9359, -1500,  1003,   674,     1,
     955,   952,   956,  5033,  9359, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500,  9668,  9668,  9668, -1500,  9668,  9668, -1500,
    9668, -1500,  9668, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
    9668,  9668,  1055,  9668,  9668,  9668,  9668,  9668,  9668,  9668,
    9668,  9668,  9668,  9668,  9668,   899,  1033,  1034,  1036, -1500,
   -1500, -1500,  8123, -1500, -1500, 10286, 10286,  9359,   905, -1500,
   -1500,   905, -1500,  8432,   905,   982,  8741, -1500, -1500, -1500,
     244, -1500,   263, -1500, -1500, -1500, -1500, -1500, -1500,  1026,
    1027,   429,  1106, -1500, -1500, 15563,   901,   620, 15276,   977,
     978,   901,  1032,  1009,  1007, -1500, -1500, -1500,    68,   896,
    1046,   845, 15276,  1002,  9359,  1028, 15276, 15276, -1500,  1013,
     964,  5033, -1500,   966,   934,   555, -1500,   962,   968,   333,
   -1500,   275,   283,  1040, -1500,    31, -1500, -1500,  1040, 15276,
      55, 15276,  1057,   304, -1500,  5033, -1500,   310, -1500, 11796,
    1056,  1108, 11796,  1032,  1060,   626, 15276,  9359,     1,   381,
     970, -1500,   972,   974,   975,    35, -1500,    70,   979, -1500,
     314,   320,  1011, -1500,   981,  5033,  5033,   444, -1500,   327,
     332,   640,  9359,   257, -1500, -1500,  9359,  9359, -1500,  9359,
    9359,  9359, -1500,  9359, -1500,  9359, -1500, 15276,  1067, -1500,
      25,   475, -1500, -1500, -1500,   479, -1500,    28, -1500, -1500,
    1014,  1015,  1016,  1017,  1018,   765,   919, -1500,    13,   325,
     928,  1072,   398,   938,   951,   946,     7, -1500,  1030, -1500,
   -1500,   987,   334,  4415,   495, 11204,   871, -1500, -1500, -1500,
    9359, -1500,   150,   562,  1145,  1145, -1500, -1500,   111, -1500,
   -1500,   117, -1500,   126, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, 15276,  1010,  9359,  1061, -1500, -1500, -1500,   960, -1500,
   -1500, -1500, -1500, -1500,  9668, -1500, -1500, -1500,    48, -1500,
     577,   577,    40,   707,   707,   707,   707,    52,    52, -1500,
   -1500, 14415, 14415, 15276, 15276, -1500,   512, -1500, -1500,   268,
   -1500, -1500, -1500,   372, -1500, -1500,   397,   298, -1500, -1500,
     428,   533,   584, -1500,   429, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500,   901, -1500,  1049, 14702,  1041,
    9359, -1500, -1500, -1500,  1090,  1032,  1032,   901, -1500,   878,
    1032,   672, 15276,   308,   649,  1156, -1500, -1500,   902,   650,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500,    68,    87,   967,   552,  9359, -1500, 15276,  1092,   890,
    1032, -1500, -1500, -1500, -1500,  1037, 15276, -1500, 15276, -1500,
   14989,  1062, 14415,  1074,  9359,    -6,  1047,    32,   291,   945,
   -1500, -1500,   722,    55,  1090, 14415,  1077,  1103,  1019,  1004,
    1068,  1032,  1039,  1070,  1109,  1032,  9359,   -40, -1500, -1500,
   -1500,  1051, -1500, -1500, -1500, -1500,  1091,  9359,  9359,  1063,
   -1500,  1107,  1111,  5033, -1500,  1024,  1029,  1059, 15276, -1500,
   15276, -1500,  9359,  1073,  1031,  9359, -1500,  1093,   401,   423,
     434,  1181, -1500,    26, -1500,   446, -1500, -1500,  1188, -1500,
     762,  9359,  9359,  9359,   772,  9359,  9359,  9359,  9359,  9359,
    9359,  9359,  9359, 12397,  1101,  9359,  9359, -1500,  6578,  1064,
    1066,  1069,  1071,   857,   732,   983, -1500,   -38, -1500,   309,
     120,   594,   126,  6269,  6269,  6269,  1144, -1500,  9359,   733,
    1121, -1500, 15276,  1122, -1500, -1500,  9359,    48,   204,   614,
   -1500,   949,    71,   980,   971, -1500, -1500,   827, -1500,   984,
     658,  1075,  1076, 14702,  1082,  1083,  1084,  1085,  1086, -1500,
     632, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500,  1099, -1500, -1500, -1500,  9359, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,   647, -1500,
    1207,   805, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500,   961, -1500, -1500,  1215, -1500, -1500, -1500, -1500, -1500,
     709,  1216, -1500,   773, -1500, -1500, -1500,   931,   326,   935,
     537,   936,   937,   877,  1083,  1084,  1085, -1500,   632,   632,
    9977,   969,   943, -1500,  1090,    87,  1021,  1078,  5033,  1087,
    1095,  1105,  1096,  1100, 15276, -1500,   382, -1500, 15276, -1500,
    9359,  1110,  9359,  1129,  9359,     3,  1112,  9359,  1113, -1500,
    1143,  1146,  9359, 15276,   898,  1186, -1500, -1500, -1500, -1500,
   -1500, -1500, 14415, -1500,  5033,  1032,  1159, -1500, -1500, -1500,
    1032,  1159, -1500,  9359,  1127,  5033, 15276, -1500, -1500,  9359,
    9359,   766, -1500,     5,   780, -1500, 13554,   810, -1500,   831,
   -1500,  1094, -1500, -1500,  5033,  1102,  1104, -1500,  9359, -1500,
   -1500,  9359,  1097,  1107,  1171, -1500,  1147, -1500,   636, -1500,
   -1500,  1269, -1500, -1500,  5033, 15276, -1500,   663, -1500, -1500,
   -1500,  1098,  1048,  1054, -1500, -1500, -1500,  1058,  1065, -1500,
   -1500, -1500,  1197, -1500, -1500, -1500,  1081,   207, 15276,  1115,
   -1500, -1500,  9359,  9359,  9359,  4724,  6578, 11204,   983, -1500,
   11204, -1500,  1116,  1145,   331, -1500, -1500, -1500,  1121, -1500,
    1032, -1500,   880, -1500,   688,  1189, -1500,  9359,   591,  1061,
     542,  1118, -1500,    48,  1053, -1500, -1500,   -50, -1500,   -98,
       2,  1088,    48,   -98,  9668, -1500,   178, -1500, -1500, -1500,
   -1500, -1500, -1500,    48,  1130,  1022,   896,     2, -1500, -1500,
    1023,  1218, -1500, -1500, -1500, 12693,  1119,  1120,  1123,  1124,
    1126,  1128,  1131, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500,  1280,    72,  1287,    72,  1050,
    1191, -1500, -1500,  1151, 15276,  1114, -1500, -1500,  9977, -1500,
    1138, -1500, -1500, -1500, -1500, -1500, -1500,  9359,  1176, -1500,
   -1500,  9359, -1500,   578, -1500,  9359,  1177,  9359, -1500,  9359,
   15276, 15276, -1500,   756, -1500,  9359, -1500,  1200,  1201,  1232,
    1032,  1159, -1500,  9359,  1150, -1500, -1500, -1500,  1152, -1500,
      43,  9359,  5033,  1153,    60, -1500, 15276,  1155, 13841,   317,
   -1500, 14128,  1161, -1500, -1500,  1158, -1500, -1500, -1500, -1500,
    9359,   839,  1181, 15276,   694, -1500,  1164,  1181, 15276, -1500,
   -1500,  9359,  9359,  9359,  9359,  1043,  9359,  9359, -1500,  9359,
     468,   470,   491,   216, -1500, -1500,  9359, -1500, -1500, -1500,
    1189, -1500, -1500, -1500,  1032,  9359, -1500,  1187, -1500, -1500,
   -1500, -1500,  1168,  9668, -1500, -1500, -1500, -1500, -1500,   619,
    9668,  9668,   570, -1500,   980, -1500,   183, -1500,   971,    48,
    1202, -1500, -1500,  1125, -1500, -1500, -1500, -1500,  1262,  1172,
   -1500,   493, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
     301,   301, -1500,    72, -1500, -1500,   530, -1500,  1333,     2,
    1267,  1179,  9977,    11,  1132,  1194, -1500, -1500,  9359, -1500,
    9359,  1220, -1500,  9359, -1500, -1500, -1500,  1316, -1500, -1500,
    6578,  9359,  1032, -1500, -1500, -1500,  9359,  9359, -1500, -1500,
   -1500,  6578,  6578,  1278,  5033, 15276,  1190, 15276,  9359, 15276,
    1192,  6578, -1500,   380,    24,  1181, 15276, -1500,  1193,  1181,
   -1500, -1500, -1500, -1500,  9359, -1500, -1500, -1500,  1180,  1107,
    1111,  9359, -1500, -1500, -1500, -1500,  1276,  9359, -1500,   707,
    9668,  9668,    40,   566, -1500, -1500, -1500, -1500, -1500, -1500,
    9359, -1500, 14415, -1500, 14415,  1279, -1500, -1500, -1500,  1354,
   -1500, -1500, -1500,  1133,  1277, -1500, -1500,  1281, -1500,   277,
   15276,  1268,  1166, 15276,  9977, -1500, -1500,  9359, -1500,  1273,
   -1500, -1500,  1159, -1500, -1500, 14415, -1500, -1500,  1298,  9359,
    1212, -1500,  1305,  6578, -1500, 15276,   559,   340, -1500,  1204,
    1181, -1500,  1209, -1500,  6578,   840,   569, -1500,  1276,    40,
      40,  9668,   576, -1500, -1500, 14415, -1500, -1500,  1267,  9977,
   -1500,  1189,  1134, 15276,  1285,  1183,  1281, -1500, 15276,  1224,
   14415,  5033, 14415,  1226, -1500, -1500,  1320,   585, -1500, -1500,
   -1500, -1500,  1231,   749, -1500, -1500, -1500,  1219, -1500,  1299,
   -1500, -1500,    40, -1500, -1500, -1500, -1500, -1500,  9359,  1135,
   15276,  1301, -1500,  5033,  1230, -1500, -1500,  1234,  9359, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, 15276, -1500,  1137,  1136,
   15276, -1500, -1500,  9359,  6578,  1235,  1139,  9359,  1140,  6578,
    9977, -1500,  9977, -1500,  1227,  1141, 15276,  1206,  1306, 15276,
    1142,  9977, -1500
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       163,   456,   457,   458,   166,   166,   166,   805,  1010,   118,
     120,   612,   897,   906,   846,   810,   808,   790,   898,   901,
     853,   814,   791,   792,     0,   907,   794,   904,   875,   855,
     830,   850,   851,   902,   899,   849,   796,   905,   797,   798,
     946,   958,   945,   847,   866,   860,   799,   848,   801,   800,
     947,   884,   885,   852,   827,   968,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   978,   992,   999,   874,   870,
     861,   841,   789,     0,   869,   877,   886,   993,   865,   482,
     842,   843,   900,   994,  1000,   862,   879,     0,   488,   445,
     484,   872,   807,   863,   864,   893,   867,   883,   892,   998,
    1001,   813,   854,   895,   483,   882,   888,   793,     0,     0,
       0,     0,   393,   880,   891,   896,   894,   873,   859,   948,
     857,   858,   995,     0,   392,     0,   996,  1002,   889,   844,
     868,   997,   423,     0,   455,   890,   871,   878,   887,   881,
     949,   835,   840,   839,   838,   837,   836,   802,   856,     0,
     806,   903,   828,   937,   936,   938,   812,   811,   831,   943,
     795,   935,   940,   941,   932,   834,   876,   934,   944,   942,
     933,   832,   939,   953,   954,   951,   952,   950,   803,   955,
     956,   957,   923,   922,   909,   826,   819,   916,   912,   829,
     825,   924,   925,   815,   816,   809,   818,   921,   920,   917,
     913,   930,   931,   929,   919,   915,   908,   817,   928,   927,
     821,   823,   822,   914,   918,   910,   824,   911,   820,   926,
     979,   980,   981,   982,   983,   984,   960,   961,   959,   965,
     966,   967,   962,   963,   964,   833,   985,   986,   987,   988,
     989,   990,   991,     0,     0,  1003,  1004,  1005,  1008,  1007,
    1006,  1009,   163,   163,     0,     2,   163,     7,     9,    21,
       0,    26,    29,    34,    35,    36,    37,    38,    39,    40,
      30,    56,    57,    31,    32,     0,    74,    77,    78,    33,
      79,    80,     0,   116,    81,    82,    83,    84,    16,   160,
     161,   162,   169,   171,   475,   172,     0,   173,   174,   175,
     176,   177,   178,   179,   182,   167,   208,   215,   210,   242,
     248,     0,   240,   241,   217,   211,   181,   212,   180,   213,
     216,   346,   348,   350,   360,   362,   366,   368,   371,   376,
     379,   382,   384,   386,   388,     0,   390,   396,   398,     0,
     414,   397,   419,   422,   424,   427,   429,     0,   434,   431,
       0,   442,   452,   454,   428,   459,   466,   480,   467,   468,
     469,   472,   473,   470,   471,   495,   497,   498,   499,   496,
     544,   545,   546,   547,   548,   549,   451,   586,   578,   585,
     584,   583,   580,   582,   579,   581,   481,   474,   613,   614,
      41,   218,   219,   221,   220,   222,   214,   477,   478,   479,
     476,   224,   227,   223,   225,   226,   453,   788,   804,   897,
     906,   904,   806,     0,   164,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   270,   271,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     447,   450,   437,     0,     0,   790,   814,   792,   845,   907,
     794,   855,   796,   866,   799,   801,   800,   884,   992,   999,
     789,   993,   843,   994,  1000,   867,   998,  1001,   948,   995,
     996,  1002,   997,   949,   943,   935,   941,   932,   832,   953,
     954,   951,   803,   955,  1004,   443,   453,   788,   435,     0,
     189,   436,   439,   790,   791,   792,   796,   797,   798,   799,
     789,   795,   485,     0,   441,   440,   184,     0,     0,   208,
       0,   794,   801,   800,     0,   166,   764,   955,     0,   215,
       0,   486,     0,   511,     0,   446,   786,     0,   787,   417,
     418,     0,   449,   448,   438,   421,     0,     0,   540,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   766,
       0,   768,     0,     0,   163,     3,     4,     1,     8,    10,
       0,     0,     0,     0,     0,   163,   163,   163,   163,     0,
     117,   170,   168,     0,   187,     0,   196,     0,     0,     0,
       0,     0,     0,     0,     0,   201,   228,   247,   243,   249,
     244,   246,   245,     0,     0,     0,   407,     0,     0,   405,
       0,   355,     0,   406,   399,   404,   403,   402,   401,   400,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
     394,   391,     0,   415,   420,     0,     0,     0,   430,   463,
     433,   432,   444,     0,   460,     0,     0,   551,   553,   557,
       0,   122,     0,   785,    45,    42,    43,    46,    47,     0,
       0,     0,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   623,   624,   625,     0,   101,
     140,     0,     0,   110,     0,     0,     0,     0,   125,     0,
       0,     0,   592,     0,     0,     0,   588,     0,     0,     0,
     602,     0,     0,   251,   253,     0,   230,   231,   250,     0,
       0,     0,   132,     0,   136,   166,   616,     0,    58,     0,
      67,     0,     0,     0,    59,     0,     0,     0,     0,     0,
       0,   593,     0,     0,     0,     0,   319,     0,     0,   591,
       0,     0,     0,   610,     0,     0,     0,     0,   596,     0,
       0,   191,     0,     0,   185,   183,     0,     0,   770,     0,
       0,     0,   485,     0,   765,     0,   487,   512,   511,   508,
       0,     0,   542,   541,   416,     0,   539,     0,   636,   637,
     790,   792,   796,   799,   789,   776,     0,   587,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   642,     0,   199,
     200,     0,     0,     0,     0,     0,   204,   205,   767,   769,
       0,     5,    22,     0,    23,     0,     6,    27,     0,    13,
      28,     0,    17,   897,    75,    14,    76,    18,   190,   188,
     209,     0,     0,     0,     0,   202,   229,   288,   347,   349,
     353,   359,   358,   357,     0,   354,   351,   352,     0,   363,
     370,   369,   367,   373,   374,   375,   372,   377,   378,   381,
     380,     0,     0,     0,     0,   412,     0,   425,   426,     0,
     464,   461,   493,     0,   615,   491,     0,     0,   119,   121,
       0,     0,     0,   100,     0,    90,    92,    93,    94,    95,
      97,    98,    99,    91,    96,    86,    87,     0,     0,   106,
       0,   102,   104,   105,   112,     0,     0,    85,    44,     0,
       0,     0,     0,     0,     0,     0,   714,   719,     0,     0,
     715,   749,   702,   704,   705,   706,   708,   710,   709,   707,
     711,     0,     0,     0,     0,     0,   109,     0,   142,     0,
       0,   556,   550,   589,   590,     0,     0,   606,     0,   603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     232,   233,     0,   238,   138,     0,     0,   133,     0,     0,
       0,     0,     0,     0,    60,     0,     0,     0,   269,   275,
     272,     0,   595,   594,   601,   609,     0,     0,     0,     0,
     555,     0,     0,     0,   408,     0,     0,     0,     0,   599,
       0,   597,     0,   192,     0,     0,   771,     0,     0,     0,
       0,   511,   509,     0,   500,     0,   489,   490,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   197,     0,   794,
     801,   800,   955,     0,     0,     0,   650,     0,   206,     0,
       0,     0,     0,   163,   163,   163,     0,   239,     0,   303,
     299,   301,     0,   289,   290,   356,     0,     0,     0,     0,
     680,   364,   653,   657,   659,   661,   663,   666,   673,   674,
     682,   907,   793,     0,   802,  1008,  1007,  1006,  1009,   383,
     562,   568,   569,   572,   617,   618,   573,   574,   779,   780,
     781,   577,   385,   387,   559,   389,   413,   465,     0,   462,
     492,   123,    54,    55,    52,    53,   129,   128,     0,    88,
       0,     0,   107,   108,   113,    72,    73,    50,    51,    71,
     720,     0,   723,   750,     0,   713,   712,   717,   716,   748,
       0,     0,   725,     0,   721,   724,   703,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   141,   144,   146,
       0,     0,     0,   111,   114,     0,     0,     0,   166,     0,
       0,   610,     0,     0,     0,   255,     0,   561,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,     0,     0,     0,   282,     0,   279,   284,   237,   139,
     134,   137,     0,   186,     0,     0,    69,    63,    66,    65,
       0,    61,   273,     0,     0,   166,     0,   317,   321,     0,
       0,     0,   324,     0,     0,   330,     0,     0,   337,     0,
     341,     0,   410,   409,   166,     0,     0,   193,     0,   195,
     318,     0,     0,     0,     0,   512,     0,   501,     0,   535,
     532,     0,   536,   537,     0,     0,   531,     0,   506,   534,
     533,     0,     0,     0,   629,   630,   626,     0,     0,   634,
     635,   631,   773,   640,   777,   638,     0,     0,     0,     0,
     644,   198,     0,     0,     0,     0,     0,     0,   645,   646,
       0,   207,     0,    24,     0,    15,    19,    20,   300,   312,
       0,   313,     0,   304,   305,   306,   307,     0,   292,     0,
       0,     0,   664,   677,     0,   361,   365,     0,   696,     0,
       0,     0,     0,     0,     0,   652,   654,   655,   691,   692,
     693,   695,   694,     0,     0,   668,   667,     0,   671,   675,
     689,   687,   686,   679,   683,     0,     0,     0,     0,     0,
       0,     0,     0,   565,   567,   566,   563,   560,   494,   131,
     130,    89,   103,   737,   718,     0,   742,     0,   742,   731,
     726,   145,   147,     0,     0,     0,   115,   143,     0,    25,
       0,   607,   608,   611,   604,   605,   254,     0,     0,   268,
     260,     0,   264,     0,   258,     0,     0,     0,   277,     0,
       0,     0,   236,   280,   283,     0,   135,     0,     0,    68,
       0,    62,   274,     0,     0,   320,   322,   327,     0,   325,
       0,     0,     0,     0,     0,   331,     0,     0,     0,     0,
     338,     0,     0,   342,   411,     0,   600,   598,   194,   772,
       0,     0,   511,     0,     0,   543,     0,   511,     0,   507,
      12,     0,     0,     0,     0,     0,     0,     0,   643,     0,
       0,     0,     0,     0,   647,   651,     0,   316,   314,   315,
     308,   309,   310,   302,     0,     0,   297,     0,   291,   681,
     672,   678,     0,     0,   751,   752,   762,   761,   760,     0,
       0,     0,     0,   753,   658,   759,     0,   656,   660,     0,
       0,   665,   669,     0,   690,   685,   688,   684,     0,     0,
     575,     0,   570,   622,   564,   783,   784,   782,   571,   738,
       0,     0,   736,   743,   744,   740,     0,   735,     0,   733,
       0,     0,     0,     0,     0,     0,   552,   257,     0,   266,
       0,     0,   262,     0,   265,   278,   286,   287,   281,   235,
       0,     0,     0,    64,   276,   558,     0,     0,   328,   332,
     326,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   554,     0,     0,   511,     0,   538,     0,   511,
     627,   628,   632,   633,     0,   639,   778,   641,     0,     0,
       0,     0,   648,   775,   311,   298,   293,     0,   676,   763,
       0,     0,   755,     0,   701,   700,   699,   698,   697,   662,
       0,   754,     0,   619,     0,     0,   747,   746,   745,     0,
     739,   732,   730,     0,   727,   728,   722,   148,   150,   152,
       0,     0,     0,     0,     0,   261,   259,     0,   267,     0,
     203,   345,    70,   323,   329,     0,   343,   339,     0,     0,
       0,   333,     0,     0,   335,     0,   521,   515,   510,     0,
     511,   502,     0,   774,     0,     0,     0,   296,   294,   757,
     756,     0,     0,   620,   576,     0,   741,   734,     0,     0,
     154,   153,     0,     0,     0,     0,   149,   263,     0,     0,
       0,     0,     0,     0,   529,   523,     0,   522,   524,   530,
     527,   517,     0,   516,   518,   528,   504,     0,   503,     0,
     649,   295,   758,   670,   621,   729,   151,   155,     0,     0,
       0,     0,   285,     0,     0,   336,   334,     0,     0,   514,
     525,   526,   513,   519,   520,   505,     0,   156,     0,     0,
       0,   344,   340,     0,     0,     0,     0,     0,     0,     0,
       0,   158,     0,   157,     0,     0,     0,     0,     0,     0,
       0,     0,   159
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1500, -1500,  -224,  -191, -1500,  1170,  1175, -1500,  1173,  -550,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1010, -1500, -1500, -1500, -1500,  -220,  -572, -1500,   713,   -61,
   -1500, -1500, -1500, -1500, -1500,   264,   487, -1500, -1500,    -3,
    -188,  1038, -1500,   998, -1500, -1500,  -637, -1500,   425, -1500,
     227, -1500,  -241,  -283, -1500,  -558, -1500,    16,    81,    67,
    -281,  -168, -1500,  -884, -1500, -1500,   -83, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500,   592,   -81,  1237,
       0, -1500, -1500, -1500, -1500,   436, -1500, -1500,  -292, -1500,
       8, -1500,   996,  -937,  -724,  -711, -1500, -1500,   675, -1500,
   -1500,    -2,   208, -1500, -1500, -1500,    97, -1499, -1500,   350,
     102, -1500, -1500,   101, -1305, -1500,   920,   195, -1500, -1500,
     191, -1009, -1500, -1500,   190, -1500, -1500, -1251, -1244, -1500,
     186, -1500, -1500,   824,   822, -1500,  -557,   808, -1500, -1500,
    -659,   346,  -644,   347,   348, -1500, -1500, -1500, -1500, -1500,
    1148, -1500, -1500, -1500, -1500,  -863,  -321, -1146, -1500,  -106,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500,   -26,  -803, -1500,
    -548,   655,   306, -1500,  -417, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500,   774, -1500, -1028, -1500,   171, -1500,   656,  -802,
   -1500, -1500, -1500, -1500, -1500,  -280,  -272, -1174,  -812, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,   563,
    -745,  -726,  -185,  -818, -1500,   112,  -828, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500,  1035,  1042,  -163,   478,   311, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500,   156, -1500, -1500,   140, -1500,   148, -1063,
   -1500, -1500, -1500,   114,   104,   -59,   370, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
     115, -1500, -1500, -1500,   -53,   367,   514, -1500, -1500, -1500,
   -1500, -1500,   303, -1500, -1500, -1480, -1500, -1500, -1500,  -543,
   -1500,    79, -1500,   -75, -1500, -1500, -1500, -1500, -1298, -1500,
     127, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500,  -913, -1500, -1500, -1500,  -382,  -362,   -70,   925,
   -1500
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   254,   865,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
    1256,   773,   272,   273,   274,   275,   276,   277,   945,   946,
     947,   278,   279,   280,   951,   952,   953,   281,   438,   282,
     283,   700,   284,   440,   441,   442,   457,   763,   764,   285,
    1207,   286,  1677,  1678,   287,   288,   289,   547,   290,   291,
     292,   293,   294,   766,   295,   296,   530,   297,   298,   299,
     300,   301,   302,   635,   303,   304,   856,   857,   305,   306,
     559,   308,   636,   455,  1012,  1013,   309,   637,   310,   639,
     560,   312,   753,   754,  1244,   464,   313,   465,   466,   760,
    1245,  1246,  1247,   640,   641,  1113,  1114,  1526,   642,  1110,
    1111,  1353,  1354,  1355,  1356,   314,   785,   786,   315,  1271,
    1272,  1470,   316,  1274,  1275,   317,   318,  1277,  1278,  1279,
    1280,   319,   320,   321,   322,   894,   323,   324,  1365,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   660,   661,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   694,   689,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   923,   364,   365,   366,  1307,   818,   819,   820,
    1708,  1752,  1753,  1746,  1747,  1754,  1748,  1308,  1309,   367,
     368,  1310,   369,   370,   371,   372,   373,   374,   375,  1153,
    1007,  1139,  1406,  1140,  1561,  1141,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   792,  1220,   386,   387,
     388,   389,  1143,  1144,  1145,  1146,   390,   391,   392,   393,
     394,   395,   846,   847,   396,  1338,  1339,  1642,  1097,  1121,
    1375,  1376,  1122,  1123,  1124,  1125,  1126,  1385,  1551,  1552,
    1127,  1388,  1128,  1532,  1129,  1130,  1393,  1394,  1557,  1555,
    1377,  1378,  1379,  1380,  1657,   729,   972,   973,   974,   975,
     976,   977,  1194,  1581,  1674,  1195,  1579,  1672,   978,  1418,
    1576,  1572,  1573,  1574,   979,   980,  1381,  1389,  1542,  1382,
    1538,  1366,   397,   398,   399,   400,   550,   401,   402,   403,
     404,   405,  1147,  1148,  1149,  1150,  1257,   567,   406,   407,
     408
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -846;
  const short int
  xquery_parser::yytable_[] =
  {
       307,   701,   701,   526,   307,   307,   307,   902,   311,   439,
     621,   598,   311,   311,   311,  1261,  1063,   542,   683,   638,
     413,   416,   417,   903,   904,   905,   906,   575,   558,   562,
    1027,  1005,  1273,  1480,   835,  1119,   616,  1306,   704,   613,
     842,   563,  1039,  1491,  1006,   874,   876,   525,  1167,  1521,
    1522,   618,  1096,   568,  1361,   571,  1053,   869,   872,   875,
     877,   605,   606,  1225,  1423,   867,   870,  1001,  1233,  1209,
     724,   415,   415,   415,   932,     9,    10,    11,   770,   774,
     625,   739,   822,  1142,  1142,   414,   414,   414,   890,  1553,
     891,   892,   625,   893,   620,   895,   424,   614,  1539,   614,
    1675,   614,  1263,   896,   897,  1471,   782,  1070,   307,   614,
    1009,   703,   614,   703,  1084,  1335,   311,  1706,   614,   462,
    1142,   614,   961,   427,   962,  1002,  1197,  1003,  1003,  1680,
    1171,  1198,   744,  1499,   621,   580,   577,   581,   584,   589,
     585,  1230,  1036,  1471,   590,   587,  1199,  1717,  1200,   745,
    1445,   761,     9,    10,  1208,  1064,  1297,  1201,    79,  1068,
    1471,   735,   600,   602,  1002,   625,  1534,  1367,   963,  1536,
     459,  1340,    90,   424,  1142,   548,  1537,   418,  1004,  1234,
     460,   713,   425,   610,  1202,   476,  1152,  1142,   673,   414,
     682,  1472,     9,    10,   744,   771,   709,   104,   664,   611,
     427,  1116,   674,  1535,  1117,   428,   461,  1707,  1570,  1174,
     622,   745,   710,   714,   125,  1644,   665,  1038,  1069,  1761,
     762,  1065,  1298,  1037,   582,   125,   623,   586,   591,  1607,
    1071,  1072,   463,    11,   588,  1681,   684,   429,   430,  1106,
    1368,  1085,   772,   814,   769,  1073,  1612,  1480,  1765,   823,
    1461,   620,   307,   307,  1119,  1119,   307,  1540,  1541,  1296,
     311,   311,   477,  1238,   311,  1474,   463,   621,   638,  1249,
    1306,  1010,  1571,   463,  1367,   463,  1227,   526,   619,  1306,
     526,  1673,  1585,  1235,  1410,   859,   615,  1436,   617,  1250,
     862,   307,   874,   876,  1231,   858,  1236,  1168,   864,   311,
    1531,  1103,  1209,   463,   463,  1142,  1118,  1105,  1011,   624,
    1343,  1203,   867,   870,    79,  1397,  1264,  1682,   964,   578,
    1499,   690,  1369,  1370,   692,  1371,   705,    11,    90,   478,
     479,   965,  1372,   966,   622,   736,   746,  1115,   625,   706,
     958,   664,  1373,   737,   967,   968,   969,  1368,   970,  1299,
     971,   927,   885,   104,  1374,   712,   807,  1116,   716,   665,
    1117,   687,   568,   693,  1036,   730,   731,   749,  1750,  1641,
     927,  1002,   443,   568,  1730,   625,   719,   767,   720,   752,
     755,   125,   996,  1350,   755,  1002,   779,  1208,   863,  1715,
     998,  1024,   775,   790,   791,   868,   871,  1415,   568,   783,
     784,   787,   797,  1204,  1205,  1206,   793,  1020,    79,   419,
    1023,  1016,   435,   861,   800,   307,   625,   625,   816,  1074,
     436,   625,    90,   311,  1142,  1340,  1767,   625,   437,  1369,
    1370,   928,  1371,   808,  1048,  1617,  1679,   722,  1237,  1050,
     625,   625,   446,  1507,   307,  1055,   307,   104,  1142,  1373,
     929,  1654,   311,  1157,   311,  1299,  1300,  1417,  1655,   801,
     621,  1374,   997,  1302,   480,  1303,  1306,   622,  1656,  1426,
     999,  1480,   307,   787,  1751,     9,    10,   307,  1003,  1158,
     311,  1120,   447,   821,   812,   311,   420,   421,   625,   422,
     423,  1017,  1080,  1304,  1342,   825,   424,  1019,  1705,   723,
    1119,  1041,  1438,  1618,  1158,   425,   426,  1042,   625,  1119,
    1161,   741,   836,   741,  1049,   852,   854,   995,   836,  1051,
    1119,  1088,   848,   427,  1446,   740,  1456,   743,   428,  1437,
     625,   874,   876,   874,  1096,  1327,   878,  1515,  1679,   741,
     879,   625,  1075,  1076,   741,  1345,  1346,  1347,   307,  1301,
    1477,   625,   687,   788,   693,   307,   311,  1077,   794,  1159,
     429,   430,   431,   311,  1744,  1031,  1618,  1142,  1299,  1302,
    1185,  1303,   621,  1175,  1176,   625,  1162,   625,  1179,   917,
     918,  1186,   625,  1679,  1160,   456,   625,   627,  1292,   458,
    1744,   628,  1692,  1163,  1299,  1101,   629,   307,   625,  1304,
    1664,   916,   625,   111,   307,   311,   919,   439,  1217,   432,
    1293,   611,   311,  1527,   630,   307,   307,   307,   307,   625,
     123,  1294,   415,   311,   311,   311,   311,   719,  1047,   720,
    1474,   420,   421,   307,   422,   423,   414,  1669,   685,   686,
    1305,   311,  1100,   627,  1104,  1299,  1300,   628,   954,   625,
    1142,   426,   629,  1142,  1803,  1638,  1804,  1639,   149,  1066,
     622,   721,   984,  1067,   853,  1812,   988,   989,   433,  1560,
     630,  1650,  1299,  1300,  1003,   450,   625,   451,  1640,  1095,
    1665,  1164,  1302,   625,  1303,  1002,  1119,   664,   722,  1008,
    1624,  1014,  1745,   469,   667,  1628,  1156,  1524,  1165,   568,
    1120,  1120,   568,  1299,  1300,   665,  1028,  1344,  1302,   434,
    1303,   470,  1304,   631,   948,  1546,   632,  1670,  1780,  1591,
    1002,  1166,   471,   668,   664,  1590,  1529,   666,  1058,  1059,
    1060,   633,   854,  1525,  1002,   435,   669,   765,  1304,  1301,
     452,   307,   665,   436,   474,   453,  1191,  1061,  1651,   311,
     723,   437,  1616,  1760,   432,  1620,   634,   949,  1299,  1302,
    1763,  1303,   950,  1192,  1721,   307,  1301,  1363,  1026,   631,
     670,   874,   632,   311,   627,  1240,  1403,  1750,   628,  1099,
    1241,  1018,  1052,   629,  1409,   526,  1302,   815,  1303,  1304,
     482,   125,   454,   111,  1350,   307,   307,  1301,   683,  1242,
     765,   630,   638,   311,   311,  1415,  1193,  1331,  1404,  1240,
     123,  1107,   634,   433,  1241,  1352,  1304,  1302,  1003,  1303,
     111,   483,  1416,  1709,   484,  1405,   733,  1712,  1349,   475,
    1493,   734,   415,  1219,  1142,  1222,  1142,   123,  1654,  1350,
    1243,  1151,  1151,  1151,  1151,  1655,   414,  1304,   149,  1351,
    1211,   111,  1003,  1093,   434,  1656,   481,  1498,   707,  1212,
    1352,  1094,   741,   741,   528,  1417,  1270,  1142,   123,  1191,
     439,   708,  1302,  1459,  1303,   149,  1045,  1046,  1151,  1468,
    1270,  1652,  1653,  1783,  1169,  1285,  1192,  1286,  1626,  1649,
     645,   531,  1184,  1473,  1749,  1755,  1169,  1142,   646,   647,
     631,   648,  1304,   632,  1390,  1391,   149,   671,  1757,   649,
    1478,  1187,  1142,   650,  1142,   651,   672,  1214,  1336,   687,
     652,   693,  1188,  1479,   598,   529,  1221,  1392,  1221,  1341,
     755,  1481,  1151,   532,  1731,  1749,  1723,   653,  1724,  1478,
    1478,  1755,   949,   634,  1482,  1151,  1120,   950,  1180,  1181,
    1182,  1240,  1623,  1759,  1183,  1120,  1241,   725,   726,   727,
     654,   655,   656,   657,   658,   659,  1120,   444,  1517,  1739,
     445,   448,   467,  1457,   449,   468,   472,   543,   793,   473,
     793,   935,   936,   937,   938,   939,   940,   941,   942,   943,
     944,  1719,  1720,  1312,   920,  1313,   544,   920,   527,  1764,
     920,   688,   564,  1317,   691,  1318,  1177,  1178,  1518,  1519,
     900,   901,   527,   836,  1774,   545,  1777,   565,   907,   908,
     576,   909,   910,  1421,  1422,  1154,  1154,  1666,  1667,   572,
     573,   574,   579,   583,   592,  1360,   527,   593,   594,   596,
     595,   597,  1358,   307,   603,   607,   625,   626,   527,   643,
     527,   311,   644,   663,   662,   885,   675,   676,   677,   687,
     678,   703,  1762,  1151,   695,   697,   696,   715,   698,   699,
     717,   718,   728,   732,   742,   756,   757,   759,  1603,   765,
     768,   776,   777,   778,   789,   795,   796,   445,  1093,   802,
     449,   468,   473,   484,   806,   804,  1094,   809,   810,   439,
     811,   813,   817,   307,   307,   307,   824,   826,   837,   827,
     741,   311,   311,   311,   849,   855,   844,   850,   845,   860,
     866,   881,   883,   882,  1281,   898,   884,   912,   913,   911,
     914,   924,  1120,   930,   931,   933,   959,   955,   956,   960,
     982,   981,  1645,   983,   985,   990,   987,  1000,   991,   993,
     992,  1015,  1021,  1022,   755,   994,  1025,  1032,  1439,  1033,
    1078,  1034,  1035,  1040,  1043,  1044,  1079,   444,   448,   467,
     472,   483,  1086,  1453,  1081,  1082,  1083,  1087,  1102,  1112,
    1108,  1170,  1151,   950,  1002,  1189,  1215,  1190,  1216,  1226,
    1218,  1609,  1228,  1210,  1232,   761,   787,  1252,  1239,  1258,
    1255,  1254,  1259,  1253,  1265,  1260,  1151,  1270,  1282,  1266,
    1269,  1276,  1284,  1283,  1291,  1288,  1295,  1311,   307,  1328,
    1332,  1289,  1333,   721,  1335,  1334,   311,  1337,  1357,  1359,
    1384,  1395,  1396,  1364,  1430,  1497,    11,  1383,  1398,  1399,
    1400,  1401,  1402,  1407,  1414,  1419,  1413,  1428,  1425,  1433,
    1387,  1510,  1511,  1512,   307,  1424,  1443,  1441,   848,  1447,
    1449,  1450,   311,  1455,  1451,   307,  1460,   526,  1429,  1463,
     526,  1478,   527,   311,  1431,   527,  1495,  1549,  1484,  1492,
    1501,  1464,  1432,  1434,   307,   415,  1502,  1435,  1500,  1486,
    1503,  1487,   311,  1505,  1490,  1350,  1556,  1504,  1580,   414,
    1485,  1509,  1533,  1550,   307,  1530,  1562,  1563,  1554,  1569,
    1564,  1565,   311,  1566,  1516,  1567,  1575,  1506,  1568,  1690,
    1578,  1582,  1586,  1588,  1593,  1151,  1600,  1601,  1602,  1647,
    1694,  1609,   415,  1696,  1605,  1093,  1093,  1543,  1606,  1611,
    1704,  1614,  1622,  1094,  1094,   549,   414,  1621,  1627,   711,
     527,   415,  1648,   527,  1583,  1660,  1662,   527,  1634,  1663,
     527,   527,  1671,  1191,  1684,   414,  1676,  1687,   527,  1689,
    1584,   741,  1695,  1725,   527,   527,  1699,  1714,  1703,   527,
    1596,  1597,  1524,  1726,  1728,  1496,  1733,   527,  1729,  1711,
    1734,  1738,  1740,   527,   527,   527,   527,  1727,  1741,  1742,
    1756,   527,   853,  1770,  1661,  1758,  1613,  1771,  1151,   527,
    1773,  1151,  1778,  1779,  1782,  1785,  1793,  1786,  1683,  1790,
    1794,  1799,  1696,  1625,  1809,  1805,   608,  1806,  1629,  1796,
    1808,   609,   612,  1457,   957,  1412,  1172,   738,  1768,  1788,
    1797,  1251,  1427,  1736,  1800,  1802,  1766,  1811,  1098,  1248,
     758,  1598,  1454,  1030,   527,  1520,  1528,   702,  1348,  1523,
    1775,  1465,  1469,   803,  1475,  1483,   889,   888,   527,  1494,
     926,   899,   307,  1784,  1062,  1781,  1223,  1155,  1514,   527,
     311,  1411,   747,   681,  1508,  1513,  1544,  1548,  1362,   748,
    1659,  1547,  1791,  1658,  1386,  1196,  1420,  1577,  1668,     0,
    1545,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1791,     0,     0,     0,   527,  1775,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1698,     0,  1700,     0,  1702,
       0,     0,     0,     0,     0,     0,  1710,     0,     0,     0,
    1716,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1722,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1151,     0,  1151,     0,     0,     0,     0,     0,
    1093,     0,     0,     0,     0,     0,     0,     0,  1094,     0,
    1732,  1093,  1093,  1735,   307,     0,     0,     0,     0,  1094,
    1094,  1093,   311,     0,     0,  1151,     0,     0,     0,  1094,
       0,     0,     0,     0,     0,  1743,     0,     0,     0,     0,
     934,     0,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1151,     0,   527,     0,     0,
       0,   527,   527,  1769,     0,     0,     0,     0,  1772,     0,
    1151,     0,  1151,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   527,     0,   527,     0,     0,     0,
       0,     0,     0,     0,   527,     0,     0,   527,     0,     0,
    1789,   527,     0,  1093,     0,     0,     0,     0,     0,     0,
       0,  1094,     0,     0,  1093,     0,  1795,     0,     0,     0,
    1798,     0,  1094,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1807,     0,     0,  1810,
       0,   307,   527,     0,     0,     0,     0,     0,     0,   311,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   307,     0,     0,     0,     0,     0,     0,
     527,   311,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   549,     0,  1093,     0,     0,     0,     0,  1093,
       0,     0,  1094,     0,     0,     0,   527,  1094,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   828,   829,     0,
       0,   838,   839,   840,   841,     0,   843,     0,     0,     0,
       0,     0,   851,     0,     0,     0,   527,   527,   527,   527,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   880,     0,     0,     0,     0,     0,     0,     0,
     886,   887,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   527,     0,     0,     0,     0,     0,     0,     0,
       0,   527,     0,   527,     0,   527,     0,   527,     0,     0,
     922,     0,     0,   922,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   986,     0,   527,     0,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1029,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,  1054,
       0,     0,     0,  1056,  1057,     0,     0,     0,     0,     0,
       0,     0,   886,     0,     0,     0,     0,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,     0,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1173,     0,     0,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1213,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1229,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,   527,  1262,     0,   527,     0,     0,     0,     0,
       0,     0,     0,     0,  1267,  1268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1287,
       0,     0,  1290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1314,  1315,
    1316,     0,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,
     527,     0,  1329,  1330,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1109,     0,     0,     0,   527,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1408,     0,     0,     0,     0,
       0,   527,     0,   527,     0,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   527,     0,
       0,     0,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1440,     0,  1442,
       0,  1444,     0,     0,  1448,     0,     0,     0,     0,  1452,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1458,     0,     0,     0,     0,     0,     0,     0,     0,
    1462,     0,     0,     0,     0,     0,  1466,  1467,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1488,     0,     0,  1489,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,   527,     0,   527,     0,     0,     0,     0,     0,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,   527,
       0,     0,     0,     0,  1109,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     527,     0,     0,     0,     0,     0,     0,     0,   527,     0,
       0,     0,     0,   527,     0,   527,     0,   527,     0,     0,
       0,     0,     0,     0,  1587,     0,     0,     0,  1589,     0,
       0,     0,  1592,     0,  1594,     0,  1595,     0,     0,     0,
       0,     0,  1599,     0,     0,   527,     0,     0,     0,     0,
    1604,     0,     0,     0,     0,     0,     0,     0,  1608,  1610,
       0,   527,     0,     0,     0,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1458,     0,     0,
       0,   527,     0,     0,   527,     0,     0,     0,  1630,  1631,
    1632,  1633,     0,  1635,  1636,     0,  1637,     0,     0,     0,
       0,     0,     0,  1643,     0,     0,     0,     0,     0,     0,
       0,     0,  1646,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1685,     0,  1686,     0,     0,
    1688,     0,     0,     0,     0,     0,     0,     0,  1691,     0,
       0,     0,     0,  1693,  1610,     0,     0,     0,     0,     0,
       0,  1697,     0,     0,     0,  1701,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1713,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1718,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -845,   450,     0,   451,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1737,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1697,  -845,     0,     0,
       0,  -845,     0,     0,     0,  -845,  -845,     0,     0,     0,
    -845,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   452,     0,     0,  -845,     0,   453,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1776,     0,
       0,     0,     0,     0,     0,     0,     0,  -845,     0,  -845,
    -845,  -845,     0,     0,  -845,  -845,  -845,  -845,     0,     0,
       0,  -845,  -845,     0,     0,  1787,     0,     0,  -845,     0,
    1792,  -845,  -845,   454,     0,  1776,  -845,     0,     0,     0,
       0,  -845,  -845,     0,     0,     0,     0,  -845,     0,     0,
    1792,  -845,     0,     0,  1801,  -845,  -845,     0,  -845,     0,
    -845,  -845,     0,     0,     0,  -845,  -845,     0,     0,  -845,
    -845,  -845,  -845,  -845,  -845,     0,     0,  -845,     0,     0,
       0,     0,  -845,  -845,     0,     0,  -845,     0,     0,     0,
       0,  -845,     0,     0,  -845,     0,     0,     0,     0,  -845,
    -845,  -845,  -845,  -845,     0,  -845,  -845,  -845,  -845,     0,
       0,     0,     0,  -845,  -845,  -845,     0,  -845,  -845,  -845,
    -845,  -845,  -845,     0,  -845,     0,  -845,     0,     0,     0,
       0,  -845,  -845,  -845,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -845,     0,  -845,
       0,  -845,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -845,     0,     0,     0,     0,  -845,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,  -845,     0,  -845,    12,    13,
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
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
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
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     0,   604,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     409,   410,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,   411,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     108,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,   546,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     9,    10,     0,    11,     0,     0,     0,   409,
     410,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,   411,    28,    29,    30,    31,
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
     805,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     9,    10,     0,    11,     0,     0,     0,   409,   410,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,  1089,   411,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,  1090,  1091,    50,
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
       0,   124,   125,     0,     0,   126,   127,   128,     0,   805,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,  1092,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       9,    10,     0,    11,     0,     0,     0,   409,   410,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,  1089,   411,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,  1090,  1091,    50,    51,
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
     124,   125,     0,     0,   126,   127,   128,     0,   546,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,  1092,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,   409,   410,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,   411,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   412,   151,   152,
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
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,   248,   249,
     250,   251,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     9,    10,     0,
      11,     0,     0,     0,    12,    13,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   412,   151,   152,   153,   154,
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
     251,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     9,    10,     0,    11,
       0,     0,     0,    12,   410,     0,    14,    15,    16,    17,
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
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   873,   410,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,   411,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   412,   151,   152,   153,   154,   155,   156,
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
       0,   409,   410,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,  1089,   411,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
    1090,  1091,    50,    51,    52,    53,    54,    55,    56,    57,
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
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,  1092,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     409,   410,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,   551,   411,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,   552,
     553,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   502,
      82,    83,    84,    85,    86,   554,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     555,   109,     0,   110,   111,   112,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,   124,   125,     0,     0,   126,   127,   128,
       0,     0,   556,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   519,   520,   521,   176,   177,   522,
     557,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   246,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   409,
     410,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   551,   411,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,   552,   553,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   502,    82,
      83,    84,    85,    86,   554,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,    96,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   555,
     109,     0,   110,   111,   112,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,   124,   125,     0,     0,   126,   127,   128,     0,
       0,     0,   129,   561,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   519,   520,   521,   176,   177,   522,   557,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     246,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   409,   410,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,   551,   411,    28,    29,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,     0,    45,    46,    47,   552,   553,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   502,    82,    83,
      84,    85,    86,   554,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,   105,   106,   107,   555,   109,
       0,   110,   111,   112,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,   124,   125,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,   132,   133,   134,     0,
     135,     0,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   519,   520,   521,   176,   177,   522,   557,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   599,   244,     0,   245,   246,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     6,     7,     8,
       0,     0,     0,    11,     0,     0,     0,   409,   410,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,   551,   411,    28,    29,    30,    31,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,     0,    45,    46,    47,   552,   553,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,     0,    69,    70,
      71,    72,    73,     0,    74,    75,    76,     0,     0,    77,
      78,     0,     0,     0,    79,    80,   502,    82,    83,    84,
      85,    86,   554,    88,    89,     0,     0,     0,    90,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,    96,
      97,    98,    99,   100,     0,     0,     0,     0,     0,     0,
     101,   102,   103,   104,   105,   106,   107,   555,   109,     0,
     110,   111,   112,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   119,   120,   121,   122,     0,   123,     0,
     124,   125,     0,     0,   126,   127,   128,     0,     0,     0,
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   519,   520,   521,   176,   177,   522,   557,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,   601,   245,   246,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     0,
       0,     0,    11,     0,     0,     0,   409,   410,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,   551,   411,    28,    29,    30,    31,     0,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,     0,    45,    46,    47,   552,   553,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     0,    69,    70,    71,
      72,    73,     0,    74,    75,    76,     0,     0,    77,    78,
       0,     0,     0,    79,    80,   502,    82,    83,    84,    85,
      86,   554,    88,    89,     0,     0,     0,    90,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,    96,    97,
      98,    99,   100,     0,     0,     0,     0,     0,     0,   101,
     102,   103,   104,   105,   106,   107,   555,   109,     0,   110,
     111,   112,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   119,   120,   121,   122,     0,   123,     0,   124,
     125,     0,     0,   126,   127,   128,     0,   915,     0,   129,
       0,   130,   131,     0,   132,   133,   134,     0,   135,     0,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,   147,   148,   149,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     519,   520,   521,   176,   177,   522,   557,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,     0,   244,     0,   245,   246,   247,   248,
     249,   250,   251,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     8,     0,     0,
       0,    11,     0,     0,     0,   409,   410,     0,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
     551,   411,    28,    29,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,    45,    46,    47,   552,   553,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   502,    82,    83,    84,    85,    86,
     554,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,    96,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   555,   109,     0,   110,   111,
     112,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   124,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,   921,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   412,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   519,
     520,   521,   176,   177,   522,   557,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   246,   247,   248,   249,
     250,   251,     1,     2,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     6,     7,     8,     0,     0,     0,
      11,     0,     0,     0,   409,   410,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,   551,
     411,    28,    29,    30,    31,     0,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     0,
      45,    46,    47,   552,   553,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     0,    69,    70,    71,    72,    73,
       0,    74,    75,    76,     0,     0,    77,    78,     0,     0,
       0,    79,    80,   502,    82,    83,    84,    85,    86,   554,
      88,    89,     0,     0,     0,    90,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,    96,    97,    98,    99,
     100,     0,     0,     0,     0,     0,     0,   101,   102,   103,
     104,   105,   106,   107,   555,   109,     0,   110,   111,   112,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     119,   120,   121,   122,     0,   123,     0,   124,   125,     0,
       0,   126,   127,   128,     0,     0,     0,   129,   925,   130,
     131,     0,   132,   133,   134,     0,   135,     0,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,   149,     0,   412,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   519,   520,
     521,   176,   177,   522,   557,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,     0,   244,     0,   245,   246,   247,   248,   249,   250,
     251,     1,     2,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     6,     7,     8,     0,     0,     0,    11,
       0,     0,     0,   409,   410,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   488,    25,   490,   411,
      28,   491,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,   493,     0,    45,
      46,    47,   495,   496,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     0,    69,    70,    71,    72,    73,     0,
      74,    75,    76,     0,     0,    77,    78,     0,     0,     0,
      79,    80,   502,    82,    83,    84,    85,    86,   554,    88,
      89,     0,     0,     0,    90,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   505,    97,    98,    99,   100,
       0,     0,     0,     0,     0,     0,   101,   102,   103,   104,
     105,   106,   107,   555,   109,     0,   110,   111,   679,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   680,   125,     0,     0,
     126,   127,   128,     0,     0,     0,   129,     0,   130,   131,
       0,   132,   133,   134,     0,   135,     0,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,   149,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   514,   160,   515,   162,   516,   517,   165,
     166,   167,   168,   169,   170,   518,   172,   519,   520,   521,
     176,   177,   522,   523,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   524,   247,   248,   249,   250,   251,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   409,   410,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,   551,   411,    28,
      29,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,     0,    45,    46,
      47,   552,   553,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   502,    82,    83,    84,    85,    86,   554,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,    96,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   555,   109,     0,   110,   111,   112,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,   124,   125,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   412,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   519,   520,   521,   176,
     177,   522,   557,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   246,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   409,   410,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   488,    25,   490,   411,    28,   491,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   493,     0,    45,    46,    47,
     495,   496,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     502,    82,    83,    84,    85,    86,   554,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   505,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   555,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   514,   160,   515,   162,   516,   517,   165,   166,   167,
     168,   169,   170,   518,   172,   519,   520,   521,   176,   177,
     522,   523,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   524,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     409,   410,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   488,    25,   490,   411,    28,   491,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,   493,     0,    45,    46,    47,   495,
     496,    50,   497,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,    69,    70,    71,    72,    73,     0,    74,    75,    76,
       0,     0,    77,    78,     0,     0,     0,    79,    80,   502,
      82,    83,    84,    85,    86,   554,    88,    89,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   505,    97,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     555,   109,     0,   110,   111,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,     0,     0,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     514,   160,   515,   162,   516,   517,   165,   166,   167,   168,
     169,   170,   518,   172,   519,   520,   521,   176,   177,   522,
     523,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   524,   247,   248,   249,   250,   251,     1,     2,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     8,     0,     0,     0,    11,     0,     0,     0,   409,
     410,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   488,    25,   490,   411,    28,   491,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   493,     0,    45,    46,    47,   495,   496,
      50,   497,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     0,
      69,    70,    71,    72,    73,     0,    74,    75,    76,     0,
       0,    77,    78,     0,     0,     0,    79,    80,   502,    82,
      83,    84,    85,    86,   554,    88,    89,     0,     0,     0,
      90,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   505,    97,    98,    99,   100,     0,     0,     0,     0,
       0,     0,   101,   102,   103,   104,   105,   106,   107,   555,
     109,     0,   110,   111,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,   122,     0,
     123,     0,     0,     0,     0,     0,   126,   127,   128,     0,
       0,     0,   129,     0,   130,   131,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   514,
     160,   515,   162,   516,   517,   165,   166,   167,   168,   169,
     170,   518,   172,   519,   520,   521,   176,   177,   522,   523,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,     0,   244,     0,   245,
     524,   247,   248,   249,   250,   251,     1,     2,     0,     0,
       0,     0,     0,     0,     0,     3,     4,     5,     6,     7,
       8,     0,     0,     0,    11,     0,     0,     0,   409,   410,
       0,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,   488,    25,   490,   411,    28,   491,    30,    31,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,   493,     0,    45,    46,    47,   495,   496,    50,
     497,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,    69,
      70,    71,    72,    73,     0,    74,    75,    76,     0,     0,
      77,    78,     0,     0,     0,    79,    80,   502,    82,    83,
      84,    85,    86,   554,    88,    89,     0,     0,     0,    90,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     505,     0,    98,    99,   100,     0,     0,     0,     0,     0,
       0,   101,   102,   103,   104,     0,   106,   107,   555,   109,
       0,   110,   111,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,   122,     0,   123,
       0,     0,     0,     0,     0,   126,   127,   128,     0,     0,
       0,   129,     0,   130,   131,     0,     0,     0,   134,     0,
     135,     0,   136,     0,   138,     0,   140,   141,   142,   143,
     144,   145,   146,     0,     0,   147,   148,   149,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   514,   160,
     515,   162,   516,   517,   165,   166,   167,   168,   169,   170,
     518,   172,   519,   520,   521,   176,   177,   522,   523,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,     0,   244,     0,   245,   524,
     247,   248,   249,   250,   251,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     3,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   409,   410,     0,
      14,    15,    16,   485,    18,    19,    20,   486,    22,   487,
     488,   489,   490,   411,    28,   491,    30,    31,     0,    32,
      33,    34,    35,   492,    37,    38,    39,    40,    41,    42,
      43,   493,     0,    45,   494,    47,   495,   496,    50,   497,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   498,   499,    68,     0,    69,    70,
      71,   500,     0,     0,    74,    75,    76,     0,     0,   501,
      78,     0,     0,     0,     0,    80,   502,    82,   503,   504,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   505,
      97,    98,   506,   507,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   508,   120,   121,   509,     0,     0,     0,
       0,     0,     0,     0,   510,   511,   128,     0,     0,     0,
     129,     0,   130,   512,     0,     0,     0,   134,     0,   135,
       0,   136,   137,   138,   139,   513,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   514,   160,   515,
     162,   516,   517,   165,   166,   167,   168,   169,   170,   518,
     172,   519,   520,   521,   176,   177,   522,   523,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     1,     2,   245,   524,   247,
     248,   249,   250,   251,     3,     0,     0,     0,     7,     8,
       0,     0,     0,     0,     0,     0,     0,   409,   410,     0,
      14,    15,    16,   533,    18,    19,    20,   486,   534,   535,
     488,   489,   490,   411,    28,   491,    30,    31,     0,    32,
      33,    34,    35,   536,    37,   537,   538,    40,    41,    42,
      43,   493,     0,    45,   539,    47,   495,   496,    50,   497,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   498,   499,    68,     0,    69,    70,
      71,   540,     0,     0,    74,    75,    76,     0,     0,   501,
      78,     0,     0,     0,     0,    80,   502,    82,   503,   504,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   505,
      97,    98,   506,   507,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,   107,     0,     0,     0,
       0,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   508,   120,   121,   509,     0,     0,     0,
       0,     0,     0,     0,   510,   511,   128,     0,     0,     0,
     129,     0,   130,   512,     0,     0,     0,   134,     0,   135,
       0,   136,   137,   138,   139,   513,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,     0,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   514,   541,   515,
     162,   516,   517,   165,   166,   167,   168,   169,   170,   518,
     172,   519,   520,   521,   176,   177,   522,   523,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     0,   566,   245,   524,   247,
     248,   249,   250,   251,     7,     8,     0,     0,     0,   780,
       0,     0,     0,   409,   410,     0,    14,    15,    16,   533,
      18,    19,    20,   486,   534,   535,   488,   489,   490,   411,
      28,   491,    30,    31,     0,    32,    33,    34,    35,   536,
      37,   537,   538,    40,    41,    42,    43,   493,     0,    45,
     539,    47,   495,   496,    50,   497,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     498,   499,    68,     0,    69,    70,    71,   540,     0,     0,
      74,    75,    76,     0,     0,   501,    78,     0,     0,     0,
       0,    80,   502,    82,   503,   504,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   505,    97,    98,   506,   507,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   508,
     120,   121,   509,     0,     0,     0,     0,     0,     0,     0,
     510,   511,   128,     0,     0,     0,   129,   781,   130,   512,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   513,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   514,   541,   515,   162,   516,   517,   165,
     166,   167,   168,   169,   170,   518,   172,   519,   520,   521,
     176,   177,   522,   523,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     0,   566,   245,   524,   247,   248,   249,   250,   251,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   409,
     410,     0,    14,    15,    16,   533,    18,    19,    20,   486,
     534,   535,   488,   489,   490,   411,    28,   491,    30,    31,
       0,    32,    33,    34,    35,   536,    37,   537,   538,    40,
      41,    42,    43,   493,     0,    45,   539,    47,   495,   496,
      50,   497,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   498,   499,    68,     0,
      69,    70,    71,   540,     0,     0,    74,    75,    76,     0,
       0,   501,    78,     0,     0,     0,     0,    80,   502,    82,
     503,   504,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   505,    97,    98,   506,   507,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   508,   120,   121,   509,     0,
       0,     0,     0,     0,     0,     0,   510,   511,   128,     0,
       0,     0,   129,     0,   130,   512,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   513,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   514,
     541,   515,   162,   516,   517,   165,   166,   167,   168,   169,
     170,   518,   172,   519,   520,   521,   176,   177,   522,   523,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     0,     0,   245,
     524,   247,   248,   249,   250,   251,   569,   570,     0,     0,
       0,     0,     7,     8,     0,     0,     0,     0,     0,     0,
       0,   409,   410,     0,    14,    15,    16,   533,    18,    19,
      20,   486,   534,   535,   488,   489,   490,   411,    28,   491,
      30,    31,     0,    32,    33,    34,    35,   536,    37,   537,
     538,    40,    41,    42,    43,   493,     0,    45,   539,    47,
     495,   496,    50,   497,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   498,   499,
      68,     0,    69,    70,    71,   540,     0,     0,    74,    75,
      76,     0,     0,   501,    78,     0,     0,     0,     0,    80,
     502,    82,   503,   504,    85,    86,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   505,    97,    98,   506,   507,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
     107,     0,     0,     0,     0,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   508,   120,   121,
     509,     0,     0,     0,     0,     0,     0,     0,   510,   511,
     128,     0,     0,     0,   129,     0,   130,   512,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   513,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
       0,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   514,   541,   515,   162,   516,   517,   165,   166,   167,
     168,   169,   170,   518,   172,   519,   520,   521,   176,   177,
     522,   523,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     0,
       0,   245,   524,   247,   248,   249,   250,   251,     4,     5,
       6,     7,     8,     0,     0,     0,    11,     0,     0,     0,
     409,   410,     0,    14,    15,    16,   830,    18,    19,    20,
      21,   534,   831,   488,    25,   490,   411,    28,   491,    30,
      31,     0,    32,    33,    34,    35,   832,    37,   537,   538,
      40,    41,    42,    43,   493,     0,    45,   833,    47,   495,
     496,    50,   497,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   498,   499,    68,
       0,    69,    70,    71,   834,     0,     0,    74,    75,    76,
       0,     0,   501,    78,     0,     0,     0,    79,    80,   502,
      82,   503,   504,    85,    86,   554,    88,     0,     0,     0,
       0,    90,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   505,    97,    98,   506,   507,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,   106,   107,
     555,   109,     0,   110,   111,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   509,
       0,   123,     0,     0,     0,     0,     0,   510,   511,   128,
       0,     0,     0,   129,     0,   130,   512,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     514,   541,   515,   162,   516,   517,   165,   166,   167,   168,
     169,   170,   518,   172,   519,   520,   521,   176,   177,   522,
     523,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,     0,   244,     0,
     245,   524,   247,   248,   249,   250,   251,     7,     8,     0,
       0,     0,     0,     0,     0,     0,   409,   410,     0,    14,
      15,    16,   485,    18,    19,    20,   486,    22,   487,   488,
    1131,   490,   411,    28,   491,    30,    31,     0,    32,    33,
      34,    35,   492,    37,    38,    39,    40,    41,    42,    43,
     493,     0,    45,   494,    47,   495,   496,    50,   497,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   498,   499,    68,     0,    69,    70,    71,
     500,     0,     0,    74,    75,    76,     0,     0,   501,    78,
       0,     0,     0,     0,    80,   502,    82,   503,   504,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   505,    97,
      98,   506,   507,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1132,     0,     0,     0,  1133,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   508,   120,   121,   509,     0,     0,     0,     0,
       0,     0,     0,   510,   511,   128,     0,     0,     0,   129,
    1558,   130,   512,     0,     0,     0,  1559,     0,   135,     0,
     136,   137,   138,   139,   513,   141,   142,   143,   144,   145,
     146,     0,     0,  1134,   148,     0,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   514,   160,   515,   162,
     516,   517,   165,   166,   167,   168,   169,   170,   518,   172,
     519,   520,   521,   176,   177,   522,   523,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     7,     8,   245,   524,   247,  1135,
    1136,  1137,  1138,   409,   410,     0,    14,    15,    16,   533,
      18,    19,    20,   486,   534,   535,   488,   489,   490,   411,
      28,   491,    30,    31,     0,    32,    33,    34,    35,   536,
      37,   537,   538,    40,    41,    42,    43,   493,     0,    45,
     539,    47,   495,   496,    50,   497,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     498,   499,    68,     0,    69,    70,    71,   540,     0,     0,
      74,    75,    76,     0,     0,   501,    78,     0,     0,     0,
       0,    80,   502,    82,   503,   504,    85,    86,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   505,    97,    98,   506,   507,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,   107,     0,     0,     0,     0,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   508,
     120,   121,   509,     0,     0,     0,     0,     0,     0,     0,
     510,   511,   128,     0,     0,     0,   129,   750,   130,   512,
       0,     0,     0,   751,     0,   135,     0,   136,   137,   138,
     139,   513,   141,   142,   143,   144,   145,   146,     0,     0,
     147,   148,     0,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   514,   541,   515,   162,   516,   517,   165,
     166,   167,   168,   169,   170,   518,   172,   519,   520,   521,
     176,   177,   522,   523,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   524,   247,   248,   249,   250,   251,
     409,   410,     0,    14,    15,    16,   533,    18,    19,    20,
     486,   534,   535,   488,   489,   490,   411,    28,   491,    30,
      31,     0,    32,    33,    34,    35,   536,    37,   537,   538,
      40,    41,    42,    43,   493,     0,    45,   539,    47,   495,
     496,    50,   497,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   498,   499,    68,
       0,    69,    70,    71,   540,     0,     0,    74,    75,    76,
       0,     0,   501,    78,     0,     0,     0,     0,    80,   502,
      82,   503,   504,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   505,    97,    98,   506,   507,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,   107,
       0,     0,     0,     0,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   508,   120,   121,   509,
       0,     0,     0,     0,     0,     0,     0,   510,   511,   128,
       0,     0,     0,   129,   798,   130,   512,     0,     0,     0,
     799,     0,   135,     0,   136,   137,   138,   139,   513,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,     0,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     514,   541,   515,   162,   516,   517,   165,   166,   167,   168,
     169,   170,   518,   172,   519,   520,   521,   176,   177,   522,
     523,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     7,     8,
     245,   524,   247,   248,   249,   250,   251,   409,   410,     0,
      14,    15,    16,   485,    18,    19,    20,   486,    22,   487,
     488,  1131,   490,   411,    28,   491,    30,    31,     0,    32,
      33,    34,    35,   492,    37,    38,    39,    40,    41,    42,
      43,   493,     0,    45,   494,    47,   495,   496,    50,   497,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   498,   499,    68,     0,    69,    70,
      71,   500,     0,     0,    74,    75,    76,     0,     0,   501,
      78,     0,     0,     0,     0,    80,   502,    82,   503,   504,
      85,    86,  1476,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   505,
      97,    98,   506,   507,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1132,     0,     0,     0,
    1133,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   508,   120,   121,   509,     0,     0,     0,
       0,     0,     0,     0,   510,   511,   128,     0,     0,     0,
     129,     0,   130,   512,     0,     0,     0,     0,     0,   135,
       0,   136,   137,   138,   139,   513,   141,   142,   143,   144,
     145,   146,     0,     0,  1134,   148,     0,     0,   412,   151,
     152,   153,   154,   155,   156,   157,   158,   514,   160,   515,
     162,   516,   517,   165,   166,   167,   168,   169,   170,   518,
     172,   519,   520,   521,   176,   177,   522,   523,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,     0,     0,     7,     8,   245,   524,   247,
    1135,  1136,  1137,  1138,   409,   410,     0,    14,    15,    16,
     485,    18,    19,    20,   486,    22,   487,   488,  1131,   490,
     411,    28,   491,    30,    31,     0,    32,    33,    34,    35,
     492,    37,    38,    39,    40,    41,    42,    43,   493,     0,
      45,   494,    47,   495,   496,    50,   497,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   498,   499,    68,     0,    69,    70,    71,   500,     0,
       0,    74,    75,    76,     0,     0,   501,    78,     0,     0,
       0,     0,    80,   502,    82,   503,   504,    85,    86,  1615,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   505,    97,    98,   506,
     507,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,  1132,     0,     0,     0,  1133,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     508,   120,   121,   509,     0,     0,     0,     0,     0,     0,
       0,   510,   511,   128,     0,     0,     0,   129,     0,   130,
     512,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   513,   141,   142,   143,   144,   145,   146,     0,
       0,  1134,   148,     0,     0,   412,   151,   152,   153,   154,
     155,   156,   157,   158,   514,   160,   515,   162,   516,   517,
     165,   166,   167,   168,   169,   170,   518,   172,   519,   520,
     521,   176,   177,   522,   523,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     7,     8,   245,   524,   247,  1135,  1136,  1137,
    1138,   409,   410,     0,    14,    15,    16,   485,    18,    19,
      20,   486,    22,   487,   488,  1131,   490,   411,    28,   491,
      30,    31,     0,    32,    33,    34,    35,   492,    37,    38,
      39,    40,    41,    42,    43,   493,     0,    45,   494,    47,
     495,   496,    50,   497,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,   498,   499,
      68,     0,    69,    70,    71,   500,     0,     0,    74,    75,
      76,     0,     0,   501,    78,     0,     0,     0,     0,    80,
     502,    82,   503,   504,    85,    86,  1619,     0,     0,     0,
       0,     0,     0,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   505,    97,    98,   506,   507,     0,     0,
       0,     0,     0,     0,   101,   102,   103,     0,   105,   106,
    1132,     0,     0,     0,  1133,     0,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   508,   120,   121,
     509,     0,     0,     0,     0,     0,     0,     0,   510,   511,
     128,     0,     0,     0,   129,     0,   130,   512,     0,     0,
       0,     0,     0,   135,     0,   136,   137,   138,   139,   513,
     141,   142,   143,   144,   145,   146,     0,     0,  1134,   148,
       0,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   514,   160,   515,   162,   516,   517,   165,   166,   167,
     168,   169,   170,   518,   172,   519,   520,   521,   176,   177,
     522,   523,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   524,   247,  1135,  1136,  1137,  1138,   409,   410,
       0,    14,    15,    16,   485,    18,    19,    20,   486,    22,
     487,   488,  1131,   490,   411,    28,   491,    30,    31,     0,
      32,    33,    34,    35,   492,    37,    38,    39,    40,    41,
      42,    43,   493,     0,    45,   494,    47,   495,   496,    50,
     497,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   498,   499,    68,     0,    69,
      70,    71,   500,     0,     0,    74,    75,    76,     0,     0,
     501,    78,     0,     0,     0,     0,    80,   502,    82,   503,
     504,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     505,    97,    98,   506,   507,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1132,     0,     0,
       0,  1133,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   508,   120,   121,   509,     0,     0,
       0,     0,     0,     0,     0,   510,   511,   128,     0,     0,
       0,   129,     0,   130,   512,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   513,   141,   142,   143,
     144,   145,   146,     0,     0,  1134,   148,     0,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   514,   160,
     515,   162,   516,   517,   165,   166,   167,   168,   169,   170,
     518,   172,   519,   520,   521,   176,   177,   522,   523,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     7,     8,   245,   524,
     247,  1135,  1136,  1137,  1138,   409,   410,     0,    14,    15,
      16,   485,    18,    19,    20,   486,    22,   487,   488,  1131,
     490,   411,    28,   491,    30,    31,     0,    32,    33,    34,
      35,   492,    37,    38,    39,    40,    41,    42,    43,   493,
       0,    45,   494,    47,   495,   496,    50,   497,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   498,   499,    68,     0,    69,    70,    71,   500,
       0,     0,    74,    75,    76,     0,     0,   501,    78,     0,
       0,     0,     0,    80,   502,    82,   503,   504,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   505,    97,    98,
     506,   507,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,  1132,     0,     0,     0,  1133,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   508,   120,   121,   509,     0,     0,     0,     0,     0,
       0,     0,   510,   511,   128,     0,     0,     0,   129,     0,
     130,   512,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   513,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   412,   151,   152,   153,
     154,   155,   156,   157,   158,   514,   160,   515,   162,   516,
     517,   165,   166,   167,   168,   169,   170,   518,   172,   519,
     520,   521,   176,   177,   522,   523,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   524,   247,  1135,  1136,
    1137,  1138,   409,   410,     0,    14,    15,    16,   533,    18,
      19,    20,   486,   534,   535,   488,   489,   490,   411,    28,
     491,    30,    31,     0,    32,    33,    34,    35,   536,    37,
     537,   538,    40,    41,    42,    43,   493,     0,    45,   539,
      47,   495,   496,    50,   497,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   498,
     499,    68,     0,    69,    70,    71,   540,     0,     0,    74,
      75,    76,     0,     0,   501,    78,     0,     0,     0,     0,
      80,   502,    82,   503,   504,    85,    86,  1224,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   505,    97,    98,   506,   507,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   508,   120,
     121,   509,     0,     0,     0,     0,     0,     0,     0,   510,
     511,   128,     0,     0,     0,   129,     0,   130,   512,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     513,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,     0,     0,   412,   151,   152,   153,   154,   155,   156,
     157,   158,   514,   541,   515,   162,   516,   517,   165,   166,
     167,   168,   169,   170,   518,   172,   519,   520,   521,   176,
     177,   522,   523,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,     0,     0,
       7,     8,   245,   524,   247,   248,   249,   250,   251,   409,
     410,     0,    14,    15,    16,   533,    18,    19,    20,   486,
     534,   535,   488,   489,   490,   411,    28,   491,    30,    31,
       0,    32,    33,    34,    35,   536,    37,   537,   538,    40,
      41,    42,    43,   493,     0,    45,   539,    47,   495,   496,
      50,   497,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   498,   499,    68,     0,
      69,    70,    71,   540,     0,     0,    74,    75,    76,     0,
       0,   501,    78,     0,     0,     0,     0,    80,   502,    82,
     503,   504,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   505,    97,    98,   506,   507,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   508,   120,   121,   509,     0,
       0,     0,     0,     0,     0,     0,   510,   511,   128,     0,
       0,     0,   129,     0,   130,   512,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   513,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   514,
     541,   515,   162,   516,   517,   165,   166,   167,   168,   169,
     170,   518,   172,   519,   520,   521,   176,   177,   522,   523,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     524,   247,   248,   249,   250,   251,   409,   410,     0,    14,
      15,    16,     0,    18,    19,    20,   486,     0,     0,   488,
     489,     0,   411,    28,   491,    30,    31,     0,    32,    33,
      34,    35,     0,    37,     0,     0,    40,    41,    42,    43,
     493,     0,    45,     0,    47,     0,     0,    50,   497,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   498,   499,    68,     0,    69,    70,    71,
       0,     0,     0,    74,    75,    76,     0,     0,   501,    78,
       0,     0,     0,     0,    80,   502,    82,   503,   504,    85,
      86,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   505,    97,
      98,   506,   507,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,     0,     0,     0,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   508,   120,   121,   509,     0,     0,     0,     0,
       0,     0,     0,   510,   511,   128,     0,     0,     0,   129,
       0,   130,   512,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   513,   141,   142,   143,   144,   145,
     146,     0,     0,     0,   148,     0,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   514,     0,   515,   162,
     516,   517,   165,   166,   167,   168,   169,   170,   518,   172,
     519,   520,   521,   176,   177,     0,   523,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     0,     0,   245,   524,   247,   248,
     249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   418,   419,    73,     4,     5,     6,   666,     0,    12,
     291,   179,     4,     5,     6,  1025,   818,    87,   339,   311,
       4,     5,     6,   667,   668,   669,   670,   133,   109,   110,
     775,   755,  1041,  1277,   582,   898,   260,  1065,   420,   259,
     588,   111,   787,  1294,   755,   617,   618,    73,   932,  1354,
    1355,   275,   855,   123,  1117,   125,   801,   615,   616,   617,
     618,   252,   253,  1000,  1210,   615,   616,    36,    36,   982,
     432,     4,     5,     6,   711,    26,    27,    29,   460,   461,
     107,   443,     8,   911,   912,     4,     5,     6,   645,  1387,
     647,   648,   107,   650,   282,   652,    47,     1,    96,     1,
    1580,     1,   142,   660,   661,   100,   468,    94,   108,     1,
      55,    29,     1,    29,   107,   153,   108,    93,     1,   118,
     948,     1,    54,    74,    56,    94,    39,    96,    96,   118,
     948,    44,    45,  1307,   415,   224,    30,   226,   224,   224,
     226,   147,   107,   100,   229,   224,    59,  1646,    61,    62,
     147,   118,    26,    27,   982,   130,   130,    70,   110,   131,
     100,   112,   243,   244,    94,   107,   216,    96,   100,   267,
      24,   209,   124,    47,  1002,   108,   274,   156,   147,   147,
      34,   169,    56,    33,    97,    76,   912,  1015,   136,   108,
     153,   186,    26,    27,    45,   113,   166,   149,   158,    49,
      74,   153,   150,   253,   156,    79,    60,   183,   136,   954,
     291,    62,   182,   201,   177,  1520,   176,   147,   190,  1718,
     187,   196,   196,   188,   313,   177,   107,   313,   313,   186,
     217,   218,   272,    29,   313,   224,   342,   111,   112,   113,
     169,   234,   160,   185,   160,   232,   186,  1491,  1728,   175,
    1260,   439,   252,   253,  1117,  1118,   256,   255,   256,  1061,
     252,   253,   153,  1008,   256,  1274,   272,   548,   560,  1014,
    1298,   216,   200,   272,    96,   272,  1002,   347,   112,  1307,
     350,  1579,  1428,  1007,  1168,   312,   190,  1224,   190,  1015,
     190,   291,   864,   865,  1005,   310,  1007,   934,   190,   291,
    1363,   190,  1215,   272,   272,  1133,   258,   190,   253,   190,
     190,   224,   862,   863,   110,  1133,  1027,   306,   250,   213,
    1494,   347,   251,   252,   350,   254,   182,    29,   124,   220,
     221,   263,   261,   265,   415,   286,   187,   894,   107,   195,
     722,   158,   271,   294,   276,   277,   278,   169,   280,     9,
     282,   107,   633,   149,   283,   425,   107,   153,   428,   176,
     156,   154,   432,   156,   107,   435,   436,   448,    28,   153,
     107,    94,   160,   443,  1679,   107,    45,   458,    47,   449,
     450,   177,   107,   106,   454,    94,   467,  1215,   612,  1640,
     107,   773,   462,   474,   475,   615,   616,    96,   468,   469,
     470,   471,   483,   316,   317,   318,   476,   769,   110,   156,
     772,   107,   286,   604,   484,   415,   107,   107,   187,    94,
     294,   107,   124,   415,  1252,   209,  1731,   107,   302,   251,
     252,   187,   254,   184,   107,   118,  1582,   106,   147,   107,
     107,   107,   153,   236,   444,   188,   446,   149,  1276,   271,
     187,   268,   444,   185,   446,     9,    10,   156,   275,   529,
     741,   283,   187,   123,   122,   125,  1494,   548,   285,  1214,
     187,  1715,   472,   543,   134,    26,    27,   477,    96,   107,
     472,   898,   156,   564,   554,   477,    37,    38,   107,    40,
      41,   187,    94,   153,   185,   576,    47,   187,   118,   168,
    1363,   187,  1226,   186,   107,    56,    57,   187,   107,  1372,
     927,   444,   582,   446,   187,   596,   597,   184,   588,   187,
    1383,   187,   592,    74,  1235,   444,  1252,   446,    79,   147,
     107,  1103,  1104,  1105,  1337,  1083,   619,  1340,  1684,   472,
     623,   107,   217,   218,   477,  1103,  1104,  1105,   548,   103,
    1276,   107,   154,   472,   156,   555,   548,   232,   477,   187,
     111,   112,   113,   555,     5,   184,   186,  1395,     9,   123,
     262,   125,   853,   955,   956,   107,   148,   107,   960,   685,
     686,   273,   107,  1729,   187,   156,   107,    42,   187,   156,
       5,    46,  1602,   165,     9,    33,    51,   597,   107,   153,
     107,   682,   107,   157,   604,   597,   687,   610,   990,   160,
     187,    49,   604,  1358,    69,   615,   616,   617,   618,   107,
     174,   187,   555,   615,   616,   617,   618,    45,   184,    47,
    1639,    37,    38,   633,    40,    41,   555,   107,   191,   192,
     194,   633,   862,    42,   868,     9,    10,    46,   718,   107,
    1478,    57,    51,  1481,  1800,   187,  1802,   187,   212,   184,
     741,    79,   732,   184,   597,  1811,   736,   737,   219,  1395,
      69,    52,     9,    10,    96,     1,   107,     3,   187,   184,
     187,   148,   123,   107,   125,    94,  1549,   158,   106,   759,
    1492,   761,   133,   156,   117,  1497,   184,   106,   165,   769,
    1117,  1118,   772,     9,    10,   176,   776,   113,   123,   260,
     125,   156,   153,   168,    94,  1374,   171,   187,   133,  1443,
      94,   137,   118,   146,   158,   147,   184,   198,   809,   810,
     811,   186,   813,   142,    94,   286,   159,   153,   153,   103,
      66,   741,   176,   294,   156,    71,    96,   817,   129,   741,
     168,   302,  1478,   184,   160,  1481,   211,   137,     9,   123,
     184,   125,   142,   113,   198,   765,   103,   153,   142,   168,
     193,  1343,   171,   765,    42,    53,   144,    28,    46,   860,
      58,   765,   142,    51,   137,   855,   123,   186,   125,   153,
     122,   177,   118,   157,   106,   795,   796,   103,  1119,    77,
     153,    69,  1094,   795,   796,    96,   156,  1088,   176,    53,
     174,   881,   211,   219,    58,   127,   153,   123,    96,   125,
     157,   153,   113,  1625,   156,   193,   137,  1629,    95,   156,
     194,   142,   765,   996,  1662,   998,  1664,   174,   268,   106,
     118,   911,   912,   913,   914,   275,   765,   153,   212,   116,
     298,   157,    96,   853,   260,   285,   122,   194,   182,   307,
     127,   853,   795,   796,   122,   156,   100,  1695,   174,    96,
     873,   195,   123,  1255,   125,   212,   795,   796,   948,   113,
     100,  1540,  1541,   134,   945,  1048,   113,  1050,   194,  1533,
     132,   122,   962,   113,  1706,  1707,   957,  1725,   140,   141,
     168,   143,   153,   171,   246,   247,   212,   200,  1710,   151,
     100,   262,  1740,   155,  1742,   157,   209,   987,   186,   154,
     162,   156,   273,   113,  1092,   118,   996,   269,   998,  1097,
    1000,   100,  1002,   122,  1679,  1747,  1662,   179,  1664,   100,
     100,  1753,   137,   211,   113,  1015,  1363,   142,   276,   277,
     278,    53,   113,   113,   282,  1372,    58,   220,   221,   222,
     202,   203,   204,   205,   206,   207,  1383,   153,  1350,  1695,
     156,   153,   153,  1254,   156,   156,   153,   118,  1048,   156,
    1050,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,  1650,  1651,   231,   688,   233,   122,   691,    73,  1725,
     694,   346,   153,   231,   349,   233,   128,   129,   128,   129,
     664,   665,    87,  1083,  1740,   122,  1742,   122,   671,   672,
     153,   673,   674,  1208,  1209,   913,   914,  1570,  1571,   122,
     122,   122,   215,   156,   118,  1116,   111,   240,   240,   156,
     241,   153,  1112,  1043,   313,     0,   107,   190,   123,   167,
     125,  1043,    92,    99,   248,  1336,    50,   199,   101,   154,
     102,    29,  1721,  1133,   145,   184,   156,    47,   184,   184,
     152,   118,   245,   303,   187,   283,   283,   118,  1460,   153,
       1,   118,   142,   107,   187,   153,   153,   156,  1088,   142,
     156,   156,   156,   156,   121,   184,  1088,   156,   156,  1102,
     156,   153,    35,  1103,  1104,  1105,    17,   213,   187,    29,
    1043,  1103,  1104,  1105,   190,   244,   230,   190,   229,   154,
       3,   118,   170,   168,  1043,    70,   170,    94,    94,   230,
      94,   149,  1549,   107,   107,    29,   127,   160,   160,   132,
      94,   245,  1524,   298,   142,   132,   118,   107,   184,   187,
     184,    94,    96,    45,  1224,   187,    96,   187,  1228,   187,
     232,   187,   187,   184,   153,   184,    94,   153,   153,   153,
     153,   153,   142,  1243,   236,   224,   230,   190,    33,   118,
     170,   132,  1252,   142,    94,    29,    94,   285,   298,   127,
     153,  1472,   118,   226,   147,   118,  1266,    94,   253,   160,
     132,   197,   132,   184,   153,    96,  1276,   100,   184,   118,
     147,   100,   153,   184,   121,   142,    35,    29,  1218,   118,
     156,   190,   156,    79,   153,   156,  1218,   244,   107,   107,
     259,   156,   156,   284,  1218,  1305,    29,   257,   156,   156,
     156,   156,   156,   144,    29,    29,   285,   226,   305,   144,
     266,  1332,  1333,  1334,  1254,   286,   127,   147,  1328,   147,
     147,   118,  1254,    77,   118,  1265,   107,  1337,   190,   142,
    1340,   100,   347,  1265,   187,   350,     7,   147,   184,   132,
     232,  1265,   187,   187,  1284,  1218,   232,   187,   190,   187,
     232,   187,  1284,    96,   197,   106,    78,   232,   107,  1218,
    1284,   186,   249,   281,  1304,   187,   187,   187,   285,    29,
     187,   187,  1304,   187,   198,   187,    29,   236,   187,  1600,
     270,   170,   184,   147,   147,  1395,   126,   126,    96,   142,
    1611,  1612,  1265,  1614,   184,  1335,  1336,   249,   186,   186,
    1621,   186,   184,  1335,  1336,   108,  1265,   186,   184,   424,
     425,  1284,   184,   428,  1424,   153,    94,   432,   315,   187,
     435,   436,    29,    96,   170,  1284,   187,   147,   443,    53,
     256,  1304,    94,    94,   449,   450,   186,   197,   186,   454,
    1450,  1451,   106,    29,   107,  1304,   118,   462,   107,   196,
     224,   118,    94,   468,   469,   470,   471,   264,   186,    94,
     196,   476,  1335,   118,   279,   196,  1476,   224,  1478,   484,
     186,  1481,   186,    93,   183,   196,   186,   118,   286,   118,
     186,   186,  1703,  1493,   118,   198,   256,   286,  1498,   292,
     224,   256,   259,  1714,   721,  1171,   949,   439,   304,   304,
     304,  1016,  1215,  1684,   305,   305,  1729,   305,   856,  1013,
     454,  1453,  1244,   778,   529,  1354,  1359,   419,  1108,  1357,
    1741,  1266,  1271,   543,  1274,  1279,   644,   643,   543,  1298,
     696,   663,  1472,  1753,   818,  1747,   998,   914,  1338,   554,
    1472,  1170,   447,   335,  1328,  1337,  1372,  1383,  1118,   447,
    1549,  1376,  1773,  1546,  1127,   981,  1193,  1418,  1573,    -1,
    1373,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1794,    -1,    -1,    -1,   592,  1799,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1615,    -1,  1617,    -1,  1619,
      -1,    -1,    -1,    -1,    -1,    -1,  1626,    -1,    -1,    -1,
    1641,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1660,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1662,    -1,  1664,    -1,    -1,    -1,    -1,    -1,
    1600,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1600,    -1,
    1680,  1611,  1612,  1683,  1614,    -1,    -1,    -1,    -1,  1611,
    1612,  1621,  1614,    -1,    -1,  1695,    -1,    -1,    -1,  1621,
      -1,    -1,    -1,    -1,    -1,  1705,    -1,    -1,    -1,    -1,
     715,    -1,    -1,   718,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1725,    -1,   732,    -1,    -1,
      -1,   736,   737,  1733,    -1,    -1,    -1,    -1,  1738,    -1,
    1740,    -1,  1742,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   759,    -1,   761,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   769,    -1,    -1,   772,    -1,    -1,
    1770,   776,    -1,  1703,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1703,    -1,    -1,  1714,    -1,  1786,    -1,    -1,    -1,
    1790,    -1,  1714,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1806,    -1,    -1,  1809,
      -1,  1741,   817,    -1,    -1,    -1,    -1,    -1,    -1,  1741,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1773,    -1,    -1,    -1,    -1,    -1,    -1,
     855,  1773,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   555,    -1,  1794,    -1,    -1,    -1,    -1,  1799,
      -1,    -1,  1794,    -1,    -1,    -1,   881,  1799,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,   581,    -1,
      -1,   584,   585,   586,   587,    -1,   589,    -1,    -1,    -1,
      -1,    -1,   595,    -1,    -1,    -1,   911,   912,   913,   914,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   625,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     633,   634,    -1,   948,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   962,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   987,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   996,    -1,   998,    -1,  1000,    -1,  1002,    -1,    -1,
     693,    -1,    -1,   696,    -1,    -1,    -1,    -1,    -1,    -1,
    1015,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   734,    -1,  1048,    -1,  1050,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   777,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1112,    -1,   802,
      -1,    -1,    -1,   806,   807,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   815,    -1,    -1,    -1,    -1,    -1,  1133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     883,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1224,
      -1,    -1,    -1,  1228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1252,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   950,    -1,    -1,
      -1,  1266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1276,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   985,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1305,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1004,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1328,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1337,  1026,    -1,  1340,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1037,  1038,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1052,
      -1,    -1,  1055,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1071,  1072,
    1073,    -1,  1075,  1076,  1077,  1078,  1079,  1080,  1081,  1082,
    1395,    -1,  1085,  1086,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1108,    -1,    -1,    -1,  1424,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1450,  1451,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1158,    -1,    -1,    -1,    -1,
      -1,  1476,    -1,  1478,    -1,    -1,  1481,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1493,    -1,
      -1,    -1,    -1,  1498,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1230,    -1,  1232,
      -1,  1234,    -1,    -1,  1237,    -1,    -1,    -1,    -1,  1242,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1254,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1263,    -1,    -1,    -1,    -1,    -1,  1269,  1270,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1288,    -1,    -1,  1291,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1615,    -1,  1617,    -1,  1619,    -1,    -1,    -1,    -1,    -1,
      -1,  1626,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1662,    -1,  1664,
      -1,    -1,    -1,    -1,  1357,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1680,    -1,    -1,  1683,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1695,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1705,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1725,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1733,    -1,
      -1,    -1,    -1,  1738,    -1,  1740,    -1,  1742,    -1,    -1,
      -1,    -1,    -1,    -1,  1437,    -1,    -1,    -1,  1441,    -1,
      -1,    -1,  1445,    -1,  1447,    -1,  1449,    -1,    -1,    -1,
      -1,    -1,  1455,    -1,    -1,  1770,    -1,    -1,    -1,    -1,
    1463,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1471,  1472,
      -1,  1786,    -1,    -1,    -1,  1790,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1490,    -1,    -1,
      -1,  1806,    -1,    -1,  1809,    -1,    -1,    -1,  1501,  1502,
    1503,  1504,    -1,  1506,  1507,    -1,  1509,    -1,    -1,    -1,
      -1,    -1,    -1,  1516,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1525,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1588,    -1,  1590,    -1,    -1,
    1593,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1601,    -1,
      -1,    -1,    -1,  1606,  1607,    -1,    -1,    -1,    -1,    -1,
      -1,  1614,    -1,    -1,    -1,  1618,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1634,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1647,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1687,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1699,    42,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    50,    51,    -1,    -1,    -1,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    69,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1741,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    94,
      95,    96,    -1,    -1,    99,   100,   101,   102,    -1,    -1,
      -1,   106,   107,    -1,    -1,  1768,    -1,    -1,   113,    -1,
    1773,   116,   117,   118,    -1,  1778,   121,    -1,    -1,    -1,
      -1,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,    -1,
    1793,   136,    -1,    -1,  1797,   140,   141,    -1,   143,    -1,
     145,   146,    -1,    -1,    -1,   150,   151,    -1,    -1,   154,
     155,   156,   157,   158,   159,    -1,    -1,   162,    -1,    -1,
      -1,    -1,   167,   168,    -1,    -1,   171,    -1,    -1,    -1,
      -1,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,   184,
     185,   186,   187,   188,    -1,   190,   191,   192,   193,    -1,
      -1,    -1,    -1,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,    -1,   209,    -1,   211,    -1,    -1,    -1,
      -1,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,    -1,   234,
      -1,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   248,    -1,    -1,    -1,    -1,   253,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,   310,    -1,   312,    33,    34,
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
      -1,   186,    -1,   188,   189,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
     315,   316,   317,   318,   319,   320,   321,    11,    12,    -1,
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
      -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,   316,   317,   318,   319,    -1,   321,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,   316,   317,   318,   319,    11,    12,    -1,
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
     184,    -1,   186,    -1,   188,   189,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,   316,   317,   318,   319,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    -1,    -1,    -1,    33,    34,
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
      -1,   176,   177,    -1,    -1,   180,   181,   182,    -1,   184,
      -1,   186,    -1,   188,   189,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
     315,   316,   317,   318,   319,    11,    12,    -1,    -1,    -1,
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
     186,    -1,   188,   189,    -1,   191,   192,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,   212,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,   311,    -1,   313,   314,   315,
     316,   317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
      -1,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,   311,    -1,   313,   314,   315,   316,
     317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     188,   189,    -1,   191,   192,   193,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,   212,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,   311,    -1,   313,   314,   315,   316,   317,
     318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,   311,    -1,   313,   314,   315,   316,   317,   318,
     319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,   316,   317,   318,   319,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,   316,   317,   318,   319,    11,
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
     192,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,   311,
      -1,   313,   314,   315,   316,   317,   318,   319,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,   158,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,   176,   177,    -1,    -1,   180,   181,   182,
      -1,    -1,   185,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,   316,   317,   318,   319,    11,    12,    -1,
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
      -1,    -1,   186,   187,   188,   189,    -1,   191,   192,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,   316,   317,   318,   319,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
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
      -1,   186,    -1,   188,   189,    -1,   191,   192,   193,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,    -1,   313,   314,
     315,   316,   317,   318,   319,    11,    12,    -1,    -1,    -1,
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
     186,    -1,   188,   189,    -1,   191,   192,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,   212,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,    -1,   311,   312,   313,   314,   315,
     316,   317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    -1,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    -1,    94,    95,    96,
      97,    98,    -1,   100,   101,   102,    -1,    -1,   105,   106,
      -1,    -1,    -1,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,   124,    -1,   126,
     127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,   136,
     137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,   146,
     147,   148,   149,   150,   151,   152,   153,   154,    -1,   156,
     157,   158,   159,   160,    -1,    -1,    -1,    -1,   165,   166,
     167,   168,   169,   170,   171,   172,    -1,   174,    -1,   176,
     177,    -1,    -1,   180,   181,   182,    -1,   184,    -1,   186,
      -1,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,   212,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,    -1,   311,    -1,   313,   314,   315,   316,
     317,   318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,
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
     188,   189,    -1,   191,   192,   193,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,   212,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,    -1,   311,    -1,   313,   314,   315,   316,   317,
     318,   319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    33,    34,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    -1,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,    -1,    -1,   105,   106,    -1,    -1,
      -1,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,    -1,   124,    -1,   126,   127,   128,
     129,    -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,
     139,    -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
     169,   170,   171,   172,    -1,   174,    -1,   176,   177,    -1,
      -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,   188,
     189,    -1,   191,   192,   193,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,   212,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,    -1,   311,    -1,   313,   314,   315,   316,   317,   318,
     319,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    29,
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
      -1,   191,   192,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,   212,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
      -1,   311,    -1,   313,   314,   315,   316,   317,   318,   319,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    98,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,   158,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,   176,   177,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
     191,   192,   193,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,   212,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,   309,    -1,
     311,    -1,   313,   314,   315,   316,   317,   318,   319,    11,
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
     192,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
     212,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,    -1,   311,
      -1,   313,   314,   315,   316,   317,   318,   319,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    98,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,   191,   192,
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,   316,   317,   318,   319,    11,    12,    -1,
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
     154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,   169,   170,   171,   172,    -1,
     174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,   212,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,    -1,   311,    -1,   313,
     314,   315,   316,   317,   318,   319,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    29,    -1,    -1,    -1,    33,    34,
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
     135,    -1,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,   149,    -1,   151,   152,   153,   154,
      -1,   156,   157,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,   174,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,    -1,
     195,    -1,   197,    -1,   199,    -1,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,   212,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,    -1,   311,    -1,   313,   314,
     315,   316,   317,   318,   319,    11,    12,    -1,    -1,    -1,
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
     186,    -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    -1,    -1,    11,    12,   313,   314,   315,
     316,   317,   318,   319,    20,    -1,    -1,    -1,    24,    25,
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
     186,    -1,   188,   189,    -1,    -1,    -1,   193,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    -1,    -1,    -1,    16,   313,   314,   315,
     316,   317,   318,   319,    24,    25,    -1,    -1,    -1,    29,
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
      -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    -1,
      -1,    -1,    16,   313,   314,   315,   316,   317,   318,   319,
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
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    -1,    -1,    -1,    -1,   313,
     314,   315,   316,   317,   318,   319,    18,    19,    -1,    -1,
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
      -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    -1,
      -1,   313,   314,   315,   316,   317,   318,   319,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    29,    -1,    -1,    -1,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    -1,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      -1,    94,    95,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,   105,   106,    -1,    -1,    -1,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,   124,    -1,   126,   127,   128,   129,    -1,   131,    -1,
      -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,   212,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,    -1,   311,    -1,
     313,   314,   315,   316,   317,   318,   319,    24,    25,    -1,
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
     187,   188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    -1,    -1,    24,    25,   313,   314,   315,   316,
     317,   318,   319,    33,    34,    -1,    36,    37,    38,    39,
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
      -1,    -1,    -1,   193,    -1,   195,    -1,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,    -1,    -1,
     210,   211,    -1,    -1,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,    -1,   258,   259,
     260,    -1,   262,   263,   264,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,    -1,
      -1,    24,    25,   313,   314,   315,   316,   317,   318,   319,
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
     193,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,    -1,    -1,   210,   211,    -1,
      -1,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,    -1,   258,   259,   260,    -1,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,    -1,    -1,    24,    25,
     313,   314,   315,   316,   317,   318,   319,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    -1,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,   105,
     106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,   135,
     136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,    -1,
     146,   147,   148,    -1,   150,   151,   152,    -1,    -1,    -1,
     156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,   169,   170,   171,   172,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,
     186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,
      -1,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,    -1,   258,   259,   260,    -1,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,    -1,    -1,    24,    25,   313,   314,   315,
     316,   317,   318,   319,    33,    34,    -1,    36,    37,    38,
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
     189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,    -1,
      -1,   210,   211,    -1,    -1,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,    -1,   258,
     259,   260,    -1,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
      -1,    -1,    24,    25,   313,   314,   315,   316,   317,   318,
     319,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    -1,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    -1,    94,    95,    96,    97,    -1,    -1,   100,   101,
     102,    -1,    -1,   105,   106,    -1,    -1,    -1,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,   131,
      -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,    -1,
      -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,   151,
     152,    -1,    -1,    -1,   156,    -1,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,    -1,    -1,   210,   211,
      -1,    -1,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,   255,   256,    -1,   258,   259,   260,    -1,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    24,
      25,   313,   314,   315,   316,   317,   318,   319,    33,    34,
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
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    -1,    -1,    24,    25,   313,   314,
     315,   316,   317,   318,   319,    33,    34,    -1,    36,    37,
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
     148,    -1,   150,   151,   152,    -1,    -1,    -1,   156,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,    -1,
     188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
      -1,    -1,   210,   211,    -1,    -1,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,    -1,
     258,   259,   260,    -1,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,    -1,    -1,    24,    25,   313,   314,   315,   316,   317,
     318,   319,    33,    34,    -1,    36,    37,    38,    39,    40,
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
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,    -1,    -1,   210,
     211,    -1,    -1,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,    -1,   258,   259,   260,
      -1,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   306,   307,   308,    -1,    -1,
      24,    25,   313,   314,   315,   316,   317,   318,   319,    33,
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
      -1,   195,    -1,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,    -1,    -1,   210,   211,    -1,    -1,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,    -1,   258,   259,   260,    -1,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,    -1,    -1,    24,    25,   313,
     314,   315,   316,   317,   318,   319,    33,    34,    -1,    36,
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
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,    -1,   211,    -1,    -1,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    -1,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,    -1,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
      -1,   258,   259,   260,    -1,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,    -1,    -1,    -1,    -1,   313,   314,   315,   316,
     317,   318,   319
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
     188,   189,   191,   192,   193,   195,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   210,   211,   212,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   258,   259,   260,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   311,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   333,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   354,   355,   356,   357,   358,   359,   363,   364,
     365,   369,   371,   372,   374,   381,   383,   386,   387,   388,
     390,   391,   392,   393,   394,   396,   397,   399,   400,   401,
     402,   403,   404,   406,   407,   410,   411,   412,   413,   418,
     420,   422,   423,   428,   447,   450,   454,   457,   458,   463,
     464,   465,   466,   468,   469,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   485,   486,   487,
     488,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   515,   516,   517,   531,   532,   534,
     535,   536,   537,   538,   539,   540,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   560,   561,   562,   563,
     568,   569,   570,   571,   572,   573,   576,   634,   635,   636,
     637,   639,   640,   641,   642,   643,   650,   651,   652,    33,
      34,    49,   214,   389,   390,   391,   389,   389,   156,   156,
      37,    38,    40,    41,    47,    56,    57,    74,    79,   111,
     112,   113,   160,   219,   260,   286,   294,   302,   370,   371,
     375,   376,   377,   160,   153,   156,   153,   156,   153,   156,
       1,     3,    66,    71,   118,   415,   156,   378,   156,    24,
      34,    60,   118,   272,   427,   429,   430,   153,   156,   156,
     156,   118,   153,   156,   156,   156,    76,   153,   220,   221,
     122,   122,   122,   153,   156,    39,    43,    45,    46,    47,
      48,    51,    59,    67,    70,    72,    73,    75,    90,    91,
      97,   105,   112,   114,   115,   135,   138,   139,   169,   172,
     180,   181,   189,   201,   223,   225,   227,   228,   235,   237,
     238,   239,   242,   243,   314,   499,   650,   651,   122,   118,
     398,   122,   122,    39,    44,    45,    59,    61,    62,    70,
      97,   224,   650,   118,   122,   122,   184,   389,   391,   411,
     638,    48,    72,    73,   118,   153,   185,   243,   410,   412,
     422,   187,   410,   650,   153,   122,    16,   649,   650,    18,
      19,   650,   122,   122,   122,   491,   153,    30,   213,   215,
     224,   226,   313,   156,   224,   226,   313,   224,   313,   224,
     229,   313,   118,   240,   240,   241,   156,   153,   393,   310,
     410,   312,   410,   313,   321,   335,   335,     0,   337,   338,
      33,    49,   340,   357,     1,   190,   334,   190,   334,   112,
     372,   392,   410,   107,   190,   107,   190,    42,    46,    51,
      69,   168,   171,   186,   211,   405,   414,   419,   420,   421,
     435,   436,   440,   167,    92,   132,   140,   141,   143,   151,
     155,   157,   162,   179,   202,   203,   204,   205,   206,   207,
     483,   484,   248,    99,   158,   176,   198,   117,   146,   159,
     193,   200,   209,   136,   150,    50,   199,   101,   102,   158,
     176,   482,   153,   488,   491,   191,   192,   154,   503,   504,
     499,   503,   499,   156,   503,   145,   156,   184,   184,   184,
     373,   506,   373,    29,   648,   182,   195,   182,   195,   166,
     182,   651,   650,   169,   201,    47,   650,   152,   118,    45,
      47,    79,   106,   168,   649,   220,   221,   222,   245,   607,
     650,   650,   303,   137,   142,   112,   286,   294,   375,   649,
     390,   391,   187,   390,    45,    62,   187,   556,   557,   410,
     187,   193,   650,   424,   425,   650,   283,   283,   424,   118,
     431,   118,   187,   379,   380,   153,   395,   410,     1,   160,
     648,   113,   160,   353,   648,   650,   118,   142,   107,   410,
      29,   187,   649,   650,   650,   448,   449,   650,   390,   187,
     410,   410,   558,   650,   390,   153,   153,   410,   187,   193,
     650,   650,   142,   448,   184,   184,   121,   107,   184,   156,
     156,   156,   650,   153,   185,   186,   187,    35,   519,   520,
     521,   410,     8,   175,    17,   410,   213,    29,   411,   411,
      39,    45,    59,    70,    97,   502,   650,   187,   411,   411,
     411,   411,   502,   411,   230,   229,   574,   575,   650,   190,
     190,   411,   410,   391,   410,   244,   408,   409,   310,   312,
     154,   335,   190,   334,   190,   334,     3,   341,   357,   387,
     341,   357,   387,    33,   358,   387,   358,   387,   398,   398,
     411,   118,   168,   170,   170,   392,   411,   411,   465,   466,
     468,   468,   468,   468,   467,   468,   468,   468,    70,   469,
     473,   473,   472,   474,   474,   474,   474,   475,   475,   476,
     476,   230,    94,    94,    94,   184,   410,   491,   491,   410,
     504,   187,   411,   514,   149,   187,   514,   107,   187,   187,
     107,   107,   378,    29,   651,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,   360,   361,   362,    94,   137,
     142,   366,   367,   368,   650,   160,   160,   360,   648,   127,
     132,    54,    56,   100,   250,   263,   265,   276,   277,   278,
     280,   282,   608,   609,   610,   611,   612,   613,   620,   626,
     627,   245,    94,   298,   650,   142,   411,   118,   650,   650,
     132,   184,   184,   187,   187,   184,   107,   187,   107,   187,
     107,    36,    94,    96,   147,   426,   427,   542,   650,    55,
     216,   253,   416,   417,   650,    94,   107,   187,   389,   187,
     649,    96,    45,   649,   648,    96,   142,   542,   650,   411,
     430,   184,   187,   187,   187,   187,   107,   188,   147,   542,
     184,   187,   187,   153,   184,   390,   390,   184,   107,   187,
     107,   187,   142,   542,   411,   188,   411,   411,   410,   410,
     410,   650,   520,   521,   130,   196,   184,   184,   131,   190,
      94,   217,   218,   232,    94,   217,   218,   232,   232,    94,
      94,   236,   224,   230,   107,   234,   142,   190,   187,    48,
      72,    73,   243,   412,   422,   184,   500,   580,   409,   410,
     357,    33,    33,   190,   334,   190,   113,   650,   170,   411,
     441,   442,   118,   437,   438,   468,   153,   156,   258,   487,
     506,   581,   584,   585,   586,   587,   588,   592,   594,   596,
     597,    47,   152,   156,   210,   316,   317,   318,   319,   543,
     545,   547,   548,   564,   565,   566,   567,   644,   645,   646,
     647,   650,   543,   541,   547,   541,   184,   185,   107,   187,
     187,   506,   148,   165,   148,   165,   137,   395,   378,   361,
     132,   545,   368,   411,   542,   648,   648,   128,   129,   648,
     276,   277,   278,   282,   650,   262,   273,   262,   273,    29,
     285,    96,   113,   156,   614,   617,   608,    39,    44,    59,
      61,    70,    97,   224,   316,   317,   318,   382,   548,   644,
     226,   298,   307,   411,   650,    94,   298,   648,   153,   558,
     559,   650,   558,   559,   118,   425,   127,   543,   118,   411,
     147,   427,   147,    36,   147,   426,   427,   147,   542,   253,
      53,    58,    77,   118,   426,   432,   433,   434,   417,   542,
     543,   380,    94,   184,   197,   132,   352,   648,   160,   132,
      96,   352,   411,   142,   427,   153,   118,   411,   411,   147,
     100,   451,   452,   453,   455,   456,   100,   459,   460,   461,
     462,   390,   184,   184,   153,   558,   558,   411,   142,   190,
     411,   121,   187,   187,   187,    35,   521,   130,   196,     9,
      10,   103,   123,   125,   153,   194,   516,   518,   529,   530,
     533,    29,   231,   233,   411,   411,   411,   231,   233,   411,
     411,   411,   411,   411,   411,   411,   411,   502,   118,   411,
     411,   392,   156,   156,   156,   153,   186,   244,   577,   578,
     209,   393,   185,   190,   113,   387,   387,   387,   441,    95,
     106,   116,   127,   443,   444,   445,   446,   107,   650,   107,
     410,   581,   588,   153,   284,   470,   633,    96,   169,   251,
     252,   254,   261,   271,   283,   582,   583,   602,   603,   604,
     605,   628,   631,   257,   259,   589,   607,   266,   593,   629,
     246,   247,   269,   598,   599,   156,   156,   545,   156,   156,
     156,   156,   156,   144,   176,   193,   544,   144,   411,   137,
     395,   560,   367,   285,    29,    96,   113,   156,   621,    29,
     614,   544,   544,   489,   286,   305,   542,   382,   226,   190,
     389,   187,   187,   144,   187,   187,   425,   147,   426,   650,
     411,   147,   411,   127,   411,   147,   427,   147,   411,   147,
     118,   118,   411,   650,   434,    77,   543,   392,   411,   648,
     107,   352,   411,   142,   389,   449,   411,   411,   113,   452,
     453,   100,   186,   113,   453,   456,   118,   543,   100,   113,
     460,   100,   113,   462,   184,   389,   187,   187,   411,   411,
     197,   459,   132,   194,   518,     7,   390,   650,   194,   529,
     190,   232,   232,   232,   232,    96,   236,   236,   575,   186,
     410,   410,   410,   580,   578,   500,   198,   648,   128,   129,
     445,   446,   446,   442,   106,   142,   439,   542,   438,   184,
     187,   581,   595,   249,   216,   253,   267,   274,   632,    96,
     255,   256,   630,   249,   585,   632,   472,   602,   586,   147,
     281,   590,   591,   630,   285,   601,    78,   600,   187,   193,
     543,   546,   187,   187,   187,   187,   187,   187,   187,    29,
     136,   200,   623,   624,   625,    29,   622,   623,   270,   618,
     107,   615,   170,   650,   256,   489,   184,   411,   147,   411,
     147,   426,   411,   147,   411,   411,   650,   650,   433,   411,
     126,   126,    96,   648,   411,   184,   186,   186,   411,   392,
     411,   186,   186,   650,   186,   118,   543,   118,   186,   118,
     543,   186,   184,   113,   521,   650,   194,   184,   521,   650,
     411,   411,   411,   411,   315,   411,   411,   411,   187,   187,
     187,   153,   579,   411,   446,   648,   411,   142,   184,   474,
      52,   129,   472,   472,   268,   275,   285,   606,   606,   587,
     153,   279,    94,   187,   107,   187,   621,   621,   625,   107,
     187,    29,   619,   630,   616,   617,   187,   384,   385,   489,
     118,   224,   306,   286,   170,   411,   411,   147,   411,    53,
     392,   411,   352,   411,   392,    94,   392,   411,   650,   186,
     650,   411,   650,   186,   392,   118,    93,   183,   522,   521,
     650,   196,   521,   411,   197,   459,   410,   439,   411,   472,
     472,   198,   410,   543,   543,    94,    29,   264,   107,   107,
     446,   542,   650,   118,   224,   650,   384,   411,   118,   543,
      94,   186,    94,   650,     5,   133,   525,   526,   528,   530,
      28,   134,   523,   524,   527,   530,   196,   521,   196,   113,
     184,   439,   472,   184,   543,   617,   385,   446,   304,   650,
     118,   224,   650,   186,   543,   392,   411,   543,   186,    93,
     133,   528,   183,   134,   527,   196,   118,   411,   304,   650,
     118,   392,   411,   186,   186,   650,   292,   304,   650,   186,
     305,   411,   305,   489,   489,   198,   286,   650,   224,   118,
     650,   305,   489
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
     585,   586
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned short int
  xquery_parser::yyr1_[] =
  {
         0,   332,   333,   333,   333,   333,   334,   335,   335,   335,
     335,   336,   336,   337,   337,   337,   337,   337,   337,   337,
     337,   338,   338,   338,   338,   339,   340,   340,   340,   341,
     341,   341,   341,   341,   342,   342,   342,   342,   342,   342,
     342,   342,   343,   343,   344,   345,   346,   346,   347,   347,
     348,   348,   349,   349,   349,   349,   350,   350,   350,   351,
     351,   351,   351,   352,   352,   353,   353,   354,   354,   354,
     354,   355,   356,   356,   357,   357,   357,   358,   358,   358,
     358,   358,   358,   358,   358,   359,   359,   360,   360,   361,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     363,   364,   365,   366,   366,   367,   367,   367,   368,   369,
     369,   369,   370,   370,   370,   370,   371,   371,   372,   372,
     372,   372,   373,   373,   374,   374,   375,   375,   376,   376,
     377,   377,   378,   378,   378,   378,   379,   379,   380,   380,
     381,   381,   381,   381,   382,   382,   382,   382,   383,   383,
     384,   384,   385,   385,   385,   385,   386,   386,   386,   386,
     387,   388,   388,   388,   389,   389,   389,   390,   390,   391,
     391,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   393,   393,   394,   395,   396,   397,   397,
     397,   398,   398,   398,   398,   399,   400,   401,   402,   403,
     403,   404,   405,   406,   407,   408,   408,   409,   410,   410,
     411,   411,   411,   411,   411,   411,   412,   412,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   413,   414,
     415,   415,   416,   416,   416,   417,   417,   418,   418,   419,
     420,   420,   420,   421,   421,   421,   421,   421,   422,   422,
     423,   423,   423,   424,   424,   424,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   426,   427,
     428,   429,   429,   430,   430,   430,   430,   431,   431,   432,
     432,   432,   433,   433,   433,   434,   434,   434,   435,   436,
     437,   437,   438,   438,   438,   438,   438,   438,   439,   440,
     440,   441,   441,   442,   442,   443,   443,   443,   443,   443,
     443,   443,   444,   444,   445,   445,   446,   447,   447,   448,
     448,   449,   449,   450,   451,   451,   452,   453,   453,   454,
     455,   455,   456,   457,   457,   458,   458,   459,   459,   460,
     460,   461,   461,   462,   462,   463,   464,   464,   465,   465,
     466,   466,   466,   466,   466,   467,   466,   466,   466,   466,
     468,   468,   469,   469,   470,   470,   471,   471,   472,   472,
     472,   473,   473,   473,   473,   473,   474,   474,   474,   475,
     475,   475,   476,   476,   477,   477,   478,   478,   479,   479,
     480,   480,   481,   481,   481,   481,   482,   482,   482,   483,
     483,   483,   483,   483,   483,   484,   484,   484,   485,   485,
     485,   485,   486,   486,   487,   487,   488,   488,   488,   489,
     489,   489,   489,   490,   491,   491,   491,   492,   492,   493,
     493,   493,   493,   494,   494,   495,   495,   495,   495,   495,
     495,   495,   496,   496,   497,   497,   498,   498,   498,   498,
     498,   499,   499,   500,   500,   501,   501,   501,   501,   502,
     502,   502,   502,   503,   503,   504,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     506,   506,   507,   507,   507,   508,   509,   509,   510,   511,
     512,   513,   513,   514,   514,   515,   515,   516,   516,   516,
     517,   517,   517,   517,   517,   517,   518,   518,   519,   519,
     520,   521,   521,   522,   522,   523,   523,   524,   524,   524,
     524,   525,   525,   526,   526,   526,   526,   527,   527,   528,
     528,   529,   529,   529,   529,   530,   530,   530,   530,   531,
     531,   532,   532,   533,   534,   534,   534,   534,   534,   534,
     535,   536,   536,   537,   537,   538,   539,   540,   540,   541,
     541,   542,   543,   543,   543,   544,   544,   544,   545,   545,
     545,   545,   545,   545,   545,   546,   546,   547,   548,   548,
     548,   548,   548,   548,   548,   548,   548,   549,   550,   550,
     550,   551,   552,   553,   553,   553,   554,   554,   554,   554,
     554,   555,   556,   556,   556,   556,   556,   556,   556,   557,
     558,   559,   560,   561,   561,   562,   563,   564,   564,   565,
     566,   566,   567,   568,   568,   568,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   570,   570,   571,   571,
     572,   573,   574,   574,   575,   576,   577,   577,   578,   579,
     580,   580,   581,   582,   582,   583,   583,   584,   584,   585,
     585,   586,   586,   587,   587,   588,   589,   589,   590,   590,
     591,   592,   592,   592,   593,   593,   594,   595,   595,   596,
     597,   597,   598,   598,   599,   599,   599,   600,   600,   601,
     601,   602,   602,   602,   602,   602,   603,   604,   605,   606,
     606,   606,   607,   607,   608,   608,   608,   608,   608,   608,
     608,   608,   609,   609,   609,   609,   610,   610,   611,   612,
     612,   613,   613,   613,   614,   614,   615,   615,   616,   616,
     617,   618,   618,   619,   619,   620,   620,   620,   621,   621,
     622,   622,   623,   623,   624,   624,   625,   625,   626,   627,
     627,   628,   628,   628,   629,   630,   630,   630,   630,   631,
     631,   632,   632,   633,   634,   634,   635,   635,   636,   636,
     637,   638,   638,   639,   639,   640,   641,   642,   643,   644,
     644,   644,   645,   646,   647,   648,   649,   649,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     651,   651,   651,   651,   651,   651,   651,   651,   651,   651,
     652
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
       4,     5,     8,     9,     9,    10,     1,     2,     1,     2,
       6,     0,     1,     3,     3,     0,     1,     1,     1,     2,
       2,     0,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       4,     3,     7,     3,     7,     4,     4,     3,     7,     1,
       2,     2,     1,     2,     3,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       4,     3,     3,     3,     4,     4,     3,     4,     6,     4,
       6,     4,     3,     4,     6,     6,     4,     6,     6,     4,
       1,     2,     1,     1,     1,     3,     3,     1,     1,     4,
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
       3,     3,     5,     5,     8,     7,     3,     5,     7,     1,
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
  "\"'*'\"", "\"'</ (start tag end)'\"", "\"'strip'\"",
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
  "UNARY_PREC", "STEP_REDUCE", "MULTIPLICATIVE_REDUCE", "$accept",
  "Module", "ERROR", "ModuleWithoutBOM", "VersionDecl", "MainModule",
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
  "SignList", "ValueExpr", "ValueComp", "NodeComp", "ValidateExpr",
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
       333,     0,    -1,   335,    -1,   320,   335,    -1,   321,   335,
      -1,   320,   321,   335,    -1,     1,     3,    -1,   337,    -1,
     336,   337,    -1,   338,    -1,   336,   338,    -1,   214,   215,
      29,   190,    -1,   214,   215,    29,   131,    29,   190,    -1,
     340,   190,   387,    -1,   357,   190,   387,    -1,   340,   190,
     357,   190,   387,    -1,   387,    -1,   340,   334,   387,    -1,
     357,   334,   387,    -1,   340,   190,   357,   334,   387,    -1,
     340,   334,   357,   190,   387,    -1,   339,    -1,   339,   340,
     190,    -1,   339,   357,   190,    -1,   339,   340,   190,   357,
     190,    -1,    34,   160,   649,   132,   648,   190,    -1,   341,
      -1,   340,   190,   341,    -1,   340,   334,   341,    -1,   342,
      -1,   350,    -1,   355,    -1,   356,    -1,   364,    -1,   343,
      -1,   344,    -1,   345,    -1,   346,    -1,   347,    -1,   348,
      -1,   349,    -1,   568,    -1,    33,    38,   182,    -1,    33,
      38,   195,    -1,    33,   113,   106,   648,    -1,    33,    37,
     648,    -1,    33,    40,   182,    -1,    33,    40,   195,    -1,
      33,    57,   169,    -1,    33,    57,   201,    -1,    33,   113,
     168,   127,   128,    -1,    33,   113,   168,   127,   129,    -1,
      33,    41,   182,   107,   148,    -1,    33,    41,   182,   107,
     165,    -1,    33,    41,   166,   107,   148,    -1,    33,    41,
     166,   107,   165,    -1,   351,    -1,   354,    -1,    49,    24,
       1,    -1,    49,    60,   648,    -1,    49,    60,   353,   648,
      -1,    49,    60,   648,    96,   352,    -1,    49,    60,   353,
     648,    96,   352,    -1,   648,    -1,   352,   107,   648,    -1,
     160,   649,   132,    -1,   113,    45,   160,    -1,    49,    34,
     648,    -1,    49,    34,   160,   649,   132,   648,    -1,    49,
      34,   648,    96,   352,    -1,    49,    34,   160,   649,   132,
     648,    96,   352,    -1,    33,   160,   649,   132,   648,    -1,
      33,   113,    45,   160,   648,    -1,    33,   113,    47,   160,
     648,    -1,   358,    -1,   357,   190,   358,    -1,   357,   334,
     358,    -1,   359,    -1,   363,    -1,   365,    -1,   369,    -1,
     374,    -1,   381,    -1,   383,    -1,   386,    -1,    33,   113,
      79,   360,    -1,    33,    79,   650,   360,    -1,   361,    -1,
     360,   361,    -1,   362,   132,   560,    -1,    80,    -1,    88,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    89,
      -1,    85,    -1,    86,    -1,    87,    -1,    33,    56,   650,
      29,    -1,    33,   260,   607,    -1,    33,   111,   152,   366,
      -1,    94,   545,   367,    -1,   367,    -1,   368,    -1,   137,
      -1,   137,   368,    -1,   142,   411,    -1,    33,   370,   142,
     411,    -1,    33,   370,   137,    -1,    33,   370,   137,   142,
     411,    -1,   112,   118,   650,    -1,   112,   118,   650,   542,
      -1,   371,   112,   118,   650,    -1,   371,   112,   118,   650,
     542,    -1,   372,    -1,   371,   372,    -1,    26,    -1,    26,
     156,   373,   187,    -1,    27,    -1,    27,   156,   373,   187,
      -1,   506,    -1,   373,   107,   506,    -1,    33,   375,    -1,
      33,   371,   375,    -1,   376,    -1,   377,    -1,    47,   651,
     378,   395,    -1,    47,   651,   378,   137,    -1,    74,    47,
     651,   378,   395,    -1,    74,    47,   651,   378,   137,    -1,
     156,   187,    -1,   156,   379,   187,    -1,   156,   187,    94,
     543,    -1,   156,   379,   187,    94,   543,    -1,   380,    -1,
     379,   107,   380,    -1,   118,   650,    -1,   118,   650,   542,
      -1,    33,   286,   650,    -1,    33,   286,   650,    94,   382,
      -1,    33,   371,   286,   650,    -1,    33,   371,   286,   650,
      94,   382,    -1,   548,    -1,   548,   544,    -1,   644,    -1,
     644,   544,    -1,    33,   294,   650,   298,   226,   489,   170,
     384,    -1,    33,   371,   294,   650,   298,   226,   489,   170,
     384,    -1,   385,    -1,   384,   107,   385,    -1,   489,    -1,
     489,   542,    -1,   489,   446,    -1,   489,   542,   446,    -1,
      33,   302,   303,   650,   298,   286,   650,   118,   650,   304,
     411,    -1,    33,   302,   303,   650,   298,   286,   650,   224,
     118,   650,   304,   292,   305,   489,    -1,    33,   302,   303,
     650,   298,   286,   650,   306,   224,   118,   650,   304,   411,
      -1,    33,   302,   303,   650,   307,   305,   256,   286,   650,
     224,   118,   650,   305,   489,   198,   286,   650,   224,   118,
     650,   305,   489,    -1,   388,    -1,   390,    -1,   391,    -1,
      -1,   390,    -1,   391,    -1,    -1,   410,    -1,   391,   410,
      -1,   392,    -1,   391,   392,    -1,   393,    -1,   396,    -1,
     399,    -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,
     404,    -1,   406,    -1,   458,    -1,   454,    -1,   407,    -1,
     153,   391,   184,    -1,   153,   184,    -1,   153,   389,   184,
      -1,   153,   389,   184,    -1,   397,   190,    -1,   397,   107,
     398,    -1,   112,   398,    -1,   371,   112,   398,    -1,   118,
     650,    -1,   118,   650,   542,    -1,   118,   650,   142,   411,
      -1,   118,   650,   542,   142,   411,    -1,   118,   650,   142,
     411,   190,    -1,   412,   190,    -1,   239,   241,   411,   190,
      -1,   242,   156,   410,   187,   392,    -1,   237,   240,   190,
      -1,   238,   240,   190,    -1,   422,   405,    -1,   186,   392,
      -1,    48,   156,   410,   187,   197,   392,   126,   392,    -1,
     243,   393,   408,    -1,   409,    -1,   408,   409,    -1,   244,
     580,   393,    -1,   411,    -1,   410,   107,   411,    -1,   413,
      -1,   450,    -1,   457,    -1,   463,    -1,   576,    -1,   412,
      -1,   464,    -1,   447,    -1,   569,    -1,   570,    -1,   572,
      -1,   571,    -1,   573,    -1,   641,    -1,   639,    -1,   642,
      -1,   643,    -1,   640,    -1,   422,   414,    -1,   186,   411,
      -1,    66,   283,    -1,    71,   283,    -1,   216,    -1,   253,
      -1,    55,   253,    -1,   416,   432,    77,   411,    -1,   416,
      77,   411,    -1,    46,   415,   431,   417,   417,    -1,    46,
     415,   431,   417,    -1,    42,   118,   650,    -1,   423,    -1,
     428,    -1,   418,    -1,   420,    -1,   435,    -1,   440,    -1,
     436,    -1,   419,    -1,   420,    -1,   422,   421,    -1,    46,
     118,   424,    -1,    46,     1,   424,    -1,    46,     3,    -1,
     425,    -1,   424,   107,   118,   425,    -1,   424,   107,   425,
      -1,   650,   147,   411,    -1,   650,    36,   127,   147,   411,
      -1,   650,   542,   147,   411,    -1,   650,   542,    36,   127,
     147,   411,    -1,   650,   426,   147,   411,    -1,   650,    36,
     127,   426,   147,   411,    -1,   650,   542,   426,   147,   411,
      -1,   650,   542,    36,   127,   426,   147,   411,    -1,   650,
     427,   147,   411,    -1,   650,   542,   427,   147,   411,    -1,
     650,   426,   427,   147,   411,    -1,   650,   542,   426,   427,
     147,   411,    -1,    96,   118,   650,    -1,   272,   118,   650,
      -1,    51,   429,    -1,   430,    -1,   429,   107,   430,    -1,
     118,   650,   142,   411,    -1,   118,   650,   542,   142,   411,
      -1,   427,   142,   411,    -1,   118,   650,   542,   427,   142,
     411,    -1,   118,   650,   147,   411,    -1,   118,   650,   542,
     147,   411,    -1,   433,    -1,   118,   650,    -1,   118,   650,
     433,    -1,   426,    -1,   426,   434,    -1,   434,    -1,    58,
     118,   650,    53,   118,   650,    -1,    53,   118,   650,    -1,
      58,   118,   650,    -1,   211,   411,    -1,   171,   170,   437,
      -1,   438,    -1,   437,   107,   438,    -1,   118,   650,    -1,
     118,   650,   142,   411,    -1,   118,   650,   542,   142,   411,
      -1,   118,   650,   542,   142,   411,   439,    -1,   118,   650,
     142,   411,   439,    -1,   118,   650,   439,    -1,   106,   648,
      -1,   168,   170,   441,    -1,    69,   168,   170,   441,    -1,
     442,    -1,   441,   107,   442,    -1,   411,    -1,   411,   443,
      -1,   444,    -1,   445,    -1,   446,    -1,   444,   445,    -1,
     444,   446,    -1,   445,   446,    -1,   444,   445,   446,    -1,
      95,    -1,   116,    -1,   127,   128,    -1,   127,   129,    -1,
     106,   648,    -1,    67,   118,   448,   188,   411,    -1,   135,
     118,   448,   188,   411,    -1,   449,    -1,   448,   107,   118,
     449,    -1,   650,   147,   411,    -1,   650,   542,   147,   411,
      -1,    72,   156,   410,   187,   451,   113,   186,   411,    -1,
     452,    -1,   451,   452,    -1,   453,   186,   411,    -1,   100,
     411,    -1,   453,   100,   411,    -1,    72,   156,   410,   187,
     455,   113,   186,   392,    -1,   456,    -1,   455,   456,    -1,
     453,   186,   392,    -1,    73,   156,   410,   187,   459,   113,
     186,   411,    -1,    73,   156,   410,   187,   459,   113,   118,
     650,   186,   411,    -1,    73,   156,   410,   187,   461,   113,
     186,   392,    -1,    73,   156,   410,   187,   459,   113,   118,
     650,   186,   392,    -1,   460,    -1,   459,   460,    -1,   100,
     543,   186,   411,    -1,   100,   118,   650,    94,   543,   186,
     411,    -1,   462,    -1,   461,   462,    -1,   100,   543,   186,
     392,    -1,   100,   118,   650,    94,   543,   186,   392,    -1,
      48,   156,   410,   187,   197,   411,   126,   411,    -1,   465,
      -1,   464,   167,   465,    -1,   466,    -1,   465,    92,   466,
      -1,   468,    -1,   468,   483,   468,    -1,   468,   484,   468,
      -1,   468,   132,   468,    -1,   468,   162,   468,    -1,    -1,
     468,   157,   467,   468,    -1,   468,   155,   468,    -1,   468,
     143,   468,    -1,   468,   141,   468,    -1,   469,    -1,   469,
     248,    70,   581,   470,    -1,   471,    -1,   471,    99,   469,
      -1,    -1,   633,    -1,   472,    -1,   472,   198,   472,    -1,
     473,    -1,   472,   176,   473,    -1,   472,   158,   473,    -1,
     474,    -1,   473,   193,   474,    -1,   473,   117,   474,    -1,
     473,   146,   474,    -1,   473,   159,   474,    -1,   475,    -1,
     474,   200,   475,    -1,   474,   209,   475,    -1,   476,    -1,
     475,   150,   476,    -1,   475,   136,   476,    -1,   477,    -1,
     477,    50,   230,   543,    -1,   478,    -1,   478,   199,    94,
     543,    -1,   479,    -1,   479,   101,    94,   541,    -1,   480,
      -1,   480,   102,    94,   541,    -1,   482,    -1,   481,   482,
      -1,   176,    -1,   158,    -1,   481,   176,    -1,   481,   158,
      -1,   485,    -1,   489,    -1,   486,    -1,   202,    -1,   207,
      -1,   206,    -1,   205,    -1,   204,    -1,   203,    -1,   151,
      -1,   179,    -1,   140,    -1,    75,   153,   390,   184,    -1,
      75,   221,   153,   390,   184,    -1,    75,   220,   153,   390,
     184,    -1,    75,    76,   558,   153,   390,   184,    -1,   487,
     153,   184,    -1,   487,   153,   410,   184,    -1,   488,    -1,
     487,   488,    -1,   177,   650,    17,    -1,   177,    18,    -1,
     177,    19,    -1,   490,    -1,   490,   491,    -1,   192,   491,
      -1,   491,    -1,   191,    -1,   492,    -1,   492,   191,   491,
      -1,   492,   192,   491,    -1,   493,    -1,   502,    -1,   494,
      -1,   494,   503,    -1,   497,    -1,   497,   503,    -1,   495,
     499,    -1,   496,    -1,   105,   122,    -1,   114,   122,    -1,
      97,   122,    -1,   189,   122,    -1,   115,   122,    -1,   139,
     122,    -1,   138,   122,    -1,   499,    -1,    98,   499,    -1,
     498,   499,    -1,   120,    -1,   172,   122,    -1,    90,   122,
      -1,   181,   122,    -1,   180,   122,    -1,    91,   122,    -1,
     548,    -1,   500,    -1,   650,    -1,   501,    -1,   193,    -1,
      11,    -1,    12,    -1,    20,    -1,   505,    -1,   502,   503,
      -1,   502,   156,   187,    -1,   502,   156,   514,   187,    -1,
     504,    -1,   503,   504,    -1,   154,   410,   185,    -1,   506,
      -1,   508,    -1,   509,    -1,   510,    -1,   513,    -1,   515,
      -1,   511,    -1,   512,    -1,   561,    -1,   394,    -1,   637,
      -1,   634,    -1,   635,    -1,   636,    -1,   507,    -1,   560,
      -1,   110,    -1,   149,    -1,   124,    -1,   118,   650,    -1,
     156,   187,    -1,   156,   410,   187,    -1,   119,    -1,   169,
     153,   410,   184,    -1,   201,   153,   410,   184,    -1,   651,
     156,   187,    -1,   651,   156,   514,   187,    -1,   411,    -1,
     514,   107,   411,    -1,   516,    -1,   534,    -1,   517,    -1,
     531,    -1,   532,    -1,   157,   650,   521,   130,    -1,   157,
     650,   519,   521,   130,    -1,   157,   650,   521,   196,   194,
     650,   521,   196,    -1,   157,   650,   521,   196,   518,   194,
     650,   521,   196,    -1,   157,   650,   519,   521,   196,   194,
     650,   521,   196,    -1,   157,   650,   519,   521,   196,   518,
     194,   650,   521,   196,    -1,   529,    -1,   518,   529,    -1,
     520,    -1,   519,   520,    -1,    35,   650,   521,   132,   521,
     522,    -1,    -1,    35,    -1,   183,   523,   183,    -1,    93,
     525,    93,    -1,    -1,   524,    -1,   134,    -1,   527,    -1,
     524,   134,    -1,   524,   527,    -1,    -1,   526,    -1,   133,
      -1,   528,    -1,   526,   133,    -1,   526,   528,    -1,    28,
      -1,   530,    -1,     5,    -1,   530,    -1,   516,    -1,    10,
      -1,   533,    -1,   530,    -1,     9,    -1,   123,    -1,   125,
      -1,   153,   390,   184,    -1,   212,    30,   213,    -1,   212,
     213,    -1,   174,   649,   175,    -1,   174,   649,     8,    -1,
     103,     7,    -1,   535,    -1,   536,    -1,   537,    -1,   538,
      -1,   539,    -1,   540,    -1,    43,   153,   390,   184,    -1,
      21,   389,   184,    -1,    45,   153,   410,   184,   153,   389,
     184,    -1,    22,   389,   184,    -1,    97,   153,   410,   184,
     153,   389,   184,    -1,    70,   153,   390,   184,    -1,    39,
     153,   390,   184,    -1,    23,   389,   184,    -1,    59,   153,
     410,   184,   153,   389,   184,    -1,   547,    -1,   547,   144,
      -1,    94,   543,    -1,   545,    -1,   545,   544,    -1,   210,
     156,   187,    -1,   144,    -1,   193,    -1,   176,    -1,   547,
      -1,   548,    -1,   152,   156,   187,    -1,   319,   156,   187,
      -1,   564,    -1,   567,    -1,   644,    -1,   543,    -1,   546,
     107,   543,    -1,   650,    -1,   550,    -1,   556,    -1,   554,
      -1,   557,    -1,   555,    -1,   553,    -1,   552,    -1,   551,
      -1,   549,    -1,   224,   156,   187,    -1,    44,   156,   187,
      -1,    44,   156,   556,   187,    -1,    44,   156,   557,   187,
      -1,    70,   156,   187,    -1,    39,   156,   187,    -1,    59,
     156,   187,    -1,    59,   156,   649,   187,    -1,    59,   156,
      29,   187,    -1,    97,   156,   187,    -1,    97,   156,   650,
     187,    -1,    97,   156,   650,   107,   558,   187,    -1,    97,
     156,   193,   187,    -1,    97,   156,   193,   107,   558,   187,
      -1,    61,   156,   650,   187,    -1,    45,   156,   187,    -1,
      45,   156,   650,   187,    -1,    45,   156,   650,   107,   558,
     187,    -1,    45,   156,   650,   107,   559,   187,    -1,    45,
     156,   193,   187,    -1,    45,   156,   193,   107,   558,   187,
      -1,    45,   156,   193,   107,   559,   187,    -1,    62,   156,
     650,   187,    -1,   650,    -1,   650,   144,    -1,    29,    -1,
     562,    -1,   563,    -1,   650,   145,   149,    -1,    47,   378,
     395,    -1,   565,    -1,   566,    -1,    47,   156,   193,   187,
      -1,    47,   156,   187,    94,   543,    -1,    47,   156,   546,
     187,    94,   543,    -1,   156,   545,   187,    -1,    33,   219,
     220,    -1,    33,   219,   221,    -1,    33,   219,   222,    -1,
     225,   224,   411,   232,   411,    -1,   225,   224,   411,    94,
     231,   232,   411,    -1,   225,   224,   411,    94,   233,   232,
     411,    -1,   225,   224,   411,   217,   411,    -1,   225,   224,
     411,   218,   411,    -1,   225,   226,   411,   232,   411,    -1,
     225,   226,   411,    94,   231,   232,   411,    -1,   225,   226,
     411,    94,   233,   232,   411,    -1,   225,   226,   411,   217,
     411,    -1,   225,   226,   411,   218,   411,    -1,   223,   224,
     411,    -1,   223,   226,   411,    -1,   228,   224,   411,   236,
     411,    -1,   228,   229,   230,   224,   411,   236,   411,    -1,
     227,   224,   411,    94,   411,    -1,   235,   118,   574,   234,
     411,   186,   411,    -1,   575,    -1,   574,   107,   118,   575,
      -1,   650,   142,   411,    -1,   243,   153,   410,   184,   577,
      -1,   578,    -1,   577,   578,    -1,   244,   580,   579,    -1,
     153,   410,   184,    -1,   500,    -1,   580,   209,   500,    -1,
     584,   582,    -1,    -1,   583,    -1,   602,    -1,   583,   602,
      -1,   585,    -1,   584,   261,   585,    -1,   586,    -1,   585,
     257,   586,    -1,   587,    -1,   586,   259,   147,   587,    -1,
     588,    -1,   258,   588,    -1,   592,   589,   590,    -1,    -1,
     607,    -1,    -1,   591,    -1,   281,   153,   410,   184,    -1,
     596,   593,    -1,   156,   581,   187,    -1,   594,    -1,    -1,
     629,    -1,   487,   153,   595,   184,    -1,    -1,   581,    -1,
     597,   598,    -1,   506,    -1,   153,   410,   184,    -1,    -1,
     599,    -1,   247,   600,    -1,   246,   601,    -1,   269,    -1,
      -1,    78,    -1,    -1,   285,    -1,   603,    -1,   604,    -1,
     605,    -1,   631,    -1,   628,    -1,   169,    -1,   283,   472,
     606,    -1,   252,   630,   606,    -1,   285,    -1,   275,    -1,
     268,    -1,   245,   608,    -1,   607,   245,   608,    -1,   609,
      -1,   610,    -1,   611,    -1,   626,    -1,   612,    -1,   620,
      -1,   613,    -1,   627,    -1,   100,   273,    -1,   100,   262,
      -1,   265,    -1,   280,    -1,   250,   273,    -1,   250,   262,
      -1,    56,   650,    29,    -1,   276,    -1,    54,   276,    -1,
     278,   614,    -1,   278,   156,   614,   615,   187,    -1,    54,
     278,    -1,   617,    -1,   113,    -1,    -1,   107,   616,    -1,
     617,    -1,   616,   107,   617,    -1,    96,    29,   618,   619,
      -1,    -1,   270,    29,    -1,    -1,   630,   264,    -1,   277,
     285,   621,   623,    -1,   277,   285,   113,   623,    -1,    54,
     277,   285,    -1,    96,    29,    -1,   156,   622,   187,    -1,
      29,    -1,   622,   107,    29,    -1,    -1,   624,    -1,   625,
      -1,   624,   625,    -1,   200,   621,    -1,   136,   621,    -1,
     263,    29,    -1,   282,    -1,    54,   282,    -1,    96,   216,
      -1,    96,   253,    -1,   254,   249,    -1,   266,   630,   279,
      -1,   255,   472,    -1,    96,   129,   472,    -1,    96,    52,
     472,    -1,   256,   472,   198,   472,    -1,   271,   632,    -1,
     251,   632,    -1,   274,    -1,   267,    -1,   284,   249,   474,
      -1,   154,   185,    -1,   154,   410,   185,    -1,   309,   310,
      -1,   309,   410,   310,    -1,   311,   312,    -1,   311,   410,
     312,    -1,   153,   638,   184,    -1,   411,   121,   411,    -1,
     638,   107,   411,   121,   411,    -1,   225,   313,   411,   232,
     411,    -1,   225,   313,   411,   232,   411,    96,   315,   411,
      -1,   314,   313,   154,   410,   185,   198,   411,    -1,   223,
     313,   502,    -1,   227,   313,   502,    94,   411,    -1,   228,
     313,   229,   230,   502,   236,   411,    -1,   645,    -1,   646,
      -1,   647,    -1,   318,   156,   187,    -1,   316,   156,   187,
      -1,   317,   156,   187,    -1,    29,    -1,    16,    -1,   650,
      -1,   651,    -1,    97,    -1,    39,    -1,    44,    -1,    45,
      -1,   152,    -1,    48,    -1,   224,    -1,    59,    -1,    61,
      -1,    62,    -1,    70,    -1,    73,    -1,    72,    -1,   210,
      -1,   242,    -1,   652,    -1,    24,    -1,   214,    -1,   127,
      -1,    38,    -1,   260,    -1,    37,    -1,   221,    -1,   220,
      -1,   146,    -1,    43,    -1,   258,    -1,   259,    -1,   273,
      -1,   262,    -1,   250,    -1,   284,    -1,   276,    -1,   278,
      -1,   277,    -1,   282,    -1,   254,    -1,   249,    -1,    78,
      -1,   216,    -1,   253,    -1,    52,    -1,   222,    -1,   235,
      -1,   301,    -1,   229,    -1,   202,    -1,   207,    -1,   206,
      -1,   205,    -1,   204,    -1,   203,    -1,    96,    -1,   111,
      -1,   112,    -1,   186,    -1,    46,    -1,    36,    -1,    66,
      -1,    71,    -1,    58,    -1,    53,    -1,    55,    -1,    77,
      -1,    42,    -1,   147,    -1,    51,    -1,   211,    -1,   170,
      -1,   171,    -1,   168,    -1,    69,    -1,    95,    -1,   116,
      -1,   128,    -1,   129,    -1,   106,    -1,    67,    -1,   135,
      -1,   188,    -1,   100,    -1,    94,    -1,   197,    -1,   126,
      -1,   167,    -1,    92,    -1,    50,    -1,   230,    -1,   101,
      -1,   198,    -1,   117,    -1,   159,    -1,   200,    -1,   150,
      -1,   136,    -1,    75,    -1,    76,    -1,   102,    -1,   199,
      -1,   151,    -1,   182,    -1,   195,    -1,   160,    -1,   137,
      -1,   131,    -1,   166,    -1,   148,    -1,   165,    -1,    33,
      -1,    40,    -1,    57,    -1,   113,    -1,    41,    -1,    56,
      -1,   215,    -1,    49,    -1,    60,    -1,    34,    -1,    47,
      -1,   272,    -1,   248,    -1,   281,    -1,   283,    -1,   252,
      -1,   266,    -1,   279,    -1,   271,    -1,   251,    -1,   265,
      -1,   280,    -1,   270,    -1,   264,    -1,   263,    -1,   247,
      -1,   246,    -1,   255,    -1,   256,    -1,   285,    -1,   275,
      -1,   274,    -1,   269,    -1,   267,    -1,   268,    -1,   228,
      -1,   234,    -1,   231,    -1,   225,    -1,   218,    -1,   217,
      -1,   219,    -1,   236,    -1,   226,    -1,   227,    -1,   233,
      -1,   223,    -1,   232,    -1,    65,    -1,    63,    -1,    74,
      -1,   169,    -1,   201,    -1,   241,    -1,   239,    -1,   240,
      -1,   237,    -1,   238,    -1,   243,    -1,   244,    -1,   245,
      -1,    64,    -1,   294,    -1,   292,    -1,   293,    -1,   298,
      -1,   299,    -1,   300,    -1,   295,    -1,   296,    -1,   297,
      -1,    79,    -1,    80,    -1,    81,    -1,    82,    -1,    83,
      -1,    84,    -1,    85,    -1,    86,    -1,    87,    -1,    88,
      -1,    89,    -1,   286,    -1,   287,    -1,   288,    -1,   289,
      -1,   290,    -1,   291,    -1,   302,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,    90,
      -1,   105,    -1,   114,    -1,   172,    -1,   180,    -1,   189,
      -1,   138,    -1,    91,    -1,   115,    -1,   139,    -1,   181,
      -1,   313,    -1,   314,    -1,   315,    -1,   318,    -1,   317,
      -1,   316,    -1,   319,    -1,    25,    -1
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
    1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,  1520,
    1526,  1532,  1539,  1543,  1548,  1550,  1553,  1557,  1560,  1563,
    1565,  1568,  1571,  1573,  1575,  1577,  1581,  1585,  1587,  1589,
    1591,  1594,  1596,  1599,  1602,  1604,  1607,  1610,  1613,  1616,
    1619,  1622,  1625,  1627,  1630,  1633,  1635,  1638,  1641,  1644,
    1647,  1650,  1652,  1654,  1656,  1658,  1660,  1662,  1664,  1666,
    1668,  1671,  1675,  1680,  1682,  1685,  1689,  1691,  1693,  1695,
    1697,  1699,  1701,  1703,  1705,  1707,  1709,  1711,  1713,  1715,
    1717,  1719,  1721,  1723,  1725,  1727,  1730,  1733,  1737,  1739,
    1744,  1749,  1753,  1758,  1760,  1764,  1766,  1768,  1770,  1772,
    1774,  1779,  1785,  1794,  1804,  1814,  1825,  1827,  1830,  1832,
    1835,  1842,  1843,  1845,  1849,  1853,  1854,  1856,  1858,  1860,
    1863,  1866,  1867,  1869,  1871,  1873,  1876,  1879,  1881,  1883,
    1885,  1887,  1889,  1891,  1893,  1895,  1897,  1899,  1901,  1905,
    1909,  1912,  1916,  1920,  1923,  1925,  1927,  1929,  1931,  1933,
    1935,  1940,  1944,  1952,  1956,  1964,  1969,  1974,  1978,  1986,
    1988,  1991,  1994,  1996,  1999,  2003,  2005,  2007,  2009,  2011,
    2013,  2017,  2021,  2023,  2025,  2027,  2029,  2033,  2035,  2037,
    2039,  2041,  2043,  2045,  2047,  2049,  2051,  2053,  2057,  2061,
    2066,  2071,  2075,  2079,  2083,  2088,  2093,  2097,  2102,  2109,
    2114,  2121,  2126,  2130,  2135,  2142,  2149,  2154,  2161,  2168,
    2173,  2175,  2178,  2180,  2182,  2184,  2188,  2192,  2194,  2196,
    2201,  2207,  2214,  2218,  2222,  2226,  2230,  2236,  2244,  2252,
    2258,  2264,  2270,  2278,  2286,  2292,  2298,  2302,  2306,  2312,
    2320,  2326,  2334,  2336,  2341,  2345,  2351,  2353,  2356,  2360,
    2364,  2366,  2370,  2373,  2374,  2376,  2378,  2381,  2383,  2387,
    2389,  2393,  2395,  2400,  2402,  2405,  2409,  2410,  2412,  2413,
    2415,  2420,  2423,  2427,  2429,  2430,  2432,  2437,  2438,  2440,
    2443,  2445,  2449,  2450,  2452,  2455,  2458,  2460,  2461,  2463,
    2464,  2466,  2468,  2470,  2472,  2474,  2476,  2478,  2482,  2486,
    2488,  2490,  2492,  2495,  2499,  2501,  2503,  2505,  2507,  2509,
    2511,  2513,  2515,  2518,  2521,  2523,  2525,  2528,  2531,  2535,
    2537,  2540,  2543,  2549,  2552,  2554,  2556,  2557,  2560,  2562,
    2566,  2571,  2572,  2575,  2576,  2579,  2584,  2589,  2593,  2596,
    2600,  2602,  2606,  2607,  2609,  2611,  2614,  2617,  2620,  2623,
    2625,  2628,  2631,  2634,  2637,  2641,  2644,  2648,  2652,  2657,
    2660,  2663,  2665,  2667,  2671,  2674,  2678,  2681,  2685,  2688,
    2692,  2696,  2700,  2706,  2712,  2721,  2729,  2733,  2739,  2747,
    2749,  2751,  2753,  2757,  2761,  2765,  2767,  2769,  2771,  2773,
    2775,  2777,  2779,  2781,  2783,  2785,  2787,  2789,  2791,  2793,
    2795,  2797,  2799,  2801,  2803,  2805,  2807,  2809,  2811,  2813,
    2815,  2817,  2819,  2821,  2823,  2825,  2827,  2829,  2831,  2833,
    2835,  2837,  2839,  2841,  2843,  2845,  2847,  2849,  2851,  2853,
    2855,  2857,  2859,  2861,  2863,  2865,  2867,  2869,  2871,  2873,
    2875,  2877,  2879,  2881,  2883,  2885,  2887,  2889,  2891,  2893,
    2895,  2897,  2899,  2901,  2903,  2905,  2907,  2909,  2911,  2913,
    2915,  2917,  2919,  2921,  2923,  2925,  2927,  2929,  2931,  2933,
    2935,  2937,  2939,  2941,  2943,  2945,  2947,  2949,  2951,  2953,
    2955,  2957,  2959,  2961,  2963,  2965,  2967,  2969,  2971,  2973,
    2975,  2977,  2979,  2981,  2983,  2985,  2987,  2989,  2991,  2993,
    2995,  2997,  2999,  3001,  3003,  3005,  3007,  3009,  3011,  3013,
    3015,  3017,  3019,  3021,  3023,  3025,  3027,  3029,  3031,  3033,
    3035,  3037,  3039,  3041,  3043,  3045,  3047,  3049,  3051,  3053,
    3055,  3057,  3059,  3061,  3063,  3065,  3067,  3069,  3071,  3073,
    3075,  3077,  3079,  3081,  3083,  3085,  3087,  3089,  3091,  3093,
    3095,  3097,  3099,  3101,  3103,  3105,  3107,  3109,  3111,  3113,
    3115,  3117,  3119,  3121,  3123,  3125,  3127,  3129,  3131,  3133,
    3135,  3137,  3139,  3141,  3143,  3145,  3147,  3149,  3151,  3153,
    3155,  3157,  3159,  3161,  3163,  3165,  3167,  3169,  3171,  3173,
    3175,  3177,  3179,  3181,  3183,  3185,  3187,  3189,  3191,  3193,
    3195,  3197,  3199,  3201,  3203,  3205,  3207,  3209,  3211,  3213,
    3215
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  xquery_parser::yyrline_[] =
  {
         0,  1039,  1039,  1040,  1044,  1048,  1059,  1068,  1074,  1082,
    1088,  1099,  1104,  1112,  1119,  1126,  1135,  1142,  1150,  1158,
    1166,  1177,  1182,  1189,  1196,  1208,  1218,  1225,  1232,  1244,
    1245,  1246,  1247,  1248,  1253,  1254,  1255,  1256,  1257,  1258,
    1259,  1262,  1267,  1272,  1280,  1288,  1296,  1301,  1309,  1314,
    1322,  1327,  1335,  1342,  1349,  1356,  1366,  1368,  1371,  1381,
    1386,  1394,  1402,  1413,  1420,  1431,  1436,  1444,  1451,  1458,
    1467,  1480,  1488,  1495,  1505,  1512,  1519,  1530,  1531,  1532,
    1533,  1534,  1535,  1536,  1537,  1542,  1548,  1557,  1564,  1574,
    1584,  1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,
    1598,  1606,  1614,  1622,  1629,  1637,  1644,  1649,  1657,  1665,
    1679,  1693,  1710,  1715,  1723,  1731,  1742,  1747,  1756,  1761,
    1768,  1773,  1783,  1788,  1797,  1803,  1816,  1821,  1829,  1840,
    1855,  1867,  1882,  1887,  1892,  1897,  1905,  1912,  1923,  1928,
    1938,  1945,  1952,  1959,  1969,  1973,  1979,  1983,  1993,  2001,
    2012,  2018,  2027,  2032,  2039,  2046,  2057,  2067,  2077,  2087,
    2105,  2125,  2129,  2134,  2141,  2145,  2150,  2157,  2162,  2174,
    2181,  2193,  2194,  2195,  2196,  2197,  2198,  2199,  2201,  2202,
    2203,  2204,  2205,  2210,  2215,  2223,  2240,  2248,  2256,  2263,
    2270,  2281,  2290,  2299,  2308,  2321,  2329,  2337,  2345,  2360,
    2365,  2373,  2387,  2404,  2429,  2437,  2444,  2455,  2465,  2470,
    2485,  2486,  2487,  2488,  2489,  2490,  2495,  2496,  2499,  2500,
    2501,  2502,  2503,  2506,  2507,  2508,  2509,  2510,  2515,  2529,
    2537,  2542,  2550,  2555,  2560,  2568,  2577,  2589,  2599,  2612,
    2620,  2621,  2622,  2627,  2628,  2629,  2630,  2631,  2636,  2643,
    2653,  2659,  2668,  2678,  2685,  2693,  2705,  2715,  2725,  2735,
    2745,  2755,  2765,  2775,  2786,  2795,  2805,  2815,  2831,  2840,
    2849,  2857,  2863,  2875,  2883,  2893,  2901,  2913,  2919,  2930,
    2932,  2936,  2944,  2948,  2953,  2957,  2961,  2965,  2975,  2983,
    2990,  2996,  3006,  3010,  3014,  3022,  3030,  3038,  3050,  3058,
    3064,  3074,  3080,  3090,  3094,  3104,  3110,  3116,  3122,  3131,
    3140,  3149,  3162,  3166,  3174,  3180,  3190,  3198,  3207,  3220,
    3227,  3239,  3243,  3255,  3262,  3268,  3277,  3284,  3290,  3301,
    3308,  3314,  3323,  3332,  3339,  3350,  3357,  3369,  3375,  3387,
    3393,  3404,  3410,  3421,  3427,  3438,  3447,  3451,  3460,  3464,
    3472,  3476,  3486,  3493,  3502,  3512,  3511,  3525,  3534,  3543,
    3556,  3560,  3572,  3576,  3584,  3587,  3594,  3598,  3607,  3611,
    3615,  3623,  3627,  3633,  3639,  3645,  3655,  3659,  3663,  3671,
    3675,  3681,  3691,  3695,  3705,  3709,  3719,  3723,  3733,  3737,
    3747,  3751,  3759,  3763,  3767,  3771,  3781,  3785,  3789,  3797,
    3801,  3805,  3809,  3813,  3817,  3825,  3829,  3833,  3841,  3845,
    3849,  3853,  3864,  3870,  3880,  3886,  3896,  3900,  3904,  3942,
    3946,  3956,  3966,  3979,  3988,  3998,  4002,  4011,  4015,  4024,
    4030,  4038,  4044,  4056,  4062,  4072,  4076,  4080,  4084,  4088,
    4094,  4100,  4108,  4112,  4120,  4124,  4135,  4139,  4143,  4149,
    4153,  4167,  4171,  4179,  4183,  4193,  4197,  4201,  4205,  4214,
    4218,  4222,  4226,  4234,  4240,  4250,  4258,  4262,  4266,  4270,
    4274,  4278,  4282,  4286,  4290,  4294,  4299,  4303,  4307,  4311,
    4319,  4323,  4331,  4338,  4345,  4356,  4364,  4368,  4376,  4384,
    4392,  4446,  4450,  4463,  4469,  4479,  4483,  4491,  4495,  4499,
    4507,  4517,  4527,  4544,  4561,  4578,  4600,  4606,  4617,  4623,
    4634,  4645,  4647,  4651,  4656,  4666,  4669,  4676,  4682,  4688,
    4696,  4709,  4712,  4719,  4725,  4731,  4738,  4749,  4753,  4763,
    4767,  4777,  4781,  4785,  4790,  4799,  4805,  4811,  4817,  4825,
    4830,  4838,  4843,  4851,  4859,  4864,  4869,  4874,  4879,  4884,
    4893,  4901,  4905,  4922,  4926,  4934,  4942,  4950,  4954,  4962,
    4968,  4978,  4986,  4990,  4994,  5029,  5035,  5041,  5051,  5055,
    5059,  5063,  5067,  5071,  5075,  5082,  5088,  5098,  5106,  5110,
    5114,  5118,  5122,  5126,  5130,  5134,  5138,  5146,  5154,  5158,
    5162,  5172,  5180,  5188,  5192,  5196,  5204,  5208,  5214,  5220,
    5224,  5234,  5242,  5246,  5252,  5261,  5270,  5276,  5282,  5292,
    5309,  5316,  5331,  5367,  5371,  5379,  5387,  5399,  5403,  5411,
    5419,  5423,  5434,  5451,  5457,  5463,  5473,  5477,  5483,  5489,
    5493,  5499,  5503,  5509,  5515,  5522,  5532,  5537,  5545,  5551,
    5561,  5583,  5592,  5598,  5611,  5625,  5632,  5638,  5648,  5657,
    5665,  5671,  5689,  5697,  5701,  5708,  5713,  5721,  5725,  5732,
    5736,  5743,  5747,  5754,  5758,  5767,  5780,  5783,  5791,  5794,
    5802,  5810,  5818,  5822,  5830,  5833,  5841,  5853,  5856,  5864,
    5876,  5882,  5892,  5895,  5903,  5907,  5911,  5919,  5922,  5930,
    5933,  5941,  5945,  5949,  5953,  5957,  5965,  5973,  5985,  5997,
    6001,  6005,  6013,  6019,  6029,  6033,  6037,  6041,  6045,  6049,
    6053,  6057,  6065,  6069,  6073,  6077,  6085,  6091,  6101,  6111,
    6115,  6123,  6133,  6144,  6151,  6155,  6163,  6166,  6173,  6178,
    6187,  6197,  6200,  6207,  6211,  6219,  6228,  6235,  6245,  6249,
    6256,  6262,  6272,  6275,  6282,  6287,  6299,  6307,  6319,  6327,
    6331,  6339,  6343,  6347,  6355,  6363,  6367,  6371,  6375,  6383,
    6391,  6403,  6407,  6415,  6429,  6433,  6440,  6445,  6453,  6458,
    6467,  6475,  6481,  6491,  6497,  6504,  6511,  6540,  6569,  6598,
    6602,  6606,  6613,  6620,  6627,  6639,  6643,  6644,  6657,  6658,
    6659,  6660,  6661,  6662,  6663,  6664,  6665,  6666,  6667,  6668,
    6669,  6670,  6671,  6672,  6676,  6677,  6678,  6679,  6680,  6681,
    6682,  6683,  6684,  6685,  6686,  6687,  6688,  6689,  6690,  6691,
    6692,  6693,  6694,  6695,  6696,  6697,  6698,  6699,  6700,  6701,
    6702,  6703,  6704,  6705,  6706,  6707,  6708,  6709,  6710,  6711,
    6712,  6713,  6714,  6715,  6716,  6717,  6718,  6719,  6720,  6721,
    6722,  6723,  6724,  6725,  6726,  6727,  6728,  6729,  6730,  6731,
    6732,  6733,  6734,  6735,  6736,  6737,  6738,  6739,  6740,  6741,
    6742,  6743,  6744,  6745,  6746,  6747,  6748,  6749,  6750,  6751,
    6752,  6753,  6754,  6755,  6756,  6757,  6758,  6759,  6760,  6761,
    6762,  6763,  6764,  6765,  6766,  6767,  6768,  6769,  6770,  6771,
    6772,  6773,  6774,  6775,  6776,  6777,  6778,  6779,  6780,  6781,
    6782,  6783,  6784,  6785,  6786,  6787,  6788,  6789,  6790,  6791,
    6792,  6793,  6794,  6795,  6796,  6797,  6798,  6799,  6800,  6801,
    6802,  6803,  6804,  6805,  6806,  6807,  6808,  6809,  6810,  6811,
    6812,  6813,  6814,  6815,  6816,  6817,  6818,  6819,  6820,  6821,
    6822,  6823,  6824,  6825,  6826,  6827,  6828,  6829,  6830,  6831,
    6832,  6833,  6834,  6835,  6836,  6837,  6838,  6839,  6840,  6841,
    6842,  6843,  6844,  6845,  6846,  6847,  6848,  6849,  6850,  6851,
    6852,  6853,  6854,  6855,  6856,  6857,  6858,  6859,  6860,  6861,
    6862,  6863,  6864,  6865,  6866,  6867,  6868,  6869,  6870,  6871,
    6872,  6873,  6874,  6875,  6876,  6877,  6878,  6879,  6880,  6881,
    6886
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
     325,   326,   327,   328,   329,   330,   331
    };
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int xquery_parser::yyeof_ = 0;
  const int xquery_parser::yylast_ = 15882;
  const int xquery_parser::yynnts_ = 321;
  const int xquery_parser::yyempty_ = -2;
  const int xquery_parser::yyfinal_ = 607;
  const int xquery_parser::yyterror_ = 1;
  const int xquery_parser::yyerrcode_ = 256;
  const int xquery_parser::yyntokens_ = 332;

  const unsigned int xquery_parser::yyuser_token_number_max_ = 586;
  const xquery_parser::token_number_type xquery_parser::yyundef_token_ = 2;


} // zorba
/* Line 1106 of lalr1.cc  */
#line 15871 "/Users/zorba/Code/zorba/debug/src/compiler/parser/xquery_parser.cpp"
/* Line 1107 of lalr1.cc  */
#line 6890 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"


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
