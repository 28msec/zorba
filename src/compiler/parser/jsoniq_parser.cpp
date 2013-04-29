/* A Bison parser, made by GNU Bison 2.7.  */

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
/* Line 279 of lalr1.cc  */
#line 1 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"

#define JSONIQ_PARSER
/* Line 279 of lalr1.cc  */
#line 58 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"


#include "common/common.h"

#ifdef WIN32
#pragma warning(disable: 4786)
#endif

#include "compiler/api/compilercb.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parser/parser_helpers.h"
#include "compiler/parser/xquery_driver.h"
#include "compiler/parsetree/parsenodes.h"
#include "store/api/update_consts.h"
#include "zorbatypes/integer.h"

#define SYMTAB( n ) driver.symtab.get( (off_t)n )
#define SYMTAB_PUT( s ) driver.symtab.put( s )
#define LOC( p ) driver.createQueryLoc( p )


#define YYDEBUG 1

using namespace std;
using namespace zorba;

/* Line 279 of lalr1.cc  */
#line 92 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"


#ifdef XQUERY_PARSER
#include "compiler/parser/xquery_scanner.h"
#else
#include "compiler/parser/jsoniq_scanner.h"
#endif

#undef yylex
#ifdef XQUERY_PARSER
#define yylex driver.getXqueryLexer()->lex
#else
#define yylex driver.getJsoniqLexer()->lex
#endif


/* Line 279 of lalr1.cc  */
#line 89 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


#include "jsoniq_parser.hpp"

/* User implementation prologue.  */
/* Line 285 of lalr1.cc  */
#line 900 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"



template<typename T> inline void release_hack( T *ref ) {
    if ( ref ) {
        RCHelper::addReference( ref );
        RCHelper::removeReference( ref );
    }
}

/* Line 285 of lalr1.cc  */
#line 108 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"


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
# define YY_SYMBOL_PRINT(Title, Type, Value, Location) YYUSE(Type)
# define YY_REDUCE_PRINT(Rule)        static_cast<void>(0)
# define YY_STACK_PRINT()             static_cast<void>(0)

#endif /* !YYDEBUG */

#define yyerrok		(yyerrstatus_ = 0)
#define yyclearin	(yychar = yyempty_)

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace zorba {
/* Line 353 of lalr1.cc  */
#line 203 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

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
  jsoniq_parser::jsoniq_parser (xquery_driver& driver_yyarg)
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

    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
        case 112: /* "'DECIMAL'" */
/* Line 455 of lalr1.cc  */
#line 898 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).decval); };
/* Line 455 of lalr1.cc  */
#line 310 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 127: /* "'DOUBLE'" */
/* Line 455 of lalr1.cc  */
#line 897 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).dval); };
/* Line 455 of lalr1.cc  */
#line 317 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 152: /* "'INTEGER'" */
/* Line 455 of lalr1.cc  */
#line 896 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).ival); };
/* Line 455 of lalr1.cc  */
#line 324 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 345: /* VersionDecl */
/* Line 455 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 331 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 346: /* MainModule */
/* Line 455 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 338 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 347: /* LibraryModule */
/* Line 455 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 345 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 348: /* ModuleDecl */
/* Line 455 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 352 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 349: /* SIND_DeclList */
/* Line 455 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 359 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 350: /* SIND_Decl */
/* Line 455 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 366 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 351: /* Setter */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 373 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 352: /* BoundarySpaceDecl */
/* Line 455 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 380 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 353: /* DefaultCollationDecl */
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 387 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 354: /* BaseURIDecl */
/* Line 455 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 394 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 355: /* ConstructionDecl */
/* Line 455 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 401 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 356: /* OrderingModeDecl */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 408 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 357: /* EmptyOrderDecl */
/* Line 455 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 415 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 358: /* CopyNamespacesDecl */
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 422 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 359: /* Import */
/* Line 455 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 429 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 360: /* SchemaImport */
/* Line 455 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 436 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 361: /* URILiteralList */
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 443 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 362: /* SchemaPrefix */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 450 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 363: /* ModuleImport */
/* Line 455 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 457 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 364: /* NamespaceDecl */
/* Line 455 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 464 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 365: /* DefaultNamespaceDecl */
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 471 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 366: /* VFO_DeclList */
/* Line 455 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 478 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 367: /* VFO_Decl */
/* Line 455 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 485 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 368: /* DecimalFormatDecl */
/* Line 455 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 492 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 369: /* DecimalFormatParamList */
/* Line 455 of lalr1.cc  */
#line 954 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).vstrpair); };
/* Line 455 of lalr1.cc  */
#line 499 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 370: /* DecimalFormatParam */
/* Line 455 of lalr1.cc  */
#line 954 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).strpair); };
/* Line 455 of lalr1.cc  */
#line 506 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 372: /* OptionDecl */
/* Line 455 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 513 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 373: /* FTOptionDecl */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 520 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 374: /* CtxItemDecl */
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 527 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 375: /* CtxItemDecl2 */
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 534 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 376: /* CtxItemDecl3 */
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 541 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 377: /* CtxItemDecl4 */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 548 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 378: /* VarDecl */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 555 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 379: /* VarNameAndType */
/* Line 455 of lalr1.cc  */
#line 954 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).varnametype); };
/* Line 455 of lalr1.cc  */
#line 562 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 380: /* AnnotationList */
/* Line 455 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 569 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 381: /* Annotation */
/* Line 455 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 576 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 382: /* AnnotationLiteralList */
/* Line 455 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 583 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 383: /* FunctionDecl */
/* Line 455 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 590 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 384: /* FunctionDecl2 */
/* Line 455 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 597 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 385: /* FunctionDeclSimple */
/* Line 455 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 604 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 386: /* FunctionDeclUpdating */
/* Line 455 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 611 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 387: /* FunctionSig */
/* Line 455 of lalr1.cc  */
#line 954 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).fnsig); };
/* Line 455 of lalr1.cc  */
#line 618 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 388: /* ParamList */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 625 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 389: /* Param */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 632 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 390: /* CollectionDecl */
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 639 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 392: /* IndexDecl */
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 646 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 393: /* IndexKeyList */
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 653 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 394: /* IndexKeySpec */
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 660 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 395: /* IntegrityConstraintDecl */
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 667 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 396: /* QueryBody */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 674 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 397: /* StatementsAndOptionalExprTop */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 681 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 398: /* StatementsAndOptionalExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 688 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 399: /* StatementsAndExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 695 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 400: /* Statements */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 702 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 401: /* Statement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 709 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 402: /* BlockStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 716 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 403: /* BlockExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 723 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 404: /* EnclosedStatementsAndOptionalExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 730 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 405: /* VarDeclStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 737 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 408: /* AssignStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 744 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 409: /* ApplyStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 751 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 410: /* ExitStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 758 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 411: /* WhileStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 765 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 412: /* FlowCtlStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 772 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 413: /* FLWORStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 779 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 414: /* ReturnStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 786 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 415: /* IfStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 793 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 416: /* TryStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 800 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 417: /* CatchListStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 807 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 418: /* CatchStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 814 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 419: /* VoidStatement */
/* Line 455 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 821 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 420: /* Expr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 828 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 421: /* ExprSingle */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 835 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 422: /* ExprSimple */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 842 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 423: /* FLWORExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 849 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 424: /* ReturnExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 856 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 427: /* FLWORWinCond */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 863 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 428: /* WindowClause */
/* Line 455 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 870 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 429: /* CountClause */
/* Line 455 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 877 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 430: /* ForLetWinClause */
/* Line 455 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 884 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 432: /* FLWORClauseList */
/* Line 455 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 891 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 433: /* ForClause */
/* Line 455 of lalr1.cc  */
#line 920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 898 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 435: /* VarInDeclList */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 905 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 436: /* VarInDecl */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 912 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 437: /* PositionalVar */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 438: /* FTScoreVar */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 439: /* LetClause */
/* Line 455 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 933 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 440: /* VarGetsDeclList */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 441: /* VarGetsDecl */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 947 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 442: /* WindowVarDecl */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 954 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 443: /* WindowVars */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 961 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 444: /* WindowVars3 */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 968 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 445: /* WindowVars2 */
/* Line 455 of lalr1.cc  */
#line 927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 975 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 446: /* WhereClause */
/* Line 455 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 982 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 447: /* GroupByClause */
/* Line 455 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 989 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 448: /* GroupSpecList */
/* Line 455 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 996 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 449: /* GroupSpec */
/* Line 455 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1003 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 450: /* GroupCollationSpec */
/* Line 455 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1010 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 451: /* OrderByClause */
/* Line 455 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1017 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 452: /* OrderSpecList */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1024 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 453: /* OrderSpec */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1031 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 454: /* OrderModifier */
/* Line 455 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1038 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 455: /* OrderDirSpec */
/* Line 455 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1045 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 456: /* OrderEmptySpec */
/* Line 455 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1052 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 457: /* OrderCollationSpec */
/* Line 455 of lalr1.cc  */
#line 922 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1059 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 458: /* QuantifiedExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1066 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 459: /* QVarInDeclList */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1073 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 460: /* QVarInDecl */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1080 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 461: /* SwitchExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1087 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 462: /* SwitchCaseClauseList */
/* Line 455 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1094 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 463: /* SwitchCaseClause */
/* Line 455 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1101 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 464: /* SwitchCaseOperandList */
/* Line 455 of lalr1.cc  */
#line 929 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1108 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 465: /* SwitchStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1115 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 468: /* TypeswitchExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1122 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 469: /* TypeswitchStatement */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1129 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 470: /* CaseClauseList */
/* Line 455 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1136 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 471: /* CaseClause */
/* Line 455 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1143 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 474: /* SequenceTypeList */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1150 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 475: /* IfExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1157 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 476: /* OrExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1164 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 477: /* AndExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1171 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 478: /* NotExpr */
/* Line 455 of lalr1.cc  */
#line 936 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1178 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 479: /* ComparisonExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1185 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 480: /* FTContainsExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1192 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 481: /* StringConcatExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1199 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 482: /* opt_FTIgnoreOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1206 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 483: /* RangeExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1213 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 484: /* AdditiveExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1220 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 485: /* MultiplicativeExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1227 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 486: /* UnionExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1234 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 487: /* IntersectExceptExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1241 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 488: /* InstanceofExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1248 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 489: /* TreatExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1255 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 490: /* CastableExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1262 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 491: /* CastExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1269 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 492: /* SingleType */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1276 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 493: /* UnaryExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1283 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 494: /* SignList */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1290 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 495: /* ValueExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1297 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 496: /* SimpleMapExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1304 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 497: /* ValueComp */
/* Line 455 of lalr1.cc  */
#line 926 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1311 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 498: /* ValidateExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1318 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 499: /* ExtensionExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1325 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 500: /* Pragma_list */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1332 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 501: /* Pragma */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1339 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 502: /* PathExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1346 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 503: /* RelativePathExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1353 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 504: /* StepExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1360 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 505: /* NameTest */
/* Line 455 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1367 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 506: /* Wildcard */
/* Line 455 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1374 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 507: /* FilterExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1381 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 508: /* PredicateList */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1388 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 509: /* Predicate */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1395 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 510: /* PrimaryExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1402 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 511: /* Literal */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1409 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 512: /* NumericLiteral */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1416 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 514: /* VarRef */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1423 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 515: /* ParenthesizedExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1430 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 516: /* ContextItemExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1437 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 517: /* OrderedExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1444 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 518: /* UnorderedExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1451 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 519: /* FunctionCall */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1458 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 520: /* ArgList */
/* Line 455 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1465 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 524: /* Constructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1472 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 525: /* DirectConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1479 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 526: /* DirElemConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1486 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 527: /* DirElemContentList */
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1493 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 528: /* DirAttributeList */
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1500 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 529: /* DirAttr */
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1507 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 531: /* DirAttributeValue */
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1514 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 532: /* opt_QuoteAttrContentList */
/* Line 455 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1521 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 533: /* QuoteAttrContentList */
/* Line 455 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1528 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 534: /* opt_AposAttrContentList */
/* Line 455 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1535 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 535: /* AposAttrContentList */
/* Line 455 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1542 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 536: /* QuoteAttrValueContent */
/* Line 455 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1549 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 537: /* AposAttrValueContent */
/* Line 455 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1556 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 538: /* DirElemContent */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1563 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 539: /* CommonContent */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1570 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 540: /* DirCommentConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1577 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 541: /* DirPIConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1584 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 542: /* CDataSection */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1591 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 543: /* ComputedConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1598 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 544: /* CompDocConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1605 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 545: /* CompElemConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1612 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 546: /* CompAttrConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1619 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 547: /* CompTextConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1626 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 548: /* CompCommentConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1633 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 549: /* CompPIConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1640 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 550: /* CompNamespaceConstructor */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1647 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 551: /* TypeDeclaration */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1654 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 552: /* SequenceType */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1661 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 553: /* OccurrenceIndicator */
/* Line 455 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1668 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 554: /* ItemType */
/* Line 455 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1675 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 555: /* TypeList */
/* Line 455 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1682 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 556: /* GeneralizedAtomicType */
/* Line 455 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1689 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 557: /* SimpleType */
/* Line 455 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1696 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 558: /* KindTest */
/* Line 455 of lalr1.cc  */
#line 921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1703 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 559: /* AnyKindTest */
/* Line 455 of lalr1.cc  */
#line 917 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1710 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 560: /* DocumentTest */
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1717 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 561: /* NamespaceTest */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1724 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 562: /* TextTest */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1731 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 563: /* CommentTest */
/* Line 455 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1738 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 564: /* PITest */
/* Line 455 of lalr1.cc  */
#line 923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1745 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 565: /* AttributeTest */
/* Line 455 of lalr1.cc  */
#line 918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1752 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 566: /* SchemaAttributeTest */
/* Line 455 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1759 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 567: /* ElementTest */
/* Line 455 of lalr1.cc  */
#line 919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1766 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 568: /* SchemaElementTest */
/* Line 455 of lalr1.cc  */
#line 924 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1773 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 569: /* TypeName */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1780 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 570: /* TypeName_WITH_HOOK */
/* Line 455 of lalr1.cc  */
#line 925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1787 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 571: /* StringLiteral */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1794 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 573: /* AnyFunctionTest */
/* Line 455 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1801 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 574: /* TypedFunctionTest */
/* Line 455 of lalr1.cc  */
#line 928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1808 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 577: /* InsertExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1815 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 578: /* DeleteExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1822 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 579: /* ReplaceExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1829 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 580: /* RenameExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1836 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 581: /* TransformExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1843 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 582: /* VarNameList */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1850 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 583: /* VarNameDecl */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1857 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 584: /* TryExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1864 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 585: /* CatchListExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1871 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 586: /* CatchExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1878 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 587: /* BracedExpr */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 1885 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 588: /* NameTestList */
/* Line 455 of lalr1.cc  */
#line 954 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { delete ((*yyvaluep).name_test_list); };
/* Line 455 of lalr1.cc  */
#line 1892 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 589: /* FTSelection */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1899 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 592: /* FTOr */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1906 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 593: /* FTAnd */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1913 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 594: /* FTMildNot */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1920 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 595: /* FTUnaryNot */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 596: /* FTPrimaryWithOptions */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1934 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 597: /* opt_FTMatchOptions */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1941 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 599: /* FTWeight */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1948 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 600: /* FTPrimary */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1955 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 601: /* opt_FTTimes */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1962 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 602: /* FTExtensionSelection */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1969 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 604: /* FTWords */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1976 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 605: /* FTWordsValue */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1983 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 607: /* FTAnyallOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1990 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 610: /* FTPosFilter */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 1997 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 611: /* FTOrder */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2004 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 612: /* FTWindow */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2011 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 613: /* FTDistance */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2018 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 614: /* FTUnit */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2025 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 615: /* FTMatchOptions */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2032 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 616: /* FTMatchOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2039 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 617: /* FTCaseOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2046 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 618: /* FTDiacriticsOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2053 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 619: /* FTExtensionOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2060 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 620: /* FTStemOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2067 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 621: /* FTThesaurusOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2074 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 625: /* FTThesaurusID */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2081 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 628: /* FTStopWordOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2088 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 629: /* FTStopWords */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2095 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 633: /* FTStopWordsInclExcl */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2102 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 634: /* FTLanguageOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2109 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 635: /* FTWildCardOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2116 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 636: /* FTContent */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2123 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 637: /* FTTimes */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2130 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 638: /* FTRange */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2137 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 639: /* FTScope */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2144 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 640: /* FTBigUnit */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2151 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 641: /* FTIgnoreOption */
/* Line 455 of lalr1.cc  */
#line 940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2158 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 642: /* JSONArrayConstructor */
/* Line 455 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2165 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 643: /* JSONSimpleObjectUnion */
/* Line 455 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2172 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 644: /* JSONAccumulatorObjectUnion */
/* Line 455 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2179 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 645: /* JSONObjectConstructor */
/* Line 455 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2186 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 646: /* JSONPairList */
/* Line 455 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).node) ); };
/* Line 455 of lalr1.cc  */
#line 2193 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 647: /* JSONInsertExpr */
/* Line 455 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2200 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 648: /* JSONAppendExpr */
/* Line 455 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2207 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 649: /* JSONDeleteExpr */
/* Line 455 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2214 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 650: /* JSONRenameExpr */
/* Line 455 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2221 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 651: /* JSONReplaceExpr */
/* Line 455 of lalr1.cc  */
#line 943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2228 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 658: /* QNAME */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2235 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 659: /* FUNCTION_NAME */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2242 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
        break;
      case 660: /* EQNAME */
/* Line 455 of lalr1.cc  */
#line 951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
        { release_hack( ((*yyvaluep).expr) ); };
/* Line 455 of lalr1.cc  */
#line 2249 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
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

    // State.
    int yyn;
    int yylen = 0;
    int yystate = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the lookahead.
    static semantic_type yyval_default;
    semantic_type yylval = yyval_default;
    /// Location of the lookahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location_type yyerror_range[3];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


/* User initialization code.  */
/* Line 545 of lalr1.cc  */
#line 131 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
{
    yylloc.begin.filename = yylloc.end.filename = &(driver.theFilename2);
}
/* Line 545 of lalr1.cc  */
#line 2349 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"

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

    // Compute the default @$.
    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }

    // Perform the reduction.
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
          case 3:
/* Line 670 of lalr1.cc  */
#line 1060 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 4:
/* Line 670 of lalr1.cc  */
#line 1064 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      }
    break;

  case 5:
/* Line 670 of lalr1.cc  */
#line 1068 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      }
    break;

  case 6:
/* Line 670 of lalr1.cc  */
#line 1076 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL;
      }
    break;

  case 7:
/* Line 670 of lalr1.cc  */
#line 1082 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 8:
/* Line 670 of lalr1.cc  */
#line 1086 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.node) = NULL; YYABORT;
      }
    break;

  case 9:
/* Line 670 of lalr1.cc  */
#line 1095 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 10:
/* Line 670 of lalr1.cc  */
#line 1101 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      MainModule* mm = dynamic_cast<MainModule*>((yysemantic_stack_[(2) - (2)].node));
      mm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 11:
/* Line 670 of lalr1.cc  */
#line 1109 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 12:
/* Line 670 of lalr1.cc  */
#line 1115 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      LibraryModule* lm = dynamic_cast<LibraryModule*>((yysemantic_stack_[(2) - (2)].node));
      lm->set_version_decl( static_cast<VersionDecl*>((yysemantic_stack_[(2) - (1)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      driver.set_expr( (yyval.node) );
    }
    break;

  case 13:
/* Line 670 of lalr1.cc  */
#line 1126 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8" );
    }
    break;

  case 14:
/* Line 670 of lalr1.cc  */
#line 1131 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );
    }
    break;

  case 15:
/* Line 670 of lalr1.cc  */
#line 1137 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), "utf-8", VersionDecl::jsoniq );
    }
    break;

  case 16:
/* Line 670 of lalr1.cc  */
#line 1142 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VersionDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)), VersionDecl::jsoniq );
    }
    break;

  case 17:
/* Line 670 of lalr1.cc  */
#line 1151 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (1)].node)), NULL);

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 18:
/* Line 670 of lalr1.cc  */
#line 1158 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (1)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(3) - (3)].expr)), prolog);
    }
    break;

  case 19:
/* Line 670 of lalr1.cc  */
#line 1165 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (1)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (3)].node)));

      (yyval.node) = new MainModule(LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(5) - (5)].expr)), prolog);
    }
    break;

  case 20:
/* Line 670 of lalr1.cc  */
#line 1174 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new MainModule( LOC((yyloc)), static_cast<QueryBody*>((yysemantic_stack_[(1) - (1)].expr)), NULL );
    }
    break;

  case 21:
/* Line 670 of lalr1.cc  */
#line 1181 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 22:
/* Line 670 of lalr1.cc  */
#line 1189 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].expr);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 23:
/* Line 670 of lalr1.cc  */
#line 1197 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (3)]).step();
      error((yylocation_stack_[(5) - (3)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 24:
/* Line 670 of lalr1.cc  */
#line 1205 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(5) - (1)].node); (yyval.node) = (yysemantic_stack_[(5) - (3)].node); (yyval.node) = (yysemantic_stack_[(5) - (5)].expr);
      (yylocation_stack_[(5) - (1)]).step();
      error((yylocation_stack_[(5) - (1)]), "syntax error, missing semicolon \";\" after statement.");
      YYERROR;
    }
    break;

  case 25:
/* Line 670 of lalr1.cc  */
#line 1216 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(1) - (1)].node)), NULL);
    }
    break;

  case 26:
/* Line 670 of lalr1.cc  */
#line 1221 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), static_cast<SIND_DeclList*>((yysemantic_stack_[(3) - (2)].node)), NULL);

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 27:
/* Line 670 of lalr1.cc  */
#line 1228 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)), NULL, static_cast<VFO_DeclList*>((yysemantic_stack_[(3) - (2)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(3) - (1)].node)), prolog);
    }
    break;

  case 28:
/* Line 670 of lalr1.cc  */
#line 1235 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      Prolog* prolog = new Prolog(LOC((yyloc)),
                                  static_cast<SIND_DeclList*>((yysemantic_stack_[(5) - (2)].node)),
                                  static_cast<VFO_DeclList*>((yysemantic_stack_[(5) - (4)].node)));

      (yyval.node) = new LibraryModule(LOC((yyloc)), static_cast<ModuleDecl*>((yysemantic_stack_[(5) - (1)].node)), prolog);
    }
    break;

  case 29:
/* Line 670 of lalr1.cc  */
#line 1247 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (3)].sval)), SYMTAB((yysemantic_stack_[(6) - (5)].sval)) );

      dynamic_cast<ModuleDecl*>((yyval.node))->setComment( SYMTAB((yysemantic_stack_[(6) - (1)].sval)) );
    }
    break;

  case 30:
/* Line 670 of lalr1.cc  */
#line 1257 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SIND_DeclList *sdl = new SIND_DeclList( LOC((yyloc)) );
      sdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = sdl;
    }
    break;

  case 31:
/* Line 670 of lalr1.cc  */
#line 1264 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((SIND_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 32:
/* Line 670 of lalr1.cc  */
#line 1271 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 46:
/* Line 670 of lalr1.cc  */
#line 1306 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::preserve_space);
    }
    break;

  case 47:
/* Line 670 of lalr1.cc  */
#line 1311 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BoundarySpaceDecl(LOC((yyloc)), StaticContextConsts::strip_space);
    }
    break;

  case 48:
/* Line 670 of lalr1.cc  */
#line 1319 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultCollationDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)) );
    }
    break;

  case 49:
/* Line 670 of lalr1.cc  */
#line 1327 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new BaseURIDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 50:
/* Line 670 of lalr1.cc  */
#line 1335 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_preserve);
    }
    break;

  case 51:
/* Line 670 of lalr1.cc  */
#line 1340 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ConstructionDecl(LOC((yyloc)), StaticContextConsts::cons_strip);
    }
    break;

  case 52:
/* Line 670 of lalr1.cc  */
#line 1348 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::ordered);
    }
    break;

  case 53:
/* Line 670 of lalr1.cc  */
#line 1353 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OrderingModeDecl(LOC((yyloc)), StaticContextConsts::unordered);
    }
    break;

  case 54:
/* Line 670 of lalr1.cc  */
#line 1361 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_greatest);
    }
    break;

  case 55:
/* Line 670 of lalr1.cc  */
#line 1366 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new EmptyOrderDecl(LOC((yyloc)), StaticContextConsts::empty_least);
    }
    break;

  case 56:
/* Line 670 of lalr1.cc  */
#line 1374 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, true);
    }
    break;

  case 57:
/* Line 670 of lalr1.cc  */
#line 1379 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), true, false);
    }
    break;

  case 58:
/* Line 670 of lalr1.cc  */
#line 1384 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, true);
    }
    break;

  case 59:
/* Line 670 of lalr1.cc  */
#line 1389 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CopyNamespacesDecl(LOC((yyloc)), false, false);
    }
    break;

  case 62:
/* Line 670 of lalr1.cc  */
#line 1402 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yyval.node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, \"import\" should be followed by either \"schema\" or \"module\".");
      YYERROR;
    }
    break;

  case 63:
/* Line 670 of lalr1.cc  */
#line 1412 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport( LOC((yyloc)), NULL, SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL );
    }
    break;

  case 64:
/* Line 670 of lalr1.cc  */
#line 1417 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(4) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(4) - (4)].sval)),
                            NULL);
    }
    break;

  case 65:
/* Line 670 of lalr1.cc  */
#line 1425 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            NULL,
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 66:
/* Line 670 of lalr1.cc  */
#line 1433 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaImport(LOC((yyloc)),
                            dynamic_cast<SchemaPrefix*>((yysemantic_stack_[(6) - (3)].node)),
                            SYMTAB((yysemantic_stack_[(6) - (4)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 67:
/* Line 670 of lalr1.cc  */
#line 1444 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      URILiteralList *ull = new URILiteralList( LOC((yyloc)));
      ull->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
      (yyval.node) = ull;
    }
    break;

  case 68:
/* Line 670 of lalr1.cc  */
#line 1451 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( URILiteralList *ull = dynamic_cast<URILiteralList*>((yysemantic_stack_[(3) - (1)].node)) )
        ull->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 69:
/* Line 670 of lalr1.cc  */
#line 1462 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 70:
/* Line 670 of lalr1.cc  */
#line 1467 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SchemaPrefix( LOC((yyloc)), true );
    }
    break;

  case 71:
/* Line 670 of lalr1.cc  */
#line 1475 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (2)].sval)));
    }
    break;

  case 72:
/* Line 670 of lalr1.cc  */
#line 1482 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)), SYMTAB((yysemantic_stack_[(6) - (4)].sval)), SYMTAB((yysemantic_stack_[(6) - (6)].sval)), NULL);

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (2)].sval)));
    }
    break;

  case 73:
/* Line 670 of lalr1.cc  */
#line 1489 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(5) - (3)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(5) - (5)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (2)].sval)));
    }
    break;

  case 74:
/* Line 670 of lalr1.cc  */
#line 1498 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ModuleImport(LOC((yyloc)),
                            SYMTAB((yysemantic_stack_[(8) - (4)].sval)),
                            SYMTAB((yysemantic_stack_[(8) - (6)].sval)),
                            dynamic_cast<URILiteralList*>((yysemantic_stack_[(8) - (8)].node)));

      dynamic_cast<ModuleImport *>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(8) - (2)].sval)));
    }
    break;

  case 75:
/* Line 670 of lalr1.cc  */
#line 1511 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceDecl( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)), SYMTAB((yysemantic_stack_[(5) - (5)].sval)) );
    }
    break;

  case 76:
/* Line 670 of lalr1.cc  */
#line 1519 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_element_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 77:
/* Line 670 of lalr1.cc  */
#line 1526 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DefaultNamespaceDecl(LOC((yyloc)),
                                    ParseConstants::ns_function_default,
                                    SYMTAB((yysemantic_stack_[(5) - (5)].sval)));
    }
    break;

  case 78:
/* Line 670 of lalr1.cc  */
#line 1536 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VFO_DeclList *vdl = new VFO_DeclList( LOC((yyloc)));
      vdl->push_back( (yysemantic_stack_[(1) - (1)].node) );
      (yyval.node) = vdl;
    }
    break;

  case 79:
/* Line 670 of lalr1.cc  */
#line 1543 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ((VFO_DeclList*)(yysemantic_stack_[(3) - (1)].node))->push_back( (yysemantic_stack_[(3) - (3)].node) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 80:
/* Line 670 of lalr1.cc  */
#line 1550 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node); (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      (yylocation_stack_[(3) - (1)]).step();
      error((yylocation_stack_[(3) - (1)]), "syntax error, missing semicolon \";\" after declaration.");
      YYERROR;
    }
    break;

  case 89:
/* Line 670 of lalr1.cc  */
#line 1573 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 90:
/* Line 670 of lalr1.cc  */
#line 1579 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DecimalFormatNode(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), (yysemantic_stack_[(4) - (4)].vstrpair));
      delete (yysemantic_stack_[(4) - (4)].vstrpair);
    }
    break;

  case 91:
/* Line 670 of lalr1.cc  */
#line 1588 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.vstrpair) = new vector<string_pair_t>();
      (yyval.vstrpair)->push_back( *(yysemantic_stack_[(1) - (1)].strpair) );
      delete (yysemantic_stack_[(1) - (1)].strpair);
    }
    break;

  case 92:
/* Line 670 of lalr1.cc  */
#line 1595 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yysemantic_stack_[(2) - (1)].vstrpair)->push_back( *(yysemantic_stack_[(2) - (2)].strpair) );
      delete (yysemantic_stack_[(2) - (2)].strpair);
      (yyval.vstrpair) = (yysemantic_stack_[(2) - (1)].vstrpair);
    }
    break;

  case 93:
/* Line 670 of lalr1.cc  */
#line 1605 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      StringLiteral *sl = static_cast<StringLiteral*>((yysemantic_stack_[(3) - (3)].expr));
      (yyval.strpair) = new string_pair_t( (yysemantic_stack_[(3) - (1)].strval), sl->get_strval().str() );
      delete sl;
    }
    break;

  case 94:
/* Line 670 of lalr1.cc  */
#line 1614 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "decimal-separator"; }
    break;

  case 95:
/* Line 670 of lalr1.cc  */
#line 1615 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "digit"; }
    break;

  case 96:
/* Line 670 of lalr1.cc  */
#line 1616 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "grouping-separator"; }
    break;

  case 97:
/* Line 670 of lalr1.cc  */
#line 1617 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "infinity"; }
    break;

  case 98:
/* Line 670 of lalr1.cc  */
#line 1618 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "minus-sign"; }
    break;

  case 99:
/* Line 670 of lalr1.cc  */
#line 1619 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "NaN"; }
    break;

  case 100:
/* Line 670 of lalr1.cc  */
#line 1620 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "pattern-separator"; }
    break;

  case 101:
/* Line 670 of lalr1.cc  */
#line 1621 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "percent"; }
    break;

  case 102:
/* Line 670 of lalr1.cc  */
#line 1622 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "per-mille"; }
    break;

  case 103:
/* Line 670 of lalr1.cc  */
#line 1623 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.strval) = "zero-digit"; }
    break;

  case 104:
/* Line 670 of lalr1.cc  */
#line 1629 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new OptionDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), SYMTAB((yysemantic_stack_[(4) - (4)].sval)));
    }
    break;

  case 105:
/* Line 670 of lalr1.cc  */
#line 1637 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTOptionDecl( LOC((yyloc)), dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (3)].node)) );
    }
    break;

  case 106:
/* Line 670 of lalr1.cc  */
#line 1645 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(4) - (4)].node);
    }
    break;

  case 107:
/* Line 670 of lalr1.cc  */
#line 1653 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(3) - (3)].node));
      d->theType = (yysemantic_stack_[(3) - (2)].node);
      (yyval.node) = d;
    }
    break;

  case 108:
/* Line 670 of lalr1.cc  */
#line 1660 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 109:
/* Line 670 of lalr1.cc  */
#line 1668 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CtxItemDecl* d = dynamic_cast<CtxItemDecl*>((yysemantic_stack_[(1) - (1)].node));
      d->theIsExternal = false;
      (yyval.node) = d;
    }
    break;

  case 110:
/* Line 670 of lalr1.cc  */
#line 1675 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), NULL);
    }
    break;

  case 111:
/* Line 670 of lalr1.cc  */
#line 1680 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 112:
/* Line 670 of lalr1.cc  */
#line 1688 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CtxItemDecl(LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 113:
/* Line 670 of lalr1.cc  */
#line 1696 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(4) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(4) - (4)].expr),
                             nt->get_annotations(),
                             false);

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 114:
/* Line 670 of lalr1.cc  */
#line 1710 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(3) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             NULL,
                             nt->get_annotations(),
                             true);

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 115:
/* Line 670 of lalr1.cc  */
#line 1724 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      std::auto_ptr<VarNameAndType> nt(dynamic_cast<VarNameAndType *>((yysemantic_stack_[(5) - (2)].varnametype)));

      (yyval.node) = new GlobalVarDecl(LOC((yyloc)),
                             nt->theName,
                             nt->theType,
                             (yysemantic_stack_[(5) - (5)].expr),
                             nt->get_annotations(),
                             true);

      static_cast<GlobalVarDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 116:
/* Line 670 of lalr1.cc  */
#line 1741 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL, NULL);
    }
    break;

  case 117:
/* Line 670 of lalr1.cc  */
#line 1746 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (4)].node)),
                              NULL);
    }
    break;

  case 118:
/* Line 670 of lalr1.cc  */
#line 1754 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                              NULL,
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (1)].node)));
    }
    break;

  case 119:
/* Line 670 of lalr1.cc  */
#line 1762 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.varnametype) = new VarNameAndType(LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (4)].expr)),
                              dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)),
                              static_cast<AnnotationListParsenode*>((yysemantic_stack_[(5) - (1)].node)));
    }
    break;

  case 120:
/* Line 670 of lalr1.cc  */
#line 1773 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationListParsenode(LOC((yyloc)), static_cast<AnnotationParsenode*>((yysemantic_stack_[(1) - (1)].node)));
    }
    break;

  case 121:
/* Line 670 of lalr1.cc  */
#line 1778 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationListParsenode*>((yysemantic_stack_[(2) - (1)].node))->push_back(static_cast<AnnotationParsenode*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 122:
/* Line 670 of lalr1.cc  */
#line 1787 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))), NULL);
    }
    break;

  case 123:
/* Line 670 of lalr1.cc  */
#line 1792 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval))),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 124:
/* Line 670 of lalr1.cc  */
#line 1799 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true), NULL);
    }
    break;

  case 125:
/* Line 670 of lalr1.cc  */
#line 1804 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationParsenode(LOC((yyloc)),
                                   new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (1)].sval)), true),
                                   static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 126:
/* Line 670 of lalr1.cc  */
#line 1814 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnnotationLiteralListParsenode(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr));
    }
    break;

  case 127:
/* Line 670 of lalr1.cc  */
#line 1819 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<AnnotationLiteralListParsenode*>((yysemantic_stack_[(3) - (1)].node))->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 128:
/* Line 670 of lalr1.cc  */
#line 1828 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      static_cast<FunctionDecl*>((yysemantic_stack_[(2) - (2)].node))->setComment( SYMTAB((yysemantic_stack_[(2) - (1)].sval)) );
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 129:
/* Line 670 of lalr1.cc  */
#line 1834 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      FunctionDecl* fdecl = static_cast<FunctionDecl*>((yysemantic_stack_[(3) - (3)].node));

      fdecl->setComment( SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );

      fdecl->set_annotations(static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
    }
    break;

  case 130:
/* Line 670 of lalr1.cc  */
#line 1847 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 131:
/* Line 670 of lalr1.cc  */
#line 1852 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 132:
/* Line 670 of lalr1.cc  */
#line 1860 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theParams,
                            &* (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType,
                            (yysemantic_stack_[(4) - (4)].expr),
                            false,
                            false);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 133:
/* Line 670 of lalr1.cc  */
#line 1871 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(4) - (3)].fnsig)->theReturnType.getp(),
                            NULL,
                            false,
                            true);
      delete (yysemantic_stack_[(4) - (3)].fnsig);
    }
    break;

  case 134:
/* Line 670 of lalr1.cc  */
#line 1886 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC ((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            (yysemantic_stack_[(5) - (5)].expr),
                            true,
                            false);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 135:
/* Line 670 of lalr1.cc  */
#line 1898 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FunctionDecl(LOC((yyloc)),
                            static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theParams.getp(),
                            (yysemantic_stack_[(5) - (4)].fnsig)->theReturnType.getp(),
                            NULL,
                            true,
                            true);
      delete (yysemantic_stack_[(5) - (4)].fnsig);
    }
    break;

  case 136:
/* Line 670 of lalr1.cc  */
#line 1913 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL);
    }
    break;

  case 137:
/* Line 670 of lalr1.cc  */
#line 1918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 138:
/* Line 670 of lalr1.cc  */
#line 1923 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(NULL, dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node)));
    }
    break;

  case 139:
/* Line 670 of lalr1.cc  */
#line 1928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.fnsig) = new FunctionSig(dynamic_cast<ParamList*>((yysemantic_stack_[(5) - (2)].node)), dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 140:
/* Line 670 of lalr1.cc  */
#line 1936 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ParamList *pl = new ParamList( LOC((yyloc)) );
      pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = pl;
    }
    break;

  case 141:
/* Line 670 of lalr1.cc  */
#line 1943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ParamList *pl = dynamic_cast<ParamList*>((yysemantic_stack_[(3) - (1)].node)) )
        pl->push_back( dynamic_cast<Param*>((yysemantic_stack_[(3) - (3)].node)) );

      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 142:
/* Line 670 of lalr1.cc  */
#line 1954 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL);
    }
    break;

  case 143:
/* Line 670 of lalr1.cc  */
#line 1959 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Param(LOC((yyloc)),
                     static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                     dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 144:
/* Line 670 of lalr1.cc  */
#line 1969 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)),
                              NULL,
                              NULL);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(3) - (1)].sval)));
    }
    break;

  case 145:
/* Line 670 of lalr1.cc  */
#line 1978 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                              static_cast<QName*>((yysemantic_stack_[(5) - (3)].expr)),
                              0,
                              static_cast<SequenceType*>((yysemantic_stack_[(5) - (5)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(5) - (1)].sval)));
    }
    break;

  case 146:
/* Line 670 of lalr1.cc  */
#line 1987 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(4) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(4) - (2)].node)),
                               0);

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(4) - (1)].sval)));
    }
    break;

  case 147:
/* Line 670 of lalr1.cc  */
#line 1996 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CollectionDecl( LOC((yyloc)),
                               static_cast<QName*>((yysemantic_stack_[(6) - (4)].expr)),
                               static_cast<AnnotationListParsenode*>((yysemantic_stack_[(6) - (2)].node)),
                               static_cast<SequenceType*>((yysemantic_stack_[(6) - (6)].node)));

      static_cast<CollectionDecl*>((yyval.node))->setComment(SYMTAB((yysemantic_stack_[(6) - (1)].sval)));
    }
    break;

  case 148:
/* Line 670 of lalr1.cc  */
#line 2008 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 149:
/* Line 670 of lalr1.cc  */
#line 2012 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));
    }
    break;

  case 150:
/* Line 670 of lalr1.cc  */
#line 2018 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL));
    }
    break;

  case 151:
/* Line 670 of lalr1.cc  */
#line 2022 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = static_cast<parsenode*>(new SequenceType(LOC((yyloc)),
                                                    (yysemantic_stack_[(2) - (1)].node),
                                                    dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node))));

    }
    break;

  case 152:
/* Line 670 of lalr1.cc  */
#line 2032 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2042 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2055 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      IndexKeyList* keyList = new IndexKeyList(LOC((yyloc)));
      keyList->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = keyList;
    }
    break;

  case 155:
/* Line 670 of lalr1.cc  */
#line 2061 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      dynamic_cast<IndexKeyList*>((yysemantic_stack_[(3) - (1)].node))->addKeySpec(dynamic_cast<IndexKeySpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 156:
/* Line 670 of lalr1.cc  */
#line 2070 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL, NULL);
    }
    break;

  case 157:
/* Line 670 of lalr1.cc  */
#line 2075 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(2) - (2)].node)),
                            NULL);
    }
    break;

  case 158:
/* Line 670 of lalr1.cc  */
#line 2082 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(2) - (1)].expr),
                            NULL,
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(2) - (2)].node)));
    }
    break;

  case 159:
/* Line 670 of lalr1.cc  */
#line 2089 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new IndexKeySpec(LOC((yyloc)),
                            (yysemantic_stack_[(3) - (1)].expr),
                            dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (2)].node)),
                            dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 160:
/* Line 670 of lalr1.cc  */
#line 2101 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollSimpleCheck(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(11) - (9)].expr)),
                                 (yysemantic_stack_[(11) - (11)].expr));
    }
    break;

  case 161:
/* Line 670 of lalr1.cc  */
#line 2111 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollUniqueKeyCheck(LOC((yyloc)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (4)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (7)].expr)),
                                    static_cast<QName*>((yysemantic_stack_[(14) - (10)].expr)),
                                    (yysemantic_stack_[(14) - (14)].expr));
    }
    break;

  case 162:
/* Line 670 of lalr1.cc  */
#line 2121 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ICCollForeachNode(LOC((yyloc)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (4)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (7)].expr)),
                                 static_cast<QName*>((yysemantic_stack_[(13) - (11)].expr)),
                                 (yysemantic_stack_[(13) - (13)].expr));
    }
    break;

  case 163:
/* Line 670 of lalr1.cc  */
#line 2132 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2148 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2168 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 166:
/* Line 670 of lalr1.cc  */
#line 2172 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 167:
/* Line 670 of lalr1.cc  */
#line 2176 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = NULL;
    }
    break;

  case 168:
/* Line 670 of lalr1.cc  */
#line 2184 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 169:
/* Line 670 of lalr1.cc  */
#line 2188 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 170:
/* Line 670 of lalr1.cc  */
#line 2192 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 171:
/* Line 670 of lalr1.cc  */
#line 2200 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 172:
/* Line 670 of lalr1.cc  */
#line 2205 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 173:
/* Line 670 of lalr1.cc  */
#line 2217 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = new BlockBody(LOC((yyloc)));
      blk->add((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = blk;
    }
    break;

  case 174:
/* Line 670 of lalr1.cc  */
#line 2224 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* blk = static_cast<BlockBody*>((yysemantic_stack_[(2) - (1)].expr));

      blk->add((yysemantic_stack_[(2) - (2)].expr));

      (yyval.expr) = blk;
    }
    break;

  case 175:
/* Line 670 of lalr1.cc  */
#line 2234 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(4) - (1)].expr);
      (yyval.expr) = (yysemantic_stack_[(4) - (2)].expr);
      (yyval.expr) = (yysemantic_stack_[(4) - (4)].expr);
      error((yylocation_stack_[(4) - (3)]), "syntax error, unexpected statement (missing semicolon \";\" between statements?)");
      delete (yysemantic_stack_[(4) - (1)].expr);
      delete (yysemantic_stack_[(4) - (2)].expr);
      delete (yysemantic_stack_[(4) - (4)].expr);
      YYERROR;
    }
    break;

  case 189:
/* Line 670 of lalr1.cc  */
#line 2269 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 190:
/* Line 670 of lalr1.cc  */
#line 2284 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      BlockBody* block = dynamic_cast<BlockBody*>((yysemantic_stack_[(3) - (2)].expr));

      if ((yysemantic_stack_[(3) - (2)].expr) == NULL || (block != NULL && block->isEmpty()))
      {
        (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)));
      }
      else

      if (block == NULL)
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
/* Line 670 of lalr1.cc  */
#line 2309 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 192:
/* Line 670 of lalr1.cc  */
#line 2317 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 193:
/* Line 670 of lalr1.cc  */
#line 2325 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = static_cast<VarDeclStmt*>((yysemantic_stack_[(3) - (1)].expr));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 194:
/* Line 670 of lalr1.cc  */
#line 2332 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)), NULL);
      vdecl->add((yysemantic_stack_[(2) - (2)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 195:
/* Line 670 of lalr1.cc  */
#line 2339 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarDeclStmt* vdecl = new VarDeclStmt(LOC((yyloc)),
                                           static_cast<AnnotationListParsenode*>((yysemantic_stack_[(3) - (1)].node)));
      vdecl->add((yysemantic_stack_[(3) - (3)].node));
      (yyval.expr) = vdecl;
    }
    break;

  case 196:
/* Line 670 of lalr1.cc  */
#line 2350 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)),
                                          NULL,
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 197:
/* Line 670 of lalr1.cc  */
#line 2359 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)),
                                          NULL,
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 198:
/* Line 670 of lalr1.cc  */
#line 2368 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                          NULL,
                                          (yysemantic_stack_[(4) - (4)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 199:
/* Line 670 of lalr1.cc  */
#line 2377 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      LocalVarDecl* vd = new LocalVarDecl(LOC((yyloc)),
                                          static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                          dynamic_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                                          (yysemantic_stack_[(5) - (5)].expr),
                                          NULL);
      (yyval.node) = vd;
    }
    break;

  case 200:
/* Line 670 of lalr1.cc  */
#line 2390 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new AssignExpr(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)), (yysemantic_stack_[(5) - (4)].expr));
    }
    break;

  case 201:
/* Line 670 of lalr1.cc  */
#line 2398 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ApplyExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr));
    }
    break;

  case 202:
/* Line 670 of lalr1.cc  */
#line 2406 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ExitExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr));
    }
    break;

  case 203:
/* Line 670 of lalr1.cc  */
#line 2414 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2429 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement(LOC((yyloc)), FlowCtlStatement::BREAK);
    }
    break;

  case 205:
/* Line 670 of lalr1.cc  */
#line 2434 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FlowCtlStatement( LOC((yyloc)), FlowCtlStatement::CONTINUE );
    }
    break;

  case 206:
/* Line 670 of lalr1.cc  */
#line 2442 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2456 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2473 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2498 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TryExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 210:
/* Line 670 of lalr1.cc  */
#line 2506 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr* cle = new CatchListExpr( LOC((yyloc)) );
      cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.expr) = cle;
    }
    break;

  case 211:
/* Line 670 of lalr1.cc  */
#line 2513 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
      if ( cle )
        cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
    }
    break;

  case 212:
/* Line 670 of lalr1.cc  */
#line 2524 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 213:
/* Line 670 of lalr1.cc  */
#line 2534 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new BlockBody(LOC((yyloc)));
    }
    break;

  case 214:
/* Line 670 of lalr1.cc  */
#line 2543 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 215:
/* Line 670 of lalr1.cc  */
#line 2548 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2561 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (1)].expr);
      (yyval.expr) = (yysemantic_stack_[(3) - (3)].expr);



      if (dynamic_cast<PathExpr*>((yysemantic_stack_[(3) - (1)].expr)) == NULL)
        error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected expression (missing comma \",\" between expressions?)");
      delete (yysemantic_stack_[(3) - (1)].expr);
      delete (yysemantic_stack_[(3) - (3)].expr);
      YYERROR;
    }
    break;

  case 235:
/* Line 670 of lalr1.cc  */
#line 2608 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2622 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new ReturnExpr( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].expr) );
    }
    break;

  case 237:
/* Line 670 of lalr1.cc  */
#line 2630 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_sliding;
    }
    break;

  case 238:
/* Line 670 of lalr1.cc  */
#line 2635 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_tumbling;
    }
    break;

  case 239:
/* Line 670 of lalr1.cc  */
#line 2643 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_start;
    }
    break;

  case 240:
/* Line 670 of lalr1.cc  */
#line 2648 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.strval) = parser::the_end;
    }
    break;

  case 241:
/* Line 670 of lalr1.cc  */
#line 2653 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
    (yyval.strval) = parser::the_only_end;
  }
    break;

  case 242:
/* Line 670 of lalr1.cc  */
#line 2661 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            dynamic_cast<WindowVars*>((yysemantic_stack_[(4) - (2)].node)),
                            (yysemantic_stack_[(4) - (4)].expr),
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(4) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 243:
/* Line 670 of lalr1.cc  */
#line 2670 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FLWORWinCond(LOC((yyloc)),
                            NULL,
                            (yysemantic_stack_[(3) - (3)].expr),
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_start,
                            (yysemantic_stack_[(3) - (1)].strval) == parser::the_only_end);
    }
    break;

  case 244:
/* Line 670 of lalr1.cc  */
#line 2687 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2703 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2716 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CountClause(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 255:
/* Line 670 of lalr1.cc  */
#line 2740 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = new FLWORClauseList( LOC((yyloc)) );
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 256:
/* Line 670 of lalr1.cc  */
#line 2747 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      FLWORClauseList *fcl = dynamic_cast<FLWORClauseList*>((yysemantic_stack_[(2) - (1)].node));
      fcl->push_back( dynamic_cast<FLWORClause*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = fcl;
    }
    break;

  case 257:
/* Line 670 of lalr1.cc  */
#line 2762 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new ForClause(LOC((yyloc)), dynamic_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 258:
/* Line 670 of lalr1.cc  */
#line 2773 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      error((yylocation_stack_[(3) - (2)]), "syntax error, unexpected qualified name \""
          + static_cast<VarInDeclList*>((yysemantic_stack_[(3) - (3)].node))->operator[](0)->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (3)].node);
      YYERROR;
    }
    break;

  case 259:
/* Line 670 of lalr1.cc  */
#line 2787 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = NULL;
      error((yylocation_stack_[(2) - (2)]), "");
      YYERROR;
    }
    break;

  case 261:
/* Line 670 of lalr1.cc  */
#line 2799 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

    }
    break;

  case 262:
/* Line 670 of lalr1.cc  */
#line 2808 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      VarInDeclList* vdl = new VarInDeclList( LOC((yyloc)) );
      vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = vdl;
    }
    break;

  case 263:
/* Line 670 of lalr1.cc  */
#line 2815 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( VarInDeclList* vdl = dynamic_cast<VarInDeclList*>((yysemantic_stack_[(4) - (1)].node)) )
        vdl->push_back( dynamic_cast<VarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 264:
/* Line 670 of lalr1.cc  */
#line 2823 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
      error((yylocation_stack_[(3) - (3)]), "syntax error, unexpected QName \""
          + static_cast<VarInDecl*>((yysemantic_stack_[(3) - (3)].node))->get_var_name()->get_qname().str() + "\" (missing \"$\" sign?)");
      delete (yysemantic_stack_[(3) - (1)].node);
      YYERROR;
    }
    break;

  case 265:
/* Line 670 of lalr1.cc  */
#line 2835 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2845 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2855 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2865 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2875 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2885 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2895 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2905 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2916 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2925 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2935 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2945 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 2961 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new PositionalVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 278:
/* Line 670 of lalr1.cc  */
#line 2970 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new FTScoreVar(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 279:
/* Line 670 of lalr1.cc  */
#line 2979 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new LetClause( LOC((yyloc)), dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(2) - (2)].node)) );
        }
    break;

  case 280:
/* Line 670 of lalr1.cc  */
#line 2987 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            VarGetsDeclList *vgdl = new VarGetsDeclList( LOC((yyloc)) );
            vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = vgdl;
        }
    break;

  case 281:
/* Line 670 of lalr1.cc  */
#line 2993 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if( VarGetsDeclList *vgdl = dynamic_cast<VarGetsDeclList*>((yysemantic_stack_[(3) - (1)].node)) )
                vgdl->push_back( dynamic_cast<VarGetsDecl*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 282:
/* Line 670 of lalr1.cc  */
#line 3005 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                           NULL,
                           NULL,
                           (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 283:
/* Line 670 of lalr1.cc  */
#line 3013 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                           NULL,
                           (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 284:
/* Line 670 of lalr1.cc  */
#line 3023 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node))->get_var_name(),
                           NULL,
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(3) - (1)].node)),
                           (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 285:
/* Line 670 of lalr1.cc  */
#line 3031 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new VarGetsDecl(LOC ((yyloc)),
                           static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                           dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (3)].node)),
                           dynamic_cast<FTScoreVar*>((yysemantic_stack_[(6) - (4)].node)),
                           (yysemantic_stack_[(6) - (6)].expr));
    }
    break;

  case 286:
/* Line 670 of lalr1.cc  */
#line 3043 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                             NULL, (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 287:
/* Line 670 of lalr1.cc  */
#line 3049 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVarDecl(LOC ((yyloc)),
                             static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                             dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (3)].node)),
                             (yysemantic_stack_[(5) - (5)].expr));
    }
    break;

  case 289:
/* Line 670 of lalr1.cc  */
#line 3062 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL);
    }
    break;

  case 290:
/* Line 670 of lalr1.cc  */
#line 3066 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(3) - (3)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_curr(static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 291:
/* Line 670 of lalr1.cc  */
#line 3074 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), dynamic_cast<PositionalVar*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL, NULL);
    }
    break;

  case 292:
/* Line 670 of lalr1.cc  */
#line 3078 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
      dynamic_cast<WindowVars *>((yyval.node))->set_posvar(dynamic_cast<PositionalVar*>((yysemantic_stack_[(2) - (1)].node)));
    }
    break;

  case 294:
/* Line 670 of lalr1.cc  */
#line 3087 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), static_cast<QName*>((yysemantic_stack_[(6) - (6)].expr)));
    }
    break;

  case 295:
/* Line 670 of lalr1.cc  */
#line 3091 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)));
    }
    break;

  case 296:
/* Line 670 of lalr1.cc  */
#line 3095 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WindowVars(LOC((yyloc)), NULL, NULL, static_cast<QName*>((yysemantic_stack_[(3) - (3)].expr)), NULL);
    }
    break;

  case 297:
/* Line 670 of lalr1.cc  */
#line 3105 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new WhereClause(LOC ((yyloc)), (yysemantic_stack_[(2) - (2)].expr));
    }
    break;

  case 298:
/* Line 670 of lalr1.cc  */
#line 3113 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupByClause(LOC((yyloc)), dynamic_cast<GroupSpecList*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 299:
/* Line 670 of lalr1.cc  */
#line 3120 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = new GroupSpecList(LOC((yyloc)));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 300:
/* Line 670 of lalr1.cc  */
#line 3126 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      GroupSpecList* gsl = static_cast<GroupSpecList*>((yysemantic_stack_[(3) - (1)].node));
      gsl->push_back(static_cast<GroupSpec*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = gsl;
    }
    break;

  case 301:
/* Line 670 of lalr1.cc  */
#line 3136 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)), NULL, NULL, NULL);
    }
    break;

  case 302:
/* Line 670 of lalr1.cc  */
#line 3140 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)), NULL, (yysemantic_stack_[(4) - (4)].expr), NULL);
    }
    break;

  case 303:
/* Line 670 of lalr1.cc  */
#line 3144 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(5) - (3)].node)),
                         (yysemantic_stack_[(5) - (5)].expr),
                         NULL);
    }
    break;

  case 304:
/* Line 670 of lalr1.cc  */
#line 3152 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                         static_cast<SequenceType*>((yysemantic_stack_[(6) - (3)].node)),
                         (yysemantic_stack_[(6) - (5)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 305:
/* Line 670 of lalr1.cc  */
#line 3160 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                         NULL,
                         (yysemantic_stack_[(5) - (4)].expr),
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(5) - (5)].node)));
    }
    break;

  case 306:
/* Line 670 of lalr1.cc  */
#line 3168 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupSpec(LOC((yyloc)),
                         static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)),
                         NULL,
                         NULL,
                         static_cast<GroupCollationSpec*>((yysemantic_stack_[(3) - (3)].node)));
    }
    break;

  case 307:
/* Line 670 of lalr1.cc  */
#line 3180 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GroupCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 308:
/* Line 670 of lalr1.cc  */
#line 3188 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 309:
/* Line 670 of lalr1.cc  */
#line 3194 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderByClause(
                LOC((yyloc)), dynamic_cast<OrderSpecList*>((yysemantic_stack_[(4) - (4)].node)), true
            );
        }
    break;

  case 310:
/* Line 670 of lalr1.cc  */
#line 3204 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            OrderSpecList *osl = new OrderSpecList( LOC((yyloc)) );
            osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = osl;
        }
    break;

  case 311:
/* Line 670 of lalr1.cc  */
#line 3210 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( OrderSpecList* osl = dynamic_cast<OrderSpecList*>((yysemantic_stack_[(3) - (1)].node)) )
                osl->push_back( dynamic_cast<OrderSpec*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 312:
/* Line 670 of lalr1.cc  */
#line 3220 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr), NULL );
        }
    break;

  case 313:
/* Line 670 of lalr1.cc  */
#line 3224 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderSpec(
                LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<OrderModifierPN*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 314:
/* Line 670 of lalr1.cc  */
#line 3234 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), dynamic_cast<OrderDirSpec*>((yysemantic_stack_[(1) - (1)].node)), NULL, NULL
            );
        }
    break;

  case 315:
/* Line 670 of lalr1.cc  */
#line 3240 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, dynamic_cast<OrderEmptySpec*>((yysemantic_stack_[(1) - (1)].node)), NULL
            );
        }
    break;

  case 316:
/* Line 670 of lalr1.cc  */
#line 3246 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderModifierPN(
                LOC((yyloc)), NULL, NULL, dynamic_cast<OrderCollationSpec*>((yysemantic_stack_[(1) - (1)].node))
            );
        }
    break;

  case 317:
/* Line 670 of lalr1.cc  */
#line 3252 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 3261 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 3270 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 3279 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 3292 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_ascending );
        }
    break;

  case 322:
/* Line 670 of lalr1.cc  */
#line 3296 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderDirSpec( LOC((yyloc)), ParseConstants::dir_descending );
        }
    break;

  case 323:
/* Line 670 of lalr1.cc  */
#line 3304 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_greatest
            );
        }
    break;

  case 324:
/* Line 670 of lalr1.cc  */
#line 3310 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderEmptySpec(
                LOC((yyloc)), StaticContextConsts::empty_least
            );
        }
    break;

  case 325:
/* Line 670 of lalr1.cc  */
#line 3320 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OrderCollationSpec( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 326:
/* Line 670 of lalr1.cc  */
#line 3328 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 3337 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 3350 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = new QVarInDeclList( LOC((yyloc)) );
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qvidl;

    }
    break;

  case 329:
/* Line 670 of lalr1.cc  */
#line 3357 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QVarInDeclList *qvidl = dynamic_cast<QVarInDeclList*>((yysemantic_stack_[(4) - (1)].node));
      qvidl->push_back( dynamic_cast<QVarInDecl*>((yysemantic_stack_[(4) - (4)].node)) );
      (yyval.node) = (yysemantic_stack_[(4) - (1)].node);
    }
    break;

  case 330:
/* Line 670 of lalr1.cc  */
#line 3369 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 331:
/* Line 670 of lalr1.cc  */
#line 3373 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QVarInDecl(LOC((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(4) - (1)].expr)),
                          dynamic_cast<SequenceType *>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 332:
/* Line 670 of lalr1.cc  */
#line 3385 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 333:
/* Line 670 of lalr1.cc  */
#line 3392 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 334:
/* Line 670 of lalr1.cc  */
#line 3398 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 335:
/* Line 670 of lalr1.cc  */
#line 3407 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 336:
/* Line 670 of lalr1.cc  */
#line 3414 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = new SwitchCaseOperandList(LOC((yyloc)));
      sco_list_p->push_back((yysemantic_stack_[(2) - (2)].expr));
      (yyval.node) = sco_list_p;
    }
    break;

  case 337:
/* Line 670 of lalr1.cc  */
#line 3420 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseOperandList* sco_list_p = static_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node));
      sco_list_p->push_back((yysemantic_stack_[(3) - (3)].expr));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 338:
/* Line 670 of lalr1.cc  */
#line 3431 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new SwitchExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(8) - (5)].node)), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 339:
/* Line 670 of lalr1.cc  */
#line 3438 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = new SwitchCaseClauseList(LOC((yyloc)));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = scc_list_p;
    }
    break;

  case 340:
/* Line 670 of lalr1.cc  */
#line 3444 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SwitchCaseClauseList* scc_list_p = static_cast<SwitchCaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      scc_list_p->push_back(static_cast<SwitchCaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 341:
/* Line 670 of lalr1.cc  */
#line 3453 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SwitchCaseClause(LOC((yyloc)), dynamic_cast<SwitchCaseOperandList*>((yysemantic_stack_[(3) - (1)].node)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 342:
/* Line 670 of lalr1.cc  */
#line 3462 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 343:
/* Line 670 of lalr1.cc  */
#line 3469 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 344:
/* Line 670 of lalr1.cc  */
#line 3480 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC((yyloc)),
                              (yysemantic_stack_[(8) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(8) - (5)].node)),
                              (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 345:
/* Line 670 of lalr1.cc  */
#line 3487 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new TypeswitchExpr(LOC ((yyloc)),
                              (yysemantic_stack_[(10) - (3)].expr),
                              static_cast<CaseClauseList*>((yysemantic_stack_[(10) - (5)].node)),
                              static_cast<QName*>((yysemantic_stack_[(10) - (8)].expr)),
                              (yysemantic_stack_[(10) - (10)].expr));
    }
    break;

  case 346:
/* Line 670 of lalr1.cc  */
#line 3499 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 347:
/* Line 670 of lalr1.cc  */
#line 3505 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = dynamic_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 348:
/* Line 670 of lalr1.cc  */
#line 3517 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 349:
/* Line 670 of lalr1.cc  */
#line 3523 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 350:
/* Line 670 of lalr1.cc  */
#line 3534 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = new CaseClauseList(LOC ((yyloc)));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = cc_list_p;
    }
    break;

  case 351:
/* Line 670 of lalr1.cc  */
#line 3540 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CaseClauseList* cc_list_p = static_cast<CaseClauseList*>((yysemantic_stack_[(2) - (1)].node));
      cc_list_p->push_back(static_cast<CaseClause*>((yysemantic_stack_[(2) - (2)].node)));
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 352:
/* Line 670 of lalr1.cc  */
#line 3551 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(4) - (2)].node)),
                          (yysemantic_stack_[(4) - (4)].expr));
    }
    break;

  case 353:
/* Line 670 of lalr1.cc  */
#line 3557 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CaseClause(LOC ((yyloc)),
                          static_cast<QName*>((yysemantic_stack_[(7) - (3)].expr)),
                          static_cast<SequenceTypeList*>((yysemantic_stack_[(7) - (5)].node)),
                          (yysemantic_stack_[(7) - (7)].expr));
     }
    break;

  case 354:
/* Line 670 of lalr1.cc  */
#line 3568 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = new SequenceTypeList(LOC((yyloc)));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(1) - (1)].node)));
      (yyval.node) = seqList;
    }
    break;

  case 355:
/* Line 670 of lalr1.cc  */
#line 3574 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      SequenceTypeList* seqList = static_cast<SequenceTypeList*>((yysemantic_stack_[(3) - (1)].node));
      seqList->push_back(static_cast<SequenceType*>((yysemantic_stack_[(3) - (3)].node)));
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 356:
/* Line 670 of lalr1.cc  */
#line 3585 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new IfExpr(LOC ((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (6)].expr), (yysemantic_stack_[(8) - (8)].expr));
    }
    break;

  case 357:
/* Line 670 of lalr1.cc  */
#line 3594 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 358:
/* Line 670 of lalr1.cc  */
#line 3598 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new OrExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
    }
    break;

  case 359:
/* Line 670 of lalr1.cc  */
#line 3611 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 360:
/* Line 670 of lalr1.cc  */
#line 3620 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AndExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 361:
/* Line 670 of lalr1.cc  */
#line 3629 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 362:
/* Line 670 of lalr1.cc  */
#line 3633 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 3648 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 364:
/* Line 670 of lalr1.cc  */
#line 3652 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

            (yyval.expr) = new ComparisonExpr(
                LOC((yyloc)),
                dynamic_cast<ValueComp*>((yysemantic_stack_[(3) - (2)].node)),
                (yysemantic_stack_[(3) - (1)].expr),
                (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 365:
/* Line 670 of lalr1.cc  */
#line 3666 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 366:
/* Line 670 of lalr1.cc  */
#line 3670 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 3682 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 368:
/* Line 670 of lalr1.cc  */
#line 3686 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new StringConcatExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
        }
    break;

  case 369:
/* Line 670 of lalr1.cc  */
#line 3693 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 370:
/* Line 670 of lalr1.cc  */
#line 3697 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 371:
/* Line 670 of lalr1.cc  */
#line 3704 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 372:
/* Line 670 of lalr1.cc  */
#line 3708 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RangeExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 373:
/* Line 670 of lalr1.cc  */
#line 3717 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 374:
/* Line 670 of lalr1.cc  */
#line 3721 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_plus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 375:
/* Line 670 of lalr1.cc  */
#line 3725 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new AdditiveExpr( LOC((yyloc)), ParseConstants::op_minus, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 376:
/* Line 670 of lalr1.cc  */
#line 3733 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 377:
/* Line 670 of lalr1.cc  */
#line 3737 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mul, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 378:
/* Line 670 of lalr1.cc  */
#line 3743 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_div, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 379:
/* Line 670 of lalr1.cc  */
#line 3749 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_idiv, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 380:
/* Line 670 of lalr1.cc  */
#line 3755 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new MultiplicativeExpr(
                LOC((yyloc)), ParseConstants::op_mod, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 381:
/* Line 670 of lalr1.cc  */
#line 3765 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 382:
/* Line 670 of lalr1.cc  */
#line 3769 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 383:
/* Line 670 of lalr1.cc  */
#line 3773 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnionExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 384:
/* Line 670 of lalr1.cc  */
#line 3781 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 385:
/* Line 670 of lalr1.cc  */
#line 3785 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_intersect, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 386:
/* Line 670 of lalr1.cc  */
#line 3791 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new IntersectExceptExpr(
                LOC((yyloc)), ParseConstants::op_except, (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)
            );
        }
    break;

  case 387:
/* Line 670 of lalr1.cc  */
#line 3801 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 388:
/* Line 670 of lalr1.cc  */
#line 3805 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InstanceofExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 389:
/* Line 670 of lalr1.cc  */
#line 3815 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 390:
/* Line 670 of lalr1.cc  */
#line 3819 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TreatExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SequenceType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 391:
/* Line 670 of lalr1.cc  */
#line 3829 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 392:
/* Line 670 of lalr1.cc  */
#line 3833 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastableExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 393:
/* Line 670 of lalr1.cc  */
#line 3843 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 394:
/* Line 670 of lalr1.cc  */
#line 3847 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new CastExpr(
                LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<SingleType*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 395:
/* Line 670 of lalr1.cc  */
#line 3857 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(1) - (1)].node)), false);
    }
    break;

  case 396:
/* Line 670 of lalr1.cc  */
#line 3861 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SingleType(LOC((yyloc)), dynamic_cast<SimpleType*>((yysemantic_stack_[(2) - (1)].node)), true);
    }
    break;

  case 397:
/* Line 670 of lalr1.cc  */
#line 3870 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 398:
/* Line 670 of lalr1.cc  */
#line 3874 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnaryExpr( LOC((yyloc)), dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)), (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 399:
/* Line 670 of lalr1.cc  */
#line 3882 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), true );
        }
    break;

  case 400:
/* Line 670 of lalr1.cc  */
#line 3886 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SignList( LOC((yyloc)), false );
        }
    break;

  case 401:
/* Line 670 of lalr1.cc  */
#line 3890 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 402:
/* Line 670 of lalr1.cc  */
#line 3894 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( SignList *sl = dynamic_cast<SignList*>((yysemantic_stack_[(2) - (1)].node)) )
                sl->negate();
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 403:
/* Line 670 of lalr1.cc  */
#line 3904 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 404:
/* Line 670 of lalr1.cc  */
#line 3908 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 405:
/* Line 670 of lalr1.cc  */
#line 3912 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 406:
/* Line 670 of lalr1.cc  */
#line 3919 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
      }
    break;

  case 407:
/* Line 670 of lalr1.cc  */
#line 3924 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new SimpleMapExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
      }
    break;

  case 408:
/* Line 670 of lalr1.cc  */
#line 3932 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_eq );
        }
    break;

  case 409:
/* Line 670 of lalr1.cc  */
#line 3936 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ne );
        }
    break;

  case 410:
/* Line 670 of lalr1.cc  */
#line 3940 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_lt );
        }
    break;

  case 411:
/* Line 670 of lalr1.cc  */
#line 3944 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_le );
        }
    break;

  case 412:
/* Line 670 of lalr1.cc  */
#line 3948 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_gt );
        }
    break;

  case 413:
/* Line 670 of lalr1.cc  */
#line 3952 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ValueComp( LOC((yyloc)), ParseConstants::op_val_ge );
        }
    break;

  case 414:
/* Line 670 of lalr1.cc  */
#line 3958 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 415:
/* Line 670 of lalr1.cc  */
#line 3962 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "lax", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 416:
/* Line 670 of lalr1.cc  */
#line 3966 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr( LOC((yyloc)), "strict", (yysemantic_stack_[(5) - (4)].expr) );
        }
    break;

  case 417:
/* Line 670 of lalr1.cc  */
#line 3970 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ValidateExpr(
                LOC((yyloc)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (3)].node))->get_name(), (yysemantic_stack_[(6) - (5)].expr)
            );
            delete (yysemantic_stack_[(6) - (3)].node);
        }
    break;

  case 418:
/* Line 670 of lalr1.cc  */
#line 3981 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(3) - (1)].node)), NULL
            );
        }
    break;

  case 419:
/* Line 670 of lalr1.cc  */
#line 3987 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ExtensionExpr(
                LOC((yyloc)), dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)), (yysemantic_stack_[(4) - (3)].expr)
            );
        }
    break;

  case 420:
/* Line 670 of lalr1.cc  */
#line 3997 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            PragmaList *pl = new PragmaList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.node) = pl;
        }
    break;

  case 421:
/* Line 670 of lalr1.cc  */
#line 4003 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PragmaList *pl = dynamic_cast<PragmaList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<Pragma*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 422:
/* Line 670 of lalr1.cc  */
#line 4013 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
        }
    break;

  case 423:
/* Line 670 of lalr1.cc  */
#line 4017 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) ), "" );
        }
    break;

  case 424:
/* Line 670 of lalr1.cc  */
#line 4021 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new Pragma( LOC((yyloc)), new QName( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), true ), "" );
        }
    break;

  case 425:
/* Line 670 of lalr1.cc  */
#line 4027 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      RelativePathExpr* rpe = dynamic_cast<RelativePathExpr*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = (!rpe ?
            (yysemantic_stack_[(1) - (1)].expr) :
            new PathExpr( LOC((yyloc)), ParseConstants::path_relative, (yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 426:
/* Line 670 of lalr1.cc  */
#line 4036 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 4058 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 428:
/* Line 670 of lalr1.cc  */
#line 4064 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 429:
/* Line 670 of lalr1.cc  */
#line 4068 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new NameTest( LOC((yyloc)), dynamic_cast<Wildcard*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 430:
/* Line 670 of lalr1.cc  */
#line 4078 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", "", ParseConstants::wild_all, false);
    }
    break;

  case 431:
/* Line 670 of lalr1.cc  */
#line 4082 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, false);
    }
    break;

  case 432:
/* Line 670 of lalr1.cc  */
#line 4086 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), "", ParseConstants::wild_elem, true);
    }
    break;

  case 433:
/* Line 670 of lalr1.cc  */
#line 4090 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new Wildcard(LOC((yyloc)), "", SYMTAB((yysemantic_stack_[(1) - (1)].sval)), ParseConstants::wild_prefix, false);
    }
    break;

  case 434:
/* Line 670 of lalr1.cc  */
#line 4103 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
     }
    break;

  case 435:
/* Line 670 of lalr1.cc  */
#line 4107 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new FilterExpr(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].expr), dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (2)].node)));
     }
    break;

  case 436:
/* Line 670 of lalr1.cc  */
#line 4111 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), false);
     }
    break;

  case 437:
/* Line 670 of lalr1.cc  */
#line 4115 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new DynamicFunctionInvocation(LOC((yyloc)), (yysemantic_stack_[(4) - (1)].expr), dynamic_cast<ArgList*>((yysemantic_stack_[(4) - (3)].node)), false);
     }
    break;

  case 438:
/* Line 670 of lalr1.cc  */
#line 4120 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), sl);
     }
    break;

  case 439:
/* Line 670 of lalr1.cc  */
#line 4125 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 440:
/* Line 670 of lalr1.cc  */
#line 4129 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
        (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 441:
/* Line 670 of lalr1.cc  */
#line 4133 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new JSONObjectLookup(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr));
     }
    break;

  case 442:
/* Line 670 of lalr1.cc  */
#line 4142 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            PredicateList *pl = new PredicateList( LOC((yyloc)) );
            pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.node) = pl;
        }
    break;

  case 443:
/* Line 670 of lalr1.cc  */
#line 4148 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( PredicateList *pl = dynamic_cast<PredicateList*>((yysemantic_stack_[(2) - (1)].node)) )
                pl->push_back( dynamic_cast<exprnode*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 444:
/* Line 670 of lalr1.cc  */
#line 4158 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
        }
    break;

  case 445:
/* Line 670 of lalr1.cc  */
#line 4166 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 446:
/* Line 670 of lalr1.cc  */
#line 4170 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 447:
/* Line 670 of lalr1.cc  */
#line 4174 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 448:
/* Line 670 of lalr1.cc  */
#line 4178 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 449:
/* Line 670 of lalr1.cc  */
#line 4182 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 450:
/* Line 670 of lalr1.cc  */
#line 4186 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 451:
/* Line 670 of lalr1.cc  */
#line 4190 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 452:
/* Line 670 of lalr1.cc  */
#line 4194 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 453:
/* Line 670 of lalr1.cc  */
#line 4198 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 454:
/* Line 670 of lalr1.cc  */
#line 4202 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 455:
/* Line 670 of lalr1.cc  */
#line 4207 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 456:
/* Line 670 of lalr1.cc  */
#line 4211 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 457:
/* Line 670 of lalr1.cc  */
#line 4215 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 458:
/* Line 670 of lalr1.cc  */
#line 4219 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 459:
/* Line 670 of lalr1.cc  */
#line 4227 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 460:
/* Line 670 of lalr1.cc  */
#line 4231 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 461:
/* Line 670 of lalr1.cc  */
#line 4236 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
        }
    break;

  case 462:
/* Line 670 of lalr1.cc  */
#line 4240 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new NullLiteral(LOC((yyloc)));
        }
    break;

  case 463:
/* Line 670 of lalr1.cc  */
#line 4249 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_decimal, *(yysemantic_stack_[(1) - (1)].decval)
            );
            delete yylval.decval;
        }
    break;

  case 464:
/* Line 670 of lalr1.cc  */
#line 4256 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_integer, *(yysemantic_stack_[(1) - (1)].ival)
            );
            delete yylval.ival;
        }
    break;

  case 465:
/* Line 670 of lalr1.cc  */
#line 4263 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = NumericLiteral::new_literal(
                LOC((yyloc)), ParseConstants::num_double, *(yysemantic_stack_[(1) - (1)].dval)
            );
            delete yylval.dval;
        }
    break;

  case 466:
/* Line 670 of lalr1.cc  */
#line 4274 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), true);
        }
    break;

  case 467:
/* Line 670 of lalr1.cc  */
#line 4278 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new BooleanLiteral(LOC((yyloc)), false);
        }
    break;

  case 468:
/* Line 670 of lalr1.cc  */
#line 4287 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new VarRef(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (2)].expr)));
        }
    break;

  case 469:
/* Line 670 of lalr1.cc  */
#line 4295 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), NULL);
        }
    break;

  case 470:
/* Line 670 of lalr1.cc  */
#line 4299 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ParenthesizedExpr( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 471:
/* Line 670 of lalr1.cc  */
#line 4307 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 472:
/* Line 670 of lalr1.cc  */
#line 4312 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ContextItemExpr( LOC((yyloc)) );
        }
    break;

  case 473:
/* Line 670 of lalr1.cc  */
#line 4321 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new OrderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 474:
/* Line 670 of lalr1.cc  */
#line 4329 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new UnorderedExpr( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
        }
    break;

  case 475:
/* Line 670 of lalr1.cc  */
#line 4335 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new FunctionCall( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), NULL );
    }
    break;

  case 476:
/* Line 670 of lalr1.cc  */
#line 4339 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 4361 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back(new ArgumentPlaceholder(LOC((yyloc))));
      (yyval.node) = al;
    }
    break;

  case 478:
/* Line 670 of lalr1.cc  */
#line 4367 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( new ArgumentPlaceholder(LOC((yyloc))) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 479:
/* Line 670 of lalr1.cc  */
#line 4373 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      ArgList *al = new ArgList( LOC((yyloc)) );
      al->push_back( (yysemantic_stack_[(1) - (1)].expr) );
      (yyval.node) = al;
    }
    break;

  case 480:
/* Line 670 of lalr1.cc  */
#line 4379 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      if ( ArgList *al = dynamic_cast<ArgList*>((yysemantic_stack_[(3) - (1)].node)) )
        al->push_back( (yysemantic_stack_[(3) - (3)].expr) );
      (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
    }
    break;

  case 481:
/* Line 670 of lalr1.cc  */
#line 4389 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 482:
/* Line 670 of lalr1.cc  */
#line 4393 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 483:
/* Line 670 of lalr1.cc  */
#line 4401 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new LiteralFunctionItem(LOC ((yyloc)), dynamic_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].ival));
    }
    break;

  case 484:
/* Line 670 of lalr1.cc  */
#line 4409 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new InlineFunction(LOC((yyloc)),
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theParams,
                              &*(yysemantic_stack_[(3) - (2)].fnsig)->theReturnType,
                              (yysemantic_stack_[(3) - (3)].expr));
      delete (yysemantic_stack_[(3) - (2)].fnsig);
    }
    break;

  case 485:
/* Line 670 of lalr1.cc  */
#line 4421 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 486:
/* Line 670 of lalr1.cc  */
#line 4425 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 487:
/* Line 670 of lalr1.cc  */
#line 4433 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 488:
/* Line 670 of lalr1.cc  */
#line 4437 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 489:
/* Line 670 of lalr1.cc  */
#line 4441 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 490:
/* Line 670 of lalr1.cc  */
#line 4449 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(4) - (2)].expr)),
                                  NULL,
                                  NULL,
                                  NULL);
    }
    break;

  case 491:
/* Line 670 of lalr1.cc  */
#line 4457 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 4474 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemConstructor(LOC((yyloc)),
                                  static_cast<QName*>((yysemantic_stack_[(5) - (2)].expr)),
                                  NULL,
                                  dynamic_cast<DirAttributeList*>((yysemantic_stack_[(5) - (3)].node)),
                                  NULL);
    }
    break;

  case 493:
/* Line 670 of lalr1.cc  */
#line 4482 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 4501 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 4520 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 4542 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = new DirElemContentList( LOC((yyloc)) );
      decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(1) - (1)].expr)) );
      (yyval.node) = decl;
    }
    break;

  case 497:
/* Line 670 of lalr1.cc  */
#line 4548 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirElemContentList *decl = dynamic_cast<DirElemContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( decl )
        decl->push_back( dynamic_cast<DirElemContent*>((yysemantic_stack_[(2) - (2)].expr)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 498:
/* Line 670 of lalr1.cc  */
#line 4559 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = new DirAttributeList( LOC((yyloc)) );
      dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = dal;
    }
    break;

  case 499:
/* Line 670 of lalr1.cc  */
#line 4565 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      DirAttributeList *dal = dynamic_cast<DirAttributeList*>((yysemantic_stack_[(2) - (1)].node));
      if ( dal )
        dal->push_back( dynamic_cast<DirAttr*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 500:
/* Line 670 of lalr1.cc  */
#line 4576 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttr(LOC((yyloc)),
                       static_cast<QName*>((yysemantic_stack_[(6) - (2)].expr)),
                       dynamic_cast<DirAttributeValue*>((yysemantic_stack_[(6) - (6)].node)));
    }
    break;

  case 503:
/* Line 670 of lalr1.cc  */
#line 4591 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue(LOC((yyloc)),
                                 dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 504:
/* Line 670 of lalr1.cc  */
#line 4596 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DirAttributeValue( LOC((yyloc)),
                                  dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(3) - (2)].node)));
    }
    break;

  case 505:
/* Line 670 of lalr1.cc  */
#line 4605 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrContentList( LOC((yyloc)) );
    }
    break;

  case 506:
/* Line 670 of lalr1.cc  */
#line 4609 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 507:
/* Line 670 of lalr1.cc  */
#line 4616 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = qacl;
    }
    break;

  case 508:
/* Line 670 of lalr1.cc  */
#line 4622 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = new QuoteAttrContentList( LOC((yyloc)) );
      qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = qacl;
    }
    break;

  case 509:
/* Line 670 of lalr1.cc  */
#line 4628 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList* qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( new QuoteAttrValueContent( LOC((yyloc)), "\"" ) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 510:
/* Line 670 of lalr1.cc  */
#line 4635 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      QuoteAttrContentList *qacl = dynamic_cast<QuoteAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( qacl )
        qacl->push_back( dynamic_cast<QuoteAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 511:
/* Line 670 of lalr1.cc  */
#line 4646 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrContentList( LOC((yyloc)) );
    }
    break;

  case 512:
/* Line 670 of lalr1.cc  */
#line 4650 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 513:
/* Line 670 of lalr1.cc  */
#line 4657 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = aacl;
    }
    break;

  case 514:
/* Line 670 of lalr1.cc  */
#line 4663 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = new AposAttrContentList( LOC((yyloc)) );
      aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(1) - (1)].node)) );
      (yyval.node) = aacl;
    }
    break;

  case 515:
/* Line 670 of lalr1.cc  */
#line 4669 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if (aacl)
        aacl->push_back( new AposAttrValueContent( LOC((yyloc)),"'") );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 516:
/* Line 670 of lalr1.cc  */
#line 4676 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      AposAttrContentList *aacl = dynamic_cast<AposAttrContentList*>((yysemantic_stack_[(2) - (1)].node));
      if ( aacl )
        aacl->push_back( dynamic_cast<AposAttrValueContent*>((yysemantic_stack_[(2) - (2)].node)) );
      (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
    }
    break;

  case 517:
/* Line 670 of lalr1.cc  */
#line 4687 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 518:
/* Line 670 of lalr1.cc  */
#line 4691 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new QuoteAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 519:
/* Line 670 of lalr1.cc  */
#line 4699 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 520:
/* Line 670 of lalr1.cc  */
#line 4703 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AposAttrValueContent(LOC((yyloc)), dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr)));
    }
    break;

  case 521:
/* Line 670 of lalr1.cc  */
#line 4711 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].expr) );
    }
    break;

  case 522:
/* Line 670 of lalr1.cc  */
#line 4715 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirElemContent( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
    }
    break;

  case 523:
/* Line 670 of lalr1.cc  */
#line 4719 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CDataSection> cdata_h = dynamic_cast<CDataSection*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cdata_h );
    }
    break;

  case 524:
/* Line 670 of lalr1.cc  */
#line 4724 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      rchandle<CommonContent> cont_h = dynamic_cast<CommonContent*>((yysemantic_stack_[(1) - (1)].expr));
      (yyval.expr) = new DirElemContent( LOC((yyloc)), cont_h );
    }
    break;

  case 525:
/* Line 670 of lalr1.cc  */
#line 4733 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_charref, SYMTAB((yysemantic_stack_[(1) - (1)].sval)));
    }
    break;

  case 526:
/* Line 670 of lalr1.cc  */
#line 4737 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_lbrace);
    }
    break;

  case 527:
/* Line 670 of lalr1.cc  */
#line 4741 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), ParseConstants::cont_escape_rbrace);
    }
    break;

  case 528:
/* Line 670 of lalr1.cc  */
#line 4745 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CommonContent(LOC((yyloc)), new EnclosedExpr(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr)));
    }
    break;

  case 529:
/* Line 670 of lalr1.cc  */
#line 4753 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 530:
/* Line 670 of lalr1.cc  */
#line 4758 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirCommentConstructor( LOC((yyloc)), "" );
    }
    break;

  case 531:
/* Line 670 of lalr1.cc  */
#line 4766 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)) );
    }
    break;

  case 532:
/* Line 670 of lalr1.cc  */
#line 4771 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new DirPIConstructor( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (2)].sval)), SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
    }
    break;

  case 533:
/* Line 670 of lalr1.cc  */
#line 4779 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CDataSection( LOC((yyloc)),SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
    }
    break;

  case 534:
/* Line 670 of lalr1.cc  */
#line 4787 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 535:
/* Line 670 of lalr1.cc  */
#line 4792 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 536:
/* Line 670 of lalr1.cc  */
#line 4797 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 537:
/* Line 670 of lalr1.cc  */
#line 4802 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 538:
/* Line 670 of lalr1.cc  */
#line 4807 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 539:
/* Line 670 of lalr1.cc  */
#line 4812 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(1) - (1)].expr);
    }
    break;

  case 541:
/* Line 670 of lalr1.cc  */
#line 4823 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompDocConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 542:
/* Line 670 of lalr1.cc  */
#line 4831 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor(LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 543:
/* Line 670 of lalr1.cc  */
#line 4835 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompElemConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 544:
/* Line 670 of lalr1.cc  */
#line 4841 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval))), (yysemantic_stack_[(3) - (2)].expr) );
    }
    break;

  case 545:
/* Line 670 of lalr1.cc  */
#line 4845 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompAttrConstructor( LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr) );
    }
    break;

  case 546:
/* Line 670 of lalr1.cc  */
#line 4853 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompTextConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 547:
/* Line 670 of lalr1.cc  */
#line 4861 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompCommentConstructor( LOC((yyloc)), (yysemantic_stack_[(4) - (3)].expr) );
    }
    break;

  case 548:
/* Line 670 of lalr1.cc  */
#line 4869 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 549:
/* Line 670 of lalr1.cc  */
#line 4873 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompPIConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 550:
/* Line 670 of lalr1.cc  */
#line 4881 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)), (yysemantic_stack_[(3) - (2)].expr));
    }
    break;

  case 551:
/* Line 670 of lalr1.cc  */
#line 4885 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = new CompNamespaceConstructor(LOC((yyloc)), (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (6)].expr));
    }
    break;

  case 552:
/* Line 670 of lalr1.cc  */
#line 4893 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(2) - (2)].node);
    }
    break;

  case 553:
/* Line 670 of lalr1.cc  */
#line 4901 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), (yysemantic_stack_[(1) - (1)].node), NULL );
        }
    break;

  case 554:
/* Line 670 of lalr1.cc  */
#line 4905 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType(LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), dynamic_cast<OccurrenceIndicator*>((yysemantic_stack_[(2) - (2)].node)));
        }
    break;

  case 555:
/* Line 670 of lalr1.cc  */
#line 4909 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 556:
/* Line 670 of lalr1.cc  */
#line 4914 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SequenceType( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 557:
/* Line 670 of lalr1.cc  */
#line 4921 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_optionally
            );
        }
    break;

  case 558:
/* Line 670 of lalr1.cc  */
#line 4927 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_zero_or_more
            );
        }
    break;

  case 559:
/* Line 670 of lalr1.cc  */
#line 4933 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new OccurrenceIndicator(
                LOC((yyloc)), ParseConstants::occurs_one_or_more
            );
        }
    break;

  case 560:
/* Line 670 of lalr1.cc  */
#line 4943 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 561:
/* Line 670 of lalr1.cc  */
#line 4947 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 562:
/* Line 670 of lalr1.cc  */
#line 4951 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 563:
/* Line 670 of lalr1.cc  */
#line 4956 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ItemType( LOC((yyloc)), true );
        }
    break;

  case 564:
/* Line 670 of lalr1.cc  */
#line 4961 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 565:
/* Line 670 of lalr1.cc  */
#line 4966 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new StructuredItemType(LOC((yyloc)));
        }
    break;

  case 566:
/* Line 670 of lalr1.cc  */
#line 4971 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 567:
/* Line 670 of lalr1.cc  */
#line 4975 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 568:
/* Line 670 of lalr1.cc  */
#line 4979 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 569:
/* Line 670 of lalr1.cc  */
#line 4986 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = new TypeList(LOC ((yyloc)));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(1) - (1)].node)));
          (yyval.node) = aTypeList;
        }
    break;

  case 570:
/* Line 670 of lalr1.cc  */
#line 4992 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          TypeList* aTypeList = dynamic_cast<TypeList *>((yysemantic_stack_[(3) - (1)].node));
          aTypeList->push_back(dynamic_cast<SequenceType *>((yysemantic_stack_[(3) - (3)].node)));
          (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 571:
/* Line 670 of lalr1.cc  */
#line 5002 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new GeneralizedAtomicType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 572:
/* Line 670 of lalr1.cc  */
#line 5010 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new SimpleType( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
    }
    break;

  case 573:
/* Line 670 of lalr1.cc  */
#line 5018 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 574:
/* Line 670 of lalr1.cc  */
#line 5022 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 575:
/* Line 670 of lalr1.cc  */
#line 5026 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 576:
/* Line 670 of lalr1.cc  */
#line 5030 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 577:
/* Line 670 of lalr1.cc  */
#line 5034 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 578:
/* Line 670 of lalr1.cc  */
#line 5038 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 579:
/* Line 670 of lalr1.cc  */
#line 5042 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 580:
/* Line 670 of lalr1.cc  */
#line 5046 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 581:
/* Line 670 of lalr1.cc  */
#line 5050 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 582:
/* Line 670 of lalr1.cc  */
#line 5054 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 583:
/* Line 670 of lalr1.cc  */
#line 5062 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyKindTest( LOC((yyloc)) );
    }
    break;

  case 584:
/* Line 670 of lalr1.cc  */
#line 5070 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)));
    }
    break;

  case 585:
/* Line 670 of lalr1.cc  */
#line 5074 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<ElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 586:
/* Line 670 of lalr1.cc  */
#line 5078 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new DocumentTest(LOC((yyloc)), dynamic_cast<SchemaElementTest*>((yysemantic_stack_[(4) - (3)].node)));
    }
    break;

  case 587:
/* Line 670 of lalr1.cc  */
#line 5086 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new NamespaceTest(LOC((yyloc)));
    }
    break;

  case 588:
/* Line 670 of lalr1.cc  */
#line 5093 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new TextTest(LOC((yyloc)));
    }
    break;

  case 589:
/* Line 670 of lalr1.cc  */
#line 5101 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new CommentTest(LOC((yyloc)));
    }
    break;

  case 590:
/* Line 670 of lalr1.cc  */
#line 5109 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), "" );
        }
    break;

  case 591:
/* Line 670 of lalr1.cc  */
#line 5113 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 592:
/* Line 670 of lalr1.cc  */
#line 5117 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new PITest( LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)) );
        }
    break;

  case 593:
/* Line 670 of lalr1.cc  */
#line 5125 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 594:
/* Line 670 of lalr1.cc  */
#line 5129 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL
            );
        }
    break;

  case 595:
/* Line 670 of lalr1.cc  */
#line 5135 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(6) - (3)].expr)), dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 596:
/* Line 670 of lalr1.cc  */
#line 5141 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest( LOC((yyloc)), NULL, NULL );
        }
    break;

  case 597:
/* Line 670 of lalr1.cc  */
#line 5145 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new AttributeTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node))
            );
        }
    break;

  case 598:
/* Line 670 of lalr1.cc  */
#line 5155 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaAttributeTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 599:
/* Line 670 of lalr1.cc  */
#line 5163 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest( LOC((yyloc)), NULL, NULL, true );
        }
    break;

  case 600:
/* Line 670 of lalr1.cc  */
#line 5167 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)), NULL, true
            );
        }
    break;

  case 601:
/* Line 670 of lalr1.cc  */
#line 5173 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 5182 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 5191 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, NULL, true
            );
        }
    break;

  case 604:
/* Line 670 of lalr1.cc  */
#line 5197 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), false
            );
        }
    break;

  case 605:
/* Line 670 of lalr1.cc  */
#line 5203 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new ElementTest(
                LOC((yyloc)), NULL, dynamic_cast<TypeName*>((yysemantic_stack_[(6) - (5)].node)), true
            );
        }
    break;

  case 606:
/* Line 670 of lalr1.cc  */
#line 5213 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new SchemaElementTest( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 607:
/* Line 670 of lalr1.cc  */
#line 5219 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(1) - (1)].expr)) );
        }
    break;

  case 608:
/* Line 670 of lalr1.cc  */
#line 5226 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new TypeName( LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(2) - (1)].expr)), true );
        }
    break;

  case 609:
/* Line 670 of lalr1.cc  */
#line 5232 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
        }
    break;

  case 610:
/* Line 670 of lalr1.cc  */
#line 5238 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 611:
/* Line 670 of lalr1.cc  */
#line 5242 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
    }
    break;

  case 612:
/* Line 670 of lalr1.cc  */
#line 5250 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.node) = new AnyFunctionTest(LOC((yyloc)));
    }
    break;

  case 613:
/* Line 670 of lalr1.cc  */
#line 5258 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)), dynamic_cast<SequenceType *>((yysemantic_stack_[(5) - (5)].node)));
        }
    break;

  case 614:
/* Line 670 of lalr1.cc  */
#line 5262 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new TypedFunctionTest(LOC ((yyloc)),
              dynamic_cast<TypeList *>((yysemantic_stack_[(6) - (3)].node)),
              dynamic_cast<SequenceType *>((yysemantic_stack_[(6) - (6)].node)));
        }
    break;

  case 615:
/* Line 670 of lalr1.cc  */
#line 5273 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
           (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 616:
/* Line 670 of lalr1.cc  */
#line 5279 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::strict_validation
            );
        }
    break;

  case 617:
/* Line 670 of lalr1.cc  */
#line 5285 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::lax_validation
            );
        }
    break;

  case 618:
/* Line 670 of lalr1.cc  */
#line 5291 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new RevalidationDecl(
                LOC((yyloc)), StaticContextConsts::skip_validation
            );
        }
    break;

  case 619:
/* Line 670 of lalr1.cc  */
#line 5301 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 620:
/* Line 670 of lalr1.cc  */
#line 5305 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 621:
/* Line 670 of lalr1.cc  */
#line 5311 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 622:
/* Line 670 of lalr1.cc  */
#line 5317 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 623:
/* Line 670 of lalr1.cc  */
#line 5321 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 624:
/* Line 670 of lalr1.cc  */
#line 5327 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr( LOC((yyloc)), store::UpdateConsts::INTO, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 625:
/* Line 670 of lalr1.cc  */
#line 5331 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC((yyloc)), store::UpdateConsts::AS_FIRST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 626:
/* Line 670 of lalr1.cc  */
#line 5337 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                  LOC((yyloc)), store::UpdateConsts::AS_LAST_INTO, (yysemantic_stack_[(7) - (3)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 627:
/* Line 670 of lalr1.cc  */
#line 5343 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)),
                store::UpdateConsts::AFTER, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 628:
/* Line 670 of lalr1.cc  */
#line 5350 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new InsertExpr(
                LOC ((yyloc)), store::UpdateConsts::BEFORE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 629:
/* Line 670 of lalr1.cc  */
#line 5360 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 630:
/* Line 670 of lalr1.cc  */
#line 5365 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new DeleteExpr( LOC ((yyloc)), (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 631:
/* Line 670 of lalr1.cc  */
#line 5373 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::NODE, (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)
            );
        }
    break;

  case 632:
/* Line 670 of lalr1.cc  */
#line 5379 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new ReplaceExpr(
                LOC((yyloc)), store::UpdateConsts::VALUE_OF_NODE, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr)
            );
        }
    break;

  case 633:
/* Line 670 of lalr1.cc  */
#line 5389 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new RenameExpr( LOC ((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 634:
/* Line 670 of lalr1.cc  */
#line 5395 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList *cvl = dynamic_cast<CopyVarList*>((yysemantic_stack_[(7) - (3)].expr));
      (yyval.expr) = new TransformExpr( LOC((yyloc)), cvl, (yysemantic_stack_[(7) - (5)].expr), (yysemantic_stack_[(7) - (7)].expr) );
    }
    break;

  case 635:
/* Line 670 of lalr1.cc  */
#line 5404 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = new CopyVarList(LOC((yyloc)));
      lList->push_back (dynamic_cast<VarBinding*> ((yysemantic_stack_[(1) - (1)].expr)));
      (yyval.expr) = lList;
    }
    break;

  case 636:
/* Line 670 of lalr1.cc  */
#line 5410 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      CopyVarList* lList = dynamic_cast<CopyVarList*>((yysemantic_stack_[(4) - (1)].expr));
      VarBinding* lBinding = dynamic_cast<VarBinding*>((yysemantic_stack_[(4) - (4)].expr));
      lList->push_back(lBinding);
      (yyval.expr) = lList;
    }
    break;

  case 637:
/* Line 670 of lalr1.cc  */
#line 5423 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new VarBinding(LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (1)].expr)), (yysemantic_stack_[(3) - (3)].expr));
    }
    break;

  case 638:
/* Line 670 of lalr1.cc  */
#line 5429 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.expr) = new TryExpr( LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr) );
        }
    break;

  case 639:
/* Line 670 of lalr1.cc  */
#line 5436 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = new CatchListExpr( LOC((yyloc)) );
            cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(1) - (1)].expr)) );
            (yyval.expr) = cle;
        }
    break;

  case 640:
/* Line 670 of lalr1.cc  */
#line 5442 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchListExpr *cle = dynamic_cast<CatchListExpr*>((yysemantic_stack_[(2) - (1)].expr));
            if ( cle )
                cle->push_back( static_cast<CatchExpr*>((yysemantic_stack_[(2) - (2)].expr)) );
            (yyval.expr) = (yysemantic_stack_[(2) - (1)].expr);
        }
    break;

  case 641:
/* Line 670 of lalr1.cc  */
#line 5452 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
       (yyval.expr) = new CatchExpr(LOC((yyloc)), *(yysemantic_stack_[(3) - (2)].name_test_list), (yysemantic_stack_[(3) - (3)].expr));
       delete (yysemantic_stack_[(3) - (2)].name_test_list);
    }
    break;

  case 642:
/* Line 670 of lalr1.cc  */
#line 5461 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
      (yyval.expr) = (yysemantic_stack_[(3) - (2)].expr);
    }
    break;

  case 643:
/* Line 670 of lalr1.cc  */
#line 5469 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl = new CatchExpr::NameTestList;
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(1) - (1)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 644:
/* Line 670 of lalr1.cc  */
#line 5475 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            CatchExpr::NameTestList *ntl =
                static_cast<CatchExpr::NameTestList*>((yysemantic_stack_[(3) - (1)].name_test_list));
            ntl->push_back( static_cast<NameTest*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.name_test_list) = ntl;
        }
    break;

  case 645:
/* Line 670 of lalr1.cc  */
#line 5484 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTSelection( LOC((yyloc)), (yysemantic_stack_[(2) - (1)].node), (yysemantic_stack_[(2) - (2)].pos_filter_list) );
            delete (yysemantic_stack_[(2) - (2)].pos_filter_list);
        }
    break;

  case 646:
/* Line 670 of lalr1.cc  */
#line 5492 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = NULL;
        }
    break;

  case 647:
/* Line 670 of lalr1.cc  */
#line 5496 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = (yysemantic_stack_[(1) - (1)].pos_filter_list);
        }
    break;

  case 648:
/* Line 670 of lalr1.cc  */
#line 5503 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.pos_filter_list) = new FTSelection::pos_filter_list_t;
            (yyval.pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 649:
/* Line 670 of lalr1.cc  */
#line 5508 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(2) - (1)].pos_filter_list)->push_back( dynamic_cast<FTPosFilter*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.pos_filter_list) = (yysemantic_stack_[(2) - (1)].pos_filter_list);
        }
    break;

  case 650:
/* Line 670 of lalr1.cc  */
#line 5516 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 651:
/* Line 670 of lalr1.cc  */
#line 5520 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOr( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 652:
/* Line 670 of lalr1.cc  */
#line 5527 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 653:
/* Line 670 of lalr1.cc  */
#line 5531 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnd( LOC((yyloc)), (yysemantic_stack_[(3) - (1)].node), (yysemantic_stack_[(3) - (3)].node) );
        }
    break;

  case 654:
/* Line 670 of lalr1.cc  */
#line 5538 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 655:
/* Line 670 of lalr1.cc  */
#line 5542 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTMildNot( LOC((yyloc)), (yysemantic_stack_[(4) - (1)].node), (yysemantic_stack_[(4) - (4)].node) );
        }
    break;

  case 656:
/* Line 670 of lalr1.cc  */
#line 5549 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 657:
/* Line 670 of lalr1.cc  */
#line 5553 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnaryNot(
                LOC((yyloc)), dynamic_cast<FTPrimaryWithOptions*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 658:
/* Line 670 of lalr1.cc  */
#line 5562 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 5574 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 660:
/* Line 670 of lalr1.cc  */
#line 5578 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 661:
/* Line 670 of lalr1.cc  */
#line 5585 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 662:
/* Line 670 of lalr1.cc  */
#line 5589 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 663:
/* Line 670 of lalr1.cc  */
#line 5597 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWeight( LOC((yyloc)), dynamic_cast<exprnode*>((yysemantic_stack_[(4) - (3)].expr)) );
        }
    break;

  case 664:
/* Line 670 of lalr1.cc  */
#line 5605 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsTimes(
                LOC((yyloc)),
                dynamic_cast<FTWords*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTTimes*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 665:
/* Line 670 of lalr1.cc  */
#line 5613 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(3) - (2)].node);
        }
    break;

  case 666:
/* Line 670 of lalr1.cc  */
#line 5617 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 667:
/* Line 670 of lalr1.cc  */
#line 5624 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 668:
/* Line 670 of lalr1.cc  */
#line 5628 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 669:
/* Line 670 of lalr1.cc  */
#line 5636 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionSelection(
                LOC((yyloc)),
                dynamic_cast<PragmaList*>((yysemantic_stack_[(4) - (1)].node)),
                dynamic_cast<FTSelection*>((yysemantic_stack_[(4) - (3)].node))
            );
        }
    break;

  case 670:
/* Line 670 of lalr1.cc  */
#line 5647 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 671:
/* Line 670 of lalr1.cc  */
#line 5651 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 672:
/* Line 670 of lalr1.cc  */
#line 5659 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWords(
                LOC((yyloc)),
                dynamic_cast<FTWordsValue*>((yysemantic_stack_[(2) - (1)].node)),
                dynamic_cast<FTAnyallOption*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 673:
/* Line 670 of lalr1.cc  */
#line 5671 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), static_cast<StringLiteral*>((yysemantic_stack_[(1) - (1)].expr)), NULL
            );
        }
    break;

  case 674:
/* Line 670 of lalr1.cc  */
#line 5677 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWordsValue(
                LOC((yyloc)), NULL, dynamic_cast<exprnode*>((yysemantic_stack_[(3) - (2)].expr))
            );
        }
    break;

  case 675:
/* Line 670 of lalr1.cc  */
#line 5686 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::any );
        }
    break;

  case 676:
/* Line 670 of lalr1.cc  */
#line 5690 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 677:
/* Line 670 of lalr1.cc  */
#line 5698 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 678:
/* Line 670 of lalr1.cc  */
#line 5702 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), (yysemantic_stack_[(2) - (2)].ft_anyall_value) );
        }
    break;

  case 679:
/* Line 670 of lalr1.cc  */
#line 5706 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTAnyallOption( LOC((yyloc)), ft_anyall_mode::phrase );
        }
    break;

  case 680:
/* Line 670 of lalr1.cc  */
#line 5713 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any;
        }
    break;

  case 681:
/* Line 670 of lalr1.cc  */
#line 5717 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::any_word;
        }
    break;

  case 682:
/* Line 670 of lalr1.cc  */
#line 5724 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all;
        }
    break;

  case 683:
/* Line 670 of lalr1.cc  */
#line 5728 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.ft_anyall_value) = ft_anyall_mode::all_words;
        }
    break;

  case 684:
/* Line 670 of lalr1.cc  */
#line 5736 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 685:
/* Line 670 of lalr1.cc  */
#line 5740 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 686:
/* Line 670 of lalr1.cc  */
#line 5744 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 687:
/* Line 670 of lalr1.cc  */
#line 5748 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 688:
/* Line 670 of lalr1.cc  */
#line 5752 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 689:
/* Line 670 of lalr1.cc  */
#line 5760 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTOrder( LOC((yyloc)) );
        }
    break;

  case 690:
/* Line 670 of lalr1.cc  */
#line 5768 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWindow(
                LOC((yyloc)),
                static_cast<AdditiveExpr*>((yysemantic_stack_[(3) - (2)].expr)),
                static_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 691:
/* Line 670 of lalr1.cc  */
#line 5780 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDistance(
                LOC((yyloc)),
                dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)),
                dynamic_cast<FTUnit*>((yysemantic_stack_[(3) - (3)].node))
            );
        }
    break;

  case 692:
/* Line 670 of lalr1.cc  */
#line 5792 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::words );
        }
    break;

  case 693:
/* Line 670 of lalr1.cc  */
#line 5796 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::sentences );
        }
    break;

  case 694:
/* Line 670 of lalr1.cc  */
#line 5800 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTUnit( LOC((yyloc)), ft_unit::paragraphs );
        }
    break;

  case 695:
/* Line 670 of lalr1.cc  */
#line 5808 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = new FTMatchOptions( LOC((yyloc)) );
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.node) = mo;
        }
    break;

  case 696:
/* Line 670 of lalr1.cc  */
#line 5814 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTMatchOptions *mo = dynamic_cast<FTMatchOptions*>((yysemantic_stack_[(3) - (1)].node));
            mo->push_back( dynamic_cast<FTMatchOption*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.node) = (yysemantic_stack_[(3) - (1)].node);
        }
    break;

  case 697:
/* Line 670 of lalr1.cc  */
#line 5824 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 698:
/* Line 670 of lalr1.cc  */
#line 5828 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 699:
/* Line 670 of lalr1.cc  */
#line 5832 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 700:
/* Line 670 of lalr1.cc  */
#line 5836 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 701:
/* Line 670 of lalr1.cc  */
#line 5840 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 702:
/* Line 670 of lalr1.cc  */
#line 5844 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 703:
/* Line 670 of lalr1.cc  */
#line 5848 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 704:
/* Line 670 of lalr1.cc  */
#line 5852 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 705:
/* Line 670 of lalr1.cc  */
#line 5860 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::sensitive );
        }
    break;

  case 706:
/* Line 670 of lalr1.cc  */
#line 5864 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::insensitive );
        }
    break;

  case 707:
/* Line 670 of lalr1.cc  */
#line 5868 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::lower );
        }
    break;

  case 708:
/* Line 670 of lalr1.cc  */
#line 5872 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTCaseOption( LOC((yyloc)), ft_case_mode::upper );
        }
    break;

  case 709:
/* Line 670 of lalr1.cc  */
#line 5880 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::sensitive
            );
        }
    break;

  case 710:
/* Line 670 of lalr1.cc  */
#line 5886 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTDiacriticsOption(
                LOC((yyloc)), ft_diacritics_mode::insensitive
            );
        }
    break;

  case 711:
/* Line 670 of lalr1.cc  */
#line 5896 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTExtensionOption(
                LOC((yyloc)), static_cast<QName*>((yysemantic_stack_[(3) - (2)].expr)), SYMTAB((yysemantic_stack_[(3) - (3)].sval))
            );
        }
    break;

  case 712:
/* Line 670 of lalr1.cc  */
#line 5906 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::stemming );
        }
    break;

  case 713:
/* Line 670 of lalr1.cc  */
#line 5910 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStemOption( LOC((yyloc)), ft_stem_mode::no_stemming );
        }
    break;

  case 714:
/* Line 670 of lalr1.cc  */
#line 5918 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 5928 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 5939 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusOption( LOC((yyloc)), NULL, false, true );
        }
    break;

  case 717:
/* Line 670 of lalr1.cc  */
#line 5946 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 718:
/* Line 670 of lalr1.cc  */
#line 5950 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 719:
/* Line 670 of lalr1.cc  */
#line 5957 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = NULL;
        }
    break;

  case 720:
/* Line 670 of lalr1.cc  */
#line 5961 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(2) - (2)].thesaurus_id_list);
        }
    break;

  case 721:
/* Line 670 of lalr1.cc  */
#line 5968 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.thesaurus_id_list) = new FTThesaurusOption::thesaurus_id_list_t;
            (yyval.thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 722:
/* Line 670 of lalr1.cc  */
#line 5973 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yysemantic_stack_[(3) - (1)].thesaurus_id_list)->push_back( dynamic_cast<FTThesaurusID*>((yysemantic_stack_[(3) - (3)].node)) );
            (yyval.thesaurus_id_list) = (yysemantic_stack_[(3) - (1)].thesaurus_id_list);
        }
    break;

  case 723:
/* Line 670 of lalr1.cc  */
#line 5982 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTThesaurusID(
                LOC((yyloc)), SYMTAB((yysemantic_stack_[(4) - (2)].sval)), SYMTAB((yysemantic_stack_[(4) - (3)].sval)), dynamic_cast<FTRange*>((yysemantic_stack_[(4) - (4)].node))
            );
        }
    break;

  case 724:
/* Line 670 of lalr1.cc  */
#line 5991 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = 0;
        }
    break;

  case 725:
/* Line 670 of lalr1.cc  */
#line 5995 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.sval) = (yysemantic_stack_[(2) - (2)].sval);
        }
    break;

  case 726:
/* Line 670 of lalr1.cc  */
#line 6002 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = NULL;
        }
    break;

  case 727:
/* Line 670 of lalr1.cc  */
#line 6006 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = (yysemantic_stack_[(2) - (1)].node);
        }
    break;

  case 728:
/* Line 670 of lalr1.cc  */
#line 6014 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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
/* Line 670 of lalr1.cc  */
#line 6023 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, (yysemantic_stack_[(4) - (4)].incl_excl_list), ft_stop_words_mode::with_default
            );
            delete (yysemantic_stack_[(4) - (4)].incl_excl_list);
        }
    break;

  case 730:
/* Line 670 of lalr1.cc  */
#line 6030 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordOption(
                LOC((yyloc)), NULL, NULL, ft_stop_words_mode::without
            );
        }
    break;

  case 731:
/* Line 670 of lalr1.cc  */
#line 6040 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)), NULL );
        }
    break;

  case 732:
/* Line 670 of lalr1.cc  */
#line 6044 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWords( LOC((yyloc)), "", (yysemantic_stack_[(3) - (2)].strlist) );
        }
    break;

  case 733:
/* Line 670 of lalr1.cc  */
#line 6051 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            string_list_t *sl = new string_list_t;
            sl->push_back( SYMTAB((yysemantic_stack_[(1) - (1)].sval)) );
            (yyval.strlist) = sl;
        }
    break;

  case 734:
/* Line 670 of lalr1.cc  */
#line 6057 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            if ( (yysemantic_stack_[(3) - (1)].strlist) )
                (yysemantic_stack_[(3) - (1)].strlist)->push_back( SYMTAB((yysemantic_stack_[(3) - (3)].sval)) );
            (yyval.strlist) = (yysemantic_stack_[(3) - (1)].strlist);
        }
    break;

  case 735:
/* Line 670 of lalr1.cc  */
#line 6066 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = NULL;
        }
    break;

  case 736:
/* Line 670 of lalr1.cc  */
#line 6070 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = (yysemantic_stack_[(1) - (1)].incl_excl_list);
        }
    break;

  case 737:
/* Line 670 of lalr1.cc  */
#line 6077 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.incl_excl_list) = new FTStopWordOption::incl_excl_list_t;
            (yyval.incl_excl_list)->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(1) - (1)].node)) );
        }
    break;

  case 738:
/* Line 670 of lalr1.cc  */
#line 6082 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            FTStopWordOption::incl_excl_list_t *iel = (yysemantic_stack_[(2) - (1)].incl_excl_list);
            if ( !iel )
                iel = new FTStopWordOption::incl_excl_list_t;
            iel->push_back( dynamic_cast<FTStopWordsInclExcl*>((yysemantic_stack_[(2) - (2)].node)) );
            (yyval.incl_excl_list) = iel;
        }
    break;

  case 739:
/* Line 670 of lalr1.cc  */
#line 6094 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::union_
            );
        }
    break;

  case 740:
/* Line 670 of lalr1.cc  */
#line 6102 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTStopWordsInclExcl(
                LOC((yyloc)),
                dynamic_cast<FTStopWords*>((yysemantic_stack_[(2) - (2)].node)),
                ft_stop_words_unex::except
            );
        }
    break;

  case 741:
/* Line 670 of lalr1.cc  */
#line 6114 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTLanguageOption( LOC((yyloc)), SYMTAB((yysemantic_stack_[(2) - (2)].sval)) );
        }
    break;

  case 742:
/* Line 670 of lalr1.cc  */
#line 6122 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::with );
        }
    break;

  case 743:
/* Line 670 of lalr1.cc  */
#line 6126 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTWildCardOption( LOC((yyloc)), ft_wild_card_mode::without );
        }
    break;

  case 744:
/* Line 670 of lalr1.cc  */
#line 6134 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_start );
        }
    break;

  case 745:
/* Line 670 of lalr1.cc  */
#line 6138 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::at_end );
        }
    break;

  case 746:
/* Line 670 of lalr1.cc  */
#line 6142 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTContent( LOC((yyloc)), ft_content_mode::entire );
        }
    break;

  case 747:
/* Line 670 of lalr1.cc  */
#line 6150 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTTimes( LOC((yyloc)), dynamic_cast<FTRange*>((yysemantic_stack_[(3) - (2)].node)) );
        }
    break;

  case 748:
/* Line 670 of lalr1.cc  */
#line 6158 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::exactly, (yysemantic_stack_[(2) - (2)].expr) );
        }
    break;

  case 749:
/* Line 670 of lalr1.cc  */
#line 6162 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_least, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 750:
/* Line 670 of lalr1.cc  */
#line 6166 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::at_most, (yysemantic_stack_[(3) - (3)].expr) );
        }
    break;

  case 751:
/* Line 670 of lalr1.cc  */
#line 6170 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTRange( LOC((yyloc)), ft_range_mode::from_to, (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr) );
        }
    break;

  case 752:
/* Line 670 of lalr1.cc  */
#line 6178 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::same,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 753:
/* Line 670 of lalr1.cc  */
#line 6186 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTScope(
                LOC((yyloc)),
                ft_scope::different,
                dynamic_cast<FTBigUnit*>((yysemantic_stack_[(2) - (2)].node))
            );
        }
    break;

  case 754:
/* Line 670 of lalr1.cc  */
#line 6198 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::sentence );
        }
    break;

  case 755:
/* Line 670 of lalr1.cc  */
#line 6202 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTBigUnit( LOC((yyloc)), ft_big_unit::paragraph );
        }
    break;

  case 756:
/* Line 670 of lalr1.cc  */
#line 6210 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
            (yyval.node) = new FTIgnoreOption( LOC((yyloc)), static_cast<UnionExpr*>((yysemantic_stack_[(3) - (3)].expr)) );
        }
    break;

  case 757:
/* Line 670 of lalr1.cc  */
#line 6216 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), NULL );
        }
    break;

  case 758:
/* Line 670 of lalr1.cc  */
#line 6220 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayConstructor( LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr) );
        }
    break;

  case 759:
/* Line 670 of lalr1.cc  */
#line 6227 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, false);
        }
    break;

  case 760:
/* Line 670 of lalr1.cc  */
#line 6232 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), false);
        }
    break;

  case 761:
/* Line 670 of lalr1.cc  */
#line 6240 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), NULL, true);
        }
    break;

  case 762:
/* Line 670 of lalr1.cc  */
#line 6245 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {

          (yyval.expr) = new JSONObjectConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (2)].expr), true);
        }
    break;

  case 763:
/* Line 670 of lalr1.cc  */
#line 6254 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONDirectObjectConstructor(LOC((yyloc)),
                                               dynamic_cast<JSONPairList*>((yysemantic_stack_[(3) - (2)].node)));
        }
    break;

  case 764:
/* Line 670 of lalr1.cc  */
#line 6263 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(3) - (1)].sval)) );
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 765:
/* Line 670 of lalr1.cc  */
#line 6272 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = new JSONPairList(LOC((yyloc)));
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(3) - (1)].expr), (yysemantic_stack_[(3) - (3)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 766:
/* Line 670 of lalr1.cc  */
#line 6278 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 767:
/* Line 670 of lalr1.cc  */
#line 6286 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          JSONPairList* jpl = dynamic_cast<JSONPairList*>((yysemantic_stack_[(5) - (1)].node));
          assert(jpl);
          StringLiteral* sl = new StringLiteral( LOC((yyloc)), SYMTAB((yysemantic_stack_[(5) - (3)].sval)) );
          jpl->push_back(new JSONPairConstructor(LOC((yyloc)), sl, (yysemantic_stack_[(5) - (5)].expr)));
          (yyval.node) = jpl;
        }
    break;

  case 768:
/* Line 670 of lalr1.cc  */
#line 6298 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(5) - (3)].expr),
                                        (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 769:
/* Line 670 of lalr1.cc  */
#line 6304 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 770:
/* Line 670 of lalr1.cc  */
#line 6314 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(8) - (3)].expr), (yysemantic_stack_[(8) - (5)].expr), (yysemantic_stack_[(8) - (8)].expr));
        }
    break;

  case 771:
/* Line 670 of lalr1.cc  */
#line 6319 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONObjectInsertExpr(LOC((yyloc)),
                                        (yysemantic_stack_[(4) - (2)].expr),
                                        (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 772:
/* Line 670 of lalr1.cc  */
#line 6325 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 773:
/* Line 670 of lalr1.cc  */
#line 6335 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayInsertExpr(LOC((yyloc)), (yysemantic_stack_[(7) - (2)].expr), (yysemantic_stack_[(7) - (4)].expr), (yysemantic_stack_[(7) - (7)].expr));
        }
    break;

  case 774:
/* Line 670 of lalr1.cc  */
#line 6343 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(5) - (3)].expr), (yysemantic_stack_[(5) - (5)].expr));
        }
    break;

  case 775:
/* Line 670 of lalr1.cc  */
#line 6348 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.expr) = new JSONArrayAppendExpr(LOC((yyloc)), (yysemantic_stack_[(4) - (2)].expr), (yysemantic_stack_[(4) - (4)].expr));
        }
    break;

  case 776:
/* Line 670 of lalr1.cc  */
#line 6356 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 777:
/* Line 670 of lalr1.cc  */
#line 6379 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 778:
/* Line 670 of lalr1.cc  */
#line 6405 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 779:
/* Line 670 of lalr1.cc  */
#line 6431 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 780:
/* Line 670 of lalr1.cc  */
#line 6460 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 781:
/* Line 670 of lalr1.cc  */
#line 6486 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 782:
/* Line 670 of lalr1.cc  */
#line 6515 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 783:
/* Line 670 of lalr1.cc  */
#line 6519 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 784:
/* Line 670 of lalr1.cc  */
#line 6523 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = (yysemantic_stack_[(1) - (1)].node);
        }
    break;

  case 785:
/* Line 670 of lalr1.cc  */
#line 6530 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 786:
/* Line 670 of lalr1.cc  */
#line 6535 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonItem);
        }
    break;

  case 787:
/* Line 670 of lalr1.cc  */
#line 6543 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 788:
/* Line 670 of lalr1.cc  */
#line 6548 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonObject);
        }
    break;

  case 789:
/* Line 670 of lalr1.cc  */
#line 6556 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 790:
/* Line 670 of lalr1.cc  */
#line 6561 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    {
          (yyval.node) = new JSON_Test(LOC((yyloc)), store::StoreConsts::jsonArray);
        }
    break;

  case 793:
/* Line 670 of lalr1.cc  */
#line 6579 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
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

  case 795:
/* Line 670 of lalr1.cc  */
#line 6592 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("attribute"))); }
    break;

  case 796:
/* Line 670 of lalr1.cc  */
#line 6593 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("comment"))); }
    break;

  case 797:
/* Line 670 of lalr1.cc  */
#line 6594 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document-node"))); }
    break;

  case 798:
/* Line 670 of lalr1.cc  */
#line 6595 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace-node"))); }
    break;

  case 799:
/* Line 670 of lalr1.cc  */
#line 6596 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("element"))); }
    break;

  case 800:
/* Line 670 of lalr1.cc  */
#line 6600 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("if"))); }
    break;

  case 801:
/* Line 670 of lalr1.cc  */
#line 6601 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("node"))); }
    break;

  case 802:
/* Line 670 of lalr1.cc  */
#line 6602 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("processing-instruction"))); }
    break;

  case 803:
/* Line 670 of lalr1.cc  */
#line 6603 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-attribute"))); }
    break;

  case 804:
/* Line 670 of lalr1.cc  */
#line 6604 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema-element"))); }
    break;

  case 805:
/* Line 670 of lalr1.cc  */
#line 6605 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("text"))); }
    break;

  case 806:
/* Line 670 of lalr1.cc  */
#line 6606 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("typeswitch"))); }
    break;

  case 807:
/* Line 670 of lalr1.cc  */
#line 6607 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("switch"))); }
    break;

  case 808:
/* Line 670 of lalr1.cc  */
#line 6608 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty-sequence"))); }
    break;

  case 809:
/* Line 670 of lalr1.cc  */
#line 6609 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("while"))); }
    break;

  case 811:
/* Line 670 of lalr1.cc  */
#line 6614 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval))); }
    break;

  case 812:
/* Line 670 of lalr1.cc  */
#line 6615 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("xquery"))); }
    break;

  case 813:
/* Line 670 of lalr1.cc  */
#line 6616 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("empty"))); }
    break;

  case 814:
/* Line 670 of lalr1.cc  */
#line 6617 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("boundary-space"))); }
    break;

  case 815:
/* Line 670 of lalr1.cc  */
#line 6618 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ft-option"))); }
    break;

  case 816:
/* Line 670 of lalr1.cc  */
#line 6619 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("base-uri"))); }
    break;

  case 817:
/* Line 670 of lalr1.cc  */
#line 6620 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lax"))); }
    break;

  case 818:
/* Line 670 of lalr1.cc  */
#line 6621 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strict"))); }
    break;

  case 819:
/* Line 670 of lalr1.cc  */
#line 6622 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("idiv"))); }
    break;

  case 820:
/* Line 670 of lalr1.cc  */
#line 6623 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("document"))); }
    break;

  case 821:
/* Line 670 of lalr1.cc  */
#line 6624 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ftnot"))); }
    break;

  case 822:
/* Line 670 of lalr1.cc  */
#line 6625 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("not"))); }
    break;

  case 823:
/* Line 670 of lalr1.cc  */
#line 6626 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sensitive"))); }
    break;

  case 824:
/* Line 670 of lalr1.cc  */
#line 6627 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("insensitive"))); }
    break;

  case 825:
/* Line 670 of lalr1.cc  */
#line 6628 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("diacritics"))); }
    break;

  case 826:
/* Line 670 of lalr1.cc  */
#line 6629 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("without"))); }
    break;

  case 827:
/* Line 670 of lalr1.cc  */
#line 6630 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stemming"))); }
    break;

  case 828:
/* Line 670 of lalr1.cc  */
#line 6631 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("thesaurus"))); }
    break;

  case 829:
/* Line 670 of lalr1.cc  */
#line 6632 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stop"))); }
    break;

  case 830:
/* Line 670 of lalr1.cc  */
#line 6633 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("wildcards"))); }
    break;

  case 831:
/* Line 670 of lalr1.cc  */
#line 6634 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("entire"))); }
    break;

  case 832:
/* Line 670 of lalr1.cc  */
#line 6635 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("content"))); }
    break;

  case 833:
/* Line 670 of lalr1.cc  */
#line 6636 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("word"))); }
    break;

  case 834:
/* Line 670 of lalr1.cc  */
#line 6637 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("start"))); }
    break;

  case 835:
/* Line 670 of lalr1.cc  */
#line 6638 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("end"))); }
    break;

  case 836:
/* Line 670 of lalr1.cc  */
#line 6639 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("most"))); }
    break;

  case 837:
/* Line 670 of lalr1.cc  */
#line 6640 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("skip"))); }
    break;

  case 838:
/* Line 670 of lalr1.cc  */
#line 6641 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy"))); }
    break;

  case 839:
/* Line 670 of lalr1.cc  */
#line 6642 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("general"))); }
    break;

  case 840:
/* Line 670 of lalr1.cc  */
#line 6643 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("value"))); }
    break;

  case 841:
/* Line 670 of lalr1.cc  */
#line 6644 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("eq"))); }
    break;

  case 842:
/* Line 670 of lalr1.cc  */
#line 6645 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ne"))); }
    break;

  case 843:
/* Line 670 of lalr1.cc  */
#line 6646 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lt"))); }
    break;

  case 844:
/* Line 670 of lalr1.cc  */
#line 6647 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("le"))); }
    break;

  case 845:
/* Line 670 of lalr1.cc  */
#line 6648 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("gt"))); }
    break;

  case 846:
/* Line 670 of lalr1.cc  */
#line 6649 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ge"))); }
    break;

  case 847:
/* Line 670 of lalr1.cc  */
#line 6650 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("at"))); }
    break;

  case 848:
/* Line 670 of lalr1.cc  */
#line 6651 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("context"))); }
    break;

  case 849:
/* Line 670 of lalr1.cc  */
#line 6652 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("variable"))); }
    break;

  case 850:
/* Line 670 of lalr1.cc  */
#line 6653 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("return"))); }
    break;

  case 851:
/* Line 670 of lalr1.cc  */
#line 6654 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("for"))); }
    break;

  case 852:
/* Line 670 of lalr1.cc  */
#line 6655 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("allowing"))); }
    break;

  case 853:
/* Line 670 of lalr1.cc  */
#line 6656 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sliding"))); }
    break;

  case 854:
/* Line 670 of lalr1.cc  */
#line 6657 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("tumbling"))); }
    break;

  case 855:
/* Line 670 of lalr1.cc  */
#line 6658 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("previous"))); }
    break;

  case 856:
/* Line 670 of lalr1.cc  */
#line 6659 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("next"))); }
    break;

  case 857:
/* Line 670 of lalr1.cc  */
#line 6660 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("only"))); }
    break;

  case 858:
/* Line 670 of lalr1.cc  */
#line 6661 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("when"))); }
    break;

  case 859:
/* Line 670 of lalr1.cc  */
#line 6662 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("count"))); }
    break;

  case 860:
/* Line 670 of lalr1.cc  */
#line 6663 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("in"))); }
    break;

  case 861:
/* Line 670 of lalr1.cc  */
#line 6664 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("let"))); }
    break;

  case 862:
/* Line 670 of lalr1.cc  */
#line 6665 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("where"))); }
    break;

  case 863:
/* Line 670 of lalr1.cc  */
#line 6666 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("by"))); }
    break;

  case 864:
/* Line 670 of lalr1.cc  */
#line 6667 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("group"))); }
    break;

  case 865:
/* Line 670 of lalr1.cc  */
#line 6668 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("order"))); }
    break;

  case 866:
/* Line 670 of lalr1.cc  */
#line 6669 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("stable"))); }
    break;

  case 867:
/* Line 670 of lalr1.cc  */
#line 6670 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ascending"))); }
    break;

  case 868:
/* Line 670 of lalr1.cc  */
#line 6671 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descending"))); }
    break;

  case 869:
/* Line 670 of lalr1.cc  */
#line 6672 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("greatest"))); }
    break;

  case 870:
/* Line 670 of lalr1.cc  */
#line 6673 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("least"))); }
    break;

  case 871:
/* Line 670 of lalr1.cc  */
#line 6674 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collation"))); }
    break;

  case 872:
/* Line 670 of lalr1.cc  */
#line 6675 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("some"))); }
    break;

  case 873:
/* Line 670 of lalr1.cc  */
#line 6676 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("every"))); }
    break;

  case 874:
/* Line 670 of lalr1.cc  */
#line 6677 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("satisfies"))); }
    break;

  case 875:
/* Line 670 of lalr1.cc  */
#line 6678 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("case"))); }
    break;

  case 876:
/* Line 670 of lalr1.cc  */
#line 6679 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("as"))); }
    break;

  case 877:
/* Line 670 of lalr1.cc  */
#line 6680 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("then"))); }
    break;

  case 878:
/* Line 670 of lalr1.cc  */
#line 6681 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("else"))); }
    break;

  case 879:
/* Line 670 of lalr1.cc  */
#line 6682 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("or"))); }
    break;

  case 880:
/* Line 670 of lalr1.cc  */
#line 6683 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("and"))); }
    break;

  case 881:
/* Line 670 of lalr1.cc  */
#line 6684 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("instance"))); }
    break;

  case 882:
/* Line 670 of lalr1.cc  */
#line 6685 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("of"))); }
    break;

  case 883:
/* Line 670 of lalr1.cc  */
#line 6686 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("castable"))); }
    break;

  case 884:
/* Line 670 of lalr1.cc  */
#line 6687 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("to"))); }
    break;

  case 885:
/* Line 670 of lalr1.cc  */
#line 6688 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("div"))); }
    break;

  case 886:
/* Line 670 of lalr1.cc  */
#line 6689 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mod"))); }
    break;

  case 887:
/* Line 670 of lalr1.cc  */
#line 6690 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("union"))); }
    break;

  case 888:
/* Line 670 of lalr1.cc  */
#line 6691 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("intersect"))); }
    break;

  case 889:
/* Line 670 of lalr1.cc  */
#line 6692 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("except"))); }
    break;

  case 890:
/* Line 670 of lalr1.cc  */
#line 6693 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("validate"))); }
    break;

  case 891:
/* Line 670 of lalr1.cc  */
#line 6694 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("type"))); }
    break;

  case 892:
/* Line 670 of lalr1.cc  */
#line 6695 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("cast"))); }
    break;

  case 893:
/* Line 670 of lalr1.cc  */
#line 6696 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("treat"))); }
    break;

  case 894:
/* Line 670 of lalr1.cc  */
#line 6697 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("is"))); }
    break;

  case 895:
/* Line 670 of lalr1.cc  */
#line 6698 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preserve"))); }
    break;

  case 896:
/* Line 670 of lalr1.cc  */
#line 6699 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("strip"))); }
    break;

  case 897:
/* Line 670 of lalr1.cc  */
#line 6700 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("namespace"))); }
    break;

  case 898:
/* Line 670 of lalr1.cc  */
#line 6701 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("external"))); }
    break;

  case 899:
/* Line 670 of lalr1.cc  */
#line 6702 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("encoding"))); }
    break;

  case 900:
/* Line 670 of lalr1.cc  */
#line 6703 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-preserve"))); }
    break;

  case 901:
/* Line 670 of lalr1.cc  */
#line 6704 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("inherit"))); }
    break;

  case 902:
/* Line 670 of lalr1.cc  */
#line 6705 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("no-inherit"))); }
    break;

  case 903:
/* Line 670 of lalr1.cc  */
#line 6706 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("declare"))); }
    break;

  case 904:
/* Line 670 of lalr1.cc  */
#line 6707 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("construction"))); }
    break;

  case 905:
/* Line 670 of lalr1.cc  */
#line 6708 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordering"))); }
    break;

  case 906:
/* Line 670 of lalr1.cc  */
#line 6709 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("default"))); }
    break;

  case 907:
/* Line 670 of lalr1.cc  */
#line 6710 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("copy-namespaces"))); }
    break;

  case 908:
/* Line 670 of lalr1.cc  */
#line 6711 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("option"))); }
    break;

  case 909:
/* Line 670 of lalr1.cc  */
#line 6712 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("version"))); }
    break;

  case 910:
/* Line 670 of lalr1.cc  */
#line 6713 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("import"))); }
    break;

  case 911:
/* Line 670 of lalr1.cc  */
#line 6714 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("schema"))); }
    break;

  case 912:
/* Line 670 of lalr1.cc  */
#line 6715 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("module"))); }
    break;

  case 913:
/* Line 670 of lalr1.cc  */
#line 6716 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("function"))); }
    break;

  case 914:
/* Line 670 of lalr1.cc  */
#line 6717 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("score"))); }
    break;

  case 915:
/* Line 670 of lalr1.cc  */
#line 6718 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("contains"))); }
    break;

  case 916:
/* Line 670 of lalr1.cc  */
#line 6719 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("weight"))); }
    break;

  case 917:
/* Line 670 of lalr1.cc  */
#line 6720 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("window"))); }
    break;

  case 918:
/* Line 670 of lalr1.cc  */
#line 6721 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("distance"))); }
    break;

  case 919:
/* Line 670 of lalr1.cc  */
#line 6722 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("occurs"))); }
    break;

  case 920:
/* Line 670 of lalr1.cc  */
#line 6723 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("times"))); }
    break;

  case 921:
/* Line 670 of lalr1.cc  */
#line 6724 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("same"))); }
    break;

  case 922:
/* Line 670 of lalr1.cc  */
#line 6725 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("different"))); }
    break;

  case 923:
/* Line 670 of lalr1.cc  */
#line 6726 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("lowercase"))); }
    break;

  case 924:
/* Line 670 of lalr1.cc  */
#line 6727 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("uppercase"))); }
    break;

  case 925:
/* Line 670 of lalr1.cc  */
#line 6728 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("relationship"))); }
    break;

  case 926:
/* Line 670 of lalr1.cc  */
#line 6729 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("levels"))); }
    break;

  case 927:
/* Line 670 of lalr1.cc  */
#line 6730 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("language"))); }
    break;

  case 928:
/* Line 670 of lalr1.cc  */
#line 6731 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("any"))); }
    break;

  case 929:
/* Line 670 of lalr1.cc  */
#line 6732 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("all"))); }
    break;

  case 930:
/* Line 670 of lalr1.cc  */
#line 6733 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exactly"))); }
    break;

  case 931:
/* Line 670 of lalr1.cc  */
#line 6734 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("from"))); }
    break;

  case 932:
/* Line 670 of lalr1.cc  */
#line 6735 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("words"))); }
    break;

  case 933:
/* Line 670 of lalr1.cc  */
#line 6736 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentences"))); }
    break;

  case 934:
/* Line 670 of lalr1.cc  */
#line 6737 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sentence"))); }
    break;

  case 935:
/* Line 670 of lalr1.cc  */
#line 6738 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("phrase"))); }
    break;

  case 936:
/* Line 670 of lalr1.cc  */
#line 6739 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraph"))); }
    break;

  case 937:
/* Line 670 of lalr1.cc  */
#line 6740 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("paragraphs"))); }
    break;

  case 938:
/* Line 670 of lalr1.cc  */
#line 6741 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("modify"))); }
    break;

  case 939:
/* Line 670 of lalr1.cc  */
#line 6742 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("first"))); }
    break;

  case 940:
/* Line 670 of lalr1.cc  */
#line 6749 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("before"))); }
    break;

  case 941:
/* Line 670 of lalr1.cc  */
#line 6750 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("after"))); }
    break;

  case 942:
/* Line 670 of lalr1.cc  */
#line 6751 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("revalidation"))); }
    break;

  case 943:
/* Line 670 of lalr1.cc  */
#line 6752 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("with"))); }
    break;

  case 944:
/* Line 670 of lalr1.cc  */
#line 6753 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("nodes"))); }
    break;

  case 945:
/* Line 670 of lalr1.cc  */
#line 6754 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("last"))); }
    break;

  case 946:
/* Line 670 of lalr1.cc  */
#line 6755 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("into"))); }
    break;

  case 947:
/* Line 670 of lalr1.cc  */
#line 6756 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("simple"))); }
    break;

  case 948:
/* Line 670 of lalr1.cc  */
#line 6757 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("sequential"))); }
    break;

  case 949:
/* Line 670 of lalr1.cc  */
#line 6758 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("updating"))); }
    break;

  case 950:
/* Line 670 of lalr1.cc  */
#line 6759 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ordered"))); }
    break;

  case 951:
/* Line 670 of lalr1.cc  */
#line 6760 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unordered"))); }
    break;

  case 952:
/* Line 670 of lalr1.cc  */
#line 6761 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("returning"))); }
    break;

  case 953:
/* Line 670 of lalr1.cc  */
#line 6762 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("exit"))); }
    break;

  case 954:
/* Line 670 of lalr1.cc  */
#line 6763 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("loop"))); }
    break;

  case 955:
/* Line 670 of lalr1.cc  */
#line 6764 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("break"))); }
    break;

  case 956:
/* Line 670 of lalr1.cc  */
#line 6765 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("continue"))); }
    break;

  case 957:
/* Line 670 of lalr1.cc  */
#line 6766 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("try"))); }
    break;

  case 958:
/* Line 670 of lalr1.cc  */
#line 6767 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("catch"))); }
    break;

  case 959:
/* Line 670 of lalr1.cc  */
#line 6768 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("using"))); }
    break;

  case 960:
/* Line 670 of lalr1.cc  */
#line 6769 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("set"))); }
    break;

  case 961:
/* Line 670 of lalr1.cc  */
#line 6770 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("index"))); }
    break;

  case 962:
/* Line 670 of lalr1.cc  */
#line 6771 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("unique"))); }
    break;

  case 963:
/* Line 670 of lalr1.cc  */
#line 6772 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("non"))); }
    break;

  case 964:
/* Line 670 of lalr1.cc  */
#line 6773 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("on"))); }
    break;

  case 965:
/* Line 670 of lalr1.cc  */
#line 6774 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("range"))); }
    break;

  case 966:
/* Line 670 of lalr1.cc  */
#line 6775 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("equality"))); }
    break;

  case 967:
/* Line 670 of lalr1.cc  */
#line 6776 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("manually"))); }
    break;

  case 968:
/* Line 670 of lalr1.cc  */
#line 6777 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("automatically"))); }
    break;

  case 969:
/* Line 670 of lalr1.cc  */
#line 6778 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("maintained"))); }
    break;

  case 970:
/* Line 670 of lalr1.cc  */
#line 6779 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-format"))); }
    break;

  case 971:
/* Line 670 of lalr1.cc  */
#line 6780 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("decimal-separator"))); }
    break;

  case 972:
/* Line 670 of lalr1.cc  */
#line 6781 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("grouping-separator"))); }
    break;

  case 973:
/* Line 670 of lalr1.cc  */
#line 6782 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("infinity"))); }
    break;

  case 974:
/* Line 670 of lalr1.cc  */
#line 6783 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("minus-sign"))); }
    break;

  case 975:
/* Line 670 of lalr1.cc  */
#line 6784 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("NaN"))); }
    break;

  case 976:
/* Line 670 of lalr1.cc  */
#line 6785 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("percent"))); }
    break;

  case 977:
/* Line 670 of lalr1.cc  */
#line 6786 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("per-mille"))); }
    break;

  case 978:
/* Line 670 of lalr1.cc  */
#line 6787 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("zero-digit"))); }
    break;

  case 979:
/* Line 670 of lalr1.cc  */
#line 6788 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("digit"))); }
    break;

  case 980:
/* Line 670 of lalr1.cc  */
#line 6789 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("pattern-separator"))); }
    break;

  case 981:
/* Line 670 of lalr1.cc  */
#line 6790 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("collection"))); }
    break;

  case 982:
/* Line 670 of lalr1.cc  */
#line 6791 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("const"))); }
    break;

  case 983:
/* Line 670 of lalr1.cc  */
#line 6792 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("append-only"))); }
    break;

  case 984:
/* Line 670 of lalr1.cc  */
#line 6793 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("queue"))); }
    break;

  case 985:
/* Line 670 of lalr1.cc  */
#line 6794 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("mutable"))); }
    break;

  case 986:
/* Line 670 of lalr1.cc  */
#line 6795 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("read-only"))); }
    break;

  case 987:
/* Line 670 of lalr1.cc  */
#line 6796 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("integrity"))); }
    break;

  case 988:
/* Line 670 of lalr1.cc  */
#line 6797 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("constraint"))); }
    break;

  case 989:
/* Line 670 of lalr1.cc  */
#line 6798 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("check"))); }
    break;

  case 990:
/* Line 670 of lalr1.cc  */
#line 6799 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("key"))); }
    break;

  case 991:
/* Line 670 of lalr1.cc  */
#line 6800 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreach"))); }
    break;

  case 992:
/* Line 670 of lalr1.cc  */
#line 6801 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("foreign"))); }
    break;

  case 993:
/* Line 670 of lalr1.cc  */
#line 6802 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("keys"))); }
    break;

  case 994:
/* Line 670 of lalr1.cc  */
#line 6803 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor"))); }
    break;

  case 995:
/* Line 670 of lalr1.cc  */
#line 6804 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("child"))); }
    break;

  case 996:
/* Line 670 of lalr1.cc  */
#line 6805 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant"))); }
    break;

  case 997:
/* Line 670 of lalr1.cc  */
#line 6806 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("parent"))); }
    break;

  case 998:
/* Line 670 of lalr1.cc  */
#line 6807 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding"))); }
    break;

  case 999:
/* Line 670 of lalr1.cc  */
#line 6808 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("self"))); }
    break;

  case 1000:
/* Line 670 of lalr1.cc  */
#line 6809 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following"))); }
    break;

  case 1001:
/* Line 670 of lalr1.cc  */
#line 6810 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("ancestor-or-self"))); }
    break;

  case 1002:
/* Line 670 of lalr1.cc  */
#line 6811 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("descendant-or-self"))); }
    break;

  case 1003:
/* Line 670 of lalr1.cc  */
#line 6812 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("following-sibling"))); }
    break;

  case 1004:
/* Line 670 of lalr1.cc  */
#line 6813 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("preceding-sibling"))); }
    break;

  case 1005:
/* Line 670 of lalr1.cc  */
#line 6814 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB(SYMTAB_PUT("position"))); }
    break;

  case 1006:
/* Line 670 of lalr1.cc  */
#line 6819 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"
    { (yyval.expr) = new QName(LOC((yyloc)), SYMTAB((yysemantic_stack_[(1) - (1)].sval)), true); }
    break;


/* Line 670 of lalr1.cc  */
#line 10658 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
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
    while (1 < yystate_stack_.height ())
      {
        yydestruct_ ("Cleanup: popping",
                     yystos_[yystate_stack_[0]],
                     &yysemantic_stack_[0],
                     &yylocation_stack_[0]);
        yypop_ ();
      }

    return yyresult;
    }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (yychar != yyempty_)
          {
            /* Make sure we have latest lookahead translation.  See
               comments at user semantic actions for why this is
               necessary.  */
            yytoken = yytranslate_ (yychar);
            yydestruct_ (YY_NULL, yytoken, &yylval, &yylloc);
          }

        while (1 < yystate_stack_.height ())
          {
            yydestruct_ (YY_NULL,
                         yystos_[yystate_stack_[0]],
                         &yysemantic_stack_[0],
                         &yylocation_stack_[0]);
            yypop_ ();
          }
        throw;
      }
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
  const short int jsoniq_parser::yypact_ninf_ = -1500;
  const short int
  jsoniq_parser::yypact_[] =
  {
      4843,  8170,  8170,  8170,  8170, -1500, -1500,   -13,    53, -1500,
     585,    11, -1500, -1500, -1500,    24, -1500, -1500, -1500,   184,
     248,   740,   336,   428,   622, -1500,   -23, -1500, -1500, -1500,
   -1500, -1500, -1500,   321, -1500, -1500, -1500, -1500, -1500,   565,
   -1500,   550, -1500,   604,   634, -1500,   426, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500,   671, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500,   725, -1500, -1500, -1500, -1500,
   -1500, 18334, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
     756, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500,  5459, 10284, 10586, 18334, -1500, -1500,   724, -1500, -1500,
   -1500, -1500,   779, -1500, -1500, -1500,  6966, -1500,  7264, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500,   800, -1500, -1500, -1500, -1500, -1500, -1500, -1500,   150,
     747,   786, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, 13908,  5762, -1500, 14210,   229, -1500, -1500,
   -1500, -1500, -1500, -1500,   893, -1500,   775,   778,   801, -1500,
   -1500,   911,   915, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500,   741, -1500, 14512, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, 10888, 11190, 11492, -1500,
    5151,  7566,  1072, -1500,  8472, -1500, -1500,   417,    90, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500,    97, -1500, -1500, -1500, -1500, -1500, -1500,
     399, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,  8170,
   -1500, -1500, -1500, -1500,    10, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500,   124, -1500,   882, -1500, -1500, -1500,
     136, -1500,   561, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
     904,   983, -1500, -1500,   851,   824,   979,   668,   677,   805,
     477, -1500,  1030,   880,   980,   985, 13002, -1500,   889, -1500,
   -1500,   687, -1500, -1500, -1500, -1500,   701, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
     815, -1500, -1500, -1500, -1500, -1500,   905, -1500,  8170,   908,
     909,   910,  8170,   200,   200,  1067,   733,   746,   738, 18625,
   18334,   646,  1050, 18334,   945,   981,   697,  6966,   764,   850,
   18334, 18334,   793,   737,    46, -1500, -1500, -1500,  6966,  8170,
    8170, 12398,   431,   948, 12398,  1104,    63,   361, 18334,   986,
     962,   999, -1500, 12398, 18334,  8170, 12398, 12398, 18334,  8170,
     953,   954, 12398, 18334, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,   966, -1500,
   18334, -1500,    24,   248,   428,   321,   550,   604,   634,   671,
     911,   926,  7868,   990,    12,   991, -1500,   815,   957,   958,
     959, 18334,  5459, -1500,   963,   148, -1500,   598, -1500,   130,
    1084, 12398, 12398,   174, -1500, -1500,  1105, 12398,   907, -1500,
    1091,  1094, 12398, 12700, 15116,   701,   957,   958,   959, 12398,
   12700,  6065,   -28,    -4, 12398, 15116,   342, 12398,   888,   891,
   18334,   937,   939, 12398, 12398,  8170,   885, -1500, -1500,    61,
   -1500,    56, 12398,   895,  7566, -1500, -1500, -1500, -1500, -1500,
     585,   622,    99,   106,  1129,  8774,  3282,  9076,  3601,   725,
   -1500, -1500,   128,   725, -1500, 12398,  4233, -1500,  1015, -1500,
     -23,   968,   967,   969,  8170, 12398, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, 18334, -1500,   852,   853, 18334,
    1024, 13304, 13304, -1500, -1500, -1500, -1500, -1500, -1500, 13606,
    1073, 13606, 13606, 13606, 13606, 13606, 13606, 13606, 13606, 13606,
   13606, 13606, 13606,   912,  1051,  1054,  1055, -1500, -1500, -1500,
   15116, 11794, -1500,  6366, 12398,  9680,   989, -1500,  1000,  9982,
   -1500, -1500, -1500, -1500,   273, -1500,   286, -1500, -1500, -1500,
   -1500, -1500, -1500,  1044,  1045,   336,  1125, -1500, -1500, 18625,
     950,   688, 18334,   993,   994,   950,  1067,  1028,  1025, -1500,
   -1500, -1500,   158,   914,  1063,   856, 18334,  1017, 12398,  1043,
   18334, 18334, -1500,  1032,   982,   988,   122, 18334,  1075,   320,
   -1500,  8170, -1500,   153, -1500,  6966,  1074,  1130,  6966,  1067,
    1080,   606, 18334, 12398,   -23,   163,   292, -1500,   307,   997,
     154,   156,  1023, -1500,  1002,  8170,  8170,   222,   614, 12398,
     391, -1500, -1500, 12398,  6065, -1500, 12398, 12398, 12398, 12398,
   -1500, 12398, -1500, 12398, -1500, 18334,  1084, -1500,     4,   223,
     250, -1500, -1500, -1500,   260, -1500,    29,   444, -1500, -1500,
     701,     3,   522,    28,     8, 12398, 12398,  1089,   601, 12398,
     943, 14814,   952,     2, -1500,  1035, -1500, -1500,   998,   157,
    7868,   357,  4541,   885, -1500, -1500, -1500,   955, 12398, -1500,
     417,   692,  1157,   755, -1500, -1500,   107, -1500, -1500, -1500,
     108, -1500,    62, -1500, -1500, -1500, -1500, -1500,  3917, -1500,
   -1500, -1500, 18334,  1020, 12398,  1076, -1500, -1500, -1500,  1088,
   -1500,    44, -1500, -1500,  1088, 18334,    30,   983, -1500, -1500,
      73, -1500,   677,   677,   743,   805,   805,   805,   805,   477,
     477, -1500, -1500, 16875, 16875, 18334, 18334, -1500, -1500,   397,
   -1500, -1500, -1500, -1500,   161, -1500, -1500, -1500,   349, -1500,
   -1500, -1500,   352,   200, -1500, -1500,   758,   769,   797, -1500,
     336, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500,   950, -1500,  1065, 17168,  1057, 12398, -1500, -1500, -1500,
    1107,  1067,  1067,   950, -1500,   776,  1067,   762, 18334,   493,
     720,  1174, -1500, -1500,   913,   620, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500,   158,    87,   975,
     704, 12398, -1500, 18334,  1111,   917,  1067, -1500, -1500,  1056,
    1107, 16875,  1090,  1117,  1029,  1019,  1082,  1067,  1060,  1093,
    1126,  1067, 16875, 12398,   -41, -1500, -1500, -1500,  1070,  1109,
   12398, 12398,  1081, -1500,  1128,  1132,  8170, -1500,  1052,  1053,
    1085, 12398,  1092,  1058, 12398, -1500,  1112,  1119, -1500,   165,
     168,   171,  1208, -1500,    23, -1500,   639,  1095, -1500, -1500,
    1215, -1500,  1216, -1500,   526, 12398, 12398, 12398,   810, 12398,
   12398, 12398, 12398, 12398,  1149, -1500, 12398, 12398, -1500, 12398,
   12398,   554, 15116,  1133, 12398, 12398, -1500,  9378,   167,  1001,
   -1500, -1500, -1500, -1500, -1500, -1500,   -20, -1500, -1500, 12398,
   -1500,   112,   348,    62,  9076,  3601,  9076,  1167, -1500, -1500,
   12398,   672,  1140, -1500, 18334,  1146, -1500, 18043,  1127,  1136,
   12398,   211,  1108,    55,   532,  1003, -1500, -1500,   654,    30,
   12398,    73,   789,   736, -1500,   973,   318,   995,  1004, -1500,
   -1500,   850, -1500,   987,   637,  1106,  1110,  1113,  1114,  1115,
    1118,  1121,  1122,  1123,  1124,  1131, 15703,  1134,  1135,  1137,
    1138,  1139,  1141, -1500,   663, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,  1142, -1500,
   -1500, -1500, -1500, 12096, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500,   821, -1500,  1236, 17168,   861, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500,   976, -1500, -1500,
    1241, -1500, -1500, -1500, -1500, -1500,   642,  1248, -1500,   381,
   -1500, -1500, -1500,  1106,  1110,  1113,  1115,  1118,  1121,  1122,
    1123,  1124,  1135, -1500,   663,   663, 15116,   992,   972, -1500,
    1107,    87,  1059,  1096,  8170, -1500, -1500, -1500, 16875, -1500,
    8170,  1067,  1177, -1500, -1500, -1500,  1067,  1177, -1500, -1500,
   12398,  1150,  8170, 18334, -1500, -1500, 12398, 12398,    69, -1500,
      16,   855, -1500, 15996,   863, -1500,   881, -1500,  1101, -1500,
   -1500,  8170, -1500, 12398, -1500, -1500, 12398, 12398,  1099,  1128,
    1189, -1500,  1166, -1500,   727, -1500, -1500,  1295, -1500, -1500,
    8170, 18334, -1500,   767, -1500, -1500, -1500,  8170,  1116,  1120,
    1064,  1068, -1500, -1500, -1500,  1071,  1083, -1500, -1500, -1500,
    1206, -1500,   984, -1500, -1500, -1500,  1066, 12398,   659, 18334,
    1143, -1500,  1152,  1154,  1155,  1159, -1500,   882,   621,  4541,
    1001, -1500,  9378,  4541, -1500, -1500,  1157,   552, -1500, -1500,
   -1500,  1140, -1500,  1067, -1500,   898, -1500,   548,  1212, -1500,
   12398,    65,  1076, 18334, -1500,   544, 18334, -1500, 12398,  1171,
   12398,  1193, 12398,   268,  1175, 12398,  1176, -1500,  1204,  1209,
   12398, 18334,   874,  1249, -1500, -1500, -1500,   413,  1144, -1500,
      73,  1078, -1500, -1500,   -73, -1500,   714,   117,  1079,    73,
     714, 13606, -1500,   213, -1500, -1500, -1500, -1500, -1500, -1500,
      73,  1180,  1048,   914,   117, -1500, -1500,  1040,  1257, -1500,
   -1500, -1500,  1151,   155, 17461, 15410,  1153,  6666, 18334, 18334,
    1156, 17752,  1158, -1500,  1160,  1161,  1162,  1163,  1164,  1165,
    1168, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500,  1308,     6,  1309,     6,  1069,  1232,
   -1500, -1500,  1172, 18334,  1097, -1500, -1500, 15116, -1500,  1169,
   -1500,  1214,  1219,  1258,  1067,  1177, -1500, 12398,  1173, -1500,
   -1500, -1500,  1170, -1500,   271, 12398,  8170,  1178,   332, -1500,
   18334,   -21, -1500, 16289,    70, -1500, 16582,  1179, -1500, -1500,
    1183, -1500, -1500, -1500, 12398,   883,  1208, 18334,   847, -1500,
    1184,  1208, 18334, -1500,  1185, -1500, -1500, 12398, 12398, 12398,
   12398,  1039, 12398, 12398, -1500, 12398, -1500, 12398, 12398, 12398,
   12398,  9378,   244, -1500, -1500, -1500, -1500, -1500,  1212, -1500,
   -1500, -1500,  1067, 12398, -1500,  1217, -1500, -1500, 12398,  1213,
   -1500, -1500, 12398, -1500,   605, -1500, 12398,  1222, 12398, -1500,
   12398, 18334, 18334, -1500,   770, -1500, 12398, -1500, -1500, -1500,
    1187, 13606, -1500, -1500, -1500, -1500, -1500,    86, 13606, 13606,
     680, -1500,   995, -1500,   383, -1500,  1004,    73,  1220, -1500,
   -1500,  1100, -1500, -1500, -1500, -1500, -1500, -1500,  1186,  1190,
   -1500,   418,   443,  1268,  1191, -1500,   446, -1500,  1194, -1500,
    1198,  1199,  1200, -1500, -1500,   485,   500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500,   410,   410, -1500,     6,
   -1500, -1500,   512, -1500,  1335,    -3,  1280,  1201, 15116,   -32,
    1098,  1210, -1500,  9378, 12398,  1067, -1500, -1500, -1500, 12398,
   12398, -1500, -1500, -1500,  9378,  9378,  1297,  8170, 16875, 18334,
     282, 18334, 12398, 18334,   434,  9378, -1500,   317,    21,  1208,
   18334, -1500,  1195,  1208, -1500, -1500, -1500, -1500, -1500, 12398,
   -1500, -1500, -1500, -1500,   192,   196,   216, 12398, -1500, -1500,
   -1500,  1287, 12398, -1500, 12398, -1500, 12398,  1246, -1500, 12398,
   -1500, -1500, -1500,  1342, -1500, -1500, -1500,   805, 13606, 13606,
     743,   670, -1500, -1500, -1500, -1500, -1500, -1500, 12398, -1500,
   -1500, -1500, 18334, -1500, 18334, -1500, 16875, -1500, 16875,  1302,
   -1500, -1500, -1500, -1500, 18334, -1500, 18334, -1500, -1500, -1500,
   -1500,  1369, -1500, -1500, -1500,  1145,  1291, -1500, -1500,  1292,
   -1500,   830, 18334,  1283,  1182, 18334, 15116, -1500, -1500,  1177,
   -1500, -1500, 16875, -1500, -1500, -1500,  1311, 12398,  1221, -1500,
    1314,  9378, -1500, 18334,   475,   469, -1500,  1205,  1208, -1500,
    1223, -1500,  1218,  1128,  1132,   416, -1500,  1287, -1500, -1500,
   12398, -1500,  1285,   743,   743, 13606,   454,  1225,  1226,  1272,
    1234,  1235, -1500, -1500, 16875,  1237,  1238, -1500, -1500,  1280,
   15116, -1500,  1212,  1147, 18334,  1301,  1197,  1292,   650, 16875,
    8170, 16875,  1242, -1500, -1500,  1330,   678, -1500, -1500, -1500,
   -1500,  1244,   551, -1500, -1500, -1500,  1233, -1500,  9378,   884,
   -1500, -1500, -1500, 18334,   743, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, 12398,  1148, 18334,
    1316,  8170,   686, -1500, -1500,   693, 12398, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500,  1317, -1500, -1500,  1181,  1188, 18334,
   -1500, -1500, 12398,  9378, 18334,  1192, 12398,  1196,  1243, 15116,
   -1500, 15116,  9378, -1500,  1239,  1202, 18334,  1203,  1318, 18334,
    1207, 15116, -1500
  };

  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
     YYTABLE doesn't specify something else to do.  Zero means the
     default is an error.  */
  const unsigned short int
  jsoniq_parser::yydefact_[] =
  {
       167,   170,   170,   170,     0,   811,  1006,   122,   124,   609,
     903,   912,   852,   816,   814,     0,   904,   907,   859,   820,
       0,   260,   913,     0,   910,   881,   861,   836,   856,   857,
     908,   905,   855,     0,   911,   948,   960,   947,   853,   872,
     866,     0,   854,     0,     0,   949,   890,   891,   858,   833,
     970,   971,   972,   973,   974,   975,   976,   977,   978,   979,
     980,   994,  1001,   880,   876,   867,   847,     0,   875,   883,
     892,   995,   871,   463,   848,   849,   906,   996,  1002,   868,
     885,     0,   472,   471,   465,   878,   813,   869,   870,   899,
     873,   889,   898,  1000,  1003,   819,   860,   901,   464,   888,
     894,   170,     0,     0,     0,   400,   886,   897,   902,   900,
     879,   865,   950,   863,   864,   997,     0,   399,     0,   998,
    1004,   895,   850,   874,   999,   213,   896,   877,   884,   893,
     887,   951,   841,   846,   845,   844,   843,   842,   862,     0,
     812,     0,   909,   834,   462,   466,   467,   941,   940,   942,
     818,   817,   837,     0,     0,   944,     0,     0,   840,   882,
     939,   946,   945,   938,   838,   943,   955,   956,   953,   954,
     952,     0,   957,   958,   959,   929,   928,   915,   832,   825,
     922,   918,   835,   831,   930,   261,   821,   822,   815,   824,
     927,   926,   923,   919,   936,   937,   935,   925,   921,   914,
     823,   934,   933,   827,   829,   828,   920,   924,   916,   830,
     917,   826,   932,   981,   982,   983,   984,   985,   986,   962,
     963,   961,   967,   968,   969,   964,   965,   966,   839,   987,
     988,   989,   990,   991,   992,   993,     0,     0,     0,  1005,
     167,   167,     0,     2,   167,     9,    11,    25,     0,    30,
      33,    38,    39,    40,    41,    42,    43,    44,    34,    60,
      61,    35,    36,     0,    78,    81,    82,    37,    83,    84,
       0,   120,    85,    86,    87,    88,    20,   164,   165,   166,
     173,   176,   454,   177,     0,   178,   179,   180,   181,   182,
     183,   184,   187,   188,     0,   214,   222,   217,   249,   255,
       0,   247,     0,   248,   224,   218,   186,   219,   185,   220,
     223,   357,   359,   361,   363,   365,   367,   371,   373,   376,
     381,   384,   387,   389,   391,   393,     0,   397,   404,   403,
     405,     0,   420,   406,   425,   426,   427,   434,   445,   459,
     461,   446,   447,   448,   451,   452,   449,   453,   481,   482,
     450,   485,   487,   488,   489,   486,   534,   535,   536,   537,
     538,   539,   540,   460,    45,   225,   226,   228,   227,   229,
     221,   456,   457,   458,   455,   231,   234,   230,   232,   233,
       0,   810,   903,   912,   910,   812,     0,   168,   169,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   279,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   194,   796,   820,   797,   799,   851,
     913,   800,   861,   798,   802,   803,   804,   872,   805,   807,
     806,   890,   795,   849,   873,   897,   950,   951,   808,   801,
     838,   955,   956,   953,   809,   957,   931,   822,   468,   794,
       0,   792,   796,   799,   800,   802,   805,   807,   806,   795,
     809,     0,     0,   214,     0,     0,   793,   794,     0,     0,
       0,     0,   170,   757,   957,     0,   222,     0,   469,     0,
     501,     0,     0,     0,   423,   424,     0,     0,     0,   530,
       0,     0,     0,   944,     0,   777,   800,   807,   806,   801,
     944,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
     542,   544,   548,   550,     0,   126,     0,   791,    49,    46,
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
     776,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   635,     0,   204,   205,     0,     0,
       0,     0,     0,   209,   210,   760,   762,     0,     0,     5,
      26,     0,    27,     0,     7,    31,     0,    17,     8,    32,
       0,    21,   903,    79,    18,    80,    22,   195,     0,   193,
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
       0,     0,   197,     0,     0,   765,     0,     0,   764,     0,
       0,     0,   501,   499,     0,   490,     0,     0,   473,   474,
       0,    13,     0,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   771,   772,     0,     0,   779,     0,
       0,     0,     0,     0,     0,     0,   202,     0,     0,     0,
     431,   432,   433,   430,   643,   429,     0,   428,   211,     0,
     775,     0,     0,     0,   167,     0,   167,     0,   175,   246,
       0,   312,   308,   310,     0,   298,   299,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,   240,     0,   245,
       0,     0,     0,     0,   673,   369,   646,   650,   652,   654,
     656,   659,   666,   667,   675,   796,   797,   799,   913,   798,
     802,   803,   804,   805,   795,   563,     0,   808,   801,   788,
     790,   786,   565,   388,   553,   560,   561,   582,   573,   581,
     580,   579,   578,   575,   577,   574,   576,   566,   610,   611,
     567,   568,   782,   783,   784,   571,   390,   392,   395,   572,
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
     768,   769,     0,   633,   778,   631,     0,     0,     0,     0,
       0,   637,     0,     0,     0,   957,   203,     0,     0,     0,
     638,   639,     0,     0,   212,   774,    28,     0,    19,    23,
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
       0,   199,   766,   767,     0,     0,   501,     0,     0,   533,
       0,   501,     0,   497,     0,    14,    16,     0,     0,     0,
       0,     0,     0,     0,   781,     0,   636,     0,     0,     0,
       0,     0,     0,   640,   644,   325,   323,   324,   317,   318,
     319,   311,     0,     0,   306,     0,   300,   263,     0,     0,
     277,   269,     0,   273,     0,   267,     0,     0,     0,   286,
       0,     0,     0,   243,   289,   292,     0,   674,   665,   671,
       0,     0,   744,   745,   755,   754,   753,     0,     0,     0,
       0,   746,   651,   752,     0,   649,   653,     0,     0,   658,
     662,     0,   683,   678,   681,   677,   589,   584,     0,     0,
     599,     0,     0,     0,     0,   569,     0,   587,     0,   590,
       0,     0,     0,   588,   593,     0,     0,   562,   615,   555,
     583,   787,   789,   785,   564,   731,     0,     0,   729,   736,
     737,   733,     0,   728,     0,   726,     0,     0,     0,     0,
       0,     0,   543,     0,     0,     0,    68,   285,   549,     0,
       0,   337,   341,   335,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   545,     0,     0,   501,
       0,   528,     0,   501,   551,   620,   621,   625,   626,     0,
     773,   632,   780,   634,     0,     0,     0,     0,   641,   320,
     307,   302,     0,   266,     0,   275,     0,     0,   271,     0,
     274,   287,   295,   296,   290,   242,   669,   756,     0,     0,
     748,     0,   694,   693,   692,   691,   690,   655,     0,   747,
     585,   586,     0,   603,     0,   600,     0,   612,     0,     0,
     592,   591,   598,   606,     0,   596,     0,   594,   740,   739,
     738,     0,   732,   725,   723,     0,   720,   721,   715,   152,
     154,   156,     0,     0,     0,     0,     0,   208,   356,    74,
     332,   338,     0,   352,   348,   355,     0,     0,     0,   342,
       0,     0,   344,     0,   511,   505,   500,     0,   501,   491,
       0,   770,     0,     0,     0,     0,   305,   303,   270,   268,
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
     -1500, -1500,  -198,  -171, -1500,  1211,  1224, -1500,  1227,  -488,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
    -898, -1500, -1500, -1500, -1500,  -189,  -528, -1500,   774,   -34,
   -1500, -1500, -1500, -1500, -1500,   324,   567, -1500, -1500,    15,
     -92,  1049, -1500,  1033, -1500, -1500,  -575, -1500,   524, -1500,
     283, -1500,  -228,  -281, -1500,  -482, -1500,    17,    34,    13,
    -258,  -162, -1500,  -798, -1500, -1500,   421, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500,   679, -1500,    93,
    1512,     0, -1500, -1500, -1500, -1500,   411, -1500, -1500,  -287,
   -1500,     5, -1500, -1500,   854,  -966,  -769,  -745, -1500, -1500,
     753, -1500, -1500,   -24,   159, -1500, -1500, -1500,   180, -1499,
   -1500,   445,   183, -1500, -1500,   187, -1222, -1500,  1005,   284,
   -1500, -1500,   278,  -918, -1500, -1500,   279, -1500, -1500, -1162,
   -1142, -1500,   275, -1345, -1500, -1500,   868,  -134, -1500,   869,
     866, -1500, -1500,  -602,   430,  -572,   433,   442, -1500, -1500,
   -1500,   636, -1500, -1500,  1229, -1500, -1500, -1500, -1500,  -773,
    -302,  -600, -1500, -1500,   218, -1500,  -122, -1500,   843, -1500,
    -370, -1500, -1500,   857,   858, -1500, -1500, -1500, -1500,   844,
   -1500, -1500, -1500, -1500,  -907, -1500,   270, -1500,   750,  -714,
   -1500, -1500, -1500, -1500, -1500,  -265,  -257, -1141,  -964, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
    -667,  -806,   -89,  -795, -1500, -1500, -1500,  -841, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500,   145,   149,  -675,  -151,
    -584, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,
   -1500, -1500,   245, -1500, -1500,   236, -1500,   238,  -969, -1500,
   -1500, -1500,   179,   172,    -1,   461, -1500, -1500, -1500, -1500,
   -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500, -1500,   186,
   -1500, -1500, -1500,     9,   456,   603, -1500, -1500, -1500, -1500,
   -1500,   373, -1500, -1500, -1454, -1500, -1500, -1500,  -478, -1500,
     139, -1500,   -31, -1500, -1500, -1500, -1500, -1258, -1500,   197,
   -1500, -1500, -1500, -1500, -1500,  -100, -1500, -1500, -1500, -1500,
   -1500,  -833, -1500, -1500, -1500,  -363,  -105,   974,   252, -1500
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  jsoniq_parser::yydefgoto_[] =
  {
        -1,   242,   576,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
    1172,   699,   260,   261,   262,   263,   264,   265,   871,   872,
     873,   266,   267,   268,   877,   878,   879,   269,   413,   270,
     271,   644,   272,   415,   416,   417,   423,   689,   690,   273,
    1153,   274,  1669,  1670,   275,   276,   277,   491,   278,   279,
     280,   281,   282,   692,   283,   284,   444,   285,   286,   287,
     288,   289,   290,   587,   291,   292,   773,   774,   293,   294,
     295,   506,   297,   588,   600,  1038,  1039,   298,   589,   299,
     591,   507,   301,   302,   809,   810,  1302,   430,   303,   431,
     432,   816,  1303,  1304,  1305,   592,   593,  1025,  1026,  1464,
     594,  1022,  1023,  1276,  1277,  1278,  1279,   304,   706,   707,
     305,  1188,  1189,  1404,   306,  1191,  1192,   307,   308,  1194,
    1195,  1196,  1197,  1411,   309,   310,   311,   312,   313,   314,
     315,  1312,   316,   317,   318,   319,   320,   321,   322,   323,
     324,  1097,   325,   326,   327,   328,   609,   329,   330,   331,
     332,   333,   334,   335,  1004,  1005,   336,   636,   637,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   848,
     347,   348,   349,   350,   351,   352,  1223,   736,   737,   738,
    1696,  1751,  1752,  1745,  1746,  1753,  1747,  1224,  1225,   353,
     354,  1226,   355,   356,   357,   358,   359,   360,   361,   362,
     934,  1412,  1364,  1074,  1526,  1075,  1098,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,   712,  1718,
     363,  1087,  1088,  1089,  1090,   364,   365,   366,   367,   368,
     369,   763,   764,   370,  1260,  1261,  1608,  1006,  1045,  1322,
    1323,  1046,  1047,  1048,  1049,  1050,  1332,  1509,  1510,  1051,
    1335,  1052,  1490,  1053,  1054,  1340,  1341,  1515,  1513,  1324,
    1325,  1326,  1327,  1635,   673,   898,   899,   900,   901,   902,
     903,  1140,  1557,  1666,  1141,  1555,  1664,   904,  1377,  1552,
    1548,  1549,  1550,   905,   906,  1328,  1336,  1500,  1329,  1496,
    1313,   371,   372,   373,   374,   494,   375,   376,   377,   378,
     379,  1091,  1092,  1093,  1094,  1173,   495,  1095,   380,   381
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If YYTABLE_NINF_, syntax error.  */
  const short int jsoniq_parser::yytable_ninf_ = -932;
  const short int
  jsoniq_parser::yytable_[] =
  {
       296,   296,   296,   296,   296,   300,   300,   300,   300,   300,
     546,   513,   824,   590,   388,   388,   388,   392,   386,   389,
     390,   571,   964,   645,   645,   414,  1190,  1073,  1096,   632,
     837,   525,   648,  1177,   536,   387,   387,   387,   391,   793,
     795,   942,  1031,   825,   826,   827,   828,  1043,  1425,   842,
     566,   952,  1415,   547,   533,  1459,  1460,   564,   563,  1222,
    1112,  1284,   564,   696,   700,   568,  1032,  1154,  1580,   555,
     556,  1584,  1308,     7,     8,  1155,  1511,   785,   789,  1117,
     858,  1028,  1433,   787,   791,   794,   796,  1035,  1672,     7,
       8,   564,  1291,   647,   399,  1497,   723,   428,   564,   974,
     564,   296,  1667,     9,  1180,   724,   300,   564,   564,   564,
     399,   993,  1706,   564,   492,  1166,  1694,   724,  1405,   573,
     400,   724,   402,   564,  -171,   564,  1178,  1143,  -172,   564,
     571,   564,  1144,  1145,   571,   387,  1262,   965,   402,  1628,
     932,  1146,  1029,   403,  1033,  1546,   393,  1492,  1147,   564,
    1148,  1149,   723,  1029,   564,   564,  1213,   564,   564,  1150,
     679,   932,   564,   970,   564,   575,   564,  1577,   564,   564,
     575,  1187,   564,  1462,   418,   404,   405,  1017,   570,   578,
     419,   518,   741,   579,  1402,    73,  1151,  1493,   580,  1181,
    1581,  1578,  1263,   564,  1030,   505,   509,   564,   725,  1673,
      84,  1145,   574,   966,  1406,  1292,  1695,   581,  1761,  1547,
    1463,   755,   394,  1120,   887,  1497,   888,   564,  1629,  1149,
     590,   971,  1214,   564,   564,    98,   695,   975,   976,  1040,
       9,   575,  1041,   575,   571,   756,  1609,   575,   429,   575,
     296,   296,   977,   994,   296,   300,   300,   983,  1212,   300,
    1036,   564,   118,  1165,   793,   795,   429,   575,  1582,  1498,
     889,   564,   575,   575,  1293,   575,   575,   982,  1043,  1043,
     575,  1354,   575,  1408,   575,  1774,   575,   575,  1395,   296,
     575,  1674,   565,  1415,   300,  1113,  1289,  1433,  1294,   567,
    1037,   780,   785,   789,   144,   145,   146,  1665,   782,  1014,
    1016,   575,   668,   884,  1266,   575,   582,  1222,   919,   583,
    -171,  1314,    73,   683,  -172,  1369,  1222,  1467,  1152,   734,
    1154,  1354,   570,   429,   584,   575,   806,    84,  1155,   549,
     551,   575,   575,   479,   429,   732,   930,  1738,  1042,   680,
     420,  1489,   925,   944,  1517,   945,   997,   681,  1102,   938,
     585,   742,    98,   497,  1208,   410,   479,  1209,   564,   575,
    1210,  1288,  1390,   411,   781,   783,   519,  1296,   479,   575,
     479,   412,   572,  1405,   798,   776,   786,   790,   775,  1498,
    1499,  1702,   853,   779,  1315,  1703,   395,   396,   296,   397,
     398,   647,   296,   300,  1782,   853,  1785,   300,   564,   586,
    1607,   939,   750,   932,   421,  1704,   497,   401,   950,   967,
    1069,  1070,  1071,   758,   564,   890,  1314,   564,  1476,   296,
     296,   144,   145,   146,   300,   300,     7,     8,   891,   922,
     892,   754,   392,   392,  1405,   296,   968,  1693,   759,   296,
     300,   893,   894,   895,   300,   896,   969,   897,   392,  1731,
    1044,   560,   392,   684,   685,   564,  1263,   941,  1103,  1570,
     537,  1103,   854,  1267,   633,   538,   575,   561,   818,   709,
    1687,  1316,  1317,   714,  1318,   855,   697,   433,  1215,  1137,
    1743,   572,   940,  1106,  1215,   572,   793,   795,   793,  1315,
     429,  1320,   296,  1385,  1578,   422,  1138,   300,  1749,   634,
     939,   635,   296,  1321,   438,  1582,   575,   300,  1374,   923,
    1776,   407,   571,   569,   686,   388,  1469,   693,  1121,  1122,
    1575,  1222,   575,  1125,   698,   575,   705,  1642,   843,   710,
     711,  1370,  1268,  1269,  1270,   717,   387,  1043,  1104,  1525,
    1018,  1105,  1759,   999,   612,   296,  1043,   429,  1477,   539,
     300,   687,  1644,  1163,   296,  1648,  1382,  1043,   770,   300,
    1215,   613,   595,   575,   596,   296,   296,   296,   296,  1376,
     300,   300,   300,   300,   408,   414,  1316,  1317,   972,  1318,
    1749,   954,   439,  1101,   296,   572,  1319,   424,  1015,   300,
     926,  1011,   783,   929,  1654,  1218,  1320,  1219,   663,  1487,
     664,  1218,  1760,  1219,   739,   740,  1750,  1643,  1321,  1656,
     744,  1744,     7,     8,  1465,   409,   621,  1415,   978,   957,
     688,  1661,  1691,   395,   396,  1220,   397,   398,   932,   597,
     622,  1220,  1645,   399,   598,  1649,   973,   769,   771,   991,
    1765,   578,  1029,   400,   401,   579,  1578,   425,  1215,  1216,
     580,   655,   479,   440,   441,   479,  1273,   426,  1632,   479,
     666,   402,   479,   479,   578,  1633,   403,  1679,   579,   581,
     479,  1044,  1044,   580,  1655,  1634,   633,  1218,  1275,  1219,
     479,   599,  1295,  1743,   427,   434,   479,  1215,  1791,  1657,
     479,   296,   581,   788,  1468,   479,   300,   987,   404,   405,
     406,  1662,   932,  1029,   388,  1617,   435,  1220,   924,  1298,
     932,   634,  1588,   635,  1299,   296,   296,  1592,  1137,  1504,
     300,   300,   667,   633,   839,   387,  1012,   844,   392,   392,
    1748,  1754,   479,  1300,  1043,  1138,  1215,  1216,   793,  1256,
    1374,   632,   561,   663,  1217,   664,   979,   980,   407,   948,
     949,   933,  1029,   479,   497,  1616,   788,  1375,   634,   951,
     635,   981,  1131,   436,  1230,  1218,  1231,  1219,   582,  1272,
     296,   583,  1685,  1132,  1301,   300,  1215,  1216,   665,  1139,
    1273,   633,  1748,   497,   874,  1408,   733,  1561,  1754,  1013,
    1274,   582,   479,   437,   583,  1220,   615,  1247,   296,   104,
     798,  1376,  1275,   300,  1218,   666,  1219,   414,  1393,  1451,
    1361,   408,   585,   783,  1788,   116,   634,   657,   635,     9,
     959,   960,   961,   633,   771,  1298,   616,   442,   875,   612,
    1299,   612,  1217,   876,  1220,   585,  1221,  1114,  1781,   617,
    1722,  1362,  1723,   631,  1264,   443,   613,   479,   613,  1114,
     658,   479,   409,  1218,   139,  1219,  1215,  1216,   634,  1363,
     635,   586,  1578,   998,  -851,  -931,   118,   667,  1029,   614,
    1248,  1715,  1217,   618,  1802,  1697,   480,   677,   410,  1700,
     511,  1803,   678,  1220,   586,   479,   411,   104,  -851,  -931,
    1337,  1338,  1310,  1218,   412,  1219,  1630,  1631,  1578,  -851,
    -931,    73,  1445,   116,   612,  1578,   653,  1123,  1124,  1107,
    1455,   860,  1391,  1339,   479,   118,    84,   649,  1771,  1627,
    1109,   613,   654,  1220,  1427,  1108,   932,   104,   479,  1298,
     651,   650,   479,   479,  1299,   512,  1110,  1111,  1273,   479,
    1044,    98,   139,   116,   652,  1040,   296,   479,  1041,  1044,
     479,   300,  1217,   691,   479,  1632,   517,  1187,  1671,   392,
    1044,  1368,  1633,   638,  1432,  1413,   520,  1717,   118,  1720,
    1407,   590,  1634,  1218,   639,  1219,   497,   691,  1414,  1725,
    1198,  1726,   139,  1416,  1756,  1413,  1413,   479,  1494,  1133,
     797,   669,   670,   671,   799,  1495,  1417,  1257,  1587,  1794,
    1134,   875,  1258,  1220,  1732,   521,   876,   104,   619,  1157,
     144,   145,   146,   540,   296,   296,   296,   620,  1158,   300,
     300,   300,   541,   116,   479,   542,  1713,  1714,   414,  1456,
    1457,  1566,   861,   862,   863,   864,   865,   866,   867,   868,
     869,   870,   822,   823,  1590,  1126,  1127,  1128,  1235,   543,
    1236,  1129,   829,   830,   479,   478,   603,   604,   605,   606,
     607,   608,   139,   831,   832,  1380,  1381,   479,  1658,  1659,
     544,   545,   557,   601,   577,   496,  1671,   602,   510,   610,
     611,   623,   624,   625,   630,   479,   479,   479,   479,   626,
     496,   640,   516,   546,   641,   642,   643,   647,   659,  1610,
     661,   662,   672,   676,   691,   694,   702,   703,   704,   715,
     716,   719,   721,  1764,   723,   726,   727,   728,   729,   731,
     735,   746,   743,   745,   747,   761,   479,   762,   496,   766,
    1671,   767,   784,  1307,   778,   802,   772,  1044,   803,   804,
     479,   805,   812,   813,   815,   820,   634,   834,  1572,   833,
     835,   836,   850,   856,   857,   859,   881,   882,   885,   908,
     886,   909,   911,   913,   296,   479,   907,   916,   917,   300,
     296,   921,   927,   479,   918,   300,   928,   388,   931,   946,
     995,  1389,   296,   943,   479,   986,   989,   300,   947,   992,
     996,  1013,  1020,   806,  1009,   388,  1024,  1027,   387,  1398,
    1115,   296,   876,   932,  1135,  1136,   300,  1161,  1156,  1813,
     687,  1814,  1164,  1168,   388,  1169,   387,  1171,  1420,  1170,
     296,  1822,  1162,  1174,  1176,   300,  1182,   296,  1175,  1183,
    1187,  1186,   300,   392,  1193,   387,  1206,  1203,  1199,  1200,
     392,  1201,  1530,  1207,  1211,  1228,  1229,  1242,   665,  1280,
    1204,  1227,  1259,  1249,  1430,  1282,  1286,  1285,  1290,  1330,
    1334,  1434,  1257,  1297,  1311,  1342,     9,  1258,  1372,  1343,
    1331,  1373,  1344,  1345,  1346,   770,   479,  1347,  1378,   479,
    1348,  1349,  1350,  1351,  1384,  1383,  1394,  1419,  1388,  1365,
    1352,  1413,  1387,  1355,  1356,  1397,  1357,  1358,  1359,  1424,
    1360,  1426,  1429,  1437,  1441,  1677,  1442,  1438,  1435,  1443,
    1439,  1448,  1436,  1449,  1450,  1262,  1681,  1572,   479,  1683,
    1273,  1472,  1440,  1474,  1481,  1478,  1480,  1692,  1486,  1482,
    1507,  1447,  1512,  1488,  1491,  1501,  1508,  1514,  1545,  1551,
    1516,  1556,  1527,  1563,  1558,  1533,  1554,  1537,  1564,  1538,
    1539,  1540,  1541,  1542,  1543,  1562,  1565,  1544,  1569,  1568,
    1560,  1599,  1612,  1614,  1646,  1663,  1574,  1585,   479,  1586,
    1591,  1594,  1619,  1626,   656,  1640,  1638,   660,  1137,  1641,
    1647,   496,  1676,  1650,   674,   675,  1639,  1651,  1652,  1653,
    1668,  1675,   496,  1682,  1699,  1462,  1710,  1712,  1724,  1727,
    1729,  1730,   701,  1734,  1755,  1763,   296,  1739,   708,  1740,
    1741,   300,   713,  1735,  1766,  1767,  1728,   718,  1758,  1768,
     479,  1779,  1757,  1769,  1770,  1787,  1772,  1773,  1780,  1790,
    1786,  1812,  1793,  1683,  1818,   479,  1799,  1804,  1819,   883,
    1815,  1371,  1118,   646,  1386,   479,  1167,   682,  1737,  1775,
    1306,  1257,  1008,   814,   708,   558,  1258,   937,  1777,  1797,
    1624,  1485,  1466,  1461,  1458,  1271,  1403,  1399,   559,   817,
    1409,  1418,  1100,   479,   562,   730,   496,   821,   819,   849,
    1805,  1454,  1783,   852,  1428,   720,   963,  1792,  1518,  1789,
     840,   841,  1519,  1721,  1446,  1816,  1453,  1452,  1502,  1806,
    1391,   479,  1506,  1309,  1809,   496,  1637,  1333,  1811,  1505,
    1142,   479,  1379,  1636,   765,   479,  1553,  1503,  1660,  1821,
       0,     0,     0,  1800,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   479,     0,     0,   479,     0,
       0,  1604,  1605,  1606,     0,  1800,     0,     0,     0,     0,
       0,     0,     0,   479,  1783,   629,     0,     0,     0,     0,
       0,     0,     0,  1257,     0,     0,     0,     0,  1258,   811,
       0,     0,     0,   811,  1257,  1257,     0,   296,     0,  1258,
    1258,     0,   300,     0,     0,  1257,     0,     0,     0,     0,
    1258,     0,     0,     0,     0,     0,   479,   479,     0,   479,
     479,   479,     0,   479,     0,     0,     0,   496,     0,     0,
       0,     0,     0,   493,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   479,   880,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     910,     0,     0,     0,   914,   915,     0,     0,     0,     0,
       0,   920,   479,     0,     0,   479,   532,     0,   479,   496,
       0,     0,   496,     0,     0,     0,   935,     0,     0,   479,
       0,     0,     0,     0,   479,     0,     0,     0,     0,     0,
       0,  1257,     0,     0,     0,     0,  1258,     0,   496,     0,
    1705,     0,     0,     0,     0,     0,     0,     0,     0,   962,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1716,     0,   479,   479,     0,     0,     0,     0,     0,
     296,     0,     0,     0,     0,   300,  1007,     0,     0,     0,
     553,     0,     0,     0,     0,     0,     0,     0,  1257,     0,
       0,     0,     0,  1258,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1019,     0,     0,     0,
       0,   296,     0,     0,     0,     0,   300,     0,     0,  1034,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1257,     0,     0,     0,     0,  1258,  1099,
    1099,     0,  1257,     0,     0,     0,     0,  1258,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     479,   479,     0,   479,     0,   479,     0,     0,     0,     0,
       0,     0,   479,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1160,     0,     0,
       0,     0,     0,     0,   479,     0,   479,     0,   479,     0,
     479,     0,     0,     0,     0,     0,   479,     0,   479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   479,     0,     0,   479,     0,     0,
       0,     0,     0,     0,   479,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   479,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   479,     0,     0,     0,
       0,   479,     0,   479,     0,     0,     0,     0,  1281,     0,
       0,   811,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   493,   479,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   479,     0,     0,   748,   749,     0,     0,     0,     0,
       0,   751,   752,   753,     0,     0,   757,     0,     0,   760,
       0,   479,     0,     0,     0,   768,   479,     0,     0,     0,
       0,     0,     0,     0,   777,     0,     0,     0,   479,     0,
       0,   479,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   800,   801,     0,
       0,     0,     0,     0,     0,     0,   807,   808,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   847,     0,     0,
       0,   847,     0,     0,     0,     0,     0,   708,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     912,     0,     0,     0,     0,  1431,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   936,     0,     0,     0,     0,
       0,     0,     0,   765,     0,     0,     0,     0,     0,     0,
       0,   953,     0,  1007,     0,   955,   956,  1007,   958,     0,
       0,     0,     0,     0,     0,   807,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   811,     0,     0,
    1470,     0,     0,     0,     0,     0,     0,   984,   985,     0,
       0,   988,     0,     0,     0,  1484,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1010,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     801,     0,     0,     0,     0,     0,  1021,     0,  1522,     0,
       0,   496,  1531,  1532,     0,  1536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1559,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1576,     0,     0,     0,  1119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1589,     0,     0,     0,     0,  1593,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1159,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1179,     0,     0,     0,     0,
       0,     0,  1184,  1185,     0,  1622,  1623,     0,     0,     0,
       0,     0,     0,  1202,     0,     0,  1205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1232,  1233,  1234,
       0,  1237,  1238,  1239,  1240,  1241,     0,     0,  1243,  1244,
       0,  1245,  1246,     0,     0,     0,  1250,  1251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1265,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1021,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1287,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1686,     0,  1688,     0,  1690,     0,     0,
       0,     0,     0,     0,  1698,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1367,  1719,     0,  1719,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   713,     0,
     713,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1733,     0,     0,  1736,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1742,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1392,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1396,     0,     0,     0,     0,     0,  1400,  1401,
       0,     0,     0,     0,     0,     0,     0,     0,  1778,     0,
       0,     0,     0,     0,     0,  1421,     0,     0,  1422,  1423,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1795,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1798,     0,     0,     0,     0,     0,  1444,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1807,     0,     0,     0,     0,  1808,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1817,     0,  1021,  1820,     0,     0,     0,     0,     0,     0,
    1471,     0,  1473,     0,  1475,     0,     0,  1479,     0,     0,
       0,     0,  1483,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1567,
       0,     0,     0,     0,     0,     0,     0,  1571,  1573,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1392,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1595,
    1596,  1597,  1598,     0,  1600,  1601,     0,  1602,     0,  1603,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1611,     0,     0,     0,     0,
    1613,     0,     0,     0,  1615,     0,     0,     0,  1618,     0,
    1620,     0,  1621,     0,     0,     0,     0,     0,  1625,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1678,     0,     0,     0,
       0,  1680,  1573,     0,     0,     0,     0,     0,     0,  1684,
       0,     0,     0,     0,  1689,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1701,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1707,     0,  1708,     0,  1709,     0,
       0,  1711,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1684,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1762,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1784,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -167,   788,     0,     0,     0,     0,     0,  1796,
       0,     0,     0,  1801,     0,     0,     0,     0,  1784,     0,
       0,     0,     0,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,  1801,     0,    10,   383,  1810,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,     0,     0,    68,    69,    70,     0,     0,    71,
      72,     0,     0,     0,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,    84,
       0,    85,    86,    87,    88,     0,    89,     0,     0,     0,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,     0,   101,   102,
       0,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,     0,     0,     0,     0,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,   138,   139,     0,   385,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
     237,  -167,   788,   238,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,   792,   383,     0,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      23,   384,    25,    26,    27,     0,    28,     0,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,    65,    66,
      67,     0,     0,    68,    69,    70,     0,     0,    71,    72,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,    84,     0,
      85,    86,    87,    88,     0,    89,     0,     0,     0,    90,
      91,    92,    93,    94,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,     0,   101,   102,     0,
     103,   104,   105,   106,   107,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   116,     0,   117,
     118,     0,     0,   119,   120,   121,     0,     0,     0,   122,
       0,   123,   124,   125,     0,     0,     0,     0,     0,   126,
       0,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,   138,   139,     0,   385,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,     0,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   788,   237,
       0,     0,   238,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     0,     9,     0,     0,
       0,   382,   383,     0,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    20,    21,    22,    23,   384,    25,    26,
      27,     0,    28,     0,    29,    30,    31,    32,    33,    34,
       0,     0,    35,    36,    37,    38,    39,     0,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,    64,    65,    66,    67,     0,     0,    68,
      69,    70,     0,     0,    71,    72,     0,     0,     0,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
       0,     0,     0,     0,    84,     0,    85,    86,    87,    88,
       0,    89,     0,     0,     0,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,    95,    96,    97,    98,
      99,   100,     0,   101,   102,     0,   103,   104,   105,   106,
     107,     0,     0,     0,   108,   109,   110,   111,   112,   113,
     114,   115,     0,   116,     0,   117,   118,     0,     0,   119,
     120,   121,     0,     0,     0,   122,     0,   123,   124,   125,
       0,     0,     0,     0,     0,   126,     0,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,     0,     0,
       0,   138,   139,     0,   385,     0,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     0,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,     0,   186,   187,   188,     0,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   788,   237,     0,     0,   238,   239,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       0,     0,     0,     9,     0,     0,     0,   382,   383,     0,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,   498,   384,    25,    26,    27,     0,    28,     0,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,     0,    40,    41,    42,   499,   500,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
      65,    66,    67,     0,     0,    68,    69,    70,     0,     0,
      71,    72,     0,     0,     0,    73,    74,   463,    76,    77,
      78,    79,    80,   501,    82,    83,     0,     0,     0,     0,
      84,     0,    85,    86,    87,    88,     0,    89,     0,     0,
       0,    90,    91,    92,    93,    94,     0,     0,     0,     0,
       0,     0,    95,    96,    97,    98,    99,   100,     0,   502,
     102,     0,   103,   104,   105,   106,   107,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,     0,     0,     0,     0,     0,
       0,   126,     0,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,   138,   139,     0,
     385,     0,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   471,   472,   473,
     169,   170,     0,   504,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,     0,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,  1000,  1001,   238,   239,     0,     0,     0,     0,
       0,  1002,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     0,     0,     0,     0,   382,   383,     0,    12,    13,
      14,   445,    16,    17,    18,   446,   447,   448,   449,   450,
     451,   384,    25,   452,    27,   453,    28,     0,    29,    30,
      31,    32,   454,    34,   455,   456,    35,    36,    37,    38,
     457,     0,    40,   458,    42,   459,   460,    45,   461,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,    65,    66,
     462,     0,     0,    68,    69,    70,     0,     0,    71,    72,
       0,     0,     0,     0,    74,   463,    76,    77,    78,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,     0,    89,     0,     0,     0,   464,
      91,    92,    93,    94,     0,     0,     0,     0,     0,     0,
      95,    96,    97,     0,    99,   100,     0,     0,     0,     0,
       0,     0,     0,   106,   465,     0,     0,     0,   108,   109,
     110,   111,   466,   113,   114,   115,     0,     0,     0,     0,
       0,     0,     0,   119,   120,   121,     0,     0,     0,   122,
       0,   123,   124,     0,     0,     0,     0,  1003,     0,   126,
       0,   127,   128,   129,   130,   467,   132,   133,   134,   135,
     136,   137,     0,     0,   468,   138,     0,     0,   385,     0,
     142,   143,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,   469,     0,   155,     0,     0,   158,   159,   160,
     161,   162,   163,   470,   165,   471,   472,   473,   169,   170,
     474,   475,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   476,     0,   186,   477,   188,     0,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,     0,     0,     0,
       0,     0,     0,   239,     1,     2,     3,     4,     5,     6,
       7,     8,     0,     9,     0,     0,     0,    10,    11,     0,
      12,    13,    14,    15,    16,    17,    18,    19,     0,    20,
      21,    22,    23,    24,    25,    26,    27,     0,    28,     0,
      29,    30,    31,    32,    33,    34,     0,     0,    35,    36,
      37,    38,    39,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
      65,    66,    67,     0,     0,    68,    69,    70,     0,     0,
      71,    72,     0,     0,     0,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,     0,     0,     0,     0,
      84,     0,    85,    86,    87,    88,     0,    89,     0,     0,
       0,    90,    91,    92,    93,    94,     0,     0,     0,     0,
       0,     0,    95,    96,    97,    98,    99,   100,     0,   101,
     102,     0,   103,   104,   105,   106,   107,     0,     0,     0,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   116,
       0,   117,   118,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,   125,     0,     0,     0,     0,
       0,   126,     0,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,     0,     0,     0,   138,   139,     0,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,     0,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,     0,   186,   187,
     188,     0,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
       0,   237,     0,     0,   238,   239,     0,     0,     0,     0,
     240,   241,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     9,     0,     0,     0,    10,    11,     0,    12,    13,
      14,    15,    16,    17,    18,    19,     0,    20,    21,    22,
      23,    24,    25,    26,    27,     0,    28,     0,    29,    30,
      31,    32,    33,    34,     0,     0,    35,    36,    37,    38,
      39,     0,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,    65,    66,
      67,     0,     0,    68,    69,    70,     0,     0,    71,    72,
       0,     0,     0,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,     0,     0,     0,     0,    84,     0,
      85,    86,    87,    88,     0,    89,     0,     0,     0,    90,
      91,    92,    93,    94,     0,     0,     0,     0,     0,     0,
      95,    96,    97,    98,    99,   100,     0,   101,   102,     0,
     103,   104,   105,   106,   107,     0,     0,     0,   108,   109,
     110,   111,   112,   113,   114,   115,     0,   116,     0,   117,
     118,     0,     0,   119,   120,   121,     0,     0,     0,   122,
       0,   123,   124,   125,     0,     0,     0,     0,     0,   126,
       0,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,     0,     0,     0,   138,   139,     0,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,     0,   186,   187,   188,     0,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,     0,   237,
       0,     0,   238,   239,     0,   481,     0,     0,     0,   554,
       1,     2,     3,     4,     5,     6,     7,     8,     0,     9,
       0,     0,     0,   382,   383,     0,    12,    13,    14,   482,
      16,    17,    18,    19,   447,   483,    21,    22,   484,   384,
      25,    26,    27,   453,    28,     0,    29,    30,    31,    32,
     485,    34,   455,   456,    35,    36,    37,    38,    39,     0,
      40,   486,    42,   487,   488,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    64,    65,    66,   489,     0,
       0,    68,    69,    70,     0,     0,    71,    72,     0,     0,
       0,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     0,     0,     0,     0,    84,     0,    85,    86,
      87,    88,     0,    89,     0,     0,     0,    90,    91,    92,
      93,    94,     0,     0,     0,     0,     0,     0,    95,    96,
      97,    98,    99,   100,     0,   101,   102,     0,   103,   104,
     105,   106,   107,     0,     0,     0,   108,   109,   110,   111,
     112,   113,   114,   115,     0,   116,     0,   117,   118,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,   125,     0,     0,     0,     0,     0,   126,     0,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
       0,     0,   468,   138,   139,     0,   385,     0,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     469,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   490,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,     0,   186,   187,   188,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,     0,   237,   481,     0,
     238,   239,     0,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   382,   383,     0,    12,
      13,    14,   482,    16,    17,    18,    19,   447,   483,    21,
      22,   526,   384,    25,    26,    27,   453,    28,     0,    29,
      30,    31,    32,   485,    34,   455,   456,    35,    36,    37,
      38,    39,     0,    40,   486,    42,   527,   528,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,   489,     0,     0,    68,    69,    70,     0,     0,    71,
      72,     0,     0,     0,    73,    74,   463,    76,    77,    78,
      79,    80,   501,    82,    83,     0,     0,     0,     0,    84,
       0,    85,    86,    87,    88,     0,    89,     0,     0,     0,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,     0,   502,   102,
       0,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,   468,   138,   139,     0,   385,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   529,   154,   530,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   471,   472,   473,   169,
     170,   474,   504,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
     237,   481,   531,   238,   239,     0,     1,     2,     3,     4,
       5,     6,     0,     0,     0,     9,     0,     0,     0,   382,
     383,     0,    12,    13,    14,   482,    16,    17,    18,    19,
     447,   483,    21,    22,   526,   384,    25,    26,    27,   453,
      28,     0,    29,    30,    31,    32,   485,    34,   455,   456,
      35,    36,    37,    38,    39,     0,    40,   486,    42,   527,
     528,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,    65,    66,   489,     0,     0,    68,    69,    70,
       0,     0,    71,    72,     0,     0,     0,    73,    74,   463,
      76,    77,    78,    79,    80,   501,    82,    83,     0,     0,
       0,     0,    84,     0,    85,    86,    87,    88,     0,    89,
       0,     0,     0,    90,    91,    92,    93,    94,     0,     0,
       0,     0,     0,     0,    95,    96,    97,    98,    99,   100,
       0,   502,   102,     0,   103,   104,   105,   106,   107,     0,
       0,     0,   108,   109,   110,   111,   112,   113,   114,   115,
       0,   116,     0,   117,   118,     0,     0,   119,   120,   121,
       0,     0,     0,   122,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   126,     0,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,     0,     0,   468,   138,
     139,     0,   385,     0,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   469,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   471,
     472,   473,   169,   170,   474,   504,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,     0,
     186,   187,   188,     0,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   481,   237,     0,     0,   238,   239,     0,     0,
       0,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     382,   383,     0,    12,    13,    14,   445,    16,    17,    18,
     446,   447,   448,   449,   450,   451,   384,    25,   452,    27,
     453,    28,     0,    29,    30,    31,    32,   454,    34,   455,
     456,    35,    36,    37,    38,   457,     0,    40,   458,    42,
     459,   460,    45,   461,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,   462,     0,     0,    68,    69,
      70,     0,     0,    71,    72,     0,     0,     0,     0,    74,
     463,    76,    77,    78,    79,    80,   501,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,     0,
      89,     0,     0,     0,   464,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,    95,    96,    97,     0,    99,
     100,     0,     0,     0,     0,   103,     0,     0,   106,   465,
       0,     0,     0,   108,   109,   110,   111,   466,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   126,     0,   127,   128,   129,   130,
     467,   132,   133,   134,   135,   136,   137,     0,     0,   468,
     138,     0,     0,   385,     0,   142,   143,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,   469,     0,   155,
       0,     0,   158,   159,   160,   161,   162,   163,   470,   165,
     471,   472,   473,   169,   170,   474,   475,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   476,
       0,   186,   477,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   481,     0,     0,     0,     0,     0,   239,     0,
       0,     5,     6,     0,     0,     0,  1528,     0,     0,     0,
     382,   383,     0,    12,    13,    14,   445,    16,    17,    18,
     446,   447,   448,   449,   450,   451,   384,    25,   452,    27,
     453,    28,     0,    29,    30,    31,    32,   454,    34,   455,
     456,    35,    36,    37,    38,   457,     0,    40,   458,    42,
     459,   460,    45,   461,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,   462,     0,     0,    68,    69,
      70,     0,     0,    71,    72,     0,     0,     0,     0,    74,
     463,    76,    77,    78,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,     0,
      89,     0,     0,     0,   464,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,    95,    96,    97,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,   106,   465,
       0,     0,     0,   108,   109,   110,   111,   466,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,   119,   120,
     121,     0,     0,     0,   122,  1529,   123,   124,     0,     0,
       0,     0,     0,     0,   126,     0,   127,   128,   129,   130,
     467,   132,   133,   134,   135,   136,   137,     0,     0,   468,
     138,     0,     0,   385,     0,   142,   143,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,   469,     0,   155,
       0,     0,   158,   159,   160,   161,   162,   163,   470,   165,
     471,   472,   473,   169,   170,   474,   475,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   476,
       0,   186,   477,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   481,     0,     0,     0,     0,     0,   239,     0,
       0,     5,     6,     0,     0,     0,     0,     0,     0,     0,
     382,   383,     0,    12,    13,    14,   445,    16,    17,    18,
     446,   447,   448,   449,   450,   451,   384,    25,   452,    27,
     453,    28,     0,    29,    30,    31,    32,   454,    34,   455,
     456,    35,    36,    37,    38,   457,     0,    40,   458,    42,
     459,   460,    45,   461,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,   462,     0,     0,    68,    69,
      70,     0,     0,    71,    72,     0,     0,     0,     0,    74,
     463,    76,    77,    78,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,     0,
      89,     0,     0,     0,   464,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,    95,    96,    97,     0,    99,
     100,     0,     0,     0,     0,     0,     0,     0,   106,   465,
       0,     0,     0,   108,   109,   110,   111,   466,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   126,     0,   127,   128,   129,   130,
     467,   132,   133,   134,   135,   136,   137,     0,     0,   468,
     138,     0,     0,   385,     0,   142,   143,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,   469,     0,   155,
       0,     0,   158,   159,   160,   161,   162,   163,   470,   165,
     471,   472,   473,   169,   170,   474,   475,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   476,
       0,   186,   477,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   514,   515,     0,     0,     0,     0,   239,     5,
       6,     0,     0,     0,     0,     0,     0,     0,   382,   383,
       0,    12,    13,    14,   445,    16,    17,    18,   446,   447,
     448,   449,   450,   451,   384,    25,   452,    27,   453,    28,
       0,    29,    30,    31,    32,   454,    34,   455,   456,    35,
      36,    37,    38,   457,     0,    40,   458,    42,   459,   460,
      45,   461,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
      64,    65,    66,   462,     0,     0,    68,    69,    70,     0,
       0,    71,    72,     0,     0,     0,     0,    74,   463,    76,
      77,    78,    79,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,     0,    89,     0,
       0,     0,   464,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,    95,    96,    97,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,   106,   465,     0,     0,
       0,   108,   109,   110,   111,   466,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,     0,     0,     0,     0,
       0,     0,   126,     0,   127,   128,   129,   130,   467,   132,
     133,   134,   135,   136,   137,     0,     0,   468,   138,     0,
       0,   385,     0,   142,   143,     0,     0,     0,   147,   148,
     149,   150,   151,   152,     0,   469,     0,   155,     0,     0,
     158,   159,   160,   161,   162,   163,   470,   165,   471,   472,
     473,   169,   170,   474,   475,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   476,     0,   186,
     477,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
       0,     0,     0,     0,     0,     0,   239,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
      10,    11,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,    27,
       0,    28,     0,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,     0,     0,    68,    69,
      70,     0,     0,    71,    72,     0,     0,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,    84,     0,    85,    86,    87,    88,     0,
      89,     0,     0,     0,    90,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,     0,   101,   102,     0,   103,   104,   105,   106,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
       0,     0,     0,     0,   126,     0,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     138,   139,     0,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,   237,     0,     0,   238,   239,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   382,   383,     0,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,    23,   384,    25,
      26,    27,     0,    28,     0,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,     0,
      68,    69,    70,     0,     0,    71,    72,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,    84,     0,    85,    86,    87,
      88,     0,    89,     0,     0,     0,    90,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,     0,   101,   102,     0,   103,   104,   105,
     106,   107,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,   722,     0,   122,     0,   123,   124,
     125,     0,     0,     0,     0,     0,   126,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,   138,   139,     0,   385,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,     0,     0,   238,
     239,     1,     2,     3,     4,     5,     6,     7,     8,     0,
       9,     0,     0,     0,   382,   383,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,    23,
     384,    25,    26,    27,     0,    28,     0,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    38,    39,
       0,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    65,    66,    67,
       0,     0,    68,    69,    70,     0,     0,    71,    72,     0,
       0,     0,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,    84,     0,    85,
      86,    87,    88,     0,    89,     0,     0,     0,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,     0,   101,   102,     0,   103,
     104,   105,   106,   107,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,   125,     0,     0,     0,     0,     0,   126,     0,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,   138,   139,     0,   385,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,   237,     0,
       0,   238,   239,     1,     2,     3,     4,     5,     6,     7,
       8,     0,     9,     0,     0,     0,    10,    11,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,     0,     0,    68,    69,    70,     0,     0,    71,
      72,     0,     0,     0,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,     0,     0,     0,     0,    84,
       0,    85,    86,    87,    88,     0,    89,     0,     0,     0,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,     0,   101,   102,
       0,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,   125,     0,     0,     0,     0,     0,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,   138,   139,     0,   385,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
     237,     0,     0,   238,   239,     1,     2,     3,     4,     5,
       6,     7,     8,     0,     9,     0,     0,     0,    10,   383,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,    23,    24,    25,    26,    27,     0,    28,
       0,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,    39,     0,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
      64,    65,    66,    67,     0,     0,    68,    69,    70,     0,
       0,    71,    72,     0,     0,     0,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,     0,     0,
       0,    84,     0,    85,    86,    87,    88,     0,    89,     0,
       0,     0,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,     0,
     101,   102,     0,   103,   104,   105,   106,   107,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,   125,     0,     0,     0,
       0,     0,   126,     0,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,   138,   139,
       0,   385,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,   237,     0,     0,   238,   239,     1,     2,     3,
       4,     5,     6,     7,     8,     0,     9,     0,     0,     0,
     792,   383,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,    23,   384,    25,    26,    27,
       0,    28,     0,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,     0,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,     0,     0,    68,    69,
      70,     0,     0,    71,    72,     0,     0,     0,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,     0,     0,    84,     0,    85,    86,    87,    88,     0,
      89,     0,     0,     0,    90,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,     0,   101,   102,     0,   103,   104,   105,   106,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,   125,     0,
       0,     0,     0,     0,   126,     0,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     138,   139,     0,   385,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,   237,     0,     0,   238,   239,     1,
       2,     3,     4,     5,     6,     7,     8,     0,     9,     0,
       0,     0,   382,   383,     0,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,  1252,   384,    25,
      26,    27,     0,    28,     0,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,     0,    40,
      41,    42,  1253,  1254,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,     0,
      68,    69,    70,     0,     0,    71,    72,     0,     0,     0,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,     0,     0,     0,     0,    84,     0,    85,    86,    87,
      88,     0,    89,     0,     0,     0,    90,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,     0,   101,   102,     0,   103,   104,   105,
     106,   107,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
     125,     0,     0,     0,     0,     0,   126,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,   138,   139,     0,   385,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,  1255,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,     0,     0,   238,
     239,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   382,   383,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,   498,
     384,    25,    26,    27,     0,    28,     0,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    38,    39,
       0,    40,    41,    42,   499,   500,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    65,    66,    67,
       0,     0,    68,    69,    70,     0,     0,    71,    72,     0,
       0,     0,    73,    74,   463,    76,    77,    78,    79,    80,
     501,    82,    83,     0,     0,     0,     0,    84,     0,    85,
      86,    87,    88,     0,    89,     0,     0,     0,    90,    91,
      92,    93,    94,     0,     0,     0,     0,   845,     0,    95,
      96,    97,    98,    99,   100,     0,   502,   102,     0,   103,
     104,   105,   106,   107,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,   846,
     123,   124,     0,     0,     0,     0,     0,     0,   126,     0,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,   138,   139,     0,   385,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   471,   472,   473,   169,   170,     0,
     504,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,   237,     0,
       0,   238,   239,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   382,   383,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,   498,   384,    25,    26,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,    40,    41,    42,   499,   500,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,     0,     0,    68,    69,    70,     0,     0,    71,
      72,     0,     0,     0,    73,    74,   463,    76,    77,    78,
      79,    80,   501,    82,    83,     0,     0,     0,     0,    84,
       0,    85,    86,    87,    88,     0,    89,     0,     0,     0,
      90,    91,    92,    93,    94,     0,     0,     0,     0,   845,
       0,    95,    96,    97,    98,    99,   100,     0,   502,   102,
       0,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,   851,   123,   124,     0,     0,     0,     0,     0,     0,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,   138,   139,     0,   385,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   471,   472,   473,   169,
     170,     0,   504,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
     237,     0,     0,   238,   239,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   382,   383,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,   498,   384,    25,    26,    27,     0,    28,
       0,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,    39,     0,    40,    41,    42,   499,   500,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
      64,    65,    66,    67,     0,     0,    68,    69,    70,     0,
       0,    71,    72,     0,     0,     0,    73,    74,   463,    76,
      77,    78,    79,    80,   501,    82,    83,     0,     0,     0,
       0,    84,     0,    85,    86,    87,    88,     0,    89,     0,
       0,     0,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,     0,
     502,   102,     0,   103,   104,   105,   106,   107,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
       0,   503,   122,     0,   123,   124,     0,     0,     0,     0,
       0,     0,   126,     0,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,   138,   139,
       0,   385,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   471,   472,
     473,   169,   170,     0,   504,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,   237,     0,     0,   238,   239,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     382,   383,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,   498,   384,    25,    26,    27,
       0,    28,     0,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,     0,    40,    41,    42,
     499,   500,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,     0,     0,    68,    69,
      70,     0,     0,    71,    72,     0,     0,     0,    73,    74,
     463,    76,    77,    78,    79,    80,   501,    82,    83,     0,
       0,     0,     0,    84,     0,    85,    86,    87,    88,     0,
      89,     0,     0,     0,    90,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,     0,   502,   102,     0,   103,   104,   105,   106,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,   508,   123,   124,     0,     0,
       0,     0,     0,     0,   126,     0,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     138,   139,     0,   385,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     471,   472,   473,   169,   170,     0,   504,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,   237,     0,     0,   238,   239,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   382,   383,     0,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,   498,   384,    25,
      26,    27,     0,    28,     0,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,     0,    40,
      41,    42,   499,   500,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,     0,
      68,    69,    70,     0,     0,    71,    72,     0,     0,     0,
      73,    74,   463,    76,    77,    78,    79,    80,   501,    82,
      83,     0,     0,     0,     0,    84,     0,    85,    86,    87,
      88,     0,    89,     0,     0,     0,    90,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,     0,   502,   102,     0,   103,   104,   105,
     106,   107,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,     0,     0,   126,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,   138,   139,     0,   385,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   471,   472,   473,   169,   170,     0,   504,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   548,   237,     0,     0,   238,
     239,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   382,   383,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,   498,
     384,    25,    26,    27,     0,    28,     0,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    38,    39,
       0,    40,    41,    42,   499,   500,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    65,    66,    67,
       0,     0,    68,    69,    70,     0,     0,    71,    72,     0,
       0,     0,    73,    74,   463,    76,    77,    78,    79,    80,
     501,    82,    83,     0,     0,     0,     0,    84,     0,    85,
      86,    87,    88,     0,    89,     0,     0,     0,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,     0,   502,   102,     0,   103,
     104,   105,   106,   107,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,     0,     0,   126,     0,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,   138,   139,     0,   385,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   471,   472,   473,   169,   170,     0,
     504,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,   237,   550,
       0,   238,   239,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   382,   383,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,    21,
      22,   498,   384,    25,    26,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,    39,     0,    40,    41,    42,   499,   500,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,     0,     0,    68,    69,    70,     0,     0,    71,
      72,     0,     0,     0,    73,    74,   463,    76,    77,    78,
      79,    80,   501,    82,    83,     0,     0,     0,     0,    84,
       0,    85,    86,    87,    88,     0,    89,     0,     0,     0,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,     0,   502,   102,
       0,   103,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,   138,   139,     0,   385,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,     0,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   471,   472,   473,   169,
     170,     0,   504,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,   186,   187,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
     237,     0,   552,   238,   239,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   382,   383,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,    21,    22,   498,   384,    25,    26,    27,     0,    28,
       0,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,    39,     0,    40,    41,    42,   499,   500,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
      64,    65,    66,    67,     0,     0,    68,    69,    70,     0,
       0,    71,    72,     0,     0,     0,    73,    74,   463,    76,
      77,    78,    79,    80,   501,    82,    83,     0,     0,     0,
       0,    84,     0,    85,    86,    87,    88,     0,    89,     0,
       0,     0,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,     0,
     502,   102,     0,   103,   104,   105,   106,   107,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
     838,     0,   122,     0,   123,   124,     0,     0,     0,     0,
       0,     0,   126,     0,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,   138,   139,
       0,   385,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   471,   472,
     473,   169,   170,     0,   504,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,     0,   186,
     187,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,   237,     0,     0,   238,   239,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     382,   383,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,    21,    22,   498,   384,    25,    26,    27,
       0,    28,     0,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,    39,     0,    40,    41,    42,
     499,   500,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,     0,     0,    68,    69,
      70,     0,     0,    71,    72,     0,     0,     0,    73,    74,
     463,    76,    77,    78,    79,    80,   501,    82,    83,     0,
       0,     0,     0,    84,     0,    85,    86,    87,    88,     0,
      89,     0,     0,     0,    90,    91,    92,    93,    94,     0,
       0,     0,     0,  1366,     0,    95,    96,    97,    98,    99,
     100,     0,   502,   102,     0,   103,   104,   105,   106,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   126,     0,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     138,   139,     0,   385,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     471,   472,   473,   169,   170,     0,   504,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,   237,     0,     0,   238,   239,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   382,   383,     0,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,    21,    22,   498,   384,    25,
      26,    27,     0,    28,     0,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,    39,     0,    40,
      41,    42,   499,   500,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,     0,
      68,    69,    70,     0,     0,    71,    72,     0,     0,     0,
      73,    74,   463,    76,    77,    78,    79,    80,   501,    82,
      83,     0,     0,     0,     0,    84,     0,    85,    86,    87,
      88,     0,    89,     0,     0,     0,    90,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,     0,   502,   102,     0,   103,   104,   105,
     106,   107,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,     0,   117,   118,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,     0,     0,   126,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,   138,   139,     0,   385,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   471,   472,   473,   169,   170,     0,   504,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,   186,   187,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,     0,     0,   238,
     239,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   382,   383,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,   498,
     384,    25,    26,    27,     0,    28,     0,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    38,    39,
       0,    40,    41,    42,   499,   500,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    65,    66,    67,
       0,     0,    68,    69,    70,     0,     0,    71,    72,     0,
       0,     0,    73,    74,   463,    76,    77,    78,    79,    80,
     501,    82,    83,     0,     0,     0,     0,    84,     0,    85,
      86,    87,    88,     0,    89,     0,     0,     0,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,     0,   502,   102,     0,     0,
     104,   105,   106,   107,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,     0,   117,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,     0,     0,   126,     0,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,   138,   139,     0,   385,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   471,   472,   473,   169,   170,     0,
     504,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,   186,   187,   188,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,   237,     0,
       0,   238,   239,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   382,   383,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,   449,
      22,     0,   384,    25,   452,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,   457,     0,    40,    41,    42,     0,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,     0,     0,    68,    69,    70,     0,     0,    71,
      72,     0,     0,     0,    73,    74,   463,    76,    77,    78,
      79,    80,   501,    82,    83,     0,     0,     0,     0,    84,
       0,    85,    86,    87,    88,     0,    89,     0,     0,     0,
     464,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,     0,   502,   102,
       0,   103,   104,   627,   106,   107,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,     0,
     628,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,   138,   139,     0,   385,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,   155,     0,     0,   158,   159,
     160,   161,   162,   163,   470,   165,   471,   472,   473,   169,
     170,     0,   475,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   476,     0,   186,   477,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
     237,     0,     0,     0,   239,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   382,   383,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,   449,    22,     0,   384,    25,   452,    27,     0,    28,
       0,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,   457,     0,    40,    41,    42,     0,     0,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
      64,    65,    66,    67,     0,     0,    68,    69,    70,     0,
       0,    71,    72,     0,     0,     0,    73,    74,   463,    76,
      77,    78,    79,    80,   501,    82,    83,     0,     0,     0,
       0,    84,     0,    85,    86,    87,    88,     0,    89,     0,
       0,     0,   464,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,     0,
     502,   102,     0,   103,   104,   105,   106,   107,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,     0,   117,   118,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,     0,     0,     0,     0,
       0,     0,   126,     0,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,   138,   139,
       0,   385,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,     0,     0,   155,     0,     0,
     158,   159,   160,   161,   162,   163,   470,   165,   471,   472,
     473,   169,   170,     0,   475,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   476,     0,   186,
     187,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,   237,     0,     0,     0,   239,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     382,   383,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,   449,    22,     0,   384,    25,   452,    27,
       0,    28,     0,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,   457,     0,    40,    41,    42,
       0,     0,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,     0,     0,    68,    69,
      70,     0,     0,    71,    72,     0,     0,     0,    73,    74,
     463,    76,    77,    78,    79,    80,   501,    82,    83,     0,
       0,     0,     0,    84,     0,    85,    86,    87,    88,     0,
      89,     0,     0,     0,   464,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,     0,   502,   102,     0,   103,   104,   105,   106,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,     0,   117,   118,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   126,     0,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     138,   139,     0,   385,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,   155,
       0,     0,   158,   159,   160,   161,   162,   163,   470,   165,
     471,   472,   473,   169,   170,     0,   475,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   476,
       0,   186,   477,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,   237,     0,     0,     0,   239,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     9,     0,
       0,     0,   382,   383,     0,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    20,   449,    22,     0,   384,    25,
     452,    27,     0,    28,     0,    29,    30,    31,    32,    33,
      34,     0,     0,    35,    36,    37,    38,   457,     0,    40,
      41,    42,     0,     0,    45,   461,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,    67,     0,     0,
      68,    69,    70,     0,     0,    71,    72,     0,     0,     0,
      73,    74,   463,    76,    77,    78,    79,    80,   501,    82,
      83,     0,     0,     0,     0,    84,     0,    85,    86,    87,
      88,     0,    89,     0,     0,     0,   464,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,    95,    96,    97,
      98,    99,   100,     0,   502,   102,     0,   103,   104,     0,
     106,   107,     0,     0,     0,   108,   109,   110,   111,   112,
     113,   114,   115,     0,   116,     0,     0,     0,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,     0,     0,   126,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,     0,
       0,     0,   138,   139,     0,   385,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,     0,   522,
       0,   523,     0,     0,   158,   159,   160,   161,   162,   163,
     470,   165,   471,   472,   473,   169,   170,     0,   475,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   476,     0,   186,   477,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,     0,   237,     0,   524,     0,
     239,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       9,     0,     0,     0,   382,   383,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,   449,    22,     0,
     384,    25,   452,    27,     0,    28,     0,    29,    30,    31,
      32,    33,    34,     0,     0,    35,    36,    37,    38,   457,
       0,    40,    41,    42,     0,     0,    45,   461,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    65,    66,    67,
       0,     0,    68,    69,    70,     0,     0,    71,    72,     0,
       0,     0,    73,    74,   463,    76,    77,    78,    79,    80,
     501,    82,    83,     0,     0,     0,     0,    84,     0,    85,
      86,    87,    88,     0,    89,     0,     0,     0,   464,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,    95,
      96,    97,    98,    99,   100,     0,   502,   102,     0,   103,
     104,     0,   106,   107,     0,     0,     0,   108,   109,   110,
     111,   112,   113,   114,   115,     0,   116,     0,     0,     0,
       0,     0,   119,   120,   121,     0,     0,     0,   122,     0,
     123,   124,     0,     0,     0,     0,     0,     0,   126,     0,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,     0,     0,     0,   138,   139,     0,   385,     0,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
       0,   534,     0,   155,     0,     0,   158,   159,   160,   161,
     162,   163,   470,   165,   471,   472,   473,   169,   170,     0,
     475,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   476,     0,   186,   477,   188,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,     0,   237,     0,
     535,     0,   239,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     9,     0,     0,     0,   382,   383,     0,    12,
      13,    14,    15,    16,    17,    18,    19,     0,    20,   449,
      22,     0,   384,    25,   452,    27,     0,    28,     0,    29,
      30,    31,    32,    33,    34,     0,     0,    35,    36,    37,
      38,   457,     0,    40,    41,    42,     0,     0,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,    67,     0,     0,    68,    69,    70,     0,     0,    71,
      72,     0,     0,     0,    73,    74,   463,    76,    77,    78,
      79,    80,   501,    82,    83,     0,     0,     0,     0,    84,
       0,    85,    86,    87,    88,     0,    89,     0,     0,     0,
     464,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,    95,    96,    97,    98,    99,   100,     0,   502,   102,
       0,     0,   104,   105,   106,   107,     0,     0,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     0,   116,     0,
     117,   118,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     0,     0,     0,   138,   139,     0,   385,
       0,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,     0,     0,     0,   155,     0,     0,   158,   159,
     160,   161,   162,   163,   470,   165,   471,   472,   473,   169,
     170,     0,   475,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   476,     0,   186,   187,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,     0,
     237,     0,     0,     0,   239,     1,     2,     3,     4,     5,
       6,     0,     0,     0,     9,     0,     0,     0,   382,   383,
       0,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      20,   449,    22,     0,   384,    25,   452,    27,     0,    28,
       0,    29,    30,    31,    32,    33,    34,     0,     0,    35,
      36,    37,    38,   457,     0,    40,    41,    42,     0,     0,
      45,   461,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
      64,    65,    66,    67,     0,     0,    68,    69,    70,     0,
       0,    71,    72,     0,     0,     0,    73,    74,   463,    76,
      77,    78,    79,    80,   501,    82,    83,     0,     0,     0,
       0,    84,     0,    85,    86,    87,    88,     0,    89,     0,
       0,     0,   464,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,    95,    96,    97,    98,    99,   100,     0,
     502,   102,     0,   103,   104,     0,   106,   107,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,     0,
     116,     0,     0,     0,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,     0,     0,     0,     0,
       0,     0,   126,     0,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,     0,     0,     0,   138,   139,
       0,   385,     0,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,     0,   990,     0,   155,     0,     0,
     158,   159,   160,   161,   162,   163,   470,   165,   471,   472,
     473,   169,   170,     0,   475,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   476,     0,   186,
     477,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,     0,   237,     0,     0,     0,   239,     1,     2,     3,
       4,     5,     6,     0,     0,     0,     9,     0,     0,     0,
     382,   383,     0,    12,    13,    14,    15,    16,    17,    18,
      19,     0,    20,   449,    22,     0,   384,    25,   452,    27,
       0,    28,     0,    29,    30,    31,    32,    33,    34,     0,
       0,    35,    36,    37,    38,   457,     0,    40,    41,    42,
       0,     0,    45,   461,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,    67,     0,     0,    68,    69,
      70,     0,     0,    71,    72,     0,     0,     0,    73,    74,
     463,    76,    77,    78,    79,    80,   501,    82,    83,     0,
       0,     0,     0,    84,     0,    85,    86,    87,    88,     0,
      89,     0,     0,     0,   464,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,     0,   502,   102,     0,   103,   104,     0,   106,   107,
       0,     0,     0,   108,   109,   110,   111,   112,   113,   114,
     115,     0,   116,     0,     0,     0,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   126,     0,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,     0,     0,     0,
     138,   139,     0,   385,     0,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     0,     0,     0,   155,
       0,     0,   158,   159,   160,   161,   162,   163,   470,   165,
     471,   472,   473,   169,   170,     0,   475,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   476,
       0,   186,   477,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,     0,   237,     5,     6,     0,   239,     0,
       0,     0,     0,     0,   382,   383,     0,    12,    13,    14,
    1055,    16,    17,    18,   446,  1056,  1057,   449,  1058,   451,
     384,    25,   452,    27,  1059,    28,     0,    29,    30,    31,
      32,  1060,    34,  1061,  1062,    35,    36,    37,    38,   457,
       0,    40,  1063,    42,   459,   460,    45,   461,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,    64,    65,    66,  1064,
       0,     0,    68,    69,    70,     0,     0,    71,    72,     0,
       0,     0,     0,    74,   463,    76,    77,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    88,     0,    89,     0,     0,     0,   464,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,    95,
      96,    97,     0,    99,   100,  1065,     0,     0,     0,  1066,
       0,     0,   106,   465,     0,     0,     0,   108,   109,   110,
     111,   466,   113,   114,   115,     0,     0,     0,     0,     0,
       0,     0,   119,   120,   121,     0,     0,     0,   122,  1523,
     123,   124,     0,     0,     0,     0,  1524,     0,   126,     0,
     127,   128,   129,   130,   467,   132,   133,   134,   135,   136,
     137,     0,     0,  1067,   138,     0,     0,   385,     0,   142,
     143,     0,     0,     0,   147,   148,   149,   150,   151,   152,
       0,  1068,     0,   155,     0,     0,   158,   159,   160,   161,
     162,   163,   470,   165,   471,   472,   473,   169,   170,   474,
     475,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   476,     0,   186,   477,   188,     0,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,     0,     0,     5,     6,
       0,     0,   239,  1069,  1070,  1071,  1072,   382,   383,     0,
      12,    13,    14,  1055,    16,    17,    18,   446,  1056,  1057,
     449,  1058,   451,   384,    25,   452,    27,  1059,    28,     0,
      29,    30,    31,    32,  1060,    34,  1061,  1062,    35,    36,
      37,    38,   457,     0,    40,  1063,    42,   459,   460,    45,
     461,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
      65,    66,  1064,     0,     0,    68,    69,    70,     0,     0,
      71,    72,     0,     0,     0,     0,    74,   463,    76,    77,
      78,    79,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,     0,    89,     0,     0,
       0,   464,    91,    92,    93,    94,     0,     0,     0,     0,
       0,     0,    95,    96,    97,     0,    99,   100,  1065,     0,
       0,     0,  1116,     0,     0,   106,   465,     0,     0,     0,
     108,   109,   110,   111,   466,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,   119,   120,   121,     0,     0,
       0,   122,  1353,   123,   124,     0,     0,     0,     0,     0,
       0,   126,     0,   127,   128,   129,   130,   467,   132,   133,
     134,   135,   136,   137,     0,     0,   468,   138,     0,     0,
     385,     0,   142,   143,     0,     0,     0,   147,   148,   149,
     150,   151,   152,     0,  1068,     0,   155,     0,     0,   158,
     159,   160,   161,   162,   163,   470,   165,   471,   472,   473,
     169,   170,   474,   475,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   476,     0,   186,   477,
     188,     0,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,     0,
       0,     5,     6,     0,     0,   239,  1069,  1070,  1071,  1072,
     382,   383,     0,    12,    13,    14,  1055,    16,    17,    18,
     446,  1056,  1057,   449,  1058,   451,   384,    25,   452,    27,
    1059,    28,     0,    29,    30,    31,    32,  1060,    34,  1061,
    1062,    35,    36,    37,    38,   457,     0,    40,  1063,    42,
     459,   460,    45,   461,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,    64,    65,    66,  1064,     0,     0,    68,    69,
      70,     0,     0,    71,    72,     0,     0,     0,     0,    74,
     463,    76,    77,    78,    79,    80,  1410,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,     0,
      89,     0,     0,     0,   464,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,    95,    96,    97,     0,    99,
     100,  1065,     0,     0,     0,  1066,     0,     0,   106,   465,
       0,     0,     0,   108,   109,   110,   111,   466,   113,   114,
     115,     0,     0,     0,     0,     0,     0,     0,   119,   120,
     121,     0,     0,     0,   122,     0,   123,   124,     0,     0,
       0,     0,     0,     0,   126,     0,   127,   128,   129,   130,
     467,   132,   133,   134,   135,   136,   137,     0,     0,  1067,
     138,     0,     0,   385,     0,   142,   143,     0,     0,     0,
     147,   148,   149,   150,   151,   152,     0,  1068,     0,   155,
       0,     0,   158,   159,   160,   161,   162,   163,   470,   165,
     471,   472,   473,   169,   170,   474,   475,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   476,
       0,   186,   477,   188,     0,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,     0,     0,     5,     6,     0,     0,   239,  1069,
    1070,  1071,  1072,   382,   383,     0,    12,    13,    14,  1055,
      16,    17,    18,   446,  1056,  1057,   449,  1058,   451,   384,
      25,   452,    27,  1059,    28,     0,    29,    30,    31,    32,
    1060,    34,  1061,  1062,    35,    36,    37,    38,   457,     0,
      40,  1063,    42,   459,   460,    45,   461,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    64,    65,    66,  1064,     0,
       0,    68,    69,    70,     0,     0,    71,    72,     0,     0,
       0,     0,    74,   463,    76,    77,    78,    79,    80,  1579,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,     0,    89,     0,     0,     0,   464,    91,    92,
      93,    94,     0,     0,     0,     0,     0,     0,    95,    96,
      97,     0,    99,   100,  1065,     0,     0,     0,  1066,     0,
       0,   106,   465,     0,     0,     0,   108,   109,   110,   111,
     466,   113,   114,   115,     0,     0,     0,     0,     0,     0,
       0,   119,   120,   121,     0,     0,     0,   122,     0,   123,
     124,     0,     0,     0,     0,     0,     0,   126,     0,   127,
     128,   129,   130,   467,   132,   133,   134,   135,   136,   137,
       0,     0,  1067,   138,     0,     0,   385,     0,   142,   143,
       0,     0,     0,   147,   148,   149,   150,   151,   152,     0,
    1068,     0,   155,     0,     0,   158,   159,   160,   161,   162,
     163,   470,   165,   471,   472,   473,   169,   170,   474,   475,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   476,     0,   186,   477,   188,     0,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,     0,     0,     5,     6,     0,
       0,   239,  1069,  1070,  1071,  1072,   382,   383,     0,    12,
      13,    14,  1055,    16,    17,    18,   446,  1056,  1057,   449,
    1058,   451,   384,    25,   452,    27,  1059,    28,     0,    29,
      30,    31,    32,  1060,    34,  1061,  1062,    35,    36,    37,
      38,   457,     0,    40,  1063,    42,   459,   460,    45,   461,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,  1064,     0,     0,    68,    69,    70,     0,     0,    71,
      72,     0,     0,     0,     0,    74,   463,    76,    77,    78,
      79,    80,  1583,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,     0,    89,     0,     0,     0,
     464,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,    95,    96,    97,     0,    99,   100,  1065,     0,     0,
       0,  1066,     0,     0,   106,   465,     0,     0,     0,   108,
     109,   110,   111,   466,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,   119,   120,   121,     0,     0,     0,
     122,     0,   123,   124,     0,     0,     0,     0,     0,     0,
     126,     0,   127,   128,   129,   130,   467,   132,   133,   134,
     135,   136,   137,     0,     0,  1067,   138,     0,     0,   385,
       0,   142,   143,     0,     0,     0,   147,   148,   149,   150,
     151,   152,     0,  1068,     0,   155,     0,     0,   158,   159,
     160,   161,   162,   163,   470,   165,   471,   472,   473,   169,
     170,   474,   475,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   476,     0,   186,   477,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,     0,     0,
       5,     6,     0,     0,   239,  1069,  1070,  1071,  1072,   382,
     383,     0,    12,    13,    14,  1055,    16,    17,    18,   446,
    1056,  1057,   449,  1058,   451,   384,    25,   452,    27,  1059,
      28,     0,    29,    30,    31,    32,  1060,    34,  1061,  1062,
      35,    36,    37,    38,   457,     0,    40,  1063,    42,   459,
     460,    45,   461,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,    65,    66,  1064,     0,     0,    68,    69,    70,
       0,     0,    71,    72,     0,     0,     0,     0,    74,   463,
      76,    77,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,     0,    89,
       0,     0,     0,   464,    91,    92,    93,    94,     0,     0,
       0,     0,     0,     0,    95,    96,    97,     0,    99,   100,
    1065,     0,     0,     0,  1066,     0,     0,   106,   465,     0,
       0,     0,   108,   109,   110,   111,   466,   113,   114,   115,
       0,     0,     0,     0,     0,     0,     0,   119,   120,   121,
       0,     0,     0,   122,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   126,     0,   127,   128,   129,   130,   467,
     132,   133,   134,   135,   136,   137,     0,     0,  1067,   138,
       0,     0,   385,     0,   142,   143,     0,     0,     0,   147,
     148,   149,   150,   151,   152,     0,  1068,     0,   155,     0,
       0,   158,   159,   160,   161,   162,   163,   470,   165,   471,
     472,   473,   169,   170,   474,   475,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   476,     0,
     186,   477,   188,     0,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,     0,     0,     5,     6,     0,     0,   239,  1069,  1070,
    1071,  1072,   382,   383,     0,    12,    13,    14,  1055,    16,
      17,    18,   446,  1056,  1057,   449,  1058,   451,   384,    25,
     452,    27,  1059,    28,     0,    29,    30,    31,    32,  1060,
      34,  1061,  1062,    35,    36,    37,    38,   457,     0,    40,
    1063,    42,   459,   460,    45,   461,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,    64,    65,    66,  1064,     0,     0,
      68,    69,    70,     0,     0,    71,    72,     0,     0,     0,
       0,    74,   463,    76,    77,    78,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,     0,    89,     0,     0,     0,   464,    91,    92,    93,
      94,     0,     0,     0,     0,     0,     0,    95,    96,    97,
       0,    99,   100,  1065,     0,     0,     0,  1116,     0,     0,
     106,   465,     0,     0,     0,   108,   109,   110,   111,   466,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
     119,   120,   121,     0,     0,     0,   122,     0,   123,   124,
       0,     0,     0,     0,     0,     0,   126,     0,   127,   128,
     129,   130,   467,   132,   133,   134,   135,   136,   137,     0,
       0,   468,   138,     0,     0,   385,     0,   142,   143,     0,
       0,     0,   147,   148,   149,   150,   151,   152,     0,  1068,
       0,   155,     0,     0,   158,   159,   160,   161,   162,   163,
     470,   165,   471,   472,   473,   169,   170,   474,   475,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   476,     0,   186,   477,   188,     0,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,     0,     0,     5,     6,     0,     0,
     239,  1069,  1070,  1071,  1072,   382,   383,     0,    12,    13,
      14,   445,    16,    17,    18,   446,   447,   448,   449,   450,
     451,   384,    25,   452,    27,   453,    28,     0,    29,    30,
      31,    32,   454,    34,   455,   456,    35,    36,    37,    38,
     457,     0,    40,   458,    42,   459,   460,    45,   461,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,     0,    64,    65,    66,
     462,     0,     0,    68,    69,    70,     0,     0,    71,    72,
       0,     0,     0,     0,    74,   463,    76,    77,    78,    79,
      80,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,     0,    89,     0,     0,     0,   464,
      91,    92,    93,    94,     0,     0,     0,     0,     0,     0,
      95,    96,    97,     0,    99,   100,     0,     0,     0,     0,
       0,     0,     0,   106,   465,     0,     0,     0,   108,   109,
     110,   111,   466,   113,   114,   115,     0,     0,     0,     0,
       0,     0,     0,   119,   120,   121,     0,     0,     0,   122,
    1520,   123,   124,     0,     0,     0,     0,  1521,     0,   126,
       0,   127,   128,   129,   130,   467,   132,   133,   134,   135,
     136,   137,     0,     0,   468,   138,     0,     0,   385,     0,
     142,   143,     0,     0,     0,   147,   148,   149,   150,   151,
     152,     0,   469,     0,   155,     0,     0,   158,   159,   160,
     161,   162,   163,   470,   165,   471,   472,   473,   169,   170,
     474,   475,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   476,     0,   186,   477,   188,     0,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,     5,     6,     0,
       0,     0,     0,   239,     0,     0,   382,   383,     0,    12,
      13,    14,   445,    16,    17,    18,   446,   447,   448,   449,
     450,   451,   384,    25,   452,    27,   453,    28,     0,    29,
      30,    31,    32,   454,    34,   455,   456,    35,    36,    37,
      38,   457,     0,    40,   458,    42,   459,   460,    45,   461,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,    64,    65,
      66,   462,     0,     0,    68,    69,    70,     0,     0,    71,
      72,     0,     0,     0,     0,    74,   463,    76,    77,    78,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    88,     0,    89,     0,     0,     0,
     464,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,    95,    96,    97,     0,    99,   100,     0,     0,     0,
       0,     0,     0,     0,   106,   465,     0,     0,     0,   108,
     109,   110,   111,   466,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,   119,   120,   121,     0,     0,     0,
     122,  1534,   123,   124,     0,     0,     0,     0,  1535,     0,
     126,     0,   127,   128,   129,   130,   467,   132,   133,   134,
     135,   136,   137,     0,     0,   468,   138,     0,     0,   385,
       0,   142,   143,     0,     0,     0,   147,   148,   149,   150,
     151,   152,     0,   469,     0,   155,     0,     0,   158,   159,
     160,   161,   162,   163,   470,   165,   471,   472,   473,   169,
     170,   474,   475,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   476,     0,   186,   477,   188,
       0,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,     5,     6,
       0,     0,     0,     0,   239,     0,     0,   382,   383,     0,
      12,    13,    14,   445,    16,    17,    18,   446,   447,   448,
     449,   450,   451,   384,    25,   452,    27,   453,    28,     0,
      29,    30,    31,    32,   454,    34,   455,   456,    35,    36,
      37,    38,   457,     0,    40,   458,    42,   459,   460,    45,
     461,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,    64,
      65,    66,   462,     0,     0,    68,    69,    70,     0,     0,
      71,    72,     0,     0,     0,     0,    74,   463,    76,    77,
      78,    79,    80,  1283,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,     0,    89,     0,     0,
       0,   464,    91,    92,    93,    94,     0,     0,     0,     0,
       0,     0,    95,    96,    97,     0,    99,   100,     0,     0,
       0,     0,     0,     0,     0,   106,   465,     0,     0,     0,
     108,   109,   110,   111,   466,   113,   114,   115,     0,     0,
       0,     0,     0,     0,     0,   119,   120,   121,     0,     0,
       0,   122,     0,   123,   124,     0,     0,     0,     0,     0,
       0,   126,     0,   127,   128,   129,   130,   467,   132,   133,
     134,   135,   136,   137,     0,     0,   468,   138,     0,     0,
     385,     0,   142,   143,     0,     0,     0,   147,   148,   149,
     150,   151,   152,     0,   469,     0,   155,     0,     0,   158,
     159,   160,   161,   162,   163,   470,   165,   471,   472,   473,
     169,   170,   474,   475,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   476,     0,   186,   477,
     188,     0,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,     5,
       6,     0,     0,     0,     0,   239,     0,     0,   382,   383,
       0,    12,    13,    14,   445,    16,    17,    18,   446,   447,
     448,   449,   450,   451,   384,    25,   452,    27,   453,    28,
       0,    29,    30,    31,    32,   454,    34,   455,   456,    35,
      36,    37,    38,   457,     0,    40,   458,    42,   459,   460,
      45,   461,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
      64,    65,    66,   462,     0,     0,    68,    69,    70,     0,
       0,    71,    72,     0,     0,     0,     0,    74,   463,    76,
      77,    78,    79,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,     0,    89,     0,
       0,     0,   464,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,    95,    96,    97,     0,    99,   100,     0,
       0,     0,     0,     0,     0,     0,   106,   465,     0,     0,
       0,   108,   109,   110,   111,   466,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     0,   119,   120,   121,     0,
       0,     0,   122,     0,   123,   124,     0,     0,     0,     0,
       0,     0,   126,     0,   127,   128,   129,   130,   467,   132,
     133,   134,   135,   136,   137,     0,     0,   468,   138,     0,
       0,   385,     0,   142,   143,     0,     0,     0,   147,   148,
     149,   150,   151,   152,     0,   469,     0,   155,     0,     0,
     158,   159,   160,   161,   162,   163,   470,   165,   471,   472,
     473,   169,   170,   474,   475,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   476,     0,   186,
     477,   188,     0,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
       5,     6,     0,     0,     0,     0,   239,     0,     0,   382,
     383,     0,    12,    13,    14,     0,    16,    17,    18,   446,
       0,     0,   449,   450,     0,   384,    25,   452,    27,     0,
      28,     0,    29,    30,    31,    32,     0,    34,     0,     0,
      35,    36,    37,    38,   457,     0,    40,     0,    42,     0,
       0,    45,   461,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
       0,    64,    65,    66,     0,     0,     0,    68,    69,    70,
       0,     0,    71,    72,     0,     0,     0,     0,    74,   463,
      76,    77,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,     0,    89,
       0,     0,     0,   464,    91,    92,    93,    94,     0,     0,
       0,     0,     0,     0,    95,    96,    97,     0,    99,   100,
       0,     0,     0,     0,     0,     0,     0,   106,   465,     0,
       0,     0,   108,   109,   110,   111,   466,   113,   114,   115,
       0,     0,     0,     0,     0,     0,     0,   119,   120,   121,
       0,     0,     0,   122,     0,   123,   124,     0,     0,     0,
       0,     0,     0,   126,     0,   127,   128,   129,   130,   467,
     132,   133,   134,   135,   136,   137,     0,     0,     0,   138,
       0,     0,   385,     0,   142,   143,     0,     0,     0,   147,
     148,   149,   150,   151,   152,     0,     0,     0,   155,     0,
       0,   158,   159,   160,   161,   162,   163,   470,   165,   471,
     472,   473,   169,   170,     0,   475,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   476,     0,
     186,   477,   188,     0,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,     0,     0,     0,     0,     0,     0,   239
  };

  /* YYCHECK.  */
  const short int
  jsoniq_parser::yycheck_[] =
  {
         0,     1,     2,     3,     4,     0,     1,     2,     3,     4,
     172,   116,   614,   300,     1,     2,     3,     4,     1,     2,
       3,   279,   736,   393,   394,    10,   944,   833,   834,   331,
     630,   153,   395,   931,   156,     1,     2,     3,     4,   567,
     568,   708,   811,   615,   616,   617,   618,   820,  1210,   633,
     248,   718,  1194,   187,   154,  1277,  1278,     1,   247,   966,
     858,  1027,     1,   426,   427,   263,   811,   908,  1413,   240,
     241,  1416,  1041,    27,    28,   908,  1334,   565,   566,   874,
     655,    37,  1223,   565,   566,   567,   568,    57,   120,    27,
      28,     1,    37,    30,    48,    98,   124,   120,     1,    96,
       1,   101,  1556,    30,   145,   109,   101,     1,     1,     1,
      48,   109,  1611,     1,   101,   921,    95,   109,   102,   109,
      58,   109,    76,     1,     0,     1,   932,    40,     0,     1,
     388,     1,    45,    46,   392,   101,   156,   133,    76,    53,
      96,    54,    98,    81,   811,   139,   159,   220,    61,     1,
      63,    64,   124,    98,     1,     1,   133,     1,     1,    72,
     114,    96,     1,   134,     1,   109,     1,   188,     1,     1,
     109,   102,     1,   108,   163,   113,   114,   115,   270,    43,
     156,    31,     8,    47,   115,   112,    99,   260,    52,   934,
     120,   212,   212,     1,   150,   102,   103,     1,   186,   231,
     127,    46,   192,   199,   188,   150,   185,    71,  1707,   203,
     145,   239,   159,   880,    56,    98,    58,     1,   132,    64,
     507,   192,   199,     1,     1,   152,   163,   224,   225,   156,
      30,   109,   159,   109,   492,   239,  1458,   109,   279,   109,
     240,   241,   239,   241,   244,   240,   241,   239,   962,   244,
     220,     1,   179,   920,   782,   783,   279,   109,   188,   262,
     102,     1,   109,   109,  1033,   109,   109,   239,  1041,  1042,
     109,  1066,   109,  1191,   109,  1729,   109,   109,  1176,   279,
     109,   313,   192,  1425,   279,   860,  1031,  1428,  1033,   192,
     260,   192,   780,   781,   221,   222,   223,  1555,   192,   192,
     192,   109,   407,   666,   192,   109,   170,  1214,   186,   173,
     186,    98,   112,   418,   186,  1113,  1223,  1283,   231,   189,
    1161,  1116,   414,   279,   188,   109,   584,   127,  1161,   236,
     237,   109,   109,    81,   279,   187,   699,  1682,   265,   293,
     156,  1310,   189,   189,   189,   189,   189,   301,   187,   186,
     214,   177,   152,   101,   189,   293,   104,   189,     1,   109,
     189,   150,  1168,   301,   562,   563,   216,  1034,   116,   109,
     118,   309,   279,   102,   572,   319,   565,   566,   317,   262,
     263,   189,   109,   554,   171,   189,    38,    39,   388,    41,
      42,    30,   392,   388,  1739,   109,  1741,   392,     1,   263,
     156,   109,   524,    96,   156,   189,   154,    59,   186,   186,
     323,   324,   325,   535,     1,   257,    98,     1,   150,   419,
     420,   221,   222,   223,   419,   420,    27,    28,   270,   109,
     272,   531,   419,   420,   102,   435,   186,   120,    96,   439,
     435,   283,   284,   285,   439,   287,   186,   289,   435,  1671,
     820,    34,   439,   419,   420,     1,   212,   150,   109,   188,
     231,   109,   189,   115,   122,   236,   109,    50,   602,   435,
     188,   258,   259,   439,   261,   189,   115,   156,     9,    98,
       5,   388,   190,   853,     9,   392,  1014,  1015,  1016,   171,
     279,   278,   492,  1160,   212,   159,   115,   492,    29,   157,
     109,   159,   502,   290,    78,   188,   109,   502,    98,   189,
    1732,   163,   770,   114,   421,   502,  1285,   424,   881,   882,
     188,  1428,   109,   886,   163,   109,   433,   109,   633,   436,
     437,  1115,  1014,  1015,  1016,   442,   502,  1310,   189,  1345,
     798,   189,  1704,   186,   161,   545,  1319,   279,  1293,   320,
     545,   120,   109,   916,   554,   109,  1156,  1330,   545,   554,
       9,   178,     1,   109,     3,   565,   566,   567,   568,   159,
     565,   566,   567,   568,   226,   560,   258,   259,   134,   261,
      29,   190,   156,   186,   584,   492,   268,   159,   786,   584,
     695,   780,   790,   698,   109,   126,   278,   128,    46,   186,
      48,   126,   186,   128,   511,   512,   137,   189,   290,   109,
     517,   136,    27,    28,  1281,   267,   139,  1759,    96,   724,
     189,   109,   188,    38,    39,   156,    41,    42,    96,    68,
     153,   156,   189,    48,    73,   189,   192,   544,   545,   761,
     186,    43,    98,    58,    59,    47,   212,    25,     9,    10,
      52,   399,   400,   227,   228,   403,   108,    35,   275,   407,
     108,    76,   410,   411,    43,   282,    81,  1565,    47,    71,
     418,  1041,  1042,    52,   189,   292,   122,   126,   130,   128,
     428,   120,   150,     5,    62,   120,   434,     9,   137,   189,
     438,   691,    71,     1,   150,   443,   691,    96,   113,   114,
     115,   189,    96,    98,   691,  1474,   156,   156,   691,    55,
      96,   157,  1426,   159,    60,   715,   716,  1431,    98,  1321,
     715,   716,   170,   122,   631,   691,    34,   634,   715,   716,
    1694,  1695,   480,    79,  1507,   115,     9,    10,  1266,   997,
      98,  1043,    50,    46,   105,    48,   224,   225,   163,   715,
     716,   145,    98,   501,   502,   150,     1,   115,   157,   145,
     159,   239,   269,   159,   238,   126,   240,   128,   170,    97,
     770,   173,  1578,   280,   120,   770,     9,    10,    81,   159,
     108,   122,  1746,   531,    96,  1703,   188,  1387,  1752,    34,
     118,   170,   540,   159,   173,   156,   119,   243,   798,   160,
     998,   159,   130,   798,   126,   108,   128,   792,  1171,   188,
     147,   226,   214,  1011,   136,   176,   157,   171,   159,    30,
     727,   728,   729,   122,   731,    55,   149,   156,   140,   161,
      60,   161,   105,   145,   156,   214,   197,   871,   188,   162,
    1646,   178,  1648,   156,  1006,   120,   178,   595,   178,   883,
     204,   599,   267,   126,   215,   128,     9,    10,   157,   196,
     159,   263,   212,   770,   124,   124,   179,   170,    98,   201,
     992,   201,   105,   196,   188,  1589,   120,   140,   293,  1593,
     156,   188,   145,   156,   263,   633,   301,   160,   148,   148,
     253,   254,   156,   126,   309,   128,  1498,  1499,   212,   159,
     159,   112,   243,   176,   161,   212,   168,   131,   132,   151,
    1273,   659,  1170,   276,   662,   179,   127,   184,  1724,  1491,
     151,   178,   184,   156,   197,   167,    96,   160,   676,    55,
     184,   198,   680,   681,    60,   156,   167,   140,   108,   687,
    1310,   152,   215,   176,   198,   156,   946,   695,   159,  1319,
     698,   946,   105,   156,   702,   275,   156,   102,  1558,   946,
    1330,   140,   282,   148,   197,   102,   219,  1642,   179,  1644,
     115,  1258,   292,   126,   159,   128,   724,   156,   115,  1654,
     946,  1656,   215,   102,  1698,   102,   102,   735,   274,   269,
     569,   227,   228,   229,   573,   281,   115,   997,   115,   115,
     280,   140,   997,   156,  1671,   219,   145,   160,   203,   305,
     221,   222,   223,   120,  1014,  1015,  1016,   212,   314,  1014,
    1015,  1016,   247,   176,   772,   247,  1628,  1629,  1013,   131,
     132,  1394,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,   612,   613,   197,   283,   284,   285,   238,   248,
     240,   289,   619,   620,   802,    81,   205,   206,   207,   208,
     209,   210,   215,   621,   622,  1154,  1155,   815,  1546,  1547,
     159,   156,     0,   169,   192,   101,  1676,    94,   104,   255,
     101,    51,   202,   103,   195,   833,   834,   835,   836,   104,
     116,   186,   118,  1255,   186,   186,   186,    30,    48,  1462,
     155,   120,   252,   310,   156,     1,   120,   145,   109,   156,
     156,   145,   186,  1715,   124,   124,   159,   159,   159,   156,
      36,    30,    17,   216,    30,   237,   874,   236,   154,   192,
    1730,   192,     3,  1040,   239,   120,   251,  1507,   170,   172,
     888,   172,   290,   290,   120,    72,   157,    96,  1406,   237,
      96,    96,   152,   109,   109,    30,   163,   163,   130,    96,
     135,   305,   145,   120,  1164,   913,   252,   135,   186,  1164,
    1170,    96,    98,   921,   186,  1170,    46,  1164,    98,   156,
     145,  1164,  1182,   186,   932,    96,   243,  1182,   186,   237,
     192,    34,   172,  1451,   239,  1182,   120,   109,  1164,  1182,
     135,  1201,   145,    96,    30,   292,  1201,    96,   233,  1809,
     120,  1811,   156,    96,  1201,   186,  1182,   135,  1201,   200,
    1220,  1821,   305,   163,    98,  1220,   156,  1227,   135,   120,
     102,   150,  1227,  1220,   102,  1201,   124,   145,   186,   186,
    1227,   156,  1347,   124,    36,    30,    30,    98,    81,   109,
     192,   156,   251,   120,  1220,   109,   120,   130,   150,   264,
     273,  1227,  1262,   260,   291,   159,    30,  1262,   292,   159,
     266,    30,   159,   159,   159,  1262,  1024,   159,    30,  1027,
     159,   159,   159,   159,   312,   293,   109,   186,   192,   147,
     159,   102,   233,   159,   159,   145,   159,   159,   159,   200,
     159,   135,     7,   239,    98,  1563,   322,   239,   192,   243,
     239,   159,   192,   159,   159,   156,  1574,  1575,  1066,  1577,
     108,   150,   239,   130,   120,   150,   150,  1585,    79,   120,
     150,   188,   292,   189,   256,   256,   288,    80,    30,    30,
     189,   109,   189,   129,   172,   189,   277,   189,   129,   189,
     189,   189,   189,   189,   189,   186,    98,   189,   188,   186,
     263,   322,   145,   150,    96,    30,   188,   188,  1116,   186,
     186,   186,   150,   186,   400,   189,   156,   403,    98,   189,
     189,   407,   172,   189,   410,   411,   286,   189,   189,   189,
     189,   293,   418,    96,   199,   108,   150,    55,    96,    30,
     109,   109,   428,   120,   199,   120,  1406,    96,   434,   188,
      96,  1406,   438,   231,   189,   189,   271,   443,   200,   147,
    1168,   120,   199,   189,   189,    95,   189,   189,   231,   185,
     188,   188,   199,  1691,   231,  1183,   120,   120,   120,   665,
     201,  1117,   875,   394,  1161,  1193,   922,   414,  1676,  1730,
    1039,  1451,   773,   599,   480,   244,  1451,   704,   311,   311,
    1484,  1302,  1282,  1280,  1277,  1020,  1188,  1183,   244,   601,
    1191,  1196,   836,  1221,   247,   501,   502,   611,   609,   636,
     299,  1263,  1740,   639,  1214,   480,   736,  1752,  1343,  1746,
     633,   633,  1343,  1644,  1249,   293,  1260,  1259,  1319,   311,
    1758,  1249,  1330,  1042,   312,   531,  1507,  1051,   312,  1323,
     907,  1259,  1139,  1504,   540,  1263,  1377,  1320,  1549,   312,
      -1,    -1,    -1,  1781,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1283,    -1,    -1,  1286,    -1,
      -1,  1448,  1449,  1450,    -1,  1803,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1301,  1812,   326,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1563,    -1,    -1,    -1,    -1,  1563,   595,
      -1,    -1,    -1,   599,  1574,  1575,    -1,  1577,    -1,  1574,
    1575,    -1,  1577,    -1,    -1,  1585,    -1,    -1,    -1,    -1,
    1585,    -1,    -1,    -1,    -1,    -1,  1344,  1345,    -1,  1347,
    1348,  1349,    -1,  1351,    -1,    -1,    -1,   633,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1383,   662,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     676,    -1,    -1,    -1,   680,   681,    -1,    -1,    -1,    -1,
      -1,   687,  1410,    -1,    -1,  1413,   154,    -1,  1416,   695,
      -1,    -1,   698,    -1,    -1,    -1,   702,    -1,    -1,  1427,
      -1,    -1,    -1,    -1,  1432,    -1,    -1,    -1,    -1,    -1,
      -1,  1691,    -1,    -1,    -1,    -1,  1691,    -1,   724,    -1,
    1607,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   735,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1638,    -1,  1481,  1482,    -1,    -1,    -1,    -1,    -1,
    1740,    -1,    -1,    -1,    -1,  1740,   772,    -1,    -1,    -1,
     238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1758,    -1,
      -1,    -1,    -1,  1758,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   802,    -1,    -1,    -1,
      -1,  1781,    -1,    -1,    -1,    -1,  1781,    -1,    -1,   815,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1803,    -1,    -1,    -1,    -1,  1803,   835,
     836,    -1,  1812,    -1,    -1,    -1,    -1,  1812,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1578,  1579,    -1,  1581,    -1,  1583,    -1,    -1,    -1,    -1,
      -1,    -1,  1590,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   888,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   913,    -1,    -1,
      -1,    -1,    -1,    -1,  1642,    -1,  1644,    -1,  1646,    -1,
    1648,    -1,    -1,    -1,    -1,    -1,  1654,    -1,  1656,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1672,    -1,    -1,  1675,    -1,    -1,
      -1,    -1,    -1,    -1,  1682,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1693,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1724,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1734,    -1,    -1,    -1,
      -1,  1739,    -1,  1741,    -1,    -1,    -1,    -1,  1024,    -1,
      -1,  1027,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   502,  1763,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1779,    -1,    -1,   522,   523,    -1,    -1,    -1,    -1,
      -1,   529,   530,   531,    -1,    -1,   534,    -1,    -1,   537,
      -1,  1799,    -1,    -1,    -1,   543,  1804,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   552,    -1,    -1,    -1,  1816,    -1,
      -1,  1819,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   575,   576,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   584,   585,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   635,    -1,    -1,
      -1,   639,    -1,    -1,    -1,    -1,    -1,  1183,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     678,    -1,    -1,    -1,    -1,  1221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   703,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1249,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   719,    -1,  1259,    -1,   723,   724,  1263,   726,    -1,
      -1,    -1,    -1,    -1,    -1,   733,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1283,    -1,    -1,
    1286,    -1,    -1,    -1,    -1,    -1,    -1,   755,   756,    -1,
      -1,   759,    -1,    -1,    -1,  1301,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     778,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     798,    -1,    -1,    -1,    -1,    -1,   804,    -1,  1344,    -1,
      -1,  1347,  1348,  1349,    -1,  1351,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1383,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1410,    -1,    -1,    -1,   876,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1427,    -1,    -1,    -1,    -1,  1432,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   911,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   933,    -1,    -1,    -1,    -1,
      -1,    -1,   940,   941,    -1,  1481,  1482,    -1,    -1,    -1,
      -1,    -1,    -1,   951,    -1,    -1,   954,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   975,   976,   977,
      -1,   979,   980,   981,   982,   983,    -1,    -1,   986,   987,
      -1,   989,   990,    -1,    -1,    -1,   994,   995,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1009,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1020,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1030,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1579,    -1,  1581,    -1,  1583,    -1,    -1,
      -1,    -1,    -1,    -1,  1590,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1103,  1642,    -1,  1644,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1654,    -1,
    1656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1672,    -1,    -1,  1675,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1693,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1170,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1180,    -1,    -1,    -1,    -1,    -1,  1186,  1187,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1734,    -1,
      -1,    -1,    -1,    -1,    -1,  1203,    -1,    -1,  1206,  1207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1763,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1779,    -1,    -1,    -1,    -1,    -1,  1247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1799,    -1,    -1,    -1,    -1,  1804,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1816,    -1,  1280,  1819,    -1,    -1,    -1,    -1,    -1,    -1,
    1288,    -1,  1290,    -1,  1292,    -1,    -1,  1295,    -1,    -1,
      -1,    -1,  1300,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1397,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1405,  1406,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1424,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1437,
    1438,  1439,  1440,    -1,  1442,  1443,    -1,  1445,    -1,  1447,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1463,    -1,    -1,    -1,    -1,
    1468,    -1,    -1,    -1,  1472,    -1,    -1,    -1,  1476,    -1,
    1478,    -1,  1480,    -1,    -1,    -1,    -1,    -1,  1486,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1564,    -1,    -1,    -1,
      -1,  1569,  1570,    -1,    -1,    -1,    -1,    -1,    -1,  1577,
      -1,    -1,    -1,    -1,  1582,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1599,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1612,    -1,  1614,    -1,  1616,    -1,
      -1,  1619,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1687,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1710,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1740,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,     1,    -1,    -1,    -1,    -1,    -1,  1777,
      -1,    -1,    -1,  1781,    -1,    -1,    -1,    -1,  1786,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,  1802,    -1,    34,    35,  1806,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,    -1,   232,   233,   234,   235,   236,   237,
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
      39,    40,    41,    42,    43,    44,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,   214,   215,    -1,   217,    -1,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,    -1,   232,   233,   234,   235,   236,   237,   238,
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
      43,    44,    -1,    46,    47,    48,    49,    50,    51,    52,
      53,    -1,    55,    -1,    57,    58,    59,    60,    61,    62,
      -1,    -1,    65,    66,    67,    68,    69,    -1,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    -1,    96,    97,    98,    99,    -1,    -1,   102,
     103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
      -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,
      -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,   142,
      -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,
     153,   154,    -1,   156,   157,    -1,   159,   160,   161,   162,
     163,    -1,    -1,    -1,   167,   168,   169,   170,   171,   172,
     173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,
     183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,   192,
      -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,   214,   215,    -1,   217,    -1,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,    -1,   232,
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
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    -1,    65,    66,
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
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,   214,   215,    -1,
     217,    -1,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,    -1,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    -1,   250,   251,   252,   253,   254,   255,   256,
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
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,   167,   168,
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
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      57,    58,    59,    60,    61,    62,    -1,    -1,    65,    66,
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
     167,   168,   169,   170,   171,   172,   173,   174,    -1,   176,
      -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,
      -1,   188,    -1,   190,   191,   192,    -1,    -1,    -1,    -1,
      -1,   198,    -1,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,    -1,    -1,    -1,   214,   215,    -1,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,    -1,   232,   233,   234,   235,   236,
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
      39,    40,    41,    42,    43,    44,    -1,    46,    47,    48,
      49,    50,    51,    52,    53,    -1,    55,    -1,    57,    58,
      59,    60,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    -1,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,
      -1,    -1,    -1,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,    -1,
     159,   160,   161,   162,   163,    -1,    -1,    -1,   167,   168,
     169,   170,   171,   172,   173,   174,    -1,   176,    -1,   178,
     179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,
      -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,   214,   215,    -1,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,    -1,   232,   233,   234,   235,   236,   237,   238,
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
     121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,   152,   153,   154,    -1,   156,   157,    -1,   159,   160,
     161,   162,   163,    -1,    -1,    -1,   167,   168,   169,   170,
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
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
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
     115,   116,   117,   118,   119,   120,   121,   122,    -1,    -1,
      -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,   154,
      -1,   156,   157,    -1,   159,   160,   161,   162,   163,    -1,
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
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,    -1,    -1,    -1,    -1,   159,    -1,    -1,   162,   163,
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
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
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
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,
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
      -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,
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
      44,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    57,    58,    59,    60,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     214,   215,    -1,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,    -1,   232,   233,
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
      42,    43,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    -1,    57,    58,    59,    60,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,   186,    -1,   188,    -1,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,    -1,
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
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,   192,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,    -1,   232,   233,   234,   235,   236,   237,   238,   239,
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
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,   192,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,    -1,   232,   233,   234,   235,   236,   237,
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
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      -1,    57,    58,    59,    60,    61,    62,    -1,    -1,    65,
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
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,   192,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,    -1,   232,   233,   234,   235,
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
      44,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    57,    58,    59,    60,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,   192,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,    -1,   232,   233,
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
      42,    43,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    -1,    57,    58,    59,    60,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
     192,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,    -1,
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
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,   147,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,   189,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,    -1,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
      -1,   321,   322,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,   147,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,   189,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,    -1,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,   321,   322,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      -1,    57,    58,    59,    60,    61,    62,    -1,    -1,    65,
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
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,   187,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,    -1,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,   321,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    57,    58,    59,    60,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,   189,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,    -1,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    -1,    57,    58,    59,    60,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,    -1,    -1,   321,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,   161,   162,   163,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,    -1,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,   319,
      -1,   321,   322,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    49,    50,    51,    52,    53,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,    -1,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,   320,   321,   322,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    49,    50,    51,    52,    53,    -1,    55,
      -1,    57,    58,    59,    60,    61,    62,    -1,    -1,    65,
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
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
     186,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,    -1,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,   321,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    48,    49,    50,    51,    52,    53,
      -1,    55,    -1,    57,    58,    59,    60,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,   147,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,    -1,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,   321,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    48,    49,    50,    51,
      52,    53,    -1,    55,    -1,    57,    58,    59,    60,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,   161,
     162,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,   178,   179,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,    -1,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,    -1,   321,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    49,
      50,    51,    52,    53,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,    -1,
     160,   161,   162,   163,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,   178,   179,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,    -1,   232,   233,   234,   235,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
      -1,   321,   322,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    50,    51,    52,    53,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,   159,   160,   161,   162,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,    -1,    -1,    -1,   233,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,    -1,   322,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    -1,    50,    51,    52,    53,    -1,    55,
      -1,    57,    58,    59,    60,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,   161,   162,   163,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,   178,   179,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,    -1,    -1,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,    -1,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    48,    -1,    50,    51,    52,    53,
      -1,    55,    -1,    57,    58,    59,    60,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,   161,   162,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,   178,   179,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,    -1,    -1,    -1,   233,
      -1,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
      -1,   265,   266,   267,    -1,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,    -1,   318,    -1,    -1,    -1,   322,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    34,    35,    -1,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    46,    47,    48,    -1,    50,    51,
      52,    53,    -1,    55,    -1,    57,    58,    59,    60,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    -1,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    96,    97,    98,    99,    -1,    -1,
     102,   103,   104,    -1,    -1,   107,   108,    -1,    -1,    -1,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,    -1,    -1,    -1,    -1,   127,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
     152,   153,   154,    -1,   156,   157,    -1,   159,   160,    -1,
     162,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
     172,   173,   174,    -1,   176,    -1,    -1,    -1,    -1,    -1,
     182,   183,   184,    -1,    -1,    -1,   188,    -1,   190,   191,
      -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,   214,   215,    -1,   217,    -1,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,    -1,   231,
      -1,   233,    -1,    -1,   236,   237,   238,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   248,    -1,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,    -1,   265,   266,   267,    -1,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,    -1,   318,    -1,   320,    -1,
     322,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    34,    35,    -1,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    46,    47,    48,    -1,
      50,    51,    52,    53,    -1,    55,    -1,    57,    58,    59,
      60,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      -1,    71,    72,    73,    -1,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    96,    97,    98,    99,
      -1,    -1,   102,   103,   104,    -1,    -1,   107,   108,    -1,
      -1,    -1,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,    -1,    -1,    -1,    -1,   127,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,   152,   153,   154,    -1,   156,   157,    -1,   159,
     160,    -1,   162,   163,    -1,    -1,    -1,   167,   168,   169,
     170,   171,   172,   173,   174,    -1,   176,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,    -1,    -1,    -1,   188,    -1,
     190,   191,    -1,    -1,    -1,    -1,    -1,    -1,   198,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,   214,   215,    -1,   217,    -1,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
      -1,   231,    -1,   233,    -1,    -1,   236,   237,   238,   239,
     240,   241,   242,   243,   244,   245,   246,   247,   248,    -1,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,    -1,   265,   266,   267,    -1,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,    -1,   318,    -1,
     320,    -1,   322,    21,    22,    23,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    35,    -1,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    46,    47,
      48,    -1,    50,    51,    52,    53,    -1,    55,    -1,    57,
      58,    59,    60,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    -1,    71,    72,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    -1,    96,    97,
      98,    99,    -1,    -1,   102,   103,   104,    -1,    -1,   107,
     108,    -1,    -1,    -1,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,    -1,    -1,    -1,    -1,   127,
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,   152,   153,   154,    -1,   156,   157,
      -1,    -1,   160,   161,   162,   163,    -1,    -1,    -1,   167,
     168,   169,   170,   171,   172,   173,   174,    -1,   176,    -1,
     178,   179,    -1,    -1,   182,   183,   184,    -1,    -1,    -1,
     188,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
     198,    -1,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,    -1,    -1,    -1,   214,   215,    -1,   217,
      -1,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,    -1,    -1,    -1,   233,    -1,    -1,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    -1,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,    -1,   265,   266,   267,
      -1,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,    -1,
     318,    -1,    -1,    -1,   322,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    35,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      46,    47,    48,    -1,    50,    51,    52,    53,    -1,    55,
      -1,    57,    58,    59,    60,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    -1,    71,    72,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    -1,
      96,    97,    98,    99,    -1,    -1,   102,   103,   104,    -1,
      -1,   107,   108,    -1,    -1,    -1,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,    -1,    -1,    -1,
      -1,   127,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,   152,   153,   154,    -1,
     156,   157,    -1,   159,   160,    -1,   162,   163,    -1,    -1,
      -1,   167,   168,   169,   170,   171,   172,   173,   174,    -1,
     176,    -1,    -1,    -1,    -1,    -1,   182,   183,   184,    -1,
      -1,    -1,   188,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,   198,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,   214,   215,
      -1,   217,    -1,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,    -1,   231,    -1,   233,    -1,    -1,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,    -1,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,    -1,   265,
     266,   267,    -1,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,    -1,   318,    -1,    -1,    -1,   322,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,
      34,    35,    -1,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    46,    47,    48,    -1,    50,    51,    52,    53,
      -1,    55,    -1,    57,    58,    59,    60,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    -1,    71,    72,    73,
      -1,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    -1,    96,    97,    98,    99,    -1,    -1,   102,   103,
     104,    -1,    -1,   107,   108,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,    -1,
      -1,    -1,    -1,   127,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,   152,   153,
     154,    -1,   156,   157,    -1,   159,   160,    -1,   162,   163,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
     174,    -1,   176,    -1,    -1,    -1,    -1,    -1,   182,   183,
     184,    -1,    -1,    -1,   188,    -1,   190,   191,    -1,    -1,
      -1,    -1,    -1,    -1,   198,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     214,   215,    -1,   217,    -1,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,    -1,    -1,    -1,   233,
      -1,    -1,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    -1,   250,   251,   252,   253,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,
     130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,
     140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,
     150,   151,    -1,   153,   154,   155,    -1,    -1,    -1,   159,
      -1,    -1,   162,   163,    -1,    -1,    -1,   167,   168,   169,
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
      -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,    -1,   153,   154,   155,    -1,
      -1,    -1,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,
     134,    -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,
      -1,    -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,
     154,   155,    -1,    -1,    -1,   159,    -1,    -1,   162,   163,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,
     131,   132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,
     141,   142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,
     151,    -1,   153,   154,   155,    -1,    -1,    -1,   159,    -1,
      -1,   162,   163,    -1,    -1,    -1,   167,   168,   169,   170,
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
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,    -1,   153,   154,   155,    -1,    -1,
      -1,   159,    -1,    -1,   162,   163,    -1,    -1,    -1,   167,
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
      -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,
     155,    -1,    -1,    -1,   159,    -1,    -1,   162,   163,    -1,
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
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,   131,
     132,    -1,   134,    -1,    -1,    -1,   138,   139,   140,   141,
     142,    -1,    -1,    -1,    -1,    -1,    -1,   149,   150,   151,
      -1,   153,   154,   155,    -1,    -1,    -1,   159,    -1,    -1,
     162,   163,    -1,    -1,    -1,   167,   168,   169,   170,   171,
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
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,   138,
     139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,    -1,
     149,   150,   151,    -1,   153,   154,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,   163,    -1,    -1,    -1,   167,   168,
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
      -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,    -1,
     138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,   150,   151,    -1,   153,   154,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,   167,
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
      -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,    -1,
      -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,    -1,
      -1,    -1,   149,   150,   151,    -1,   153,   154,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,    -1,
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
      -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,    -1,
      -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,    -1,
      -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,   163,    -1,    -1,
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
      -1,    -1,    -1,    -1,   129,   130,   131,   132,    -1,   134,
      -1,    -1,    -1,   138,   139,   140,   141,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,   150,   151,    -1,   153,   154,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,   163,    -1,
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
      46,    47,    48,    49,    50,    51,    52,    53,    55,    57,
      58,    59,    60,    61,    62,    65,    66,    67,    68,    69,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    96,    97,    98,    99,   102,   103,
     104,   107,   108,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   127,   129,   130,   131,   132,   134,
     138,   139,   140,   141,   142,   149,   150,   151,   152,   153,
     154,   156,   157,   159,   160,   161,   162,   163,   167,   168,
     169,   170,   171,   172,   173,   174,   176,   178,   179,   182,
     183,   184,   188,   190,   191,   192,   198,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   214,   215,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   265,   266,   267,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   318,   321,   322,
     327,   328,   342,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     363,   364,   365,   366,   367,   368,   372,   373,   374,   378,
     380,   381,   383,   390,   392,   395,   396,   397,   399,   400,
     401,   402,   403,   405,   406,   408,   409,   410,   411,   412,
     413,   415,   416,   419,   420,   421,   422,   423,   428,   430,
     432,   433,   434,   439,   458,   461,   465,   468,   469,   475,
     476,   477,   478,   479,   480,   481,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   493,   494,   495,   496,   498,
     499,   500,   501,   502,   503,   504,   507,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   521,   522,   523,
     524,   525,   526,   540,   541,   543,   544,   545,   546,   547,
     548,   549,   550,   571,   576,   577,   578,   579,   580,   581,
     584,   642,   643,   644,   645,   647,   648,   649,   650,   651,
     659,   660,    34,    35,    50,   217,   398,   399,   400,   398,
     398,   399,   400,   159,   159,    38,    39,    41,    42,    48,
      58,    59,    76,    81,   113,   114,   115,   163,   226,   267,
     293,   301,   309,   379,   380,   384,   385,   386,   163,   156,
     156,   156,   159,   387,   159,    25,    35,    62,   120,   279,
     438,   440,   441,   156,   120,   156,   159,   159,    78,   156,
     227,   228,   156,   120,   407,    40,    44,    45,    46,    47,
      48,    49,    52,    54,    61,    63,    64,    69,    72,    74,
      75,    77,    99,   114,   138,   163,   171,   204,   213,   231,
     242,   244,   245,   246,   249,   250,   263,   266,   658,   659,
     120,    16,    40,    46,    49,    61,    72,    74,    75,    99,
     249,   398,   400,   421,   646,   657,   658,   659,    49,    74,
      75,   120,   156,   187,   250,   420,   422,   432,   189,   420,
     658,   156,   156,   657,    18,    19,   658,   156,    31,   216,
     219,   219,   231,   233,   320,   507,    49,    74,    75,   231,
     233,   320,   421,   646,   231,   320,   507,   231,   236,   320,
     120,   247,   247,   248,   159,   156,   402,   478,   317,   420,
     319,   420,   320,   421,   328,   344,   344,     0,   346,   347,
      34,    50,   349,   366,     1,   192,   343,   192,   343,   114,
     381,   401,   420,   109,   192,   109,   343,   192,    43,    47,
      52,    71,   170,   173,   188,   214,   263,   414,   424,   429,
     430,   431,   446,   447,   451,     1,     3,    68,    73,   120,
     425,   169,    94,   205,   206,   207,   208,   209,   210,   497,
     255,   101,   161,   178,   201,   119,   149,   162,   196,   203,
     212,   139,   153,    51,   202,   103,   104,   161,   178,   495,
     195,   156,   501,   122,   157,   159,   508,   509,   148,   159,
     186,   186,   186,   186,   382,   511,   382,    30,   656,   184,
     198,   184,   198,   168,   184,   659,   658,   171,   204,    48,
     658,   155,   120,    46,    48,    81,   108,   170,   657,   227,
     228,   229,   252,   615,   658,   658,   310,   140,   145,   114,
     293,   301,   384,   657,   399,   399,   420,   120,   189,   388,
     389,   156,   404,   420,     1,   163,   656,   115,   163,   362,
     656,   658,   120,   145,   109,   420,   459,   460,   658,   399,
     420,   420,   569,   658,   399,   156,   156,   420,   658,   145,
     459,   186,   186,   124,   109,   186,   124,   159,   159,   159,
     658,   156,   187,   188,   189,    36,   528,   529,   530,   420,
     420,     8,   177,    17,   420,   216,    30,    30,   421,   421,
     507,   421,   421,   421,   646,   239,   239,   421,   507,    96,
     421,   237,   236,   582,   583,   658,   192,   192,   421,   420,
     400,   420,   251,   417,   418,   317,   319,   421,   239,   344,
     192,   343,   192,   343,     3,   350,   366,   396,     1,   350,
     366,   396,    34,   367,   396,   367,   396,   407,   343,   407,
     421,   421,   120,   170,   172,   172,   401,   421,   421,   435,
     436,   658,   290,   290,   435,   120,   442,   477,   478,   480,
      72,   481,   485,   485,   484,   486,   486,   486,   486,   487,
     487,   488,   488,   237,    96,    96,    96,   502,   186,   420,
     514,   515,   571,   657,   420,   147,   189,   421,   520,   509,
     152,   189,   520,   109,   189,   189,   109,   109,   387,    30,
     659,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,   369,   370,   371,    96,   140,   145,   375,   376,   377,
     658,   163,   163,   369,   656,   130,   135,    56,    58,   102,
     257,   270,   272,   283,   284,   285,   287,   289,   616,   617,
     618,   619,   620,   621,   628,   634,   635,   252,    96,   305,
     658,   145,   421,   120,   658,   658,   135,   186,   186,   186,
     658,    96,   109,   189,   398,   189,   657,    98,    46,   657,
     656,    98,    96,   145,   551,   658,   421,   441,   186,   109,
     190,   150,   551,   186,   189,   189,   156,   186,   399,   399,
     186,   145,   551,   421,   190,   421,   421,   657,   421,   420,
     420,   420,   658,   529,   530,   133,   199,   186,   186,   186,
     134,   192,   134,   192,    96,   224,   225,   239,    96,   224,
     225,   239,   239,   239,   421,   421,    96,    96,   421,   243,
     231,   507,   237,   109,   241,   145,   192,   189,   420,   186,
      11,    12,    20,   196,   505,   506,   588,   658,   418,   239,
     421,   366,    34,    34,   192,   343,   192,   115,   401,   658,
     172,   421,   452,   453,   120,   448,   449,   109,    37,    98,
     150,   437,   438,   551,   658,    57,   220,   260,   426,   427,
     156,   159,   265,   500,   511,   589,   592,   593,   594,   595,
     596,   600,   602,   604,   605,    40,    45,    46,    48,    54,
      61,    63,    64,    72,    99,   155,   159,   213,   231,   323,
     324,   325,   326,   552,   554,   556,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   572,   573,   574,
     575,   652,   653,   654,   655,   658,   552,   492,   557,   658,
     492,   186,   187,   109,   189,   189,   511,   151,   167,   151,
     167,   140,   404,   387,   370,   135,   159,   554,   377,   421,
     551,   656,   656,   131,   132,   656,   283,   284,   285,   289,
     658,   269,   280,   269,   280,    30,   292,    98,   115,   159,
     622,   625,   616,    40,    45,    46,    54,    61,    63,    64,
      72,    99,   231,   391,   558,   652,   233,   305,   314,   421,
     658,    96,   305,   656,   156,   551,   552,   389,    96,   186,
     200,   135,   361,   656,   163,   135,    98,   361,   552,   421,
     145,   438,   156,   120,   421,   421,   150,   102,   462,   463,
     464,   466,   467,   102,   470,   471,   472,   473,   399,   186,
     186,   156,   421,   145,   192,   421,   124,   124,   189,   189,
     189,    36,   530,   133,   199,     9,    10,   105,   126,   128,
     156,   197,   525,   527,   538,   539,   542,   156,    30,    30,
     238,   240,   421,   421,   421,   238,   240,   421,   421,   421,
     421,   421,    98,   421,   421,   421,   421,   243,   507,   120,
     421,   421,    49,    74,    75,   250,   401,   422,   432,   251,
     585,   586,   156,   212,   402,   421,   192,   115,   396,   396,
     396,   452,    97,   108,   118,   130,   454,   455,   456,   457,
     109,   658,   109,   120,   436,   130,   120,   421,   150,   438,
     150,    37,   150,   437,   438,   150,   551,   260,    55,    60,
      79,   120,   437,   443,   444,   445,   427,   420,   589,   596,
     156,   291,   482,   641,    98,   171,   258,   259,   261,   268,
     278,   290,   590,   591,   610,   611,   612,   613,   636,   639,
     264,   266,   597,   615,   273,   601,   637,   253,   254,   276,
     606,   607,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   189,   554,   159,   159,   159,   159,   159,
     159,   147,   178,   196,   553,   147,   147,   421,   140,   404,
     571,   376,   292,    30,    98,   115,   159,   629,    30,   622,
     553,   553,   502,   293,   312,   551,   391,   233,   192,   398,
     552,   401,   421,   656,   109,   361,   421,   145,   398,   460,
     421,   421,   115,   463,   464,   102,   188,   115,   464,   467,
     120,   474,   552,   102,   115,   471,   102,   115,   473,   186,
     398,   421,   421,   421,   200,   470,   135,   197,   527,     7,
     399,   658,   197,   538,   399,   192,   192,   239,   239,   239,
     239,    98,   322,   243,   421,   243,   583,   188,   159,   159,
     159,   188,   588,   586,   505,   656,   131,   132,   456,   457,
     457,   453,   108,   145,   450,   551,   449,   436,   150,   437,
     658,   421,   150,   421,   130,   421,   150,   438,   150,   421,
     150,   120,   120,   421,   658,   445,    79,   186,   189,   589,
     603,   256,   220,   260,   274,   281,   640,    98,   262,   263,
     638,   256,   593,   640,   484,   610,   594,   150,   288,   598,
     599,   638,   292,   609,    80,   608,   189,   189,   567,   568,
     189,   196,   658,   189,   196,   552,   555,   189,    30,   189,
     657,   658,   658,   189,   189,   196,   658,   189,   189,   189,
     189,   189,   189,   189,   189,    30,   139,   203,   631,   632,
     633,    30,   630,   631,   277,   626,   109,   623,   172,   658,
     263,   502,   186,   129,   129,    98,   656,   421,   186,   188,
     188,   421,   401,   421,   188,   188,   658,   188,   212,   120,
     474,   120,   188,   120,   474,   188,   186,   115,   530,   658,
     197,   186,   530,   658,   186,   421,   421,   421,   421,   322,
     421,   421,   421,   421,   420,   420,   420,   156,   587,   457,
     656,   421,   145,   421,   150,   421,   150,   437,   421,   150,
     421,   421,   658,   658,   444,   421,   186,   486,    53,   132,
     484,   484,   275,   282,   292,   614,   614,   595,   156,   286,
     189,   189,   109,   189,   109,   189,    96,   189,   109,   189,
     189,   189,   189,   189,   109,   189,   109,   189,   629,   629,
     633,   109,   189,    30,   627,   638,   624,   625,   189,   393,
     394,   502,   120,   231,   313,   293,   172,   401,   421,   361,
     421,   401,    96,   401,   421,   552,   658,   188,   658,   421,
     658,   188,   401,   120,    95,   185,   531,   530,   658,   199,
     530,   421,   189,   189,   189,   420,   450,   421,   421,   421,
     150,   421,    55,   484,   484,   201,   420,   569,   570,   658,
     569,   570,   552,   552,    96,   569,   569,    30,   271,   109,
     109,   457,   551,   658,   120,   231,   658,   393,   474,    96,
     188,    96,   658,     5,   136,   534,   535,   537,   539,    29,
     137,   532,   533,   536,   539,   199,   530,   199,   200,   470,
     186,   450,   421,   120,   484,   186,   189,   189,   147,   189,
     189,   552,   189,   189,   625,   394,   457,   311,   658,   120,
     231,   188,   474,   401,   421,   474,   188,    95,   136,   537,
     185,   137,   536,   199,   115,   658,   421,   311,   658,   120,
     401,   421,   188,   188,   120,   299,   311,   658,   658,   312,
     421,   312,   188,   502,   502,   201,   293,   658,   231,   120,
     658,   312,   502
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
     477,   478,   478,   479,   479,   480,   480,   481,   481,   482,
     482,   483,   483,   484,   484,   484,   485,   485,   485,   485,
     485,   486,   486,   486,   487,   487,   487,   488,   488,   489,
     489,   490,   490,   491,   491,   492,   492,   493,   493,   494,
     494,   494,   494,   495,   495,   495,   496,   496,   497,   497,
     497,   497,   497,   497,   498,   498,   498,   498,   499,   499,
     500,   500,   501,   501,   501,   502,   503,   504,   505,   505,
     506,   506,   506,   506,   507,   507,   507,   507,   507,   507,
     507,   507,   508,   508,   509,   510,   510,   510,   510,   510,
     510,   510,   510,   510,   510,   510,   510,   510,   510,   511,
     511,   511,   511,   512,   512,   512,   513,   513,   514,   515,
     515,   516,   516,   517,   518,   519,   519,   520,   520,   520,
     520,   521,   521,   522,   523,   524,   524,   525,   525,   525,
     526,   526,   526,   526,   526,   526,   527,   527,   528,   528,
     529,   530,   530,   531,   531,   532,   532,   533,   533,   533,
     533,   534,   534,   535,   535,   535,   535,   536,   536,   537,
     537,   538,   538,   538,   538,   539,   539,   539,   539,   540,
     540,   541,   541,   542,   543,   543,   543,   543,   543,   543,
     543,   544,   545,   545,   546,   546,   547,   548,   549,   549,
     550,   550,   551,   552,   552,   552,   552,   553,   553,   553,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   555,
     555,   556,   557,   558,   558,   558,   558,   558,   558,   558,
     558,   558,   558,   559,   560,   560,   560,   561,   562,   563,
     564,   564,   564,   565,   565,   565,   565,   565,   566,   567,
     567,   567,   567,   567,   567,   567,   568,   569,   570,   571,
     572,   572,   573,   574,   574,   575,   576,   576,   576,   577,
     577,   577,   577,   577,   577,   577,   577,   577,   577,   578,
     578,   579,   579,   580,   581,   582,   582,   583,   584,   585,
     585,   586,   587,   588,   588,   589,   590,   590,   591,   591,
     592,   592,   593,   593,   594,   594,   595,   595,   596,   597,
     597,   598,   598,   599,   600,   600,   600,   601,   601,   602,
     603,   603,   604,   605,   605,   606,   606,   607,   607,   607,
     608,   608,   609,   609,   610,   610,   610,   610,   610,   611,
     612,   613,   614,   614,   614,   615,   615,   616,   616,   616,
     616,   616,   616,   616,   616,   617,   617,   617,   617,   618,
     618,   619,   620,   620,   621,   621,   621,   622,   622,   623,
     623,   624,   624,   625,   626,   626,   627,   627,   628,   628,
     628,   629,   629,   630,   630,   631,   631,   632,   632,   633,
     633,   634,   635,   635,   636,   636,   636,   637,   638,   638,
     638,   638,   639,   639,   640,   640,   641,   642,   642,   643,
     643,   644,   644,   645,   646,   646,   646,   646,   647,   647,
     647,   647,   647,   647,   648,   648,   649,   649,   650,   650,
     651,   651,   652,   652,   652,   653,   653,   654,   654,   655,
     655,   656,   657,   657,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   658,   658,   658,   658,   658,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   659,   659,   659,   659,
     659,   659,   659,   659,   659,   659,   660
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
       3,     2,     3,     3,     3,     3,     5,     5,     5,     5,
       8,     4,     4,     7,     5,     4,     3,     2,     5,     4,
       7,     6,     1,     1,     1,     3,     1,     3,     1,     3,
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
  "\"'!='\"", "\"'nodecomp'\"", "\"'<no inherit>'\"",
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
  "URI_LITERAL", "NCNAME", "QNAME", "FUNCTION_NAME", "EQNAME", YY_NULL
  };

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const jsoniq_parser::rhs_number_type
  jsoniq_parser::yyrhs_[] =
  {
       342,     0,    -1,   344,    -1,   327,   344,    -1,   328,   344,
      -1,   327,   328,   344,    -1,     1,    -1,     1,     3,    -1,
     343,     1,    -1,   346,    -1,   345,   346,    -1,   347,    -1,
     345,   347,    -1,   217,   219,    30,   192,    -1,   217,   219,
      30,   134,    30,   192,    -1,   218,   219,    30,   192,    -1,
     218,   219,    30,   134,    30,   192,    -1,   349,   192,   396,
      -1,   366,   192,   396,    -1,   349,   192,   366,   192,   396,
      -1,   396,    -1,   349,   343,   396,    -1,   366,   343,   396,
      -1,   349,   192,   366,   343,   396,    -1,   349,   343,   366,
     192,   396,    -1,   348,    -1,   348,   349,   192,    -1,   348,
     366,   192,    -1,   348,   349,   192,   366,   192,    -1,    35,
     163,   657,   135,   656,   192,    -1,   350,    -1,   349,   192,
     350,    -1,   349,   343,   350,    -1,   351,    -1,   359,    -1,
     364,    -1,   365,    -1,   373,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,   356,    -1,   357,    -1,   358,    -1,
     576,    -1,    34,    39,   184,    -1,    34,    39,   198,    -1,
      34,   115,   108,   656,    -1,    34,    38,   656,    -1,    34,
      41,   184,    -1,    34,    41,   198,    -1,    34,    59,   171,
      -1,    34,    59,   204,    -1,    34,   115,   170,   130,   131,
      -1,    34,   115,   170,   130,   132,    -1,    34,    42,   184,
     109,   151,    -1,    34,    42,   184,   109,   167,    -1,    34,
      42,   168,   109,   151,    -1,    34,    42,   168,   109,   167,
      -1,   360,    -1,   363,    -1,    50,    25,     1,    -1,    50,
      62,   656,    -1,    50,    62,   362,   656,    -1,    50,    62,
     656,    98,   361,    -1,    50,    62,   362,   656,    98,   361,
      -1,   656,    -1,   361,   109,   656,    -1,   163,   657,   135,
      -1,   115,    46,   163,    -1,    50,    35,   656,    -1,    50,
      35,   163,   657,   135,   656,    -1,    50,    35,   656,    98,
     361,    -1,    50,    35,   163,   657,   135,   656,    98,   361,
      -1,    34,   163,   657,   135,   656,    -1,    34,   115,    46,
     163,   656,    -1,    34,   115,    48,   163,   656,    -1,   367,
      -1,   366,   192,   367,    -1,   366,   343,   367,    -1,   368,
      -1,   372,    -1,   374,    -1,   378,    -1,   383,    -1,   390,
      -1,   392,    -1,   395,    -1,    34,   115,    81,   369,    -1,
      34,    81,   658,   369,    -1,   370,    -1,   369,   370,    -1,
     371,   135,   571,    -1,    82,    -1,    90,    -1,    83,    -1,
      84,    -1,    85,    -1,    86,    -1,    91,    -1,    87,    -1,
      88,    -1,    89,    -1,    34,    58,   658,    30,    -1,    34,
     267,   615,    -1,    34,   113,   155,   375,    -1,    96,   554,
     376,    -1,   376,    -1,   377,    -1,   140,    -1,   140,   377,
      -1,   145,   421,    -1,    34,   379,   145,   421,    -1,    34,
     379,   140,    -1,    34,   379,   140,   145,   421,    -1,   114,
     120,   658,    -1,   114,   120,   658,   551,    -1,   380,   114,
     120,   658,    -1,   380,   114,   120,   658,   551,    -1,   381,
      -1,   380,   381,    -1,    27,    -1,    27,   159,   382,   189,
      -1,    28,    -1,    28,   159,   382,   189,    -1,   511,    -1,
     382,   109,   511,    -1,    34,   384,    -1,    34,   380,   384,
      -1,   385,    -1,   386,    -1,    48,   659,   387,   404,    -1,
      48,   659,   387,   140,    -1,    76,    48,   659,   387,   404,
      -1,    76,    48,   659,   387,   140,    -1,   159,   189,    -1,
     159,   388,   189,    -1,   159,   189,    96,   552,    -1,   159,
     388,   189,    96,   552,    -1,   389,    -1,   388,   109,   389,
      -1,   120,   658,    -1,   120,   658,   551,    -1,    34,   293,
     658,    -1,    34,   293,   658,    96,   391,    -1,    34,   380,
     293,   658,    -1,    34,   380,   293,   658,    96,   391,    -1,
     558,    -1,   558,   553,    -1,   652,    -1,   652,   553,    -1,
      34,   301,   658,   305,   233,   502,   172,   393,    -1,    34,
     380,   301,   658,   305,   233,   502,   172,   393,    -1,   394,
      -1,   393,   109,   394,    -1,   502,    -1,   502,   551,    -1,
     502,   457,    -1,   502,   551,   457,    -1,    34,   309,   310,
     658,   305,   293,   658,   120,   658,   311,   421,    -1,    34,
     309,   310,   658,   305,   293,   658,   231,   120,   658,   311,
     299,   312,   502,    -1,    34,   309,   310,   658,   305,   293,
     658,   313,   231,   120,   658,   311,   421,    -1,    34,   309,
     310,   658,   314,   312,   263,   293,   658,   231,   120,   658,
     312,   502,   201,   293,   658,   231,   120,   658,   312,   502,
      -1,   397,    -1,   399,    -1,   400,    -1,    -1,   399,    -1,
     400,    -1,    -1,   420,    -1,   400,   420,    -1,   401,    -1,
     400,   401,    -1,   400,   420,   343,   401,    -1,   402,    -1,
     405,    -1,   408,    -1,   409,    -1,   410,    -1,   411,    -1,
     412,    -1,   413,    -1,   415,    -1,   469,    -1,   465,    -1,
     416,    -1,   419,    -1,   156,   400,   186,    -1,   156,   398,
     186,    -1,   156,   398,   186,    -1,   406,   192,    -1,   406,
     109,   407,    -1,   114,   407,    -1,   380,   114,   407,    -1,
     120,   658,    -1,   120,   658,   551,    -1,   120,   658,   145,
     421,    -1,   120,   658,   551,   145,   421,    -1,   120,   658,
     145,   421,   192,    -1,   422,   192,    -1,   246,   248,   421,
     192,    -1,   249,   159,   420,   189,   401,    -1,   244,   247,
     192,    -1,   245,   247,   192,    -1,   432,   414,    -1,   188,
     401,    -1,    49,   159,   420,   189,   200,   401,   129,   401,
      -1,   250,   402,   417,    -1,   418,    -1,   417,   418,    -1,
     251,   588,   402,    -1,   192,    -1,   421,    -1,   420,   109,
     421,    -1,   420,   343,   421,    -1,   423,    -1,   461,    -1,
     468,    -1,   475,    -1,   584,    -1,   422,    -1,   476,    -1,
     458,    -1,   577,    -1,   578,    -1,   580,    -1,   579,    -1,
     581,    -1,   649,    -1,   647,    -1,   650,    -1,   651,    -1,
     648,    -1,   432,   424,    -1,   188,   421,    -1,    68,   290,
      -1,    73,   290,    -1,   220,    -1,   260,    -1,    57,   260,
      -1,   426,   443,    79,   421,    -1,   426,    79,   421,    -1,
     434,   425,   442,   427,   427,    -1,   434,   425,   442,   427,
      -1,    43,   120,   658,    -1,   433,    -1,   439,    -1,   428,
      -1,   430,    -1,   446,    -1,   451,    -1,   447,    -1,   429,
      -1,   430,    -1,   432,   431,    -1,   434,   120,   435,    -1,
     434,     1,   435,    -1,   434,     3,    -1,    47,    -1,   263,
      -1,   436,    -1,   435,   109,   120,   436,    -1,   435,   109,
     436,    -1,   658,   150,   421,    -1,   658,    37,   130,   150,
     421,    -1,   658,   551,   150,   421,    -1,   658,   551,    37,
     130,   150,   421,    -1,   658,   437,   150,   421,    -1,   658,
      37,   130,   437,   150,   421,    -1,   658,   551,   437,   150,
     421,    -1,   658,   551,    37,   130,   437,   150,   421,    -1,
     658,   438,   150,   421,    -1,   658,   551,   438,   150,   421,
      -1,   658,   437,   438,   150,   421,    -1,   658,   551,   437,
     438,   150,   421,    -1,    98,   120,   658,    -1,   279,   120,
     658,    -1,    52,   440,    -1,   441,    -1,   440,   109,   441,
      -1,   120,   658,   145,   421,    -1,   120,   658,   551,   145,
     421,    -1,   438,   145,   421,    -1,   120,   658,   551,   438,
     145,   421,    -1,   120,   658,   150,   421,    -1,   120,   658,
     551,   150,   421,    -1,   444,    -1,   120,   658,    -1,   120,
     658,   444,    -1,   437,    -1,   437,   445,    -1,   445,    -1,
      60,   120,   658,    55,   120,   658,    -1,    55,   120,   658,
      -1,    60,   120,   658,    -1,   214,   421,    -1,   173,   172,
     448,    -1,   449,    -1,   448,   109,   449,    -1,   120,   658,
      -1,   120,   658,   145,   421,    -1,   120,   658,   551,   145,
     421,    -1,   120,   658,   551,   145,   421,   450,    -1,   120,
     658,   145,   421,   450,    -1,   120,   658,   450,    -1,   108,
     656,    -1,   170,   172,   452,    -1,    71,   170,   172,   452,
      -1,   453,    -1,   452,   109,   453,    -1,   421,    -1,   421,
     454,    -1,   455,    -1,   456,    -1,   457,    -1,   455,   456,
      -1,   455,   457,    -1,   456,   457,    -1,   455,   456,   457,
      -1,    97,    -1,   118,    -1,   130,   131,    -1,   130,   132,
      -1,   108,   656,    -1,    69,   120,   459,   190,   421,    -1,
     138,   120,   459,   190,   421,    -1,   460,    -1,   459,   109,
     120,   460,    -1,   658,   150,   421,    -1,   658,   551,   150,
     421,    -1,    74,   159,   420,   189,   462,   115,   188,   421,
      -1,   463,    -1,   462,   463,    -1,   464,   188,   421,    -1,
     102,   421,    -1,   464,   102,   421,    -1,    74,   159,   420,
     189,   466,   115,   188,   401,    -1,   467,    -1,   466,   467,
      -1,   464,   188,   401,    -1,    75,   159,   420,   189,   470,
     115,   188,   421,    -1,    75,   159,   420,   189,   470,   115,
     120,   658,   188,   421,    -1,    75,   159,   420,   189,   472,
     115,   188,   401,    -1,    75,   159,   420,   189,   470,   115,
     120,   658,   188,   401,    -1,   471,    -1,   470,   471,    -1,
     102,   474,   188,   421,    -1,   102,   120,   658,    96,   474,
     188,   421,    -1,   473,    -1,   472,   473,    -1,   102,   474,
     188,   401,    -1,   102,   120,   658,    96,   474,   188,   401,
      -1,   552,    -1,   474,   212,   552,    -1,    49,   159,   420,
     189,   200,   421,   129,   421,    -1,   477,    -1,   476,   169,
     477,    -1,   478,    -1,   477,    94,   478,    -1,   479,    -1,
     266,   478,    -1,   480,    -1,   480,   497,   480,    -1,   481,
      -1,   481,   255,    72,   589,   482,    -1,   483,    -1,   483,
     101,   481,    -1,    -1,   641,    -1,   484,    -1,   484,   201,
     484,    -1,   485,    -1,   484,   178,   485,    -1,   484,   161,
     485,    -1,   486,    -1,   485,   196,   486,    -1,   485,   119,
     486,    -1,   485,   149,   486,    -1,   485,   162,   486,    -1,
     487,    -1,   486,   203,   487,    -1,   486,   212,   487,    -1,
     488,    -1,   487,   153,   488,    -1,   487,   139,   488,    -1,
     489,    -1,   489,    51,   237,   552,    -1,   490,    -1,   490,
     202,    96,   552,    -1,   491,    -1,   491,   103,    96,   492,
      -1,   493,    -1,   493,   104,    96,   492,    -1,   557,    -1,
     557,   147,    -1,   495,    -1,   494,   495,    -1,   178,    -1,
     161,    -1,   494,   178,    -1,   494,   161,    -1,   498,    -1,
     496,    -1,   499,    -1,   502,    -1,   496,   195,   502,    -1,
     205,    -1,   210,    -1,   209,    -1,   208,    -1,   207,    -1,
     206,    -1,    77,   156,   399,   186,    -1,    77,   228,   156,
     399,   186,    -1,    77,   227,   156,   399,   186,    -1,    77,
      78,   569,   156,   399,   186,    -1,   500,   156,   186,    -1,
     500,   156,   420,   186,    -1,   501,    -1,   500,   501,    -1,
     179,   658,    17,    -1,   179,    18,    -1,   179,    19,    -1,
     503,    -1,   504,    -1,   507,    -1,   658,    -1,   506,    -1,
     196,    -1,    11,    -1,    12,    -1,    20,    -1,   510,    -1,
     507,   508,    -1,   507,   159,   189,    -1,   507,   159,   520,
     189,    -1,   507,   122,   657,    -1,   507,   122,   515,    -1,
     507,   122,   514,    -1,   507,   122,   571,    -1,   509,    -1,
     508,   509,    -1,   157,   420,   187,    -1,   511,    -1,   514,
      -1,   515,    -1,   516,    -1,   519,    -1,   524,    -1,   517,
      -1,   518,    -1,   521,    -1,   403,    -1,   645,    -1,   642,
      -1,   643,    -1,   644,    -1,   512,    -1,   571,    -1,   513,
      -1,   221,    -1,   112,    -1,   152,    -1,   127,    -1,   222,
      -1,   223,    -1,   120,   658,    -1,   159,   189,    -1,   159,
     420,   189,    -1,   122,    -1,   121,    -1,   171,   156,   420,
     186,    -1,   204,   156,   420,   186,    -1,   659,   159,   189,
      -1,   659,   159,   520,   189,    -1,   147,    -1,   520,   109,
     147,    -1,   421,    -1,   520,   109,   421,    -1,   522,    -1,
     523,    -1,   659,   148,   152,    -1,    48,   387,   404,    -1,
     525,    -1,   543,    -1,   526,    -1,   540,    -1,   541,    -1,
     160,   658,   530,   133,    -1,   160,   658,   530,   199,   197,
     658,   530,   199,    -1,   160,   658,   528,   530,   133,    -1,
     160,   658,   528,   530,   199,   197,   658,   530,   199,    -1,
     160,   658,   530,   199,   527,   197,   658,   530,   199,    -1,
     160,   658,   528,   530,   199,   527,   197,   658,   530,   199,
      -1,   538,    -1,   527,   538,    -1,   529,    -1,   528,   529,
      -1,    36,   658,   530,   135,   530,   531,    -1,    -1,    36,
      -1,   185,   532,   185,    -1,    95,   534,    95,    -1,    -1,
     533,    -1,   137,    -1,   536,    -1,   533,   137,    -1,   533,
     536,    -1,    -1,   535,    -1,   136,    -1,   537,    -1,   535,
     136,    -1,   535,   537,    -1,    29,    -1,   539,    -1,     5,
      -1,   539,    -1,   525,    -1,    10,    -1,   542,    -1,   539,
      -1,     9,    -1,   126,    -1,   128,    -1,   156,   399,   186,
      -1,   215,    31,   216,    -1,   215,   216,    -1,   176,   657,
     177,    -1,   176,   657,     8,    -1,   105,     7,    -1,   544,
      -1,   545,    -1,   546,    -1,   547,    -1,   548,    -1,   549,
      -1,   550,    -1,    44,   156,   399,   186,    -1,    21,   398,
     186,    -1,    46,   156,   420,   186,   156,   398,   186,    -1,
      22,   398,   186,    -1,    99,   156,   420,   186,   156,   398,
     186,    -1,    72,   156,   399,   186,    -1,    40,   156,   399,
     186,    -1,    23,   398,   186,    -1,    61,   156,   420,   186,
     156,   398,   186,    -1,    24,   399,   186,    -1,   163,   156,
     420,   186,   156,   399,   186,    -1,    96,   552,    -1,   554,
      -1,   554,   553,    -1,   213,   159,   189,    -1,   159,   189,
      -1,   147,    -1,   196,    -1,   178,    -1,   556,    -1,   558,
      -1,   155,   159,   189,    -1,   155,    -1,   326,   159,   189,
      -1,   326,    -1,   572,    -1,   575,    -1,   652,    -1,   552,
      -1,   555,   109,   552,    -1,   658,    -1,   658,    -1,   560,
      -1,   567,    -1,   565,    -1,   568,    -1,   566,    -1,   564,
      -1,   563,    -1,   562,    -1,   561,    -1,   559,    -1,   231,
     159,   189,    -1,    45,   159,   189,    -1,    45,   159,   567,
     189,    -1,    45,   159,   568,   189,    -1,    54,   159,   189,
      -1,    72,   159,   189,    -1,    40,   159,   189,    -1,    61,
     159,   189,    -1,    61,   159,   657,   189,    -1,    61,   159,
      30,   189,    -1,    99,   159,   189,    -1,    99,   159,   658,
     189,    -1,    99,   159,   658,   109,   569,   189,    -1,    99,
     159,   196,   189,    -1,    99,   159,   196,   109,   569,   189,
      -1,    63,   159,   658,   189,    -1,    46,   159,   189,    -1,
      46,   159,   658,   189,    -1,    46,   159,   658,   109,   569,
     189,    -1,    46,   159,   658,   109,   570,   189,    -1,    46,
     159,   196,   189,    -1,    46,   159,   196,   109,   569,   189,
      -1,    46,   159,   196,   109,   570,   189,    -1,    64,   159,
     658,   189,    -1,   658,    -1,   658,   147,    -1,    30,    -1,
     573,    -1,   574,    -1,    48,   159,   196,   189,    -1,    48,
     159,   189,    96,   552,    -1,    48,   159,   555,   189,    96,
     552,    -1,   159,   554,   189,    -1,    34,   226,   227,    -1,
      34,   226,   228,    -1,    34,   226,   229,    -1,   232,   231,
     421,   239,   421,    -1,   232,   231,   421,    96,   238,   239,
     421,    -1,   232,   231,   421,    96,   240,   239,   421,    -1,
     232,   231,   421,   224,   421,    -1,   232,   231,   421,   225,
     421,    -1,   232,   233,   421,   239,   421,    -1,   232,   233,
     421,    96,   238,   239,   421,    -1,   232,   233,   421,    96,
     240,   239,   421,    -1,   232,   233,   421,   224,   421,    -1,
     232,   233,   421,   225,   421,    -1,   230,   231,   421,    -1,
     230,   233,   421,    -1,   235,   231,   421,   243,   421,    -1,
     235,   236,   237,   231,   421,   243,   421,    -1,   234,   231,
     421,    96,   421,    -1,   242,   120,   582,   241,   421,   188,
     421,    -1,   583,    -1,   582,   109,   120,   583,    -1,   658,
     145,   421,    -1,   250,   156,   420,   186,   585,    -1,   586,
      -1,   585,   586,    -1,   251,   588,   587,    -1,   156,   420,
     186,    -1,   505,    -1,   588,   212,   505,    -1,   592,   590,
      -1,    -1,   591,    -1,   610,    -1,   591,   610,    -1,   593,
      -1,   592,   268,   593,    -1,   594,    -1,   593,   264,   594,
      -1,   595,    -1,   594,   266,   150,   595,    -1,   596,    -1,
     265,   596,    -1,   600,   597,   598,    -1,    -1,   615,    -1,
      -1,   599,    -1,   288,   156,   420,   186,    -1,   604,   601,
      -1,   159,   589,   189,    -1,   602,    -1,    -1,   637,    -1,
     500,   156,   603,   186,    -1,    -1,   589,    -1,   605,   606,
      -1,   511,    -1,   156,   420,   186,    -1,    -1,   607,    -1,
     254,   608,    -1,   253,   609,    -1,   276,    -1,    -1,    80,
      -1,    -1,   292,    -1,   611,    -1,   612,    -1,   613,    -1,
     639,    -1,   636,    -1,   171,    -1,   290,   484,   614,    -1,
     259,   638,   614,    -1,   292,    -1,   282,    -1,   275,    -1,
     252,   616,    -1,   615,   252,   616,    -1,   617,    -1,   618,
      -1,   619,    -1,   634,    -1,   620,    -1,   628,    -1,   621,
      -1,   635,    -1,   102,   280,    -1,   102,   269,    -1,   272,
      -1,   287,    -1,   257,   280,    -1,   257,   269,    -1,    58,
     658,    30,    -1,   283,    -1,    56,   283,    -1,   285,   622,
      -1,   285,   159,   622,   623,   189,    -1,    56,   285,    -1,
     625,    -1,   115,    -1,    -1,   109,   624,    -1,   625,    -1,
     624,   109,   625,    -1,    98,    30,   626,   627,    -1,    -1,
     277,    30,    -1,    -1,   638,   271,    -1,   284,   292,   629,
     631,    -1,   284,   292,   115,   631,    -1,    56,   284,   292,
      -1,    98,    30,    -1,   159,   630,   189,    -1,    30,    -1,
     630,   109,    30,    -1,    -1,   632,    -1,   633,    -1,   632,
     633,    -1,   203,   629,    -1,   139,   629,    -1,   270,    30,
      -1,   289,    -1,    56,   289,    -1,    98,   220,    -1,    98,
     260,    -1,   261,   256,    -1,   273,   638,   286,    -1,   262,
     484,    -1,    98,   132,   484,    -1,    98,    53,   484,    -1,
     263,   484,   201,   484,    -1,   278,   640,    -1,   258,   640,
      -1,   281,    -1,   274,    -1,   291,   256,   486,    -1,   157,
     187,    -1,   157,   420,   187,    -1,   316,   317,    -1,   316,
     420,   317,    -1,   318,   319,    -1,   318,   420,   319,    -1,
     156,   646,   186,    -1,   657,   124,   421,    -1,   421,   124,
     421,    -1,   646,   109,   421,   124,   421,    -1,   646,   109,
     657,   124,   421,    -1,   232,   320,   421,   239,   421,    -1,
     232,   320,   646,   239,   421,    -1,   232,   320,   421,   239,
     421,    98,   322,   421,    -1,   232,   421,   239,   421,    -1,
     232,   646,   239,   421,    -1,   232,   421,   239,   421,    98,
     322,   421,    -1,   321,   320,   421,   239,   421,    -1,   321,
     421,   239,   421,    -1,   230,   320,   507,    -1,   230,   507,
      -1,   234,   320,   507,    96,   421,    -1,   234,   507,    96,
     421,    -1,   235,   320,   236,   237,   507,   243,   421,    -1,
     235,   236,   237,   507,   243,   421,    -1,   653,    -1,   654,
      -1,   655,    -1,   325,   159,   189,    -1,   325,    -1,   323,
     159,   189,    -1,   323,    -1,   324,   159,   189,    -1,   324,
      -1,    30,    -1,    16,    -1,   658,    -1,   659,    -1,    99,
      -1,    40,    -1,    45,    -1,    54,    -1,    46,    -1,    49,
      -1,   231,    -1,    61,    -1,    63,    -1,    64,    -1,    72,
      -1,    75,    -1,    74,    -1,   213,    -1,   249,    -1,   660,
      -1,    25,    -1,   217,    -1,   130,    -1,    39,    -1,   267,
      -1,    38,    -1,   228,    -1,   227,    -1,   149,    -1,    44,
      -1,   265,    -1,   266,    -1,   280,    -1,   269,    -1,   257,
      -1,   291,    -1,   283,    -1,   285,    -1,   284,    -1,   289,
      -1,   261,    -1,   256,    -1,    80,    -1,   220,    -1,   260,
      -1,    53,    -1,   229,    -1,   242,    -1,   308,    -1,   236,
      -1,   205,    -1,   210,    -1,   209,    -1,   208,    -1,   207,
      -1,   206,    -1,    98,    -1,   113,    -1,   114,    -1,   188,
      -1,    47,    -1,    37,    -1,    68,    -1,    73,    -1,    60,
      -1,    55,    -1,    57,    -1,    79,    -1,    43,    -1,   150,
      -1,    52,    -1,   214,    -1,   172,    -1,   173,    -1,   170,
      -1,    71,    -1,    97,    -1,   118,    -1,   131,    -1,   132,
      -1,   108,    -1,    69,    -1,   138,    -1,   190,    -1,   102,
      -1,    96,    -1,   200,    -1,   129,    -1,   169,    -1,    94,
      -1,    51,    -1,   237,    -1,   103,    -1,   201,    -1,   119,
      -1,   162,    -1,   203,    -1,   153,    -1,   139,    -1,    77,
      -1,    78,    -1,   104,    -1,   202,    -1,   154,    -1,   184,
      -1,   198,    -1,   163,    -1,   140,    -1,   134,    -1,   168,
      -1,   151,    -1,   167,    -1,    34,    -1,    41,    -1,    59,
      -1,   115,    -1,    42,    -1,    58,    -1,   219,    -1,    50,
      -1,    62,    -1,    35,    -1,    48,    -1,   279,    -1,   255,
      -1,   288,    -1,   290,    -1,   259,    -1,   273,    -1,   286,
      -1,   278,    -1,   258,    -1,   272,    -1,   287,    -1,   277,
      -1,   271,    -1,   270,    -1,   254,    -1,   253,    -1,   262,
      -1,   263,    -1,   292,    -1,   282,    -1,   281,    -1,   276,
      -1,   274,    -1,   275,    -1,   241,    -1,   238,    -1,   225,
      -1,   224,    -1,   226,    -1,   243,    -1,   233,    -1,   240,
      -1,   239,    -1,    67,    -1,    65,    -1,    76,    -1,   171,
      -1,   204,    -1,   248,    -1,   246,    -1,   247,    -1,   244,
      -1,   245,    -1,   250,    -1,   251,    -1,   252,    -1,    66,
      -1,   301,    -1,   299,    -1,   300,    -1,   305,    -1,   306,
      -1,   307,    -1,   302,    -1,   303,    -1,   304,    -1,    81,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    86,
      -1,    87,    -1,    88,    -1,    89,    -1,    90,    -1,    91,
      -1,   293,    -1,   294,    -1,   295,    -1,   296,    -1,   297,
      -1,   298,    -1,   309,    -1,   310,    -1,   311,    -1,   312,
      -1,   313,    -1,   314,    -1,   315,    -1,    92,    -1,   107,
      -1,   116,    -1,   174,    -1,   182,    -1,   191,    -1,   141,
      -1,    93,    -1,   117,    -1,   142,    -1,   183,    -1,   322,
      -1,    26,    -1
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
    2669,  2673,  2676,  2680,  2684,  2688,  2692,  2698,  2704,  2710,
    2716,  2725,  2730,  2735,  2743,  2749,  2754,  2758,  2761,  2767,
    2772,  2780,  2787,  2789,  2791,  2793,  2797,  2799,  2803,  2805,
    2809,  2811,  2813,  2815,  2817,  2819,  2821,  2823,  2825,  2827,
    2829,  2831,  2833,  2835,  2837,  2839,  2841,  2843,  2845,  2847,
    2849,  2851,  2853,  2855,  2857,  2859,  2861,  2863,  2865,  2867,
    2869,  2871,  2873,  2875,  2877,  2879,  2881,  2883,  2885,  2887,
    2889,  2891,  2893,  2895,  2897,  2899,  2901,  2903,  2905,  2907,
    2909,  2911,  2913,  2915,  2917,  2919,  2921,  2923,  2925,  2927,
    2929,  2931,  2933,  2935,  2937,  2939,  2941,  2943,  2945,  2947,
    2949,  2951,  2953,  2955,  2957,  2959,  2961,  2963,  2965,  2967,
    2969,  2971,  2973,  2975,  2977,  2979,  2981,  2983,  2985,  2987,
    2989,  2991,  2993,  2995,  2997,  2999,  3001,  3003,  3005,  3007,
    3009,  3011,  3013,  3015,  3017,  3019,  3021,  3023,  3025,  3027,
    3029,  3031,  3033,  3035,  3037,  3039,  3041,  3043,  3045,  3047,
    3049,  3051,  3053,  3055,  3057,  3059,  3061,  3063,  3065,  3067,
    3069,  3071,  3073,  3075,  3077,  3079,  3081,  3083,  3085,  3087,
    3089,  3091,  3093,  3095,  3097,  3099,  3101,  3103,  3105,  3107,
    3109,  3111,  3113,  3115,  3117,  3119,  3121,  3123,  3125,  3127,
    3129,  3131,  3133,  3135,  3137,  3139,  3141,  3143,  3145,  3147,
    3149,  3151,  3153,  3155,  3157,  3159,  3161,  3163,  3165,  3167,
    3169,  3171,  3173,  3175,  3177,  3179,  3181,  3183,  3185,  3187,
    3189,  3191,  3193,  3195,  3197,  3199,  3201,  3203,  3205,  3207,
    3209,  3211,  3213,  3215,  3217,  3219,  3221,  3223,  3225,  3227,
    3229,  3231,  3233,  3235,  3237,  3239,  3241
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  jsoniq_parser::yyrline_[] =
  {
         0,  1058,  1058,  1059,  1063,  1067,  1075,  1081,  1085,  1094,
    1100,  1108,  1114,  1125,  1130,  1136,  1141,  1150,  1157,  1164,
    1173,  1180,  1188,  1196,  1204,  1215,  1220,  1227,  1234,  1246,
    1256,  1263,  1270,  1282,  1283,  1284,  1285,  1286,  1291,  1292,
    1293,  1294,  1295,  1296,  1297,  1300,  1305,  1310,  1318,  1326,
    1334,  1339,  1347,  1352,  1360,  1365,  1373,  1378,  1383,  1388,
    1396,  1398,  1401,  1411,  1416,  1424,  1432,  1443,  1450,  1461,
    1466,  1474,  1481,  1488,  1497,  1510,  1518,  1525,  1535,  1542,
    1549,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1572,
    1578,  1587,  1594,  1604,  1614,  1615,  1616,  1617,  1618,  1619,
    1620,  1621,  1622,  1623,  1628,  1636,  1644,  1652,  1659,  1667,
    1674,  1679,  1687,  1695,  1709,  1723,  1740,  1745,  1753,  1761,
    1772,  1777,  1786,  1791,  1798,  1803,  1813,  1818,  1827,  1833,
    1846,  1851,  1859,  1870,  1885,  1897,  1912,  1917,  1922,  1927,
    1935,  1942,  1953,  1958,  1968,  1977,  1986,  1995,  2007,  2011,
    2017,  2021,  2031,  2041,  2054,  2060,  2069,  2074,  2081,  2088,
    2099,  2109,  2119,  2129,  2147,  2167,  2171,  2176,  2183,  2187,
    2192,  2199,  2204,  2216,  2223,  2233,  2248,  2249,  2250,  2251,
    2252,  2253,  2254,  2256,  2257,  2258,  2259,  2260,  2262,  2268,
    2283,  2308,  2316,  2324,  2331,  2338,  2349,  2358,  2367,  2376,
    2389,  2397,  2405,  2413,  2428,  2433,  2441,  2455,  2472,  2497,
    2505,  2512,  2523,  2533,  2542,  2547,  2560,  2577,  2578,  2579,
    2580,  2581,  2582,  2587,  2588,  2591,  2592,  2593,  2594,  2595,
    2598,  2599,  2600,  2601,  2602,  2607,  2621,  2629,  2634,  2642,
    2647,  2652,  2660,  2669,  2684,  2700,  2715,  2723,  2724,  2725,
    2730,  2731,  2732,  2733,  2734,  2739,  2746,  2759,  2770,  2784,
    2797,  2798,  2807,  2814,  2822,  2834,  2844,  2854,  2864,  2874,
    2884,  2894,  2904,  2915,  2924,  2934,  2944,  2960,  2969,  2978,
    2986,  2992,  3004,  3012,  3022,  3030,  3042,  3048,  3059,  3061,
    3065,  3073,  3077,  3082,  3086,  3090,  3094,  3104,  3112,  3119,
    3125,  3135,  3139,  3143,  3151,  3159,  3167,  3179,  3187,  3193,
    3203,  3209,  3219,  3223,  3233,  3239,  3245,  3251,  3260,  3269,
    3278,  3291,  3295,  3303,  3309,  3319,  3327,  3336,  3349,  3356,
    3368,  3372,  3384,  3391,  3397,  3406,  3413,  3419,  3430,  3437,
    3443,  3452,  3461,  3468,  3479,  3486,  3498,  3504,  3516,  3522,
    3533,  3539,  3550,  3556,  3567,  3573,  3584,  3593,  3597,  3609,
    3618,  3628,  3632,  3647,  3651,  3665,  3669,  3681,  3685,  3693,
    3696,  3703,  3707,  3716,  3720,  3724,  3732,  3736,  3742,  3748,
    3754,  3764,  3768,  3772,  3780,  3784,  3790,  3800,  3804,  3814,
    3818,  3828,  3832,  3842,  3846,  3856,  3860,  3869,  3873,  3881,
    3885,  3889,  3893,  3903,  3907,  3911,  3918,  3923,  3931,  3935,
    3939,  3943,  3947,  3951,  3957,  3961,  3965,  3969,  3980,  3986,
    3996,  4002,  4012,  4016,  4020,  4026,  4035,  4057,  4063,  4067,
    4077,  4081,  4085,  4089,  4101,  4106,  4110,  4114,  4119,  4124,
    4128,  4132,  4141,  4147,  4157,  4165,  4169,  4173,  4177,  4181,
    4185,  4189,  4193,  4197,  4201,  4206,  4210,  4214,  4218,  4226,
    4230,  4235,  4239,  4248,  4255,  4262,  4273,  4277,  4286,  4294,
    4298,  4306,  4311,  4320,  4328,  4334,  4338,  4360,  4366,  4372,
    4378,  4388,  4392,  4400,  4408,  4420,  4424,  4432,  4436,  4440,
    4448,  4456,  4473,  4481,  4498,  4517,  4541,  4547,  4558,  4564,
    4575,  4584,  4586,  4590,  4595,  4605,  4608,  4615,  4621,  4627,
    4634,  4646,  4649,  4656,  4662,  4668,  4675,  4686,  4690,  4698,
    4702,  4710,  4714,  4718,  4723,  4732,  4736,  4740,  4744,  4752,
    4757,  4765,  4770,  4778,  4786,  4791,  4796,  4801,  4806,  4811,
    4816,  4822,  4830,  4834,  4840,  4844,  4852,  4860,  4868,  4872,
    4880,  4884,  4892,  4900,  4904,  4908,  4913,  4920,  4926,  4932,
    4942,  4946,  4950,  4955,  4960,  4965,  4970,  4974,  4978,  4985,
    4991,  5001,  5009,  5017,  5021,  5025,  5029,  5033,  5037,  5041,
    5045,  5049,  5053,  5061,  5069,  5073,  5077,  5085,  5092,  5100,
    5108,  5112,  5116,  5124,  5128,  5134,  5140,  5144,  5154,  5162,
    5166,  5172,  5181,  5190,  5196,  5202,  5212,  5218,  5225,  5231,
    5237,  5241,  5249,  5257,  5261,  5272,  5278,  5284,  5290,  5300,
    5304,  5310,  5316,  5320,  5326,  5330,  5336,  5342,  5349,  5359,
    5364,  5372,  5378,  5388,  5394,  5403,  5409,  5422,  5428,  5435,
    5441,  5451,  5460,  5468,  5474,  5483,  5491,  5495,  5502,  5507,
    5515,  5519,  5526,  5530,  5537,  5541,  5548,  5552,  5561,  5574,
    5577,  5585,  5588,  5596,  5604,  5612,  5616,  5624,  5627,  5635,
    5647,  5650,  5658,  5670,  5676,  5686,  5689,  5697,  5701,  5705,
    5713,  5716,  5724,  5727,  5735,  5739,  5743,  5747,  5751,  5759,
    5767,  5779,  5791,  5795,  5799,  5807,  5813,  5823,  5827,  5831,
    5835,  5839,  5843,  5847,  5851,  5859,  5863,  5867,  5871,  5879,
    5885,  5895,  5905,  5909,  5917,  5927,  5938,  5945,  5949,  5957,
    5960,  5967,  5972,  5981,  5991,  5994,  6001,  6005,  6013,  6022,
    6029,  6039,  6043,  6050,  6056,  6066,  6069,  6076,  6081,  6093,
    6101,  6113,  6121,  6125,  6133,  6137,  6141,  6149,  6157,  6161,
    6165,  6169,  6177,  6185,  6197,  6201,  6209,  6215,  6219,  6226,
    6231,  6239,  6244,  6253,  6262,  6271,  6277,  6285,  6297,  6303,
    6313,  6318,  6324,  6334,  6342,  6347,  6355,  6378,  6404,  6430,
    6459,  6485,  6514,  6518,  6522,  6529,  6534,  6542,  6547,  6555,
    6560,  6573,  6577,  6578,  6591,  6592,  6593,  6594,  6595,  6596,
    6600,  6601,  6602,  6603,  6604,  6605,  6606,  6607,  6608,  6609,
    6613,  6614,  6615,  6616,  6617,  6618,  6619,  6620,  6621,  6622,
    6623,  6624,  6625,  6626,  6627,  6628,  6629,  6630,  6631,  6632,
    6633,  6634,  6635,  6636,  6637,  6638,  6639,  6640,  6641,  6642,
    6643,  6644,  6645,  6646,  6647,  6648,  6649,  6650,  6651,  6652,
    6653,  6654,  6655,  6656,  6657,  6658,  6659,  6660,  6661,  6662,
    6663,  6664,  6665,  6666,  6667,  6668,  6669,  6670,  6671,  6672,
    6673,  6674,  6675,  6676,  6677,  6678,  6679,  6680,  6681,  6682,
    6683,  6684,  6685,  6686,  6687,  6688,  6689,  6690,  6691,  6692,
    6693,  6694,  6695,  6696,  6697,  6698,  6699,  6700,  6701,  6702,
    6703,  6704,  6705,  6706,  6707,  6708,  6709,  6710,  6711,  6712,
    6713,  6714,  6715,  6716,  6717,  6718,  6719,  6720,  6721,  6722,
    6723,  6724,  6725,  6726,  6727,  6728,  6729,  6730,  6731,  6732,
    6733,  6734,  6735,  6736,  6737,  6738,  6739,  6740,  6741,  6742,
    6749,  6750,  6751,  6752,  6753,  6754,  6755,  6756,  6757,  6758,
    6759,  6760,  6761,  6762,  6763,  6764,  6765,  6766,  6767,  6768,
    6769,  6770,  6771,  6772,  6773,  6774,  6775,  6776,  6777,  6778,
    6779,  6780,  6781,  6782,  6783,  6784,  6785,  6786,  6787,  6788,
    6789,  6790,  6791,  6792,  6793,  6794,  6795,  6796,  6797,  6798,
    6799,  6800,  6801,  6802,  6803,  6804,  6805,  6806,  6807,  6808,
    6809,  6810,  6811,  6812,  6813,  6814,  6819
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
  const int jsoniq_parser::yylast_ = 18947;
  const int jsoniq_parser::yynnts_ = 320;
  const int jsoniq_parser::yyempty_ = -2;
  const int jsoniq_parser::yyfinal_ = 557;
  const int jsoniq_parser::yyterror_ = 1;
  const int jsoniq_parser::yyerrcode_ = 256;
  const int jsoniq_parser::yyntokens_ = 341;

  const unsigned int jsoniq_parser::yyuser_token_number_max_ = 595;
  const jsoniq_parser::token_number_type jsoniq_parser::yyundef_token_ = 2;


} // zorba
/* Line 1141 of lalr1.cc  */
#line 16513 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.cpp"
/* Line 1142 of lalr1.cc  */
#line 6823 "/Users/pjl/src/flwor/zorba/repo/bug-1090089/zorba/build/src/compiler/parser/jsoniq_parser.y"


namespace zorba {







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



      if (msg.find("(missing comma \",\" between expressions?)") != string::npos
          &&
          prevErr->msg.find(zstring("\",\"")) == zstring::npos)
        return;
    }


    string message = msg;
    int pos;
    std::string unexpected_qname = "unexpected \"'QName'\"";
    if ((pos = message.find(unexpected_qname)) != -1)
      message = message.substr(0, pos) + "unexpected qualified name \"" + driver.symtab.get_last_qname() + "\"" + message.substr(pos+unexpected_qname.length());


    while ((pos = message.find("\"'")) != -1 || (pos = message.find("'\"")) != -1)
      message.replace(pos, 2, "\"");
    driver.set_expr(new ParseErrorNode(driver.createQueryLoc(loc), err::XPST0003, message));
  }
}

}
