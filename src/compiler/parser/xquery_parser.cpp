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
#line 75 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"


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
#line 102 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"


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
#line 197 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"

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
#line 303 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 124: /* "'DOUBLE'" */
/* Line 453 of lalr1.cc  */
#line 903 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).dval); };
/* Line 453 of lalr1.cc  */
#line 310 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 149: /* "'INTEGER'" */
/* Line 453 of lalr1.cc  */
#line 902 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).ival); };
/* Line 453 of lalr1.cc  */
#line 317 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 336: /* VersionDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 324 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 337: /* MainModule */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 331 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 338: /* LibraryModule */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 338 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 339: /* ModuleDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 345 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 340: /* SIND_DeclList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 352 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 341: /* SIND_Decl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 359 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 342: /* Setter */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 366 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 343: /* BoundarySpaceDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 373 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 344: /* DefaultCollationDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 380 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 345: /* BaseURIDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 387 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 346: /* ConstructionDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 394 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 347: /* OrderingModeDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 401 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 348: /* EmptyOrderDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 408 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 349: /* CopyNamespacesDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 415 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 350: /* Import */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 422 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 351: /* SchemaImport */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 429 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 352: /* URILiteralList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 436 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 353: /* SchemaPrefix */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 443 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 354: /* ModuleImport */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 450 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 355: /* NamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 457 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 356: /* DefaultNamespaceDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 464 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 357: /* VFO_DeclList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 471 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 358: /* VFO_Decl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 478 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 359: /* DecimalFormatDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 485 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 360: /* DecimalFormatParamList */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).vstrpair); };
/* Line 453 of lalr1.cc  */
#line 492 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 361: /* DecimalFormatParam */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).strpair); };
/* Line 453 of lalr1.cc  */
#line 499 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 363: /* OptionDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 506 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 364: /* FTOptionDecl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 513 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 365: /* CtxItemDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 520 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 366: /* CtxItemDecl2 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 527 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 367: /* CtxItemDecl3 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 534 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 368: /* CtxItemDecl4 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 541 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 369: /* VarDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 548 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 370: /* VarNameAndType */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).varnametype); };
/* Line 453 of lalr1.cc  */
#line 555 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 371: /* AnnotationList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 562 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 372: /* Annotation */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 569 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 373: /* AnnotationLiteralList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 576 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 374: /* FunctionDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 583 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 375: /* FunctionDecl2 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 590 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 376: /* FunctionDeclSimple */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 597 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 377: /* FunctionDeclUpdating */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 604 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 378: /* FunctionSig */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).fnsig); };
/* Line 453 of lalr1.cc  */
#line 611 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 379: /* ParamList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 618 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 380: /* Param */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 625 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 381: /* CollectionDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 632 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 383: /* IndexDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 639 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 384: /* IndexKeyList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 646 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 385: /* IndexKeySpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 653 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 386: /* IntegrityConstraintDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 660 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 387: /* QueryBody */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 667 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 388: /* StatementsAndOptionalExprTop */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 674 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 389: /* StatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 681 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 390: /* StatementsAndExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 688 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 391: /* Statements */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 695 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 392: /* Statement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 702 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 393: /* BlockStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 709 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 394: /* BlockExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 716 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 395: /* EnclosedStatementsAndOptionalExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 723 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 396: /* VarDeclStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 730 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 399: /* AssignStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 737 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 400: /* ApplyStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 744 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 401: /* ExitStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 751 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 402: /* WhileStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 758 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 403: /* FlowCtlStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 765 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 404: /* FLWORStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 772 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 405: /* ReturnStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 779 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 406: /* IfStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 786 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 407: /* TryStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 793 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 408: /* CatchListStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 800 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 409: /* CatchStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 807 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 410: /* Expr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 814 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 411: /* ExprSingle */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 821 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 412: /* ExprSimple */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 828 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 413: /* FLWORExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 835 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 414: /* ReturnExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 842 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 417: /* FLWORWinCond */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 849 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 418: /* WindowClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 856 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 419: /* CountClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 863 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 420: /* ForLetWinClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 870 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 422: /* FLWORClauseList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 877 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 423: /* ForClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 884 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 424: /* VarInDeclList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 891 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 425: /* VarInDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 898 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 426: /* PositionalVar */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 905 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 427: /* FTScoreVar */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 912 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 428: /* LetClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 919 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 429: /* VarGetsDeclList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 926 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 430: /* VarGetsDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 933 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 431: /* WindowVarDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 940 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 432: /* WindowVars */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 947 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 433: /* WindowVars3 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 954 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 434: /* WindowVars2 */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 961 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 435: /* WhereClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 968 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 436: /* GroupByClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 975 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 437: /* GroupSpecList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 982 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 438: /* GroupSpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 989 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 439: /* GroupCollationSpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 996 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 440: /* OrderByClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1003 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 441: /* OrderSpecList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1010 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 442: /* OrderSpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1017 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 443: /* OrderModifier */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1024 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 444: /* OrderDirSpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1031 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 445: /* OrderEmptySpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1038 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 446: /* OrderCollationSpec */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1045 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 447: /* QuantifiedExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1052 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 448: /* QVarInDeclList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1059 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 449: /* QVarInDecl */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1066 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 450: /* SwitchExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1073 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 451: /* SwitchCaseClauseList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1080 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 452: /* SwitchCaseClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1087 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 453: /* SwitchCaseOperandList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1094 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 454: /* SwitchStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1101 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 457: /* TypeswitchExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1108 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 458: /* TypeswitchStatement */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1115 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 459: /* CaseClauseList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1122 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 460: /* CaseClause */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1129 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 463: /* IfExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1136 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 464: /* OrExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1143 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 465: /* AndExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1150 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 466: /* ComparisonExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1157 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 468: /* FTContainsExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1164 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 469: /* StringConcatExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1171 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 470: /* opt_FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1178 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 471: /* RangeExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1185 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 472: /* AdditiveExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1192 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 473: /* MultiplicativeExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1199 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 474: /* UnionExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1206 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 475: /* IntersectExceptExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1213 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 476: /* InstanceofExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1220 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 477: /* TreatExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1227 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 478: /* CastableExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1234 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 479: /* CastExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1241 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 480: /* UnaryExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1248 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 481: /* SignList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1255 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 482: /* ValueExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1262 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 483: /* ValueComp */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1269 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 484: /* NodeComp */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1276 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 485: /* ValidateExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1283 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 486: /* ExtensionExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1290 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 487: /* Pragma_list */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1297 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 488: /* Pragma */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1304 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 489: /* PathExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1311 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 491: /* RelativePathExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1318 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 492: /* StepExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1325 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 493: /* AxisStep */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1332 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 494: /* ForwardStep */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1339 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 495: /* ForwardAxis */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1346 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 496: /* AbbrevForwardStep */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1353 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 497: /* ReverseStep */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1360 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 498: /* ReverseAxis */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1367 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 499: /* NodeTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1374 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 500: /* NameTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1381 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 501: /* Wildcard */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1388 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 502: /* FilterExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1395 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 503: /* PredicateList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1402 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 504: /* Predicate */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1409 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 505: /* PrimaryExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1416 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 506: /* Literal */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1423 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 507: /* NumericLiteral */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1430 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 508: /* VarRef */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1437 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 509: /* ParenthesizedExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1444 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 510: /* ContextItemExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1451 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 511: /* OrderedExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1458 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 512: /* UnorderedExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1465 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 513: /* FunctionCall */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1472 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 514: /* ArgList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1479 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 515: /* Constructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1486 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 516: /* DirectConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1493 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 517: /* DirElemConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1500 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 518: /* DirElemContentList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1507 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 519: /* DirAttributeList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1514 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 520: /* DirAttr */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1521 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 522: /* DirAttributeValue */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1528 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 523: /* opt_QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1535 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 524: /* QuoteAttrContentList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1542 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 525: /* opt_AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1549 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 526: /* AposAttrContentList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1556 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 527: /* QuoteAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1563 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 528: /* AposAttrValueContent */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1570 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 529: /* DirElemContent */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1577 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 530: /* CommonContent */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1584 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 531: /* DirCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1591 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 532: /* DirPIConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1598 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 533: /* CDataSection */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1605 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 534: /* ComputedConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1612 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 535: /* CompDocConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1619 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 536: /* CompElemConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1626 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 537: /* CompAttrConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1633 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 538: /* CompTextConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1640 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 539: /* CompCommentConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1647 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 540: /* CompPIConstructor */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1654 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 541: /* SingleType */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1661 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 542: /* TypeDeclaration */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1668 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 543: /* SequenceType */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1675 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 544: /* OccurrenceIndicator */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1682 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 545: /* ItemType */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1689 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 546: /* TypeList */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1696 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 547: /* AtomicType */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1703 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 548: /* KindTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1710 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 549: /* AnyKindTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1717 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 550: /* DocumentTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1724 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 551: /* TextTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1731 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 552: /* CommentTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1738 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 553: /* PITest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1745 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 554: /* AttributeTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1752 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 555: /* SchemaAttributeTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1759 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 556: /* ElementTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1766 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 557: /* SchemaElementTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1773 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 558: /* TypeName */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1780 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 559: /* TypeName_WITH_HOOK */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1787 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 560: /* StringLiteral */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1794 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 565: /* AnyFunctionTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1801 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 566: /* TypedFunctionTest */
/* Line 453 of lalr1.cc  */
#line 918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1808 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 569: /* InsertExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1815 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 570: /* DeleteExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1822 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 571: /* ReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1829 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 572: /* RenameExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1836 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 573: /* TransformExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1843 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 574: /* VarNameList */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1850 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 575: /* VarNameDecl */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1857 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 576: /* TryExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1864 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 577: /* CatchListExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1871 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 578: /* CatchExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1878 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 579: /* BracedExpr */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 1885 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 580: /* NameTestList */
/* Line 453 of lalr1.cc  */
#line 930 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ delete ((*yyvaluep).name_test_list); };
/* Line 453 of lalr1.cc  */
#line 1892 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 581: /* FTSelection */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1899 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 584: /* FTOr */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1906 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 585: /* FTAnd */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1913 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 586: /* FTMildNot */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1920 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 587: /* FTUnaryNot */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1927 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 588: /* FTPrimaryWithOptions */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1934 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 589: /* opt_FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1941 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 591: /* FTWeight */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1948 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 592: /* FTPrimary */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1955 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 593: /* opt_FTTimes */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1962 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 594: /* FTExtensionSelection */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1969 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 596: /* FTWords */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1976 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 597: /* FTWordsValue */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1983 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 599: /* FTAnyallOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1990 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 602: /* FTPosFilter */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 1997 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 603: /* FTOrder */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2004 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 604: /* FTWindow */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2011 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 605: /* FTDistance */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2018 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 606: /* FTUnit */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2025 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 607: /* FTMatchOptions */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2032 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 608: /* FTMatchOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2039 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 609: /* FTCaseOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2046 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 610: /* FTDiacriticsOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2053 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 611: /* FTExtensionOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2060 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 612: /* FTStemOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2067 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 613: /* FTThesaurusOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2074 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 617: /* FTThesaurusID */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2081 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 620: /* FTStopWordOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2088 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 621: /* FTStopWords */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2095 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 625: /* FTStopWordsInclExcl */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2102 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 626: /* FTLanguageOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2109 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 627: /* FTWildCardOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2116 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 628: /* FTContent */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2123 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 629: /* FTTimes */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2130 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 630: /* FTRange */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2137 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 631: /* FTScope */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2144 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 632: /* FTBigUnit */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2151 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 633: /* FTIgnoreOption */
/* Line 453 of lalr1.cc  */
#line 921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2158 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 634: /* JSONArrayConstructor */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2165 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 635: /* JSONSimpleObjectUnion */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2172 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 636: /* JSONAccumulatorObjectUnion */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2179 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 637: /* JSONObjectConstructor */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2186 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 638: /* JSONPairList */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).node) ); };
/* Line 453 of lalr1.cc  */
#line 2193 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 639: /* JSONInsertExpr */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2200 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 640: /* JSONAppendExpr */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2207 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 641: /* JSONDeleteExpr */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2214 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 642: /* JSONRenameExpr */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2221 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 643: /* JSONReplaceExpr */
/* Line 453 of lalr1.cc  */
#line 924 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2228 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 650: /* QNAME */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2235 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 651: /* FUNCTION_NAME */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2242 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
	break;
      case 652: /* EQNAME */
/* Line 453 of lalr1.cc  */
#line 927 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
	{ release_hack( ((*yyvaluep).expr) ); };
/* Line 453 of lalr1.cc  */
#line 2249 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
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
#line 2344 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"

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

  case 210:
/* Line 661 of lalr1.cc  */
#line 2483 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr); // to prevent the Bison warning
      (yyval.expr) = (yysemantic_stack_[(4) - (3)].expr); // to prevent the Bison warning
      error((yylocation_stack_[(4) - (2)]), "syntax error, unexpected ExprSingle (missing comma \",\" between expressions?)");
      YYERROR;
    }
    break;

  case 211:
/* Line 661 of lalr1.cc  */
#line 2490 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2533 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2547 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 232:
/* Line 661 of lalr1.cc  */
#line 2555 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 233:
/* Line 661 of lalr1.cc  */
#line 2560 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 234:
/* Line 661 of lalr1.cc  */
#line 2568 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 235:
/* Line 661 of lalr1.cc  */
#line 2573 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 236:
/* Line 661 of lalr1.cc  */
#line 2578 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 237:
/* Line 661 of lalr1.cc  */
#line 2586 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2595 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2607 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2617 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2630 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 250:
/* Line 661 of lalr1.cc  */
#line 2654 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 251:
/* Line 661 of lalr1.cc  */
#line 2661 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 252:
/* Line 661 of lalr1.cc  */
#line 2671 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 253:
/* Line 661 of lalr1.cc  */
#line 2677 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2686 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = NULL; // to prevent the Bison warning
      error((yylocation_stack_[(2) - (2)]), ""); // the error message is already set in the driver's parseError member
      YYERROR;
    }
    break;

  case 255:
/* Line 661 of lalr1.cc  */
#line 2696 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 256:
/* Line 661 of lalr1.cc  */
#line 2703 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 257:
/* Line 661 of lalr1.cc  */
#line 2711 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2723 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2733 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2743 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2753 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2763 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2773 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2783 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2793 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2804 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2813 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2823 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2833 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2849 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 271:
/* Line 661 of lalr1.cc  */
#line 2858 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 272:
/* Line 661 of lalr1.cc  */
#line 2867 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 273:
/* Line 661 of lalr1.cc  */
#line 2875 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 274:
/* Line 661 of lalr1.cc  */
#line 2881 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 275:
/* Line 661 of lalr1.cc  */
#line 2893 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2901 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2911 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2919 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 2931 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 280:
/* Line 661 of lalr1.cc  */
#line 2937 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 282:
/* Line 661 of lalr1.cc  */
#line 2950 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 283:
/* Line 661 of lalr1.cc  */
#line 2954 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 284:
/* Line 661 of lalr1.cc  */
#line 2962 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 285:
/* Line 661 of lalr1.cc  */
#line 2966 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 287:
/* Line 661 of lalr1.cc  */
#line 2975 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 288:
/* Line 661 of lalr1.cc  */
#line 2979 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 289:
/* Line 661 of lalr1.cc  */
#line 2983 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 290:
/* Line 661 of lalr1.cc  */
#line 2993 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 291:
/* Line 661 of lalr1.cc  */
#line 3001 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 292:
/* Line 661 of lalr1.cc  */
#line 3008 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 293:
/* Line 661 of lalr1.cc  */
#line 3014 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 294:
/* Line 661 of lalr1.cc  */
#line 3024 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 295:
/* Line 661 of lalr1.cc  */
#line 3028 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 296:
/* Line 661 of lalr1.cc  */
#line 3032 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3040 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3048 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3056 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3068 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 301:
/* Line 661 of lalr1.cc  */
#line 3076 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 302:
/* Line 661 of lalr1.cc  */
#line 3082 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 303:
/* Line 661 of lalr1.cc  */
#line 3092 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 304:
/* Line 661 of lalr1.cc  */
#line 3098 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 305:
/* Line 661 of lalr1.cc  */
#line 3108 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 306:
/* Line 661 of lalr1.cc  */
#line 3112 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 307:
/* Line 661 of lalr1.cc  */
#line 3122 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 308:
/* Line 661 of lalr1.cc  */
#line 3128 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 309:
/* Line 661 of lalr1.cc  */
#line 3134 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 310:
/* Line 661 of lalr1.cc  */
#line 3140 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3149 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3158 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3167 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3180 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 315:
/* Line 661 of lalr1.cc  */
#line 3184 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 316:
/* Line 661 of lalr1.cc  */
#line 3192 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 317:
/* Line 661 of lalr1.cc  */
#line 3198 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 318:
/* Line 661 of lalr1.cc  */
#line 3208 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 319:
/* Line 661 of lalr1.cc  */
#line 3216 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3225 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3238 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 322:
/* Line 661 of lalr1.cc  */
#line 3245 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 323:
/* Line 661 of lalr1.cc  */
#line 3257 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 324:
/* Line 661 of lalr1.cc  */
#line 3261 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 325:
/* Line 661 of lalr1.cc  */
#line 3273 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 326:
/* Line 661 of lalr1.cc  */
#line 3280 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 327:
/* Line 661 of lalr1.cc  */
#line 3286 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 328:
/* Line 661 of lalr1.cc  */
#line 3295 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 329:
/* Line 661 of lalr1.cc  */
#line 3302 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 330:
/* Line 661 of lalr1.cc  */
#line 3308 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 331:
/* Line 661 of lalr1.cc  */
#line 3319 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 332:
/* Line 661 of lalr1.cc  */
#line 3326 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 333:
/* Line 661 of lalr1.cc  */
#line 3332 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 334:
/* Line 661 of lalr1.cc  */
#line 3341 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 335:
/* Line 661 of lalr1.cc  */
#line 3350 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 336:
/* Line 661 of lalr1.cc  */
#line 3357 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3368 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              dynamic_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 338:
/* Line 661 of lalr1.cc  */
#line 3375 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3387 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 340:
/* Line 661 of lalr1.cc  */
#line 3393 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:
/* Line 661 of lalr1.cc  */
#line 3405 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 342:
/* Line 661 of lalr1.cc  */
#line 3411 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 343:
/* Line 661 of lalr1.cc  */
#line 3422 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 344:
/* Line 661 of lalr1.cc  */
#line 3428 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(dynamic_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 345:
/* Line 661 of lalr1.cc  */
#line 3439 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 346:
/* Line 661 of lalr1.cc  */
#line 3445 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          dynamic_cast<SequenceType*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 347:
/* Line 661 of lalr1.cc  */
#line 3456 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 348:
/* Line 661 of lalr1.cc  */
#line 3465 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 349:
/* Line 661 of lalr1.cc  */
#line 3469 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 350:
/* Line 661 of lalr1.cc  */
#line 3478 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 351:
/* Line 661 of lalr1.cc  */
#line 3482 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 352:
/* Line 661 of lalr1.cc  */
#line 3490 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 353:
/* Line 661 of lalr1.cc  */
#line 3494 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3504 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            /*  ::=  "is" | "<<" | ">>" */
            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)), dynamic_cast<NodeComp*>((yysemantic_stack_[(3) - (2)].node)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 355:
/* Line 661 of lalr1.cc  */
#line 3511 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3520 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3529 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            /* this call is needed */
            driver.lexer->interpretAsLessThan();
        }
    break;

  case 358:
/* Line 661 of lalr1.cc  */
#line 3534 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3543 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3552 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3561 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3574 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 363:
/* Line 661 of lalr1.cc  */
#line 3578 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
#line 3590 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 365:
/* Line 661 of lalr1.cc  */
#line 3594 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 366:
/* Line 661 of lalr1.cc  */
#line 3601 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 367:
/* Line 661 of lalr1.cc  */
#line 3605 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 368:
/* Line 661 of lalr1.cc  */
#line 3612 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 369:
/* Line 661 of lalr1.cc  */
#line 3616 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 370:
/* Line 661 of lalr1.cc  */
#line 3625 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 371:
/* Line 661 of lalr1.cc  */
#line 3629 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 372:
/* Line 661 of lalr1.cc  */
#line 3633 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:
/* Line 661 of lalr1.cc  */
#line 3641 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:
/* Line 661 of lalr1.cc  */
#line 3645 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 375:
/* Line 661 of lalr1.cc  */
#line 3651 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 376:
/* Line 661 of lalr1.cc  */
#line 3657 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 377:
/* Line 661 of lalr1.cc  */
#line 3663 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:
/* Line 661 of lalr1.cc  */
#line 3673 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 379:
/* Line 661 of lalr1.cc  */
#line 3677 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 380:
/* Line 661 of lalr1.cc  */
#line 3681 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 381:
/* Line 661 of lalr1.cc  */
#line 3689 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:
/* Line 661 of lalr1.cc  */
#line 3693 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 383:
/* Line 661 of lalr1.cc  */
#line 3699 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 384:
/* Line 661 of lalr1.cc  */
#line 3709 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:
/* Line 661 of lalr1.cc  */
#line 3713 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 386:
/* Line 661 of lalr1.cc  */
#line 3723 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 387:
/* Line 661 of lalr1.cc  */
#line 3727 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 388:
/* Line 661 of lalr1.cc  */
#line 3737 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 389:
/* Line 661 of lalr1.cc  */
#line 3741 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 390:
/* Line 661 of lalr1.cc  */
#line 3751 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 391:
/* Line 661 of lalr1.cc  */
#line 3755 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 392:
/* Line 661 of lalr1.cc  */
#line 3765 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 393:
/* Line 661 of lalr1.cc  */
#line 3769 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 394:
/* Line 661 of lalr1.cc  */
#line 3777 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 395:
/* Line 661 of lalr1.cc  */
#line 3781 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 396:
/* Line 661 of lalr1.cc  */
#line 3785 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 397:
/* Line 661 of lalr1.cc  */
#line 3789 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 398:
/* Line 661 of lalr1.cc  */
#line 3799 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 399:
/* Line 661 of lalr1.cc  */
#line 3803 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 400:
/* Line 661 of lalr1.cc  */
#line 3807 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 401:
/* Line 661 of lalr1.cc  */
#line 3815 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 402:
/* Line 661 of lalr1.cc  */
#line 3819 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 403:
/* Line 661 of lalr1.cc  */
#line 3823 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 404:
/* Line 661 of lalr1.cc  */
#line 3827 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 405:
/* Line 661 of lalr1.cc  */
#line 3831 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 406:
/* Line 661 of lalr1.cc  */
#line 3835 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 407:
/* Line 661 of lalr1.cc  */
#line 3843 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_is );
        }
    break;

  case 408:
/* Line 661 of lalr1.cc  */
#line 3847 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_precedes );
        }
    break;

  case 409:
/* Line 661 of lalr1.cc  */
#line 3851 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NodeComp( LOC((yyloc)), ParseConstants::op_follows );
        }
    break;

  case 410:
/* Line 661 of lalr1.cc  */
#line 3859 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 411:
/* Line 661 of lalr1.cc  */
#line 3863 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 412:
/* Line 661 of lalr1.cc  */
#line 3867 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 413:
/* Line 661 of lalr1.cc  */
#line 3871 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 414:
/* Line 661 of lalr1.cc  */
#line 3882 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 415:
/* Line 661 of lalr1.cc  */
#line 3888 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 416:
/* Line 661 of lalr1.cc  */
#line 3898 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 417:
/* Line 661 of lalr1.cc  */
#line 3904 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 418:
/* Line 661 of lalr1.cc  */
#line 3914 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 419:
/* Line 661 of lalr1.cc  */
#line 3918 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 420:
/* Line 661 of lalr1.cc  */
#line 3922 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 421:
/* Line 661 of lalr1.cc  */
#line 3960 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new PathExpr(LOC((yyloc)), ParseConstants::path_leading_lone_slash, NULL);
    }
    break;

  case 422:
/* Line 661 of lalr1.cc  */
#line 3964 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slash,
                        rpe);
    }
    break;

  case 423:
/* Line 661 of lalr1.cc  */
#line 3974 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe;

      rpe = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, NULL, (yysemantic_stack_[(2) - (2)].expr), false);

      (yyval.expr) = new PathExpr(LOC((yyloc)),
                        ParseConstants::path_leading_slashslash,
                        rpe);
    }
    break;

  case 424:
/* Line 661 of lalr1.cc  */
#line 3984 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 425:
/* Line 661 of lalr1.cc  */
#line 3997 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 426:
/* Line 661 of lalr1.cc  */
#line 4006 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 4016 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 428:
/* Line 661 of lalr1.cc  */
#line 4020 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new RelativePathExpr(LOC((yyloc)), ParseConstants::st_slashslash, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr), false);
    }
    break;

  case 429:
/* Line 661 of lalr1.cc  */
#line 4029 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 430:
/* Line 661 of lalr1.cc  */
#line 4033 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 431:
/* Line 661 of lalr1.cc  */
#line 4042 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ForwardStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 432:
/* Line 661 of lalr1.cc  */
#line 4048 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ForwardStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 433:
/* Line 661 of lalr1.cc  */
#line 4056 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)), dynamic_cast<ReverseStep*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 434:
/* Line 661 of lalr1.cc  */
#line 4062 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new AxisStep(
                LOC((yyloc)),
                dynamic_cast<ReverseStep*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 435:
/* Line 661 of lalr1.cc  */
#line 4074 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<ForwardAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node)
            );
        }
    break;

  case 436:
/* Line 661 of lalr1.cc  */
#line 4080 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardStep(
                LOC((yyloc)), dynamic_cast<AbbrevForwardStep*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 437:
/* Line 661 of lalr1.cc  */
#line 4090 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_child );
        }
    break;

  case 438:
/* Line 661 of lalr1.cc  */
#line 4094 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_descendant);
        }
    break;

  case 439:
/* Line 661 of lalr1.cc  */
#line 4098 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_attribute );
        }
    break;

  case 440:
/* Line 661 of lalr1.cc  */
#line 4102 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_self );
        }
    break;

  case 441:
/* Line 661 of lalr1.cc  */
#line 4106 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_descendant_or_self
            );
        }
    break;

  case 442:
/* Line 661 of lalr1.cc  */
#line 4112 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis(
                LOC((yyloc)), ParseConstants::axis_following_sibling
            );
        }
    break;

  case 443:
/* Line 661 of lalr1.cc  */
#line 4118 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ForwardAxis( LOC((yyloc)), ParseConstants::axis_following );
        }
    break;

  case 444:
/* Line 661 of lalr1.cc  */
#line 4126 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), false );
        }
    break;

  case 445:
/* Line 661 of lalr1.cc  */
#line 4130 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AbbrevForwardStep( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].node), true );
        }
    break;

  case 446:
/* Line 661 of lalr1.cc  */
#line 4138 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseStep( LOC((yyloc)), dynamic_cast<ReverseAxis*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].node) );
        }
    break;

  case 447:
/* Line 661 of lalr1.cc  */
#line 4142 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            ReverseAxis *ra = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_parent
            );
            (yyval.node) = new ReverseStep( LOC((yyloc)), ra, NULL );
        }
    break;

  case 448:
/* Line 661 of lalr1.cc  */
#line 4153 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_parent );
        }
    break;

  case 449:
/* Line 661 of lalr1.cc  */
#line 4157 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_ancestor );
        }
    break;

  case 450:
/* Line 661 of lalr1.cc  */
#line 4161 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_preceding_sibling
            );
        }
    break;

  case 451:
/* Line 661 of lalr1.cc  */
#line 4167 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis( LOC((yyloc)), ParseConstants::axis_preceding );
        }
    break;

  case 452:
/* Line 661 of lalr1.cc  */
#line 4171 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ReverseAxis(
                LOC((yyloc)), ParseConstants::axis_ancestor_or_self
            );
        }
    break;

  case 453:
/* Line 661 of lalr1.cc  */
#line 4185 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 454:
/* Line 661 of lalr1.cc  */
#line 4189 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 455:
/* Line 661 of lalr1.cc  */
#line 4197 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 456:
/* Line 661 of lalr1.cc  */
#line 4201 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 457:
/* Line 661 of lalr1.cc  */
#line 4211 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 458:
/* Line 661 of lalr1.cc  */
#line 4215 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 459:
/* Line 661 of lalr1.cc  */
#line 4219 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 460:
/* Line 661 of lalr1.cc  */
#line 4223 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 461:
/* Line 661 of lalr1.cc  */
#line 4232 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 462:
/* Line 661 of lalr1.cc  */
#line 4236 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 463:
/* Line 661 of lalr1.cc  */
#line 4240 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(3) - (1)].expr));
     }
    break;

  case 464:
/* Line 661 of lalr1.cc  */
#line 4244 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC ((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)));
     }
    break;

  case 465:
/* Line 661 of lalr1.cc  */
#line 4252 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 466:
/* Line 661 of lalr1.cc  */
#line 4258 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 467:
/* Line 661 of lalr1.cc  */
#line 4268 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 468:
/* Line 661 of lalr1.cc  */
#line 4276 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 469:
/* Line 661 of lalr1.cc  */
#line 4280 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 470:
/* Line 661 of lalr1.cc  */
#line 4284 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 471:
/* Line 661 of lalr1.cc  */
#line 4288 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 472:
/* Line 661 of lalr1.cc  */
#line 4292 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 473:
/* Line 661 of lalr1.cc  */
#line 4296 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 474:
/* Line 661 of lalr1.cc  */
#line 4300 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 475:
/* Line 661 of lalr1.cc  */
#line 4304 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 476:
/* Line 661 of lalr1.cc  */
#line 4308 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 477:
/* Line 661 of lalr1.cc  */
#line 4312 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 478:
/* Line 661 of lalr1.cc  */
#line 4317 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 479:
/* Line 661 of lalr1.cc  */
#line 4321 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 480:
/* Line 661 of lalr1.cc  */
#line 4325 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 481:
/* Line 661 of lalr1.cc  */
#line 4329 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 482:
/* Line 661 of lalr1.cc  */
#line 4337 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 483:
/* Line 661 of lalr1.cc  */
#line 4341 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 484:
/* Line 661 of lalr1.cc  */
#line 4349 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 485:
/* Line 661 of lalr1.cc  */
#line 4356 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 486:
/* Line 661 of lalr1.cc  */
#line 4363 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 487:
/* Line 661 of lalr1.cc  */
#line 4374 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 488:
/* Line 661 of lalr1.cc  */
#line 4382 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 489:
/* Line 661 of lalr1.cc  */
#line 4386 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 490:
/* Line 661 of lalr1.cc  */
#line 4394 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 491:
/* Line 661 of lalr1.cc  */
#line 4402 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 492:
/* Line 661 of lalr1.cc  */
#line 4410 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 493:
/* Line 661 of lalr1.cc  */
#line 4464 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
        }
    break;

  case 494:
/* Line 661 of lalr1.cc  */
#line 4468 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new FunctionCall(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 495:
/* Line 661 of lalr1.cc  */
#line 4481 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            ArgList *al = new ArgList( LOC((yyloc)) );
            al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
            (yyval.node) = al;
        }
    break;

  case 496:
/* Line 661 of lalr1.cc  */
#line 4487 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
                al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 497:
/* Line 661 of lalr1.cc  */
#line 4497 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 498:
/* Line 661 of lalr1.cc  */
#line 4501 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 499:
/* Line 661 of lalr1.cc  */
#line 4509 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 500:
/* Line 661 of lalr1.cc  */
#line 4513 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 501:
/* Line 661 of lalr1.cc  */
#line 4517 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 502:
/* Line 661 of lalr1.cc  */
#line 4525 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 4535 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 4545 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
                NULL,
                dynamic_cast<DirElemContentList*>((yysemantic_stack_[(9) - (5)].node))
            );
        }
    break;

  case 506:
/* Line 661 of lalr1.cc  */
#line 4579 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 4596 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 4618 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
            decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = decl;
        }
    break;

  case 509:
/* Line 661 of lalr1.cc  */
#line 4624 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( decl )
                decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 510:
/* Line 661 of lalr1.cc  */
#line 4635 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
            dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = dal;
        }
    break;

  case 511:
/* Line 661 of lalr1.cc  */
#line 4641 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
            if ( dal )
                dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 512:
/* Line 661 of lalr1.cc  */
#line 4652 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttr(
                LOC((yyloc)),
                static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node))
            );
        }
    break;

  case 515:
/* Line 661 of lalr1.cc  */
#line 4669 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 516:
/* Line 661 of lalr1.cc  */
#line 4674 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 517:
/* Line 661 of lalr1.cc  */
#line 4683 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
        }
    break;

  case 518:
/* Line 661 of lalr1.cc  */
#line 4687 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 519:
/* Line 661 of lalr1.cc  */
#line 4694 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = qacl;
        }
    break;

  case 520:
/* Line 661 of lalr1.cc  */
#line 4700 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
            qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = qacl;
        }
    break;

  case 521:
/* Line 661 of lalr1.cc  */
#line 4706 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 522:
/* Line 661 of lalr1.cc  */
#line 4714 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            QuoteAttrContentList *qacl =
                dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( qacl )
                qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 523:
/* Line 661 of lalr1.cc  */
#line 4726 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
        }
    break;

  case 524:
/* Line 661 of lalr1.cc  */
#line 4730 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 525:
/* Line 661 of lalr1.cc  */
#line 4737 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = aacl;
        }
    break;

  case 526:
/* Line 661 of lalr1.cc  */
#line 4743 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
            aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = aacl;
        }
    break;

  case 527:
/* Line 661 of lalr1.cc  */
#line 4749 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if (aacl)
                aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 528:
/* Line 661 of lalr1.cc  */
#line 4756 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
            if ( aacl )
                aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 529:
/* Line 661 of lalr1.cc  */
#line 4767 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 530:
/* Line 661 of lalr1.cc  */
#line 4771 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new QuoteAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 531:
/* Line 661 of lalr1.cc  */
#line 4781 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 532:
/* Line 661 of lalr1.cc  */
#line 4785 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AposAttrValueContent(
                LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr))
            );
        }
    break;

  case 533:
/* Line 661 of lalr1.cc  */
#line 4795 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
        }
    break;

  case 534:
/* Line 661 of lalr1.cc  */
#line 4799 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 535:
/* Line 661 of lalr1.cc  */
#line 4803 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
        }
    break;

  case 536:
/* Line 661 of lalr1.cc  */
#line 4808 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
            (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
        }
    break;

  case 537:
/* Line 661 of lalr1.cc  */
#line 4817 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval))
            );
        }
    break;

  case 538:
/* Line 661 of lalr1.cc  */
#line 4823 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_lbrace
            );
        }
    break;

  case 539:
/* Line 661 of lalr1.cc  */
#line 4829 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(
                LOC((yyloc)), ParseConstants::cont_escape_rbrace
            );
        }
    break;

  case 540:
/* Line 661 of lalr1.cc  */
#line 4835 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
        }
    break;

  case 541:
/* Line 661 of lalr1.cc  */
#line 4843 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 542:
/* Line 661 of lalr1.cc  */
#line 4848 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 543:
/* Line 661 of lalr1.cc  */
#line 4856 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 544:
/* Line 661 of lalr1.cc  */
#line 4861 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 545:
/* Line 661 of lalr1.cc  */
#line 4869 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 546:
/* Line 661 of lalr1.cc  */
#line 4877 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 547:
/* Line 661 of lalr1.cc  */
#line 4882 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 548:
/* Line 661 of lalr1.cc  */
#line 4887 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 549:
/* Line 661 of lalr1.cc  */
#line 4892 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 550:
/* Line 661 of lalr1.cc  */
#line 4897 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 551:
/* Line 661 of lalr1.cc  */
#line 4902 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 552:
/* Line 661 of lalr1.cc  */
#line 4911 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 553:
/* Line 661 of lalr1.cc  */
#line 4919 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
        }
    break;

  case 554:
/* Line 661 of lalr1.cc  */
#line 4923 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 555:
/* Line 661 of lalr1.cc  */
#line 4940 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 556:
/* Line 661 of lalr1.cc  */
#line 4944 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 557:
/* Line 661 of lalr1.cc  */
#line 4952 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 558:
/* Line 661 of lalr1.cc  */
#line 4960 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 559:
/* Line 661 of lalr1.cc  */
#line 4968 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 560:
/* Line 661 of lalr1.cc  */
#line 4972 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new CompPIConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
        }
    break;

  case 561:
/* Line 661 of lalr1.cc  */
#line 4980 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(1) - (1)].node)), false
            );
        }
    break;

  case 562:
/* Line 661 of lalr1.cc  */
#line 4986 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SingleType(
                LOC((yyloc)), dynamic_cast<AtomicType*>((yysemantic_stack_[(2) - (1)].node)), true
            );
        }
    break;

  case 563:
/* Line 661 of lalr1.cc  */
#line 4996 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
        }
    break;

  case 564:
/* Line 661 of lalr1.cc  */
#line 5004 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 565:
/* Line 661 of lalr1.cc  */
#line 5008 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 566:
/* Line 661 of lalr1.cc  */
#line 5012 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 567:
/* Line 661 of lalr1.cc  */
#line 5047 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 568:
/* Line 661 of lalr1.cc  */
#line 5053 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 569:
/* Line 661 of lalr1.cc  */
#line 5059 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 570:
/* Line 661 of lalr1.cc  */
#line 5069 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 571:
/* Line 661 of lalr1.cc  */
#line 5073 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 572:
/* Line 661 of lalr1.cc  */
#line 5077 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 573:
/* Line 661 of lalr1.cc  */
#line 5081 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 574:
/* Line 661 of lalr1.cc  */
#line 5085 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 575:
/* Line 661 of lalr1.cc  */
#line 5089 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 576:
/* Line 661 of lalr1.cc  */
#line 5093 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 577:
/* Line 661 of lalr1.cc  */
#line 5100 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 578:
/* Line 661 of lalr1.cc  */
#line 5106 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 579:
/* Line 661 of lalr1.cc  */
#line 5116 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 580:
/* Line 661 of lalr1.cc  */
#line 5124 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 581:
/* Line 661 of lalr1.cc  */
#line 5128 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 582:
/* Line 661 of lalr1.cc  */
#line 5132 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 583:
/* Line 661 of lalr1.cc  */
#line 5136 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 584:
/* Line 661 of lalr1.cc  */
#line 5140 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 585:
/* Line 661 of lalr1.cc  */
#line 5144 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 586:
/* Line 661 of lalr1.cc  */
#line 5148 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 587:
/* Line 661 of lalr1.cc  */
#line 5152 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 588:
/* Line 661 of lalr1.cc  */
#line 5156 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 589:
/* Line 661 of lalr1.cc  */
#line 5164 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AnyKindTest( LOC((yyloc)) );
        }
    break;

  case 590:
/* Line 661 of lalr1.cc  */
#line 5172 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)) );
        }
    break;

  case 591:
/* Line 661 of lalr1.cc  */
#line 5176 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest( LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)) );
        }
    break;

  case 592:
/* Line 661 of lalr1.cc  */
#line 5180 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new DocumentTest(
                LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 593:
/* Line 661 of lalr1.cc  */
#line 5190 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TextTest( LOC((yyloc)) );
        }
    break;

  case 594:
/* Line 661 of lalr1.cc  */
#line 5198 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new CommentTest( LOC((yyloc)));
        }
    break;

  case 595:
/* Line 661 of lalr1.cc  */
#line 5206 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 596:
/* Line 661 of lalr1.cc  */
#line 5210 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 597:
/* Line 661 of lalr1.cc  */
#line 5214 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 598:
/* Line 661 of lalr1.cc  */
#line 5222 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 599:
/* Line 661 of lalr1.cc  */
#line 5226 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 600:
/* Line 661 of lalr1.cc  */
#line 5232 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 601:
/* Line 661 of lalr1.cc  */
#line 5238 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 602:
/* Line 661 of lalr1.cc  */
#line 5242 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 603:
/* Line 661 of lalr1.cc  */
#line 5252 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 604:
/* Line 661 of lalr1.cc  */
#line 5260 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 605:
/* Line 661 of lalr1.cc  */
#line 5264 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 606:
/* Line 661 of lalr1.cc  */
#line 5270 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 5279 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 5288 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 609:
/* Line 661 of lalr1.cc  */
#line 5294 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 610:
/* Line 661 of lalr1.cc  */
#line 5300 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 611:
/* Line 661 of lalr1.cc  */
#line 5310 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 612:
/* Line 661 of lalr1.cc  */
#line 5327 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 613:
/* Line 661 of lalr1.cc  */
#line 5334 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 614:
/* Line 661 of lalr1.cc  */
#line 5349 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 615:
/* Line 661 of lalr1.cc  */
#line 5385 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 616:
/* Line 661 of lalr1.cc  */
#line 5389 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 617:
/* Line 661 of lalr1.cc  */
#line 5397 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 618:
/* Line 661 of lalr1.cc  */
#line 5405 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 619:
/* Line 661 of lalr1.cc  */
#line 5417 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 620:
/* Line 661 of lalr1.cc  */
#line 5421 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 621:
/* Line 661 of lalr1.cc  */
#line 5429 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 622:
/* Line 661 of lalr1.cc  */
#line 5437 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 623:
/* Line 661 of lalr1.cc  */
#line 5441 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 624:
/* Line 661 of lalr1.cc  */
#line 5452 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 625:
/* Line 661 of lalr1.cc  */
#line 5469 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 626:
/* Line 661 of lalr1.cc  */
#line 5475 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 627:
/* Line 661 of lalr1.cc  */
#line 5481 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 628:
/* Line 661 of lalr1.cc  */
#line 5491 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 629:
/* Line 661 of lalr1.cc  */
#line 5495 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 630:
/* Line 661 of lalr1.cc  */
#line 5501 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 631:
/* Line 661 of lalr1.cc  */
#line 5507 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 632:
/* Line 661 of lalr1.cc  */
#line 5511 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 633:
/* Line 661 of lalr1.cc  */
#line 5517 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 634:
/* Line 661 of lalr1.cc  */
#line 5521 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 635:
/* Line 661 of lalr1.cc  */
#line 5527 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 636:
/* Line 661 of lalr1.cc  */
#line 5533 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 637:
/* Line 661 of lalr1.cc  */
#line 5540 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 638:
/* Line 661 of lalr1.cc  */
#line 5550 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 639:
/* Line 661 of lalr1.cc  */
#line 5555 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 640:
/* Line 661 of lalr1.cc  */
#line 5563 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 641:
/* Line 661 of lalr1.cc  */
#line 5569 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 642:
/* Line 661 of lalr1.cc  */
#line 5579 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 643:
/* Line 661 of lalr1.cc  */
#line 5601 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 644:
/* Line 661 of lalr1.cc  */
#line 5610 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 645:
/* Line 661 of lalr1.cc  */
#line 5616 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 646:
/* Line 661 of lalr1.cc  */
#line 5629 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 647:
/* Line 661 of lalr1.cc  */
#line 5643 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 648:
/* Line 661 of lalr1.cc  */
#line 5650 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 649:
/* Line 661 of lalr1.cc  */
#line 5656 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 650:
/* Line 661 of lalr1.cc  */
#line 5666 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 651:
/* Line 661 of lalr1.cc  */
#line 5675 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 652:
/* Line 661 of lalr1.cc  */
#line 5683 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 653:
/* Line 661 of lalr1.cc  */
#line 5689 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 654:
/* Line 661 of lalr1.cc  */
#line 5707 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 655:
/* Line 661 of lalr1.cc  */
#line 5715 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 656:
/* Line 661 of lalr1.cc  */
#line 5719 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 657:
/* Line 661 of lalr1.cc  */
#line 5726 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 658:
/* Line 661 of lalr1.cc  */
#line 5731 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 659:
/* Line 661 of lalr1.cc  */
#line 5739 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 660:
/* Line 661 of lalr1.cc  */
#line 5743 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 661:
/* Line 661 of lalr1.cc  */
#line 5750 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 662:
/* Line 661 of lalr1.cc  */
#line 5754 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 663:
/* Line 661 of lalr1.cc  */
#line 5761 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 664:
/* Line 661 of lalr1.cc  */
#line 5765 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 665:
/* Line 661 of lalr1.cc  */
#line 5772 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 666:
/* Line 661 of lalr1.cc  */
#line 5776 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 667:
/* Line 661 of lalr1.cc  */
#line 5785 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 5797 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 669:
/* Line 661 of lalr1.cc  */
#line 5801 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 670:
/* Line 661 of lalr1.cc  */
#line 5808 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 671:
/* Line 661 of lalr1.cc  */
#line 5812 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:
/* Line 661 of lalr1.cc  */
#line 5820 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 673:
/* Line 661 of lalr1.cc  */
#line 5828 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 674:
/* Line 661 of lalr1.cc  */
#line 5836 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 675:
/* Line 661 of lalr1.cc  */
#line 5840 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 676:
/* Line 661 of lalr1.cc  */
#line 5847 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 677:
/* Line 661 of lalr1.cc  */
#line 5851 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 678:
/* Line 661 of lalr1.cc  */
#line 5859 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 679:
/* Line 661 of lalr1.cc  */
#line 5870 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 680:
/* Line 661 of lalr1.cc  */
#line 5874 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 681:
/* Line 661 of lalr1.cc  */
#line 5882 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 682:
/* Line 661 of lalr1.cc  */
#line 5894 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 683:
/* Line 661 of lalr1.cc  */
#line 5900 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 684:
/* Line 661 of lalr1.cc  */
#line 5909 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 685:
/* Line 661 of lalr1.cc  */
#line 5913 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:
/* Line 661 of lalr1.cc  */
#line 5921 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 687:
/* Line 661 of lalr1.cc  */
#line 5925 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 688:
/* Line 661 of lalr1.cc  */
#line 5929 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 689:
/* Line 661 of lalr1.cc  */
#line 5936 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 690:
/* Line 661 of lalr1.cc  */
#line 5940 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 691:
/* Line 661 of lalr1.cc  */
#line 5947 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 692:
/* Line 661 of lalr1.cc  */
#line 5951 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 693:
/* Line 661 of lalr1.cc  */
#line 5959 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 694:
/* Line 661 of lalr1.cc  */
#line 5963 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 695:
/* Line 661 of lalr1.cc  */
#line 5967 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 696:
/* Line 661 of lalr1.cc  */
#line 5971 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 697:
/* Line 661 of lalr1.cc  */
#line 5975 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:
/* Line 661 of lalr1.cc  */
#line 5983 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 699:
/* Line 661 of lalr1.cc  */
#line 5991 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 700:
/* Line 661 of lalr1.cc  */
#line 6003 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 701:
/* Line 661 of lalr1.cc  */
#line 6015 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 702:
/* Line 661 of lalr1.cc  */
#line 6019 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 703:
/* Line 661 of lalr1.cc  */
#line 6023 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 704:
/* Line 661 of lalr1.cc  */
#line 6031 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 705:
/* Line 661 of lalr1.cc  */
#line 6037 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 706:
/* Line 661 of lalr1.cc  */
#line 6047 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 707:
/* Line 661 of lalr1.cc  */
#line 6051 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 708:
/* Line 661 of lalr1.cc  */
#line 6055 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 709:
/* Line 661 of lalr1.cc  */
#line 6059 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 710:
/* Line 661 of lalr1.cc  */
#line 6063 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 711:
/* Line 661 of lalr1.cc  */
#line 6067 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 712:
/* Line 661 of lalr1.cc  */
#line 6071 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 713:
/* Line 661 of lalr1.cc  */
#line 6075 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 714:
/* Line 661 of lalr1.cc  */
#line 6083 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 715:
/* Line 661 of lalr1.cc  */
#line 6087 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 716:
/* Line 661 of lalr1.cc  */
#line 6091 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 717:
/* Line 661 of lalr1.cc  */
#line 6095 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 718:
/* Line 661 of lalr1.cc  */
#line 6103 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 719:
/* Line 661 of lalr1.cc  */
#line 6109 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 720:
/* Line 661 of lalr1.cc  */
#line 6119 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 721:
/* Line 661 of lalr1.cc  */
#line 6129 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 722:
/* Line 661 of lalr1.cc  */
#line 6133 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 723:
/* Line 661 of lalr1.cc  */
#line 6141 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 6151 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 6162 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 726:
/* Line 661 of lalr1.cc  */
#line 6169 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 727:
/* Line 661 of lalr1.cc  */
#line 6173 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 728:
/* Line 661 of lalr1.cc  */
#line 6180 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 729:
/* Line 661 of lalr1.cc  */
#line 6184 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 730:
/* Line 661 of lalr1.cc  */
#line 6191 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 731:
/* Line 661 of lalr1.cc  */
#line 6196 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 732:
/* Line 661 of lalr1.cc  */
#line 6205 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 733:
/* Line 661 of lalr1.cc  */
#line 6214 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 734:
/* Line 661 of lalr1.cc  */
#line 6218 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 735:
/* Line 661 of lalr1.cc  */
#line 6225 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 736:
/* Line 661 of lalr1.cc  */
#line 6229 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 737:
/* Line 661 of lalr1.cc  */
#line 6237 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 6246 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 739:
/* Line 661 of lalr1.cc  */
#line 6253 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 740:
/* Line 661 of lalr1.cc  */
#line 6263 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 741:
/* Line 661 of lalr1.cc  */
#line 6267 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 742:
/* Line 661 of lalr1.cc  */
#line 6274 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 743:
/* Line 661 of lalr1.cc  */
#line 6280 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 744:
/* Line 661 of lalr1.cc  */
#line 6289 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 745:
/* Line 661 of lalr1.cc  */
#line 6293 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 746:
/* Line 661 of lalr1.cc  */
#line 6300 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 747:
/* Line 661 of lalr1.cc  */
#line 6305 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 748:
/* Line 661 of lalr1.cc  */
#line 6317 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 749:
/* Line 661 of lalr1.cc  */
#line 6325 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 750:
/* Line 661 of lalr1.cc  */
#line 6337 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 751:
/* Line 661 of lalr1.cc  */
#line 6345 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 752:
/* Line 661 of lalr1.cc  */
#line 6349 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 753:
/* Line 661 of lalr1.cc  */
#line 6357 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 754:
/* Line 661 of lalr1.cc  */
#line 6361 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 755:
/* Line 661 of lalr1.cc  */
#line 6365 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 756:
/* Line 661 of lalr1.cc  */
#line 6373 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 757:
/* Line 661 of lalr1.cc  */
#line 6381 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 758:
/* Line 661 of lalr1.cc  */
#line 6385 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 759:
/* Line 661 of lalr1.cc  */
#line 6389 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 760:
/* Line 661 of lalr1.cc  */
#line 6393 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 761:
/* Line 661 of lalr1.cc  */
#line 6401 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 762:
/* Line 661 of lalr1.cc  */
#line 6409 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 763:
/* Line 661 of lalr1.cc  */
#line 6421 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 764:
/* Line 661 of lalr1.cc  */
#line 6425 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 765:
/* Line 661 of lalr1.cc  */
#line 6433 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 766:
/* Line 661 of lalr1.cc  */
#line 6447 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 767:
/* Line 661 of lalr1.cc  */
#line 6451 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 768:
/* Line 661 of lalr1.cc  */
#line 6458 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 769:
/* Line 661 of lalr1.cc  */
#line 6463 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 770:
/* Line 661 of lalr1.cc  */
#line 6471 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 771:
/* Line 661 of lalr1.cc  */
#line 6476 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          // TODO: fill in with the correct constructor
          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 772:
/* Line 661 of lalr1.cc  */
#line 6485 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 773:
/* Line 661 of lalr1.cc  */
#line 6493 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 774:
/* Line 661 of lalr1.cc  */
#line 6499 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 775:
/* Line 661 of lalr1.cc  */
#line 6509 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 776:
/* Line 661 of lalr1.cc  */
#line 6515 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 6525 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 778:
/* Line 661 of lalr1.cc  */
#line 6532 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 779:
/* Line 661 of lalr1.cc  */
#line 6539 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 780:
/* Line 661 of lalr1.cc  */
#line 6568 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 781:
/* Line 661 of lalr1.cc  */
#line 6597 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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

  case 782:
/* Line 661 of lalr1.cc  */
#line 6626 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 783:
/* Line 661 of lalr1.cc  */
#line 6630 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 784:
/* Line 661 of lalr1.cc  */
#line 6634 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 785:
/* Line 661 of lalr1.cc  */
#line 6641 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 786:
/* Line 661 of lalr1.cc  */
#line 6648 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 787:
/* Line 661 of lalr1.cc  */
#line 6655 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 790:
/* Line 661 of lalr1.cc  */
#line 6672 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
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
/* Line 661 of lalr1.cc  */
#line 6685 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 793:
/* Line 661 of lalr1.cc  */
#line 6686 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 794:
/* Line 661 of lalr1.cc  */
#line 6687 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 795:
/* Line 661 of lalr1.cc  */
#line 6688 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 796:
/* Line 661 of lalr1.cc  */
#line 6689 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("item"))); }
    break;

  case 797:
/* Line 661 of lalr1.cc  */
#line 6690 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 798:
/* Line 661 of lalr1.cc  */
#line 6691 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 799:
/* Line 661 of lalr1.cc  */
#line 6692 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 800:
/* Line 661 of lalr1.cc  */
#line 6693 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 801:
/* Line 661 of lalr1.cc  */
#line 6694 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 802:
/* Line 661 of lalr1.cc  */
#line 6695 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 803:
/* Line 661 of lalr1.cc  */
#line 6696 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 804:
/* Line 661 of lalr1.cc  */
#line 6697 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 805:
/* Line 661 of lalr1.cc  */
#line 6698 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 806:
/* Line 661 of lalr1.cc  */
#line 6699 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 808:
/* Line 661 of lalr1.cc  */
#line 6704 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 809:
/* Line 661 of lalr1.cc  */
#line 6705 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 810:
/* Line 661 of lalr1.cc  */
#line 6706 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 811:
/* Line 661 of lalr1.cc  */
#line 6707 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 812:
/* Line 661 of lalr1.cc  */
#line 6708 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 813:
/* Line 661 of lalr1.cc  */
#line 6709 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 814:
/* Line 661 of lalr1.cc  */
#line 6710 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 815:
/* Line 661 of lalr1.cc  */
#line 6711 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 816:
/* Line 661 of lalr1.cc  */
#line 6712 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 817:
/* Line 661 of lalr1.cc  */
#line 6713 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 818:
/* Line 661 of lalr1.cc  */
#line 6714 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 819:
/* Line 661 of lalr1.cc  */
#line 6715 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 820:
/* Line 661 of lalr1.cc  */
#line 6716 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 821:
/* Line 661 of lalr1.cc  */
#line 6717 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 822:
/* Line 661 of lalr1.cc  */
#line 6718 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 823:
/* Line 661 of lalr1.cc  */
#line 6719 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 824:
/* Line 661 of lalr1.cc  */
#line 6720 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 825:
/* Line 661 of lalr1.cc  */
#line 6721 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 826:
/* Line 661 of lalr1.cc  */
#line 6722 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 827:
/* Line 661 of lalr1.cc  */
#line 6723 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 828:
/* Line 661 of lalr1.cc  */
#line 6724 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 829:
/* Line 661 of lalr1.cc  */
#line 6725 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 830:
/* Line 661 of lalr1.cc  */
#line 6726 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 831:
/* Line 661 of lalr1.cc  */
#line 6727 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 832:
/* Line 661 of lalr1.cc  */
#line 6728 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 833:
/* Line 661 of lalr1.cc  */
#line 6729 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 834:
/* Line 661 of lalr1.cc  */
#line 6730 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 835:
/* Line 661 of lalr1.cc  */
#line 6731 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 836:
/* Line 661 of lalr1.cc  */
#line 6732 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 837:
/* Line 661 of lalr1.cc  */
#line 6733 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 838:
/* Line 661 of lalr1.cc  */
#line 6734 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 839:
/* Line 661 of lalr1.cc  */
#line 6735 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 840:
/* Line 661 of lalr1.cc  */
#line 6736 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 841:
/* Line 661 of lalr1.cc  */
#line 6737 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 842:
/* Line 661 of lalr1.cc  */
#line 6738 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 843:
/* Line 661 of lalr1.cc  */
#line 6739 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 844:
/* Line 661 of lalr1.cc  */
#line 6740 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 845:
/* Line 661 of lalr1.cc  */
#line 6741 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 846:
/* Line 661 of lalr1.cc  */
#line 6742 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 847:
/* Line 661 of lalr1.cc  */
#line 6743 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 848:
/* Line 661 of lalr1.cc  */
#line 6744 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 849:
/* Line 661 of lalr1.cc  */
#line 6745 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 850:
/* Line 661 of lalr1.cc  */
#line 6746 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 851:
/* Line 661 of lalr1.cc  */
#line 6747 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 852:
/* Line 661 of lalr1.cc  */
#line 6748 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 853:
/* Line 661 of lalr1.cc  */
#line 6749 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 854:
/* Line 661 of lalr1.cc  */
#line 6750 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 855:
/* Line 661 of lalr1.cc  */
#line 6751 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 856:
/* Line 661 of lalr1.cc  */
#line 6752 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 857:
/* Line 661 of lalr1.cc  */
#line 6753 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 858:
/* Line 661 of lalr1.cc  */
#line 6754 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 859:
/* Line 661 of lalr1.cc  */
#line 6755 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 860:
/* Line 661 of lalr1.cc  */
#line 6756 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 861:
/* Line 661 of lalr1.cc  */
#line 6757 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 862:
/* Line 661 of lalr1.cc  */
#line 6758 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 863:
/* Line 661 of lalr1.cc  */
#line 6759 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 864:
/* Line 661 of lalr1.cc  */
#line 6760 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 865:
/* Line 661 of lalr1.cc  */
#line 6761 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 866:
/* Line 661 of lalr1.cc  */
#line 6762 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 867:
/* Line 661 of lalr1.cc  */
#line 6763 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 868:
/* Line 661 of lalr1.cc  */
#line 6764 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 869:
/* Line 661 of lalr1.cc  */
#line 6765 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 870:
/* Line 661 of lalr1.cc  */
#line 6766 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 871:
/* Line 661 of lalr1.cc  */
#line 6767 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 872:
/* Line 661 of lalr1.cc  */
#line 6768 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 873:
/* Line 661 of lalr1.cc  */
#line 6769 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 874:
/* Line 661 of lalr1.cc  */
#line 6770 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 875:
/* Line 661 of lalr1.cc  */
#line 6771 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 876:
/* Line 661 of lalr1.cc  */
#line 6772 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 877:
/* Line 661 of lalr1.cc  */
#line 6773 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 878:
/* Line 661 of lalr1.cc  */
#line 6774 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 879:
/* Line 661 of lalr1.cc  */
#line 6775 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 880:
/* Line 661 of lalr1.cc  */
#line 6776 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 881:
/* Line 661 of lalr1.cc  */
#line 6777 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 882:
/* Line 661 of lalr1.cc  */
#line 6778 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 883:
/* Line 661 of lalr1.cc  */
#line 6779 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 884:
/* Line 661 of lalr1.cc  */
#line 6780 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 885:
/* Line 661 of lalr1.cc  */
#line 6781 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 886:
/* Line 661 of lalr1.cc  */
#line 6782 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 887:
/* Line 661 of lalr1.cc  */
#line 6783 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 888:
/* Line 661 of lalr1.cc  */
#line 6784 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 889:
/* Line 661 of lalr1.cc  */
#line 6785 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 890:
/* Line 661 of lalr1.cc  */
#line 6786 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 891:
/* Line 661 of lalr1.cc  */
#line 6787 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 892:
/* Line 661 of lalr1.cc  */
#line 6788 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 893:
/* Line 661 of lalr1.cc  */
#line 6789 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 894:
/* Line 661 of lalr1.cc  */
#line 6790 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 895:
/* Line 661 of lalr1.cc  */
#line 6791 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 896:
/* Line 661 of lalr1.cc  */
#line 6792 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 897:
/* Line 661 of lalr1.cc  */
#line 6793 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 898:
/* Line 661 of lalr1.cc  */
#line 6794 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 899:
/* Line 661 of lalr1.cc  */
#line 6795 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 900:
/* Line 661 of lalr1.cc  */
#line 6796 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 901:
/* Line 661 of lalr1.cc  */
#line 6797 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 902:
/* Line 661 of lalr1.cc  */
#line 6798 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 903:
/* Line 661 of lalr1.cc  */
#line 6799 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 904:
/* Line 661 of lalr1.cc  */
#line 6800 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 905:
/* Line 661 of lalr1.cc  */
#line 6801 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 906:
/* Line 661 of lalr1.cc  */
#line 6802 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 907:
/* Line 661 of lalr1.cc  */
#line 6803 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 908:
/* Line 661 of lalr1.cc  */
#line 6804 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 909:
/* Line 661 of lalr1.cc  */
#line 6805 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 910:
/* Line 661 of lalr1.cc  */
#line 6806 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 911:
/* Line 661 of lalr1.cc  */
#line 6807 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 912:
/* Line 661 of lalr1.cc  */
#line 6808 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 913:
/* Line 661 of lalr1.cc  */
#line 6809 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 914:
/* Line 661 of lalr1.cc  */
#line 6810 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 915:
/* Line 661 of lalr1.cc  */
#line 6811 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 916:
/* Line 661 of lalr1.cc  */
#line 6812 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 917:
/* Line 661 of lalr1.cc  */
#line 6813 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 918:
/* Line 661 of lalr1.cc  */
#line 6814 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 919:
/* Line 661 of lalr1.cc  */
#line 6815 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 920:
/* Line 661 of lalr1.cc  */
#line 6816 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 921:
/* Line 661 of lalr1.cc  */
#line 6817 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 922:
/* Line 661 of lalr1.cc  */
#line 6818 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 923:
/* Line 661 of lalr1.cc  */
#line 6819 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 924:
/* Line 661 of lalr1.cc  */
#line 6820 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 925:
/* Line 661 of lalr1.cc  */
#line 6821 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 926:
/* Line 661 of lalr1.cc  */
#line 6822 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 927:
/* Line 661 of lalr1.cc  */
#line 6823 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 928:
/* Line 661 of lalr1.cc  */
#line 6824 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 929:
/* Line 661 of lalr1.cc  */
#line 6825 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 930:
/* Line 661 of lalr1.cc  */
#line 6826 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 931:
/* Line 661 of lalr1.cc  */
#line 6827 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 932:
/* Line 661 of lalr1.cc  */
#line 6828 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 933:
/* Line 661 of lalr1.cc  */
#line 6829 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 934:
/* Line 661 of lalr1.cc  */
#line 6830 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 935:
/* Line 661 of lalr1.cc  */
#line 6831 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("replace"))); }
    break;

  case 936:
/* Line 661 of lalr1.cc  */
#line 6832 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 937:
/* Line 661 of lalr1.cc  */
#line 6833 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 938:
/* Line 661 of lalr1.cc  */
#line 6834 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insert"))); }
    break;

  case 939:
/* Line 661 of lalr1.cc  */
#line 6835 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 940:
/* Line 661 of lalr1.cc  */
#line 6836 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 941:
/* Line 661 of lalr1.cc  */
#line 6837 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 942:
/* Line 661 of lalr1.cc  */
#line 6838 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 943:
/* Line 661 of lalr1.cc  */
#line 6839 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 944:
/* Line 661 of lalr1.cc  */
#line 6840 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("rename"))); }
    break;

  case 945:
/* Line 661 of lalr1.cc  */
#line 6841 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 946:
/* Line 661 of lalr1.cc  */
#line 6842 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("delete"))); }
    break;

  case 947:
/* Line 661 of lalr1.cc  */
#line 6843 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 948:
/* Line 661 of lalr1.cc  */
#line 6844 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 949:
/* Line 661 of lalr1.cc  */
#line 6845 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 950:
/* Line 661 of lalr1.cc  */
#line 6846 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 951:
/* Line 661 of lalr1.cc  */
#line 6847 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 952:
/* Line 661 of lalr1.cc  */
#line 6848 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 953:
/* Line 661 of lalr1.cc  */
#line 6849 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 954:
/* Line 661 of lalr1.cc  */
#line 6850 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 955:
/* Line 661 of lalr1.cc  */
#line 6851 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 956:
/* Line 661 of lalr1.cc  */
#line 6852 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 957:
/* Line 661 of lalr1.cc  */
#line 6853 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 958:
/* Line 661 of lalr1.cc  */
#line 6854 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 959:
/* Line 661 of lalr1.cc  */
#line 6855 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 960:
/* Line 661 of lalr1.cc  */
#line 6856 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 961:
/* Line 661 of lalr1.cc  */
#line 6857 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 962:
/* Line 661 of lalr1.cc  */
#line 6858 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 963:
/* Line 661 of lalr1.cc  */
#line 6859 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 964:
/* Line 661 of lalr1.cc  */
#line 6860 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 965:
/* Line 661 of lalr1.cc  */
#line 6861 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 966:
/* Line 661 of lalr1.cc  */
#line 6862 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 967:
/* Line 661 of lalr1.cc  */
#line 6863 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 968:
/* Line 661 of lalr1.cc  */
#line 6864 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 969:
/* Line 661 of lalr1.cc  */
#line 6865 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 970:
/* Line 661 of lalr1.cc  */
#line 6866 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 971:
/* Line 661 of lalr1.cc  */
#line 6867 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 972:
/* Line 661 of lalr1.cc  */
#line 6868 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 973:
/* Line 661 of lalr1.cc  */
#line 6869 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 974:
/* Line 661 of lalr1.cc  */
#line 6870 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 975:
/* Line 661 of lalr1.cc  */
#line 6871 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 976:
/* Line 661 of lalr1.cc  */
#line 6872 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 977:
/* Line 661 of lalr1.cc  */
#line 6873 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 978:
/* Line 661 of lalr1.cc  */
#line 6874 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 979:
/* Line 661 of lalr1.cc  */
#line 6875 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 980:
/* Line 661 of lalr1.cc  */
#line 6876 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 981:
/* Line 661 of lalr1.cc  */
#line 6877 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 982:
/* Line 661 of lalr1.cc  */
#line 6878 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 983:
/* Line 661 of lalr1.cc  */
#line 6879 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 984:
/* Line 661 of lalr1.cc  */
#line 6880 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 985:
/* Line 661 of lalr1.cc  */
#line 6881 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 986:
/* Line 661 of lalr1.cc  */
#line 6882 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 987:
/* Line 661 of lalr1.cc  */
#line 6883 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 988:
/* Line 661 of lalr1.cc  */
#line 6884 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 989:
/* Line 661 of lalr1.cc  */
#line 6885 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 990:
/* Line 661 of lalr1.cc  */
#line 6886 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 991:
/* Line 661 of lalr1.cc  */
#line 6887 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 992:
/* Line 661 of lalr1.cc  */
#line 6888 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 993:
/* Line 661 of lalr1.cc  */
#line 6889 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 994:
/* Line 661 of lalr1.cc  */
#line 6890 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 995:
/* Line 661 of lalr1.cc  */
#line 6891 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 996:
/* Line 661 of lalr1.cc  */
#line 6892 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 997:
/* Line 661 of lalr1.cc  */
#line 6893 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 998:
/* Line 661 of lalr1.cc  */
#line 6894 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 999:
/* Line 661 of lalr1.cc  */
#line 6895 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 1000:
/* Line 661 of lalr1.cc  */
#line 6896 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1001:
/* Line 661 of lalr1.cc  */
#line 6897 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1002:
/* Line 661 of lalr1.cc  */
#line 6898 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1003:
/* Line 661 of lalr1.cc  */
#line 6899 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1004:
/* Line 661 of lalr1.cc  */
#line 6900 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1005:
/* Line 661 of lalr1.cc  */
#line 6901 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1006:
/* Line 661 of lalr1.cc  */
#line 6902 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json"))); }
    break;

  case 1007:
/* Line 661 of lalr1.cc  */
#line 6903 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append"))); }
    break;

  case 1008:
/* Line 661 of lalr1.cc  */
#line 6904 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1009:
/* Line 661 of lalr1.cc  */
#line 6905 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("json-item"))); }
    break;

  case 1010:
/* Line 661 of lalr1.cc  */
#line 6906 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("array"))); }
    break;

  case 1011:
/* Line 661 of lalr1.cc  */
#line 6907 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("object"))); }
    break;

  case 1012:
/* Line 661 of lalr1.cc  */
#line 6908 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("structured-item"))); }
    break;

  case 1013:
/* Line 661 of lalr1.cc  */
#line 6913 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;


/* Line 661 of lalr1.cc  */
#line 10695 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
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
  const short int xquery_parser::yypact_ninf_ = -1493;
  const short int
  xquery_parser::yypact_[] =
  {
      3467, -1493, -1493, -1493,  5325,  5325,  5325, -1493, -1493,    60,
     401, -1493,   798,    37, -1493, -1493, -1493,   742, -1493, -1493,
   -1493,   434,   463,   770,  2586,   473,   509,   725, -1493,    11,
   -1493, -1493, -1493, -1493, -1493, -1493,   803, -1493,   579,   594,
   -1493, -1493, -1493, -1493,   504, -1493,   815, -1493,   658,   670,
   -1493,   437, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493,   522,   711, -1493, -1493,
   -1493, -1493,   651, 11196, -1493, -1493, -1493,   719, -1493, -1493,
   -1493,   743, -1493,   759,   785, -1493, -1493, 15568, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493,   806, -1493, -1493,   820,
     826, -1493, -1493, -1493, -1493, -1493, -1493, -1493,  4089,  7179,
    7488, 15568, -1493, -1493, -1493, -1493, -1493, -1493, -1493,   799,
   -1493, -1493,   848, 12088, -1493, 12390,   854,   856, -1493, -1493,
   -1493,   861, -1493, 10578, -1493, -1493, -1493, -1493, -1493, -1493,
     807, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,   118,
     777, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,   -83,
     829,   -75, -1493,   -88,   -72, -1493, -1493, -1493, -1493, -1493,
   -1493,   876, -1493,   763,   765,   766, -1493, -1493,   852,   859,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493,  7797,  8106, -1493,   703, -1493, -1493, -1493,
   -1493, -1493,  3778,  5634,  1015, -1493,  5943, -1493, -1493,   407,
      99, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493,   108, -1493, -1493, -1493, -1493,
   -1493, -1493,   119, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493,  5325, -1493, -1493, -1493, -1493,   302, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493,   348, -1493,   828, -1493, -1493,
   -1493,   702, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
     857,   929, -1493,  1004,   775,   927,    16,   615,   684,   519,
   -1493,   979,   831,   931,   935,  9342, -1493, -1493, -1493,   264,
   -1493, -1493, 10887, -1493,   495, -1493,   879, 11196, -1493,   879,
   11196, -1493, -1493, -1493,   713, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493,   895,   886, -1493, -1493,
   -1493, -1493, -1493,   860, -1493,  5325,   863,   866,    96,    96,
    1014,   526,   683,   613, 15855, 15568,     7,   998, 15568,   899,
     937,   527, 12088,   694,   814, 15568, 15568,   757,   692,    44,
   -1493, -1493, -1493, 12088,  5325,   874,  5325,   156,  9651, 13272,
   15568, -1493,   780,   784, 15568,   948,   294,   916,  9651,  1069,
      82,   350, 15568,   957,   934,   970, -1493,  9651, 11792, 15568,
   15568, 15568,  5325,   893,  9651,  9651, 15568,  5325,   925,   930,
   -1493, -1493, -1493,  9651, 13559,   926, -1493,   932, -1493, -1493,
   -1493, -1493,   933, -1493,   939, -1493, -1493, -1493, -1493, -1493,
     940, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, 15568,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493,   944, 15568, -1493, -1493, -1493,   906,  4398,   976,
     303,   943,   945,   947, 15568,  5325, -1493,   938,   188, -1493,
     714, -1493,   139,  1071,  9651, -1493, -1493,   104, -1493, -1493,
   -1493,  1087, -1493, -1493, -1493, -1493,  9651,   894, -1493,  1085,
    9651,  9651, 12689,   928,  9651,  9651,  9651,  9651, 12689,  9651,
     890,   887, 15568,   936,   941,  9651,  9651,  4089,   878, -1493,
      58, -1493,    57,  9651,  5634, -1493, -1493, -1493, -1493, -1493,
     798,   725,   112,   113,  1121,  6252,  6252,  6561,  6561,   743,
   -1493, -1493,   404,   743, -1493,  3158,  9651,  9651, -1493,  1009,
     691,    11,   960,   959,   964,  5325,  9651, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493,  9960,  9960,  9960, -1493,  9960,
    9960, -1493,  9960, -1493,  9960, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493,  9960,  9960,  1060,  9960,  9960,  9960,  9960,  9960,
    9960,  9960,  9960,  9960,  9960,  9960,  9960,   907,  1044,  1045,
    1046, -1493, -1493, -1493,  8415, -1493, -1493, 10578, 10578,  9651,
     879, -1493, -1493,   879, -1493,  8724,   879,   992,  9033, -1493,
   -1493, -1493,    56, -1493,   309, -1493, -1493, -1493, -1493, -1493,
   -1493,  1035,  1036,   473,  1119, -1493, -1493, 15855,  1090,   605,
   15568,   989,   990,  1090,  1014,  1029,  1026, -1493, -1493, -1493,
     148,   915,  1068,   867, 15568,  1022,  9651,  1050, 15568, 15568,
   -1493,  1048,   997,  5325, -1493,  1001,   932,   594, -1493,   995,
     999,   273, -1493,   325,   332,  1080, -1493,    48, -1493, -1493,
    1080, 15568,    43, 15568,  1095,   357, -1493,  5325, -1493,   180,
   -1493, 12088,  1094,  1146, 12088,  1014,  1096,   489, 15568,  9651,
      11,   386,  1006, -1493,  1007,  1011,  1012,    27, -1493,    65,
    1013, -1493,   197,   233,  1043, -1493,  1016,  5325,  5325,   394,
   -1493,   377,   397,   499,  9651,   307, -1493, -1493,  9651,  9651,
   -1493,  9651,  9651,  9651, -1493,  9651, -1493,  9651, -1493, 15568,
    1071, -1493,    28,   417, -1493, -1493, -1493,   458, -1493,   409,
   -1493, -1493,  1052,  1059,  1061,  1062,  1063,   713,   895, -1493,
     396,   456,   270,    89,  1107,   553,   967,   993,   983,   295,
   -1493,  1076, -1493, -1493,  1030,   274,  4707,   461, 11496,   878,
   -1493, -1493, -1493,   987, -1493,   407,   751,  1188,  1188, -1493,
   -1493,   125, -1493, -1493,   126, -1493,    59, -1493, -1493, -1493,
   -1493, -1493, -1493,  1222, -1493, -1493, 15568,  1054,  9651,  1108,
   -1493, -1493, -1493,   929, -1493, -1493, -1493, -1493, -1493,  9960,
   -1493, -1493, -1493,    70, -1493,   615,   615,    29,   684,   684,
     684,   684,   519,   519, -1493, -1493, 14707, 14707, 15568, 15568,
   -1493,   466, -1493, -1493,   212, -1493, -1493, -1493,   459, -1493,
   -1493,   464,    96, -1493, -1493,    35,    45,   715, -1493,   473,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
    1090, -1493,  1097, 14994,  1086,  9651, -1493, -1493, -1493,  1137,
    1014,  1014,  1090, -1493,   659,  1014,   685, 15568,   -95,   285,
    1203, -1493, -1493,   949,   568, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493,   148,    34,  1017,   585,
    9651, -1493, 15568,  1141,   950,  1014, -1493, -1493, -1493, -1493,
    1084, 15568, -1493, 15568, -1493, 15281,  1114, 14707,  1127,  9651,
     150,  1099,    41,   341,   994, -1493, -1493,   595,    43,  1137,
   14707,  1131,  1156,  1067,  1055,  1122,  1014,  1093,  1124,  1161,
    1014,  9651,   -23, -1493, -1493, -1493,  1109, -1493, -1493, -1493,
   -1493,  1145,  9651,  9651,  1117, -1493,  1165,  1166,  5325, -1493,
    1083,  1089,  1115, 15568, -1493, 15568, -1493,  9651,  1128,  1081,
    9651, -1493,  1153,   281,   283,   331,  1240, -1493,   312, -1493,
     326, -1493, -1493,  1247, -1493,   656,  9651,  9651,  9651,   733,
    9651,  9651,  9651,  9651,  9651,  9651,  9651,  9651,  9651, 12689,
    1160,  9651,  9651, -1493,  6870,  1123,  1125,  1126,  1130,   828,
     811,  1040, -1493,   266, -1493,  9651,   127,   229,    59,  6561,
    6561,  6561,  1206, -1493, -1493,  9651,   639,  1180, -1493, 15568,
    1182, -1493, -1493,  9651,    70,   569,   638, -1493,  1008,   103,
    1037,  1034, -1493, -1493,   814, -1493,  1031,   573,  1139,  1142,
   14994,  1144,  1147,  1148,  1150,  1151, -1493,   415, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493,  1157, -1493, -1493, -1493,  9651, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493,   723, -1493,  1279,   762, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,  1024, -1493,
   -1493,  1281, -1493, -1493, -1493, -1493, -1493,   602,  1283, -1493,
     413, -1493, -1493, -1493,   926,   463,   933,   579,   939,   940,
     829,  1147,  1148,  1150, -1493,   415,   415, 10269,  1027,  1021,
   -1493,  1137,    34,  1088,  1132,  5325,  1129,  1134,  1171,  1140,
    1143, 15568, -1493,    81, -1493, 15568, -1493,  9651,  1170,  9651,
    1191,  9651,   259,  1181,  9651,  1184, -1493,  1211,  1214,  9651,
   15568,   891,  1256, -1493, -1493, -1493, -1493, -1493, -1493, 14707,
   -1493,  5325,  1014,  1227, -1493, -1493, -1493,  1014,  1227, -1493,
    9651,  1193,  5325, 15568, -1493, -1493,  9651,  9651,   790, -1493,
      47,   818, -1493, 13846,   830, -1493,   832, -1493,  1152, -1493,
   -1493,  5325,  1158,  1159, -1493,  9651, -1493, -1493,  9651,  1162,
    1165,  1238, -1493,  1207, -1493,   783, -1493, -1493,  1333, -1493,
   -1493,  5325, 15568, -1493,   911, -1493, -1493, -1493,  1163,  1116,
    1118, -1493, -1493, -1493,  1133,  1135, -1493, -1493, -1493,  1251,
   -1493, -1493, -1493, -1493,  1120,    19, 15568,  1169, -1493, -1493,
    9651,  9651,  9651,  5016,  6870, 11496,  1040, -1493, 11496, -1493,
   -1493,  1188,    76, -1493, -1493, -1493,  1180, -1493,  1014, -1493,
     805, -1493,    84,  1252, -1493,  9651,   574,  1108,   468,  1173,
   -1493,    70,  1112, -1493, -1493,   -32, -1493,   169,    21,  1113,
      70,   169,  9960, -1493,   111, -1493, -1493, -1493, -1493, -1493,
   -1493,    70,  1216,  1091,   915,    21, -1493, -1493,  1101,  1291,
   -1493, -1493, -1493, 12985,  1183,  1186,  1189,  1192,  1197,  1200,
    1202, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493,  1349,   298,  1351,   298,  1136,  1284, -1493,
   -1493,  1220, 15568,  1138, -1493, -1493, 10269, -1493,  1209, -1493,
   -1493, -1493, -1493, -1493, -1493,  9651,  1248, -1493, -1493,  9651,
   -1493,   447, -1493,  9651,  1249,  9651, -1493,  9651, 15568, 15568,
   -1493,   133, -1493,  9651, -1493,  1271,  1272,  1303,  1014,  1227,
   -1493,  9651,  1217, -1493, -1493, -1493,  1218, -1493,    53,  9651,
    5325,  1219,    54, -1493, 15568,  1221, 14133,    51, -1493, 14420,
    1223, -1493, -1493,  1224, -1493, -1493, -1493, -1493,  9651,   838,
    1240, 15568,  1010, -1493,  1226,  1240, 15568, -1493, -1493,  9651,
    9651,  9651,  9651,  1098,  9651,  9651, -1493,  9651,   340,   343,
     346,   400, -1493, -1493, -1493, -1493, -1493,  1252, -1493, -1493,
   -1493,  1014,  9651, -1493,  1258, -1493, -1493, -1493, -1493,  1228,
    9960, -1493, -1493, -1493, -1493, -1493,    98,  9960,  9960,   562,
   -1493,  1037, -1493,   501, -1493,  1034,    70,  1250, -1493, -1493,
    1149, -1493, -1493, -1493, -1493,  1308,  1229, -1493,   488, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493,   378,   378, -1493,
     298, -1493, -1493,   496, -1493,  1382,    21,  1318,  1230, 10269,
      12,  1154,  1245, -1493, -1493,  9651, -1493,  9651,  1273, -1493,
    9651, -1493, -1493, -1493,  1365, -1493, -1493,  6870,  9651,  1014,
   -1493, -1493, -1493,  9651,  9651, -1493, -1493, -1493,  6870,  6870,
    1325,  5325, 15568,  1235, 15568,  9651, 15568,  1237,  6870, -1493,
     319,    39,  1240, 15568, -1493,  1231,  1240, -1493, -1493, -1493,
   -1493,  9651, -1493, -1493, -1493,  1232,  1165,  1166,  9651, -1493,
   -1493, -1493,  1319,  9651, -1493,   684,  9960,  9960,    29,   565,
   -1493, -1493, -1493, -1493, -1493, -1493,  9651, -1493, 14707, -1493,
   14707,  1330, -1493, -1493, -1493,  1397, -1493, -1493, -1493,  1167,
    1323, -1493, -1493,  1326, -1493,   339, 15568,  1314,  1210, 15568,
   10269, -1493, -1493,  9651, -1493,  1317, -1493, -1493,  1227, -1493,
   -1493, 14707, -1493, -1493,  1342,  9651,  1253, -1493,  1343,  6870,
   -1493, 15568,   587,   794, -1493,  1242,  1240, -1493,  1246, -1493,
    6870,   841,   470, -1493,  1319,    29,    29,  9960,   472, -1493,
   -1493, 14707, -1493, -1493,  1318, 10269, -1493,  1252,  1155, 15568,
    1327,  1225,  1326, -1493, 15568,  1255, 14707,  5325, 14707,  1257,
   -1493, -1493,  1353,   657, -1493, -1493, -1493, -1493,  1261,   812,
   -1493, -1493, -1493,  1254, -1493,  1329, -1493, -1493,    29, -1493,
   -1493, -1493, -1493, -1493,  9651,  1164, 15568,  1334, -1493,  5325,
    1262, -1493, -1493,  1265,  9651, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, 15568, -1493,  1168,  1172, 15568, -1493, -1493,  9651,
    6870,  1267,  1174,  9651,  1176,  6870, 10269, -1493, 10269, -1493,
    1259,  1177, 15568,  1234,  1336, 15568,  1178, 10269, -1493
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  xquery_parser::yydefact_[] =
  {
       163,   458,   459,   460,   166,   166,   166,   808,  1013,   118,
     120,   614,   900,   909,   849,   813,   811,   793,   901,   904,
     856,   817,   794,   795,     0,   910,   797,   907,   878,   858,
     833,   853,   854,   905,   902,   852,   799,   908,   800,   801,
     949,   961,   948,   850,   869,   863,   802,   851,   804,   803,
     950,   887,   888,   855,   830,   971,   972,   973,   974,   975,
     976,   977,   978,   979,   980,   981,   995,  1002,   877,   873,
     864,   844,   792,     0,   872,   880,   889,   996,   868,   484,
     845,   846,   903,   997,  1003,   865,   882,     0,   490,   447,
     486,   875,   810,   866,   867,   896,   870,   886,   895,  1001,
    1004,   816,   857,   898,   485,   885,   891,   796,     0,     0,
       0,     0,   395,   883,   894,   899,   897,   876,   862,   951,
     860,   861,   998,     0,   394,     0,   999,  1005,   892,   847,
     871,  1000,   425,     0,   457,   893,   874,   881,   890,   884,
     952,   838,   843,   842,   841,   840,   839,   805,   859,     0,
     809,   906,   831,   940,   939,   941,   815,   814,   834,   946,
     798,   938,   943,   944,   935,   837,   879,   937,   947,   945,
     936,   835,   942,   956,   957,   954,   955,   953,   806,   958,
     959,   960,   926,   925,   912,   829,   822,   919,   915,   832,
     828,   927,   928,   818,   819,   812,   821,   924,   923,   920,
     916,   933,   934,   932,   922,   918,   911,   820,   931,   930,
     824,   826,   825,   917,   921,   913,   827,   914,   823,   929,
     982,   983,   984,   985,   986,   987,   963,   964,   962,   968,
     969,   970,   965,   966,   967,   836,   988,   989,   990,   991,
     992,   993,   994,     0,     0,  1006,  1007,  1008,  1011,  1010,
    1009,  1012,   163,   163,     0,     2,   163,     7,     9,    21,
       0,    26,    29,    34,    35,    36,    37,    38,    39,    40,
      30,    56,    57,    31,    32,     0,    74,    77,    78,    33,
      79,    80,     0,   116,    81,    82,    83,    84,    16,   160,
     161,   162,   169,   171,   477,   172,     0,   173,   174,   175,
     176,   177,   178,   179,   182,     0,   208,   217,   212,   244,
     250,     0,   242,   243,   219,   213,   181,   214,   180,   215,
     218,   348,   350,   352,   362,   364,   368,   370,   373,   378,
     381,   384,   386,   388,   390,     0,   392,   398,   400,     0,
     416,   399,   421,   424,   426,   429,   431,     0,   436,   433,
       0,   444,   454,   456,   430,   461,   468,   482,   469,   470,
     471,   474,   475,   472,   473,   497,   499,   500,   501,   498,
     546,   547,   548,   549,   550,   551,   453,   588,   580,   587,
     586,   585,   582,   584,   581,   583,   483,   476,   615,   616,
      41,   220,   221,   223,   222,   224,   216,   479,   480,   481,
     478,   226,   229,   225,   227,   228,   455,   791,   807,   900,
     909,   907,   809,     0,   164,   165,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     124,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   272,   273,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     449,   452,   439,     0,     0,   793,   817,   795,   848,   910,
     797,   858,   799,   869,   802,   804,   803,   887,   995,  1002,
     792,   996,   846,   997,  1003,   870,  1001,  1004,   951,   998,
     999,  1005,  1000,   952,   946,   938,   944,   935,   835,   956,
     957,   954,   806,   958,  1007,   445,   455,   791,   437,     0,
     189,   438,   441,   793,   794,   795,   799,   800,   801,   802,
     792,   798,   487,     0,   443,   442,   184,     0,     0,   208,
       0,   797,   804,   803,     0,   166,   766,   958,     0,   217,
       0,   488,     0,   513,     0,   448,   789,     0,   790,   419,
     420,     0,   451,   450,   440,   423,     0,     0,   542,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   768,
       0,   770,     0,     0,   163,     3,     4,     1,     8,    10,
       0,     0,     0,     0,     0,   163,   163,   163,   163,     0,
     117,   170,     0,     0,   187,     0,     0,     0,   196,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   230,   249,
     245,   251,   246,   248,   247,     0,     0,     0,   409,     0,
       0,   407,     0,   357,     0,   408,   401,   406,   405,   404,
     403,   402,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   397,   396,   393,     0,   417,   422,     0,     0,     0,
     432,   465,   435,   434,   446,     0,   462,     0,     0,   553,
     555,   559,     0,   122,     0,   788,    45,    42,    43,    46,
      47,     0,     0,     0,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   625,   626,   627,
       0,   101,   140,     0,     0,   110,     0,     0,     0,     0,
     125,     0,     0,     0,   594,     0,     0,     0,   590,     0,
       0,     0,   604,     0,     0,   253,   255,     0,   232,   233,
     252,     0,     0,     0,   132,     0,   136,   166,   618,     0,
      58,     0,    67,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,   595,     0,     0,     0,     0,   321,     0,
       0,   593,     0,     0,     0,   612,     0,     0,     0,     0,
     598,     0,     0,   191,     0,     0,   185,   183,     0,     0,
     772,     0,     0,     0,   487,     0,   767,     0,   489,   514,
     513,   510,     0,     0,   544,   543,   418,     0,   541,     0,
     638,   639,   793,   795,   799,   802,   792,   779,     0,   589,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     644,     0,   199,   200,     0,     0,     0,     0,     0,   204,
     205,   769,   771,     0,     5,    22,     0,    23,     0,     6,
      27,     0,    13,    28,     0,    17,   900,    75,    14,    76,
      18,   190,   188,     0,   209,   211,     0,     0,     0,     0,
     202,   231,   290,   349,   351,   355,   361,   360,   359,     0,
     356,   353,   354,     0,   365,   372,   371,   369,   375,   376,
     377,   374,   379,   380,   383,   382,     0,     0,     0,     0,
     414,     0,   427,   428,     0,   466,   463,   495,     0,   617,
     493,     0,     0,   119,   121,     0,     0,     0,   100,     0,
      90,    92,    93,    94,    95,    97,    98,    99,    91,    96,
      86,    87,     0,     0,   106,     0,   102,   104,   105,   112,
       0,     0,    85,    44,     0,     0,     0,     0,     0,     0,
       0,   716,   721,     0,     0,   717,   751,   704,   706,   707,
     708,   710,   712,   711,   709,   713,     0,     0,     0,     0,
       0,   109,     0,   142,     0,     0,   558,   552,   591,   592,
       0,     0,   608,     0,   605,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,   235,     0,   240,   138,
       0,     0,   133,     0,     0,     0,     0,     0,     0,    60,
       0,     0,     0,   271,   277,   274,     0,   597,   596,   603,
     611,     0,     0,     0,     0,   557,     0,     0,     0,   410,
       0,     0,     0,     0,   601,     0,   599,     0,   192,     0,
       0,   773,     0,     0,     0,     0,   513,   511,     0,   502,
       0,   491,   492,     0,    11,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   197,     0,   797,   804,   803,   958,     0,
       0,     0,   652,     0,   206,     0,     0,     0,     0,   163,
     163,   163,     0,   210,   241,     0,   305,   301,   303,     0,
     291,   292,   358,     0,     0,     0,     0,   682,   366,   655,
     659,   661,   663,   665,   668,   675,   676,   684,   910,   796,
       0,   805,  1011,  1010,  1009,  1012,   385,   564,   570,   571,
     574,   619,   620,   575,   576,   782,   783,   784,   579,   387,
     389,   561,   391,   415,   467,     0,   464,   494,   123,    54,
      55,    52,    53,   129,   128,     0,    88,     0,     0,   107,
     108,   113,    72,    73,    50,    51,    71,   722,     0,   725,
     752,     0,   715,   714,   719,   718,   750,     0,     0,   727,
       0,   723,   726,   705,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   141,   144,   146,     0,     0,     0,
     111,   114,     0,     0,     0,   166,     0,     0,   612,     0,
       0,     0,   257,     0,   563,     0,   258,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,     0,     0,
       0,   284,     0,   281,   286,   239,   139,   134,   137,     0,
     186,     0,     0,    69,    63,    66,    65,     0,    61,   275,
       0,     0,   166,     0,   319,   323,     0,     0,     0,   326,
       0,     0,   332,     0,     0,   339,     0,   343,     0,   412,
     411,   166,     0,     0,   193,     0,   195,   320,     0,     0,
       0,     0,   514,     0,   503,     0,   537,   534,     0,   538,
     539,     0,     0,   533,     0,   508,   536,   535,     0,     0,
       0,   631,   632,   628,     0,     0,   636,   637,   633,   775,
     776,   642,   780,   640,     0,     0,     0,     0,   646,   198,
       0,     0,     0,     0,     0,     0,   647,   648,     0,   207,
     778,    24,     0,    15,    19,    20,   302,   314,     0,   315,
       0,   306,   307,   308,   309,     0,   294,     0,     0,     0,
     666,   679,     0,   363,   367,     0,   698,     0,     0,     0,
       0,     0,     0,   654,   656,   657,   693,   694,   695,   697,
     696,     0,     0,   670,   669,     0,   673,   677,   691,   689,
     688,   681,   685,     0,     0,     0,     0,     0,     0,     0,
       0,   567,   569,   568,   565,   562,   496,   131,   130,    89,
     103,   739,   720,     0,   744,     0,   744,   733,   728,   145,
     147,     0,     0,     0,   115,   143,     0,    25,     0,   609,
     610,   613,   606,   607,   256,     0,     0,   270,   262,     0,
     266,     0,   260,     0,     0,     0,   279,     0,     0,     0,
     238,   282,   285,     0,   135,     0,     0,    68,     0,    62,
     276,     0,     0,   322,   324,   329,     0,   327,     0,     0,
       0,     0,     0,   333,     0,     0,     0,     0,   340,     0,
       0,   344,   413,     0,   602,   600,   194,   774,     0,     0,
     513,     0,     0,   545,     0,   513,     0,   509,    12,     0,
       0,     0,     0,     0,     0,     0,   645,     0,     0,     0,
       0,     0,   649,   653,   318,   316,   317,   310,   311,   312,
     304,     0,     0,   299,     0,   293,   683,   674,   680,     0,
       0,   753,   754,   764,   763,   762,     0,     0,     0,     0,
     755,   660,   761,     0,   658,   662,     0,     0,   667,   671,
       0,   692,   687,   690,   686,     0,     0,   577,     0,   572,
     624,   566,   786,   787,   785,   573,   740,     0,     0,   738,
     745,   746,   742,     0,   737,     0,   735,     0,     0,     0,
       0,     0,     0,   554,   259,     0,   268,     0,     0,   264,
       0,   267,   280,   288,   289,   283,   237,     0,     0,     0,
      64,   278,   560,     0,     0,   330,   334,   328,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   556,
       0,     0,   513,     0,   540,     0,   513,   629,   630,   634,
     635,     0,   641,   781,   643,     0,     0,     0,     0,   650,
     313,   300,   295,     0,   678,   765,     0,     0,   757,     0,
     703,   702,   701,   700,   699,   664,     0,   756,     0,   621,
       0,     0,   749,   748,   747,     0,   741,   734,   732,     0,
     729,   730,   724,   148,   150,   152,     0,     0,     0,     0,
       0,   263,   261,     0,   269,     0,   203,   347,    70,   325,
     331,     0,   345,   341,     0,     0,     0,   335,     0,     0,
     337,     0,   523,   517,   512,     0,   513,   504,     0,   777,
       0,     0,     0,   298,   296,   759,   758,     0,     0,   622,
     578,     0,   743,   736,     0,     0,   154,   153,     0,     0,
       0,     0,   149,   265,     0,     0,     0,     0,     0,     0,
     531,   525,     0,   524,   526,   532,   529,   519,     0,   518,
     520,   530,   506,     0,   505,     0,   651,   297,   760,   672,
     623,   731,   151,   155,     0,     0,     0,     0,   287,     0,
       0,   338,   336,     0,     0,   516,   527,   528,   515,   521,
     522,   507,     0,   156,     0,     0,     0,   346,   342,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,   157,
       0,     0,     0,     0,     0,     0,     0,     0,   159
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yypgoto_[] =
  {
     -1493, -1493,  -235,  -196, -1493,  1199,  1208, -1493,  1212,  -541,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
    -982, -1493, -1493, -1493, -1493,  -244,  -574, -1493,   739,  -223,
   -1493, -1493, -1493, -1493, -1493,   278,   511, -1493, -1493,   -10,
    -116,  1053, -1493,  1028, -1493, -1493,  -633, -1493,   448, -1493,
     252, -1493,  -215,  -258, -1493,  -549, -1493,     5,    77,    14,
    -236,  -176, -1493,  -875, -1493, -1493,   240, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493,   619,   -82,  1374,
       0, -1493, -1493, -1493, -1493,   469, -1493, -1493,  -287, -1493,
       8, -1493,  1032,  -917,  -734,  -703, -1493, -1493,   710, -1493,
   -1493,    30,   241, -1493, -1493, -1493,   128, -1492, -1493,   381,
     132, -1493, -1493,   131, -1310, -1493,   955,   226, -1493, -1493,
     222, -1016, -1493, -1493,   220, -1493, -1493, -1251, -1245, -1493,
     216, -1493, -1493,   858,   864, -1493,  -560,   839, -1493, -1493,
    -646,   314,  -635,   313,   315, -1493, -1493, -1493, -1493, -1493,
    1179, -1493, -1493, -1493, -1493,  -874,  -332, -1168, -1493,  -107,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493,   -13,  -820, -1493,
    -537,   626,   106, -1493,  -387, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493,   808, -1493, -1024, -1493,   200, -1493,   687,  -804,
   -1493, -1493, -1493, -1493, -1493,  -250,  -241, -1175,  -862, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,   596,
    -756,  -900,  -227,  -848, -1493,    83,  -852, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493,  1066,  1070,  -301,   513,   347, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
   -1493, -1493, -1493,   187, -1493, -1493,   179, -1493,   181, -1061,
   -1493, -1493, -1493,   147,   137,   -27,   405, -1493, -1493, -1493,
   -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493, -1493,
     149, -1493, -1493, -1493,   -22,   398,   548, -1493, -1493, -1493,
   -1493, -1493,   335, -1493, -1493, -1463, -1493, -1493, -1493,  -578,
   -1493,   110, -1493,   -43, -1493, -1493, -1493, -1493, -1285, -1493,
     157, -1493, -1493, -1493, -1493, -1493,   953, -1493, -1493, -1493,
   -1493, -1493,  -911, -1493, -1493, -1493,  -419,  -371,   235,   603,
   -1493
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  xquery_parser::yydefgoto_[] =
  {
        -1,   254,   627,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
    1263,   775,   272,   273,   274,   275,   276,   277,   950,   951,
     952,   278,   279,   280,   956,   957,   958,   281,   438,   282,
     283,   702,   284,   440,   441,   442,   457,   765,   766,   285,
    1214,   286,  1683,  1684,   287,   288,   289,   547,   290,   291,
     292,   293,   294,   768,   295,   296,   530,   297,   298,   299,
     300,   301,   302,   637,   303,   304,   859,   860,   305,   306,
     559,   308,   638,   455,  1017,  1018,   309,   639,   310,   641,
     560,   312,   755,   756,  1251,   464,   313,   465,   466,   762,
    1252,  1253,  1254,   642,   643,  1120,  1121,  1533,   644,  1117,
    1118,  1361,  1362,  1363,  1364,   314,   787,   788,   315,  1278,
    1279,  1478,   316,  1281,  1282,   317,   318,  1284,  1285,  1286,
    1287,   319,   320,   321,   322,   899,   323,   324,  1373,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   662,   663,   337,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   696,   691,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   928,   364,   365,   366,  1314,   820,   821,   822,
    1714,  1758,  1759,  1752,  1753,  1760,  1754,  1315,  1316,   367,
     368,  1317,   369,   370,   371,   372,   373,   374,   375,  1160,
    1012,  1146,  1414,  1147,  1568,  1148,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   794,  1227,   386,   387,
     388,   389,  1150,  1151,  1152,  1153,   390,   391,   392,   393,
     394,   395,   849,   850,   396,  1346,  1347,  1649,  1103,  1128,
    1383,  1384,  1129,  1130,  1131,  1132,  1133,  1393,  1558,  1559,
    1134,  1396,  1135,  1539,  1136,  1137,  1401,  1402,  1564,  1562,
    1385,  1386,  1387,  1388,  1663,   731,   977,   978,   979,   980,
     981,   982,  1201,  1588,  1680,  1202,  1586,  1678,   983,  1426,
    1583,  1579,  1580,  1581,   984,   985,  1389,  1397,  1549,  1390,
    1545,  1374,   397,   398,   399,   400,   550,   401,   402,   403,
     404,   405,  1154,  1155,  1156,  1157,  1264,   567,   406,   407,
     408
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int xquery_parser::yytable_ninf_ = -849;
  const short int
  xquery_parser::yytable_[] =
  {
       307,   706,   439,   598,   307,   307,   307,   685,   311,   413,
     416,   417,   311,   311,   311,   613,  1068,  1159,   415,   415,
     415,  1032,   907,  1010,   640,   616,   575,   558,   562,  1126,
    1280,   703,   703,  1044,   908,   909,   910,   911,  1102,  1488,
     618,   772,   776,   877,   879,   837,  1313,  1058,  1268,  1431,
    1499,   845,  1528,  1529,  1011,   621,   605,   606,   625,   625,
     525,   726,  1174,  1369,  1149,  1149,   872,   875,   878,   880,
       9,    10,   741,  1204,   870,   873,  1216,  1240,  1205,   746,
     937,   414,   414,   414,  1006,     9,    10,   895,  1232,   896,
     897,   424,   898,  1206,   900,  1207,   747,   784,  1014,    11,
     614,  1149,   901,   902,  1208,  1178,   424,  1234,   307,   614,
    1560,   705,   824,   614,   614,   425,   311,  1546,   427,  1270,
    1257,   721,   548,   722,  1681,    11,   614,   614,   614,   462,
    1686,  1209,  1712,   427,  1041,  1215,   587,  1008,   428,  1507,
     625,   580,  1007,   581,  1008,     9,    10,  1479,   577,   584,
    1656,   585,   589,  1479,  1479,  1149,   737,   590,  1069,  1007,
    1723,   600,   602,   932,   626,   626,   620,  1192,  1149,  1624,
     429,   430,  1112,   689,   666,   695,   715,  1008,  1193,   621,
      79,   625,   724,  1169,  1541,   414,  1247,   666,  1241,   625,
    1358,  1248,   667,  1171,    90,  1009,   809,   443,   625,  1375,
    1170,   746,   966,  1181,   967,   667,    79,  1375,   716,   622,
    1172,  1360,  1043,   625,   668,  1042,   418,  1650,   747,   104,
      90,  1542,  1713,  1123,  1070,   588,  1124,  1657,  1445,  1008,
     582,   619,  1767,  1480,   625,   686,  1687,  1625,   586,  1614,
    1619,   591,   771,   933,   725,   104,   626,   125,   968,   463,
    1126,  1126,   307,   307,  1488,  1515,   307,  1245,  1210,  1015,
     311,   311,  1303,  1256,   311,  1482,   420,   421,  1592,   422,
     423,  1771,  1376,   640,   625,   625,  1547,  1548,  1242,   825,
    1376,  1313,   625,   463,   625,  1469,   426,   626,  1149,   615,
    1313,   307,  1405,   877,   879,   626,  1016,  1237,   617,   311,
    1418,  1679,   865,   867,   626,   963,  1175,  1238,   526,  1243,
    1538,  1216,   621,   463,  1444,  1109,  1111,  1351,  1688,   626,
     463,  1084,   542,   620,   870,   873,   818,  1507,  1125,  1271,
     738,   578,   625,   622,   692,  1306,  1307,   694,   739,  1122,
     626,   625,  1352,   748,   625,   435,   563,   625,  -167,   625,
    1211,  1212,  1213,   436,  1377,  1378,  1029,  1379,   568,  1464,
     571,   437,  1377,  1378,  1380,  1379,   751,  1024,   861,   862,
    1215,   871,   874,   816,  1381,  1736,   769,   866,   868,   705,
     626,   626,  1381,  1485,  1046,   781,  1382,   625,   626,   432,
     626,   808,   792,   793,  1382,   625,  1721,  1164,   969,   890,
    1025,   799,  1090,  1028,  -168,   625,  1453,  1149,   864,   623,
     809,   970,   763,   971,  1041,   307,   932,   684,   625,  1343,
    1047,  1685,   463,   311,   972,   973,   974,  1773,   975,  1308,
     976,  1149,  1001,  1007,  1577,  1007,  1543,  1711,   626,  1003,
     610,   125,  1304,  1544,   307,  1358,   307,   626,   433,  1309,
     626,  1310,   311,   626,   311,   626,   611,  1000,   743,   625,
     743,  1094,   625,   773,  1021,  1434,   622,   625,  1299,   625,
    1300,   625,   307,   625,  1423,  1348,  1488,   307,  1313,  1311,
     311,   764,   823,   111,  1053,   311,   743,   810,  1244,   434,
    1075,   743,   624,   626,   827,  1060,   934,  1126,  1578,  1446,
     123,   626,  1083,  1567,  1055,  1625,  1126,   621,  1305,  1198,
     774,   626,  1002,   476,   855,   857,  1127,  1126,  1301,  1004,
    1312,   742,  1685,   745,   626,  1102,  1199,  1645,  1523,  1091,
    1646,   463,  -167,  1647,  1425,   877,   879,   877,   149,  1454,
    1073,  1182,  1183,  1008,  1022,  1168,  1186,  1194,   307,   790,
    1079,  1149,  1335,  1648,   796,   307,   311,   419,  1195,  1411,
    1353,  1354,  1355,   311,  1054,   626,  1165,  1685,   626,   415,
    1036,  1165,   721,   626,   722,   626,  1224,   626,  1052,   626,
     922,   923,   526,  1007,  1056,   526,  1623,   446,  -168,  1627,
     477,  1412,  1750,  1007,  1597,  1670,  1306,   307,    11,  1074,
     439,  1071,   921,  1675,   307,   311,   723,   924,  1413,  1348,
    1534,   856,   311,  1076,  1077,   307,   307,   307,   307,   447,
     621,  1106,   471,   311,   311,   311,   311,  1698,  1078,   456,
    1482,  1031,   414,   724,  1149,   307,  1110,  1149,  1809,   868,
    1810,  1057,  1072,   311,   480,  1101,  1166,  1086,  1247,  1818,
    1163,  1167,  1536,  1248,  1766,   675,  1769,   478,   479,   666,
     714,   622,  1750,   718,  1198,   458,  1306,   568,  1007,   676,
     732,   733,  1249,  1080,  1081,  1671,   527,   667,   568,    79,
    1531,  1199,  1126,  1676,   754,   757,   687,   688,  1082,   757,
     527,  1008,   450,    90,   451,   725,  1631,   777,  1423,   953,
    1226,  1635,  1229,   568,   785,   786,   789,   689,   707,   695,
    1309,   795,  1310,  1250,   527,  1424,  1532,  1598,   104,   802,
    1751,   708,  1123,   666,  1200,  1124,   527,  1176,   527,  1063,
    1064,  1065,   669,   857,  1357,   469,  1553,  1127,  1127,  1176,
    1311,   667,   954,   307,   629,  1358,   125,   955,   630,   459,
     470,   311,  1292,   631,  1293,  1359,   629,   452,  1425,   460,
     630,   670,   453,  1727,   803,   631,  1360,   307,  1729,  1660,
    1730,   632,  1023,   482,   671,   311,  1661,   877,   789,   711,
    1309,   415,  1310,   632,  1107,   461,  1662,  1184,  1185,   814,
    1786,  1371,  1306,  1307,   685,   712,   925,   307,   307,   925,
     611,  1745,   925,  1306,   483,   311,   311,   484,   672,   454,
    1311,   743,   743,   640,   474,   125,  1149,   838,  1149,  1398,
    1399,  1306,  1756,   838,     9,    10,   475,   851,  1715,   735,
    1660,  1770,  1718,   481,   736,   420,   421,  1661,   422,   423,
    1756,   528,  1400,  1467,   414,   424,  1780,  1662,  1783,  1149,
    1755,  1761,  1173,   629,   425,   426,  1099,   630,  1339,   881,
    1417,   529,   631,   882,  1100,   709,   439,   689,   767,   695,
     633,   868,   427,   634,  1050,  1051,   767,   428,   710,  1149,
     632,   531,   633,  1218,   673,   634,  1308,  1319,   635,  1320,
    1277,  1755,  1219,   674,  1149,   444,  1149,  1761,   445,   954,
     817,  1658,  1659,  1476,   955,  1655,  1309,   532,  1310,   429,
     430,   431,  1763,   636,   727,   728,   729,  1309,  1277,  1310,
    1306,  1307,   598,   448,   543,   636,   449,  1349,  1757,  1737,
    1486,  1481,  1489,  1525,  1526,  1309,  1311,  1310,  1486,  1524,
     111,  1486,   544,  1487,  1247,  1490,  1789,  1311,   545,  1248,
     527,  1630,   564,   527,  1765,   959,   467,   123,   432,   468,
     576,  1187,  1188,  1189,  1324,  1311,  1325,  1190,   472,   989,
     565,   473,   690,   993,   994,   693,   572,  1501,   573,   633,
     905,   906,   634,   574,  1127,   583,   912,   913,  1429,  1430,
     914,   915,   579,  1127,   592,   149,  1013,  1344,  1019,  1672,
    1673,  1161,  1161,   593,  1127,   594,   568,   595,   596,   568,
    1725,  1726,   597,  1033,  1308,   607,   603,   433,   628,  1306,
    1307,   646,   636,   664,   645,  1465,   665,   713,   527,   677,
     678,   527,   679,   689,  1309,   527,  1310,   680,   527,   527,
     697,  1368,   698,   705,   699,   717,   527,   700,   307,  1610,
     701,   719,   527,   527,  1066,   720,   311,   527,   434,   730,
     734,   744,   743,   758,  1311,   527,   761,   759,   111,   767,
     770,   527,   527,   527,   527,   778,   779,   780,   797,   527,
     791,  1768,   445,   798,   435,   123,   804,   527,   449,   468,
     806,   815,   436,   526,  1099,   473,   484,   808,   439,   811,
     437,   812,  1100,   813,   826,  1506,   819,   828,   890,   307,
     307,   307,  1651,  1308,   829,   839,   848,   311,   311,   311,
     847,  1114,   858,   149,   869,  1288,   852,   886,   887,   888,
     903,   853,   527,  1309,   889,  1310,   647,   916,   917,   918,
     919,   929,   935,   936,   648,   649,   527,   650,   938,   960,
     961,  1158,  1158,  1158,  1158,   651,   964,   527,   965,   652,
     986,   653,   987,  1311,   990,   988,   654,   111,   992,  1127,
     940,   941,   942,   943,   944,   945,   946,   947,   948,   949,
     995,   996,   998,   655,   123,   997,   999,  1005,  1158,  1020,
    1026,  1027,  1030,  1037,  1038,   527,  1048,  1045,  1039,  1040,
    1049,  1085,  1191,  1087,  1633,   444,   656,   657,   658,   659,
     660,   661,   448,  1089,   467,   472,   483,  1088,  1092,  1105,
    1093,  1108,   149,  1113,  1115,   307,  1119,  1221,   955,  1177,
    1438,  1007,  1196,   311,  1197,  1222,  1228,  1225,  1228,   415,
     757,  1233,  1158,  1217,  1616,  1235,  1239,  1246,  1223,   763,
    1259,  1260,  1261,  1265,  1262,  1158,  1266,  1267,  1518,  1519,
    1520,   307,  1272,  1273,  1276,  1277,  1283,  1289,  1291,   311,
    1295,  1296,   307,  1290,  1298,  1302,  1318,  1472,  1336,  1340,
     311,  1341,  1342,  1343,  1345,   723,   415,  1365,   795,  1367,
     795,   307,  1372,  1392,  1391,  1403,  1493,  1395,  1404,   311,
    1406,  1415,   414,  1407,  1408,   415,  1409,  1410,    11,  1421,
    1422,   307,  1427,  1432,  1436,  1441,  1439,  1449,  1451,   311,
     939,  1440,  1437,   527,   838,   743,  1433,  1442,  1455,  1458,
    1443,  1457,  1459,  1463,  1468,  1471,  1492,   527,  1486,  1500,
    1503,   527,   527,  1099,  1099,  1494,  1495,  1513,  1509,   414,
    1510,  1100,  1100,  1508,  1366,  1517,  1514,   856,  1358,  1498,
    1537,  1540,  1550,  1556,   527,  1511,   527,  1512,   414,  1563,
    1569,  1696,  1557,  1570,   527,  1158,  1571,   527,  1576,  1572,
    1582,   527,  1700,  1616,  1573,  1702,  1561,  1574,  1504,  1575,
    1589,  1587,  1710,  1593,  1591,  1595,  1600,  1607,  1608,  1609,
    1653,  1612,  1668,  1666,  1613,  1618,  1585,  1621,  1629,  1628,
    1634,  1677,  1654,  1641,  1198,  1690,  1669,  1682,  1695,  1701,
    1693,  1705,   527,  1709,  1731,  1531,  1732,  1717,  1667,  1720,
    1734,  1733,  1739,  1735,  1740,  1744,  1746,  1748,  1762,  1747,
    1689,  1779,  1764,  1784,  1788,  1776,  1785,  1792,  1799,  1777,
    1791,  1800,  1796,  1805,  1815,   608,  1420,  1811,  1814,  1774,
    1802,   527,   962,  1812,   609,  1179,   757,   740,  1794,  1258,
    1447,   612,   704,  1702,  1435,  1742,  1803,  1772,  1104,  1806,
     307,  1808,   549,  1817,  1465,  1461,   760,  1255,   311,   527,
    1035,  1605,  1462,  1527,  1158,  1535,  1356,  1530,   805,  1473,
    1477,  1483,  1491,   893,   904,  1502,   931,  1067,   789,  1790,
     894,  1781,  1787,   749,   683,  1162,  1230,   750,  1158,   527,
     527,   527,   527,  1516,  1419,  1522,  1521,  1551,  1555,  1665,
    1370,  1664,  1394,  1554,  1203,  1428,  1584,  1674,  1552,   843,
       0,     0,     0,  1797,     0,     0,     0,  1505,     0,     0,
       0,     0,     0,     0,     0,     0,   527,     0,     0,     0,
       0,     0,     0,     0,  1797,     0,  1722,     0,     0,  1781,
     527,   851,     0,     0,     0,     0,     0,     0,     0,     0,
     526,     0,     0,   526,  1728,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,     0,     0,     0,
       0,     0,     0,     0,   527,     0,   527,  1099,   527,     0,
     527,     0,     0,     0,     0,  1100,     0,     0,  1099,  1099,
       0,   307,     0,   527,     0,     0,  1100,  1100,  1099,   311,
       0,     0,     0,     0,     0,     0,  1100,     0,  1158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   527,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,  1590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1603,  1604,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1099,
       0,     0,     0,     0,     0,     0,     0,  1100,     0,  1620,
    1099,  1158,   527,     0,  1158,     0,     0,     0,  1100,     0,
       0,     0,     0,     0,     0,     0,  1632,     0,     0,     0,
       0,  1636,     0,   527,     0,     0,     0,   307,     0,     0,
       0,     0,     0,     0,     0,   311,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   307,
       0,     0,     0,     0,     0,     0,     0,   311,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1099,     0,     0,     0,     0,  1099,     0,     0,  1100,     0,
       0,     0,     0,  1100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   527,     0,     0,     0,  1704,     0,  1706,
       0,  1708,   527,     0,     0,     0,     0,     0,  1716,     0,
       0,     0,     0,     0,     0,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1158,     0,  1158,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,     0,     0,     0,
       0,  1738,     0,     0,  1741,     0,     0,     0,     0,   549,
       0,     0,     0,     0,     0,     0,  1158,     0,     0,   527,
       0,     0,     0,     0,     0,     0,  1749,     0,   527,     0,
       0,   527,     0,     0,   830,   831,     0,     0,   840,   841,
     842,   844,     0,   846,     0,     0,  1158,     0,     0,   854,
       0,     0,     0,     0,  1775,     0,     0,   863,     0,  1778,
       0,  1158,     0,  1158,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   883,
     884,   885,     0,     0,     0,     0,   527,     0,     0,   891,
     892,  1795,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1801,     0,     0,
       0,  1804,     0,     0,     0,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1813,     0,     0,
    1816,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   527,   527,     0,     0,     0,     0,     0,     0,   927,
       0,     0,   927,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   527,     0,   527,
       0,     0,   527,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,     0,   527,
     991,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1034,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1059,     0,
       0,     0,  1061,  1062,     0,     0,     0,     0,     0,     0,
       0,   891,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,   527,     0,   527,
       0,     0,     0,     0,     0,     0,   527,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1116,     0,     0,     0,     0,     0,     0,     0,
       0,   527,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,     0,   527,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   527,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1180,
       0,     0,     0,     0,   527,     0,     0,     0,     0,     0,
       0,     0,   527,     0,     0,     0,     0,   527,     0,   527,
       0,   527,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1220,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   527,
       0,     0,     0,  1236,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,     0,     0,     0,   527,
       0,     0,     0,     0,     0,  1269,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   527,  1274,  1275,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1294,     0,     0,  1297,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1321,  1322,  1323,     0,  1326,  1327,  1328,  1329,  1330,  1331,
    1332,  1333,  1334,     0,     0,  1337,  1338,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1350,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1416,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -848,   450,     0,   451,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1448,     0,  1450,     0,  1452,     0,     0,  1456,     0,
       0,     0,     0,  1460,     0,     0,     0,     0,  -848,     0,
       0,     0,  -848,     0,     0,  1466,  -848,  -848,     0,     0,
       0,  -848,     0,     0,  1470,     0,     0,     0,     0,     0,
    1474,  1475,   452,     0,     0,  -848,     0,   453,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1496,
       0,     0,  1497,     0,     0,     0,     0,     0,  -848,     0,
    -848,  -848,  -848,     0,     0,  -848,  -848,  -848,  -848,     0,
       0,     0,  -848,  -848,     0,     0,     0,     0,     0,  -848,
       0,     0,  -848,  -848,   454,     0,     0,  -848,     0,     0,
       0,     0,  -848,  -848,     0,     0,     0,     0,  -848,     0,
       0,     0,  -848,     0,     0,     0,  -848,  -848,     0,  -848,
       0,  -848,  -848,     0,     0,     0,  -848,  -848,     0,  1116,
    -848,  -848,  -848,  -848,  -848,  -848,     0,     0,  -848,     0,
       0,     0,     0,  -848,  -848,     0,     0,  -848,     0,     0,
       0,     0,  -848,     0,     0,  -848,     0,     0,     0,     0,
    -848,  -848,  -848,  -848,  -848,     0,  -848,  -848,  -848,  -848,
       0,     0,     0,     0,  -848,  -848,  -848,     0,  -848,  -848,
    -848,  -848,  -848,  -848,     0,  -848,     0,  -848,     0,     0,
       0,     0,  -848,  -848,  -848,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -848,  1594,
    -848,     0,  -848,  1596,     0,     0,     0,  1599,     0,  1601,
       0,  1602,     0,     0,  -848,     0,     0,  1606,     0,  -848,
       0,     0,     0,     0,     0,  1611,     0,     0,     0,     0,
       0,     0,     0,  1615,  1617,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1466,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1637,  1638,  1639,  1640,     0,  1642,  1643,
       0,  1644,     0,     0,     0,     0,  -848,     0,  -848,     0,
       0,     0,     0,     0,     0,     0,  1652,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1691,
       0,  1692,     0,     0,  1694,     0,     0,     0,     0,     0,
       0,     0,  1697,     0,     0,     0,     0,  1699,  1617,     0,
       0,     0,     0,     0,     0,  1703,     0,     0,     0,  1707,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1719,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1724,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1743,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1703,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1782,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1793,     0,
       0,     0,     0,  1798,     0,     0,     0,     0,  1782,     0,
       0,   869,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     0,     0,  1798,     0,     0,     0,  1807,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   409,   410,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,   551,   411,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     552,   553,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     502,    82,    83,    84,    85,    86,   554,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   555,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   519,   520,   521,   176,   177,
     522,   557,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
      12,    13,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
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
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
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
     245,   246,   247,   248,   249,   250,   251,   252,   253,     1,
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
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     0,   604,
       1,     2,     0,     0,     0,     0,     0,     0,     0,     3,
       4,     5,     6,     7,     8,     9,    10,     0,    11,     0,
       0,     0,   409,   410,     0,    14,    15,    16,    17,    18,
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
     127,   128,     0,   546,     0,   129,     0,   130,   131,     0,
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
      20,    21,    22,    23,    24,    25,    26,   411,    28,    29,
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
     128,     0,   807,     0,   129,     0,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,     0,   193,   194,   195,     0,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,     0,   244,
       0,   245,   246,   247,   248,   249,   250,   251,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     3,     4,     5,
       6,     7,     8,     9,    10,     0,    11,     0,     0,     0,
     409,   410,     0,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,  1095,   411,    28,    29,    30,
      31,     0,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    45,    46,    47,  1096,
    1097,    50,    51,    52,    53,    54,    55,    56,    57,    58,
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
       0,   807,     0,   129,     0,   130,   131,     0,   132,   133,
     134,     0,   135,     0,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,   147,   148,   149,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
    1098,   180,   181,   182,   183,   184,   185,   186,   187,   188,
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
      22,    23,    24,    25,  1095,   411,    28,    29,    30,    31,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,     0,    45,    46,    47,  1096,  1097,
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
     546,     0,   129,     0,   130,   131,     0,   132,   133,   134,
       0,   135,     0,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,   149,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,  1098,
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
      23,    24,    25,    26,   411,    28,    29,    30,    31,     0,
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
     144,   145,   146,     0,     0,   147,   148,   149,     0,   412,
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
     129,     0,   130,   131,     0,   132,   133,   134,     0,   135,
       0,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,     0,     0,   147,   148,   149,     0,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,     0,   193,   194,   195,     0,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
     248,   249,   250,   251,     1,     2,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      10,     0,    11,     0,     0,     0,    12,    13,     0,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     0,    32,    33,
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
       0,    11,     0,     0,     0,    12,   410,     0,    14,    15,
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
       0,     0,   147,   148,   149,     0,   412,   151,   152,   153,
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
      11,     0,     0,     0,   876,   410,     0,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
     411,    28,    29,    30,    31,     0,    32,    33,    34,    35,
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
       0,     0,     0,   409,   410,     0,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,  1095,   411,
      28,    29,    30,    31,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     0,    45,
      46,    47,  1096,  1097,    50,    51,    52,    53,    54,    55,
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
     176,   177,   178,  1098,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
       0,   244,     0,   245,   246,   247,   248,   249,   250,   251,
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
     127,   128,     0,     0,   556,   129,     0,   130,   131,     0,
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
      20,    21,    22,    23,    24,    25,   551,   411,    28,    29,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,     0,    45,    46,    47,
     552,   553,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     502,    82,    83,    84,    85,    86,   554,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,    96,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   555,   109,     0,   110,   111,   112,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,   124,   125,     0,     0,   126,   127,
     128,     0,     0,     0,   129,   561,   130,   131,     0,   132,
     133,   134,     0,   135,     0,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,     0,     0,   147,   148,
     149,     0,   412,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   519,   520,   521,   176,   177,
     522,   557,   180,   181,   182,   183,   184,   185,   186,   187,
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
       0,     0,     0,   129,     0,   130,   131,     0,   132,   133,
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
     237,   238,   239,   240,   241,   242,   243,   599,   244,     0,
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
       0,     0,   129,     0,   130,   131,     0,   132,   133,   134,
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
     238,   239,   240,   241,   242,   243,     0,   244,   601,   245,
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
       0,   124,   125,     0,     0,   126,   127,   128,     0,   920,
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
     239,   240,   241,   242,   243,     0,   244,     0,   245,   246,
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
     129,   926,   130,   131,     0,   132,   133,   134,     0,   135,
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
     240,   241,   242,   243,     0,   244,     0,   245,   246,   247,
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
     125,     0,     0,   126,   127,   128,     0,     0,     0,   129,
     930,   130,   131,     0,   132,   133,   134,     0,   135,     0,
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
      16,    17,    18,    19,    20,    21,    22,    23,   488,    25,
     490,   411,    28,   491,    30,    31,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,   493,
       0,    45,    46,    47,   495,   496,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,    69,    70,    71,    72,
      73,     0,    74,    75,    76,     0,     0,    77,    78,     0,
       0,     0,    79,    80,   502,    82,    83,    84,    85,    86,
     554,    88,    89,     0,     0,     0,    90,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   505,    97,    98,
      99,   100,     0,     0,     0,     0,     0,     0,   101,   102,
     103,   104,   105,   106,   107,   555,   109,     0,   110,   111,
     681,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   119,   120,   121,   122,     0,   123,     0,   682,   125,
       0,     0,   126,   127,   128,     0,     0,     0,   129,     0,
     130,   131,     0,   132,   133,   134,     0,   135,     0,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,   149,     0,   412,   151,   152,   153,
     154,   155,   156,   157,   158,   514,   160,   515,   162,   516,
     517,   165,   166,   167,   168,   169,   170,   518,   172,   519,
     520,   521,   176,   177,   522,   523,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,     0,   244,     0,   245,   524,   247,   248,   249,
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
       0,   126,   127,   128,     0,     0,     0,   129,     0,   130,
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
     105,   106,   107,   555,   109,     0,   110,   111,   112,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   119,
     120,   121,   122,     0,   123,     0,   124,   125,     0,     0,
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
      19,    20,    21,    22,    23,   488,    25,   490,   411,    28,
     491,    30,    31,     0,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,   493,     0,    45,    46,
      47,   495,   496,    50,   497,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,    69,    70,    71,    72,    73,     0,    74,
      75,    76,     0,     0,    77,    78,     0,     0,     0,    79,
      80,   502,    82,    83,    84,    85,    86,   554,    88,    89,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   505,    97,    98,    99,   100,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   555,   109,     0,   110,   111,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   122,     0,   123,     0,     0,     0,     0,     0,   126,
     127,   128,     0,     0,     0,   129,     0,   130,   131,     0,
     132,   133,   134,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   412,   151,   152,   153,   154,   155,   156,
     157,   158,   514,   160,   515,   162,   516,   517,   165,   166,
     167,   168,   169,   170,   518,   172,   519,   520,   521,   176,
     177,   522,   523,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   524,   247,   248,   249,   250,   251,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     3,     4,
       5,     6,     7,     8,     0,     0,     0,    11,     0,     0,
       0,   409,   410,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   488,    25,   490,   411,    28,   491,
      30,    31,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,   493,     0,    45,    46,    47,
     495,   496,    50,   497,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,    69,    70,    71,    72,    73,     0,    74,    75,
      76,     0,     0,    77,    78,     0,     0,     0,    79,    80,
     502,    82,    83,    84,    85,    86,   554,    88,    89,     0,
       0,     0,    90,     0,    91,    92,    93,    94,     0,    95,
       0,     0,     0,   505,    97,    98,    99,   100,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
     107,   555,   109,     0,   110,   111,     0,   113,   114,     0,
       0,     0,     0,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,     0,     0,     0,     0,   126,   127,
     128,     0,     0,     0,   129,     0,   130,   131,     0,     0,
       0,   134,     0,   135,     0,   136,   137,   138,   139,   140,
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
       0,     0,   505,     0,    98,    99,   100,     0,     0,     0,
       0,     0,     0,   101,   102,   103,   104,     0,   106,   107,
     555,   109,     0,   110,   111,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   119,   120,   121,   122,
       0,   123,     0,     0,     0,     0,     0,   126,   127,   128,
       0,     0,     0,   129,     0,   130,   131,     0,     0,     0,
     134,     0,   135,     0,   136,     0,   138,     0,   140,   141,
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
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       7,     8,     0,     0,     0,     0,     0,     0,     0,   409,
     410,     0,    14,    15,    16,   485,    18,    19,    20,   486,
      22,   487,   488,   489,   490,   411,    28,   491,    30,    31,
       0,    32,    33,    34,    35,   492,    37,    38,    39,    40,
      41,    42,    43,   493,     0,    45,   494,    47,   495,   496,
      50,   497,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   498,   499,    68,     0,
      69,    70,    71,   500,     0,     0,    74,    75,    76,     0,
       0,   501,    78,     0,     0,     0,     0,    80,   502,    82,
     503,   504,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   505,    97,    98,   506,   507,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,   107,     0,
       0,     0,     0,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   508,   120,   121,   509,     0,
       0,     0,     0,     0,     0,     0,   510,   511,   128,     0,
       0,     0,   129,     0,   130,   512,     0,     0,     0,   134,
       0,   135,     0,   136,   137,   138,   139,   513,   141,   142,
     143,   144,   145,   146,     0,     0,   147,   148,     0,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   514,
     160,   515,   162,   516,   517,   165,   166,   167,   168,   169,
     170,   518,   172,   519,   520,   521,   176,   177,   522,   523,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     1,     2,   245,
     524,   247,   248,   249,   250,   251,     3,     0,     0,     0,
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
       0,     0,   129,     0,   130,   512,     0,     0,     0,   134,
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
     238,   239,   240,   241,   242,     0,     0,     0,   566,   245,
     524,   247,   248,   249,   250,   251,     7,     8,     0,     0,
       0,   782,     0,     0,     0,   409,   410,     0,    14,    15,
      16,   533,    18,    19,    20,   486,   534,   535,   488,   489,
     490,   411,    28,   491,    30,    31,     0,    32,    33,    34,
      35,   536,    37,   537,   538,    40,    41,    42,    43,   493,
       0,    45,   539,    47,   495,   496,    50,   497,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   498,   499,    68,     0,    69,    70,    71,   540,
       0,     0,    74,    75,    76,     0,     0,   501,    78,     0,
       0,     0,     0,    80,   502,    82,   503,   504,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   505,    97,    98,
     506,   507,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   508,   120,   121,   509,     0,     0,     0,     0,     0,
       0,     0,   510,   511,   128,     0,     0,     0,   129,   783,
     130,   512,     0,     0,     0,     0,     0,   135,     0,   136,
     137,   138,   139,   513,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   412,   151,   152,   153,
     154,   155,   156,   157,   158,   514,   541,   515,   162,   516,
     517,   165,   166,   167,   168,   169,   170,   518,   172,   519,
     520,   521,   176,   177,   522,   523,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     0,   566,   245,   524,   247,   248,   249,
     250,   251,     7,     8,     0,     0,     0,     0,     0,     0,
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
       0,   245,   524,   247,   248,   249,   250,   251,   569,   570,
       0,     0,     0,     0,     7,     8,     0,     0,     0,     0,
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
     510,   511,   128,     0,     0,     0,   129,     0,   130,   512,
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
       0,     0,     0,   245,   524,   247,   248,   249,   250,   251,
       4,     5,     6,     7,     8,     0,     0,     0,    11,     0,
       0,     0,   409,   410,     0,    14,    15,    16,   832,    18,
      19,    20,    21,   534,   833,   488,    25,   490,   411,    28,
     491,    30,    31,     0,    32,    33,    34,    35,   834,    37,
     537,   538,    40,    41,    42,    43,   493,     0,    45,   835,
      47,   495,   496,    50,   497,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   498,
     499,    68,     0,    69,    70,    71,   836,     0,     0,    74,
      75,    76,     0,     0,   501,    78,     0,     0,     0,    79,
      80,   502,    82,   503,   504,    85,    86,   554,    88,     0,
       0,     0,     0,    90,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   505,    97,    98,   506,   507,     0,
       0,     0,     0,     0,     0,   101,   102,   103,   104,   105,
     106,   107,   555,   109,     0,   110,   111,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   119,   120,
     121,   509,     0,   123,     0,     0,     0,     0,     0,   510,
     511,   128,     0,     0,     0,   129,     0,   130,   512,     0,
       0,     0,     0,     0,   135,     0,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,     0,     0,   147,
     148,   149,     0,   412,   151,   152,   153,   154,   155,   156,
     157,   158,   514,   541,   515,   162,   516,   517,   165,   166,
     167,   168,   169,   170,   518,   172,   519,   520,   521,   176,
     177,   522,   523,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,     0,   193,   194,   195,
       0,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,     0,
     244,     0,   245,   524,   247,   248,   249,   250,   251,     7,
       8,     0,     0,     0,     0,     0,     0,     0,   409,   410,
       0,    14,    15,    16,   485,    18,    19,    20,   486,    22,
     487,   488,  1138,   490,   411,    28,   491,    30,    31,     0,
      32,    33,    34,    35,   492,    37,    38,    39,    40,    41,
      42,    43,   493,     0,    45,   494,    47,   495,   496,    50,
     497,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   498,   499,    68,     0,    69,
      70,    71,   500,     0,     0,    74,    75,    76,     0,     0,
     501,    78,     0,     0,     0,     0,    80,   502,    82,   503,
     504,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     505,    97,    98,   506,   507,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,  1139,     0,     0,
       0,  1140,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   508,   120,   121,   509,     0,     0,
       0,     0,     0,     0,     0,   510,   511,   128,     0,     0,
       0,   129,  1565,   130,   512,     0,     0,     0,  1566,     0,
     135,     0,   136,   137,   138,   139,   513,   141,   142,   143,
     144,   145,   146,     0,     0,  1141,   148,     0,     0,   412,
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
     247,  1142,  1143,  1144,  1145,   409,   410,     0,    14,    15,
      16,   533,    18,    19,    20,   486,   534,   535,   488,   489,
     490,   411,    28,   491,    30,    31,     0,    32,    33,    34,
      35,   536,    37,   537,   538,    40,    41,    42,    43,   493,
       0,    45,   539,    47,   495,   496,    50,   497,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   498,   499,    68,     0,    69,    70,    71,   540,
       0,     0,    74,    75,    76,     0,     0,   501,    78,     0,
       0,     0,     0,    80,   502,    82,   503,   504,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,    91,    92,
      93,    94,     0,    95,     0,     0,     0,   505,    97,    98,
     506,   507,     0,     0,     0,     0,     0,     0,   101,   102,
     103,     0,   105,   106,   107,     0,     0,     0,     0,     0,
       0,   113,   114,     0,     0,     0,     0,   115,   116,   117,
     118,   508,   120,   121,   509,     0,     0,     0,     0,     0,
       0,     0,   510,   511,   128,     0,     0,     0,   129,   752,
     130,   512,     0,     0,     0,   753,     0,   135,     0,   136,
     137,   138,   139,   513,   141,   142,   143,   144,   145,   146,
       0,     0,   147,   148,     0,     0,   412,   151,   152,   153,
     154,   155,   156,   157,   158,   514,   541,   515,   162,   516,
     517,   165,   166,   167,   168,   169,   170,   518,   172,   519,
     520,   521,   176,   177,   522,   523,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,     0,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,     0,     0,     7,     8,   245,   524,   247,   248,   249,
     250,   251,   409,   410,     0,    14,    15,    16,   533,    18,
      19,    20,   486,   534,   535,   488,   489,   490,   411,    28,
     491,    30,    31,     0,    32,    33,    34,    35,   536,    37,
     537,   538,    40,    41,    42,    43,   493,     0,    45,   539,
      47,   495,   496,    50,   497,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   498,
     499,    68,     0,    69,    70,    71,   540,     0,     0,    74,
      75,    76,     0,     0,   501,    78,     0,     0,     0,     0,
      80,   502,    82,   503,   504,    85,    86,     0,     0,     0,
       0,     0,     0,     0,     0,    91,    92,    93,    94,     0,
      95,     0,     0,     0,   505,    97,    98,   506,   507,     0,
       0,     0,     0,     0,     0,   101,   102,   103,     0,   105,
     106,   107,     0,     0,     0,     0,     0,     0,   113,   114,
       0,     0,     0,     0,   115,   116,   117,   118,   508,   120,
     121,   509,     0,     0,     0,     0,     0,     0,     0,   510,
     511,   128,     0,     0,     0,   129,   800,   130,   512,     0,
       0,     0,   801,     0,   135,     0,   136,   137,   138,   139,
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
     410,     0,    14,    15,    16,   485,    18,    19,    20,   486,
      22,   487,   488,  1138,   490,   411,    28,   491,    30,    31,
       0,    32,    33,    34,    35,   492,    37,    38,    39,    40,
      41,    42,    43,   493,     0,    45,   494,    47,   495,   496,
      50,   497,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   498,   499,    68,     0,
      69,    70,    71,   500,     0,     0,    74,    75,    76,     0,
       0,   501,    78,     0,     0,     0,     0,    80,   502,    82,
     503,   504,    85,    86,  1484,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,     0,    95,     0,     0,
       0,   505,    97,    98,   506,   507,     0,     0,     0,     0,
       0,     0,   101,   102,   103,     0,   105,   106,  1139,     0,
       0,     0,  1140,     0,     0,   113,   114,     0,     0,     0,
       0,   115,   116,   117,   118,   508,   120,   121,   509,     0,
       0,     0,     0,     0,     0,     0,   510,   511,   128,     0,
       0,     0,   129,     0,   130,   512,     0,     0,     0,     0,
       0,   135,     0,   136,   137,   138,   139,   513,   141,   142,
     143,   144,   145,   146,     0,     0,  1141,   148,     0,     0,
     412,   151,   152,   153,   154,   155,   156,   157,   158,   514,
     160,   515,   162,   516,   517,   165,   166,   167,   168,   169,
     170,   518,   172,   519,   520,   521,   176,   177,   522,   523,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,     0,   193,   194,   195,     0,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,     0,     7,     8,   245,
     524,   247,  1142,  1143,  1144,  1145,   409,   410,     0,    14,
      15,    16,   485,    18,    19,    20,   486,    22,   487,   488,
    1138,   490,   411,    28,   491,    30,    31,     0,    32,    33,
      34,    35,   492,    37,    38,    39,    40,    41,    42,    43,
     493,     0,    45,   494,    47,   495,   496,    50,   497,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   498,   499,    68,     0,    69,    70,    71,
     500,     0,     0,    74,    75,    76,     0,     0,   501,    78,
       0,     0,     0,     0,    80,   502,    82,   503,   504,    85,
      86,  1622,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,     0,    95,     0,     0,     0,   505,    97,
      98,   506,   507,     0,     0,     0,     0,     0,     0,   101,
     102,   103,     0,   105,   106,  1139,     0,     0,     0,  1140,
       0,     0,   113,   114,     0,     0,     0,     0,   115,   116,
     117,   118,   508,   120,   121,   509,     0,     0,     0,     0,
       0,     0,     0,   510,   511,   128,     0,     0,     0,   129,
       0,   130,   512,     0,     0,     0,     0,     0,   135,     0,
     136,   137,   138,   139,   513,   141,   142,   143,   144,   145,
     146,     0,     0,  1141,   148,     0,     0,   412,   151,   152,
     153,   154,   155,   156,   157,   158,   514,   160,   515,   162,
     516,   517,   165,   166,   167,   168,   169,   170,   518,   172,
     519,   520,   521,   176,   177,   522,   523,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
       0,   193,   194,   195,     0,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,     0,     0,     7,     8,   245,   524,   247,  1142,
    1143,  1144,  1145,   409,   410,     0,    14,    15,    16,   485,
      18,    19,    20,   486,    22,   487,   488,  1138,   490,   411,
      28,   491,    30,    31,     0,    32,    33,    34,    35,   492,
      37,    38,    39,    40,    41,    42,    43,   493,     0,    45,
     494,    47,   495,   496,    50,   497,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
     498,   499,    68,     0,    69,    70,    71,   500,     0,     0,
      74,    75,    76,     0,     0,   501,    78,     0,     0,     0,
       0,    80,   502,    82,   503,   504,    85,    86,  1626,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
       0,    95,     0,     0,     0,   505,    97,    98,   506,   507,
       0,     0,     0,     0,     0,     0,   101,   102,   103,     0,
     105,   106,  1139,     0,     0,     0,  1140,     0,     0,   113,
     114,     0,     0,     0,     0,   115,   116,   117,   118,   508,
     120,   121,   509,     0,     0,     0,     0,     0,     0,     0,
     510,   511,   128,     0,     0,     0,   129,     0,   130,   512,
       0,     0,     0,     0,     0,   135,     0,   136,   137,   138,
     139,   513,   141,   142,   143,   144,   145,   146,     0,     0,
    1141,   148,     0,     0,   412,   151,   152,   153,   154,   155,
     156,   157,   158,   514,   160,   515,   162,   516,   517,   165,
     166,   167,   168,   169,   170,   518,   172,   519,   520,   521,
     176,   177,   522,   523,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,     0,   193,   194,
     195,     0,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,     0,
       0,     7,     8,   245,   524,   247,  1142,  1143,  1144,  1145,
     409,   410,     0,    14,    15,    16,   485,    18,    19,    20,
     486,    22,   487,   488,  1138,   490,   411,    28,   491,    30,
      31,     0,    32,    33,    34,    35,   492,    37,    38,    39,
      40,    41,    42,    43,   493,     0,    45,   494,    47,   495,
     496,    50,   497,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,   498,   499,    68,
       0,    69,    70,    71,   500,     0,     0,    74,    75,    76,
       0,     0,   501,    78,     0,     0,     0,     0,    80,   502,
      82,   503,   504,    85,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    92,    93,    94,     0,    95,     0,
       0,     0,   505,    97,    98,   506,   507,     0,     0,     0,
       0,     0,     0,   101,   102,   103,     0,   105,   106,  1139,
       0,     0,     0,  1140,     0,     0,   113,   114,     0,     0,
       0,     0,   115,   116,   117,   118,   508,   120,   121,   509,
       0,     0,     0,     0,     0,     0,     0,   510,   511,   128,
       0,     0,     0,   129,     0,   130,   512,     0,     0,     0,
       0,     0,   135,     0,   136,   137,   138,   139,   513,   141,
     142,   143,   144,   145,   146,     0,     0,  1141,   148,     0,
       0,   412,   151,   152,   153,   154,   155,   156,   157,   158,
     514,   160,   515,   162,   516,   517,   165,   166,   167,   168,
     169,   170,   518,   172,   519,   520,   521,   176,   177,   522,
     523,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,     0,   193,   194,   195,     0,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,     0,     0,     7,     8,
     245,   524,   247,  1142,  1143,  1144,  1145,   409,   410,     0,
      14,    15,    16,   485,    18,    19,    20,   486,    22,   487,
     488,  1138,   490,   411,    28,   491,    30,    31,     0,    32,
      33,    34,    35,   492,    37,    38,    39,    40,    41,    42,
      43,   493,     0,    45,   494,    47,   495,   496,    50,   497,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,   498,   499,    68,     0,    69,    70,
      71,   500,     0,     0,    74,    75,    76,     0,     0,   501,
      78,     0,     0,     0,     0,    80,   502,    82,   503,   504,
      85,    86,     0,     0,     0,     0,     0,     0,     0,     0,
      91,    92,    93,    94,     0,    95,     0,     0,     0,   505,
      97,    98,   506,   507,     0,     0,     0,     0,     0,     0,
     101,   102,   103,     0,   105,   106,  1139,     0,     0,     0,
    1140,     0,     0,   113,   114,     0,     0,     0,     0,   115,
     116,   117,   118,   508,   120,   121,   509,     0,     0,     0,
       0,     0,     0,     0,   510,   511,   128,     0,     0,     0,
     129,     0,   130,   512,     0,     0,     0,     0,     0,   135,
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
     240,   241,   242,     0,     0,     7,     8,   245,   524,   247,
    1142,  1143,  1144,  1145,   409,   410,     0,    14,    15,    16,
     533,    18,    19,    20,   486,   534,   535,   488,   489,   490,
     411,    28,   491,    30,    31,     0,    32,    33,    34,    35,
     536,    37,   537,   538,    40,    41,    42,    43,   493,     0,
      45,   539,    47,   495,   496,    50,   497,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   498,   499,    68,     0,    69,    70,    71,   540,     0,
       0,    74,    75,    76,     0,     0,   501,    78,     0,     0,
       0,     0,    80,   502,    82,   503,   504,    85,    86,  1231,
       0,     0,     0,     0,     0,     0,     0,    91,    92,    93,
      94,     0,    95,     0,     0,     0,   505,    97,    98,   506,
     507,     0,     0,     0,     0,     0,     0,   101,   102,   103,
       0,   105,   106,   107,     0,     0,     0,     0,     0,     0,
     113,   114,     0,     0,     0,     0,   115,   116,   117,   118,
     508,   120,   121,   509,     0,     0,     0,     0,     0,     0,
       0,   510,   511,   128,     0,     0,     0,   129,     0,   130,
     512,     0,     0,     0,     0,     0,   135,     0,   136,   137,
     138,   139,   513,   141,   142,   143,   144,   145,   146,     0,
       0,   147,   148,     0,     0,   412,   151,   152,   153,   154,
     155,   156,   157,   158,   514,   541,   515,   162,   516,   517,
     165,   166,   167,   168,   169,   170,   518,   172,   519,   520,
     521,   176,   177,   522,   523,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,     0,   193,
     194,   195,     0,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
       0,     0,     7,     8,   245,   524,   247,   248,   249,   250,
     251,   409,   410,     0,    14,    15,    16,   533,    18,    19,
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
     236,   237,   238,   239,   240,   241,   242,     0,     0,     7,
       8,   245,   524,   247,   248,   249,   250,   251,   409,   410,
       0,    14,    15,    16,     0,    18,    19,    20,   486,     0,
       0,   488,   489,     0,   411,    28,   491,    30,    31,     0,
      32,    33,    34,    35,     0,    37,     0,     0,    40,    41,
      42,    43,   493,     0,    45,     0,    47,     0,     0,    50,
     497,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,   498,   499,    68,     0,    69,
      70,    71,     0,     0,     0,    74,    75,    76,     0,     0,
     501,    78,     0,     0,     0,     0,    80,   502,    82,   503,
     504,    85,    86,     0,     0,     0,     0,     0,     0,     0,
       0,    91,    92,    93,    94,     0,    95,     0,     0,     0,
     505,    97,    98,   506,   507,     0,     0,     0,     0,     0,
       0,   101,   102,   103,     0,   105,   106,     0,     0,     0,
       0,     0,     0,     0,   113,   114,     0,     0,     0,     0,
     115,   116,   117,   118,   508,   120,   121,   509,     0,     0,
       0,     0,     0,     0,     0,   510,   511,   128,     0,     0,
       0,   129,     0,   130,   512,     0,     0,     0,     0,     0,
     135,     0,   136,   137,   138,   139,   513,   141,   142,   143,
     144,   145,   146,     0,     0,     0,   148,     0,     0,   412,
     151,   152,   153,   154,   155,   156,   157,   158,   514,     0,
     515,   162,   516,   517,   165,   166,   167,   168,   169,   170,
     518,   172,   519,   520,   521,   176,   177,     0,   523,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,     0,   193,   194,   195,     0,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,     0,     0,     0,     0,   245,   524,
     247,   248,   249,   250,   251
  };

  /* YYCHECK.  */
  const short int
  xquery_parser::yycheck_[] =
  {
         0,   420,    12,   179,     4,     5,     6,   339,     0,     4,
       5,     6,     4,     5,     6,   259,   820,   917,     4,     5,
       6,   777,   668,   757,   311,   260,   133,   109,   110,   903,
    1046,   418,   419,   789,   669,   670,   671,   672,   858,  1284,
     275,   460,   461,   617,   618,   582,  1070,   803,  1030,  1217,
    1301,   588,  1362,  1363,   757,   291,   252,   253,     1,     1,
      73,   432,   937,  1124,   916,   917,   615,   616,   617,   618,
      26,    27,   443,    39,   615,   616,   987,    36,    44,    45,
     713,     4,     5,     6,    36,    26,    27,   647,  1005,   649,
     650,    47,   652,    59,   654,    61,    62,   468,    55,    29,
       1,   953,   662,   663,    70,   953,    47,  1007,   108,     1,
    1395,    29,     8,     1,     1,    56,   108,    96,    74,   142,
    1020,    45,   108,    47,  1587,    29,     1,     1,     1,   118,
     118,    97,    93,    74,   107,   987,   224,    96,    79,  1314,
       1,   224,    94,   226,    96,    26,    27,   100,    30,   224,
      52,   226,   224,   100,   100,  1007,   112,   229,   130,    94,
    1652,   243,   244,   107,   107,   107,   282,   262,  1020,   118,
     111,   112,   113,   154,   158,   156,   169,    96,   273,   415,
     110,     1,   106,   148,   216,   108,    53,   158,   147,     1,
     106,    58,   176,   148,   124,   147,   107,   160,     1,    96,
     165,    45,    54,   959,    56,   176,   110,    96,   201,   291,
     165,   127,   147,     1,   198,   188,   156,  1527,    62,   149,
     124,   253,   183,   153,   196,   313,   156,   129,   147,    96,
     313,   112,  1724,   186,     1,   342,   224,   186,   313,   186,
     186,   313,   160,   187,   168,   149,   107,   177,   100,   272,
    1124,  1125,   252,   253,  1499,   236,   256,  1013,   224,   216,
     252,   253,  1066,  1019,   256,  1281,    37,    38,  1436,    40,
      41,  1734,   169,   560,     1,     1,   255,   256,  1012,   175,
     169,  1305,     1,   272,     1,  1267,    57,   107,  1140,   190,
    1314,   291,  1140,   867,   868,   107,   253,   147,   190,   291,
    1175,  1586,   190,   190,   107,   724,   939,  1010,    73,  1012,
    1371,  1222,   548,   272,  1231,   190,   190,   190,   306,   107,
     272,   232,    87,   439,   865,   866,   187,  1502,   258,  1032,
     286,   213,     1,   415,   347,     9,    10,   350,   294,   899,
     107,     1,   113,   187,     1,   286,   111,     1,     0,     1,
     316,   317,   318,   294,   251,   252,   775,   254,   123,  1259,
     125,   302,   251,   252,   261,   254,   448,   187,   310,   312,
    1222,   615,   616,   185,   271,  1685,   458,   612,   613,    29,
     107,   107,   271,  1283,   187,   467,   283,     1,   107,   160,
     107,   121,   474,   475,   283,     1,  1647,   185,   250,   635,
     771,   483,   107,   774,     0,     1,   147,  1259,   604,   107,
     107,   263,   118,   265,   107,   415,   107,   153,     1,   153,
     187,  1589,   272,   415,   276,   277,   278,  1737,   280,   103,
     282,  1283,   107,    94,   136,    94,   267,   118,   107,   107,
      33,   177,   130,   274,   444,   106,   446,   107,   219,   123,
     107,   125,   444,   107,   446,   107,    49,   184,   444,     1,
     446,   187,     1,   113,   107,  1221,   548,     1,   187,     1,
     187,     1,   472,     1,    96,   209,  1721,   477,  1502,   153,
     472,   187,   564,   157,   107,   477,   472,   184,   147,   260,
      94,   477,   190,   107,   576,   188,   187,  1371,   200,  1233,
     174,   107,   232,  1403,   107,   186,  1380,   743,   196,    96,
     160,   107,   187,    76,   596,   597,   903,  1391,   187,   187,
     194,   444,  1690,   446,   107,  1345,   113,   187,  1348,   234,
     187,   272,   184,   187,   156,  1109,  1110,  1111,   212,  1242,
     131,   960,   961,    96,   187,   932,   965,   262,   548,   472,
      94,  1403,  1089,   153,   477,   555,   548,   156,   273,   144,
    1109,  1110,  1111,   555,   187,   107,   107,  1735,   107,   555,
     184,   107,    45,   107,    47,   107,   995,   107,   184,   107,
     687,   688,   347,    94,   187,   350,  1486,   153,   184,  1489,
     153,   176,     5,    94,   147,   107,     9,   597,    29,   190,
     610,   184,   684,   107,   604,   597,    79,   689,   193,   209,
    1366,   597,   604,   217,   218,   615,   616,   617,   618,   156,
     856,   865,   118,   615,   616,   617,   618,  1609,   232,   156,
    1646,   142,   555,   106,  1486,   635,   871,  1489,  1806,   874,
    1808,   142,   184,   635,   122,   184,   187,    94,    53,  1817,
     184,   187,   184,    58,   184,   136,   184,   220,   221,   158,
     425,   743,     5,   428,    96,   156,     9,   432,    94,   150,
     435,   436,    77,   217,   218,   187,    73,   176,   443,   110,
     106,   113,  1556,   187,   449,   450,   191,   192,   232,   454,
      87,    96,     1,   124,     3,   168,  1500,   462,    96,    94,
    1001,  1505,  1003,   468,   469,   470,   471,   154,   182,   156,
     123,   476,   125,   118,   111,   113,   142,  1451,   149,   484,
     133,   195,   153,   158,   156,   156,   123,   950,   125,   811,
     812,   813,   117,   815,    95,   156,  1382,  1124,  1125,   962,
     153,   176,   137,   743,    42,   106,   177,   142,    46,    24,
     156,   743,  1053,    51,  1055,   116,    42,    66,   156,    34,
      46,   146,    71,   198,   529,    51,   127,   767,  1668,   268,
    1670,    69,   767,   122,   159,   767,   275,  1351,   543,   166,
     123,   767,   125,    69,    33,    60,   285,   128,   129,   554,
     133,   153,     9,    10,  1126,   182,   690,   797,   798,   693,
      49,  1701,   696,     9,   153,   797,   798,   156,   193,   118,
     153,   797,   798,  1100,   156,   177,  1668,   582,  1670,   246,
     247,     9,    28,   588,    26,    27,   156,   592,  1632,   137,
     268,  1731,  1636,   122,   142,    37,    38,   275,    40,    41,
      28,   122,   269,  1262,   767,    47,  1746,   285,  1748,  1701,
    1712,  1713,   137,    42,    56,    57,   856,    46,  1094,   619,
     137,   118,    51,   623,   856,   182,   876,   154,   153,   156,
     168,  1106,    74,   171,   797,   798,   153,    79,   195,  1731,
      69,   122,   168,   298,   200,   171,   103,   231,   186,   233,
     100,  1753,   307,   209,  1746,   153,  1748,  1759,   156,   137,
     186,  1547,  1548,   113,   142,  1540,   123,   122,   125,   111,
     112,   113,  1716,   211,   220,   221,   222,   123,   100,   125,
       9,    10,  1098,   153,   118,   211,   156,  1103,   134,  1685,
     100,   113,   100,   128,   129,   123,   153,   125,   100,  1358,
     157,   100,   122,   113,    53,   113,   134,   153,   122,    58,
     347,   113,   153,   350,   113,   720,   153,   174,   160,   156,
     153,   276,   277,   278,   231,   153,   233,   282,   153,   734,
     122,   156,   346,   738,   739,   349,   122,   194,   122,   168,
     666,   667,   171,   122,  1371,   156,   673,   674,  1215,  1216,
     675,   676,   215,  1380,   118,   212,   761,   186,   763,  1577,
    1578,   918,   919,   240,  1391,   240,   771,   241,   156,   774,
    1656,  1657,   153,   778,   103,     0,   313,   219,   190,     9,
      10,    92,   211,   248,   167,  1261,    99,   424,   425,    50,
     199,   428,   101,   154,   123,   432,   125,   102,   435,   436,
     145,  1123,   156,    29,   184,    47,   443,   184,  1048,  1468,
     184,   152,   449,   450,   819,   118,  1048,   454,   260,   245,
     303,   187,  1048,   283,   153,   462,   118,   283,   157,   153,
       1,   468,   469,   470,   471,   118,   142,   107,   153,   476,
     187,  1727,   156,   153,   286,   174,   142,   484,   156,   156,
     184,   153,   294,   858,  1094,   156,   156,   121,  1108,   156,
     302,   156,  1094,   156,    17,   194,    35,   213,  1344,  1109,
    1110,  1111,  1531,   103,    29,   187,   229,  1109,  1110,  1111,
     230,   886,   244,   212,     3,  1048,   190,   118,   168,   170,
      70,   190,   529,   123,   170,   125,   132,   230,    94,    94,
      94,   149,   107,   107,   140,   141,   543,   143,    29,   160,
     160,   916,   917,   918,   919,   151,   127,   554,   132,   155,
     245,   157,    94,   153,   142,   298,   162,   157,   118,  1556,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
     132,   184,   187,   179,   174,   184,   187,   107,   953,    94,
      96,    45,    96,   187,   187,   592,   153,   184,   187,   187,
     184,    94,   967,   236,   194,   153,   202,   203,   204,   205,
     206,   207,   153,   230,   153,   153,   153,   224,   142,   232,
     190,    33,   212,     1,   170,  1225,   118,   992,   142,   132,
    1225,    94,    29,  1225,   285,    94,  1001,   153,  1003,  1225,
    1005,   127,  1007,   226,  1480,   118,   147,   253,   298,   118,
      94,   184,   197,   160,   132,  1020,   132,    96,  1340,  1341,
    1342,  1261,   153,   118,   147,   100,   100,   184,   153,  1261,
     142,   190,  1272,   184,   121,    35,    29,  1272,   118,   156,
    1272,   156,   156,   153,   244,    79,  1272,   107,  1053,   107,
    1055,  1291,   284,   259,   257,   156,  1291,   266,   156,  1291,
     156,   144,  1225,   156,   156,  1291,   156,   156,    29,   285,
      29,  1311,    29,   286,   226,   144,   187,   147,   127,  1311,
     717,   187,   190,   720,  1089,  1311,   305,   187,   147,   118,
     187,   147,   118,    77,   107,   142,   184,   734,   100,   132,
       7,   738,   739,  1343,  1344,   187,   187,    96,   232,  1272,
     232,  1343,  1344,   190,  1119,   186,   236,  1343,   106,   197,
     187,   249,   249,   147,   761,   232,   763,   232,  1291,    78,
     187,  1607,   281,   187,   771,  1140,   187,   774,    29,   187,
      29,   778,  1618,  1619,   187,  1621,   285,   187,  1311,   187,
     170,   107,  1628,   184,   256,   147,   147,   126,   126,    96,
     142,   184,    94,   153,   186,   186,   270,   186,   184,   186,
     184,    29,   184,   315,    96,   170,   187,   187,    53,    94,
     147,   186,   819,   186,    94,   106,    29,   196,   279,   197,
     107,   264,   118,   107,   224,   118,    94,    94,   196,   186,
     286,   186,   196,   186,   183,   118,    93,   118,   186,   224,
     196,   186,   118,   186,   118,   256,  1178,   198,   224,   304,
     292,   858,   723,   286,   256,   954,  1231,   439,   304,  1021,
    1235,   259,   419,  1709,  1222,  1690,   304,  1735,   859,   305,
    1480,   305,   108,   305,  1720,  1250,   454,  1018,  1480,   886,
     780,  1461,  1251,  1362,  1259,  1367,  1115,  1365,   543,  1273,
    1278,  1281,  1286,   645,   665,  1305,   698,   820,  1273,  1759,
     646,  1747,  1753,   447,   335,   919,  1003,   447,  1283,   916,
     917,   918,   919,  1336,  1177,  1346,  1345,  1380,  1391,  1556,
    1125,  1553,  1134,  1384,   986,  1200,  1426,  1580,  1381,   586,
      -1,    -1,    -1,  1779,    -1,    -1,    -1,  1312,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   953,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1800,    -1,  1648,    -1,    -1,  1805,
     967,  1336,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1345,    -1,    -1,  1348,  1666,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   992,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1001,    -1,  1003,  1607,  1005,    -1,
    1007,    -1,    -1,    -1,    -1,  1607,    -1,    -1,  1618,  1619,
      -1,  1621,    -1,  1020,    -1,    -1,  1618,  1619,  1628,  1621,
      -1,    -1,    -1,    -1,    -1,    -1,  1628,    -1,  1403,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1053,    -1,  1055,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1432,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1458,  1459,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1709,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1709,    -1,  1484,
    1720,  1486,  1119,    -1,  1489,    -1,    -1,    -1,  1720,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1501,    -1,    -1,    -1,
      -1,  1506,    -1,  1140,    -1,    -1,    -1,  1747,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1747,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1779,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1779,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1800,    -1,    -1,    -1,    -1,  1805,    -1,    -1,  1800,    -1,
      -1,    -1,    -1,  1805,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1231,    -1,    -1,    -1,  1235,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1250,    -1,    -1,    -1,  1622,    -1,  1624,
      -1,  1626,  1259,    -1,    -1,    -1,    -1,    -1,  1633,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1273,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1283,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1668,    -1,  1670,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1312,    -1,    -1,    -1,    -1,
      -1,  1686,    -1,    -1,  1689,    -1,    -1,    -1,    -1,   555,
      -1,    -1,    -1,    -1,    -1,    -1,  1701,    -1,    -1,  1336,
      -1,    -1,    -1,    -1,    -1,    -1,  1711,    -1,  1345,    -1,
      -1,  1348,    -1,    -1,   580,   581,    -1,    -1,   584,   585,
     586,   587,    -1,   589,    -1,    -1,  1731,    -1,    -1,   595,
      -1,    -1,    -1,    -1,  1739,    -1,    -1,   603,    -1,  1744,
      -1,  1746,    -1,  1748,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   625,
     626,   627,    -1,    -1,    -1,    -1,  1403,    -1,    -1,   635,
     636,  1776,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1792,    -1,    -1,
      -1,  1796,    -1,    -1,    -1,  1432,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1812,    -1,    -1,
    1815,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1458,  1459,    -1,    -1,    -1,    -1,    -1,    -1,   695,
      -1,    -1,   698,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1484,    -1,  1486,
      -1,    -1,  1489,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1501,    -1,    -1,    -1,    -1,  1506,
     736,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   779,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   804,    -1,
      -1,    -1,   808,   809,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   817,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1622,    -1,  1624,    -1,  1626,
      -1,    -1,    -1,    -1,    -1,    -1,  1633,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   888,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1668,    -1,  1670,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1686,
      -1,    -1,  1689,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1701,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1711,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   955,
      -1,    -1,    -1,    -1,  1731,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1739,    -1,    -1,    -1,    -1,  1744,    -1,  1746,
      -1,  1748,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   990,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1776,
      -1,    -1,    -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1792,    -1,    -1,    -1,  1796,
      -1,    -1,    -1,    -1,    -1,  1031,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1812,  1042,  1043,  1815,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1057,    -1,    -1,  1060,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1076,  1077,  1078,    -1,  1080,  1081,  1082,  1083,  1084,  1085,
    1086,  1087,  1088,    -1,    -1,  1091,  1092,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1105,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1115,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1165,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     0,     1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1237,    -1,  1239,    -1,  1241,    -1,    -1,  1244,    -1,
      -1,    -1,    -1,  1249,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    -1,    -1,  1261,    50,    51,    -1,    -1,
      -1,    55,    -1,    -1,  1270,    -1,    -1,    -1,    -1,    -1,
    1276,  1277,    66,    -1,    -1,    69,    -1,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1295,
      -1,    -1,  1298,    -1,    -1,    -1,    -1,    -1,    92,    -1,
      94,    95,    96,    -1,    -1,    99,   100,   101,   102,    -1,
      -1,    -1,   106,   107,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,   116,   117,   118,    -1,    -1,   121,    -1,    -1,
      -1,    -1,   126,   127,    -1,    -1,    -1,    -1,   132,    -1,
      -1,    -1,   136,    -1,    -1,    -1,   140,   141,    -1,   143,
      -1,   145,   146,    -1,    -1,    -1,   150,   151,    -1,  1365,
     154,   155,   156,   157,   158,   159,    -1,    -1,   162,    -1,
      -1,    -1,    -1,   167,   168,    -1,    -1,   171,    -1,    -1,
      -1,    -1,   176,    -1,    -1,   179,    -1,    -1,    -1,    -1,
     184,   185,   186,   187,   188,    -1,   190,   191,   192,   193,
      -1,    -1,    -1,    -1,   198,   199,   200,    -1,   202,   203,
     204,   205,   206,   207,    -1,   209,    -1,   211,    -1,    -1,
      -1,    -1,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,  1445,
     234,    -1,   236,  1449,    -1,    -1,    -1,  1453,    -1,  1455,
      -1,  1457,    -1,    -1,   248,    -1,    -1,  1463,    -1,   253,
      -1,    -1,    -1,    -1,    -1,  1471,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1479,  1480,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1498,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1509,  1510,  1511,  1512,    -1,  1514,  1515,
      -1,  1517,    -1,    -1,    -1,    -1,   310,    -1,   312,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1532,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1595,
      -1,  1597,    -1,    -1,  1600,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1608,    -1,    -1,    -1,    -1,  1613,  1614,    -1,
      -1,    -1,    -1,    -1,    -1,  1621,    -1,    -1,    -1,  1625,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1641,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1653,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1693,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1705,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1747,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1774,    -1,
      -1,    -1,    -1,  1779,    -1,    -1,    -1,    -1,  1784,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    11,
      12,    -1,    -1,  1799,    -1,    -1,    -1,  1803,    20,    21,
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
     313,   314,   315,   316,   317,   318,   319,   320,   321,    11,
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
      -1,   313,   314,   315,   316,   317,   318,   319,    -1,   321,
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
     181,   182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,
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
     182,    -1,   184,    -1,   186,    -1,   188,   189,    -1,   191,
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
     181,   182,    -1,    -1,   185,   186,    -1,   188,   189,    -1,
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
     182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,   191,
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
     303,   304,   305,   306,   307,   308,   309,   310,   311,    -1,
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
     304,   305,   306,   307,   308,   309,    -1,   311,   312,   313,
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
     186,   187,   188,   189,    -1,   191,   192,   193,    -1,   195,
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
     177,    -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,
     187,   188,   189,    -1,   191,   192,   193,    -1,   195,    -1,
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
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,
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
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,   169,   170,   171,
     172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,
     182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,
      -1,   193,    -1,   195,    -1,   197,   198,   199,   200,   201,
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
      -1,    -1,   135,    -1,   137,   138,   139,    -1,    -1,    -1,
      -1,    -1,    -1,   146,   147,   148,   149,    -1,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,   174,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
     193,    -1,   195,    -1,   197,    -1,   199,    -1,   201,   202,
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
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
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
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,
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
     304,   305,   306,   307,   308,    -1,    -1,    11,    12,   313,
     314,   315,   316,   317,   318,   319,    20,    -1,    -1,    -1,
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
      -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,   193,
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
     304,   305,   306,   307,   308,    -1,    -1,    -1,    16,   313,
     314,   315,   316,   317,   318,   319,    24,    25,    -1,    -1,
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
     308,    -1,    -1,    -1,    16,   313,   314,   315,   316,   317,
     318,   319,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   313,   314,   315,   316,   317,   318,   319,    18,    19,
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
      -1,    -1,    -1,   313,   314,   315,   316,   317,   318,   319,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    29,    -1,
      -1,    -1,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    -1,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    -1,    94,    95,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,   105,   106,    -1,    -1,    -1,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,   124,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,   174,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,    -1,
      -1,    -1,    -1,    -1,   195,    -1,   197,   198,   199,   200,
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
     311,    -1,   313,   314,   315,   316,   317,   318,   319,    24,
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
      -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,   187,   188,   189,    -1,    -1,    -1,   193,    -1,
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
     148,    -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,   169,   170,   171,   172,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   180,   181,   182,    -1,    -1,    -1,   186,   187,
     188,   189,    -1,    -1,    -1,   193,    -1,   195,    -1,   197,
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
     111,   112,   113,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,    -1,
     131,    -1,    -1,    -1,   135,   136,   137,   138,   139,    -1,
      -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,   150,
     151,   152,    -1,    -1,    -1,    -1,    -1,    -1,   159,   160,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,   170,
     171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,
     181,   182,    -1,    -1,    -1,   186,   187,   188,   189,    -1,
      -1,    -1,   193,    -1,   195,    -1,   197,   198,   199,   200,
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
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,
      -1,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,   150,   151,   152,    -1,
      -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,    -1,
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
      -1,   188,   189,    -1,    -1,    -1,    -1,    -1,   195,    -1,
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
      -1,   111,   112,   113,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   126,   127,   128,   129,
      -1,   131,    -1,    -1,    -1,   135,   136,   137,   138,   139,
      -1,    -1,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
     150,   151,   152,    -1,    -1,    -1,   156,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,   165,   166,   167,   168,   169,
     170,   171,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     180,   181,   182,    -1,    -1,    -1,   186,    -1,   188,   189,
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
      -1,    -1,    -1,   156,    -1,    -1,   159,   160,    -1,    -1,
      -1,    -1,   165,   166,   167,   168,   169,   170,   171,   172,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   180,   181,   182,
      -1,    -1,    -1,   186,    -1,   188,   189,    -1,    -1,    -1,
      -1,    -1,   195,    -1,   197,   198,   199,   200,   201,   202,
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
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   150,   151,   152,    -1,    -1,    -1,    -1,    -1,    -1,
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
     302,   303,   304,   305,   306,   307,   308,    -1,    -1,    24,
      25,   313,   314,   315,   316,   317,   318,   319,    33,    34,
      -1,    36,    37,    38,    -1,    40,    41,    42,    43,    -1,
      -1,    46,    47,    -1,    49,    50,    51,    52,    53,    -1,
      55,    56,    57,    58,    -1,    60,    -1,    -1,    63,    64,
      65,    66,    67,    -1,    69,    -1,    71,    -1,    -1,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    -1,    94,
      95,    96,    -1,    -1,    -1,   100,   101,   102,    -1,    -1,
     105,   106,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   126,   127,   128,   129,    -1,   131,    -1,    -1,    -1,
     135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   148,    -1,   150,   151,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,   160,    -1,    -1,    -1,    -1,
     165,   166,   167,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   180,   181,   182,    -1,    -1,
      -1,   186,    -1,   188,   189,    -1,    -1,    -1,    -1,    -1,
     195,    -1,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,    -1,    -1,    -1,   211,    -1,    -1,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,    -1,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,    -1,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,    -1,   258,   259,   260,    -1,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,    -1,    -1,    -1,    -1,   313,   314,
     315,   316,   317,   318,   319
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
     372,   392,   410,   107,   190,     1,   107,   334,   190,    42,
      46,    51,    69,   168,   171,   186,   211,   405,   414,   419,
     420,   421,   435,   436,   440,   167,    92,   132,   140,   141,
     143,   151,   155,   157,   162,   179,   202,   203,   204,   205,
     206,   207,   483,   484,   248,    99,   158,   176,   198,   117,
     146,   159,   193,   200,   209,   136,   150,    50,   199,   101,
     102,   158,   176,   482,   153,   488,   491,   191,   192,   154,
     503,   504,   499,   503,   499,   156,   503,   145,   156,   184,
     184,   184,   373,   506,   373,    29,   648,   182,   195,   182,
     195,   166,   182,   651,   650,   169,   201,    47,   650,   152,
     118,    45,    47,    79,   106,   168,   649,   220,   221,   222,
     245,   607,   650,   650,   303,   137,   142,   112,   286,   294,
     375,   649,   390,   391,   187,   390,    45,    62,   187,   556,
     557,   410,   187,   193,   650,   424,   425,   650,   283,   283,
     424,   118,   431,   118,   187,   379,   380,   153,   395,   410,
       1,   160,   648,   113,   160,   353,   648,   650,   118,   142,
     107,   410,    29,   187,   649,   650,   650,   448,   449,   650,
     390,   187,   410,   410,   558,   650,   390,   153,   153,   410,
     187,   193,   650,   650,   142,   448,   184,   184,   121,   107,
     184,   156,   156,   156,   650,   153,   185,   186,   187,    35,
     519,   520,   521,   410,     8,   175,    17,   410,   213,    29,
     411,   411,    39,    45,    59,    70,    97,   502,   650,   187,
     411,   411,   411,   638,   411,   502,   411,   230,   229,   574,
     575,   650,   190,   190,   411,   410,   391,   410,   244,   408,
     409,   310,   312,   411,   335,   190,   334,   190,   334,     3,
     341,   357,   387,   341,   357,   387,    33,   358,   387,   358,
     387,   398,   398,   411,   411,   411,   118,   168,   170,   170,
     392,   411,   411,   465,   466,   468,   468,   468,   468,   467,
     468,   468,   468,    70,   469,   473,   473,   472,   474,   474,
     474,   474,   475,   475,   476,   476,   230,    94,    94,    94,
     184,   410,   491,   491,   410,   504,   187,   411,   514,   149,
     187,   514,   107,   187,   187,   107,   107,   378,    29,   651,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
     360,   361,   362,    94,   137,   142,   366,   367,   368,   650,
     160,   160,   360,   648,   127,   132,    54,    56,   100,   250,
     263,   265,   276,   277,   278,   280,   282,   608,   609,   610,
     611,   612,   613,   620,   626,   627,   245,    94,   298,   650,
     142,   411,   118,   650,   650,   132,   184,   184,   187,   187,
     184,   107,   187,   107,   187,   107,    36,    94,    96,   147,
     426,   427,   542,   650,    55,   216,   253,   416,   417,   650,
      94,   107,   187,   389,   187,   649,    96,    45,   649,   648,
      96,   142,   542,   650,   411,   430,   184,   187,   187,   187,
     187,   107,   188,   147,   542,   184,   187,   187,   153,   184,
     390,   390,   184,   107,   187,   107,   187,   142,   542,   411,
     188,   411,   411,   410,   410,   410,   650,   520,   521,   130,
     196,   184,   184,   131,   190,    94,   217,   218,   232,    94,
     217,   218,   232,   232,   232,    94,    94,   236,   224,   230,
     107,   234,   142,   190,   187,    48,    72,    73,   243,   412,
     422,   184,   500,   580,   409,   232,   357,    33,    33,   190,
     334,   190,   113,     1,   650,   170,   411,   441,   442,   118,
     437,   438,   468,   153,   156,   258,   487,   506,   581,   584,
     585,   586,   587,   588,   592,   594,   596,   597,    47,   152,
     156,   210,   316,   317,   318,   319,   543,   545,   547,   548,
     564,   565,   566,   567,   644,   645,   646,   647,   650,   543,
     541,   547,   541,   184,   185,   107,   187,   187,   506,   148,
     165,   148,   165,   137,   395,   378,   361,   132,   545,   368,
     411,   542,   648,   648,   128,   129,   648,   276,   277,   278,
     282,   650,   262,   273,   262,   273,    29,   285,    96,   113,
     156,   614,   617,   608,    39,    44,    59,    61,    70,    97,
     224,   316,   317,   318,   382,   548,   644,   226,   298,   307,
     411,   650,    94,   298,   648,   153,   558,   559,   650,   558,
     559,   118,   425,   127,   543,   118,   411,   147,   427,   147,
      36,   147,   426,   427,   147,   542,   253,    53,    58,    77,
     118,   426,   432,   433,   434,   417,   542,   543,   380,    94,
     184,   197,   132,   352,   648,   160,   132,    96,   352,   411,
     142,   427,   153,   118,   411,   411,   147,   100,   451,   452,
     453,   455,   456,   100,   459,   460,   461,   462,   390,   184,
     184,   153,   558,   558,   411,   142,   190,   411,   121,   187,
     187,   187,    35,   521,   130,   196,     9,    10,   103,   123,
     125,   153,   194,   516,   518,   529,   530,   533,    29,   231,
     233,   411,   411,   411,   231,   233,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   502,   118,   411,   411,   392,
     156,   156,   156,   153,   186,   244,   577,   578,   209,   393,
     411,   190,   113,   387,   387,   387,   441,    95,   106,   116,
     127,   443,   444,   445,   446,   107,   650,   107,   410,   581,
     588,   153,   284,   470,   633,    96,   169,   251,   252,   254,
     261,   271,   283,   582,   583,   602,   603,   604,   605,   628,
     631,   257,   259,   589,   607,   266,   593,   629,   246,   247,
     269,   598,   599,   156,   156,   545,   156,   156,   156,   156,
     156,   144,   176,   193,   544,   144,   411,   137,   395,   560,
     367,   285,    29,    96,   113,   156,   621,    29,   614,   544,
     544,   489,   286,   305,   542,   382,   226,   190,   389,   187,
     187,   144,   187,   187,   425,   147,   426,   650,   411,   147,
     411,   127,   411,   147,   427,   147,   411,   147,   118,   118,
     411,   650,   434,    77,   543,   392,   411,   648,   107,   352,
     411,   142,   389,   449,   411,   411,   113,   452,   453,   100,
     186,   113,   453,   456,   118,   543,   100,   113,   460,   100,
     113,   462,   184,   389,   187,   187,   411,   411,   197,   459,
     132,   194,   518,     7,   390,   650,   194,   529,   190,   232,
     232,   232,   232,    96,   236,   236,   575,   186,   410,   410,
     410,   580,   578,   500,   648,   128,   129,   445,   446,   446,
     442,   106,   142,   439,   542,   438,   184,   187,   581,   595,
     249,   216,   253,   267,   274,   632,    96,   255,   256,   630,
     249,   585,   632,   472,   602,   586,   147,   281,   590,   591,
     630,   285,   601,    78,   600,   187,   193,   543,   546,   187,
     187,   187,   187,   187,   187,   187,    29,   136,   200,   623,
     624,   625,    29,   622,   623,   270,   618,   107,   615,   170,
     650,   256,   489,   184,   411,   147,   411,   147,   426,   411,
     147,   411,   411,   650,   650,   433,   411,   126,   126,    96,
     648,   411,   184,   186,   186,   411,   392,   411,   186,   186,
     650,   186,   118,   543,   118,   186,   118,   543,   186,   184,
     113,   521,   650,   194,   184,   521,   650,   411,   411,   411,
     411,   315,   411,   411,   411,   187,   187,   187,   153,   579,
     446,   648,   411,   142,   184,   474,    52,   129,   472,   472,
     268,   275,   285,   606,   606,   587,   153,   279,    94,   187,
     107,   187,   621,   621,   625,   107,   187,    29,   619,   630,
     616,   617,   187,   384,   385,   489,   118,   224,   306,   286,
     170,   411,   411,   147,   411,    53,   392,   411,   352,   411,
     392,    94,   392,   411,   650,   186,   650,   411,   650,   186,
     392,   118,    93,   183,   522,   521,   650,   196,   521,   411,
     197,   459,   410,   439,   411,   472,   472,   198,   410,   543,
     543,    94,    29,   264,   107,   107,   446,   542,   650,   118,
     224,   650,   384,   411,   118,   543,    94,   186,    94,   650,
       5,   133,   525,   526,   528,   530,    28,   134,   523,   524,
     527,   530,   196,   521,   196,   113,   184,   439,   472,   184,
     543,   617,   385,   446,   304,   650,   118,   224,   650,   186,
     543,   392,   411,   543,   186,    93,   133,   528,   183,   134,
     527,   196,   118,   411,   304,   650,   118,   392,   411,   186,
     186,   650,   292,   304,   650,   186,   305,   411,   305,   489,
     489,   198,   286,   650,   224,   118,   650,   305,   489
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
     410,   410,   411,   411,   411,   411,   411,   411,   412,   412,
     412,   412,   412,   412,   412,   412,   412,   412,   412,   412,
     413,   414,   415,   415,   416,   416,   416,   417,   417,   418,
     418,   419,   420,   420,   420,   421,   421,   421,   421,   421,
     422,   422,   423,   423,   423,   424,   424,   424,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     426,   427,   428,   429,   429,   430,   430,   430,   430,   431,
     431,   432,   432,   432,   433,   433,   433,   434,   434,   434,
     435,   436,   437,   437,   438,   438,   438,   438,   438,   438,
     439,   440,   440,   441,   441,   442,   442,   443,   443,   443,
     443,   443,   443,   443,   444,   444,   445,   445,   446,   447,
     447,   448,   448,   449,   449,   450,   451,   451,   452,   453,
     453,   454,   455,   455,   456,   457,   457,   458,   458,   459,
     459,   460,   460,   461,   461,   462,   462,   463,   464,   464,
     465,   465,   466,   466,   466,   466,   466,   467,   466,   466,
     466,   466,   468,   468,   469,   469,   470,   470,   471,   471,
     472,   472,   472,   473,   473,   473,   473,   473,   474,   474,
     474,   475,   475,   475,   476,   476,   477,   477,   478,   478,
     479,   479,   480,   480,   481,   481,   481,   481,   482,   482,
     482,   483,   483,   483,   483,   483,   483,   484,   484,   484,
     485,   485,   485,   485,   486,   486,   487,   487,   488,   488,
     488,   489,   489,   489,   489,   490,   491,   491,   491,   492,
     492,   493,   493,   493,   493,   494,   494,   495,   495,   495,
     495,   495,   495,   495,   496,   496,   497,   497,   498,   498,
     498,   498,   498,   499,   499,   500,   500,   501,   501,   501,
     501,   502,   502,   502,   502,   503,   503,   504,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   506,   506,   507,   507,   507,   508,   509,   509,
     510,   511,   512,   513,   513,   514,   514,   515,   515,   516,
     516,   516,   517,   517,   517,   517,   517,   517,   518,   518,
     519,   519,   520,   521,   521,   522,   522,   523,   523,   524,
     524,   524,   524,   525,   525,   526,   526,   526,   526,   527,
     527,   528,   528,   529,   529,   529,   529,   530,   530,   530,
     530,   531,   531,   532,   532,   533,   534,   534,   534,   534,
     534,   534,   535,   536,   536,   537,   537,   538,   539,   540,
     540,   541,   541,   542,   543,   543,   543,   544,   544,   544,
     545,   545,   545,   545,   545,   545,   545,   546,   546,   547,
     548,   548,   548,   548,   548,   548,   548,   548,   548,   549,
     550,   550,   550,   551,   552,   553,   553,   553,   554,   554,
     554,   554,   554,   555,   556,   556,   556,   556,   556,   556,
     556,   557,   558,   559,   560,   561,   561,   562,   563,   564,
     564,   565,   566,   566,   567,   568,   568,   568,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   570,   570,
     571,   571,   572,   573,   574,   574,   575,   576,   577,   577,
     578,   579,   580,   580,   581,   582,   582,   583,   583,   584,
     584,   585,   585,   586,   586,   587,   587,   588,   589,   589,
     590,   590,   591,   592,   592,   592,   593,   593,   594,   595,
     595,   596,   597,   597,   598,   598,   599,   599,   599,   600,
     600,   601,   601,   602,   602,   602,   602,   602,   603,   604,
     605,   606,   606,   606,   607,   607,   608,   608,   608,   608,
     608,   608,   608,   608,   609,   609,   609,   609,   610,   610,
     611,   612,   612,   613,   613,   613,   614,   614,   615,   615,
     616,   616,   617,   618,   618,   619,   619,   620,   620,   620,
     621,   621,   622,   622,   623,   623,   624,   624,   625,   625,
     626,   627,   627,   628,   628,   628,   629,   630,   630,   630,
     630,   631,   631,   632,   632,   633,   634,   634,   635,   635,
     636,   636,   637,   638,   638,   639,   639,   639,   640,   641,
     642,   643,   644,   644,   644,   645,   646,   647,   648,   649,
     649,   650,   650,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   651,   651,   651,
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
     651,   651,   651,   652
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       2,     3,     3,     3,     5,     5,     5,     8,     5,     3,
       5,     7,     1,     1,     1,     3,     3,     3,     1,     1,
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
     580,   393,    -1,   411,    -1,   410,   107,   411,    -1,   410,
       1,   411,     1,    -1,   410,   334,   411,    -1,   413,    -1,
     450,    -1,   457,    -1,   463,    -1,   576,    -1,   412,    -1,
     464,    -1,   447,    -1,   569,    -1,   570,    -1,   572,    -1,
     571,    -1,   573,    -1,   641,    -1,   639,    -1,   642,    -1,
     643,    -1,   640,    -1,   422,   414,    -1,   186,   411,    -1,
      66,   283,    -1,    71,   283,    -1,   216,    -1,   253,    -1,
      55,   253,    -1,   416,   432,    77,   411,    -1,   416,    77,
     411,    -1,    46,   415,   431,   417,   417,    -1,    46,   415,
     431,   417,    -1,    42,   118,   650,    -1,   423,    -1,   428,
      -1,   418,    -1,   420,    -1,   435,    -1,   440,    -1,   436,
      -1,   419,    -1,   420,    -1,   422,   421,    -1,    46,   118,
     424,    -1,    46,     1,   424,    -1,    46,     3,    -1,   425,
      -1,   424,   107,   118,   425,    -1,   424,   107,   425,    -1,
     650,   147,   411,    -1,   650,    36,   127,   147,   411,    -1,
     650,   542,   147,   411,    -1,   650,   542,    36,   127,   147,
     411,    -1,   650,   426,   147,   411,    -1,   650,    36,   127,
     426,   147,   411,    -1,   650,   542,   426,   147,   411,    -1,
     650,   542,    36,   127,   426,   147,   411,    -1,   650,   427,
     147,   411,    -1,   650,   542,   427,   147,   411,    -1,   650,
     426,   427,   147,   411,    -1,   650,   542,   426,   427,   147,
     411,    -1,    96,   118,   650,    -1,   272,   118,   650,    -1,
      51,   429,    -1,   430,    -1,   429,   107,   430,    -1,   118,
     650,   142,   411,    -1,   118,   650,   542,   142,   411,    -1,
     427,   142,   411,    -1,   118,   650,   542,   427,   142,   411,
      -1,   118,   650,   147,   411,    -1,   118,   650,   542,   147,
     411,    -1,   433,    -1,   118,   650,    -1,   118,   650,   433,
      -1,   426,    -1,   426,   434,    -1,   434,    -1,    58,   118,
     650,    53,   118,   650,    -1,    53,   118,   650,    -1,    58,
     118,   650,    -1,   211,   411,    -1,   171,   170,   437,    -1,
     438,    -1,   437,   107,   438,    -1,   118,   650,    -1,   118,
     650,   142,   411,    -1,   118,   650,   542,   142,   411,    -1,
     118,   650,   542,   142,   411,   439,    -1,   118,   650,   142,
     411,   439,    -1,   118,   650,   439,    -1,   106,   648,    -1,
     168,   170,   441,    -1,    69,   168,   170,   441,    -1,   442,
      -1,   441,   107,   442,    -1,   411,    -1,   411,   443,    -1,
     444,    -1,   445,    -1,   446,    -1,   444,   445,    -1,   444,
     446,    -1,   445,   446,    -1,   444,   445,   446,    -1,    95,
      -1,   116,    -1,   127,   128,    -1,   127,   129,    -1,   106,
     648,    -1,    67,   118,   448,   188,   411,    -1,   135,   118,
     448,   188,   411,    -1,   449,    -1,   448,   107,   118,   449,
      -1,   650,   147,   411,    -1,   650,   542,   147,   411,    -1,
      72,   156,   410,   187,   451,   113,   186,   411,    -1,   452,
      -1,   451,   452,    -1,   453,   186,   411,    -1,   100,   411,
      -1,   453,   100,   411,    -1,    72,   156,   410,   187,   455,
     113,   186,   392,    -1,   456,    -1,   455,   456,    -1,   453,
     186,   392,    -1,    73,   156,   410,   187,   459,   113,   186,
     411,    -1,    73,   156,   410,   187,   459,   113,   118,   650,
     186,   411,    -1,    73,   156,   410,   187,   461,   113,   186,
     392,    -1,    73,   156,   410,   187,   459,   113,   118,   650,
     186,   392,    -1,   460,    -1,   459,   460,    -1,   100,   543,
     186,   411,    -1,   100,   118,   650,    94,   543,   186,   411,
      -1,   462,    -1,   461,   462,    -1,   100,   543,   186,   392,
      -1,   100,   118,   650,    94,   543,   186,   392,    -1,    48,
     156,   410,   187,   197,   411,   126,   411,    -1,   465,    -1,
     464,   167,   465,    -1,   466,    -1,   465,    92,   466,    -1,
     468,    -1,   468,   483,   468,    -1,   468,   484,   468,    -1,
     468,   132,   468,    -1,   468,   162,   468,    -1,    -1,   468,
     157,   467,   468,    -1,   468,   155,   468,    -1,   468,   143,
     468,    -1,   468,   141,   468,    -1,   469,    -1,   469,   248,
      70,   581,   470,    -1,   471,    -1,   471,    99,   469,    -1,
      -1,   633,    -1,   472,    -1,   472,   198,   472,    -1,   473,
      -1,   472,   176,   473,    -1,   472,   158,   473,    -1,   474,
      -1,   473,   193,   474,    -1,   473,   117,   474,    -1,   473,
     146,   474,    -1,   473,   159,   474,    -1,   475,    -1,   474,
     200,   475,    -1,   474,   209,   475,    -1,   476,    -1,   475,
     150,   476,    -1,   475,   136,   476,    -1,   477,    -1,   477,
      50,   230,   543,    -1,   478,    -1,   478,   199,    94,   543,
      -1,   479,    -1,   479,   101,    94,   541,    -1,   480,    -1,
     480,   102,    94,   541,    -1,   482,    -1,   481,   482,    -1,
     176,    -1,   158,    -1,   481,   176,    -1,   481,   158,    -1,
     485,    -1,   489,    -1,   486,    -1,   202,    -1,   207,    -1,
     206,    -1,   205,    -1,   204,    -1,   203,    -1,   151,    -1,
     179,    -1,   140,    -1,    75,   153,   390,   184,    -1,    75,
     221,   153,   390,   184,    -1,    75,   220,   153,   390,   184,
      -1,    75,    76,   558,   153,   390,   184,    -1,   487,   153,
     184,    -1,   487,   153,   410,   184,    -1,   488,    -1,   487,
     488,    -1,   177,   650,    17,    -1,   177,    18,    -1,   177,
      19,    -1,   490,    -1,   490,   491,    -1,   192,   491,    -1,
     491,    -1,   191,    -1,   492,    -1,   492,   191,   491,    -1,
     492,   192,   491,    -1,   493,    -1,   502,    -1,   494,    -1,
     494,   503,    -1,   497,    -1,   497,   503,    -1,   495,   499,
      -1,   496,    -1,   105,   122,    -1,   114,   122,    -1,    97,
     122,    -1,   189,   122,    -1,   115,   122,    -1,   139,   122,
      -1,   138,   122,    -1,   499,    -1,    98,   499,    -1,   498,
     499,    -1,   120,    -1,   172,   122,    -1,    90,   122,    -1,
     181,   122,    -1,   180,   122,    -1,    91,   122,    -1,   548,
      -1,   500,    -1,   650,    -1,   501,    -1,   193,    -1,    11,
      -1,    12,    -1,    20,    -1,   505,    -1,   502,   503,    -1,
     502,   156,   187,    -1,   502,   156,   514,   187,    -1,   504,
      -1,   503,   504,    -1,   154,   410,   185,    -1,   506,    -1,
     508,    -1,   509,    -1,   510,    -1,   513,    -1,   515,    -1,
     511,    -1,   512,    -1,   561,    -1,   394,    -1,   637,    -1,
     634,    -1,   635,    -1,   636,    -1,   507,    -1,   560,    -1,
     110,    -1,   149,    -1,   124,    -1,   118,   650,    -1,   156,
     187,    -1,   156,   410,   187,    -1,   119,    -1,   169,   153,
     410,   184,    -1,   201,   153,   410,   184,    -1,   651,   156,
     187,    -1,   651,   156,   514,   187,    -1,   411,    -1,   514,
     107,   411,    -1,   516,    -1,   534,    -1,   517,    -1,   531,
      -1,   532,    -1,   157,   650,   521,   130,    -1,   157,   650,
     519,   521,   130,    -1,   157,   650,   521,   196,   194,   650,
     521,   196,    -1,   157,   650,   521,   196,   518,   194,   650,
     521,   196,    -1,   157,   650,   519,   521,   196,   194,   650,
     521,   196,    -1,   157,   650,   519,   521,   196,   518,   194,
     650,   521,   196,    -1,   529,    -1,   518,   529,    -1,   520,
      -1,   519,   520,    -1,    35,   650,   521,   132,   521,   522,
      -1,    -1,    35,    -1,   183,   523,   183,    -1,    93,   525,
      93,    -1,    -1,   524,    -1,   134,    -1,   527,    -1,   524,
     134,    -1,   524,   527,    -1,    -1,   526,    -1,   133,    -1,
     528,    -1,   526,   133,    -1,   526,   528,    -1,    28,    -1,
     530,    -1,     5,    -1,   530,    -1,   516,    -1,    10,    -1,
     533,    -1,   530,    -1,     9,    -1,   123,    -1,   125,    -1,
     153,   390,   184,    -1,   212,    30,   213,    -1,   212,   213,
      -1,   174,   649,   175,    -1,   174,   649,     8,    -1,   103,
       7,    -1,   535,    -1,   536,    -1,   537,    -1,   538,    -1,
     539,    -1,   540,    -1,    43,   153,   390,   184,    -1,    21,
     389,   184,    -1,    45,   153,   410,   184,   153,   389,   184,
      -1,    22,   389,   184,    -1,    97,   153,   410,   184,   153,
     389,   184,    -1,    70,   153,   390,   184,    -1,    39,   153,
     390,   184,    -1,    23,   389,   184,    -1,    59,   153,   410,
     184,   153,   389,   184,    -1,   547,    -1,   547,   144,    -1,
      94,   543,    -1,   545,    -1,   545,   544,    -1,   210,   156,
     187,    -1,   144,    -1,   193,    -1,   176,    -1,   547,    -1,
     548,    -1,   152,   156,   187,    -1,   319,   156,   187,    -1,
     564,    -1,   567,    -1,   644,    -1,   543,    -1,   546,   107,
     543,    -1,   650,    -1,   550,    -1,   556,    -1,   554,    -1,
     557,    -1,   555,    -1,   553,    -1,   552,    -1,   551,    -1,
     549,    -1,   224,   156,   187,    -1,    44,   156,   187,    -1,
      44,   156,   556,   187,    -1,    44,   156,   557,   187,    -1,
      70,   156,   187,    -1,    39,   156,   187,    -1,    59,   156,
     187,    -1,    59,   156,   649,   187,    -1,    59,   156,    29,
     187,    -1,    97,   156,   187,    -1,    97,   156,   650,   187,
      -1,    97,   156,   650,   107,   558,   187,    -1,    97,   156,
     193,   187,    -1,    97,   156,   193,   107,   558,   187,    -1,
      61,   156,   650,   187,    -1,    45,   156,   187,    -1,    45,
     156,   650,   187,    -1,    45,   156,   650,   107,   558,   187,
      -1,    45,   156,   650,   107,   559,   187,    -1,    45,   156,
     193,   187,    -1,    45,   156,   193,   107,   558,   187,    -1,
      45,   156,   193,   107,   559,   187,    -1,    62,   156,   650,
     187,    -1,   650,    -1,   650,   144,    -1,    29,    -1,   562,
      -1,   563,    -1,   650,   145,   149,    -1,    47,   378,   395,
      -1,   565,    -1,   566,    -1,    47,   156,   193,   187,    -1,
      47,   156,   187,    94,   543,    -1,    47,   156,   546,   187,
      94,   543,    -1,   156,   545,   187,    -1,    33,   219,   220,
      -1,    33,   219,   221,    -1,    33,   219,   222,    -1,   225,
     224,   411,   232,   411,    -1,   225,   224,   411,    94,   231,
     232,   411,    -1,   225,   224,   411,    94,   233,   232,   411,
      -1,   225,   224,   411,   217,   411,    -1,   225,   224,   411,
     218,   411,    -1,   225,   226,   411,   232,   411,    -1,   225,
     226,   411,    94,   231,   232,   411,    -1,   225,   226,   411,
      94,   233,   232,   411,    -1,   225,   226,   411,   217,   411,
      -1,   225,   226,   411,   218,   411,    -1,   223,   224,   411,
      -1,   223,   226,   411,    -1,   228,   224,   411,   236,   411,
      -1,   228,   229,   230,   224,   411,   236,   411,    -1,   227,
     224,   411,    94,   411,    -1,   235,   118,   574,   234,   411,
     186,   411,    -1,   575,    -1,   574,   107,   118,   575,    -1,
     650,   142,   411,    -1,   243,   153,   410,   184,   577,    -1,
     578,    -1,   577,   578,    -1,   244,   580,   579,    -1,   153,
     410,   184,    -1,   500,    -1,   580,   209,   500,    -1,   584,
     582,    -1,    -1,   583,    -1,   602,    -1,   583,   602,    -1,
     585,    -1,   584,   261,   585,    -1,   586,    -1,   585,   257,
     586,    -1,   587,    -1,   586,   259,   147,   587,    -1,   588,
      -1,   258,   588,    -1,   592,   589,   590,    -1,    -1,   607,
      -1,    -1,   591,    -1,   281,   153,   410,   184,    -1,   596,
     593,    -1,   156,   581,   187,    -1,   594,    -1,    -1,   629,
      -1,   487,   153,   595,   184,    -1,    -1,   581,    -1,   597,
     598,    -1,   506,    -1,   153,   410,   184,    -1,    -1,   599,
      -1,   247,   600,    -1,   246,   601,    -1,   269,    -1,    -1,
      78,    -1,    -1,   285,    -1,   603,    -1,   604,    -1,   605,
      -1,   631,    -1,   628,    -1,   169,    -1,   283,   472,   606,
      -1,   252,   630,   606,    -1,   285,    -1,   275,    -1,   268,
      -1,   245,   608,    -1,   607,   245,   608,    -1,   609,    -1,
     610,    -1,   611,    -1,   626,    -1,   612,    -1,   620,    -1,
     613,    -1,   627,    -1,   100,   273,    -1,   100,   262,    -1,
     265,    -1,   280,    -1,   250,   273,    -1,   250,   262,    -1,
      56,   650,    29,    -1,   276,    -1,    54,   276,    -1,   278,
     614,    -1,   278,   156,   614,   615,   187,    -1,    54,   278,
      -1,   617,    -1,   113,    -1,    -1,   107,   616,    -1,   617,
      -1,   616,   107,   617,    -1,    96,    29,   618,   619,    -1,
      -1,   270,    29,    -1,    -1,   630,   264,    -1,   277,   285,
     621,   623,    -1,   277,   285,   113,   623,    -1,    54,   277,
     285,    -1,    96,    29,    -1,   156,   622,   187,    -1,    29,
      -1,   622,   107,    29,    -1,    -1,   624,    -1,   625,    -1,
     624,   625,    -1,   200,   621,    -1,   136,   621,    -1,   263,
      29,    -1,   282,    -1,    54,   282,    -1,    96,   216,    -1,
      96,   253,    -1,   254,   249,    -1,   266,   630,   279,    -1,
     255,   472,    -1,    96,   129,   472,    -1,    96,    52,   472,
      -1,   256,   472,   198,   472,    -1,   271,   632,    -1,   251,
     632,    -1,   274,    -1,   267,    -1,   284,   249,   474,    -1,
     154,   185,    -1,   154,   410,   185,    -1,   309,   310,    -1,
     309,   410,   310,    -1,   311,   312,    -1,   311,   410,   312,
      -1,   153,   638,   184,    -1,   411,   121,   411,    -1,   638,
     107,   411,   121,   411,    -1,   225,   313,   411,   232,   411,
      -1,   225,   313,   638,   232,   411,    -1,   225,   313,   411,
     232,   411,    96,   315,   411,    -1,   314,   313,   411,   232,
     411,    -1,   223,   313,   502,    -1,   227,   313,   502,    94,
     411,    -1,   228,   313,   229,   230,   502,   236,   411,    -1,
     645,    -1,   646,    -1,   647,    -1,   318,   156,   187,    -1,
     316,   156,   187,    -1,   317,   156,   187,    -1,    29,    -1,
      16,    -1,   650,    -1,   651,    -1,    97,    -1,    39,    -1,
      44,    -1,    45,    -1,   152,    -1,    48,    -1,   224,    -1,
      59,    -1,    61,    -1,    62,    -1,    70,    -1,    73,    -1,
      72,    -1,   210,    -1,   242,    -1,   652,    -1,    24,    -1,
     214,    -1,   127,    -1,    38,    -1,   260,    -1,    37,    -1,
     221,    -1,   220,    -1,   146,    -1,    43,    -1,   258,    -1,
     259,    -1,   273,    -1,   262,    -1,   250,    -1,   284,    -1,
     276,    -1,   278,    -1,   277,    -1,   282,    -1,   254,    -1,
     249,    -1,    78,    -1,   216,    -1,   253,    -1,    52,    -1,
     222,    -1,   235,    -1,   301,    -1,   229,    -1,   202,    -1,
     207,    -1,   206,    -1,   205,    -1,   204,    -1,   203,    -1,
      96,    -1,   111,    -1,   112,    -1,   186,    -1,    46,    -1,
      36,    -1,    66,    -1,    71,    -1,    58,    -1,    53,    -1,
      55,    -1,    77,    -1,    42,    -1,   147,    -1,    51,    -1,
     211,    -1,   170,    -1,   171,    -1,   168,    -1,    69,    -1,
      95,    -1,   116,    -1,   128,    -1,   129,    -1,   106,    -1,
      67,    -1,   135,    -1,   188,    -1,   100,    -1,    94,    -1,
     197,    -1,   126,    -1,   167,    -1,    92,    -1,    50,    -1,
     230,    -1,   101,    -1,   198,    -1,   117,    -1,   159,    -1,
     200,    -1,   150,    -1,   136,    -1,    75,    -1,    76,    -1,
     102,    -1,   199,    -1,   151,    -1,   182,    -1,   195,    -1,
     160,    -1,   137,    -1,   131,    -1,   166,    -1,   148,    -1,
     165,    -1,    33,    -1,    40,    -1,    57,    -1,   113,    -1,
      41,    -1,    56,    -1,   215,    -1,    49,    -1,    60,    -1,
      34,    -1,    47,    -1,   272,    -1,   248,    -1,   281,    -1,
     283,    -1,   252,    -1,   266,    -1,   279,    -1,   271,    -1,
     251,    -1,   265,    -1,   280,    -1,   270,    -1,   264,    -1,
     263,    -1,   247,    -1,   246,    -1,   255,    -1,   256,    -1,
     285,    -1,   275,    -1,   274,    -1,   269,    -1,   267,    -1,
     268,    -1,   228,    -1,   234,    -1,   231,    -1,   225,    -1,
     218,    -1,   217,    -1,   219,    -1,   236,    -1,   226,    -1,
     227,    -1,   233,    -1,   223,    -1,   232,    -1,    65,    -1,
      63,    -1,    74,    -1,   169,    -1,   201,    -1,   241,    -1,
     239,    -1,   240,    -1,   237,    -1,   238,    -1,   243,    -1,
     244,    -1,   245,    -1,    64,    -1,   294,    -1,   292,    -1,
     293,    -1,   298,    -1,   299,    -1,   300,    -1,   295,    -1,
     296,    -1,   297,    -1,    79,    -1,    80,    -1,    81,    -1,
      82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,    -1,
      87,    -1,    88,    -1,    89,    -1,   286,    -1,   287,    -1,
     288,    -1,   289,    -1,   290,    -1,   291,    -1,   302,    -1,
     303,    -1,   304,    -1,   305,    -1,   306,    -1,   307,    -1,
     308,    -1,    90,    -1,   105,    -1,   114,    -1,   172,    -1,
     180,    -1,   189,    -1,   138,    -1,    91,    -1,   115,    -1,
     139,    -1,   181,    -1,   313,    -1,   314,    -1,   315,    -1,
     318,    -1,   317,    -1,   316,    -1,   319,    -1,    25,    -1
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
    1504,  1506,  1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,
    1524,  1529,  1535,  1541,  1548,  1552,  1557,  1559,  1562,  1566,
    1569,  1572,  1574,  1577,  1580,  1582,  1584,  1586,  1590,  1594,
    1596,  1598,  1600,  1603,  1605,  1608,  1611,  1613,  1616,  1619,
    1622,  1625,  1628,  1631,  1634,  1636,  1639,  1642,  1644,  1647,
    1650,  1653,  1656,  1659,  1661,  1663,  1665,  1667,  1669,  1671,
    1673,  1675,  1677,  1680,  1684,  1689,  1691,  1694,  1698,  1700,
    1702,  1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1720,
    1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,  1739,  1742,
    1746,  1748,  1753,  1758,  1762,  1767,  1769,  1773,  1775,  1777,
    1779,  1781,  1783,  1788,  1794,  1803,  1813,  1823,  1834,  1836,
    1839,  1841,  1844,  1851,  1852,  1854,  1858,  1862,  1863,  1865,
    1867,  1869,  1872,  1875,  1876,  1878,  1880,  1882,  1885,  1888,
    1890,  1892,  1894,  1896,  1898,  1900,  1902,  1904,  1906,  1908,
    1910,  1914,  1918,  1921,  1925,  1929,  1932,  1934,  1936,  1938,
    1940,  1942,  1944,  1949,  1953,  1961,  1965,  1973,  1978,  1983,
    1987,  1995,  1997,  2000,  2003,  2005,  2008,  2012,  2014,  2016,
    2018,  2020,  2022,  2026,  2030,  2032,  2034,  2036,  2038,  2042,
    2044,  2046,  2048,  2050,  2052,  2054,  2056,  2058,  2060,  2062,
    2066,  2070,  2075,  2080,  2084,  2088,  2092,  2097,  2102,  2106,
    2111,  2118,  2123,  2130,  2135,  2139,  2144,  2151,  2158,  2163,
    2170,  2177,  2182,  2184,  2187,  2189,  2191,  2193,  2197,  2201,
    2203,  2205,  2210,  2216,  2223,  2227,  2231,  2235,  2239,  2245,
    2253,  2261,  2267,  2273,  2279,  2287,  2295,  2301,  2307,  2311,
    2315,  2321,  2329,  2335,  2343,  2345,  2350,  2354,  2360,  2362,
    2365,  2369,  2373,  2375,  2379,  2382,  2383,  2385,  2387,  2390,
    2392,  2396,  2398,  2402,  2404,  2409,  2411,  2414,  2418,  2419,
    2421,  2422,  2424,  2429,  2432,  2436,  2438,  2439,  2441,  2446,
    2447,  2449,  2452,  2454,  2458,  2459,  2461,  2464,  2467,  2469,
    2470,  2472,  2473,  2475,  2477,  2479,  2481,  2483,  2485,  2487,
    2491,  2495,  2497,  2499,  2501,  2504,  2508,  2510,  2512,  2514,
    2516,  2518,  2520,  2522,  2524,  2527,  2530,  2532,  2534,  2537,
    2540,  2544,  2546,  2549,  2552,  2558,  2561,  2563,  2565,  2566,
    2569,  2571,  2575,  2580,  2581,  2584,  2585,  2588,  2593,  2598,
    2602,  2605,  2609,  2611,  2615,  2616,  2618,  2620,  2623,  2626,
    2629,  2632,  2634,  2637,  2640,  2643,  2646,  2650,  2653,  2657,
    2661,  2666,  2669,  2672,  2674,  2676,  2680,  2683,  2687,  2690,
    2694,  2697,  2701,  2705,  2709,  2715,  2721,  2727,  2736,  2742,
    2746,  2752,  2760,  2762,  2764,  2766,  2770,  2774,  2778,  2780,
    2782,  2784,  2786,  2788,  2790,  2792,  2794,  2796,  2798,  2800,
    2802,  2804,  2806,  2808,  2810,  2812,  2814,  2816,  2818,  2820,
    2822,  2824,  2826,  2828,  2830,  2832,  2834,  2836,  2838,  2840,
    2842,  2844,  2846,  2848,  2850,  2852,  2854,  2856,  2858,  2860,
    2862,  2864,  2866,  2868,  2870,  2872,  2874,  2876,  2878,  2880,
    2882,  2884,  2886,  2888,  2890,  2892,  2894,  2896,  2898,  2900,
    2902,  2904,  2906,  2908,  2910,  2912,  2914,  2916,  2918,  2920,
    2922,  2924,  2926,  2928,  2930,  2932,  2934,  2936,  2938,  2940,
    2942,  2944,  2946,  2948,  2950,  2952,  2954,  2956,  2958,  2960,
    2962,  2964,  2966,  2968,  2970,  2972,  2974,  2976,  2978,  2980,
    2982,  2984,  2986,  2988,  2990,  2992,  2994,  2996,  2998,  3000,
    3002,  3004,  3006,  3008,  3010,  3012,  3014,  3016,  3018,  3020,
    3022,  3024,  3026,  3028,  3030,  3032,  3034,  3036,  3038,  3040,
    3042,  3044,  3046,  3048,  3050,  3052,  3054,  3056,  3058,  3060,
    3062,  3064,  3066,  3068,  3070,  3072,  3074,  3076,  3078,  3080,
    3082,  3084,  3086,  3088,  3090,  3092,  3094,  3096,  3098,  3100,
    3102,  3104,  3106,  3108,  3110,  3112,  3114,  3116,  3118,  3120,
    3122,  3124,  3126,  3128,  3130,  3132,  3134,  3136,  3138,  3140,
    3142,  3144,  3146,  3148,  3150,  3152,  3154,  3156,  3158,  3160,
    3162,  3164,  3166,  3168,  3170,  3172,  3174,  3176,  3178,  3180,
    3182,  3184,  3186,  3188,  3190,  3192,  3194,  3196,  3198,  3200,
    3202,  3204,  3206,  3208,  3210,  3212,  3214,  3216,  3218,  3220,
    3222,  3224,  3226,  3228
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
    2482,  2489,  2502,  2503,  2504,  2505,  2506,  2507,  2512,  2513,
    2516,  2517,  2518,  2519,  2520,  2523,  2524,  2525,  2526,  2527,
    2532,  2546,  2554,  2559,  2567,  2572,  2577,  2585,  2594,  2606,
    2616,  2629,  2637,  2638,  2639,  2644,  2645,  2646,  2647,  2648,
    2653,  2660,  2670,  2676,  2685,  2695,  2702,  2710,  2722,  2732,
    2742,  2752,  2762,  2772,  2782,  2792,  2803,  2812,  2822,  2832,
    2848,  2857,  2866,  2874,  2880,  2892,  2900,  2910,  2918,  2930,
    2936,  2947,  2949,  2953,  2961,  2965,  2970,  2974,  2978,  2982,
    2992,  3000,  3007,  3013,  3023,  3027,  3031,  3039,  3047,  3055,
    3067,  3075,  3081,  3091,  3097,  3107,  3111,  3121,  3127,  3133,
    3139,  3148,  3157,  3166,  3179,  3183,  3191,  3197,  3207,  3215,
    3224,  3237,  3244,  3256,  3260,  3272,  3279,  3285,  3294,  3301,
    3307,  3318,  3325,  3331,  3340,  3349,  3356,  3367,  3374,  3386,
    3392,  3404,  3410,  3421,  3427,  3438,  3444,  3455,  3464,  3468,
    3477,  3481,  3489,  3493,  3503,  3510,  3519,  3529,  3528,  3542,
    3551,  3560,  3573,  3577,  3589,  3593,  3601,  3604,  3611,  3615,
    3624,  3628,  3632,  3640,  3644,  3650,  3656,  3662,  3672,  3676,
    3680,  3688,  3692,  3698,  3708,  3712,  3722,  3726,  3736,  3740,
    3750,  3754,  3764,  3768,  3776,  3780,  3784,  3788,  3798,  3802,
    3806,  3814,  3818,  3822,  3826,  3830,  3834,  3842,  3846,  3850,
    3858,  3862,  3866,  3870,  3881,  3887,  3897,  3903,  3913,  3917,
    3921,  3959,  3963,  3973,  3983,  3996,  4005,  4015,  4019,  4028,
    4032,  4041,  4047,  4055,  4061,  4073,  4079,  4089,  4093,  4097,
    4101,  4105,  4111,  4117,  4125,  4129,  4137,  4141,  4152,  4156,
    4160,  4166,  4170,  4184,  4188,  4196,  4200,  4210,  4214,  4218,
    4222,  4231,  4235,  4239,  4243,  4251,  4257,  4267,  4275,  4279,
    4283,  4287,  4291,  4295,  4299,  4303,  4307,  4311,  4316,  4320,
    4324,  4328,  4336,  4340,  4348,  4355,  4362,  4373,  4381,  4385,
    4393,  4401,  4409,  4463,  4467,  4480,  4486,  4496,  4500,  4508,
    4512,  4516,  4524,  4534,  4544,  4561,  4578,  4595,  4617,  4623,
    4634,  4640,  4651,  4662,  4664,  4668,  4673,  4683,  4686,  4693,
    4699,  4705,  4713,  4726,  4729,  4736,  4742,  4748,  4755,  4766,
    4770,  4780,  4784,  4794,  4798,  4802,  4807,  4816,  4822,  4828,
    4834,  4842,  4847,  4855,  4860,  4868,  4876,  4881,  4886,  4891,
    4896,  4901,  4910,  4918,  4922,  4939,  4943,  4951,  4959,  4967,
    4971,  4979,  4985,  4995,  5003,  5007,  5011,  5046,  5052,  5058,
    5068,  5072,  5076,  5080,  5084,  5088,  5092,  5099,  5105,  5115,
    5123,  5127,  5131,  5135,  5139,  5143,  5147,  5151,  5155,  5163,
    5171,  5175,  5179,  5189,  5197,  5205,  5209,  5213,  5221,  5225,
    5231,  5237,  5241,  5251,  5259,  5263,  5269,  5278,  5287,  5293,
    5299,  5309,  5326,  5333,  5348,  5384,  5388,  5396,  5404,  5416,
    5420,  5428,  5436,  5440,  5451,  5468,  5474,  5480,  5490,  5494,
    5500,  5506,  5510,  5516,  5520,  5526,  5532,  5539,  5549,  5554,
    5562,  5568,  5578,  5600,  5609,  5615,  5628,  5642,  5649,  5655,
    5665,  5674,  5682,  5688,  5706,  5714,  5718,  5725,  5730,  5738,
    5742,  5749,  5753,  5760,  5764,  5771,  5775,  5784,  5797,  5800,
    5808,  5811,  5819,  5827,  5835,  5839,  5847,  5850,  5858,  5870,
    5873,  5881,  5893,  5899,  5909,  5912,  5920,  5924,  5928,  5936,
    5939,  5947,  5950,  5958,  5962,  5966,  5970,  5974,  5982,  5990,
    6002,  6014,  6018,  6022,  6030,  6036,  6046,  6050,  6054,  6058,
    6062,  6066,  6070,  6074,  6082,  6086,  6090,  6094,  6102,  6108,
    6118,  6128,  6132,  6140,  6150,  6161,  6168,  6172,  6180,  6183,
    6190,  6195,  6204,  6214,  6217,  6224,  6228,  6236,  6245,  6252,
    6262,  6266,  6273,  6279,  6289,  6292,  6299,  6304,  6316,  6324,
    6336,  6344,  6348,  6356,  6360,  6364,  6372,  6380,  6384,  6388,
    6392,  6400,  6408,  6420,  6424,  6432,  6446,  6450,  6457,  6462,
    6470,  6475,  6484,  6492,  6498,  6508,  6514,  6524,  6531,  6538,
    6567,  6596,  6625,  6629,  6633,  6640,  6647,  6654,  6666,  6670,
    6671,  6684,  6685,  6686,  6687,  6688,  6689,  6690,  6691,  6692,
    6693,  6694,  6695,  6696,  6697,  6698,  6699,  6703,  6704,  6705,
    6706,  6707,  6708,  6709,  6710,  6711,  6712,  6713,  6714,  6715,
    6716,  6717,  6718,  6719,  6720,  6721,  6722,  6723,  6724,  6725,
    6726,  6727,  6728,  6729,  6730,  6731,  6732,  6733,  6734,  6735,
    6736,  6737,  6738,  6739,  6740,  6741,  6742,  6743,  6744,  6745,
    6746,  6747,  6748,  6749,  6750,  6751,  6752,  6753,  6754,  6755,
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
    6906,  6907,  6908,  6913
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
  const int xquery_parser::yylast_ = 16174;
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
#line 15968 "/Users/zorba/Code/zorba/release/src/compiler/parser/xquery_parser.cpp"
/* Line 1107 of lalr1.cc  */
#line 6917 "/Users/zorba/Code/zorba/sandbox/src/compiler/parser/xquery_parser.y"


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
